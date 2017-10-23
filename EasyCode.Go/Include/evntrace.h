#ifndef EVNTRACE_H
#define EVNTRACE_H

/* Windows NT Event tracing definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Advapi32.dll
#ENDIF

#IFNDEF GUIDDEF_H
	#include guiddef.h
#ENDIF

#define MAX_MOF_FIELDS  16

#define EVENT_TRACE_TYPE_INFO  0x00
#define EVENT_TRACE_TYPE_START  0x01
#define EVENT_TRACE_TYPE_END  0x02
#define EVENT_TRACE_TYPE_DC_START  0x03
#define EVENT_TRACE_TYPE_DC_END  0x04
#define EVENT_TRACE_TYPE_EXTENSION  0x05
#define EVENT_TRACE_TYPE_REPLY  0x06
#define EVENT_TRACE_TYPE_DEQUEUE  0x07
#define EVENT_TRACE_TYPE_CHECKPOINT  0x08
#define EVENT_TRACE_TYPE_RESERVED9  0x09

#define EVENT_TRACE_TYPE_LOAD  0x0A

#define EVENT_TRACE_TYPE_IO_READ  0x0A
#define EVENT_TRACE_TYPE_IO_WRITE  0x0B

#define EVENT_TRACE_TYPE_MM_TF  0x0A
#define EVENT_TRACE_TYPE_MM_DZF  0x0B
#define EVENT_TRACE_TYPE_MM_COW  0x0C
#define EVENT_TRACE_TYPE_MM_GPF  0x0D
#define EVENT_TRACE_TYPE_MM_HPF  0x0E

#define EVENT_TRACE_TYPE_SEND  0x0A
#define EVENT_TRACE_TYPE_RECEIVE  0x0B
#define EVENT_TRACE_TYPE_CONNECT  0x0C
#define EVENT_TRACE_TYPE_DISCONNECT  0x0D

#define EVENT_TRACE_TYPE_GUIDMAP  0x0A
#define EVENT_TRACE_TYPE_CONFIG  0x0B
#define EVENT_TRACE_TYPE_SIDINFO  0x0C
#define EVENT_TRACE_TYPE_SECURITY  0x0D

#define EVENT_TRACE_TYPE_REGCREATE  0x0A
#define EVENT_TRACE_TYPE_REGOPEN  0x0B
#define EVENT_TRACE_TYPE_REGDELETE  0x0C
#define EVENT_TRACE_TYPE_REGQUERY  0x0D
#define EVENT_TRACE_TYPE_REGSETVALUE  0x0E
#define EVENT_TRACE_TYPE_REGDELETEVALUE  0x0F
#define EVENT_TRACE_TYPE_REGQUERYVALUE  0x10
#define EVENT_TRACE_TYPE_REGENUMERATEKEY  0x11
#define EVENT_TRACE_TYPE_REGENUMERATEVALUEKEY  0x12
#define EVENT_TRACE_TYPE_REGQUERYMULTIPLEVALUE  0x13
#define EVENT_TRACE_TYPE_REGSETINFORMATION  0x14
#define EVENT_TRACE_TYPE_REGFLUSH  0x15

#define EVENT_TRACE_FLAG_PROCESS  0x00000001
#define EVENT_TRACE_FLAG_THREAD  0x00000002
#define EVENT_TRACE_FLAG_IMAGE_LOAD  0x00000004
#define EVENT_TRACE_FLAG_DISK_IO  0x00000100
#define EVENT_TRACE_FLAG_DISK_FILE_IO  0x00000200
#define EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS 0x00001000
#define EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS 0x00002000
#define EVENT_TRACE_FLAG_NETWORK_TCPIP  0x00010000
#define EVENT_TRACE_FLAG_REGISTRY  0x00020000
#define EVENT_TRACE_FLAG_EXTENSION  0x80000000
#define EVENT_TRACE_FLAG_FORWARD_WMI  0x40000000
#define EVENT_TRACE_FLAG_ENABLE_RESERVE  0x20000000

#define EVENT_TRACE_FILE_MODE_NONE  0x0000
#define EVENT_TRACE_FILE_MODE_SEQUENTIAL  0x0001
#define EVENT_TRACE_FILE_MODE_CIRCULAR  0x0002

#define EVENT_TRACE_REAL_TIME_MODE  0x0100
#define EVENT_TRACE_DELAY_OPEN_FILE_MODE  0x0200
#define EVENT_TRACE_BUFFERING_MODE  0x0400
#define EVENT_TRACE_PRIVATE_LOGGER_MODE  0x0800
#define EVENT_TRACE_ADD_HEADER_MODE  0x1000

#define EVENT_TRACE_CONTROL_QUERY  0
#define EVENT_TRACE_CONTROL_STOP  1
#define EVENT_TRACE_CONTROL_UPDATE  2

#DEFINE GUID_EventTraceGuid <0x68fdd900,0x4a3e,0x11d1,<0x84,0xf4,0x00,0x00,0xf8,0x04,0x64,0xe3>>
#DEFINE GUID_SystemTraceControlGuid <0x9e814aad,0x3204,0x11d2,<0x9a,0x82,0x00,0x60,0x08,0xa8,0x69,0x39>>

TRACE_ENABLE_CONTEXT STRUCT
	LoggerId DW
	Level DB
	InternalFlag DB
	EnableFlags DD
ENDS

EVENT_TRACE_HEADER STRUCT
	Size DW
	HeaderType DB
	MarkerFlags DB
	UNION
		Version DD
		Class STRUCT
			Type DB
			Level DB
			Version DW
		ENDS
	ENDUNION
	ThreadId DQ
	TimeStamp DQ
	UNION
		Guid GUID
		GuidPtr DQ
	ENDUNION
	UNION
		ClientContext DQ
		KernelTime DQ
		ProcessorTime DQ
	ENDUNION
ENDS

EVENT_INSTANCE_HEADER STRUCT
	Size DW
	HeaderType DB
	MarkerFlags DB
	UNION
		Version DD
		Class STRUCT
			Type DB
			Level DB
			Version DW
		ENDS
	ENDUNION
	ThreadId DQ
	TimeStamp DQ
	RegHandle DQ
	InstanceId DD
	ParentInstanceId DD
	UNION
		ClientContext DQ
		KernelTime DQ
		ProcessorTime DQ
	ENDUNION
	ParentRegHandle DQ
ENDS

MOF_FIELD STRUCT
	DataPtr DQ
	Length DD
	DataType DD
ENDS

;_VersionDetail STRUCT
;	MajorVersion DB
;	MinorVersion DB
;	SubVersion DB
;	SubMinorVersion DB
;ENDS

TRACE_LOGFILE_HEADER STRUCT
	BufferSize DD
	union
		Version DD
		VersionDetail struct
			MajorVersion DB
			MinorVersion DB
			SubVersion DB
			SubMinorVersion DB
		ENDS
	ENDUNION
	ProviderVersion DD
	NumberOfProcessors DD
	EndTime LARGE_INTEGER
	TimerResolution DD
	MaximumFileSize DD
	LogFileMode DD
	BuffersWritten DD
	UNION
		LogInstanceGuid GUID
		STRUCT
			StartBuffers DD
			PointerSize DD
			EventsLost DD
			CpuSpeedInMHz DD
		ENDS
	ENDUNION
	LoggerName PTR
	LogFileName PTR
	TimeZone TIME_ZONE_INFORMATION
	BootTime LARGE_INTEGER
	PerfFreq LARGE_INTEGER
	StartTime LARGE_INTEGER
	ReservedFlags DD
	BuffersLost DD
ENDS

EVENT_INSTANCE_INFO STRUCT
	RegHandle HANDLE
	InstanceId DD
ENDS

#IFNDEF WNODE_HEADER
WNODE_HEADER STRUCT
	BufferSize DD
	ProviderId DD
	UNION
		HistoricalContext DQ
		STRUCT
			Version DD
			Linkage DD
		ENDS
	ENDUNION
	UNION
		KernelHandle HANDLE
		TimeStamp LARGE_INTEGER
	ENDUNION
	Guid GUID
	ClientContext DD
	Flags DD 
ENDS
#ENDIF

EVENT_TRACE_PROPERTIES STRUCT
	Wnode WNODE_HEADER
	BufferSize DD
	MinimumBuffers DD
	MaximumBuffers DD
	MaximumFileSize DD
	LogFileMode DD
	FlushTimer DD
	EnableFlags DD
    LONG AgeLimit DD
	NumberOfBuffers DD
	FreeBuffers DD
	EventsLost DD
	BuffersWritten DD
	LogBuffersLost DD
	RealTimeBuffersLost DD
	LoggerThreadId HANDLE
	LogFileNameOffset DD
	LoggerNameOffset DD
ENDS

TRACE_GUID_REGISTRATION STRUCT
	Guid PTR
	RegHandle HANDLE
ENDS

EVENT_TRACE STRUCT
	Header EVENT_TRACE_HEADER
	InstanceId DD
	ParentInstanceId DD
	ParentGuid GUID
	MofData PTR
	MofLength DD
	UNION
		ClientContext DD
		BufferContext DD
	ENDUNION
ENDS

EVENT_TRACE_LOGFILEW STRUCT
	LogFileName PTR
	LoggerName PTR
	CurrentTime DQ
	BuffersRead DD
	UNION
		LogFileMode DD
		ProcessTraceMode DD
	ENDUNION
	CurrentEvent EVENT_TRACE
	LogfileHeader TRACE_LOGFILE_HEADER
	BufferCallback PTR
	BufferSize DD
	Filled DD
	EventsLost DD
	UNION
		EventCallback PTR
		EventRecordCallback PTR
	ENDUNION
	IsKernelTrace DD
	Context PTR
ENDS

EVENT_TRACE_LOGFILEA STRUCT
	LogFileName PTR
	LoggerName PTR
	CurrentTime DQ
	BuffersRead DD
	UNION
		LogFileMode DD
		ProcessTraceMode DD
	ENDUNION
	CurrentEvent EVENT_TRACE
	LogfileHeader TRACE_LOGFILE_HEADER
	BufferCallback PTR
	BufferSize DD
	Filled DD
	EventsLost DD
	UNION
		EventCallback PTR
		EventRecordCallback PTR
	ENDUNION
	IsKernelTrace DD
	Context PTR
ENDS

ETW_BUFFER_CONTEXT STRUCT
	ProcessorNumber CHAR
	Alignment CHAR
	LoggerId SHORT
ENDS

#IFDEF UNICODE
	#define EVENT_TRACE_LOGFILE  EVENT_TRACE_LOGFILEW
	#define RegisterTraceGuids  RegisterTraceGuidsW
	#define StartTrace  StartTraceW
	#define ControlTrace  ControlTraceW
	#define QueryAllTraces  QueryAllTracesW
	#define OpenTrace  OpenTraceW
	#define FlushTrace  FlushTraceW
#else
	#define EVENT_TRACE_LOGFILE  EVENT_TRACE_LOGFILEA
	#define RegisterTraceGuids  RegisterTraceGuidsA
	#define StartTrace  StartTraceA
	#define ControlTrace  ControlTraceA
	#define QueryAllTraces  QueryAllTracesA
	#define OpenTrace  OpenTraceA
	#define FlushTrace  FlushTraceA
#endif /* UNICODE */

#endif
