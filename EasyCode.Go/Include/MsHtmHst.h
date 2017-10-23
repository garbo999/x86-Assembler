//--------------------------------------------------------------------------
// MSTHML Advanced Host Interfaces.

#IFNDEF MSHTMHST_H
#DEFINE MSHTMHST_H

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

/* header files for imported files */
#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF
#IFNDEF DOCOBJ_H
	#include "docobj.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define CONTEXT_MENU_DEFAULT        0
#define CONTEXT_MENU_IMAGE          1
#define CONTEXT_MENU_CONTROL        2
#define CONTEXT_MENU_TABLE          3
// in browse mode
#define CONTEXT_MENU_TEXTSELECT     4
#define CONTEXT_MENU_ANCHOR         5
#define CONTEXT_MENU_UNKNOWN        6
//;begin_internal
// These 2 are mapped to IMAGE for the public
#define CONTEXT_MENU_IMGDYNSRC      7
#define CONTEXT_MENU_IMGART         8
#define CONTEXT_MENU_DEBUG          9
//;end_internal
#define CONTEXT_MENU_VSCROLL        10
#define CONTEXT_MENU_HSCROLL        11
#define MENUEXT_SHOWDIALOG           0x1
#define DOCHOSTUIFLAG_BROWSER       (DOCHOSTUIFLAG_DISABLE_HELP_MENU | DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE) 
#define HTMLDLG_NOUI                     0x0010
#define HTMLDLG_MODAL                    0x0020
#define HTMLDLG_MODELESS                 0x0040
#define HTMLDLG_PRINT_TEMPLATE           0x0080
#define HTMLDLG_VERIFY                   0x0100
#define HTMLDLG_ALLOW_UNKNOWN_THREAD     0x0200
#define PRINT_DONTBOTHERUSER             0x01
#define PRINT_WAITFORCOMPLETION          0x02

#define GUID_CMDSETID_Forms3 <0xDE4BA900,0x59CA,0x11CF,<0x95,0x92,0x44,0x45,0x53,0x54,0x00,0x00>>

#define SZ_HTML_CLIENTSITE_OBJECTPARAM L"{d4db6850-5385-11d0-89e9-00a0c90a90ac}"

#DEFINE GUID_IID_IHostDialogHelper <0x53DEC138,0xA51E,0x11d2,<0x86,0x1E,0x00,0xC0,0x4F,0xA3,0x5C,0x89>>

IHostDialogHelper STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowHTMLDialog PTR
ENDS

#define GUID_CLSID_HostDialogHelper <0x429af92c,0xa51f,0x11d2,<0x86,0x1e,0x00,0xc0,0x4f,0xa3,0x5c,0x89>>

DOCHOSTUITYPE_BROWSE	= 0
DOCHOSTUITYPE_AUTHOR	= 1

DOCHOSTUIDBLCLK_DEFAULT	= 0
DOCHOSTUIDBLCLK_SHOWPROPERTIES	= 1
DOCHOSTUIDBLCLK_SHOWCODE	= 2

DOCHOSTUIFLAG_DIALOG	= 0x1
DOCHOSTUIFLAG_DISABLE_HELP_MENU	= 0x2
DOCHOSTUIFLAG_NO3DBORDER	= 0x4
DOCHOSTUIFLAG_SCROLL_NO	= 0x8
DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE	= 0x10
DOCHOSTUIFLAG_OPENNEWWIN	= 0x20
DOCHOSTUIFLAG_DISABLE_OFFSCREEN	= 0x40
DOCHOSTUIFLAG_FLAT_SCROLLBAR	= 0x80
DOCHOSTUIFLAG_DIV_BLOCKDEFAULT	= 0x100
DOCHOSTUIFLAG_ACTIVATE_CLIENTHIT_ONLY	= 0x200
DOCHOSTUIFLAG_OVERRIDEBEHAVIORFACTORY	= 0x400
DOCHOSTUIFLAG_CODEPAGELINKEDFONTS	= 0x800
DOCHOSTUIFLAG_URL_ENCODING_DISABLE_UTF8	= 0x1000
DOCHOSTUIFLAG_URL_ENCODING_ENABLE_UTF8	= 0x2000
DOCHOSTUIFLAG_ENABLE_FORMS_AUTOCOMPLETE	= 0x4000
DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION	= 0x10000
DOCHOSTUIFLAG_IME_ENABLE_RECONVERSION	= 0x20000
DOCHOSTUIFLAG_THEME	= 0x40000
DOCHOSTUIFLAG_NOTHEME	= 0x80000
DOCHOSTUIFLAG_NOPICS	= 0x100000
DOCHOSTUIFLAG_NO3DOUTERBORDER	= 0x200000
DOCHOSTUIFLAG_DISABLE_EDIT_NS_FIXUP	= 0x400000
DOCHOSTUIFLAG_LOCAL_MACHINE_ACCESS_CHECK	= 0x800000
DOCHOSTUIFLAG_DISABLE_UNTRUSTEDPROTOCOL	= 0x1000000
DOCHOSTUIFLAG_HOST_NAVIGATES	= 0x2000000
DOCHOSTUIFLAG_ENABLE_REDIRECT_NOTIFICATION	= 0x4000000
DOCHOSTUIFLAG_USE_WINDOWLESS_SELECTCONTROL	= 0x8000000
DOCHOSTUIFLAG_USE_WINDOWED_SELECTCONTROL	= 0x10000000
DOCHOSTUIFLAG_ENABLE_ACTIVEX_INACTIVATE_MODE	= 0x20000000

#define DOCHOSTUIATOM_ENABLE_HIRES "TridentEnableHiRes"

DOCHOSTUIINFO STRUCT
	cbSize DD
	dwFlags DD
	dwDoubleClick DD
	pchHostCss PTR
	pchHostNS PTR
ENDS

#DEFINE GUID_IID_IDocHostUIHandler <0xbd3f23c0,0xd43e,0x11cf,<0x89,0x3b,0x00,0xaa,0x00,0xbd,0xce,0x1a>>

IDocHostUIHandler STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowContextMenu PTR
	GetHostInfo PTR
	ShowUI PTR
	HideUI PTR
	UpdateUI PTR
	EnableModeless PTR
	OnDocWindowActivate PTR
	OnFrameWindowActivate PTR
	ResizeBorder PTR
	TranslateAccelerator PTR
	GetOptionKeyPath PTR
	GetDropTarget PTR
	GetExternal PTR
	TranslateUrl PTR
	FilterDataObject PTR
ENDS

#DEFINE GUID_IID_IDocHostUIHandler2 <0x3050f6d0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IDocHostUIHandler2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowContextMenu PTR
	GetHostInfo PTR
	ShowUI PTR
	HideUI PTR
	UpdateUI PTR
	EnableModeless PTR
	OnDocWindowActivate PTR
	OnFrameWindowActivate PTR
	ResizeBorder PTR
	TranslateAccelerator PTR
	GetOptionKeyPath PTR
	GetDropTarget PTR
	GetExternal PTR
	TranslateUrl PTR
	FilterDataObject PTR
	GetOverrideKeyPath PTR
ENDS

#DEFINE GUID_CGID_DocHostCommandHandler <0xf38bc242,0xb950,0x11d1,<0x89,0x18,0x00,0xc0,0x4f,0xc2,0xc8,0x36>>

#DEFINE GUID_IID_ICustomDoc <0x3050f3f0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ICustomDoc STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetUIHandler PTR
ENDS

#DEFINE GUID_IID_IDocHostShowUI <0xc4d244b0,0xd43e,0x11cf,<0x89,0x3b,0x00,0xaa,0x00,0xbd,0xce,0x1a>>

IDocHostShowUI STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowMessage PTR
	ShowHelp PTR
ENDS

#DEFINE GUID_IID_IClassFactoryEx <0x342D1EA0,0xAE25,0x11D1,<0x89,0xC5,0x00,0x60,0x08,0xC3,0xFB,0xFC>>

IClassFactoryEx STRUCT
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
	CreateInstanceWithContext PTR
ENDS

#DEFINE GUID_IID_IHTMLOMWindowServices <0x3050f5fc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLOMWindowServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	moveTo PTR
	moveBy PTR
	resizeTo PTR
	resizeBy PTR
ENDS

#endif



