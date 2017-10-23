// This is a part of the Active Template Library.
// Copyright (C) 1996-1998 Microsoft Corporation
// All rights reserved.

#ifndef ATLBASE_H
#define ATLBASE_H

#IFDEF LINKFILES
	#dynamiclinkfile atl.dll
#ENDIF

#IFNDEF ATLDEF_H
	#include "atldef.h"
#ENDIF

#IFNDEF WINDOWS_H
	#include "windows.h"
#ENDIF

#IFNDEF WINNLS_H
	#include "winnls.h"
#ENDIF

#IFNDEF OLE2_H
	#include "ole2.h"
#ENDIF

#IFNDEF STDDEF_H
	#include "C99\stddef.h"
#ENDIF

#IFNDEF OLECTL_H
	#include "olectl.h"
#ENDIF

#IFNDEF WINREG_H
	#include "winreg.h"
#ENDIF

#IFNDEF ATLIFACE_H
	#include "atliface.h"
#ENDIF

#IFNDEF SHLWAPI_H
	#include "shlwapi.h"
#ENDIF

#define GUID_TLBID_ATLLib <0x44EC0535,0x400F,0x11D0,<0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3>

#IFNDEF GUID_CLSID_Registrar
	#define GUID_CLSID_Registrar <0x44EC053A,0x400F,0x11D0,<0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3>>
#ENDIF

#IFNDEF GUID_IID_IRegistrar
	#define GUID_IID_IRegistrar <0x44EC053B,0x400F,0x11D0,<0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3>>
#ENDIF

#IFNDEF GUID_IID_IAxWinHostWindow
	#define GUID_IID_IAxWinHostWindow <0xb6ea2050,0x48a,0x11d1,<0x82,0xb9,0x0,0xc0,0x4f,0xb9,0x94,0x2e>>
#ENDIF

#IFNDEF GUID_IID_IAxWinAmbientDispatch
	#define GUID_IID_IAxWinAmbientDispatch <0xb6ea2051,0x48a,0x11d1,<0x82,0xb9,0x0,0xc0,0x4f,0xb9,0x94,0x2e>>
#ENDIF

#IFNDEF GUID_IID_IInternalConnection
	#define GUID_IID_IInternalConnection <0x72AD0770,0x6A9F,0x11d1,<0xBC,0xEC,0x00,0x60,0x08,0x8F,0x44,0x4E>>
#ENDIF

#IFNDEF GUID_IID_IDocHostUIHandlerDispatch
	#define GUID_IID_IDocHostUIHandlerDispatch <0x425B5AF0,0x65F1,0x11d1,<0x96,0x11,0x00,0x00,0xF8,0x1E,0x0D,0x0D>>
#ENDIF

_ATL_CATMAP_ENTRY STRUCT
	iType DD
	pcatid PTR
ENDS

#define _ATL_CATMAP_ENTRY_END 0
#define _ATL_CATMAP_ENTRY_IMPLEMENTED 1
#define _ATL_CATMAP_ENTRY_REQUIRED 2

_ATL_TERMFUNC_ELEM STRUCT
	pFunc PTR
	_dw DD
	pNext PTR
ENDS

_ATL_OBJMAP_ENTRY STRUCT
	pclsid PTR
	pfnUpdateRegistry PTR
	pfnGetClassObject PTR
	pfnCreateInstance PTR
	pCF PTR
	dwRegister DD
	pfnGetObjectDescription PTR
	pfnGetCategoryMap PTR
	RevokeClassObject PTR
	RegisterClassObject PTR
	pfnObjectMain PTR
ENDS

_ATL_REGMAP_ENTRY STRUCT
	szKey PTR
	szData PTR
ENDS

_AtlCreateWndData STRUCT
	m_pThis PTR
	m_dwThreadID DD
	m_pNext PTR
ENDS

_ATL_MODULE STRUCT
	cbSize DD
	m_hInst DD
	m_hInstResource DD
	m_hInstTypeLib DD
	m_pObjMap PTR
	m_nLockCnt DD
	m_hHeap DD
	UNION
		m_csTypeInfoHolder CRITICAL_SECTION <>
		m_csStaticDataInit CRITICAL_SECTION <>
	ENDUNION
	m_csWindowCreate CRITICAL_SECTION <>
	m_csObjMap CRITICAL_SECTION <>
// Original Size = 100
// Stuff added in ATL 3.0
	dwAtlBuildVer DD
	m_pCreateWndList PTR
	m_bDestroyHeap DD
	pguidVer PTR
	m_dwHeaps DD    // Number of heaps we have (-1)
	m_phHeaps PTR
	m_nHeap DD        // Which heap to choose from
	m_pTermFuncs PTR
ENDS

_nAtlModuleVer1Size = 100

_ATL_INTMAP_ENTRY STRUCT
	piid PTR       // the interface id (IID)
	_dw DD
	pFunc PTR //NULL:end, 1:offset, n:ptr
ENDS

// Application defined categories
atlTraceUser        = 0x00000001
atlTraceUser2       = 0x00000002
atlTraceUser3       = 0x00000004
atlTraceUser4       = 0x00000008
// ATL defined categories
atlTraceGeneral     = 0x00000020
atlTraceCOM         = 0x00000040
atlTraceQI      = 0x00000080
atlTraceRegistrar   = 0x00000100
atlTraceRefcount    = 0x00000200
atlTraceWindowing   = 0x00000400
atlTraceControls    = 0x00000800
atlTraceHosting     = 0x00001000
atlTraceDBClient    = 0x00002000
atlTraceDBProvider  = 0x00004000
atlTraceSnapin      = 0x00008000
atlTraceNotImpl     = 0x00010000

#ifndef ATL_TRACE_CATEGORY
	#define ATL_TRACE_CATEGORY 0xFFFFFFFF
#endif

/////////////////////////////////////////////////////////////////////////////
// Module

_ATL_MODULE20 STRUCT
	cbSize DD
	m_hInst DD
	m_hInstResource DD
	m_hInstTypeLib DD
	m_pObjMap PTR
	m_nLockCnt DD
	m_hHeap DD
	m_csTypeInfoHolder CRITICAL_SECTION <>
	m_csWindowCreate CRITICAL_SECTION <>
	m_csObjMap CRITICAL_SECTION <>
ENDS

#define _ATL_MODULE30 _ATL_MODULE

_ATL_OBJMAP_ENTRY20 STRUCT
	pclsid PTR
	pfnUpdateRegistry PTR
	pfnGetClassObject PTR
	pfnCreateInstance PTR
	pCF PTR
	dwRegister DD
	pfnGetObjectDescription PTR
ENDS

#define _ATL_OBJMAP_ENTRY30 _ATL_OBJMAP_ENTRY

ATL_DRAWINFO STRUCT
	cbSize DD
	dwDrawAspect DD
	lindex DD
	ptd PTR
	hicTargetDev DD
	hdcDraw DD
	prcBounds PTR
	prcWBounds PTR
	bOptimize DD
	bZoomed DD
	bRectInHimetric DD
	ZoomNum SIZEL <>
	ZoomDen SIZEL <>
ENDS

_ATL_BASE_MODULE70 STRUCT
	cbSize DD
	m_hInst DD
	m_hInstResource DD
	m_bNT5orWin98 DD
	dwAtlBuildVer DD
	pguidVer PTR
	m_csResource CRITICAL_SECTION <>
	m_rgResourceInstance DD
ENDS

#define ATL_BASE_MODULE _ATL_BASE_MODULE70

_ATL_COM_MODULE70 STRUCT
	cbSize DD
	m_hInstTypeLib DD
	m_ppAutoObjMapFirst PTR
	m_ppAutoObjMapLast PTR
	m_csObjMap CRITICAL_SECTION <>
ENDS

#DEFINE ATL_COM_MODULE _ATL_COM_MODULE70

_ATL_OBJMAP_ENTRYA STRUCT
	pclsid PTR
	pfnUpdateRegistry PTR
	pfnGetClassObject PTR
	pfnCreateInstance PTR
	pCF PTR
	dwRegister DD
	pfnGetObjectDescription PTR
	pfnGetCategoryMap PTR
	pfnObjectMain PTR
ENDS

_ATL_FUNC_INFO STRUCT
	cc DD
	vtReturn DD
	nParams DW
	pVarTypes DD ATL_MAX_VARTYPES DUP
ENDS

#endif

