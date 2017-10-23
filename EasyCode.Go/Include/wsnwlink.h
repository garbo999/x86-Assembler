#ifndef WSNWLINK_H
#define WSNWLINK_H

/* MS extensions to Windows NT IPX/SPX Windows Sockets interface */

#define IPX_PTYPE  0x4000
#define IPX_FILTERPTYPE  0x4001
#define IPX_STOPFILTERPTYPE  0x4003
#define IPX_DSTYPE  0x4002
#define IPX_EXTENDED_ADDRESS  0x4004
#define IPX_RECVHDR  0x4005
#define IPX_MAXSIZE  0x4006
#define IPX_ADDRESS  0x4007
#define IPX_GETNETINFO  0x4008
#define IPX_GETNETINFO_NORIP  0x4009
#define IPX_SPXGETCONNECTIONSTATUS  0x400B
#define IPX_ADDRESS_NOTIFY  0x400C
#define IPX_MAX_ADAPTER_NUM  0x400D
#define IPX_RERIPNETNUMBER  0x400E
#define IPX_RECEIVE_BROADCAST  0x400F
#define IPX_IMMEDIATESPXACK  0x4010

IPX_ADDRESS_DATA STRUCT
	adapternum DD
	netnum DB 4 DUP
	nodenum DB 6 DUP
	wan DB
	status DB
	maxpkt DD
	linkspeed DD
ENDS

IPX_NETNUM_DATA STRUCT
	netnum DB 4 DUP
	hopcount DW
	netdelay DW
	cardnum DD
	router DB 6 DUP
ENDS

IPX_SPXCONNSTATUS_DATA STRUCT
	ConnectionState DB
	WatchDogActive DB
	LocalConnectionId DW
	RemoteConnectionId DW
	LocalSequenceNumber DW
	LocalAckNumber DW
	LocalAllocNumber DW
	RemoteAckNumber DW
	RemoteAllocNumber DW
	LocalSocket DW
	ImmediateAddress DB 6 DUP
	RemoteNetwork DB 4 DUP
	RemoteNode DB 6 DUP
	RemoteSocket DW
	RetransmissionCount DW
	EstimatedRoundTripDelay DW
	RetransmittedPackets DW
	SuppressedPacket DW
ENDS

#endif
