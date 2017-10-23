#ifndef FAXDEV_H
#define FAXDEV_H

/* FAX device provider API definitions */

#IFNDEF COMMCTRL_H
	#include commctrl.h
#ENDIF

#define FS_INITIALIZING  0x20000000
#define FS_DIALING  0x20000001
#define FS_TRANSMITTING  0x20000002
#define FS_RECEIVING  0x20000004
#define FS_COMPLETED  0x20000008
#define FS_HANDLED  0x20000010
#define FS_LINE_UNAVAILABLE  0x20000020
#define FS_BUSY  0x20000040
#define FS_NO_ANSWER  0x20000080
#define FS_BAD_ADDRESS  0x20000100
#define FS_NO_DIAL_TONE  0x20000200
#define FS_DISCONNECTED  0x20000400
#define FS_FATAL_ERROR  0x20000800
#define FS_NOT_FAX_CALL  0x20001000
#define FS_CALL_DELAYED  0x20002000
#define FS_CALL_BLACKLISTED  0x20004000
#define FS_USER_ABORT  0x20200000
#define FS_ANSWERED  0x20800000

#define FAXDEVRECEIVE_SIZE  4096
#define FAXDEVREPORTSTATUS_SIZE  4096

FAX_SEND STRUCT
	SizeOfStruct DD
	FileName PTR
	CallerName PTR
	CallerNumber PTR
	ReceiverName PTR
	ReceiverNumber PTR
	Branding DD
	CallHandle HANDLE
	Reserved DD 3 DUP
ENDS

FAX_RECEIVE STRUCT
	SizeOfStruct DD
	FileName PTR
	ReceiverName PTR
	ReceiverNumber PTR
	Reserved DD 4 DUP
ENDS

FAX_DEV_STATUS STRUCT
	SizeOfStruct DD
	StatusId DD
	StringId DD
	PageCount DD
	CSI PTR
	CallerId PTR
	RoutingInfo PTR
	ErrorCode DD
	Reserved DD 3 DUP
ENDS

#endif /* FAXDEV_H */
