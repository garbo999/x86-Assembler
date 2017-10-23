#ifndef ROUTPROT_H
#define ROUTPROT_H

/* Routing Protocol interface definitions
For integration of third-party routing protocols into the Routing and Remote Access Service (RRAS).
RRAS is a feature of Windows that acts as a multi-protocol router. RRAS defines the interface
between the router manager and the routing protocol.
The routing protocol is implemented in a dynamic link library (DLL).
*/

#IFNDEF STM_H
	#include "stm.h"
#ENDIF

#define RF_ROUTING  0x00000001
#define RF_DEMAND_UPDATE_ROUTES  0x00000004
#define RF_ADD_ALL_INTERFACES  0x00000010
#define RF_MULTICAST  0x00000020
#define RF_POWER  0x00000040

#define MS_ROUTER_VERSION  0x00000500

#define IR_PROMISCUOUS  0
#define IR_PROMISCUOUS_MULTICAST  1

#define PROTO_IP_OTHER  1
#define PROTO_IP_LOCAL  2
#define PROTO_IP_NETMGMT  3
#define PROTO_IP_ICMP  4
#define PROTO_IP_EGP  5
#define PROTO_IP_GGP  6
#define PROTO_IP_HELLO  7
#define PROTO_IP_RIP  8
#define PROTO_IP_IS_IS  9
#define PROTO_IP_ES_IS  10
#define PROTO_IP_CISCO  11
#define PROTO_IP_BBN  12
#define PROTO_IP_OSPF  13
#define PROTO_IP_BGP  14

#define PROTO_IP_MSDP  9
#define PROTO_IP_IGMP  10
#define PROTO_IP_BGMP  11

#define PROTO_IP_VRRP  112
#define PROTO_IP_BOOTP   9999
#define PROTO_IP_NT_AUTOSTATIC  10002
#define PROTO_IP_DNS_PROXY  10003
#define PROTO_IP_DHCP_ALLOCATOR  10004
#define PROTO_IP_NAT  10005
#define PROTO_IP_NT_STATIC  10006
#define PROTO_IP_NT_STATIC_NON_DOD  10007
#define PROTO_IP_DIFFSERV  10008
#define PROTO_IP_MGM  10009
#define PROTO_IP_DTP  10010
#define PROTO_IP_H323  10011
#define PROTO_IP_FTP  10012
#define PROTO_IP_ALG  10013

;#define PROTOCOL_ID(Type,VendorId,ProtocolId)  (((Type & 0x03)<<30)|((VendorId & 0x3FFF)<<16)|(ProtocolId & 0xFFFF))
;PROTOCOL_ID(%Type,%VendorId,%ProtocolId) MACRO
;	(((Type & 0x03)<<30)|((VendorId & 0x3FFF)<<16)|(ProtocolId & 0xFFFF))
;ENDM
;#define TYPE_FROM_PROTO_ID(X)  (((X)>>30)&0x03)
;#define VENDOR_FROM_PROTO_ID(X)  (((X)>>16)&0x3FFF)
;#define PROTO_FROM_PROTO_ID(X)  ((X)&0xFFFF)

#define PROTO_TYPE_UCAST  0
#define PROTO_TYPE_MCAST  1
#define PROTO_TYPE_MS0  2
#define PROTO_TYPE_MS1  3

#define PROTO_VENDOR_MS0  0x0000
#define PROTO_VENDOR_MS1  0x137
#define PROTO_VENDOR_MS2  0x3FFF

#define MS_IP_BOOTP  ((PROTO_TYPE_UCAST&3)<<30)|((PROTO_VENDOR_MS0&0x3FFF)<<16)|(PROTO_IP_BOOTP& 0xFFFF)
#define MS_IP_RIP  ((PROTO_TYPE_UCAST&3)<<30)|((PROTO_VENDOR_MS0&0x3FFF)<<16)|(PROTO_IP_RIP& 0xFFFF)
#define MS_IP_OSPF  ((PROTO_TYPE_UCAST&3)<<30)|((PROTO_VENDOR_MS0&0x3FFF)<<16)|(PROTO_IP_OSPF& 0xFFFF)
#define MS_IP_BGP  ((PROTO_TYPE_UCAST&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_BGP& 0xFFFF)
#define MS_IP_IGMP  ((PROTO_TYPE_MCAST&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_IGMP& 0xFFFF)
#define MS_IP_BGMP  ((PROTO_TYPE_MCAST&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_BGMP& 0xFFFF)
#define MS_IP_MSDP  ((PROTO_TYPE_MCAST&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_MSDP& 0xFFFF)
#define MS_IP_DNS_PROXY  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_DNS_PROXY& 0xFFFF)
#define MS_IP_DHCP_ALLOCATOR  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_DHCP_ALLOCATOR& 0xFFFF)
#define MS_IP_NAT  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_NAT& 0xFFFF)
#define MS_IP_DIFFSERV  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_DIFFSERV& 0xFFFF)
#define MS_IP_MGM  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_MGM& 0xFFFF)
#define MS_IP_VRRP  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_VRRP& 0xFFFF)
#define MS_IP_DTP  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_DTP& 0xFFFF)
#define MS_IP_H323  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_H323& 0xFFFF)
#define MS_IP_FTP  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_FTP& 0xFFFF)
#define MS_IP_ALG  ((PROTO_TYPE_MS0&3)<<30)|((PROTO_VENDOR_MS1&0x3FFF)<<16)|(PROTO_IP_ALG& 0xFFFF)

#define IPX_PROTOCOL_BASE 0x0001ffff
#define IPX_PROTOCOL_RIP  IPX_PROTOCOL_BASE + 1
#define IPX_PROTOCOL_SAP  IPX_PROTOCOL_BASE + 2
#define IPX_PROTOCOL_NLSP  IPX_PROTOCOL_BASE + 3

#define RIS_INTERFACE_ADDRESS_CHANGE  0
#define RIS_INTERFACE_ENABLED  1
#define RIS_INTERFACE_DISABLED  2
#define RIS_INTERFACE_MEDIA_PRESENT  3
#define RIS_INTERFACE_MEDIA_ABSENT  4

;#define SIZEOF_IP_BINDING(X)  (FIELD_OFFSET(IP_ADAPTER_BINDING_INFO,Address[0])+((X)*sizeof(IP_LOCAL_BINDING)))

#define MRINFO_TUNNEL_FLAG  0x01
#define MRINFO_PIM_FLAG  0x04
#define MRINFO_DOWN_FLAG  0x10
#define MRINFO_DISABLED_FLAG  0x20
#define MRINFO_QUERIER_FLAG  0x40
#define MRINFO_LEAF_FLAG  0x80

#define MFE_NO_ERROR  0
#define MFE_REACHED_CORE  1

#define MFE_OIF_PRUNED  5

#define MFE_PRUNED_UPSTREAM  4
#define MFE_OLD_ROUTER  11

#define MFE_NOT_FORWARDING  2
#define MFE_WRONG_IF  3
#define MFE_BOUNDARY_REACHED  6
#define MFE_NO_MULTICAST  7
#define MFE_IIF  8
#define MFE_NO_ROUTE  9
#define MFE_NOT_LAST_HOP  10
#define MFE_PROHIBITED  12
#define MFE_NO_SPACE  13

#define REGISTER_PROTOCOL_ENTRY_POINT_STRING  "RegisterProtocol"

ROUTER_STOPPED = 0
SAVE_GLOBAL_CONFIG_INFO = 1
SAVE_INTERFACE_CONFIG_INFO = 2
UPDATE_COMPLETE = 3

PERMANENT = 0
DEMAND_DIAL = 1
LOCAL_WORKSTATION_DIAL = 2
REMOTE_WORKSTATION_DIAL = 3

SUPPORT_FUNCTIONS STRUCT
	UNION
		_Align8 DQ
		struct
			dwVersion DD
			dwReserved DD
        	ENDS
	ENDUNION
	DemandDialRequest PTR
	SetInterfaceReceiveType PTR
	ValidateRoute PTR
	MIBEntryCreate PTR
	MIBEntryDelete PTR
	MIBEntrySet PTR
	MIBEntryGet PTR
	MIBEntryGetFirst PTR
	MIBEntryGetNext PTR
;	GetRouterId DD
;	HasMulticastBoundary DD
ENDS

UPDATE_COMPLETE_MESSAGE STRUCT
	InterfaceIndex DD
	UpdateType DD
	UpdateStatus DD
ENDS

MESSAGE UNION
    UpdateCompleteMessage UPDATE_COMPLETE_MESSAGE <>
	InterfaceIndex DD
ENDS

IPX_ADAPTER_BINDING_INFO STRUCT
	AdapterIndex DD
	Network DB 4 DUP
	LocalNode DB 6 DUP
	RemoteNode DB 6 DUP
	MaxPacketSize DD
	LinkSpeed DD
ENDS

IP_LOCAL_BINDING STRUCT
	Address DD
	Mask DD
ENDS

IP_ADAPTER_BINDING_INFO STRUCT
	AddressCount DD
	RemoteAddress DD
	Mtu DD
	Speed DQ
	Address IP_LOCAL_BINDING <>
ENDS

MPR50_ROUTING_CHARACTERISTICS STRUCT
	dwVersion DD
	dwProtocolId DD
	fSupportedFunctionality DD
	pfnStartProtocol PTR
	pfnStartComplete PTR
	pfnStopProtocol PTR
	pfnGetGlobalInfo PTR
	pfnSetGlobalInfo PTR
	pfnQueryPower PTR
	pfnSetPower PTR
	pfnAddInterface PTR
	pfnDeleteInterface PTR
	pfnInterfaceStatus PTR
	pfnGetInterfaceInfo PTR
	pfnSetInterfaceInfo PTR
	pfnGetEventMessage PTR
	pfnUpdateRoutes PTR
	pfnConnectClient PTR
	pfnDisconnectClient PTR
	pfnGetNeighbors PTR
	pfnGetMfeStatus PTR
	pfnMibCreateEntry PTR
	pfnMibDeleteEntry PTR
	pfnMibGetEntry PTR
	pfnMibSetEntry PTR
	pfnMibGetFirstEntry PTR
	pfnMibGetNextEntry PTR
	pfnMibSetTrapInfo PTR
	pfnMibGetTrapInfo PTR
ENDS

#define MPR_ROUTING_CHARACTERISTICS MPR50_ROUTING_CHARACTERISTICS

#endif /* ROUTPROT_H */
