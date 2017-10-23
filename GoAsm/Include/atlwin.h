// This is a part of the Active Template Library.
// Copyright (C) 1996-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef ATLWIN_H
#define ATLWIN_H

#define HIMETRIC_PER_INCH   2540

_ATL_WNDCLASSINFOA STRUCT
	m_wc WNDCLASSEXA
	m_lpszOrigName PTR
	pWndProc PTR
	m_lpszCursorID PTR
	m_bSystemCursor DD
	m_atom ATOM // ATOM
	m_szAutoName DB 13 DUP
	Register PTR
ENDS

_ATL_WNDCLASSINFOW STRUCT
	m_wc WNDCLASSEXW
	m_lpszOrigName PTR
	pWndProc PTR
	m_lpszCursorID PTR
	m_bSystemCursor DD
	m_atom ATOM // ATOM
	m_szAutoName DW 13 DUP
	Register PTR
ENDS

#ifdef UNICODE
	#define AtlModuleRegisterWndClassInfo AtlModuleRegisterWndClassInfoW
	#define _ATL_WNDCLASSINFO ATL_WNDCLASSINFOW
#else
	#define AtlModuleRegisterWndClassInfo AtlModuleRegisterWndClassInfoA
	#define _ATL_WNDCLASSINFO ATL_WNDCLASSINFOA
#endif

/////////////////////////////////////////////////////////////////////////////
// _DialogSizeHelper - helpers for calculating the size of a dialog template

ATL_DLGTEMPLATEEX STRUCT
	dlgVer DW
	signature DW
	helpID DD
	exStyle DD
	style DD
	cDlgItems DW
	x DW
	y DW
	cx DW
	cy DW
ENDS

#endif // ATLWIN_H
