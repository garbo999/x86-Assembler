#ifndef PATCHAPI_H
#define PATCHAPI_H

/* Interface for creating and applying patches to files */

#IFDEF LINKFILES
	#dynamiclinkfile mspatcha.dll
#ENDIF

#define PATCH_OPTION_USE_LZX_A  0x00000001
#define PATCH_OPTION_USE_LZX_B  0x00000002
#define PATCH_OPTION_USE_LZX_BEST  0x00000003
#define PATCH_OPTION_USE_BEST  0x00000000
#define PATCH_OPTION_USE_LZX_LARGE  0x00000004
#define PATCH_OPTION_NO_BINDFIX  0x00010000
#define PATCH_OPTION_NO_LOCKFIX  0x00020000
#define PATCH_OPTION_NO_REBASE  0x00040000
#define PATCH_OPTION_FAIL_IF_SAME_FILE  0x00080000
#define PATCH_OPTION_FAIL_IF_BIGGER  0x00100000
#define PATCH_OPTION_NO_CHECKSUM  0x00200000
#define PATCH_OPTION_NO_RESTIMEFIX  0x00400000
#define PATCH_OPTION_NO_TIMESTAMP  0x00800000
#define PATCH_OPTION_SIGNATURE_MD5  0x01000000
#define PATCH_OPTION_RESERVED1  0x80000000
#define PATCH_OPTION_VALID_FLAGS  0x80FF0007
#define PATCH_SYMBOL_NO_IMAGEHLP  0x00000001
#define PATCH_SYMBOL_NO_FAILURES  0x00000002
#define PATCH_SYMBOL_UNDECORATED_TOO  0x00000004
#define PATCH_SYMBOL_RESERVED1  0x80000000
#define APPLY_OPTION_FAIL_IF_EXACT  0x00000001
#define APPLY_OPTION_FAIL_IF_CLOSE  0x00000002
#define APPLY_OPTION_TEST_ONLY  0x00000004
#define APPLY_OPTION_VALID_FLAGS  0x00000007
#define ERROR_PATCH_ENCODE_FAILURE  0xC00E3101
#define ERROR_PATCH_INVALID_OPTIONS  0xC00E3102
#define ERROR_PATCH_SAME_FILE  0xC00E3103
#define ERROR_PATCH_RETAIN_RANGES_DIFFER  0xC00E3104
#define ERROR_PATCH_BIGGER_THAN_COMPRESSED  0xC00E3105
#define ERROR_PATCH_IMAGEHLP_FAILURE  0xC00E3106
#define ERROR_PATCH_DECODE_FAILURE  0xC00E4101
#define ERROR_PATCH_CORRUPT  0xC00E4102
#define ERROR_PATCH_NEWER_FORMAT  0xC00E4103
#define ERROR_PATCH_WRONG_FILE  0xC00E4104
#define ERROR_PATCH_NOT_NECESSARY  0xC00E4105
#define ERROR_PATCH_NOT_AVAILABLE  0xC00E4106

PATCH_IGNORE_RANGE STRUCT
	OffsetInOldFile DD
	LengthInBytes DD
ENDS

PATCH_RETAIN_RANGE STRUCT
	OffsetInOldFile DD
	LengthInBytes DD
	OffsetInNewFile DD
ENDS

PATCH_OLD_FILE_INFO_A STRUCT
	SizeOfThisStruct DD
	OldFileName PTR
	IgnoreRangeCount DD
	IgnoreRangeArray PTR
	RetainRangeCount DD
	RetainRangeArray PTR
ENDS

PATCH_OLD_FILE_INFO_W STRUCT
	SizeOfThisStruct DD
	OldFileName PTR
	IgnoreRangeCount DD
	IgnoreRangeArray PTR
	RetainRangeCount DD
	RetainRangeArray PTR
ENDS

PATCH_OLD_FILE_INFO_H STRUCT
	SizeOfThisStruct DD
	OldFileHandle HANDLE
	IgnoreRangeCount DD
	IgnoreRangeArray PTR
	RetainRangeCount DD
	RetainRangeArray PTR
ENDS

PATCH_OLD_FILE_INFO STRUCT
	SizeOfThisStruct DD
	UNION
		OldFileNameA PTR
		OldFileNameW PTR
		OldFileHandle HANDLE
	ENDUNION
	IgnoreRangeCount DD
	IgnoreRangeArray PTR
	RetainRangeCount DD
	RetainRangeArray PTR
ENDS

PATCH_INTERLEAVE_MAP STRUCT
	CountRanges DD
    Range STRUCT
		OldOffset DD
		OldLength DD
		NewLength DD
	ENDS
ENDS

PATCH_OPTION_DATA STRUCT
	SizeOfThisStruct DD
	SymbolOptionFlags DD
	NewFileSymbolPath PTR
	OldFileSymbolPathArray PTR
	ExtendedOptionFlags DD
	SymLoadCallback PTR
	SymLoadContext PTR
	InterleaveMapArray PTR
	MaxLzxWindowSize DD
ENDS

#IFDEF UNICODE
	#define CreatePatchFile  CreatePatchFileW
	#define CreatePatchFileEx  CreatePatchFileExW
	#define TestApplyPatchToFile  TestApplyPatchToFileW
	#define ApplyPatchToFile  ApplyPatchToFileW
	#define ApplyPatchToFileEx  ApplyPatchToFileExW
	#define ExtractPatchHeaderToFile ExtractPatchHeaderToFileW
	#define GetFilePatchSignature  GetFilePatchSignatureW
	#define PATCH_OLD_FILE_INFO	PATCH_OLD_FILE_INFO_W
#else
	#define CreatePatchFile  CreatePatchFileA
	#define CreatePatchFileEx  CreatePatchFileExA
	#define TestApplyPatchToFile  TestApplyPatchToFileA
	#define ApplyPatchToFile  ApplyPatchToFileA
	#define ApplyPatchToFileEx  ApplyPatchToFileExA
	#define ExtractPatchHeaderToFile ExtractPatchHeaderToFileA
	#define GetFilePatchSignature  GetFilePatchSignatureA
	#define PATCH_OLD_FILE_INFO	PATCH_OLD_FILE_INFO_A
#endif

#endif
