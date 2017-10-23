#ifndef MPRAPI_H
#define MPRAPI_H

/* MPR definitions */
#IFNDEF LMCONS_H
	#include lmcons.h
#ENDIF
#IFNDEF RAS_H
	#include ras.h
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile Mprapi.dll
#ENDIF

#define RRAS_SERVICE_NAME  "RemoteAccess"

#define PID_IPX  0x0000002B
#define PID_IP  0x00000021
#define PID_NBF  0x0000003F
#define PID_ATALK  0x00000029

#define MAX_INTERFACE_NAME_LEN  256
#define MAX_TRANSPORT_NAME_LEN  40
#define MAX_MEDIA_NAME  16
#define MAX_PORT_NAME  16
#define MAX_DEVICE_NAME  128
#define MAX_PHONE_NUMBER_LEN  128
#define MAX_DEVICETYPE_NAME  16

#define MPR_INTERFACE_OUT_OF_RESOURCES  0x00000001
#define MPR_INTERFACE_ADMIN_DISABLED  0x00000002
#define MPR_INTERFACE_CONNECTION_FAILURE  0x00000004
#define MPR_INTERFACE_SERVICE_PAUSED  0x00000008
#define MPR_INTERFACE_DIALOUT_HOURS_RESTRICTION  0x00000010
#define MPR_INTERFACE_NO_MEDIA_SENSE  0x00000020
#define MPR_INTERFACE_NO_DEVICE  0x00000040

ROUTER_IF_TYPE_CLIENT = 0
ROUTER_IF_TYPE_HOME_ROUTER = 1
ROUTER_IF_TYPE_FULL_ROUTER = 2
ROUTER_IF_TYPE_DEDICATED = 3
ROUTER_IF_TYPE_INTERNAL = 4
ROUTER_IF_TYPE_LOOPBACK = 5
ROUTER_IF_TYPE_TUNNEL1 = 6
ROUTER_IF_TYPE_DIALOUT = 7

ROUTER_IF_STATE_UNREACHABLE = 0
ROUTER_IF_STATE_DISCONNECTED = 1
ROUTER_IF_STATE_CONNECTING = 2
ROUTER_IF_STATE_CONNECTED = 3

MPR_INTERFACE_0 STRUCT
	wszInterfaceName DW MAX_INTERFACE_NAME_LEN+1 DUP
	hInterface HANDLE
	fEnabled DD
	dwIfType DD
	dwConnectionState DD
	fUnReachabilityReasons DD
	dwLastError DD
ENDS

MPR_IPINIP_INTERFACE_0 STRUCT
	wszFriendlyName DW MAX_INTERFACE_NAME_LEN+1 DUP
	Guid GUID
ENDS

#define MPR_MaxDeviceType  RAS_MaxDeviceType
#define MPR_MaxPhoneNumber  RAS_MaxPhoneNumber
#define MPR_MaxIpAddress  RAS_MaxIpAddress
#define MPR_MaxIpxAddress  RAS_MaxIpxAddress

#define MPR_MaxEntryName  RAS_MaxEntryName
#define MPR_MaxDeviceName  RAS_MaxDeviceName
#define MPR_MaxCallbackNumber  RAS_MaxCallbackNumber

#define MPR_MaxAreaCode  RAS_MaxAreaCode
#define MPR_MaxPadType  RAS_MaxPadType
#define MPR_MaxX25Address  RAS_MaxX25Address
#define MPR_MaxFacilities  RAS_MaxFacilities
#define MPR_MaxUserData  RAS_MaxUserData

#define MPRIO_SpecificIpAddr  RASEO_SpecificIpAddr
#define MPRIO_SpecificNameServers  RASEO_SpecificNameServers
#define MPRIO_IpHeaderCompression  RASEO_IpHeaderCompression
#define MPRIO_RemoteDefaultGateway  RASEO_RemoteDefaultGateway
#define MPRIO_DisableLcpExtensions  RASEO_DisableLcpExtensions
#define MPRIO_SwCompression  RASEO_SwCompression
#define MPRIO_RequireEncryptedPw  RASEO_RequireEncryptedPw
#define MPRIO_RequireMsEncryptedPw  RASEO_RequireMsEncryptedPw
#define MPRIO_RequireDataEncryption  RASEO_RequireDataEncryption
#define MPRIO_NetworkLogon  RASEO_NetworkLogon
#define MPRIO_PromoteAlternates  RASEO_PromoteAlternates
#define MPRIO_SecureLocalFiles  RASEO_SecureLocalFiles
#define MPRIO_RequireEAP  RASEO_RequireEAP
#define MPRIO_RequirePAP  RASEO_RequirePAP
#define MPRIO_RequireSPAP  RASEO_RequireSPAP
#define MPRIO_SharedPhoneNumbers  RASEO_SharedPhoneNumbers
#define MPRIO_RequireCHAP  RASEO_RequireCHAP
#define MPRIO_RequireMsCHAP  RASEO_RequireMsCHAP

#define MPRNP_Ipx  RASNP_Ipx
#define MPRNP_Ip  RASNP_Ip

#define MPRDT_Modem  RASDT_Modem
#define MPRDT_Isdn  RASDT_Isdn
#define MPRDT_X25  RASDT_X25
#define MPRDT_Vpn  RASDT_Vpn
#define MPRDT_Pad  RASDT_Pad
#define MPRDT_Generic  RASDT_Generic
#define MPRDT_Serial  RASDT_Serial
#define MPRDT_FrameRelay  RASDT_FrameRelay
#define MPRDT_Atm  RASDT_Atm
#define MPRDT_Sonet  RASDT_Sonet
#define MPRDT_SW56  RASDT_SW56
#define MPRDT_Irda  RASDT_Irda
#define MPRDT_Parallel  RASDT_Parallel

#define MPRET_Phone  RASET_Phone
#define MPRET_Vpn  RASET_Vpn
#define MPRET_Direct  RASET_Direct

#define MPRDM_DialAll  RASEDM_DialAll
#define MPRDM_DialAsNeeded  RASEDM_DialAsNeeded

#define MPRIDS_Disabled  RASIDS_Disabled
#define MPRIDS_UseGlobalValue  RASIDS_UseGlobalValue

#define MPR_ET_None  ET_None
#define MPR_ET_Require  ET_Require
#define MPR_ET_RequireMax  ET_RequireMax
#define MPR_ET_Optional  ET_Optional

#define MPR_VS_Default  VS_Default
#define MPR_VS_PptpOnly  VS_PptpOnly
#define MPR_VS_PptpFirst  VS_PptpFirst
#define MPR_VS_L2tpOnly  VS_L2tpOnly
#define MPR_VS_L2tpFirst  VS_L2tpFirst

MPR_INTERFACE_1 STRUCT
	wszInterfaceName DW MAX_INTERFACE_NAME_LEN+1 DUP
	hInterface HANDLE
	fEnabled DD
	dwIfType DD
	dwConnectionState DD
	fUnReachabilityReasons DD
	dwLastError DD
	lpwsDialoutHoursRestriction PTR
ENDS

MPR_INTERFACE_2 STRUCT
	wszInterfaceName DW MAX_INTERFACE_NAME_LEN+1 DUP
	hInterface HANDLE
	fEnabled DD
	dwIfType DD
	dwConnectionState DD
	fUnReachabilityReasons DD
	dwLastError DD
	dwfOptions DD
	szLocalPhoneNumber DW RAS_MaxPhoneNumber+1 DUP
	szAlternates PTR
	ipaddr DD
	ipaddrDns DD
	ipaddrDnsAlt DD
	ipaddrWins DD
	ipaddrWinsAlt DD
	dwfNetProtocols DD
	szDeviceType DW MPR_MaxDeviceType+1 DUP
	szDeviceName DW MPR_MaxDeviceName+1 DUP
	szX25PadType DW MPR_MaxPadType+1 DUP
	szX25Address DW MPR_MaxX25Address+1 DUP
	szX25Facilities DW MPR_MaxFacilities+1 DUP
	szX25UserData DW MPR_MaxUserData+1 DUP
	dwChannels DD
	dwSubEntries DD
	dwDialMode DD
	dwDialExtraPercent DD
	dwDialExtraSampleSeconds DD
	dwHangUpExtraPercent DD
	dwHangUpExtraSampleSeconds DD
	dwIdleDisconnectSeconds DD
	dwType DD
	dwEncryptionType DD
	dwCustomAuthKey DD
	dwCustomAuthDataSize DD
	lpbCustomAuthData PTR
	guidId GUID
	dwVpnStrategy DD
ENDS

MPR_DEVICE_0 STRUCT
	szDeviceType DW MPR_MaxDeviceType+1 DUP
	szDeviceName DW MPR_MaxDeviceName+1 DUP
ENDS

MPR_DEVICE_1 STRUCT
	szDeviceType DW MPR_MaxDeviceType+1 DUP
	szDeviceName DW MPR_MaxDeviceName+1 DUP
	szLocalPhoneNumber DW MPR_MaxPhoneNumber+1 DUP
	szAlternates PTR
ENDS

MPR_CREDENTIALSEX_0  STRUCT
	dwSize DD
	lpbCredentialsInfo PTR
ENDS

MPR_TRANSPORT_0  STRUCT
	dwTransportId DD
	hTransport HANDLE
	wszTransportName DW MAX_TRANSPORT_NAME_LEN+1 DUP
ENDS

MPR_IFTRANSPORT_0  STRUCT
	dwTransportId DD
	hIfTransport HANDLE
	wszIfTransportName DW MAX_TRANSPORT_NAME_LEN+1 DUP
ENDS

MPR_SERVER_0 STRUCT
	fLanOnlyMode DD
	dwUpTime DD
	dwTotalPorts DD
	dwPortsInUse DD
ENDS

RAS_PORT_NON_OPERATIONAL = 0
RAS_PORT_DISCONNECTED = 1
RAS_PORT_CALLING_BACK = 2
RAS_PORT_LISTENING = 3
RAS_PORT_AUTHENTICATING = 4
RAS_PORT_AUTHENTICATED = 5
RAS_PORT_INITIALIZING = 6

RAS_HARDWARE_OPERATIONAL = 0
RAS_HARDWARE_FAILURE = 1

RAS_PORT_0 STRUCT
	hPort HANDLE
	hConnection HANDLE
	dwPortCondition DD
	dwTotalNumberOfCalls DD
	dwConnectDuration DD
	wszPortName DW MAX_PORT_NAME+1 DUP
	wszMediaName DW MAX_MEDIA_NAME+1 DUP
	wszDeviceName DW MAX_DEVICE_NAME+1 DUP
	wszDeviceType DW MAX_DEVICETYPE_NAME+1 DUP
ENDS

RAS_PORT_1 STRUCT
	hPort HANDLE
	hConnection HANDLE
	dwHardwareCondition DD
	dwLineSpeed DD
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
	dwCompressionRatioIn DD
	dwCompressionRatioOut DD
ENDS

#define IPADDRESSLEN  15
#define IPXADDRESSLEN  22
#define ATADDRESSLEN  32

PPP_NBFCP_INFO STRUCT
	dwError DD
	wszWksta DW NETBIOS_NAME_LEN+1 DUP
ENDS

PPP_IPCP_INFO STRUCT
	dwError DD
	wszAddress DW IPADDRESSLEN+1 DUP
	wszRemoteAddress DW IPADDRESSLEN+1 DUP
ENDS

#define PPP_IPCP_VJ  0x00000001

PPP_IPCP_INFO2 STRUCT
	dwError DD
	wszAddress DW IPADDRESSLEN+1 DUP
	wszRemoteAddress DW IPADDRESSLEN+1 DUP
	dwOptions DD
	dwRemoteOptions DD
ENDS

PPP_IPXCP_INFO STRUCT
	dwError DD
	wszAddress DW IPXADDRESSLEN+1 DUP
ENDS

PPP_ATCP_INFO STRUCT
	dwError DD
	wszAddress DW ATADDRESSLEN+1 DUP
ENDS

PPP_INFO STRUCT
	nbf PPP_NBFCP_INFO
	ip PPP_IPCP_INFO
	ipx PPP_IPXCP_INFO
	at PPP_ATCP_INFO
ENDS

#define RASCCPCA_MPPC  0x00000006
#define RASCCPCA_STAC  0x00000005

#define PPP_CCP_COMPRESSION  0x00000001
#define PPP_CCP_ENCRYPTION40BITOLD  0x00000010
#define PPP_CCP_ENCRYPTION40BIT  0x00000020
#define PPP_CCP_ENCRYPTION128BIT  0x00000040
#define PPP_CCP_ENCRYPTION56BIT  0x00000080
#define PPP_CCP_HISTORYLESS  0x01000000

#define PPP_LCP_PAP  0xC023
#define PPP_LCP_SPAP  0xC123
#define PPP_LCP_CHAP  0xC223
#define PPP_LCP_EAP  0xC227

#define PPP_LCP_CHAP_MD5  0x05
#define PPP_LCP_CHAP_MS  0x80
#define PPP_LCP_CHAP_MSV2  0x81

#define PPP_LCP_MULTILINK_FRAMING  0x00000001
#define PPP_LCP_PFC  0x00000002
#define PPP_LCP_ACFC  0x00000004
#define PPP_LCP_SSHF  0x00000008
#define PPP_LCP_DES_56  0x00000010
#define PPP_LCP_3_DES  0x00000020

PPP_CCP_INFO STRUCT
	dwError DD
	dwCompressionAlgorithm DD
	dwOptions DD
	dwRemoteCompressionAlgorithm DD
	dwRemoteOptions DD
ENDS

PPP_LCP_INFO STRUCT
	dwError DD
	dwAuthenticationProtocol DD
	dwAuthenticationData DD
	dwRemoteAuthenticationProtocol DD
	dwRemoteAuthenticationData DD
	dwTerminateReason DD
	dwRemoteTerminateReason DD
	dwOptions DD
	dwRemoteOptions DD
	dwEapTypeId DD
	dwRemoteEapTypeId DD
ENDS

PPP_INFO_2 STRUCT
	nbf PPP_NBFCP_INFO
	ip PPP_IPCP_INFO2
	ipx PPP_IPXCP_INFO
	at PPP_ATCP_INFO
	ccp PPP_CCP_INFO
	lcp PPP_LCP_INFO
ENDS

#define RAS_FLAGS_PPP_CONNECTION  0x00000001
#define RAS_FLAGS_MESSENGER_PRESENT  0x00000002
#define RAS_FLAGS_RAS_CONNECTION  0x00000004

RAS_CONNECTION_0 STRUCT
	hConnection HANDLE
	hInterface HANDLE
	dwConnectDuration DD
	dwInterfaceType DD
	dwConnectionFlags DD
	wszInterfaceName DW MAX_INTERFACE_NAME_LEN+1 DUP
	wszUserName DW UNLEN+1 DUP
	wszLogonDomain DW DNLEN+1 DUP
	wszRemoteComputer DW NETBIOS_NAME_LEN+1 DUP
ENDS

RAS_CONNECTION_1 STRUCT
	hConnection HANDLE
	hInterface HANDLE
	PppInfo PPP_INFO
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
	dwCompressionRatioIn DD
	dwCompressionRatioOut DD
ENDS

RAS_CONNECTION_2 STRUCT
	hConnection HANDLE
	wszUserName DW UNLEN+1 DUP
	dwInterfaceType DD
	guid GUID
	PppInfo2 PPP_INFO_2
ENDS

#define RASPRIV_NoCallback  0x01
#define RASPRIV_AdminSetCallback  0x02
#define RASPRIV_CallerSetCallback  0x04
#define RASPRIV_DialinPrivilege  0x08
#define RASPRIV_CallbackType (RASPRIV_AdminSetCallback|RASPRIV_CallerSetCallback|RASPRIV_NoCallback)

#define RASPRIV2_DialinPolicy  0x1

#ifndef _RAS_USER_0_DEFINED
#define _RAS_USER_0_DEFINED
	RAS_USER_0 STRUCT
		bfPrivilege DB
		wszPhoneNumber DW MAX_PHONE_NUMBER_LEN+1 DUP
	ENDS
#endif

RAS_USER_1 STRUCT
	bfPrivilege DB
	wszPhoneNumber DW MAX_PHONE_NUMBER_LEN+1 DUP
	bfPrivilege2 DB
ENDS

#endif

