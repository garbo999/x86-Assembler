#ifndef DBGHELP_H
#define DBGHELP_H

// cvconst.h has been translated
// #DEFINE NO_CVCONST_H

#IF X64
	#DEFINE IMAGEHLP64
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile dbghelp.dll
#ENDIF

// As a general principal always call the 64 bit version
// of every API, if a choice exists.  The 64 bit version
// works great on 32 bit platforms, and is forward
// compatible to 64 bit platforms.

#define IMAGE_SEPARATION (64*1024)

// Observant readers may notice that 2 new fields,
// 'fReadOnly' and 'Version' have been added to
// the LOADED_IMAGE structure after 'fDOSImage'.
// This does not change the size of the structure 
// from previous headers.  That is because while 
// 'fDOSImage' is a byte, it is padded by the 
// compiler to 4 bytes.  So the 2 new fields are 
// slipped into the extra space.

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

#define MAX_SYM_NAME            2000

// Error codes set by dbghelp functions.  Call GetLastError
// to see them.
// Dbghelp also sets error codes found in winerror.h

#define ERROR_IMAGE_NOT_STRIPPED    0x8800  // the image is not stripped.  No dbg file available.
#define ERROR_NO_DBG_POINTER        0x8801  // image is stripped but there is no pointer to a dbg file
#define ERROR_NO_PDB_POINTER        0x8802  // image does not point to a pdb file

#ifndef X64
/* wont be ported to Win64 */
// Note the pointers are defined as DWORDs since there is no 64 bit version
IMAGE_DEBUG_INFORMATION STRUCT
	List LIST_ENTRY <>
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

//
// UnDecorateSymbolName Flags
//

#define UNDNAME_COMPLETE                 (0x0000)  // Enable full undecoration
#define UNDNAME_NO_LEADING_UNDERSCORES   (0x0001)  // Remove leading underscores from MS extended keywords
#define UNDNAME_NO_MS_KEYWORDS           (0x0002)  // Disable expansion of MS extended keywords
#define UNDNAME_NO_FUNCTION_RETURNS      (0x0004)  // Disable expansion of return type for primary declaration
#define UNDNAME_NO_ALLOCATION_MODEL      (0x0008)  // Disable expansion of the declaration model
#define UNDNAME_NO_ALLOCATION_LANGUAGE   (0x0010)  // Disable expansion of the declaration language specifier
#define UNDNAME_NO_MS_THISTYPE           (0x0020)  // NYI Disable expansion of MS keywords on the 'this' type for primary declaration
#define UNDNAME_NO_CV_THISTYPE           (0x0040)  // NYI Disable expansion of CV modifiers on the 'this' type for primary declaration
#define UNDNAME_NO_THISTYPE              (0x0060)  // Disable all modifiers on the 'this' type
#define UNDNAME_NO_ACCESS_SPECIFIERS     (0x0080)  // Disable expansion of access specifiers for members
#define UNDNAME_NO_THROW_SIGNATURES      (0x0100)  // Disable expansion of 'throw-signatures' for functions and pointers to functions
#define UNDNAME_NO_MEMBER_TYPE           (0x0200)  // Disable expansion of 'static' or 'virtual'ness of members
#define UNDNAME_NO_RETURN_UDT_MODEL      (0x0400)  // Disable expansion of MS model for UDT returns
#define UNDNAME_32_BIT_DECODE            (0x0800)  // Undecorate 32-bit decorated names
#define UNDNAME_NAME_ONLY                (0x1000)  // Crack only the name for primary declaration;
                                                                                                   //  return just [scope::]name.  Does expand template params
#define UNDNAME_NO_ARGUMENTS             (0x2000)  // Don't undecorate arguments to function
#define UNDNAME_NO_SPECIAL_SYMS          (0x4000)  // Don't undecorate special names (v-table, vcall, vector xxx, metatype, etc)

//
// these values are used for synthesized file types
// that can be passed in as image headers instead of
// the standard ones from ntimage.h
//

#define DBHHEADER_DEBUGDIRS     0x1

MODLOAD_DATA STRUCT
	ssize DD
	ssig DD
	data PTR
	size DD
	flags DD
ENDS

//
// StackWalking API
//

AddrMode1616 = 0
AddrMode1632 = 1
AddrModeReal = 2
AddrModeFlat = 3

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

//
// This structure is included in the STACKFRAME structure,
// and is used to trace through usermode callbacks in a thread's
// kernel stack.  The values must be copied by the kernel debugger
// from the DBGKD_GET_VERSION and WAIT_STATE_CHANGE packets.
//

//
// New KDHELP structure for 64 bit system support.
// This structure is preferred in new code.
//
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

#IFDEF IMAGEHLP64
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
	AddrPC ADDRESS64 <>
	AddrReturn ADDRESS64 <>
	AddrFrame ADDRESS64 <>
	AddrStack ADDRESS64 <>
	AddrBStore ADDRESS64 <>
	FuncTableEntry DQ
	Params DQ 4 DUP (?)
	Far DD
	Virtual DD
	Reserved DQ 3 DUP (?)
	KdHelp KDHELP64 <>
ENDS

#IFDEF IMAGEHLP64
#define STACKFRAME STACKFRAME64

#else
	STACKFRAME STRUCT
		AddrPC ADDRESS <>
		AddrReturn ADDRESS <>
		AddrFrame ADDRESS <>
		AddrStack ADDRESS <>
		FuncTableEntry DD
		Params DD 4 DUP (?)
		Far DD
		Virtual DD
		Reserved DD 3 DUP (?)
		KdHelp KDHELP <>
		AddrBStore ADDRESS <>
	ENDS
#endif

#define API_VERSION_NUMBER 11

API_VERSION STRUCT
	MajorVersion DW
	MinorVersion DW
	Revision DW
	Reserved DW
ENDS

// values found in SYMBOL_INFO.Tag
//
// This was taken from cvconst.h and should
// not override any values found there.
//
// #define _NO_CVCONST_H_ if you don't
// have access to that file...

#ifdef NO_CVCONST_H
// SymTagEnum
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

//
// symbol type enumeration
//
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

//
// symbol data structure
//

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
	Name DW
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

	IMAGEHLP_SYMBOL64_PACKAGE STRUCT
		sym IMAGEHLP_SYMBOL64
		name DB MAX_SYM_NAME+1 DUP
	ENDS

	IMAGEHLP_SYMBOLW STRUCT
		SizeOfStruct DD
		Address DQ
		Size DD
		Flags DD
		MaxNameLength DD
		Name DW
	ENDS

	IMAGEHLP_SYMBOLW64_PACKAGE STRUCT
		sym IMAGEHLP_SYMBOLW
		name DW MAX_SYM_NAME+1 DUP
	ENDS

#endif

//
// module data structure
//

IMAGEHLP_MODULE64 STRUCT
	SizeOfStruct DD            // set to sizeof(IMAGEHLP_MODULE64) 
	padding DD                 // This is not in the definition however it is required
	BaseOfImage DWORD64        // base load address of module
	ImageSize DD               // virtual size of the loaded module
	TimeDateStamp DD           // date/time stamp from pe header
	CheckSum DD                // checksum from the pe header
	NumSyms DD                 // number of symbols in the symbol table
	SymType ENUM                 // type of symbols loaded
	ModuleName CHAR 32 DUP       // module name
	ImageName CHAR 256 DUP       // image name
	LoadedImageName CHAR 256 DUP // symbol file name
    // new elements: 07-Jun-2002
	LoadedPdbName CHAR 256 DUP   // pdb file name
	CVSig DD                   // Signature of the CV record in the debug directories
	CVData CHAR MAX_PATH*3 DUP   // Contents of the CV record
	PdbSig DD                  // Signature of PDB
	PdbSig70 GUID              // Signature of PDB (VC 7 and up)
	PdbAge DD                  // DBI age of pdb
	PdbUnmatched BOOL            // loaded an unmatched pdb
	DbgUnmatched BOOL            // loaded an unmatched dbg
	LineNumbers BOOL             // we have line number information
	GlobalSymbols BOOL           // we have internal symbol information
	TypeInfo BOOL                // we have type information
    // new elements: 17-Dec-2003
	SourceIndexed BOOL           // pdb supports source server
	Publics BOOL                 // contains public symbols
ENDS

IMAGEHLP_MODULEW64 STRUCT
	SizeOfStruct DD            // set to sizeof(IMAGEHLP_MODULE64)
	padding DD                 // This is not in the definition however it is required
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

//
// source file line data structure
//

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

//
// source file structure
//

SOURCEFILE STRUCT
	ModBase DQ
	FileName PTR
ENDS

#DEFINE SOURCEFILEW SOURCEFILE

//
// data structures used for registered symbol callbacks
//

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

#DEFINE IMAGEHLP_DEFERRED_SYMBOL_LOADW64 IMAGEHLP_DEFERRED_SYMBOL_LOAD64

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

//
// options that are set/returned by SymSetOptions() & SymGetOptions()
// these are used as a mask
//
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

#define SYMOPT_DEBUG                    0x80000000

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

// flags for SymEnumSourceLines

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

SYMBOL_INFO STRUCT
	SizeOfStruct DD
	TypeIndex DD
	Reserved DQ 2 DUP
	Index DD
	Size DD
	ModBase DQ
	Flags DD
#IFNDEF USEOLDSYMBOLINFO
	alignpadding DD
#ENDIF
	Value DQ
	Address DQ
	Register DD
	Scope DD
	Tag DD
	NameLen DD
	MaxNameLen DD
	Name DB 4 DUP
ENDS

SYMBOL_INFOW STRUCT
	SizeOfStruct DD
	TypeIndex DD
	Reserved DQ 2 DUP
	Index DD
	Size DD
	ModBase DQ
	Flags DD
#IFNDEF USEOLDSYMBOLINFO
	Reserved2 DD
#ENDIF
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

SYMSRV_INDEX_INFO STRUCT
	sizeofstruct DD
	file DB MAX_PATH+1 DUP
	stripped DD
	timestamp DD
	size DD
	dbgfile DB MAX_PATH+1 DUP
	pdbfile DB MAX_PATH+1 DUP
	guid GUID
	sig DD
	age DD
ENDS

SYMSRV_INDEX_INFOW STRUCT
	sizeofstruct DD
	file DW MAX_PATH+1 DUP
	stripped DD
	timestamp DD
	size DD
	dbgfile DW MAX_PATH+1 DUP
	pdbfile DW MAX_PATH+1 DUP
	guid GUID
	sig DD
	age DD
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

#IFDEF UNICODE
	#define MapFileAndCheckSum  MapFileAndCheckSumW
#else

	#define MapFileAndCheckSum  MapFileAndCheckSumA
#endif

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



#define MINIDUMP_SIGNATURE 'PMDM'
#define MINIDUMP_VERSION   (42899)

MINIDUMP_LOCATION_DESCRIPTOR STRUCT
	DataSize DD
	Rva DD
ENDS

MINIDUMP_LOCATION_DESCRIPTOR64 STRUCT
	DataSize DQ
	Rva DQ
ENDS

MINIDUMP_MEMORY_DESCRIPTOR STRUCT
	StartOfMemoryRange DQ
	Memory MINIDUMP_LOCATION_DESCRIPTOR
ENDS

// DESCRIPTOR64 is used for full-memory minidumps where
// all of the raw memory is laid out sequentially at the
// end of the dump.  There is no need for individual RVAs
// as the RVA is the base RVA plus the sum of the preceeding
// data blocks.
MINIDUMP_MEMORY_DESCRIPTOR64 STRUCT
	StartOfMemoryRange DQ
	DataSize DQ
ENDS

MINIDUMP_HEADER STRUCT
	Signature DD
	Version DD
	NumberOfStreams DD
	StreamDirectoryRva DD
	CheckSum DD
	UNION
		Reserved DD
		TimeDateStamp DD
	ENDUNION
	Flags DQ
ENDS

//
// The MINIDUMP_HEADER field StreamDirectoryRva points to 
// an array of MINIDUMP_DIRECTORY structures.
//

MINIDUMP_DIRECTORY STRUCT
	StreamType DD
	Location MINIDUMP_LOCATION_DESCRIPTOR
ENDS

MINIDUMP_STRING STRUCT
	Length DD
	Buffer DW
ENDS

//
// The MINIDUMP_DIRECTORY field StreamType may be one of the following types.
// Types will be added in the future, so if a program reading the minidump
// header encounters a stream type it does not understand it should ignore
// the data altogether. Any tag above LastReservedStream will not be used by
// the system and is reserved for program-specific information.
//

UnusedStream                = 0
ReservedStream0             = 1
ReservedStream1             = 2
ThreadListStream            = 3
ModuleListStream            = 4
MemoryListStream            = 5
ExceptionStream             = 6
SystemInfoStream            = 7
ThreadExListStream          = 8
Memory64ListStream          = 9
CommentStreamA              = 10
CommentStreamW              = 11
HandleDataStream            = 12
FunctionTableStream         = 13
UnloadedModuleListStream    = 14
MiscInfoStream              = 15
MemoryInfoListStream        = 16
ThreadInfoListStream        = 17
HandleOperationListStream   = 18

ceStreamNull                = 0x8000
ceStreamSystemInfo          = 0x8001
ceStreamException           = 0x8002
ceStreamModuleList          = 0x8003
ceStreamProcessList         = 0x8004
ceStreamThreadList          = 0x8005 
ceStreamThreadContextList   = 0x8006
ceStreamThreadCallStackList = 0x8007
ceStreamMemoryVirtualList   = 0x8008
ceStreamMemoryPhysicalList  = 0x8009
ceStreamBucketParameters    = 0x800A     

LastReservedStream          = 0xffff



//
// The minidump system information contains processor and
// Operating System specific information.
// 

//
// CPU information is obtained from one of two places.
//
//  1) On x86 computers, CPU_INFORMATION is obtained from the CPUID
//     instruction. You must use the X86 portion of the union for X86
//     computers.
//
//  2) On non-x86 architectures, CPU_INFORMATION is obtained by calling
//     IsProcessorFeatureSupported().
//

CPU_INFORMATION UNION
	X86CpuInfo STRUCT
		//
		// CPUID Subfunction 0, register EAX (VendorId [0]),
		// EBX (VendorId [1]) and ECX (VendorId [2]).
		//
		VendorId DD 3 DUP
		//
		// CPUID Subfunction 1, register EAX
		//
		VersionInformation DD
		//
		// CPUID Subfunction 1, register EDX
		//
		FeatureInformation DD
		//
		// CPUID, Subfunction 80000001, register EBX. This will only
		// be obtained if the vendor id is "AuthenticAMD".
		//
		AMDExtendedCpuFeatures DD
	ENDS

    //
    // Non-x86 platforms use processor feature flags.
    //
    
	OtherCpuInfo STRUCT
		ProcessorFeatures DQ 2 DUP
	ENDS
ENDUNION
        
MINIDUMP_SYSTEM_INFO STRUCT
    //
    // ProcessorArchitecture, ProcessorLevel and ProcessorRevision are all
    // taken from the SYSTEM_INFO structure obtained by GetSystemInfo( ).
    //
    ProcessorArchitecture DW
	ProcessorLevel DW
	ProcessorRevision DW
	UNION
		Reserved0 DW
		STRUCT
			NumberOfProcessors DB
			ProductType DB
		ENDS
	ENDUNION
    //
    // MajorVersion, MinorVersion, BuildNumber, PlatformId and
    // CSDVersion are all taken from the OSVERSIONINFO structure
    // returned by GetVersionEx( ).
    //
	MajorVersion DD
	MinorVersion DD
	BuildNumber DD
	PlatformId DD
    //
    // RVA to a CSDVersion string in the string table.
    //
	CSDVersionRva DD
	UNION
		Reserved1 DD
		STRUCT
			SuiteMask DW
			Reserved2 DW
		ENDS
	ENDUNION
	Cpu CPU_INFORMATION
ENDS


//
// The minidump thread contains standard thread
// information plus an RVA to the memory for this 
// thread and an RVA to the CONTEXT structure for
// this thread.
//

//
// ThreadId must be 4 bytes on all architectures.
//
MINIDUMP_THREAD STRUCT
	ThreadId DD
	SuspendCount DD
	PriorityClass DD
	Priority DD
	Teb DQ
	Stack MINIDUMP_MEMORY_DESCRIPTOR
	ThreadContext MINIDUMP_LOCATION_DESCRIPTOR
ENDS
//
// The thread list is a container of threads.
//
MINIDUMP_THREAD_LIST STRUCT
	NumberOfThreads DD
	Threads MINIDUMP_THREAD
ENDS

MINIDUMP_THREAD_EX STRUCT
	ThreadId DD
	SuspendCount DD
	PriorityClass DD
	Priority DD
	Teb DQ
	Stack MINIDUMP_MEMORY_DESCRIPTOR
	ThreadContext MINIDUMP_LOCATION_DESCRIPTOR
	BackingStore MINIDUMP_MEMORY_DESCRIPTOR
ENDS
//
// The thread list is a container of threads.
//
MINIDUMP_THREAD_EX_LIST STRUCT
	NumberOfThreads DD
	Threads MINIDUMP_THREAD_EX
ENDS
//
// The MINIDUMP_EXCEPTION is the same as EXCEPTION on Win64.
//
MINIDUMP_EXCEPTION  STRUCT
	ExceptionCode DD
	ExceptionFlags DD
	ExceptionRecord DQ
	ExceptionAddress DQ
	NumberParameters DD
	__unusedAlignment DD
	ExceptionInformation DQ EXCEPTION_MAXIMUM_PARAMETERS DUP
ENDS
//
// The exception information stream contains the id of the thread that caused
// the exception (ThreadId), the exception record for the exception
// (ExceptionRecord) and an RVA to the thread context where the exception
// occured.
//
MINIDUMP_EXCEPTION_STREAM STRUCT
	ThreadId DD
	__alignment DD
	ExceptionRecord MINIDUMP_EXCEPTION
	ThreadContext MINIDUMP_LOCATION_DESCRIPTOR
ENDS
//
// The MINIDUMP_MODULE contains information about a
// a specific module. It includes the CheckSum and
// the TimeDateStamp for the module so the module
// can be reloaded during the analysis phase.
//
MINIDUMP_MODULE STRUCT
	BaseOfImage DQ
	SizeOfImage DD
	CheckSum DD
	TimeDateStamp DD
	ModuleNameRva DD
	VersionInfo VS_FIXEDFILEINFO
	CvRecord MINIDUMP_LOCATION_DESCRIPTOR
	MiscRecord MINIDUMP_LOCATION_DESCRIPTOR
	Reserved0 DQ
	Reserved1 DQ
ENDS   
//
// The minidump module list is a container for modules.
//
MINIDUMP_MODULE_LIST STRUCT
	NumberOfModules DD
	Modules MINIDUMP_MODULE
ENDS
//
// Memory Ranges
//
MINIDUMP_MEMORY_LIST STRUCT
	NumberOfMemoryRanges DD
	MemoryRanges MINIDUMP_MEMORY_DESCRIPTOR
ENDS

MINIDUMP_MEMORY64_LIST STRUCT
	NumberOfMemoryRanges DQ
	BaseRva DQ
	MemoryRanges MINIDUMP_MEMORY_DESCRIPTOR64
ENDS
//
// Support for user supplied exception information.
//
MINIDUMP_EXCEPTION_INFORMATION STRUCT
	ThreadId DD
	ExceptionPointers PTR
	ClientPointers DD
ENDS

MINIDUMP_EXCEPTION_INFORMATION64 STRUCT
	ThreadId DD
	ExceptionRecord DQ
	ContextRecord DQ
	ClientPointers DD
ENDS
//
// Support for capturing system handle state at the time of the dump.
//

// Per-handle object information varies according to
// the OS, the OS version, the processor type and
// so on.  The minidump gives a minidump identifier
// to each possible data format for identification
// purposes but does not control nor describe the actual data.
MiniHandleObjectInformationNone = 0
MiniThreadInformation1 = 1
MiniMutantInformation1 = 2
MiniMutantInformation2 = 3
MiniProcessInformation1 = 4
MiniProcessInformation2 = 5
MiniHandleObjectInformationTypeMax = 6

MINIDUMP_HANDLE_OBJECT_INFORMATION STRUCT
	NextInfoRva DD
	InfoType DD
	SizeOfInfo DD
    // Raw information follows.
ENDS

MINIDUMP_HANDLE_DESCRIPTOR STRUCT
	Handle DQ
	TypeNameRva DD
	ObjectNameRva DD
	Attributes DD
	GrantedAccess DD
	HandleCount DD
	PointerCount DD
ENDS

MINIDUMP_HANDLE_DESCRIPTOR_2 STRUCT
	Handle DQ
	TypeNameRva DD
	ObjectNameRva DD
	Attributes DD
	GrantedAccess DD
	HandleCount DD
	PointerCount DD
	ObjectInfoRva DD
	Reserved0 DD
ENDS

MINIDUMP_HANDLE_DATA_STREAM STRUCT
	SizeOfHeader DD
	SizeOfDescriptor DD
	NumberOfDescriptors DD
	Reserved DD
ENDS
// Some operating systems can track the last operations
// performed on a handle.  For example, Application Verifier
// can enable this for some versions of Windows.  The
// handle operation list collects handle operations
// known for the dump target.
// Each entry is an AVRF_HANDLE_OPERATION.
MINIDUMP_HANDLE_OPERATION_LIST STRUCT
	SizeOfHeader DD
	SizeOfEntry DD
	NumberOfEntries DD
	Reserved DD
ENDS
//
// Support for capturing dynamic function table state at the time of the dump.
//
MINIDUMP_FUNCTION_TABLE_DESCRIPTOR STRUCT
	MinimumAddress DQ
	MaximumAddress DQ
	BaseAddress DQ
	EntryCount DD
	SizeOfAlignPad DD
ENDS

MINIDUMP_FUNCTION_TABLE_STREAM STRUCT
	SizeOfHeader DD
	SizeOfDescriptor DD
	SizeOfNativeDescriptor DD
	SizeOfFunctionEntry DD
	NumberOfDescriptors DD
	SizeOfAlignPad DD
ENDS
//
// The MINIDUMP_UNLOADED_MODULE contains information about a
// a specific module that was previously loaded but no
// longer is.  This can help with diagnosing problems where
// callers attempt to call code that is no longer loaded.
//
MINIDUMP_UNLOADED_MODULE STRUCT
	BaseOfImage DQ
	SizeOfImage DD
	CheckSum DD
	TimeDateStamp DD
	ModuleNameRva DD
ENDS
//
// The minidump unloaded module list is a container for unloaded modules.
//
MINIDUMP_UNLOADED_MODULE_LIST STRUCT
	SizeOfHeader DD
	SizeOfEntry DD
	NumberOfEntries DD
ENDS
//
// The miscellaneous information stream contains a variety
// of small pieces of information.  A member is valid if
// it's within the available size and its corresponding
// bit is set.
//
#define MINIDUMP_MISC1_PROCESS_ID           0x00000001
#define MINIDUMP_MISC1_PROCESS_TIMES        0x00000002
#define MINIDUMP_MISC1_PROCESSOR_POWER_INFO 0x00000004

MINIDUMP_MISC_INFO STRUCT
	SizeOfInfo DD
	Flags1 DD
	ProcessId DD
	ProcessCreateTime DD
	ProcessUserTime DD
	ProcessKernelTime DD
ENDS

MINIDUMP_MISC_INFO_2 STRUCT
	SizeOfInfo DD
	Flags1 DD
	ProcessId DD
	ProcessCreateTime DD
	ProcessUserTime DD
	ProcessKernelTime DD
	ProcessorMaxMhz DD
	ProcessorCurrentMhz DD
	ProcessorMhzLimit DD
	ProcessorMaxIdleState DD
	ProcessorCurrentIdleState DD
ENDS
//
// The memory information stream contains memory region
// description information.  This stream corresponds to
// what VirtualQuery would return for the process the
// dump was created for.
//
MINIDUMP_MEMORY_INFO STRUCT
	BaseAddress DQ
	AllocationBase DQ
	AllocationProtect DD
	__alignment1 DD
	RegionSize DQ
	State DD
	Protect DD
	Type DD
	__alignment2 DD
ENDS

MINIDUMP_MEMORY_INFO_LIST STRUCT
	SizeOfHeader DD
	SizeOfEntry DD
	NumberOfEntries DQ
ENDS
//
// The memory information stream contains memory region
// description information.  This stream corresponds to
// what VirtualQuery would return for the process the
// dump was created for.
//
// Thread dump writer status flags.
#define MINIDUMP_THREAD_INFO_ERROR_THREAD    0x00000001
#define MINIDUMP_THREAD_INFO_WRITING_THREAD  0x00000002
#define MINIDUMP_THREAD_INFO_EXITED_THREAD   0x00000004
#define MINIDUMP_THREAD_INFO_INVALID_INFO    0x00000008
#define MINIDUMP_THREAD_INFO_INVALID_CONTEXT 0x00000010
#define MINIDUMP_THREAD_INFO_INVALID_TEB     0x00000020

MINIDUMP_THREAD_INFO STRUCT
	ThreadId DD
	DumpFlags DD
	DumpError DD
	ExitStatus DD
	CreateTime DQ
	ExitTime DQ
	KernelTime DQ
	UserTime DQ
	StartAddress DQ
	Affinity DQ
ENDS

MINIDUMP_THREAD_INFO_LIST STRUCT
	SizeOfHeader DD
	SizeOfEntry DD
	NumberOfEntries DD
ENDS
//
// Support for arbitrary user-defined information.
//
MINIDUMP_USER_RECORD STRUCT
	Type DD
	Memory MINIDUMP_LOCATION_DESCRIPTOR
ENDS

MINIDUMP_USER_STREAM STRUCT
	Type DD
	BufferSize DD
	Buffer PTR
ENDS

MINIDUMP_USER_STREAM_INFORMATION STRUCT
	UserStreamCount DD
	UserStreamArray PTR
ENDS

//
// Callback support.
//

ModuleCallback = 0
ThreadCallback = 1
ThreadExCallback = 3
IncludeThreadCallback = 4
IncludeModuleCallback = 5
MemoryCallback = 6
CancelCallback = 7
WriteKernelMinidumpCallback = 8
KernelMinidumpStatusCallback = 9
RemoveMemoryCallback = 10
IncludeVmRegionCallback = 11
IoStartCallback = 12
IoWriteAllCallback = 13
IoFinishCallback = 14
ReadMemoryFailureCallback = 15
SecondaryFlagsCallback = 16


MINIDUMP_THREAD_CALLBACK STRUCT
	ThreadId DD
	ThreadHandle HANDLE
	Context CONTEXT
	SizeOfContext DD
	StackBase DD
	StackEnd DD
ENDS

MINIDUMP_THREAD_EX_CALLBACK STRUCT
	ThreadId DD
	ThreadHandle HANDLE
	Context CONTEXT
	SizeOfContext DD
	StackBase DQ
	StackEnd DQ
	BackingStoreBase DQ
	BackingStoreEnd DQ
ENDS

MINIDUMP_INCLUDE_THREAD_CALLBACK STRUCT
	ThreadId DD
ENDS

ThreadWriteThread            = 0x0001
ThreadWriteStack             = 0x0002
ThreadWriteContext           = 0x0004
ThreadWriteBackingStore      = 0x0008
ThreadWriteInstructionWindow = 0x0010
ThreadWriteThreadData        = 0x0020
ThreadWriteThreadInfo        = 0x0040

MINIDUMP_MODULE_CALLBACK STRUCT
	FullPath PTR
	BaseOfImage DQ
	SizeOfImage DD
	CheckSum DD
	TimeDateStamp DD
	VersionInfo VS_FIXEDFILEINFO
	CvRecord PTR
	SizeOfCvRecord DD
	MiscRecord PTR
	SizeOfMiscRecord DD
ENDS

MINIDUMP_INCLUDE_MODULE_CALLBACK STRUCT
	BaseOfImage DQ
ENDS

ModuleWriteModule        = 0x0001
ModuleWriteDataSeg       = 0x0002
ModuleWriteMiscRecord    = 0x0004
ModuleWriteCvRecord      = 0x0008
ModuleReferencedByMemory = 0x0010
ModuleWriteTlsData       = 0x0020
ModuleWriteCodeSegs      = 0x0040

MINIDUMP_IO_CALLBACK STRUCT
	Handle HANDLE
	Offset DQ
	Buffer PTR
	BufferBytes DD
ENDS

MINIDUMP_READ_MEMORY_FAILURE_CALLBACK STRUCT
	Offset DQ
	Bytes DD
	FailureStatus DD
ENDS

MINIDUMP_CALLBACK_INPUT STRUCT
	ProcessId DD
	ProcessHandle HANDLE
	CallbackType DD
	UNION
		Status DD
		Thread MINIDUMP_THREAD_CALLBACK
		ThreadEx MINIDUMP_THREAD_EX_CALLBACK
		Module MINIDUMP_MODULE_CALLBACK
		IncludeThread MINIDUMP_INCLUDE_THREAD_CALLBACK
		IncludeModule MINIDUMP_INCLUDE_MODULE_CALLBACK
		Io MINIDUMP_IO_CALLBACK
		ReadMemoryFailure MINIDUMP_READ_MEMORY_FAILURE_CALLBACK
		SecondaryFlags DD
	ENDUNION
ENDS

MINIDUMP_CALLBACK_OUTPUT STRUCT
	UNION
		ModuleWriteFlags DD
		ThreadWriteFlags DD
		SecondaryFlags DD
		STRUCT
			MemoryBase DQ
			MemorySize DD
		ENDS
		STRUCT
			CheckCancel DD
			Cancel DD
		ENDS
		Handle HANDLE
		STRUCT
			VmRegion MINIDUMP_MEMORY_INFO
			Continue DD
		ENDS
		Status DD
	ENDUNION
ENDS

        
//
// A normal minidump contains just the information
// necessary to capture stack traces for all of the
// existing threads in a process.
//
// A minidump with data segments includes all of the data
// sections from loaded modules in order to capture
// global variable contents.  This can make the dump much
// larger if many modules have global data.
//
// A minidump with full memory includes all of the accessible
// memory in the process and can be very large.  A minidump
// with full memory always has the raw memory data at the end
// of the dump so that the initial structures in the dump can
// be mapped directly without having to include the raw
// memory information.
//
// Stack and backing store memory can be filtered to remove
// data unnecessary for stack walking.  This can improve
// compression of stacks and also deletes data that may
// be private and should not be stored in a dump.
// Memory can also be scanned to see what modules are
// referenced by stack and backing store memory to allow
// omission of other modules to reduce dump size.
// In either of these modes the ModuleReferencedByMemory flag
// is set for all modules referenced before the base
// module callbacks occur.
//
// On some operating systems a list of modules that were
// recently unloaded is kept in addition to the currently
// loaded module list.  This information can be saved in
// the dump if desired.
//
// Stack and backing store memory can be scanned for referenced
// pages in order to pick up data referenced by locals or other
// stack memory.  This can increase the size of a dump significantly.
//
// Module paths may contain undesired information such as user names
// or other important directory names so they can be stripped.  This
// option reduces the ability to locate the proper image later
// and should only be used in certain situations.
//
// Complete operating system per-process and per-thread information can
// be gathered and stored in the dump.
//
// The virtual address space can be scanned for various types
// of memory to be included in the dump.
//
// Code which is concerned with potentially private information
// getting into the minidump can set a flag that automatically
// modifies all existing and future flags to avoid placing
// unnecessary data in the dump.  Basic data, such as stack
// information, will still be included but optional data, such
// as indirect memory, will not.
//
// When doing a full memory dump it's possible to store all
// of the enumerated memory region descriptive information
// in a memory information stream.
//
// Additional thread information beyond the basic thread
// structure can be collected if desired.
//
// A minidump with code segments includes all of the code
// and code-related sections from loaded modules in order
// to capture executable content.
//
// MiniDumpWithoutAuxiliaryState turns off any secondary,
// auxiliary-supported memory gathering.
//
// MiniDumpWithFullAuxiliaryState asks any present auxiliary
// data providers to include all of their state in the dump.
// The exact set of what is provided depends on the auxiliary.
// This can be quite large.
//

MiniDumpNormal                         = 0x00000000
MiniDumpWithDataSegs                   = 0x00000001
MiniDumpWithFullMemory                 = 0x00000002
MiniDumpWithHandleData                 = 0x00000004
MiniDumpFilterMemory                   = 0x00000008
MiniDumpScanMemory                     = 0x00000010
MiniDumpWithUnloadedModules            = 0x00000020
MiniDumpWithIndirectlyReferencedMemory = 0x00000040
MiniDumpFilterModulePaths              = 0x00000080
MiniDumpWithProcessThreadData          = 0x00000100
MiniDumpWithPrivateReadWriteMemory     = 0x00000200
MiniDumpWithoutOptionalData            = 0x00000400
MiniDumpWithFullMemoryInfo             = 0x00000800
MiniDumpWithThreadInfo                 = 0x00001000
MiniDumpWithCodeSegs                   = 0x00002000
MiniDumpWithoutAuxiliaryState          = 0x00004000
MiniDumpWithFullAuxiliaryState         = 0x00008000

MiniDumpValidTypeFlags                 = 0x0000ffff

//
// In addition to the primary flags provided to
// MiniDumpWriteDump there are additional, less
// frequently used options queried via the secondary
// flags callback.
//
// MiniSecondaryWithoutPowerInfo suppresses the minidump
// query that retrieves processor power information for
// MINIDUMP_MISC_INFO.
//

MiniSecondaryWithoutPowerInfo = 0x00000001
MiniSecondaryValidFlags       = 0x00000001

#endif // _DBGHELP_


