;=============================================================;
;          winsock.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINSOCK_INC
#Define WINSOCK_INC

#IFNDEF WINDOWS_INC
	#Include <windows.inc>
#ENDIF

#IFNDEF FD_SETSIZE
	#Define FD_SETSIZE					64
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

#Define INADDR_ANY              		000000000H
#Define INADDR_LOOPBACK         		07F000001H
#Define INADDR_BROADCAST        		0FFFFFFFFH
#Define INADDR_NONE             		0FFFFFFFFH

#Define WSADESCRIPTION_LEN      		256
#Define WSASYS_STATUS_LEN       		128

#Define IP_OPTIONS          			1
#Define IP_MULTICAST_IF     			2
#Define IP_MULTICAST_TTL    			3
#Define IP_MULTICAST_LOOP   			4
#Define IP_ADD_MEMBERSHIP   			5
#Define IP_DROP_MEMBERSHIP  			6
#Define IP_TTL              			7
#Define IP_TOS              			8
#Define IP_DONTFRAGMENT     			9

#Define IP_DEFAULT_MULTICAST_TTL   		1
#Define IP_DEFAULT_MULTICAST_LOOP  		1
#Define IP_MAX_MEMBERSHIPS         		20

#Define INVALID_SOCKET  				(~0)
#Define SOCKET_ERROR            		(-1)

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

#Define SO_CONNDATA     				07000H
#Define SO_CONNOPT      				07001H
#Define SO_DISCDATA     				07002H
#Define SO_DISCOPT      				07003H
#Define SO_CONNDATALEN  				07004H
#Define SO_CONNOPTLEN   				07005H
#Define SO_DISCDATALEN  				07006H
#Define SO_DISCOPTLEN   				07007H

#Define SO_OPENTYPE     				07008H

#Define SO_SYNCHRONOUS_ALERT    		010H
#Define SO_SYNCHRONOUS_NONALERT 		020H

#Define SO_MAXDG        				07009H
#Define SO_MAXPATHDG    				0700AH
#Define SO_UPDATE_ACCEPT_CONTEXT 		0700BH
#Define SO_CONNECT_TIME 				0700CH

#Define TCP_NODELAY     				00001H
#Define TCP_BSDURGENT   				07000H

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

#Define AF_MAX          				22

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

#Define PF_MAX          				AF_MAX

#Define SOL_SOCKET      				0FFFFH

#Define SOMAXCONN       				5

#Define MSG_OOB         				01H
#Define MSG_PEEK        				02H
#Define MSG_DONTROUTE   				04H

#Define MSG_MAXIOVLEN   				16

#Define MSG_PARTIAL     				08000H

#Define MAXGETHOSTSTRUCT        		1024

#Define FD_READ         				001H
#Define FD_WRITE        				002H
#Define FD_OOB          				004H
#Define FD_ACCEPT       				008H
#Define FD_CONNECT      				010H
#Define FD_CLOSE        				020H

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

#Define WSAEDISCON              		(WSABASEERR+101)

#Define WSASYSNOTREADY          		(WSABASEERR+91)
#Define WSAVERNOTSUPPORTED      		(WSABASEERR+92)
#Define WSANOTINITIALISED       		(WSABASEERR+93)

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

#Define TF_DISCONNECT       			001H
#Define TF_REUSE_SOCKET     			002H
#Define TF_WRITE_BEHIND     			004H


fd_set Struct
	fd_count DD
	fd_array DD FD_SETSIZE Dup ?
EndS

timeval	Struct
	tv_sec	DD
	tv_usec	DD
EndS

hostent	Struct
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

ip_mreq Struct
	imr_multiaddr in_addr <>
	imr_interface in_addr <>
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

TRANSMIT_FILE_BUFFERS Struct
	Head DD
	HeadLength DD
	Tail DD
	TailLength DD
EndS

#ENDIF ;WINSOCK_INC
