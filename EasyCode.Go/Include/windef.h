#ifndef WINDEF_H
#define WINDEF_H

#DEFINE WINDEF_H_REQVER 201

/* Windows Basic Type Definitions */

/*
Switches used
NT_EXCLUDED = do not include winnt.h
*/

/*
Dependancies
winnt.h
*/


// Note that this does not define the size of the type WORD
// rather it defines the word size of the processor, 32 or 64 bits
#IFDEF WIN64
	#DEFINE @ADDRESSWIDTH 64
#ELSE
	#DEFINE @ADDRESSWIDTH 32
#ENDIF

#IF STRINGS UNICODE
	#DEFINE @CHARSIZE 2
#ELSE
	#DEFINE @CHARSIZE 1
#ENDIF

// Windows version numbers
#define NTDDI_WINCE							0x02000000

#define NTDDI_WIN9X                         0x03000000
#define NTDDI_WIN9XALL                      0x0300FFFF

#define NTDDI_WINNT4                        0x04000000
#define NTDDI_WINNT4ALL                     0x0400FFFF

#define NTDDI_WIN2K                         0x05000000
#define NTDDI_WIN2KSP1                      0x05000100
#define NTDDI_WIN2KSP2                      0x05000200
#define NTDDI_WIN2KSP3                      0x05000300
#define NTDDI_WIN2KSP4                      0x05000400
#define NTDDI_WIN2KALL                      0x0500FFFF

#define NTDDI_WINXP                         0x05010000
#define NTDDI_WINXPSP1                      0x05010100
#define NTDDI_WINXPSP2                      0x05010200
#define NTDDI_WINXPSP3                      0x05010300
#define NTDDI_WINXPSP4                      0x05010400
#define NTDDI_WINXPALL                      0x0501FFFF

#define NTDDI_WS03                          0x05020000
#define NTDDI_WS03SP1                       0x05020100
#define NTDDI_WS03SP2                       0x05020200
#define NTDDI_WS03SP3                       0x05020300
#define NTDDI_WS03SP4                       0x05020400
#define NTDDI_WS03ALL                       0x0502FFFF

#define NTDDI_WIN6                          0x06000000
#define NTDDI_WIN6SP1                       0x06000100
#define NTDDI_WIN6SP2                       0x06000200
#define NTDDI_WIN6SP3                       0x06000300
#define NTDDI_WIN6SP4                       0x06000400
#define NTDDI_WIN6ALL                       0x0600FFFF

#define NTDDI_WIN7                          0x07000000
#define NTDDI_WIN7ALL                       0x0700FFFF

#define NTDDI_WIN8                          0x08000000
#define NTDDI_WIN8ALL                       0x0800FFFF

#define NTDDI_LONGHORN						NTDDI_WIN6
#define NTDDI_VISTA                         NTDDI_WIN6
#define NTDDI_VISTASP1                      NTDDI_WIN6SP1
#define NTDDI_VISTASP2                      NTDDI_WIN6SP2
#define NTDDI_VISTASP3                      NTDDI_WIN6SP3
#define NTDDI_VISTASP4                      NTDDI_WIN6SP4
#define NTDDI_VISTAALL                      NTDDI_WIN6ALL

#define NTDDI_WS08                          NTDDI_WIN6SP1
#define NTDDI_WS08SP2                       NTDDI_WIN6SP2
#define NTDDI_WS08SP3                       NTDDI_WIN6SP3
#define NTDDI_WS08SP4                       NTDDI_WIN6SP4
#define NTDDI_WS08ALL                       NTDDI_WIN6ALL

// These old defs are kept around for compatibility
// New applications should use the 3 digit versions
#define WIN32_IE_IE20                      0x0200
#define WIN32_IE_IE30                      0x0300
#define WIN32_IE_IE40                      0x0400
#define WIN32_IE_IE50                      0x0500
#define WIN32_IE_IE55                      0x0550
#define WIN32_IE_IE60                      0x0600
#define WIN32_IE_IE60SP1                   0x0601
#define WIN32_IE_IE60SP2                   0x0603
#define WIN32_IE_IE70                      0x0700
#define WIN32_IE_IE80                      0x0800
#define WIN32_IE_IE90                      0x0900
#define WIN32_IE_ALL                       0xFFFF

#define WIN32_IE_IE200                     0x0200
#define WIN32_IE_IE300                     0x0300
#define WIN32_IE_IE302                     0x0302
#define WIN32_IE_IE400                     0x0400
#define WIN32_IE_IE401                     0x0401
#define WIN32_IE_IE500                     0x0500
#define WIN32_IE_IE501                     0x0501
#define WIN32_IE_IE550                     0x0550
#define WIN32_IE_IE600                     0x0600
#define WIN32_IE_IE601                     0x0601 // IE 6 service pack 1
#define WIN32_IE_IE603                     0x0603 // IE 6 service pack 2
#define WIN32_IE_IE700                     0x0700
#define WIN32_IE_IE800                     0x0800
#define WIN32_IE_IE900                     0x0900

// These old defs are kept around for compatibility
// New applications should use the 3 digit versions
#define WIN32_SHELL_40                     0x0400
#define WIN32_SHELL_50                     0x0500
#define WIN32_SHELL_60                     0x0600
#define WIN32_SHELL_61                     0x0610

#define WIN32_SHELL_400                    0x0400
#define WIN32_SHELL_471                    0x0471
#define WIN32_SHELL_472                    0x0472
#define WIN32_SHELL_500                    0x0500
#define WIN32_SHELL_550                    0x0550
#define WIN32_SHELL_600                    0x0600
#define WIN32_SHELL_601                    0x0601
#define WIN32_SHELL_610                    0x0610
#define WIN32_SHELL_ALL                    0xFFFF

#define WIN32_COMMCTRL_400                 0x0400 // Windows 95 + IE 3.00
#define WIN32_COMMCTRL_470                 0x0470 // Windows 95 OSR2  Windows NT 4.0 + IE 3.01, 3.02
#define WIN32_COMMCTRL_471                 0x0471 // IE 4.0
#define WIN32_COMMCTRL_472                 0x0472 // Windows 98  late NT 4.0 service packs  + IE 4.01
#define WIN32_COMMCTRL_580                 0x0580 // Windows 98 SE + IE 5.0 (Use also for XP)
#define WIN32_COMMCTRL_581                 0x0581 // Windows Me  Windows 2000 + IE 5.01, 5.5, 6.0 
#define WIN32_COMMCTRL_582                 0x0582 // Windows XP, Windows Server 2003, Windows Vista
#define WIN32_COMMCTRL_600                 0x0600 // Windows XP (SxS), Windows Server 2003 (SxS)
#define WIN32_COMMCTRL_601                 0x0601 // Windows XP (SxS), Windows Server 2003 (SxS)
#define WIN32_COMMCTRL_610                 0x0610 // Windows 7
#define WIN32_COMMCTRL_ALL                 0xFFFF

#define WIN32_SHLWAPI_400                  0x0400
#define WIN32_SHLWAPI_470                  0x0470
#define WIN32_SHLWAPI_471                  0x0471
#define WIN32_SHLWAPI_500                  0x0500
#define WIN32_SHLWAPI_600                  0x0600
#define WIN32_SHLWAPI_610                  0x0610
#define WIN32_SHLWAPI_ALL                  0xFFFF

#define WIN32_USER_400                     0x0400
#define WIN32_USER_410                     0x0410
#define WIN32_USER_500                     0x0500
#define WIN32_USER_510                     0x0510
#define WIN32_USER_600                     0x0600
#define WIN32_USER_610                     0x0610
#define WIN32_USER_ALL                     0xFFFF

#define WIN32_GDI_400                      0x0400
#define WIN32_GDI_410                      0x0410
#define WIN32_GDI_500                      0x0500
#define WIN32_GDI_510                      0x0510
#define WIN32_GDI_600                      0x0600
#define WIN32_GDI_610                      0x0610
#define WIN32_GDI_ALL                      0xFFFF

#define WIN32_KERNEL_400                   0x0400
#define WIN32_KERNEL_470                   0x0470
#define WIN32_KERNEL_471                   0x0471
#define WIN32_KERNEL_500                   0x0500
#define WIN32_KERNEL_510                   0x0510
#define WIN32_KERNEL_520                   0x0520
#define WIN32_KERNEL_600                   0x0600
#define WIN32_KERNEL_610                   0x0610
#define WIN32_KERNEL_ALL                   0xFFFF

#define WIN32_GDIP_100                     0x0100
#define WIN32_GDIP_110                     0x0110
#define WIN32_GDIP_ALL                     0xFFFF

#define WIN32_ADVAPI_500                   0x0500
#define WIN32_ADVAPI_510                   0x0510
#define WIN32_ADVAPI_520                   0x0520
#define WIN32_ADVAPI_600                   0x0600
#define WIN32_ADVAPI_610                   0x0610
#define WIN32_ADVAPI_ALL                   0xFFFF

#define WINNT_NTDLL_400                    0x0400 // Windows NT4 (not versioned)
#define WINNT_NTDLL_500                    0x0500 // Windows 2000
#define WINNT_NTDLL_510                    0x0510 // Windows XP
#define WINNT_NTDLL_520                    0x0520 // Windows Server 2003
#define WINNT_NTDLL_600                    0x0600 // Windows Vista
#define WINNT_NTDLL_610                    0x0610 // Windows 7
#define WINNT_NTDLL_ALL                    0xFFFF

/*
Old definitions for windows versions. These have been replaced by the NTDDI defs 
#define _WIN32_WINNT_NT4                    0x0400
#define _WIN32_WINNT_WIN2K                  0x0500
#define _WIN32_WINNT_WINXP                  0x0501
#define _WIN32_WINNT_WS03                   0x0502
#define _WIN32_WINNT_WIN6                   0x0600
#define _WIN32_WINNT_VISTA                  0x0600
#define _WIN32_WINNT_WS08                   0x0600
#define _WIN32_WINNT_LONGHORN               0x0600
*/

#define OSVERSION_MASK      0xFFFF0000
#define SPVERSION_MASK      0x0000FF00
#define SUBVERSION_MASK     0x000000FF

#define MAX_PATH  260

// The SCHAR type is only meant to be used in the initialized data section
// for locals and unitialized data use TCHAR or %TCHAR instead
#IF STRINGS UNICODE
	#DEFINE SCHAR DUS
#ELSE
	#DEFINE SCHAR DB
#ENDIF

#DEFINE ATOM DW
#DEFINE BOOL DD
#DEFINE BOOLEAN DB
#DEFINE CHAR DB
#DEFINE COLORREF DD
#DEFINE DWORDLONG DQ
#DEFINE DWORD32 DD
#DEFINE DWORD64 DQ
#DEFINE ENUM DD
#DEFINE LRESULT DD
#DEFINE INT32 DD
#DEFINE INT64 DQ
#DEFINE LANGID DW
#DEFINE LCID DD
#DEFINE LCTYPE DD
#DEFINE LGRPID DD
#DEFINE LONG DD
#DEFINE LONGLONG DQ
#DEFINE LONG32 DD
#DEFINE LONG64 DQ
#DEFINE SHORT DW
#DEFINE USN DQ
#DEFINE WCHAR DW
#DEFINE FLOAT DD
#DEFINE DOUBLE DQ
#DEFINE FXPT2DOT30 DD
#DEFINE VARTYPE DW

// Defined for the VARIANT structure
#DEFINE VARIANT_BOOL DW
#DEFINE DATE DQ

#IFDEF WIN64
	#DEFINE INT_PTR DQ
	#DEFINE UINT_PTR DQ
	#DEFINE LONG_PTR DQ
	#DEFINE ULONG_PTR DQ
	#DEFINE DWORD_PTR DQ
	#DEFINE HALF_PTR DD
	#DEFINE SIZE_T DQ
	#DEFINE HANDLE DQ
	#DEFINE LPARAM DQ
	#DEFINE WPARAM DQ
	#DEFINE PTR DQ
#ELSE
	#DEFINE INT_PTR DD
	#DEFINE UINT_PTR DD
	#DEFINE LONG_PTR DD
	#DEFINE ULONG_PTR DD
	#DEFINE DWORD_PTR DD
	#DEFINE HALF_PTR DW
	#DEFINE SIZE_T DD
	#DEFINE HANDLE DD
	#DEFINE LPARAM DD
	#DEFINE WPARAM DD
	#DEFINE PTR DD
#ENDIF

#IF STRINGS UNICODE
	#DEFINE TBYTE DW
	#DEFINE TCHAR DW
#ELSE
	#DEFINE TBYTE DB
	#DEFINE TCHAR DB
#ENDIF

%ATOM STRUCT
	DW
ENDS

%BOOL STRUCT
	DD
ENDS

%BOOLEAN STRUCT
	DB
ENDS

%CHAR STRUCT
	DB
ENDS

%COLORREF STRUCT
	DD
ENDS

%DWORDLONG STRUCT
	DQ
ENDS

%DWORD32 STRUCT
	DD
ENDS

%DWORD64 STRUCT
	DQ
ENDS

%LRESULT STRUCT
	DD
ENDS

%FLOAT STRUCT
	DD
ENDS

%DOUBLE STRUCT
	DQ
ENDS

%FXPT2DOT30 STRUCT
	DD
ENDS

%INT32 STRUCT
	DD
ENDS

%INT64 STRUCT
	DQ
ENDS

%LANGID STRUCT
	DW
ENDS

%LCID STRUCT
	DD
ENDS

%LCTYPE STRUCT
	DD
ENDS

%LGRPID STRUCT
	DD
ENDS

%LONG STRUCT
	DD
ENDS

%LONGLONG STRUCT
	DQ
ENDS

%LONG32 STRUCT
	DD
ENDS

%LONG64 STRUCT
	DQ
ENDS

%SHORT STRUCT
	DW
ENDS

%USN STRUCT
	DQ
ENDS

%WCHAR STRUCT
	DW
ENDS

%VARTYPE STRUCT
	DW
ENDS

%VARIANT_BOOL STRUCT
	DW
ENDS

%DATE STRUCT
	DQ
ENDS

#IFDEF WIN64
	%INT_PTR STRUCT
		DQ
	ENDS
	%UINT_PTR STRUCT
		DQ
	ENDS
	%LONG_PTR STRUCT
		DQ
	ENDS
	%ULONG_PTR STRUCT
		DQ
	ENDS
	%DWORD_PTR STRUCT
		DQ
	ENDS
	%HALF_PTR STRUCT
		DD
	ENDS
	%SIZE_T STRUCT
		DQ
	ENDS
	%LPARAM STRUCT
		DQ
	ENDS
	%WPARAM STRUCT
		DQ
	ENDS
	%HANDLE STRUCT
		DQ
	ENDS
	%PTR STRUCT
		DQ
	ENDS
#ELSE
	%INT_PTR STRUCT
		DD
	ENDS
	%UINT_PTR STRUCT
		DD
	ENDS
	%LONG_PTR STRUCT
		DD
	ENDS
	%ULONG_PTR STRUCT
		DD
	ENDS
	%DWORD_PTR STRUCT
		DD
	ENDS
	%HALF_PTR STRUCT
		DW
	ENDS
	%SIZE_T STRUCT
		DD
	ENDS
	%LPARAM STRUCT
		DD
	ENDS
	%WPARAM STRUCT
		DD
	ENDS
	%HANDLE STRUCT
		DD
	ENDS
	%PTR STRUCT
		DD
	ENDS
#ENDIF

#IFDEF UNICODE
	%TBYTE STRUCT
		DW
	ENDS
	%TCHAR STRUCT
		DW
	ENDS
#ELSE
	%TBYTE STRUCT
		DB
	ENDS
	%TCHAR STRUCT
		DB
	ENDS
#ENDIF

#ifndef NULL
#define NULL  0
#endif

#ifndef FALSE
#define FALSE  0
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef NT_EXCLUDED
	#IFNDEF WINNT_H
		#include winnt.h // WIN3264 - VISTA
	#ENDIF
#endif

#define HFILE_ERROR -1

STRING STRUCT
	Length SHORT
	MaximumLength SHORT
	Buffer PTR
ENDS

UNICODE_STRING STRUCT
	Length DW
	MaximumLength DW
	Buffer PTR
ENDS

#IFNDEF RECT
	RECT STRUCT
		left DD
		top DD
		right DD
		bottom DD
	ENDS
#ENDIF

#IFNDEF RECTL
	RECTL = RECT
#ENDIF

#IFNDEF POINT
	POINT STRUCT
		x DD
		y DD
	ENDS
#ENDIF

#IFNDEF POINTL
	POINTL STRUCT
		x DD
		y DD
	ENDS
#ENDIF

#IFNDEF SIZE
	SIZE STRUCT
		cx DD
		cy DD
	ENDS
#ENDIF

#IFNDEF SIZEL
	SIZEL STRUCT
		cx DD
		cy DD
	ENDS
#ENDIF

#IFNDEF POINTS
	POINTS STRUCT
		x DW
		y DW
	ENDS
#ENDIF

#define DM_UPDATE  1
#define DM_COPY  2
#define DM_PROMPT  4
#define DM_MODIFY  8

#define DM_IN_BUFFER  DM_MODIFY
#define DM_IN_PROMPT  DM_PROMPT
#define DM_OUT_BUFFER  DM_COPY
#define DM_OUT_DEFAULT  DM_UPDATE

#define DC_FIELDS  1
#define DC_PAPERS  2
#define DC_PAPERSIZE  3
#define DC_MINEXTENT  4
#define DC_MAXEXTENT  5
#define DC_BINS  6
#define DC_DUPLEX  7
#define DC_SIZE  8
#define DC_EXTRA  9
#define DC_VERSION  10
#define DC_DRIVER  11
#define DC_BINNAMES  12
#define DC_ENUMRESOLUTIONS  13
#define DC_FILEDEPENDENCIES  14
#define DC_TRUETYPE  15
#define DC_PAPERNAMES  16
#define DC_ORIENTATION  17
#define DC_COPIES  18

#define GUID_NULL <0,0,0,<0,0,0,0,0,0,0,0>>

#endif

