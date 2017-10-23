;=============================================================;
;          winsock2.inc file for Easy Code visual IDE         ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINSOCK2_INC
#Define WINSOCK2_INC

#IFNDEF WINDOWS_INC
	#Include <windows.inc>
#ENDIF

#IFNDEF FD_SETSIZE
	#Define FD_SETSIZE      			64
#ENDIF

#IFNDEF QOS_INC
	#Include <qos.inc>
#ENDIF

#Define IOCPARM_MASK    				07FH
#Define IOC_VOID        				020000000H
#Define IOC_OUT         				040000000H
#Define IOC_IN          				080000000H
#Define IOC_INOUT       				(IOC_IN | IOC_OUT)

#Define IPPROTO_IP              		0
#Define IPPROTO_ICMP            		1
#Define IPPROTO_IGMP            		2
#Define IPPROTO_GGP             		3
#Define IPPROTO_TCP             		6
#Define IPPROTO_PUP             		12
#Define IPPROTO_UDP             		17
#Define IPPROTO_IDP             		22
#Define IPPROTO_ND              		77

#Define IPPROTO_RAW             		255
#Define IPPROTO_MAX             		256

#Define IPPORT_ECHO             		7
#Define IPPORT_DISCARD          		9
#Define IPPORT_SYSTAT           		11
#Define IPPORT_DAYTIME          		13
#Define IPPORT_NETSTAT          		15
#Define IPPORT_FTP              		21
#Define IPPORT_TELNET           		23
#Define IPPORT_SMTP             		25
#Define IPPORT_TIMESERVER       		37
#Define IPPORT_NAMESERVER       		42
#Define IPPORT_WHOIS            		43
#Define IPPORT_MTP              		57

#Define IPPORT_TFTP             		69
#Define IPPORT_RJE              		77
#Define IPPORT_FINGER           		79
#Define IPPORT_TTYLINK          		87
#Define IPPORT_SUPDUP           		95

#Define IPPORT_EXECSERVER       		512
#Define IPPORT_LOGINSERVER      		513
#Define IPPORT_CMDSERVER        		514
#Define IPPORT_EFSSERVER        		520

#Define IPPORT_BIFFUDP          		512
#Define IPPORT_WHOSERVER        		513
#Define IPPORT_ROUTESERVER      		520

#Define IPPORT_RESERVED         		1024

#Define IMPLINK_IP              		155
#Define IMPLINK_LOWEXPER        		156
#Define IMPLINK_HIGHEXPER       		158

#Define IN_CLASSA_NET           		0FF000000H
#Define IN_CLASSA_NSHIFT        		24
#Define IN_CLASSA_HOST          		000FFFFFFH
#Define IN_CLASSA_MAX           		128

#Define IN_CLASSB_NET           		0FFFF0000H
#Define IN_CLASSB_NSHIFT        		16
#Define IN_CLASSB_HOST          		00000FFFFH
#Define IN_CLASSB_MAX           		65536

#Define IN_CLASSC_NET           		0FFFFFF00H
#Define IN_CLASSC_NSHIFT        		8
#Define IN_CLASSC_HOST          		0000000FFH

#Define IN_CLASSD_NET           		0F0000000H
#Define IN_CLASSD_NSHIFT        		28
#Define IN_CLASSD_HOST          		00FFFFFFFH

#Define INADDR_ANY              		000000000H
#Define INADDR_LOOPBACK         		07F000001H
#Define INADDR_BROADCAST        		0FFFFFFFFH
#Define INADDR_NONE             		0FFFFFFFFH

#Define ADDR_ANY                		INADDR_ANY

#Define WSADESCRIPTION_LEN      		256
#Define WSASYS_STATUS_LEN       		128

#Define INVALID_SOCKET  				(~0)
#Define SOCKET_ERROR            		(-1)

#Define FROM_PROTOCOL_INFO				(-1)

#Define SOCK_STREAM     				1
#Define SOCK_DGRAM      				2
#Define SOCK_RAW        				3
#Define SOCK_RDM        				4
#Define SOCK_SEQPACKET  				5

#Define SO_DEBUG        				00001H
#Define SO_ACCEPTCONN   				00002H
#Define SO_REUSEADDR    				00004H
#Define SO_KEEPALIVE    				00008H
#Define SO_DONTROUTE    				00010H
#Define SO_BROADCAST    				00020H
#Define SO_USELOOPBACK  				00040H
#Define SO_LINGER       				00080H
#Define SO_OOBINLINE    				00100H

#Define SO_DONTLINGER					(~SO_LINGER)

#Define SO_SNDBUF       				01001H
#Define SO_RCVBUF       				01002H
#Define SO_SNDLOWAT     				01003H
#Define SO_RCVLOWAT     				01004H
#Define SO_SNDTIMEO     				01005H
#Define SO_RCVTIMEO     				01006H
#Define SO_ERROR        				01007H
#Define SO_TYPE         				01008H

#Define SO_GROUP_ID       				02001H
#Define SO_GROUP_PRIORITY 				02002H
#Define SO_MAX_MSG_SIZE   				02003H
#Define SO_PROTOCOL_INFOA 				02004H
#Define SO_PROTOCOL_INFOW 				02005H
#Define PVD_CONFIG        				03001H

#Define TCP_NODELAY     				00001H

#Define AF_UNSPEC       				0
#Define AF_UNIX         				1
#Define AF_INET         				2
#Define AF_IMPLINK      				3
#Define AF_PUP          				4
#Define AF_CHAOS        				5
#Define AF_IPX          				6
#Define AF_NS           				6
#Define AF_ISO          				7
#Define AF_OSI          				AF_ISO
#Define AF_ECMA         				8
#Define AF_DATAKIT      				9
#Define AF_CCITT        				10
#Define AF_SNA          				11
#Define AF_DECnet       				12
#Define AF_DLI          				13
#Define AF_LAT          				14
#Define AF_HYLINK       				15
#Define AF_APPLETALK    				16
#Define AF_NETBIOS      				17
#Define AF_VOICEVIEW    				18
#Define AF_FIREFOX      				19
#Define AF_UNKNOWN1     				20
#Define AF_BAN          				21
#Define AF_ATM          				22
#Define AF_INET6        				23
#Define AF_CLUSTER      				24
#Define AF_12844        				25

#Define AF_MAX          				26

#Define PF_UNSPEC       				AF_UNSPEC
#Define PF_UNIX         				AF_UNIX
#Define PF_INET         				AF_INET
#Define PF_IMPLINK      				AF_IMPLINK
#Define PF_PUP          				AF_PUP
#Define PF_CHAOS        				AF_CHAOS
#Define PF_NS           				AF_NS
#Define PF_IPX          				AF_IPX
#Define PF_ISO          				AF_ISO
#Define PF_OSI          				AF_OSI
#Define PF_ECMA         				AF_ECMA
#Define PF_DATAKIT      				AF_DATAKIT
#Define PF_CCITT        				AF_CCITT
#Define PF_SNA          				AF_SNA
#Define PF_DECnet       				AF_DECnet
#Define PF_DLI          				AF_DLI
#Define PF_LAT          				AF_LAT
#Define PF_HYLINK       				AF_HYLINK
#Define PF_APPLETALK    				AF_APPLETALK
#Define PF_VOICEVIEW    				AF_VOICEVIEW
#Define PF_FIREFOX      				AF_FIREFOX
#Define PF_UNKNOWN1     				AF_UNKNOWN1
#Define PF_BAN          				AF_BAN
#Define PF_ATM          				AF_ATM
#Define PF_INET6        				AF_INET6

#Define PF_MAX          				AF_MAX

#Define SOL_SOCKET      				0FFFFH

#Define SOMAXCONN       				07FFFFFFFH

#Define MSG_OOB         				01H
#Define MSG_PEEK        				02H
#Define MSG_DONTROUTE   				04H

#Define MSG_OOB         				01H
#Define MSG_PEEK        				02H
#Define MSG_DONTROUTE   				04H

#Define MSG_PARTIAL     				08000H

#Define MSG_INTERRUPT   				010H

#Define MSG_MAXIOVLEN   				16

#Define MAXGETHOSTSTRUCT        		1024

#Define FD_READ_BIT      				0
#Define FD_READ          				(1 << FD_READ_BIT)

#Define FD_WRITE_BIT     				1
#Define FD_WRITE         				(1 << FD_WRITE_BIT)

#Define FD_OOB_BIT       				2
#Define FD_OOB           				(1 << FD_OOB_BIT)

#Define FD_ACCEPT_BIT    				3
#Define FD_ACCEPT        				(1 << FD_ACCEPT_BIT)

#Define FD_CONNECT_BIT   				4
#Define FD_CONNECT       				(1 << FD_CONNECT_BIT)

#Define FD_CLOSE_BIT     				5
#Define FD_CLOSE         				(1 << FD_CLOSE_BIT)

#Define FD_QOS_BIT       				6
#Define FD_QOS           				(1 << FD_QOS_BIT)

#Define FD_GROUP_QOS_BIT 				7
#Define FD_GROUP_QOS     				(1 << FD_GROUP_QOS_BIT)

#Define FD_ROUTING_INTERFACE_CHANGE_BIT	8
#define FD_ROUTING_INTERFACE_CHANGE     (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)

#Define FD_ADDRESS_LIST_CHANGE_BIT 		9
#Define FD_ADDRESS_LIST_CHANGE     		(1 << FD_ADDRESS_LIST_CHANGE_BIT)

#Define FD_MAX_EVENTS    				10
#Define FD_ALL_EVENTS    				((1 << FD_MAX_EVENTS) - 1)

#Define WSABASEERR              		10000

#Define WSAEINTR                		(WSABASEERR+4)
#Define WSAEBADF                		(WSABASEERR+9)
#Define WSAEACCES               		(WSABASEERR+13)
#Define WSAEFAULT               		(WSABASEERR+14)
#Define WSAEINVAL               		(WSABASEERR+22)
#Define WSAEMFILE               		(WSABASEERR+24)

#Define WSAEWOULDBLOCK          		(WSABASEERR+35)
#Define WSAEINPROGRESS          		(WSABASEERR+36)
#Define WSAEALREADY             		(WSABASEERR+37)
#Define WSAENOTSOCK             		(WSABASEERR+38)
#Define WSAEDESTADDRREQ         		(WSABASEERR+39)
#Define WSAEMSGSIZE             		(WSABASEERR+40)
#Define WSAEPROTOTYPE           		(WSABASEERR+41)
#Define WSAENOPROTOOPT          		(WSABASEERR+42)
#Define WSAEPROTONOSUPPORT      		(WSABASEERR+43)
#Define WSAESOCKTNOSUPPORT      		(WSABASEERR+44)
#Define WSAEOPNOTSUPP           		(WSABASEERR+45)
#Define WSAEPFNOSUPPORT         		(WSABASEERR+46)
#Define WSAEAFNOSUPPORT         		(WSABASEERR+47)
#Define WSAEADDRINUSE           		(WSABASEERR+48)
#Define WSAEADDRNOTAVAIL        		(WSABASEERR+49)
#Define WSAENETDOWN             		(WSABASEERR+50)
#Define WSAENETUNREACH          		(WSABASEERR+51)
#Define WSAENETRESET            		(WSABASEERR+52)
#Define WSAECONNABORTED         		(WSABASEERR+53)
#Define WSAECONNRESET           		(WSABASEERR+54)
#Define WSAENOBUFS              		(WSABASEERR+55)
#Define WSAEISCONN              		(WSABASEERR+56)
#Define WSAENOTCONN             		(WSABASEERR+57)
#Define WSAESHUTDOWN            		(WSABASEERR+58)
#Define WSAETOOMANYREFS         		(WSABASEERR+59)
#Define WSAETIMEDOUT            		(WSABASEERR+60)
#Define WSAECONNREFUSED         		(WSABASEERR+61)
#Define WSAELOOP                		(WSABASEERR+62)
#Define WSAENAMETOOLONG         		(WSABASEERR+63)
#Define WSAEHOSTDOWN            		(WSABASEERR+64)
#Define WSAEHOSTUNREACH         		(WSABASEERR+65)
#Define WSAENOTEMPTY            		(WSABASEERR+66)
#Define WSAEPROCLIM             		(WSABASEERR+67)
#Define WSAEUSERS               		(WSABASEERR+68)
#Define WSAEDQUOT               		(WSABASEERR+69)
#Define WSAESTALE               		(WSABASEERR+70)
#Define WSAEREMOTE              		(WSABASEERR+71)

#Define WSASYSNOTREADY          		(WSABASEERR+91)
#Define WSAVERNOTSUPPORTED      		(WSABASEERR+92)
#Define WSANOTINITIALISED       		(WSABASEERR+93)
#Define WSAEDISCON              		(WSABASEERR+101)
#Define WSAENOMORE              		(WSABASEERR+102)
#Define WSAECANCELLED           		(WSABASEERR+103)
#Define WSAEINVALIDPROCTABLE    		(WSABASEERR+104)
#Define WSAEINVALIDPROVIDER     		(WSABASEERR+105)
#Define WSAEPROVIDERFAILEDINIT  		(WSABASEERR+106)
#Define WSASYSCALLFAILURE       		(WSABASEERR+107)
#Define WSASERVICE_NOT_FOUND    		(WSABASEERR+108)
#Define WSATYPE_NOT_FOUND       		(WSABASEERR+109)
#Define WSA_E_NO_MORE           		(WSABASEERR+110)
#Define WSA_E_CANCELLED         		(WSABASEERR+111)
#Define WSAEREFUSED             		(WSABASEERR+112)

#Define WSAHOST_NOT_FOUND       		(WSABASEERR+1001)
#Define HOST_NOT_FOUND          		WSAHOST_NOT_FOUND

#Define WSATRY_AGAIN            		(WSABASEERR+1002)
#Define TRY_AGAIN               		WSATRY_AGAIN

#Define WSANO_RECOVERY          		(WSABASEERR+1003)
#Define NO_RECOVERY             		WSANO_RECOVERY

#Define WSANO_DATA              		(WSABASEERR+1004)
#Define NO_DATA                 		WSANO_DATA

#Define WSANO_ADDRESS           		WSANO_DATA
#Define NO_ADDRESS              		WSANO_ADDRESS

#Define WSA_QOS_RECEIVERS               (WSABASEERR + 1005)
#Define WSA_QOS_SENDERS                 (WSABASEERR + 1006)
#Define WSA_QOS_NO_SENDERS              (WSABASEERR + 1007)
#Define WSA_QOS_NO_RECEIVERS            (WSABASEERR + 1008)
#Define WSA_QOS_REQUEST_CONFIRMED       (WSABASEERR + 1009)
#Define WSA_QOS_ADMISSION_FAILURE       (WSABASEERR + 1010)
#Define WSA_QOS_POLICY_FAILURE          (WSABASEERR + 1011)
#Define WSA_QOS_BAD_STYLE               (WSABASEERR + 1012)
#Define WSA_QOS_BAD_OBJECT              (WSABASEERR + 1013)
#Define WSA_QOS_TRAFFIC_CTRL_ERROR      (WSABASEERR + 1014)
#Define WSA_QOS_GENERIC_ERROR           (WSABASEERR + 1015)

#Define EWOULDBLOCK             		WSAEWOULDBLOCK
#Define EINPROGRESS             		WSAEINPROGRESS
#Define EALREADY                		WSAEALREADY
#Define ENOTSOCK                		WSAENOTSOCK
#Define EDESTADDRREQ            		WSAEDESTADDRREQ
#Define EMSGSIZE                		WSAEMSGSIZE
#Define EPROTOTYPE              		WSAEPROTOTYPE
#Define ENOPROTOOPT             		WSAENOPROTOOPT
#Define EPROTONOSUPPORT         		WSAEPROTONOSUPPORT
#Define ESOCKTNOSUPPORT         		WSAESOCKTNOSUPPORT
#Define EOPNOTSUPP              		WSAEOPNOTSUPP
#Define EPFNOSUPPORT            		WSAEPFNOSUPPORT
#Define EAFNOSUPPORT            		WSAEAFNOSUPPORT
#Define EADDRINUSE              		WSAEADDRINUSE
#Define EADDRNOTAVAIL           		WSAEADDRNOTAVAIL
#Define ENETDOWN                		WSAENETDOWN
#Define ENETUNREACH             		WSAENETUNREACH
#Define ENETRESET               		WSAENETRESET
#Define ECONNABORTED            		WSAECONNABORTED
#Define ECONNRESET              		WSAECONNRESET
#Define ENOBUFS                 		WSAENOBUFS
#Define EISCONN                 		WSAEISCONN
#Define ENOTCONN                		WSAENOTCONN
#Define ESHUTDOWN               		WSAESHUTDOWN
#Define ETOOMANYREFS            		WSAETOOMANYREFS
#Define ETIMEDOUT               		WSAETIMEDOUT
#Define ECONNREFUSED            		WSAECONNREFUSED
#Define ELOOP                   		WSAELOOP
#Define ENAMETOOLONG            		WSAENAMETOOLONG
#Define EHOSTDOWN               		WSAEHOSTDOWN
#Define EHOSTUNREACH            		WSAEHOSTUNREACH
#Define ENOTEMPTY               		WSAENOTEMPTY
#Define EPROCLIM                		WSAEPROCLIM
#Define EUSERS                  		WSAEUSERS
#Define EDQUOT                  		WSAEDQUOT
#Define ESTALE                  		WSAESTALE
#Define EREMOTE                 		WSAEREMOTE

#Define WSA_IO_PENDING          		ERROR_IO_PENDING
#Define WSA_IO_INCOMPLETE       		ERROR_IO_INCOMPLETE
#Define WSA_INVALID_HANDLE      		ERROR_INVALID_HANDLE
#Define WSA_INVALID_PARAMETER   		ERROR_INVALID_PARAMETER
#Define WSA_NOT_ENOUGH_MEMORY   		ERROR_NOT_ENOUGH_MEMORY
#Define WSA_OPERATION_ABORTED   		ERROR_OPERATION_ABORTED

#Define WSA_INVALID_EVENT       		NULL
#Define WSA_MAXIMUM_WAIT_EVENTS 		MAXIMUM_WAIT_OBJECTS
#Define WSA_WAIT_FAILED         		(-1)
#Define WSA_WAIT_EVENT_0        		WAIT_OBJECT_0
#Define WSA_WAIT_IO_COMPLETION  		WAIT_IO_COMPLETION
#Define WSA_WAIT_TIMEOUT        		WAIT_TIMEOUT
#Define WSA_INFINITE            		INFINITE

#Define CF_ACCEPT       				00000H
#Define CF_REJECT       				00001H
#Define CF_DEFER        				00002H

#Define SD_RECEIVE      				000H
#Define SD_SEND         				001H
#Define SD_BOTH         				002H

#Define SG_UNCONSTRAINED_GROUP   		001H
#Define SG_CONSTRAINED_GROUP     		002H

#Define MAX_PROTOCOL_CHAIN				7

#Define BASE_PROTOCOL      				1
#Define LAYERED_PROTOCOL   				0

#Define WSAPROTOCOL_LEN					255

#Define PFL_MULTIPLE_PROTO_ENTRIES      000000001H
#Define PFL_RECOMMENDED_PROTO_ENTRY     000000002H
#Define PFL_HIDDEN                      000000004H
#Define PFL_MATCHES_PROTOCOL_ZERO       000000008H

#Define XP1_CONNECTIONLESS              000000001H
#Define XP1_GUARANTEED_DELIVERY         000000002H
#Define XP1_GUARANTEED_ORDER            000000004H
#Define XP1_MESSAGE_ORIENTED            000000008H
#Define XP1_PSEUDO_STREAM               000000010H
#Define XP1_GRACEFUL_CLOSE              000000020H
#Define XP1_EXPEDITED_DATA              000000040H
#Define XP1_CONNECT_DATA                000000080H
#Define XP1_DISCONNECT_DATA             000000100H
#Define XP1_SUPPORT_BROADCAST           000000200H
#Define XP1_SUPPORT_MULTIPOINT          000000400H
#Define XP1_MULTIPOINT_CONTROL_PLANE    000000800H
#Define XP1_MULTIPOINT_DATA_PLANE       000001000H
#Define XP1_QOS_SUPPORTED               000002000H
#Define XP1_INTERRUPT                   000004000H
#Define XP1_UNI_SEND                    000008000H
#Define XP1_UNI_RECV                    000010000H
#Define XP1_IFS_HANDLES                 000020000H
#Define XP1_PARTIAL_MESSAGE             000040000H

#Define BIGENDIAN                       00000H
#Define LITTLEENDIAN                    00001H

#Define SECURITY_PROTOCOL_NONE          00000H

#Define JL_SENDER_ONLY    				001H
#Define JL_RECEIVER_ONLY  				002H
#Define JL_BOTH           				004H

#Define WSA_FLAG_OVERLAPPED				001H
#Define WSA_FLAG_MULTIPOINT_C_ROOT		002H
#Define WSA_FLAG_MULTIPOINT_C_LEAF		004H
#Define WSA_FLAG_MULTIPOINT_D_ROOT		008H
#Define WSA_FLAG_MULTIPOINT_D_LEAF		010H

#Define IOC_UNIX						000000000H
#Define IOC_WS2							008000000H
#Define IOC_PROTOCOL					010000000H
#Define IOC_VENDOR						018000000H

#Define TH_NETDEV        				000000001H
#Define TH_TAPI          				000000002H

#Define SOCKADDR						sockaddr

#Define SERVICE_MULTIPLE       			000000001H

#Define NS_ALL                      	0

#Define NS_SAP                      	1
#Define NS_NDS                      	2
#Define NS_PEER_BROWSE              	3

#Define NS_TCPIP_LOCAL              	10
#Define NS_TCPIP_HOSTS              	11
#Define NS_DNS                      	12
#Define NS_NETBT                    	13
#Define NS_WINS                     	14

#Define NS_NBP                      	20

#Define NS_MS                       	30
#Define NS_STDA                     	31
#Define NS_NTDS                     	32

#Define NS_X500                     	40
#Define NS_NIS                      	41
#Define NS_NISPLUS                  	42

#Define NS_WRQ                      	50

#Define RES_UNUSED_1                	000000001H
#Define RES_FLUSH_CACHE             	000000002H
#IFNDEF RES_SERVICE
	#Define RES_SERVICE                 000000004H
#ENDIF

#Define SERVICE_TYPE_VALUE_IPXPORTA     "IpxSocket"
#Define SERVICE_TYPE_VALUE_IPXPORTW     L"IpxSocket"
#Define SERVICE_TYPE_VALUE_SAPIDA       "SapId"
#Define SERVICE_TYPE_VALUE_SAPIDW       L"SapId"

#Define SERVICE_TYPE_VALUE_TCPPORTA     "TcpPort"
#Define SERVICE_TYPE_VALUE_TCPPORTW     L"TcpPort"

#Define SERVICE_TYPE_VALUE_UDPPORTA     "UdpPort"
#Define SERVICE_TYPE_VALUE_UDPPORTW     L"UdpPort"

#Define SERVICE_TYPE_VALUE_OBJECTIDA    "ObjectId"
#Define SERVICE_TYPE_VALUE_OBJECTIDW    L"ObjectId"

;WSAECOMPARATOR enumeration
COMP_EQUAL								Equ 0
COMP_NOTLESS							Equ 1

#Define LUP_DEEP                		00001H
#Define LUP_CONTAINERS          		00002H
#Define LUP_NOCONTAINERS        		00004H
#Define LUP_NEAREST             		00008H
#Define LUP_RETURN_NAME         		00010H
#Define LUP_RETURN_TYPE         		00020H
#Define LUP_RETURN_VERSION      		00040H
#Define LUP_RETURN_COMMENT      		00080H
#Define LUP_RETURN_ADDR         		00100H
#Define LUP_RETURN_BLOB         		00200H
#Define LUP_RETURN_ALIASES      		00400H
#Define LUP_RETURN_QUERY_STRING 		00800H
#Define LUP_RETURN_ALL          		00FF0H
#Define LUP_RES_SERVICE         		08000H

#Define LUP_FLUSHCACHE       			01000H
#Define LUP_FLUSHPREVIOUS    			02000H

#Define RESULT_IS_ALIAS      			00001H

;WSAESETSERVICEOP enumeration
RNRSERVICE_REGISTER						Equ 0
RNRSERVICE_DEREGISTER					Equ 1
RNRSERVICE_DELETE						Equ 2

#Define SOCKADDR_IN						sockaddr_in
#Define LINGER							linger
#Define IN_ADDR							in_addr
#Define FD_SET							fd_set
#Define HOSTENT							hostent
#Define SERVENT							servent
#Define PROTOENT						protoent
#Define TIMEVAL							timeval


fd_set Struct
	fd_count DD
	fd_array DD FD_SETSIZE Dup ?
EndS

timeval Struct
	tv_sec DD
	tv_usec DD
EndS

hostent Struct
	h_name DD
	h_aliases DD
	h_addrtype DW
	h_length DW
	h_addr_list DD
EndS

netent Struct
	n_name DD
	n_aliases DD
	n_addrtype DW
	n_net DD
EndS

servent Struct
	s_name DD
	s_aliases DD
	s_port DW
	s_proto DD
EndS

protoent Struct
	p_name DD
	p_aliases DD
	p_proto DW
EndS

in_addr Struct
	S_un Union
		S_un_b Struct
			s_b1 DB
			s_b2 DB
			s_b3 DB
			s_b4 DB
		EndS
		S_un_w Struct
			s_w1 DW
			s_w2 DW
		EndS
		S_addr DD
	EndUnion
EndS

sockaddr_in Struct
	sin_family DW
	sin_port DW
	sin_addr in_addr <>
	sin_zero DB 8 Dup ?
EndS

WSADATA Struct
	wVersion DW
	wHighVersion DW
	szDescription DB (WSADESCRIPTION_LEN + 1) Dup ?
	szSystemStatus DB (WSASYS_STATUS_LEN + 1) Dup ?
	iMaxSockets DW
	iMaxUdpDg DW
	lpVendorInfo DD
EndS

sockaddr Struct
	sa_family DW
	sa_data DB 14 Dup ?
EndS

sockproto Struct
	sp_family DW
	sp_protocol DW
EndS

linger Struct
	l_onoff DW
	l_linger DW
EndS

WSABUF Struct
	len DD
	buf DD
EndS

QOS Struct
	SendingFlowspec FLOWSPEC <>
	ReceivingFlowspec FLOWSPEC <>
	ProviderSpecific WSABUF <>
EndS

WSANETWORKEVENTS Struct
	lNetworkEvents DD
	iErrorCode DD FD_MAX_EVENTS Dup ?
EndS

#IFNDEF GUID_DEFINED
	#Define GUID_DEFINED
	GUID Struct
		Data1 DD
		Data2 DW
		Data3 DW
		Data4 DB 8 Dup ?
	EndS
#ENDIF

WSAPROTOCOLCHAIN Struct
	ChainLen DD
	ChainEntries DD MAX_PROTOCOL_CHAIN Dup ?
EndS

WSAPROTOCOL_INFOA Struct
	dwServiceFlags1 DD
	dwServiceFlags2 DD
	dwServiceFlags3 DD
	dwServiceFlags4 DD
	dwProviderFlags DD
	ProviderId GUID <>
	dwCatalogEntryId DD
	ProtocolChain WSAPROTOCOLCHAIN <>
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
	szProtocol DB (WSAPROTOCOL_LEN + 1) Dup ?
EndS

WSAPROTOCOL_INFOW Struct
	dwServiceFlags1 DD
	dwServiceFlags2 DD
	dwServiceFlags3 DD
	dwServiceFlags4 DD
	dwProviderFlags DD
	ProviderId GUID <>
	dwCatalogEntryId DD
	ProtocolChain WSAPROTOCOLCHAIN <>
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
	szProtocol DW (WSAPROTOCOL_LEN + 1) Dup ?
EndS

#IFNDEF BLOB_DEFINED
	#Define BLOB_DEFINED
	BLOB Struct
		cbSize DD
		pBlobData DD
	EndS
#ENDIF

#IFNDEF CSADDR_DEFINED
	#Define CSADDR_DEFINED
	SOCKET_ADDRESS Struct
		lpSockaddr DD
		iSockaddrLength DD
	EndS

CSADDR_INFO Struct
		LocalAddr SOCKET_ADDRESS <>
		RemoteAddr SOCKET_ADDRESS <>
		iSocketType DD
		iProtocol DD
	EndS
#ENDIF

SOCKET_ADDRESS_LIST Struct
	iAddressCount DD
	ADDRESS SOCKET_ADDRESS <>
EndS

AFPROTOCOLS Struct
	iAddressFamily DD
	iProtocol DD
EndS

WSAVERSION Struct
	dwVersion DD
	ecHow WSAECOMPARATOR <>
EndS

WSAQUERYSETA Struct
	dwSize DD
	lpszServiceInstanceName  DD
	lpServiceClassId DD
	lpVersion DD
	lpszComment DD
	dwNameSpace DD
	lpNSProviderId DD
	lpszContext DD
	dwNumberOfProtocols DD
	lpafpProtocols DD
	lpszQueryString DD
	dwNumberOfCsAddrs DD
	lpcsaBuffer DD
	dwOutputFlags DD
	lpBlob DD
EndS

WSAQUERYSETW Struct
	dwSize DD
	lpszServiceInstanceName  DD
	lpServiceClassId DD
	lpVersion DD
	lpszComment DD
	dwNameSpace DD
	lpNSProviderId DD
	lpszContext DD
	dwNumberOfProtocols DD
	lpafpProtocols DD
	lpszQueryString DD
	dwNumberOfCsAddrs DD
	lpcsaBuffer DD
	dwOutputFlags DD
	lpBlob DD
EndS

WSANSCLASSINFOA Struct
	lpszName DD
	dwNameSpace DD
	dwValueType DD
	dwValueSize DD
	lpValue DD
EndS

WSANSCLASSINFOW Struct
	lpszName DD
	dwNameSpace DD
	dwValueType DD
	dwValueSize DD
	lpValue DD
EndS

WSASERVICECLASSINFOA Struct
	lpServiceClassId DD
	lpszServiceClassName DD
	dwCount DD
	lpClassInfos DD
EndS

WSASERVICECLASSINFOW Struct
	lpServiceClassId DD
	lpszServiceClassName DD
	dwCount DD
	lpClassInfos DD
EndS

WSANAMESPACE_INFOA Struct
	NSProviderId GUID <>
	dwNameSpace DD
	fActive DD
	dwVersion DD
	lpszIdentifier DD
EndS

WSANAMESPACE_INFOW Struct
	NSProviderId GUID <>
	dwNameSpace DD
	fActive DD
	dwVersion DD
	lpszIdentifier DD
EndS

#IF STRINGS UNICODE
	#Define SO_PROTOCOL_INFOSO_PROTOCOL_INFOW
	#Define WSAPROTOCOL_INFO WSAPROTOCOL_INFOW
	#Define SERVICE_TYPE_VALUE_SAPID SERVICE_TYPE_VALUE_SAPIDW
	#Define SERVICE_TYPE_VALUE_TCPPORT SERVICE_TYPE_VALUE_TCPPORTW
	#Define SERVICE_TYPE_VALUE_UDPPORT SERVICE_TYPE_VALUE_UDPPORTW
	#Define SERVICE_TYPE_VALUE_OBJECTID SERVICE_TYPE_VALUE_OBJECTIDW
	#Define WSAQUERYSET WSAQUERYSETW
	#Define WSANSCLASSINFO WSANSCLASSINFOW
	#Define WSASERVICECLASSINFO WSASERVICECLASSINFOW
	#Define WSANAMESPACE_INFO WSANAMESPACE_INFOW
	#Define WSADuplicateSocket WSADuplicateSocketW
	#Define WSAEnumProtocols WSAEnumProtocolsW
	#Define WSASocket WSASocketW
	#Define WSAAddressToString WSAAddressToStringW
	#Define WSAStringToAddress WSAStringToAddressW
	#Define WSALookupServiceBegin WSALookupServiceBeginW
	#Define WSALookupServiceNext WSALookupServiceNextW
	#Define WSAInstallServiceClass WSAInstallServiceClassW
	#Define WSAGetServiceClassInfo WSAGetServiceClassInfoW
	#Define WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
	#Define WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
	#Define WSASetService WSASetServiceW
#ELSE
	#Define SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
	#Define WSAPROTOCOL_INFO WSAPROTOCOL_INFOA
	#Define SERVICE_TYPE_VALUE_SAPID SERVICE_TYPE_VALUE_SAPIDA
	#Define SERVICE_TYPE_VALUE_TCPPORT SERVICE_TYPE_VALUE_TCPPORTA
	#Define SERVICE_TYPE_VALUE_UDPPORT SERVICE_TYPE_VALUE_UDPPORTA
	#Define SERVICE_TYPE_VALUE_OBJECTID SERVICE_TYPE_VALUE_OBJECTIDA
	#Define WSAQUERYSET WSAQUERYSETA
	#Define WSANSCLASSINFO WSANSCLASSINFOA
	#Define WSASERVICECLASSINFO WSASERVICECLASSINFOA
	#Define WSANAMESPACE_INFO WSANAMESPACE_INFOA
	#Define WSADuplicateSocket WSADuplicateSocketA
	#Define WSAEnumProtocols WSAEnumProtocolsA
	#Define WSASocket WSASocketA
	#Define WSAAddressToString WSAAddressToStringA
	#Define WSAStringToAddress WSAStringToAddressA
	#Define WSALookupServiceBegin WSALookupServiceBeginA
	#Define WSALookupServiceNext WSALookupServiceNextA
	#Define WSAInstallServiceClass WSAInstallServiceClassA
	#Define WSAGetServiceClassInfo WSAGetServiceClassInfoA
	#Define WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
	#Define WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
	#Define WSASetService WSASetServiceA
#ENDIF

#ENDIF ;WINSOCK2_INC
