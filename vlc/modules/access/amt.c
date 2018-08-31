/**
 * @file amt.c
 * @brief Automatic Multicast Tunneling Protocol (AMT) file for VLC media player
 * Allows multicast streaming when not in a multicast-enabled network
 * Currently IPv4 is supported, but IPv6 is not yet.
 *
 * Copyright (C) 2018 VLC authors and VideoLAN
 * Copyright (c) Juniper Networks, Inc., 2018. All rights reserved.
 *
 * Authors: Christophe Massiot <massiot@via.ecp.fr>     - original UDP code
 *          Tristan Leteurtre <tooney@via.ecp.fr>       - original UDP code
 *          Laurent Aimar <fenrir@via.ecp.fr>           - original UDP code
 *          Jean-Paul Saman <jpsaman #_at_# m2x dot nl> - original UDP code
 *          Remi Denis-Courmont                         - original UDP code
 *          Natalie Landsberg natalie.landsberg97@gmail.com - AMT support
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
#define AMT_RELAY_ADDRESS N_("AMT relay address")
#define AMT_RELAY_ADDR_LONG N_("AMT relay anycast address, or specify the relay you want")

static int  Open (vlc_object_t *);
static void Close (vlc_object_t *);

vlc_module_begin ()
    set_shortname( N_("AMT" ) )
    set_description( N_("AMT input") )
    set_category( CAT_INPUT )
    set_subcategory( SUBCAT_INPUT_ACCESS )

    add_integer( "amt-timeout", 5, AMT_TIMEOUT_TEXT, NULL, true )
    add_integer( "amt-native-timeout", 3, TIMEOUT_TEXT, NULL, true )
    add_string( "amt-relay", "", AMT_RELAY_ADDRESS, AMT_RELAY_ADDR_LONG, true )

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
static block_t *BlockUDP(stream_t *access, bool *restrict eof)
{
    access_sys_t *sys = access->p_sys;

    block_t *pkt = block_Alloc(sys->mtu);
    char *amtpkt = malloc( DEFAULT_MTU );

    if (unlikely(pkt == NULL))
    {   /* OOM - dequeue and discard one packet */
        char dummy;
        recv(sys->fd, &dummy, 1, 0);
        return NULL;
    }

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
            msg_Err(access, "native multicast receive time-out");
            net_Close( sys->fd );
            if( !sys->tryAMT )
            {
                if( !open_amt_tunnel( sys, access ) )
                    goto error;
            }
            else
            {
                msg_Err(access, "AMT receive time-out");
                *eof = true;
            }
            /* fall through */
        case -1:
            goto error;
    }

    ssize_t len;
    if( sys->tryAMT )
    {
        len = recv( sys->sAMT, amtpkt, DEFAULT_MTU, 0 );

        if( len < 0 || amtpkt[0] != AMT_MULT_DATA )
            goto error;

        ssize_t shift = IP_HDR_LEN + UDP_HDR_LEN + AMT_HDR_LEN;

        if( len < shift )
        {
            msg_Err(access, "%zd bytes packet truncated (MTU was %zu)",
                len, sys->mtu);
            pkt->i_flags |= BLOCK_FLAG_CORRUPTED;
            sys->mtu = len;
        } else {
            len -= shift;
        }

        memcpy( pkt->p_buffer, &amtpkt[shift], len );
        free( amtpkt );
    }
    else
        len = recvmsg(sys->fd, &msg, 0);

#ifdef MSG_TRUNC
    if (msg.msg_flags & MSG_TRUNC)
    {
        msg_Err(access, "%zd bytes packet truncated (MTU was %zu)",
                len, sys->mtu);
        pkt->i_flags |= BLOCK_FLAG_CORRUPTED;
        sys->mtu = len;
    }
    else
#endif
        pkt->i_buffer = len;

    return pkt;

error:
    free( amtpkt );
    block_Release(pkt);
    return NULL;
}

/*****************************************************************************
 * Open: open the socket
 *****************************************************************************/
static int Open( vlc_object_t *p_this )
{
    stream_t     *p_access = (stream_t*)p_this;
    access_sys_t *sys;

    if( p_access->b_preparsing )
        return VLC_EGENERIC;

    sys = vlc_obj_malloc( p_this, sizeof( *sys ) );
    if( unlikely( sys == NULL ) )
    {
        free( sys );
        return VLC_ENOMEM;
    }

    p_access->p_sys = sys;

    /* Set up p_access */
    ACCESS_SET_CALLBACKS( NULL, BlockUDP, Control, NULL );

    if( !p_access->psz_location )
    {
        free( sys );
        return VLC_EGENERIC;
    }

    char *psz_name = strdup( p_access->psz_location );
    int  i_bind_port = 1234, i_server_port = 0;

    if( unlikely(psz_name == NULL) )
        goto error;

    /* Parse psz_name syntax :
     * [serveraddr[:serverport]][@[bindaddr]:[bindport]] */
    vlc_url_t url;

    if( vlc_UrlParse( &url, p_access->psz_url ) != 0 )
    {
        msg_Err( p_access, "Invalid URL" );
        vlc_UrlClean( &url );
        goto error;
    }

    if( url.i_port > 0 )
        i_bind_port = url.i_port;

    msg_Dbg( p_access, "opening server=%s:%d local=%s:%d",
             url.psz_host, i_server_port, url.psz_path, i_bind_port );

    if( url.psz_host == NULL || strlen( url.psz_host ) == 0 )
    {
        msg_Err( p_access, "Please enter a group and/or source address." );
        goto error;
    }
    sys->mcastGroup = strdup( url.psz_host );
    sys->srcAddr = strdup( strtok( psz_name, "@" ) );
    if( strcmp( url.psz_host, sys->srcAddr ) == 0 )
        strcpy(sys->srcAddr, "0.0.0.0");
    sys->relayAddr = var_InheritString( p_access, "amt-relay" );

    if( unlikely(sys->relayAddr == NULL ) )
    {
        msg_Err( p_access, "No relay anycast or unicast address specified." );
        goto error;
    }

    msg_Dbg( p_access, "Addresses: mcastGroup: %s srcAddr: %s relayAddr: %s", \
                sys->mcastGroup, sys->srcAddr, sys->relayAddr);

    sys->fd = net_OpenDgram( p_access, sys->mcastGroup, i_bind_port,
                             sys->srcAddr, i_server_port, IPPROTO_UDP );
    if( sys->fd == -1 )
    {
        msg_Err( p_access, "cannot open socket" );
        goto error;
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

    return VLC_SUCCESS;

error:
    free( psz_name );
    vlc_obj_free( p_this, sys );
    return VLC_EGENERIC;

}

/*****************************************************************************
 * Close: free unused data structures
 *****************************************************************************/
static void Close( vlc_object_t *p_this )
{
    stream_t     *p_access = (stream_t*)p_this;
    access_sys_t *sys = p_access->p_sys;

    if( strcmp(sys->srcAddr, "0.0.0.0") == 0 )
        amt_leaveASM_group( sys );
    else
        amt_leaveSSM_group( sys );
    amt_send_mem_update( sys, true );

    if( sys->threadReady )
    {
        sys->threadReady = false;
        vlc_cancel( sys->updateThread );
        vlc_join( sys->updateThread, NULL );
    }

    if( sys->mcastGroup != NULL )
        free( sys->mcastGroup );

    if( sys->srcAddr != NULL )
        free( sys->srcAddr );

    if( sys->relayAddr != NULL )
        free( sys->relayAddr );

    net_Close( sys->fd );
    net_Close( sys->sAMT );
    net_Close( sys->sQuery );
}


bool open_amt_tunnel( access_sys_t *sys, stream_t *access )
{
    msg_Dbg( access, "Attempting AMT...");
    sys->tryAMT = true;

    if( amt_sockets_init( sys, access ) != 0 )
    {
        msg_Err( access, "Error initializing sockets" );
        goto error;
    }

    amt_send_relay_discovery_msg( sys, access );
    msg_Dbg( access, "Sent AMT discovery message" );
    if( !amt_rcv_relay_adv( sys, access ) )
    {
        msg_Err( access, "Error receiving relay adv msg, skipping" );
        goto error;
    }

    msg_Dbg( access, "Received relay adv" );
    amt_send_relay_request( sys, access );

    if( !amt_rcv_relay_mem_query( sys, access ) )
    {
        msg_Err( access, "Could not receive relay membership query: %s", strerror(errno));
        goto error;
    }

    msg_Dbg( access, "Received mem query" );
    if( strcmp(sys->srcAddr, "") == 0 )
    {
        if( amt_joinASM_group( sys ) != 0 )
        {
            msg_Err( access, "Error joining SSM %s", strerror(errno) );
            goto error;
        }
        msg_Dbg( access, "Joined ASM group: %s", sys->mcastGroup );
    } else {
        if( amt_joinSSM_group( sys ) != 0 )
        {
            msg_Err( access, "Error joining SSM %s", strerror(errno) );
            goto error;
        }
        msg_Dbg( access, "Joined SSM src: %s group: %s", sys->srcAddr, sys->mcastGroup );
    }

    sys->queryTime = vlc_tick_now() / CLOCK_FREQ;

    return true;
error:
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
 * Make IGMP Membershipt report
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
int amt_sockets_init( access_sys_t *sys, stream_t *p_access )
{
    struct sockaddr_in rcvAddr;
    memset( &rcvAddr, 0, sizeof(struct sockaddr_in) );
    int enable = 0;

    /* Relay anycast address for discovery */
    sys->relayAddrDisco.sin_family = AF_INET;
    sys->relayAddrDisco.sin_port = htons( AMT_PORT );
    int res = inet_pton( AF_INET, sys->relayAddr, &sys->relayAddrDisco.sin_addr );
    if( res != 1 )
    {
        msg_Err( p_access, "Could not convert relay anycast" );
        goto error;
    }

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
        msg_Err( p_access, "Couldn't set socket options for IPPROTO_IP, IP_PKTINFO\n %s", strerror(errno));
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
        msg_Err( p_access, "Failed to bind UDP socket error: %s", strerror(errno) );
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
void amt_send_relay_discovery_msg( access_sys_t *sys, stream_t *p_access )
{
    char          chaSendBuffer[AMT_DISCO_MSG_LEN];
    unsigned int  ulNonce;
    int           nRet;

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
        msg_Err( p_access, "Sendto failed with error %d.", errno);

}

/**
 * Send relay request message, stage 2 of handshake
 * */
void amt_send_relay_request( access_sys_t *sys, stream_t *p_access )
{
    char chaSendBuffer[AMT_REQUEST_MSG_LEN];
    uint32_t ulNonce;
    int nRet;
    int nRetry;

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
        msg_Err(p_access, "Error sending relay request error: %s", strerror(errno) );
}

/*
* create AMT request message format
* +----------------------------------------------------------------------------------+
* | Msg Type(1 byte)| Reserved (1 byte)| MAC (6 byte)| nonce (4 byte) | IGMP packet  |
* +----------------------------------------------------------------------------------+
*/
void amt_send_mem_update( access_sys_t *sys, bool leave)
{
    int sendBufSize = IP_HDR_IGMP_LEN + MAC_LEN + NONCE_LEN + AMT_HDR_LEN;
    char pSendBuffer[ sendBufSize + IGMP_REPORT_LEN ];
    uint32_t ulNonce = 0;
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
bool amt_rcv_relay_adv( access_sys_t *sys, stream_t *p_access )
{
    char pkt[RELAY_ADV_MSG_LEN];
    memset( &pkt, 0, RELAY_ADV_MSG_LEN );

    struct pollfd ufd[1];

    ufd[0].fd = sys->sAMT;
    ufd[0].events = POLLIN;

    switch( vlc_poll_i11e(ufd, 1, sys->timeout) )
    {
        case 0:
            msg_Err(p_access, "relay adv receive time-out");
            /* fall through */
        case -1:
            return false;
    }

    struct sockaddr temp;
    uint32_t temp_size = sizeof( struct sockaddr );
    ssize_t len = recvfrom( sys->sAMT, &pkt, RELAY_ADV_MSG_LEN, 0, &temp, &temp_size );

    if (len < 0)
    {
        msg_Err(p_access, "length less than zero");
        return false;
    }

    memcpy( (void*)&sys->relay_adv_msg.type, &pkt[0], MSG_TYPE_LEN );
    if( sys->relay_adv_msg.type != AMT_RELAY_ADV )
    {
        msg_Err( p_access, "Received message not relay advertisement, ignoring. ");
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
        msg_Err( p_access, "Error connecting AMT UDP socket: %s", strerror(errno) );
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
bool amt_rcv_relay_mem_query( access_sys_t *sys, stream_t *p_access )
{
    char pkt[RELAY_QUERY_MSG_LEN];
    memset( &pkt, 0, RELAY_QUERY_MSG_LEN );

    struct pollfd ufd[1];

    ufd[0].fd = sys->sAMT;
    ufd[0].events = POLLIN;

    switch( vlc_poll_i11e(ufd, 1, sys->timeout) )
    {
        case 0:
            msg_Err(p_access, "mem query receive time-out");
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

    if( vlc_clone( &sys->updateThread, amt_mem_upd, sys, VLC_THREAD_PRIORITY_LOW) )
    {
        msg_Err( p_access, "Could not create update thread" );
        return false;
    }

    sys->threadReady = true;
    return true;
}

/**
 * Join SSM group based on input addresses, or use the defaults
 * */
int amt_joinSSM_group( access_sys_t *sys )
{
    struct ip_mreq_source imr;
    struct sockaddr_in temp;
    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr.s_addr) );
    imr.imr_multiaddr.s_addr = temp.sin_addr.s_addr;

    inet_pton( AF_INET, sys->srcAddr, &(temp.sin_addr.s_addr) );
    imr.imr_sourceaddr.s_addr = temp.sin_addr.s_addr;
    imr.imr_interface.s_addr = INADDR_ANY;

    return setsockopt( sys->sAMT, IPPROTO_IP, IP_ADD_SOURCE_MEMBERSHIP, (char *)&imr, sizeof(imr) );
}

int amt_joinASM_group( access_sys_t *sys )
{
    struct ip_mreq imr;
    struct sockaddr_in temp;

    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr.s_addr) );
    imr.imr_multiaddr.s_addr = temp.sin_addr.s_addr;
    imr.imr_interface.s_addr = INADDR_ANY;

    return setsockopt( sys->sAMT, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&imr, sizeof(imr) );
}

/**
 * Leave SSM group that was joined earlier.
 * */
int amt_leaveSSM_group( access_sys_t *sys )
{
    struct ip_mreq_source imr;
    struct sockaddr_in temp;
    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr.s_addr) );
    imr.imr_multiaddr.s_addr = temp.sin_addr.s_addr;

    inet_pton( AF_INET, sys->srcAddr, &(temp.sin_addr.s_addr) );
    imr.imr_sourceaddr.s_addr = temp.sin_addr.s_addr;
    imr.imr_interface.s_addr = INADDR_ANY;

    return setsockopt( sys->sAMT, IPPROTO_IP, IP_DROP_SOURCE_MEMBERSHIP, (char *)&imr, sizeof(imr) );
}

int amt_leaveASM_group( access_sys_t *sys )
{
    struct ip_mreq imr;
    struct sockaddr_in temp;

    inet_pton( AF_INET, sys->mcastGroup, &(temp.sin_addr.s_addr) );
    imr.imr_multiaddr.s_addr = temp.sin_addr.s_addr;
    imr.imr_interface.s_addr = INADDR_ANY;

    return setsockopt( sys->sAMT, IPPROTO_IP, IP_DROP_MEMBERSHIP, (char *)&imr, sizeof(imr) );
}

void *amt_mem_upd( void *data )
{
    access_sys_t *sys = data;
    for (;;)
    {
        if( !sys->threadReady )
            break;
        amt_send_mem_update( sys, false );
        vlc_tick_sleep( (vlc_tick_t)sys->relay_igmp_query.qqic * CLOCK_FREQ );
    }
    return NULL;
}