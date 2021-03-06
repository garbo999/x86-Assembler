
/*++

Copyright 2004 (c) Microsoft Corporation. All rights reserved.

Module Name:

 evntcons.h

Abstract:

 This defines the event consumer API

Revision History:

 Insung Park (insungp) 26-Aug-2004 
 Created the file.

--*/

#ifndef EVNTCONS_H
#define EVNTCONS_H

#IFDEF LINKFILES
	#dynamiclinkfile advapi32.dll
#ENDIF

#IFNDEF WMISTR_H
#include "wmistr.h"
#ENDIF

#IFNDEF EVNTRACE_H
#include "evntrace.h"
#ENDIF

#IFNDEF EVNTPROV_H
#include "evntprov.h"
#ENDIF

#define EVENT_HEADER_EXT_TYPE_RELATED_ACTIVITYID 0x0001
#define EVENT_HEADER_EXT_TYPE_SID 0x0002
#define EVENT_HEADER_EXT_TYPE_TS_ID 0x0003
#define EVENT_HEADER_EXT_TYPE_INSTANCE_INFO 0x0004
#define EVENT_HEADER_EXT_TYPE_STACK_TRACE32 0x0005
#define EVENT_HEADER_EXT_TYPE_STACK_TRACE64 0x0006
#define EVENT_HEADER_EXT_TYPE_MAX 0x0007

EVENT_HEADER_EXTENDED_DATA_ITEM STRUCT
	Reserved1 SHORT
	ExtType SHORT 
;	STRUCT
		Linkage SHORT 
		Reserved2 SHORT
;	ENDS
	DataSize SHORT
	DataPtr LONGLONG
ENDS

//
// Structures for extended items.
//

EVENT_EXTENDED_ITEM_INSTANCE STRUCT
	InstanceId LONG
	ParentInstanceId LONG
	ParentGuid GUID
ENDS

EVENT_EXTENDED_ITEM_RELATED_ACTIVITYID STRUCT
	RelatedActivityId GUID
ENDS

EVENT_EXTENDED_ITEM_TS_ID STRUCT
	SessionId LONG
ENDS

EVENT_EXTENDED_ITEM_STACK_TRACE32 STRUCT
	MatchId DWORD64
	Address LONG
ENDS

EVENT_EXTENDED_ITEM_STACK_TRACE64 STRUCT
	MatchId DWORD64
	Address DWORD64
ENDS

#define EVENT_HEADER_PROPERTY_XML 0x0001
#define EVENT_HEADER_PROPERTY_FORWARDED_XML 0x0002
#define EVENT_HEADER_PROPERTY_LEGACY_EVENTLOG 0x0004

#define EVENT_HEADER_FLAG_EXTENDED_INFO 0x0001
#define EVENT_HEADER_FLAG_PRIVATE_SESSION 0x0002
#define EVENT_HEADER_FLAG_STRING_ONLY 0x0004
#define EVENT_HEADER_FLAG_TRACE_MESSAGE 0x0008
#define EVENT_HEADER_FLAG_NO_CPUTIME 0x0010
#define EVENT_HEADER_FLAG_32_BIT_HEADER 0x0020
#define EVENT_HEADER_FLAG_64_BIT_HEADER 0x0040
#define EVENT_HEADER_FLAG_CLASSIC_HEADER 0x0100

EVENT_HEADER STRUCT
	Size SHORT
	HeaderType SHORT
	Flags SHORT
	EventProperty SHORT
	ThreadId LONG
	ProcessId LONG
	TimeStamp LARGE_INTEGER
	ProviderId GUID
	EventDescriptor EVENT_DESCRIPTOR
	UNION
		STRUCT
			KernelTime LONG
			UserTime LONG
		ENDS
		ProcessorTime DWORD64 
	ENDUNION
	ActivityId GUID
ENDS

EVENT_RECORD STRUCT
	EventHeader EVENT_HEADER
	BufferContext ETW_BUFFER_CONTEXT
	ExtendedDataCount SHORT
	UserDataLength SHORT
	ExtendedData PTR  
	UserData PTR
	UserContext PTR
ENDS

#define EVENT_ENABLE_PROPERTY_SID 0x00000001
#define EVENT_ENABLE_PROPERTY_TS_ID 0x00000002
#define EVENT_ENABLE_PROPERTY_STACK_TRACE 0x00000004

//
// Consumer API
//

#define PROCESS_TRACE_MODE_REAL_TIME 0x00000100
#define PROCESS_TRACE_MODE_RAW_TIMESTAMP 0x00001000
#define PROCESS_TRACE_MODE_EVENT_RECORD 0x10000000

//
// Event Security APIs
//

// EVENTSECURITYOPERATION
	EventSecuritySetDACL = 0
	EventSecuritySetSACL = 1
	EventSecurityAddDACL = 2
	EventSecurityAddSACL = 3
	EventSecurityMax = 4

#endif

