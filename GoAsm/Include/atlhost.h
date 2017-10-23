// This is a part of the Active Template Library.
// Copyright (C) 1996-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#ifndef ATLHOST_H
#define ATLHOST_H

#IFNDEF URLMON_H
	#include "urlmon.h"
#ENDIF

#IFNDEF MSHTML_H
	#include "mshtml.h"
#ENDIF
#IFNDEF MSHTMHST_H
	#include "mshtmhst.h"
#ENDIF

#IFNDEF EXDISP_H
	#include "exdisp.h"
#ENDIF

#ifndef ATL_AXHOST
	#define ATL_AXHOST
#endif //ATL_AXHOST

#IFNDEF ATLWIN_H
	#include "atlwin.h"
#ENDIF

/////////////////////////////////////////////////////////////////////////////
// Helper functions for cracking dialog templates

#define ATL_RT_DLGINIT  240

WM_OCC_LOADFROMSTREAM = 0x0376
WM_OCC_LOADFROMSTORAGE = 0x0377
WM_OCC_INITNEW = 0x0378
WM_OCC_LOADFROMSTREAM_EX = 0x037A
WM_OCC_LOADFROMSTORAGE_EX = 0x037B
DISPID_DATASOURCE = 0x80010001
DISPID_DATAFIELD = 0x80010002

DLGINITSTRUCT STRUCT
	nIDC DW
	message DW
	dwSize DD
ENDS

DLGTEMPLATEEX STRUCT
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

// Everything else in this structure is variable length,
// and therefore must be determined dynamically

// sz_Or_Ord menu;			// name or ordinal of a menu resource
// sz_Or_Ord windowClass;	// name or ordinal of a window class
// WCHAR title[titleLen];	// title string of the dialog box
// short pointsize;			// only if DS_SETFONT is set
// short weight;			// only if DS_SETFONT is set
// short bItalic;			// only if DS_SETFONT is set
// WCHAR font[fontLen];		// typeface name, if DS_SETFONT is set


DLGITEMTEMPLATEEX STRUCT
	helpID DD
	exStyle DD
	style DD
	x DW
	y DW
	cx DW
	cy DW
	id DD
ENDS

// Everything else in this structure is variable length,
// and therefore must be determined dynamically

// sz_Or_Ord windowClass;	// name or ordinal of a window class
// sz_Or_Ord title;			// title string or ordinal of a resource
// WORD extraCount;			// bytes following creation data

#endif  // ATLHOST_H

