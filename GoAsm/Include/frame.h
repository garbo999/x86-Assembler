#ifndef FRAME_H
#define FRAME_H

/* Microsoft Network Monitor definitions */

#define MAX_ADDR_LENGTH  6

#define ETHERNET_HEADER_LENGTH  14

#define ETHERNET_DATA_LENGTH  0x05DC
#define ETHERNET_FRAME_LENGTH  0x05EA
#define ETHERNET_FRAME_TYPE  0x0600

#define TOKENRING_HEADER_LENGTH  14

#define TOKENRING_SA_ROUTING_INFO  0x0080
#define TOKENRING_SA_LOCAL  0x0040

#define TOKENRING_DA_LOCAL  0x0040
#define TOKENRING_DA_GROUP  0x0080

#define TOKENRING_RC_LENGTHMASK  0x001F
#define TOKENRING_BC_MASK  0x00E0

#define TOKENRING_TYPE_MAC  0x0000
#define TOKENRING_TYPE_LLC  0x0040

#define FDDI_HEADER_LENGTH  13

#define FDDI_TYPE_MAC  0x00
#define FDDI_TYPE_LLC  0x10
#define FDDI_TYPE_LONG_ADDRESS  0x40

ETHERNET STRUCT
	DstAddr DB MAX_ADDR_LENGTH DUP
	SrcAddr DB MAX_ADDR_LENGTH DUP
	UNION
		Length DW
		Type DW
	ENDUNION
	Info DB
ENDS

TOKENRING STRUCT
	AccessCtrl DB
	FrameCtrl DB
	DstAddr DB MAX_ADDR_LENGTH DUP
	SrcAddr DB MAX_ADDR_LENGTH DUP
	UNION
		Info DB
		RoutingInfo DW
	ENDUNION
ENDS

FDDI STRUCT
	FrameCtrl DB
	DstAddr DB MAX_ADDR_LENGTH DUP
	SrcAddr DB MAX_ADDR_LENGTH DUP
	Info DB
ENDS

ControlFieldStruct STRUCT
	UNION
		Command DB
		NextSend DB
	ENDUNION
	UNION
		NextRecv DB
		Data DB
	ENDUNION
ENDS

LLC STRUCT
	dsap DB
	ssap DB
	ControlField ControlFieldStruct
ENDS

#endif
