#ifndef TLHELP32_H
#define TLHELP32_H

/* Windows Tool Help definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Kernel32.dll
#ENDIF

#define MAX_MODULE_NAME32  255

#define TH32CS_SNAPHEAPLIST 0x00000001
#define TH32CS_SNAPPROCESS  0x00000002
#define TH32CS_SNAPTHREAD  0x00000004
#define TH32CS_SNAPMODULE  0x00000008
#define TH32CS_SNAPALL  (TH32CS_SNAPHEAPLIST|TH32CS_SNAPPROCESS|TH32CS_SNAPTHREAD|TH32CS_SNAPMODULE)
#define TH32CS_INHERIT  0x80000000

#define HF32_DEFAULT  1
#define HF32_SHARED  2

#define LF32_FIXED  0x00000001
#define LF32_FREE  0x00000002
#define LF32_MOVEABLE 0x00000004

HEAPLIST32 STRUCT
	dwSize SIZE_T
	th32ProcessID DD
	th32HeapID ULONG_PTR
	dwFlags DD
ENDS

HEAPENTRY32 STRUCT
	dwSize SIZE_T
	hHandle HANDLE
	dwAddress ULONG_PTR
	dwBlockSize SIZE_T
	dwFlags DD
	dwLockCount DD
	dwResvd DD
	th32ProcessID DD
	th32HeapID ULONG_PTR
ENDS

PROCESSENTRY32W STRUCT
	dwSize DD
	cntUsage DD
	th32ProcessID DD
	th32DefaultHeapID ULONG_PTR
	th32ModuleID DD
	cntThreads DD
	th32ParentProcessID DD
	pcPriClassBase DD
	dwFlags DD
	szExeFile DW MAX_PATH DUP (?)
ENDS

PROCESSENTRY32A STRUCT
	dwSize DD
	cntUsage DD
	th32ProcessID DD
	th32DefaultHeapID ULONG_PTR
	th32ModuleID DD
	cntThreads DD
	th32ParentProcessID DD
	pcPriClassBase DD
	dwFlags DD
	szExeFile DB MAX_PATH DUP (?)
ENDS

THREADENTRY32 STRUCT
	dwSize DD
	cntUsage DD
	th32ThreadID DD
	th32OwnerProcessID DD
	tpBasePri DD
	tpDeltaPri DD
	dwFlags DD
ENDS

MODULEENTRY32W STRUCT
	dwSize DD
	th32ModuleID DD
	th32ProcessID DD
	GlblcntUsage DD
	ProccntUsage DD
	modBaseAddr PTR
	modBaseSize DD
	hModule HANDLE
	szModule DW MAX_MODULE_NAME32+1 DUP (?)
	szExePath DW MAX_PATH DUP (?)
ENDS

MODULEENTRY32A STRUCT
	dwSize DD
	th32ModuleID DD
	th32ProcessID DD
	GlblcntUsage DD
	ProccntUsage DD
	modBaseAddr PTR
	modBaseSize DD
	hModule HANDLE
	szModule DB MAX_MODULE_NAME32+1 DUP (?)
	szExePath DB MAX_PATH DUP (?)
ENDS

#IFDEF UNICODE
	#define Process32First Process32FirstW
	#define Process32Next Process32NextW
	#define Module32First Module32FirstW
	#define Module32Next Module32NextW
	#define PROCESSENTRY32 PROCESSENTRY32W
	#define MODULEENTRY32 MODULEENTRY32W
#ELSE
	#define PROCESSENTRY32 PROCESSENTRY32A
	#define MODULEENTRY32 MODULEENTRY32A
#endif

#endif /* _TLHELP32_H */
