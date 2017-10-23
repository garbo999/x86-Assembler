;=============================================================;
;            qos.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF QOS_INC
#Define QOS_INC

#Define SERVICETYPE_NOTRAFFIC               000000000H
#Define SERVICETYPE_BESTEFFORT              000000001H
#Define SERVICETYPE_CONTROLLEDLOAD          000000002H
#Define SERVICETYPE_GUARANTEED              000000003H
#Define SERVICETYPE_NETWORK_UNAVAILABLE     000000004H
#Define SERVICETYPE_GENERAL_INFORMATION     000000005H
#Define SERVICETYPE_NOCHANGE                000000006H

#Define SERVICE_IMMEDIATE_TRAFFIC_CONTROL   080000000H

#Define SERVICE_NO_QOS_SIGNALING   			040000000H

#Define RSVP_OBJECT_ID_BASE         		1000
#Define RSVP_OBJECT_STATUS_INFO     		(000000000H + RSVP_OBJECT_ID_BASE)
#Define RSVP_OBJECT_RESERVE_INFO    		(000000001H + RSVP_OBJECT_ID_BASE)
#Define RSVP_OBJECT_ADSPEC          		(000000002H + RSVP_OBJECT_ID_BASE)

#Define QOS_GENERAL_ID_BASE         		2000
#Define QOS_OBJECT_PRIORITY         		(000000000H + QOS_GENERAL_ID_BASE)
#Define QOS_OBJECT_END_OF_LIST      		(000000001H + QOS_GENERAL_ID_BASE)
#Define QOS_OBJECT_SD_MODE          		(000000002H + QOS_GENERAL_ID_BASE)
#Define QOS_OBJECT_TRAFFIC_CLASS    		(000000003H + QOS_GENERAL_ID_BASE)

#Define QOS_NOT_SPECIFIED     				0FFFFFFFFH

#Define POSITIVE_INFINITY_RATE     			0FFFFFFFEH

;FilterType enumeration
FILTERSPECV4								Equ 1
FILTERSPECV6								Equ 2
FILTERSPECV6_FLOW							Equ 3
FILTERSPECV4_GPI							Equ 4
FILTERSPECV6_GPI							Equ 5
FILTERSPEC_END								Equ 6

#Define RSVP_WILDCARD_STYLE           		000000001H
#Define RSVP_FIXED_FILTER_STYLE       		000000002H
#Define RSVP_SHARED_EXPLICIT_STYLE    		000000003H

#Define TC_NONCONF_BORROW   				0
#Define TC_NONCONF_SHAPE    				1
#Define TC_NONCONF_DISCARD  				2

#Define INDETERMINATE_LATENCY   			0FFFFFFFFH

#Define AD_FLAG_BREAK_BIT    				000000001H


FLOWSPEC Struct
	TokenRate DD
	TokenBucketSize DD
	PeakBandwidth DD
	Latency DD
	DelayVariation DD
	ServiceType DD
	MaxSduSize DD
	MinimumPolicedSize DD
EndS

QOS_OBJECT_HDR Struct
	ObjectType DD
	ObjectLength DD
EndS

IN_ADDR_IPV4 Union
	Addr DD
	AddrBytes DB 4 Dup ?
EndUnion

IN_ADDR_IPV6 Struct
	Addr DB 16 Dup ?
EndS

RSVP_FILTERSPEC_V4 Struct
    Address IN_ADDR_IPV4 <>
	Unused DW
	Port DW
EndS

RSVP_FILTERSPEC_V6 Struct
	Address IN_ADDR_IPV6 <>
	UnUsed DW
	Port DW
EndS

RSVP_FILTERSPEC_V6_FLOW Struct
	Address IN_ADDR_IPV6 <>
	UnUsed DW
	FlowLabel DB 3 Dup ?
EndS

RSVP_FILTERSPEC_V4_GPI Struct
	Address IN_ADDR_IPV4 <>
	GeneralPortId DD
EndS

RSVP_FILTERSPEC_V6_GPI Struct
	Address IN_ADDR_IPV6 <>
	GeneralPortId DD
EndS

RSVP_FILTERSPEC Struct
	Type DD
	Union
	FilterSpecV4 RSVP_FILTERSPEC_V4 <>
	FilterSpecV6 RSVP_FILTERSPEC_V6 <>
	FilterSpecV6Flow RSVP_FILTERSPEC_V6_FLOW <>
	FilterSpecV4Gpi RSVP_FILTERSPEC_V4_GPI <>
	FilterSpecV6Gpi RSVP_FILTERSPEC_V6_GPI <>
	EndUnion
EndS

FLOWDESCRIPTOR Struct
	FlowSpec FLOWSPEC <>
	NumFilters DD
	FilterList DD
EndS

RSVP_POLICY Struct
	Type DD
EndS

RSVP_RESERVE_INFO Struct
	ObjectHdr QOS_OBJECT_HDR <>
	Style DD
	ConfirmRequest DD
	Policy DD
	NumFlowDesc DD
	FlowDescList DD
EndS

RSVP_STATUS_INFO Struct
	ObjectHdr QOS_OBJECT_HDR <>
	StatusCode DD
	ExtendedStatus1 DD
	ExtendedStatus2 DD
EndS

QOS_PRIORITY Struct
	ObjectHdr QOS_OBJECT_HDR <>
	SendPriority DB
	SendFlags DB
	ReceivePriority DB
	Unused DB
EndS

QOS_SD_MODE Struct
	ObjectHdr QOS_OBJECT_HDR <>
	ShapeDiscardMode DD
EndS

QOS_TRAFFIC_CLASS Struct
	ObjectHdr QOS_OBJECT_HDR <>
	TrafficClass DD
EndS

AD_GENERAL_PARAMS Struct
	IntServAwareHopCount DD
	PathBandwidthEstimate DD
	MinimumLatency DD
	PathMTU DD
	Flags DD
EndS

AD_GUARANTEED Struct
	CTotal DD
	DTotal DD
	CSum DD
	DSum DD
EndS

PARAM_BUFFER Struct
	ParameterId DD
	Length DD
	Buffer DB
EndS

CONTROL_SERVICE Struct
	Length DD
	Service DD
	Overrides AD_GENERAL_PARAMS <>
	Union
	Guaranteed AD_GUARANTEED <>
	ParamBuffer PARAM_BUFFER <>
	EndUnion
EndS

RSVP_ADSPEC Struct
	ObjectHdr QOS_OBJECT_HDR <>
	GeneralParams AD_GENERAL_PARAMS <>
	NumberOfServices DD
	Services CONTROL_SERVICE <>
EndS

#ENDIF ;QOS_INC
