#ifndef IPEXPORT_H
#define IPEXPORT_H

/* TCP/IP definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Iphlpapi.dll
#ENDIF

#define MAX_ADAPTER_NAME  128

#define IP_STATUS_BASE              11000
#define IP_SUCCESS                  0
#define IP_BUF_TOO_SMALL            (IP_STATUS_BASE + 1)
#define IP_DEST_NET_UNREACHABLE     (IP_STATUS_BASE + 2)
#define IP_DEST_HOST_UNREACHABLE    (IP_STATUS_BASE + 3)
#define IP_DEST_PROT_UNREACHABLE    (IP_STATUS_BASE + 4)
#define IP_DEST_PORT_UNREACHABLE    (IP_STATUS_BASE + 5)
#define IP_NO_RESOURCES             (IP_STATUS_BASE + 6)
#define IP_BAD_OPTION               (IP_STATUS_BASE + 7)
#define IP_HW_ERROR                 (IP_STATUS_BASE + 8)
#define IP_PACKET_TOO_BIG           (IP_STATUS_BASE + 9)
#define IP_REQ_TIMED_OUT            (IP_STATUS_BASE + 10)
#define IP_BAD_REQ                  (IP_STATUS_BASE + 11)
#define IP_BAD_ROUTE                (IP_STATUS_BASE + 12)
#define IP_TTL_EXPIRED_TRANSIT      (IP_STATUS_BASE + 13)
#define IP_TTL_EXPIRED_REASSEM      (IP_STATUS_BASE + 14)
#define IP_PARAM_PROBLEM            (IP_STATUS_BASE + 15)
#define IP_SOURCE_QUENCH            (IP_STATUS_BASE + 16)
#define IP_OPTION_TOO_BIG           (IP_STATUS_BASE + 17)
#define IP_BAD_DESTINATION          (IP_STATUS_BASE + 18)

//
// Variants of the above using IPv6 terminology, where different
//

#define IP_DEST_NO_ROUTE            (IP_STATUS_BASE + 2)
#define IP_DEST_ADDR_UNREACHABLE    (IP_STATUS_BASE + 3)
#define IP_DEST_PROHIBITED          (IP_STATUS_BASE + 4)
#define IP_DEST_PORT_UNREACHABLE    (IP_STATUS_BASE + 5)
#define IP_HOP_LIMIT_EXCEEDED       (IP_STATUS_BASE + 13)
#define IP_REASSEMBLY_TIME_EXCEEDED (IP_STATUS_BASE + 14)
#define IP_PARAMETER_PROBLEM        (IP_STATUS_BASE + 15)

//
// IPv6-only status codes
//

#define IP_DEST_UNREACHABLE         (IP_STATUS_BASE + 40)
#define IP_TIME_EXCEEDED            (IP_STATUS_BASE + 41)
#define IP_BAD_HEADER               (IP_STATUS_BASE + 42)
#define IP_UNRECOGNIZED_NEXT_HEADER (IP_STATUS_BASE + 43)
#define IP_ICMP_ERROR               (IP_STATUS_BASE + 44)
#define IP_DEST_SCOPE_MISMATCH      (IP_STATUS_BASE + 45)

//
// The next group are status codes passed up on status indications to
// transport layer protocols.
//
#define IP_ADDR_DELETED             (IP_STATUS_BASE + 19)
#define IP_SPEC_MTU_CHANGE          (IP_STATUS_BASE + 20)
#define IP_MTU_CHANGE               (IP_STATUS_BASE + 21)
#define IP_UNLOAD                   (IP_STATUS_BASE + 22)
#define IP_ADDR_ADDED               (IP_STATUS_BASE + 23)
#define IP_MEDIA_CONNECT            (IP_STATUS_BASE + 24)
#define IP_MEDIA_DISCONNECT         (IP_STATUS_BASE + 25)
#define IP_BIND_ADAPTER             (IP_STATUS_BASE + 26)
#define IP_UNBIND_ADAPTER           (IP_STATUS_BASE + 27)
#define IP_DEVICE_DOES_NOT_EXIST    (IP_STATUS_BASE + 28)
#define IP_DUPLICATE_ADDRESS        (IP_STATUS_BASE + 29)
#define IP_INTERFACE_METRIC_CHANGE  (IP_STATUS_BASE + 30)
#define IP_RECONFIG_SECFLTR         (IP_STATUS_BASE + 31)
#define IP_NEGOTIATING_IPSEC        (IP_STATUS_BASE + 32)
#define IP_INTERFACE_WOL_CAPABILITY_CHANGE  (IP_STATUS_BASE + 33)
#define IP_DUPLICATE_IPADD          (IP_STATUS_BASE + 34)

#define IP_GENERAL_FAILURE          (IP_STATUS_BASE + 50)
#define MAX_IP_STATUS               IP_GENERAL_FAILURE
#define IP_PENDING                  (IP_STATUS_BASE + 255)

// Values used in the Flags field of IP_OPTION_INFORMATION.
//
#define IP_FLAG_REVERSE 0x1         // Do a round-trip echo request.
#define IP_FLAG_DF      0x2         // Don't fragment this packet.

//
// Supported IP Option Types.
//
// These types define the options which may be used in the OptionsData field
// of the ip_option_information structure.  See RFC 791 for a complete
// description of each.
//
#define IP_OPT_EOL      0          // End of list option
#define IP_OPT_NOP      1          // No operation
#define IP_OPT_SECURITY 0x82       // Security option
#define IP_OPT_LSRR     0x83       // Loose source route
#define IP_OPT_SSRR     0x89       // Strict source route
#define IP_OPT_RR       0x7        // Record route
#define IP_OPT_TS       0x44       // Timestamp
#define IP_OPT_SID      0x88       // Stream ID (obsolete)
#define IP_OPT_ROUTER_ALERT 0x94  // Router Alert Option

#define MAX_OPT_SIZE    40         // Maximum length of IP options in bytes

// Ioctls code exposed by Memphis tcpip stack.
// For NT these ioctls are define in ntddip.h  (private\inc)

#define IOCTL_IP_RTCHANGE_NOTIFY_REQUEST   101
#define IOCTL_IP_ADDCHANGE_NOTIFY_REQUEST  102
#define IOCTL_ARP_SEND_REQUEST             103
#define IOCTL_IP_INTERFACE_INFO            104
#define IOCTL_IP_GET_BEST_INTERFACE        105
#define IOCTL_IP_UNIDIRECTIONAL_ADAPTER_ADDRESS        106

#IFNDEF IPAddr
IPAddr struct
	S_un UNION
		S_un_b STRUCT
			s_b1 DB
			s_b2 DB
			s_b3 DB
			s_b4 DB
		ENDS
		S_un_w STRUCT
			s_w1 DW
			s_w2 DW
		ENDS
		S_addr DD
	ENDUNION
ENDS
#ENDIF

IP_OPTION_INFORMATION STRUCT
	Ttl DB
	Tos DB
	Flags DB
	OptionsSize DB
	OptionsData PTR
ENDS

ICMP_ECHO_REPLY STRUCT
	Address IPAddr
	Status DD
	RoundTripTime DD
	DataSize DW
	Reserved DW
	Data PTR
	Options ip_option_information <>
ENDS

#IFDEF WIN64

IP_OPTION_INFORMATION32 STRUCT
	Ttl DB
	Tos DB
	Flags DB
	OptionsSize DB
	OptionsData DD
ENDS

ICMP_ECHO_REPLY32 STRUCT
	Address IPAddr
	Status DD
	RoundTripTime DD
	DataSize DW
	Reserved DW
	Data DD
	Options ip_option_information <>
ENDS

#ENDIF

#if WINVER >= NTDDI_WINXP

IPV6_ADDRESS_EX STRUCT
	sin6_port DW
	sin6_flowinfo DD
	sin6_addr DW 8 DUP
	sin6_scope_id DD
ENDS

ICMPV6_ECHO_REPLY_LH STRUCT
	Address IPV6_ADDRESS_EX
	Status DD
	RoundTripTime DD
ENDS

#endif


ArpRequestBuffer STRUCT
	DestAddress IPAddr
	SrcAddress IPAddr
ENDS

ARP_SEND_REPLY STRUCT
	DestAddress IPAddr
	SrcAddress IPAddr
ENDS

TCP_RESERVE_PORT_RANGE STRUCT
	UpperRange DW
	LowerRange DW
ENDS

IP_ADAPTER_INDEX_MAP STRUCT
	Index DD
	Name DW MAX_ADAPTER_NAME DUP
ENDS

IP_INTERFACE_INFO STRUCT
	NumAdapters DD
	Adapter IP_ADAPTER_INDEX_MAP
ENDS

IP_UNIDIRECTIONAL_ADAPTER_ADDRESS STRUCT
	NumAdapters DD
	Address IPAddr
ENDS

IP_ADAPTER_ORDER_MAP STRUCT
	NumAdapters DD
	AdapterOrder DD
ENDS

#endif

