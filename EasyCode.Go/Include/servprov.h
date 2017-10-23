#ifndef SERVPROV_H
#define SERVPROV_H

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
#endif /* COM_NO_WINDOWS_H */

#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define GUID_IID_IServiceProvider <0x6d5140c1,0x7436,0x11ce,<0x80,0x34,0x00,0xaa,0x00,0x60,0x09,0xfa>>
IServiceProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryService PTR
ENDS

#endif /* _SERVPROV_H */
