#ifndef CERTPOL_H
#define CERTPOL_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF
#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#ENDIF /*COM_NO_WINDOWS_H */

#IFNDEF WTYPES_H
	#include "wtypes.h"
#ENDIF
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#define GUID_IID_ICertPolicy <0x38bb5a00,0x7636,0x11d0,<0xb4,0x13,0x00,0xa0,0xc9,0x1b,0xbf,0x8c>>
ICertPolicy STRUCT
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
	VerifyRequest PTR
	GetDescription PTR
	ShutDown PTR
ENDS

#endif /* _CERTPOL_H */
