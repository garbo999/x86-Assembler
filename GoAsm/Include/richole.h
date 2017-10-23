#ifndef RICHOLE_H
#define RICHOLE_H

/* Windows RichEdit OLE Extension definitions */

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define REO_GETOBJ_NO_INTERFACES  0
#define REO_GETOBJ_POLEOBJ  1
#define REO_GETOBJ_PSTG  2
#define REO_GETOBJ_POLESITE  4
#define REO_GETOBJ_ALL_INTERFACES  7

#define REO_CP_SELECTION  -1
#define REO_IOB_SELECTION  -1
#define REO_IOB_USE_CP  -2

#define REO_NULL  0x00000000
#define REO_READWRITEMASK  0x0000003F
#define REO_DONTNEEDPALETTE  0x00000020
#define REO_BLANK  0x00000010
#define REO_DYNAMICSIZE  0x00000008
#define REO_INVERTEDSELECT  0x00000004
#define REO_BELOWBASELINE  0x00000002
#define REO_RESIZABLE  0x00000001
#define REO_LINK  0x80000000
#define REO_STATIC  0x40000000
#define REO_SELECTED  0x08000000
#define REO_OPEN  0x04000000
#define REO_INPLACEACTIVE  0x02000000
#define REO_HILITED  0x01000000
#define REO_LINKAVAILABLE  0x00800000
#define REO_GETMETAFILE  0x00400000

#define RECO_PASTE  0
#define RECO_DROP  1
#define RECO_COPY  2
#define RECO_CUT  3
#define RECO_DRAG  4

#DEFINE GUID_IID_IRichEditOle <0x00020D00,0,0,<0xC0,0,0,0,0,0,0,0x46>>
#DEFINE GUID_IID_IRichEditOleCallback <0x00020D03,0,0,<0xC0,0,0,0,0,0,0,0x46>>

REOBJECT STRUCT
	cbStruct DD
	cp DD
	clsid GUID
	poleobj PTR
	pstg PTR
	polesite PTR
	sizel SIZEL
	dvaspect DD
	dwFlags DD
	dwUser DD
ENDS

IRichEditOle STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClientSite PTR
	GetObjectCount PTR
	GetLinkCount PTR
	GetObject PTR
	InsertObject PTR
	ConvertObject PTR
	ActivateAs PTR
	SetHostNames PTR
	SetLinkAvailable PTR
	SetDvaspect PTR
	HandsOffStorage PTR
	SaveCompleted PTR
	InPlaceDeactivate PTR
	ContextSensitiveHelp PTR
	GetClipboardData PTR
	ImportDataObject PTR
ENDS

IRichEditOleCallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNewStorage PTR
	GetInPlaceContext PTR
	ShowContainerUI PTR
	QueryInsertObject PTR
	DeleteObject PTR
	QueryAcceptData PTR
	ContextSensitiveHelp PTR
	GetClipboardData PTR
	GetDragDropEffect PTR
	GetContextMenu PTR
ENDS

#endif /* _RICHOLE_H */
