#ifndef MSWSOCK_H
#define MSWSOCK_H

#define MSWSOCK_H_REQVER 100

/* Microsoft extensions to Windows Sockets API */

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

#define TCP_BSDURGENT  0x7000

#define TF_DISCONNECT  0x01
#define TF_REUSE_SOCKET  0x02
#define TF_WRITE_BEHIND  0x04
#define TF_USE_DEFAULT_WORKER  0x00
#define TF_USE_SYSTEM_THREAD  0x10
#define TF_USE_KERNEL_APC  0x20

#define GUID_WSAID_TRANSMITFILE  <0xb5367df0,0xcbac,0x11cf,<0x95,0xca,0x00,0x80,0x5f,0x48,0xa1,0x92>>
#define GUID_WSAID_ACCEPTEX  <0xb5367df1,0xcbac,0x11cf,<0x95,0xca,0x00,0x80,0x5f,0x48,0xa1,0x92>>
#define GUID_WSAID_GETACCEPTEXSOCKADDRS  <0xb5367df2,0xcbac,0x11cf,<0x95,0xca,0x00,0x80,0x5f,0x48,0xa1,0x92>>

TRANSMIT_FILE_BUFFERS STRUCT
	Head PTR
	HeadLength DD
	Tail PTR
	TailLength DD
ENDS

#endif /* _MSWSOCK_H */

