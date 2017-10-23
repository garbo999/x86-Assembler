#ifndef CUSTCNTL_H
#define CUSTCNTL_H

/* Custom Control Library definitions */

#define CCHCCCLASS  32
#define CCHCCDESC  32
#define CCHCCTEXT  256

#define CCF_NOTEXT  0x00000001

CCSTYLEA STRUCT
	flStyle DD
	flExtStyle DD
	szText DB CCHCCTEXT DUP (?)
	lgid DD
	wReserved1 DW
ENDS

CCSTYLEW STRUCT
	flStyle DD
	flExtStyle DD
	szText DW CCHCCTEXT DUP (?)
	lgid DD
	wReserved1 DW
ENDS

CCSTYLEFLAGA STRUCT
	flStyle DD
	flStyleMask DD
	pszStyle PTR
ENDS

CCSTYLEFLAGW STRUCT
	flStyle DD
	flStyleMask DD
	pszStyle PTR
ENDS

CCINFOA STRUCT
	szClass DB CCHCCCLASS DUP (?)
	flOptions DD
	szDesc DB CCHCCDESC DUP (?)
	cxDefault DD
	cyDefault DD
	flStyleDefault DD
	flExtStyleDefault DD
	flCtrlTypeMask DD
	szTextDefault DB CCHCCTEXT DUP (?)
	cStyleFlags DD
	aStyleFlags DD
	lpfnStyle PTR
	lpfnSizeToText PTR
	dwReserved1 DD
	dwReserved2 DD
ENDS

CCINFOW STRUCT
	szClass DW CCHCCCLASS DUP (?)
	flOptions DD
	szDesc DW CCHCCDESC DUP (?)
	cxDefault DD
	cyDefault DD
	flStyleDefault DD
	flExtStyleDefault DD
	flCtrlTypeMask DD
	szTextDefault DW CCHCCTEXT DUP (?)
	cStyleFlags DD
	aStyleFlags DD
	lpfnStyle PTR
	lpfnSizeToText PTR
	dwReserved1 DD
	dwReserved2 DD
ENDS

#IFDEF UNICODE
	#define CCSTYLE CCSTYLEW
	#define CCSTYLEFLAG CCSTYLEFLAGW
	#define CCINFO CCINFOW
#else
	#define CCSTYLE CCSTYLEA
	#define CCSTYLEFLAG CCSTYLEFLAGA
	#define CCINFO CCINFOA
#endif

#endif
