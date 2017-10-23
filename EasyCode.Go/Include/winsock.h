#ifndef WINSOCK_H
#define WINSOCK_H

/* Windows Sockets specification 1.1 */

#IFDEF LINKFILES
	#dynamiclinkfile Mswsock.dll
#ENDIF

#ifndef FD_SETSIZE
	#define FD_SETSIZE  64
#endif

fd_set STRUCT
	fd_count DD
	fd_array SOCKET FD_SETSIZE DUP
ENDS

timeval STRUCT
	tv_sec DD
	tv_usec DD
ENDS

#define IOCPARM_MASK  0x7f
#define IOC_VOID  0x20000000
#define IOC_OUT  0x40000000
#define IOC_IN  0x80000000
#define IOC_INOUT  0xC0000000

#define FIONREAD (IOC_OUT | (4&IOCPARM_MASK) <<16 | 66h << 8 | 127)
#define FIONBIO (IOC_IN | (4&IOCPARM_MASK) <<16 | 66h << 8 | 126)
#define FIOASYNC (IOC_IN | (4&IOCPARM_MASK) <<16 | 66h << 8 | 125)

#define SIOCSHIWAT (IOC_IN | (4&IOCPARM_MASK) <<16 | 73h << 8)
#define SIOCGHIWAT (IOC_OUT | (4&IOCPARM_MASK) <<16 | 73h << 8 | 1)
#define SIOCSHIWAT (IOC_IN | (4&IOCPARM_MASK) <<16 | 73h << 8 | 2)
#define SIOCGLOWAT (IOC_OUT | (4&IOCPARM_MASK) <<16 | 73h << 8 | 3)
#define SIOCATMARK (IOC_OUT | (4&IOCPARM_MASK) <<16 | 73h << 8 | 7)

#ifndef HOSTENT
	HOSTENT STRUCT
		h_name PTR
		h_aliases PTR
		h_addrtype DW
		h_length DW
		h_addr_list PTR
	ENDS
	
	NETENT STRUCT
		n_name PTR
		n_aliases PTR
		n_addrtype DW
		n_net DD
	ENDS
	
	SERVENT STRUCT
		s_name PTR
		s_aliases PTR
		#ifdef _WIN64
			s_proto PTR
			s_port DW
		#else
			s_port DW
			s_proto PTR
		#endif
	ENDS

	PROTOENT STRUCT
		p_name PTR
		p_aliases PTR
		p_proto DW
	ENDS

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

;#define s_addr  S_un.S_addr
;#define s_host  S_un.S_un_b.s_b2
;#define s_net  S_un.S_un_b.s_b1
;#define s_imp  S_un.S_un_w.s_w2
;#define s_impno  S_un.S_un_b.s_b4
;#define s_lh  S_un.S_un_b.s_b3

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

#define INADDR_ANY  0x00000000
#define INADDR_LOOPBACK  0x7f000001
#define INADDR_BROADCAST  0xffffffff
#define INADDR_NONE  0xffffffff

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
	lpVendorInfo DD
#endif
ENDS

#endif

#define IP_OPTIONS  1
#define IP_MULTICAST_IF  2
#define IP_MULTICAST_TTL  3
#define IP_MULTICAST_LOOP  4
#define IP_ADD_MEMBERSHIP  5
#define IP_DROP_MEMBERSHIP  6
#define IP_TTL  7
#define IP_TOS  8
#define IP_DONTFRAGMENT  9

#define IP_DEFAULT_MULTICAST_TTL  1
#define IP_DEFAULT_MULTICAST_LOOP  1
#define IP_MAX_MEMBERSHIPS  20

ip_mreq STRUCT
	imr_multiaddr in_addr
	imr_interface in_addr
ENDS

#define INVALID_SOCKET  -1
#define SOCKET_ERROR  -1

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

#define SO_SNDBUF  0x1001
#define SO_RCVBUF  0x1002
#define SO_SNDLOWAT  0x1003
#define SO_RCVLOWAT  0x1004
#define SO_SNDTIMEO  0x1005
#define SO_RCVTIMEO  0x1006
#define SO_ERROR  0x1007
#define SO_TYPE  0x1008

#define SO_CONNDATA  0x7000
#define SO_CONNOPT  0x7001
#define SO_DISCDATA  0x7002
#define SO_DISCOPT  0x7003
#define SO_CONNDATALEN  0x7004
#define SO_CONNOPTLEN  0x7005
#define SO_DISCDATALEN  0x7006
#define SO_DISCOPTLEN  0x7007

#define SO_OPENTYPE  0x7008

#define SO_SYNCHRONOUS_ALERT  0x10
#define SO_SYNCHRONOUS_NONALERT  0x20

#define SO_MAXDG  0x7009
#define SO_MAXPATHDG  0x700A
#define SO_UPDATE_ACCEPT_CONTEXT  0x700B
#define SO_CONNECT_TIME  0x700C

#define TCP_NODELAY  0x0001
#define TCP_BSDURGENT  0x7000

#define AF_UNSPEC  0
#define AF_UNIX  1
#define AF_INET  2
#define AF_IMPLINK  3
#define AF_PUP  4
#define AF_CHAOS  5
#define AF_IPX  6
#define AF_NS  6
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
#define AF_MAX  22

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
#define PF_MAX  AF_MAX

#ifndef linger
	linger STRUCT
		l_onoff DW
		l_linger DW
	ENDS
#endif

#define LINGER linger

#define SOL_SOCKET  0xffff

#define SOMAXCONN  5

#define MSG_OOB  0x1
#define MSG_PEEK  0x2
#define MSG_DONTROUTE  0x4
#define MSG_MAXIOVLEN  16
#define MSG_PARTIAL  0x8000

#define MAXGETHOSTSTRUCT  1024

#define FD_READ  0x01
#define FD_WRITE  0x02
#define FD_OOB  0x04
#define FD_ACCEPT  0x08
#define FD_CONNECT  0x10
#define FD_CLOSE  0x20

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
#define WSAHOST_NOT_FOUND  (WSABASEERR+1001)
#define WSATRY_AGAIN  (WSABASEERR+1002)
#define WSANO_RECOVERY  (WSABASEERR+1003)
#define WSANO_DATA  (WSABASEERR+1004)
#endif /* WSABASEERR */

#define HOST_NOT_FOUND  WSAHOST_NOT_FOUND
#define TRY_AGAIN  WSATRY_AGAIN
#define NO_RECOVERY  WSANO_RECOVERY
#define NO_DATA  WSANO_DATA
#define WSANO_ADDRESS  WSANO_DATA
#define NO_ADDRESS  WSANO_ADDRESS

TRANSMIT_FILE_BUFFERS STRUCT
	Head PTR
	HeadLength DD
	Tail PTR
	TailLength DD
ENDS

#define TF_DISCONNECT  0x01
#define TF_REUSE_SOCKET  0x02
#define TF_WRITE_BEHIND  0x04

#endif /* _WINSOCK_H */
