#ifndef WSIPX_H
#define WSIPX_H

/* Windows Sockets definitions for IPX/SPX */

#define NSPROTO_IPX  1000
#define NSPROTO_SPX  1256
#define NSPROTO_SPXII  1257

sockaddr_ipx STRUCT
	sa_family DW
	sa_netnum DB 4 DUP (?)
	sa_nodenum DB 6 DUP (?)
	sa_socket DW
ENDS

#endif /* _WSIPX_H */

