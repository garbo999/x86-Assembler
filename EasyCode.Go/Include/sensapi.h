#ifndef SENSAPI_H
#define SENSAPI_H

/* SENS Connectivity API definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Sensapi.dll
#ENDIF

#define NETWORK_ALIVE_LAN  0x00000001
#define NETWORK_ALIVE_WAN  0x00000002
#define NETWORK_ALIVE_AOL  0x00000004

QOCINFO STRUCT
	dwSize DD
	dwFlags DD
	dwInSpeed DD
	dwOutSpeed DD
ENDS

#IFDEF UNICODE
	#define IsDestinationReachable  IsDestinationReachableW
#else
	#define IsDestinationReachable  IsDestinationReachableA
#endif /* UNICODE */

#endif /* _SENSAPI_H */
