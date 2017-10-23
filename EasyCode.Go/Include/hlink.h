#ifndef HLINK_H
#define HLINK_H

#IFDEF LINKFILES
	#dynamiclinkfile Hlink.dll
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif /*COM_NO_WINDOWS_H*/

#IFNDEF URLMON_H
	#include "urlmon.h"
#ENDIF

#IFNDEF HLGUIDS_H
	#include "HlGuids.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

//=--------------------------------------------------------------------------=
// HLInk.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1995 - 1998 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

//--------------------------------------------------------------------------
// OLE Hyperlinking Interfaces.

// We temporarily support the old 'source' names                              
#define SID_SHlinkFrame IID_IHlinkFrame
#define IID_IHlinkSource IID_IHlinkTarget
#define IHlinkSource IHlinkTarget

/****************************************************************************/
/**** Error codes                                                        ****/
/****************************************************************************/
#ifndef HLINK_ERRORS_DEFINED
#define HLINK_ERRORS_DEFINED
#define HLINK_E_FIRST (OLE_E_LAST+1)
#define HLINK_S_FIRST (OLE_S_LAST+1)
#define HLINK_S_DONTHIDE (HLINK_S_FIRST)
#endif //_HLINK_ERRORS_DEFINED

/****************************************************************************/
/**** Hyperlink APIs                                                     ****/
/****************************************************************************/

#ifdef MAC
	#define cfHyperlink 'HLNK'
#else
	#define CFSTR_HYPERLINK "Hyperlink"
#endif

HLSR_HOME	= 0
HLSR_SEARCHPAGE	= 1
HLSR_HISTORYFOLDER	= 2

HLSHORTCUTF_DEFAULT	= 0
HLSHORTCUTF_DONTACTUALLYCREATE	= 0x1
HLSHORTCUTF_USEFILENAMEFROMFRIENDLYNAME	= 0x2
HLSHORTCUTF_USEUNIQUEFILENAME	= 0x4
HLSHORTCUTF_MAYUSEEXISTINGSHORTCUT	= 0x8

HLTRANSLATEF_DEFAULT	= 0
HLTRANSLATEF_DONTAPPLYDEFAULTPREFIX	= 0x1

/****************************************************************************/
/**** Hyperlink interface definitions                                    ****/
/****************************************************************************/

HLNF_INTERNALJUMP	= 0x1
HLNF_OPENINNEWWINDOW	= 0x2
HLNF_NAVIGATINGBACK	= 0x4
HLNF_NAVIGATINGFORWARD	= 0x8
HLNF_NAVIGATINGTOSTACKITEM	= 0x10
HLNF_CREATENOHISTORY	= 0x20

HLINKGETREF_DEFAULT	= 0
HLINKGETREF_ABSOLUTE	= 1
HLINKGETREF_RELATIVE	= 2

HLFNAMEF_DEFAULT	= 0
HLFNAMEF_TRYCACHE	= 0x1
HLFNAMEF_TRYPRETTYTARGET	= 0x2
HLFNAMEF_TRYFULLTARGET	= 0x4
HLFNAMEF_TRYWIN95SHORTCUT	= 0x8

HLINKMISC_RELATIVE	= 0x1

HLINKSETF_TARGET	= 0x1
HLINKSETF_LOCATION	= 0x2

#DEFINE GUID_IID_IHlink <0x79eac9c3,0xbaf9,0x11ce,<0x8c,0x82,0x00,0xaa,0x00,0x4b,0xa9,0x0b>>
IHlink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetHlinkSite PTR
	GetHlinkSite PTR
	SetMonikerReference PTR
	GetMonikerReference PTR
	SetStringReference PTR
	GetStringReference PTR
	SetFriendlyName PTR
	GetFriendlyName PTR
	SetTargetFrameName PTR
	GetTargetFrameName PTR
	GetMiscStatus PTR
	Navigate PTR
	SetAdditionalParams PTR
	GetAdditionalParams PTR
ENDS

HLINKWHICHMK_CONTAINER	= 1
HLINKWHICHMK_BASE	= 2

#DEFINE GUID_IID_IHlinkSite <0x79eac9c2,0xbaf9,0x11ce,<0x8c,0x82,0x00,0xaa,0x00,0x4b,0xa9,0x0b>>
IHlinkSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryService PTR
	GetMoniker PTR
	ReadyToNavigate PTR
	OnNavigationComplete PTR
ENDS

#DEFINE GUID_IID_IHlinkTarget <0x79eac9c4,0xbaf9,0x11ce,<0x8c,0x82,0x00,0xaa,0x00,0x4b,0xa9,0x0b>>
IHlinkTarget STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetBrowseContext PTR
	GetBrowseContext PTR
	Navigate PTR
	GetMoniker PTR
	GetFriendlyName PTR
ENDS

#DEFINE GUID_IID_IHlinkFrame <0x79eac9c5,0xbaf9,0x11ce,<0x8c,0x8,0x00,0xaa,0x00,0x4b,0xa9,0x0b>>
IHlinkFrame STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetBrowseContext PTR
	GetBrowseContext PTR
	Navigate PTR
	OnNavigate PTR
	UpdateHlink PTR
ENDS

HLITEM STRUCT
	uHLID DD
	pwzFriendlyName PTR
ENDS

#DEFINE GUID_IID_IEnumHLITEM <0x79eac9c6,0xbaf9,0x11ce,<0x8c,0x82,0x00,0xaa,0x00,0x4b,0xa9,0x0b>>
IEnumHLITEM STRUCT
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

HLTB_DOCKEDLEFT	= 0
HLTB_DOCKEDTOP	= 1
HLTB_DOCKEDRIGHT	= 2
HLTB_DOCKEDBOTTOM	= 3
HLTB_FLOATING	= 4

HLTBINFO STRUCT
	uDockType DD
	rcTbPos RECT
ENDS

HLBWIF_HASFRAMEWNDINFO	= 0x1
HLBWIF_HASDOCWNDINFO	= 0x2
HLBWIF_FRAMEWNDMAXIMIZED	= 0x4
HLBWIF_DOCWNDMAXIMIZED	= 0x8
HLBWIF_HASWEBTOOLBARINFO	= 0x10
HLBWIF_WEBTOOLBARHIDDEN	= 0x20

HLBWINFO STRUCT
	cbSize DD
	grfHLBWIF DD
	rcFramePos RECT
	rcDocPos RECT
	hltbinfo HLTBINFO
ENDS

HLID_INVALID	= 0
HLID_PREVIOUS	= 0xffffffff
HLID_NEXT	= 0xfffffffe
HLID_CURRENT	= 0xfffffffd
HLID_STACKBOTTOM	= 0xfffffffc
HLID_STACKTOP	= 0xfffffffb

HLQF_ISVALID	= 0x1
HLQF_ISCURRENT	= 0x2

#DEFINE GUID_IID_IHlinkBrowseContext <0x79eac9c7,0xbaf9,0x11ce,<0x8c,0x82,0x00,0xaa,0x00,0x4b,0xa9,0x0b>>
IHlinkBrowseContext STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Register PTR
	GetObject PTR
	Revoke PTR
	SetBrowseWindowInfo PTR
	GetBrowseWindowInfo PTR
	SetInitialHlink PTR
	OnNavigateHlink PTR
	UpdateHlink PTR
	EnumNavigationStack PTR
	QueryHlink PTR
	GetHlink PTR
	SetCurrentHlink PTR
	Clone PTR
	Close PTR
ENDS

#DEFINE GUID_IID_IExtensionServices <0x79eac9cb,0xbaf9,0x11ce,<0x8c,0x82,0x00,0xaa,0x00,0x4b,0xa9,0x0b>>
IExtensionServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAdditionalHeaders PTR
	SetAuthenticateData PTR
ENDS
                                                                         
#endif // HLINK_H