#IFNDEF NTDLL_H
#DEFINE NTDLL_H

#IF WINVER >= NTDDI_WIN7
	#define AitLogFeatureUsageByApp ntdll.dll:1
	#define AitFireParentUsageEvent ntdll.dll:2
	#define SbtLogSystemUsageByParent ntdll.dll:3
	#define SbtLogSystemUsageByStack ntdll.dll:4
	#define SbtDisableForCurrentProcess ntdll.dll:5
	#define SbtLogDllMapping ntdll.dll:6
	#define SbtLogExeInitializing ntdll.dll:7
	#define RtlDispatchAPC ntdll.dll:8
#ENDIF

#define STATUS_INFO_LENGTH_MISMATCH 0xc0000004

SystemBasicInformation = 0
SystemProcessesAndThreadsInformation = 5

SYSTEM_BASIC_INFORMATION STRUCT
	Unknown LONG
	MaximumIncrement LONG
	PhysicalPageSize LONG
	NumberOfPhysicalPages LONG
	LowestPhysicalPage LONG
	HighestPhysicalPage LONG
	AllocationGranularity LONG
	LowestUserAddress LONG
	HighestUserAddress LONG
	ActiveProcessors LONG
	NumberProcessors LONG
ENDS

#IFNDEF IO_COUNTERS
IO_COUNTERS STRUCT
	//  NtQueryInformationProcess using ProcessIoCounters
	ReadOperationCount	DQ
	WriteOperationCount	DQ
	OtherOperationCount	DQ
	ReadTransferCount	DQ
	WriteTransferCount	DQ
	OtherTransferCount	DQ
ENDS
#ENDIF

#IFNDEF VM_COUNTERS
VM_COUNTERS STRUCT
	PeakVirtualSize LONG
	VirtualSize LONG
	PageFaultCount LONG
	PeakWorkingSetSize LONG
	WorkingSetSize LONG
	QuotaPeakPagedPoolUsage LONG
	QuotaPagedPoolUsage LONG
	QuotaPeakNonPagedPoolUsage LONG
	QuotaNonPagedPoolUsage LONG
	PagefileUsage LONG
	PeakPagefileUsage LONG
ENDS
#ENDIF

#IFNDEF CLIENT_ID
CLIENT_ID STRUCT
	UniqueProcess HANDLE
	UniqueThread HANDLE
ENDS
#ENDIF

StateInitialized = 0
StateReady = 1
StateRunning = 2
StateStandby = 3
StateTerminated = 4
StateWait = 5
StateTransition = 6
StateUnknown = 7

Executive = 0
FreePage = 1
PageIn = 2
PoolAllocation = 3
DelayExecution = 4
Suspended = 5
UserRequest = 6
WrExecutive = 7
WrFreePage = 8
WrPageIn = 9
WrPoolAllocation = 10
WrDelayExecution = 11
WrSuspended = 12
WrUserRequest = 13
WrEventPair = 14
WrQueue = 15
WrLpcReceive = 16
WrLpcReply = 17
WrVirtualMemory = 18
WrPageOut = 19
WrRendezvous = 20
Spare2 = 21
Spare3 = 22
Spare4 = 23
Spare5 = 24
Spare6 = 25
WrKernel = 26
MaximumWaitReason = 27

SYSTEM_THREADS STRUCT
	KernelTime LARGE_INTEGER
	UserTime LARGE_INTEGER
	CreateTime LARGE_INTEGER
	WaitTime LONG
	StartAddress PTR
	ClientId CLIENT_ID
	Priority LONG
	BasePriority LONG
	ContextSwitchCount LONG
	State DD
	WaitReason DD
ENDS

SYSTEM_PROCESSES STRUCT
	NextEntryDelta LONG
	Threadcount LONG
	Reserved1 LONG 6 DUP
	CreateTime LARGE_INTEGER
	UserTime LARGE_INTEGER
	KernelTime LARGE_INTEGER
	ProcessName UNICODE_STRING
	BasePriority LONG
	ProcessId LONG
	InheritedFromProcessId LONG
	HandleCount LONG
	Reserved2 LONG 2 DUP
	VmCounters VM_COUNTERS
	IoCounters IO_COUNTERS
	Threads SYSTEM_THREADS
ENDS

#ENDIF