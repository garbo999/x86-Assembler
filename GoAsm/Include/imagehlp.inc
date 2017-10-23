;=============================================================;
;         imagehlp.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF IMAGEHLP_INC
#Define IMAGEHLP_INC

#Define CHECKSUM_SUCCESS                    0
#Define CHECKSUM_OPEN_FAILURE               1
#Define CHECKSUM_MAP_FAILURE                2
#Define CHECKSUM_MAPVIEW_FAILURE            3
#Define CHECKSUM_UNICODE_FAILURE            4

#Define SPLITSYM_REMOVE_PRIVATE             000000001H
#Define SPLITSYM_EXTRACT_ALL                000000002H
#Define SPLITSYM_SYMBOLPATH_IS_SRC          000000004H

;IMAGEHLP_STATUS_REASON enumeration
#Define BindOutOfMemory                     0
#Define BindRvaToVaFailed                   1
#Define BindNoRoomInImage                   2
#Define BindImportModuleFailed              3
#Define BindImportProcedureFailed           4
#Define BindImportModule                    5
#Define BindImportProcedure                 6
#Define BindForwarder                       7
#Define BindForwarderNOT                    8
#Define BindImageModified                   9
#Define BindExpandFileHeaders               10
#Define BindImageComplete                   11
#Define BindMismatchedSymbols               12
#Define BindSymbolsNotUpdated               13

#Define BIND_NO_BOUND_IMPORTS               000000001H
#Define BIND_NO_UPDATE                      000000002H
#Define BIND_ALL_IMAGES                     000000004H
#Define BIND_CACHE_IMPORT_DLLS              000000008H

#Define IMAGE_SEPARATION                    (64 * 1024)

#IFNDEF LIST_ENTRY
	LIST_ENTRY Struct
		Flink DD
		Blink DD
	EndS
#ENDIF

LOADED_IMAGE Struct
	ModuleName DD
	hFile DD
	MappedAddress DD
	FileHeader DD
	LastRvaSection DD
	NumberOfSections DD
	Sections DD
	Characteristics DD
	fSystemImage DD
	fDOSImage DD
	Links LIST_ENTRY <>
	SizeOfImage DD
EndS

IMAGE_DEBUG_INFORMATION Struct
	List LIST_ENTRY <>
	ReservedSize DD
	ReservedMappedBase DD
	ReservedMachine DW
	ReservedCharacteristics DW
	ReservedCheckSum DD
	ImageBase DD
	SizeOfImage DD
	ReservedNumberOfSections DD
	ReservedSections DD
	ReservedExportedNamesSize DD
    ReservedExportedNames DD
	ReservedNumberOfFunctionTableEntries DD
	ReservedFunctionTableEntries DD
	ReservedLowestFunctionStartingAddress DD
	ReservedHighestFunctionEndingAddress DD
	ReservedNumberOfFpoTableEntries DD
    ReservedFpoTableEntries DD
	SizeOfCoffSymbols DD
	CoffSymbols DD
	SizeOfCodeViewSymbols DD
	CodeViewSymbols DD
	ImageFilePath DD
	ImageFileName DD
	DebugFilePath DD
	TimeDateStamp DD
	RomImage DD
	DebugDirectory DD
	NumberOfDebugDirectories DD
	Reserved DD 3 Dup ?
EndS

#Define UNDNAME_COMPLETE                    (00000H)
#Define UNDNAME_NO_LEADING_UNDERSCORES      (00001H)
#Define UNDNAME_NO_MS_KEYWORDS              (00002H)
#Define UNDNAME_NO_FUNCTION_RETURNS         (00004H)
#Define UNDNAME_NO_ALLOCATION_MODEL         (00008H)
#Define UNDNAME_NO_ALLOCATION_LANGUAGE      (00010H)
#Define UNDNAME_NO_MS_THISTYPE              (00020H)
#Define UNDNAME_NO_CV_THISTYPE              (00040H)
#Define UNDNAME_NO_THISTYPE                 (00060H)
#Define UNDNAME_NO_ACCESS_SPECIFIERS        (00080H)
#Define UNDNAME_NO_THROW_SIGNATURES         (00100H)
#Define UNDNAME_NO_MEMBER_TYPE              (00200H)
#Define UNDNAME_NO_RETURN_UDT_MODEL         (00400H)
#Define UNDNAME_32_BIT_DECODE               (00800H)
#Define UNDNAME_NAME_ONLY                   (01000H)

#Define UNDNAME_NO_ARGUMENTS                (02000H)
#Define UNDNAME_NO_SPECIAL_SYMS             (04000H)

;ADDRESS_MODE enumeration
#Define AddrMode1616                        0
#Define AddrMode1632                        1
#Define AddrModeReal                        2
#Define AddrModeFlat                        3

ADDRESS Struct
	Offset DQ
	Segment DW
	Mode DD
EndS

KDHELP Struct
	Thread DD
	ThCallbackStack DD
	NextCallback DD
	FramePointer DD
	KiCallUserMode DD
	KeUserCallbackDispatcher DD
	SystemRangeStart DD
EndS

STACKFRAME Struct
	AddrPC ADDRESS <>
	AddrReturn ADDRESS <>
	AddrFrame ADDRESS <>
	AddrStack ADDRESS <>
	FuncTableEntry DD
	Params DD 4 Dup ?
	Far DD
	Virtual DD
	Reserved DD 3 Dup ?
	KdHelp KDHELP <>
EndS

#Define API_VERSION_NUMBER                  7

API_VERSION Struct
	MajorVersion DW
	MinorVersion DW
	Revision DW
	Reserved DW
EndS

#Define SYMF_OMAP_GENERATED                 000000001H
#Define SYMF_OMAP_MODIFIED                  000000002H

;SYM_TYPE enumeration
#Define SymNone                             0
#Define SymCoff                             1
#Define SymCv                               2
#Define SymPdb                              3
#Define SymExport                           4
#Define SymDeferred                         5
#Define SymSym                              6

IMAGEHLP_SYMBOL Struct
	SizeOfStruct DD
	Address DD
	Size DD
	Flags DD
	MaxNameLength DD
	Name DB
EndS

IMAGEHLP_MODULE Struct
	SizeOfStruct DD
	BaseOfImage DD
	ImageSize DD
	TimeDateStamp DD
	CheckSum DD
	NumSyms DD
	SymType DD
	ModuleName DB 32 Dup ?
	ImageName DB 256 Dup ?
	LoadedImageName DB 256 Dup ?
EndS

IMAGEHLP_LINE Struct
	SizeOfStruct DD
	Key DD
	LineNumber DD
	FileName DD
	Address DD
EndS

#Define CBA_DEFERRED_SYMBOL_LOAD_START      000000001H
#Define CBA_DEFERRED_SYMBOL_LOAD_COMPLETE   000000002H
#Define CBA_DEFERRED_SYMBOL_LOAD_FAILURE    000000003H
#Define CBA_SYMBOLS_UNLOADED                000000004H
#Define CBA_DUPLICATE_SYMBOL                000000005H

IMAGEHLP_DEFERRED_SYMBOL_LOAD Struct
	SizeOfStruct DD
	BaseOfImage DD
	CheckSum DD
	TimeDateStamp DD
	FileName DB MAX_PATH Dup ?
	Reparse DD
EndS

IMAGEHLP_DUPLICATE_SYMBOL Struct
	SizeOfStruct DD
	NumberOfDups DD
	Symbol DD
	SelectedSymbol DD
EndS

#Define SYMOPT_CASE_INSENSITIVE             000000001H
#Define SYMOPT_UNDNAME                      000000002H
#Define SYMOPT_DEFERRED_LOADS               000000004H
#Define SYMOPT_NO_CPP                       000000008H
#Define SYMOPT_LOAD_LINES                   000000010H
#Define SYMOPT_OMAP_FIND_NEAREST            000000020H

#Define CERT_PE_IMAGE_DIGEST_DEBUG_INFO      001H
#Define CERT_PE_IMAGE_DIGEST_RESOURCES       002H
#Define CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO 004H
#Define CERT_PE_IMAGE_DIGEST_NON_PE_INFO     008H

#Define CERT_SECTION_TYPE_ANY               0FFH

#IF STRINGS UNICODE
	#Define MapFileAndCheckSum MapFileAndCheckSumW
#ELSE
	#Define MapFileAndCheckSum MapFileAndCheckSumA
#ENDIF

#ENDIF ;IMAGEHLP_INC
