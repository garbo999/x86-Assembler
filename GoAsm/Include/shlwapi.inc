;=============================================================;
;          shlwapi.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF SHLWAPI_INC
#Define SHLWAPI_INC

#Define STIF_DEFAULT        		000000000H
#Define STIF_SUPPORT_HEX    		000000001H

#Define StrCatA                 	lstrcatA
#Define StrCmpA                 	lstrcmpA
#Define StrCmpIA                	lstrcmpiA
#Define StrCpyA                 	lstrcpyA
#Define StrCpyNA                	lstrcpynA

#Define StrToLong               	StrToInt
#Define StrNCmp                 	StrCmpN
#Define StrNCmpI                	StrCmpNI
#Define StrNCpy                 	StrCpyN
#Define StrCatN                 	StrNCat

#Define GCT_INVALID             	00000H
#Define GCT_LFNCHAR             	00001H
#Define GCT_SHORTCHAR           	00002H
#Define GCT_WILD                	00004H
#Define GCT_SEPARATOR           	00008H


;SHREGDEL_FLAGS enumeration
SHREGDEL_DEFAULT					000000000H
SHREGDEL_HKCU						000000001H
SHREGDEL_HKLM						000000010H
SHREGDEL_BOTH						000000011H

;SHREGENUM_FLAGS enumeration
SHREGENUM_DEFAULT					000000000H
SHREGENUM_HKCU						000000001H
SHREGENUM_HKLM						000000010H
SHREGENUM_BOTH						000000011H

#Define SHREGSET_HKCU           	000000001H
#Define SHREGSET_FORCE_HKCU     	000000002H
#Define SHREGSET_HKLM           	000000004H
#Define SHREGSET_FORCE_HKLM     	000000008H
#Define SHREGSET_DEFAULT        	(SHREGSET_FORCE_HKCU | SHREGSET_HKLM)

#Define DLLVER_PLATFORM_WINDOWS     000000001H
#Define DLLVER_PLATFORM_NT          000000002H


DLLVERSIONINFO Struct
	cbSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformID DD
EndS


#IF STRINGS UNICODE
	#Define StrChr StrChrW
	#Define StrRChr StrRChrW
	#Define StrChrI StrChrIW
	#Define StrRChrI StrRChrIW
	#Define StrCmpN StrCmpNW
	#Define StrCmpNI StrCmpNIW
	#Define StrStr StrStrW
	#Define StrStrI StrStrIW
	#Define StrDup StrDupW
	#Define StrRStrI StrRStrIW
	#Define StrCSpn StrCSpnW
	#Define StrCSpnI StrCSpnIW
	#Define StrSpn StrSpnW
	#Define StrToInt StrToIntW
	#Define StrPBrk StrPBrkW
	#Define StrToIntEx StrToIntExW
	#Define StrFromTimeInterval StrFromTimeIntervalW
	#Define StrIntlEqN StrIntlEqNW
	#Define StrIntlEqNI StrIntlEqNIW
	#Define StrFormatByteSize StrFormatByteSizeW
	#Define StrNCat StrNCatW
	#Define StrTrim StrTrimW
	#Define ChrCmpI ChrCmpIW
	#Define StrCat StrCatW
	#Define StrCmp StrCmpW
	#Define StrCmpI StrCmpIW
	#Define StrCpy StrCpyW
	#Define StrCpyN StrCpyNW
	#Define PathAddBackslash PathAddBackslashW
	#Define PathAddExtension PathAddExtensionW
	#Define PathAppend PathAppendW
	#Define PathBuildRoot PathBuildRootW
	#Define PathCanonicalize PathCanonicalizeW
	#Define PathCombine PathCombineW
	#Define PathCompactPath PathCompactPathW
	#Define PathCompactPathEx PathCompactPathExW
	#Define PathCommonPrefix PathCommonPrefixW
	#Define PathFileExists PathFileExistsW
	#Define PathFindExtension PathFindExtensionW
	#Define PathFindFileName PathFindFileNameW
	#Define PathFindNextComponent PathFindNextComponentW
	#Define PathFindOnPath PathFindOnPathW
	#Define PathGetArgs PathGetArgsW
	#Define PathGetCharType PathGetCharTypeW
	#Define PathGetDriveNumber PathGetDriveNumberW
	#Define PathIsDirectory PathIsDirectoryW
	#Define PathIsFileSpec PathIsFileSpecW
	#Define PathIsPrefix PathIsPrefixW
	#Define PathIsRelative PathIsRelativeW
	#Define PathIsRoot PathIsRootW
	#Define PathIsSameRoot PathIsSameRootW
	#Define PathIsUNC PathIsUNCW
	#Define PathIsUNCServer PathIsUNCServerW
	#Define PathIsUNCServerShare PathIsUNCServerShareW
	#Define PathIsContentType PathIsContentTypeW
	#Define PathIsHTMLFile PathIsHTMLFileW
	#Define PathIsURL PathIsURLW
	#Define PathMakePretty PathMakePrettyW
	#Define PathMatchSpec PathMatchSpecW
	#Define PathParseIconLocation PathParseIconLocationW
	#Define PathQuoteSpaces PathQuoteSpacesW
	#Define PathRelativePathTo PathRelativePathToW
	#Define PathRemoveArgs PathRemoveArgsW
	#Define PathRemoveBackslash PathRemoveBackslashW
	#Define PathRemoveBlanks PathRemoveBlanksW
	#Define PathRemoveExtension PathRemoveExtensionW
	#Define PathRemoveFileSpec PathRemoveFileSpecW
	#Define PathRenameExtension PathRenameExtensionW
	#Define PathSearchAndQualify PathSearchAndQualifyW
	#Define PathSetDlgItemPath PathSetDlgItemPathW
	#Define PathSkipRoot PathSkipRootW
	#Define PathStripPath PathStripPathW
	#Define PathStripToRoot PathStripToRootW
	#Define PathUnquoteSpaces PathUnquoteSpacesW
	#Define PathMakeSystemFolder PathMakeSystemFolderW
	#Define PathUnmakeSystemFolder PathUnmakeSystemFolderW
	#Define PathIsSystemFolder PathIsSystemFolderW
	#Define SHDeleteEmptyKey SHDeleteEmptyKeyW
	#Define SHDeleteKey SHDeleteKeyW
	#Define SHDeleteValue SHDeleteValueW
	#Define SHGetValue SHGetValueW
	#Define SHSetValue SHSetValueW
	#Define SHQueryValueEx SHQueryValueExW
	#Define SHEnumKeyEx SHEnumKeyExW
	#Define SHEnumValue SHEnumValueW
	#Define SHQueryInfoKey SHQueryInfoKeyW
	#Define SHRegCreateUSKey SHRegCreateUSKeyW
	#Define SHRegOpenUSKey SHRegOpenUSKeyW
	#Define SHRegQueryUSValue SHRegQueryUSValueW
	#Define SHRegWriteUSValue SHRegWriteUSValueW
	#Define SHRegDeleteUSValue SHRegDeleteUSValueW
	#Define SHRegDeleteEmptyUSKey SHRegDeleteEmptyUSKeyW
	#Define SHRegEnumUSKey SHRegEnumUSKeyW
	#Define SHRegEnumUSValue SHRegEnumUSValueW
	#Define SHRegQueryInfoUSKey SHRegQueryInfoUSKeyW
	#Define SHRegGetUSValue SHRegGetUSValueW
	#Define SHRegSetUSValue SHRegSetUSValueW
	#Define SHRegGetBoolUSValue SHRegGetBoolUSValueW
	#Define SHOpenRegStream SHOpenRegStreamW
#ELSE
	#Define StrChr StrChrA
	#Define StrRChr StrRChrA
	#Define StrChrI StrChrIA
	#Define StrRChrI StrRChrIA
	#Define StrCmpN StrCmpNA
	#Define StrCmpNI StrCmpNIA
	#Define StrStr StrStrA
	#Define StrStrI StrStrIA
	#Define StrDup StrDupA
	#Define StrRStrI StrRStrIA
	#Define StrCSpn StrCSpnA
	#Define StrCSpnI StrCSpnIA
	#Define StrSpn StrSpnA
	#Define StrToInt StrToIntA
	#Define StrPBrk StrPBrkA
	#Define StrToIntEx StrToIntExA
	#Define StrFromTimeInterval StrFromTimeIntervalA
	#Define StrIntlEqN StrIntlEqNA
	#Define StrIntlEqNI StrIntlEqNIA
	#Define StrFormatByteSize StrFormatByteSizeA
	#Define StrNCat StrNCatA
	#Define StrTrim StrTrimA
	#Define ChrCmpI ChrCmpIA
	#Define StrCat lstrcatA
	#Define StrCmp lstrcmpA
	#Define StrCmpI lstrcmpiA
	#Define StrCpy lstrcpyA
	#Define StrCpyN lstrcpynA
	#Define PathAddBackslash PathAddBackslashA
	#Define PathAddExtension PathAddExtensionA
	#Define PathAppend PathAppendA
	#Define PathBuildRoot PathBuildRootA
	#Define PathCanonicalize PathCanonicalizeA
	#Define PathCombine PathCombineA
	#Define PathCompactPath PathCompactPathA
	#Define PathCompactPathEx PathCompactPathExA
	#Define PathCommonPrefix PathCommonPrefixA
	#Define PathFileExists PathFileExistsA
	#Define PathFindExtension PathFindExtensionA
	#Define PathFindFileName PathFindFileNameA
	#Define PathFindNextComponent PathFindNextComponentA
	#Define PathFindOnPath PathFindOnPathA
	#Define PathGetArgs PathGetArgsA
	#Define PathGetCharType PathGetCharTypeA
	#Define PathGetDriveNumber PathGetDriveNumberA
	#Define PathIsDirectory PathIsDirectoryA
	#Define PathIsFileSpec PathIsFileSpecA
	#Define PathIsPrefix PathIsPrefixA
	#Define PathIsRelative PathIsRelativeA
	#Define PathIsRoot PathIsRootA
	#Define PathIsSameRoot PathIsSameRootA
	#Define PathIsUNC PathIsUNCA
	#Define PathIsUNCServer PathIsUNCServerA
	#Define PathIsUNCServerShare PathIsUNCServerShareA
	#Define PathIsContentType PathIsContentTypeA
	#Define PathIsHTMLFile PathIsHTMLFileA
	#Define PathIsURL PathIsURLA
	#Define PathMakePretty PathMakePrettyA
	#Define PathMatchSpec PathMatchSpecA
	#Define PathParseIconLocation PathParseIconLocationA
	#Define PathQuoteSpaces PathQuoteSpacesA
	#Define PathRelativePathTo PathRelativePathToA
	#Define PathRemoveArgs PathRemoveArgsA
	#Define PathRemoveBackslash PathRemoveBackslashA
	#Define PathRemoveBlanks PathRemoveBlanksA
	#Define PathRemoveExtension PathRemoveExtensionA
	#Define PathRemoveFileSpec PathRemoveFileSpecA
	#Define PathRenameExtension PathRenameExtensionA
	#Define PathSearchAndQualify PathSearchAndQualifyA
	#Define PathSetDlgItemPath PathSetDlgItemPathA
	#Define PathSkipRoot PathSkipRootA
	#Define PathStripPath PathStripPathA
	#Define PathStripToRoot PathStripToRootA
	#Define PathUnquoteSpaces PathUnquoteSpacesA
	#Define PathMakeSystemFolder PathMakeSystemFolderA
	#Define PathUnmakeSystemFolder PathUnmakeSystemFolderA
	#Define PathIsSystemFolder PathIsSystemFolderA
	#Define SHDeleteEmptyKey SHDeleteEmptyKeyA
	#Define SHDeleteKey SHDeleteKeyA
	#Define SHDeleteValue SHDeleteValueA
	#Define SHGetValue SHGetValueA
	#Define SHSetValue SHSetValueA
	#Define SHQueryValueEx SHQueryValueExA
	#Define SHEnumKeyEx SHEnumKeyExA
	#Define SHEnumValue SHEnumValueA
	#Define SHQueryInfoKey SHQueryInfoKeyA
	#Define SHRegCreateUSKey SHRegCreateUSKeyA
	#Define SHRegOpenUSKey SHRegOpenUSKeyA
	#Define SHRegQueryUSValue SHRegQueryUSValueA
	#Define SHRegWriteUSValue SHRegWriteUSValueA
	#Define SHRegDeleteUSValue SHRegDeleteUSValueA
	#Define SHRegDeleteEmptyUSKey SHRegDeleteEmptyUSKeyA
	#Define SHRegEnumUSKey SHRegEnumUSKeyA
	#Define SHRegEnumUSValue SHRegEnumUSValueA
	#Define SHRegQueryInfoUSKey SHRegQueryInfoUSKeyA
	#Define SHRegGetUSValue SHRegGetUSValueA
	#Define SHRegSetUSValue SHRegSetUSValueA
	#Define SHRegGetBoolUSValue SHRegGetBoolUSValueA
	#Define SHOpenRegStream SHOpenRegStreamA
#ENDIF

#ENDIF ;SHLWAPI_INC
