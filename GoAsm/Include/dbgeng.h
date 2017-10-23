//----------------------------------------------------------------------------
//
// Debugger engine interfaces.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#ifndef DBGENG_H
#define DBGENG_H

#IFDEF LINKFILES
	#dynamiclinkfile dbgeng.dll
#ENDIF

;#include <stdarg.h>
;#include <objbase.h>

//----------------------------------------------------------------------------
//
// GUIDs and interface forward declarations.
//
//----------------------------------------------------------------------------

/* f2df5f53-071f-47bd-9de6-5734c3fed689 */
#DEFINE GUID_IID_IDebugAdvanced <0xf2df5f53, 0x071f, 0x47bd, <0x9d, 0xe6, 0x57, 0x34, 0xc3, 0xfe, 0xd6, 0x89>>
/* 716d14c9-119b-4ba5-af1f-0890e672416a */
#DEFINE GUID_IID_IDebugAdvanced2 <0x716d14c9, 0x119b, 0x4ba5, <0xaf, 0x1f, 0x08, 0x90, 0xe6, 0x72, 0x41, 0x6a>>
/* cba4abb4-84c4-444d-87ca-a04e13286739 */
#DEFINE GUID_IID_IDebugAdvanced3 <0xcba4abb4, 0x84c4, 0x444d, <0x87, 0xca, 0xa0, 0x4e, 0x13, 0x28, 0x67, 0x39>>
/* 5bd9d474-5975-423a-b88b-65a8e7110e65 */
#DEFINE GUID_IID_IDebugBreakpoint <0x5bd9d474, 0x5975, 0x423a, <0xb8, 0x8b, 0x65, 0xa8, 0xe7, 0x11, 0x0e, 0x65>>
/* 1b278d20-79f2-426e-a3f9-c1ddf375d48e */
#DEFINE GUID_IID_IDebugBreakpoint2 <0x1b278d20, 0x79f2, 0x426e, <0xa3, 0xf9, 0xc1, 0xdd, 0xf3, 0x75, 0xd4, 0x8e>>
/* 27fe5639-8407-4f47-8364-ee118fb08ac8 */
#DEFINE GUID_IID_IDebugClient <0x27fe5639, 0x8407, 0x4f47, <0x83, 0x64, 0xee, 0x11, 0x8f, 0xb0, 0x8a, 0xc8>>
/* edbed635-372e-4dab-bbfe-ed0d2f63be81 */
#DEFINE GUID_IID_IDebugClient2 <0xedbed635, 0x372e, 0x4dab, <0xbb, 0xfe, 0xed, 0x0d, 0x2f, 0x63, 0xbe, 0x81>>
/* dd492d7f-71b8-4ad6-a8dc-1c887479ff91 */
#DEFINE GUID_IID_IDebugClient3 <0xdd492d7f, 0x71b8, 0x4ad6, <0xa8, 0xdc, 0x1c, 0x88, 0x74, 0x79, 0xff, 0x91>>
/* ca83c3de-5089-4cf8-93c8-d892387f2a5e */
#DEFINE GUID_IID_IDebugClient4 <0xca83c3de, 0x5089, 0x4cf8, <0x93, 0xc8, 0xd8, 0x92, 0x38, 0x7f, 0x2a, 0x5e>>
/* e3acb9d7-7ec2-4f0c-a0da-e81e0cbbe628 */
#DEFINE GUID_IID_IDebugClient5 <0xe3acb9d7, 0x7ec2, 0x4f0c, <0xa0, 0xda, 0xe8, 0x1e, 0x0c, 0xbb, 0xe6, 0x28>>
/* 5182e668-105e-416e-ad92-24ef800424ba */
#DEFINE GUID_IID_IDebugControl <0x5182e668, 0x105e, 0x416e, <0xad, 0x92, 0x24, 0xef, 0x80, 0x04, 0x24, 0xba>>
/* d4366723-44df-4bed-8c7e-4c05424f4588 */
#DEFINE GUID_IID_IDebugControl2 <0xd4366723, 0x44df, 0x4bed, <0x8c, 0x7e, 0x4c, 0x05, 0x42, 0x4f, 0x45, 0x88>>
/* 7df74a86-b03f-407f-90ab-a20dadcead08 */
#DEFINE GUID_IID_IDebugControl3 <0x7df74a86, 0xb03f, 0x407f, <0x90, 0xab, 0xa2, 0x0d, 0xad, 0xce, 0xad, 0x08>>
/* 94e60ce9-9b41-4b19-9fc0-6d9eb35272b3 */
#DEFINE GUID_IID_IDebugControl4 <0x94e60ce9, 0x9b41, 0x4b19, <0x9f, 0xc0, 0x6d, 0x9e, 0xb3, 0x52, 0x72, 0xb3>>
/* 88f7dfab-3ea7-4c3a-aefb-c4e8106173aa */
#DEFINE GUID_IID_IDebugDataSpaces <0x88f7dfab, 0x3ea7, 0x4c3a, <0xae, 0xfb, 0xc4, 0xe8, 0x10, 0x61, 0x73, 0xaa>>
/* 7a5e852f-96e9-468f-ac1b-0b3addc4a049 */
#DEFINE GUID_IID_IDebugDataSpaces2 <0x7a5e852f, 0x96e9, 0x468f, <0xac, 0x1b, 0x0b, 0x3a, 0xdd, 0xc4, 0xa0, 0x49>>
/* 23f79d6c-8aaf-4f7c-a607-9995f5407e63 */
#DEFINE GUID_IID_IDebugDataSpaces3 <0x23f79d6c, 0x8aaf, 0x4f7c, <0xa6, 0x07, 0x99, 0x95, 0xf5, 0x40, 0x7e, 0x63>>
/* d98ada1f-29e9-4ef5-a6c0-e53349883212 */
#DEFINE GUID_IID_IDebugDataSpaces4 <0xd98ada1f, 0x29e9, 0x4ef5, <0xa6, 0xc0, 0xe5, 0x33, 0x49, 0x88, 0x32, 0x12>>
/* 337be28b-5036-4d72-b6bf-c45fbb9f2eaa */
#DEFINE GUID_IID_IDebugEventCallbacks <0x337be28b, 0x5036, 0x4d72, <0xb6, 0xbf, 0xc4, 0x5f, 0xbb, 0x9f, 0x2e, 0xaa>>
/* 0690e046-9c23-45ac-a04f-987ac29ad0d3 */
#DEFINE GUID_IID_IDebugEventCallbacksWide <0x0690e046, 0x9c23, 0x45ac, <0xa0, 0x4f, 0x98, 0x7a, 0xc2, 0x9a, 0xd0, 0xd3>>
/* 9f50e42c-f136-499e-9a97-73036c94ed2d */
#DEFINE GUID_IID_IDebugInputCallbacks <0x9f50e42c, 0xf136, 0x499e, <0x9a, 0x97, 0x73, 0x03, 0x6c, 0x94, 0xed, 0x2d>>
/* 4bf58045-d654-4c40-b0af-683090f356dc */
#DEFINE GUID_IID_IDebugOutputCallbacks <0x4bf58045, 0xd654, 0x4c40, <0xb0, 0xaf, 0x68, 0x30, 0x90, 0xf3, 0x56, 0xdc>>
/* 4c7fd663-c394-4e26-8ef1-34ad5ed3764c */
#DEFINE GUID_IID_IDebugOutputCallbacksWide <0x4c7fd663, 0xc394, 0x4e26, <0x8e, 0xf1, 0x34, 0xad, 0x5e, 0xd3, 0x76, 0x4c>>
/* 67721fe9-56d2-4a44-a325-2b65513ce6eb */
#DEFINE GUID_IID_IDebugOutputCallbacks2 <0x67721fe9, 0x56d2, 0x4a44, <0xa3, 0x25, 0x2b, 0x65, 0x51, 0x3c, 0xe6, 0xeb>>
/* ce289126-9e84-45a7-937e-67bb18691493 */
#DEFINE GUID_IID_IDebugRegisters <0xce289126, 0x9e84, 0x45a7, <0x93, 0x7e, 0x67, 0xbb, 0x18, 0x69, 0x14, 0x93>>
/* 1656afa9-19c6-4e3a-97e7-5dc9160cf9c4 */
#DEFINE GUID_IID_IDebugRegisters2 <0x1656afa9, 0x19c6, 0x4e3a, <0x97, 0xe7, 0x5d, 0xc9, 0x16, 0x0c, 0xf9, 0xc4>>
/* f2528316-0f1a-4431-aeed-11d096e1e2ab */
#DEFINE GUID_IID_IDebugSymbolGroup <0xf2528316, 0x0f1a, 0x4431, <0xae, 0xed, 0x11, 0xd0, 0x96, 0xe1, 0xe2, 0xab>>
/* 6a7ccc5f-fb5e-4dcc-b41c-6c20307bccc7 */
#DEFINE GUID_IID_IDebugSymbolGroup2 <0x6a7ccc5f, 0xfb5e, 0x4dcc, <0xb4, 0x1c, 0x6c, 0x20, 0x30, 0x7b, 0xcc, 0xc7>>
/* 8c31e98c-983a-48a5-9016-6fe5d667a950 */
#DEFINE GUID_IID_IDebugSymbols <0x8c31e98c, 0x983a, 0x48a5, <0x90, 0x16, 0x6f, 0xe5, 0xd6, 0x67, 0xa9, 0x50>>
/* 3a707211-afdd-4495-ad4f-56fecdf8163f */
#DEFINE GUID_IID_IDebugSymbols2 <0x3a707211, 0xafdd, 0x4495, <0xad, 0x4f, 0x56, 0xfe, 0xcd, 0xf8, 0x16, 0x3f>>
/* f02fbecc-50ac-4f36-9ad9-c975e8f32ff8 */
#DEFINE GUID_IID_IDebugSymbols3 <0xf02fbecc, 0x50ac, 0x4f36, <0x9a, 0xd9, 0xc9, 0x75, 0xe8, 0xf3, 0x2f, 0xf8>>
/* 6b86fe2c-2c4f-4f0c-9da2-174311acc327 */
#DEFINE GUID_IID_IDebugSystemObjects <0x6b86fe2c, 0x2c4f, 0x4f0c, <0x9d, 0xa2, 0x17, 0x43, 0x11, 0xac, 0xc3, 0x27>>
/* 0ae9f5ff-1852-4679-b055-494bee6407ee */
#DEFINE GUID_IID_IDebugSystemObjects2 <0x0ae9f5ff, 0x1852, 0x4679, <0xb0, 0x55, 0x49, 0x4b, 0xee, 0x64, 0x07, 0xee>>
/* e9676e2f-e286-4ea3-b0f9-dfe5d9fc330e */
#DEFINE GUID_IID_IDebugSystemObjects3 <0xe9676e2f, 0xe286, 0x4ea3, <0xb0, 0xf9, 0xdf, 0xe5, 0xd9, 0xfc, 0x33, 0x0e>>
/* 489468e6-7d0f-4af5-87ab-25207454d553 */
#DEFINE GUID_IID_IDebugSystemObjects4 <0x489468e6, 0x7d0f, 0x4af5, <0x87, 0xab, 0x25, 0x20, 0x74, 0x54, 0xd5, 0x53>>

//----------------------------------------------------------------------------
//
// IDebugAdvanced.
//
//----------------------------------------------------------------------------

DEBUG_OFFSET_REGION STRUCT
	Base DQ
	Size DQ
ENDS

IDebugAdvanced STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugAdvanced.

    // Get/SetThreadContext offer control over
    // the full processor context for a thread.
    // Higher-level functions, such as the
    // IDebugRegisters interface, allow similar
    // access in simpler and more generic ways.
    // Get/SetThreadContext are useful when
    // large amounts of thread context must
    // be changed and processor-specific code
    // is not a problem.
	GetThreadContext PTR
	SetThreadContext PTR
ENDS

DEBUG_READ_USER_MINIDUMP_STREAM STRUCT
	StreamType DD
	Flags DD
	Offset DQ
	Buffer PTR
	BufferSize DD
	BufferUsed DD
ENDS

#define DEBUG_GET_TEXT_COMPLETIONS_NO_DOT_COMMANDS       0x00000001
#define DEBUG_GET_TEXT_COMPLETIONS_NO_EXTENSION_COMMANDS 0x00000002
#define DEBUG_GET_TEXT_COMPLETIONS_NO_SYMBOLS            0x00000004

DEBUG_GET_TEXT_COMPLETIONS_IN STRUCT
	Flags DD
	MatchCountLimit DD
	Reserved DQ 3 DUP
ENDS

#define DEBUG_GET_TEXT_COMPLETIONS_IS_DOT_COMMAND       0x00000001
#define DEBUG_GET_TEXT_COMPLETIONS_IS_EXTENSION_COMMAND 0x00000002
#define DEBUG_GET_TEXT_COMPLETIONS_IS_SYMBOL            0x00000004

DEBUG_GET_TEXT_COMPLETIONS_OUT STRUCT
	Flags DD
    // Char index in input string where completions start.
	ReplaceIndex DD
	MatchCount DD
	Reserved1 DD
	Reserved2 DQ 2 DUP
    // Completions follow.
    // Completion data is zero-terminated strings ended
    // by a final zero double-terminator.
ENDS

DEBUG_CACHED_SYMBOL_INFO STRUCT
	ModBase DQ
	Arg1 DQ
	Arg2 DQ
	Id DD
	Arg3 DD
ENDS

//
// Request requests.
//

// InBuffer - Unused.
// OutBuffer - Unused.
#define DEBUG_REQUEST_SOURCE_PATH_HAS_SOURCE_SERVER 0

// InBuffer - Unused.
// OutBuffer - Machine-specific CONTEXT.
#define DEBUG_REQUEST_TARGET_EXCEPTION_CONTEXT 1

// InBuffer - Unused.
// OutBuffer - ULONG system ID of thread.
#define DEBUG_REQUEST_TARGET_EXCEPTION_THREAD 2

// InBuffer - Unused.
// OutBuffer - EXCEPTION_RECORD64.
#define DEBUG_REQUEST_TARGET_EXCEPTION_RECORD 3

// InBuffer - Unused.
// OutBuffer - DEBUG_CREATE_PROCESS_OPTIONS.
#define DEBUG_REQUEST_GET_ADDITIONAL_CREATE_OPTIONS 4

// InBuffer - DEBUG_CREATE_PROCESS_OPTIONS.
// OutBuffer - Unused.
#define DEBUG_REQUEST_SET_ADDITIONAL_CREATE_OPTIONS 5

// InBuffer - Unused.
// OutBuffer - ULONG[2] major/minor.
#define DEBUG_REQUEST_GET_WIN32_MAJOR_MINOR_VERSIONS 6

// InBuffer - DEBUG_READ_USER_MINIDUMP_STREAM.
// OutBuffer - Unused.
#define DEBUG_REQUEST_READ_USER_MINIDUMP_STREAM 7

// InBuffer - Unused.
// OutBuffer - Unused.
#define DEBUG_REQUEST_TARGET_CAN_DETACH 8

// InBuffer - PTSTR.
// OutBuffer - Unused.
#define DEBUG_REQUEST_SET_LOCAL_IMPLICIT_COMMAND_LINE 9

// InBuffer - Unused.
// OutBuffer - Event code stream offset.
#define DEBUG_REQUEST_GET_CAPTURED_EVENT_CODE_OFFSET 10

// InBuffer - Unused.
// OutBuffer - Event code stream information.
#define DEBUG_REQUEST_READ_CAPTURED_EVENT_CODE_STREAM 11

// InBuffer - Input data block.
// OutBuffer - Processed data block.
#define DEBUG_REQUEST_EXT_TYPED_DATA_ANSI 12

// InBuffer - Unused.
// OutBuffer - Returned path.
#define DEBUG_REQUEST_GET_EXTENSION_SEARCH_PATH_WIDE 13

// InBuffer - DEBUG_GET_TEXT_COMPLETIONS_IN.
// OutBuffer - DEBUG_GET_TEXT_COMPLETIONS_OUT.
#define DEBUG_REQUEST_GET_TEXT_COMPLETIONS_WIDE 14

// InBuffer - ULONG64 cookie.
// OutBuffer - DEBUG_CACHED_SYMBOL_INFO.
#define DEBUG_REQUEST_GET_CACHED_SYMBOL_INFO 15

// InBuffer - DEBUG_CACHED_SYMBOL_INFO.
// OutBuffer - ULONG64 cookie.
#define DEBUG_REQUEST_ADD_CACHED_SYMBOL_INFO 16

// InBuffer - ULONG64 cookie.
// OutBuffer - Unused.
#define DEBUG_REQUEST_REMOVE_CACHED_SYMBOL_INFO 17

// InBuffer - DEBUG_GET_TEXT_COMPLETIONS_IN.
// OutBuffer - DEBUG_GET_TEXT_COMPLETIONS_OUT.
#define DEBUG_REQUEST_GET_TEXT_COMPLETIONS_ANSI 18

// InBuffer - Unused.
// OutBuffer - Unused.
#define DEBUG_REQUEST_CURRENT_OUTPUT_CALLBACKS_ARE_DML_AWARE 19

// InBuffer - ULONG64 offset.
// OutBuffer - Unwind information.
#define DEBUG_REQUEST_GET_OFFSET_UNWIND_INFORMATION 20

// InBuffer - Unused
// OutBuffer - returned DUMP_HEADER32/DUMP_HEADER64 structure.
#define DEBUG_REQUEST_GET_DUMP_HEADER 21

// InBuffer - DUMP_HEADER32/DUMP_HEADER64 structure.
// OutBuffer - Unused
#define DEBUG_REQUEST_SET_DUMP_HEADER 22

// InBuffer - Midori specific
// OutBuffer - Midori specific
#define DEBUG_REQUEST_MIDORI 23

// InBuffer - Unused
// OutBuffer - PROCESS_NAME_ENTRY blocks
#define DEBUG_REQUEST_PROCESS_DESCRIPTORS 24

// InBuffer - Unused
// OutBuffer - MINIDUMP_MISC_INFO_N blocks
#define DEBUG_REQUEST_MISC_INFORMATION 25

// InBuffer - Unused
// OutBuffer - ULONG64 as TokenHandle value
#define DEBUG_REQUEST_OPEN_PROCESS_TOKEN 26

// InBuffer - Unused
// OutBuffer - ULONG64 as TokenHandle value
#define DEBUG_REQUEST_OPEN_THREAD_TOKEN 27

// InBuffer -  ULONG64 as TokenHandle being duplicated
// OutBuffer - ULONG64 as new duplicated TokenHandle
#define DEBUG_REQUEST_DUPLICATE_TOKEN 28

// InBuffer - a ULONG64 as TokenHandle and a ULONG as NtQueryInformationToken() request code
// OutBuffer - NtQueryInformationToken() return
#define DEBUG_REQUEST_QUERY_INFO_TOKEN 29

// InBuffer - ULONG64 as TokenHandle
// OutBuffer - Unused
#define DEBUG_REQUEST_CLOSE_TOKEN 30



//
// GetSourceFileInformation requests.
//

// Arg64 - Module base.
// Arg32 - Unused.
#define DEBUG_SRCFILE_SYMBOL_TOKEN 0

// Arg64 - Module base.
// Arg32 - Unused.
#define DEBUG_SRCFILE_SYMBOL_TOKEN_SOURCE_COMMAND_WIDE 1

//
// GetSymbolInformation requests.
//

// Arg64 - Unused.
// Arg32 - Breakpoint ID.
// Buffer - ULONG line number.
// String - File name.
#define DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE 0

// Arg64 - Module base.
// Arg32 - Unused.
// Buffer - IMAGEHLP_MODULEW64.
// String - Unused.
#define DEBUG_SYMINFO_IMAGEHLP_MODULEW64 1

// Arg64 - Offset.
// Arg32 - Symbol tag.
// Buffer - Unicode symbol name strings.  Could have multiple strings.
// String - Unused, strings are returned in Buffer as there
//          may be more than one.
#define DEBUG_SYMINFO_GET_SYMBOL_NAME_BY_OFFSET_AND_TAG_WIDE 2

// Arg64 - Module base.
// Arg32 - Symbol tag.
// Buffer - Array of symbol addresses.
// String - Concatenated symbol strings.  Individual symbol
//          strings are zero-terminated and the final string in
//          a symbol is double-zero-terminated.
#define DEBUG_SYMINFO_GET_MODULE_SYMBOL_NAMES_AND_OFFSETS 3

//
// GetSystemObjectInformation requests.
//

// Arg64 - Unused.
// Arg32 - Debugger thread ID.
// Buffer - DEBUG_THREAD_BASIC_INFORMATION.
#define DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION 0

// Arg64 - Unused.
// Arg32 - Debugger thread ID.
// Buffer - Unicode name string.
#define DEBUG_SYSOBJINFO_THREAD_NAME_WIDE 1

// Arg64 - Unused.
// Arg32 - Unused.
// Buffer - ULONG cookie value.
#define DEBUG_SYSOBJINFO_CURRENT_PROCESS_COOKIE 2

#define DEBUG_TBINFO_EXIT_STATUS    0x00000001
#define DEBUG_TBINFO_PRIORITY_CLASS 0x00000002
#define DEBUG_TBINFO_PRIORITY       0x00000004
#define DEBUG_TBINFO_TIMES          0x00000008
#define DEBUG_TBINFO_START_OFFSET   0x00000010
#define DEBUG_TBINFO_AFFINITY       0x00000020
#define DEBUG_TBINFO_ALL            0x0000003f

DEBUG_THREAD_BASIC_INFORMATION STRUCT
	Valid DD
	ExitStatus DD
	PriorityClass DD
	Priority DD
	CreateTime DQ
	ExitTime DQ
	KernelTime DQ
	UserTime DQ
	StartOffset DQ
	Affinity DQ
ENDS

IDebugAdvanced2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugAdvanced.

    // Get/SetThreadContext offer control over
    // the full processor context for a thread.
    // Higher-level functions, such as the
    // IDebugRegisters interface, allow similar
    // access in simpler and more generic ways.
    // Get/SetThreadContext are useful when
    // large amounts of thread context must
    // be changed and processor-specific code
    // is not a problem.
	GetThreadContext PTR
	SetThreadContext PTR

    // IDebugAdvanced2.

    //
    // Generalized open-ended methods for querying
    // and manipulation.  The open-ended nature of
    // these methods makes it easy to add new requests,
    // although at a cost in convenience of calling.
    // Sufficiently common requests may have more specific,
    // simpler methods elsewhere.
    //

	Request PTR
	GetSourceFileInformation PTR
	FindSourceFileAndToken PTR
	GetSymbolInformation PTR
	GetSystemObjectInformation PTR
ENDS

IDebugAdvanced3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugAdvanced.

    // Get/SetThreadContext offer control over
    // the full processor context for a thread.
    // Higher-level functions, such as the
    // IDebugRegisters interface, allow similar
    // access in simpler and more generic ways.
    // Get/SetThreadContext are useful when
    // large amounts of thread context must
    // be changed and processor-specific code
    // is not a problem.
	GetThreadContext PTR
	SetThreadContext PTR

    // IDebugAdvanced2.

    //
    // Generalized open-ended methods for querying
    // and manipulation.  The open-ended nature of
    // these methods makes it easy to add new requests,
    // although at a cost in convenience of calling.
    // Sufficiently common requests may have more specific,
    // simpler methods elsewhere.
    //
	Request PTR
	GetSourceFileInformation PTR
	FindSourceFileAndToken PTR
	GetSymbolInformation PTR
	GetSystemObjectInformation PTR
    // IDebugAdvanced3.
	GetSourceFileInformationWide PTR
	FindSourceFileAndTokenWide PTR
	GetSymbolInformationWide PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugBreakpoint.
//
//----------------------------------------------------------------------------

// Types of breakpoints.
#define DEBUG_BREAKPOINT_CODE 0
#define DEBUG_BREAKPOINT_DATA 1
#define DEBUG_BREAKPOINT_TIME 2

// Breakpoint flags.
// Go-only breakpoints are only active when
// the engine is in unrestricted execution
// mode.  They do not fire when the engine
// is stepping.
#define DEBUG_BREAKPOINT_GO_ONLY    0x00000001
// A breakpoint is flagged as deferred as long as
// its offset expression cannot be evaluated.
// A deferred breakpoint is not active.
#define DEBUG_BREAKPOINT_DEFERRED   0x00000002
#define DEBUG_BREAKPOINT_ENABLED    0x00000004
// The adder-only flag does not affect breakpoint
// operation.  It is just a marker to restrict
// output and notifications for the breakpoint to
// the client that added the breakpoint.  Breakpoint
// callbacks for adder-only breaks will only be delivered
// to the adding client.  The breakpoint can not
// be enumerated and accessed by other clients.
#define DEBUG_BREAKPOINT_ADDER_ONLY 0x00000008
// One-shot breakpoints automatically clear themselves
// the first time they are hit.
#define DEBUG_BREAKPOINT_ONE_SHOT   0x00000010

// Data breakpoint access types.
// Different architectures support different
// sets of these bits.
#define DEBUG_BREAK_READ    0x00000001
#define DEBUG_BREAK_WRITE   0x00000002
#define DEBUG_BREAK_EXECUTE 0x00000004
#define DEBUG_BREAK_IO      0x00000008

// Structure for querying breakpoint information
// all at once.
DEBUG_BREAKPOINT_PARAMETERS STRUCT
	Offset DQ
	Id DD
	BreakType DD
	ProcType DD
	Flags DD
	DataSize DD
	DataAccessType DD
	PassCount DD
	CurrentPassCount DD
	MatchThread DD
	CommandSize DD
	OffsetExpressionSize DD
ENDS

IDebugBreakpoint STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugBreakpoint.

    // Retrieves debugger engine unique ID
    // for the breakpoint.  This ID is
    // fixed as long as the breakpoint exists
    // but after that may be reused.
	GetId PTR
    // Retrieves the type of break and
    // processor type for the breakpoint.
	GetType PTR
    // Returns the client that called AddBreakpoint.
	GetAdder PTR
	GetFlags PTR
    // Only certain flags can be changed.  Flags
    // are: GO_ONLY, ENABLE.
    // Sets the given flags.
	AddFlags PTR
    // Clears the given flags.
	RemoveFlags PTR
    // Sets the flags.
	SetFlags PTR

    // Controls the offset of the breakpoint.  The
    // interpretation of the offset value depends on
    // the type of breakpoint and its settings.  It
    // may be a code address, a data address, an
    // I/O port, etc.
	GetOffset PTR
	SetOffset PTR

    // Data breakpoint methods will fail if the
    // target platform does not support the
    // parameters used.
    // These methods only function for breakpoints
    // created as data breakpoints.
	GetDataParameters PTR
	SetDataParameters PTR
    // Pass count defaults to one.
	GetPassCount PTR
	SetPassCount PTR
    // Gets the current number of times
    // the breakpoint has been hit since
    // it was last triggered.
	GetCurrentPassCount PTR

    // If a match thread is set this breakpoint will
    // only trigger if it occurs on the match thread.
    // Otherwise it triggers for all threads.
    // Thread restrictions are not currently supported
    // in kernel mode.
	GetMatchThreadId PTR
	SetMatchThreadId PTR

    // The command for a breakpoint is automatically
    // executed by the engine before the event
    // is propagated.  If the breakpoint continues
    // execution the event will begin with a continue
    // status.  If the breakpoint does not continue
    // the event will begin with a break status.
    // This allows breakpoint commands to participate
    // in the normal event status voting.
    // Breakpoint commands are only executed until
    // the first command that alters the execution
    // status, such as g, p and t.
	GetCommand PTR
	SetCommand PTR

    // Offset expressions are evaluated immediately
    // and at module load and unload events.  If the
    // evaluation is successful the breakpoints
    // offset is updated and the breakpoint is
    // handled normally.  If the expression cannot
    // be evaluated the breakpoint is deferred.
    // Currently the only offset expression
    // supported is a module-relative symbol
    // of the form <Module>!<Symbol>.
	GetOffsetExpression PTR
	SetOffsetExpression PTR
	GetParameters PTR
ENDS

IDebugBreakpoint2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugBreakpoint.

    // Retrieves debugger engine unique ID
    // for the breakpoint.  This ID is
    // fixed as long as the breakpoint exists
    // but after that may be reused.
	GetId PTR
    // Retrieves the type of break and
    // processor type for the breakpoint.
	GetType PTR
    // Returns the client that called AddBreakpoint.
	GetAdder PTR
	GetFlags PTR
    // Only certain flags can be changed.  Flags
    // are: GO_ONLY, ENABLE.
    // Sets the given flags.
	AddFlags PTR
    // Clears the given flags.
	RemoveFlags PTR
    // Sets the flags.
	SetFlags PTR

    // Controls the offset of the breakpoint.  The
    // interpretation of the offset value depends on
    // the type of breakpoint and its settings.  It
    // may be a code address, a data address, an
    // I/O port, etc.
	GetOffset PTR
	SetOffset PTR

    // Data breakpoint methods will fail if the
    // target platform does not support the
    // parameters used.
    // These methods only function for breakpoints
    // created as data breakpoints.
	GetDataParameters PTR
	SetDataParameters PTR
    // Pass count defaults to one.
	GetPassCount PTR
	SetPassCount PTR
    // Gets the current number of times
    // the breakpoint has been hit since
    // it was last triggered.
	GetCurrentPassCount PTR

    // If a match thread is set this breakpoint will
    // only trigger if it occurs on the match thread.
    // Otherwise it triggers for all threads.
    // Thread restrictions are not currently supported
    // in kernel mode.
	GetMatchThreadId PTR
	SetMatchThreadId PTR

    // The command for a breakpoint is automatically
    // executed by the engine before the event
    // is propagated.  If the breakpoint continues
    // execution the event will begin with a continue
    // status.  If the breakpoint does not continue
    // the event will begin with a break status.
    // This allows breakpoint commands to participate
    // in the normal event status voting.
    // Breakpoint commands are only executed until
    // the first command that alters the execution
    // status, such as g, p and t.
	GetCommand PTR
	SetCommand PTR

    // Offset expressions are evaluated immediately
    // and at module load and unload events.  If the
    // evaluation is successful the breakpoints
    // offset is updated and the breakpoint is
    // handled normally.  If the expression cannot
    // be evaluated the breakpoint is deferred.
    // Currently the only offset expression
    // supported is a module-relative symbol
    // of the form <Module>!<Symbol>.
	GetOffsetExpression PTR
	SetOffsetExpression PTR
	GetParameters PTR
    // IDebugBreakpoint2.

	GetCommandWide PTR
	SetCommandWide PTR
	GetOffsetExpressionWide PTR
	SetOffsetExpressionWide PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugClient.
//
//----------------------------------------------------------------------------

// Kernel attach flags.
#define DEBUG_ATTACH_KERNEL_CONNECTION 0x00000000
// Attach to the local machine.  If this flag is not set
// a connection is made to a separate target machine using
// the given connection options.
#define DEBUG_ATTACH_LOCAL_KERNEL      0x00000001
// Attach to an eXDI driver.
#define DEBUG_ATTACH_EXDI_DRIVER       0x00000002
// Just install client-side transpotr drivers
#define DEBUG_ATTACH_INSTALL_DRIVER    0x00000004

// GetRunningProcessSystemIdByExecutableName flags.
// By default the match allows a tail match on
// just the filename.  The match returns the first hit
// even if multiple matches exist.
#define DEBUG_GET_PROC_DEFAULT      0x00000000
// The name must match fully.
#define DEBUG_GET_PROC_FULL_MATCH   0x00000001
// The match must be the only match.
#define DEBUG_GET_PROC_ONLY_MATCH   0x00000002
// The name is a service name instead of an executable name.
#define DEBUG_GET_PROC_SERVICE_NAME 0x00000004

// GetRunningProcessDescription flags.
#define DEBUG_PROC_DESC_DEFAULT         0x00000000
// Return only filenames, not full paths.
#define DEBUG_PROC_DESC_NO_PATHS        0x00000001
// Dont look up service names.
#define DEBUG_PROC_DESC_NO_SERVICES     0x00000002
// Dont look up MTS package names.
#define DEBUG_PROC_DESC_NO_MTS_PACKAGES 0x00000004
// Dont retrieve the command line.
#define DEBUG_PROC_DESC_NO_COMMAND_LINE 0x00000008
// Dont retrieve the session ID.
#define DEBUG_PROC_DESC_NO_SESSION_ID   0x00000010
// Dont retrieve the process's user name.
#define DEBUG_PROC_DESC_NO_USER_NAME    0x00000020

//
// Attach flags.
//

// Call DebugActiveProcess when attaching.
#define DEBUG_ATTACH_DEFAULT                   0x00000000
// When attaching to a process just examine
// the process state and suspend the threads.
// DebugActiveProcess is not called so the process
// is not actually being debugged.  This is useful
// for debugging processes holding locks which
// interfere with the operation of DebugActiveProcess
// or in situations where it is not desirable to
// actually set up as a debugger.
#define DEBUG_ATTACH_NONINVASIVE               0x00000001
// Attempt to attach to a process that was abandoned
// when being debugged.  This is only supported in
// some system versions.
// This flag also allows multiple debuggers to
// attach to the same process, which can result
// in numerous problems unless very carefully
// managed.
#define DEBUG_ATTACH_EXISTING                  0x00000002
// When attaching non-invasively, do not suspend
// threads.  It is the callers responsibility
// to either suspend the threads itself or be
// aware that the attach state may not reflect
// the current state of the process if threads
// are still running.
#define DEBUG_ATTACH_NONINVASIVE_NO_SUSPEND    0x00000004
// When doing an invasive attach do not inject
// a break-in thread to generate the initial break-in
// event.  This can be useful to save resources when
// an initial break is not necessary or when injecting
// a thread might affect the debuggee's state.  This
// option is only supported on Windows XP and above.
#define DEBUG_ATTACH_INVASIVE_NO_INITIAL_BREAK 0x00000008
// When doing an invasive attach resume all threads at the
// time of attach.  This makes it possible to attach
// to a process created suspended and cause it to start running.
#define DEBUG_ATTACH_INVASIVE_RESUME_PROCESS   0x00000010
// When doing a non-invasive attach the engine must
// recover information for all debuggee elements.  The
// engine may not have permissions for all elements,
// for example it may not be able to open all threads,
// and that would ordinarily block the attach.  This
// flag allows unusable elements to be ignored.
#define DEBUG_ATTACH_NONINVASIVE_ALLOW_PARTIAL 0x00000020


//
// Process creation flags to merge with Win32 flags.
//

// On Windows XP this flag prevents the debug
// heap from being used in the new process.
#define DEBUG_CREATE_PROCESS_NO_DEBUG_HEAP CREATE_UNICODE_ENVIRONMENT
// Indicates that the native NT RTL process creation
// routines should be used instead of Win32.  This
// is only meaningful for special processes that run
// as NT native processes.
#define DEBUG_CREATE_PROCESS_THROUGH_RTL   STACK_SIZE_PARAM_IS_A_RESERVATION

//
// Process creation flags specific to the debugger engine.
//

#define DEBUG_ECREATE_PROCESS_DEFAULT                   0x00000000
#define DEBUG_ECREATE_PROCESS_INHERIT_HANDLES           0x00000001
#define DEBUG_ECREATE_PROCESS_USE_VERIFIER_FLAGS        0x00000002
#define DEBUG_ECREATE_PROCESS_USE_IMPLICIT_COMMAND_LINE 0x00000004

DEBUG_CREATE_PROCESS_OPTIONS STRUCT
    // Win32 create flags.
	CreateFlags DD
    // DEBUG_ECREATE_PROCESS_* flags.
	EngCreateFlags DD
    // Application Verifier flags,
    // if DEBUG_ECREATE_PROCESS_USE_VERIFIER_FLAGS is set.
	VerifierFlags DD
    // Must be zero.
	Reserved DD
ENDS

//
// Process options.
//

// Indicates that the debuggee process should be
// automatically detached when the debugger exits.
// A debugger can explicitly detach on exit or this
// flag can be set so that detach occurs regardless
// of how the debugger exits.
// This is only supported on some system versions.
#define DEBUG_PROCESS_DETACH_ON_EXIT    0x00000001
// Indicates that processes created by the current
// process should not be debugged.
// Modifying this flag is only supported on some
// system versions.
#define DEBUG_PROCESS_ONLY_THIS_PROCESS 0x00000002

// ConnectSession flags.
// Default connect.
#define DEBUG_CONNECT_SESSION_DEFAULT     0x00000000
// Do not output the debugger version.
#define DEBUG_CONNECT_SESSION_NO_VERSION  0x00000001
// Do not announce the connection.
#define DEBUG_CONNECT_SESSION_NO_ANNOUNCE 0x00000002

// OutputServers flags.
// Debugger servers from StartSever.
#define DEBUG_SERVERS_DEBUGGER 0x00000001
// Process servers from StartProcessServer.
#define DEBUG_SERVERS_PROCESS  0x00000002
#define DEBUG_SERVERS_ALL      0x00000003

// EndSession flags.
// Perform cleanup for the session.
#define DEBUG_END_PASSIVE          0x00000000
// Actively terminate the session and then perform cleanup.
#define DEBUG_END_ACTIVE_TERMINATE 0x00000001
// If possible, detach from all processes and then perform cleanup.
#define DEBUG_END_ACTIVE_DETACH    0x00000002
// Perform whatever cleanup is possible that doesn't require
// acquiring any locks.  This is useful for situations where
// a thread is currently using the engine but the application
// needs to exit and still wants to give the engine
// the opportunity to clean up as much as possible.
// This may leave the engine in an indeterminate state so
// further engine calls should not be made.
// When making a reentrant EndSession call from a remote
// client it is the callers responsibility to ensure
// that the server can process the request.  It is best
// to avoid making such calls.
#define DEBUG_END_REENTRANT        0x00000003
// Notify a server that a remote client is disconnecting.
// This isnt required but if it isnt called then
// no disconnect messages will be generated by the server.
#define DEBUG_END_DISCONNECT       0x00000004

// Output mask bits.
// Normal output.
#define DEBUG_OUTPUT_NORMAL            0x00000001
// Error output.
#define DEBUG_OUTPUT_ERROR             0x00000002
// Warnings.
#define DEBUG_OUTPUT_WARNING           0x00000004
// Additional output.
#define DEBUG_OUTPUT_VERBOSE           0x00000008
// Prompt output.
#define DEBUG_OUTPUT_PROMPT            0x00000010
// Register dump before prompt.
#define DEBUG_OUTPUT_PROMPT_REGISTERS  0x00000020
// Warnings specific to extension operation.
#define DEBUG_OUTPUT_EXTENSION_WARNING 0x00000040
// Debuggee debug output, such as from OutputDebugString.
#define DEBUG_OUTPUT_DEBUGGEE          0x00000080
// Debuggee-generated prompt, such as from DbgPrompt.
#define DEBUG_OUTPUT_DEBUGGEE_PROMPT   0x00000100
// Symbol messages, such as for !sym noisy.
#define DEBUG_OUTPUT_SYMBOLS           0x00000200

// Internal debugger output, used mainly
// for debugging the debugger.  Output
// may only occur in debug builds.
// KD protocol output.
#define DEBUG_IOUTPUT_KD_PROTOCOL      0x80000000
// Remoting output.
#define DEBUG_IOUTPUT_REMOTING         0x40000000
// Breakpoint output.
#define DEBUG_IOUTPUT_BREAKPOINT       0x20000000
// Event output.
#define DEBUG_IOUTPUT_EVENT            0x10000000
// Virtual/Physical address translation
#define DEBUG_IOUTPUT_ADDR_TRANSLATE   0x08000000

// OutputIdentity flags.
#define DEBUG_OUTPUT_IDENTITY_DEFAULT 0x00000000

IDebugClient STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
	AttachKernel PTR
	GetKernelConnectionOptions PTR
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
	SetKernelConnectionOptions PTR

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
	StartProcessServer PTR
	ConnectProcessServer PTR
	DisconnectProcessServer PTR

    // Enumerates and describes processes
    // accessible through the given process server.
	GetRunningProcessSystemIds PTR
	GetRunningProcessSystemIdByExecutableName PTR
	GetRunningProcessDescription PTR

    // Attaches to a running user-mode process.
	AttachProcess PTR
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
	CreateProcess PTR
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
	CreateProcessAndAttach PTR
    // Gets and sets process control flags.
	GetProcessOptions PTR
	AddProcessOptions PTR
	RemoveProcessOptions PTR
	SetProcessOptions PTR

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
	OpenDumpFile PTR
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
	WriteDumpFile PTR

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
	ConnectSession PTR
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
	StartServer PTR
    // List the servers running on the given machine.
    // Uses the line prefix.
	OutputServers PTR

    // Attempts to terminate all processes in the debuggers list.
	TerminateProcesses PTR
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
	DetachProcesses PTR
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
	EndSession PTR
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
	GetExitCode PTR

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
	DispatchCallbacks PTR
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
	ExitDispatch PTR

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
	CreateClient PTR

	GetInputCallbacks PTR
	SetInputCallbacks PTR

    // Output callback interfaces are described separately.
	GetOutputCallbacks PTR
	SetOutputCallbacks PTR
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
	GetOutputMask PTR
	SetOutputMask PTR
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
	GetOtherOutputMask PTR
	SetOtherOutputMask PTR
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
	GetOutputWidth PTR
	SetOutputWidth PTR
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
	GetOutputLinePrefix PTR
	SetOutputLinePrefix PTR

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
	GetIdentity PTR
    // Format is a printf-like format string
    // with one %s where the identity string should go.
	OutputIdentity PTR

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
	GetEventCallbacks PTR
	SetEventCallbacks PTR

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
	FlushCallbacks PTR
ENDS

// Per-dump-format control flags.
#define DEBUG_FORMAT_DEFAULT                  0x00000000
// When creating a CAB with secondary images do searches
// for all image files, regardless of whether they're
// needed for the current session or not.
#define DEBUG_FORMAT_CAB_SECONDARY_ALL_IMAGES 0x10000000
// Write dump to a temporary file, then package it
// into a CAB file and delete the temporary file.
#define DEBUG_FORMAT_WRITE_CAB                0x20000000
// When creating a CAB add secondary files such as
// current symbols and mapped images.
#define DEBUG_FORMAT_CAB_SECONDARY_FILES      0x40000000
// Don't overwrite existing files.
#define DEBUG_FORMAT_NO_OVERWRITE             0x80000000

#define DEBUG_FORMAT_USER_SMALL_FULL_MEMORY               0x00000001
#define DEBUG_FORMAT_USER_SMALL_HANDLE_DATA               0x00000002
#define DEBUG_FORMAT_USER_SMALL_UNLOADED_MODULES          0x00000004
#define DEBUG_FORMAT_USER_SMALL_INDIRECT_MEMORY           0x00000008
#define DEBUG_FORMAT_USER_SMALL_DATA_SEGMENTS             0x00000010
#define DEBUG_FORMAT_USER_SMALL_FILTER_MEMORY             0x00000020
#define DEBUG_FORMAT_USER_SMALL_FILTER_PATHS              0x00000040
#define DEBUG_FORMAT_USER_SMALL_PROCESS_THREAD_DATA       0x00000080
#define DEBUG_FORMAT_USER_SMALL_PRIVATE_READ_WRITE_MEMORY 0x00000100
#define DEBUG_FORMAT_USER_SMALL_NO_OPTIONAL_DATA          0x00000200
#define DEBUG_FORMAT_USER_SMALL_FULL_MEMORY_INFO          0x00000400
#define DEBUG_FORMAT_USER_SMALL_THREAD_INFO               0x00000800
#define DEBUG_FORMAT_USER_SMALL_CODE_SEGMENTS             0x00001000
#define DEBUG_FORMAT_USER_SMALL_NO_AUXILIARY_STATE        0x00002000
#define DEBUG_FORMAT_USER_SMALL_FULL_AUXILIARY_STATE      0x00004000
#define DEBUG_FORMAT_USER_SMALL_IGNORE_INACCESSIBLE_MEM   0x08000000

//
// Dump information file types.
//

// Base dump file, returned when querying for dump files.
#define DEBUG_DUMP_FILE_BASE           0xffffffff
// Single file containing packed page file information.
#define DEBUG_DUMP_FILE_PAGE_FILE_DUMP 0x00000000

IDebugClient2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
	AttachKernel PTR
	GetKernelConnectionOptions PTR
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
	SetKernelConnectionOptions PTR

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
	StartProcessServer PTR
	ConnectProcessServer PTR
	DisconnectProcessServer PTR

    // Enumerates and describes processes
    // accessible through the given process server.
	GetRunningProcessSystemIds PTR
	GetRunningProcessSystemIdByExecutableName PTR
	GetRunningProcessDescription PTR

    // Attaches to a running user-mode process.
	AttachProcess PTR
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
	CreateProcess PTR
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
	CreateProcessAndAttach PTR
    // Gets and sets process control flags.
	GetProcessOptions PTR
	AddProcessOptions PTR
	RemoveProcessOptions PTR
	SetProcessOptions PTR

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
	OpenDumpFile PTR
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
	WriteDumpFile PTR

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
	ConnectSession PTR
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
	StartServer PTR
    // List the servers running on the given machine.
    // Uses the line prefix.
	OutputServers PTR

    // Attempts to terminate all processes in the debuggers list.
	TerminateProcesses PTR
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
	DetachProcesses PTR
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
	EndSession PTR
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
	GetExitCode PTR

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
	DispatchCallbacks PTR
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
	ExitDispatch PTR

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
	CreateClient PTR

	GetInputCallbacks PTR
	SetInputCallbacks PTR

    // Output callback interfaces are described separately.
	GetOutputCallbacks PTR
	SetOutputCallbacks PTR
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
	GetOutputMask PTR
	SetOutputMask PTR
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
	GetOtherOutputMask PTR
	SetOtherOutputMask PTR
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
	GetOutputWidth PTR
	SetOutputWidth PTR
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
	GetOutputLinePrefix PTR
	SetOutputLinePrefix PTR

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
	GetIdentity PTR
    // Format is a printf-like format string
    // with one %s where the identity string should go.
	OutputIdentity PTR

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
	GetEventCallbacks PTR
	SetEventCallbacks PTR

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
	FlushCallbacks PTR

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
	WriteDumpFile2 PTR
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
	AddDumpInformationFile PTR
    // Requests that the remote process server shut down.
	EndProcessServer PTR
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
	WaitForProcessServerEnd PTR
    // Returns S_OK if the system is configured
    // to allow kernel debugging.
	IsKernelDebuggerEnabled PTR
    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
	TerminateCurrentProcess PTR
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
	DetachCurrentProcess PTR
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
	AbandonCurrentProcess PTR
ENDS

IDebugClient3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
	AttachKernel PTR
	GetKernelConnectionOptions PTR
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
	SetKernelConnectionOptions PTR

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
	StartProcessServer PTR
	ConnectProcessServer PTR
	DisconnectProcessServer PTR

    // Enumerates and describes processes
    // accessible through the given process server.
	GetRunningProcessSystemIds PTR
	GetRunningProcessSystemIdByExecutableName PTR
	GetRunningProcessDescription PTR

    // Attaches to a running user-mode process.
	AttachProcess PTR
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
	CreateProcess PTR
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
	CreateProcessAndAttach PTR
    // Gets and sets process control flags.
	GetProcessOptions PTR
	AddProcessOptions PTR
	RemoveProcessOptions PTR
	SetProcessOptions PTR

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
	OpenDumpFile PTR
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
	WriteDumpFile PTR

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
	ConnectSession PTR
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
	StartServer PTR
    // List the servers running on the given machine.
    // Uses the line prefix.
	OutputServers PTR

    // Attempts to terminate all processes in the debuggers list.
	TerminateProcesses PTR
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
	DetachProcesses PTR
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
	EndSession PTR
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
	GetExitCode PTR

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
	DispatchCallbacks PTR
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
	ExitDispatch PTR

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
	CreateClient PTR

	GetInputCallbacks PTR
	SetInputCallbacks PTR

    // Output callback interfaces are described separately.
	GetOutputCallbacks PTR
	SetOutputCallbacks PTR
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
	GetOutputMask PTR
	SetOutputMask PTR
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
	GetOtherOutputMask PTR
	SetOtherOutputMask PTR
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
	GetOutputWidth PTR
	SetOutputWidth PTR
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
	GetOutputLinePrefix PTR
	SetOutputLinePrefix PTR

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
	GetIdentity PTR
    // Format is a printf-like format string
    // with one %s where the identity string should go.
	OutputIdentity PTR

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
	GetEventCallbacks PTR
	SetEventCallbacks PTR

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
	FlushCallbacks PTR

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
	WriteDumpFile2 PTR
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
	AddDumpInformationFile PTR
    // Requests that the remote process server shut down.
	EndProcessServer PTR
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
	WaitForProcessServerEnd PTR
    // Returns S_OK if the system is configured
    // to allow kernel debugging.
	IsKernelDebuggerEnabled PTR
    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
	TerminateCurrentProcess PTR
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
	DetachCurrentProcess PTR
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
	AbandonCurrentProcess PTR

    // IDebugClient3.

	GetRunningProcessSystemIdByExecutableNameWide PTR
	GetRunningProcessDescriptionWide PTR
	CreateProcessWide PTR
	CreateProcessAndAttachWide PTR
ENDS

//
// Special indices for GetDumpFile to return
// alternate filenames.
//

// Special index that returns the name of the last .dmp file
// that failed to load (whether directly or from inside a
// .cab file).
#define DEBUG_DUMP_FILE_LOAD_FAILED_INDEX  0xffffffff
// Index that returns last cab file opened, this is needed to
// get the name of original CAB file since debugger returns the
// extracted dump file in the GetDumpFile method.
#define DEBUG_DUMP_FILE_ORIGINAL_CAB_INDEX 0xfffffffe

IDebugClient4 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
	AttachKernel PTR
	GetKernelConnectionOptions PTR
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
	SetKernelConnectionOptions PTR

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
	StartProcessServer PTR
	ConnectProcessServer PTR
	DisconnectProcessServer PTR

    // Enumerates and describes processes
    // accessible through the given process server.
	GetRunningProcessSystemIds PTR
	GetRunningProcessSystemIdByExecutableName PTR
	GetRunningProcessDescription PTR

    // Attaches to a running user-mode process.
	AttachProcess PTR
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
	CreateProcess PTR
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
	CreateProcessAndAttach PTR
    // Gets and sets process control flags.
	GetProcessOptions PTR
	AddProcessOptions PTR
	RemoveProcessOptions PTR
	SetProcessOptions PTR

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
	OpenDumpFile PTR
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
	WriteDumpFile PTR

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
	ConnectSession PTR
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
	StartServer PTR
    // List the servers running on the given machine.
    // Uses the line prefix.
	OutputServers PTR

    // Attempts to terminate all processes in the debuggers list.
	TerminateProcesses PTR
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
	DetachProcesses PTR
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
	EndSession PTR
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
	GetExitCode PTR

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
	DispatchCallbacks PTR
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
	ExitDispatch PTR

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
	CreateClient PTR

	GetInputCallbacks PTR
	SetInputCallbacks PTR

    // Output callback interfaces are described separately.
	GetOutputCallbacks PTR
	SetOutputCallbacks PTR
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
	GetOutputMask PTR
	SetOutputMask PTR
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
	GetOtherOutputMask PTR
	SetOtherOutputMask PTR
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
	GetOutputWidth PTR
	SetOutputWidth PTR
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
	GetOutputLinePrefix PTR
	SetOutputLinePrefix PTR

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
	GetIdentity PTR
    // Format is a printf-like format string
    // with one %s where the identity string should go.
	OutputIdentity PTR

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
	GetEventCallbacks PTR
	SetEventCallbacks PTR

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
	FlushCallbacks PTR

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
	WriteDumpFile2 PTR
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
	AddDumpInformationFile PTR
    // Requests that the remote process server shut down.
	EndProcessServer PTR
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
	WaitForProcessServerEnd PTR
    // Returns S_OK if the system is configured
    // to allow kernel debugging.
	IsKernelDebuggerEnabled PTR
    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
	TerminateCurrentProcess PTR
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
	DetachCurrentProcess PTR
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
	AbandonCurrentProcess PTR

    // IDebugClient3.

	GetRunningProcessSystemIdByExecutableNameWide PTR
	GetRunningProcessDescriptionWide PTR
	CreateProcessWide PTR
	CreateProcessAndAttachWide PTR
    // IDebugClient4.

    // In the following methods both a filename and a file
    // handle can be passed in.  If a file handle is given
    // the filename may be omitted, although providing it
    // allows the debugger to properly report the name when
    // queried.
    // File handles cannot be used in remote calls.
	OpenDumpFileWide PTR
	WriteDumpFileWide PTR
	AddDumpInformationFileWide PTR
    // These methods can be used to retrieve
    // file information for all targets that
    // involve files.
	GetNumberDumpFiles PTR
	GetDumpFile PTR
	GetDumpFileWide PTR
ENDS

IDebugClient5 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugClient.

    // The following set of methods start
    // the different kinds of debuggees.

    // Begins a debug session using the kernel
    // debugging protocol.  This method selects
    // the protocol as the debuggee communication
    // mechanism but does not initiate the communication
    // itself.
	AttachKernel PTR
	GetKernelConnectionOptions PTR
    // Updates the connection options for a live
    // kernel connection.  This can only be used
    // to modify parameters for the connection, not
    // to switch to a completely different kind of
    // connection.
    // This method is reentrant.
	SetKernelConnectionOptions PTR

    // Starts a process server for remote
    // user-mode process control.
    // The local process server is server zero.
	StartProcessServer PTR
	ConnectProcessServer PTR
	DisconnectProcessServer PTR

    // Enumerates and describes processes
    // accessible through the given process server.
	GetRunningProcessSystemIds PTR
	GetRunningProcessSystemIdByExecutableName PTR
	GetRunningProcessDescription PTR

    // Attaches to a running user-mode process.
	AttachProcess PTR
    // Creates a new user-mode process for debugging.
    // CreateFlags are as given to Win32s CreateProcess.
    // One of DEBUG_PROCESS or DEBUG_ONLY_THIS_PROCESS
    // must be specified.
	CreateProcess PTR
    // Creates or attaches to a user-mode process, or both.
    // If CommandLine is NULL this method operates as
    // AttachProcess does.  If ProcessId is zero it
    // operates as CreateProcess does.  If CommandLine is
    // non-NULL and ProcessId is non-zero the method first
    // starts a process with the given information but
    // in a suspended state.  The engine then attaches to
    // the indicated process.  Once the attach is successful
    // the suspended process is resumed.  This provides
    // synchronization between the new process and the
    // attachment.
	CreateProcessAndAttach PTR
    // Gets and sets process control flags.
	GetProcessOptions PTR
	AddProcessOptions PTR
	RemoveProcessOptions PTR
	SetProcessOptions PTR

    // Opens any kind of user- or kernel-mode dump file
    // and begins a debug session with the information
    // contained within it.
	OpenDumpFile PTR
    // Writes a dump file from the current session information.
    // The kind of dump file written is determined by the
    // kind of session and the type qualifier given.
    // For example, if the current session is a kernel
    // debug session (DEBUG_CLASS_KERNEL) and the qualifier
    // is DEBUG_DUMP_SMALL a small kernel dump will be written.
	WriteDumpFile PTR

    // Indicates that a remote client is ready to
    // begin participating in the current session.
    // HistoryLimit gives a character limit on
    // the amount of output history to be sent.
	ConnectSession PTR
    // Indicates that the engine should start accepting
    // remote connections. Options specifies connection types
    // and their parameters.  Supported strings are:
    //    npipe:Pipe=<Pipe name>
    //    tcp:Port=<IP port>
	StartServer PTR
    // List the servers running on the given machine.
    // Uses the line prefix.
	OutputServers PTR

    // Attempts to terminate all processes in the debuggers list.
	TerminateProcesses PTR
    // Attempts to detach from all processes in the debuggers list.
    // This requires OS support for debugger detach.
	DetachProcesses PTR
    // Stops the current debug session.  If a process
    // was created or attached an active EndSession can
    // terminate or detach from it.
    // If a kernel connection was opened it will be closed but the
    // target machine is otherwise unaffected.
	EndSession PTR
    // If a process was started and ran to completion
    // this method can be used to retrieve its exit code.
	GetExitCode PTR

    // Client event callbacks are called on the thread
    // of the client.  In order to give thread
    // execution to the engine for callbacks all
    // client threads should call DispatchCallbacks
    // when they are idle.  Callbacks are only
    // received when a thread calls DispatchCallbacks
    // or WaitForEvent.  WaitForEvent can only be
    // called by the thread that started the debug
    // session so all other client threads should
    // call DispatchCallbacks when possible.
    // DispatchCallbacks returns when ExitDispatch is used
    // to interrupt dispatch or when the timeout expires.
    // DispatchCallbacks dispatches callbacks for all
    // clients associated with the thread calling
    // DispatchCallbacks.
    // DispatchCallbacks returns S_FALSE when the
    // timeout expires.
	DispatchCallbacks PTR
    // ExitDispatch can be used to interrupt callback
    // dispatch when a client thread is needed by the
    // client.  This method is reentrant and can
    // be called from any thread.
	ExitDispatch PTR

    // Clients are specific to the thread that
    // created them.  Calls from other threads
    // fail immediately.  The CreateClient method
    // is a notable exception; it allows creation
    // of a new client for a new thread.
	CreateClient PTR

	GetInputCallbacks PTR
	SetInputCallbacks PTR

    // Output callback interfaces are described separately.
	GetOutputCallbacks PTR
	SetOutputCallbacks PTR
    // Output flags provide control over
    // the distribution of output among clients.
    // Output masks select which output streams
    // should be sent to the output callbacks.
    // Only Output calls with a mask that
    // contains one of the output mask bits
    // will be sent to the output callbacks.
    // These methods are reentrant.
    // If such access is not synchronized
    // disruptions in output may occur.
	GetOutputMask PTR
	SetOutputMask PTR
    // These methods allow access to another clients
    // output mask.  They are necessary for changing
    // a clients output mask when it is
    // waiting for events.  These methods are reentrant
    // and can be called from any thread.
	GetOtherOutputMask PTR
	SetOtherOutputMask PTR
    // Control the width of an output line for
    // commands which produce formatted output.
    // This setting is just a suggestion.
	GetOutputWidth PTR
	SetOutputWidth PTR
    // Some of the engines output commands produce
    // multiple lines of output.  A prefix can be
    // set that the engine will automatically output
    // for each line in that case, allowing a caller
    // to control indentation or identifying marks.
    // This is not a general setting for any output
    // with a newline in it.  Methods which use
    // the line prefix are marked in their documentation.
	GetOutputLinePrefix PTR
	SetOutputLinePrefix PTR

    // Returns a string describing the machine
    // and user this client represents.  The
    // specific content of the string varies
    // with operating system.  If the client is
    // remotely connected some network information
    // may also be present.
	GetIdentity PTR
    // Format is a printf-like format string
    // with one %s where the identity string should go.
	OutputIdentity PTR

    // Event callbacks allow a client to
    // receive notification about changes
    // during the debug session.
	GetEventCallbacks PTR
	SetEventCallbacks PTR

    // The engine sometimes merges compatible callback
    // requests to reduce callback overhead.  This is
    // most noticeable with output as small pieces of
    // output are collected into larger groups to
    // reduce the overall number of output callback calls.
    // A client can use this method to force all pending
    // callbacks to be delivered.  This is rarely necessary.
	FlushCallbacks PTR

    // IDebugClient2.

    // Functions similarly to WriteDumpFile with
    // the addition of the ability to specify
    // per-dump-format write control flags.
    // Comment is not supported in all formats.
	WriteDumpFile2 PTR
    // Registers additional files of supporting information
    // for a dump file open.  This method must be called
    // before OpenDumpFile is called.
    // The files registered may be opened at the time
    // this method is called but generally will not
    // be used until OpenDumpFile is called.
	AddDumpInformationFile PTR
    // Requests that the remote process server shut down.
	EndProcessServer PTR
    // Waits for a started process server to
    // exit.  Allows an application running a
    // process server to monitor the process
    // server so that it can tell when a remote
    // client has asked for it to exit.
    // Returns S_OK if the process server has
    // shut down and S_FALSE for a timeout.
	WaitForProcessServerEnd PTR
    // Returns S_OK if the system is configured
    // to allow kernel debugging.
	IsKernelDebuggerEnabled PTR
    // Attempts to terminate the current process.
    // Exit process events for the process may be generated.
	TerminateCurrentProcess PTR
    // Attempts to detach from the current process.
    // This requires OS support for debugger detach.
	DetachCurrentProcess PTR
    // Removes the process from the debuggers process
    // list without making any other changes.  The process
    // will still be marked as being debugged and will
    // not run.  This allows a debugger to be shut down
    // and a new debugger attached without taking the
    // process out of the debugged state.
    // This is only supported on some system versions.
	AbandonCurrentProcess PTR

    // IDebugClient3.

	GetRunningProcessSystemIdByExecutableNameWide PTR
	GetRunningProcessDescriptionWide PTR
	CreateProcessWide PTR
	CreateProcessAndAttachWide PTR
    // IDebugClient4.

    // In the following methods both a filename and a file
    // handle can be passed in.  If a file handle is given
    // the filename may be omitted, although providing it
    // allows the debugger to properly report the name when
    // queried.
    // File handles cannot be used in remote calls.
	OpenDumpFileWide PTR
	WriteDumpFileWide PTR
	AddDumpInformationFileWide PTR
    // These methods can be used to retrieve
    // file information for all targets that
    // involve files.
	GetNumberDumpFiles PTR
	GetDumpFile PTR
	GetDumpFileWide PTR

    // IDebugClient5.
	AttachKernelWide PTR
	GetKernelConnectionOptionsWide PTR
	SetKernelConnectionOptionsWide PTR
	StartProcessServerWide PTR
	ConnectProcessServerWide PTR
	StartServerWide PTR
	OutputServersWide PTR
	GetOutputCallbacksWide PTR
	SetOutputCallbacksWide PTR
	GetOutputLinePrefixWide PTR
	SetOutputLinePrefixWide PTR
	GetIdentityWide PTR
	OutputIdentityWide PTR
	GetEventCallbacksWide PTR
	SetEventCallbacksWide PTR
	CreateProcess2 PTR
	CreateProcess2Wide PTR
	CreateProcessAndAttach2 PTR
	CreateProcessAndAttach2Wide PTR
    // Helpers for saving and restoring the
    // current output line prefix.
	PushOutputLinePrefix PTR
	PushOutputLinePrefixWide PTR
	PopOutputLinePrefix PTR
    // Queries to determine if any clients
    // could potentially respond to the given callback.
	GetNumberInputCallbacks PTR
	GetNumberOutputCallbacks PTR
	GetNumberEventCallbacks PTR
    // Control over locking the session against
    // undesired quits.  The quit lock string
    // cannot be retrieved from a secure session.
	GetQuitLockString PTR
	SetQuitLockString PTR
	GetQuitLockStringWide PTR
	SetQuitLockStringWide PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugControl.
//
//----------------------------------------------------------------------------

// Execution status codes used for waiting,
// for returning current status and for
// event method return values.
#define DEBUG_STATUS_NO_CHANGE           0
#define DEBUG_STATUS_GO                  1
#define DEBUG_STATUS_GO_HANDLED          2
#define DEBUG_STATUS_GO_NOT_HANDLED      3
#define DEBUG_STATUS_STEP_OVER           4
#define DEBUG_STATUS_STEP_INTO           5
#define DEBUG_STATUS_BREAK               6
#define DEBUG_STATUS_NO_DEBUGGEE         7
#define DEBUG_STATUS_STEP_BRANCH         8
#define DEBUG_STATUS_IGNORE_EVENT        9
#define DEBUG_STATUS_RESTART_REQUESTED   10
#define DEBUG_STATUS_REVERSE_GO          11
#define DEBUG_STATUS_REVERSE_STEP_BRANCH 12
#define DEBUG_STATUS_REVERSE_STEP_OVER   13
#define DEBUG_STATUS_REVERSE_STEP_INTO   14

#define DEBUG_STATUS_MASK                0xf

// This bit is added in DEBUG_CES_EXECUTION_STATUS
// notifications when the engines execution status
// is changing due to operations performed during
// a wait, such as making synchronous callbacks.  If
// the bit is not set the execution status is changing
// due to a wait being satisfied.
#define DEBUG_STATUS_INSIDE_WAIT  0x100000000
// This bit is added in DEBUG_CES_EXECUTION_STATUS
// notifications when the engines execution status
// update is coming after a wait has timed-out.
// It indicates that the execution status change
// was not due to an actual event.
#define DEBUG_STATUS_WAIT_TIMEOUT 0x200000000

// Output control flags.
// Output generated by methods called by this
// client will be sent only to this clients
// output callbacks.
#define DEBUG_OUTCTL_THIS_CLIENT       0x00000000
// Output will be sent to all clients.
#define DEBUG_OUTCTL_ALL_CLIENTS       0x00000001
// Output will be sent to all clients except
// the client generating the output.
#define DEBUG_OUTCTL_ALL_OTHER_CLIENTS 0x00000002
// Output will be discarded immediately and will not
// be logged or sent to callbacks.
#define DEBUG_OUTCTL_IGNORE            0x00000003
// Output will be logged but not sent to callbacks.
#define DEBUG_OUTCTL_LOG_ONLY          0x00000004
// All send control bits.
#define DEBUG_OUTCTL_SEND_MASK         0x00000007
// Do not place output from this client in
// the global log file.
#define DEBUG_OUTCTL_NOT_LOGGED        0x00000008
// Send output to clients regardless of whether the
// mask allows it or not.
#define DEBUG_OUTCTL_OVERRIDE_MASK     0x00000010
// Text is markup instead of plain text.
#define DEBUG_OUTCTL_DML               0x00000020

// Special values which mean leave the output settings
// unchanged.
#define DEBUG_OUTCTL_AMBIENT_DML       0xfffffffe
#define DEBUG_OUTCTL_AMBIENT_TEXT      0xffffffff

// Old ambient flag which maps to text.
#define DEBUG_OUTCTL_AMBIENT           DEBUG_OUTCTL_AMBIENT_TEXT

// Interrupt types.
// Force a break in if the debuggee is running.
#define DEBUG_INTERRUPT_ACTIVE  0
// Notify but do not force a break in.
#define DEBUG_INTERRUPT_PASSIVE 1
// Try and get the current engine operation to
// complete so that the engine will be available
// again.  If no wait is active this is the same
// as a passive interrupt.  If a wait is active
// this will try to cause the wait to fail without
// breaking in to the debuggee.  There is
// no guarantee that issuing an exit interrupt
// will cause the engine to become available
// as not all operations are arbitrarily
// interruptible.
#define DEBUG_INTERRUPT_EXIT    2

// OutputCurrentState flags.  These flags
// allow a particular type of information
// to be displayed but do not guarantee
// that it will be displayed.  Other global
// settings may override these flags or
// the particular state may not be available.
// For example, source line information may
// not be present so source line information
// may not be displayed.
#define DEBUG_CURRENT_DEFAULT     0x0000000f
#define DEBUG_CURRENT_SYMBOL      0x00000001
#define DEBUG_CURRENT_DISASM      0x00000002
#define DEBUG_CURRENT_REGISTERS   0x00000004
#define DEBUG_CURRENT_SOURCE_LINE 0x00000008

//
// Disassemble flags.
//

// Compute the effective address from current register
// information and display it.
#define DEBUG_DISASM_EFFECTIVE_ADDRESS  0x00000001
// If the current disassembly offset has an exact
// symbol match output the symbol.
#define DEBUG_DISASM_MATCHING_SYMBOLS   0x00000002
// Output the source line number for each disassembly offset.
#define DEBUG_DISASM_SOURCE_LINE_NUMBER 0x00000004
// Output the source file name (no path) for each disassembly offset.
#define DEBUG_DISASM_SOURCE_FILE_NAME   0x00000008

// Code interpretation levels for stepping
// and other operations.
#define DEBUG_LEVEL_SOURCE   0
#define DEBUG_LEVEL_ASSEMBLY 1

// Engine control flags.
#define DEBUG_ENGOPT_IGNORE_DBGHELP_VERSION      0x00000001
#define DEBUG_ENGOPT_IGNORE_EXTENSION_VERSIONS   0x00000002
// If neither allow nor disallow is specified
// the engine will pick one based on what kind
// of debugging is going on.
#define DEBUG_ENGOPT_ALLOW_NETWORK_PATHS         0x00000004
#define DEBUG_ENGOPT_DISALLOW_NETWORK_PATHS      0x00000008
#define DEBUG_ENGOPT_NETWORK_PATHS               (0x00000004 | 0x00000008)
// Ignore loader-generated first-chance exceptions.
#define DEBUG_ENGOPT_IGNORE_LOADER_EXCEPTIONS    0x00000010
// Break in on a debuggees initial event.  In user-mode
// this will break at the initial system breakpoint
// for every created process.  In kernel-mode it
// will attempt break in on the target at the first
// WaitForEvent.
#define DEBUG_ENGOPT_INITIAL_BREAK               0x00000020
// Break in on the first module load for a debuggee.
#define DEBUG_ENGOPT_INITIAL_MODULE_BREAK        0x00000040
// Break in on a debuggees final event.  In user-mode
// this will break on process exit for every process.
// In kernel-mode it currently does nothing.
#define DEBUG_ENGOPT_FINAL_BREAK                 0x00000080
// By default Execute will repeat the last command
// if it is given an empty string.  The flags to
// Execute can override this behavior for a single
// command or this engine option can be used to
// change the default globally.
#define DEBUG_ENGOPT_NO_EXECUTE_REPEAT           0x00000100
// Disable places in the engine that have fallback
// code when presented with incomplete information.
//   1. Fails minidump module loads unless matching
//      executables can be mapped.
#define DEBUG_ENGOPT_FAIL_INCOMPLETE_INFORMATION 0x00000200
// Allow the debugger to manipulate page protections
// in order to insert code breakpoints on pages that
// do not have write access.  This option is not on
// by default as it allows breakpoints to be set
// in potentially hazardous memory areas.
#define DEBUG_ENGOPT_ALLOW_READ_ONLY_BREAKPOINTS 0x00000400
// When using a software (bp/bu) breakpoint in code
// that will be executed by multiple threads it is
// possible for breakpoint management to cause the
// breakpoint to be missed or for spurious single-step
// exceptions to be generated.  This flag suspends
// all but the active thread when doing breakpoint
// management and thereby avoids multithreading
// problems.  Care must be taken when using it, though,
// as the suspension of threads can cause deadlocks
// if the suspended threads are holding resources that
// the active thread needs.  Additionally, there
// are still rare situations where problems may
// occur, but setting this flag corrects nearly
// all multithreading issues with software breakpoints.
// Thread-restricted stepping and execution supersedes
// this flags effect.
// This flag is ignored in kernel sessions as there
// is no way to restrict processor execution.
#define DEBUG_ENGOPT_SYNCHRONIZE_BREAKPOINTS     0x00000800
// Disallows executing shell commands through the
// engine with .shell (!!).
#define DEBUG_ENGOPT_DISALLOW_SHELL_COMMANDS     0x00001000
// Turns on "quiet mode", a somewhat less verbose mode
// of operation supported in the debuggers that were
// superseded by dbgeng.dll.  This equates to the KDQUIET
// environment variable.
#define DEBUG_ENGOPT_KD_QUIET_MODE               0x00002000
// Disables managed code debugging support in the engine.
// If managed support is already in use this flag has no effect.
#define DEBUG_ENGOPT_DISABLE_MANAGED_SUPPORT     0x00004000
// Disables symbol loading for all modules created
// after this flag is set.
#define DEBUG_ENGOPT_DISABLE_MODULE_SYMBOL_LOAD  0x00008000
// Disables execution commands.
#define DEBUG_ENGOPT_DISABLE_EXECUTION_COMMANDS  0x00010000
// Disallows mapping of image files from disk for any use.
// For example, this disallows image mapping for memory
// content when debugging minidumps.
// Does not affect existing mappings, only future attempts.
#define DEBUG_ENGOPT_DISALLOW_IMAGE_FILE_MAPPING 0x00020000
// Requests that dbgeng run DML-enhanced versions of commands
// and operations by default.
#define DEBUG_ENGOPT_PREFER_DML                  0x00040000
#define DEBUG_ENGOPT_ALL                         0x0007FFFF

// General unspecified ID constant.
#define DEBUG_ANY_ID 0xffffffff

DEBUG_STACK_FRAME STRUCT
	InstructionOffset DQ
	ReturnOffset DQ
	FrameOffset DQ
	StackOffset DQ
	FuncTableEntry DQ
	Params DQ 4 DUP
	Reserved DQ 6 DUP
	Virtual BOOL
	FrameNumber DD
ENDS

// OutputStackTrace flags.
// Display a small number of arguments for each call.
// These may or may not be the actual arguments depending
// on the architecture, particular function and
// point during the execution of the function.
// If the current code level is assembly arguments
// are dumped as hex values.  If the code level is
// source the engine attempts to provide symbolic
// argument information.
#define DEBUG_STACK_ARGUMENTS               0x00000001
// Displays information about the functions
// frame such as __stdcall arguments, FPO
// information and whatever else is available.
#define DEBUG_STACK_FUNCTION_INFO           0x00000002
// Displays source line information for each
// frame of the stack trace.
#define DEBUG_STACK_SOURCE_LINE             0x00000004
// Show return, previous frame and other relevant address
// values for each frame.
#define DEBUG_STACK_FRAME_ADDRESSES         0x00000008
// Show column names.
#define DEBUG_STACK_COLUMN_NAMES            0x00000010
// Show non-volatile register context for each
// frame.  This is only meaningful for some platforms.
#define DEBUG_STACK_NONVOLATILE_REGISTERS   0x00000020
// Show frame numbers
#define DEBUG_STACK_FRAME_NUMBERS           0x00000040
// Show typed source parameters.
#define DEBUG_STACK_PARAMETERS              0x00000080
// Show just return address in stack frame addresses.
#define DEBUG_STACK_FRAME_ADDRESSES_RA_ONLY 0x00000100
// Show frame-to-frame memory usage.
#define DEBUG_STACK_FRAME_MEMORY_USAGE      0x00000200
// Show typed source parameters one to a line.
#define DEBUG_STACK_PARAMETERS_NEWLINE      0x00000400
// Produce stack output enhanced with DML content.
#define DEBUG_STACK_DML                     0x00000800
// Show offset from stack frame
#define DEBUG_STACK_FRAME_OFFSETS           0x00001000

// Classes of debuggee.  Each class
// has different qualifiers for specific
// kinds of debuggees.
#define DEBUG_CLASS_UNINITIALIZED 0
#define DEBUG_CLASS_KERNEL        1
#define DEBUG_CLASS_USER_WINDOWS  2
#define DEBUG_CLASS_IMAGE_FILE    3

// Generic dump types.  These can be used
// with either user or kernel sessions.
// Session-type-specific aliases are also
// provided.
#define DEBUG_DUMP_SMALL      1024
#define DEBUG_DUMP_DEFAULT    1025
#define DEBUG_DUMP_FULL       1026
#define DEBUG_DUMP_IMAGE_FILE 1027
#define DEBUG_DUMP_TRACE_LOG  1028
#define DEBUG_DUMP_WINDOWS_CE 1029

// Specific types of kernel debuggees.
#define DEBUG_KERNEL_CONNECTION     0
#define DEBUG_KERNEL_LOCAL          1
#define DEBUG_KERNEL_EXDI_DRIVER    2
#define DEBUG_KERNEL_IDNA           3
#define DEBUG_KERNEL_INSTALL_DRIVER 4

#define DEBUG_KERNEL_SMALL_DUMP  DEBUG_DUMP_SMALL
#define DEBUG_KERNEL_DUMP        DEBUG_DUMP_DEFAULT
#define DEBUG_KERNEL_FULL_DUMP   DEBUG_DUMP_FULL

#define DEBUG_KERNEL_TRACE_LOG   DEBUG_DUMP_TRACE_LOG

// Specific types of Windows user debuggees.
#define DEBUG_USER_WINDOWS_PROCESS         0
#define DEBUG_USER_WINDOWS_PROCESS_SERVER  1
#define DEBUG_USER_WINDOWS_IDNA            2
#define DEBUG_USER_WINDOWS_SMALL_DUMP      DEBUG_DUMP_SMALL
#define DEBUG_USER_WINDOWS_DUMP            DEBUG_DUMP_DEFAULT
#define DEBUG_USER_WINDOWS_DUMP_WINDOWS_CE DEBUG_DUMP_WINDOWS_CE

// Extension flags.
#define DEBUG_EXTENSION_AT_ENGINE 0x00000000

// Execute and ExecuteCommandFile flags.
// These flags only apply to the command
// text itself; output from the executed
// command is controlled by the output
// control parameter.
// Default execution.  Command is logged
// but not output.
#define DEBUG_EXECUTE_DEFAULT    0x00000000
// Echo commands during execution.  In
// ExecuteCommandFile also echoes the prompt
// for each line of the file.
#define DEBUG_EXECUTE_ECHO       0x00000001
// Do not log or output commands during execution.
// Overridden by DEBUG_EXECUTE_ECHO.
#define DEBUG_EXECUTE_NOT_LOGGED 0x00000002
// If this flag is not set an empty string
// to Execute will repeat the last Execute
// string.
#define DEBUG_EXECUTE_NO_REPEAT  0x00000004

// Specific event filter types.  Some event
// filters have optional arguments to further
// qualify their operation.
#define DEBUG_FILTER_CREATE_THREAD       0x00000000
#define DEBUG_FILTER_EXIT_THREAD         0x00000001
#define DEBUG_FILTER_CREATE_PROCESS      0x00000002
#define DEBUG_FILTER_EXIT_PROCESS        0x00000003
// Argument is the name of a module to break on.
#define DEBUG_FILTER_LOAD_MODULE         0x00000004
// Argument is the base address of a specific module to break on.
#define DEBUG_FILTER_UNLOAD_MODULE       0x00000005
#define DEBUG_FILTER_SYSTEM_ERROR        0x00000006
// Initial breakpoint and initial module load are one-shot
// events that are triggered at the appropriate points in
// the beginning of a session.  Their commands are executed
// and then further processing is controlled by the normal
// exception and load module filters.
#define DEBUG_FILTER_INITIAL_BREAKPOINT  0x00000007
#define DEBUG_FILTER_INITIAL_MODULE_LOAD 0x00000008
// The debug output filter allows the debugger to stop
// when output is produced so that the code causing
// output can be tracked down or synchronized with.
// This filter is not supported for live dual-machine
// kernel debugging.
#define DEBUG_FILTER_DEBUGGEE_OUTPUT     0x00000009

// Event filter execution options.
// Break in always.
#define DEBUG_FILTER_BREAK               0x00000000
// Break in on second-chance exceptions.  For events
// that are not exceptions this is the same as BREAK.
#define DEBUG_FILTER_SECOND_CHANCE_BREAK 0x00000001
// Output a message about the event but continue.
#define DEBUG_FILTER_OUTPUT              0x00000002
// Continue the event.
#define DEBUG_FILTER_IGNORE              0x00000003
// Used to remove general exception filters.
#define DEBUG_FILTER_REMOVE              0x00000004

// Event filter continuation options.  These options are
// only used when DEBUG_STATUS_GO is used to continue
// execution.  If a specific go status such as
// DEBUG_STATUS_GO_NOT_HANDLED is used it controls
// the continuation.
#define DEBUG_FILTER_GO_HANDLED          0x00000000
#define DEBUG_FILTER_GO_NOT_HANDLED      0x00000001

// Specific event filter settings.
DEBUG_SPECIFIC_FILTER_PARAMETERS STRUCT
	ExecutionOption DD
	ContinueOption DD
	TextSize DD
	CommandSize DD
    // If ArgumentSize is zero this filter does
    // not have an argument.  An empty argument for
    // a filter which does have an argument will take
    // one byte for the terminator.
	ArgumentSize DD
ENDS

// Exception event filter settings.
DEBUG_EXCEPTION_FILTER_PARAMETERS STRUCT
	ExecutionOption DD
	ContinueOption DD
	TextSize DD
	CommandSize DD
	SecondCommandSize DD
	ExceptionCode DD
ENDS

// Wait flags.
#define DEBUG_WAIT_DEFAULT 0x00000000

// Last event information structures.
DEBUG_LAST_EVENT_INFO_BREAKPOINT STRUCT
	Id DD
ENDS

DEBUG_LAST_EVENT_INFO_EXCEPTION STRUCT
	ExceptionRecord EXCEPTION_RECORD64
	FirstChance DD
ENDS

DEBUG_LAST_EVENT_INFO_EXIT_THREAD STRUCT
	ExitCode DD
ENDS

DEBUG_LAST_EVENT_INFO_EXIT_PROCESS STRUCT
	ExitCode DD
ENDS

DEBUG_LAST_EVENT_INFO_LOAD_MODULE STRUCT
	Base DQ
ENDS

DEBUG_LAST_EVENT_INFO_UNLOAD_MODULE STRUCT
	Base DQ
ENDS

DEBUG_LAST_EVENT_INFO_SYSTEM_ERROR STRUCT
	ERROR DD
	Level DD
ENDS

// DEBUG_VALUE types.
#define DEBUG_VALUE_INVALID      0
#define DEBUG_VALUE_INT8         1
#define DEBUG_VALUE_INT16        2
#define DEBUG_VALUE_INT32        3
#define DEBUG_VALUE_INT64        4
#define DEBUG_VALUE_FLOAT32      5
#define DEBUG_VALUE_FLOAT64      6
#define DEBUG_VALUE_FLOAT80      7
#define DEBUG_VALUE_FLOAT82      8
#define DEBUG_VALUE_FLOAT128     9
#define DEBUG_VALUE_VECTOR64     10
#define DEBUG_VALUE_VECTOR128    11
// Count of type indices.
#define DEBUG_VALUE_TYPES        12


// We want the DEBUG_VALUE structure to have 8-byte alignment
// and be 32 bytes total.  This is tricky because the compiler
// wants to pad the union of values out to a even 8-byte multiple,
// pushing the type out too far.  We can't use 4-packing because
// then the 8-byte alignment requirement is lost, so instead
// we shrink the union to 24 bytes and have a reserved field
// before the type field.  The same amount of space is available
// and everybody's happy, but the structure is somewhat unusual.

DEBUG_VALUE STRUCT
	UNION
		I8 DB
		I16 DW
		I32 DD
        STRUCT
            // Extra NAT indicator for IA64
            // integer registers.  NAT will
            // always be false for other CPUs.
			I64 DQ
			Nat BOOL
		ENDS
		F32 FLOAT
		F64 DOUBLE
		F80Bytes DB 10 DUP
		F82Bytes DB 11 DUP
		F128Bytes DB 16 DUP
        // Vector interpretations.  The actual number
        // of valid elements depends on the vector length.
		VI8 DB 16 DUP
		VI16 DW 8 DUP
		VI32 DD 4 DUP
		VI64 DQ 2 DUP
		VF32 FLOAT 4 DUP
		VF64 DOUBLE 2 DUP
		I64Parts32 STRUCT
			LowPart DD
			HighPart DD
		ENDS
        F128Parts64 struct
			LowPart DQ
			HighPart DQ
		ENDS
        // Allows raw byte access to content.  Array
        // can be indexed for as much data as Type
        // describes.  This array also serves to pad
        // the structure out to 32 bytes and reserves
        // space for future members.
		RawBytes DB 24 DUP
    ENDUNION
	TailOfRawBytes DD
	Type DD
ENDS

IDebugControl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
	GetInterrupt PTR
    // Registers a user interrupt.
    // This method is reentrant.
	SetInterrupt PTR
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
	GetInterruptTimeout PTR
	SetInterruptTimeout PTR
	GetLogFile PTR
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
	OpenLogFile PTR
	CloseLogFile PTR
    // Controls what output is logged.
	GetLogMask PTR
	SetLogMask PTR
    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
	Input PTR
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
	ReturnInput PTR
    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
	Output PTR
	OutputVaList PTR
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
	ControlledOutput PTR
	ControlledOutputVaList PTR
    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
	OutputPrompt PTR
	OutputPromptVaList PTR
    // Gets the text that would be displayed by OutputPrompt.
	GetPromptText PTR
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
	OutputCurrentState PTR
    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
	OutputVersionInformation PTR
    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
	GetNotifyEventHandle PTR
	SetNotifyEventHandle PTR
	Assemble PTR
	Disassemble PTR
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
	GetDisassembleEffectiveOffset PTR
    // Uses the line prefix if necessary.
	OutputDisassembly PTR
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
	OutputDisassemblyLines PTR
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
	GetNearInstruction PTR
    // Offsets can be passed in as zero to use the current
    // thread state.
	GetStackTrace PTR
    // Does a simple stack trace to determine
    // what the current return address is.
	GetReturnOffset PTR
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
	OutputStackTrace PTR
    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
	GetDebuggeeType PTR
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
	GetActualProcessorType PTR
    // Returns the type of processor used in the
    // current processor context.
	GetExecutingProcessorType PTR
    // Query all the possible processor types that
    // may be encountered during this debug session.
	GetNumberPossibleExecutingProcessorTypes PTR
	GetPossibleExecutingProcessorTypes PTR
    // Get the number of actual processors in
    // the machine.
	GetNumberProcessors PTR
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
	GetSystemVersion PTR
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
	GetPageSize PTR
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
	IsPointer64Bit PTR
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
	ReadBugCheckData PTR
    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
	GetNumberSupportedProcessorTypes PTR
	GetSupportedProcessorTypes PTR
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
	GetProcessorTypeNames PTR
    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
	GetEffectiveProcessorType PTR
	SetEffectiveProcessorType PTR
    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
	GetExecutionStatus PTR
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
	SetExecutionStatus PTR
    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
	GetCodeLevel PTR
	SetCodeLevel PTR
    // Gets and sets engine control flags.
    // These methods are reentrant.
	GetEngineOptions PTR
	AddEngineOptions PTR
	RemoveEngineOptions PTR
	SetEngineOptions PTR
    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
	GetSystemErrorControl PTR
	SetSystemErrorControl PTR
    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
	GetTextMacro PTR
	SetTextMacro PTR
    // Controls the default number radix used
    // in expressions and commands.
	GetRadix PTR
	SetRadix PTR
    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
	Evaluate PTR
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
	CoerceValue PTR
	CoerceValues PTR
    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
	Execute PTR
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
	ExecuteCommandFile PTR
    // Breakpoint interfaces are described
    // elsewhere in this section.
	GetNumberBreakpoints PTR
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
	GetBreakpointByIndex PTR
	GetBreakpointById PTR
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
	GetBreakpointParameters PTR
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
	AddBreakpoint PTR
    // Breakpoint interface is invalid after this call.
	RemoveBreakpoint PTR
    // Control and use extension DLLs.
	AddExtension PTR
	RemoveExtension PTR
	GetExtensionByPath PTR
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
	CallExtension PTR
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // _EFN_ is automatically prepended to
    // the name string given.
    // This function cannot be called remotely.
	GetExtensionFunction PTR
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
	GetWindbgExtensionApis32 PTR
	GetWindbgExtensionApis64 PTR
    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
	GetNumberEventFilters PTR
    // Some filters have descriptive text associated with them.
	GetEventFilterText PTR
    // All filters support executing a command when the
    // event occurs.
	GetEventFilterCommand PTR
	SetEventFilterCommand PTR
	GetSpecificFilterParameters PTR
	SetSpecificFilterParameters PTR
    // Some specific filters have arguments to further
    // qualify their operation.
	GetSpecificFilterArgument PTR
	SetSpecificFilterArgument PTR
    // If Codes is non-NULL Start is ignored.
	GetExceptionFilterParameters PTR
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
	SetExceptionFilterParameters PTR
    // Exception filters support an additional command for
    // second-chance events.
	GetExceptionFilterSecondCommand PTR
	SetExceptionFilterSecondCommand PTR
    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
	WaitForEvent PTR
    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
	GetLastEventInformation PTR
ENDS

// OutputTextReplacements flags.
#define DEBUG_OUT_TEXT_REPL_DEFAULT 0x00000000

IDebugControl2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
	GetInterrupt PTR
    // Registers a user interrupt.
    // This method is reentrant.
	SetInterrupt PTR
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
	GetInterruptTimeout PTR
	SetInterruptTimeout PTR
	GetLogFile PTR
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
	OpenLogFile PTR
	CloseLogFile PTR
    // Controls what output is logged.
	GetLogMask PTR
	SetLogMask PTR
    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
	Input PTR
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
	ReturnInput PTR
    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
	Output PTR
	OutputVaList PTR
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
	ControlledOutput PTR
	ControlledOutputVaList PTR
    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
	OutputPrompt PTR
	OutputPromptVaList PTR
    // Gets the text that would be displayed by OutputPrompt.
	GetPromptText PTR
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
	OutputCurrentState PTR
    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
	OutputVersionInformation PTR
    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
	GetNotifyEventHandle PTR
	SetNotifyEventHandle PTR
	Assemble PTR
	Disassemble PTR
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
	GetDisassembleEffectiveOffset PTR
    // Uses the line prefix if necessary.
	OutputDisassembly PTR
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
	OutputDisassemblyLines PTR
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
	GetNearInstruction PTR
    // Offsets can be passed in as zero to use the current
    // thread state.
	GetStackTrace PTR
    // Does a simple stack trace to determine
    // what the current return address is.
	GetReturnOffset PTR
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
	OutputStackTrace PTR
    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
	GetDebuggeeType PTR
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
	GetActualProcessorType PTR
    // Returns the type of processor used in the
    // current processor context.
	GetExecutingProcessorType PTR
    // Query all the possible processor types that
    // may be encountered during this debug session.
	GetNumberPossibleExecutingProcessorTypes PTR
	GetPossibleExecutingProcessorTypes PTR
    // Get the number of actual processors in
    // the machine.
	GetNumberProcessors PTR
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
	GetSystemVersion PTR
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
	GetPageSize PTR
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
	IsPointer64Bit PTR
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
	ReadBugCheckData PTR
    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
	GetNumberSupportedProcessorTypes PTR
	GetSupportedProcessorTypes PTR
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
	GetProcessorTypeNames PTR
    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
	GetEffectiveProcessorType PTR
	SetEffectiveProcessorType PTR
    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
	GetExecutionStatus PTR
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
	SetExecutionStatus PTR
    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
	GetCodeLevel PTR
	SetCodeLevel PTR
    // Gets and sets engine control flags.
    // These methods are reentrant.
	GetEngineOptions PTR
	AddEngineOptions PTR
	RemoveEngineOptions PTR
	SetEngineOptions PTR
    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
	GetSystemErrorControl PTR
	SetSystemErrorControl PTR
    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
	GetTextMacro PTR
	SetTextMacro PTR
    // Controls the default number radix used
    // in expressions and commands.
	GetRadix PTR
	SetRadix PTR
    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
	Evaluate PTR
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
	CoerceValue PTR
	CoerceValues PTR
    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
	Execute PTR
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
	ExecuteCommandFile PTR
    // Breakpoint interfaces are described
    // elsewhere in this section.
	GetNumberBreakpoints PTR
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
	GetBreakpointByIndex PTR
	GetBreakpointById PTR
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
	GetBreakpointParameters PTR
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
	AddBreakpoint PTR
    // Breakpoint interface is invalid after this call.
	RemoveBreakpoint PTR
    // Control and use extension DLLs.
	AddExtension PTR
	RemoveExtension PTR
	GetExtensionByPath PTR
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
	CallExtension PTR
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // _EFN_ is automatically prepended to
    // the name string given.
    // This function cannot be called remotely.
	GetExtensionFunction PTR
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
	GetWindbgExtensionApis32 PTR
	GetWindbgExtensionApis64 PTR
    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
	GetNumberEventFilters PTR
    // Some filters have descriptive text associated with them.
	GetEventFilterText PTR
    // All filters support executing a command when the
    // event occurs.
	GetEventFilterCommand PTR
	SetEventFilterCommand PTR
	GetSpecificFilterParameters PTR
	SetSpecificFilterParameters PTR
    // Some specific filters have arguments to further
    // qualify their operation.
	GetSpecificFilterArgument PTR
	SetSpecificFilterArgument PTR
    // If Codes is non-NULL Start is ignored.
	GetExceptionFilterParameters PTR
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
	SetExceptionFilterParameters PTR
    // Exception filters support an additional command for
    // second-chance events.
	GetExceptionFilterSecondCommand PTR
	SetExceptionFilterSecondCommand PTR
    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
	WaitForEvent PTR
    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
	GetLastEventInformation PTR
    // IDebugControl2.
	GetCurrentTimeDate PTR
    // Retrieves the number of seconds since the
    // machine started running.
	GetCurrentSystemUpTime PTR
    // If the current session is a dump session,
    // retrieves any extended format information.
	GetDumpFormatFlags PTR
    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
	GetNumberTextReplacements PTR
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
	GetTextReplacement PTR
    // Setting the destination text to
    // NULL removes the alias.
	SetTextReplacement PTR
	RemoveTextReplacements PTR
    // Outputs the complete list of current
    // replacements.
	OutputTextReplacements PTR
ENDS

//
// Assembly/disassembly options.
//
// The specific effects of these flags varies depending
// on the particular instruction set.
//

#define DEBUG_ASMOPT_DEFAULT             0x00000000
// Display additional information in disassembly.
#define DEBUG_ASMOPT_VERBOSE             0x00000001
// Do not display raw code bytes in disassembly.
#define DEBUG_ASMOPT_NO_CODE_BYTES       0x00000002
// Do not take the output width into account when
// formatting disassembly.
#define DEBUG_ASMOPT_IGNORE_OUTPUT_WIDTH 0x00000004
// Display source file line number before each line if available.
#define DEBUG_ASMOPT_SOURCE_LINE_NUMBER  0x00000008

//
// Expression syntax options.
//

// MASM-style expression evaluation.
#define DEBUG_EXPR_MASM      0x00000000
// C++-style expression evaluation.
#define DEBUG_EXPR_CPLUSPLUS 0x00000001

//
// Event index description information.
//

#define DEBUG_EINDEX_NAME 0x00000000

//
// SetNextEventIndex relation options.
//

// Value increases forward from the first index.
#define DEBUG_EINDEX_FROM_START   0x00000000
// Value increases backwards from the last index.
#define DEBUG_EINDEX_FROM_END     0x00000001
// Value is a signed delta from the current index.
#define DEBUG_EINDEX_FROM_CURRENT 0x00000002

IDebugControl3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
	GetInterrupt PTR
    // Registers a user interrupt.
    // This method is reentrant.
	SetInterrupt PTR
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
	GetInterruptTimeout PTR
	SetInterruptTimeout PTR
	GetLogFile PTR
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
	OpenLogFile PTR
	CloseLogFile PTR
    // Controls what output is logged.
	GetLogMask PTR
	SetLogMask PTR
    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
	Input PTR
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
	ReturnInput PTR
    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
	Output PTR
	OutputVaList PTR
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
	ControlledOutput PTR
	ControlledOutputVaList PTR
    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
	OutputPrompt PTR
	OutputPromptVaList PTR
    // Gets the text that would be displayed by OutputPrompt.
	GetPromptText PTR
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
	OutputCurrentState PTR
    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
	OutputVersionInformation PTR
    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
	GetNotifyEventHandle PTR
	SetNotifyEventHandle PTR
	Assemble PTR
	Disassemble PTR
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
	GetDisassembleEffectiveOffset PTR
    // Uses the line prefix if necessary.
	OutputDisassembly PTR
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
	OutputDisassemblyLines PTR
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
	GetNearInstruction PTR
    // Offsets can be passed in as zero to use the current
    // thread state.
	GetStackTrace PTR
    // Does a simple stack trace to determine
    // what the current return address is.
	GetReturnOffset PTR
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
	OutputStackTrace PTR
    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
	GetDebuggeeType PTR
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
	GetActualProcessorType PTR
    // Returns the type of processor used in the
    // current processor context.
	GetExecutingProcessorType PTR
    // Query all the possible processor types that
    // may be encountered during this debug session.
	GetNumberPossibleExecutingProcessorTypes PTR
	GetPossibleExecutingProcessorTypes PTR
    // Get the number of actual processors in
    // the machine.
	GetNumberProcessors PTR
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
	GetSystemVersion PTR
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
	GetPageSize PTR
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
	IsPointer64Bit PTR
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
	ReadBugCheckData PTR
    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
	GetNumberSupportedProcessorTypes PTR
	GetSupportedProcessorTypes PTR
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
	GetProcessorTypeNames PTR
    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
	GetEffectiveProcessorType PTR
	SetEffectiveProcessorType PTR
    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
	GetExecutionStatus PTR
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
	SetExecutionStatus PTR
    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
	GetCodeLevel PTR
	SetCodeLevel PTR
    // Gets and sets engine control flags.
    // These methods are reentrant.
	GetEngineOptions PTR
	AddEngineOptions PTR
	RemoveEngineOptions PTR
	SetEngineOptions PTR
    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
	GetSystemErrorControl PTR
	SetSystemErrorControl PTR
    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
	GetTextMacro PTR
	SetTextMacro PTR
    // Controls the default number radix used
    // in expressions and commands.
	GetRadix PTR
	SetRadix PTR
    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
	Evaluate PTR
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
	CoerceValue PTR
	CoerceValues PTR
    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
	Execute PTR
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
	ExecuteCommandFile PTR
    // Breakpoint interfaces are described
    // elsewhere in this section.
	GetNumberBreakpoints PTR
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
	GetBreakpointByIndex PTR
	GetBreakpointById PTR
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
	GetBreakpointParameters PTR
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
	AddBreakpoint PTR
    // Breakpoint interface is invalid after this call.
	RemoveBreakpoint PTR
    // Control and use extension DLLs.
	AddExtension PTR
	RemoveExtension PTR
	GetExtensionByPath PTR
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
	CallExtension PTR
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // _EFN_ is automatically prepended to
    // the name string given.
    // This function cannot be called remotely.
	GetExtensionFunction PTR
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
	GetWindbgExtensionApis32 PTR
	GetWindbgExtensionApis64 PTR
    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
	GetNumberEventFilters PTR
    // Some filters have descriptive text associated with them.
	GetEventFilterText PTR
    // All filters support executing a command when the
    // event occurs.
	GetEventFilterCommand PTR
	SetEventFilterCommand PTR
	GetSpecificFilterParameters PTR
	SetSpecificFilterParameters PTR
    // Some specific filters have arguments to further
    // qualify their operation.
	GetSpecificFilterArgument PTR
	SetSpecificFilterArgument PTR
    // If Codes is non-NULL Start is ignored.
	GetExceptionFilterParameters PTR
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
	SetExceptionFilterParameters PTR
    // Exception filters support an additional command for
    // second-chance events.
	GetExceptionFilterSecondCommand PTR
	SetExceptionFilterSecondCommand PTR
    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
	WaitForEvent PTR
    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
	GetLastEventInformation PTR
    // IDebugControl2.
	GetCurrentTimeDate PTR
    // Retrieves the number of seconds since the
    // machine started running.
	GetCurrentSystemUpTime PTR
    // If the current session is a dump session,
    // retrieves any extended format information.
	GetDumpFormatFlags PTR
    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
	GetNumberTextReplacements PTR
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
	GetTextReplacement PTR
    // Setting the destination text to
    // NULL removes the alias.
	SetTextReplacement PTR
	RemoveTextReplacements PTR
    // Outputs the complete list of current
    // replacements.
	OutputTextReplacements PTR

    // IDebugControl3.

    // Control options for assembly and disassembly.
	GetAssemblyOptions PTR
	AddAssemblyOptions PTR
	RemoveAssemblyOptions PTR
	SetAssemblyOptions PTR
    // Control the expression syntax.
	GetExpressionSyntax PTR
	SetExpressionSyntax PTR
    // Look up a syntax by its abbreviated
    // name and set it.
	SetExpressionSyntaxByName PTR
	GetNumberExpressionSyntaxes PTR
	GetExpressionSyntaxNames PTR
    //
    // Some debug sessions have only a single
    // possible event, such as a snapshot dump
    // file; some have dynamic events, such as
    // a live debug session; and others may have
    // multiple events, such as a dump file that
    // contains snapshots from different points
    // in time.  The following methods allow
    // discovery and selection of the available
    // events for a session.
    // Sessions with one or more static events
    // will be able to report all of the events
    // when queried.  Sessions with dynamic events
    // will only report a single event representing
    // the current event.
    // Switching events constitutes execution and
    // changing the current event will alter the
    // execution status to a running state, after
    // which WaitForEvent must be used to process
    // the selected event.
    //

    // GetNumberEvents returns S_OK if this is the
    // complete set of events possible, such as for
    // a static session; or S_FALSE if other events
    // may be possible, such as for a dynamic session.
	GetNumberEvents PTR
    // Sessions may have descriptive information for
    // the various events available.  The amount of
    // information varies according to the specific
    // session and data.
	GetEventIndexDescription PTR
	GetCurrentEventIndex PTR
    // SetNextEventIndex works like seek in that
    // it can set an absolute or relative index.
    // SetNextEventIndex works similarly to SetExecutionStatus
    // by putting the session into a running state, after
    // which the caller must call WaitForEvent.  The
    // current event index only changes when WaitForEvent
    // is called.
	SetNextEventIndex PTR
ENDS

//
// Log file flags.
//

#define DEBUG_LOG_DEFAULT 0x00000000
#define DEBUG_LOG_APPEND  0x00000001
#define DEBUG_LOG_UNICODE 0x00000002
#define DEBUG_LOG_DML     0x00000004

//
// System version strings.
//

#define DEBUG_SYSVERSTR_SERVICE_PACK 0x00000000
#define DEBUG_SYSVERSTR_BUILD        0x00000001

//
// GetManagedStatus flags and strings.
//

#define DEBUG_MANAGED_DISABLED   0x00000000
#define DEBUG_MANAGED_ALLOWED    0x00000001
#define DEBUG_MANAGED_DLL_LOADED 0x00000002

#define DEBUG_MANSTR_NONE               0x00000000
#define DEBUG_MANSTR_LOADED_SUPPORT_DLL 0x00000001
#define DEBUG_MANSTR_LOAD_STATUS        0x00000002

//
// ResetManagedStatus flags.
//

// Reset state to default engine startup state with
// no support loaded.
#define DEBUG_MANRESET_DEFAULT  0x00000000
// Force managed support DLL load attempt.
#define DEBUG_MANRESET_LOAD_DLL 0x00000001

IDebugControl4 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugControl.

    // Checks for a user interrupt, such a Ctrl-C
    // or stop button.
    // This method is reentrant.
	GetInterrupt PTR
    // Registers a user interrupt.
    // This method is reentrant.
	SetInterrupt PTR
    // Interrupting a user-mode process requires
    // access to some system resources that the
    // process may hold itself, preventing the
    // interrupt from occurring.  The engine
    // will time-out pending interrupt requests
    // and simulate an interrupt if necessary.
    // These methods control the interrupt timeout.
	GetInterruptTimeout PTR
	SetInterruptTimeout PTR
	GetLogFile PTR
    // Opens a log file which collects all
    // output.  Output from every client except
    // those that explicitly disable logging
    // goes into the log.
    // Opening a log file closes any log file
    // already open.
	OpenLogFile PTR
	CloseLogFile PTR
    // Controls what output is logged.
	GetLogMask PTR
	SetLogMask PTR
    // Input requests input from all clients.
    // The first input that is returned is used
    // to satisfy the call.  Other returned
    // input is discarded.
	Input PTR
    // This method is used by clients to return
    // input when it is available.  It will
    // return S_OK if the input is used to
    // satisfy an Input call and S_FALSE if
    // the input is ignored.
    // This method is reentrant.
	ReturnInput PTR
    // Sends output through clients
    // output callbacks if the mask is allowed
    // by the current output control mask and
    // according to the output distribution
    // settings.
	Output PTR
	OutputVaList PTR
    // The following methods allow direct control
    // over the distribution of the given output
    // for situations where something other than
    // the default is desired.  These methods require
    // extra work in the engine so they should
    // only be used when necessary.
	ControlledOutput PTR
	ControlledOutputVaList PTR
    // Displays the standard command-line prompt
    // followed by the given output.  If Format
    // is NULL no additional output is produced.
    // Output is produced under the
    // DEBUG_OUTPUT_PROMPT mask.
    // This method only outputs the prompt; it
    // does not get input.
	OutputPrompt PTR
	OutputPromptVaList PTR
    // Gets the text that would be displayed by OutputPrompt.
	GetPromptText PTR
    // Outputs information about the current
    // debuggee state such as a register
    // summary, disassembly at the current PC,
    // closest symbol and others.
    // Uses the line prefix.
	OutputCurrentState PTR
    // Outputs the debugger and extension version
    // information.  This method is reentrant.
    // Uses the line prefix.
	OutputVersionInformation PTR
    // In user-mode debugging sessions the
    // engine will set an event when
    // exceptions are continued.  This can
    // be used to synchronize other processes
    // with the debuggers handling of events.
    // For example, this is used to support
    // the e argument to ntsd.
	GetNotifyEventHandle PTR
	SetNotifyEventHandle PTR
	Assemble PTR
	Disassemble PTR
    // Returns the value of the effective address
    // computed for the last Disassemble, if there
    // was one.
	GetDisassembleEffectiveOffset PTR
    // Uses the line prefix if necessary.
	OutputDisassembly PTR
    // Produces multiple lines of disassembly output.
    // There will be PreviousLines of disassembly before
    // the given offset if a valid disassembly exists.
    // In all, there will be TotalLines of output produced.
    // The first and last line offsets are returned
    // specially and all lines offsets can be retrieved
    // through LineOffsets.  LineOffsets will contain
    // offsets for each line where disassembly started.
    // When disassembly of a single instruction takes
    // multiple lines the initial offset will be followed
    // by DEBUG_INVALID_OFFSET.
    // Uses the line prefix.
	OutputDisassemblyLines PTR
    // Returns the offset of the start of
    // the instruction thats the given
    // delta away from the instruction
    // at the initial offset.
    // This routine does not check for
    // validity of the instruction or
    // the memory containing it.
	GetNearInstruction PTR
    // Offsets can be passed in as zero to use the current
    // thread state.
	GetStackTrace PTR
    // Does a simple stack trace to determine
    // what the current return address is.
	GetReturnOffset PTR
    // If Frames is NULL OutputStackTrace will
    // use GetStackTrace to get FramesSize frames
    // and then output them.  The current register
    // values for frame, stack and instruction offsets
    // are used.
    // Uses the line prefix.
	OutputStackTrace PTR
    // Returns information about the debuggee such
    // as user vs. kernel, dump vs. live, etc.
	GetDebuggeeType PTR
    // Returns the type of physical processors in
    // the machine.
    // Returns one of the IMAGE_FILE_MACHINE values.
	GetActualProcessorType PTR
    // Returns the type of processor used in the
    // current processor context.
	GetExecutingProcessorType PTR
    // Query all the possible processor types that
    // may be encountered during this debug session.
	GetNumberPossibleExecutingProcessorTypes PTR
	GetPossibleExecutingProcessorTypes PTR
    // Get the number of actual processors in
    // the machine.
	GetNumberProcessors PTR
    // PlatformId is one of the VER_PLATFORM values.
    // Major and minor are as given in the NT
    // kernel debugger protocol.
    // ServicePackString and ServicePackNumber indicate the
    // system service pack level.  ServicePackNumber is not
    // available in some sessions where the service pack level
    // is only expressed as a string.  The service pack information
    // will be empty if the system does not have a service pack
    // applied.
    // The build string is string information identifying the
    // particular build of the system.  The build string is
    // empty if the system has no particular identifying
    // information.
	GetSystemVersion PTR
    // Returns the page size for the currently executing
    // processor context.  The page size may vary between
    // processor types.
	GetPageSize PTR
    // Returns S_OK if the current processor context uses
    // 64-bit addresses, otherwise S_FALSE.
	IsPointer64Bit PTR
    // Reads the bugcheck data area and returns the
    // current contents.  This method only works
    // in kernel debugging sessions.
	ReadBugCheckData PTR
    // Query all the processor types supported by
    // the engine.  This is a complete list and is
    // not related to the machine running the engine
    // or the debuggee.
	GetNumberSupportedProcessorTypes PTR
	GetSupportedProcessorTypes PTR
    // Returns a full, descriptive name and an
    // abbreviated name for a processor type.
	GetProcessorTypeNames PTR
    // Gets and sets the type of processor to
    // use when doing things like setting
    // breakpoints, accessing registers,
    // getting stack traces and so on.
	GetEffectiveProcessorType PTR
	SetEffectiveProcessorType PTR
    // Returns information about whether and how
    // the debuggee is running.  Status will
    // be GO if the debuggee is running and
    // BREAK if it isnt.
    // If no debuggee exists the status is
    // NO_DEBUGGEE.
    // This method is reentrant.
	GetExecutionStatus PTR
    // Changes the execution status of the
    // engine from stopped to running.
    // Status must be one of the go or step
    // status values.
	SetExecutionStatus PTR
    // Controls what code interpretation level the debugger
    // runs at.  The debugger checks the code level when
    // deciding whether to step by a source line or
    // assembly instruction along with other related operations.
	GetCodeLevel PTR
	SetCodeLevel PTR
    // Gets and sets engine control flags.
    // These methods are reentrant.
	GetEngineOptions PTR
	AddEngineOptions PTR
	RemoveEngineOptions PTR
	SetEngineOptions PTR
    // Gets and sets control values for
    // handling system error events.
    // If the system error level is less
    // than or equal to the given levels
    // the error may be displayed and
    // the default break for the event
    // may be set.
	GetSystemErrorControl PTR
	SetSystemErrorControl PTR
    // The command processor supports simple
    // string replacement macros in Evaluate and
    // Execute.  There are currently ten macro
    // slots available.  Slots 0-9 map to
    // the command invocations $u0-$u9.
	GetTextMacro PTR
	SetTextMacro PTR
    // Controls the default number radix used
    // in expressions and commands.
	GetRadix PTR
	SetRadix PTR
    // Evaluates the given expression string and
    // returns the resulting value.
    // If DesiredType is DEBUG_VALUE_INVALID then
    // the natural type is used.
    // RemainderIndex, if provided, is set to the index
    // of the first character in the input string that was
    // not used when evaluating the expression.
	Evaluate PTR
    // Attempts to convert the input value to a value
    // of the requested type in the output value.
    // Conversions can fail if no conversion exists.
    // Successful conversions may be lossy.
	CoerceValue PTR
	CoerceValues PTR
    // Executes the given command string.
    // If the string has multiple commands
    // Execute will not return until all
    // of them have been executed.  If this
    // requires waiting for the debuggee to
    // execute an internal wait will be done
    // so Execute can take an arbitrary amount
    // of time.
	Execute PTR
    // Executes the given command file by
    // reading a line at a time and processing
    // it with Execute.
	ExecuteCommandFile PTR
    // Breakpoint interfaces are described
    // elsewhere in this section.
	GetNumberBreakpoints PTR
    // It is possible for this retrieval function to
    // fail even with an index within the number of
    // existing breakpoints if the breakpoint is
    // a private breakpoint.
	GetBreakpointByIndex PTR
	GetBreakpointById PTR
    // If Ids is non-NULL the Count breakpoints
    // referred to in the Ids array are returned,
    // otherwise breakpoints from index Start to
    // Start + Count  1 are returned.
	GetBreakpointParameters PTR
    // Breakpoints are created empty and disabled.
    // When their parameters have been set they
    // should be enabled by setting the ENABLE flag.
    // If DesiredId is DEBUG_ANY_ID then the
    // engine picks an unused ID.  If DesiredId
    // is any other number the engine attempts
    // to use the given ID for the breakpoint.
    // If another breakpoint exists with that ID
    // the call will fail.
	AddBreakpoint PTR
    // Breakpoint interface is invalid after this call.
	RemoveBreakpoint PTR
    // Control and use extension DLLs.
	AddExtension PTR
	RemoveExtension PTR
	GetExtensionByPath PTR
    // If Handle is zero the extension
    // chain is walked searching for the
    // function.
	CallExtension PTR
    // GetExtensionFunction works like
    // GetProcAddress on extension DLLs
    // to allow raw function-call-level
    // interaction with extension DLLs.
    // Such functions do not need to
    // follow the standard extension prototype
    // if they are not going to be called
    // through the text extension interface.
    // _EFN_ is automatically prepended to
    // the name string given.
    // This function cannot be called remotely.
	GetExtensionFunction PTR
    // These methods return alternate
    // extension interfaces in order to allow
    // interface-style extension DLLs to mix in
    // older extension calls.
    // Structure sizes must be initialized before
    // the call.
    // These methods cannot be called remotely.
	GetWindbgExtensionApis32 PTR
	GetWindbgExtensionApis64 PTR
    // The engine provides a simple mechanism
    // to filter common events.  Arbitrarily complicated
    // filtering can be done by registering event callbacks
    // but simple event filtering only requires
    // setting the options of one of the predefined
    // event filters.
    // Simple event filters are either for specific
    // events and therefore have an enumerant or
    // they are for an exception and are based on
    // the exceptions code.  Exception filters
    // are further divided into exceptions specially
    // handled by the engine, which is a fixed set,
    // and arbitrary exceptions.
    // All three groups of filters are indexed together
    // with the specific filters first, then the specific
    // exception filters and finally the arbitrary
    // exception filters.
    // The first specific exception is the default
    // exception.  If an exception event occurs for
    // an exception without settings the default
    // exception settings are used.
	GetNumberEventFilters PTR
    // Some filters have descriptive text associated with them.
	GetEventFilterText PTR
    // All filters support executing a command when the
    // event occurs.
	GetEventFilterCommand PTR
	SetEventFilterCommand PTR
	GetSpecificFilterParameters PTR
	SetSpecificFilterParameters PTR
    // Some specific filters have arguments to further
    // qualify their operation.
	GetSpecificFilterArgument PTR
	SetSpecificFilterArgument PTR
    // If Codes is non-NULL Start is ignored.
	GetExceptionFilterParameters PTR
    // The codes in the parameter data control the application
    // of the parameter data.  If a code is not already in
    // the set of filters it is added.  If the ExecutionOption
    // for a code is REMOVE then the filter is removed.
    // Specific exception filters cannot be removed.
	SetExceptionFilterParameters PTR
    // Exception filters support an additional command for
    // second-chance events.
	GetExceptionFilterSecondCommand PTR
	SetExceptionFilterSecondCommand PTR
    // Yields processing to the engine until
    // an event occurs.  This method may
    // only be called by the thread that started
    // the debug session.
    // When an event occurs the engine carries
    // out all event processing such as calling
    // callbacks.
    // If the callbacks indicate that execution should
    // break the wait will return, otherwise it
    // goes back to waiting for a new event.
    // If the timeout expires, S_FALSE is returned.
    // The timeout is not currently supported for
    // kernel debugging.
	WaitForEvent PTR
    // Retrieves information about the last event that occurred.
    // EventType is one of the event callback mask bits.
    // ExtraInformation contains additional event-specific
    // information.  Not all events have additional information.
	GetLastEventInformation PTR
    // IDebugControl2.
	GetCurrentTimeDate PTR
    // Retrieves the number of seconds since the
    // machine started running.
	GetCurrentSystemUpTime PTR
    // If the current session is a dump session,
    // retrieves any extended format information.
	GetDumpFormatFlags PTR
    // The debugger has been enhanced to allow
    // arbitrary text replacements in addition
    // to the simple $u0-$u9 text macros.
    // Text replacement takes a given source
    // text in commands and converts it to the
    // given destination text.  Replacements
    // are named by their source text so that
    // only one replacement for a source text
    // string can exist.
	GetNumberTextReplacements PTR
    // If SrcText is non-NULL the replacement
    // is looked up by source text, otherwise
    // Index is used to get the Nth replacement.
	GetTextReplacement PTR
    // Setting the destination text to
    // NULL removes the alias.
	SetTextReplacement PTR
	RemoveTextReplacements PTR
    // Outputs the complete list of current
    // replacements.
	OutputTextReplacements PTR

    // IDebugControl3.

    // Control options for assembly and disassembly.
	GetAssemblyOptions PTR
	AddAssemblyOptions PTR
	RemoveAssemblyOptions PTR
	SetAssemblyOptions PTR
    // Control the expression syntax.
	GetExpressionSyntax PTR
	SetExpressionSyntax PTR
    // Look up a syntax by its abbreviated
    // name and set it.
	SetExpressionSyntaxByName PTR
	GetNumberExpressionSyntaxes PTR
	GetExpressionSyntaxNames PTR
    //
    // Some debug sessions have only a single
    // possible event, such as a snapshot dump
    // file; some have dynamic events, such as
    // a live debug session; and others may have
    // multiple events, such as a dump file that
    // contains snapshots from different points
    // in time.  The following methods allow
    // discovery and selection of the available
    // events for a session.
    // Sessions with one or more static events
    // will be able to report all of the events
    // when queried.  Sessions with dynamic events
    // will only report a single event representing
    // the current event.
    // Switching events constitutes execution and
    // changing the current event will alter the
    // execution status to a running state, after
    // which WaitForEvent must be used to process
    // the selected event.
    //

    // GetNumberEvents returns S_OK if this is the
    // complete set of events possible, such as for
    // a static session; or S_FALSE if other events
    // may be possible, such as for a dynamic session.
	GetNumberEvents PTR
    // Sessions may have descriptive information for
    // the various events available.  The amount of
    // information varies according to the specific
    // session and data.
	GetEventIndexDescription PTR
	GetCurrentEventIndex PTR
    // SetNextEventIndex works like seek in that
    // it can set an absolute or relative index.
    // SetNextEventIndex works similarly to SetExecutionStatus
    // by putting the session into a running state, after
    // which the caller must call WaitForEvent.  The
    // current event index only changes when WaitForEvent
    // is called.
	SetNextEventIndex PTR

    // IDebugControl4.
	GetLogFileWide PTR
	OpenLogFileWide PTR
	InputWide PTR
	ReturnInputWide PTR
	OutputWide PTR
	OutputVaListWide PTR
	ControlledOutputWide PTR
	ControlledOutputVaListWide PTR
	OutputPromptWide PTR
	OutputPromptVaListWide PTR
	GetPromptTextWide PTR
	AssembleWide PTR
	DisassembleWide PTR
	GetProcessorTypeNamesWide PTR
	GetTextMacroWide PTR
	SetTextMacroWide PTR
	EvaluateWide PTR
	ExecuteWide PTR
	ExecuteCommandFileWide PTR
	GetBreakpointByIndex2 PTR
	GetBreakpointById2 PTR
	AddBreakpoint2 PTR
	RemoveBreakpoint2 PTR
	AddExtensionWide PTR
	GetExtensionByPathWide PTR
	CallExtensionWide PTR
	GetExtensionFunctionWide PTR
	GetEventFilterTextWide PTR
	GetEventFilterCommandWide PTR
	SetEventFilterCommandWide PTR
	GetSpecificFilterArgumentWide PTR
	SetSpecificFilterArgumentWide PTR
	GetExceptionFilterSecondCommandWide PTR
	SetExceptionFilterSecondCommandWide PTR
	GetLastEventInformationWide PTR
	GetTextReplacementWide PTR
	SetTextReplacementWide PTR
	SetExpressionSyntaxByNameWide PTR
	GetExpressionSyntaxNamesWide PTR
	GetEventIndexDescriptionWide PTR
	GetLogFile2 PTR
	OpenLogFile2 PTR
	GetLogFile2Wide PTR
	OpenLogFile2Wide PTR
    // GetSystemVersion always returns the kd
    // major/minor version numbers, which are
    // different than the Win32 version numbers.
    // GetSystemVersionValues can be used
    // to determine the Win32 version values.
	GetSystemVersionValues PTR
    // Strings are selected with DEBUG_SYSVERSTR_*.
	GetSystemVersionString PTR
	GetSystemVersionStringWide PTR
    // Stack tracing with a full initial context
    // and full context return for each frame.
    // The FrameContextsSize parameter is the total
    // byte size of FrameContexts.  FrameContextsEntrySize
    // gives the byte size of each entry in
    // FrameContexts.
	GetContextStackTrace PTR
	OutputContextStackTrace PTR
    // Some targets, such as user-mode minidump files,
    // have separate "event of interest" information
    // stored within them.  This method allows
    // access to that information.
	GetStoredEventInformation PTR
    // Managed debugging support relies on debugging
    // functionality provided by the Common Language Runtime.
    // This method provides feedback on the engine's
    // use of the runtime debugging APIs.
	GetManagedStatus PTR
	GetManagedStatusWide PTR
    // Clears and reinitializes the engine's
    // managed code debugging support.
	ResetManagedStatus PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugDataSpaces.
//
//----------------------------------------------------------------------------

// Data space indices for callbacks and other methods.
#define DEBUG_DATA_SPACE_VIRTUAL       0
#define DEBUG_DATA_SPACE_PHYSICAL      1
#define DEBUG_DATA_SPACE_CONTROL       2
#define DEBUG_DATA_SPACE_IO            3
#define DEBUG_DATA_SPACE_MSR           4
#define DEBUG_DATA_SPACE_BUS_DATA      5
#define DEBUG_DATA_SPACE_DEBUGGER_DATA 6
// Count of data spaces.
#define DEBUG_DATA_SPACE_COUNT         7

// Indices for ReadDebuggerData interface
#define DEBUG_DATA_KernBase                              24
#define DEBUG_DATA_BreakpointWithStatusAddr              32
#define DEBUG_DATA_SavedContextAddr                      40
#define DEBUG_DATA_KiCallUserModeAddr                    56
#define DEBUG_DATA_KeUserCallbackDispatcherAddr          64
#define DEBUG_DATA_PsLoadedModuleListAddr                72
#define DEBUG_DATA_PsActiveProcessHeadAddr               80
#define DEBUG_DATA_PspCidTableAddr                       88
#define DEBUG_DATA_ExpSystemResourcesListAddr            96
#define DEBUG_DATA_ExpPagedPoolDescriptorAddr           104
#define DEBUG_DATA_ExpNumberOfPagedPoolsAddr            112
#define DEBUG_DATA_KeTimeIncrementAddr                  120
#define DEBUG_DATA_KeBugCheckCallbackListHeadAddr       128
#define DEBUG_DATA_KiBugcheckDataAddr                   136
#define DEBUG_DATA_IopErrorLogListHeadAddr              144
#define DEBUG_DATA_ObpRootDirectoryObjectAddr           152
#define DEBUG_DATA_ObpTypeObjectTypeAddr                160
#define DEBUG_DATA_MmSystemCacheStartAddr               168
#define DEBUG_DATA_MmSystemCacheEndAddr                 176
#define DEBUG_DATA_MmSystemCacheWsAddr                  184
#define DEBUG_DATA_MmPfnDatabaseAddr                    192
#define DEBUG_DATA_MmSystemPtesStartAddr                200
#define DEBUG_DATA_MmSystemPtesEndAddr                  208
#define DEBUG_DATA_MmSubsectionBaseAddr                 216
#define DEBUG_DATA_MmNumberOfPagingFilesAddr            224
#define DEBUG_DATA_MmLowestPhysicalPageAddr             232
#define DEBUG_DATA_MmHighestPhysicalPageAddr            240
#define DEBUG_DATA_MmNumberOfPhysicalPagesAddr          248
#define DEBUG_DATA_MmMaximumNonPagedPoolInBytesAddr     256
#define DEBUG_DATA_MmNonPagedSystemStartAddr            264
#define DEBUG_DATA_MmNonPagedPoolStartAddr              272
#define DEBUG_DATA_MmNonPagedPoolEndAddr                280
#define DEBUG_DATA_MmPagedPoolStartAddr                 288
#define DEBUG_DATA_MmPagedPoolEndAddr                   296
#define DEBUG_DATA_MmPagedPoolInformationAddr           304
#define DEBUG_DATA_MmPageSize                           312
#define DEBUG_DATA_MmSizeOfPagedPoolInBytesAddr         320
#define DEBUG_DATA_MmTotalCommitLimitAddr               328
#define DEBUG_DATA_MmTotalCommittedPagesAddr            336
#define DEBUG_DATA_MmSharedCommitAddr                   344
#define DEBUG_DATA_MmDriverCommitAddr                   352
#define DEBUG_DATA_MmProcessCommitAddr                  360
#define DEBUG_DATA_MmPagedPoolCommitAddr                368
#define DEBUG_DATA_MmExtendedCommitAddr                 376
#define DEBUG_DATA_MmZeroedPageListHeadAddr             384
#define DEBUG_DATA_MmFreePageListHeadAddr               392
#define DEBUG_DATA_MmStandbyPageListHeadAddr            400
#define DEBUG_DATA_MmModifiedPageListHeadAddr           408
#define DEBUG_DATA_MmModifiedNoWritePageListHeadAddr    416
#define DEBUG_DATA_MmAvailablePagesAddr                 424
#define DEBUG_DATA_MmResidentAvailablePagesAddr         432
#define DEBUG_DATA_PoolTrackTableAddr                   440
#define DEBUG_DATA_NonPagedPoolDescriptorAddr           448
#define DEBUG_DATA_MmHighestUserAddressAddr             456
#define DEBUG_DATA_MmSystemRangeStartAddr               464
#define DEBUG_DATA_MmUserProbeAddressAddr               472
#define DEBUG_DATA_KdPrintCircularBufferAddr            480
#define DEBUG_DATA_KdPrintCircularBufferEndAddr         488
#define DEBUG_DATA_KdPrintWritePointerAddr              496
#define DEBUG_DATA_KdPrintRolloverCountAddr             504
#define DEBUG_DATA_MmLoadedUserImageListAddr            512
#define DEBUG_DATA_NtBuildLabAddr                       520
#define DEBUG_DATA_KiNormalSystemCall                   528
#define DEBUG_DATA_KiProcessorBlockAddr                 536
#define DEBUG_DATA_MmUnloadedDriversAddr                544
#define DEBUG_DATA_MmLastUnloadedDriverAddr             552
#define DEBUG_DATA_MmTriageActionTakenAddr              560
#define DEBUG_DATA_MmSpecialPoolTagAddr                 568
#define DEBUG_DATA_KernelVerifierAddr                   576
#define DEBUG_DATA_MmVerifierDataAddr                   584
#define DEBUG_DATA_MmAllocatedNonPagedPoolAddr          592
#define DEBUG_DATA_MmPeakCommitmentAddr                 600
#define DEBUG_DATA_MmTotalCommitLimitMaximumAddr        608
#define DEBUG_DATA_CmNtCSDVersionAddr                   616
#define DEBUG_DATA_MmPhysicalMemoryBlockAddr            624
#define DEBUG_DATA_MmSessionBase                        632
#define DEBUG_DATA_MmSessionSize                        640
#define DEBUG_DATA_MmSystemParentTablePage              648
#define DEBUG_DATA_MmVirtualTranslationBase             656
#define DEBUG_DATA_OffsetKThreadNextProcessor           664
#define DEBUG_DATA_OffsetKThreadTeb                     666
#define DEBUG_DATA_OffsetKThreadKernelStack             668
#define DEBUG_DATA_OffsetKThreadInitialStack            670
#define DEBUG_DATA_OffsetKThreadApcProcess              672
#define DEBUG_DATA_OffsetKThreadState                   674
#define DEBUG_DATA_OffsetKThreadBStore                  676
#define DEBUG_DATA_OffsetKThreadBStoreLimit             678
#define DEBUG_DATA_SizeEProcess                         680
#define DEBUG_DATA_OffsetEprocessPeb                    682
#define DEBUG_DATA_OffsetEprocessParentCID              684
#define DEBUG_DATA_OffsetEprocessDirectoryTableBase     686
#define DEBUG_DATA_SizePrcb                             688
#define DEBUG_DATA_OffsetPrcbDpcRoutine                 690
#define DEBUG_DATA_OffsetPrcbCurrentThread              692
#define DEBUG_DATA_OffsetPrcbMhz                        694
#define DEBUG_DATA_OffsetPrcbCpuType                    696
#define DEBUG_DATA_OffsetPrcbVendorString               698
#define DEBUG_DATA_OffsetPrcbProcessorState             700
#define DEBUG_DATA_OffsetPrcbNumber                     702
#define DEBUG_DATA_SizeEThread                          704
#define DEBUG_DATA_KdPrintCircularBufferPtrAddr         712
#define DEBUG_DATA_KdPrintBufferSizeAddr                720
#define DEBUG_DATA_MmBadPagesDetected                   800
#define DEBUG_DATA_EtwpDebuggerData                     816

#define DEBUG_DATA_PaeEnabled                        100000
#define DEBUG_DATA_SharedUserData                    100008
#define DEBUG_DATA_ProductType                       100016
#define DEBUG_DATA_SuiteMask                         100024
#define DEBUG_DATA_DumpWriterStatus                  100032
#define DEBUG_DATA_DumpFormatVersion                 100040
#define DEBUG_DATA_DumpWriterVersion                 100048
#define DEBUG_DATA_DumpPowerState                    100056
#define DEBUG_DATA_DumpMmStorage                     100064

//
// Processor information structures.
//

DEBUG_PROCESSOR_IDENTIFICATION_ALPHA STRUCT
	Type DD
	Revision DD
ENDS

DEBUG_PROCESSOR_IDENTIFICATION_AMD64 STRUCT
	Family DD
	Model DD
	Stepping DD
	VendorString DB 16 DUP
ENDS

DEBUG_PROCESSOR_IDENTIFICATION_IA64 STRUCT
	Model DD
	Revision DD
	Family DD
	ArchRev DD
	VendorString DB 16 DUP
ENDS

DEBUG_PROCESSOR_IDENTIFICATION_X86 STRUCT
	Family DD
	Model DD
	Stepping DD
	VendorString DB 16 DUP
ENDS

DEBUG_PROCESSOR_IDENTIFICATION_ARM STRUCT
	Type DD
	Revision DD
ENDS

DEBUG_PROCESSOR_IDENTIFICATION_ALL UNION
	Alpha DEBUG_PROCESSOR_IDENTIFICATION_ALPHA
	Amd64 DEBUG_PROCESSOR_IDENTIFICATION_AMD64
	Ia64 DEBUG_PROCESSOR_IDENTIFICATION_IA64
	X86 DEBUG_PROCESSOR_IDENTIFICATION_X86
	Arm DEBUG_PROCESSOR_IDENTIFICATION_ARM
ENDUNION

// Indices for ReadProcessorSystemData.
#define DEBUG_DATA_KPCR_OFFSET                          0
#define DEBUG_DATA_KPRCB_OFFSET                         1
#define DEBUG_DATA_KTHREAD_OFFSET                       2
#define DEBUG_DATA_BASE_TRANSLATION_VIRTUAL_OFFSET      3
#define DEBUG_DATA_PROCESSOR_IDENTIFICATION             4
#define DEBUG_DATA_PROCESSOR_SPEED                      5

IDebugDataSpaces STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugDataSpaces.
	ReadVirtual PTR
	WriteVirtual PTR
    // SearchVirtual searches the given virtual
    // address range for the given pattern.  PatternSize
    // gives the byte length of the pattern and PatternGranularity
    // controls the granularity of comparisons during
    // the search.
    // For example, a DWORD-granular search would
    // use a pattern granularity of four to search by DWORD
    // increments.
	SearchVirtual PTR
    // These methods are identical to Read/WriteVirtual
    // except that they avoid the kernel virtual memory
    // cache entirely and are therefore useful for reading
    // virtual memory which is inherently volatile, such
    // as memory-mapped device areas, without contaminating
    // or invalidating the cache.
    // In user-mode they are the same as Read/WriteVirtual.
	ReadVirtualUncached PTR
	WriteVirtualUncached PTR
    // The following two methods are convenience
    // methods for accessing pointer values.
    // They automatically convert between native pointers
    // and canonical 64-bit values as necessary.
    // These routines stop at the first failure.
	ReadPointersVirtual PTR
	WritePointersVirtual PTR
    // All non-virtual data spaces are only
    // available when kernel debugging.
	ReadPhysical PTR
	WritePhysical PTR
	ReadControl PTR
	WriteControl PTR
	ReadIo PTR
	WriteIo PTR
	ReadMsr PTR
	WriteMsr PTR
	ReadBusData PTR
	WriteBusData PTR
	CheckLowMemory PTR
	ReadDebuggerData PTR
	ReadProcessorSystemData PTR
ENDS

//
// Handle data types and structures.
//

#define DEBUG_HANDLE_DATA_TYPE_BASIC                 0
#define DEBUG_HANDLE_DATA_TYPE_TYPE_NAME             1
#define DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME           2
#define DEBUG_HANDLE_DATA_TYPE_HANDLE_COUNT          3
#define DEBUG_HANDLE_DATA_TYPE_TYPE_NAME_WIDE        4
#define DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME_WIDE      5
#define DEBUG_HANDLE_DATA_TYPE_MINI_THREAD_1         6
#define DEBUG_HANDLE_DATA_TYPE_MINI_MUTANT_1         7
#define DEBUG_HANDLE_DATA_TYPE_MINI_MUTANT_2         8
#define DEBUG_HANDLE_DATA_TYPE_PER_HANDLE_OPERATIONS 9
#define DEBUG_HANDLE_DATA_TYPE_ALL_HANDLE_OPERATIONS 10
#define DEBUG_HANDLE_DATA_TYPE_MINI_PROCESS_1        11
#define DEBUG_HANDLE_DATA_TYPE_MINI_PROCESS_2        12

DEBUG_HANDLE_DATA_BASIC STRUCT
	TypeNameSize DD
	ObjectNameSize DD
	Attributes DD
	GrantedAccess DD
	HandleCount DD
	PointerCount DD
ENDS

IDebugDataSpaces2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugDataSpaces.
	ReadVirtual PTR
	WriteVirtual PTR
    // SearchVirtual searches the given virtual
    // address range for the given pattern.  PatternSize
    // gives the byte length of the pattern and PatternGranularity
    // controls the granularity of comparisons during
    // the search.
    // For example, a DWORD-granular search would
    // use a pattern granularity of four to search by DWORD
    // increments.
	SearchVirtual PTR
    // These methods are identical to Read/WriteVirtual
    // except that they avoid the kernel virtual memory
    // cache entirely and are therefore useful for reading
    // virtual memory which is inherently volatile, such
    // as memory-mapped device areas, without contaminating
    // or invalidating the cache.
    // In user-mode they are the same as Read/WriteVirtual.
	ReadVirtualUncached PTR
	WriteVirtualUncached PTR
    // The following two methods are convenience
    // methods for accessing pointer values.
    // They automatically convert between native pointers
    // and canonical 64-bit values as necessary.
    // These routines stop at the first failure.
	ReadPointersVirtual PTR
	WritePointersVirtual PTR
    // All non-virtual data spaces are only
    // available when kernel debugging.
	ReadPhysical PTR
	WritePhysical PTR
	ReadControl PTR
	WriteControl PTR
	ReadIo PTR
	WriteIo PTR
	ReadMsr PTR
	WriteMsr PTR
	ReadBusData PTR
	WriteBusData PTR
	CheckLowMemory PTR
	ReadDebuggerData PTR
	ReadProcessorSystemData PTR
    // IDebugDataSpaces2.
	VirtualToPhysical PTR
    // Returns the physical addresses for the
    // N levels of the systems paging structures.
    // Level zero is the starting base physical
    // address for virtual translations.
    // Levels one-(N-1) will point to the appropriate
    // paging descriptor for the virtual address at
    // the given level of the paging hierarchy.  The
    // exact number of levels depends on many factors.
    // The last level will be the fully translated
    // physical address, matching what VirtualToPhysical
    // returns.  If the address can only be partially
    // translated S_FALSE is returned.
	GetVirtualTranslationPhysicalOffsets PTR
    // System handle data is accessible in certain
    // debug sessions.  The particular data available
    // varies from session to session and platform
    // to platform.
	ReadHandleData PTR
    // Fills memory with the given pattern.
    // The fill stops at the first non-writable byte.
	FillVirtual PTR
	FillPhysical PTR
    // Queries virtual memory mapping information given
    // an address similarly to the Win32 API VirtualQuery.
    // MEMORY_BASIC_INFORMATION64 is defined in crash.h.
    // This method currently only works for user-mode sessions.
	QueryVirtual PTR
ENDS

DebugDataSpaces3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugDataSpaces.
	ReadVirtual PTR
	WriteVirtual PTR
    // SearchVirtual searches the given virtual
    // address range for the given pattern.  PatternSize
    // gives the byte length of the pattern and PatternGranularity
    // controls the granularity of comparisons during
    // the search.
    // For example, a DWORD-granular search would
    // use a pattern granularity of four to search by DWORD
    // increments.
	SearchVirtual PTR
    // These methods are identical to Read/WriteVirtual
    // except that they avoid the kernel virtual memory
    // cache entirely and are therefore useful for reading
    // virtual memory which is inherently volatile, such
    // as memory-mapped device areas, without contaminating
    // or invalidating the cache.
    // In user-mode they are the same as Read/WriteVirtual.
	ReadVirtualUncached PTR
	WriteVirtualUncached PTR
    // The following two methods are convenience
    // methods for accessing pointer values.
    // They automatically convert between native pointers
    // and canonical 64-bit values as necessary.
    // These routines stop at the first failure.
	ReadPointersVirtual PTR
	WritePointersVirtual PTR
    // All non-virtual data spaces are only
    // available when kernel debugging.
	ReadPhysical PTR
	WritePhysical PTR
	ReadControl PTR
	WriteControl PTR
	ReadIo PTR
	WriteIo PTR
	ReadMsr PTR
	WriteMsr PTR
	ReadBusData PTR
	WriteBusData PTR
	CheckLowMemory PTR
	ReadDebuggerData PTR
	ReadProcessorSystemData PTR
    // IDebugDataSpaces2.
	VirtualToPhysical PTR
    // Returns the physical addresses for the
    // N levels of the systems paging structures.
    // Level zero is the starting base physical
    // address for virtual translations.
    // Levels one-(N-1) will point to the appropriate
    // paging descriptor for the virtual address at
    // the given level of the paging hierarchy.  The
    // exact number of levels depends on many factors.
    // The last level will be the fully translated
    // physical address, matching what VirtualToPhysical
    // returns.  If the address can only be partially
    // translated S_FALSE is returned.
	GetVirtualTranslationPhysicalOffsets PTR
    // System handle data is accessible in certain
    // debug sessions.  The particular data available
    // varies from session to session and platform
    // to platform.
	ReadHandleData PTR
    // Fills memory with the given pattern.
    // The fill stops at the first non-writable byte.
	FillVirtual PTR
	FillPhysical PTR
    // Queries virtual memory mapping information given
    // an address similarly to the Win32 API VirtualQuery.
    // MEMORY_BASIC_INFORMATION64 is defined in crash.h.
    // This method currently only works for user-mode sessions.
	QueryVirtual PTR
    // IDebugDataSpaces3.

    // Convenience method for reading an image
    // header from virtual memory.  Given the
    // image base, this method determines where
    // the NT headers are, validates the necessary
    // markers and converts the headers into
    // 64-bit form for consistency.
    // A caller can check whether the headers were
    // originally 32-bit by checking the optional
    // header magic value.
    // This method will not read ROM headers.
	ReadImageNtHeaders PTR
    // Some debug sessions have arbitrary additional
    // data available.  For example, additional dump
    // information files may contain extra information
    // gathered at the same time as the primary dump.
    // Such information is tagged with a unique identifier
    // and can only be retrieved via the tag.
    // Tagged data cannot be partially available; the
    // tagged block is either fully present or completely
    // absent.
	ReadTagged PTR
	StartEnumTagged PTR
	GetNextTagged PTR
	EndEnumTagged PTR
ENDS

#define DEBUG_OFFSINFO_VIRTUAL_SOURCE 0x00000001

#define DEBUG_VSOURCE_INVALID              0x00000000
#define DEBUG_VSOURCE_DEBUGGEE             0x00000001
#define DEBUG_VSOURCE_MAPPED_IMAGE         0x00000002
#define DEBUG_VSOURCE_DUMP_WITHOUT_MEMINFO 0x00000003

#define DEBUG_VSEARCH_DEFAULT       0x00000000
#define DEBUG_VSEARCH_WRITABLE_ONLY 0x00000001

#define DEBUG_PHYSICAL_DEFAULT        0x00000000
#define DEBUG_PHYSICAL_CACHED         0x00000001
#define DEBUG_PHYSICAL_UNCACHED       0x00000002
#define DEBUG_PHYSICAL_WRITE_COMBINED 0x00000003

IDebugDataSpaces4 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugDataSpaces.
	ReadVirtual PTR
	WriteVirtual PTR
    // SearchVirtual searches the given virtual
    // address range for the given pattern.  PatternSize
    // gives the byte length of the pattern and PatternGranularity
    // controls the granularity of comparisons during
    // the search.
    // For example, a DWORD-granular search would
    // use a pattern granularity of four to search by DWORD
    // increments.
	SearchVirtual PTR
    // These methods are identical to Read/WriteVirtual
    // except that they avoid the kernel virtual memory
    // cache entirely and are therefore useful for reading
    // virtual memory which is inherently volatile, such
    // as memory-mapped device areas, without contaminating
    // or invalidating the cache.
    // In user-mode they are the same as Read/WriteVirtual.
	ReadVirtualUncached PTR
	WriteVirtualUncached PTR
    // The following two methods are convenience
    // methods for accessing pointer values.
    // They automatically convert between native pointers
    // and canonical 64-bit values as necessary.
    // These routines stop at the first failure.
	ReadPointersVirtual PTR
	WritePointersVirtual PTR
    // All non-virtual data spaces are only
    // available when kernel debugging.
	ReadPhysical PTR
	WritePhysical PTR
	ReadControl PTR
	WriteControl PTR
	ReadIo PTR
	WriteIo PTR
	ReadMsr PTR
	WriteMsr PTR
	ReadBusData PTR
	WriteBusData PTR
	CheckLowMemory PTR
	ReadDebuggerData PTR
	ReadProcessorSystemData PTR
    // IDebugDataSpaces2.
	VirtualToPhysical PTR
    // Returns the physical addresses for the
    // N levels of the systems paging structures.
    // Level zero is the starting base physical
    // address for virtual translations.
    // Levels one-(N-1) will point to the appropriate
    // paging descriptor for the virtual address at
    // the given level of the paging hierarchy.  The
    // exact number of levels depends on many factors.
    // The last level will be the fully translated
    // physical address, matching what VirtualToPhysical
    // returns.  If the address can only be partially
    // translated S_FALSE is returned.
	GetVirtualTranslationPhysicalOffsets PTR
    // System handle data is accessible in certain
    // debug sessions.  The particular data available
    // varies from session to session and platform
    // to platform.
	ReadHandleData PTR
    // Fills memory with the given pattern.
    // The fill stops at the first non-writable byte.
	FillVirtual PTR
	FillPhysical PTR
    // Queries virtual memory mapping information given
    // an address similarly to the Win32 API VirtualQuery.
    // MEMORY_BASIC_INFORMATION64 is defined in crash.h.
    // This method currently only works for user-mode sessions.
	QueryVirtual PTR
    // IDebugDataSpaces3.

    // Convenience method for reading an image
    // header from virtual memory.  Given the
    // image base, this method determines where
    // the NT headers are, validates the necessary
    // markers and converts the headers into
    // 64-bit form for consistency.
    // A caller can check whether the headers were
    // originally 32-bit by checking the optional
    // header magic value.
    // This method will not read ROM headers.
	ReadImageNtHeaders PTR
    // Some debug sessions have arbitrary additional
    // data available.  For example, additional dump
    // information files may contain extra information
    // gathered at the same time as the primary dump.
    // Such information is tagged with a unique identifier
    // and can only be retrieved via the tag.
    // Tagged data cannot be partially available; the
    // tagged block is either fully present or completely
    // absent.
	ReadTagged PTR
	StartEnumTagged PTR
	GetNextTagged PTR
	EndEnumTagged PTR
    // IDebugDataSpaces4.

    // General information about an address in the given data space.
    // Queries are from DEBUG_OFFSINFO_*.
	GetOffsetInformation PTR
    // Given a particular address, return the
    // next address which has a different validity.
    // For example, in debug sessions such as a live
    // user-mode session where virtual address validity
    // changes from page to page this will return the
    // page after the given page.  In sessions such as
    // a user-mode dump file where validity can change
    // from byte to byte this will return the start of
    // the next region that has different validity.
	GetNextDifferentlyValidOffsetVirtual PTR
    // Given a particular range of virtual addresses,
    // find the first region which is valid memory.
	GetValidRegionVirtual PTR
	SearchVirtual2 PTR
    // Attempts to read a multi-byte string
    // starting at the given virtual address.
    // The possible string length, including terminator,
    // is capped at the given max size.
    // If a return buffer is given it will always
    // be terminated.
	ReadMultiByteStringVirtual PTR
    // Reads a multi-byte string and converts
    // it to Unicode using the given code page.
	ReadMultiByteStringVirtualWide PTR
	ReadUnicodeStringVirtual PTR
	ReadUnicodeStringVirtualWide PTR
	ReadPhysical2 PTR
	WritePhysical2 PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugEventCallbacks.
//
//----------------------------------------------------------------------------

// Interest mask bits.
#define DEBUG_EVENT_BREAKPOINT              0x00000001
#define DEBUG_EVENT_EXCEPTION               0x00000002
#define DEBUG_EVENT_CREATE_THREAD           0x00000004
#define DEBUG_EVENT_EXIT_THREAD             0x00000008
#define DEBUG_EVENT_CREATE_PROCESS          0x00000010
#define DEBUG_EVENT_EXIT_PROCESS            0x00000020
#define DEBUG_EVENT_LOAD_MODULE             0x00000040
#define DEBUG_EVENT_UNLOAD_MODULE           0x00000080
#define DEBUG_EVENT_SYSTEM_ERROR            0x00000100
#define DEBUG_EVENT_SESSION_STATUS          0x00000200
#define DEBUG_EVENT_CHANGE_DEBUGGEE_STATE   0x00000400
#define DEBUG_EVENT_CHANGE_ENGINE_STATE     0x00000800
#define DEBUG_EVENT_CHANGE_SYMBOL_STATE     0x00001000

// SessionStatus flags.
// A debuggee has been discovered for the session.
#define DEBUG_SESSION_ACTIVE                       0x00000000
// The session has been ended by EndSession.
#define DEBUG_SESSION_END_SESSION_ACTIVE_TERMINATE 0x00000001
#define DEBUG_SESSION_END_SESSION_ACTIVE_DETACH    0x00000002
#define DEBUG_SESSION_END_SESSION_PASSIVE          0x00000003
// The debuggee has run to completion.  User-mode only.
#define DEBUG_SESSION_END                          0x00000004
// The target machine has rebooted.  Kernel-mode only.
#define DEBUG_SESSION_REBOOT                       0x00000005
// The target machine has hibernated.  Kernel-mode only.
#define DEBUG_SESSION_HIBERNATE                    0x00000006
// The engine was unable to continue the session.
#define DEBUG_SESSION_FAILURE                      0x00000007

// ChangeDebuggeeState flags.
// The debuggees state has changed generally, such
// as when the debuggee has been executing.
// Argument is zero.
#define DEBUG_CDS_ALL       0xffffffff
// Registers have changed.  If only a single register
// changed, argument is the index of the register.
// Otherwise it is DEBUG_ANY_ID.
#define DEBUG_CDS_REGISTERS 0x00000001
// Data spaces have changed.  If only a single
// space was affected, argument is the data
// space.  Otherwise it is DEBUG_ANY_ID.
#define DEBUG_CDS_DATA      0x00000002

// ChangeEngineState flags.
// The engine state has changed generally.
// Argument is zero.
#define DEBUG_CES_ALL                 0xffffffff
// Current thread changed.  This may imply a change
// of system and process also.  Argument is the ID of the new
// current thread or DEBUG_ANY_ID if no thread is current.
#define DEBUG_CES_CURRENT_THREAD      0x00000001
// Effective processor changed.  Argument is the
// new processor type.
#define DEBUG_CES_EFFECTIVE_PROCESSOR 0x00000002
// Breakpoints changed.  If only a single breakpoint
// changed, argument is the ID of the breakpoint.
// Otherwise it is DEBUG_ANY_ID.
#define DEBUG_CES_BREAKPOINTS         0x00000004
// Code interpretation level changed.  Argument is
// the new level.
#define DEBUG_CES_CODE_LEVEL          0x00000008
// Execution status changed.  Argument is the new
// execution status.
#define DEBUG_CES_EXECUTION_STATUS    0x00000010
// Engine options have changed.  Argument is the new
// options value.
#define DEBUG_CES_ENGINE_OPTIONS      0x00000020
// Log file information has changed.  Argument
// is TRUE if a log file was opened and FALSE if
// a log file was closed.
#define DEBUG_CES_LOG_FILE            0x00000040
// Default number radix has changed.  Argument
// is the new radix.
#define DEBUG_CES_RADIX               0x00000080
// Event filters changed.  If only a single filter
// changed the argument is the filter's index,
// otherwise it is DEBUG_ANY_ID.
#define DEBUG_CES_EVENT_FILTERS       0x00000100
// Process options have changed.  Argument is the new
// options value.
#define DEBUG_CES_PROCESS_OPTIONS     0x00000200
// Extensions have been added or removed.
#define DEBUG_CES_EXTENSIONS          0x00000400
// Systems have been added or removed.  The argument
// is the system ID.  Systems, unlike processes and
// threads, may be created at any time and not
// just during WaitForEvent.
#define DEBUG_CES_SYSTEMS             0x00000800
// Assembly/disassembly options have changed.  Argument
// is the new options value.
#define DEBUG_CES_ASSEMBLY_OPTIONS    0x00001000
// Expression syntax has changed.  Argument
// is the new syntax value.
#define DEBUG_CES_EXPRESSION_SYNTAX   0x00002000
// Text replacements have changed.
#define DEBUG_CES_TEXT_REPLACEMENTS   0x00004000

// ChangeSymbolState flags.
// Symbol state has changed generally, such
// as after reload operations.  Argument is zero.
#define DEBUG_CSS_ALL            0xffffffff
// Modules have been loaded.  If only a
// single module changed, argument is the
// base address of the module.  Otherwise
// it is zero.
#define DEBUG_CSS_LOADS          0x00000001
// Modules have been unloaded.  If only a
// single module changed, argument is the
// base address of the module.  Otherwise
// it is zero.
#define DEBUG_CSS_UNLOADS        0x00000002
// Current symbol scope changed.
#define DEBUG_CSS_SCOPE          0x00000004
// Paths have changed.
#define DEBUG_CSS_PATHS          0x00000008
// Symbol options have changed.  Argument is the new
// options value.
#define DEBUG_CSS_SYMBOL_OPTIONS 0x00000010
// Type options have changed.  Argument is the new
// options value.
#define DEBUG_CSS_TYPE_OPTIONS   0x00000020

IDebugEventCallbacks STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugEventCallbacks.

    // The engine calls GetInterestMask once when
    // the event callbacks are set for a client.
	GetInterestMask PTR
    // A breakpoint event is generated when
    // a breakpoint exception is received and
    // it can be mapped to an existing breakpoint.
    // The callback method is given a reference
    // to the breakpoint and should release it when
    // it is done with it.
	Breakpoint PTR
    // Exceptions include breaks which cannot
    // be mapped to an existing breakpoint
    // instance.
	Exception PTR
    // Any of these values can be zero if they
    // cannot be provided by the engine.
    // Currently the kernel does not return thread
    // or process change events.
	CreateThread PTR
	ExitThread PTR
    // Any of these values can be zero if they
    // cannot be provided by the engine.
	CreateProcess PTR
	ExitProcess PTR
    // Any of these values may be zero.
	LoadModule PTR
	UnloadModule PTR
	SystemError PTR
    // Session status is synchronous like the other
    // wait callbacks but it is called as the state
    // of the session is changing rather than at
    // specific events so its return value does not
    // influence waiting.  Implementations should just
    // return DEBUG_STATUS_NO_CHANGE.
    // Also, because some of the status
    // notifications are very early or very
    // late in the session lifetime there may not be
    // current processes or threads when the notification
    // is generated.
	SessionStatus PTR
    // The following callbacks are informational
    // callbacks notifying the provider about
    // changes in debug state.  The return value
    // of these callbacks is ignored.  Implementations
    // can not call back into the engine.

    // Debuggee state, such as registers or data spaces,
    // has changed.
	ChangeDebuggeeState PTR
    // Engine state has changed.
	ChangeEngineState PTR
    // Symbol state has changed.
	ChangeSymbolState PTR
ENDS

IDebugEventCallbacksWide STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugEventCallbacksWide.

    // The engine calls GetInterestMask once when
    // the event callbacks are set for a client.
	GetInterestMask PTR
    // A breakpoint event is generated when
    // a breakpoint exception is received and
    // it can be mapped to an existing breakpoint.
    // The callback method is given a reference
    // to the breakpoint and should release it when
    // it is done with it.
	Breakpoint PTR
    // Exceptions include breaks which cannot
    // be mapped to an existing breakpoint
    // instance.
	Exception PTR
    // Any of these values can be zero if they
    // cannot be provided by the engine.
    // Currently the kernel does not return thread
    // or process change events.
	CreateThread PTR
	ExitThread PTR
    // Any of these values can be zero if they
    // cannot be provided by the engine.
	CreateProcess PTR
	ExitProcess PTR
    // Any of these values may be zero.
	LoadModule PTR
	UnloadModule PTR
	SystemError PTR
    // Session status is synchronous like the other
    // wait callbacks but it is called as the state
    // of the session is changing rather than at
    // specific events so its return value does not
    // influence waiting.  Implementations should just
    // return DEBUG_STATUS_NO_CHANGE.
    // Also, because some of the status
    // notifications are very early or very
    // late in the session lifetime there may not be
    // current processes or threads when the notification
    // is generated.
	SessionStatus PTR
    // The following callbacks are informational
    // callbacks notifying the provider about
    // changes in debug state.  The return value
    // of these callbacks is ignored.  Implementations
    // can not call back into the engine.

    // Debuggee state, such as registers or data spaces,
    // has changed.
	ChangeDebuggeeState PTR
    // Engine state has changed.
	ChangeEngineState PTR
    // Symbol state has changed.
	ChangeSymbolState PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugInputCallbacks.
//
//----------------------------------------------------------------------------

IDebugInputCallbacks STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugInputCallbacks.

    // A call to the StartInput method is a request for
    // a line of input from any client.  The returned input
    // should always be zero-terminated.  The buffer size
    // provided is only a guideline.  A client can return
    // more if necessary and the engine will truncate it
    // before returning from IDebugControl::Input.
    // The return value is ignored.
	StartInput PTR
    // The return value is ignored.
	EndInput PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugOutputCallbacks.
//
//----------------------------------------------------------------------------

IDebugOutputCallbacks STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugOutputCallbacks.

    // This method is only called if the supplied mask
    // is allowed by the clients output control.
    // The return value is ignored.
	Output PTR
ENDS

IDebugOutputCallbacksWide STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugOutputCallbacksWide.

    // This method is only called if the supplied mask
    // is allowed by the clients output control.
    // The return value is ignored.
	Output PTR
ENDS

//
// IDebugOutputCallbacks2 interest mask flags.
//

// Indicates that the callback wants notifications
// of all explicit flushes.
#define DEBUG_OUTCBI_EXPLICIT_FLUSH 0x00000001
// Indicates that the callback wants
// content in text form.
#define DEBUG_OUTCBI_TEXT           0x00000002
// Indicates that the callback wants
// content in markup form.
#define DEBUG_OUTCBI_DML            0x00000004

#define DEBUG_OUTCBI_ANY_FORMAT     0x00000006

//
// Different kinds of output callback notifications
// that can be sent to Output2.
//

// Plain text content, flags are below, argument is mask.
#define DEBUG_OUTCB_TEXT           0
// Debugger markup content, flags are below, argument is mask.
#define DEBUG_OUTCB_DML            1
// Notification of an explicit output flush, flags and argument are zero.
#define DEBUG_OUTCB_EXPLICIT_FLUSH 2

//
// Flags for various Output2 callbacks.
//

// The content string was followed by an
// explicit flush.  This flag will be used
// instead of a separate DEBUG_OUTCB_EXPLICIT_FLUSH
// callback when a flush has text to flush,
// thus avoiding two callbacks.
#define DEBUG_OUTCBF_COMBINED_EXPLICIT_FLUSH    0x00000001

// The markup content string has embedded tags.
#define DEBUG_OUTCBF_DML_HAS_TAGS               0x00000002
// The markup content has encoded special characters like ", &, < and >.
#define DEBUG_OUTCBF_DML_HAS_SPECIAL_CHARACTERS 0x00000004

IDebugOutputCallbacks2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugOutputCallbacks.

    // This method is only called if the supplied mask
    // is allowed by the clients output control.
    // The return value is ignored.
	Output PTR
    // IDebugOutputCallbacks2.

    // The engine calls GetInterestMask once when
    // the callbacks are set for a client.
	GetInterestMask PTR
	Output2 PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugRegisters.
//
//----------------------------------------------------------------------------

#define DEBUG_REGISTERS_DEFAULT 0x00000000
#define DEBUG_REGISTERS_INT32   0x00000001
#define DEBUG_REGISTERS_INT64   0x00000002
#define DEBUG_REGISTERS_FLOAT   0x00000004
#define DEBUG_REGISTERS_ALL     0x00000007

#define DEBUG_REGISTER_SUB_REGISTER 0x00000001

DEBUG_REGISTER_DESCRIPTION STRUCT
    // DEBUG_VALUE type.
	Type DD
	Flags DD

    // If this is a subregister the full
    // registers description index is
    // given in SubregMaster.  The length, mask
    // and shift describe how the subregisters
    // bits fit into the full register.
	SubregMaster DD
	SubregLength DD
	SubregMask DQ
	SubregShift DD
	Reserved0 DD
ENDS

IDebugRegisters STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugRegisters.
	GetNumberRegisters PTR
	GetDescription PTR
	GetIndexByName PTR
	GetValue PTR
    // SetValue makes a best effort at coercing
    // the given value into the given registers
    // value type.  If the given value is larger
    // than the register can hold the least
    // significant bits will be dropped.  Float
    // to int and int to float will be done
    // if necessary.  Subregister bits will be
    // inserted into the master register.
	SetValue PTR
    // Gets Count register values.  If Indices is
    // non-NULL it must contain Count register
    // indices which control the registers affected.
    // If Indices is NULL the registers from Start
    // to Start + Count  1 are retrieved.
	GetValues PTR
	SetValues PTR
    // Outputs a group of registers in a well-formatted
    // way thats specific to the platforms register set.
    // Uses the line prefix.
	OutputRegisters PTR
    // Abstracted pieces of processor information.
    // The mapping of these values to architectural
    // registers is architecture-specific and their
    // interpretation and existence may vary.  They
    // are intended to be directly compatible with
    // calls which take this information, such as
    // stack walking.
	GetInstructionOffset PTR
	GetStackOffset PTR
	GetFrameOffset PTR
ENDS

//
// The engine maintains several separate
// pieces of context information.  There is
// the current debuggee context, a possible
// override context, such as from .cxr,
// a context for the current scope frame and so on.
//

// Get register information from the debuggee.
#define DEBUG_REGSRC_DEBUGGEE 0x00000000
// Get register information from an explicit
// override context, such as one set by .cxr.
// If there is no override context the request will fail.
#define DEBUG_REGSRC_EXPLICIT 0x00000001
// Get register information from the current scope
// frame.  Note that stack unwinding does not guarantee
// accurate updating of the register context,
// so scope frame register context may not be accurate
// in all cases.
#define DEBUG_REGSRC_FRAME    0x00000002

IDebugRegisters2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugRegisters.
	GetNumberRegisters PTR
	GetDescription PTR
	GetIndexByName PTR
	GetValue PTR
    // SetValue makes a best effort at coercing
    // the given value into the given registers
    // value type.  If the given value is larger
    // than the register can hold the least
    // significant bits will be dropped.  Float
    // to int and int to float will be done
    // if necessary.  Subregister bits will be
    // inserted into the master register.
	SetValue PTR
    // Gets Count register values.  If Indices is
    // non-NULL it must contain Count register
    // indices which control the registers affected.
    // If Indices is NULL the registers from Start
    // to Start + Count  1 are retrieved.
	GetValues PTR
	SetValues PTR
    // Outputs a group of registers in a well-formatted
    // way thats specific to the platforms register set.
    // Uses the line prefix.
	OutputRegisters PTR
    // Abstracted pieces of processor information.
    // The mapping of these values to architectural
    // registers is architecture-specific and their
    // interpretation and existence may vary.  They
    // are intended to be directly compatible with
    // calls which take this information, such as
    // stack walking.
	GetInstructionOffset PTR
	GetStackOffset PTR
	GetFrameOffset PTR
    // IDebugRegisters2.

	GetDescriptionWide PTR
	GetIndexByNameWide PTR
    // Pseudo-registers are synthetic values derived
    // by the engine that are presented in a manner
    // similar to regular registers.  They are simple
    // value holders, similar to actual registers.
    // Pseudo-registers are defined for concepts,
    // such as current-instruction-pointer or
    // current-thread-data.  As such they have
    // types appropriate for their data.
	GetNumberPseudoRegisters PTR
	GetPseudoDescription PTR
	GetPseudoDescriptionWide PTR
	GetPseudoIndexByName PTR
	GetPseudoIndexByNameWide PTR
    // Some pseudo-register values are affected
    // by the register source, others are not.
	GetPseudoValues PTR
    // Many pseudo-registers are read-only and cannot be set.
	SetPseudoValues PTR
    // These expanded methods allow selection
    // of the source of register information.
	GetValues2 PTR
	SetValues2 PTR
	OutputRegisters2 PTR
	GetInstructionOffset2 PTR
	GetStackOffset2 PTR
	GetFrameOffset2 PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugSymbolGroup
//
//----------------------------------------------------------------------------

// OutputSymbols flags.
// Default output contains
//   <Name>**NAME**<Offset>**OFF**<Value>**VALUE**<Type>**TYPE**
// per symbol.
#define DEBUG_OUTPUT_SYMBOLS_DEFAULT    0x00000000
#define DEBUG_OUTPUT_SYMBOLS_NO_NAMES   0x00000001
#define DEBUG_OUTPUT_SYMBOLS_NO_OFFSETS 0x00000002
#define DEBUG_OUTPUT_SYMBOLS_NO_VALUES  0x00000004
#define DEBUG_OUTPUT_SYMBOLS_NO_TYPES   0x00000010

#define DEBUG_OUTPUT_NAME_END           "**NAME**"
#define DEBUG_OUTPUT_OFFSET_END         "**OFF**"
#define DEBUG_OUTPUT_VALUE_END          "**VALUE**"
#define DEBUG_OUTPUT_TYPE_END           "**TYPE**"

#define DEBUG_OUTPUT_NAME_END_WIDE      L"**NAME**"
#define DEBUG_OUTPUT_OFFSET_END_WIDE    L"**OFF**"
#define DEBUG_OUTPUT_VALUE_END_WIDE     L"**VALUE**"
#define DEBUG_OUTPUT_TYPE_END_WIDE      L"**TYPE**"

#ifdef UNICODE
#define DEBUG_OUTPUT_NAME_END_T DEBUG_OUTPUT_NAME_END_WIDE
#define DEBUG_OUTPUT_OFFSET_END_T DEBUG_OUTPUT_OFFSET_END_WIDE
#define DEBUG_OUTPUT_VALUE_END_T DEBUG_OUTPUT_VALUE_END_WIDE
#define DEBUG_OUTPUT_TYPE_END_T DEBUG_OUTPUT_TYPE_END_WIDE
#else
#define DEBUG_OUTPUT_NAME_END_T DEBUG_OUTPUT_NAME_END
#define DEBUG_OUTPUT_OFFSET_END_T DEBUG_OUTPUT_OFFSET_END
#define DEBUG_OUTPUT_VALUE_END_T DEBUG_OUTPUT_VALUE_END
#define DEBUG_OUTPUT_TYPE_END_T DEBUG_OUTPUT_TYPE_END
#endif

// DEBUG_SYMBOL_PARAMETERS flags.
// Cumulative expansion level, takes four bits.
#define DEBUG_SYMBOL_EXPANSION_LEVEL_MASK 0x0000000f
// Symbols subelements follow.
#define DEBUG_SYMBOL_EXPANDED             0x00000010
// Symbols value is read-only.
#define DEBUG_SYMBOL_READ_ONLY            0x00000020
// Symbol subelements are array elements.
#define DEBUG_SYMBOL_IS_ARRAY             0x00000040
// Symbol is a float value.
#define DEBUG_SYMBOL_IS_FLOAT             0x00000080
// Symbol is a scope argument.
#define DEBUG_SYMBOL_IS_ARGUMENT          0x00000100
// Symbol is a scope argument.
#define DEBUG_SYMBOL_IS_LOCAL             0x00000200

DEBUG_SYMBOL_PARAMETERS STRUCT
	Module DQ
	TypeId DD
    // ParentSymbol may be DEBUG_ANY_ID when unknown.
	ParentSymbol DD
    // A subelement of a symbol can be a field, such
    // as in structs, unions or classes; or an array
    // element count for arrays.
	SubElements DD
	Flags DD
	Reserved DQ
ENDS

IDebugSymbolGroup STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSymbolGroup.
	GetNumberSymbols PTR
    // On input Index indicates the desired insertion
    // index.  On output Index contains the actual index.
    // Use DEBUG_ANY_ID to append a symbol to the end.
	AddSymbol PTR
	RemoveSymbolByName PTR
	RemoveSymbolByIndex PTR
	GetSymbolName PTR
	GetSymbolParameters PTR
	ExpandSymbol PTR
    // Uses the line prefix.
	OutputSymbols PTR
	WriteSymbol PTR
	OutputAsType PTR
ENDS

#define DEBUG_SYMENT_IS_CODE      0x00000001
#define DEBUG_SYMENT_IS_DATA      0x00000002
#define DEBUG_SYMENT_IS_PARAMETER 0x00000004
#define DEBUG_SYMENT_IS_LOCAL     0x00000008
#define DEBUG_SYMENT_IS_MANAGED   0x00000010
#define DEBUG_SYMENT_IS_SYNTHETIC 0x00000020

typedef struct _DEBUG_SYMBOL_ENTRY
	ModuleBase DQ
	Offset DQ
	Id DQ
	Arg64 DQ
	Size DD
	Flags DD
	TypeId DD
	NameSize DD
	Token DD
	Tag DD
	Arg32 DD
	Reserved DD
ENDS

IDebugSymbolGroup2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSymbolGroup.
	GetNumberSymbols PTR
    // On input Index indicates the desired insertion
    // index.  On output Index contains the actual index.
    // Use DEBUG_ANY_ID to append a symbol to the end.
	AddSymbol PTR
	RemoveSymbolByName PTR
	RemoveSymbolByIndex PTR
	GetSymbolName PTR
	GetSymbolParameters PTR
	ExpandSymbol PTR
    // Uses the line prefix.
	OutputSymbols PTR
	WriteSymbol PTR
	OutputAsType PTR
    // IDebugSymbolGroup2.
	AddSymbolWide PTR
	RemoveSymbolByNameWide PTR
	GetSymbolNameWide PTR
	WriteSymbolWide PTR
	OutputAsTypeWide PTR
	GetSymbolTypeName PTR
	GetSymbolTypeNameWide PTR
	GetSymbolSize PTR
	GetSymbolOffset PTR
	GetSymbolRegister PTR
	GetSymbolValueText PTR
	GetSymbolValueTextWide PTR
	GetSymbolEntryInformation PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugSymbols.
//
//----------------------------------------------------------------------------

//
// Information about a module.
//

// Flags.
#define DEBUG_MODULE_LOADED            0x00000000
#define DEBUG_MODULE_UNLOADED          0x00000001
#define DEBUG_MODULE_USER_MODE         0x00000002
#define DEBUG_MODULE_EXE_MODULE        0x00000004
#define DEBUG_MODULE_EXPLICIT          0x00000008
#define DEBUG_MODULE_SECONDARY         0x00000010
#define DEBUG_MODULE_SYNTHETIC         0x00000020
#define DEBUG_MODULE_SYM_BAD_CHECKSUM  0x00010000

// Symbol types.
#define DEBUG_SYMTYPE_NONE     0
#define DEBUG_SYMTYPE_COFF     1
#define DEBUG_SYMTYPE_CODEVIEW 2
#define DEBUG_SYMTYPE_PDB      3
#define DEBUG_SYMTYPE_EXPORT   4
#define DEBUG_SYMTYPE_DEFERRED 5
#define DEBUG_SYMTYPE_SYM      6
#define DEBUG_SYMTYPE_DIA      7

DEBUG_MODULE_PARAMETERS STRUCT
	Base DQ
	Size DD
	TimeDateStamp DD
	Checksum DD
	Flags DD
	SymbolType DD
	ImageNameSize DD
	ModuleNameSize DD
	LoadedImageNameSize DD
	SymbolFileNameSize DD
	MappedImageNameSize DD
	Reserved DQ 2 DUP
ENDS

// Scope arguments are function arguments
// and thus only change when the scope
// crosses functions.
#define DEBUG_SCOPE_GROUP_ARGUMENTS 0x00000001
// Scope locals are locals declared in a particular
// scope and are only defined within that scope.
#define DEBUG_SCOPE_GROUP_LOCALS    0x00000002
// All symbols in the scope.
#define DEBUG_SCOPE_GROUP_ALL       0x00000003

// Typed data output control flags.
#define DEBUG_OUTTYPE_DEFAULT              0x00000000
#define DEBUG_OUTTYPE_NO_INDENT            0x00000001
#define DEBUG_OUTTYPE_NO_OFFSET            0x00000002
#define DEBUG_OUTTYPE_VERBOSE              0x00000004
#define DEBUG_OUTTYPE_COMPACT_OUTPUT       0x00000008
#define DEBUG_OUTTYPE_RECURSION_LEVEL(Max) (((Max) & 0xf) << 4)
#define DEBUG_OUTTYPE_ADDRESS_OF_FIELD     0x00010000
#define DEBUG_OUTTYPE_ADDRESS_AT_END       0x00020000
#define DEBUG_OUTTYPE_BLOCK_RECURSE        0x00200000

// FindSourceFile flags.
#define DEBUG_FIND_SOURCE_DEFAULT      0x00000000
// Returns fully-qualified paths only.  If this
// is not set the path returned may be relative.
#define DEBUG_FIND_SOURCE_FULL_PATH    0x00000001
// Scans all the path elements for a match and
// returns the one that has the most similarity
// between the given file and the matching element.
#define DEBUG_FIND_SOURCE_BEST_MATCH   0x00000002
// Do not search source server paths.
#define DEBUG_FIND_SOURCE_NO_SRCSRV    0x00000004
// Restrict FindSourceFileAndToken to token lookup only.
#define DEBUG_FIND_SOURCE_TOKEN_LOOKUP 0x00000008

// A special value marking an offset that should not
// be treated as a valid offset.  This is only used
// in special situations where it is unlikely that
// this value would be a valid offset.
#define DEBUG_INVALID_OFFSET ((ULONG64)-1)

// Module index sort order used by GetModuleByIndex() API.
#define MODULE_ORDERS_MASK       0xF0000000
#define MODULE_ORDERS_LOADTIME   0x10000000
#define MODULE_ORDERS_MODULENAME 0x20000000

IDebugSymbols STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSym
    // IDebugSymbols.

    // Controls the symbol options used during
    // symbol operations.
    // Uses the same flags as dbghelps SymSetOptions.
	GetSymbolOptions PTR
	AddSymbolOptions PTR
	RemoveSymbolOptions PTR
	SetSymbolOptions PTR
	GetNameByOffset PTR
    // A symbol name may not be unique, particularly
    // when overloaded functions exist which all
    // have the same name.  If GetOffsetByName
    // finds multiple matches for the name it
    // can return any one of them.  In that
    // case it will return S_FALSE to indicate
    // that ambiguity was arbitrarily resolved.
    // A caller can then use SearchSymbols to
    // find all of the matches if it wishes to
    // perform different disambiguation.
	GetOffsetByName PTR
    // GetNearNameByOffset returns symbols
    // located near the symbol closest to
    // to the offset, such as the previous
    // or next symbol.  If Delta is zero it
    // operates identically to GetNameByOffset.
    // If Delta is nonzero and such a symbol
    // does not exist an error is returned.
    // The next symbol, if one exists, will
    // always have a higher offset than the
    // input offset so the displacement is
    // always negative.  The situation is
    // reversed for the previous symbol.
	GetNearNameByOffset PTR
	GetLineByOffset PTR
	GetOffsetByLine PTR
    // Enumerates the engines list of modules
    // loaded for the current process.  This may
    // or may not match the system module list
    // for the process.  Reload can be used to
    // synchronize the engines list with the system
    // if necessary.
    // Some sessions also track recently unloaded
    // code modules for help in analyzing failures
    // where an attempt is made to call unloaded code.
    // These modules are indexed after the loaded
    // modules.
	GetNumberModules PTR
	GetModuleByIndex PTR
    // The module name may not be unique.
    // This method returns the first match.
	GetModuleByModuleName PTR
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
	GetModuleByOffset PTR
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
	GetModuleNames PTR
	GetModuleParameters PTR
    // Looks up the module from a <Module>!<Symbol>
    // string.
	GetSymbolModule PTR
    // Returns the string name of a type.
	GetTypeName PTR
    // Returns the ID for a type name.
	GetTypeId PTR
	GetTypeSize PTR
    // Given a type which can contain members
    // this method returns the offset of a
    // particular member within the type.
    // TypeId should give the container type ID
    // and Field gives the dot-separated path
    // to the field of interest.
	GetFieldOffset PTR
	GetSymbolTypeId PTR
    // As with GetOffsetByName a symbol's
    // name may be ambiguous.  GetOffsetTypeId
    // returns the type for the symbol closest
    // to the given offset and can be used
    // to avoid ambiguity.
	GetOffsetTypeId PTR
    // Helpers for virtual and physical data
    // which combine creation of a location with
    // the actual operation.
	ReadTypedDataVirtual PTR
	WriteTypedDataVirtual PTR
	OutputTypedDataVirtual PTR
	ReadTypedDataPhysical PTR
	WriteTypedDataPhysical PTR
	OutputTypedDataPhysical PTR
    // Function arguments and scope block symbols
    // can be retrieved relative to currently
    // executing code.  A caller can provide just
    // a code offset for scoping purposes and look
    // up names or the caller can provide a full frame
    // and look up actual values.  The values for
    // scoped symbols are best-guess and may or may not
    // be accurate depending on program optimizations,
    // the machine architecture, the current point
    // in the programs execution and so on.
    // A caller can also provide a complete register
    // context for setting a scope to a previous
    // machine state such as a context saved for
    // an exception.  Usually this isnt necessary
    // and the current register context is used.
	GetScope PTR
    // If ScopeFrame or ScopeContext is non-NULL then
    // InstructionOffset is ignored.
    // If ScopeContext is NULL the current
    // register context is used.
    // If the scope identified by the given
    // information is the same as before
    // SetScope returns S_OK.  If the scope
    // information changes, such as when the
    // scope moves between functions or scope
    // blocks, SetScope returns S_FALSE.
	SetScope PTR
    // ResetScope clears the scope information
    // for situations where scoped symbols
    // mask global symbols or when resetting
    // from explicit information to the current
    // information.
	ResetScope PTR
    // A scope symbol is tied to its particular
    // scope and only is meaningful within the scope.
    // The returned group can be updated by passing it back
    // into the method for lower-cost
    // incremental updates when stepping.
	GetScopeSymbolGroup PTR
    // Create a new symbol group.
	CreateSymbolGroup PTR
    // StartSymbolMatch matches symbol names
    // against the given pattern using simple
    // regular expressions.  The search results
    // are iterated through using GetNextSymbolMatch.
    // When the caller is done examining results
    // the match should be freed via EndSymbolMatch.
    // If the match pattern contains a module name
    // the search is restricted to a single module.
    // Pattern matching is only done on symbol names,
    // not module names.
    // All active symbol match handles are invalidated
    // when the set of loaded symbols changes.
	StartSymbolMatch PTR
    // If Buffer is NULL the match does not
    // advance.
	GetNextSymbolMatch PTR
	EndSymbolMatch PTR
	Reload PTR
	GetSymbolPath PTR
	SetSymbolPath PTR
	AppendSymbolPath PTR
    // Manipulate the path for executable images.
    // Some dump files need to load executable images
    // in order to resolve dump information.  This
    // path controls where the engine looks for
    // images.
	GetImagePath PTR
	SetImagePath PTR
	AppendImagePath PTR
    // Path routines for source file location
    // methods.
	GetSourcePath PTR
    // Gets the nth part of the source path.
	GetSourcePathElement PTR
	SetSourcePath PTR
	AppendSourcePath PTR
    // Uses the given file path and the source path
    // information to try and locate an existing file.
    // The given file path is merged with elements
    // of the source path and checked for existence.
    // If a match is found the element used is returned.
    // A starting element can be specified to restrict
    // the search to a subset of the path elements;
    // this can be useful when checking for multiple
    // matches along the source path.
    // The returned element can be 1, indicating
    // the file was found directly and not on the path.
	FindSourceFile PTR
    // Retrieves all the line offset information
    // for a particular source file.  Buffer is
    // first intialized to DEBUG_INVALID_OFFSET for
    // every entry.  Then for each piece of line
    // symbol information Buffer[Line] set to
    // Lines offset.  This produces a per-line
    // map of the offsets for the lines of the
    // given file.  Line numbers are decremented
    // for the map so Buffer[0] contains the offset
    // for line number 1.
    // If there is no line information at all for
    // the given file the method fails rather
    // than returning a map of invalid offsets.
	GetSourceFileLineOffsets PTR
ENDS

//
// GetModuleNameString strings.
//

#define DEBUG_MODNAME_IMAGE        0x00000000
#define DEBUG_MODNAME_MODULE       0x00000001
#define DEBUG_MODNAME_LOADED_IMAGE 0x00000002
#define DEBUG_MODNAME_SYMBOL_FILE  0x00000003
#define DEBUG_MODNAME_MAPPED_IMAGE 0x00000004

//
// Type options, used with Get/SetTypeOptions.
//

// Display PUSHORT and USHORT arrays in Unicode.
#define DEBUG_TYPEOPTS_UNICODE_DISPLAY    0x00000001
// Display LONG types in default base instead of decimal.
#define DEBUG_TYPEOPTS_LONGSTATUS_DISPLAY 0x00000002
// Display integer types in default base instead of decimal.
#define DEBUG_TYPEOPTS_FORCERADIX_OUTPUT  0x00000004
// Search for the type/symbol with largest size when
// multiple type/symbol match for a given name
#define DEBUG_TYPEOPTS_MATCH_MAXSIZE      0x00000008

IDebugSymbols2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSym
    // IDebugSymbols.

    // Controls the symbol options used during
    // symbol operations.
    // Uses the same flags as dbghelps SymSetOptions.
	GetSymbolOptions PTR
	AddSymbolOptions PTR
	RemoveSymbolOptions PTR
	SetSymbolOptions PTR
	GetNameByOffset PTR
    // A symbol name may not be unique, particularly
    // when overloaded functions exist which all
    // have the same name.  If GetOffsetByName
    // finds multiple matches for the name it
    // can return any one of them.  In that
    // case it will return S_FALSE to indicate
    // that ambiguity was arbitrarily resolved.
    // A caller can then use SearchSymbols to
    // find all of the matches if it wishes to
    // perform different disambiguation.
	GetOffsetByName PTR
    // GetNearNameByOffset returns symbols
    // located near the symbol closest to
    // to the offset, such as the previous
    // or next symbol.  If Delta is zero it
    // operates identically to GetNameByOffset.
    // If Delta is nonzero and such a symbol
    // does not exist an error is returned.
    // The next symbol, if one exists, will
    // always have a higher offset than the
    // input offset so the displacement is
    // always negative.  The situation is
    // reversed for the previous symbol.
	GetNearNameByOffset PTR
	GetLineByOffset PTR
	GetOffsetByLine PTR
    // Enumerates the engines list of modules
    // loaded for the current process.  This may
    // or may not match the system module list
    // for the process.  Reload can be used to
    // synchronize the engines list with the system
    // if necessary.
    // Some sessions also track recently unloaded
    // code modules for help in analyzing failures
    // where an attempt is made to call unloaded code.
    // These modules are indexed after the loaded
    // modules.
	GetNumberModules PTR
	GetModuleByIndex PTR
    // The module name may not be unique.
    // This method returns the first match.
	GetModuleByModuleName PTR
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
	GetModuleByOffset PTR
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
	GetModuleNames PTR
	GetModuleParameters PTR
    // Looks up the module from a <Module>!<Symbol>
    // string.
	GetSymbolModule PTR
    // Returns the string name of a type.
	GetTypeName PTR
    // Returns the ID for a type name.
	GetTypeId PTR
	GetTypeSize PTR
    // Given a type which can contain members
    // this method returns the offset of a
    // particular member within the type.
    // TypeId should give the container type ID
    // and Field gives the dot-separated path
    // to the field of interest.
	GetFieldOffset PTR
	GetSymbolTypeId PTR
    // As with GetOffsetByName a symbol's
    // name may be ambiguous.  GetOffsetTypeId
    // returns the type for the symbol closest
    // to the given offset and can be used
    // to avoid ambiguity.
	GetOffsetTypeId PTR
    // Helpers for virtual and physical data
    // which combine creation of a location with
    // the actual operation.
	ReadTypedDataVirtual PTR
	WriteTypedDataVirtual PTR
	OutputTypedDataVirtual PTR
	ReadTypedDataPhysical PTR
	WriteTypedDataPhysical PTR
	OutputTypedDataPhysical PTR
    // Function arguments and scope block symbols
    // can be retrieved relative to currently
    // executing code.  A caller can provide just
    // a code offset for scoping purposes and look
    // up names or the caller can provide a full frame
    // and look up actual values.  The values for
    // scoped symbols are best-guess and may or may not
    // be accurate depending on program optimizations,
    // the machine architecture, the current point
    // in the programs execution and so on.
    // A caller can also provide a complete register
    // context for setting a scope to a previous
    // machine state such as a context saved for
    // an exception.  Usually this isnt necessary
    // and the current register context is used.
	GetScope PTR
    // If ScopeFrame or ScopeContext is non-NULL then
    // InstructionOffset is ignored.
    // If ScopeContext is NULL the current
    // register context is used.
    // If the scope identified by the given
    // information is the same as before
    // SetScope returns S_OK.  If the scope
    // information changes, such as when the
    // scope moves between functions or scope
    // blocks, SetScope returns S_FALSE.
	SetScope PTR
    // ResetScope clears the scope information
    // for situations where scoped symbols
    // mask global symbols or when resetting
    // from explicit information to the current
    // information.
	ResetScope PTR
    // A scope symbol is tied to its particular
    // scope and only is meaningful within the scope.
    // The returned group can be updated by passing it back
    // into the method for lower-cost
    // incremental updates when stepping.
	GetScopeSymbolGroup PTR
    // Create a new symbol group.
	CreateSymbolGroup PTR
    // StartSymbolMatch matches symbol names
    // against the given pattern using simple
    // regular expressions.  The search results
    // are iterated through using GetNextSymbolMatch.
    // When the caller is done examining results
    // the match should be freed via EndSymbolMatch.
    // If the match pattern contains a module name
    // the search is restricted to a single module.
    // Pattern matching is only done on symbol names,
    // not module names.
    // All active symbol match handles are invalidated
    // when the set of loaded symbols changes.
	StartSymbolMatch PTR
    // If Buffer is NULL the match does not
    // advance.
	GetNextSymbolMatch PTR
	EndSymbolMatch PTR
	Reload PTR
	GetSymbolPath PTR
	SetSymbolPath PTR
	AppendSymbolPath PTR
    // Manipulate the path for executable images.
    // Some dump files need to load executable images
    // in order to resolve dump information.  This
    // path controls where the engine looks for
    // images.
	GetImagePath PTR
	SetImagePath PTR
	AppendImagePath PTR
    // Path routines for source file location
    // methods.
	GetSourcePath PTR
    // Gets the nth part of the source path.
	GetSourcePathElement PTR
	SetSourcePath PTR
	AppendSourcePath PTR
    // Uses the given file path and the source path
    // information to try and locate an existing file.
    // The given file path is merged with elements
    // of the source path and checked for existence.
    // If a match is found the element used is returned.
    // A starting element can be specified to restrict
    // the search to a subset of the path elements;
    // this can be useful when checking for multiple
    // matches along the source path.
    // The returned element can be 1, indicating
    // the file was found directly and not on the path.
	FindSourceFile PTR
    // Retrieves all the line offset information
    // for a particular source file.  Buffer is
    // first intialized to DEBUG_INVALID_OFFSET for
    // every entry.  Then for each piece of line
    // symbol information Buffer[Line] set to
    // Lines offset.  This produces a per-line
    // map of the offsets for the lines of the
    // given file.  Line numbers are decremented
    // for the map so Buffer[0] contains the offset
    // for line number 1.
    // If there is no line information at all for
    // the given file the method fails rather
    // than returning a map of invalid offsets.
	GetSourceFileLineOffsets PTR
    // IDebugSymbols2.

    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // Item is specified as in VerQueryValue.
    // Module version information is only
    // available for loaded modules and may
    // not be available in all debug sessions.
	GetModuleVersionInformation)(
    // Retrieves any available module name string
    // such as module name or symbol file name.
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // If symbols are deferred an error will
    // be returned.
    // E_NOINTERFACE may be returned, indicating
    // no information exists.
	GetModuleNameString PTR
    // Returns the string name of a constant type.
	GetConstantName PTR
    // Gets name of a field in a struct
    // FieldNumber is 0 based index of field in a struct
	GetFieldName PTR
    // Control options for typed values.
	GetTypeOptions PTR
	AddTypeOptions PTR
	RemoveTypeOptions PTR
	SetTypeOptions PTR
ENDS

//
// GetModuleBy* flags.
//

// Scan all modules, loaded and unloaded.
#define DEBUG_GETMOD_DEFAULT             0x00000000
// Do not scan loaded modules.
#define DEBUG_GETMOD_NO_LOADED_MODULES   0x00000001
// Do not scan unloaded modules.
#define DEBUG_GETMOD_NO_UNLOADED_MODULES 0x00000002

//
// AddSyntheticModule flags.
//

#define DEBUG_ADDSYNTHMOD_DEFAULT 0x00000000

//
// AddSyntheticSymbol flags.
//

#define DEBUG_ADDSYNTHSYM_DEFAULT 0x00000000

//
// OutputSymbolByOffset flags.
//

// Use the current debugger settings for symbol output.
#define DEBUG_OUTSYM_DEFAULT            0x00000000
// Always display the offset in addition to any symbol hit.
#define DEBUG_OUTSYM_FORCE_OFFSET       0x00000001
// Display source line information if found.
#define DEBUG_OUTSYM_SOURCE_LINE        0x00000002
// Output symbol hits that don't exactly match.
#define DEBUG_OUTSYM_ALLOW_DISPLACEMENT 0x00000004

//
// GetFunctionEntryByOffset flags.
//

#define DEBUG_GETFNENT_DEFAULT        0x00000000
// The engine provides artificial entries for well-known
// cases.  This flag limits the entry search to only
// the raw entries and disables artificial entry lookup.
#define DEBUG_GETFNENT_RAW_ENTRY_ONLY 0x00000001

DEBUG_MODULE_AND_ID STRUCT
	ModuleBase DQ
	Id DQ
ENDS

#define DEBUG_SOURCE_IS_STATEMENT 0x00000001

//
// GetSourceEntriesByLine flags.
//

#define DEBUG_GSEL_DEFAULT         0x00000000
// Do not allow any extra symbols to load during the search.
#define DEBUG_GSEL_NO_SYMBOL_LOADS 0x00000001
// Allow source hits with lower line numbers.
#define DEBUG_GSEL_ALLOW_LOWER     0x00000002
// Allow source hits with higher line numbers.
#define DEBUG_GSEL_ALLOW_HIGHER    0x00000004
// Only return the nearest hits.
#define DEBUG_GSEL_NEAREST_ONLY    0x00000008

DEBUG_SYMBOL_SOURCE_ENTRY STRUCT
	ModuleBase DQ
	Offset DQ
	FileNameId DQ
	EngineInternal DQ
	Size DD
	Flags DD
	FileNameSize DD
    // Line numbers are one-based.
    // May be DEBUG_ANY_ID if unknown.
	StartLine DD
	EndLine DD
    // Column numbers are one-based byte indices.
    // May be DEBUG_ANY_ID if unknown.
	StartColumn DD
	EndColumn DD
	Reserved DD
ENDS

IDebugSymbols3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSymbols.

    // Controls the symbol options used during
    // symbol operations.
    // Uses the same flags as dbghelps SymSetOptions.
	GetSymbolOptions PTR
	AddSymbolOptions PTR
	RemoveSymbolOptions PTR
	SetSymbolOptions PTR
	GetNameByOffset PTR
    // A symbol name may not be unique, particularly
    // when overloaded functions exist which all
    // have the same name.  If GetOffsetByName
    // finds multiple matches for the name it
    // can return any one of them.  In that
    // case it will return S_FALSE to indicate
    // that ambiguity was arbitrarily resolved.
    // A caller can then use SearchSymbols to
    // find all of the matches if it wishes to
    // perform different disambiguation.
	GetOffsetByName PTR
    // GetNearNameByOffset returns symbols
    // located near the symbol closest to
    // to the offset, such as the previous
    // or next symbol.  If Delta is zero it
    // operates identically to GetNameByOffset.
    // If Delta is nonzero and such a symbol
    // does not exist an error is returned.
    // The next symbol, if one exists, will
    // always have a higher offset than the
    // input offset so the displacement is
    // always negative.  The situation is
    // reversed for the previous symbol.
	GetNearNameByOffset PTR
	GetLineByOffset PTR
	GetOffsetByLine PTR
    // Enumerates the engines list of modules
    // loaded for the current process.  This may
    // or may not match the system module list
    // for the process.  Reload can be used to
    // synchronize the engines list with the system
    // if necessary.
    // Some sessions also track recently unloaded
    // code modules for help in analyzing failures
    // where an attempt is made to call unloaded code.
    // These modules are indexed after the loaded
    // modules.
	GetNumberModules PTR
	GetModuleByIndex PTR
    // The module name may not be unique.
    // This method returns the first match.
	GetModuleByModuleName PTR
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
	GetModuleByOffset PTR
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
	GetModuleNames PTR
	GetModuleParameters PTR
    // Looks up the module from a <Module>!<Symbol>
    // string.
	GetSymbolModule PTR
    // Returns the string name of a type.
	GetTypeName PTR
    // Returns the ID for a type name.
	GetTypeId PTR
	GetTypeSize PTR
    // Given a type which can contain members
    // this method returns the offset of a
    // particular member within the type.
    // TypeId should give the container type ID
    // and Field gives the dot-separated path
    // to the field of interest.
	GetFieldOffset PTR
	GetSymbolTypeId PTR
    // As with GetOffsetByName a symbol's
    // name may be ambiguous.  GetOffsetTypeId
    // returns the type for the symbol closest
    // to the given offset and can be used
    // to avoid ambiguity.
	GetOffsetTypeId PTR
    // Helpers for virtual and physical data
    // which combine creation of a location with
    // the actual operation.
	ReadTypedDataVirtual PTR
	WriteTypedDataVirtual PTR
	OutputTypedDataVirtual PTR
	ReadTypedDataPhysical PTR
	WriteTypedDataPhysical PTR
	OutputTypedDataPhysical PTR
    // Function arguments and scope block symbols
    // can be retrieved relative to currently
    // executing code.  A caller can provide just
    // a code offset for scoping purposes and look
    // up names or the caller can provide a full frame
    // and look up actual values.  The values for
    // scoped symbols are best-guess and may or may not
    // be accurate depending on program optimizations,
    // the machine architecture, the current point
    // in the programs execution and so on.
    // A caller can also provide a complete register
    // context for setting a scope to a previous
    // machine state such as a context saved for
    // an exception.  Usually this isnt necessary
    // and the current register context is used.
	GetScope PTR
    // If ScopeFrame or ScopeContext is non-NULL then
    // InstructionOffset is ignored.
    // If ScopeContext is NULL the current
    // register context is used.
    // If the scope identified by the given
    // information is the same as before
    // SetScope returns S_OK.  If the scope
    // information changes, such as when the
    // scope moves between functions or scope
    // blocks, SetScope returns S_FALSE.
	SetScope PTR
    // ResetScope clears the scope information
    // for situations where scoped symbols
    // mask global symbols or when resetting
    // from explicit information to the current
    // information.
	ResetScope PTR
    // A scope symbol is tied to its particular
    // scope and only is meaningful within the scope.
    // The returned group can be updated by passing it back
    // into the method for lower-cost
    // incremental updates when stepping.
	GetScopeSymbolGroup PTR
    // Create a new symbol group.
	CreateSymbolGroup PTR
    // StartSymbolMatch matches symbol names
    // against the given pattern using simple
    // regular expressions.  The search results
    // are iterated through using GetNextSymbolMatch.
    // When the caller is done examining results
    // the match should be freed via EndSymbolMatch.
    // If the match pattern contains a module name
    // the search is restricted to a single module.
    // Pattern matching is only done on symbol names,
    // not module names.
    // All active symbol match handles are invalidated
    // when the set of loaded symbols changes.
	StartSymbolMatch PTR
    // If Buffer is NULL the match does not
    // advance.
	GetNextSymbolMatch PTR
	EndSymbolMatch PTR
	Reload PTR
	GetSymbolPath PTR
	SetSymbolPath PTR
	AppendSymbolPath PTR
    // Manipulate the path for executable images.
    // Some dump files need to load executable images
    // in order to resolve dump information.  This
    // path controls where the engine looks for
    // images.
	GetImagePath PTR
	SetImagePath PTR
	AppendImagePath PTR
    // Path routines for source file location
    // methods.
	GetSourcePath PTR
    // Gets the nth part of the source path.
	GetSourcePathElement PTR
	SetSourcePath PTR
	AppendSourcePath PTR
    // Uses the given file path and the source path
    // information to try and locate an existing file.
    // The given file path is merged with elements
    // of the source path and checked for existence.
    // If a match is found the element used is returned.
    // A starting element can be specified to restrict
    // the search to a subset of the path elements;
    // this can be useful when checking for multiple
    // matches along the source path.
    // The returned element can be 1, indicating
    // the file was found directly and not on the path.
	FindSourceFile PTR
    // Retrieves all the line offset information
    // for a particular source file.  Buffer is
    // first intialized to DEBUG_INVALID_OFFSET for
    // every entry.  Then for each piece of line
    // symbol information Buffer[Line] set to
    // Lines offset.  This produces a per-line
    // map of the offsets for the lines of the
    // given file.  Line numbers are decremented
    // for the map so Buffer[0] contains the offset
    // for line number 1.
    // If there is no line information at all for
    // the given file the method fails rather
    // than returning a map of invalid offsets.
	GetSourceFileLineOffsets PTR
    // IDebugSymbols2.

    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // Item is specified as in VerQueryValue.
    // Module version information is only
    // available for loaded modules and may
    // not be available in all debug sessions.
	GetModuleVersionInformation)(
    // Retrieves any available module name string
    // such as module name or symbol file name.
    // If Index is DEBUG_ANY_ID the base address
    // is used to look up the module instead.
    // If symbols are deferred an error will
    // be returned.
    // E_NOINTERFACE may be returned, indicating
    // no information exists.
	GetModuleNameString PTR
    // Returns the string name of a constant type.
	GetConstantName PTR
    // Gets name of a field in a struct
    // FieldNumber is 0 based index of field in a struct
	GetFieldName PTR
    // Control options for typed values.
	GetTypeOptions PTR
	AddTypeOptions PTR
	RemoveTypeOptions PTR
	SetTypeOptions PTR
    // IDebugSymbols3.
	GetNameByOffsetWide PTR
	GetOffsetByNameWide PTR
	GetNearNameByOffsetWide PTR
	GetLineByOffsetWide PTR
	GetOffsetByLineWide PTR
	GetModuleByModuleNameWide PTR
	GetSymbolModuleWide PTR
	GetTypeNameWide PTR
	GetTypeIdWide PTR
	GetFieldOffsetWide PTR
	GetSymbolTypeIdWide PTR
	GetScopeSymbolGroup2 PTR
	CreateSymbolGroup2 PTR
	StartSymbolMatchWide PTR
	GetNextSymbolMatchWide PTR
	ReloadWide PTR
	GetSymbolPathWide PTR
	SetSymbolPathWide PTR
	AppendSymbolPathWide PTR
	GetImagePathWide PTR
	SetImagePathWide PTR
	AppendImagePathWide PTR
	GetSourcePathWide PTR
	GetSourcePathElementWide PTR
	SetSourcePathWide PTR
	AppendSourcePathWide PTR
	FindSourceFileWide PTR
	GetSourceFileLineOffsetsWide PTR
	GetModuleVersionInformationWide PTR
	GetModuleNameStringWide PTR
	GetConstantNameWide PTR
	GetFieldNameWide PTR
    // Returns S_OK if the engine is using managed
    // debugging support when retriving information
    // for the given module.  This can be expensive
    // to check.
	IsManagedModule PTR
    // The module name may not be unique.
    // This method returns the first match.
	GetModuleByModuleName2 PTR
	GetModuleByModuleName2Wide PTR
    // Offset can be any offset within
    // the module extent.  Extents may
    // not be unique when including unloaded
    // drivers.  This method returns the
    // first match.
	GetModuleByOffset2 PTR
    // A caller can create artificial loaded modules in
    // the engine's module list if desired.
    // These modules only serve as names for
    // a region of addresses.  They cannot have
    // real symbols loaded for them; if that
    // is desired Reload can be used with explicit
    // parameters to create a true module entry.
    // The region must not be in use by any other
    // module.
    // A general reload will discard any synthetic modules.
	AddSyntheticModule PTR
	AddSyntheticModuleWide PTR
	RemoveSyntheticModule PTR
    // Modify the current frame used for scoping.
    // This is equivalent to the '.frame' command.
	GetCurrentScopeFrameIndex PTR
	SetScopeFrameByIndex PTR
    // Recovers JIT_DEBUG_INFO information at the given
    // address from the debuggee and sets current
    // debugger scope context from it.
    // Equivalent to '.jdinfo' command.
	SetScopeFromJitDebugInfo PTR
    // Switches the current debugger scope to
    // the stored event information.
    // Equivalent to the '.ecxr' command.
	SetScopeFromStoredEvent PTR
    // Takes the first symbol hit and outputs it.
    // Controlled with DEBUG_OUTSYM_* flags.
	OutputSymbolByOffset PTR
    // Function entry information for a particular
    // piece of code can be retrieved by this method.
    // The actual data returned is system-dependent.
	GetFunctionEntryByOffset PTR
    // Given a type which can contain members
    // this method returns the type ID and offset of a
    // particular member within the type.
    // Field gives the dot-separated path
    // to the field of interest.
	GetFieldTypeAndOffset PTR
	GetFieldTypeAndOffsetWide PTR
    // Artificial symbols can be created in any
    // existing module as a way to name an address.
    // The address must not already have symbol
    // information.
    // A reload will discard synthetic symbols
    // for all address regions reloaded.
	AddSyntheticSymbol PTR
	AddSyntheticSymbolWide PTR
	RemoveSyntheticSymbol PTR
    // The following methods can return multiple
    // hits for symbol lookups to allow for all
    // possible hits to be returned.
	GetSymbolEntriesByOffset PTR
	GetSymbolEntriesByName PTR
	GetSymbolEntriesByNameWide PTR
	GetSymbolEntryByToken PTR
    // Retrieves full symbol entry information from an ID.
	GetSymbolEntryInformation PTR
	GetSymbolEntryString PTR
	GetSymbolEntryStringWide PTR
    // Returns all known memory regions associated
    // with the given symbol.  Simple symbols will
    // have a single region starting from their base.
    // More complicated regions, such as functions
    // with multiple code areas, can have an arbitrarily
    // large number of regions.
    // The quality of information returned is highly
    // dependent on the symbolic information availble.
	GetSymbolEntryOffsetRegions PTR
    // This method allows navigating within the
    // symbol entry hierarchy.
	GetSymbolEntryBySymbolEntry PTR
    // The following methods can return multiple
    // hits for source lookups to allow for all
    // possible hits to be returned.
	GetSourceEntriesByOffset PTR
	GetSourceEntriesByLine PTR
	GetSourceEntriesByLineWide PTR
	GetSourceEntryString PTR
	GetSourceEntryStringWide PTR
    // Returns all known memory regions associated
    // with the given source entry.  As with
    // GetSymbolEntryOffsetRegions the regions available
    // are variable.
	GetSourceEntryOffsetRegions PTR
    // This method allows navigating within the
    // source entries.
	GetSourceEntryBySourceEntry PTR
ENDS

//----------------------------------------------------------------------------
//
// IDebugSystemObjects
//
//----------------------------------------------------------------------------

IDebugSystemObjects STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSystemObjects.

    // In user mode debugging the debugger
    // tracks all threads and processes and
    // enumerates them through the following
    // methods.  When enumerating threads
    // the threads are enumerated for the current
    // process.
    // Kernel mode debugging currently is
    // limited to enumerating only the threads
    // assigned to processors, not all of
    // the threads in the system.  Process
    // enumeration is limited to a single
    // virtual process representing kernel space.

    // Returns the ID of the thread on which
    // the last event occurred.
	GetEventThread PTR
	GetEventProcess PTR
    // Controls implicit thread used by the
    // debug engine.  The debuggers current
    // thread is just a piece of data held
    // by the debugger for calls which use
    // thread-specific information.  In those
    // calls the debuggers current thread is used.
    // The debuggers current thread is not related
    // to any system thread attribute.
    // IDs for threads are small integer IDs
    // maintained by the engine.  They are not
    // related to system thread IDs.
	GetCurrentThreadId PTR
	SetCurrentThreadId PTR
    // The current process is the process
    // that owns the current thread.
	GetCurrentProcessId PTR
    // Setting the current process automatically
    // sets the current thread to the thread that
    // was last current in that process.
	SetCurrentProcessId PTR
    // Gets the number of threads in the current process.
	GetNumberThreads PTR
    // Gets thread count information for all processes
    // and the largest number of threads in a single process.
	GetTotalNumberThreads PTR
	GetThreadIdsByIndex PTR
    // Gets the debugger ID for the thread
    // currently running on the given
    // processor.  Only works in kernel
    // debugging.
	GetThreadIdByProcessor PTR
    // Returns the offset of the current threads
    // system data structure.  When kernel debugging
    // this is the offset of the KTHREAD.
    // When user debugging it is the offset
    // of the current TEB.
	GetCurrentThreadDataOffset PTR
    // Looks up a debugger thread ID for the given
    // system thread data structure.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByDataOffset PTR
    // Returns the offset of the current threads
    // TEB.  In user mode this is equivalent to
    // the threads data offset.
	GetCurrentThreadTeb PTR
    // Looks up a debugger thread ID for the given TEB.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByTeb PTR
    // Returns the system unique ID for the current thread.
    // Not currently supported when kernel debugging.
	GetCurrentThreadSystemId PTR
    // Looks up a debugger thread ID for the given
    // system thread ID.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdBySystemId PTR
    // Returns the handle of the current thread.
    // In kernel mode the value returned is the
    // index of the processor the thread is
    // executing on plus one.
	GetCurrentThreadHandle PTR
    // Looks up a debugger thread ID for the given handle.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByHandle PTR
    // Currently kernel mode sessions will only have
    // a single process representing kernel space.
	GetNumberProcesses PTR
	GetProcessIdsByIndex PTR
    // Returns the offset of the current processs
    // system data structure.  When kernel debugging
    // this is the offset of the KPROCESS of
    // the process that owns the current thread.
    // When user debugging it is the offset
    // of the current PEB.
	GetCurrentProcessDataOffset PTR
    // Looks up a debugger process ID for the given
    // system process data structure.
    // Not currently supported when kernel debugging.
	GetProcessIdByDataOffset PTR
    // Returns the offset of the current processs
    // PEB.  In user mode this is equivalent to
    // the processs data offset.
	GetCurrentProcessPeb PTR
    // Looks up a debugger process ID for the given PEB.
    // Not currently supported when kernel debugging.
	GetProcessIdByPeb PTR
    // Returns the system unique ID for the current process.
    // Not currently supported when kernel debugging.
	GetCurrentProcessSystemId PTR
    // Looks up a debugger process ID for the given
    // system process ID.
    // Not currently supported when kernel debugging.
	GetProcessIdBySystemId PTR
    // Returns the handle of the current process.
    // In kernel mode this is the kernel processs
    // artificial handle used for symbol operations
    // and so can only be used with dbghelp APIs.
	GetCurrentProcessHandle PTR
    // Looks up a debugger process ID for the given handle.
	GetProcessIdByHandle PTR
    // Retrieve the name of the executable loaded
    // in the process.  This may fail if no executable
    // was identified.
	GetCurrentProcessExecutableName PTR
ENDS

IDebugSystemObjects2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSystemObjects.

    // In user mode debugging the debugger
    // tracks all threads and processes and
    // enumerates them through the following
    // methods.  When enumerating threads
    // the threads are enumerated for the current
    // process.
    // Kernel mode debugging currently is
    // limited to enumerating only the threads
    // assigned to processors, not all of
    // the threads in the system.  Process
    // enumeration is limited to a single
    // virtual process representing kernel space.

    // Returns the ID of the thread on which
    // the last event occurred.
	GetEventThread PTR
	GetEventProcess PTR
    // Controls implicit thread used by the
    // debug engine.  The debuggers current
    // thread is just a piece of data held
    // by the debugger for calls which use
    // thread-specific information.  In those
    // calls the debuggers current thread is used.
    // The debuggers current thread is not related
    // to any system thread attribute.
    // IDs for threads are small integer IDs
    // maintained by the engine.  They are not
    // related to system thread IDs.
	GetCurrentThreadId PTR
	SetCurrentThreadId PTR
    // The current process is the process
    // that owns the current thread.
	GetCurrentProcessId PTR
    // Setting the current process automatically
    // sets the current thread to the thread that
    // was last current in that process.
	SetCurrentProcessId PTR
    // Gets the number of threads in the current process.
	GetNumberThreads PTR
    // Gets thread count information for all processes
    // and the largest number of threads in a single process.
	GetTotalNumberThreads PTR
	GetThreadIdsByIndex PTR
    // Gets the debugger ID for the thread
    // currently running on the given
    // processor.  Only works in kernel
    // debugging.
	GetThreadIdByProcessor PTR
    // Returns the offset of the current threads
    // system data structure.  When kernel debugging
    // this is the offset of the KTHREAD.
    // When user debugging it is the offset
    // of the current TEB.
	GetCurrentThreadDataOffset PTR
    // Looks up a debugger thread ID for the given
    // system thread data structure.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByDataOffset PTR
    // Returns the offset of the current threads
    // TEB.  In user mode this is equivalent to
    // the threads data offset.
	GetCurrentThreadTeb PTR
    // Looks up a debugger thread ID for the given TEB.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByTeb PTR
    // Returns the system unique ID for the current thread.
    // Not currently supported when kernel debugging.
	GetCurrentThreadSystemId PTR
    // Looks up a debugger thread ID for the given
    // system thread ID.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdBySystemId PTR
    // Returns the handle of the current thread.
    // In kernel mode the value returned is the
    // index of the processor the thread is
    // executing on plus one.
	GetCurrentThreadHandle PTR
    // Looks up a debugger thread ID for the given handle.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByHandle PTR
    // Currently kernel mode sessions will only have
    // a single process representing kernel space.
	GetNumberProcesses PTR
	GetProcessIdsByIndex PTR
    // Returns the offset of the current processs
    // system data structure.  When kernel debugging
    // this is the offset of the KPROCESS of
    // the process that owns the current thread.
    // When user debugging it is the offset
    // of the current PEB.
	GetCurrentProcessDataOffset PTR
    // Looks up a debugger process ID for the given
    // system process data structure.
    // Not currently supported when kernel debugging.
	GetProcessIdByDataOffset PTR
    // Returns the offset of the current processs
    // PEB.  In user mode this is equivalent to
    // the processs data offset.
	GetCurrentProcessPeb PTR
    // Looks up a debugger process ID for the given PEB.
    // Not currently supported when kernel debugging.
	GetProcessIdByPeb PTR
    // Returns the system unique ID for the current process.
    // Not currently supported when kernel debugging.
	GetCurrentProcessSystemId PTR
    // Looks up a debugger process ID for the given
    // system process ID.
    // Not currently supported when kernel debugging.
	GetProcessIdBySystemId PTR
    // Returns the handle of the current process.
    // In kernel mode this is the kernel processs
    // artificial handle used for symbol operations
    // and so can only be used with dbghelp APIs.
	GetCurrentProcessHandle PTR
    // Looks up a debugger process ID for the given handle.
	GetProcessIdByHandle PTR
    // Retrieve the name of the executable loaded
    // in the process.  This may fail if no executable
    // was identified.
	GetCurrentProcessExecutableName PTR
    // IDebugSystemObjects2.

    // Return the number of seconds that the current
    // process has been running.
	GetCurrentProcessUpTime PTR
    // During kernel sessions the debugger retrieves
    // some information from the system thread and process
    // running on the current processor.  For example,
    // the debugger will retrieve virtual memory translation
    // information for when the debugger needs to
    // carry out its own virtual to physical translations.
    // Occasionally it can be interesting to perform
    // similar operations but on a process which isnt
    // currently running.  The follow methods allow a caller
    // to override the data offsets used by the debugger
    // so that other system threads and processes can
    // be used instead.  These values are defaulted to
    // the thread and process running on the current
    // processor each time the debuggee executes or
    // the current processor changes.
    // The thread and process settings are independent so
    // it is possible to refer to a thread in a process
    // other than the current process and vice versa.
    // Setting an offset of zero will reload the
    // default value.
	GetImplicitThreadDataOffset PTR
	SetImplicitThreadDataOffset PTR
	GetImplicitProcessDataOffset PTR
	SetImplicitProcessDataOffset PTR
ENDS

IDebugSystemObjects3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSystemObjects.

    // In user mode debugging the debugger
    // tracks all threads and processes and
    // enumerates them through the following
    // methods.  When enumerating threads
    // the threads are enumerated for the current
    // process.
    // Kernel mode debugging currently is
    // limited to enumerating only the threads
    // assigned to processors, not all of
    // the threads in the system.  Process
    // enumeration is limited to a single
    // virtual process representing kernel space.

    // Returns the ID of the thread on which
    // the last event occurred.
	GetEventThread PTR
	GetEventProcess PTR
    // Controls implicit thread used by the
    // debug engine.  The debuggers current
    // thread is just a piece of data held
    // by the debugger for calls which use
    // thread-specific information.  In those
    // calls the debuggers current thread is used.
    // The debuggers current thread is not related
    // to any system thread attribute.
    // IDs for threads are small integer IDs
    // maintained by the engine.  They are not
    // related to system thread IDs.
	GetCurrentThreadId PTR
	SetCurrentThreadId PTR
    // The current process is the process
    // that owns the current thread.
	GetCurrentProcessId PTR
    // Setting the current process automatically
    // sets the current thread to the thread that
    // was last current in that process.
	SetCurrentProcessId PTR
    // Gets the number of threads in the current process.
	GetNumberThreads PTR
    // Gets thread count information for all processes
    // and the largest number of threads in a single process.
	GetTotalNumberThreads PTR
	GetThreadIdsByIndex PTR
    // Gets the debugger ID for the thread
    // currently running on the given
    // processor.  Only works in kernel
    // debugging.
	GetThreadIdByProcessor PTR
    // Returns the offset of the current threads
    // system data structure.  When kernel debugging
    // this is the offset of the KTHREAD.
    // When user debugging it is the offset
    // of the current TEB.
	GetCurrentThreadDataOffset PTR
    // Looks up a debugger thread ID for the given
    // system thread data structure.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByDataOffset PTR
    // Returns the offset of the current threads
    // TEB.  In user mode this is equivalent to
    // the threads data offset.
	GetCurrentThreadTeb PTR
    // Looks up a debugger thread ID for the given TEB.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByTeb PTR
    // Returns the system unique ID for the current thread.
    // Not currently supported when kernel debugging.
	GetCurrentThreadSystemId PTR
    // Looks up a debugger thread ID for the given
    // system thread ID.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdBySystemId PTR
    // Returns the handle of the current thread.
    // In kernel mode the value returned is the
    // index of the processor the thread is
    // executing on plus one.
	GetCurrentThreadHandle PTR
    // Looks up a debugger thread ID for the given handle.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByHandle PTR
    // Currently kernel mode sessions will only have
    // a single process representing kernel space.
	GetNumberProcesses PTR
	GetProcessIdsByIndex PTR
    // Returns the offset of the current processs
    // system data structure.  When kernel debugging
    // this is the offset of the KPROCESS of
    // the process that owns the current thread.
    // When user debugging it is the offset
    // of the current PEB.
	GetCurrentProcessDataOffset PTR
    // Looks up a debugger process ID for the given
    // system process data structure.
    // Not currently supported when kernel debugging.
	GetProcessIdByDataOffset PTR
    // Returns the offset of the current processs
    // PEB.  In user mode this is equivalent to
    // the processs data offset.
	GetCurrentProcessPeb PTR
    // Looks up a debugger process ID for the given PEB.
    // Not currently supported when kernel debugging.
	GetProcessIdByPeb PTR
    // Returns the system unique ID for the current process.
    // Not currently supported when kernel debugging.
	GetCurrentProcessSystemId PTR
    // Looks up a debugger process ID for the given
    // system process ID.
    // Not currently supported when kernel debugging.
	GetProcessIdBySystemId PTR
    // Returns the handle of the current process.
    // In kernel mode this is the kernel processs
    // artificial handle used for symbol operations
    // and so can only be used with dbghelp APIs.
	GetCurrentProcessHandle PTR
    // Looks up a debugger process ID for the given handle.
	GetProcessIdByHandle PTR
    // Retrieve the name of the executable loaded
    // in the process.  This may fail if no executable
    // was identified.
	GetCurrentProcessExecutableName PTR
    // IDebugSystemObjects2.

    // Return the number of seconds that the current
    // process has been running.
	GetCurrentProcessUpTime PTR
    // During kernel sessions the debugger retrieves
    // some information from the system thread and process
    // running on the current processor.  For example,
    // the debugger will retrieve virtual memory translation
    // information for when the debugger needs to
    // carry out its own virtual to physical translations.
    // Occasionally it can be interesting to perform
    // similar operations but on a process which isnt
    // currently running.  The follow methods allow a caller
    // to override the data offsets used by the debugger
    // so that other system threads and processes can
    // be used instead.  These values are defaulted to
    // the thread and process running on the current
    // processor each time the debuggee executes or
    // the current processor changes.
    // The thread and process settings are independent so
    // it is possible to refer to a thread in a process
    // other than the current process and vice versa.
    // Setting an offset of zero will reload the
    // default value.
	GetImplicitThreadDataOffset PTR
	SetImplicitThreadDataOffset PTR
	GetImplicitProcessDataOffset PTR
	SetImplicitProcessDataOffset PTR
    // IDebugSystemObjects3.
	GetEventSystem PTR
	GetCurrentSystemId PTR
	SetCurrentSystemId PTR
	GetNumberSystems PTR
	GetSystemIdsByIndex PTR
	GetTotalNumberThreadsAndProcesses PTR
	GetCurrentSystemServer PTR
	GetSystemByServer PTR
	GetCurrentSystemServerName PTR
ENDS

IDebugSystemObjects4 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // IDebugSystemObjects.

    // In user mode debugging the debugger
    // tracks all threads and processes and
    // enumerates them through the following
    // methods.  When enumerating threads
    // the threads are enumerated for the current
    // process.
    // Kernel mode debugging currently is
    // limited to enumerating only the threads
    // assigned to processors, not all of
    // the threads in the system.  Process
    // enumeration is limited to a single
    // virtual process representing kernel space.

    // Returns the ID of the thread on which
    // the last event occurred.
	GetEventThread PTR
	GetEventProcess PTR
    // Controls implicit thread used by the
    // debug engine.  The debuggers current
    // thread is just a piece of data held
    // by the debugger for calls which use
    // thread-specific information.  In those
    // calls the debuggers current thread is used.
    // The debuggers current thread is not related
    // to any system thread attribute.
    // IDs for threads are small integer IDs
    // maintained by the engine.  They are not
    // related to system thread IDs.
	GetCurrentThreadId PTR
	SetCurrentThreadId PTR
    // The current process is the process
    // that owns the current thread.
	GetCurrentProcessId PTR
    // Setting the current process automatically
    // sets the current thread to the thread that
    // was last current in that process.
	SetCurrentProcessId PTR
    // Gets the number of threads in the current process.
	GetNumberThreads PTR
    // Gets thread count information for all processes
    // and the largest number of threads in a single process.
	GetTotalNumberThreads PTR
	GetThreadIdsByIndex PTR
    // Gets the debugger ID for the thread
    // currently running on the given
    // processor.  Only works in kernel
    // debugging.
	GetThreadIdByProcessor PTR
    // Returns the offset of the current threads
    // system data structure.  When kernel debugging
    // this is the offset of the KTHREAD.
    // When user debugging it is the offset
    // of the current TEB.
	GetCurrentThreadDataOffset PTR
    // Looks up a debugger thread ID for the given
    // system thread data structure.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByDataOffset PTR
    // Returns the offset of the current threads
    // TEB.  In user mode this is equivalent to
    // the threads data offset.
	GetCurrentThreadTeb PTR
    // Looks up a debugger thread ID for the given TEB.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByTeb PTR
    // Returns the system unique ID for the current thread.
    // Not currently supported when kernel debugging.
	GetCurrentThreadSystemId PTR
    // Looks up a debugger thread ID for the given
    // system thread ID.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdBySystemId PTR
    // Returns the handle of the current thread.
    // In kernel mode the value returned is the
    // index of the processor the thread is
    // executing on plus one.
	GetCurrentThreadHandle PTR
    // Looks up a debugger thread ID for the given handle.
    // Currently when kernel debugging this will fail
    // if the thread is not executing on a processor.
	GetThreadIdByHandle PTR
    // Currently kernel mode sessions will only have
    // a single process representing kernel space.
	GetNumberProcesses PTR
	GetProcessIdsByIndex PTR
    // Returns the offset of the current processs
    // system data structure.  When kernel debugging
    // this is the offset of the KPROCESS of
    // the process that owns the current thread.
    // When user debugging it is the offset
    // of the current PEB.
	GetCurrentProcessDataOffset PTR
    // Looks up a debugger process ID for the given
    // system process data structure.
    // Not currently supported when kernel debugging.
	GetProcessIdByDataOffset PTR
    // Returns the offset of the current processs
    // PEB.  In user mode this is equivalent to
    // the processs data offset.
	GetCurrentProcessPeb PTR
    // Looks up a debugger process ID for the given PEB.
    // Not currently supported when kernel debugging.
	GetProcessIdByPeb PTR
    // Returns the system unique ID for the current process.
    // Not currently supported when kernel debugging.
	GetCurrentProcessSystemId PTR
    // Looks up a debugger process ID for the given
    // system process ID.
    // Not currently supported when kernel debugging.
	GetProcessIdBySystemId PTR
    // Returns the handle of the current process.
    // In kernel mode this is the kernel processs
    // artificial handle used for symbol operations
    // and so can only be used with dbghelp APIs.
	GetCurrentProcessHandle PTR
    // Looks up a debugger process ID for the given handle.
	GetProcessIdByHandle PTR
    // Retrieve the name of the executable loaded
    // in the process.  This may fail if no executable
    // was identified.
	GetCurrentProcessExecutableName PTR
    // IDebugSystemObjects2.

    // Return the number of seconds that the current
    // process has been running.
	GetCurrentProcessUpTime PTR
    // During kernel sessions the debugger retrieves
    // some information from the system thread and process
    // running on the current processor.  For example,
    // the debugger will retrieve virtual memory translation
    // information for when the debugger needs to
    // carry out its own virtual to physical translations.
    // Occasionally it can be interesting to perform
    // similar operations but on a process which isnt
    // currently running.  The follow methods allow a caller
    // to override the data offsets used by the debugger
    // so that other system threads and processes can
    // be used instead.  These values are defaulted to
    // the thread and process running on the current
    // processor each time the debuggee executes or
    // the current processor changes.
    // The thread and process settings are independent so
    // it is possible to refer to a thread in a process
    // other than the current process and vice versa.
    // Setting an offset of zero will reload the
    // default value.
	GetImplicitThreadDataOffset PTR
	SetImplicitThreadDataOffset PTR
	GetImplicitProcessDataOffset PTR
	SetImplicitProcessDataOffset PTR
    // IDebugSystemObjects3.
	GetEventSystem PTR
	GetCurrentSystemId PTR
	SetCurrentSystemId PTR
	GetNumberSystems PTR
	GetSystemIdsByIndex PTR
	GetTotalNumberThreadsAndProcesses PTR
	GetCurrentSystemServer PTR
	GetSystemByServer PTR
	GetCurrentSystemServerName PTR
    // IDebugSystemObjects4.
	GetCurrentProcessExecutableNameWide PTR
	GetCurrentSystemServerNameWide PTR
ENDS

//----------------------------------------------------------------------------
//
// Debugger/debuggee communication.
//
// A distinguished exception, DBG_COMMAND_EXCEPTION (0x40010009),
// can be used by a debuggee to communicate with the debugger.
// The arguments of the exception must be:
// 1. Exception ID.
// 2. Command code.
// 3. Size of argument.
// 4. Pointer to argument.
//
// The arguments depend on the command code.
//
//----------------------------------------------------------------------------

#define DEBUG_COMMAND_EXCEPTION_ID 0xdbe00dbe

// Invalid command code.
#define DEBUG_CMDEX_INVALID             0x00000000

//
// The debugger can collect strings for display at the
// next event.  A debuggee can use this to register information
// about a program situation before places where an event
// may occur, such as a risky operation or assertion.
// The strings are automatically flushed on the next
// event continuation.  Strings are kept on a per-thread basis.
//
// When adding, the argument is the string to add.
// Reset has no arguments and clears all strings.
//
#define DEBUG_CMDEX_ADD_EVENT_STRING    0x00000001
#define DEBUG_CMDEX_RESET_EVENT_STRINGS 0x00000002

//----------------------------------------------------------------------------
//
// Extension callbacks.
//
//----------------------------------------------------------------------------
//
// Descriptive flags returned from extension initialization.
//

// Extension has a !help command which can give
// per-command help.
#define DEBUG_EXTINIT_HAS_COMMAND_HELP 0x00000001

// A debuggee has been discovered for the session.  It
// is not necessarily halted.
#define DEBUG_NOTIFY_SESSION_ACTIVE       0x00000000
// The session no longer has a debuggee.
#define DEBUG_NOTIFY_SESSION_INACTIVE     0x00000001
// The debuggee is halted and accessible.
#define DEBUG_NOTIFY_SESSION_ACCESSIBLE   0x00000002
// The debuggee is running or inaccessible.
#define DEBUG_NOTIFY_SESSION_INACCESSIBLE 0x00000003

// A PDEBUG_EXTENSION_CALL function can return this code
// to indicate that it was unable to handle the request
// and that the search for an extension function should
// continue down the extension DLL chain.
// Taken from STATUS_VALIDATE_CONTINUE.
#define DEBUG_EXTENSION_CONTINUE_SEARCH 0xC0000271

// A PDEBUG_EXTENSION_CALL function can return this code
// to indicate that the engine should unload and reload
// the extension binary.  This allows extensions to implement
// auto-update functionality.
#define DEBUG_EXTENSION_RELOAD_EXTENSION 0xC00000EE

//
// KnownStructOutput[Ex] flags
//

// Return names of supported structs.
#define DEBUG_KNOWN_STRUCT_GET_NAMES              1
// Return value output for type.
#define DEBUG_KNOWN_STRUCT_GET_SINGLE_LINE_OUTPUT 2
// Return S_OK if suppressing type name.
#define DEBUG_KNOWN_STRUCT_SUPPRESS_TYPE_NAME     3

//
// Extensions can provide pseudo-register values that
// operate similiarly to the debugger's built-in $teb, etc.
//

#define DEBUG_EXT_QVALUE_DEFAULT 0x00000000

#define DEBUG_EXT_PVALUE_DEFAULT 0x00000000

#define DEBUG_EXT_PVTYPE_IS_VALUE   0x00000000
#define DEBUG_EXT_PVTYPE_IS_POINTER 0x00000001

#ifdef UNICODE

#define IDebugEventCallbacksT IDebugEventCallbacksWide
#define IID_IDebugEventCallbacksT IID_IDebugEventCallbacksWide
#define IDebugOutputCallbacksT IDebugOutputCallbacksWide
#define IID_IDebugOutputCallbacksT IID_IDebugOutputCallbacksWide
#define DebugBaseEventCallbacksT DebugBaseEventCallbacksWide

#define DebugConnectT DebugConnectWide
#define GetSourceFileInformationT GetSourceFileInformationWide
#define FindSourceFileAndTokenT FindSourceFileAndTokenWide
#define GetSymbolInformationT GetSymbolInformationWide
#define GetCommandT GetCommandWide
#define SetCommandT SetCommandWide
#define GetOffsetExpressionT GetOffsetExpressionWide
#define SetOffsetExpressionT SetOffsetExpressionWide
#define GetRunningProcessSystemIdByExecutableNameT GetRunningProcessSystemIdByExecutableNameWide
#define GetRunningProcessDescriptionT GetRunningProcessDescriptionWide
#define CreateProcessT CreateProcessWide
#define CreateProcessAndAttachT CreateProcessAndAttachWide
#define AddDumpInformationFileT AddDumpInformationFileWide
#define GetDumpFileT GetDumpFileWide
#define AttachKernelT AttachKernelWide
#define GetKernelConnectionOptionsT GetKernelConnectionOptionsWide
#define SetKernelConnectionOptionsT SetKernelConnectionOptionsWide
#define StartProcessServerT StartProcessServerWide
#define ConnectProcessServerT ConnectProcessServerWide
#define StartServerT StartServerWide
#define OutputServersT OutputServersWide
#define GetOutputCallbacksT GetOutputCallbacksWide
#define SetOutputCallbacksT SetOutputCallbacksWide
#define GetOutputLinePrefixT GetOutputLinePrefixWide
#define SetOutputLinePrefixT SetOutputLinePrefixWide
#define GetIdentityT GetIdentityWide
#define OutputIdentityT OutputIdentityWide
#define GetEventCallbacksT GetEventCallbacksWide
#define SetEventCallbacksT SetEventCallbacksWide
#define CreateProcess2T CreateProcess2Wide
#define CreateProcessAndAttach2T CreateProcessAndAttach2Wide
#define PushOutputLinePrefixT PushOutputLinePrefixWide
#define GetQuitLockStringT GetQuitLockStringWide
#define SetQuitLockStringT SetQuitLockStringWide
#define GetLogFileT GetLogFileWide
#define OpenLogFileT OpenLogFileWide
#define InputT InputWide
#define ReturnInputT ReturnInputWide
#define OutputT OutputWide
#define OutputVaListT OutputVaListWide
#define ControlledOutputT ControlledOutputWide
#define ControlledOutputVaListT ControlledOutputVaListWide
#define OutputPromptT OutputPromptWide
#define OutputPromptVaListT OutputPromptVaListWide
#define GetPromptTextT GetPromptTextWide
#define AssembleT AssembleWide
#define DisassembleT DisassembleWide
#define GetProcessorTypeNamesT GetProcessorTypeNamesWide
#define GetTextMacroT GetTextMacroWide
#define SetTextMacroT SetTextMacroWide
#define EvaluateT EvaluateWide
#define ExecuteT ExecuteWide
#define ExecuteCommandFileT ExecuteCommandFileWide
#define AddExtensionT AddExtensionWide
#define GetExtensionByPathT GetExtensionByPathWide
#define CallExtensionT CallExtensionWide
#define GetExtensionFunctionT GetExtensionFunctionWide
#define GetEventFilterTextT GetEventFilterTextWide
#define GetEventFilterCommandT GetEventFilterCommandWide
#define SetEventFilterCommandT SetEventFilterCommandWide
#define GetSpecificFilterArgumentT GetSpecificFilterArgumentWide
#define SetSpecificFilterArgumentT SetSpecificFilterArgumentWide
#define GetExceptionFilterSecondCommandT GetExceptionFilterSecondCommandWide
#define SetExceptionFilterSecondCommandT SetExceptionFilterSecondCommandWide
#define GetLastEventInformationT GetLastEventInformationWide
#define GetTextReplacementT GetTextReplacementWide
#define SetTextReplacementT SetTextReplacementWide
#define SetExpressionSyntaxByNameT SetExpressionSyntaxByNameWide
#define GetExpressionSyntaxNamesT GetExpressionSyntaxNamesWide
#define GetEventIndexDescriptionT GetEventIndexDescriptionWide
#define GetLogFile2T GetLogFile2Wide
#define OpenLogFile2T OpenLogFile2Wide
#define GetSystemVersionStringT GetSystemVersionStringWide
#define ReadMultiByteStringVirtualT ReadMultiByteStringVirtualWide
#define ReadUnicodeStringVirtualT ReadUnicodeStringVirtualWide
#define GetDescriptionT GetDescriptionWide
#define GetIndexByNameT GetIndexByNameWide
#define GetPseudoDescriptionT GetPseudoDescriptionWide
#define GetPseudoIndexByNameT GetPseudoIndexByNameWide
#define AddSymbolT AddSymbolWide
#define RemoveSymbolByNameT RemoveSymbolByNameWide
#define GetSymbolNameT GetSymbolNameWide
#define WriteSymbolT WriteSymbolWide
#define OutputAsTypeT OutputAsTypeWide
#define GetSymbolTypeNameT GetSymbolTypeNameWide
#define GetSymbolValueTextT GetSymbolValueTextWide
#define GetNameByOffsetT GetNameByOffsetWide
#define GetOffsetByNameT GetOffsetByNameWide
#define GetNearNameByOffsetT GetNearNameByOffsetWide
#define GetLineByOffsetT GetLineByOffsetWide
#define GetOffsetByLineT GetOffsetByLineWide
#define GetModuleByModuleNameT GetModuleByModuleNameWide
#define GetModuleByModuleName2T GetModuleByModuleName2Wide
#define GetSymbolModuleT GetSymbolModuleWide
#define GetTypeNameT GetTypeNameWide
#define GetTypeIdT GetTypeIdWide
#define GetFieldOffsetT GetFieldOffsetWide
#define GetSymbolTypeIdT GetSymbolTypeIdWide
#define StartSymbolMatchT StartSymbolMatchWide
#define GetNextSymbolMatchT GetNextSymbolMatchWide
#define ReloadT ReloadWide
#define GetSymbolPathT GetSymbolPathWide
#define SetSymbolPathT SetSymbolPathWide
#define AppendSymbolPathT AppendSymbolPathWide
#define GetImagePathT GetImagePathWide
#define SetImagePathT SetImagePathWide
#define AppendImagePathT AppendImagePathWide
#define GetSourcePathT GetSourcePathWide
#define GetSourcePathElementT GetSourcePathElementWide
#define SetSourcePathT SetSourcePathWide
#define AppendSourcePathT AppendSourcePathWide
#define FindSourceFileT FindSourceFileWide
#define GetSourceFileLineOffsetsT GetSourceFileLineOffsetsWide
#define GetModuleVersionInformationT GetModuleVersionInformationWide
#define GetModuleNameStringT GetModuleNameStringWide
#define GetConstantNameT GetConstantNameWide
#define GetFieldNameT GetFieldNameWide
#define GetFieldTypeAndOffsetT GetFieldTypeAndOffsetWide
#define GetSymbolEntriesByNameT GetSymbolEntriesByNameWide
#define GetSymbolEntryStringT GetSymbolEntryStringWide
#define GetSourceEntriesByLineT GetSourceEntriesByLineWide
#define GetSourceEntryStringT GetSourceEntryStringWide
#define GetCurrentProcessExecutableNameT GetCurrentProcessExecutableNameWide
#define GetCurrentSystemServerNameT GetCurrentSystemServerNameWide

#else // #ifdef UNICODE

#define IDebugEventCallbacksT IDebugEventCallbacks
#define IID_IDebugEventCallbacksT IID_IDebugEventCallbacks
#define IDebugOutputCallbacksT IDebugOutputCallbacks
#define IID_IDebugOutputCallbacksT IID_IDebugOutputCallbacks
#define DebugBaseEventCallbacksT DebugBaseEventCallbacks

#define DebugConnectT DebugConnect
#define GetSourceFileInformationT GetSourceFileInformation
#define FindSourceFileAndTokenT FindSourceFileAndToken
#define GetSymbolInformationT GetSymbolInformation
#define GetCommandT GetCommand
#define SetCommandT SetCommand
#define GetOffsetExpressionT GetOffsetExpression
#define SetOffsetExpressionT SetOffsetExpression
#define GetRunningProcessSystemIdByExecutableNameT GetRunningProcessSystemIdByExecutableName
#define GetRunningProcessDescriptionT GetRunningProcessDescription
#define CreateProcessT CreateProcess
#define CreateProcessAndAttachT CreateProcessAndAttach
#define AddDumpInformationFileT AddDumpInformationFile
#define GetDumpFileT GetDumpFile
#define AttachKernelT AttachKernel
#define GetKernelConnectionOptionsT GetKernelConnectionOptions
#define SetKernelConnectionOptionsT SetKernelConnectionOptions
#define StartProcessServerT StartProcessServer
#define ConnectProcessServerT ConnectProcessServer
#define StartServerT StartServer
#define OutputServersT OutputServers
#define GetOutputCallbacksT GetOutputCallbacks
#define SetOutputCallbacksT SetOutputCallbacks
#define GetOutputLinePrefixT GetOutputLinePrefix
#define SetOutputLinePrefixT SetOutputLinePrefix
#define GetIdentityT GetIdentity
#define OutputIdentityT OutputIdentity
#define GetEventCallbacksT GetEventCallbacks
#define SetEventCallbacksT SetEventCallbacks
#define CreateProcess2T CreateProcess2
#define CreateProcessAndAttach2T CreateProcessAndAttach2
#define PushOutputLinePrefixT PushOutputLinePrefix
#define GetQuitLockStringT GetQuitLockString
#define SetQuitLockStringT SetQuitLockString
#define GetLogFileT GetLogFile
#define OpenLogFileT OpenLogFile
#define InputT Input
#define ReturnInputT ReturnInput
#define OutputT Output
#define OutputVaListT OutputVaList
#define ControlledOutputT ControlledOutput
#define ControlledOutputVaListT ControlledOutputVaList
#define OutputPromptT OutputPrompt
#define OutputPromptVaListT OutputPromptVaList
#define GetPromptTextT GetPromptText
#define AssembleT Assemble
#define DisassembleT Disassemble
#define GetProcessorTypeNamesT GetProcessorTypeNames
#define GetTextMacroT GetTextMacro
#define SetTextMacroT SetTextMacro
#define EvaluateT Evaluate
#define ExecuteT Execute
#define ExecuteCommandFileT ExecuteCommandFile
#define AddExtensionT AddExtension
#define GetExtensionByPathT GetExtensionByPath
#define CallExtensionT CallExtension
#define GetExtensionFunctionT GetExtensionFunction
#define GetEventFilterTextT GetEventFilterText
#define GetEventFilterCommandT GetEventFilterCommand
#define SetEventFilterCommandT SetEventFilterCommand
#define GetSpecificFilterArgumentT GetSpecificFilterArgument
#define SetSpecificFilterArgumentT SetSpecificFilterArgument
#define GetExceptionFilterSecondCommandT GetExceptionFilterSecondCommand
#define SetExceptionFilterSecondCommandT SetExceptionFilterSecondCommand
#define GetLastEventInformationT GetLastEventInformation
#define GetTextReplacementT GetTextReplacement
#define SetTextReplacementT SetTextReplacement
#define SetExpressionSyntaxByNameT SetExpressionSyntaxByName
#define GetExpressionSyntaxNamesT GetExpressionSyntaxNames
#define GetEventIndexDescriptionT GetEventIndexDescription
#define GetLogFile2T GetLogFile2
#define OpenLogFile2T OpenLogFile2
#define GetSystemVersionStringT GetSystemVersionString
#define ReadMultiByteStringVirtualT ReadMultiByteStringVirtual
#define ReadUnicodeStringVirtualT ReadUnicodeStringVirtual
#define GetDescriptionT GetDescription
#define GetIndexByNameT GetIndexByName
#define GetPseudoDescriptionT GetPseudoDescription
#define GetPseudoIndexByNameT GetPseudoIndexByName
#define AddSymbolT AddSymbol
#define RemoveSymbolByNameT RemoveSymbolByName
#define GetSymbolNameT GetSymbolName
#define WriteSymbolT WriteSymbol
#define OutputAsTypeT OutputAsType
#define GetSymbolTypeNameT GetSymbolTypeName
#define GetSymbolValueTextT GetSymbolValueText
#define GetNameByOffsetT GetNameByOffset
#define GetOffsetByNameT GetOffsetByName
#define GetNearNameByOffsetT GetNearNameByOffset
#define GetLineByOffsetT GetLineByOffset
#define GetOffsetByLineT GetOffsetByLine
#define GetModuleByModuleNameT GetModuleByModuleName
#define GetModuleByModuleName2T GetModuleByModuleName2
#define GetSymbolModuleT GetSymbolModule
#define GetTypeNameT GetTypeName
#define GetTypeIdT GetTypeId
#define GetFieldOffsetT GetFieldOffset
#define GetSymbolTypeIdT GetSymbolTypeId
#define StartSymbolMatchT StartSymbolMatch
#define GetNextSymbolMatchT GetNextSymbolMatch
#define ReloadT Reload
#define GetSymbolPathT GetSymbolPath
#define SetSymbolPathT SetSymbolPath
#define AppendSymbolPathT AppendSymbolPath
#define GetImagePathT GetImagePath
#define SetImagePathT SetImagePath
#define AppendImagePathT AppendImagePath
#define GetSourcePathT GetSourcePath
#define GetSourcePathElementT GetSourcePathElement
#define SetSourcePathT SetSourcePath
#define AppendSourcePathT AppendSourcePath
#define FindSourceFileT FindSourceFile
#define GetSourceFileLineOffsetsT GetSourceFileLineOffsets
#define GetModuleVersionInformationT GetModuleVersionInformation
#define GetModuleNameStringT GetModuleNameString
#define GetConstantNameT GetConstantName
#define GetFieldNameT GetFieldName
#define GetFieldTypeAndOffsetT GetFieldTypeAndOffset
#define GetSymbolEntriesByNameT GetSymbolEntriesByName
#define GetSymbolEntryStringT GetSymbolEntryString
#define GetSourceEntriesByLineT GetSourceEntriesByLine
#define GetSourceEntryStringT GetSourceEntryString
#define GetCurrentProcessExecutableNameT GetCurrentProcessExecutableName
#define GetCurrentSystemServerNameT GetCurrentSystemServerName
#endif

#endif // #ifndef __DBGENG_H__
