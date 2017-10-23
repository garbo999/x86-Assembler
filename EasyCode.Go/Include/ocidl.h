#ifndef OCIDL_H
#define OCIDL_H

#IFNDEF RPC_H
	#include rpc.h ; Windows RPC definitions
#ENDIF

#IFNDEF RPCNDR_H
	#include rpcndr.h
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include windows.h
	#ENDIF
	#IFNDEF OLE2_H
		#include ole2.h
	#ENDIF
#endif

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF SIZE
	SIZE STRUCT
		cx DD
		cy DD
	ENDS
#ENDIF

#IFNDEF OLEIDL_H
	#include "oleidl.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF SERVPROV_H
	#include "servprov.h"
#ENDIF

#IFNDEF URLMON_H
	#include "urlmon.h"
#ENDIF

UAS_NORMAL = 0
UAS_BLOCKED = 0x1
UAS_NOPARENTENABLE = 0x2
UAS_MASK = 0x3

READYSTATE_UNINITIALIZED = 0
READYSTATE_LOADING = 1
READYSTATE_LOADED = 2
READYSTATE_INTERACTIVE = 3
READYSTATE_COMPLETE = 4

CONNECTDATA STRUCT
	pUnk PTR
	dwCookie DD
ENDS

#define GUID_IID_IEnumConnections <0xB196B287,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IEnumConnections STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#define GUID_IID_IConnectionPoint <0xB196B286,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IConnectionPoint STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetConnectionInterface PTR
	GetConnectionPointContainer PTR
	Advise PTR
	Unadvise PTR
	EnumConnections PTR
ENDS

#define GUID_IID_IEnumConnectionPoints <0x0B196B285,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IEnumConnectionPoints STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#define GUID_IID_IConnectionPointContainer <0xB196B284,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IConnectionPointContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	EnumConnectionPoints PTR
	FindConnectionPoint PTR
ENDS

#define GUID_IID_IClassFactory2 <0xB196B28F,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IClassFactory2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateInstance PTR
	LockServer PTR
	GetLicInfo PTR
	RequestLicKey PTR
	CreateInstanceLic PTR
ENDS

#define GUID_IID_IProvideClassInfo <0xB196B283,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IProvideClassInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassInfo PTR
ENDS

#define GUID_IID_IProvideClassInfo2 <0xA6BC3AC0,0xDBAA,0x11CE,<0x9D,0xE3,0x00,0xAA,0x00,0x4B,0xB8,0x51>>
IProvideClassInfo2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassInfo PTR
	GetGUID PTR
ENDS

#define MULTICLASSINFO_GETTYPEINFO  0x00000001
#define MULTICLASSINFO_GETNUMRESERVEDDISPIDS  0x00000002
#define MULTICLASSINFO_GETIIDPRIMARY  0x00000004
#define MULTICLASSINFO_GETIIDSOURCE  0x00000008
#define TIFLAGS_EXTENDDISPATCHONLY  0x00000001

#define GUID_IID_IProvideMultipleClassInfo <0xA7ABA9C1,0x8983,0x11cf,<0x8F,0x20,0x00,0x80,0x5F,0x2C,0xD0,0x64>>
IProvideMultipleClassInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassInfo PTR
	GetGUID PTR
	GetMultiTypeInfoCount PTR
	GetInfoOfIndex PTR
ENDS

CONTROLINFO STRUCT
	cb DD
	hAccel HANDLE
	cAccel DW
	dwFlags DD
ENDS

CTRLINFO_EATS_RETURN = 1
CTRLINFO_EATS_ESCAPE = 2

#define GUID_IID_IOleControl <0xB196B288,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IOleControl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetControlInfo PTR
	OnMnemonic PTR
	OnAmbientPropertyChange PTR
	FreezeEvents PTR
ENDS

POINTF STRUCT
	x DD
	y DD
ENDS

XFORMCOORDS_POSITION = 0x1
XFORMCOORDS_SIZE = 0x2
XFORMCOORDS_HIMETRICTOCONTAINER = 0x4
XFORMCOORDS_CONTAINERTOHIMETRIC = 0x8
XFORMCOORDS_EVENTCOMPAT = 0x10

#define GUID_IID_IOleControlSite <0xB196B289,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IOleControlSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnControlInfoChanged PTR
	LockInPlaceActive PTR
	GetExtendedControl PTR
	TransformCoords PTR
	TranslateAccelerator PTR
	OnFocus PTR
	ShowPropertyFrame PTR
ENDS

PROPPAGEINFO STRUCT
	cb DD
	pszTitle PTR
	size SIZE
	pszDocString PTR
	pszHelpFile PTR
	dwHelpContext DD
ENDS

#define GUID_IID_IPropertyPage <0xB196B28D,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IPropertyPage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetPageSite PTR
	Activate PTR
	Deactivate PTR
	GetPageInfo PTR
	SetObjects PTR
	Show PTR
	Move PTR
	IsPageDirty PTR
	Apply PTR
	Help PTR
	TranslateAccelerator PTR
ENDS

#define GUID_IID_IPropertyPage2 <0x01E44665,0x24AC,0x101B,<0x84,0xED,0x08,0x00,0x2B,0x2E,0xC7,0x13>>
IPropertyPage2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetPageSite PTR
	Activate PTR
	Deactivate PTR
	GetPageInfo PTR
	SetObjects PTR
	Show PTR
	Move PTR
	IsPageDirty PTR
	Apply PTR
	Help PTR
	TranslateAccelerator PTR
	EditProperty PTR
ENDS

PROPPAGESTATUS_DIRTY = 0x1
PROPPAGESTATUS_VALIDATE = 0x2
PROPPAGESTATUS_CLEAN = 0x4

#define GUID_IID_IPropertyPageSite <0xB196B28C,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IPropertyPageSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnStatusChange PTR
	GetLocaleID PTR
	GetPageContainer PTR
	TranslateAccelerator PTR
ENDS

#define GUID_IID_IPropertyNotifySink <0x9BFBBC02,0xEFF1,0x101A,<0x84,0xED,0x00,0xAA,0x00,0x34,0x1D,0x07>>
IPropertyNotifySink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnChanged PTR
	OnRequestEdit PTR
ENDS

CAUUID STRUCT
	cElems DD
	pElems PTR
ENDS

#define GUID_IID_ISpecifyPropertyPages <0xB196B28B,0xBAB4,0x101A,<0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07>>
ISpecifyPropertyPages STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPages PTR
ENDS

#define GUID_IID_IPersistMemory <0xBD1AE5E0,0xA6AE,0x11CE,<0xBD,0x37,0x50,0x42,0x00,0xC1,0x00,0x00>>
IPersistMemory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	IsDirty PTR
	Load PTR
	Save PTR
	GetSizeMax PTR
	InitNew PTR
ENDS

#define GUID_IID_IPersistStreamInit <0x7FD52380,0x4E07,0x101B,<0xAE,0x2D,0x08,0x00,0x2B,0x2E,0xC7,0x13>>
IPersistStreamInit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	IsDirty PTR
	Load PTR
	Save PTR
	GetSizeMax PTR
	InitNew PTR
ENDS

#define GUID_IID_IPersistPropertyBag <0x37D84F60,0x42CB,0x11CE,<0x81,0x35,0x00,0xAA,0x00,0x4B,0xB8,0x51>>
IPersistPropertyBag STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	InitNew PTR
	Load PTR
	Save PTR
ENDS

#define GUID_IID_ISimpleFrameSite <0x742B0E01,0x14E6,0x101B,<0x91,0x4E,0x00,0xAA,0x00,0x30,0x0C,0xAB>>
ISimpleFrameSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	PreMessageFilter PTR
	PostMessageFilter PTR
ENDS

#define GUID_IID_IFont <0xBEF6E002,0xA874,0x101A,<0x8B,0xBA,0x00,0xAA,0x00,0x30,0x0C,0xAB>>
IFont STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	put_Name PTR
	get_Size PTR
	put_Size PTR
	get_Bold PTR
	put_Bold PTR
	get_Italic PTR
	put_Italic PTR
	get_Underline PTR
	put_Underline PTR
	get_Strikethrough PTR
	put_Strikethrough PTR
	get_Weight PTR
	put_Weight PTR
	get_Charset PTR
	put_Charset PTR
	get_hFont PTR
	Clone PTR
	IsEqual PTR
	SetRatio PTR
	QueryTextMetrics PTR
	AddRefHfont PTR
	ReleaseHfont PTR
	SetHdc PTR
ENDS

PICTURE_SCALABLE = 0x1
PICTURE_TRANSPARENT = 0x2

#define GUID_IID_IPicture <0x7BF80980,0xBF32,0x101A,<0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB>>
IPicture STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Handle PTR
	get_hPal PTR
	get_Type PTR
	get_Width PTR
	get_Height PTR
	Render PTR
	set_hPal PTR
	get_CurDC PTR
	SelectPicture PTR
	get_KeepOriginalFormat PTR
	put_KeepOriginalFormat PTR
	PictureChanged PTR
	SaveAsFile PTR
	get_Attributes PTR
ENDS

#define GUID_IID_IFontEventsDisp <0x4EF6100A,0xAF88,0x11D0,<0x98,0x46,0x00,0xC0,0x4F,0xC2,0x99,0x93>>
IFontEventsDisp STRUCT
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
ENDS

#define GUID_IID_IFontDisp <0xBEF6E003,0xA874,0x101A,<0x8B,0xBA,0x00,0xAA,0x00,0x30,0x0C,0xAB>>
IFontDisp STRUCT
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
ENDS

#define GUID_IID_IPictureDisp <0x7BF80981,0xBF32,0x101A,<0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB>>
IPictureDisp STRUCT
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
ENDS

#define GUID_IID_IOleInPlaceObjectWindowless <0x1C2056CC,0x5EF4,0x101B,<0x8B,0xC8,0x00,0xAA,0x00,0x3E,0x3B,0x29>>
IOleInPlaceObjectWindowless STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	InPlaceDeactivate PTR
	UIDeactivate PTR
	SetObjectRects PTR
	ReactivateAndUndo PTR
	OnWindowMessage PTR
	GetDropTarget PTR
ENDS

ACTIVATE_WINDOWLESS = 1

#define GUID_IID_IOleInPlaceSiteEx <0x9C2CAD80,0x3424,0x11CF,<0xB6,0x70,0x00,0xAA,0x00,0x4C,0xD6,0xD8>>
IOleInPlaceSiteEx STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	CanInPlaceActivate PTR
	OnInPlaceActivate PTR
	OnUIActivate PTR
	GetWindowContext PTR
	Scroll PTR
	OnUIDeactivate PTR
	OnInPlaceDeactivate PTR
	DiscardUndoState PTR
	DeactivateAndUndo PTR
	OnPosRectChange PTR
	OnInPlaceActivateEx PTR
	OnInPlaceDeactivateEx PTR
	RequestUIActivate PTR
ENDS

OLEDC_NODRAW = 0x1
OLEDC_PAINTBKGND = 0x2
OLEDC_OFFSCREEN = 0x4

#define GUID_IID_IOleInPlaceSiteWindowless <0x922EADA0,0x3424,0x11CF,<0xB6,0x70,0x00,0xAA,0x00,0x4C,0xD6,0xD8>>
IOleInPlaceSiteWindowless STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	CanInPlaceActivate PTR
	OnInPlaceActivate PTR
	OnUIActivate PTR
	GetWindowContext PTR
	Scroll PTR
	OnUIDeactivate PTR
	OnInPlaceDeactivate PTR
	DiscardUndoState PTR
	DeactivateAndUndo PTR
	OnPosRectChange PTR
	OnInPlaceActivateEx PTR
	OnInPlaceDeactivateEx PTR
	RequestUIActivate PTR
	CanWindowlessActivate PTR
	GetCapture PTR
	SetCapture PTR
	GetFocus PTR
	SetFocus PTR
	GetDC PTR
	ReleaseDC PTR
	InvalidateRect PTR
	InvalidateRgn PTR
	ScrollRect PTR
	AdjustRect PTR
	OnDefWindowMessage PTR
ENDS

VIEWSTATUS_OPAQUE = 1
VIEWSTATUS_SOLIDBKGND = 2
VIEWSTATUS_DVASPECTOPAQUE = 4
VIEWSTATUS_DVASPECTTRANSPARENT = 8
VIEWSTATUS_SURFACE = 16
VIEWSTATUS_3DSURFACE = 32

HITRESULT_OUTSIDE = 0
HITRESULT_TRANSPARENT = 1
HITRESULT_CLOSE = 2
HITRESULT_HIT = 3

DVASPECT_OPAQUE = 16
DVASPECT_TRANSPARENT = 32

DVEXTENTINFO STRUCT
	cb DD
	dwExtentMode DD
	sizelProposed SIZE
ENDS

DVEXTENT_CONTENT = 0
DVEXTENT_INTEGRAL = 1

DVASPECTINFOFLAG_CANOPTIMIZE = 1

DVASPECTINFO STRUCT
	cb DD
	dwFlags DD
ENDS

#define GUID_IID_IViewObjectEx <0x3AF24292,0x0C96,0x11CE,<0xA0,0xCF,0x00,0xAA,0x00,0x60,0x0A,0xB8>>
IViewObjectEx STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Draw PTR
	GetColorSet PTR
	Freeze PTR
	Unfreeze PTR
	SetAdvise PTR
	GetAdvise PTR
	GetExtent PTR
	GetRect PTR
	GetViewStatus PTR
	QueryHitPoint PTR
	QueryHitRect PTR
	GetNaturalExtent PTR
ENDS

#define GUID_IID_IOleUndoUnit <0x894AD3B0,0xEF97,0x11CE,<0x9B,0xC9,0x00,0xAA,0x00,0x60,0x8E,0x01>>
IOleUndoUnit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Do PTR
	GetDescription PTR
	GetUnitType PTR
	OnNextAdd PTR
ENDS

#define GUID_IID_IOleParentUndoUnit <0xA1FAF330,0xEF97,0x11CE,<0x9B,0xC9,0x00,0xAA,0x00,0x60,0x8E,0x01>>
IOleParentUndoUnit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Do PTR
	GetDescription PTR
	GetUnitType PTR
	OnNextAdd PTR
	Open PTR
	Close PTR
	Add PTR
	FindUnit PTR
	GetParentState PTR
ENDS

#define GUID_IID_IEnumOleUndoUnits <0xB3E7C340,0xEF97,0x11CE,<0x9B,0xC9,0x00,0xAA,0x00,0x60,0x8E,0x01>>
IEnumOleUndoUnits STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#define GUID_IID_IOleUndoManager <0xD001F200,0xEF97,0x11CE,<0x9B,0xC9,0x00,0xAA,0x00,0x60,0x8E,0x01>>
IOleUndoManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Open PTR
	Close PTR
	Add PTR
	GetParentState PTR
	DiscardFrom PTR
	UndoTo PTR
	RedoTo PTR
	EnumUndoable PTR
	EnumRedoable PTR
	GetLastUndoDescription PTR
	GetLastRedoDescription PTR
	Enable PTR
ENDS

#define GUID_IID_IPointerInactive <0x55980BA0,0x35AA,0x11CF,<0xB6,0x71,0x00,0xAA,0x00,0x4C,0xD6,0xD8>>
IPointerInactive STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetActivationPolicy PTR
	OnInactiveMouseMove PTR
	OnInactiveSetCursor PTR
ENDS

#define GUID_IID_IObjectWithSite <0xFC4801A3,0x2BA9,0x11CF,<0xA2,0x29,0x00,0xAA,0x00,0x3D,0x73,0x52>>
IObjectWithSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetSite PTR
	GetSite PTR
ENDS

CALPOLESTR STRUCT
	cElems DD
	pElems PTR
ENDS

CADWORD STRUCT
	cElems DD
	pElems PTR
ENDS

#define GUID_IID_IPerPropertyBrowsing <0x376BD3AA,0x3845,0x101B,<0x84,0xED,0x08,0x00,0x2B,0x2E,0xC7,0x13>>
IPerPropertyBrowsing STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDisplayString PTR
	MapPropertyToPage PTR
	GetPredefinedStrings PTR
	GetPredefinedValue PTR
ENDS

PROPBAG2_TYPE_UNDEFINED = 0
PROPBAG2_TYPE_DATA = 1
PROPBAG2_TYPE_URL = 2
PROPBAG2_TYPE_OBJECT = 3
PROPBAG2_TYPE_STREAM = 4
PROPBAG2_TYPE_STORAGE = 5
PROPBAG2_TYPE_MONIKER = 6

PROPBAG2 STRUCT
	dwType DD
	vt  DD
	cfType CLIPFORMAT
	dwHint DD
	pstrName PTR
	clsid GUID
ENDS

#define GUID_IID_IPropertyBag2 <0x22F55882,0x280B,0x11d0,<0xA8,0xA9,0x00,0xA0,0xC9,0x0C,0x20,0x04>>
IPropertyBag2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Read PTR
	Write PTR
	CountProperties PTR
	GetPropertyInfo PTR
	LoadObject PTR
ENDS

#define GUID_IID_IPersistPropertyBag2 <0x22F55881,0x280B,0x11d0,<0xA8,0xA9,0x00,0xA0,0xC9,0x0C,0x20,0x04>>
IPersistPropertyBag2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	InitNew PTR
	Load PTR
	Save PTR
	IsDirty PTR
ENDS

#define GUID_IID_IAdviseSinkEx <0x3AF24290,0x0C96,0x11CE,<0xA0,0xCF,0x00,0xAA,0x00,0x60,0x0A,0xB8>>
IAdviseSinkEx STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnDataChange PTR
	OnViewChange PTR
	OnRename PTR
	OnSave PTR
	OnClose PTR
	OnViewStatusChange PTR
ENDS

QACONTAINER_SHOWHATCHING = 0x1
QACONTAINER_SHOWGRABHANDLES = 0x2
QACONTAINER_USERMODE = 0x4
QACONTAINER_DISPLAYASDEFAULT = 0x8
QACONTAINER_UIDEAD = 0x10
QACONTAINER_AUTOCLIP = 0x20
QACONTAINER_MESSAGEREFLECT = 0x40
QACONTAINER_SUPPORTSMNEMONICS = 0x80

QACONTAINER STRUCT
	cbSize DD
	pClientSite PTR
	pAdviseSink PTR
	pPropertyNotifySink PTR
	pUnkEventSink PTR
	dwAmbientFlags DD
	colorFore DD
	colorBack DD
	pFont PTR
	pUndoMgr PTR
	dwAppearance DD
	lcid DD
	hpal HANDLE
	pBindHost PTR
	pOleControlSite PTR
	pServiceProvider PTR
ENDS

QACONTROL STRUCT
	cbSize DD
	dwMiscStatus DD
	dwViewStatus DD
	dwEventCookie DD
	dwPropNotifyCookie DD
	dwPointerActivationPolicy DD
ENDS

#define GUID_IID_IQuickActivate <0xCF51ED10,0x62FE,0x11CF,<0xBF,0x86,0x00,0xA0,0xC9,0x03,0x48,0x36>>
IQuickActivate STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QuickActivate PTR
	SetContentExtent PTR
	GetContentExtent PTR
ENDS

#endif