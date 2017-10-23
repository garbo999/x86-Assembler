#ifndef TRAFFIC_H
#define TRAFFIC_H

/* Traffic control interface API definitions */

#IFDEF LINKFILES
	#dynamiclinkfile traffic.dll
#ENDIF

#define CURRENT_TCI_VERSION  0x0002

#define TC_NOTIFY_IFC_UP  1
#define TC_NOTIFY_IFC_CLOSE  2
#define TC_NOTIFY_IFC_CHANGE  3
#define TC_NOTIFY_PARAM_CHANGED 4
#define TC_NOTIFY_FLOW_CLOSE  5

#define TC_INVALID_HANDLE 0

#define MAX_STRING_LENGTH  256

#define QOS_TRAFFIC_GENERAL_ID_BASE  4000

#define QOS_OBJECT_DS_CLASS  (0x00000001+QOS_TRAFFIC_GENERAL_ID_BASE)
#define QOS_OBJECT_TRAFFIC_CLASS  (0x00000002+QOS_TRAFFIC_GENERAL_ID_BASE)
#define QOS_OBJECT_DIFFSERV  (0x00000003+QOS_TRAFFIC_GENERAL_ID_BASE)
#define QOS_OBJECT_TCP_TRAFFIC  (0x00000004+QOS_TRAFFIC_GENERAL_ID_BASE)

TCI_CLIENT_FUNC_LIST STRUCT
	ClNotifyHandler PTR
	ClAddFlowCompleteHandler PTR
	ClModifyFlowCompleteHandler PTR
	ClDeleteFlowCompleteHandler PTR
ENDS

ADDRESS_LIST_DESCRIPTOR STRUCT
	MediaType DD
	AddressList PTR
ENDS

TC_IFC_DESCRIPTOR STRUCT
	Length DD
	pInterfaceName PTR
	pInterfaceID PTR
	AddressListDesc ADDRESS_LIST_DESCRIPTOR
ENDS

TC_SUPPORTED_INFO_BUFFER STRUCT
	InstanceIDLength DW
	InstanceID DW MAX_STRING_LENGTH DUP
	AddrListDesc ADDRESS_LIST_DESCRIPTOR
ENDS

TC_GEN_FILTER STRUCT
	AddressType DW
	PatternSize DD
	Pattern PTR
	Mask PTR
ENDS

TC_GEN_FLOW STRUCT
	SendingFlowspec FLOWSPEC
	ReceivingFlowspec FLOWSPEC
	TcObjectsLength DD
	TcObjects QOS_OBJECT_HDR
ENDS

IP_PATTERN STRUCT
	Reserved1 DD
	Reserved2 DD
	SrcAddr DD
	DstAddr DD
	UNION
		S_un_ports STRUCT
			s_srcport DW
			s_dstport DW
		ENDS
		S_un_icmp STRUCT
			s_type DB
			s_code DB
			DW
		ENDS
		S_Spi DD
	ENDUNION
	ProtocolId DB
	Reserved3 DB 3 DUP (?)
ENDS

#define tcSrcPort S_un.S_un_ports.s_srcport
#define tcDstPort S_un.S_un_ports.s_dstport
#define tcIcmpType  S_un.S_un_icmp.s_type
#define tcIcmpCode  S_un.S_un_icmp.s_code
#define tcSpi  S_un.S_Spi

IPX_PATTERN STRUCT
    Src STRUCT
    	NetworkAddress DD
		NodeAddress DB 6 DUP
		Socket DW
    ENDS
	Dest STRUCT
		NetworkAddress DD
		NodeAddress DB 6 DUP
		Socket DW
	ENDS
ENDS

ENUMERATION_BUFFER STRUCT
	Length DD
	OwnerProcessId DD
	FlowNameLength DW
	FlowName DW MAX_STRING_LENGTH DUP
	pFlow PTR
	NumberOfFilters DD
	GenericFilter TC_GEN_FILTER
ENDS

QOS_TRAFFIC_CLASS STRUCT
	ObjectHdr QOS_OBJECT_HDR
	TrafficClass DD
ENDS

QOS_DS_CLASS STRUCT
	ObjectHdr QOS_OBJECT_HDR
	DSField DD
ENDS

QOS_DIFFSERV STRUCT
	ObjectHdr QOS_OBJECT_HDR
	DSFieldCount DD
	DiffservRule DB
ENDS

QOS_DIFFSERV_RULE STRUCT
	InboundDSField DB
	ConformingOutboundDSField DB
	NonConformingOutboundDSField DB
	ConformingUserPriority DB
	NonConformingUserPriority DB
ENDS

QOS_TCP_TRAFFIC STRUCT
	ObjectHdr QOS_OBJECT_HDR
ENDS

#IFDEF UNICODE
	#define TcOpenInterface  TcOpenInterfaceW
	#define TcQueryFlow  TcQueryFlowW
	#define TcSetFlow  TcSetFlowW
	#define TcGetFlowName  TcGetFlowNameW
#else
	#define TcOpenInterface  TcOpenInterfaceA
	#define TcQueryFlow  TcQueryFlowA
	#define TcSetFlow  TcSetFlowA
	#define TcGetFlowName  TcGetFlowNameA
#endif

#endif
