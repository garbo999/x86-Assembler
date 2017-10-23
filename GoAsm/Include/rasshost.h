#ifndef RASSHOST_H
#define RASSHOST_H

/* Remote Access Server and third party security DLL definitions */
#IFNDEF MPRAPI_H
	#include mprapi.h
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile Rasman.dll
#ENDIF

#define SECURITYMSG_SUCCESS  1
#define SECURITYMSG_FAILURE  2
#define SECURITYMSG_ERROR  3

SECURITY_MESSAGE STRUCT
	dwMsgId DD
	hPort HANDLE
	dwError DD
	UserName DB UNLEN+1 DUP
	Domain DB DNLEN+1 DUP
ENDS

RAS_SECURITY_INFO STRUCT
	LastError DD
	BytesReceived DD
	DeviceName DB MAX_DEVICE_NAME+1 DUP
ENDS

#endif /* _RASSHOST_H */
