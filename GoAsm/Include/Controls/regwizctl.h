// Generated .IDL file (by the OLE/COM Object Viewer)
// 
// typelib filename: regwizc.dll

#IFNDEF REGWIZCTL_H
#DEFINE REGWIZCTL_H

#IFDEF LINKFILES
	#dynamiclinkfile regwizc.dll
#ENDIF

#define REGWIZCTL_PROGID "RegWizCtrl.RegWizCtrl"

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define GUID_TLBID_RegwizCtrl <0x50E5E3C0,0xC07E,0x11D0,<0xB9,0xFD,0x00,0xA0,0x24,0x9F,0x6B,0x00>>

#define GUID_IID_IRegwizCtrl <0x50E5E3CF,0xC07E,0x11D0,<0xB9,0xFD,0x00,0xA0,0x24,0x9F,0x6B,0x00>>
#define GUID_CLSID_RegwizCtrl <0x50E5E3D1,0xC07E,0x11D0,<0xB9,0xFD,0x00,0xA0,0x24,0x9F,0x6B,0x00>>

IRegWizCtrl STRUCT
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
	get_IsRegistered PTR
	put_IsRegistered PTR
	InvokeRegWizard PTR
	get_Version PTR
ENDS

#ENDIF