#IFNDEF WINDOWS_INC
// These structures conflict with header structures
// defining them first will ensure the older MASM32
// versions are used instead of the correct versions
// in the header files. This is a fix for backward
// compatibility only. New projects should use the
// header project only, older projects should be
// adapted to the header project where possible

REBARBANDINFO STRUCT
  cbSize        DD
  fMask         DD
  fStyle        DD
  clrFore       DD
  clrBack       DD
  lpText        DD
  cch           DD
  iImage        DD
  hwndChild     DD
  cxMinChild    DD
  cyMinChild    DD
  lx            DD
  hbmBack       DD
  wID           DD
  cyChild       DD
  cyMaxChild    DD
  cyIntegral    DD
  cxIdeal       DD
  lParam        DD
  cxHeader      DD
REBARBANDINFO ENDS

HD_ITEM STRUCT
  imask          DD
  lxy            DD
  pszText        DD
  hbm            DD
  cchTextMax     DD
  fmt            DD
  lParam         DD
  iImage         DD
  iOrder         DD
  itype dd
  pvFilter dd
HD_ITEM ENDS

LV_COLUMN STRUCT
  imask         DD
  fmt           DD
  lx            DD
  pszText       DD
  cchTextMax    DD
  iSubItem      DD
  iImage        DD
  iOrder        DD
LV_COLUMN ENDS

WINDOWPOS STRUCT
  hwnd              DD
  hWndInsertAfter   DD
  x                 DD
  y                 DD
  lx                DD
  cy                DD
  flags             DD
WINDOWPOS ENDS

CREATESTRUCT STRUCT
  lpCreateParams    DD
  hInstance         DD
  hMenu             DD
  hWndParent        DD
  ly                DD
  lx                DD
  y                 DD
  x                 DD
  style             DD
  lpszName          DD
  lpszClass         DD
  ExStyle           DD
CREATESTRUCT ENDS

DLGTEMPLATE STRUCT
  style             DD
  dwExtendedStyle   DD
  cdit              DW
  x                 DW
  y                 DW
  lx                DW
  ly                DW
DLGTEMPLATE ENDS

DLGITEMTEMPLATE STRUCT
  style DD
  dwExtendedStyle  DD
  x     DW
  y     DW
  lx    DW
  cy    DW
  id    DW
DLGITEMTEMPLATE ENDS

MDICREATESTRUCT STRUCT
  szClass   DD
  szTitle   DD
  hOwner    DD
  x         DD
  y         DD
  lx        DD
  ly        DD
  style     DD
  lParam    DD
MDICREATESTRUCT ENDS

HELPWININFO STRUCT
  wStructSize   DD
  x             DD
  y             DD
  lx            DD
  ly            DD
  wMax          DD
  rgchMember    DB 2 DUP 0
HELPWININFO ENDS

TBBUTTONINFO STRUCT
    cbSize      DD
    dwMask      DD
    idCommand   DD
    iImage      DD
    fsState     DB
    fsStyle     DB
    lx          DW
    lParam      DD
    pszText     DD
    cchText     DD
TBBUTTONINFO ENDS

IMAGELISTDRADWORDS STRUCT
  cbSize            DD
  himl              DD
  i                 DD
  hdcDst            DD
  x                 DD
  y                 DD
  _cx               DD
  cy                DD
  xBitmap           DD
  yBitmap           DD
  rgbBk             DD
  rgbFg             DD
  fStyle            DD
  dwRop             DD
IMAGELISTDRADWORDS ENDS

TVITEM STRUCT
	imask DD
	hItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	iSelectedImage DD
	cChildren DD
	lParam DD
ENDS

TVITEMEX STRUCT
	imask DD
	hItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	iSelectedImage DD
	cChildren DD
	lParam DD
	iIntegral DD
ENDS

TVINSERTSTRUCT STRUCT
	hParent DD
	hInsertAfter DD
	UNION
		itemex TVITEMEX
		item TVITEM
	ENDUNION
ENDS

LVITEM STRUCT
	imask DD
	iItem DD
	iSubItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	lParam DD
	iIndent DD
	iGroupId DD
	cColumns DD
	puColumns DD
ENDS

// This stub file replaces the Windows.inc file previously used
// for definitions. It can be copied over the old files (UNICODE and ANSI versions)
// to use the new headers with your projects without having to modify them

GOASM_ECHO This INC file is a temporary fix, to ensure compatibility
GOASM_ECHO use the full WINDOWS.H file and the header project

// NOTE: INCLUDE Environment variable must be set to headers path
// Kludge for symbol conflict
#DEFINE IDISPATCH_DEFINED
#DEFINE IUNKNOWN_DEFINED

#DEFINE LINKFILES
#DEFINE LINKVCRT
#DEFINE ODBC_STD
#DEFINE NORADASM
#DEFINE NOZLIB
#DEFINE NODONKEY
#DEFINE CCUSEORDINALS

#include "WINDOWS.H"
#include "Commctrl.h"
#include "macros.h"

#ENDIF