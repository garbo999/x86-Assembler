#ifndef WINSOCK2_H
#define WINSOCK2_H
#define WINSOCK_H

/* Windows WinSock 2 API definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Ws2_32.dll
#ENDIF

#ifndef GUID
GUID STRUCT
    Data1     dd
    Data2     dw
    Data3     dw
    Data4     db 8 DUP
ENDS
#endif

#IFNDEF QOS_H
	#include qos.h // WIN32/64
#ENDIF

#ifndef INCL_WINSOCK_API_PROTOTYPES
	#define INCL_WINSOCK_API_PROTOTYPES  1
#endif

#ifndef INCL_WINSOCK_API_TYPEDEFS
	#define INCL_WINSOCK_API_TYPEDEFS  0
#endif

#ifndef WINDOWS_H
	#include windows.h // WIN32/64
#endif

#ifndef WINSOCK_VERSION
	#define WINSOCK_VERSION 202h
#endif

#ifndef FD_SETSIZE
	#define FD_SETSIZE  64
#endif

fd_set STRUCT
    u_int fd_count DD
	fd_array DD FD_SETSIZE DUP
ENDS

timeval STRUCT
	tv_sec DD
	tv_usec DD
ENDS

#define IOCPARM_MASK  0x7f
#define IOC_VOID  0x20000000
#define IOC_OUT  0x40000000
#define IOC_IN   0x80000000
#define IOC_INOUT  0xC0000000

#ifndef HOSTENT
	HOSTENT STRUCT
		h_name PTR
		h_aliases PTR
		h_addrtype DW
		h_length DW
		h_addr_list PTR
	ENDS
	
	#define hostent HOSTENT
	
	NETENT STRUCT
		n_name PTR
		n_aliases PTR
		n_addrtype DW
		n_net DD
	ENDS
	
	#define netent NETENT
	
	SERVENT STRUCT
		s_name PTR
		s_aliases PTR
		#ifdef WIN64
			s_proto PTR
			s_port DW
		#else
			s_port DW
			s_proto PTR
		#endif
	ENDS
	
	#define servent SERVENT

	PROTOENT STRUCT
		p_name PTR
		p_aliases PTR
		p_proto DW
	ENDS

	#define protoent PROTOENT

#endif

#define IPPROTO_IP  0
#define IPPROTO_ICMP  1
#define IPPROTO_IGMP  2
#define IPPROTO_GGP  3
#define IPPROTO_TCP  6
#define IPPROTO_PUP  12
#define IPPROTO_UDP  17
#define IPPROTO_IDP  22
#define IPPROTO_ND  77
#define IPPROTO_RAW  255
#define IPPROTO_MAX  256

#define IPPORT_ECHO  7
#define IPPORT_DISCARD  9
#define IPPORT_SYSTAT  11
#define IPPORT_DAYTIME  13
#define IPPORT_NETSTAT  15
#define IPPORT_FTP  21
#define IPPORT_TELNET  23
#define IPPORT_SMTP  25
#define IPPORT_TIMESERVER  37
#define IPPORT_NAMESERVER  42
#define IPPORT_WHOIS  43
#define IPPORT_MTP  57
#define IPPORT_TFTP  69
#define IPPORT_RJE  77
#define IPPORT_FINGER  79
#define IPPORT_TTYLINK  87
#define IPPORT_SUPDUP  95
#define IPPORT_EXECSERVER  512
#define IPPORT_LOGINSERVER  513
#define IPPORT_CMDSERVER  514
#define IPPORT_EFSSERVER  520
#define IPPORT_BIFFUDP  512
#define IPPORT_WHOSERVER  513
#define IPPORT_ROUTESERVER  520
#define IPPORT_RESERVED  1024

#define IMPLINK_IP  155
#define IMPLINK_LOWEXPER  156
#define IMPLINK_HIGHEXPER  158

#ifndef in_addr
	in_addr STRUCT
		UNION
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
#endif

#define IN_CLASSA_NET  0xff000000
#define IN_CLASSA_NSHIFT  24
#define IN_CLASSA_HOST  0x00ffffff
#define IN_CLASSA_MAX  128

#define IN_CLASSB_NET  0xffff0000
#define IN_CLASSB_NSHIFT  16
#define IN_CLASSB_HOST  0x0000ffff
#define IN_CLASSB_MAX  65536

#define IN_CLASSC_NET  0xffffff00
#define IN_CLASSC_NSHIFT  8
#define IN_CLASSC_HOST  0x000000ff

#define IN_CLASSD_NET  0xf0000000
#define IN_CLASSD_NSHIFT  28
#define IN_CLASSD_HOST  0x0fffffff

#define INADDR_ANY  0x00000000
#define INADDR_LOOPBACK  0x7f000001
#define INADDR_BROADCAST  0xffffffff
#define INADDR_NONE  0xffffffff

#define ADDR_ANY  INADDR_ANY

#ifndef sockaddr_in
	sockaddr_in STRUCT
		sin_family DW
		sin_port DW
	    sin_addr in_addr
		sin_zero DB 8 DUP
	ENDS
	#define SOCKADDR_IN  sockaddr_in
#endif

#ifndef WSADATA
	#define WSADESCRIPTION_LEN  256
	#define WSASYS_STATUS_LEN  128

WSADATA STRUCT
	wVersion DW
	wHighVersion DW
#ifdef WIN64
	iMaxSockets DW
	iMaxUdpDg DW
	lpVendorInfo DQ
	szDescription DB (WSADESCRIPTION_LEN+1) DUP
	szSystemStatus DB (WSASYS_STATUS_LEN+1) DUP
#else
	szDescription DB (WSADESCRIPTION_LEN+1) DUP
	szSystemStatus DB (WSADESCRIPTION_LEN+1) DUP
	iMaxSockets DW
	iMaxUdpDg DW
	lpVendorInfo PTR
#endif
ENDS
#endif

#define SOCKET_ERROR  -1

#define FROM_PROTOCOL_INFO  -1

#define SOCK_STREAM  1
#define SOCK_DGRAM  2
#define SOCK_RAW  3
#define SOCK_RDM  4
#define SOCK_SEQPACKET  5

#define SO_DEBUG  0x0001
#define SO_ACCEPTCONN  0x0002
#define SO_REUSEADDR  0x0004
#define SO_KEEPALIVE  0x0008
#define SO_DONTROUTE  0x0010
#define SO_BROADCAST  0x0020
#define SO_USELOOPBACK  0x0040
#define SO_LINGER  0x0080
#define SO_OOBINLINE  0x0100
#define SO_DONTLINGER  0FFFFFF7Fh
#define SO_EXCLUSIVEADDRUSE 0FFFFFFFBh

#define SO_SNDBUF  0x1001
#define SO_RCVBUF  0x1002
#define SO_SNDLOWAT  0x1003
#define SO_RCVLOWAT  0x1004
#define SO_SNDTIMEO  0x1005
#define SO_RCVTIMEO  0x1006
#define SO_ERROR  0x1007
#define SO_TYPE  0x1008

#define SO_GROUP_ID  0x2001
#define SO_GROUP_PRIORITY 0x2002
#define SO_MAX_MSG_SIZE  0x2003
#define SO_PROTOCOL_INFOA 0x2004
#define SO_PROTOCOL_INFOW 0x2005

#IFDEF UNICODE
	#define SO_PROTOCOL_INFO  SO_PROTOCOL_INFOW
#else
	#define SO_PROTOCOL_INFO  SO_PROTOCOL_INFOA
#endif

#define PVD_CONFIG  0x3001
#define SO_CONDITIONAL_ACCEPT 0x3002

#define TCP_NODELAY  0x0001

#define AF_UNSPEC  0
#define AF_UNIX  1
#define AF_INET  2
#define AF_IMPLINK  3
#define AF_PUP  4
#define AF_CHAOS  5
#define AF_NS  6
#define AF_IPX  AF_NS
#define AF_ISO  7
#define AF_OSI  AF_ISO
#define AF_ECMA  8
#define AF_DATAKIT  9
#define AF_CCITT  10
#define AF_SNA  11
#define AF_DECnet  12
#define AF_DLI  13
#define AF_LAT  14
#define AF_HYLINK  15
#define AF_APPLETALK  16
#define AF_NETBIOS  17
#define AF_VOICEVIEW  18
#define AF_FIREFOX  19
#define AF_UNKNOWN1  20
#define AF_BAN  21
#define AF_ATM  22
#define AF_INET6  23
#define AF_CLUSTER  24
#define AF_12844  25
#define AF_IRDA  26
#define AF_NETDES  28
#define AF_MAX  29

#ifndef sockaddr
	sockaddr STRUCT
		sa_family DW
		sa_data DB 14 DUP
	ENDS
	
	#define SOCKADDR sockaddr
	
	sockproto STRUCT
		sp_family DW
		sp_protocol DW
	ENDS

	#define SOCKPROTO sockproto
	
#endif

#define PF_UNSPEC  AF_UNSPEC
#define PF_UNIX  AF_UNIX
#define PF_INET  AF_INET
#define PF_IMPLINK  AF_IMPLINK
#define PF_PUP  AF_PUP
#define PF_CHAOS  AF_CHAOS
#define PF_NS  AF_NS
#define PF_IPX  AF_IPX
#define PF_ISO  AF_ISO
#define PF_OSI  AF_OSI
#define PF_ECMA  AF_ECMA
#define PF_DATAKIT  AF_DATAKIT
#define PF_CCITT  AF_CCITT
#define PF_SNA  AF_SNA
#define PF_DECnet  AF_DECnet
#define PF_DLI  AF_DLI
#define PF_LAT  AF_LAT
#define PF_HYLINK  AF_HYLINK
#define PF_APPLETALK  AF_APPLETALK
#define PF_VOICEVIEW  AF_VOICEVIEW
#define PF_FIREFOX  AF_FIREFOX
#define PF_UNKNOWN1  AF_UNKNOWN1
#define PF_BAN  AF_BAN
#define PF_ATM  AF_ATM
#define PF_INET6  AF_INET6
#define PF_MAX  AF_MAX

linger STRUCT
	l_onoff DW
	l_linger DW
ENDS

#define LINGER linger

#define SOL_SOCKET  0xffff

#define SOMAXCONN  0x7fffffff

#define MSG_OOB  0x1
#define MSG_PEEK  0x2
#define MSG_DONTROUTE  0x4
#define MSG_PARTIAL  0x8000
#define MSG_INTERRUPT  0x10
#define MSG_MAXIOVLEN  16

#define MAXGETHOSTSTRUCT  1024

#define FD_READ_BIT  0
#define FD_READ  (1<<FD_READ_BIT)
#define FD_WRITE_BIT  1
#define FD_WRITE  10b
#define FD_OOB_BIT  2
#define FD_OOB  (1<<FD_OOB_BIT)
#define FD_ACCEPT_BIT  3
#define FD_ACCEPT  (1<<FD_ACCEPT_BIT)
#define FD_CONNECT_BIT  4
#define FD_CONNECT  (1<<FD_CONNECT_BIT)
#define FD_CLOSE_BIT  5
#define FD_CLOSE  (1<<FD_CLOSE_BIT)
#define FD_QOS_BIT  6
#define FD_QOS  (1<<FD_QOS_BIT)
#define FD_GROUP_QOS_BIT 7
#define FD_GROUP_QOS  (1<<FD_GROUP_QOS_BIT)
#define FD_ROUTING_INTERFACE_CHANGE_BIT 8
#define FD_ROUTING_INTERFACE_CHANGE  (1<<FD_ROUTING_INTERFACE_CHANGE_BIT)
#define FD_ADDRESS_LIST_CHANGE_BIT 9
#define FD_ADDRESS_LIST_CHANGE  (1<<FD_ADDRESS_LIST_CHANGE_BIT)
#define FD_MAX_EVENTS  10
#define FD_ALL_EVENTS  ((1<<FD_MAX_EVENTS)-1)

#ifndef WSABASEERR
#define WSABASEERR  10000
#define WSAEINTR  (WSABASEERR+4)
#define WSAEBADF  (WSABASEERR+9)
#define WSAEACCES  (WSABASEERR+13)
#define WSAEFAULT  (WSABASEERR+14)
#define WSAEINVAL  (WSABASEERR+22)
#define WSAEMFILE  (WSABASEERR+24)
#define WSAEWOULDBLOCK  (WSABASEERR+35)
#define WSAEINPROGRESS  (WSABASEERR+36)
#define WSAEALREADY  (WSABASEERR+37)
#define WSAENOTSOCK  (WSABASEERR+38)
#define WSAEDESTADDRREQ  (WSABASEERR+39)
#define WSAEMSGSIZE  (WSABASEERR+40)
#define WSAEPROTOTYPE  (WSABASEERR+41)
#define WSAENOPROTOOPT  (WSABASEERR+42)
#define WSAEPROTONOSUPPORT  (WSABASEERR+43)
#define WSAESOCKTNOSUPPORT  (WSABASEERR+44)
#define WSAEOPNOTSUPP  (WSABASEERR+45)
#define WSAEPFNOSUPPORT  (WSABASEERR+46)
#define WSAEAFNOSUPPORT  (WSABASEERR+47)
#define WSAEADDRINUSE  (WSABASEERR+48)
#define WSAEADDRNOTAVAIL  (WSABASEERR+49)
#define WSAENETDOWN  (WSABASEERR+50)
#define WSAENETUNREACH  (WSABASEERR+51)
#define WSAENETRESET  (WSABASEERR+52)
#define WSAECONNABORTED  (WSABASEERR+53)
#define WSAECONNRESET  (WSABASEERR+54)
#define WSAENOBUFS  (WSABASEERR+55)
#define WSAEISCONN  (WSABASEERR+56)
#define WSAENOTCONN  (WSABASEERR+57)
#define WSAESHUTDOWN  (WSABASEERR+58)
#define WSAETOOMANYREFS  (WSABASEERR+59)
#define WSAETIMEDOUT  (WSABASEERR+60)
#define WSAECONNREFUSED  (WSABASEERR+61)
#define WSAELOOP  (WSABASEERR+62)
#define WSAENAMETOOLONG  (WSABASEERR+63)
#define WSAEHOSTDOWN  (WSABASEERR+64)
#define WSAEHOSTUNREACH  (WSABASEERR+65)
#define WSAENOTEMPTY  (WSABASEERR+66)
#define WSAEPROCLIM  (WSABASEERR+67)
#define WSAEUSERS  (WSABASEERR+68)
#define WSAEDQUOT  (WSABASEERR+69)
#define WSAESTALE  (WSABASEERR+70)
#define WSAEREMOTE  (WSABASEERR+71)
#define WSASYSNOTREADY  (WSABASEERR+91)
#define WSAVERNOTSUPPORTED  (WSABASEERR+92)
#define WSANOTINITIALISED  (WSABASEERR+93)
#define WSAEDISCON  (WSABASEERR+101)
#define WSAENOMORE  (WSABASEERR+102)
#define WSAECANCELLED  (WSABASEERR+103)
#define WSAEINVALIDPROCTABLE  (WSABASEERR+104)
#define WSAEINVALIDPROVIDER  (WSABASEERR+105)
#define WSAEPROVIDERFAILEDINIT  (WSABASEERR+106)
#define WSASYSCALLFAILURE  (WSABASEERR+107)
#define WSASERVICE_NOT_FOUND  (WSABASEERR+108)
#define WSATYPE_NOT_FOUND  (WSABASEERR+109)
#define WSA_E_NO_MORE  (WSABASEERR+110)
#define WSA_E_CANCELLED  (WSABASEERR+111)
#define WSAEREFUSED  (WSABASEERR+112)
#define WSAHOST_NOT_FOUND  (WSABASEERR+1001)
#define WSATRY_AGAIN  (WSABASEERR+1002)
#define WSANO_RECOVERY  (WSABASEERR+1003)
#define WSANO_DATA  (WSABASEERR+1004)
#define WSA_QOS_RECEIVERS  (WSABASEERR+1005)
#define WSA_QOS_SENDERS  (WSABASEERR+1006)
#define WSA_QOS_NO_SENDERS  (WSABASEERR+1007)
#define WSA_QOS_NO_RECEIVERS  (WSABASEERR+1008)
#define WSA_QOS_REQUEST_CONFIRMED  (WSABASEERR+1009)
#define WSA_QOS_ADMISSION_FAILURE  (WSABASEERR+1010)
#define WSA_QOS_POLICY_FAILURE  (WSABASEERR+1011)
#define WSA_QOS_BAD_STYLE  (WSABASEERR+1012)
#define WSA_QOS_BAD_OBJECT  (WSABASEERR+1013)
#define WSA_QOS_TRAFFIC_CTRL_ERROR  (WSABASEERR+1014)
#define WSA_QOS_GENERIC_ERROR  (WSABASEERR+1015)
#define WSA_QOS_ESERVICETYPE  (WSABASEERR+1016)
#define WSA_QOS_EFLOWSPEC  (WSABASEERR+1017)
#define WSA_QOS_EPROVSPECBUF  (WSABASEERR+1018)
#define WSA_QOS_EFILTERSTYLE  (WSABASEERR+1019)
#define WSA_QOS_EFILTERTYPE  (WSABASEERR+1020)
#define WSA_QOS_EFILTERCOUNT  (WSABASEERR+1021)
#define WSA_QOS_EOBJLENGTH  (WSABASEERR+1022)
#define WSA_QOS_EFLOWCOUNT  (WSABASEERR+1023)
#define WSA_QOS_EUNKOWNPSOBJ  (WSABASEERR+1024)
#define WSA_QOS_EPOLICYOBJ  (WSABASEERR+1025)
#define WSA_QOS_EFLOWDESC  (WSABASEERR+1026)
#define WSA_QOS_EPSFLOWSPEC  (WSABASEERR+1027)
#define WSA_QOS_EPSFILTERSPEC  (WSABASEERR+1028)
#define WSA_QOS_ESDMODEOBJ  (WSABASEERR+1029)
#define WSA_QOS_ESHAPERATEOBJ  (WSABASEERR+1030)
#define WSA_QOS_RESERVED_PETYPE  (WSABASEERR+1031)
#endif

#define HOST_NOT_FOUND  WSAHOST_NOT_FOUND
#define TRY_AGAIN  WSATRY_AGAIN
#define NO_RECOVERY  WSANO_RECOVERY
#define NO_DATA  WSANO_DATA
#define WSANO_ADDRESS  WSANO_DATA
#define NO_ADDRESS  WSANO_ADDRESS

#define WSAAPI  PASCAL
#define WSAEVENT  HANDLE
#define WSAOVERLAPPED  OVERLAPPED

#define WSA_IO_PENDING  (ERROR_IO_PENDING)
#define WSA_IO_INCOMPLETE  (ERROR_IO_INCOMPLETE)
#define WSA_INVALID_HANDLE  (ERROR_INVALID_HANDLE)
#define WSA_INVALID_PARAMETER  (ERROR_INVALID_PARAMETER)
#define WSA_NOT_ENOUGH_MEMORY  (ERROR_NOT_ENOUGH_MEMORY)
#define WSA_OPERATION_ABORTED  (ERROR_OPERATION_ABORTED)

#define WSA_INVALID_EVENT  ((WSAEVENT)NULL)
#define WSA_MAXIMUM_WAIT_EVENTS (MAXIMUM_WAIT_OBJECTS)
#define WSA_WAIT_FAILED  (WAIT_FAILED)
#define WSA_WAIT_EVENT_0  (WAIT_OBJECT_0)
#define WSA_WAIT_IO_COMPLETION  (WAIT_IO_COMPLETION)
#define WSA_WAIT_TIMEOUT  (WAIT_TIMEOUT)
#define WSA_INFINITE  (INFINITE)

WSABUF STRUCT
	len DD
	buf PTR
ENDS

QualityOfService STRUCT
	SendingFlowspec FLOWSPEC
	ReceivingFlowspec FLOWSPEC
	ProviderSpecific WSABUF
ENDS

#define CF_ACCEPT  0x0000
#define CF_REJECT  0x0001
#define CF_DEFER  0x0002

#define SD_RECEIVE  0x00
#define SD_SEND  0x01
#define SD_BOTH  0x02

#define SG_UNCONSTRAINED_GROUP  0x01
#define SG_CONSTRAINED_GROUP  0x02

WSANETWORKEVENTS STRUCT
	lNetworkEvents DD
	iErrorCode DD FD_MAX_EVENTS DUP
ENDS

#define MAX_PROTOCOL_CHAIN 7

#define BASE_PROTOCOL  1
#define LAYERED_PROTOCOL  0

WSAPROTOCOLCHAIN STRUCT
	ChainLen DD
	ChainEntries DD MAX_PROTOCOL_CHAIN DUP
ENDS

#define WSAPROTOCOL_LEN  255

WSAPROTOCOL_INFOA STRUCT
	dwServiceFlags1 DD
	dwServiceFlags2 DD
	dwServiceFlags3 DD
	dwServiceFlags4 DD
	dwProviderFlags DD
	ProviderId GUID
	dwCatalogEntryId DD
	ProtocolChain WSAPROTOCOLCHAIN
	iVersion DD
	iAddressFamily DD
	iMaxSockAddr DD
	iMinSockAddr DD
	iSocketType DD
	iProtocol DD
	iProtocolMaxOffset DD
	iNetworkByteOrder DD
	iSecurityScheme DD
	dwMessageSize DD
	dwProviderReserved DD
	szProtocol DB WSAPROTOCOL_LEN+1 DUP
ENDS

WSAPROTOCOL_INFOW STRUCT
	dwServiceFlags1 DD
	dwServiceFlags2 DD
	dwServiceFlags3 DD
	dwServiceFlags4 DD
	dwProviderFlags DD
	ProviderId GUID
	dwCatalogEntryId DD
	ProtocolChain WSAPROTOCOLCHAIN
	iVersion DD
	iAddressFamily DD
	iMaxSockAddr DD
	iMinSockAddr DD
	iSocketType DD
	iProtocol DD
	iProtocolMaxOffset DD
	iNetworkByteOrder DD
	iSecurityScheme DD
	dwMessageSize DD
	dwProviderReserved DD
	szProtocol DW WSAPROTOCOL_LEN+1 DUP
ENDS

#IFDEF UNICODE
	#define WSAPROTOCOL_INFO WSAPROTOCOL_INFOW
#else
	#define WSAPROTOCOL_INFO WSAPROTOCOL_INFOA
#endif

#define PFL_MULTIPLE_PROTO_ENTRIES  0x00000001
#define PFL_RECOMMENDED_PROTO_ENTRY  0x00000002
#define PFL_HIDDEN  0x00000004
#define PFL_MATCHES_PROTOCOL_ZERO  0x00000008

#define XP1_CONNECTIONLESS  0x00000001
#define XP1_GUARANTEED_DELIVERY  0x00000002
#define XP1_GUARANTEED_ORDER  0x00000004
#define XP1_MESSAGE_ORIENTED  0x00000008
#define XP1_PSEUDO_STREAM  0x00000010
#define XP1_GRACEFUL_CLOSE  0x00000020
#define XP1_EXPEDITED_DATA  0x00000040
#define XP1_CONNECT_DATA  0x00000080
#define XP1_DISCONNECT_DATA  0x00000100
#define XP1_SUPPORT_BROADCAST  0x00000200
#define XP1_SUPPORT_MULTIPOINT  0x00000400
#define XP1_MULTIPOINT_CONTROL_PLANE  0x00000800
#define XP1_MULTIPOINT_DATA_PLANE  0x00001000
#define XP1_QOS_SUPPORTED  0x00002000
#define XP1_INTERRUPT  0x00004000
#define XP1_UNI_SEND  0x00008000
#define XP1_UNI_RECV  0x00010000
#define XP1_IFS_HANDLES  0x00020000
#define XP1_PARTIAL_MESSAGE  0x00040000

#define BIGENDIAN  0x0000
#define LITTLEENDIAN  0x0001

#define SECURITY_PROTOCOL_NONE  0x0000

#define JL_SENDER_ONLY  0x01
#define JL_RECEIVER_ONLY  0x02
#define JL_BOTH  0x04

#define WSA_FLAG_OVERLAPPED  0x01
#define WSA_FLAG_MULTIPOINT_C_ROOT  0x02
#define WSA_FLAG_MULTIPOINT_C_LEAF  0x04
#define WSA_FLAG_MULTIPOINT_D_ROOT  0x08
#define WSA_FLAG_MULTIPOINT_D_LEAF  0x10

#define IOC_UNIX  0x00000000
#define IOC_WS2  0x08000000
#define IOC_PROTOCOL  0x10000000
#define IOC_VENDOR  0x18000000

#define TH_NETDEV  0x00000001
#define TH_TAPI  0x00000002

#ifndef BLOB_DEFINED
#define BLOB_DEFINED
BLOB STRUCT
	cbSize DD
	pBlobData PTR
ENDS
#endif

#define SERVICE_MULTIPLE 1

#define NS_ALL  0
#define NS_SAP  1
#define NS_NDS  2
#define NS_PEER_BROWSE  3
#define NS_SLP  5
#define NS_DHCP  6
#define NS_TCPIP_LOCAL  10
#define NS_TCPIP_HOSTS  11
#define NS_DNS  12
#define NS_NETBT  13
#define NS_WINS  14
#define NS_NBP  20
#define NS_MS  30
#define NS_STDA  31
#define NS_NTDS  32
#define NS_X500  40
#define NS_NIS  41
#define NS_NISPLUS  42
#define NS_WRQ  50
#define NS_NETDES  60

#define RES_UNUSED_1  0x00000001
#define RES_FLUSH_CACHE  0x00000002
#ifndef RES_SERVICE
	#define RES_SERVICE  0x00000004
#endif

#define SERVICE_TYPE_VALUE_IPXPORTA  A"IpxSocket"
#define SERVICE_TYPE_VALUE_IPXPORTW  L"IpxSocket"
#define SERVICE_TYPE_VALUE_SAPIDA  A"SapId"
#define SERVICE_TYPE_VALUE_SAPIDW  L"SapId"
#define SERVICE_TYPE_VALUE_TCPPORTA  A"TcpPort"
#define SERVICE_TYPE_VALUE_TCPPORTW  L"TcpPort"
#define SERVICE_TYPE_VALUE_UDPPORTA  A"UdpPort"
#define SERVICE_TYPE_VALUE_UDPPORTW  L"UdpPort"
#define SERVICE_TYPE_VALUE_OBJECTIDA  A"ObjectId"
#define SERVICE_TYPE_VALUE_OBJECTIDW  L"ObjectId"

#IFDEF UNICODE
	#define SERVICE_TYPE_VALUE_SAPID  SERVICE_TYPE_VALUE_SAPIDW
	#define SERVICE_TYPE_VALUE_TCPPORT  SERVICE_TYPE_VALUE_TCPPORTW
	#define SERVICE_TYPE_VALUE_UDPPORT  SERVICE_TYPE_VALUE_UDPPORTW
	#define SERVICE_TYPE_VALUE_OBJECTID  SERVICE_TYPE_VALUE_OBJECTIDW
#else
	#define SERVICE_TYPE_VALUE_SAPID  SERVICE_TYPE_VALUE_SAPIDA
	#define SERVICE_TYPE_VALUE_TCPPORT  SERVICE_TYPE_VALUE_TCPPORTA
	#define SERVICE_TYPE_VALUE_UDPPORT  SERVICE_TYPE_VALUE_UDPPORTA
	#define SERVICE_TYPE_VALUE_OBJECTID  SERVICE_TYPE_VALUE_OBJECTIDA
#endif

SOCKET_ADDRESS STRUCT
	lpSockaddr PTR
	iSockaddrLength DD
ENDS

CSADDR_INFO STRUCT
	LocalAddr SOCKET_ADDRESS
	RemoteAddr SOCKET_ADDRESS
	iSocketType DD
	iProtocol DD
ENDS

SOCKET_ADDRESS_LIST STRUCT
	iAddressCount DD
	Address SOCKET_ADDRESS
ENDS

AFPROTOCOLS STRUCT
	iAddressFamily DD
	iProtocol DD
ENDS

COMP_EQUAL =0
COMP_NOTLESS =1

WSAVERSION STRUCT
	dwVersion DD
	ecHow DD
ENDS

WSAQUERYSETA STRUCT
	dwSize DD
	lpszServiceInstanceName PTR
	lpServiceClassId PTR
	lpVersion PTR
	lpszComment PTR
	dwNameSpace DD
	lpNSProviderId PTR
	lpszContext PTR
	dwNumberOfProtocols DD
	lpafpProtocols PTR
	lpszQueryString PTR
	dwNumberOfCsAddrs DD
	lpcsaBuffer PTR
	dwOutputFlags DD
	lpBlob PTR
ENDS

WSAQUERYSETW STRUCT
	dwSize DD
	lpszServiceInstanceName PTR
	lpServiceClassId PTR
	lpVersion PTR
	lpszComment PTR
	dwNameSpace DD
	lpNSProviderId PTR
	lpszContext PTR
	dwNumberOfProtocols DD
	lpafpProtocols PTR
	lpszQueryString PTR
	dwNumberOfCsAddrs DD
	lpcsaBuffer PTR
	dwOutputFlags DD
	lpBlob PTR
ENDS

#IFDEF UNICODE
#define WSAQUERYSET WSAQUERYSETW
#else
#define WSAQUERYSET WSAQUERYSETA
#endif

#define LUP_DEEP  0x0001
#define LUP_CONTAINERS  0x0002
#define LUP_NOCONTAINERS  0x0004
#define LUP_NEAREST  0x0008
#define LUP_RETURN_NAME  0x0010
#define LUP_RETURN_TYPE  0x0020
#define LUP_RETURN_VERSION  0x0040
#define LUP_RETURN_COMMENT  0x0080
#define LUP_RETURN_ADDR  0x0100
#define LUP_RETURN_BLOB  0x0200
#define LUP_RETURN_ALIASES  0x0400
#define LUP_RETURN_QUERY_STRING 0x0800
#define LUP_RETURN_ALL  0x0FF0
#define LUP_RES_SERVICE  0x8000
#define LUP_FLUSHCACHE  0x1000
#define LUP_FLUSHPREVIOUS  0x2000

#define RESULT_IS_ALIAS  0x0001

RNRSERVICE_REGISTER = 0,
RNRSERVICE_DEREGISTER = 1
RNRSERVICE_DELETE = 2

WSANSCLASSINFOA STRUCT
	lpszName PTR
	dwNameSpace DD
	dwValueType DD
	dwValueSize DD
	lpValue PTR
ENDS

WSANSCLASSINFOW STRUCT
	lpszName PTR
	dwNameSpace DD
	dwValueType DD
	dwValueSize DD
	lpValue PTR
ENDS

#IFDEF UNICODE
	#define WSANSCLASSINFO WSANSCLASSINFOW
#else
	#define WSANSCLASSINFO WSANSCLASSINFOA
#endif

WSASERVICECLASSINFOA STRUCT
	lpServiceClassId PTR
	lpszServiceClassName PTR
	dwCount DD
	lpClassInfos PTR
ENDS

WSASERVICECLASSINFOW STRUCT
	lpServiceClassId PTR
	lpszServiceClassName PTR
	dwCount DD
	lpClassInfos PTR
ENDS

#IFDEF UNICODE
	#define WSASERVICECLASSINFO WSASERVICECLASSINFOW
#else
	#define WSASERVICECLASSINFO WSASERVICECLASSINFOA
#endif

WSANAMESPACE_INFOA STRUCT
	NSProviderId GUID
	dwNameSpace DD
	fActive DD
	dwVersion DD
	lpszIdentifier PTR
ENDS

WSANAMESPACE_INFOW STRUCT
	NSProviderId GUID
	dwNameSpace DD
	fActive DD
	dwVersion DD
	lpszIdentifier PTR
ENDS

#IFDEF UNICODE
	#define WSANAMESPACE_INFO WSANAMESPACE_INFOW
#else
	#define WSANAMESPACE_INFO WSANAMESPACE_INFOA
#endif

#IFDEF UNICODE
	#define WSADuplicateSocket  WSADuplicateSocketW
	#define WSAEnumProtocols  WSAEnumProtocolsW
	#define WSASocket  WSASocketW
	#define WSAAddressToString  WSAAddressToStringW
	#define WSAStringToAddress  WSAStringToAddressW
	#define WSALookupServiceBegin  WSALookupServiceBeginW
	#define WSALookupServiceNext  WSALookupServiceNextW
	#define WSAInstallServiceClass  WSAInstallServiceClassW
	#define WSAGetServiceClassInfo  WSAGetServiceClassInfoW
	#define WSAEnumNameSpaceProviders  WSAEnumNameSpaceProvidersW
	#define WSAGetServiceClassNameByClassId  WSAGetServiceClassNameByClassIdW
	#define WSASetService  WSASetServiceW
#else
	#define WSADuplicateSocket  WSADuplicateSocketA
	#define WSAEnumProtocols  WSAEnumProtocolsA
	#define WSASocket  WSASocketA
	#define WSAAddressToString  WSAAddressToStringA
	#define WSAStringToAddress  WSAStringToAddressA
	#define WSALookupServiceBegin  WSALookupServiceBeginA
	#define WSALookupServiceNext  WSALookupServiceNextA
	#define WSAInstallServiceClass  WSAInstallServiceClassA
	#define WSAGetServiceClassInfo  WSAGetServiceClassInfoA
	#define WSAEnumNameSpaceProviders  WSAEnumNameSpaceProvidersA
	#define WSAGetServiceClassNameByClassId  WSAGetServiceClassNameByClassIdA
	#define WSASetService  WSASetServiceA
#endif

#endif
