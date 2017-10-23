
#ifndef dia2_h
#define dia2_h

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif /*COM_NO_WINDOWS_H*/


/* header files for imported files */
#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF
#IFNDEF PROPIDL_H
	#include "propidl.h"
#ENDIF
#IFNDEF CVCONST_H
	#include "cvconst.h"
#ENDIF

nsNone = 0
nsfCaseSensitive = 0x1
nsfCaseInsensitive = 0x2
nsfFNameExt = 0x4
nsfRegularExpression = 0x8
nsfUndecoratedName = 0x10
nsCaseSensitive = 0x1
nsCaseInsensitive = 0x2
nsFNameExt = 0x6
nsRegularExpression = 0x9
nsCaseInRegularExpression = 0xa

E_PDB_OK =  0x806d0001
E_PDB_USAGE = 0x806d0002
E_PDB_OUT_OF_MEMORY = 0x806d0003
E_PDB_FILE_SYSTEM = 0x806d0004
E_PDB_NOT_FOUND = 0x806d0005
E_PDB_INVALID_SIG = 0x806d0006
E_PDB_INVALID_AGE = 0x806d0007
E_PDB_PRECOMP_REQUIRED = 0x806d0008
E_PDB_OUT_OF_TI = 0x806d0009
E_PDB_NOT_IMPLEMENTED = 0x806d000A
E_PDB_V1_PDB = 0x806d000B
E_PDB_FORMAT = 0x806d000C
E_PDB_LIMIT = 0x806d000D
E_PDB_CORRUPT = 0x806d000E
E_PDB_TI16 = 0x806d000F
E_PDB_ACCESS_DENIED = 0x806d0010
E_PDB_ILLEGAL_TYPE_EDIT = 0x806d0011
E_PDB_INVALID_EXECUTABLE = 0x806d0012
E_PDB_DBG_NOT_FOUND = 0x806d0013
E_PDB_NO_DEBUG_INFO = 0x806d0014
E_PDB_INVALID_EXE_TIMESTAMP = 0x806d0015
E_PDB_RESERVED = 0x806d0016
E_PDB_DEBUG_INFO_NOT_IN_PDB = 0x806d0017
E_PDB_SYMSRV_BAD_CACHE_PATH = 0x806d0018
E_PDB_SYMSRV_CACHE_FULL = 0x806d0019
E_PDB_MAX = 0x806d001A

#DEFINE GUID_IID_IDiaLoadCallback <0xC32ADB82,0x73F4,0x421b,<0x95,0xD5,0xA4,0x70,0x6E,0xDF,0x5D,0xBE>>

IDiaLoadCallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	NotifyDebugDir PTR
	NotifyOpenDBG PTR
	NotifyOpenPDB PTR
	RestrictRegistryAccess PTR
	RestrictSymbolServerAccess PTR
ENDS

#DEFINE GUID_IID_IDiaLoadCallback2 <0x4688a074,0x5a4d,0x4486,<0xae,0xa8,0x7b,0x90,0x71,0x1d,0x9f,0x7c>>

IDiaLoadCallback2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	NotifyDebugDir PTR
	NotifyOpenDBG PTR
	NotifyOpenPDB PTR
	RestrictRegistryAccess PTR
	RestrictSymbolServerAccess PTR
	RestrictOriginalPathAccess PTR
	RestrictReferencePathAccess PTR
	RestrictDBGAccess PTR
	RestrictSystemRootAccess PTR
ENDS


#DEFINE GUID_IID_IDiaReadExeAtOffsetCallback <0x587A461C,0xB80B,0x4f54,<0x91,0x94,0x50,0x32,0x58,0x9A,0x63,0x19>>

IDiaReadExeAtOffsetCallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ReadExecutableAt PTR
ENDS

#DEFINE GUID_IID_IDiaReadExeAtRVACallback <0x8E3F80CA,0x7517,0x432a,<0xBA,0x07,0x28,0x51,0x34,0xAA,0xEA,0x8E>>

IDiaReadExeAtRVACallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ReadExecutableAtRVA PTR
ENDS

#DEFINE GUID_IID_IDiaDataSource <0x79F1BB5F,0xB66E,0x48e5,<0xB6,0xA9,0x15,0x45,0xC3,0x23,0xCA,0x3D>>

IDiaDataSource STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_lastError PTR
	loadDataFromPdb PTR
	loadAndValidateDataFromPdb PTR
	loadDataForExe PTR
	loadDataFromIStream PTR
	openSession PTR
ENDS

#DEFINE GUID_IID_IDiaEnumSymbols <0xCAB72C48,0x443B,0x48f5,<0x9B,0x0B,0x42,0xF0,0x82,0x0A,0xB2,0x9A>>

IDiaEnumSymbols STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IDiaEnumSymbolsByAddr <0x624B7D9C,0x24EA,0x4421,<0x9D,0x06,0x3B,0x57,0x74,0x71,0xC1,0xFA>>

IDiaEnumSymbolsByAddr STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	symbolByAddr PTR
	symbolByRVA PTR
	symbolByVA PTR
	Next PTR
	Prev PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IDiaEnumSourceFiles <0x10F3DBD9,0x664F,0x4469,<0xB8,0x08,0x94,0x71,0xC7,0xA5,0x05,0x38>>

IDiaEnumSourceFiles STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IDiaEnumLineNumbers <0xFE30E878,0x54AC,0x44f1,<0x81,0xBA,0x39,0xDE,0x94,0x0F,0x60,0x52>>

IDiaEnumLineNumbers STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IDiaEnumInjectedSources <0xD5612573,0x6925,0x4468,<0x88,0x83,0x98,0xCD,0xEC,0x8C,0x38,0x4A>>

IDiaEnumInjectedSources STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IDiaEnumSegments <0xE8368CA9,0x01D1,0x419d,<0xAC,0x0C,0xE3,0x12,0x35,0xDB,0xDA,0x9F>>

IDiaEnumSegments STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IDiaEnumSectionContribs <0x1994DEB2,0x2C82,0x4b1d,<0xA5,0x7F,0xAF,0xF4,0x24,0xD5,0x4A,0x68>>

IDiaEnumSectionContribs STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IDiaEnumFrameData <0x9FC77A4B,0x3C1C,0x44ed,<0xA7,0x98,0x6C,0x1D,0xEE,0xA5,0x3E,0x1F>>

IDiaEnumFrameData STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
	frameByRVA PTR
	frameByVA PTR
ENDS

#DEFINE GUID_IID_IDiaEnumDebugStreamData <0x486943E8,0xD187,0x4a6b,<0xA3,0xC4,0x29,0x12,0x59,0xFF,0xF6,0x0D>>

IDiaEnumDebugStreamData STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IDiaEnumDebugStreams <0x08CBB41E,0x47A6,0x4f87,<0x92,0xF1,0x1C,0x9C,0x87,0xCE,0xD0,0x44>>

IDiaEnumDebugStreams STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

DiaAddressMapEntry STRUCT
	rva DD
	rvaTo DD
ENDS

#DEFINE GUID_IID_IDiaAddressMap <0xB62A2E7A,0x067A,0x4ea3,<0xB5,0x98,0x04,0xC0,0x97,0x17,0x50,0x2C>>

IDiaAddressMap STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_addressMapEnabled PTR
	put_addressMapEnabled PTR
	get_relativeVirtualAddressEnabled PTR
	put_relativeVirtualAddressEnabled PTR
	get_imageAlign PTR
	put_imageAlign PTR
	set_imageHeaders PTR
	set_addressMap PTR
ENDS

#DEFINE GUID_IID_IDiaSession <0x67138B34,0x79CD,0x4b42,<0xB7,0x4A,0xA1,0x8A,0xDB,0xB7,0x99,0xDF>>

IDiaSession STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_loadAddress PTR
	put_loadAddress PTR
	get_globalScope PTR
	getEnumTables PTR
	getSymbolsByAddr PTR
	findChildren PTR
	findSymbolByAddr PTR
	findSymbolByRVA PTR
	findSymbolByVA PTR
	findSymbolByToken PTR
	symsAreEquiv PTR
	symbolById PTR
	findSymbolByRVAEx PTR
	findSymbolByVAEx PTR
	findFile PTR
	findFileById PTR
	findLines PTR
	findLinesByAddr PTR
	findLinesByRVA PTR
	findLinesByVA PTR
	findLinesByLinenum PTR
	findInjectedSource PTR
	getEnumDebugStreams PTR
ENDS

#DEFINE GUID_IID_IDiaSymbol <0xcb787b2f,0xbd6c,0x4635,<0xba,0x52,0x93,0x31,0x26,0xbd,0x2d,0xcd>>

IDiaSymbol STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_symIndexId PTR
	get_symTag PTR
	get_name PTR
	get_lexicalParent PTR
	get_classParent PTR
	get_type PTR
	get_dataKind PTR
	get_locationType PTR
	get_addressSection PTR
	get_addressOffset PTR
	get_relativeVirtualAddress PTR
	get_virtualAddress PTR
	get_registerId PTR
	get_offset PTR
	get_length PTR
	get_slot PTR
	get_volatileType PTR
	get_constType PTR
	get_unalignedType PTR
	get_access PTR
	get_libraryName PTR
	get_platform PTR
	get_language PTR
	get_editAndContinueEnabled PTR
	get_frontEndMajor PTR
	get_frontEndMinor PTR
	get_frontEndBuild PTR
	get_backEndMajor PTR
	get_backEndMinor PTR
	get_backEndBuild PTR
	get_sourceFileName PTR
	get_unused PTR
	get_thunkOrdinal PTR
	get_thisAdjust PTR
	get_virtualBaseOffset PTR
	get_virtual PTR
	get_intro PTR
	get_pure PTR
	get_callingConvention PTR
	get_value PTR
	get_baseType PTR
	get_token PTR
	get_timeStamp PTR
	get_guid PTR
	get_symbolsFileName PTR
	get_reference PTR
	get_count PTR
	get_bitPosition PTR
	get_arrayIndexType PTR
	get_packed PTR
	get_constructor PTR
	get_overloadedOperator PTR
	get_nested PTR
	get_hasNestedTypes PTR
	get_hasAssignmentOperator PTR
	get_hasCastOperator PTR
	get_scoped PTR
	get_virtualBaseClass PTR
	get_indirectVirtualBaseClass PTR
	get_virtualBasePointerOffset PTR
	get_virtualTableShape PTR
	get_lexicalParentId PTR
	get_classParentId PTR
	get_typeId PTR
	get_arrayIndexTypeId PTR
	get_virtualTableShapeId PTR
	get_code PTR
	get_function PTR
	get_managed PTR
	get_msil PTR
	get_virtualBaseDispIndex PTR
	get_undecoratedName PTR
	get_age PTR
	get_signature PTR
	get_compilerGenerated PTR
	get_addressTaken PTR
	get_rank PTR
	get_lowerBound PTR
	get_upperBound PTR
	get_lowerBoundId PTR
	get_upperBoundId PTR
	get_dataBytes PTR
	findChildren PTR
	get_targetSection PTR
	get_targetOffset PTR
	get_targetRelativeVirtualAddress PTR
	get_targetVirtualAddress PTR
	get_machineType PTR
	get_oemId PTR
	get_oemSymbolId PTR
	get_types PTR
	get_typeIds PTR
	get_objectPointerType PTR
	get_udtKind PTR
	get_undecoratedNameEx PTR
	get_liveLVarInstances PTR
	get_noReturn PTR
	get_customCallingConvention PTR
	get_noInline PTR
	get_optimizedCodeDebugInfo PTR
	get_notReached PTR
	get_interruptReturn PTR
	get_farReturn PTR
	get_isStatic PTR
	get_hasDebugInfo PTR
	get_isLTCG PTR
	get_isDataAligned PTR
	get_hasSecurityChecks PTR
	get_compilerName PTR
	get_hasAlloca PTR
	get_hasSetJump PTR
	get_hasLongJump PTR
	get_hasInlAsm PTR
	get_hasEH PTR
	get_hasSEH PTR
	get_hasEHa PTR
	get_isNaked PTR
	get_isAggregated PTR
	get_isSplitted PTR
	get_container PTR
	get_inlSpec PTR
	get_noStackOrdering PTR
	get_virtualBaseTableType PTR
	get_hasManagedCode PTR
	get_isHotpatchable PTR
	get_isCVTCIL PTR
	get_isMSILNetmodule PTR
	get_isCTypes PTR
	get_isStripped PTR
	get_frontEndQFE PTR
	get_backEndQFE PTR
	get_wasInlined PTR
	get_strictGSCheck PTR
	get_isCxxReturnUdt PTR
	get_isConstructorVirtualBase PTR
ENDS

#DEFINE GUID_IID_IDiaSourceFile <0xA2EF5353,0xF5A8,0x4eb3,<0x90,0xD2,0xCB,0x52,0x6A,0xCB,0x3C,0xDD>>

IDiaSourceFile STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_uniqueId PTR
	get_fileName PTR
	get_checksumType PTR
	get_compilands PTR
	get_checksum PTR
ENDS

#DEFINE GUID_IID_IDiaLineNumber <0xB388EB14,0xBE4D,0x421d,<0xA8,0xA1,0x6C,0xF7,0xAB,0x05,0x70,0x86>>

IDiaLineNumber STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_compiland PTR
	get_sourceFile PTR
	get_lineNumber PTR
	get_lineNumberEnd PTR
	get_columnNumber PTR
	get_columnNumberEnd PTR
	get_addressSection PTR
	get_addressOffset PTR
	get_relativeVirtualAddress PTR
	get_virtualAddress PTR
	get_length PTR
	get_sourceFileId PTR
	get_statement PTR
	get_compilandId PTR
ENDS

#DEFINE GUID_IID_IDiaSectionContrib <0x0CF4B60E,0x35B1,0x4c6c,<0xBD,0xD8,0x85,0x4B,0x9C,0x8E,0x38,0x57>>

IDiaSectionContrib STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_compiland PTR
	get_addressSection PTR
	get_addressOffset PTR
	get_relativeVirtualAddress PTR
	get_virtualAddress PTR
	get_length PTR
	get_notPaged PTR
	get_code PTR
	get_initializedData PTR
	get_uninitializedData PTR
	get_remove PTR
	get_comdat PTR
	get_discardable PTR
	get_notCached PTR
	get_share PTR
	get_execute PTR
	get_read PTR
	get_write PTR
	get_dataCrc PTR
	get_relocationsCrc PTR
	get_compilandId PTR
	get_code16bit PTR
ENDS

#DEFINE GUID_IID_IDiaSegment <0x0775B784,0xC75B,0x4449,<0x84,0x8B,0xB7,0xBD,0x31,0x59,0x54,0x5B>>

IDiaSegment STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_frame PTR
	get_offset PTR
	get_length PTR
	get_read PTR
	get_write PTR
	get_execute PTR
	get_addressSection PTR
	get_relativeVirtualAddress PTR
	get_virtualAddress PTR
ENDS

#DEFINE GUID_IID_IDiaInjectedSource <0xAE605CDC,0x8105,0x4a23,<0xB7,0x10,0x32,0x59,0xF1,0xE2,0x61,0x12>>

IDiaInjectedSource STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_crc PTR
	get_length PTR
	get_filename PTR
	get_objectFilename PTR
	get_virtualFilename PTR
	get_sourceCompression PTR
	get_source PTR
ENDS

#DEFINE GUID_IID_IDiaLVarInstance <0x0e425a73,0x3ced,0x4964,<0x8c,0xf0,0xa6,0xca,0xf1,0x1b,0xd8,0x18>>

IDiaLVarInstance STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_symbol PTR
	get_sectionStart PTR
	get_offsetStart PTR
	get_rvaStart PTR
	get_vaStart PTR
	get_rvaEnd PTR
	get_sectionEnd PTR
	get_offsetEnd PTR
	get_vaEnd PTR
	get_program PTR
	get_livenessAt PTR
	get_location PTR
ENDS

E_DIA_INPROLOG	= 0x806d0064
E_DIA_SYNTAX	= 806d0065
E_DIA_FRAME_ACCESS	= 806d0066
E_DIA_VALUE	= 806d0067

#DEFINE GUID_IID_IDiaStackWalkFrame <0x97F0F1A6,0xE04E,0x4ea4,<0xB4,0xF9,0xB0,0xD0,0xE8,0xD9,0x0F,0x5D>>

IDiaStackWalkFrame STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_registerValue PTR
	put_registerValue PTR
	readMemory PTR
	searchForReturnAddress PTR
	searchForReturnAddressStart PTR
ENDS

#DEFINE GUID_IID_IDiaFrameData <0xA39184B7,0x6A36,0x42de,<0x8E,0xEC,0x7D,0xF9,0xF3,0xF5,0x9F,0x33>>

IDiaFrameData STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_addressSection PTR
	get_addressOffset PTR
	get_relativeVirtualAddress PTR
	get_virtualAddress PTR
	get_lengthBlock PTR
	get_lengthLocals PTR
	get_lengthParams PTR
	get_maxStack PTR
	get_lengthProlog PTR
	get_lengthSavedRegisters PTR
	get_program PTR
	get_systemExceptionHandling PTR
	get_cplusplusExceptionHandling PTR
	get_functionStart PTR
	get_allocatesBasePointer PTR
	get_type PTR
	get_functionParent PTR
	execute PTR
ENDS

#DEFINE GUID_IID_IDiaImageData <0xC8E40ED2,0xA1D9,0x4221,<0x86,0x92,0x3C,0xE6,0x61,0x18,0x4B,0x44>>

IDiaImageData STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_relativeVirtualAddress PTR
	get_virtualAddress PTR
	get_imageBase PTR
ENDS

#DEFINE GUID_IID_IDiaTable <0x4A59FB77,0xABAC,0x469b,<0xA3,0x0B,0x9E,0xCC,0x85,0xBF,0xEF,0x14>>

IDiaTable STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
	get__NewEnum PTR
	get_name PTR
	get_Count PTR
	Item PTR
ENDS

#DEFINE GUID_IID_IDiaEnumTables <0xC65C2B0A,0x1150,0x4d7a,<0xAF,0xCC,0xE0,0x5B,0xF3,0xDE,0xE8,0x1E>>

IDiaEnumTables STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get__NewEnum PTR
	get_Count PTR
	Item PTR
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_CLSID_DiaSource <0x4C41678E,0x887B,0x4365,<0xA0,0x9E,0x92,0x5D,0x28,0xDB,0x33,0xC2>>
#DEFINE GUID_CLSID_DiaSourceAlt <0xFF5FAFD8,0xCBCB,0x4EF9,<0xAD,0xC0,0x45,0xA6,0x2B,0x68,0x1E,0x96>>
#DEFINE GUID_CLSID_DiaStackWalker <0x8557EAC0,0x2A06,0x4E08,<0xA6,0xD8,0xAB,0xBA,0x2A,0xF1,0x73,0xE1>>

#define	DiaTable_Symbols L"Symbols"

#define	DiaTable_Sections L"Sections"

#define	DiaTable_SrcFiles L"SourceFiles"

#define	DiaTable_LineNums L"LineNumbers"

#define	DiaTable_SegMap L"SegmentMap"

#define	DiaTable_Dbg L"Dbg"

#define	DiaTable_InjSrc L"InjectedSource"

#define	DiaTable_FrameData L"FrameData"

#DEFINE GUID_IID_IDiaPropertyStorage <0x9d416f9c,0xe184,0x45b2,<0xa4,0xf0,0xce,0x51,0x7f,0x71,0x9e,0x9b>>

IDiaPropertyStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ReadMultiple PTR
	ReadPropertyNames PTR
	Enum PTR
	ReadDWORD PTR
	ReadLONG PTR
	ReadBOOL PTR
	ReadULONGLONG PTR
	ReadBSTR PTR
ENDS

#DEFINE GUID_IID_IDiaStackFrame <0x5edbc96d,0xcdd6,0x4792,<0xaf,0xbe,0xcc,0x89,0x00,0x7d,0x96,0x10>>

IDiaStackFrame STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_type PTR
	get_base PTR
	get_size PTR
	get_returnAddress PTR
	get_localsBase PTR
	get_lengthLocals PTR
	get_lengthParams PTR
	get_lengthProlog PTR
	get_lengthSavedRegisters PTR
	get_systemExceptionHandling PTR
	get_cplusplusExceptionHandling PTR
	get_functionStart PTR
	get_allocatesBasePointer PTR
	get_maxStack PTR
	get_registerValue PTR
	get_rawLVarInstanceValue PTR
	get_lVarInstanceLocation PTR
ENDS

#DEFINE GUID_IID_IDiaEnumStackFrames <0xec9d461d,0xce74,0x4711,<0xa0,0x20,0x7d,0x8f,0x9a,0x1d,0xd2,0x55>>

IDiaEnumStackFrames STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
ENDS

// Frame Pointer Omission (FPO) data
FPODATA STRUCT
	ulOffStart DD
	cbProcSize DD
	cdwLocals DD
	cdwParams DW
	cdwFlags DW
ENDS

#DEFINE GUID_IID_IDiaStackWalkHelper <0xfeb0155d,0x35a8,0x42d4,<0x83,0x28,0xbf,0x45,0x8f,0x42,0x9a,0x3a>>

IDiaStackWalkHelper STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_registerValue PTR
	put_registerValue PTR
	readMemory PTR
	searchForReturnAddress PTR
	searchForReturnAddressStart PTR
	frameForVA PTR
	symbolForVA PTR
	pdataForVA PTR
	imageForVA PTR
ENDS

#DEFINE GUID_IID_IDiaStackWalker <0x5485216b,0xa54c,0x469f,<0x96,0x70,0x52,0xb2,0x4d,0x52,0x29,0xbb>>

IDiaStackWalker STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	getEnumFrames PTR
	getEnumFrames2 PTR
ENDS

#DEFINE GUID_IID_IDiaStackWalkHelper2 <0x8222c490,0x507b,0x4bef,<0xb3,0xbd,0x41,0xdc,0xa7,0xb5,0x93,0x4c>>

IDiaStackWalkHelper2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_registerValue PTR
	put_registerValue PTR
	readMemory PTR
	searchForReturnAddress PTR
	searchForReturnAddressStart PTR
	frameForVA PTR
	symbolForVA PTR
	pdataForVA PTR
	imageForVA PTR
ENDS

#DEFINE GUID_IID_IDiaStackWalker2 <0x7c185885,0xa015,0x4cac,<0x94,0x11,0x0f,0x4f,0xb3,0x9b,0x1f,0x3a>>

IDiaStackWalker2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	getEnumFrames PTR
	getEnumFrames2 PTR
ENDS

#endif


