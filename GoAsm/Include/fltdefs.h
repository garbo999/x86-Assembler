#ifndef FLTDEFS_H
#define FLTDEFS_H

/* Windows filter API definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Iphlpapi.dll
#ENDIF

#define FILTER_PROTO_ANY  0x00
#define FILTER_PROTO_ICMP  0x01
#define FILTER_PROTO_TCP  0x06
#define FILTER_PROTO_UDP  0x11

#define FILTER_TCPUDP_PORT_ANY  0x0000

#define FILTER_ICMP_TYPE_ANY  0xff
#define FILTER_ICMP_CODE_ANY  0xff

#define FD_FLAGS_NOSYN  0x1
#define FD_FLAGS_ALLFLAGS  FD_FLAGS_NOSYN

#define LB_SRC_ADDR_USE_SRCADDR_FLAG  0x00000001
#define LB_SRC_ADDR_USE_DSTADDR_FLAG  0x00000002
#define LB_DST_ADDR_USE_SRCADDR_FLAG  0x00000004
#define LB_DST_ADDR_USE_DSTADDR_FLAG  0x00000008
#define LB_SRC_MASK_LATE_FLAG  0x00000010
#define LB_DST_MASK_LATE_FLAG  0x00000020

#define PFERROR_NO_PF_INTERFACE  23000+0
#define PFERROR_NO_FILTERS_GIVEN  23000+1
#define PFERROR_BUFFER_TOO_SMALL  23000+2
#define ERROR_IPV6_NOT_IMPLEMENTED 23000+3

GF_FRAGMENTS = 2
GF_STRONGHOST = 8
GF_FRAGCACHE = 9

PF_ACTION_FORWARD = 0
PF_ACTION_DROP = 1

PF_IPV4 = 0
PF_IPV6 = 1

PF_FILTER_DESCRIPTOR STRUCT
	dwFilterFlags DD
	dwRule DD
	pfatType PTR
	SrcAddr PTR
	SrcMask PTR
	DstAddr PTR
	DstMask PTR
	dwProtocol DD
	fLateBound DD
	wSrcPort DW
	wDstPort DW
	wSrcPortHighRange DW
	wDstPortHighRange DW
ENDS

PF_FILTER_STATS STRUCT
	dwNumPacketsFiltered DD
	info PF_FILTER_DESCRIPTOR
ENDS

PF_INTERFACE_STATS STRUCT
	pvDriverContext PTR
	dwFlags DD
	dwInDrops DD
	dwOutDrops DD
	eaInAction PTR
	eaOutAction PTR
	dwNumInFilters DD
	dwNumOutFilters DD
	dwFrag DD
	dwSpoof DD
	dwReserved1 DD
	dwReserved2 DD
	liSYN LARGE_INTEGER
	liTotalLogged LARGE_INTEGER
	dwLostLogEntries DD
	FilterInfo PF_FILTER_STATS
ENDS

PF_LATEBIND_INFO STRUCT
	SrcAddr PTR
	DstAddr PTR
	Mask PTR
ENDS

PFFT_FILTER = 1
PFFT_FRAG = 2
PFFT_SPOOF = 3

PFLOGFRAME STRUCT
	Timestamp LARGE_INTEGER
	pfeTypeOfFrame PFFRAMETYPE
	dwTotalSizeUsed DD
	dwFilterRule DD
	wSizeOfAdditionalData DW
	wSizeOfIpHeader DW
	dwInterfaceName DD
	dwIPIndex DD
	bPacketData DB
ENDS

#endif
