#ifndef IMAGEHLP_H
#define IMAGEHLP_H

#DEFINE IMAGEHLP_H_REQVER 100

// cvconst.h has not been translated yet
#DEFINE NO_CVCONST_H

/* Windows Image help definitions */

/*
Dependancies
wintrust.h
*/

#IFDEF LINKFILES
	#dynamiclinkfile Dbghelp.dll
	#dynamiclinkfile imagehlp.dll
#ENDIF

/*
Switches
X64
*/

#ifdef X64
	#ifndef IMAGEHLP64
		#define IMAGEHLP64
	#endif
#endif

#ifdef IA64
	#ifndef IMAGEHLP64
		#define IMAGEHLP64
	#endif
#endif

#IFNDEF WINTRUST_H
	#include wintrust.h
#ENDIF

#IFNDEF LIST_ENTRY
	LIST_ENTRY STRUCT
		Flink DD
		Blink DD
	ENDS
#ENDIF

#define IMAGE_SEPARATION  (64*1024)

#define BIND_NO_BOUND_IMPORTS  0x00000001
#define BIND_NO_UPDATE  0x00000002
#define BIND_ALL_IMAGES  0x00000004
#define BIND_CACHE_IMPORT_DLLS  0x00000008

#define CHECKSUM_SUCCESS  0
#define CHECKSUM_OPEN_FAILURE  1
#define CHECKSUM_MAP_FAILURE  2
#define CHECKSUM_MAPVIEW_FAILURE  3
#define CHECKSUM_UNICODE_FAILURE  4

#define SPLITSYM_REMOVE_PRIVATE  0x00000001
#define SPLITSYM_EXTRACT_ALL  0x00000002
#define SPLITSYM_SYMBOLPATH_IS_SRC  0x00000004

#define CERT_PE_IMAGE_DIGEST_DEBUG_INFO  0x01
#define CERT_PE_IMAGE_DIGEST_RESOURCES  0x02
#define CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO  0x04
#define CERT_PE_IMAGE_DIGEST_NON_PE_INFO  0x08

#define CERT_SECTION_TYPE_ANY  0xFF

#define UNDNAME_COMPLETE  0x0000
#define UNDNAME_NO_LEADING_UNDERSCORES  0x0001
#define UNDNAME_NO_MS_KEYWORDS  0x0002
#define UNDNAME_NO_FUNCTION_RETURNS  0x0004
#define UNDNAME_NO_ALLOCATION_MODEL  0x0008
#define UNDNAME_NO_ALLOCATION_LANGUAGE  0x0010
#define UNDNAME_NO_MS_THISTYPE  0x0020
#define UNDNAME_NO_CV_THISTYPE  0x0040
#define UNDNAME_NO_THISTYPE  0x0060
#define UNDNAME_NO_ACCESS_SPECIFIERS  0x0080
#define UNDNAME_NO_THROW_SIGNATURES  0x0100
#define UNDNAME_NO_MEMBER_TYPE  0x0200
#define UNDNAME_NO_RETURN_UDT_MODEL  0x0400
#define UNDNAME_32_BIT_DECODE  0x0800
#define UNDNAME_NAME_ONLY  0x1000
#define UNDNAME_NO_ARGUMENTS  0x2000
#define UNDNAME_NO_SPECIAL_SYMS  0x4000

#define API_VERSION_NUMBER  9

#define SYMF_OMAP_GENERATED  0x00000001
#define SYMF_OMAP_MODIFIED  0x00000002

#define CBA_DEFERRED_SYMBOL_LOAD_START          0x00000001
#define CBA_DEFERRED_SYMBOL_LOAD_COMPLETE       0x00000002
#define CBA_DEFERRED_SYMBOL_LOAD_FAILURE        0x00000003
#define CBA_SYMBOLS_UNLOADED                    0x00000004
#define CBA_DUPLICATE_SYMBOL                    0x00000005
#define CBA_READ_MEMORY                         0x00000006
#define CBA_DEFERRED_SYMBOL_LOAD_CANCEL         0x00000007
#define CBA_SET_OPTIONS                         0x00000008
#define CBA_EVENT                               0x00000010
#define CBA_DEFERRED_SYMBOL_LOAD_PARTIAL        0x00000020
#define CBA_DEBUG_INFO                          0x10000000

#define SYMOPT_CASE_INSENSITIVE         0x00000001
#define SYMOPT_UNDNAME                  0x00000002
#define SYMOPT_DEFERRED_LOADS           0x00000004
#define SYMOPT_NO_CPP                   0x00000008
#define SYMOPT_LOAD_LINES               0x00000010
#define SYMOPT_OMAP_FIND_NEAREST        0x00000020
#define SYMOPT_LOAD_ANYTHING            0x00000040
#define SYMOPT_IGNORE_CVREC             0x00000080
#define SYMOPT_NO_UNQUALIFIED_LOADS     0x00000100
#define SYMOPT_FAIL_CRITICAL_ERRORS     0x00000200
#define SYMOPT_EXACT_SYMBOLS            0x00000400
#define SYMOPT_ALLOW_ABSOLUTE_SYMBOLS   0x00000800
#define SYMOPT_IGNORE_NT_SYMPATH        0x00001000
#define SYMOPT_INCLUDE_32BIT_MODULES    0x00002000
#define SYMOPT_PUBLICS_ONLY             0x00004000
#define SYMOPT_NO_PUBLICS               0x00008000
#define SYMOPT_AUTO_PUBLICS             0x00010000
#define SYMOPT_NO_IMAGE_SEARCH          0x00020000
#define SYMOPT_SECURE                   0x00040000
#define SYMOPT_NO_PROMPTS               0x00080000
#define SYMOPT_OVERWRITE                0x00100000
#define SYMOPT_IGNORE_IMAGEDIR          0x00200000
#define SYMOPT_FLAT_DIRECTORY           0x00400000
#define SYMOPT_FAVOR_COMPRESSED         0x00800000
#define SYMOPT_ALLOW_ZERO_ADDRESS       0x01000000

LOADED_IMAGE STRUCT
	ModuleName PTR
	hFile HANDLE
	MappedAddress PTR
	FileHeader PTR
	LastRvaSection PTR
	NumberOfSections DD
	Sections PTR
	Characteristics DD
	fSystemImage DB
	fDOSImage DB
	fReadOnly DB
	Version DB
	Links LIST_ENTRY
	SizeOfImage DD
ENDS

#define BindRvaToVaFailed 1
#define BindNoRoomInImage 2
#define BindImportModuleFailed 3
#define BindImportProcedureFailed 4
#define BindImportModule 5
#define BindImportProcedure 6
#define BindForwarder 7
#define BindForwarderNOT 8
#define BindImageModified 9
#define BindExpandFileHeaders 10
#define BindImageComplete 11
#define BindMismatchedSymbols 12
#define BindSymbolsNotUpdated 13


#ifndef X64
/* wont be ported to Win64 */
// Note the pointers are defined as DWORDs since there is no 64 bit version
IMAGE_DEBUG_INFORMATION STRUCT
	List LIST_ENTRY
	Size DD
	MappedBase DD
	Machine DW
	Characteristics DW
	CheckSum DD
	ImageBase DD
	SizeOfImage DD
	NumberOfSections DD
	Sections DD
	ExportedNamesSize DD
	ExportedNames DD
	NumberOfFunctionTableEntries DD
	FunctionTableEntries DD
	LowestFunctionStartingAddress DD
	HighestFunctionEndingAddress DD
	NumberOfFpoTableEntries DD
	FpoTableEntries DD
	SizeOfCoffSymbols DD
	CoffSymbols DD
	SizeOfCodeViewSymbols DD
	CodeViewSymbols DD
	ImageFilePath DD
	ImageFileName DD
	ReservedDebugFilePath DD
	ReservedTimeDateStamp DD
	BOOL ReservedRomImage DD
	ReservedDebugDirectory DD
	ReservedNumberOfDebugDirectories DD
	ReservedOriginalFunctionTableBaseAddress DD
	Reserved DD 2 DUP 
ENDS
#endif

#define AddrMode1616 0
#define AddrMode1632 1
#define AddrModeReal 2
#define AddrModeFlat 3

ADDRESS64 STRUCT
	Offset DQ
	Segment DW
	Mode DD
ENDS

#ifdef IMAGEHLP64
	#define ADDRESS ADDRESS64
#else
	ADDRESS STRUCT
		Offset DD
		Segment DW
		Mode DD
	ENDS
#endif

KDHELP64 STRUCT
	Thread DQ
	ThCallbackStack DD
	ThCallbackBStore DD
	NextCallback DD
	FramePointer DD
	KiCallUserMode DQ
	KeUserCallbackDispatcher DQ
	SystemRangeStart DQ
	KiUserExceptionDispatcher DQ
	StackBase DQ
	StackLimit DQ
	Reserved DQ 5 DUP
ENDS

#ifdef IMAGEHLP64
	#define KDHELP KDHELP64
#else
	KDHELP STRUCT
		Thread DD
		ThCallbackStack DD
		ThCallbackBStore DD
		NextCallback DD
		FramePointer DD
		KiCallUserMode DD
		KeUserCallbackDispatcher DQ
		SystemRangeStart DD
		KiUserExceptionDispatcher DQ
		StackBase DD
		StackLimit DD
		Reserved DD 5 DUP
	ENDS
#endif

STACKFRAME64 STRUCT
	AddrPC ADDRESS64
	AddrReturn ADDRESS64
	AddrFrame ADDRESS64
	AddrStack ADDRESS64
	AddrBStore ADDRESS64
	FuncTableEntry DQ
	Params DQ 4 DUP
	Far DD
	Virtual DD
	Reserved DQ 3 DUP
	KdHelp KDHELP64
ENDS

#ifdef IMAGEHLP64
	#define STACKFRAME STACKFRAME64
#else
STACKFRAME STRUCT
	AddrPC ADDRESS
	AddrReturn ADDRESS
	AddrFrame ADDRESS
	AddrStack ADDRESS
	FuncTableEntry DD
	Params DD 4 DUP
	Far DD
	Virtual DD
	Reserved DD 3 DUP
	KdHelp KDHELP
	AddrBStore ADDRESS
ENDS
#endif

API_VERSION STRUCT
	MajorVersion DW
	MinorVersion DW
	Revision DW
	Reserved DW
ENDS

#ifdef NO_CVCONST_H
	SymTagNull = 0
	SymTagExe = 1
	SymTagCompiland = 2
	SymTagCompilandDetails = 3
	SymTagCompilandEnv = 4
	SymTagFunction = 5
	SymTagBlock = 6
	SymTagData = 7
	SymTagAnnotation = 8
	SymTagLabel = 9
	SymTagPublicSymbol = 10
	SymTagUDT = 11
	SymTagEnum = 12
	SymTagFunctionType = 13
	SymTagPointerType = 14
	SymTagArrayType = 15
	SymTagBaseType = 16
	SymTagTypedef = 17
	SymTagBaseClass = 18
	SymTagFriend = 19
	SymTagFunctionArgType = 20
	SymTagFuncDebugStart = 21
	SymTagFuncDebugEnd = 22
	SymTagUsingNamespace = 23
	SymTagVTableShape = 24
	SymTagVTable = 25
	SymTagCustom = 26
	SymTagThunk = 27
	SymTagCustomType = 28
	SymTagManagedType = 29
	SymTagDimension = 30
	SymTagMax = 31
#endif

//
// flags found in SYMBOL_INFO.Flags
//

#define SYMFLAG_VALUEPRESENT     0x00000001
#define SYMFLAG_REGISTER         0x00000008
#define SYMFLAG_REGREL           0x00000010
#define SYMFLAG_FRAMEREL         0x00000020
#define SYMFLAG_PARAMETER        0x00000040
#define SYMFLAG_LOCAL            0x00000080
#define SYMFLAG_CONSTANT         0x00000100
#define SYMFLAG_EXPORT           0x00000200
#define SYMFLAG_FORWARDER        0x00000400
#define SYMFLAG_FUNCTION         0x00000800
#define SYMFLAG_VIRTUAL          0x00001000
#define SYMFLAG_THUNK            0x00002000
#define SYMFLAG_TLSREL           0x00004000
#define SYMFLAG_SLOT             0x00008000
#define SYMFLAG_ILREL            0x00010000
#define SYMFLAG_METADATA         0x00020000
#define SYMFLAG_CLR_TOKEN        0x00040000

// this resets SymNext/Prev to the beginning
// of the module passed in the address field

#define SYMFLAG_RESET            0x80000000  

SymNone = 0
SymCoff = 1
SymCv = 2
SymPdb = 3
SymExport = 4
SymDeferred = 5
SymSym = 6
SymDia = 7
SymVirtual = 8
NumSymTypes = 9

IMAGEHLP_SYMBOL64 STRUCT
	SizeOfStruct DD
	Address DQ
	Size DD
	Flags DD
	MaxNameLength DD
	Name DB
ENDS

IMAGEHLP_SYMBOL64_PACKAGE STRUCT
	sym IMAGEHLP_SYMBOL64
	name DB MAX_SYM_NAME+1 DUP
ENDS

IMAGEHLP_SYMBOLW64 STRUCT
	SizeOfStruct DD
	Address DQ
	Size DD
	Flags DD
	MaxNameLength DD
	Name DB
ENDS

IMAGEHLP_SYMBOLW64_PACKAGE STRUCT
	sym IMAGEHLP_SYMBOL64
	name DW MAX_SYM_NAME+1 DUP
ENDS

#ifdef IMAGEHLP64
	#define IMAGEHLP_SYMBOL IMAGEHLP_SYMBOL64
	#define IMAGEHLP_SYMBOL_PACKAGE IMAGEHLP_SYMBOL64_PACKAGE
	#define IMAGEHLP_SYMBOLW IMAGEHLP_SYMBOLW64
	#define IMAGEHLP_SYMBOLW_PACKAGE IMAGEHLP_SYMBOLW64_PACKAGE
#else
	IMAGEHLP_SYMBOL STRUCT
		SizeOfStruct DD
		Address DD
		Size DD
		Flags DD
		MaxNameLength DD
		Name DB
	ENDS
	
#endif

IMAGEHLP_MODULE64 STRUCT
	SizeOfStruct DD            // set to sizeof(IMAGEHLP_MODULE64)
	BaseOfImage DQ             // base load address of module
	ImageSize DD               // virtual size of the loaded module
	TimeDateStamp DD           // date/time stamp from pe header
	CheckSum DD                // checksum from the pe header
	NumSyms DD                 // number of symbols in the symbol table
	SymType DD                 // type of symbols loaded
	ModuleName DB 32 DUP       // module name
	ImageName DB 256 DUP       // image name
	LoadedImageName DB 256 DUP // symbol file name
    // new elements: 07-Jun-2002
	LoadedPdbName DB 256 DUP   // pdb file name
	CVSig DD                   // Signature of the CV record in the debug directories
	CVData DB MAX_PATH*3 DUP   // Contents of the CV record
	PdbSig DD                  // Signature of PDB
	PdbSig70 GUID              // Signature of PDB (VC 7 and up)
	PdbAge DD                  // DBI age of pdb
	PdbUnmatched DD            // loaded an unmatched pdb
	DbgUnmatched DD            // loaded an unmatched dbg
	LineNumbers DD             // we have line number information
	GlobalSymbols DD           // we have internal symbol information
	TypeInfo DD                // we have type information
    // new elements: 17-Dec-2003
	SourceIndexed DD           // pdb supports source server
	Publics DD                 // contains public symbols
ENDS

IMAGEHLP_MODULEW64 STRUCT
	SizeOfStruct DD            // set to sizeof(IMAGEHLP_MODULE64)
	BaseOfImage DQ             // base load address of module
	ImageSize DD               // virtual size of the loaded module
	TimeDateStamp DD           // date/time stamp from pe header
	CheckSum DD                // checksum from the pe header
	NumSyms DD                 // number of symbols in the symbol table
	SymType DD                 // type of symbols loaded
	ModuleName DW 32 DUP       // module name
	ImageName DW 256 DUP       // image name
	LoadedImageName DW 256 DUP // symbol file name
    // new elements: 07-Jun-2002
	LoadedPdbName DW 256 DUP   // pdb file name
	CVSig DD                   // Signature of the CV record in the debug directories
	CVData DW MAX_PATH*3 DUP   // Contents of the CV record
	PdbSig DD                  // Signature of PDB
	PdbSig70 GUID              // Signature of PDB (VC 7 and up)
	PdbAge DD                  // DBI age of pdb
	PdbUnmatched DD            // loaded an unmatched pdb
	DbgUnmatched DD            // loaded an unmatched dbg
	LineNumbers DD             // we have line number information
	GlobalSymbols DD           // we have internal symbol information
	TypeInfo DD                // we have type information
    // new elements: 17-Dec-2003
	SourceIndexed DD           // pdb supports source server
	Publics DD                 // contains public symbols
ENDS

#ifdef IMAGEHLP64
	#define IMAGEHLP_MODULE IMAGEHLP_MODULE64
	#define IMAGEHLP_MODULEW IMAGEHLP_MODULEW64
#else
	IMAGEHLP_MODULE STRUCT
		SizeOfStruct DD
		BaseOfImage DD
		ImageSize DD
		TimeDateStamp DD
		CheckSum DD
		NumSyms DD
		SymType DD
		ModuleName DB 32 DUP
		ImageName DB 256 DUP
		LoadedImageName DB 256 DUP
	ENDS
	
	IMAGEHLP_MODULEW STRUCT
		SizeOfStruct DD
		BaseOfImage DD
		ImageSize DD
		TimeDateStamp DD
		CheckSum DD
		NumSyms DD
		SymType DD
		ModuleName DW 32 DUP
		ImageName DW 256 DUP
		LoadedImageName DW 256 DUP
	ENDS
#endif

IMAGEHLP_LINE64 STRUCT
	SizeOfStruct DD
	Key DQ
	LineNumber DD
	FileName DQ
	Address DQ
ENDS

#DEFINE IMAGEHLP_LINEW64 IMAGEHLP_LINE64

#ifdef IMAGEHLP64
	#define IMAGEHLP_LINE IMAGEHLP_LINE64
#else
	IMAGEHLP_LINE STRUCT
		SizeOfStruct DD
		Key DD
		LineNumber DD
		FileName DD
		Address DD
	ENDS
	#define IMAGEHLP_LINEW IMAGEHLP_LINE
#endif

SOURCEFILE STRUCT
	ModBase DQ
	FileName PTR
ENDS

#DEFINE SOURCEFILEW SOURCEFILE

IMAGEHLP_CBA_READ_MEMORY STRUCT
	addr DQ
	buf PTR
	bytes DD
	bytesread DD
ENDS

sevInfo = 0
sevProblem = 1
sevAttn = 2
sevFatal = 3
sevMax = 4

#define EVENT_SRCSPEW_START 100
#define EVENT_SRCSPEW       100
#define EVENT_SRCSPEW_END   199

IMAGEHLP_CBA_EVENT STRUCT
	severity DD
	code DD
	desc PTR
	object PTR
ENDS

#DEFINE IMAGEHLP_CBA_EVENTW IMAGEHLP_CBA_EVENT

IMAGEHLP_DEFERRED_SYMBOL_LOAD64 STRUCT
	SizeOfStruct DD
	BaseOfImage DQ
	CheckSum DD
	TimeDateStamp DD
	FileName DB MAX_PATH DUP
	Reparse DB
	hFile HANDLE
	Flags DD
ENDS

#define DSLFLAG_MISMATCHED_PDB  0x1
#define DSLFLAG_MISMATCHED_DBG  0x2

#ifdef IMAGEHLP64
	#define IMAGEHLP_DEFERRED_SYMBOL_LOAD IMAGEHLP_DEFERRED_SYMBOL_LOAD64
#else
	IMAGEHLP_DEFERRED_SYMBOL_LOAD STRUCT
		SizeOfStruct DD
		BaseOfImage DD
		CheckSum DD
		TimeDateStamp DD
		FileName DB MAX_PATH DUP
		Reparse DB
		hFile HANDLE
	ENDS
#endif

IMAGEHLP_DUPLICATE_SYMBOL64 STRUCT
	SizeOfStruct DD
	NumberOfDups DD
	Symbol PTR
	SelectedSymbol DD
ENDS

#ifdef IMAGEHLP64
	#define IMAGEHLP_DUPLICATE_SYMBOL IMAGEHLP_DUPLICATE_SYMBOL64
#else
	IMAGEHLP_DUPLICATE_SYMBOL STRUCT
		SizeOfStruct DD
		NumberOfDups DD
		Symbol PTR
		SelectedSymbol DD
	ENDS
#endif

hdBase = 0
hdSym = 1
hdSrc = 2
hdMax = 3

IMAGEHLP_TYPEID_INDEX = 1
IMAGEHLP_TYPEID_NAME = 2
IMAGEHLP_TYPEID_IMAGEHLP_SYMBOL = 3
IMAGEHLP_TYPEID_IMAGEHLP_SYMBOL64 = 4
IMAGEHLP_TYPEID_MODULE_TYPE_INFO = 5
IMAGEHLP_TYPEID_TYPE_ENUM_INFO = 6

#define ESLFLAG_FULLPATH        0x1
#define ESLFLAG_NEAREST         0x2
#define ESLFLAG_PREV            0x4
#define ESLFLAG_NEXT            0x8

#define SLMFLAG_VIRTUAL     0x1
#define SLMFLAG_ALT_INDEX   0x2
#define SLMFLAG_NO_SYMBOLS  0x4

IMAGEHLP_SYMBOL_SRC STRUCT
	sizeofstruct DD
	type DD
	file DB MAX_PATH DUP
ENDS

MODULE_TYPE_INFO STRUCT
	dataLength DW
	leaf DW
	data DB
ENDS

TYPE_ENUM_INFO STRUCT
	CallerData DD
	CallbackRoutine DD
ENDS

SYMBOL_INFO STRUCT
	SizeOfStruct DD
	TypeIndex DD
	Reserved DQ 2 DUP
	Index DD
	Size DD
	ModBase DQ
	Flags DD
	Value DQ
	Address DQ
	Register DD
	Scope DD
	Tag DD
	NameLen DD
	MaxNameLen DD
	Name DB
ENDS

SYMBOL_INFO_PACKAGE STRUCT
	si SYMBOL_INFO
	name DB MAX_SYM_NAME+1 DUP
ENDS

SYMBOL_INFOW STRUCT
	SizeOfStruct DD
	TypeIndex DD
	Reserved DQ 2 DUP
	Index DD
	Size DD
	ModBase DQ
	Flags DD
	Value DQ
	Address DQ
	Register DD
	Scope DD
	Tag DD
	NameLen DD
	MaxNameLen DD
	Name DW
ENDS

SYMBOL_INFO_PACKAGEW STRUCT
	si SYMBOL_INFOW
	name DW MAX_SYM_NAME+1 DUP
ENDS

IMAGEHLP_STACK_FRAME STRUCT
	InstructionOffset DQ
	ReturnOffset DQ
	FrameOffset DQ
	StackOffset DQ
	BackingStoreOffset DQ
	FuncTableEntry DQ
	Params DQ 4 DUP
	Reserved DQ 5 DUP
	Virtual DD
	Reserved2 DD
ENDS

#define SYMSEARCH_MASKOBJS      0x01    // used internally to implement other APIs
#define SYMSEARCH_RECURSE       0X02    // recurse scopes
#define SYMSEARCH_GLOBALSONLY   0X04    // search only for global symbols

TI_GET_SYMTAG = 0
TI_GET_SYMNAME = 1
TI_GET_LENGTH = 2
TI_GET_TYPE = 3
TI_GET_TYPEID = 4
TI_GET_BASETYPE = 5
TI_GET_ARRAYINDEXTYPEID = 6
TI_FINDCHILDREN = 7
TI_GET_DATAKIND = 8
TI_GET_ADDRESSOFFSET = 9
TI_GET_OFFSET = 10
TI_GET_VALUE = 11
TI_GET_COUNT = 12
TI_GET_CHILDRENCOUNT = 13
TI_GET_BITPOSITION = 14
TI_GET_VIRTUALBASECLASS = 15
TI_GET_VIRTUALTABLESHAPEID = 16
TI_GET_VIRTUALBASEPOINTEROFFSET = 17
TI_GET_CLASSPARENTID = 18
TI_GET_NESTED = 19
TI_GET_SYMINDEX = 20
TI_GET_LEXICALPARENT = 21
TI_GET_ADDRESS = 22
TI_GET_THISADJUST = 23
TI_GET_UDTKIND = 24
TI_IS_EQUIV_TO = 25
TI_GET_CALLING_CONVENTION = 26
TI_IS_CLOSE_EQUIV_TO = 27
TI_GTIEX_REQS_VALID = 28
TI_GET_VIRTUALBASEOFFSET = 29
TI_GET_VIRTUALBASEDISPINDEX = 30
TI_GET_IS_REFERENCE = 31
IMAGEHLP_SYMBOL_TYPE_INFO_MAX = 32

TI_FINDCHILDREN_PARAMS STRUCT
	Count DD
	Start DD
	ChildId DD
ENDS

#define IMAGEHLP_GET_TYPE_INFO_UNCACHED 0x00000001
#define IMAGEHLP_GET_TYPE_INFO_CHILDREN 0x00000002

IMAGEHLP_GET_TYPE_INFO_PARAMS STRUCT
	SizeOfStruct DD
	Flags DD
	NumIds DD
	TypeIds PTR
	TagFilter DQ
	NumReqs DD
	ReqKinds PTR
	ReqOffsets PTR
	ReqSizes PTR
	ReqStride ULONG_PTR
	BufferSize ULONG_PTR
	Buffer PTR
	EntriesMatched DD
	EntriesFilled DD
	TagsFound DQ
	AllReqsValid DQ
	NumReqsValid DD
	ReqsValid PTR
ENDS

sfImage = 0
sfDbg = 1
sfPdb = 2
sfMpd = 3
sfMax = 4

#define SYMSRV_VERSION              2

#define SSRVOPT_CALLBACK            0x000001
#define SSRVOPT_DWORD               0x000002
#define SSRVOPT_DWORDPTR            0x000004
#define SSRVOPT_GUIDPTR             0x000008
#define SSRVOPT_OLDGUIDPTR          0x000010
#define SSRVOPT_UNATTENDED          0x000020
#define SSRVOPT_NOCOPY              0x000040
#define SSRVOPT_GETPATH             0x000040
#define SSRVOPT_PARENTWIN           0x000080
#define SSRVOPT_PARAMTYPE           0x000100
#define SSRVOPT_SECURE              0x000200
#define SSRVOPT_TRACE               0x000400
#define SSRVOPT_SETCONTEXT          0x000800
#define SSRVOPT_PROXY               0x001000
#define SSRVOPT_DOWNSTREAM_STORE    0x002000
#define SSRVOPT_OVERWRITE           0x004000
#define SSRVOPT_RESETTOU            0x008000
#define SSRVOPT_CALLBACKW           0x010000
#define SSRVOPT_FLAT_DEFAULT_STORE  0x020000
#define SSRVOPT_PROXYW              0x040000
#define SSRVOPT_MESSAGE             0x080000
#define SSRVOPT_SERVICE             0x100000   // deprecated
#define SSRVOPT_FAVOR_COMPRESSED    0x200000  

#define SSRVOPT_MAX                 0x40000

#define SSRVOPT_RESET               -1


#define NUM_SSRVOPTS                30

#define SSRVACTION_TRACE        1
#define SSRVACTION_QUERYCANCEL  2
#define SSRVACTION_EVENT        3
#define SSRVACTION_EVENTW       4

#define SYMSTOREOPT_COMPRESS        0x01
#define SYMSTOREOPT_OVERWRITE       0x02
#define SYMSTOREOPT_RETURNINDEX     0x04
#define SYMSTOREOPT_POINTER         0x08
#define SYMSTOREOPT_ALT_INDEX       0x10
#define SYMSTOREOPT_UNICODE         0x20
#define SYMSTOREOPT_PASS_IF_EXISTS  0x40

#IFDEF DBGHELP_TRANSLATE_TCHAR
	#define SymInitialize                     SymInitializeW
	#define SymAddSymbol                      SymAddSymbolW
	#define SymDeleteSymbol                   SymDeleteSymbolW
	#define SearchTreeForFile                 SearchTreeForFileW
	#define UnDecorateSymbolName              UnDecorateSymbolNameW
	#define SymGetLineFromName64              SymGetLineFromNameW64
	#define SymGetLineFromAddr64              SymGetLineFromAddrW64
	#define SymGetLineNext64                  SymGetLineNextW64
	#define SymGetLinePrev64                  SymGetLinePrevW64
	#define SymFromName                       SymFromNameW
	#define SymFindExecutableImage            SymFindExecutableImageW
	#define FindExecutableImageEx             FindExecutableImageExW
	#define SymSearch                         SymSearchW
	#define SymEnumLines                      SymEnumLinesW
	#define SymEnumSourceLines                SymEnumSourceLinesW
	#define SymGetTypeFromName                SymGetTypeFromNameW
	#define SymEnumSymbolsForAddr             SymEnumSymbolsForAddrW
	#define SymFromAddr                       SymFromAddrW
	#define SymMatchString                    SymMatchStringW
	#define SymEnumSourceFiles                SymEnumSourceFilesW
	#define SymEnumSymbols                    SymEnumSymbolsW
	#define SymLoadModuleEx                   SymLoadModuleExW
	#define SymSetSearchPath                  SymSetSearchPathW
	#define SymGetSearchPath                  SymGetSearchPathW
	#define EnumDirTree                       EnumDirTreeW
	#define SymFromToken                      SymFromTokenW
	#define SymFromIndex                      SymFromIndexW
	#define SymGetScope                       SymGetScopeW
	#define SymNext                           SymNextW
	#define SymPrev                           SymPrevW
	#define SymEnumTypes                      SymEnumTypesW
	#define SymRegisterCallback64             SymRegisterCallbackW64
	#define SymFindDebugInfoFile              SymFindDebugInfoFileW
	#define FindDebugInfoFileEx               FindDebugInfoFileExW
	#define SymFindFileInPath                 SymFindFileInPathW
	#define SymEnumerateModules64             SymEnumerateModulesW64
	#define SymSetHomeDirectory               SymSetHomeDirectoryW
	#define SymGetHomeDirectory               SymGetHomeDirectoryW
	#define SymGetSourceFile                  SymGetSourceFileW
	#define SymGetSourceFileToken             SymGetSourceFileTokenW
	#define SymGetSourceFileFromToken         SymGetSourceFileFromTokenW
	#define SymGetSourceVarFromToken          SymGetSourceVarFromTokenW
	#define SymGetSourceFileToken             SymGetSourceFileTokenW
	#define SymGetFileLineOffsets64           SymGetFileLineOffsetsW64
	#define SymFindFileInPath                 SymFindFileInPathW
	#define SymMatchFileName                  SymMatchFileNameW
	#define SymGetSourceFileFromToken         SymGetSourceFileFromTokenW
	#define SymGetSourceVarFromToken          SymGetSourceVarFromTokenW
	#define SymGetModuleInfo64                SymGetModuleInfoW64
	#define SymSrvIsStore                     SymSrvIsStoreW
	#define SymSrvDeltaName                   SymSrvDeltaNameW
	#define SymSrvGetSupplement               SymSrvGetSupplementW
	#define SymSrvStoreSupplement             SymSrvStoreSupplementW
	#define SymSrvGetFileIndexes              SymSrvGetFileIndexes
	#define SymSrvGetFileIndexString          SymSrvGetFileIndexStringW
	#define SymSrvStoreFile                   SymSrvStoreFileW
	#define SymGetSymbolFile                  SymGetSymbolFileW
	#define EnumerateLoadedModules64          EnumerateLoadedModulesW64
	#define SymSrvGetFileIndexInfo            SymSrvGetFileIndexInfoW
	#define IMAGEHLP_LINE64                   IMAGEHLP_LINEW64
	#define SYMBOL_INFO                       SYMBOL_INFOW
	#define SYMBOL_INFO_PACKAGE               SYMBOL_INFO_PACKAGEW
	#define FIND_EXE_FILE_CALLBACK            FIND_EXE_FILE_CALLBACKW
	#define SYM_ENUMERATESYMBOLS_CALLBACK     SYM_ENUMERATESYMBOLS_CALLBACKW
	#define SRCCODEINFO                       SRCCODEINFOW
	#define SOURCEFILE                        SOURCEFILEW
	#define SYM_ENUMSOURECFILES_CALLBACK      SYM_ENUMSOURCEFILES_CALLBACKW
	#define IMAGEHLP_CBA_EVENT                IMAGEHLP_CBA_EVENTW
	#define IMAGEHLP_DEFERRED_SYMBOL_LOAD64   IMAGEHLP_DEFERRED_SYMBOL_LOADW64
	#define IMAGEHLP_MODULE64                 IMAGEHLP_MODULEW64
	#define SYMSRV_INDEX_INFO                 SYMSRV_INDEX_INFOW
#ENDIF

// -----------------------------------------------------------------
// The following APIs exist only for backwards compatibility
// with a pre-release version documented in an MSDN release.

// You should use SymFindFileInPath if you want to maintain
// future compatibility.


// These values should not be used.
// They have been replaced by SYMFLAG_ values.

#define SYMF_OMAP_GENERATED   0x00000001
#define SYMF_OMAP_MODIFIED    0x00000002
#define SYMF_REGISTER         0x00000008
#define SYMF_REGREL           0x00000010
#define SYMF_FRAMEREL         0x00000020
#define SYMF_PARAMETER        0x00000040
#define SYMF_LOCAL            0x00000080
#define SYMF_CONSTANT         0x00000100
#define SYMF_EXPORT           0x00000200
#define SYMF_FORWARDER        0x00000400
#define SYMF_FUNCTION         0x00000800
#define SYMF_VIRTUAL          0x00001000
#define SYMF_THUNK            0x00002000
#define SYMF_TLSREL           0x00004000

// These values should also not be used.
// They have been replaced by SYMFLAG_ values.

#define IMAGEHLP_SYMBOL_INFO_VALUEPRESENT          1
#define IMAGEHLP_SYMBOL_INFO_REGISTER              SYMF_REGISTER        // 0x0008
#define IMAGEHLP_SYMBOL_INFO_REGRELATIVE           SYMF_REGREL          // 0x0010
#define IMAGEHLP_SYMBOL_INFO_FRAMERELATIVE         SYMF_FRAMEREL        // 0x0020
#define IMAGEHLP_SYMBOL_INFO_PARAMETER             SYMF_PARAMETER       // 0x0040
#define IMAGEHLP_SYMBOL_INFO_LOCAL                 SYMF_LOCAL           // 0x0080
#define IMAGEHLP_SYMBOL_INFO_CONSTANT              SYMF_CONSTANT        // 0x0100
#define IMAGEHLP_SYMBOL_FUNCTION                   SYMF_FUNCTION        // 0x0800
#define IMAGEHLP_SYMBOL_VIRTUAL                    SYMF_VIRTUAL         // 0x1000
#define IMAGEHLP_SYMBOL_THUNK                      SYMF_THUNK           // 0x2000
#define IMAGEHLP_SYMBOL_INFO_TLSRELATIVE           SYMF_TLSREL          // 0x4000

// For MINIDUMP definitions include the DbgHlp.h header file

#IFDEF UNICODE
	#define MapFileAndCheckSum  MapFileAndCheckSumW
#else
	#define MapFileAndCheckSum  MapFileAndCheckSumA
#endif

#ifdef IMAGEHLP64
	#define StackWalk StackWalk64
	#define SymEnumerateModules SymEnumerateModules64
	#define SymEnumerateSymbols SymEnumerateSymbols64
	#define SymEnumerateSymbolsW SymEnumerateSymbolsW64
	#define EnumerateLoadedModules EnumerateLoadedModules64
	#define SymFunctionTableAccess SymFunctionTableAccess64
	#define SymGetModuleInfo SymGetModuleInfo64
	#define SymGetModuleInfoW SymGetModuleInfoW64
	#define SymGetModuleBase SymGetModuleBase64
	#define SymGetSymFromAddr SymGetSymFromAddr64
	#define SymGetSymFromName SymGetSymFromName64
	#define SymGetSymNext SymGetSymNext64
	#define SymGetSymPrev SymGetSymPrev64
	#define SymGetLineFromAddr SymGetLineFromAddr64
	#define SymGetLineFromName SymGetLineFromName64
	#define SymGetLineNext SymGetLineNext64
	#define SymGetLinePrev SymGetLinePrev64
	#define SymLoadModule SymLoadModule64
	#define SymUnloadModule SymUnloadModule64
	#define SymUnDName SymUnDName64
	#define SymRegisterCallback SymRegisterCallback64
	#define SymRegisterFunctionEntryCallback SymRegisterFunctionEntryCallback64
	#define SymGetModuleInfoEx SymGetModuleInfoEx64
	#define SymGetSymbolInfo SymGetSymbolInfo64
#ENDIF

#endif
