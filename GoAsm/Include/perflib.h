/*++
Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    perflib.h

Abstract:

    Public headers for PERFLIB provider APIs,
--*/

#ifndef PERFLIB_H
#define _ERFLIB_H


// PERFLIB V2 provider side published literals, data structures and APIs.
//

// This is used in generated PERF_COUNTERSET_INFO structure to declare provider type.
// Kernel provider is reserved for Microsoft internal use.
// Driver provider and user-mode provider literals will be published.
//
#define PERF_PROVIDER_USER_MODE   0
#define PERF_PROVIDER_KERNEL_MODE 1
#define PERF_PROVIDER_DRIVER      2

// These are used for PERF_COUNTERSET_INFO::InstanceType value. That is, whether the CounterSet
// allows multiple instances (for example, Process, PhysicalDisk, etc) or only single default instance
// (for example, Memory, TCP, etc).
//
#define PERF_COUNTERSET_FLAG_MULTIPLE             2  // 0010
#define PERF_COUNTERSET_FLAG_AGGREGATE            4  // 0100
#define PERF_COUNTERSET_FLAG_HISTORY              8  // 1000
#define PERF_COUNTERSET_FLAG_INSTANCE            16  // 00010000

#define PERF_COUNTERSET_SINGLE_INSTANCE          0
#define PERF_COUNTERSET_MULTI_INSTANCES          (PERF_COUNTERSET_FLAG_MULTIPLE)
#define PERF_COUNTERSET_SINGLE_AGGREGATE         (PERF_COUNTERSET_FLAG_AGGREGATE)
#define PERF_COUNTERSET_MULTI_AGGREGATE          (PERF_COUNTERSET_FLAG_AGGREGATE | PERF_COUNTERSET_FLAG_MULTIPLE)
#define PERF_COUNTERSET_SINGLE_AGGREGATE_HISTORY (PERF_COUNTERSET_FLAG_HISTORY | PERF_COUNTERSET_SINGLE_AGGREGATE)
#define PERF_COUNTERSET_INSTANCE_AGGREGATE       (PERF_COUNTERSET_MULTI_AGGREGATE | PERF_COUNTERSET_FLAG_INSTANCE)

// Pre-defined aggregation function for CounterSets that need counter data aggregation. This is only useful
// for CounterSet with instanceType PERF_COUNTERSET_SINGLE_AGGREGATE, PERF_COUNTERSET_MULTI_AGGREGATE, and
// PERF_COUNTERSET_SINGLE_AGGREGATE_HISTORY. For other CounterSet instanceTypes, this is no effect.
//
#define PERF_AGGREGATE_UNDEFINED  0
#define PERF_AGGREGATE_TOTAL      1
#define PERF_AGGREGATE_AVG        2
#define PERF_AGGREGATE_MIN        3
#define PERF_AGGREGATE_MAX        4

// These are possible attributes used in generated PERF_COUNTER_INFO::Attrib value.
//
#define PERF_ATTRIB_BY_REFERENCE       0x0000000000000001
#define PERF_ATTRIB_NO_DISPLAYABLE     0x0000000000000002
#define PERF_ATTRIB_NO_GROUP_SEPARATOR 0x0000000000000004
#define PERF_ATTRIB_DISPLAY_AS_REAL    0x0000000000000008
#define PERF_ATTRIB_DISPLAY_AS_HEX     0x0000000000000010

// Provider counterset is defined as a leading PERF_COUNTERSET_INFO structure followed by a sequence
// of PERF_COUNTER_INFO structures. Note that the structure block will be automatically generated
// by schema generation/parsing tool.
//
PERF_COUNTERSET_INFO STRUCT
	CounterSetGuid GUID
	ProviderGuid GUID
	NumCounters DD
	InstanceType DD
ENDS

PERF_COUNTER_INFO STRUCT
	CounterId DD     // max of 64K counters per GUID instance
	Type DD
	Attrib DQ
	Size DD
	DetailLevel DD
	Scale  DD
	Offset DD         // overlays to give the actual counter
ENDS

// PERF_COUNTERSET_INSTANCE block is returned from PerfCreateInstance() API call to identify specific
// instance of a counterset. The returned block is formed by PERF_COUNTERSET_INSTANCE structure followed
// by counter data block (layout defined by provider counterset template) and instance name string (if exists).
//
PERF_COUNTERSET_INSTANCE STRUCT
	CounterSetGuid GUID
	dwSize DD
	InstanceId DD
	InstanceNameOffset DD
	InstanceNameSize DD
ENDS

// PERF_COUNTER_IDENTITY structure is used in customized notification callback. Wheneven PERFLIB V2
// invokes customized notification callback, it passes wnode datablock (which contains WNODE_HEADER
// structure followed by other binary data) that contains the information providers can use.
//
// For PERF_ADD_COUNTER and PERF_REMOVE_COUNTER request, PERFLIB will pass PERF_COUNTER_IDENTITY block
// so that providers know which counter is added/removed. For other requests, currently only machine name 
// is passed (so that providers can determine whether the request is for physical node or virtual node).
//
PERF_COUNTER_IDENTITY STRUCT
	CounterSetGuid GUID
	BufferSize DD
	CounterId DD
	InstanceId DD
	MachineOffset DD
	NameOffset DD
	Reserved DD
ENDS

#define PERF_WILDCARD_COUNTER   0xFFFFFFFF
#define PERF_WILDCARD_INSTANCE  L"*"
#define PERF_AGGREGATE_INSTANCE L"_Total"
#define PERF_MAX_INSTANCE_NAME  1024

#define PERF_ADD_COUNTER            1
#define PERF_REMOVE_COUNTER         2
#define PERF_ENUM_INSTANCES         3
#define PERF_COLLECT_START          5
#define PERF_COLLECT_END            6
#define PERF_FILTER                 9


PROVIDER_CONTEXT STRUCT
	ContextSize DD // should be sizeof(PERF_PROVIDER_CONTEXT)
	Reserved PTR
	ControlCallback PTR
	MemAllocRoutine PTR
	MemFreeRoutine PTR
	pMemContext PTR
ENDS

#endif /* PERFLIB_H */

