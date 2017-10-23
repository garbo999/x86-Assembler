#ifndef HTTPTRACE_H
#define HTTPTRACE_H
/*++

    Copyright (c) 2005 Microsoft Corporation

    Module Name:

        httptrace.h

    Abstract:

        Definition of the event tracing structures for IIS
        (applies for IIS version >= 7 )

--*/

//
// HTTP_TRACE_TYPE contains type that are supported by 
// the IIS trace infrastructure.
// The enum values match the equivalent VARIANT types.
//

HTTP_TRACE_TYPE_BYTE = 17
HTTP_TRACE_TYPE_USHORT = 18
HTTP_TRACE_TYPE_ULONG = 19
HTTP_TRACE_TYPE_ULONGLONG = 21
HTTP_TRACE_TYPE_CHAR = 16
HTTP_TRACE_TYPE_SHORT = 2
HTTP_TRACE_TYPE_LONG = 3
HTTP_TRACE_TYPE_LONGLONG = 20
HTTP_TRACE_TYPE_LPCWSTR = 31
HTTP_TRACE_TYPE_LPCSTR = 30
HTTP_TRACE_TYPE_LPCGUID = 72
HTTP_TRACE_TYPE_BOOL = 11

// bit values for the HTTP_TRACE_EVENT.dwFlags

//
// If HTTP_TRACE_EVENT_FLAG_STATIC_DESCRIPTIVE_FIELDS is set then
// consumers of the trace event can assume that
// pProviderGuid, pAreaGuid, pszEventName in the HTTP_TRACE_EVENT
// and pszName and pszDescription in each HTTP_TRACE_EVENT_ITEM
// entry are static (their memory is available throughout the 
// process lifetime). If event needs to be buffered there is no need 
// to copy values for these fields
//
#define HTTP_TRACE_EVENT_FLAG_STATIC_DESCRIPTIVE_FIELDS       0x01

//
// In addition to TRACE_LEVEL_FATAL - TRACE_LEVEL_VERBOSE
//
#define HTTP_TRACE_LEVEL_START  6
#define HTTP_TRACE_LEVEL_END    7

//
// Each Trace event will need to be described with the HTTP_TRACE_EVENT structure. 
// It is designed to contain all the information relevant to ETW, 
// but ETW is not the only consumer
//
//

HTTP_TRACE_EVENT STRUCT
	pProviderGuid PTR
	dwArea DD
	pAreaGuid PTR
	dwEvent DD
	pszEventName PTR
	dwEventVersion DD
	dwVerbosity DD
	pActivityGuid PTR
	pRelatedActivityGuid PTR
	dwTimeStamp DD
	dwFlags DD
	cEventItems DD 
	pEventItems PTR 
ENDS


// Each HTTP_TRACE_EVENT can have multiple items or elements that describe the event
// (for example the "GENERAL_REQUEST_START" event contains an item with the Request URL)

HTTP_TRACE_EVENT_ITEM STRUCT
	pszName PTR
	dwDataType DD
	pbData PTR
	cbData DD
	pszDataDescription PTR
ENDS

//
// HTTP_TRACE_CONFIGURATION is used by both trace providers and trace consumers
// Trace consumers declare the TraceProviders and TraceAreas of the interest.
// Trace providers can retrieve what areas at what verbosity is allowed
// for a given provider
//

HTTP_TRACE_CONFIGURATION STRUCT
	pProviderGuid PTR
	dwAreas DD
	dwVerbosity DD
	fProviderEnabled BOOL
ENDS

//
// Definiton of the GUIDs for the TRACE Providers that ship with IIS
// or are related to IIS
//

#DEFINE GUID_IIS_ALL_TRACE_PROVIDERS <0x00000000,0x0000,0x0000,<0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00>>

#DEFINE GUID_IIS_WWW_SERVER_TRACE_PROVIDER <0x3a2a4e84,0x4c21,0x4981,<0xae,0x10,0x3f,0xda,0x0d,0x9b,0x0f,0x83>>

// ETW name for the provider: "ASP.NET Events
#DEFINE GUID_IIS_ASPNET_TRACE_PROVIDER <0xAFF081FE,0x0247,0x4275,<0x9C,0x4E,0x02,0x1F,0x3D,0xC1,0xDA,0x35>>

// ETW name for the provider: "IIS: Active Server Pages (ASP)"
#DEFINE GUID_IIS_ASP_TRACE_TRACE_PROVIDER <0x06b94d9a,0xb15e,0x456e,<0xa4,0xef,0x37,0xc9,0x84,0xa2,0xcb,0x4b>>

#DEFINE GUID_IIS_WWW_GLOBAL_TRACE_PROVIDER <0xd55d3bc9,0xcba9,0x44df,<0x82,0x7e,0x13,0x2d,0x3a,0x45,0x96,0xc2>>

// ETW name for the provider: "IIS: WWW Isapi Extension"
#DEFINE GUID_IIS_ISAPI_TRACE_PROVIDER <0xa1c2040e,0x8840,0x4c31,<0xba,0x11,0x98,0x71,0x03,0x1a,0x19,0xea>>

#endif


