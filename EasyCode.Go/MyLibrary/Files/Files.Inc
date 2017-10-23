#Define FILE_BEGIN	0
#Define FILE_CURRENT 1
#Define FILE_END 2

#Define PAGE_NOACCESS 1
#Define PAGE_READONLY 2
#Define PAGE_READWRITE 4
#Define PAGE_WRITECOPY 8
#Define PAGE_EXECUTE 10h
#Define PAGE_EXECUTE_READ 20h
#Define PAGE_EXECUTE_READWRITE 40h
#Define PAGE_EXECUTE_WRITECOPY 80h
#Define PAGE_GUARD 100h
#Define PAGE_NOCACHE 200h

#Define HEAP_ZERO_MEMORY 00000008h

#Define MEM_COMMIT 1000h
#Define MEM_RELEASE 8000h

#Define NULL 0
#Define FALSE 0

#Define CREATE_NEW 1
#Define CREATE_ALWAYS 2
#Define OPEN_EXISTING 3
#Define OPEN_ALWAYS 4

#Define INVALID_HANDLE_VALUE -1
#Define MAX_PATH 260
#Define FILE_ATTRIBUTE_DIRECTORY 10h

#Define GENERIC_READ 080000000h
#Define FILE_SHARE_READ 1h

#Define SECTION_QUERY 1h
#Define SECTION_MAP_WRITE 2h
#Define SECTION_MAP_READ 4h
#Define SECTION_MAP_EXECUTE 8h
#Define SECTION_EXTEND_SIZE 10h
#Define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SECTION_QUERY | SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_SIZE)
#Define FILE_MAP_COPY SECTION_QUERY
#Define FILE_MAP_WRITE SECTION_MAP_WRITE
#Define FILE_MAP_READ SECTION_MAP_READ
#Define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#Define MAX_MODULE_NAME32 255

FILETIME STRUCT
  dwLowDateTime     DD
  dwHighDateTime    DD
FILETIME ENDS

WIN32_FIND_DATA STRUCT
  dwFileAttributes      DD
  ftCreationTime        FILETIME         <0>
  ftLastAccessTime      FILETIME         <0>
  ftLastWriteTime       FILETIME         <0>
  nFileSizeHigh         DD
  nFileSizeLow          DD
  dwReserved0           DD
  dwReserved1           DD
  cFileName             DB MAX_PATH dup 0
  cAlternate            DB 14 dup 0
ENDS

BY_HANDLE_FILE_INFORMATION STRUCT
  dwFileAttributes      DD
  ftCreationTime        FILETIME         <0>
  ftLastAccessTime      FILETIME         <0>
  ftLastWriteTime       FILETIME         <0>
  dwVolumeSerialNumber  DD
  nFileSizeHigh         DD
  nFileSizeLow          DD
  nNumberOfLinks        DD
  nFileIndexHigh        DD
  nFileIndexLow         DD
ENDS

VS_FIXEDFILEINFO STRUCT
  dwSignature           DD
  dwStrucVersion        DD
  dwFileVersionMS       DD
  dwFileVersionLS       DD
  dwProductVersionMS    DD
  dwProductVersionLS    DD
  dwFileFlagsMask       DD
  dwFileFlags           DD
  dwFileOS              DD
  dwFileType            DD
  dwFileSubtype         DD
  dwFileDateMS          DD
  dwFileDateLS          DD
ENDS

#Define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16
#Define IMAGE_SIZEOF_SHORT_NAME 8
#Define IMAGE_ORDINAL_FLAG32 80000000h

IMAGE_IMPORT_BY_NAME STRUCT
    Hint dw
    Name1 db
ENDS

IMAGE_IMPORT_DESCRIPTOR STRUCT
	OriginalFirstThunk	dd	?
	TimeDateStamp		dd	?
	ForwarderChain		dd	?
	Name1				dd	?
	FirstThunk			dd	?
ENDS

IMAGE_DOS_HEADER STRUCT
  e_magic           DW
  e_cblp            DW
  e_cp              DW
  e_crlc            DW
  e_cparhdr         DW
  e_minalloc        DW
  e_maxalloc        DW
  e_ss              DW
  e_sp              DW
  e_csum            DW
  e_ip              DW
  e_cs              DW
  e_lfarlc          DW
  e_ovno            DW
  e_res             DW   4 dup 0
  e_oemid           DW
  e_oeminfo         DW
  e_res2            DW  10 dup 0
  e_lfanew          DD
IMAGE_DOS_HEADER ENDS

IMAGE_OPTIONAL_HEADER32 STRUCT
  Magic                         DW
  MajorLinkerVersion            DB
  MinorLinkerVersion            DB
  SizeOfCode                    DD
  SizeOfInitializedData         DD
  SizeOfUninitializedData       DD
  AddressOfEntryPoint           DD
  BaseOfCode                    DD
  BaseOfData                    DD
  ImageBase                     DD
  SectionAlignment              DD
  FileAlignment                 DD
  MajorOperatingSystemVersion   DW
  MinorOperatingSystemVersion   DW
  MajorImageVersion             DW
  MinorImageVersion             DW
  MajorSubsystemVersion         DW
  MinorSubsystemVersion         DW
  Win32VersionValue             DD
  SizeOfImage                   DD
  SizeOfHeaders                 DD
  CheckSum                      DD
  Subsystem                     DW
  DllCharacteristics            DW
  SizeOfStackReserve            DD
  SizeOfStackCommit             DD
  SizeOfHeapReserve             DD
  SizeOfHeapCommit              DD
  LoaderFlags                   DD
  NumberOfRvaAndSizes           DD
  DataDirectory                 DQ IMAGE_NUMBEROF_DIRECTORY_ENTRIES dup
IMAGE_OPTIONAL_HEADER32 ENDS

#Define IMAGE_OPTIONAL_HEADER  IMAGE_OPTIONAL_HEADER32

IMAGE_FILE_HEADER STRUCT
  Machine               DW
  NumberOfSections      DW
  TimeDateStamp         DD
  PointerToSymbolTable  DD
  NumberOfSymbols       DD
  SizeOfOptionalHeader  DW
  Characteristics       DW
IMAGE_FILE_HEADER ENDS

IMAGE_SECTION_HEADER struct  
	Name					DB	IMAGE_SIZEOF_SHORT_NAME DUP (?)
	PhysicalAddress			DD	?
	VirtualAddress			DD	?
	SizeOfRawData			DD	?
	PointerToRawData		DD	?
	PointerToRelocations	DD	?
	PointerToLinenumbers	DD	?
	NumberOfRelocations		DW	?
	NumberOfLinenumbers		DW	?
	Characteristics			DD	?
ENDS

IMAGE_NT_HEADERS STRUCT
  Signature         DD
  FileHeader        IMAGE_FILE_HEADER         <>
  OptionalHeader    IMAGE_OPTIONAL_HEADER32   <>
ENDS

IMAGE_EXPORT_DIRECTORY STRUCT
  Characteristics           DD
  TimeDateStamp             DD
  MajorVersion              DW
  MinorVersion              DW
  nName                     DD
  nBase                     DD
  NumberOfFunctions         DD
  NumberOfNames             DD
  AddressOfFunctions        DD
  AddressOfNames            DD
  AddressOfNameOrdinals     DD
IMAGE_EXPORT_DIRECTORY ENDS
