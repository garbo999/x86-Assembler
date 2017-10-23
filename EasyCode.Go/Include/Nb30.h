/*++

Copyright (c) 1991-1999  Microsoft Corporation

Module Name:

 nb30.h

Abstract:

 This module contains the definitions for portable NetBIOS 3.0
 support.

--*/

#ifndef NB30_H
#define NB30_H

#IFNDEF VISTA /* NetBIOS is not available in VISTA */

/****************************************************************
 *                                                              *
 *              Data structure templates                        *
 *                                                              *
 ****************************************************************/

#define NCBNAMSZ        16    /* absolute length of a net name           */
#define MAX_LANA       254    /* lana's in range 0 to MAX_LANA inclusive */

/*
 * Network Control Block
 */

NCB STRUCT
	ncb_command DB
	ncb_retcode DB
	ncb_lsn DB
	ncb_num DB
	ncb_buffer PTR
	ncb_length DW
	ncb_callname DB NCBNAMSZ DUP
	ncb_name DB NCBNAMSZ DUP
	ncb_rto DB
	ncb_sto DB
	ncb_post PTR
	ncb_lana_num DB
	ncb_cmd_cplt DB
	#ifdef WIN64
		ncb_reserve DB 18 DUP
	#else
		ncb_reserve DB 10 DUP
	#endif
	ncb_event HANDLE
ENDS

/*
 *  Structure returned to the NCB command NCBASTAT is ADAPTER_STATUS followed
 *  by an array of NAME_BUFFER structures.
 */

ADAPTER_STATUS STRUCT
	adapter_address DB 6 DUP
	rev_major DB
	reserved0 DB
	adapter_type DB
	rev_minor DB
	duration DW
	frmr_recv DW
	frmr_xmit DW

	iframe_recv_err DW

	xmit_aborts DW
	xmit_success DD
	recv_success DD

	iframe_xmit_err DW

	recv_buff_unavail DW
	t1_timeouts DW
	ti_timeouts DW
	reserved1 DD
	free_ncbs DW
	max_cfg_ncbs DW
	max_ncbs DW
	xmit_buf_unavail DW
	max_dgram_size DW
	pending_sess DW
	max_cfg_sess DW
	max_sess DW
	max_sess_pkt_size DW
	name_count DW
ENDS

NAME_BUFFER STRUCT
	name DB NCBNAMSZ DUP
	name_num DB
	name_flags DB
ENDS

/*  values for name_flags bits. */

#define NAME_FLAGS_MASK 0x87

#define GROUP_NAME      0x80
#define UNIQUE_NAME     0x00

#define REGISTERING     0x00
#define REGISTERED      0x04
#define DEREGISTERED    0x05
#define DUPLICATE       0x06
#define DUPLICATE_DEREG 0x07

/*
 *  Structure returned to the NCB command NCBSSTAT is SESSION_HEADER followed
 *  by an array of SESSION_BUFFER structures. If the NCB_NAME starts with an
 *  asterisk then an array of these structures is returned containing the
 *  status for all names.
 */

SESSION_HEADER STRUCT
	sess_name DB
	num_sess DB
	rcv_dg_outstanding DB
	rcv_any_outstanding DB
ENDS

SESSION_BUFFER STRUCT
	lsn DB
	state DB
	local_name DB NCBNAMSZ DUP
	remote_name DB NCBNAMSZ DUP
	rcvs_outstanding DB
	sends_outstanding DB
ENDS

/*  Values for state */

#define LISTEN_OUTSTANDING      0x01
#define CALL_PENDING            0x02
#define SESSION_ESTABLISHED     0x03
#define HANGUP_PENDING          0x04
#define HANGUP_COMPLETE         0x05
#define SESSION_ABORTED         0x06

/*
 *  Structure returned to the NCB command NCBENUM.
 *
 *  On a system containing lana's 0, 2 and 3, a structure with
 *  length =3, lana[0]=0, lana[1]=2 and lana[2]=3 will be returned.
 */

LANA_ENUM STRUCT
	length DB
	lana DB MAX_LANA+1 DUP
ENDS

/*
 *  Structure returned to the NCB command NCBFINDNAME is FIND_NAME_HEADER followed
 *  by an array of FIND_NAME_BUFFER structures.
 */

FIND_NAME_HEADER STRUCT
	node_count DW
	reserved DB
	unique_group DB
ENDS

FIND_NAME_BUFFER STRUCT
	length DB
	access_control DB
	frame_control DB
	destination_addr DB 6 DUP
	source_addr DB 6 DUP
	routing_info DB 18 DUP
ENDS

/*
 *  Structure provided with NCBACTION. The purpose of NCBACTION is to provide
 *  transport specific extensions to netbios.
 */

ACTION_HEADER STRUCT
	transport_id DD
	action_code DW
	reserved DW
ENDS

/*  Values for transport_id */

#define ALL_TRANSPORTS  "M\0\0\0"
#define MS_NBF          "MNBF"


/****************************************************************
 *                                                              *
 *              Special values and constants                    *
 *                                                              *
 ****************************************************************/

/*
 *      NCB Command codes
 */

#define NCBCALL         0x10            /* NCB CALL                           */
#define NCBLISTEN       0x11            /* NCB LISTEN                         */
#define NCBHANGUP       0x12            /* NCB HANG UP                        */
#define NCBSEND         0x14            /* NCB SEND                           */
#define NCBRECV         0x15            /* NCB RECEIVE                        */
#define NCBRECVANY      0x16            /* NCB RECEIVE ANY                    */
#define NCBCHAINSEND    0x17            /* NCB CHAIN SEND                     */
#define NCBDGSEND       0x20            /* NCB SEND DATAGRAM                  */
#define NCBDGRECV       0x21            /* NCB RECEIVE DATAGRAM               */
#define NCBDGSENDBC     0x22            /* NCB SEND BROADCAST DATAGRAM        */
#define NCBDGRECVBC     0x23            /* NCB RECEIVE BROADCAST DATAGRAM     */
#define NCBADDNAME      0x30            /* NCB ADD NAME                       */
#define NCBDELNAME      0x31            /* NCB DELETE NAME                    */
#define NCBRESET        0x32            /* NCB RESET                          */
#define NCBASTAT        0x33            /* NCB ADAPTER STATUS                 */
#define NCBSSTAT        0x34            /* NCB SESSION STATUS                 */
#define NCBCANCEL       0x35            /* NCB CANCEL                         */
#define NCBADDGRNAME    0x36            /* NCB ADD GROUP NAME                 */
#define NCBENUM         0x37            /* NCB ENUMERATE LANA NUMBERS         */
#define NCBUNLINK       0x70            /* NCB UNLINK                         */
#define NCBSENDNA       0x71            /* NCB SEND NO ACK                    */
#define NCBCHAINSENDNA  0x72            /* NCB CHAIN SEND NO ACK              */
#define NCBLANSTALERT   0x73            /* NCB LAN STATUS ALERT               */
#define NCBACTION       0x77            /* NCB ACTION                         */
#define NCBFINDNAME     0x78            /* NCB FIND NAME                      */
#define NCBTRACE        0x79            /* NCB TRACE                          */


#define ASYNCH          0x80            /* high bit set == asynchronous       */

/*
 *      NCB Return codes
 */

#define NRC_GOODRET     0x00    /* good return                                */
                                /* also returned when ASYNCH request accepted */
#define NRC_BUFLEN      0x01    /* illegal buffer length                      */
#define NRC_ILLCMD      0x03    /* illegal command                            */
#define NRC_CMDTMO      0x05    /* command timed out                          */
#define NRC_INCOMP      0x06    /* message incomplete, issue another command  */
#define NRC_BADDR       0x07    /* illegal buffer address                     */
#define NRC_SNUMOUT     0x08    /* session number out of range                */
#define NRC_NORES       0x09    /* no resource available                      */
#define NRC_SCLOSED     0x0a    /* session closed                             */
#define NRC_CMDCAN      0x0b    /* command cancelled                          */
#define NRC_DUPNAME     0x0d    /* duplicate name                             */
#define NRC_NAMTFUL     0x0e    /* name table full                            */
#define NRC_ACTSES      0x0f    /* no deletions, name has active sessions     */
#define NRC_LOCTFUL     0x11    /* local session table full                   */
#define NRC_REMTFUL     0x12    /* remote session table full                  */
#define NRC_ILLNN       0x13    /* illegal name number                        */
#define NRC_NOCALL      0x14    /* no callname                                */
#define NRC_NOWILD      0x15    /* cannot put * in NCB_NAME                   */
#define NRC_INUSE       0x16    /* name in use on remote adapter              */
#define NRC_NAMERR      0x17    /* name deleted                               */
#define NRC_SABORT      0x18    /* session ended abnormally                   */
#define NRC_NAMCONF     0x19    /* name conflict detected                     */
#define NRC_IFBUSY      0x21    /* interface busy, IRET before retrying       */
#define NRC_TOOMANY     0x22    /* too many commands outstanding, retry later */
#define NRC_BRIDGE      0x23    /* ncb_lana_num field invalid                 */
#define NRC_CANOCCR     0x24    /* command completed while cancel occurring   */
#define NRC_CANCEL      0x26    /* command not valid to cancel                */
#define NRC_DUPENV      0x30    /* name defined by anther local process       */
#define NRC_ENVNOTDEF   0x34    /* environment undefined. RESET required      */
#define NRC_OSRESNOTAV  0x35    /* required OS resources exhausted            */
#define NRC_MAXAPPS     0x36    /* max number of applications exceeded        */
#define NRC_NOSAPS      0x37    /* no saps available for netbios              */
#define NRC_NORESOURCES 0x38    /* requested resources are not available      */
#define NRC_INVADDRESS  0x39    /* invalid ncb address or length > segment    */
#define NRC_INVDDID     0x3B    /* invalid NCB DDID                           */
#define NRC_LOCKFAIL    0x3C    /* lock of user area failed                   */
#define NRC_OPENERR     0x3f    /* NETBIOS not loaded                         */
#define NRC_SYSTEM      0x40    /* system error                               */

#define NRC_PENDING     0xff    /* asynchronous command is not yet finished   */

#endif /* VISTA */

#endif /* NCB_INCLUDED */

