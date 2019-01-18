/**
 * @file amt.c
 * @brief Automatic Multicast Tunneling Protocol (AMT) file for VLC media player
 * Allows multicast streaming when not in a multicast-enabled network
 * Currently IPv4 is supported, but IPv6 is not yet.
 *
 * Copyright (C) 2018 VLC authors and VideoLAN
 * Copyright (c) Juniper Networks, Inc., 2018. All rights reserved.
 *
 * Authors: Christophe Massiot <massiot@via.ecp.fr>         - original UDP code
 *          Tristan Leteurtre <tooney@via.ecp.fr>           - original UDP code
 *          Laurent Aimar <fenrir@via.ecp.fr>               - original UDP code
 *          Jean-Paul Saman <jpsaman #_at_# m2x dot nl>     - original UDP code
 *          Remi Denis-Courmont                             - original UDP code
 *          Natalie Landsberg natalie.landsberg97@gmail.com - AMT support
 *          Wayne Brassem <wbrassem@rogers.com>             - Added FQDN support 
 *
 * This code is licensed to you under the GNU Lesser General Public License
 * version 2.1 or later. You may not use this code except in compliance with
 * the GNU Lesser General Public License.
 * This code is not an official Juniper product.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 ****************************************************************************/
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <errno.h>
#include <ctype.h>
#ifdef HAVE_ARPA_INET_H
# include <arpa/inet.h>
#endif

#ifdef HAVE_SYS_SELECT_H
# include <sys/select.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif

#include <vlc_common.h>
#include <vlc_demux.h>
#include <vlc_plugin.h>
#include <vlc_access.h>
#include <vlc_network.h>
#include <vlc_block.h>
#include <vlc_interrupt.h>
#include <vlc_url.h>

#include "amt.h"

#ifdef HAVE_POLL
 #include <poll.h>
#endif
#ifdef HAVE_SYS_UIO_H
 #include <sys/uio.h>
#endif

#define BUFFER_TEXT N_("Receive buffer")
#define BUFFER_LONGTEXT N_("AMT receive buffer size (bytes)" )
#define TIMEOUT_TEXT N_("Native multicast timeout (sec)")
#define AMT_TIMEOUT_TEXT N_("AMT timeout (sec)")
#define AMT_RELAY_ADDRESS N_("AMT relay (IP address or FQDN)")
#define AMT_RELAY_ADDR_LONG N_("AMT relay anycast address, or specify the relay you want by address or fully qualified domain name")
#define AMT_DEFAULT_RELAY N_("amt-relay.m2icast.net")

static int  Open (vlc_object_t *);
static void Close (vlc_object_t *);

/* memory leak and packet counters */
static int mem_alloc, packet;

vlc_module_begin ()
    set_shortname( N_("AMT" ) )
    set_description( N_("AMT input") )
    set_category( CAT_INPUT )
    set_subcategory( SUBCAT_INPUT_ACCESS )

    add_integer( "amt-timeout", 5, AMT_TIMEOUT_TEXT, NULL, true )
    add_integer( "amt-native-timeout", 3, TIMEOUT_TEXT, NULL, true )
    add_string( "amt-relay", AMT_DEFAULT_RELAY, AMT_RELAY_ADDRESS, AMT_RELAY_ADDR_LONG, true )

    set_capability( "access", 0 )
    add_shortcut( "amt" )

    set_callbacks( Open, Close )
vlc_module_end ()

/*****************************************************************************
 * Control:
 *****************************************************************************/
static int Control( stream_t *p_access, int i_query, va_list args )
{
    bool    *pb_bool;

/*    msg_Dbg( p_access, "Control: mem_alloc = %d", mem_alloc); */

    switch( i_query )
    {
        case STREAM_CAN_SEEK:
        case STREAM_CAN_FASTSEEK:
        case STREAM_CAN_PAUSE:
        case STREAM_CAN_CONTROL_PACE:
            pb_bool = va_arg( args, bool * );
            *pb_bool = false;
            break;

        case STREAM_GET_PTS_DELAY:
            *va_arg( args, vlc_tick_t * ) =
                VLC_TICK_FROM_MS(var_InheritInteger( p_access, "network-caching" ));
        break;

        default:
            return VLC_EGENERIC;
    }
    return VLC_SUCCESS;
}

/*****************************************************************************
 * BlockUDP:
 *****************************************************************************/
static block_t *BlockUDP(stream_t *p_access, bool *restrict eof)
{
    access_sys_t *sys = p_access->p_sys;
    ssize_t len;

    block_t *pkt = block_Alloc(sys->mtu);
    char *amtpkt = malloc( DEFAULT_MTU );

    packet++;
    mem_alloc++;   /* do not include *pkt in memory alloc count because it gets freed by caller */
    
/*    msg_Dbg( p_access, "BlockUDP Enter: packet = %d, mem_alloc = %d, pkt = %016x, amtpkt = %016x", packet, mem_alloc, (int) pkt, (int) amtpkt); */

    if (unlikely(pkt == NULL))
    {   /* OOM - dequeue and discard one packet */
        char dummy;
        recv(sys->fd, &dummy, 1, 0);
        return NULL;
    }

    if (unlikely(amtpkt == NULL))
    	goto error;
    
    struct iovec iov = {
        .iov_base = pkt->p_buffer,
        .iov_len  = sys->mtu,
    };
    struct msghdr msg = {
        .msg_iov = &iov,
        .msg_iovlen = 1,
#ifdef __linux__
        .msg_flags = MSG_TRUNC,
#endif
    };

    struct pollfd ufd[1];

    if( sys->tryAMT )
        ufd[0].fd = sys->sAMT;
    else
        ufd[0].fd = sys->fd;
    ufd[0].events = POLLIN;

    switch (vlc_poll_i11e(ufd, 1, sys->timeout))
    {
        case 0:
            msg_Err(p_access, "native multicast receive time-out, packet = %d", packet);
            net_Close( sys->fd );
            if( !sys->tryAMT )
            {
                if( open_amt_tunnel( p_access ) == false )
                    goto error;
                break;
            }
            else
            {
                msg_Err(p_access, "AMT receive time-out");
                *eof = true;
            }
            /* fall through */
        case -1:
/*            msg_Dbg(p_access, "Exiting vlc_poll switch, packet = %d", packet); */
            goto error;
    }

    if( sys->tryAMT )
    {
        len = recv( sys->sAMT, amtpkt, DEFAULT_MTU, 0 );

        if( len < 0 || amtpkt[0] != AMT_MULT_DATA )
            goto error;

        ssize_t shift = IP_HDR_LEN + UDP_HDR_LEN + AMT_HDR_LEN;

        if( len < shift )
        {
            msg_Err(p_access, "%zd bytes packet truncated (MTU was %zu)",
                len, sys->mtu);
            pkt->i_flags |= BLOCK_FLAG_CORRUPTED;
            sys->mtu = len;
        } else {
            len -= shift;
        }

        memcpy( pkt->p_buffer, &amtpkt[shift], len );
    }
    else
        len = recvmsg(sys->fd, &msg, 0);

#ifdef MSG_TRUNC
    if (msg.msg_flags & MSG_TRUNC)
    {
        msg_Err(p_access, "%zd bytes packet truncated (MTU was %zu)",
                len, sys->mtu);
        pkt->i_flags |= BLOCK_FLAG_CORRUPTED;
        sys->mtu = len;
    }
    else
#endif
        pkt->i_buffer = len;

    free( amtpkt );
    mem_alloc--;

/*    msg_Dbg( p_access, "BlockUDP: Main Exit: mem_alloc = %d, packet = %d", mem_alloc, packet); */

    return pkt;
    
error:
    free( amtpkt );
    mem_alloc--;

/*    msg_Dbg( p_access, "BlockUDP: Error Exit: mem_alloc = %d, packet = %d", mem_alloc, packet); */

    return NULL;
}

/*****************************************************************************
 * Open: open the socket
 *****************************************************************************/
static int Open( vlc_object_t *p_this )
{
    stream_t            *p_access = (stream_t*) p_this;
    access_sys_t        *sys = NULL;
    struct addrinfo      hints, *serverinfo = NULL;
    struct sockaddr_in  *server_addr;
    char                *psz_name = NULL, *saveptr, ip_buffer[INET_ADDRSTRLEN];
    int                  i_bind_port = 1234, i_server_port = 0, VLC_ret = VLC_SUCCESS, res;
    vlc_url_t            url;
    
    mem_alloc = 0; packet = 0;
/*    msg_Dbg( p_access, "Open: Enter: mem_alloc = %d", mem_alloc); */

    if( p_access->b_preparsing )
    {
        VLC_ret = VLC_EGENERIC;
        goto cleanup;
    }

    sys = vlc_obj_malloc( p_this, sizeof( *sys ) );
    mem_alloc++;
    
    if( unlikely( sys == NULL ) )
    {
        VLC_ret = VLC_ENOMEM;
        goto cleanup;
    }
    else
        memset( sys, 0, sizeof( *sys ));

    p_access->p_sys = sys;

    /* Set up p_access */
    ACCESS_SET_CALLBACKS( NULL, BlockUDP, Control, NULL );

    if( !p_access->psz_location )
    {
        VLC_ret = VLC_EGENERIC;
        goto cleanup;
    }

    psz_name = strdup( p_access->psz_location );
    mem_alloc++;
    if ( unlikely( psz_name == NULL ) )
    {
        VLC_ret = VLC_ENOMEM;
        goto cleanup;
    }
    
    /* Parse psz_name syntax :
     * [serveraddr[:serverport]][@[bindaddr]:[bindport]] */
    if( vlc_UrlParse( &url, p_access->psz_url ) != 0 )
    {
        msg_Err( p_access, "Invalid URL" );
        VLC_ret = VLC_EGENERIC;
        goto cleanup;
    }
    mem_alloc++;

    if( url.i_port > 0 )
        i_bind_port = url.i_port;

    msg_Dbg( p_access, "opening multicast: %s:%d local=%s:%d",
             url.psz_host, i_server_port, url.psz_path, i_bind_port );

    if( ( url.psz_host == NULL ) || ( strlen( url.psz_host ) == 0 ) )
    {
        msg_Err( p_access, "Please enter a group and/or source address." );
        VLC_ret = VLC_EGENERIC;
        goto cleanup;
    }

    memset( &hints, 0, sizeof( hints ));
    hints.ai_family = AF_INET;  /* Setting to AF_UNSPEC accepts both IPv4 and IPv6 */
    hints.ai_socktype = SOCK_DGRAM;

    /* retrieve list of multicast addresses matching the multicast group identifier */
    res = vlc_getaddrinfo( url.psz_host, AMT_PORT, &hints, &serverinfo );
    mem_alloc++;

    if( res )
    {
        msg_Err( p_access, "Could not find multicast group %s, reason: %s", url.psz_host, gai_strerror(res) );
        VLC_ret = VLC_EGENERIC;
        goto cleanup;
    }

    /* Convert binary socket address to string */
    server_addr = (struct sockaddr_in *) serverinfo->ai_addr;
    inet_ntop(AF_INET, &(server_addr->sin_addr), ip_buffer, INET_ADDRSTRLEN);

    /* release the allocated memory */
    freeaddrinfo(serverinfo);
    serverinfo = NULL;
    mem_alloc--;

    msg_Dbg( p_access, "Setting multicast group address to %s", ip_buffer);

    sys->mcastGroup = strdup( ip_buffer );
    mem_alloc++;
    if( unlikely( sys->mcastGroup == NULL ) )
    {
        VLC_ret = VLC_ENOMEM;
        goto cleanup;
    }
	
    /* The following uses strtok_r() because strtok() is not thread safe */
    sys->srcAddr = strdup( strtok_r( psz_name, "@", &saveptr ) );
    mem_alloc++;

    if( unlikely( sys->srcAddr == NULL ) )
    {
        VLC_ret = VLC_ENOMEM;
        goto cleanup;
    }
    
    /* if strings are equal then no multicast source has been specified */
    if( strcmp( url.psz_host, sys->srcAddr ) == 0 )
	{
        strcpy(sys->srcAddr, "0.0.0.0");
        msg_Dbg( p_access, "No multicast source address specified, trying ASM...");
    }

    /* retrieve list of source addresses matching the multicast source identifier */
    res = vlc_getaddrinfo( sys->srcAddr, AMT_PORT, &hints, &serverinfo );
    mem_alloc++;

    if( res )
    {
        msg_Err( p_access, "Could not find multicast source %s, reason: %s", sys->srcAddr, gai_strerror(res) );
        VLC_ret = VLC_EGENERIC;
        goto cleanup;
    }

    /* Convert binary socket address to string */
    server_addr = (struct sockaddr_in *) serverinfo->ai_addr;
    inet_ntop(AF_INET, &(server_addr->sin_addr), ip_buffer, INET_ADDRSTRLEN);

    msg_Dbg( p_access, "Setting multicast source address to %s", ip_buffer);
            
    /* free the original source address buffer (IP or FQDN) and assign it just the IP address */
    free(sys->srcAddr);
    sys->srcAddr = strdup( ip_buffer );
    
    if( unlikely( sys->srcAddr == NULL ) )
    {
        VLC_ret = VLC_ENOMEM;
        goto cleanup;
    }
    
    if( strcmp( url.psz_host, sys->srcAddr ) == 0 )
        strcpy(sys->srcAddr, "0.0.0.0");

    sys->relayAddr = var_InheritString( p_access, "amt-relay" );

    if( unlikely(sys->relayAddr == NULL ) )
    {
        msg_Err( p_access, "No relay anycast or unicast address specified." );
        VLC_ret = VLC_EGENERIC;
        goto cleanup;
    }

    msg_Dbg( p_access, "Addresses: mcastGroup: %s srcAddr: %s relayAddr: %s", \
             sys->mcastGroup, sys->srcAddr, sys->relayAddr);

    sys->fd = net_OpenDgram( p_access, sys->mcastGroup, i_bind_port,
                             sys->srcAddr, i_server_port, IPPROTO_UDP );
    if( sys->fd == -1 )
    {
        msg_Err( p_access, "cannot open socket" );
        VLC_ret = VLC_EGENERIC;
        goto cleanup;
    }

    sys->mtu = 7 * 188;

    sys->timeout = var_InheritInteger( p_access, "amt-native-timeout");
    if( sys->timeout > 0)
        sys->timeout *= 1000;

    sys->amtTimeout = var_InheritInteger( p_access, "amt-timeout" );
    if( sys->amtTimeout > 0)
        sys->amtTimeout *= 1000;

    sys->tryAMT = false;
    sys->threadReady = false;

cleanup: /* fall through */
    
    /* release the allocated memory */
    free( psz_name );
    vlc_UrlClean( &url );
    freeaddrinfo( serverinfo );

    mem_alloc-=3;

    /* if an error occurred free the memory */
    if ( VLC_ret != VLC_SUCCESS )
    {
        free( sys->mcastGroup );
        free( sys->srcAddr );
        vlc_obj_free( p_this, sys );
        mem_alloc -= 3;
    }
    
/*    msg_Dbg( p_access, "Open: Exit: mem_alloc = %d", mem_alloc); */

    return VLC_ret;
}

/*****************************************************************************
 * Close: free unused data structures
 *****************************************************************************/
static void Close( vlc_object_t *p_this )
{
    char         relay_ip[INET_ADDRSTRLEN];
    stream_t     *p_access = (stream_t*)p_this;
    access_sys_t *sys = p_access->p_sys;

    inet_ntop(AF_INET, &(sys->relayAddrDisco.sin_addr), relay_ip, INET_ADDRSTRLEN);
    
    if( strcmp(sys->srcAddr, "0.0.0.0") == 0 )
        amt_leaveASM_group( p_access );
    else
        amt_leaveSSM_group( p_access );
    amt_send_mem_update( p_access, relay_ip, true );

    if( sys->threadReady )
    {
        sys->threadReady = false;
        vlc_cancel( sys->updateThread );
        vlc_join( sys->updateThread, NULL );
    }

    free( sys->mcastGroup );
    free( sys->srcAddr );
    vlc_obj_free( p_this, sys );

    mem_alloc -= 3;
    if (mem_alloc)
        msg_Err( p_access, "Closing AMT plugin, mem_alloc = %d", mem_alloc);
    else
        msg_Dbg( p_access, "Closing AMT plugin, mem_alloc = %d", mem_alloc);

    net_Close( sys->fd );
    net_Close( sys->sAMT );
    net_Close( sys->sQuery );
}


bool open_amt_tunnel( stream_t *p_access )
{
    struct addrinfo hints, *serverinfo, *server;
    access_sys_t *sys = p_access->p_sys;

    memset( &hints, 0, sizeof( hints ));
    hints.ai_family = AF_INET;  /* Setting to AF_UNSPEC accepts both IPv4 and IPv6 */
    hints.ai_socktype = SOCK_DGRAM;

/*    msg_Dbg( p_access, "open_amt_tunnel: Enter: mem_alloc = %d", mem_alloc); */

    msg_Dbg( p_access, "Attempting AMT to %s...", sys->relayAddr);
    sys->tryAMT = true;

    /* retrieve list of addresses matching the AMT relay */
    int res = vlc_getaddrinfo( sys->relayAddr, AMT_PORT, &hints, &serverinfo );
    mem_alloc++;

    if( res )
    {
        msg_Err( p_access, "Could not find relay %s, reason: %s", sys->relayAddr, gai_strerror(res) );
        goto error;
    }

    /* iterate through the list of sockets to find one the works */
    for (server = serverinfo; server != NULL; server = server->ai_next)
    {
        struct sockaddr_in *server_addr = (struct sockaddr_in *) server->ai_addr;
        char relay_ip[INET_ADDRSTRLEN];

        inet_ntop(AF_INET, &(server_addr->sin_addr), relay_ip, INET_ADDRSTRLEN);

        msg_Dbg( p_access, "Trying AMT Server: %s", relay_ip);
	
        sys->relayAddrDisco.sin_addr = server_addr->sin_addr;

        /* if can't open socket try any others in list */
        if( amt_sockets_init( p_access ) != 0 )
            msg_Err( p_access, "Error initializing socket to %s", relay_ip );
        
        /* Otherwise negotiate with AMT relay and confirm you can pull a UDP packet  */
        else
        {
            amt_send_relay_discovery_msg( p_access, relay_ip );
            msg_Dbg( p_access, "Sent relay AMT discovery message to %s", relay_ip );

            if( !amt_rcv_relay_adv( p_access ) )
            {
                msg_Err( p_access, "Error receiving AMT relay advertisement msg from %s, skipping", relay_ip );
                goto error;
            }
            msg_Dbg( p_access, "Received AMT relay advertisement from %s", relay_ip );

            amt_send_relay_request( p_access, relay_ip );
            msg_Dbg( p_access, "Sent AMT relay request message to %s", relay_ip );
            
            if( !amt_rcv_relay_mem_query( p_access ) )
            {
                msg_Err( p_access, "Could not receive AMT relay membership query from %s, reason: %s", relay_ip, vlc_strerror(errno));
                goto error;
            }
            msg_Dbg( p_access, "Received AMT relay membership query from %s", relay_ip );

            if( strcmp(sys->srcAddr, "") == 0 )
            {
                if( amt_joinASM_group( p_access ) != 0 )
                {
                    msg_Err( p_access, "Error joining ASM %s", vlc_strerror(errno) );
                    goto error;
                }
                msg_Dbg( p_access, "Joined ASM group: %s", sys->mcastGroup );
            }
            else {
                if( amt_joinSSM_group( p_access ) != 0 )
                {
                    msg_Err( p_access, "Error joining SSM %s", vlc_strerror(errno) );
                    goto error;
                }
                msg_Dbg( p_access, "Joined SSM src: %s group: %s", sys->srcAddr, sys->mcastGroup );
            }

            bool eof=false;
            block_t *pkt;
       	
            /* Confirm that you can pull a UDP packet from the socket */
            if ( (pkt = BlockUDP( p_access, &eof )) == false )
                msg_Dbg( p_access, "Unable to receive UDP packet from AMT relay %s for multicast group %s, skipping...", relay_ip, sys->mcastGroup );
            else
            {
                block_Release(pkt);  /* don't decrement mem_alloc since pkt not included in count */
                msg_Dbg( p_access, "Got UDP packet from multicast group %s via AMT relay %s, continuing...", sys->mcastGroup, relay_ip );
                break;   /* found an active server sending UDP packets, so exit loop */
           }
        }
    }

    /* if server is NULL then no AMT relay is responding */
    if (server == NULL)
    {
        msg_Err( p_access, "No AMT servers responding" );
        goto error;
    }
	
    sys->queryTime = vlc_tick_now() / CLOCK_FREQ;

    /* release the allocated memory */
    freeaddrinfo(serverinfo);
    mem_alloc--;

/*    msg_Dbg( p_access, "open_amt_tunnel: Exit: mem_alloc = %d", mem_alloc); */

    return true;

error:
    /* release the allocated memory */
    freeaddrinfo(serverinfo);
    mem_alloc--;

/*    msg_Dbg( p_access, "open_amt_tunnel: Exit: mem_alloc = %d", mem_alloc); */

    sys->threadReady = false;
    return false;
}
/**
 * Calculate checksum
 * */
unsigned short getChecksum( unsigned short *buffer, int nLen )
{
    int nleft = nLen;
    int sum = 0;
    unsigned short *w = buffer;
    unsigned short answer = 0;

    while (nleft > 1)
    {
        sum += *w++;
        nleft -= 2;
    }
    if (nleft == 1)
    {
        *(unsigned char*)(&answer) = *(unsigned char*)w;
        sum += answer;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    answer = ~sum;
    return (answer);
}

/**
 * Make IGMP Membership report
 * */
void makeReport( amt_igmpv3_membership_report_t *mr )
{
    mr->type = AMT_IGMPV3_MEMBERSHIP_REPORT_TYPEID;
    mr->resv = 0;
    mr->checksum = 0;
    mr->resv2 = 0;
    mr->nGroupRecord = htons(1);
}

/**
 * Make IP header
 * */
void makeIPHeader( amt_ip_alert_t *p_ipHead )
{
    p_ipHead->ver_ihl = 0x46;
    p_ipHead->tos = 0xc0;
    p_ipHead->tot_len = htons( IP_HDR_IGMP_LEN + IGMP_REPORT_LEN );
    p_ipHead->id = 0x00;
    p_ipHead->frag_off = 0x0000;
    p_ipHead->ttl = 0x01;
    p_ipHead->protocol = 0x02;
    p_ipHead->check = 0;
    p_ipHead->srcAddr = INADDR_ANY;
    p_ipHead->options = 0x0000;
}

/** Create relay discovery socket, query socket, UDP socket and
 * fills in relay anycast address for discovery
 * return 0 if successful, -1 if not
 */
int amt_sockets_init( stream_t *p_access )
{
    struct sockaddr_in rcvAddr;
    access_sys_t *sys = p_access->p_sys;
    memset( &rcvAddr, 0, sizeof(struct sockaddr_in) );
    int enable = 0, res = 0;

    /* Relay anycast address for discovery */
    sys->relayAddrDisco.sin_family = AF_INET;
    sys->relayAddrDisco.sin_port = htons( AMT_PORT );

    /* create UDP socket */
    sys->sAMT = vlc_socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP, true );
    if( sys->sAMT == -1 )
    {
        msg_Err( p_access, "Failed to create UDP socket" );
        goto error;
    }

    res = setsockopt(sys->sAMT, IPPROTO_IP, IP_PKTINFO, &enable, sizeof(enable));
    if(res < 0)
    {
        msg_Err( p_access, "Couldn't set socket options for IPPROTO_IP, IP_PKTINFO\n %s", vlc_strerror(errno));
        goto error;
    }

    res = setsockopt(sys->sAMT, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    if(res < 0)
    {
        msg_Err( p_access, "Couldn't make socket reusable");
        goto error;
    }

    rcvAddr.sin_family      = AF_INET;
    rcvAddr.sin_port        = htons( 0 );
    rcvAddr.sin_addr.s_addr = INADDR_ANY;

    if( bind(sys->sAMT, (struct sockaddr *)&rcvAddr, sizeof(rcvAddr) ) != 0 )
    {
        msg_Err( p_access, "Failed to bind UDP socket error: %s", vlc_strerror(errno) );
        goto error;
    }

    sys->sQuery = vlc_socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP, true );
    if( sys->sQuery == -1 )
    {
        msg_Err( p_access, "Failed to create query socket" );
        goto error;
    }

    /* bind socket to local address */
    sys->stLocalAddr.sin_family      = AF_INET;
    sys->stLocalAddr.sin_port        = htons( 0 );
    sys->stLocalAddr.sin_addr.s_addr = INADDR_ANY;

    if( bind(sys->sQuery, (struct sockaddr *)&sys->stLocalAddr, sizeof(struct sockaddr) ) != 0 )
    {
        msg_Err( p_access, "Failed to bind query socket" );
        goto error;
    }

    sys->stSvrAddr.sin_family        = AF_INET;
    sys->stSvrAddr.sin_port          = htons( 9124 );
    res = inet_pton( AF_INET, "127.0.0.1", &sys->stSvrAddr.sin_addr );
    if( res == 0 )
    {
        msg_Err( p_access, "Could not convert loopback address" );
        goto error;
    }

    return 0;

error:
    net_Close( sys->sAMT );
    net_Close( sys->sQuery );
    return -1;
}

/**
 * Send a relay discovery message, before 3-way handshake
 * */
void amt_send_relay_discovery_msg( stream_t *p_access, char *relay_ip )
{
    char          chaSendBuffer[AMT_DISCO_MSG_LEN];
    unsigned int  ulNonce;
    int           nRet;
    access_sys_t *sys = p_access->p_sys;

    /* initialize variables */
    memset( chaSendBuffer, 0, sizeof(chaSendBuffer) );
    ulNonce = 0;
    nRet = 0;

    /*
     * create AMT discovery message format
     * +---------------------------------------------------+
     * | Msg Type(1Byte)| Reserved (3 byte)| nonce (4byte) |
     * +---------------------------------------------------+
     */

    chaSendBuffer[0] = AMT_RELAY_DISCO;
    chaSendBuffer[1] = 0;
    chaSendBuffer[2] = 0;
    chaSendBuffer[3] = 0;

    /* create nonce and copy into send buffer */
    srand( (unsigned int)time(NULL) );
    ulNonce = htonl( rand() );
    memcpy( (void*)&chaSendBuffer[4], (void*)&ulNonce, sizeof(ulNonce) );
    sys->glob_ulNonce = ulNonce;

    /* send it */
    nRet = sendto( sys->sAMT, chaSendBuffer, sizeof(chaSendBuffer), 0,\
            (struct sockaddr *)&sys->relayAddrDisco, sizeof(struct sockaddr) );

    if( nRet < 0)
        msg_Err( p_access, "Sendto failed to %s with error %d.", relay_ip, errno);
}

/**
 * Send relay request message, stage 2 of handshake
 * */
void amt_send_relay_request( stream_t *p_access, char *relay_ip )
{
    char         chaSendBuffer[AMT_REQUEST_MSG_LEN];
    uint32_t     ulNonce;
    int          nRet;
    int          nRetry;
    access_sys_t *sys = p_access->p_sys;

    memset( chaSendBuffer, 0, sizeof(chaSendBuffer) );

    ulNonce = 0;
    nRet = 0;
    nRetry = 0;

    /*
     * create AMT request message format
     * +-----------------------------------------------------------------+
     * | Msg Type(1Byte)| Reserved(1byte)|P flag(1byte)|Reserved (2 byte)|
     * +-----------------------------------------------------------------+
     * |             nonce (4byte)                                       |
     * +-----------------------------------------------------------------+
     *
     * The P flag is set to indicate which group membership protocol the
     * gateway wishes the relay to use in the Membership Query response:

     * Value Meaning

     *  0    The relay MUST respond with a Membership Query message that
     *       contains an IPv4 packet carrying an IGMPv3 General Query
     *       message.
     *  1    The relay MUST respond with a Membership Query message that
     *       contains an IPv6 packet carrying an MLDv2 General Query
     *       message.
     *
     */

    chaSendBuffer[0] = AMT_REQUEST;
    chaSendBuffer[1] = 0;
    chaSendBuffer[2] = 0;
    chaSendBuffer[3] = 0;

    ulNonce = sys->glob_ulNonce;
    memcpy( (void*)&chaSendBuffer[4], (void*)&ulNonce, sizeof(uint32_t) );

    nRet = send( sys->sAMT, chaSendBuffer, sizeof(chaSendBuffer), 0 );

    if( nRet < 0 )
        msg_Err(p_access, "Error sending relay request to %s error: %s", relay_ip, vlc_strerror(errno) );
}

/*
* create AMT request message format
* +----------------------------------------------------------------------------------+
* | Msg Type(1 byte)| Reserved (1 byte)| MAC (6 byte)| nonce (4 byte) | IGMP packet  |
* +----------------------------------------------------------------------------------+
*/
void amt_send_mem_update( stream_t *p_access, char *relay_ip, bool leave)
{
    int           sendBufSize = IP_HDR_IGMP_LEN + MAC_LEN + NONCE_LEN + AMT_HDR_LEN;
    char          pSendBuffer[ sendBufSize + IGMP_REPORT_LEN ];
    uint32_t      ulNonce = 0;
    access_sys_t *sys = p_access->p_sys;

    memset( &pSendBuffer, 0, sizeof(pSendBuffer) );

    pSendBuffer[0] = AMT_MEM_UPD;

    /* copy relay MAC response */
    memcpy( (void*)&pSendBuffer[2], (void*)sys->relay_mem_query_msg.uchaMAC, MAC_LEN );

    /* copy nonce */
    ulNonce = ntohl(sys->glob_ulNonce);
    memcpy( (void*)&pSendBuffer[8], (void*)&ulNonce, NONCE_LEN );

    /* make IP header for IGMP packet */
    amt_ip_alert_t p_ipHead;
    memset( &p_ipHead, 0, IP_HDR_IGMP_LEN );
    makeIPHeader( &p_ipHead );

    struct sockaddr_in temp;
    inet_pton( AF_INET, MCAST_ALLHOSTS, &(temp.sin_addr) );
    p_ipHead.destAddr = temp.sin_addr.s_addr;
    p_ipHead.check = getChecksum( (unsigned short*)&p_ipHead, IP_HDR_IGMP_LEN );

    amt_igmpv3_groupRecord_t groupRcd;
    groupRcd.auxDatalen = 0;
    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr) );
    groupRcd.ssm = temp.sin_addr.s_addr;

    if( strcmp(sys->srcAddr, "0.0.0.0") != 0 )
    {
        groupRcd.type = leave ? AMT_IGMP_BLOCK:AMT_IGMP_INCLUDE;
        groupRcd.nSrc = htons(1);

        inet_pton( AF_INET, sys->srcAddr, &(temp.sin_addr) );
        groupRcd.srcIP[0] = temp.sin_addr.s_addr;

    } else {
        groupRcd.type = leave ? AMT_IGMP_INCLUDE_CHANGE:AMT_IGMP_EXCLUDE_CHANGE;
        groupRcd.nSrc = htons(0);
    }

    /* make IGMP membership report */
    amt_igmpv3_membership_report_t p_igmpMemRep;
    makeReport( &p_igmpMemRep );

    memcpy((void *)&p_igmpMemRep.grp[0], (void *)&groupRcd, (int)sizeof(groupRcd) );
    p_igmpMemRep.checksum = getChecksum( (unsigned short*)&p_igmpMemRep, IGMP_REPORT_LEN );

    amt_membership_update_msg_t memUpdateMsg;
    memset((void*)&memUpdateMsg, 0, sizeof(memUpdateMsg));
    memcpy((void*)&memUpdateMsg.ipHead, (void*)&p_ipHead, sizeof(p_ipHead) );
    memcpy((void*)&memUpdateMsg.memReport, (void*)&p_igmpMemRep, sizeof(p_igmpMemRep) );

    memcpy( (void*)&pSendBuffer[12], (void*)&memUpdateMsg, sizeof(memUpdateMsg) );

    send( sys->sAMT, pSendBuffer, sizeof(pSendBuffer), 0 );

    msg_Dbg( p_access, "AMT relay membership report sent to %s", relay_ip );
}

/**
 * Receive relay advertisement message
 *
 *
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |  V=0  |Type=2 |                   Reserved                    |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |                        Discovery Nonce                        |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |                                                               |
 *  ~                  Relay Address (IPv4 or IPv6)                 ~
 *  |                                                               |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * */
bool amt_rcv_relay_adv( stream_t *p_access )
{
    char pkt[RELAY_ADV_MSG_LEN];
    access_sys_t *sys = p_access->p_sys;

    memset( &pkt, 0, RELAY_ADV_MSG_LEN );

    struct pollfd ufd[1];

    ufd[0].fd = sys->sAMT;
    ufd[0].events = POLLIN;

    switch( vlc_poll_i11e(ufd, 1, sys->timeout) )
    {
        case 0:
            msg_Err(p_access, "AMT relay advertisement receive time-out");
            /* fall through */
        case -1:
            return false;
    }

    struct sockaddr temp;
    uint32_t temp_size = sizeof( struct sockaddr );
    ssize_t len = recvfrom( sys->sAMT, &pkt, RELAY_ADV_MSG_LEN, 0, &temp, &temp_size );

    if (len < 0)
    {
        msg_Err(p_access, "Received message length less than zero");
        return false;
    }

    memcpy( (void*)&sys->relay_adv_msg.type, &pkt[0], MSG_TYPE_LEN );
    if( sys->relay_adv_msg.type != AMT_RELAY_ADV )
    {
        msg_Err( p_access, "Received message not an AMT relay advertisement, ignoring. ");
        return false;
    }

    memcpy( (void*)&sys->relay_adv_msg.ulRcvNonce, &pkt[NONCE_LEN], NONCE_LEN );
    if( sys->glob_ulNonce != sys->relay_adv_msg.ulRcvNonce )
    {
        msg_Err( p_access, "Discovery nonces differ! currNonce:%x rcvd%x", sys->glob_ulNonce, ntohl(sys->relay_adv_msg.ulRcvNonce) );
        return false;
    }

    memcpy( (void*)&sys->relay_adv_msg.ipAddr, &pkt[8], 4 );

    memset( &sys->relayAddress, 0, sizeof(sys->relayAddress) );
    sys->relayAddress.sin_family       = AF_INET;
    sys->relayAddress.sin_addr.s_addr  = sys->relay_adv_msg.ipAddr;
    sys->relayAddress.sin_port         = htons( AMT_PORT );

    int nRet = connect( sys->sAMT, (struct sockaddr *)&sys->relayAddress, sizeof(sys->relayAddress) );
    if( nRet < 0 )
    {
        msg_Err( p_access, "Error connecting AMT UDP socket: %s", vlc_strerror(errno) );
        return false;
    }

    return true;
}

/**
 * Receive relay membership query message
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  V=0  |Type=4 | Reserved  |L|G|         Response MAC          |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                               +
   |                                                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                         Request Nonce                         |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                                                               |
   |               Encapsulated General Query Message              |
   ~                 IPv4:IGMPv3(Membership Query)                 ~
   |                  IPv6:MLDv2(Listener Query)                   |
   |                                                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |     Gateway Port Number       |                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                               +
   |                                                               |
   +                                                               +
   |                Gateway IP Address (IPv4 or IPv6)              |
   +                                                               +
   |                                                               |
   +                               +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */
bool amt_rcv_relay_mem_query( stream_t *p_access )
{
    char pkt[RELAY_QUERY_MSG_LEN];
    memset( &pkt, 0, RELAY_QUERY_MSG_LEN );
    struct pollfd ufd[1];
    access_sys_t *sys = p_access->p_sys;

    ufd[0].fd = sys->sAMT;
    ufd[0].events = POLLIN;

    switch( vlc_poll_i11e(ufd, 1, sys->timeout) )
    {
        case 0:
            msg_Err(p_access, "AMT relay membership query receive time-out");
            /* fall through */
        case -1:
            return false;
    }

    ssize_t len = recv( sys->sAMT, &pkt, RELAY_QUERY_MSG_LEN, 0 );

    if (len < 0)
    {
        msg_Err(p_access, "length less than zero");
        return false;
    }

    memcpy( (void*)&sys->relay_mem_query_msg.type, &pkt[0], MSG_TYPE_LEN );
    /* pkt[1] is reserved  */
    memcpy( (void*)&sys->relay_mem_query_msg.uchaMAC[0], &pkt[AMT_HDR_LEN], MAC_LEN );
    memcpy( (void*)&sys->relay_mem_query_msg.ulRcvedNonce, &pkt[AMT_HDR_LEN + MAC_LEN], NONCE_LEN );
    if( sys->relay_mem_query_msg.ulRcvedNonce != sys->glob_ulNonce )
    {
        msg_Warn( p_access, "Nonces are different rcvd: %x glob: %x", sys->relay_mem_query_msg.ulRcvedNonce, sys->glob_ulNonce );
        return false;
    }

    sys->glob_ulNonce = ntohl(sys->relay_mem_query_msg.ulRcvedNonce);

    int shift = AMT_HDR_LEN + MAC_LEN + NONCE_LEN;
    memcpy( (void*)&sys->relay_ip_hdr, (void*)&pkt[shift], IP_HDR_IGMP_LEN );

    shift += IP_HDR_IGMP_LEN;
    sys->relay_igmp_query.type = pkt[shift];
    shift++;
    sys->relay_igmp_query.max_resp_code = pkt[shift];
    shift++;
    memcpy( (void*)&sys->relay_igmp_query.checksum, &pkt[shift], 2 );
    shift += 2;
    memcpy( (void*)&sys->relay_igmp_query.ssmIP, &pkt[shift], 4 );
    shift += 4;
    sys->relay_igmp_query.s_qrv = pkt[shift];
    shift++;
    if( (int)pkt[shift] == 0 )
        sys->relay_igmp_query.qqic = 125;
    else if( (int)pkt[shift] < 128 )
        sys->relay_igmp_query.qqic = pkt[shift];
    else {
        int qqic;
        qqic = ((pkt[shift]&0x0f) + 0x10) << (((pkt[shift] >> 4)&0x07) + 3);
        sys->relay_igmp_query.qqic = qqic;
    }

    shift++;
    memcpy( (void*)&sys->relay_igmp_query.nSrc, &pkt[shift], 2 );
    if( sys->relay_igmp_query.nSrc != 0 )
    {
        shift += 2;
        memcpy( (void*)&sys->relay_igmp_query.srcIP, &pkt[shift], 4 );
    }

    /* if a membership thread exists cancel it */
    if( sys->threadReady )
    {
        msg_Dbg( p_access, "Cancelling existing AMT relay membership update thread");

        sys->threadReady = false;
        vlc_cancel( sys->updateThread );
        vlc_join( sys->updateThread, NULL );
    }

    msg_Dbg( p_access, "Spawning AMT relay membership update thread");

    if( vlc_clone( &sys->updateThread, amt_mem_upd, p_access, VLC_THREAD_PRIORITY_LOW) )
    {
        msg_Err( p_access, "Could not create AMT relay membership update thread" );
        return false;
    }

    /* set theadReady to true, thread will send periodic membership updates until false */
    sys->threadReady = true;
    return true;
}

/**
 * Join SSM group based on input addresses, or use the defaults
 * */
int amt_joinSSM_group( stream_t *p_access )
{
    struct ip_mreq_source imr;
    struct sockaddr_in temp;
    access_sys_t *sys = p_access->p_sys;

    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr.s_addr) );
    imr.imr_multiaddr.s_addr = temp.sin_addr.s_addr;

    inet_pton( AF_INET, sys->srcAddr, &(temp.sin_addr.s_addr) );
    imr.imr_sourceaddr.s_addr = temp.sin_addr.s_addr;
    imr.imr_interface.s_addr = INADDR_ANY;

    return setsockopt( sys->sAMT, IPPROTO_IP, IP_ADD_SOURCE_MEMBERSHIP, (char *)&imr, sizeof(imr) );
}

int amt_joinASM_group( stream_t *p_access )
{
    struct ip_mreq imr;
    struct sockaddr_in temp;
    access_sys_t *sys = p_access->p_sys;

    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr.s_addr) );
    imr.imr_multiaddr.s_addr = temp.sin_addr.s_addr;
    imr.imr_interface.s_addr = INADDR_ANY;

    return setsockopt( sys->sAMT, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&imr, sizeof(imr) );
}

/**
 * Leave SSM group that was joined earlier.
 * */
int amt_leaveSSM_group( stream_t *p_access )
{
    struct ip_mreq_source imr;
    struct sockaddr_in temp;
    access_sys_t *sys = p_access->p_sys;

    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr.s_addr) );
    imr.imr_multiaddr.s_addr = temp.sin_addr.s_addr;

    inet_pton( AF_INET, sys->srcAddr, &(temp.sin_addr.s_addr) );
    imr.imr_sourceaddr.s_addr = temp.sin_addr.s_addr;
    imr.imr_interface.s_addr = INADDR_ANY;

    return setsockopt( sys->sAMT, IPPROTO_IP, IP_DROP_SOURCE_MEMBERSHIP, (char *)&imr, sizeof(imr) );
}

int amt_leaveASM_group( stream_t *p_access )
{
    struct ip_mreq imr;
    struct sockaddr_in temp;
    access_sys_t *sys = p_access->p_sys;

    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr.s_addr) );
    imr.imr_multiaddr.s_addr = temp.sin_addr.s_addr;
    imr.imr_interface.s_addr = INADDR_ANY;

    return setsockopt( sys->sAMT, IPPROTO_IP, IP_DROP_MEMBERSHIP, (char *)&imr, sizeof(imr) );
}

void *amt_mem_upd( void *data )
{
    char          relay_ip[INET_ADDRSTRLEN];
    stream_t     *p_access = (stream_t*) data;
    access_sys_t *sys = p_access->p_sys;

    msg_Dbg( p_access, "AMT relay membership update thread started" );

    inet_ntop(AF_INET, &(sys->relayAddrDisco.sin_addr), relay_ip, INET_ADDRSTRLEN);
    
    /* thread sends periodic AMT membership updates until Close() which clears sys->threadReady and terminates thread */
    while ( sys->threadReady  )
    {
        amt_send_mem_update( p_access, relay_ip, false );
        vlc_tick_sleep( (vlc_tick_t)sys->relay_igmp_query.qqic * CLOCK_FREQ );
    }

    return NULL;
}
