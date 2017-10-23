#IFNDEF HTMLLITE_H
#define HTMLLITE_H

#IFDEF LINKFILES
	#dynamiclinkfile htmllite.dll
#ENDIF

#define WC_HTMLLITEA "HTMLLITE"
#define WC_HTMLLITEW L"HTMLLITE"

#IFDEF HTMLLITE_USEVSDLL
	// The visual studio version of the DLL uses decorated names
	// while others use undecorated names. In order to use the DLL
	// with VS you must define the HTMLLITE_USEVSDLL switch

	#define FRegisterHtmlLiteClass _FRegisterHtmlLiteClass@4
	#define FUnregisterHtmlLiteClas _FUnregisterHtmlLiteClass@4

	#define CchHtmlBreakLinesA _CchHtmlBreakLinesA@12
	#define CchHtmlBreakLinesW _CchHtmlBreakLinesW@12

	#define CchHtmlExcapeTextA _CchHtmlExcapeTextA@16
	#define CchHtmlExcapeTextW _CchHtmlExcapeTextW@16
	#define FHtmlReplaceCtl _FHtmlReplaceCtl@8
#ENDIF

#IFDEF UNICODE
	#define CchHtmlBreakLines CchHtmlBreakLinesW
	#define CchHtmlExcapeTex CchHtmlExcapeTexW
	#define WC_HTMLLITE WC_HTMLLITEW
#ELSE
	#define CchHtmlBreakLines CchHtmlBreakLinesA
	#define CchHtmlExcapeTex CchHtmlExcapeTexA
	#define WC_HTMLLITE WC_HTMLLITEA
#ENDIF

#define HTMLLITE_CODE_LEFTCLICK    1000 
#define HTMLLITE_CODE_TABCYCLE  1001 
#define HTMLLITE_CODE_RIGHTCLICK   1003 
#define HTMLLITE_CODE_MOUSEOVER    1004 
#define HTMLLITE_CODE_MOUSEHOVER   1005 
#define HTMLLITE_CODE_MOUSEEXIT    1006 

NMHTMLLITE struct
	hwndFrom HANDLE
	idFrom DD
	code DD
	linkid DD 
	linkrc RECT
ENDS

#ENDIF