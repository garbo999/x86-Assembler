#ifndef NPPTYPES_H
#define NPPTYPES_H

/* Microsoft Network Monitor type definitions */

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define MAC_TYPE_UNKNOWN  0
#define MAC_TYPE_ETHERNET  1
#define MAC_TYPE_TOKENRING  2
#define MAC_TYPE_FDDI  3

#define MACHINE_NAME_LENGTH  16
#define USER_NAME_LENGTH  32
#define ADAPTER_COMMENT_LENGTH  32

#define CONNECTION_FLAGS_WANT_CONVERSATION_STATS  0x00000001

#define MAX_NAME_SIZE  32
#define IP_ADDRESS_SIZE  4
#define MAC_ADDRESS_SIZE  6

#define MAX_ADDRESS_SIZE  10

#define ADDRESS_TYPE_ETHERNET  0
#define ADDRESS_TYPE_IP  1
#define ADDRESS_TYPE_IPX  2
#define ADDRESS_TYPE_TOKENRING  3
#define ADDRESS_TYPE_FDDI  4

#define ADDRESS_TYPE_XNS  5
#define ADDRESS_TYPE_ANY  6
#define ADDRESS_TYPE_ANY_GROUP  7
#define ADDRESS_TYPE_FIND_HIGHEST  8
#define ADDRESS_TYPE_VINES_IP  9
#define ADDRESS_TYPE_LOCAL_ONLY  10

#define ADDRESSTYPE_FLAGS_NORMALIZE  0x0001
#define ADDRESSTYPE_FLAGS_BIT_REVERSE  0x0002

#define ADDRESS_FLAGS_MATCH_DST  0x0001
#define ADDRESS_FLAGS_MATCH_SRC  0x0002
#define ADDRESS_FLAGS_EXCLUDE  0x0004
#define ADDRESS_FLAGS_DST_GROUP_ADDR  0x0008
#define ADDRESS_FLAGS_MATCH_BOTH  0x0003

#define MAX_ADDRESS_PAIRS  8

#define NETWORKINFO_FLAGS_PMODE_NOT_SUPPORTED  0x00000001
#define NETWORKINFO_FLAGS_REMOTE_NAL  0x00000004
#define NETWORKINFO_FLAGS_REMOTE_NAL_CONNECTED  0x00000008
#define NETWORKINFO_FLAGS_REMOTE_CARD  0x00000010
#define NETWORKINFO_FLAGS_RAS  0x00000020

#define MINIMUM_FRAME_SIZE  32

#define MAX_PATTERN_LENGTH  16

#define PATTERN_MATCH_FLAGS_NOT  0x00000001
#define PATTERN_MATCH_FLAGS_RESERVED_1  0x00000002
#define PATTERN_MATCH_FLAGS_PORT_SPECIFIED  0x00000008

#define OFFSET_BASIS_RELATIVE_TO_FRAME  0
#define OFFSET_BASIS_RELATIVE_TO_EFFECTIVE_PROTOCOL  1
#define OFFSET_BASIS_RELATIVE_TO_IPX  2
#define OFFSET_BASIS_RELATIVE_TO_IP  3

#define MAX_PATTERNS  4

#define TRIGGER_TYPE_PATTERN_MATCH  1
#define TRIGGER_TYPE_BUFFER_CONTENT  2
#define TRIGGER_TYPE_PATTERN_MATCH_THEN_BUFFER_CONTENT  3
#define TRIGGER_TYPE_BUFFER_CONTENT_THEN_PATTERN_MATCH  4

#define TRIGGER_FLAGS_FRAME_RELATIVE  0x00000000
#define TRIGGER_FLAGS_DATA_RELATIVE  0x00000001

#define TRIGGER_ACTION_NOTIFY  0x00
#define TRIGGER_ACTION_STOP  0x02
#define TRIGGER_ACTION_PAUSE  0x03

#define TRIGGER_BUFFER_FULL_25_PERCENT  0
#define TRIGGER_BUFFER_FULL_50_PERCENT  1
#define TRIGGER_BUFFER_FULL_75_PERCENT  2
#define TRIGGER_BUFFER_FULL_100_PERCENT  3

#ifndef MAX_PATH
	#define MAX_PATH  260
#endif

#define CAPTUREFILTER_FLAGS_INCLUDE_ALL_SAPS  0x0001
#define CAPTUREFILTER_FLAGS_INCLUDE_ALL_ETYPES  0x0002
#define CAPTUREFILTER_FLAGS_TRIGGER  0x0004
#define CAPTUREFILTER_FLAGS_LOCAL_ONLY  0x0008
#define CAPTUREFILTER_FLAGS_DISCARD_COMMENTS  0x0010
#define CAPTUREFILTER_FLAGS_KEEP_RAW  0x0020
#define CAPTUREFILTER_FLAGS_INCLUDE_ALL  0x0003

#define BUFFER_FULL_25_PERCENT  0
#define BUFFER_FULL_50_PERCENT  1
#define BUFFER_FULL_75_PERCENT  2
#define BUFFER_FULL_100_PERCENT  3

#define LOW_PROTOCOL_IPX  OFFSET_BASIS_RELATIVE_TO_IPX
#define LOW_PROTOCOL_IP  OFFSET_BASIS_RELATIVE_TO_IP
#define LOW_PROTOCOL_UNKNOWN -1

#define STATIONSTATS_FLAGS_INITIALIZED  0x0001
#define STATIONSTATS_FLAGS_EVENTPOSTED  0x0002

#define STATIONSTATS_POOL_SIZE  100

#define SESSION_FLAGS_INITIALIZED  0x0001
#define SESSION_FLAGS_EVENTPOSTED  0x0002

#define SESSION_POOL_SIZE  100

#define STATIONQUERY_FLAGS_LOADED  0x0001
#define STATIONQUERY_FLAGS_RUNNING  0x0002
#define STATIONQUERY_FLAGS_CAPTURING  0x0004
#define STATIONQUERY_FLAGS_TRANSMITTING 0x0008

#define STATIONQUERY_VERSION_MINOR  0x01
#define STATIONQUERY_VERSION_MAJOR  0x02

#define MAX_SECURITY_BREACH_REASON_SIZE  100
#define MAX_SIGNATURE_LENGTH  128
#define MAX_USER_NAME_LENGTH  256

#define UPDATE_EVENT_TERMINATE_THREAD  0x00000000
#define UPDATE_EVENT_NETWORK_STATUS  0x00000001

#define UPDATE_EVENT_RTC_INTERVAL_ELAPSED  0x00000002
#define UPDATE_EVENT_RTC_FRAME_TABLE_FULL  0x00000003
#define UPDATE_EVENT_RTC_BUFFER_FULL  0x00000004

#define UPDATE_EVENT_TRIGGER_BUFFER_CONTENT  0x00000005
#define UPDATE_EVENT_TRIGGER_PATTERN_MATCH  0x00000006
#define UPDATE_EVENT_TRIGGER_BUFFER_PATTERN  0x00000007
#define UPDATE_EVENT_TRIGGER_PATTERN_BUFFER  0x00000008

#define UPDATE_EVENT_TRANSMIT_STATUS  0x00000009

#define UPDATE_EVENT_SECURITY_BREACH  0x0000000A

#define UPDATE_EVENT_REMOTE_FAILURE  0x0000000B

#define UPDATE_ACTION_TERMINATE_THREAD  0x00000000
#define UPDATE_ACTION_NOTIFY  0x00000001
#define UPDATE_ACTION_STOP_CAPTURE  0x00000002
#define UPDATE_ACTION_PAUSE_CAPTURE  0x00000003
#define UPDATE_ACTION_RTC_BUFFER_SWITCH  0x00000004

#define NETWORKSTATUS_STATE_VOID  0
#define NETWORKSTATUS_STATE_INIT  1
#define NETWORKSTATUS_STATE_CAPTURING  2
#define NETWORKSTATUS_STATE_PAUSED  3

#define NETWORKSTATUS_FLAGS_TRIGGER_PENDING  0x0001

#define ALERT_CODE_BEGIN_TRANSMIT  0

#define BONE_PACKET_SIGNATURE  'RTSS'

#define BONE_COMMAND_STATION_QUERY_REQUEST  0
#define BONE_COMMAND_STATION_QUERY_RESPONSE  1
#define BONE_COMMAND_ALERT  2
#define BONE_COMMAND_PERMISSION_CHECK  3
#define BONE_COMMAND_PERMISSION_RESPONSE  4
#define BONE_COMMAND_SECURITY_MONITOR_EVENT  5

#define MAX_SESSIONS  100
#define MAX_STATIONS  100

#define CAPTUREFILE_VERSION_MAJOR  2
#define CAPTUREFILE_VERSION_MINOR  0

#define NETMON_1_0_CAPTUREFILE_SIGNATURE 'RTSS'
#define NETMON_2_0_CAPTUREFILE_SIGNATURE 'GMBU'

#define DEFAULT_TR_AC  0x00
#define DEFAULT_TR_FC  0x40
#define DEFAULT_SAP  0xAA
#define DEFAULT_CONTROL  0x03
#define DEFAULT_ETHERTYPE  0x8419
#define DEFAULT_FDDI_FC  0x10

#define STATISTICS_VERSION_1_0  0x00000000
#define STATISTICS_VERSION_2_0  0x00000020

#define MAX_STATSFRAME_SIZE  sizeof TRSTATFRAME

#define STATS_FRAME_TYPE  103

STATISTICS STRUCT
	TimeElapsed DQ
	TotalFramesCaptured DD
	TotalBytesCaptured DD
	TotalFramesFiltered DD
	TotalBytesFiltered DD
	TotalMulticastsFiltered DD
	TotalBroadcastsFiltered DD
	TotalFramesSeen DD
	TotalBytesSeen DD
	TotalMulticastsReceived DD
	TotalBroadcastsReceived DD
	TotalFramesDropped DD
	TotalFramesDroppedFromBuffer DD
	MacFramesReceived DD
	MacCRCErrors DD
	MacBytesReceivedEx DQ
	MacFramesDropped_NoBuffers DD
	MacMulticastsReceived DD
	MacBroadcastsReceived DD
	MacFramesDropped_HwError DD
ENDS

#define STATISTICS_SIZE  sizeof STATISTICS

VINES_IP_ADDRESS STRUCT
	NetID DD
	SubnetID DW
ENDS

#define VINES_IP_ADDRESS_SIZE sizeof VINES_IP_ADDRESS

IPX_ADDRESS STRUCT
	Subnet DB 4 DUP
	Address DB 6 DUP
ENDS

#define IPX_ADDRESS_SIZE  sizeof IPX_ADDRESS

ETHERNET_SRC_ADDRESS STRUCT
	RoutingBit DB
	LocalBit DB
	Byte0 DB
	Reserved DB 5 DUP
ENDS

ETHERNET_DST_ADDRESS STRUCT
	GroupBit DB
	AdminBit DB
	Byte0 DB
	Reserved DB 5 DUP
ENDS

#define FDDI_SRC_ADDRESS ETHERNET_SRC_ADDRESS
#define FDDI_DST_ADDRESS ETHERNET_DST_ADDRESS

TOKENRING_SRC_ADDRESS STRUCT
	Byte0 DB
	LocalBit DB
	RoutingBit DB
	Byte1 DB
	Byte2 DB
	Functional DB
	Reserved DB 3 DUP
ENDS

TOKENRING_DST_ADDRESS STRUCT
	Byte0 DB
	AdminBit DB
	GroupBit DB
	Reserved DB 5 DUP
ENDS

NPP_ADDRESS STRUCT
	Type DD
    UNION
		MACAddress DB MAC_ADDRESS_SIZE DUP
		IPAddress DB IP_ADDRESS_SIZE DUP
		IPXRawAddress DB IPX_ADDRESS_SIZE DUP
		IPXAddress IPX_ADDRESS
		VinesIPRawAddress DB VINES_IP_ADDRESS_SIZE DUP
		VinesIPAddress VINES_IP_ADDRESS
		EthernetSrcAddress ETHERNET_SRC_ADDRESS
		EthernetDstAddress ETHERNET_DST_ADDRESS
		TokenringSrcAddress TOKENRING_SRC_ADDRESS
		TokenringDstAddress TOKENRING_DST_ADDRESS
		FddiSrcAddress FDDI_SRC_ADDRESS
		FddiDstAddress FDDI_DST_ADDRESS
    ENDUNION
	Flags DW
ENDS
#define NPP_ADDRESS_SIZE  sizeof NPP_ADDRESS

ADDRESSPAIR STRUCT
	AddressFlags DW
	NalReserved DW
	DstAddress ADDRESS
	SrcAddress ADDRESS
ENDS

#define ADDRESSPAIR_SIZE  sizeof ADDRESSPAIR

ADDRESSTABLE STRUCT
	nAddressPairs DD
	nNonMacAddressPairs DD
	AddressPair ADDRESSPAIR MAX_ADDRESS_PAIRS DUP
ENDS

#define ADDRESSTABLE_SIZE  sizeof ADDRESSTABLE

NETWORKINFO STRUCT
	PermanentAddr DB 6 DUP
	CurrentAddr DB 6 DUP
	OtherAddress ADDRESS
	LinkSpeed DD
	MacType DD
	MaxFrameSize DD
	Flags DD
	TimestampScaleFactor DD
	NodeName DB 32 DUP
	PModeSupported DD
	Comment DB ADAPTER_COMMENT_LENGTH DUP
ENDS

#define NETWORKINFO_SIZE  sizeof NETWORKINFO

GENERIC_PORT UNION
	IPPort DB
	ByteSwappedIPXPort DW
ENDUNION

PATTERNMATCH STRUCT
	Flags DD
	OffsetBasis DB
	Port GENERIC_PORT
	Offset DW
	Length DW
	PatternToMatch DB MAX_PATTERN_LENGTH DUP
ENDS

#define PATTERNMATCH_SIZE sizeof PATTERNMATCH

ANDEXP STRUCT
	nPatternMatches DD
	PatternMatch PATTERNMATCH MAX_PATTERNS DUP
ENDS

#define ANDEXP_SIZE  sizeof ANDEXP

EXPRESSION STRUCT
	nAndExps DD
	AndExp ANDEXP MAX_PATTERNS DUP
ENDS

#define EXPRESSION_SIZE  sizeof EXPRESSION

TRIGGER STRUCT
	TriggerActive DD
	TriggerType DB
	TriggerAction DB
	TriggerFlags DD
	TriggerPatternMatch PATTERNMATCH
	TriggerBufferSize DD
	TriggerReservedDD
	TriggerCommandLine DB MAX_PATH DUP
ENDS

#define TRIGGER_SIZE  sizeof TRIGGER

CAPTUREFILTER STRUCT
	FilterFlags DD
	lpSapTable DD
	lpEtypeTable DD
	nSaps DW
	nEtypes DW
	AddressTable DD
	FilterExpression EXPRESSION
	Trigger TRIGGER
	nFrameBytesToCopy DD
	Reserved DD
ENDS

#define CAPTUREFILTER_SIZE  sizeof CAPTUREFILTER

NPP_FRAME STRUCT
	TimeStamp DQ
	FrameLength DD
	nBytesAvailDD
	MacFrame DB
ENDS

#define NPP_FRAME_SIZE  sizeof NPP_FRAME

FRAME_DESCRIPTOR STRUCT
	FramePointer DD
	TimeStamp DQ
	FrameLength DD
	nBytesAvail DD
	Etype DW
	Sap DB
	LowProtocol DB
	LowProtocolOffset DW
	HighPort GENERIC_PORT
	HighProtocolOffset DW
ENDS

#define FRAME_DESCRIPTOR_SIZE sizeof FRAME_DESCRIPTOR

FRAMETABLE STRUCT
	FrameTableLength DD
	StartIndex DD
	EndIndex DD
	FrameCount DD
	Frames FRAME_DESCRIPTOR
ENDS

STATIONSTATS STRUCT
	NextStationStats DD
	SessionPartnerList DD
	Flags DD
	StationAddress DB 6 DUP
	Pad DW
	TotalPacketsReceived DD
	TotalDirectedPacketsSent DD
	TotalBroadcastPacketsSent DD
	TotalMulticastPacketsSent DD
	TotalBytesReceived DD
	TotalBytesSent DD
ENDS

#define STATIONSTATS_SIZE  sizeof STATIONSTATS

SESSIONSTATS STRUCT
	NextSession DD
	StationOwner DD
	StationPartner DD
	Flags DD
	TotalPacketsSent DD
ENDS

#define SESSIONSTATS_SIZE  sizeof SESSIONSTATS

OLDSTATIONQUERY STRUCT
	Flags DD
	BCDVerMinor DB
	BCDVerMajor DB
	LicenseNumber DD
	MachineName DB MACHINE_NAME_LENGTH DUP
	UserName DB USER_NAME_LENGTH DUP
	Reserved DB 32 DUP
	AdapterAddress DB 6 DUP
ENDS

#define OLDSTATIONQUERY_SIZE  sizeof OLDSTATIONQUERY

STATIONQUERY STRUCT
	Flags DD
	BCDVerMinor DB
	BCDVerMajor DB
	LicenseNumber DD
	MachineName DB MACHINE_NAME_LENGTH DUP
	UserName DB USER_NAME_LENGTH DUP
	Reserved DB 32 DUP
	AdapterAddress DB 6 DUP
	WMachineName DW MACHINE_NAME_LENGTH DUP
	WUserName DW USER_NAME_LENGTH DUP
ENDS

#define STATIONQUERY_SIZE  sizeof STATIONQUERY

QUERYTABLE STRUCT
	nStationQueries DD
	StationQuery STATIONQUERY
ENDS

#define QUERYTABLE_SIZE  sizeof QUERYTABLE

#ifndef LINK
	LINK STRUCT
		PrevLink DD
		NextLink DD
	ENDS
#endif /* _LINK_ */

SECURITY_PERMISSION_CHECK STRUCT
	Version DD
	RandomNumber DD
	MachineName DB MACHINE_NAME_LENGTH DUP
	UserName DB USER_NAME_LENGTH DUP
	MacType DD
	PermanentAdapterAddress DB MAC_ADDRESS_SIZE DUP
	CurrentAdapterAddress DB MAC_ADDRESS_SIZE DUP
	WMachineName DW MACHINE_NAME_LENGTH DUP
	WUserName DW USER_NAME_LENGTH DUP
ENDS

#define SECURITY_PERMISSION_CHECK_SIZE  sizeof SECURITY_PERMISSION_CHECK

SECURITY_PERMISSION_RESPONSE STRUCT
	Version DD
	RandomNumber DD
	MachineName DB MACHINE_NAME_LENGTH DUP
	Address DB MAC_ADDRESS_SIZE DUP
	UserName DB MAX_USER_NAME_LENGTH DUP
	Reason DB MAX_SECURITY_BREACH_REASON_SIZE DUP
	SignatureLength DD
	Signature DB MAX_SIGNATURE_LENGTH DUP
ENDS

#define SECURITY_PERMISSION_RESPONSE_SIZE  sizeof SECURITY_PERMISSION_RESPONSE

UPDATE_EVENT STRUCT
	Event DW
	Action DD
	Status DD
	Value DD
	TimeStamp DQ
	lpUserContext DD
	lpReserved DD
	FramesDropped DD
	UNION
    	Reserved DD
		lpFrameTable DD
		SecurityResponse SECURITY_PERMISSION_RESPONSE
	ENDUNION
	lpFinalStats DD
ENDS

NETWORKSTATUS STRUCT
	State DD
	Flags DD
ENDS

#define NETWORKSTATUS_SIZE  sizeof NETWORKSTATUS

BONEPACKET STRUCT
	Signature DD
	Command DB
	Flags DB
	Reserved DD
	Length DW
ENDS

#define BONEPACKET_SIZE  sizeof BONEPACKET

ALERT STRUCT
	AlertCode DD
	WMachineName DW MACHINE_NAME_LENGTH DUP
	WUserName DW USER_NAME_LENGTH DUP
	UNION
		Pad DB 32 DUP
		nFramesToSend DD
	ENDUNION
ENDS

#define ALERT_SIZE sizeof ALERT

STATISTICSPARAM STRUCT
	StatisticsSize DD
	Statistics STATISTICS
	StatisticsTableEntries DD
	StatisticsTable STATIONSTATS MAX_STATIONS DUP
	SessionTableEntries DD
	SessionTable SESSIONSTATS MAX_SESSIONS DUP
ENDS

#define STATISTICSPARAM_SIZE  sizeof STATISTICSPARAM

CAPTUREFILE_HEADER_VALUES STRUCT
	Signature DD
	BCDVerMinor DB
	BCDVerMajor DB
	MacType DW
	TimeStamp SYSTEMTIME
	FrameTableOffset DD
	FrameTableLength DD
	UserDataOffset DD
	UserDataLength DD
	CommentDataOffset DD
	CommentDataLength DD
	StatisticsOffset DD
	StatisticsLength DD
	NetworkInfoOffset DD
	NetworkInfoLength DD
	ConversationStatsOffset DD
	ConversationStatsLength DD
ENDS

#define CAPTUREFILE_HEADER_VALUES_SIZE  sizeof CAPTUREFILE_HEADER_VALUES

CAPTUREFILE_HEADER STRUCT
	UNION
		ActualHeader CAPTUREFILE_HEADER_VALUES
		Buffer DB CAPTUREFILE_HEADER_VALUES_SIZE DUP
	ENDUNION
	Reserved DB (128 - CAPTUREFILE_HEADER_VALUES_SIZE) DUP
ENDS

#define CAPTUREFILE_HEADER_SIZE  sizeof CAPTUREFILE_HEADER

EFRAMEHDR STRUCT
	SrcAddress DB 6 DUP
	DstAddress DB 6 DUP
	Length DW
	DSAP DB
	SSAP DB
	Control DB
	ProtocolID DB 3 DUP
	EtherType DW
ENDS

TRFRAMEHDR STRUCT
	AC DB
	FC DB
	SrcAddress DB 6 DUP
	DstAddress DB 6 DUP
	DSAP DB
	SSAP DB
	Control DB
	ProtocolID DB 3 DUP
	EtherType DW
ENDS

FDDIFRAMEHDR STRUCT
	FC DB
	SrcAddress DB 6 DUP
	DstAddress DB 6 DUP
	DSAP DB
	SSAP DB
	Control DB
	ProtocolID DB 3 DUP
	EtherType DW
ENDS

FDDISTATFRAME STRUCT
	TimeStamp DQ
	FrameLength DD
	nBytesAvail DD
	FrameHeader FDDIFRAMEHDR
	FrameID DB 4 DUP
	Flags DD
	FrameType DD
	StatsDataLen DW
	StatsVersion DD
	Statistics STATISTICS
ENDS

#define FDDISTATFRAME_SIZE  sizeof FDDISTATFRAME

TRSTATFRAME STRUCT
	TimeStamp DQ
	FrameLength DD
	nBytesAvail DD
	FrameHeader TRFRAMEHDR
	FrameID DB 4 DUP
	Flags DD
	FrameType DD
	StatsDataLen DW
	StatsVersion DD
	Statistics STATISTICS
ENDS

#define TRSTATFRAME_SIZE  sizeof TRSTATFRAME

ESTATFRAME STRUCT
	TimeStamp DQ
	FrameLength DD
	nBytesAvail DD
	FrameHeader EFRAMEHDR
	FrameID DB 4 DUP
	Flags DD
	FrameType DD
	StatsDataLen DW
	StatsVersion DD
	Statistics STATISTICS
ENDS

#define ESTATFRAME_SIZE  sizeof ESTATFRAME

#endif /* _NPPTYPES_H */