/*****************************************************************************
 * @file amt.h
 * @brief AMT access module structs
 *
 * Some of this code was pulled from or based off Cisco's open-source
 * SSMAMTtools repo.
 * Copyright (c) Juniper Networks, Inc., 2018 - 2018. All rights reserved.
 *
 * This code is licensed to you under the GNU Lesser General Public License
 * version 2.1 or later. You may not use this code except in compliance with
 * the GNU Lesser General Public License.
 * This code is not an official Juniper product.
 *
 * Authors: Natalie Landsberg <nlandsberg@juniper.net>
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

/*****************************************************************************
 * Various Lengths of Msgs or Hdrs
 *****************************************************************************/
#define MAC_LEN 6                /* length of generated MAC in bytes */
#define NONCE_LEN 4              /* length of nonce in bytes */

#define MSG_TYPE_LEN 1           /* length of msg type */
#define RELAY_QUERY_MSG_LEN 48   /* total length of relay query */
#define RELAY_ADV_MSG_LEN 12     /* length of relay advertisement message */
#define IGMP_QUERY_LEN 24        /* length of encapsulated IGMP query message */
#define IGMP_REPORT_LEN 20
#define AMT_HDR_LEN 2            /* length of AMT header on a packet */
#define IP_HDR_LEN 20            /* length of standard IP header */
#define IP_HDR_IGMP_LEN 24       /* length of IP header with an IGMP report */
#define UDP_HDR_LEN 8            /* length of standard UDP header */
#define AMT_REQUEST_MSG_LEN 9
#define AMT_DISCO_MSG_LEN 8

/*****************************************************************************
 * Different AMT Message Types
 *****************************************************************************/
#define AMT_RELAY_DISCO 1       /* relay discovery */
#define AMT_RELAY_ADV 2         /* relay advertisement */
#define AMT_REQUEST 3           /* request */
#define AMT_MEM_QUERY 4         /* membership query */
#define AMT_MEM_UPD 5           /* membership update */
#define AMT_MULT_DATA 6         /* multicast data */
#define AMT_TEARDOWN 7          /* teardown (not currently supported) */

/*****************************************************************************
 * Different IGMP Message Types
 *****************************************************************************/
#define AMT_IGMPV3_MEMBERSHIP_QUERY_TYPEID 0x11
#define AMT_IGMPV3_MEMBERSHIP_REPORT_TYPEID 0x22
/* IGMPv2, interoperability  */
#define AMT_IGMPV1_MEMBERSHIP_REPORT_TYPEID 0x12
#define AMT_IGMPV2_MEMBERSHIP_REPORT_TYPEID 0x16
#define AMT_IGMPV2_MEMBERSHIP_LEAVE_TYPEID 0x17

#define AMT_IGMP_INCLUDE 0x01
#define AMT_IGMP_EXCLUDE 0x02
#define AMT_IGMP_INCLUDE_CHANGE 0x03
#define AMT_IGMP_EXCLUDE_CHANGE 0x04
#define AMT_IGMP_ALLOW 0x05
#define AMT_IGMP_BLOCK 0x06

#define MCAST_ALLHOSTS "224.0.0.22"
#define AMT_PORT 2268

#define DEFAULT_MTU (1500u - (20 + 8))

typedef struct access_sys_t access_sys_t;

typedef struct _amt_ip {
    uint8_t  ver_ihl;
    uint8_t  tos;
    uint16_t tot_len;
    uint16_t id;
    uint16_t frag_off;
    uint8_t  ttl;
    uint8_t  protocol;
    uint16_t check;
    uint32_t srcAddr;
    uint32_t destAddr;
} amt_ip_t;

typedef struct _amt_ip_alert {
    uint8_t  ver_ihl;
    uint8_t   tos;
    uint16_t tot_len;
    uint16_t id;
    uint16_t frag_off;
    uint8_t  ttl;
    uint8_t  protocol;
    uint16_t check;
    uint32_t srcAddr;
    uint32_t destAddr;
    uint32_t options;
} amt_ip_alert_t;

typedef struct _amt_igmpv3_groupRecord {
    uint8_t type;
    uint8_t auxDatalen;
    uint16_t nSrc;
    uint32_t ssm;
    uint32_t srcIP[1];
} amt_igmpv3_groupRecord_t;

typedef struct _amt_igmpv3_membership_report {
    uint8_t  type;
    uint8_t  resv;
    uint16_t checksum;
    uint16_t resv2;
    uint16_t nGroupRecord;
    amt_igmpv3_groupRecord_t grp[1];
} amt_igmpv3_membership_report_t;

typedef struct _amt_igmpv3_membership_query {
    uint8_t  type;
    uint8_t  max_resp_code;  /* in 100ms, Max Resp Time = (mant | 0x10) << (exp + 3) */
    uint32_t checksum;
    uint32_t   ssmIP;
    uint8_t  s_qrv;
    uint8_t  qqic;           /* in second, query Time = (mant | 0x10) << (exp + 3) */
    uint16_t nSrc;
    uint32_t srcIP[1];
} amt_igmpv3_membership_query_t;

typedef struct _amt_membership_update_msg {
    amt_ip_alert_t ipHead;
    amt_igmpv3_membership_report_t memReport;
} amt_membership_update_msg_t;

typedef struct _amt_udpHdr {
    uint16_t srcPort;
    uint16_t dstPort;
    uint16_t len;
    uint16_t check;
} amt_udpHdr_t;

typedef struct _amt_multicast_data {
    uint8_t   type;
    uint8_t   resv;
    amt_ip_t        ip;
    amt_udpHdr_t    udp;
    uint8_t   *buf;
} amt_multicast_data_t;

/* AMT Functions */
int amt_sockets_init( access_sys_t *sys, stream_t *p_access );
void amt_send_relay_discovery_msg( access_sys_t *sys, stream_t *p_access );
void amt_send_relay_request( access_sys_t *sys, stream_t *p_access );
int amt_joinSSM_group( access_sys_t *sys );
int amt_joinASM_group( access_sys_t *sys );
int amt_leaveASM_group( access_sys_t *sys );
int amt_leaveSSM_group( access_sys_t *sys );
bool amt_rcv_relay_adv( access_sys_t *sys, stream_t *p_access );
bool amt_rcv_relay_mem_query( access_sys_t *sys, stream_t *p_access );
void amt_send_mem_update( access_sys_t *sys, bool leave );
bool open_amt_tunnel( access_sys_t *sys, stream_t *access );
void *amt_mem_upd( void *data );

/* Utility functions */
unsigned short getChecksum( unsigned short *buffer, int nLen );
void makeReport( amt_igmpv3_membership_report_t *mr );
void makeIPHeader( amt_ip_alert_t *p_ipHead );

struct access_sys_t
{
    int fd;
    int sAMT;
    int sQuery;
    int timeout;
    int amtTimeout;
    size_t mtu;
    bool tryAMT;
    bool threadReady;

    vlc_thread_t updateThread;
    vlc_tick_t queryTime;

    char *mcastGroup;
    char *srcAddr;
    char *relayAddr;

    struct sockaddr_in relayAddrDisco;
    struct sockaddr_in relayAddress;
    struct sockaddr_in stLocalAddr;
    struct sockaddr_in stSvrAddr;

    uint32_t glob_ulNonce;
    uint32_t ulRelayNonce;

    struct relay_mem_query_msg_t {
        uint8_t type;
        uint32_t  ulRcvedNonce;
        uint8_t uchaMAC[MAC_LEN];
        uint8_t uchaIGMP[IGMP_QUERY_LEN];
    } relay_mem_query_msg;

    struct relay_adv_msg_t {
        uint8_t type;
        uint32_t ulRcvNonce;
        uint32_t ipAddr;
    } relay_adv_msg;

    amt_ip_t relay_ip_hdr;
    amt_igmpv3_membership_query_t relay_igmp_query;
};