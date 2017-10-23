#ifndef RASSAPI_H
#define RASSAPI_H

/* Remote Access admin API definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Rassapi.dll
#ENDIF

#ifndef LMCONS_H
	#include lmcons.h
#endif

#define RASSAPI_MAX_PHONENUMBER_SIZE  128
#define RASSAPI_MAX_MEDIA_NAME  16
#define RASSAPI_MAX_PORT_NAME  16
#define RASSAPI_MAX_DEVICE_NAME  128
#define RASSAPI_MAX_DEVICETYPE_NAME  16
#define RASSAPI_MAX_PARAM_KEY_SIZE  32

#define RASPRIV_NoCallback  0x01
#define RASPRIV_AdminSetCallback  0x02
#define RASPRIV_CallerSetCallback 0x04
#define RASPRIV_DialinPrivilege  0x08

#define RAS_MODEM_OPERATIONAL  1
#define RAS_MODEM_NOT_RESPONDING  2
#define RAS_MODEM_HARDWARE_FAILURE  3
#define RAS_MODEM_INCORRECT_RESPONSE 4
#define RAS_MODEM_UNKNOWN  5

#define RAS_PORT_NON_OPERATIONAL 1
#define RAS_PORT_DISCONNECTED  2
#define RAS_PORT_CALLING_BACK  3
#define RAS_PORT_LISTENING  4
#define RAS_PORT_AUTHENTICATING  5
#define RAS_PORT_AUTHENTICATED  6
#define RAS_PORT_INITIALIZING  7

#define MEDIA_UNKNOWN  0
#define MEDIA_SERIAL  1
#define MEDIA_RAS10_SERIAL  2
#define MEDIA_X25  3
#define MEDIA_ISDN  4

#define USER_AUTHENTICATED  0x0001
#define MESSENGER_PRESENT  0x0002
#define PPP_CLIENT  0x0004
#define GATEWAY_ACTIVE  0x0008
#define REMOTE_LISTEN  0x0010
#define PORT_MULTILINKED  0x0020

#define RAS_IPADDRESSLEN  15
#define RAS_IPXADDRESSLEN  22
#define RAS_ATADDRESSLEN  32

#define RASDOWNLEVEL  10
#define RASADMIN_35  35
#define RASADMIN_CURRENT  40

ParamNumber = 0
ParamString = 1

RAS_PARAMS_VALUE STRUCT
	UNION
	Number DD
	String STRUCT
		Length DD
		Data PTR
	ENDS
	ENDUNION
ENDS

RAS_PARAMETERS STRUCT
	P_Key DB RASSAPI_MAX_PARAM_KEY_SIZE DUP
	P_Type DD
	P_Attributes DB
	P_Value RAS_PARAMS_VALUE <>
ENDS

#ifndef RAS_USER_0
	RAS_USER_0 STRUCT
		bfPrivilege DB
		szPhoneNumber DW RASSAPI_MAX_PHONENUMBER_SIZE+1 DUP
	ENDS
#endif

#ifndef RAS_PORT_0
	RAS_PORT_0 STRUCT
		wszPortName DW RASSAPI_MAX_PORT_NAME DUP
		wszDeviceType DW RASSAPI_MAX_DEVICETYPE_NAME DUP
		wszDeviceName DW RASSAPI_MAX_DEVICE_NAME DUP
		wszMediaName DW RASSAPI_MAX_MEDIA_NAME DUP
		reserved DD
		Flags DD
		wszUserName DW UNLEN+1 DUP
		wszComputer DW NETBIOS_NAME_LEN DUP
		dwStartSessionTime DD
		wszLogonDomain DW DNLEN+1 DUP
		fAdvancedServer DD
	ENDS
#endif

RAS_PPP_NBFCP_RESULT STRUCT
	dwError DD
	dwNetBiosError DD
	szName DB NETBIOS_NAME_LEN+1 DUP
	wszWksta DW NETBIOS_NAME_LEN+1 DUP
ENDS

RAS_PPP_IPCP_RESULT STRUCT
	dwError DD
	wszAddress DW RAS_IPADDRESSLEN+1 DUP
ENDS

RAS_PPP_IPXCP_RESULT STRUCT
	dwError DD
	wszAddress DW RAS_IPXADDRESSLEN+1 DUP
ENDS

RAS_PPP_ATCP_RESULT STRUCT
	dwError DD
	wszAddress DW RAS_ATADDRESSLEN+1 DUP
ENDS

RAS_PPP_PROJECTION_RESULT STRUCT
	nbf RAS_PPP_NBFCP_RESULT <>
	ip RAS_PPP_IPCP_RESULT <>
	ipx RAS_PPP_IPXCP_RESULT <>
	at RAS_PPP_ATCP_RESULT <>
ENDS

#ifndef RAS_PORT_1
	RAS_PORT_1 STRUCT
		rasport0 RAS_PORT_0 <>
		LineCondition DD
		HardwareCondition DD
		LineSpeed DD
		NumStatistics DW
		NumMediaParms DW
		SizeMediaParms DD
		ProjResult RAS_PPP_PROJECTION_RESULT <>
	ENDS
#endif

RAS_PORT_STATISTICS STRUCT
	dwBytesXmited DD
	dwBytesRcved DD
	dwFramesXmited DD
	dwFramesRcved DD
	dwCrcErr DD
	dwTimeoutErr DD
	dwAlignmentErr DD
	dwHardwareOverrunErr DD
	dwFramingErr DD
	dwBufferOverrunErr DD
	dwBytesXmitedUncompressed DD
	dwBytesRcvedUncompressed DD
	dwBytesXmitedCompressed DD
	dwBytesRcvedCompressed DD
	dwPortBytesXmited DD
	dwPortBytesRcved DD
	dwPortFramesXmited DD
	dwPortFramesRcved DD
	dwPortCrcErr DD
	dwPortTimeoutErr DD
	dwPortAlignmentErr DD
	dwPortHardwareOverrunErr DD
	dwPortFramingErr DD
	dwPortBufferOverrunErr DD
	dwPortBytesXmitedUncompressed DD
	dwPortBytesRcvedUncompressed DD
	dwPortBytesXmitedCompressed DD
	dwPortBytesRcvedCompressed DD
ENDS

RAS_SERVER_0 STRUCT
	TotalPorts DW
	PortsInUse DW
	RasVersion DD
ENDS

#endif
