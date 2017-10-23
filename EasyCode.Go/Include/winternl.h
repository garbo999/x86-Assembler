/************************************************************************
*                                                                       *
*   winternl.h -- This module defines the internal NT APIs and data     *
*       structures that are intended for the use only by internal core  *
*       Windows components.  These APIs and data structures may change  *
*       at any time.                                                    *
*                                                                       *
*   These APIs and data structures are subject to changes from one      *
*       Windows release to another Windows release.  To maintain the    *
*       compatiblity of your application, avoid using these APIs and    *
*       data structures.                                                *
*                                                                       *
*   The appropriate mechanism for accessing the functions defined in    *
*       this header is to use LoadLibrary() for ntdll.dll and           *
*       GetProcAddress() for the particular function.  By using this    *
*       approach, your application will be more resilient to changes    *
*       for these functions between Windows releases.  If a function    *
*       prototype does change, then GetProcAddress() for that function  *
*       might detect the change and fail the function call, which your  *
*       application will be able to detect.  GetProcAddress() may not   *
*       be able to detect all signature changes, thus avoid using these *
*       internal functions.  Instead, your application should use the   *
*       appropriate Win32 function that provides equivalent or similiar *
*       functionality.                                                  *
*                                                                       *
*   Copyright (c) Microsoft Corp. All rights reserved.                  *
*                                                                       *
************************************************************************/

// The winternl.h file is highly specialized
// it is not for general use. verify that it
// matches your criteria before using it. Do not
// use it in conjunction with any other low level
// header files or with WinNT.h. To use it include
// it *before* including WINDOWS.H.

#ifndef WINTERNL_H
#define WINTERNL_H

// NO OTHER LOW LEVEL FILES !!!!
#DEFINE WINNT_H
#DEFINE DBGHELP_H
#DEFINE IMAGEHLP_H
#DEFINE PSAPI_H

#IFNDEF WINDEF_H
	#include "windef.h"
#ENDIF

#IFNDEF ACCESS_MASK
	#DEFINE ACCESS_MASK DD
#ENDIF

//
// The PEB and TEB structures are subject to changes between Windows
// releases, thus the fields offsets may change as well as the Reserved
// fields.  The Reserved fields are reserved for use only by the Windows
// operating systems.  Do not assume a maximum size for the structures.
//

//
// Instead of using the BeingDebugged field, use the Win32 APIs
//     IsDebuggerPresent, CheckRemoteDebuggerPresent
// Instead of using the SessionId field, use the Win32 APIs
//     GetCurrentProcessId and ProcessIdToSessionId
// Sample x86 assembly code that gets the SessionId (subject to change
//     between Windows releases, use the Win32 APIs to make your application
//     resilient to changes)
//     mov     eax,fs:[00000018]
//     mov     eax,[eax+0x30]
//     mov     eax,[eax+0x1d4]
//

PEB STRUCT
	Reserved1 DB 2 DUP (?)
	BeingDebugged DB
	Reserved2 DB 229 DUP (?)
	Reserved3 DD 59 DUP (?)
	SessionId DD
ENDS

//
// Instead of using the Tls fields, use the Win32 TLS APIs
//     TlsAlloc, TlsGetValue, TlsSetValue, TlsFree
//
// Instead of using the ReservedForOle field, use the COM API
//     CoGetContextToken
//

TEB STRUCT
	Reserved1 DB 1952 DUP (?)
	Reserved2 DD 412 DUP (?)
	TlsSlots DD 64 DUP (?)
	Reserved3 DB 8 DUP (?)
	Reserved4 DD 26 DUP (?)
	ReservedForOle DD  // Windows 2000 only
	Reserved5 DD 4 DUP (?)
	TlsExpansionSlots DD
ENDS

//
// These data structures and type definitions are needed for compilation and
// use of the internal Windows APIs defined in this header.
//
#IFNDEF STRING

STRING STRUCT
	Length DW
	MaximumLength DW
	Buffer PTR
ENDS

#define ANSI_STRING STRING
#define OEM_STRING STRING
#define UNICODE_STRING STRING
#ENDIF

OBJECT_ATTRIBUTES STRUCT
	Length DD
	RootDirectory DD
	ObjectName PTR
	Attributes DD
	SecurityDescriptor PTR
	SecurityQualityOfService PTR
ENDS

IO_STATUS_BLOCK STRUCT
	UNION
		Status DD
		Pointer DD
	ENDUNION
	Information DD
ENDS

PIO_APC_ROUTINE STRUCT
	ApcContext DD
	IoStatusBlock DD
	Reserved DD
ENDS

#IFDEF IA64

FRAME_POINTERS STRUCT
	MemoryStackFp DQ
	BackingStoreFp DQ
ENDS

#define UNWIND_HISTORY_TABLE_SIZE 12

RUNTIME_FUNCTION STRUCT
	BeginAddress DD
	EndAddress DD
	UnwindInfoAddress DD
ENDS

UNWIND_HISTORY_TABLE_ENTRY STRUCT
	ImageBase DQ
	Gp DQ
	FunctionEntry DQ
ENDS

UNWIND_HISTORY_TABLE STRUCT
	Count DD
	Search DD
	LowAddress DQ
	HighAddress DQ
	Entry UNWIND_HISTORY_TABLE_ENTRY <>
ENDS

#endif // IA64

#IFNDEF PROCESS_BASIC_INFORMATION
PROCESS_BASIC_INFORMATION SRUCT
	ExitStatus LONG
	PebBaseAddress PTR
	AffinityMask PTR
	BasePriority LONG
	UniqueProcessId ULONG_PTR
	InheritedFromUniqueProcessId ULONG_PTR
ENDS
#ENDIF

SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION STRUCT
	IdleTime DQ
	KernelTime DQ
	UserTime DQ
	Reserved1 DQ 2 DUP
	Reserved2 DD
ENDS

SYSTEM_PROCESS_INFORMATION STRUCT
	NextEntryOffset DD
	Reserved1 DB 52 DUP
	Reserved2 DD 3 DUP
	UniqueProcessId DD
	Reserved3 DD
	HandleCount DD
	Reserved4 DB 4 DUP
	Reserved5 DD 11 DUP
	PeakPagefileUsage SIZE_T <>
	PrivatePageCount SIZE_T <>
	Reserved6 DQ 6 DUP
ENDS

SYSTEM_REGISTRY_QUOTA_INFORMATION STRUCT
	RegistryQuotaAllowed DD
	RegistryQuotaUsed DD
	Reserved1 DD
ENDS

SYSTEM_BASIC_INFORMATION STRUCT
	Reserved1 DB 24 DUP
	Reserved2 DD 4 DUP
	NumberOfProcessors DB
ENDS

SYSTEM_TIMEOFDAY_INFORMATION STRUCT
	Reserved1 DB 48 DUP
ENDS

SYSTEM_PERFORMANCE_INFORMATION STRUCT
	Reserved1 DB 312 DUP
ENDS

SYSTEM_EXCEPTION_INFORMATION STRUCT
	Reserved1 DB 16 DUP
ENDS

SYSTEM_LOOKASIDE_INFORMATION STRUCT
	Reserved1 DB 32 DUP
ENDS

SYSTEM_INTERRUPT_INFORMATION STRUCT
	Reserved1 DB 24 DUP
ENDS

FileDirectoryInformation       = 1
FileFullDirectoryInformation   = 2
FileBothDirectoryInformation   = 3
FileBasicInformation           = 4
FileStandardInformation        = 5
FileInternalInformation        = 6
FileEaInformation              = 7
FileAccessInformation          = 8
FileNameInformation            = 9
FileRenameInformation          = 10
FileLinkInformation            = 11
FileNamesInformation           = 12
FileDispositionInformation     = 13
FilePositionInformation        = 14
FileFullEaInformation          = 15
FileModeInformation            = 16
FileAlignmentInformation       = 17
FileAllInformation             = 18
FileAllocationInformation      = 19
FileEndOfFileInformation       = 20
FileAlternateNameInformation   = 21
FileStreamInformation          = 22
FilePipeInformation            = 23
FilePipeLocalInformation       = 24
FilePipeRemoteInformation      = 25
FileMailslotQueryInformation   = 26
FileMailslotSetInformation     = 27
FileCompressionInformation     = 28
FileObjectIdInformation        = 29
FileCompletionInformation      = 30
FileMoveClusterInformation     = 31
FileQuotaInformation           = 32
FileReparsePointInformation    = 33
FileNetworkOpenInformation     = 34
FileAttributeTagInformation    = 35
FileTrackingInformation        = 36
FileIdBothDirectoryInformation = 37
FileIdFullDirectoryInformation = 38
FileValidDataLengthInformation = 39
FileShortNameInformation       = 40
FileIoCompletionNotificationInformation = 41
FileIoStatusBlockRangeInformation       = 42
FileIoPriorityHintInformation           = 43
FileSfioReserveInformation              = 44
FileSfioVolumeInformation               = 45
FileHardLinkInformation                 = 46
FileProcessIdsUsingFileInformation      = 47
FileNormalizedNameInformation           = 48
FileNetworkPhysicalNameInformation      = 49
FileIdGlobalTxDirectoryInformation      = 50
FileIsRemoteDeviceInformation           = 51
FileAttributeCacheInformation           = 52
FileNumaNodeInformation                 = 53
FileStandardLinkInformation             = 54
FileRemoteProtocolInformation           = 55
FileMaximumInformation					= 56

FILE_BASIC_INFORMATION STRUCT
	CreationTime LARGE_INTEGER
	LastAccessTime LARGE_INTEGER
	LastWriteTime LARGE_INTEGER
	ChangeTime LARGE_INTEGER
	FileAttributes LONG
ENDS

FILE_STANDARD_INFORMATION STRUCT
	AllocationSize LARGE_INTEGER
	EndOfFile LARGE_INTEGER
	NumberOfLinks LONG
	DeletePending BOOLEAN
	Directory BOOLEAN
ENDS

FILE_POSITION_INFORMATION STRUCT
	CurrentByteOffset LARGE_INTEGER
ENDS

FILE_NETWORK_OPEN_INFORMATION STRUCT
	CreationTime LARGE_INTEGER
	LastAccessTime LARGE_INTEGER
	LastWriteTime LARGE_INTEGER
	ChangeTime LARGE_INTEGER
	AllocationSize LARGE_INTEGER
	EndOfFile LARGE_INTEGER
	FileAttributes LONG
ENDS

FILE_EA_INFORMATION STRUCT
	EaSize LONG
ENDS

FILE_FULL_EA_INFORMATION STRUCT
	NextEntryOffset LONG
	Flags CHAR
	EaNameLength CHAR
	EaValueLength SHORT
	EaName CHAR
ENDS

FILE_SFIO_RESERVE_INFORMATION STRUCT
	RequestsPerPeriod LONG
	Period LONG
	RetryFailures BOOLEAN
	Discardable BOOLEAN
	RequestSize LONG
	NumOutstandingRequests LONG
ENDS

FILE_SFIO_VOLUME_INFORMATION STRUCT
	MaximumRequestsPerPeriod LONG
	MinimumPeriod LONG
	MinimumTransferSize LONG
ENDS

// enum IO_PRIORITY_HINT
IoPriorityVeryLow = 0           // Defragging, content indexing and other background I/Os
IoPriorityLow = 1               // Prefetching for applications.
IoPriorityNormal = 2            // Normal I/Os
IoPriorityHigh = 3              // Used by filesystems for checkpoint I/O
IoPriorityCritical = 4          // Used by memory manager. Not available for applications.
MaxIoPriorityTypes = 5

FILE_IO_PRIORITY_HINT_INFORMATION STRUCT
	PriorityHint ENUM //    IO_PRIORITY_HINT
ENDS

#define FILE_SKIP_COMPLETION_PORT_ON_SUCCESS    0x1
#define FILE_SKIP_SET_EVENT_ON_HANDLE           0x2
#define FILE_SKIP_SET_USER_EVENT_ON_FAST_IO     0x4

FILE_IO_COMPLETION_NOTIFICATION_INFORMATION STRUCT
	Flags LONG
ENDS

FILE_PROCESS_IDS_USING_FILE_INFORMATION STRUCT
	NumberOfProcessIdsInList LONG
	ProcessIdList ULONG_PTR
ENDS

FILE_IS_REMOTE_DEVICE_INFORMATION STRUCT
	IsRemote BOOLEAN
ENDS

FILE_NUMA_NODE_INFORMATION STRUCT
	NodeNumber SHORT
ENDS

FILE_IOSTATUSBLOCK_RANGE_INFORMATION STRUCT
	IoStatusBlockRange PTR
	Length LONG
ENDS

// enum FSINFOCLASS
FileFsVolumeInformation      = 1
FileFsLabelInformation       = 2
FileFsSizeInformation        = 3
FileFsDeviceInformation      = 4
FileFsAttributeInformation   = 5
FileFsControlInformation     = 6
FileFsFullSizeInformation    = 7
FileFsObjectIdInformation    = 8
FileFsDriverPathInformation  = 9
FileFsVolumeFlagsInformation = 10
FileFsMaximumInformation     = 11

#define FILE_DEVICE_BEEP                0x00000001
#define FILE_DEVICE_CD_ROM              0x00000002
#define FILE_DEVICE_CD_ROM_FILE_SYSTEM  0x00000003
#define FILE_DEVICE_CONTROLLER          0x00000004
#define FILE_DEVICE_DATALINK            0x00000005
#define FILE_DEVICE_DFS                 0x00000006
#define FILE_DEVICE_DISK                0x00000007
#define FILE_DEVICE_DISK_FILE_SYSTEM    0x00000008
#define FILE_DEVICE_FILE_SYSTEM         0x00000009
#define FILE_DEVICE_INPORT_PORT         0x0000000a
#define FILE_DEVICE_KEYBOARD            0x0000000b
#define FILE_DEVICE_MAILSLOT            0x0000000c
#define FILE_DEVICE_MIDI_IN             0x0000000d
#define FILE_DEVICE_MIDI_OUT            0x0000000e
#define FILE_DEVICE_MOUSE               0x0000000f
#define FILE_DEVICE_MULTI_UNC_PROVIDER  0x00000010
#define FILE_DEVICE_NAMED_PIPE          0x00000011
#define FILE_DEVICE_NETWORK             0x00000012
#define FILE_DEVICE_NETWORK_BROWSER     0x00000013
#define FILE_DEVICE_NETWORK_FILE_SYSTEM 0x00000014
#define FILE_DEVICE_NULL                0x00000015
#define FILE_DEVICE_PARALLEL_PORT       0x00000016
#define FILE_DEVICE_PHYSICAL_NETCARD    0x00000017
#define FILE_DEVICE_PRINTER             0x00000018
#define FILE_DEVICE_SCANNER             0x00000019
#define FILE_DEVICE_SERIAL_MOUSE_PORT   0x0000001a
#define FILE_DEVICE_SERIAL_PORT         0x0000001b
#define FILE_DEVICE_SCREEN              0x0000001c
#define FILE_DEVICE_SOUND               0x0000001d
#define FILE_DEVICE_STREAMS             0x0000001e
#define FILE_DEVICE_TAPE                0x0000001f
#define FILE_DEVICE_TAPE_FILE_SYSTEM    0x00000020
#define FILE_DEVICE_TRANSPORT           0x00000021
#define FILE_DEVICE_UNKNOWN             0x00000022
#define FILE_DEVICE_VIDEO               0x00000023
#define FILE_DEVICE_VIRTUAL_DISK        0x00000024
#define FILE_DEVICE_WAVE_IN             0x00000025
#define FILE_DEVICE_WAVE_OUT            0x00000026
#define FILE_DEVICE_8042_PORT           0x00000027
#define FILE_DEVICE_NETWORK_REDIRECTOR  0x00000028
#define FILE_DEVICE_BATTERY             0x00000029
#define FILE_DEVICE_BUS_EXTENDER        0x0000002a
#define FILE_DEVICE_MODEM               0x0000002b
#define FILE_DEVICE_VDM                 0x0000002c
#define FILE_DEVICE_MASS_STORAGE        0x0000002d
#define FILE_DEVICE_SMB                 0x0000002e
#define FILE_DEVICE_KS                  0x0000002f
#define FILE_DEVICE_CHANGER             0x00000030
#define FILE_DEVICE_SMARTCARD           0x00000031
#define FILE_DEVICE_ACPI                0x00000032
#define FILE_DEVICE_DVD                 0x00000033
#define FILE_DEVICE_FULLSCREEN_VIDEO    0x00000034
#define FILE_DEVICE_DFS_FILE_SYSTEM     0x00000035
#define FILE_DEVICE_DFS_VOLUME          0x00000036
#define FILE_DEVICE_SERENUM             0x00000037
#define FILE_DEVICE_TERMSRV             0x00000038
#define FILE_DEVICE_KSEC                0x00000039
#define FILE_DEVICE_FIPS                0x0000003A
#define FILE_DEVICE_INFINIBAND          0x0000003B
#define FILE_DEVICE_VMBUS               0x0000003E
#define FILE_DEVICE_CRYPT_PROVIDER      0x0000003F
#define FILE_DEVICE_WPD                 0x00000040
#define FILE_DEVICE_BLUETOOTH           0x00000041
#define FILE_DEVICE_MT_COMPOSITE        0x00000042
#define FILE_DEVICE_MT_TRANSPORT        0x00000043
#define FILE_DEVICE_BIOMETRIC		0x00000044
#define FILE_DEVICE_PMI                 0x00000045

FILE_FS_DEVICE_INFORMATION STRUCT
	DeviceType LONG // DEVICE_TYPE  - Note this ENUM is explicitly defined as ULONG in the headers
	Characteristics LONG
ENDS

FILE_ACCESS_INFORMATION STRUCT
	AccessFlags DD
ENDS

FILE_ALIGNMENT_INFORMATION STRUCT
	AlignmentRequirement LONG
ENDS

FILE_ALL_INFORMATION STRUCT
	BasicInformation FILE_BASIC_INFORMATION
	StandardInformation FILE_STANDARD_INFORMATION
	InternalInformation FILE_INTERNAL_INFORMATION
	EaInformation FILE_EA_INFORMATION
	AccessInformation FILE_ACCESS_INFORMATION
	PositionInformation FILE_POSITION_INFORMATION
	ModeInformation FILE_MODE_INFORMATION
	AlignmentInformation FILE_ALIGNMENT_INFORMATION
	NameInformation FILE_NAME_INFORMATION
ENDS

FILE_INTERNAL_INFORMATION STRUCT
	IndexNumber LARGE_INTEGER
ENDS

FILE_MODE_INFORMATION STRUCT
	Mode LONG
ENDS

FILE_ATTRIBUTE_TAG_INFORMATION STRUCT
	FileAttributes LONG
	ReparseTag LONG
ENDS

#IFNDEF ProcessBasicInformation
ProcessBasicInformation = 0
ProcessQuotaLimits = 1
ProcessIoCounters = 2
ProcessVmCounters = 3
ProcessTimes = 4
ProcessBasePriority = 5
ProcessRaisePriority = 6
ProcessDebugPort = 7
ProcessExceptionPort = 8
ProcessAccessToken = 9
ProcessLdtInformation = 10
ProcessLdtSize = 11
ProcessDefaultHardErrorMode = 12
ProcessIoPortHandlers = 13 // Use from kernel mode only !!!
ProcessPooledUsageAndLimits = 14
ProcessWorkingSetWatch = 15
ProcessUserModeIOPL = 16
ProcessEnableAlignmentFaultFixup = 17
ProcessPriorityClass = 18
ProcessWx86Information = 19
ProcessHandleCount = 20
ProcessAffinityMask = 21
ProcessPriorityBoost = 22
MaxProcessInfoClass = 23
ProcessEllapsedTime = 24
ProcessWow64Information = 26
ProcessImageFileName = 27
ProcessLUIDDeviceMapsEnabled = 28
ProcessBreakOnTermination = 29
ProcessDebugObjectHandle = 30
ProcessDebugFlags = 31
ProcessHandleTracing = 32
ProcessIoPriority = 33
ProcessExecuteFlags = 34
ProcessTlsInformation = 35
ProcessCookie = 36
ProcessImageInformation = 37
ProcessCycleTime = 38
ProcessPagePriority = 39
ProcessInstrumentationCallback = 40
ProcessThreadStackAllocation = 41
ProcessWorkingSetWatchEx = 42
ProcessImageFileNameWin32 = 43
ProcessImageFileMapping = 44
ProcessAffinityUpdateMode = 45
ProcessMemoryAllocationMode = 46
ProcessGroupInformation = 47
ProcessTokenVirtualizationEnabled = 48
ProcessConsoleHostProcess = 49
ProcessWindowInformation = 50
MaxProcessInfoClass = 51
#ENDIF

ThreadIsIoPending = 16

// Definitions for NtQuerySystemInformation

SystemBasicInformation = 0
SystemProcessorInformation = 1
SystemPerformanceInformation = 2
SystemTimeOfDayInformation = 3
SystemPathInformation = 4
SystemProcessInformation = 5
SystemCallCountInformation = 6
SystemDeviceInformation = 7
SystemProcessorPerformanceInformation = 8
SystemFlagsInformation = 9
SystemCallTimeInformation = 10
SystemModuleInformation = 11
SystemLocksInformation = 12
SystemStackTraceInformation = 13
SystemPagedPoolInformation = 14
SystemNonPagedPoolInformation = 15
SystemHandleInformation = 16
SystemObjectInformation = 17
SystemPageFileInformation = 18
SystemVdmInstemulInformation = 19
SystemVdmBopInformation = 20
SystemFileCacheInformation = 21
SystemPoolTagInformation = 22
SystemInterruptInformation = 23
SystemDpcBehaviorInformation = 24
SystemFullMemoryInformation = 25
SystemLoadGdiDriverInformation = 26
SystemUnloadGdiDriverInformation = 27
SystemTimeAdjustmentInformation = 28
SystemSummaryMemoryInformation = 29
SystemNextEventIdInformation = 30
SystemEventIdsInformation = 31
SystemCrashDumpInformation = 32
SystemExceptionInformation = 33
SystemCrashDumpStateInformation = 34
SystemKernelDebuggerInformation = 35
SystemContextSwitchInformation = 36
SystemRegistryQuotaInformation = 37
SystemExtendServiceTableInformation = 38
SystemPrioritySeperation = 39
SystemPlugPlayBusInformation = 40
SystemDockInformation = 41
SystemPowerInformation = 42
SystemProcessorSpeedInformation = 43
SystemCurrentTimeZoneInformation = 44
SystemLookasideInformation = 45


#define INTERNAL_TS_ACTIVE_CONSOLE_ID 0x7ffe02d8
#define LOGONID_CURRENT -1
#define SERVERNAME_CURRENT 0

WinStationInformation = 8

WINSTATIONINFORMATIONW STRUCT
	Reserved2 DB 70 DUP
	LogonId DD
	Reserved3 DB 1140 DUP
ENDS

// OBJECT_INFORMATION_CLASS enumeration
ObjectBasicInformation      = 0 /*0x0*/
ObjectNameInformation       = 1 /*0x1*/
ObjectTypeInformation       = 2 /*0x2*/
ObjectTypesInformation      = 3 /*0x3*/
ObjectHandleFlagInformation = 4 /*0x4*/
ObjectSessionInformation    = 5 /*0x5*/
MaxObjectInfoClass          = 6 /*0x6*/

PUBLIC_OBJECT_BASIC_INFORMATION STRUCT
	Attributes LONG
	GrantedAccess ACCESS_MASK
	HandleCount LONG
	PointerCount LONG
	Reserved LONG 10 DUP
ENDS

PUBLIC_OBJECT_TYPE_INFORMATION STRUCT
	TypeName UNICODE_STRING
	Reserved LONG 22 DUP
ENDS

PUBLIC_OBJECT_NAME_INFORMATION STRUCT
	Name UNICODE_STRING
ENDS

SYSTEM_HANDLE_ENTRY STRUCT
	OwnerPid LONG
	ObjectType DB
	HandleFlags DB
	HandleValue SHORT
	ObjectPointer PTR
	GrantedAccess ACCESS_MASK
ENDS

SYSTEM_HANDLE_INFORMATION STRUCT
	HandleCount LONG
	Handles SYSTEM_HANDLE_ENTRY
ENDS

#IF X64

// X64 exception handling defs
// Win64 structured exception handling is not currently supported in GoAsm
// do not use these defs.

#define EXCEPTION_NONCONTINUABLE   0x0001
#define EXCEPTION_UNWINDING        0x0002
#define EXCEPTION_EXIT_UNWIND      0x0004
#define EXCEPTION_STACK_INVALID    0x0008
#define EXCEPTION_NESTED_CALL      0x0010
#define EXCEPTION_TARGET_UNWIND    0x0020
#define EXCEPTION_COLLIDED_UNWIND  0x0040
#define EXCEPTION_UNWIND           0x0066

#define UNWIND_HISTORY_TABLE_SIZE 12

#define UNWIND_HISTORY_TABLE_NONE 0
#define UNWIND_HISTORY_TABLE_GLOBAL 1
#define UNWIND_HISTORY_TABLE_LOCAL 2

UNWIND_HISTORY_TABLE STRUCT
	Count DD
	Search DB
	LowAddress DQ
	HighAddress DQ
	Entry UNWIND_HISTORY_TABLE_ENTRY UNWIND_HISTORY_TABLE_SIZE DUP
ENDS

UNWIND_HISTORY_TABLE_ENTRY STRUCT
	ImageBase DQ
	FunctionEntry PTR
ENDS

SCOPE_TABLE STRUCT
	Count DD
	ScopeRecord struct
		BeginAddress DD
		EndAddress DD
		HandlerAddress DD
		JumpTarget DD
	ENDS
ENDS

DISPATCHER_CONTEXT  STRUCT
	ControlPc DQ
	ImageBase DQ
	FunctionEntry PTR
	EstablisherFrame DQ
	TargetIp DQ
	ContextRecord PTR
	LanguageHandler PTR
	HandlerData PTR
	HistoryTable PTR
	ScopeIndex DD
	Fill0 DD
ENDS

// UNWIND_OP_CODES enum
UWOP_PUSH_NONVOL = 0     /* info == register number */
UWOP_ALLOC_LARGE = 1     /* no info, alloc size in next 2 slots */
UWOP_ALLOC_SMALL = 2     /* info == size of allocation / 8 - 1 */
UWOP_SET_FPREG = 3       /* no info, FP = RSP + UNWIND_INFO.FPRegOffset*16 */
UWOP_SAVE_NONVOL = 4     /* info == register number, offset in next slot */
UWOP_SAVE_NONVOL_FAR = 5 /* info == register number, offset in next 2 slots */
UWOP_SAVE_XMM128 = 6     /* info == XMM reg number, offset in next slot */
UWOP_SAVE_XMM128_FAR = 7 /* info == XMM reg number, offset in next 2 slots */
UWOP_PUSH_MACHFRAME = 8  /* info == 0: no error-code, 1: error-code */

UNWIND_CODE UNION
    struct
		CodeOffset DB
		UnwindOp DB
		OpInfo DB
	ENDS
	FrameOffset DW
ENDUNION

#define UNW_FLAG_EHANDLER  0x01
#define UNW_FLAG_UHANDLER  0x02
#define UNW_FLAG_CHAININFO 0x04

UNWIND_INFO STRUCT
	Version DB
	Flags DB
	SizeOfProlog DB
	CountOfCodes DB
	FrameRegister DB
	FrameOffset DB
	UnwindCode UNWIND_CODE
;  UNWIND_CODE MoreUnwindCode[((CountOfCodes + 1) & ~1) - 1];
;   union {
;       OPTIONAL ULONG ExceptionHandler;
;       OPTIONAL ULONG FunctionEntry;
;   };
;   OPTIONAL ULONG ExceptionData[]; */
ENDS

RUNTIME_FUNCTION STRUCT
	BeginAddress DD
	EndAddress DD
	UnwindData DD
ENDS

#ENDIF

#endif // WINTERNL_H
