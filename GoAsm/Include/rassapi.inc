;=============================================================;
;          rassapi.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RASSAPI_INC
#Define RASSAPI_INC

#Define RASSAPI_MAX_PHONENUMBER_SIZE	128
#Define RASSAPI_MAX_MEDIA_NAME			16
#Define RASSAPI_MAX_PORT_NAME			16
#Define RASSAPI_MAX_DEVICE_NAME			128
#Define RASSAPI_MAX_DEVICETYPE_NAME		16
#Define RASSAPI_MAX_PARAM_KEY_SIZE		32

#Define RASPRIV_NoCallback				001H
#Define RASPRIV_AdminSetCallback		002H
#Define RASPRIV_CallerSetCallback		004H
#Define RASPRIV_DialinPrivilege			008H

#Define RAS_MODEM_OPERATIONAL			1
#Define RAS_MODEM_NOT_RESPONDING		2
#Define RAS_MODEM_HARDWARE_FAILURE		3
#Define RAS_MODEM_INCORRECT_RESPONSE	4
#Define RAS_MODEM_UNKNOWN				5

#Define RAS_PORT_NON_OPERATIONAL		1
#Define RAS_PORT_DISCONNECTED			2
#Define RAS_PORT_CALLING_BACK			3
#Define RAS_PORT_LISTENING				4
#Define RAS_PORT_AUTHENTICATING			5
#Define RAS_PORT_AUTHENTICATED			6
#Define RAS_PORT_INITIALIZING			7

;RAS_PARAMS_FORMAT enumeration
ParamNumber								Equ 0
ParamString								Equ 1

#Define MEDIA_UNKNOWN					0
#Define MEDIA_SERIAL					1
#Define MEDIA_RAS10_SERIAL				2
#Define MEDIA_X25						3
#Define MEDIA_ISDN						4


#Define USER_AUTHENTICATED    			00001H
#Define MESSENGER_PRESENT     			00002H
#Define PPP_CLIENT            			00004H
#Define GATEWAY_ACTIVE        			00008H
#Define REMOTE_LISTEN         			00010H
#Define PORT_MULTILINKED      			00020H

#Define RAS_IPADDRESSLEN				15
#Define RAS_IPXADDRESSLEN				22
#Define RAS_ATADDRESSLEN				32

#Define RASDOWNLEVEL       				10
#Define RASADMIN_35        				35
#Define RASADMIN_CURRENT   				40


RAS_PARAMS_VALUE Union
	Number DD
	String Struct
		Length DD
		Data DD
	EndS
EndS

RAS_PARAMETERS Struct
	P_Key DB RASSAPI_MAX_PARAM_KEY_SIZE Dup ?
	P_Type DD
	P_Attributes  DB
	P_Value RAS_PARAMS_VALUE <>
EndS

RAS_USER_0	Struct
	bfPrivilege DB
	szPhoneNumber DW (RASSAPI_MAX_PHONENUMBER_SIZE + 1) Dup ?
EndS

RAS_PORT_0 Struct
	wszPortName DW RASSAPI_MAX_PORT_NAME Dup ?
	wszDeviceType DW RASSAPI_MAX_DEVICETYPE_NAME Dup ?
	wszDeviceName DW RASSAPI_MAX_DEVICE_NAME Dup ?
	wszMediaName DW RASSAPI_MAX_MEDIA_NAME Dup ?
	reserved DD
	Flags DD
	wszUserName DW (UNLEN + 1 Dup) ?
	wszComputer DW NETBIOS_NAME_LEN Dup ?
	dwStartSessionTime DD
	wszLogonDomain DW (DNLEN + 1) Dup ?
	fAdvancedServer DD
EndS

RAS_PPP_NBFCP_RESULT Struct
	dwError DD
	dwNetBiosError DD
	szName DB (NETBIOS_NAME_LEN + 1) Dup ?
	wszWksta DW (NETBIOS_NAME_LEN + 1) Dup ?
EndS

RAS_PPP_IPCP_RESULT Struct
	dwError DD
	wszAddress DW (RAS_IPADDRESSLEN + 1) Dup ?
EndS

RAS_PPP_IPXCP_RESULT Struct
	dwError DD
	wszAddress DW (RAS_IPXADDRESSLEN + 1) Dup ?
EndS

RAS_PPP_ATCP_RESULT Struct
	dwError DD
	wszAddress DW (RAS_ATADDRESSLEN + 1) Dup ?
EndS

RAS_PPP_PROJECTION_RESULT Struct
	nbf RAS_PPP_ATCP_RESULT <>
	ip RAS_PPP_ATCP_RESULT <>
	ipx RAS_PPP_ATCP_RESULT <>
	at RAS_PPP_ATCP_RESULT <>
EndS

RAS_PORT_1 Struct
	rasport0 RAS_PORT_0 <>
	LineCondition DD
	HardwareCondition DD
	LineSpeed DD
	NumStatistics DW
	NumMediaParms DW
	SizeMediaParms DD
	ProjResult RAS_PPP_PROJECTION_RESULT <>
EndS

RAS_PORT_STATISTICS Struct
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
EndS

RAS_SERVER_0 Struct
	TotalPorts DW
	PortsInUse DW
	RasVersion DD
EndS

#ENDIF ;RASSAPI_INC
