#ifndef PSAPI_H
#define PSAPI_H

/* Windows PSAPI.DLL definitions */

#IFDEF LINKFILES
	#dynamiclinkfile PSAPI.dll
#ENDIF

MODULEINFO STRUCT
	lpBaseOfDll PTR
	SizeOfImage DD
	EntryPoint PTR
ENDS

PSAPI_WS_WATCH_INFORMATION STRUCT
	FaultingPc PTR
	FaultingVa PTR
ENDS

PSAPI_WS_WATCH_INFORMATION_EX STRUCT
	BasicInfo PSAPI_WS_WATCH_INFORMATION
	FaultingThreadId ULONG_PTR
	Flags ULONG_PTR
ENDS

PROCESS_MEMORY_COUNTERS STRUCT
	cb DD
	PageFaultCount DD
	PeakWorkingSetSize SIZE_T
	WorkingSetSize SIZE_T
	QuotaPeakPagedPoolUsage SIZE_T
	QuotaPagedPoolUsage SIZE_T
	QuotaPeakNonPagedPoolUsage SIZE_T
	QuotaNonPagedPoolUsage SIZE_T
	PagefileUsage SIZE_T
	PeakPagefileUsage SIZE_T
ENDS

PROCESS_MEMORY_COUNTERS_EX STRUCT
	cb DD
	PageFaultCount DD
	PeakWorkingSetSize SIZE_T
	WorkingSetSize SIZE_T
	QuotaPeakPagedPoolUsage SIZE_T
	QuotaPagedPoolUsage SIZE_T
	QuotaPeakNonPagedPoolUsage SIZE_T
	QuotaNonPagedPoolUsage SIZE_T
	PagefileUsage SIZE_T
	PeakPagefileUsage SIZE_T
	PrivateUsage SIZE_T
ENDS

PERFORMANCE_INFORMATION STRUCT
	cb DD
	CommitTotal SIZE_T
	CommitLimit SIZE_T
	CommitPeak SIZE_T
	PhysicalTotal SIZE_T
	PhysicalAvailable SIZE_T
	SystemCache SIZE_T
	KernelTotal SIZE_T
	KernelPaged SIZE_T
	KernelNonpaged SIZE_T
	PageSize SIZE_T
	HandleCount DD
	ProcessCount DD
	ThreadCount DD
ENDS

ENUM_PAGE_FILE_INFORMATION STRUCT
	cb DD
	Reserved DD
	TotalSize SIZE_T
	TotalInUse SIZE_T
	PeakUsage SIZE_T
ENDS



PSAPI_WORKING_SET_BLOCK UNION
	Flags ULONG_PTR
    STRUCT
		Protection ULONG_PTR
		ShareCount ULONG_PTR
		Shared ULONG_PTR
		Reserved ULONG_PTR
		VirtualPage ULONG_PTR
	ENDS
ENDUNION

PSAPI_WORKING_SET_INFORMATION STRUCT
	NumberOfEntries ULONG_PTR
	WorkingSetInfo PSAPI_WORKING_SET_BLOCK
ENDS

PSAPI_WORKING_SET_EX_BLOCK UNION
	Flags ULONG_PTR
	STRUCT
		Valid ULONG_PTR
		ShareCount ULONG_PTR
		Win32Protection ULONG_PTR
		Shared ULONG_PTR
		Node ULONG_PTR
		Locked ULONG_PTR
		LargePage ULONG_PTR
	ENDS
ENDUNION

PSAPI_WORKING_SET_EX_INFORMATION STRUCT
	VirtualAddress PTR
	VirtualAttributes PSAPI_WORKING_SET_EX_BLOCK
ENDS


#IFDEF UNICODE
	#define GetModuleBaseName GetModuleBaseNameW
	#define GetModuleFileNameEx GetModuleFileNameExW
	#define GetMappedFileName GetMappedFileNameW
	#define GetDeviceDriverBaseName GetDeviceDriverBaseNameW
	#define GetDeviceDriverFileName GetDeviceDriverFileNameW
	#define EnumPageFiles EnumPageFilesW
	#define GetProcessImageFileName GetProcessImageFileNameW
#else
	#define GetModuleBaseName GetModuleBaseNameA
	#define GetModuleFileNameEx GetModuleFileNameExA
	#define GetMappedFileName GetMappedFileNameA
	#define GetDeviceDriverBaseName GetDeviceDriverBaseNameA
	#define GetDeviceDriverFileName GetDeviceDriverFileNameA
	#define EnumPageFiles EnumPageFilesA
	#define GetProcessImageFileName GetProcessImageFileNameA
#endif

#endif
