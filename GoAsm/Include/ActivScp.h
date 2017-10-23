//=--------------------------------------------------------------------------=
// ActivScp.h
//=--------------------------------------------------------------------------=
// (C) Copyright Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=
//
//
// Declarations for ActiveX Scripting host applications and script engines.
//

#IFNDEF ACTIVSCP_H
#DEFINE ACTIVSCP_H

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

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

/* GUIDs
 ********/

// {F0B7A1A1-9847-11cf-8F20-00805F2CD064}
#DEFINE GUID_CATID_ActiveScript <0xf0b7a1a1, 0x9847, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>

// {F0B7A1A2-9847-11cf-8F20-00805F2CD064}
#DEFINE GUID_CATID_ActiveScriptParse <0xf0b7a1a2, 0x9847, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>

// {F0B7A1A3-9847-11cf-8F20-00805F2CD064}
#DEFINE GUID_CATID_ActiveScriptEncode <0xf0b7a1a3, 0x9847, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>

// {BB1A2AE1-A4F9-11cf-8F20-00805F2CD064}
#DEFINE GUID_IID_IActiveScript <0xbb1a2ae1, 0xa4f9, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>

// {BB1A2AE2-A4F9-11cf-8F20-00805F2CD064}
#DEFINE GUID_IID_IActiveScriptParse32 <0xbb1a2ae2, 0xa4f9, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>
// {C7EF7658-E1EE-480E-97EA-D52CB4D76D17}
#DEFINE GUID_IID_IActiveScriptParse64 <0xc7ef7658, 0xe1ee, 0x480e, <0x97, 0xea, 0xd5, 0x2c, 0xb4, 0xd7, 0x6d, 0x17>>

// {BB1A2AE3-A4F9-11cf-8F20-00805F2CD064}
#DEFINE GUID_IID_IActiveScriptEncode <0xbb1a2ae3, 0xa4f9, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>

// {BEE9B76E-CFE3-11d1-B747-00C04FC2B085}
#DEFINE GUID_IID_IActiveScriptHostEncode <0xbee9b76e, 0xcfe3, 0x11d1, <0xb7, 0x47, 0x00, 0xc0, 0x4f, 0xc2, 0xb0, 0x85>>

// {1CFF0050-6FDD-11d0-9328-00A0C90DCAA9}
#DEFINE GUID_IID_IActiveScriptParseProcedureOld32 <0x1cff0050, 0x6fdd, 0x11d0, <0x93, 0x28, 0x00, 0xa0, 0xc9, 0x0d, 0xca, 0xa9>>
// {21F57128-08C9-4638-BA12-22D15D88DC5C}
#DEFINE GUID_IID_IActiveScriptParseProcedureOld64 <0x21f57128, 0x08c9, 0x4638, <0xba, 0x12, 0x22, 0xd1, 0x5d, 0x88, 0xdc, 0x5c>>

// {AA5B6A80-B834-11d0-932F-00A0C90DCAA9}
#DEFINE GUID_IID_IActiveScriptParseProcedure32 <0xaa5b6a80, 0xb834, 0x11d0, <0x93, 0x2f, 0x00, 0xa0, 0xc9, 0x0d, 0xca, 0xa9>>
// {C64713B6-E029-4CC5-9200-438B72890B6A}
#DEFINE GUID_IID_IActiveScriptParseProcedure64 <0xc64713b6, 0xe029, 0x4cc5, <0x92, 0x00, 0x43, 0x8b, 0x72, 0x89, 0x0b, 0x6a>>

// {71EE5B20-FB04-11d1-B3A8-00A0C911E8B2}
#DEFINE GUID_IID_IActiveScriptParseProcedure2_32 <0x71ee5b20, 0xfb04, 0x11d1, <0xb3, 0xa8, 0x00, 0xa0, 0xc9, 0x11, 0xe8, 0xb2>>
// {FE7C4271-210C-448D-9F54-76DAB7047B28}
#DEFINE GUID_IID_IActiveScriptParseProcedure2_64 <0xfe7c4271, 0x210c, 0x448d, <0x9f, 0x54, 0x76, 0xda, 0xb7, 0x04, 0x7b, 0x28>>

// {DB01A1E3-A42B-11cf-8F20-00805F2CD064}
#DEFINE GUID_IID_IActiveScriptSite <0xdb01a1e3, 0xa42b, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>

// {4B7272AE-1955-4bfe-98B0-780621888569}
#DEFINE GUID_IID_IActiveScriptSiteTraceInfo <0x4b7272ae, 0x1955, 0x4bfe, <0x98, 0xb0, 0x78, 0x6, 0x21, 0x88, 0x85, 0x69>>

// {D10F6761-83E9-11cf-8F20-00805F2CD064}
#DEFINE GUID_IID_IActiveScriptSiteWindow <0xd10f6761, 0x83e9, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>

// {539698A0-CDCA-11CF-A5EB-00AA0047A063}
#DEFINE GUID_IID_IActiveScriptSiteInterruptPoll <0x539698a0, 0xcdca, 0x11cf, <0xa5, 0xeb, 0x00, 0xaa, 0x00, 0x47, 0xa0, 0x63>>

// {AEDAE97E-D7EE-4796-B960-7F092AE844AB}
#DEFINE GUID_IID_IActiveScriptSiteUIControl <0xaedae97e, 0xd7ee, 0x4796, <0xb9, 0x60, 0x7f, 0x9, 0x2a, 0xe8, 0x44, 0xab>>

// {EAE1BA61-A4ED-11cf-8F20-00805F2CD064}
#DEFINE GUID_IID_IActiveScriptError <0xeae1ba61, 0xa4ed, 0x11cf, <0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64>>
// {B21FB2A1-5B8F-4963-8C21-21450F84ED7F}
#DEFINE GUID_IID_IActiveScriptError64 <0xb21fb2a1, 0x5b8f, 0x4963, <0x8c, 0x21, 0x21, 0x45, 0x0f, 0x84, 0xed, 0x7f>>

// {63CDBCB0-C1B1-11d0-9336-00A0C90DCAA9}
#DEFINE GUID_IID_IBindEventHandler <0x63cdbcb0, 0xc1b1, 0x11d0, <0x93, 0x36, 0x00, 0xa0, 0xc9, 0x0d, 0xca, 0xa9>>

// {B8DA6310-E19B-11d0-933C-00A0C90DCAA9}
#DEFINE GUID_IID_IActiveScriptStats <0xb8da6310, 0xe19b, 0x11d0, <0x93, 0x3c, 0x00, 0xa0, 0xc9, 0x0d, 0xca, 0xa9>>

// {4954E0D0-FBC7-11D1-8410-006008C3FBFC}
#DEFINE GUID_IID_IActiveScriptProperty <0x4954E0D0, 0xFBC7, 0x11D1, <0x84, 0x10, 0x00, 0x60, 0x08, 0xC3, 0xFB, 0xFC>>

// {1DC9CA50-06EF-11d2-8415-006008C3FBFC}
#DEFINE GUID_IID_ITridentEventSink <0x1dc9ca50, 0x6ef, 0x11d2, <0x84, 0x15, 0x00, 0x60, 0x08, 0xc3, 0xfb, 0xfc>>

// {6AA2C4A0-2B53-11d4-A2A0-00104BD35090}
#DEFINE GUID_IID_IActiveScriptGarbageCollector <0x6aa2c4a0, 0x2b53, 0x11d4, <0xa2, 0xa0, 0x00, 0x10, 0x4b, 0xd3, 0x50, 0x90>>

// {764651D0-38DE-11d4-A2A3-00104BD35090}
#DEFINE GUID_IID_IActiveScriptSIPInfo <0x764651d0, 0x38de, 0x11d4, <0xa2, 0xa3, 0x00, 0x10, 0x4b, 0xd3, 0x50, 0x90>>

// {C35456E7-BEBF-4a1b-86A9-24D56BE8B369}
#DEFINE GUID_IID_IActiveScriptTraceInfo <0xC35456E7, 0xBEBF, 0x4a1b, <0x86, 0xA9, 0x24, 0xD5, 0x6B, 0xE8, 0xB3, 0x69>>

// {1629F04E-2799-4db5-8FE5-ACE10F17EBAB}
#DEFINE GUID_OID_VBSSIP <0x1629f04e, 0x2799, 0x4db5, <0x8f, 0xe5, 0xac, 0xe1, 0x0f, 0x17, 0xeb, 0xab>>

// {06C9E010-38CE-11d4-A2A3-00104BD35090}
#DEFINE GUID_OID_JSSIP <0x6c9e010, 0x38ce, 0x11d4, <0xa2, 0xa3, 0x00, 0x10, 0x4b, 0xd3, 0x50, 0x90>>

// {1A610570-38CE-11d4-A2A3-00104BD35090}
#DEFINE GUID_OID_WSFSIP <0x1a610570, 0x38ce, 0x11d4, <0xa2, 0xa3, 0x00, 0x10, 0x4b, 0xd3, 0x50, 0x90>>

// {58562769-ED52-42f7-8403-4963514E1F11}
#DEFINE GUID_IID_IActiveScriptStringCompare <0x58562769, 0xED52, 0x42f7, <0x84, 0x03, 0x49, 0x63, 0x51, 0x4E, 0x1F, 0x11>>

// Constants used by ActiveX Scripting:
//

/* IActiveScript::AddNamedItem() input flags */

#define SCRIPTITEM_ISVISIBLE            0x00000002
#define SCRIPTITEM_ISSOURCE             0x00000004
#define SCRIPTITEM_GLOBALMEMBERS        0x00000008
#define SCRIPTITEM_ISPERSISTENT         0x00000040
#define SCRIPTITEM_CODEONLY             0x00000200
#define SCRIPTITEM_NOCODE               0x00000400

#define SCRIPTITEM_ALL_FLAGS            (SCRIPTITEM_ISSOURCE | \
                                         SCRIPTITEM_ISVISIBLE | \
                                         SCRIPTITEM_ISPERSISTENT | \
                                         SCRIPTITEM_GLOBALMEMBERS | \
                                         SCRIPTITEM_NOCODE | \
                                         SCRIPTITEM_CODEONLY)

/* IActiveScript::AddTypeLib() input flags */

#define SCRIPTTYPELIB_ISCONTROL         0x00000010
#define SCRIPTTYPELIB_ISPERSISTENT      0x00000040
#define SCRIPTTYPELIB_ALL_FLAGS         (SCRIPTTYPELIB_ISCONTROL | SCRIPTTYPELIB_ISPERSISTENT)

/* IActiveScriptParse::AddScriptlet() and IActiveScriptParse::ParseScriptText() input flags */

#define SCRIPTTEXT_DELAYEXECUTION       0x00000001
#define SCRIPTTEXT_ISVISIBLE            0x00000002
#define SCRIPTTEXT_ISEXPRESSION         0x00000020
#define SCRIPTTEXT_ISPERSISTENT         0x00000040
#define SCRIPTTEXT_HOSTMANAGESSOURCE    0x00000080
#define SCRIPTTEXT_ISXDOMAIN            0x00000100
#define SCRIPTTEXT_ALL_FLAGS            (SCRIPTTEXT_DELAYEXECUTION | \
                                         SCRIPTTEXT_ISVISIBLE | \
                                         SCRIPTTEXT_ISEXPRESSION | \
                                         SCRIPTTEXT_ISPERSISTENT | \
                                         SCRIPTTEXT_HOSTMANAGESSOURCE | \
                                         SCRIPTTEXT_ISXDOMAIN)

/* IActiveScriptParseProcedure::ParseProcedureText() input flags */

#define SCRIPTPROC_ISEXPRESSION         0x00000020
#define SCRIPTPROC_HOSTMANAGESSOURCE    0x00000080
#define SCRIPTPROC_IMPLICIT_THIS        0x00000100
#define SCRIPTPROC_IMPLICIT_PARENTS     0x00000200
#define SCRIPTPROC_ISXDOMAIN            0x00000400
#define SCRIPTPROC_ALL_FLAGS            (SCRIPTPROC_HOSTMANAGESSOURCE | \
                                         SCRIPTPROC_ISEXPRESSION | \
                                         SCRIPTPROC_IMPLICIT_THIS | \
                                         SCRIPTPROC_IMPLICIT_PARENTS | \
                                         SCRIPTPROC_ISXDOMAIN)

/* IActiveScriptSite::GetItemInfo() input flags */

#define SCRIPTINFO_IUNKNOWN             0x00000001
#define SCRIPTINFO_ITYPEINFO            0x00000002
#define SCRIPTINFO_ALL_FLAGS            (SCRIPTINFO_IUNKNOWN | \
                                         SCRIPTINFO_ITYPEINFO)

/* IActiveScript::Interrupt() Flags */

#define SCRIPTINTERRUPT_DEBUG           0x00000001
#define SCRIPTINTERRUPT_RAISEEXCEPTION  0x00000002
#define SCRIPTINTERRUPT_ALL_FLAGS       (SCRIPTINTERRUPT_DEBUG | \
                                         SCRIPTINTERRUPT_RAISEEXCEPTION)

/* IActiveScriptStats::GetStat() values */

#define SCRIPTSTAT_STATEMENT_COUNT       1
#define SCRIPTSTAT_INSTRUCTION_COUNT     2
#define SCRIPTSTAT_INTSTRUCTION_TIME     3
#define SCRIPTSTAT_TOTAL_TIME            4

/* IActiveScriptEncode::AddSection() input flags */

#define SCRIPT_ENCODE_SECTION         0x00000001

#define SCRIPT_ENCODE_DEFAULT_LANGUAGE        0x00000001
#define SCRIPT_ENCODE_NO_ASP_LANGUAGE         0x00000002

/* Properties for IActiveScriptProperty */
#define SCRIPTPROP_NAME                     0x00000000
#define SCRIPTPROP_MAJORVERSION             0x00000001
#define SCRIPTPROP_MINORVERSION             0x00000002
#define SCRIPTPROP_BUILDNUMBER              0x00000003

#define SCRIPTPROP_DELAYEDEVENTSINKING      0x00001000
#define SCRIPTPROP_CATCHEXCEPTION           0x00001001
#define SCRIPTPROP_CONVERSIONLCID           0x00001002
#define SCRIPTPROP_HOSTSTACKREQUIRED        0x00001003

#define SCRIPTPROP_DEBUGGER                 0x00001100
#define SCRIPTPROP_JITDEBUG                 0x00001101

#define SCRIPTPROP_GCCONTROLSOFTCLOSE       0x00002000

#define SCRIPTPROP_INTEGERMODE              0x00003000
#define SCRIPTPROP_STRINGCOMPAREINSTANCE    0x00003001

#define SCRIPTPROP_INVOKEVERSIONING         0x00004000

// These properties are defined and available, but are not
// officially supported.
#define SCRIPTPROP_HACK_FIBERSUPPORT        0x70000000
#define SCRIPTPROP_HACK_TRIDENTEVENTSINK    0x70000001
#define SCRIPTPROP_ABBREVIATE_GLOBALNAME_RESOLUTION  0x70000002


/* script language version values for SCRIPTPROP_INVOKEVERSIONING property */

SCRIPTLANGUAGEVERSION_DEFAULT	= 0
SCRIPTLANGUAGEVERSION_5_7	= 1
SCRIPTLANGUAGEVERSION_5_8	= 2
SCRIPTLANGUAGEVERSION_MAX	= 255

SCRIPTSTATE_UNINITIALIZED	= 0
SCRIPTSTATE_INITIALIZED	= 5
SCRIPTSTATE_STARTED	= 1
SCRIPTSTATE_CONNECTED	= 2
SCRIPTSTATE_DISCONNECTED	= 3
SCRIPTSTATE_CLOSED	= 4

SCRIPTTRACEINFO_SCRIPTSTART	= 0
SCRIPTTRACEINFO_SCRIPTEND	= 1
SCRIPTTRACEINFO_COMCALLSTART	= 2
SCRIPTTRACEINFO_COMCALLEND	= 3
SCRIPTTRACEINFO_CREATEOBJSTART	= 4
SCRIPTTRACEINFO_CREATEOBJEND	= 5
SCRIPTTRACEINFO_GETOBJSTART	= 6
SCRIPTTRACEINFO_GETOBJEND	= 7

/* script thread state values */

SCRIPTTHREADSTATE_NOTINSCRIPT	= 0
SCRIPTTHREADSTATE_RUNNING	= 1

/* IActiveScriptCollectGarbage constants */

SCRIPTGCTYPE_NORMAL	= 0
SCRIPTGCTYPE_EXHAUSTIVE	= 1

/* IActiveScriptSiteUIControl constants*/

SCRIPTUICITEM_INPUTBOX	= 1
SCRIPTUICITEM_MSGBOX	= 2

SCRIPTUICHANDLING_ALLOW	= 0
SCRIPTUICHANDLING_NOUIERROR	= 1
SCRIPTUICHANDLING_NOUIDEFAULT	= 2

#define SCRIPTTHREADID_CURRENT  -1
#define SCRIPTTHREADID_BASE     -2
#define SCRIPTTHREADID_ALL      -3
 
/* Structures */

/* Interfaces
 *************/

#DEFINE GUID_IID_IActiveScriptSite <0xDB01A1E3,0xA42B,0x11cf,<0x8F,0x20,0x00,0x80,0x5F,0x2C,0xD0,0x64>>

IActiveScriptSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLCID PTR
	GetItemInfo PTR
	GetDocVersionString PTR
	OnScriptTerminate PTR
	OnStateChange PTR
	OnScriptError PTR
	OnEnterScript PTR
	OnLeaveScript PTR
ENDS

#DEFINE GUID_IID_IActiveScriptError <0xEAE1BA61,0xA4ED,0x11cf,<0x8F,0x20,0x00,0x80,0x5F,0x2C,0xD0,0x64>>

IActiveScriptError STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSourcePosition PTR
	GetSourceLineText PTR
ENDS

#DEFINE GUID_IID_IActiveScriptError64 <0xB21FB2A1,0x5B8F,0x4963,<0x8C,0x21,0x21,0x45,0x0F,0x84,0xED,0x7F>>

IActiveScriptError64 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSourcePosition PTR
	GetSourceLineText PTR
	GetSourcePosition64 PTR
ENDS

#DEFINE GUID_IID_IActiveScriptSiteWindow <0xD10F6761,0x83E9,0x11cf,<0x8F,0x20,0x00,0x80,0x5F,0x2C,0xD0,0x64>>

IActiveScriptSiteWindow STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	EnableModeless PTR
ENDS

#DEFINE GUID_IID_IActiveScriptSiteUIControl <0xAEDAE97E,0xD7EE,0x4796,<0xB9,0x60,0x7F,0x09,0x2A,0xE8,0x44,0xAB>>

IActiveScriptSiteUIControl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetUIBehavior PTR
ENDS

#DEFINE GUID_IID_IActiveScriptSiteInterruptPoll <0x539698A0,0xCDCA,0x11CF,<0xA5,0xEB,0x00,0xAA,0x00,0x47,0xA0,0x63>>

IActiveScriptSiteInterruptPoll STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryContinue PTR
ENDS

#DEFINE GUID_IID_IActiveScript <0xBB1A2AE1,0xA4F9,0x11cf,<0x8F,0x20,0x00,0x80,0x5F,0x2C,0xD0,0x64>>

IActiveScript STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetScriptSite PTR
	GetScriptSite PTR
	SetScriptState PTR
	GetScriptState PTR
	Close PTR
	AddNamedItem PTR
	AddTypeLib PTR
	GetScriptDispatch PTR
	GetCurrentScriptThreadID PTR
	GetScriptThreadID PTR
	GetScriptThreadState PTR
	InterruptScriptThread PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IActiveScriptParse32 <0xBB1A2AE2,0xA4F9,0x11cf,<0x8F,0x20,0x00,0x80,0x5F,0x2C,0xD0,0x64>>

IActiveScriptParse32 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitNew PTR
	AddScriptlet PTR
	ParseScriptText PTR
ENDS

#DEFINE GUID_IID_IActiveScriptParse64 <0xC7EF7658,0xE1EE,0x480E,<0x97,0xEA,0xD5,0x2C,0xB4,0xD7,0x6D,0x17>>

IActiveScriptParse64 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitNew PTR
	AddScriptlet PTR
	ParseScriptText PTR
ENDS

#ifdef WIN64
	#define IActiveScriptParse     IActiveScriptParse64
	#define IID_IActiveScriptParse IID_IActiveScriptParse64
#else
	#define IActiveScriptParse     IActiveScriptParse32
	#define IID_IActiveScriptParse IID_IActiveScriptParse32
#endif

#DEFINE GUID_IID_IActiveScriptParseProcedureOld32 <0x1CFF0050,0x6FDD,0x11d0,<0x93,0x28,0x00,0xA0,0xC9,0x0D,0xCA,0xA9>>

IActiveScriptParseProcedureOld32 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseProcedureText PTR
ENDS

#DEFINE GUID_IID_IActiveScriptParseProcedureOld64 <0x21F57128,0x08C9,0x4638,<0xBA,0x12,0x22,0xD1,0x5D,0x88,0xDC,0x5C>>

IActiveScriptParseProcedureOld64 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseProcedureText PTR
ENDS

#ifdef WIN64
	#define IActiveScriptParseProcedureOld     IActiveScriptParseProcedureOld64
	#define IID_IActiveScriptParseProcedureOld IID_IActiveScriptParseProcedureOld64
#else
	#define IActiveScriptParseProcedureOld     IActiveScriptParseProcedureOld32
	#define IID_IActiveScriptParseProcedureOld IID_IActiveScriptParseProcedureOld32
#endif

#DEFINE GUID_IID_IActiveScriptParseProcedure32 <0xAA5B6A80,0xB834,0x11d0,<0x93,0x2F,0x00,0xA0,0xC9,0x0D,0xCA,0xA9>>

IActiveScriptParseProcedure32 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseProcedureText PTR
ENDS

#DEFINE GUID_IID_IActiveScriptParseProcedure64 <0xC64713B6,0xE029,0x4CC5,<0x92,0x00,0x43,0x8B,0x72,0x89,0x0B,0x6A>>

IActiveScriptParseProcedure64 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseProcedureText PTR
ENDS

#ifdef WIN64
	#define IActiveScriptParseProcedure     IActiveScriptParseProcedure64
	#define IID_IActiveScriptParseProcedure IID_IActiveScriptParseProcedure64
#else
	#define IActiveScriptParseProcedure     IActiveScriptParseProcedure32
	#define IID_IActiveScriptParseProcedure IID_IActiveScriptParseProcedure32
#endif

#DEFINE GUID_IID_IActiveScriptParseProcedure2_32 <0x71EE5B20,0xFB04,0x11d1,<0xB3,0xA8,0x00,0xA0,0xC9,0x11,0xE8,0xB2>>

IActiveScriptParseProcedure2_32 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseProcedureText PTR
ENDS

#DEFINE GUID_IID_IActiveScriptParseProcedure2_64 <0xFE7C4271,0x210C,0x448D,<0x9F,0x54,0x76,0xDA,0xB7,0x04,0x7B,0x28>>

IActiveScriptParseProcedure2_64 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseProcedureText PTR
ENDS

#ifdef WIN64
	#define IActiveScriptParseProcedure2     IActiveScriptParseProcedure2_64
	#define IID_IActiveScriptParseProcedure2 IID_IActiveScriptParseProcedure2_64
#else
	#define IActiveScriptParseProcedure2     IActiveScriptParseProcedure2_32
	#define IID_IActiveScriptParseProcedure2 IID_IActiveScriptParseProcedure2_32
#endif

#DEFINE GUID_IID_IActiveScriptEncode <0xBB1A2AE3,0xA4F9,0x11cf,<0x8F,0x20,0x00,0x80,0x5F,0x2C,0xD0,0x64>>

IActiveScriptEncode STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	EncodeSection PTR
	DecodeScript PTR
	GetEncodeProgId PTR
ENDS

#DEFINE GUID_IID_IActiveScriptHostEncode <0xBEE9B76E,0xCFE3,0x11d1,<0xB7,0x47,0x00,0xC0,0x4F,0xC2,0xB0,0x85>>

IActiveScriptHostEncode STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	EncodeScriptHostFile PTR
ENDS

#DEFINE GUID_IID_IBindEventHandler <0x63CDBCB0,0xC1B1,0x11d0,<0x93,0x36,0x00,0xA0,0xC9,0x0D,0xCA,0xA9>>

IBindEventHandler STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	BindHandler PTR
ENDS

#DEFINE GUID_IID_IActiveScriptStats <0xB8DA6310,0xE19B,0x11d0,<0x93,0x3C,0x00,0xA0,0xC9,0x0D,0xCA,0xA9>>

IActiveScriptStats STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetStat PTR
	GetStatEx PTR
	ResetStats PTR
ENDS

#DEFINE GUID_IID_IActiveScriptProperty <0x4954E0D0,0xFBC7,0x11D1,<0x84,0x10,0x00,0x60,0x08,0xC3,0xFB,0xFC>>

IActiveScriptProperty STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetProperty PTR
	SetProperty PTR
ENDS

#DEFINE GUID_IID_ITridentEventSink <0x1DC9CA50,0x06EF,0x11d2,<0x84,0x15,0x00,0x60,0x08,0xC3,0xFB,0xFC>>

ITridentEventSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	FireEvent PTR
ENDS

#DEFINE GUID_IID_IActiveScriptGarbageCollector <0x6AA2C4A0,0x2B53,0x11d4,<0xA2,0xA0,0x00,0x10,0x4B,0xD3,0x50,0x90>>

IActiveScriptGarbageCollector STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CollectGarbage PTR
ENDS

#DEFINE GUID_IID_IActiveScriptSIPInfo <0x764651D0,0x38DE,0x11d4,<0xA2,0xA3,0x00,0x10,0x4B,0xD3,0x50,0x90>>

IActiveScriptSIPInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSIPOID PTR
ENDS

#DEFINE GUID_IID_IActiveScriptSiteTraceInfo <0x4B7272AE,0x1955,0x4bfe,<0x98,0xB0,0x78,0x06,0x21,0x88,0x85,0x69>>

IActiveScriptSiteTraceInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SendScriptTraceInfo PTR
ENDS

#DEFINE GUID_IID_IActiveScriptTraceInfo <0xC35456E7,0xBEBF,0x4a1b,<0x86,0xA9,0x24,0xD5,0x6B,0xE8,0xB3,0x69>>

IActiveScriptTraceInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	StartScriptTracing PTR
ENDS

#DEFINE GUID_IID_IActiveScriptStringCompare <0x58562769,0xED52,0x42f7,<0x84,0x03,0x49,0x63,0x51,0x4E,0x1F,0x11>>

IActiveScriptStringCompare STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	StrComp PTR
ENDS

#endif



