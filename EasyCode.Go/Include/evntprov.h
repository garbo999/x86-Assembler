
/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

 evntprov.h

Abstract:

 This defines the unified provider side user mode API.

Revision History:

--*/

#ifndef EVNTPROV_H
#define EVNTPROV_H

#IFDEF LINKFILES
	#dynamiclinkfile Advapi32.dll
#ENDIF

#define EVENT_MIN_LEVEL 0
#define EVENT_MAX_LEVEL 0xff

#define EVENT_ACTIVITY_CTRL_GET_ID 1
#define EVENT_ACTIVITY_CTRL_SET_ID 2
#define EVENT_ACTIVITY_CTRL_CREATE_ID 3
#define EVENT_ACTIVITY_CTRL_GET_SET_ID 4
#define EVENT_ACTIVITY_CTRL_CREATE_SET_ID 5

#define MAX_EVENT_DATA_DESCRIPTORS 128
#define MAX_EVENT_FILTER_DATA_SIZE 1024

#define EVENT_FILTER_TYPE_SCHEMATIZED 0x80000000

//
// EVENT_DATA_DESCRIPTOR is used to pass in user data items
// in events.
// 
EVENT_DATA_DESCRIPTOR STRUCT
	Ptr LONGLONG
	Size LONG
	Reserved LONG
ENDS

//
// EVENT_DESCRIPTOR describes and categorizes an event.
// 
#IFNDEF EVENT_DESCRIPTOR
	EVENT_DESCRIPTOR STRUCT
		Id SHORT
		Version CHAR
		Channel CHAR
		Level CHAR
		Opcode CHAR
		Task SHORT
		Keyword LONGLONG
	ENDS
#ENDIF

//
// EVENT_FILTER_DESCRIPTOR is used to pass in enable filter
// data item to a user callback function.
// 
EVENT_FILTER_DESCRIPTOR STRUCT
	Ptr LONGLONG
	Size LONG
	Type LONG
ENDS

EVENT_FILTER_HEADER STRUCT
	Id SHORT
	Version CHAR
	Reserved CHAR 5 DUP
	InstanceId LONGLONG
	Size LONG
	NextOffset LONG
ENDS

#endif

