/*
Switches
COM_NO_WINDOWS_H
*/
#ifndef CERTMOD_H
#define CERTMOD_H

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

#IFNDEF WTYPES_H
	#include "wtypes.h"
#ENDIF
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#define CMM_REFRESHONLY 1

wszCMM_PROP_NAME = L"Name"
wszCMM_PROP_DESCRIPTION = L"Description"
wszCMM_PROP_COPYRIGHT = L"Copyright"
wszCMM_PROP_FILEVER = L"File Version"
wszCMM_PROP_PRODUCTVER = L"Product Version"
wszCMM_PROP_DISPLAY_HWND = L"HWND"

#define GUID_IID_ICertManageModule <0xe7d7ad42,0xbd3d,0x11d1,<0x9a,0x4d,0x00,0xc0,0x4f,0xc2,0x97,0xeb>>
ICertManageModule STRUCT
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
	GetProperty PTR
	SetProperty PTR
	Configure PTR
ENDS

#endif /* CERTMOD_H */
