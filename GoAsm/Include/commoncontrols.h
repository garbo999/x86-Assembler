#IFNDEF COMMONCONTROLS_H
#DEFINE COMMONCONTROLS_H

// Requires a common control V6 manifest file
// GoAsm will not import ImageList_CoCreateInstance from the standard comctl32.dll
// in order to have it imported you must specify the V6 version of the DLL found in
// C:\Windows\winsxs\x86_microsoft.windows.common-controls_6595b64144ccf1df_6.0.6002.18005_none_5cb72f96088b0de0\
// or whatever it is on your system, side by side assemblies bug me
// I really haven't found a way to set this up by default, that is when CCv6 is specified to redirect the
// search for the DLL but I am working on it

/* header files for imported files */
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF

IMAGELISTDRAWPARAMS STRUCT
	cbSize DD
	himl HANDLE
	i DD
	hdcDst HANDLE
	x DD
	y DD
	cx DD
	cy DD
	xBitmap DD
	yBitmap DD
	rgbBk COLORREF
	rgbFg COLORREF
	fStyle DD
	dwRop DD
	fState DD
	Frame DD
	crEffect COLORREF
ENDS

IMAGEINFO STRUCT
	hbmImage HANDLE
	hbmMask HANDLE
	Unused1 DD
	Unused2 DD
	rcImage RECT
ENDS

#define ILIF_ALPHA               0x00000001
#define ILIF_LOWQUALITY          0x00000002
#define ILDRF_IMAGELOWQUALITY    0x00000001
#define ILDRF_OVERLAYLOWQUALITY  0x00000010

#DEFINE GUID_IID_IImageList <0x46EB5926,0x582E,0x4017,<0x9F,0xDF,0xE8,0x99,0x8D,0xAA,0x09,0x50>>

IImageList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Add PTR
	ReplaceIcon PTR
	SetOverlayImage PTR
	Replace PTR
	AddMasked PTR
	Draw PTR
	Remove PTR
	GetIcon PTR
	GetImageInfo PTR
	Copy PTR
	Merge PTR
	Clone PTR
	GetImageRect PTR
	GetIconSize PTR
	SetIconSize PTR
	GetImageCount PTR
	SetImageCount PTR
	SetBkColor PTR
	GetBkColor PTR
	BeginDrag PTR
	EndDrag PTR
	DragEnter PTR
	DragLeave PTR
	DragMove PTR
	SetDragCursorImage PTR
	DragShowNolock PTR
	GetDragImage PTR
	GetItemFlags PTR
	GetOverlayImage PTR
ENDS

#define ILR_DEFAULT                  0x0000
#define ILR_HORIZONTAL_LEFT          0x0000
#define ILR_HORIZONTAL_CENTER        0x0001
#define ILR_HORIZONTAL_RIGHT         0x0002
#define ILR_VERTICAL_TOP             0x0000
#define ILR_VERTICAL_CENTER          0x0010
#define ILR_VERTICAL_BOTTOM          0x0020
#define ILR_SCALE_CLIP               0x0000
#define ILR_SCALE_ASPECTRATIO        0x0100


#define ILGOS_ALWAYS         0x00000000
#define ILGOS_FROMSTANDBY    0x00000001
#define ILFIP_ALWAYS         0x00000000
#define ILFIP_FROMSTANDBY    0x00000001
#define ILDI_PURGE       0x00000001
#define ILDI_STANDBY     0x00000002
#define ILDI_RESETACCESS 0x00000004
#define ILDI_QUERYACCESS 0x00000008

IMAGELISTSTATS STRUCT
	cbSize DD
	cAlloc DD
	cUsed DD
	cStandby DD
ENDS

#DEFINE GUID_IID_IImageList2 <0x192b9d83,0x50fc,0x457b,<0x90,0xa0,0x2b,0x82,0xa8,0xb5,0xda,0xe1>>

IImageList2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Add PTR
	ReplaceIcon PTR
	SetOverlayImage PTR
	Replace PTR
	AddMasked PTR
	Draw PTR
	Remove PTR
	GetIcon PTR
	GetImageInfo PTR
	Copy PTR
	Merge PTR
	Clone PTR
	GetImageRect PTR
	GetIconSize PTR
	SetIconSize PTR
	GetImageCount PTR
	SetImageCount PTR
	SetBkColor PTR
	GetBkColor PTR
	BeginDrag PTR
	EndDrag PTR
	DragEnter PTR
	DragLeave PTR
	DragMove PTR
	SetDragCursorImage PTR
	DragShowNolock PTR
	GetDragImage PTR
	GetItemFlags PTR
	GetOverlayImage PTR
	Resize PTR
	GetOriginalSize PTR
	SetOriginalSize PTR
	SetCallback PTR
	GetCallback PTR
	ForceImagePresent PTR
	DiscardImages PTR
	PreloadImages PTR
	GetStatistics PTR
	Initialize PTR
	Replace2 PTR
	ReplaceFromImageList PTR
Ends

#DEFINE GUID_CLSID_ImageList <0x7C476BA2,0x02B1,0x48f4,<0x80,0x48,0xB2,0x46,0x19,0xDD,0xC0,0x58>>

#endif



