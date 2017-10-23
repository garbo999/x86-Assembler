#IFNDEF DISPEX_H
#DEFINE DISPEX_H

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
#endif /*COM_NO_WINDOWS_H*/

#IFNDEF SERVPROV_H
	#include "servprov.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF ACTIVSCP_H
	#include "ActivScp.h"
#ENDIF

// {A6EF9860-C720-11d0-9337-00A0C90DCAA9}
#DEFINE GUID_IID_IDispatchEx <0xa6ef9860, 0xc720, 0x11d0, <0x93, 0x37, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9>>

// {A6EF9861-C720-11d0-9337-00A0C90DCAA9}
#DEFINE GUID_IID_IDispError <0xa6ef9861, 0xc720, 0x11d0, <0x93, 0x37, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9>>

// {A6EF9862-C720-11d0-9337-00A0C90DCAA9}
#DEFINE GUID_IID_IVariantChangeType <0xa6ef9862, 0xc720, 0x11d0, <0x93, 0x37, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9>>

// {1F101481-BCCD-11d0-9336-00A0C90DCAA9}
#DEFINE GUID_SID_VariantConversion <0x1f101481, 0xbccd, 0x11d0, <0x93, 0x36, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9>>

// {4717CC40-BCB9-11d0-9336-00A0C90DCAA9}
#DEFINE GUID_SID_GetCaller <0x4717cc40, 0xbcb9, 0x11d0, <0x93, 0x36, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9>>

// {74A5040C-DD0C-48f0-AC85-194C3259180A}
#DEFINE GUID_SID_ProvideRuntimeContext <0x74a5040c, 0xdd0c, 0x48f0, <0xac, 0x85, 0x19, 0x4c, 0x32, 0x59, 0x18, 0xa>>

// {10E2414A-EC59-49d2-BC51-5ADD2C36FEBC}
#DEFINE GUID_IID_IProvideRuntimeContext <0x10e2414a, 0xec59, 0x49d2, <0xbc, 0x51, 0x5a, 0xdd, 0x2c, 0x36, 0xfe, 0xbc>>

// {CA04B7E6-0D21-11d1-8CC5-00C04FC2B085}
#DEFINE GUID_IID_IObjectIdentity <0xca04b7e6, 0xd21, 0x11d1, <0x8c, 0xc5, 0x0, 0xc0, 0x4f, 0xc2, 0xb0, 0x85>>

#define GUID_SID_GetScriptSite GUID_IID_IActiveScriptSite

// Input flags for GetDispID
#define fdexNameCaseSensitive       0x00000001
#define fdexNameEnsure              0x00000002
#define fdexNameImplicit            0x00000004
#define fdexNameCaseInsensitive     0x00000008
#define fdexNameInternal            0x00000010
#define fdexNameNoDynamicProperties 0x00000020

// Output flags for GetMemberProperties
#define fdexPropCanGet              0x00000001
#define fdexPropCannotGet           0x00000002
#define fdexPropCanPut              0x00000004
#define fdexPropCannotPut           0x00000008
#define fdexPropCanPutRef           0x00000010
#define fdexPropCannotPutRef        0x00000020
#define fdexPropNoSideEffects       0x00000040
#define fdexPropDynamicType         0x00000080
#define fdexPropCanCall             0x00000100
#define fdexPropCannotCall          0x00000200
#define fdexPropCanConstruct        0x00000400
#define fdexPropCannotConstruct     0x00000800
#define fdexPropCanSourceEvents     0x00001000
#define fdexPropCannotSourceEvents  0x00002000

#define grfdexPropCanAll (fdexPropCanGet | fdexPropCanPut | fdexPropCanPutRef | fdexPropCanCall | fdexPropCanConstruct | fdexPropCanSourceEvents)
#define grfdexPropCannotAll (fdexPropCannotGet | fdexPropCannotPut | fdexPropCannotPutRef | fdexPropCannotCall | fdexPropCannotConstruct | fdexPropCannotSourceEvents)
#define grfdexPropExtraAll (fdexPropNoSideEffects | fdexPropDynamicType)
#define grfdexPropAll (grfdexPropCanAll | grfdexPropCannotAll | grfdexPropExtraAll)

// Input flags for GetNextDispID
#define fdexEnumDefault             0x00000001
#define fdexEnumAll                 0x00000002

// Additional flags for Invoke - when object member is
// used as a constructor.
#define DISPATCH_CONSTRUCT 0x4000

// Standard DISPIDs
#define DISPID_THIS (-613)
#define DISPID_STARTENUM DISPID_UNKNOWN


;#DEFINE GUID_IID_IDispatchEx <0xA6EF9860,0xC720,0x11d0,<0x93,0x37,0x00,0xA0,0xC9,0x0D,0xCA,0xA9>>

IDispatchEx STRUCT
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
	GetDispID PTR
	InvokeEx PTR
	DeleteMemberByName PTR
	DeleteMemberByDispID PTR
	GetMemberProperties PTR
	GetMemberName PTR
	GetNextDispID PTR
	GetNameSpaceParent PTR
ENDS


;#DEFINE GUID_IID_IDispError <0xA6EF9861,0xC720,0x11d0,<0x93,0x37,0x00,0xA0,0xC9,0x0D,0xCA,0xA9>>

IDispError STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryErrorInfo PTR
	GetNext PTR
	GetHresult PTR
	GetSource PTR
	GetHelpInfo PTR
	GetDescription PTR
ENDS

;#DEFINE GUID_IID_IVariantChangeType <0xA6EF9862,0xC720,0x11d0,<0x93,0x37,0x00,0xA0,0xC9,0x0D,0xCA,0xA9>>

IVariantChangeType STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ChangeType PTR
ENDS


;#DEFINE GUID_IID_IObjectIdentity <0xCA04B7E6,0x0D21,0x11d1,<0x8C,0xC5,0x00,0xC0,0x4F,0xC2,0xB0,0x85>>

IObjectIdentity STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsEqualObject PTR
ENDS

;#DEFINE GUID_IID_IProvideRuntimeContext <0x10E2414A,0xEC59,0x49d2,<0xBC,0x51,0x5A,0xDD,0x2C,0x36,0xFE,0xBC>>

IProvideRuntimeContext STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCurrentSourceContext PTR
ENDS

#endif



