#IFNDEF HHCTRL_H
#DEFINE HHCTRL_H

#define GUID_TLBID_HHCtrl <0xADB880A2,0xD8FF,0x11CF,<0x93,0x77,0x00,0xAA,0x00,0x3B,0x7A,0x11>>

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define GUID_IID__HHCtrlEvents <0xADB880A3,0xD8FF,0x11CF,<0x93,0x77,0x00,0xAA,0x00,0x3B,0x7A,0x11>>

_HHCtrlEvents STRUCT
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
	Click PTR
ENDS

DISP_HHCTRL_CLICK = 0

#DEFINE DISPID_HHEVENT_CLICK 0

#define GUID_CLSID_HHCtrl <0x52A2AAAE,0x085D,0x4187,<0x97,0xEA,0x8C,0x30,0xDB,0x99,0x04,0x36>>

#define GUID_IID_IHHCtrl <0xADB880A1,0xD8FF,0x11CF,<0x93,0x77,0x00,0xAA,0x00,0x3B,0x7A,0x11>>

IHHCtrl STRUCT
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
	put_Image PTR
	get_Image PTR
	Click PTR
	HHClick PTR
	Print PTR
	syncURL PTR
	TCard PTR
	TextPopup PTR
ENDS

// Deprecated control classes
#define GUID_CLSID_OldHHCtrl2 <0x41B23C28,0x488E,0x4E5C,<0xAC,0xE2,0xBB,0x0B,0xBA,0xBE,0x99,0xE8>>
#define GUID_CLSID_OldHHCtrl1 <0xADB880A6,0xD8FF,0x11CF,0x93,0x77,0x00,0xAA,0x00,0x3B,0x7A,0x11>>

#ENDIF
