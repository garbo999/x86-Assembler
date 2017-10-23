// This is a part of the Active Template Library.
// Copyright (C) 1996-1998 Microsoft Corporation
// All rights reserved.

#ifndef ATLIFACE_H
#define ATLIFACE_H

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
#endif

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF
#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF

#IFNDEF GUID_CLSID_Registrar
	#define GUID_CLSID_Registrar <0x44EC053A,0x400F,0x11D0,<0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3>>
#ENDIF

#IFNDEF GUID_IID_IRegistrar
	#define GUID_IID_IRegistrar <0x44EC053B,0x400F,0x11D0,<0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3>>
#ENDIF

IID_IRegistrar STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddReplacement PTR
	ClearReplacements PTR
	ResourceRegisterSz PTR
	ResourceUnregisterSz PTR
	FileRegister PTR
	FileUnregister PTR
	StringRegister PTR
	StringUnregister PTR
	ResourceRegister PTR
	ResourceUnregister PTR
ENDS

docHostUIDblClkDEFAULT	= 0
docHostUIDblClkSHOWPROPERTIES	= 1
docHostUIDblClkSHOWCODE	= 2

docHostUIFlagDIALOG	= 1
docHostUIFlagDISABLE_HELP_MENU	= 2
docHostUIFlagNO3DBORDER	= 4
docHostUIFlagSCROLL_NO	= 8
docHostUIFlagDISABLE_SCRIPT_INACTIVE	= 16
docHostUIFlagOPENNEWWIN	= 32
docHostUIFlagDISABLE_OFFSCREEN	= 64
docHostUIFlagFLAT_SCROLLBAR	= 128
docHostUIFlagDIV_BLOCKDEFAULT	= 256
docHostUIFlagACTIVATE_CLIENTHIT_ONLY	= 512

#IFNDEF GUID_IID_IDocHostUIHandlerDispatch
	#define GUID_IID_IDocHostUIHandlerDispatch <0x425B5AF0,0x65F1,0x11d1,<0x96,0x11,0x00,0x00,0xF8,0x1E,0x0D,0x0D>>
#ENDIF

IDocHostUIHandlerDispatch STRUCT
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

#IFNDEF GUID_IID_IAxWinHostWindow
	#define GUID_IID_IAxWinHostWindow <0xb6ea2050,0x48a,0x11d1,<0x82,0xb9,0x0,0xc0,0x4f,0xb9,0x94,0x2e>>
#ENDIF

IAxWinHostWindow STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateControl PTR
	CreateControlEx PTR
	AttachControl PTR
	QueryControl PTR
	SetExternalDispatch PTR
	SetExternalUIHandler PTR
ENDS

#IFNDEF GUID_IID_IAxWinAmbientDispatch
	#define GUID_IID_IAxWinAmbientDispatch <0xb6ea2051,0x48a,0x11d1,<0x82,0xb9,0x0,0xc0,0x4f,0xb9,0x94,0x2e>>
#ENDIF

IAxWinAmbientDispatch STRUCT
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
	put_AllowWindowlessActivation PTR
	get_AllowWindowlessActivation PTR
	put_BackColor PTR
	get_BackColor PTR
	put_ForeColor PTR
	get_ForeColor PTR
	put_LocaleID PTR
	get_LocaleID PTR
 	put_UserMode PTR
	get_UserMode PTR
	put_DisplayAsDefault PTR
	get_DisplayAsDefault PTR
	put_Font PTR
	get_Font PTR
	put_MessageReflect PTR
	get_MessageReflect PTR
	get_ShowGrabHandles PTR
	get_ShowHatching PTR
	put_DocHostFlags PTR
	get_DocHostFlags PTR
	put_DocHostDoubleClickFlags PTR
	get_DocHostDoubleClickFlags PTR
	put_AllowContextMenu PTR
	get_AllowContextMenu PTR
	put_AllowShowUI PTR
	get_AllowShowUI PTR
	put_OptionKeyPath PTR
	get_OptionKeyPath PTR
ENDS

#IFNDEF GUID_IID_IInternalConnection
	#define GUID_IID_IInternalConnection <0x72AD0770,0x6A9F,0x11d1,<0xBC,0xEC,0x00,0x60,0x08,0x8F,0x44,0x4E>>
#ENDIF

IInternalConnection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddConnection PTR
	ReleaseConnection PTR
ENDS

#ifdef UNICODE
	#define AtlAxDialogBox AtlAxDialogBoxW
	#define AtlAxCreateDialog AtlAxCreateDialogW
#else
	#define AtlAxDialogBox AtlAxDialogBoxA
	#define AtlAxCreateDialog AtlAxCreateDialogA
#endif

#endif
