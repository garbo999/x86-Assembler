/*
Switches
COM_NO_WINDOWS_H
*/
#IFNDEF CERTEXIT_H
#define CERTEXIT_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif /*COM_NO_WINDOWS_H */

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define EXITEVENT_INVALID  (0)
#define EXITEVENT_CERTISSUED  (0x1)
#define EXITEVENT_CERTPENDING  (0x2)
#define EXITEVENT_CERTDENIED  (0x4)
#define EXITEVENT_CERTREVOKED  (0x8)
#define EXITEVENT_CERTRETRIEVEPENDING  (0x10)
#define EXITEVENT_CRLISSUED  (0x20)
#define EXITEVENT_SHUTDOWN  (0x40)


#define GUID_IID_ICertExit <0xe19ae1a0,0x7364,0x11d0,<0x88,0x16,0x00,0xa0,0xc9,0x03,0xb8,0x3c>>
ICertExit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Initialize PTR
	Notify PTR
	GetDescription PTR
ENDS

#ENDIF /* CERTEXIT_H */
