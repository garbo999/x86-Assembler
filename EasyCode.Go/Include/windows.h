/* About
*********************************************************************************
GOASM HEADER FILES

Note this project is neither endorsed nor supported by GoTools, Jeremy Gordon or
MrDuck software. Address all support inquiries to the GoAsm forum or

donkey.asm@gmail.com

Translated from PSDK headers by Edgar Hansen (Donkey) et al
Thanks to...
Jeremy Gordon (jorgon)
Wayne J Radburn (wjr)
Bryant Keller (Synfire)
Bill Cravener (Cycle Saddles)
Ramon Sala (rsala)
jj2007
Mark Jones
E^cube
Yuri
BlackVortex
Rob Chandler (Microsoft Help MVP)
Pat Styles (Microsoft Corp. Help with license issues)

NOTE: The syntax of these files is not compatible with MASM
********************************************************************************* 
*/

#IFNDEF WINDOWS_H
#define WINDOWS_H

// Copyright notices for various header files. All or parts of these files may
// be subject to the following copyrights.

//--------------------------------------------------------------------
//
// GoAsm is Copyright © Jeremy Gordon 2001-2010 [MrDuck Software] - all rights reserved.
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1993-2009.
//  http://www.microsoft.com/about/legal/permissions/default.mspx
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//
// Pelle C headers
// © pelle orinius 2003-2008
// http://www.christian-heffner.de/
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//
// zlib.h -- interface of the 'zlib' general purpose compression library
// version 1.2.3, July 18th, 2005
//
// Copyright (C) 1995-2005 Jean-loup Gailly and Mark Adler
// http://www.zlib.net/
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//
// RadASM© Win32 assembly IDE
// RadASM (C) KetilO 2001-2007
// Ketil Olsen
// http://www.radasm.com/
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//
// Scintilla source code edit control Version 222
//
// Copyright 1998-2003 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.
//
//--------------------------------------------------------------------

/* Windows API master include file */

/* IMPORTANT !!!!!
**********************************************************************************
IMPORTANT !!!!!

You must create an INCLUDE environment variable with the path to these header files
See "Include files - using #include and INCBIN" in the GoAsm manual for details
***********************************************************************************
*/

/* Switches ****CHANGED IN VERSION 2.0.0

WIN32_LEAN_AND_MEAN = Include minimal set of X86 common definitions only
WIN64_LEAN_AND_MEAN = Include minimal set of X64 common definitions only
NOCRYPT = Do not include Windows Cryptographic API definitions
NOSERVICE = Do not include Windows Service Control Manager definitions
NONETWORK = Do not include Windows Network definitions
NOVER = Do not include Windows version management definitions
NOMCX = Do not include Windows MCX API definitions
NOIME = Do not include Windows Input Method Manager definitions
NOTV = Do not include Windows TV definitions
NOREG = Do not include Windows Registry API definitions
NONLS = Do not include Windows NLS component definitions
NOCON = Do not include Windows Console subsystem definitions
NOGDI = Do not include Windows GDI Module definitions
NOUSER = Do not include Windows User Module definitions
NOOLE = Do not include Windows Linking and Embedding API definitions
NOCARD = Do not include Windows SmartCard Subsystem definitions
NOGDIPLUS = Do not include GDI Plus definitions

**** Additions in version 2.1.05

FILTERAPI = Enables API version filtering
WINVER = The NTDDI constant for the target Windows OS version (see windef.h)
SHELLVER = The WIN32_SHELL version number of Shell32.dll (see windef.h)
COMMCTRLVER = The WIN32_COMMCTRL version number of ComCtl32.dll (see windef.h)
SHLWAPIVER = The WIN32_SHLWAPI version number of shwapi.dll (see windef.h)
KERNELVER = The WIN32_KERNEL version number of kernel32.dll (see windef.h)
GDIPVER = The WIN32_GDIP version number of gdiplus.dll (see windef.h)

**** Additions in version 2.1.12

NTDLLVER = The WINNT_NTDLL version number of ntdll.dll (see windef.h)
USERVER = The WIN32_USER version number of User32.dll (see windef.h)
ADVAPIVER = The WIN32_ADVAPI version number of Advapi32.dll (see windef.h)

************* IMPORTANT THESE 2 SWITCHES ARE MUTUALLY EXCLUSIVE !!!
AMD64 = Use AMD64/ X86-64 internal structures (ie CONTEXT)
IA64 = Use IA64 / Xeon internal structures (ie CONTEXT)

Link switches
LINKFILES = If defined passes the name of the appropriate DLL to GoLink at compile time
LINKVCRT = Adds msvcrt.dll to the list of DLLs searched for a function
C99HDRS = If defined includes the C99 headers, must be used with LINKVCRT

X86USEUNDOC - Use undocumented opcodes
*/

/*
This has changed in version 0x021007

IDISPATCH_DEFINED
IUNKNOWN_DEFINED

You no longer must define these two switches in order to avoid
symbol conflicts in COM interfaces. They are defined in windows.h
and the definition can be overridden by the USE_IUNKNOWN switch.
If you do not define them the syntax for COM interfaces changes for
IUnknown and IDispatch implementations of all COM interfaces:

******************
With USE_IUNKNOWN only the following is valid

IInterface.QueryInterface

When setting up your vTable use the following syntax to fill
the IDispatch structure:

vtable IDispatch <<1,2,3>,<4,5,6,7>>

******************
Without USE_IUNKNOWN both of the following are valid (default)

IInterface.IUnknown.QueryInterface
IInterface.QueryInterface

the USE_IUNKNOWN switch will enable the definition of the IUnknown and IDispatch
interfaces. These are needed for COM servers in order to build vtables. They are
not available if the switch is not used. This was done in order to avoid symbol
conflicts and still keep both syntaxes.
*/

/* NOTE about npptypes.h ****CHANGED IN VERSION 2.0.0

There are conflicts within this header file that have been resolved as follows
ADDRESS structure conflicts with the ADDRESS structure and has been renamed NPP_ADDRESS
ADDRESS_SIZE has been renamed NPP_ADDRESS_SIZE
FRAME structure conflicts with a GoAsm keyword and has been renamed NPP_FRAME
FRAME_SIZE has been renamed NPP_FRAME_SIZE

NOTE about winternl.h ****CHANGED IN VERSION 2.0.0
All structures in this header may conflict with others. If you need to use another
definition for a particular structure you must include it before this file. For
example:

PEB STRUCT
...
ENDS
#include winternl.h

*/

/* Compatibility note

Starting at version 013000 the GUID structure has been redefined.

Though it is not compulsory new guids should be defined as follows
#define GUID_CLSID_Registrar <0x44EC053A,0x400F,0x11D0,0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3>
changes to:
#define GUID_CLSID_Registrar <0x44EC053A,0x400F,0x11D0,<0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3>>
Note that the last 8 bytes are now in nested brackets.

The GUID structure should now be defined as follows in all code to ensure compatability with the headers

GUID STRUCT
		Data1	dd
		Data2	dw
		Data3	dw
		Data4	db 8 DUP
ENDS

**** Note that as of version 2.0.0 this definition has become compulsory, the
older version of the structure is no longer supported

*/

/* VERSION 2.0.0 and above Unicode compatibility note
Starting with 2.0.0 the STRINGS UNICODE and UNICODE
switches have been separated. STRINGS UNICODE will
no longer load the unicode versions of the api it
will only direct GoAsm to convert quoted strings to
unicode, Jeremy's original intention. The UNICODE
switch is now used to load the unicode versions of
api calls, this was done to keep in step with the 
GoAsm manual.

Programs should now use the /d UNICODE switch on
the GoAsm command line or #DEFINE UNICODE before
Windows.h is included.
*/

// Note : DbgHelp.h / ImgHelp.h files
// Use ImgHelp.h instead, it has all the same definitions unless you
// require the MINIDUMP definitions then use DbgHelp.h. These 2 files
// are mutually exclusive, though it will not break code to include
// both it will generate a lot of duplicate symbols.

/* Version 0x020012

The NMHDR structure has been changed to:

NMHDR STRUCT
	hwndFrom HANDLE
	idFrom UINT_PTR
	code DD
ENDS

This should be transparent to any current code
*/

/* fileextd.h change version 2.1.09
The variable FILEEXTLIB has been added to identify the location of
the Win32 FileID API Library. You can set it to a unique location
if you do not wish to have to include fileextd.lib in your build
folder.
*/

/* macros.a has been deprecated.
Macros.a has been replaced with macros.h starting in version 0x021009
the file macros.a has been turned into a simple stub in order to keep
backward compatibility. However it will be removed eventually and existing
code will have to be modified.

Note as of version 0x021016 this file has been removed from the distribution
*/

/* API_Filter version 021027
This header will function as it always has however the error messages
returned now have spaces instead of underscores. This was done to improve
readability.
*/

GOASMHDRVER = 0x02102E

#IFNDEF WINVER
	// The OS version must be defined before windows.h is
	// included, subsequent definitions will be ignored.
	// The default OS version is XP - no service pack
	#DEFINE WINVER NTDDI_WINXP
#ENDIF

/* Note for version 0x021000
Begining with this version certain core libraries
versions are more accurately targeted based on OS version. 
The following define only the versions commonly found
for the OS version specified. If you wish to change the
target versions define a different one before including
windows.h
*/

// windef.h is a minimum required include

#IFNDEF WINDEF_H
	#include "windef.h" ; Windows basic type definitions - WIN32/64
#ENDIF

#IFNDEF SHELLVER
	#IF WINVER < NTDDI_WIN9XALL
		// Note there is no distinction made between 9x versions
		#DEFINE SHELLVER WIN32_SHELL_472
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE SHELLVER WIN32_SHELL_500
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE SHELLVER WIN32_SHELL_600
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE SHELLVER WIN32_SHELL_601
	#ELSE // WIN7
		#DEFINE SHELLVER WIN32_SHELL_610
	#ENDIF
#ENDIF

#IFNDEF GDIVER
	#IF WINVER < NTDDI_WIN9XALL
		#DEFINE GDIVER WIN32_GDI_410
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE GDIVER WIN32_GDI_500
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE GDIVER WIN32_GDI_510
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE GDIVER WIN32_GDI_600
	#ELSE // WIN7
		#DEFINE GDIVER WIN32_GDI_610
	#ENDIF
#ENDIF

#IFNDEF USERVER
	#IF WINVER < NTDDI_WIN9XALL
		// Note there is no distinction made between 9x versions
		#DEFINE USERVER WIN32_USER_410
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE USERVER WIN32_USER_500
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE USERVER WIN32_USER_510
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE USERVER WIN32_USER_600
	#ELSE // WIN7
		#DEFINE USERVER WIN32_USER_610
	#ENDIF
#ENDIF

#IFNDEF NTDLLVER
	#IF WINVER < NTDDI_WIN9XALL
		// Not available for Win9x
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE NTDLLVER WINNT_NTDLL_500
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE NTDLLVER WINNT_NTDLL_510
	#ELSEIF WINVER < NTDDI_WS03ALL
		#DEFINE NTDLLVER WINNT_NTDLL_520
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE NTDLLVER WINNT_NTDLL_600
	#ELSE // WIN7
		#DEFINE NTDLLVER WINNT_NTDLL_610
	#ENDIF
#ENDIF

#IFNDEF ADVAPIVER
	#IF WINVER < NTDDI_WIN9XALL
		// Not available for Win9x
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE ADVAPIVER WIN32_ADVAPI_500
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE ADVAPIVER WIN32_ADVAPI_510
	#ELSEIF WINVER < NTDDI_WS03ALL
		#DEFINE ADVAPIVER WIN32_ADVAPI_520
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE ADVAPIVER WIN32_ADVAPI_600
	#ELSE // WIN7
		#DEFINE ADVAPIVER WIN32_ADVAPI_610
	#ENDIF
#ENDIF

#IFNDEF COMMCTRLVER
	// Common controls above 5.82 require side by side (SxS) assemblies
	// The versions are limited since v6+ is redistributable to all
	// Windows above WinXP but require a manifest to use. To enable
	// higher versions set COMMCTRLVER explicitly before including
	// Windows.h
	#IF WINVER < NTDDI_WIN9XALL
		#DEFINE COMMCTRLVER WIN32_COMMCTRL_472
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE COMMCTRLVER WIN32_COMMCTRL_580
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE COMMCTRLVER WIN32_COMMCTRL_582
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE COMMCTRLVER WIN32_COMMCTRL_582
	#ELSE // WIN7
		#DEFINE COMMCTRLVER WIN32_COMMCTRL_582
	#ENDIF
#ENDIF

#IFNDEF SHLWAPIVER
	#IF WINVER < NTDDI_WIN9XALL
		#DEFINE SHLWAPIVER WIN32_SHLWAPI_471
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE SHLWAPIVER WIN32_SHLWAPI_500
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE SHLWAPIVER WIN32_SHLWAPI_600
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE SHLWAPIVER WIN32_SHLWAPI_610
	#ELSE // WIN7
		#DEFINE SHLWAPIVER WIN32_SHLWAPI_610
	#ENDIF
#ENDIF

#IFNDEF KERNELVER
	#IF WINVER < NTDDI_WIN9XALL
		#DEFINE KERNELVER WIN32_KERNEL_471
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE KERNELVER WIN32_KERNEL_500
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE KERNELVER WIN32_KERNEL_510
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE KERNELVER WIN32_KERNEL_600
	#ELSE // WIN7
		#DEFINE KERNELVER WIN32_KERNEL_610
	#ENDIF
#ENDIF

/*
The GDI+ version numbers do not match the version
numbers reported by the DLL. The version numbers
supported by Microsoft are used (at the time of
this writing 1.0 or 1.1). The DLL will report
5.x for 1.0 and 6.x for 1.1
*/

#IFNDEF GDIPVER
	#IF WINVER < NTDDI_WIN9XALL
		#DEFINE GDIPVER WIN32_GDIP_100
	#ELSEIF WINVER < NTDDI_WIN2KALL
		#DEFINE GDIPVER WIN32_GDIP_100
	#ELSEIF WINVER < NTDDI_WINXPALL
		#DEFINE GDIPVER WIN32_GDIP_100
	// Note that the following require SxS assembly
	// Use WIN32_GDIP_100 if you do not want to
	// include a manifest file
	#ELSEIF WINVER < NTDDI_WIN6ALL
		#DEFINE GDIPVER WIN32_GDIP_110
	#ELSE // WIN7
		#DEFINE GDIPVER WIN32_GDIP_110
	#ENDIF
#ENDIF

#IFDEF FILTERAPI
	#include "API_Filter.h"
#ENDIF

// winbase.h is a minimum required include

#IFNDEF WINBASE_H
	#include "winbase.h" ; Windows core definitions - WIN32/64
#ENDIF

#IFDEF AMD64
	// These switches are incompatible
	#undef IA64
#ENDIF

#IFDEF X86USEUNDOC
	// Submitted by Synfire
	#DEFINE	salc DB 0D6h	; Set AL based on Carry Flag
	#DEFINE	SALC salc
	#DEFINE icebp	DB F1h
	#DEFINE ICEBP icebp
#ENDIF

#IFDEF WIN32_LEAN_AND_MEAN
	#UNDEF WIN64
	#DEFINE WIN_LEAN_AND_MEAN
#ENDIF

#IFDEF WIN64_LEAN_AND_MEAN
	#DEFINE WIN64
	#IFNDEF IA64
		#DEFINE AMD64
	#ENDIF
	#DEFINE WIN_LEAN_AND_MEAN
#ENDIF

// The required version of windef.h is 201 or greater
#IF WINDEF_H_REQVER < 201
	GOASM_ECHO ********* Headers Fatal Error
	GOASM_ECHO windef.h version is incompatible
	GOASM_EXIT
#ENDIF

#IFDEF USE_IUNKNOWN
	#IFDEF IDISPATCH_DEFINED
		GOASM_ECHO ********* Headers Warning
		GOASM_ECHO IDISPATCH_DEFINED and USE_IUNKNOWN are mutually exclusive
		GOASM_ECHO *********
	#ENDIF
	#IFDEF IUNKNOWN_DEFINED
		GOASM_ECHO ********* Headers Warning
		GOASM_ECHO IUNKNOWN_DEFINED and USE_IUNKNOWN are mutually exclusive
		GOASM_ECHO *********
	#ENDIF
#ENDIF

// Kludge for symbol conflicts
#IFNDEF USE_IUNKNOWN
	#DEFINE IDISPATCH_DEFINED
	#DEFINE IUNKNOWN_DEFINED
#ENDIF

#IFNDEF BASECOM_H
	// Required for all COM header files
	#include "BaseCOM.h"
#ENDIF

// ****CHANGED IN VERSION 2.0.0
// The winternl.h file is highly specialized
// it is not for general use. Verify that it
// matches your criteria before using it. Do not
// use it in conjunction with any other low level
// header files or with WinNT.h. To use it include
// it *before* including WINDOWS.H. Including this
// file will block winnt.h, imagehlp.h, dbghelp.h
// and psapi.h from loading.

// This line will prevent it from loading even if
// it is later explicitly included.
#DEFINE WINTERNL_H

#IF WINVER < NTDDI_WINXP
	#IFDEF WIN64
		GOASM_ECHO ********* Headers Warning
		GOASM_ECHO WIN64 not supported on this OS version
		GOASM_ECHO *********
	#ENDIF
#ENDIF

// This is just in case you are including a header that
// employs NTDDI_VERSION instead of WINVER
#IFNDEF NTDDI_VERSION
	#define NTDDI_VERSION WINVER
#ENDIF

#IFDEF LINKVCRT
	#IFDEF C99HDRS
		#include C99\stdarg.h
		#include C99\stdbool.h
		#include C99\stddef.h
		#include C99\stdint.h
		#include C99\stdio.h
		#include C99\stdlib.h
		#include C99\ctype.h
		#include C99\errno.h
		#include C99\excpt.h
		#include C99\fcntl.h
		#include C99\fenv.h
		#include C99\float.h
		#include C99\inttypes.h
		#include C99\io.h
		#include C99\limits.h
		#include C99\locale.h
		#include C99\math.h
		#include C99\process.h
		#include C99\signal.h
		#include C99\time.h
		#include C99\wizard.h
	#ENDIF

	#IFDEF LINKFILES
		#dynamiclinkfile msvcrt.dll
	#ENDIF
#ENDIF

#IFNDEF INCLUDEALL

#IFNDEF NOUSER
	#include "winuser.h" ; Windows User Module definitions - WIN32/64 VISTA
#ENDIF

#IFNDEF NOGDI
	#include wingdi.h ; Windows GDI Module definitions - WIN32/64
#ENDIF

#IFNDEF NOGDIPLUS
	#include GDIPlus\gdiplus.h ; Windows GDI+ Module definitions - WIN32/64
#ENDIF

#IFNDEF NOCON
	#include wincon.h ; Windows Console subsystem definitions - WIN32/64
#ENDIF

#IFNDEF NONLS
	#include winnls.h ; Windows NLS component definitions - WIN32/64
#ENDIF

#IFNDEF NOREG
	#include winreg.h ; Windows Registry API definitions - WIN32/64
#ENDIF

#IFNDEF NOVER
	#include winver.h ; Windows version management definitions - WIN32/64
#ENDIF

#IFNDEF WIN_LEAN_AND_MEAN
	#IFNDEF CDERR_H
		#include cderr.h ; Windows Common dialog errors - WIN32/64
	#ENDIF
	#IFNDEF DDE_H
		#include dde.h ; Windows Dynamic Data Exchange definitions - WIN32/64
	#ENDIF
	#IFNDEF DDEML_H
		#include ddeml.h ; Windows DDEML API definitions - WIN32/64
	#ENDIF
	#IFNDEF DLGS_H
		#include dlgs.h ; Windows UI dialog definitions - WIN32/64
	#ENDIF
	#IFNDEF LZEXPAND_H
		#include lzexpand.h ; Data decompression library definitions - WIN32/64
	#ENDIF
	#IFNDEF MMSYSTEM_H
		#include mmsystem.h ; Windows Multimedia API definitions - WIN32/64
	#ENDIF
	#IFNDEF NB30_H
		#include nb30.h ; Portable NetBIOS 3.0 definitions - WIN32/64
	#ENDIF
	#IFNDEF RPC_H
		#include rpc.h ; Windows RPC definitions - WIN32/64
	#ENDIF
	#IFNDEF SHELLAPI_H
		#include shellapi.h ; Windows Shell API definitions - WIN32/64
	#ENDIF
	#IFNDEF WINPERF_H
		#include winperf.h ; Windows Performance Monitor data definitions - WIN32/64
	#ENDIF

	#IFNDEF NONETWORK
		#IFNDEF WINNETWK_H
			#include winnetwk.h ; Windows Network definitions - WIN32/64
		#ENDIF
	#ENDIF

	#IFNDEF NOTV
		#IFNDEF TVOUT_H
			#include tvout.h ; Windows TV definitions - WIN32/64
		#ENDIF
	#ENDIF

	#IF WINVER > NTDDI_WIN9X
		#include winsock2.h ; Windows WinSock 2 API definitions - WIN32/64
		#include mswsock.h ; Microsoft extensions to Windows Sockets API - WIN32/64
	#ELSE
		#include winsock.h ; Windows WinSock API definitions - WIN32/64
	#ENDIF

	#IFNDEF NOCRYPT
		#IFNDEF WINCRYPT_H
			#include wincrypt.h ; Windows Cryptographic API definitions - WIN32/64
		#ENDIF
		#IFNDEF WINEFS_H
			#include winefs.h ; Windows File Encryption definitions - WIN32/64
		#ENDIF
	#ENDIF

	#IFNDEF NOCARD
		#IFNDEF WINSCARD_H
			#include winscard.h ; Windows SmartCard Subsystem definitions - WIN32/64
		#ENDIF
	#ENDIF

	#IFNDEF WINSPOOL_H
		#include winspool.h ; Windows Print API definitions - WIN32/64
	#ENDIF

	#IFNDEF COMMDLG_H
		#include commdlg.h ; Windows Common Dialog API definitions - WIN32/64
	#ENDIF

	#IFNDEF NOOLE
		#IFNDEF OLE2_H
			#include ole2.h ; Windows Linking and Embedding API definitions - WIN32/64
		#ENDIF
	#ENDIF

	#IFNDEF NOSERVICE
		#IFNDEF WINSVC_H
			#include winsvc.h ; Windows Service Control Manager definitions - WIN32/64
		#ENDIF
	#ENDIF

	#IFNDEF NOMCX
		#IFNDEF MCX_H
			#include mcx.h ; Windows MCX API definitions - WIN32/64
		#ENDIF
	#ENDIF

	#IFNDEF NOIME
		#IFNDEF IMM_H
			#include imm.h ; Windows Input Method Manager definitions - WIN32/64
		#ENDIF
	#ENDIF

#ENDIF

/*
NON-STANDARD HEADER FILES

These header files are not part of the standard Windows set, they have been
included as a convienience and mostly for myself as I use them on occasion
*/

#IFDEF INC_DONKEY
	#IFNDEF DONKEYLIB_H
		#include DonkeyLib.h ; Donkeylib definitions
	#ENDIF
#ENDIF

#IFDEF INC_ZLIB
	#IFNDEF ZLIB_H
		#include ZLib.h ; Zlib static library definitions
	#ENDIF
#ENDIF

#ELSE
	#IFDEF LINKFILES
		// These files should be searched first for imports
		#dynamiclinkfile kernel32.dll
		#dynamiclinkfile user32.dll
		#dynamiclinkfile shell32.dll
		#dynamiclinkfile comctl32.dll
		#dynamiclinkfile shlwapi.dll
	#ENDIF

	#IFNDEF ACCCTRL_H
		#include "accctrl.h"
	#ENDIF
	#IFNDEF ACLAPI_H
		#include "aclapi.h"
	#ENDIF
	#IFNDEF ACLUI_H
		#include "aclui.h"
	#ENDIF
	#IFNDEF ACTIVEDS_H
		#include "activeds.h"
	#ENDIF
	#IFNDEF ADPTIF_H
		#include "adptif.h"
	#ENDIF
	#IFNDEF ADSDB_H
		#include "adsdb.h"
	#ENDIF
	#IFNDEF ADSERR_H
		#include "adserr.h"
	#ENDIF
	#IFNDEF ADSHLP_H
		#include "adshlp.h"
	#ENDIF
	#IFNDEF ADSIID_H
		#include "adsiid.h"
	#ENDIF
	#IFNDEF ADSNMS_H
		#include "adsnms.h"
	#ENDIF
	#IFNDEF ADSSTS_H
		#include "Adssts.h"
	#ENDIF
	#IFNDEF ADTGEN_H
		#include "adtgen.h"
	#ENDIF
	#IFNDEF AF_IRDA_H
		#include "af_irda.h"
	#ENDIF
	#IFNDEF APPAVCAP_H
		#include "appavcap.h"
	#ENDIF
	#IFNDEF ATLBASE_H
		#include "atlbase.h"
	#ENDIF
	#IFNDEF ATLCOM_H
		#include "atlcom.h"
	#ENDIF
	#IFNDEF ATLDEF_H
		#include "atldef.h"
	#ENDIF
	#IFNDEF ATLHOST_H
		#include "atlhost.h"
	#ENDIF
	#IFNDEF ATLIFACE_H
		#include "atliface.h"
	#ENDIF
	#IFNDEF ATLWIN_H
		#include "atlwin.h"
	#ENDIF
	#IFNDEF AUTHIF_H
		#include "authif.h"
	#ENDIF
	#IFNDEF AUTHZ_H
		#include "authz.h"
	#ENDIF
	#IFNDEF AVIFMT_H
		#include "avifmt.h"
	#ENDIF
	#IFNDEF AVIRIFF_H
		#include "aviriff.h"
	#ENDIF
	#IFNDEF BASETSD_H
		#include "basetsd.h"
	#ENDIF
	#IFNDEF BASETYPES_H
		#include "basetyps.h"
	#ENDIF
	#IFNDEF BATCLASS_H
		#include "batclass.h"
	#ENDIF
	#IFNDEF BHERR_H
		#include "bherr.h"
	#ENDIF
	#IFNDEF BHFILTER_H
		#include "bhfilter.h"
	#ENDIF
	#IFNDEF BHTYPES_H
		#include "bhtypes.h"
	#ENDIF
	#IFNDEF CCHANNEL_H
		#include "cchannel.h"
	#ENDIF
	#IFNDEF CDERR_H
		#include "cderr.h"
	#ENDIF
	#IFNDEF CERTADM_H
		#include "certadm.h"
	#ENDIF
	#IFNDEF CERTBCLI_H
		#include "certbcli.h"
	#ENDIF
	#IFNDEF CERTEXIT_H
		#include "certexit.h"
	#ENDIF
	#IFNDEF CERTIF_H
		#include "certif.h"
	#ENDIF
	#IFNDEF CERTMOD_H
		#include "certmod.h"
	#ENDIF
	#IFNDEF CERTPOL_H
		#include "certpol.h"
	#ENDIF
	#IFNDEF CERTVIEW_H
		#include "certview.h"
	#ENDIF
	#IFNDEF CGUID_H
		#include "cguid.h"
	#ENDIF
	#IFNDEF CLUSAPI_H
		#include "clusapi.h"
	#ENDIF
	#IFNDEF CODECS_H
		#include "codecs.h"
	#ENDIF
	#IFNDEF COLORDLG_H
		#include "colordlg.h"
	#ENDIF
	#IFNDEF COMCAT_H
		#include "comcat.h"
	#ENDIF
	#IFNDEF COMMCTRL_H
		#include "commctrl.h"
	#ENDIF
	#IFNDEF COMMDLG_H
		#include "commdlg.h"
	#ENDIF
	#IFNDEF CPL_H
		#include "cpl.h"
	#ENDIF
	#IFNDEF CPLEXT_H
		#include "cplext.h"
	#ENDIF
	#IFNDEF CRYPTUIAPI_H
		#include "cryptuiapi.h"
	#ENDIF
	#IFNDEF CUSTCNTL_H
		#include "custcntl.h"
	#ENDIF
	#IFNDEF D3D8_H
		#include "d3d8.h"
	#ENDIF
	#IFNDEF D3D8CAPS_H
		#include "d3d8caps.h"
	#ENDIF
	#IFNDEF D3D8TYPES_H
		#include "d3d8types.h"
	#ENDIF
	#IFNDEF DBGAPI_H
		#include "dbgapi.h"
	#ENDIF
	#IFNDEF DBGHELP_H
		#include "DbgHelp.h"
	#ENDIF
	#IFNDEF DBT_H
		#include "dbt.h"
	#ENDIF
	#IFNDEF DDE_H
		#include "dde.h"
	#ENDIF
	#IFNDEF DDEML_H
		#include "ddeml.h"
	#ENDIF
	#IFNDEF DDRAW_H
		#include "ddraw.h"
	#ENDIF
	#IFNDEF DDRAWEX_H
		#include "ddrawex.h"
	#ENDIF
	#IFNDEF DHCPCSDK_H
		#include "dhcpcsdk.h"
	#ENDIF
	#IFNDEF DHTMLDID_H
		#include "DHtmldid.h"
	#ENDIF
	#IFNDEF DHTMLED_H
		#include "DHtmled.h"
	#ENDIF
	#IFNDEF DIGITALTV_H
		#include "digitalv.h"
	#ENDIF
	#IFNDEF DIMM_H
		#include "Dimm.h"
	#ENDIF
	#IFNDEF DISPDIB_H
		#include "dispdib.H"
	#ENDIF
	#IFNDEF DISPEX_H
		#include "DispEx.h"
	#ENDIF
	#IFNDEF DLGS_H
		#include "dlgs.h"
	#ENDIF
	#IFNDEF DMUSBUFF_H
		#include "dmusbuff.h"
	#ENDIF
	#IFNDEF DOCOBJ_H
		#include "DocObj.h"
	#ENDIF
	#IFNDEF NODONKEY
		#IFNDEF DONKEYLIB_H
			#include "DonkeyLib.h"
		#ENDIF
	#ENDIF
	#IFNDEF DPADDR_H
		#include "dpaddr.h"
	#ENDIF
	#IFNDEF DPLAY8_H
		#include "dplay8.h"
	#ENDIF
	#IFNDEF DSQUERY_H
		#include "dsquery.h"
	#ENDIF
	#IFNDEF DSROLE_H
		#include "dsrole.h"
	#ENDIF
	#IFNDEF EVNTRACE_H
		#include "evntrace.h"
	#ENDIF
	#IFNDEF EXDISP_H
		#include "exdisp.h"
	#ENDIF
	#IFNDEF EXDISPID_H
		#include "ExDispid.h"
	#ENDIF
	#IFNDEF FAXDEV_H
		#include "faxdev.h"
	#ENDIF
	#IFNDEF FAXROUTE_H
		#include "faxroute.h"
	#ENDIF
	#IFNDEF FLTDEFS_H
		#include "fltdefs.h"
	#ENDIF
	#IFNDEF FRAME_H
		#include "frame.h"
	#ENDIF
	#IFNDEF GUIDDEF_H
		#include "guiddef.h"
	#ENDIF
	#IFNDEF HHCTRL_H
		#include "HHCtrl.h"
	#ENDIF
	#IFNDEF HIGHLEVELMONITORCONFIGURATIONAPI_H
		#include "highlevelmonitorconfigurationapi.h"
	#ENDIF
	#IFNDEF HLGUIDS_H
		#include "HlGuids.h"
	#ENDIF
	#IFNDEF HLINK_H
		#include "hlink.h"
	#ENDIF
	#IFNDEF HOSTABLE_WEB_CORE_H
		#include "hostable_web_core.h"
	#ENDIF
	#IFNDEF HTMLCOLORS_H
		#include "htmlcolors.h"
	#ENDIF
	#IFNDEF HTMLGUID_H
		#include "htmlguid.h"
	#ENDIF
	#IFNDEF HTMLHELP_H
		#include "htmlhelp.h"
	#ENDIF
	#IFNDEF IA64REG_H
		#include "ia64reg.h"
	#ENDIF
	#IFNDEF IADS_H
		#include "iads.h"
	#ENDIF
	#IFNDEF IDISPIDS_H
		#include "IDispIds.h"
	#ENDIF
	#IFNDEF IMAGEHLP_H
		#include "imagehlp.h"
	#ENDIF
	#IFNDEF IMM_H
		#include "imm.h"
	#ENDIF
	#IFNDEF INFOTECH_H
		#include "infotech.h"
	#ENDIF
	#IFNDEF INILIB_H
		#include "inilib.h"
	#ENDIF
	#IFNDEF INTSHCUT_H
		#include "intshcut.h"
	#ENDIF
	#IFNDEF IPEXPORT_H
		#include "ipexport.h"
	#ENDIF
	#IFNDEF ISGUIDS_H
		#include "isguids.h"
	#ENDIF
	#IFNDEF JAVAATTR_H
		#include "javaattr.h"
	#ENDIF
	#IFNDEF JAVAEXEC_H
		#include "javaexec.h"
	#ENDIF
	#IFNDEF JDBGGUID_H
		#include "jdbgguid.h"
	#ENDIF
	#IFNDEF KXIA64_H
		#include "kxia64.h"
	#ENDIF
	#IFNDEF LM_H
		#include "lm.h"
	#ENDIF
	#IFNDEF LMACCESS_H
		#include "lmaccess.h"
	#ENDIF
	#IFNDEF LMALERT_H
		#include "lmalert.h"
	#ENDIF
	#IFNDEF LMAT_H
		#include "lmat.h"
	#ENDIF
	#IFNDEF LMAUDIT_H
		#include "lmaudit.h"
	#ENDIF
	#IFNDEF LMCONFIG_H
		#include "lmconfig.h"
	#ENDIF
	#IFNDEF LMCONS_H
		#include "lmcons.h"
	#ENDIF
	#IFNDEF LMDFS_H
		#include "lmdfs.h"
	#ENDIF
	#IFNDEF LMERR_H
		#include "lmerr.h"
	#ENDIF
	#IFNDEF LMERRLOG_H
		#include "lmerrlog.h"
	#ENDIF
	#IFNDEF LMJOIN_H
		#include "lmjoin.h"
	#ENDIF
	#IFNDEF LMMSG_H
		#include "lmmsg.h"
	#ENDIF
	#IFNDEF LMREMUTL_H
		#include "lmremutl.h"
	#ENDIF
	#IFNDEF LMREPL_H
		#include "lmrepl.h"
	#ENDIF
	#IFNDEF LMSERVER_H
		#include "lmserver.h"
	#ENDIF
	#IFNDEF LMSHARE_H
		#include "lmshare.h"
	#ENDIF
	#IFNDEF LMSNAME_H
		#include "lmsname.h"
	#ENDIF
	#IFNDEF LMSTATS_H
		#include "lmstats.h"
	#ENDIF
	#IFNDEF LMSVC_H
		#include "lmsvc.h"
	#ENDIF
	#IFNDEF LMUSE_H
		#include "lmuse.h"
	#ENDIF
	#IFNDEF LMUSEFLG_H
		#include "lmuseflg.h"
	#ENDIF
	#IFNDEF LMWKSTA_H
		#include "lmwksta.h"
	#ENDIF
	#IFNDEF LZEXPAND_H
		#include "lzexpand.h"
	#ENDIF
	#IFNDEF MAPI_H
		#include "mapi.h"
	#ENDIF
	#IFNDEF MAPICODE_H
		#include "mapicode.h"
	#ENDIF
	#IFNDEF MAPIDEFS_H
		#include "mapidefs.h"
	#ENDIF
	#IFNDEF MAPIFORM_H
		#include "mapiform.h"
	#ENDIF
	#IFNDEF MAPIGUID_H
		#include "mapiguid.h"
	#ENDIF
	#IFNDEF MAPITAGS_H
		#include "mapitags.h"
	#ENDIF
	#IFNDEF MAPIX_H
		#include "mapix.h"
	#ENDIF
	#IFNDEF MCIAVI_H
		#include "mciavi.h"
	#ENDIF
	#IFNDEF MCX_H
		#include "mcx.h"
	#ENDIF
	#IFNDEF MEDIAERR_H
		#include "mediaerr.h"
	#ENDIF
	#IFNDEF MMREG_H
		#include "mmreg.h"
	#ENDIF
	#IFNDEF MMSYSTEM_H
		#include "mmsystem.h"
	#ENDIF
	#IFNDEF MPRAPI_H
		#include "mprapi.h"
	#ENDIF
	#IFNDEF MSACM_H
		#include "msacm.h"
	#ENDIF
	#IFNDEF MSHELPCONTROLS_H
		#include "MSHelpControls.h"
	#ENDIF
	#IFNDEF MSHELPSERVICES_H
		#include "MSHelpServices.h"
	#ENDIF
	#IFNDEF MSHTMCID_H
		#include "MsHtmcid.h"
	#ENDIF
	#IFNDEF MSHTMID_H
		#include "MsHtmdid.h"
	#ENDIF
	#IFNDEF MSHTMHST_H
		#include "MsHtmHst.h"
	#ENDIF
	#IFNDEF MSHTML_H
		#include "Mshtml.h"
	#ENDIF
	#IFNDEF MSI_H
		#include "msi.h"
	#ENDIF
	#IFNDEF MSIMCNTL_H
		#include "msimcntl.h"
	#ENDIF
	#IFNDEF MSIQUERY_H
		#include "msiquery.h"
	#ENDIF
	#IFNDEF MSWSOCK_H
		#include "mswsock.h"
	#ENDIF
	#IFNDEF MSXML_H
		#include "MsXml.h"
	#ENDIF
	#IFNDEF NB30_H
		#include "Nb30.h"
	#ENDIF
	#IFNDEF NDDEAPI_H
		#include "nddeapi.h"
	#ENDIF
	#IFNDEF NETMON_H
		#include "netmon.h"
	#ENDIF
	#IFNDEF NMERR_H
		#include "nmerr.h"
	#ENDIF
	#IFNDEF NMEVENT_H
		#include "nmevent.h"
	#ENDIF
	#IFNDEF NMEXPERT_H
		#include "nmexpert.h"
	#ENDIF
	#IFNDEF NMSUPP_H
		#include "nmsupp.h"
	#ENDIF
	#IFNDEF NPPTYPES_H
		#include "npptypes.h"
	#ENDIF
	#IFNDEF OAIDL_H
		#include "oaidl.h"
	#ENDIF
	#IFNDEF OBJBASE_H
		#include "objbase.h"
	#ENDIF
	#IFNDEF OBJIDL_H
		#include "objidl.h"
	#ENDIF
	#IFNDEF OCIDL_H
		#include "ocidl.h"
	#ENDIF
	#IFNDEF ODBCINST_H
		#include "odbcinst.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
	#IFNDEF OLE2VER_H
		#include "ole2ver.h"
	#ENDIF
	#IFNDEF OLEAUTO_H
		#include "oleauto.h"
	#ENDIF
	#IFNDEF OLECTL_H
		#include "olectl.h"
	#ENDIF
	#IFNDEF OLEDLG_H
		#include "oledlg.h"
	#ENDIF
	#IFNDEF OLEIDL_H
		#include "oleidl.h"
	#ENDIF
	#IFNDEF PARSER_H
		#include "parser.h"
	#ENDIF
	#IFNDEF PATCHAPI_H
		#include "patchapi.h"
	#ENDIF
	#IFNDEF PATCHWIZ_H
		#include "patchwiz.h"
	#ENDIF
	#IFNDEF PBT_H
		#include "pbt.h"
	#ENDIF
	#IFNDEF PCHANNEL_H
		#include "pchannel.h"
	#ENDIF
	#IFNDEF PDH_H
		#include "pdh.h"
	#ENDIF
	#IFNDEF PEB_H
		#include "peb.h"
	#ENDIF
	#IFNDEF PERFLIB_H
		#include "perflib.h"
	#ENDIF
	#IFNDEF PERHIST_H
		#include "PerHist.h"
	#ENDIF
	#IFNDEF PHYSICALMONITORENUMERATIONAPI_H
		#include "physicalmonitorenumerationapi.h"
	#ENDIF
	#IFNDEF PROFINFO_H
		#include "profinfo.h"
	#ENDIF
	#IFNDEF PROPIDL_H
		#include "propidl.h"
	#ENDIF
	#IFNDEF PRSHT_H
		#include "prsht.h"
	#ENDIF
	#IFNDEF PSAPI_H
		#include "psapi.h"
	#ENDIF
	#IFNDEF QOS_H
		#include "qos.h"
	#ENDIF
	#IFNDEF QOSNAME_H
		#include "qosname.h"
	#ENDIF
	#IFNDEF RADASM_H
		#include "RadAsm.h"
	#ENDIF
	#IFNDEF RAS_H
		#include "ras.h"
	#ENDIF
	#IFNDEF RASDLG_H
		#include "rasdlg.h"
	#ENDIF
	#IFNDEF RASEAPIF_H
		#include "raseapif.h"
	#ENDIF
	#IFNDEF RASERROR_H
		#include "raserror.h"
	#ENDIF
	#IFNDEF RASSAPI_H
		#include "rassapi.h"
	#ENDIF
	#IFNDEF RASSHOST_H
		#include "rasshost.h"
	#ENDIF
	#IFNDEF REASON_H
		#include "reason.h"
	#ENDIF
	#IFNDEF REGSTR_H
		#include "regstr.h"
	#ENDIF
	#IFNDEF RICHEDIT_H
		#include "richedit.h"
	#ENDIF
	#IFNDEF RICHOLE_H
		#include "richole.h"
	#ENDIF
	#IFNDEF ROUTPROT_H
		#include "routprot.h"
	#ENDIF
	#IFNDEF RPC_H
		#include "rpc.h"
	#ENDIF
	#IFNDEF RPCASYNC_H
		#include "rpcasync.h"
	#ENDIF
	#IFNDEF RPCDCE_H
		#include "rpcdce.h"
	#ENDIF
	#IFNDEF RPCNDR_H
		#include "rpcndr.h"
	#ENDIF
	#IFNDEF RPCNSI_H
		#include "rpcnsi.h"
	#ENDIF
	#IFNDEF RPCNSIP_H
		#include "rpcnsip.h"
	#ENDIF
	#IFNDEF RPCNTERR_H
		#include "rpcnterr.h"
	#ENDIF
	#IFNDEF SCARD_H
		#include "SCardErr.h"
	#ENDIF
	#IFNDEF SCHANNEL_H
		#include "schannel.h"
	#ENDIF
	#IFNDEF SCHEDULE_H
		#include "schedule.h"
	#ENDIF
	#IFNDEF SCHNLSP_H
		#include "schnlsp.h"
	#ENDIF
	#IFNDEF SECEXT_H
		#include "secext.h"
	#ENDIF
	#IFNDEF SECURITY_H
		#include "security.h"
	#ENDIF
	#IFNDEF SENSAPI_H
		#include "sensapi.h"
	#ENDIF
	#IFNDEF SERVPROV_H
		#include "servprov.h"
	#ENDIF
	#IFNDEF SFC_H
		#include "sfc.h"
	#ENDIF
	#IFNDEF SHELLAPI_H
		#include "shellapi.h"
	#ENDIF
	#IFNDEF SHFOLDER_H
		#include "shfolder.h"
	#ENDIF
	#IFNDEF SHIMGDATA_H
		#include "ShImgData.h"
	#ENDIF
	#IFNDEF SHLDISP_H
		#include "shldisp.h"
	#ENDIF
	#IFNDEF SHLGUID_H
		#include "shlguid.h"
	#ENDIF
	#IFNDEF SHLOBJ_H
		#include "shlobj.h"
	#ENDIF
	#IFNDEF SHLWAPI_H
		#include "shlwapi.h"
	#ENDIF
	#IFNDEF SHOBJIDL_H
		#include "ShObjIdl.h"
	#ENDIF
	#IFNDEF SHTYPES_H
		#include "ShTypes.h"
	#ENDIF
	#IFNDEF SIMPDATA_H
		#include "simpdata.h"
	#ENDIF
	#IFNDEF SQL_H
		#include "sql.h"
	#ENDIF
	#IFNDEF SQLEXT_H
		#include "sqlext.h"
	#ENDIF
	#IFNDEF SQLOLEDB_H
		#include "sqloledb.h"
	#ENDIF
	#IFNDEF SQLTYPES_H
		#include "sqltypes.h"
	#ENDIF
	#IFNDEF SQLCODE_H
		#include "sqlucode.h"
	#ENDIF
	#IFNDEF SSPI_H
		#include "sspi.h"
	#ENDIF
	#IFNDEF STM_H
		#include "stm.h"
	#ENDIF
	#IFNDEF TAPI_H
		#include "tapi.h"
	#ENDIF
	#IFNDEF TCGUID_H
		#include "tcguid.h"
	#ENDIF
	#IFNDEF TLHELP32_H
		#include "tlhelp32.h"
	#ENDIF
	#IFNDEF TNEF_H
		#include "tnef.h"
	#ENDIF
	#IFNDEF TRAFFIC_H
		#include "traffic.h"
	#ENDIF
	#IFNDEF TSPI_H
		#include "tspi.h"
	#ENDIF
	#IFNDEF TVOUT_H
		#include "tvout.h"
	#ENDIF
	#IFNDEF URLHIST_H
		#include "UrlHist.h"
	#ENDIF
	#IFNDEF URLMON_H
		#include "urlmon.h"
	#ENDIF
	#IFNDEF USP10_H
		#include "usp10.h"
	#ENDIF
	#IFNDEF UXTHEME_H
		#include "uxtheme.h"
	#ENDIF
	#IFNDEF VCR_H
		#include "vcr.h"
	#ENDIF
	#IFNDEF VFW_H
		#include "vfw.h"
	#ENDIF
	#IFNDEF VSHELP80_H
		#include "VSHelp80.h"
	#ENDIF
	#IFNDEF WBEMADS_H
		#include "wbemads.h"
	#ENDIF
	#IFNDEF WBEMCLI_H
		#include "wbemcli.h"
	#ENDIF
	#IFNDEF WBEMDISP_H
		#include "wbemdisp.h"
	#ENDIF
	#IFNDEF WBEMIDL_H
		#include "wbemidl.h"
	#ENDIF
	#IFNDEF WBEMPROV_H
		#include "wbemprov.h"
	#ENDIF
	#IFNDEF WBEMTRAN_H
		#include "wbemtran.h"
	#ENDIF
	#IFNDEF WINABLE_H
		#include "winable.h"
	#ENDIF
	#IFNDEF WINCON_H
		#include "wincon.h"
	#ENDIF
	#IFNDEF WINCRYPT_H
		#include "wincrypt.h"
	#ENDIF
	#IFNDEF WINEFS_H
		#include "winefs.h"
	#ENDIF
	#IFNDEF WINERROR_H
		#include "winerror.h"
	#ENDIF
	#IFNDEF WINGDI_H
		#include "wingdi.h"
	#ENDIF
	#IFNDEF WINHTTP_H
		#include "winhttp.h"
	#ENDIF
	#IFNDEF WININET_H
		#include "wininet.h"
	#ENDIF
	#IFNDEF WINIOCTL_H
		#include "winioctl.h"
	#ENDIF
	#IFNDEF WINNETWK_H
		#include "winnetwk.h"
	#ENDIF
	#IFNDEF WINNLS_H
		#include "winnls.h"
	#ENDIF
	#IFNDEF WINNT_H
		#include "winnt.h"
	#ENDIF
	#IFNDEF WINPERF_H
		#include "winperf.h"
	#ENDIF
	#IFNDEF WINREG_H
		#include "winreg.h"
	#ENDIF
	#IFNDEF WINRESRC_H
		// This is a severely stripped down version of windows.h
		// It should not be included
		;#include "winresrc.h"
	#ENDIF
	#IFNDEF WINSCARD_H
		#include "winscard.h"
	#ENDIF
	#IFNDEF WINSMCRD_H
		#include "winsmcrd.h"
	#ENDIF
	#IFNDEF WINSOCK_H
		#include "winsock.h"
	#ENDIF
	#IFNDEF WINSOCK2_H
		#include "winsock2.h"
	#ENDIF
	#IFNDEF WINSPOOL_H
		#include "winspool.h"
	#ENDIF
	#IFNDEF WINSVC_H
		#include "winsvc.h"
	#ENDIF
	#IFNDEF WINTERNL_H
		// This file should not be included, see note above
		;#include "winternl.h"
	#ENDIF
	#IFNDEF WINTRUST_H
		#include "wintrust.h"
	#ENDIF
	#IFNDEF WINUSER_H
		#include "winuser.h"
	#ENDIF
	#IFNDEF WINVER_H
		#include "winver.h"
	#ENDIF
	#IFNDEF WINWLX_H
		#include "winwlx.h"
	#ENDIF
	#IFNDEF WMISTR_H
		#include "wmistr.h"
	#ENDIF
	#IFNDEF WMIUTILS_H
		#include "WMIUtils.h"
	#ENDIF
	#IFNDEF WOWNT32_H
		#include "wownt32.h"
	#ENDIF
	#IFNDEF WPAPI_H
		#include "wpapi.h"
	#ENDIF
	#IFNDEF WPAPIMSG_H
		#include "wpapimsg.h"
	#ENDIF
	#IFNDEF WPCRSMSG_H
		#include "wpcrsmsg.h"
	#ENDIF
	#IFNDEF WPFTPMSG_H
		#include "wpftpmsg.h"
	#ENDIF
	#IFNDEF WPPSTMSG_H
		#include "wppstmsg.h"
	#ENDIF
	#IFNDEF WPTYPES_H
		#include "wptypes.h"
	#ENDIF
	#IFNDEF WPWIZMSG_H
		#include "wpwizmsg.h"
	#ENDIF
	#IFNDEF WSIPX_H
		#include "wsipx.h"
	#ENDIF
	#IFNDEF WSNWLINK_H
		#include "wsnwlink.h"
	#ENDIF
	#IFNDEF WTYPES_H
		#include "wtypes.h"
	#ENDIF
	#IFNDEF HTTP_H
		#include "http.h"
	#ENDIF
	#IFNDEF HTTPCACH_H
		#include "httpcach.h"
	#ENDIF
	#IFNDEF HTTPEXT_H
		#include "httpext.h"
	#ENDIF
	#IFNDEF HTTPFILT_H
		#include "httpfilt.h"
	#ENDIF
	#IFNDEF HTTPREQUESTID_H
		#include "httprequestid.h"
	#ENDIF
	#IFNDEF HTTPSERV_H
		#include "httpserv.h"
	#ENDIF
	#IFNDEF HTTPTRACE_H
		#include "httptrace.h"
	#ENDIF
	#IFNDEF HTTPFILT_H
		#include "winber.h"
	#ENDIF
	#IFNDEF FDI_H
		#include "fdi.h"
	#ENDIF
	#IFNDEF ZLIB_H
		#include "Zlib.h"
	#ENDIF
	#IFNDEF GDIPLUS_H
		#include GDIPlus\gdiplus.h
	#ENDIF
	#IFNDEF GLAUX_H
		#include gl\glaux.h
	#ENDIF
	#IFNDEF FAXCONTROL_H
		#include Controls\faxcontrol.h
	#ENDIF
	#IFNDEF HTMLLITE_H
		#include Controls\htmllite.h
	#ENDIF
	#IFNDEF REGWIZCTL_H
		#include Controls\regwizctl.h
	#ENDIF
	#IFNDEF DHTML_H
		#include Controls\dhtml.h
	#ENDIF
#ENDIF

#ENDIF /* WINDOWS_H */


