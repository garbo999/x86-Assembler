
/*
Switches
COM_NO_WINDOWS_H
*/


/*
Dependancies
rpc.h
rpcndr.h
windows.h *
ole2.h *
objidl.h
*/

#ifndef OLEIDL_H
#define OLEIDL_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
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

#define GUID_IID_IOleAdviseHolder <0x00000111,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleAdviseHolder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Advise PTR
	Unadvise PTR
	EnumAdvise PTR
	SendOnRename PTR
	SendOnSave PTR
	SendOnClose PTR
ENDS

#define GUID_IID_IOleCache <0x0000011E,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleCache STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Cache PTR
	Uncache PTR
	EnumCache PTR
	InitCache PTR
	SetData PTR
ENDS

#define UPDFCACHE_NODATACACHE  0x1
#define UPDFCACHE_ONSAVECACHE  0x2
#define UPDFCACHE_ONSTOPCACHE  0x4
#define UPDFCACHE_NORMALCACHE  0x8
#define UPDFCACHE_IFBLANK  0x10
#define UPDFCACHE_ONLYIFBLANK  0x80000000
#define UPDFCACHE_IFBLANKORONSAVECACHE  UPDFCACHE_IFBLANK|UPDFCACHE_ONSAVECACHE
#define UPDFCACHE_ALL  !UPDFCACHE_ONLYIFBLANK
#define UPDFCACHE_ALLBUTNODATACACHE  UPDFCACHE_ALL&!UPDFCACHE_NODATACACHE

DISCARDCACHE_SAVEIFDIRTY = 0
DISCARDCACHE_NOSAVE = 1

#define GUID_IID_IOleCache2 <0x00000128,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleCache2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Cache PTR
	Uncache PTR
	EnumCache PTR
	InitCache PTR
	SetData PTR
	UpdateCache PTR
	DiscardCache PTR
ENDS

#define GUID_IID_IOleCacheControl <0x00000129,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleCacheControl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnRun PTR
	OnStop PTR
ENDS

#define GUID_IID_IParseDisplayName <0x0000011a,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IParseDisplayName STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseDisplayName PTR
ENDS

#define GUID_IID_IOleContainer <0x0000011b,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseDisplayName PTR
	EnumObjects PTR
	LockContainer PTR
ENDS

#define GUID_IID_IOleClientSite <0x00000118,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleClientSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SaveObject PTR
	GetMoniker PTR
	GetContainer PTR
	ShowObject PTR
	OnShowWindow PTR
	RequestNewObjectLayout PTR
ENDS

OLEGETMONIKER_ONLYIFTHERE = 1
OLEGETMONIKER_FORCEASSIGN = 2
OLEGETMONIKER_UNASSIGN = 3
OLEGETMONIKER_TEMPFORUSER = 4

OLEWHICHMK_CONTAINER = 1
OLEWHICHMK_OBJREL = 2
OLEWHICHMK_OBJFULL = 3

USERCLASSTYPE_FULL = 1
USERCLASSTYPE_SHORT = 2
USERCLASSTYPE_APPNAME = 3

OLEMISC_RECOMPOSEONRESIZE = 0x1
OLEMISC_ONLYICONIC = 0x2
OLEMISC_INSERTNOTREPLACE = 0x4
OLEMISC_STATIC = 0x8
OLEMISC_CANTLINKINSIDE = 0x10
OLEMISC_CANLINKBYOLE1 = 0x20
OLEMISC_ISLINKOBJECT = 0x40
OLEMISC_INSIDEOUT = 0x80
OLEMISC_ACTIVATEWHENVISIBLE = 0x100
OLEMISC_RENDERINGISDEVICEINDEPENDENT = 0x200
OLEMISC_INVISIBLEATRUNTIME = 0x400
OLEMISC_ALWAYSRUN = 0x800
OLEMISC_ACTSLIKEBUTTON = 0x1000
OLEMISC_ACTSLIKELABEL = 0x2000
OLEMISC_NOUIACTIVATE = 0x4000
OLEMISC_ALIGNABLE = 0x8000
OLEMISC_SIMPLEFRAME = 0x10000,
OLEMISC_SETCLIENTSITEFIRST = 0x20000
OLEMISC_IMEMODE = 0x40000
OLEMISC_IGNOREACTIVATEWHENVISIBLE = 0x80000
OLEMISC_WANTSTOMENUMERGE = 0x100000
OLEMISC_SUPPORTSMULTILEVELUNDO = 0x200000

OLECLOSE_SAVEIFDIRTY = 0
OLECLOSE_NOSAVE = 1
OLECLOSE_PROMPTSAVE = 2

#define GUID_IID_IOleObject <0x00000112,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetClientSite PTR
	GetClientSite PTR
	SetHostNames PTR
	Close PTR
	SetMoniker PTR
	GetMoniker PTR
	InitFromData PTR
	GetClipboardData PTR
	DoVerb PTR
	EnumVerbs PTR
	Update PTR
	IsUpToDate PTR
	GetUserClassID PTR
	GetUserType PTR
	SetExtent PTR
	GetExtent PTR
	Advise PTR
	Unadvise PTR
	EnumAdvise PTR
	GetMiscStatus PTR
	SetColorScheme PTR
ENDS

OLERENDER_NONE = 0
OLERENDER_DRAW = 1
OLERENDER_FORMAT = 2
OLERENDER_ASIS = 3

OBJECTDESCRIPTOR STRUCT
	cbSize DD
	clsid GUID
	dwDrawAspect DD
	sizel SIZE
	pointl POINT
	dwStatus DD
	dwFullUserTypeName DD
	dwSrcOfCopy DD
ENDS

#define GUID_IID_IOleWindow <0x00000114,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleWindow STRUCT
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
ENDS

OLEUPDATE_ALWAYS = 1
OLEUPDATE_ONCALL = 3

OLELINKBIND_EVENIFCLASSDIFF = 1

#define GUID_IID_IOleLink <0x0000011d,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleLink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetUpdateOptions PTR
	GetUpdateOptions PTR
	SetSourceMoniker PTR
	GetSourceMoniker PTR
	SetSourceDisplayName PTR
	GetSourceDisplayName PTR
	BindToSource PTR
	BindIfRunning PTR
	GetBoundSource PTR
	UnbindSource PTR
	Update PTR
ENDS

BINDSPEED_INDEFINITE = 1
BINDSPEED_MODERATE = 2
BINDSPEED_IMMEDIATE = 3

OLECONTF_EMBEDDINGS = 1
OLECONTF_LINKS = 2
OLECONTF_OTHERS = 4
OLECONTF_ONLYUSER = 8
OLECONTF_ONLYIFRUNNING = 16

#define GUID_IID_IOleItemContainer <0x0000011c,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleItemContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseDisplayName PTR
	EnumObjects PTR
	LockContainer PTR
	GetObject PTR
	GetObjectStorage PTR
	IsRunning PTR
ENDS

#define GUID_IID_IOleInPlaceUIWindow <0x00000115,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleInPlaceUIWindow STRUCT
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
	GetBorder PTR
	RequestBorderSpace PTR
	SetBorderSpace PTR
	SetActiveObject PTR
ENDS

#define GUID_IID_IOleInPlaceActiveObject <0x00000117,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleInPlaceActiveObject STRUCT
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
	TranslateAccelerator PTR
	OnFrameWindowActivate PTR
	OnDocWindowActivate PTR
	ResizeBorder PTR
	EnableModeless PTR
ENDS

OLEINPLACEFRAMEINFO STRUCT
	cb DD
	fMDIApp DD
	hwndFrame HANDLE
	haccel HANDLE
	cAccelEntries DD
ENDS

OLEMENUGROUPWIDTHS STRUCT
	width DD 6 DUP (?)
ENDS

#define GUID_IID_IOleInPlaceFrame <0x0116,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleInPlaceFrame STRUCT
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
	GetBorder PTR
	RequestBorderSpace PTR
	SetBorderSpace PTR
	SetActiveObject PTR
	InsertMenus PTR
	SetMenu PTR
	RemoveMenus PTR
	SetStatusText PTR
	EnableModeless PTR
	ranslateAccelerator PTR
ENDS

#define GUID_IID_IOleInPlaceObject <0x0113,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleInPlaceObject STRUCT
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
ENDS

#define GUID_IID_IOleInPlaceSite <0x00000119,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IOleInPlaceSite STRUCT
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
ENDS

#define GUID_IID_IContinue <0x0000012a,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IContinue STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	FContinue PTR
ENDS


#define GUID_IID_IViewObject <0x0000010d,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IViewObject STRUCT
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
ENDS

#define GUID_IID_IViewObject2 <0x00000127,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IViewObject2 STRUCT
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
ENDS

#define GUID_IID_IDropSource <0x00000121,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IDropSource STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryContinueDrag PTR
	GiveFeedback PTR
ENDS

#define MK_ALT  0x20

#define DROPEFFECT_NONE  0
#define DROPEFFECT_COPY  1
#define DROPEFFECT_MOVE  2
#define DROPEFFECT_LINK  4
#define DROPEFFECT_SCROLL  0x80000000

#define DD_DEFSCROLLINSET  11
#define DD_DEFSCROLLDELAY  50
#define DD_DEFSCROLLINTERVAL  50
#define DD_DEFDRAGDELAY  200
#define DD_DEFDRAGMINDIST  2

#define GUID_IID_IDropTarget <0x00000122,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IDropTarget STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	DragEnter PTR
	DragOver PTR
	DragLeave PTR
	Drop PTR
ENDS


OLEVERB STRUCT
	lVerb DD
	lpszVerbName PTR
	fuFlags DD
	grfAttribs DD
ENDS

OLEVERBATTRIB_NEVERDIRTIES = 1
OLEVERBATTRIB_ONCONTAINERMENU = 2

#define GUID_IID_IEnumOLEVERB <0x00000104,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IEnumOLEVERB STRUCT
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

#endif /* OLEIDL_H */
