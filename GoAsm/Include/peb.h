#IFNDEF PEB_H
#define PEB_H

/*
Switches used
WIN9X
*/

#IF WINVER > NTDDI_WIN9X
/*
NtQueryInformationProcess is available for use in Windows 2000 and Windows XP.
It may be altered or unavailable in subsequent versions.
*/

	// ProcessInformationClasses for NtQueryInformationProcess
	#Define ProcessBasicInformation 000000000h
	#Define ProcessQuotaLimits 000000001h
	#Define ProcessIoCounters 000000002h
	#Define ProcessVmCounters 000000003h
	#Define ProcessTimes 000000004h
	#Define ProcessBasePriority 000000005h
	#Define ProcessRaisePriority 000000006h
	#Define ProcessDebugPort 000000007h
	#Define ProcessExceptionPort 000000008h
	#Define ProcessAccessToken 000000009h
	#Define ProcessLdtInformation 00000000Ah
	#Define ProcessLdtSize 00000000Bh
	#Define ProcessDefaultHardErrorMode 00000000Ch
	#Define ProcessIoPortHandlers 00000000Dh ; Kernel mode only
	#Define ProcessPooledUsageAndLimits 00000000Eh
	#Define ProcessWorkingSetWatch 00000000Fh
	#Define ProcessUserModeIOPL 000000010h
	#Define ProcessEnableAlignmentFaultFixup 000000011h
	#Define ProcessPriorityClass 000000012h
	#Define ProcessWx86Information 000000013h
	#Define ProcessHandleCount 000000014h
	#Define ProcessAffinityMask 000000015h
	#Define ProcessPriorityBoost 000000016h
	#Define ProcessDeviceMap 000000017h
	#Define ProcessSessionInformation 000000018h
	#Define ProcessForegroundInformation 000000019h
	#Define ProcessWow64Information 00000001Ah
	#Define MaxProcessInfoClass 00000001Bh

	PROCESS_BASIC_INFORMATION STRUCT
		//  NtQueryInformationProcess using ProcessBasicInfo
		ExitStatus						DD
		PebBaseAddress					DD
		AffinityMask					DD
		BasePriority					DD
		UniqueProcessId					DD
		InheritedFromUniqueProcessId	DD
	ENDS

	PROCESS_SESSION_INFORMATION STRUCT
		//  NtQueryInformationProcess using ProcessSessionInformation
		SessionId		DD
	ENDS

	QUOTA_LIMITS STRUCT
		//  NtQueryInformationProcess using ProcessQuotaLimits
		//  NtQueryInformationProcess using ProcessPooledQuotaLimits
		//  NtSetInformationProcess using ProcessQuotaLimits
		PagedPoolLimit			DD
		NonPagedPoolLimit		DD
		MinimumWorkingSetSize	DD
		MaximumWorkingSetSize	DD
		PagefileLimit			DD
		TimeLimit				DQ
	ENDS

	IO_COUNTERS STRUCT
		//  NtQueryInformationProcess using ProcessIoCounters
		ReadOperationCount	DQ
		WriteOperationCount	DQ
		OtherOperationCount	DQ
		ReadTransferCount	DQ
		WriteTransferCount	DQ
		OtherTransferCount	DQ
	ENDS

	VM_COUNTERS STRUCT
		//  NtQueryInformationProcess using ProcessVmCounters
		PeakVirtualSize				DD
		VirtualSize					DD
		PageFaultCount				DD
		PeakWorkingSetSize			DD
		WorkingSetSize				DD
		QuotaPeakPagedPoolUsage		DD
		QuotaPagedPoolUsage			DD
		QuotaPeakNonPagedPoolUsage	DD
		QuotaNonPagedPoolUsage		DD
		PagefileUsage				DD
		PeakPagefileUsage			DD
	ENDS

	POOLED_USAGE_AND_LIMITS STRUCT
		//  NtSetInformationProcess using ProcessAccessToken
		//  PROCESS_SET_ACCESS_TOKEN access to the process is needed
		PeakPagedPoolUsage		DD
		PagedPoolUsage			DD
		PagedPoolLimit			DD
		PeakNonPagedPoolUsage	DD
		NonPagedPoolUsage		DD
		NonPagedPoolLimit		DD
		PeakPagefileUsage		DD
		PagefileUsage			DD
		PagefileLimit			DD
	ENDS

	PROCESS_ACCESS_TOKEN STRUCT
		//  NtSetInformationProcess using ProcessAccessToken
		//  PROCESS_SET_ACCESS_TOKEN access to the process is needed
		Token	DD
		Thread	DD
	ENDS

	KERNEL_USER_TIMES STRUCT
		//  NtQueryInformationProcess using ProcessTimes
		//  NtQueryInformationThread using ThreadTimes
		//	Note all times are zulu
		CreateTime	DQ
		ExitTime	DQ
		KernelTime	DQ
		UserTime	DQ
	ENDS

	TIME_FIELDS STRUCT
		// Use with RtlTimeToTimeFields
		// RtlTimeToTimeFields,offset DQTIME,offset TIME_FIELDS
		// Needed to convert KERNEL_USER_TIMES fields
		Year			DW ; range [1601...]
		Month			DW ; range [1..12]
		Day				DW ; range [1..31]
		Hour			DW ; range [0..23]
		Minute			DW ; range [0..59]
		Second			DW ; range [0..59]
		Milliseconds	DW ; range [0..999]
		Weekday			DW ; range [0..6] == [Sunday..Saturday]
	ENDS

	CLIENT_ID STRUCT
		UniqueProcess	DD
		UniqueThread	DD
	ENDS

	SYSTEM_THREAD STRUCT
		KernelTime		DQ
		UserTime		DQ
		CreateTime		DQ
		WaitTime		DD
		StartAddress	DD
		ClientId		CLIENT_ID
		Priority		DD
		BasePriority	DD
		ContextSwitches	DD
		ThreadState		DD // 2=running; 5=waiting
		WaitReason		DD
	ENDS

	UNICODE_STRING	STRUCT
		Length			DW
		MaximumLength	DW
		Buffer			DD
	ENDS

	ANSI_STRING STRUCT
		Length			dw
		MaximumLength	dw
		Buffer			DD
	ENDS

	SYSTEM_PROCESS_INFORMATION STRUCT
		dNext							DD
		dThreadCount					DD
		dReserved01						DD
		dReserved02						DD
		dReserved03						DD
		dReserved04						DD
		dReserved05						DD
		dReserved06						DD
		qCreateTime						DQ
		qUserTime						DQ
		qKernelTime						DQ
		usName							UNICODE_STRING
		BasePriority					DD
		dUniqueProcessId				DD
		dInheritedFromUniqueProcessId	DD
		dHandleCount					DD
		dReserved07						DD
		dReserved08						DD
		VmCounters						VM_COUNTERS
		dCommitCharge					DD
		Threads							SYSTEM_THREAD
	ENDS
#ENDIF

#IF WINVER = NTDDI_WIN9X
	TIB STRUCT
		; 9X & NT
		pvExcept			DD	// 00h Head of exception record list
		pvStackUserTop		DD	// 04h Top of user stack
		pvStackUserBase		DD	// 08h Base of user stack
	
		; 9X only
		pvTDB				DW	// 0Ch TDB
		pvThunkSS			DW	// 0Eh SS selector used for thunking to 16 bits
		unknown1			DD	// 10h
		
		; 9X & NT
		pvArbitrary			DD	// 14h Available for application use
		ptibSelf			DD	// 18h Linear address of this structure
		
		; 9X only
		TIBFlags			DW	// 1Ch
		Win16MutexCount		DW	// 1Eh
		DebugContext		DD	// 20h
		pCurrentPriority	DD	// 24h
		pvQueue				DD	// 28h Message Queue selector
	
		; 9X & NT
		pvTLSArray			DD	// 2Ch Thread Local Storage array
		; 9X only
		pProcess			DD	// 30h Pointer to owning process database (PDB)
	ENDS
#ELSE
	TIB STRUCT
		pvExcept			DD	// 00h Head of exception record list
		pvStackUserTop		DD	// 04h Top of user stack
		pvStackUserBase		DD	// 08h Base of user stack
	
		; NT only
		SubSystemTib		DD	// 0Ch
		FiberData			DD	// 10h
	
		; 9X & NT
		pvArbitrary			DD	// 14h Available for application use
		ptibSelf			DD	// 18h Linear address of this structure
	
		; NT only
		unknown1			DD	// 1Ch
		processID			DD	// 20h
		threadID			DD	// 24h
		unknown2			DD	// 28h
	
		pvTLSArray			DD	// 2Ch Thread Local Storage array
	
		; NT only
		pPEB				DD	// 30h Pointer to Process Environment Block (PEB)
	ENDS
	
#ENDIF

PDB STRUCT
	header 				DD	2 DUP		// 00 Kernel object header
	module				DD				// 08 Main exe module (NT)
	LdrData				DD				// 0c Pointer to loader information 
	ProcessParameters	DD				// 10 Process parameters 
	unknown1			DD				// 14 Unknown
	heap				DD				// 18 Default process heap
	mem_context			DD				// 1c Process memory context
	dwflags				DD				// 20 Flags
	pdb16				DD				// 24 DOS PSP (pointer)
	PSP_sel				DW				// 28 Selector to DOS PSP
	imte				DW				// 2a IMTE for the process module
	threads				DW				// 2c Number of threads
	running_threads		DW				// 2e Number of running threads
	free_lib_count		DW				// 30 Recursion depth of FreeLibrary calls
	ring0_threads		DW				// 32 Number of ring 0 threads
	system_heap			DD				// 34 System heap to allocate handles
	task				DD				// 38 Win16 task
	mem_map_files		DD				// 3c Pointer to mem-mapped files (pointer)
	env_db				DD				// 40 Environment database (pointer)
	handle_table		DD				// 44 Handle table (pointer)
	parent				DD				// 48 Parent process (pointer)
	modref_list			DD				// 4c MODREF list (pointer)
	thread_list			DD				// 50 List of threads (pointer)
	debuggee_CB			DD				// 54 Debuggee context block (pointer)
	local_heap_free		DD				// 58 Head of local heap free list (pointer)
	unknown2			DD				// 5c Unknown 
	crit_section		DD				// 60 Critical section
	unknown3			DD	3 DUP		// 78 Unknown
	console				DD				// 84 Console (pointer)
	tls_bits			DD	2 DUP		// 88 TLS in-use bits
	process_dword		DD				// 90 process dword (??)
	group				DD				// 94 Process group (pointer)
	exe_modref			DD				// 98 MODREF for the process EXE (pointer)
	top_filter			DD				// 9c Top exception filter (pointer)
	priority			DD				// a0 Priority level
	heap_list			DD				// a4 Head of process heap list
	heap_handles		DD				// a8 Head of heap handles list (pointer)
	unknown4			DD				// ac Unknown
	console_provider	DD				// b0 Console provider (??)
	env_selector		DD				// b4 Selector to process environment
	error_mode			DD				// b6 Error mode
	load_done_evt		DD				// b8 Event for process loading done
	UTState				DD				// bc Head of Univeral Thunk list
	unknown5			DD				// c0 Unknown (NT)
	locale				DD				// c4 Locale to be queried by GetThreadLocale (NT)
ENDS

#IF X64
	PEB STRUCT
		Reserved1 DB 2 DUP
		BeingDebugged DB
		Reserved2 DB
		Reserved3 PTR 2 DUP
		Ldr PTR
		ProcessParameters PTR
		Reserved4 DB 104 DUP
		Reserved5 PTR 52 DUP
		PostProcessInitRoutine PTR
		Reserved6 DB 128 DUP
		Reserved7 PTR
		SessionId DD 
	ENDS
#ELSE
	PEB STRUCT
		Reserved1 DB 2 DUP
		BeingDebugged DB
		Reserved2 DB 21 DUP
		LoaderData PTR
		ProcessParameters PTR
		Reserved3 DB 520 DUP
		PostProcessInitRoutine PTR
		Reserved4 DB 136 DUP
		SessionId DD
	ENDS
#ENDIF

// OBJECT_INFORMATION_CLASS enumeration
ObjectBasicInformation      = 0 /*0x0*/,
ObjectNameInformation       = 1 /*0x1*/,
ObjectTypeInformation       = 2 /*0x2*/,
ObjectTypesInformation      = 3 /*0x3*/,
ObjectHandleFlagInformation = 4 /*0x4*/,
ObjectSessionInformation    = 5 /*0x5*/,
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

#ENDIF
