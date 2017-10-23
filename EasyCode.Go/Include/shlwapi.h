#ifndef SHLWAPI_H
#define SHLWAPI_H

/* Windows light-weight utility API definitions */
#IFDEF LINKFILES
	#dynamiclinkfile shlwapi.dll
#ENDIF

#IFNDEF OBJBASE_H
	#include objbase.h
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define SZ_CONTENTTYPE_HTMLA  A"text/html"
#define SZ_CONTENTTYPE_HTMLW  L"text/html"
#define SZ_CONTENTTYPE_CDFA  A"application/x-cdf"
#define SZ_CONTENTTYPE_CDFW  L"application/x-cdf"

// Return values of WhichPlatform
#define PLATFORM_UNKNOWN     0
#define PLATFORM_IE3         1      // obsolete: use PLATFORM_BROWSERONLY
#define PLATFORM_BROWSERONLY 1      // browser-only (no new shell)
#define PLATFORM_INTEGRATED  2      // integrated shell

#define ILMM_IE4    0       // 1997-era machine

CTF_INSIST              = 0x00000001
CTF_THREAD_REF          = 0x00000002
CTF_PROCESS_REF         = 0x00000004
CTF_COINIT_STA          = 0x00000008
CTF_COINIT              = 0x00000008
CTF_FREELIBANDEXIT      = 0x00000010
CTF_REF_COUNTED         = 0x00000020
CTF_WAIT_ALLOWCOM       = 0x00000040
CTF_UNUSED              = 0x00000080
CTF_INHERITWOW64        = 0x00000100
CTF_WAIT_NO_REENTRANCY  = 0x00000200
CTF_KEYBOARD_LOCALE     = 0x00000400
CTF_OLEINITIALIZE       = 0x00000800
CTF_COINIT_MTA          = 0x00001000
CTF_NOADDREFLIB         = 0x00002000

#define SPMODE_SHELL      0x00000001
#define SPMODE_DEBUGOUT   0x00000002
#define SPMODE_TEST       0x00000004
#define SPMODE_BROWSER    0x00000008
#define SPMODE_FLUSH      0x00000010
#define SPMODE_EVENT      0x00000020
#define SPMODE_MSVM       0x00000040
#define SPMODE_FORMATTEXT 0x00000080
#define SPMODE_PROFILE    0x00000100
#define SPMODE_DEBUGBREAK 0x00000200
#define SPMODE_MSGTRACE   0x00000400
#define SPMODE_PERFTAGS   0x00000800
#define SPMODE_MEMWATCH   0x00001000
#define SPMODE_DBMON      0x00002000
#define SPMODE_MULTISTOP  0x00004000
#define SPMODE_EVENTTRACE 0x00008000 // Event Tracing for Windows Enabled

#define FDTF_SHORTTIME          0x00000001      // eg, "7:48 PM"
#define FDTF_SHORTDATE          0x00000002      // eg, "3/29/98"
#define FDTF_DEFAULT            (FDTF_SHORTDATE | FDTF_SHORTTIME) // eg, "3/29/98 7:48 PM"
#define FDTF_LONGDATE           0x00000004      // eg, "Monday, March 29, 1998"
#define FDTF_LONGTIME           0x00000008      // eg. "7:48:33 PM"
#define FDTF_RELATIVE           0x00000010      // uses "Yesterday", etc. if possible
#define FDTF_LTRDATE            0x00000100      // Left To Right reading order
#define FDTF_RTLDATE            0x00000200      // Right To Left reading order
#define FDTF_NOAUTOREADINGORDER 0x00000400      // Don't detect reading order automatically. Useful if you will be converting to Ansi and don't want Unicode reading order characters

#define SHGVSPB_PERUSER             0x00000001 // must have one of PERUSER or ALLUSERS
#define SHGVSPB_ALLUSERS            0x00000002
#define SHGVSPB_PERFOLDER           0x00000004 // must have one of PERFOLDER ALLFOLDERS or INHERIT
#define SHGVSPB_ALLFOLDERS          0x00000008
#define SHGVSPB_INHERIT             0x00000010
#define SHGVSPB_ROAM                0x00000020 // modifies the above
#define SHGVSPB_NOAUTODEFAULTS      0x80000000 // turns off read delegation to more general property bags
#define SHGVSPB_FOLDER              (SHGVSPB_PERUSER | SHGVSPB_PERFOLDER)
#define SHGVSPB_FOLDERNODEFAULTS    (SHGVSPB_PERUSER | SHGVSPB_PERFOLDER | SHGVSPB_NOAUTODEFAULTS)
#define SHGVSPB_USERDEFAULTS        (SHGVSPB_PERUSER | SHGVSPB_ALLFOLDERS)
#define SHGVSPB_GLOBALDEFAULTS      (SHGVSPB_ALLUSERS | SHGVSPB_ALLFOLDERS)

#define STIF_DEFAULT  0x00000000
#define STIF_SUPPORT_HEX  0x00000001

#define SRRF_RT_REG_NONE        0x00000001
#define SRRF_RT_REG_SZ          0x00000002
#define SRRF_RT_REG_EXPAND_SZ   0x00000004
#define SRRF_RT_REG_BINARY      0x00000008
#define SRRF_RT_REG_DWORD       0x00000010
#define SRRF_RT_REG_MULTI_SZ    0x00000020
#define SRRF_RT_REG_QWORD       0x00000040
#define SRRF_RT_DWORD           (SRRF_RT_REG_BINARY | SRRF_RT_REG_DWORD)
#define SRRF_RT_QWORD           (SRRF_RT_REG_BINARY | SRRF_RT_REG_QWORD)
#define SRRF_RT_ANY             0x0000ffff
#define SRRF_RM_ANY             0x00000000
#define SRRF_RM_NORMAL          0x00010000
#define SRRF_RM_SAFE            0x00020000
#define SRRF_RM_SAFENETWORK     0x00040000
#define SRRF_NOEXPAND           0x10000000
#define SRRF_ZEROONFAILURE      0x20000000
#define SRRF_NOVIRT             0x40000000

#define GCT_INVALID  0x0000
#define GCT_LFNCHAR  0x0001
#define GCT_SHORTCHAR  0x0002
#define GCT_WILD  0x0004
#define GCT_SEPARATOR  0x0008

#define URL_UNESCAPE  0x10000000
#define URL_ESCAPE_UNSAFE  0x20000000
#define URL_PLUGGABLE_PROTOCOL  0x40000000
#define URL_WININET_COMPATIBILITY  0x80000000
#define URL_DONT_ESCAPE_EXTRA_INFO  0x02000000
#define URL_DONT_UNESCAPE_EXTRA_INFO  URL_DONT_ESCAPE_EXTRA_INFO
#define URL_BROWSER_MODE  URL_DONT_ESCAPE_EXTRA_INFO
#define URL_ESCAPE_SPACES_ONLY  0x04000000
#define URL_DONT_SIMPLIFY  0x08000000
#define URL_NO_META  URL_DONT_SIMPLIFY
#define URL_UNESCAPE_INPLACE  0x00100000
#define URL_CONVERT_IF_DOSPATH  0x00200000
#define URL_UNESCAPE_HIGH_ANSI_ONLY  0x00400000
#define URL_INTERNAL_PATH  0x00800000
#define URL_FILE_USE_PATHURL  0x00010000
#define URL_DONT_UNESCAPE 0x00020000
#define URL_ESCAPE_AS_UTF8 0x00040000
#define URL_ESCAPE_PERCENT 0x00001000
#define URL_ESCAPE_SEGMENT_ONLY  0x00002000

#define URL_PARTFLAG_KEEPSCHEME  0x00000001

#define URL_APPLY_DEFAULT  0x00000001
#define URL_APPLY_GUESSSCHEME  0x00000002
#define URL_APPLY_GUESSFILE  0x00000004
#define URL_APPLY_FORCEAPPLY  0x00000008

QITAB struct
	piid PTR
	dwOffset INT32
ENDS

#define SHREGSET_HKCU  0x00000001
#define SHREGSET_FORCE_HKCU  0x00000002
#define SHREGSET_HKLM  0x00000004
#define SHREGSET_FORCE_HKLM  0x00000008
#define SHREGSET_DEFAULT  (SHREGSET_FORCE_HKCU|SHREGSET_HKLM)

#define SHACF_DEFAULT  0x00000000
#define SHACF_FILESYSTEM  0x00000001
#define SHACF_URLALL  (SHACF_URLHISTORY|SHACF_URLMRU)
#define SHACF_URLHISTORY  0x00000002
#define SHACF_URLMRU  0x00000004
#define SHACF_USETAB  0x00000008
#define SHACF_FILESYS_ONLY  0x00000010
#define SHACF_FILESYS_DIRS              0x00000020
#define SHACF_VIRTUAL_NAMESPACE         0x00000040

#define SHACF_AUTOSUGGEST_FORCE_ON  0x10000000
#define SHACF_AUTOSUGGEST_FORCE_OFF  0x20000000
#define SHACF_AUTOAPPEND_FORCE_ON  0x40000000
#define SHACF_AUTOAPPEND_FORCE_OFF  0x80000000

#define CTF_INSIST  0x00000001
#define CTF_THREAD_REF  0x00000002
#define CTF_PROCESS_REF  0x00000004
#define CTF_COINIT  0x00000008

// Enum URL_SCHEME
URL_SCHEME_INVALID = -1
URL_SCHEME_UNKNOWN = 0
URL_SCHEME_FTP = 1
URL_SCHEME_HTTP = 2
URL_SCHEME_GOPHER = 3
URL_SCHEME_MAILTO = 4
URL_SCHEME_NEWS = 5
URL_SCHEME_NNTP = 6
URL_SCHEME_TELNET = 7
URL_SCHEME_WAIS = 8
URL_SCHEME_FILE = 9
URL_SCHEME_MK = 10
URL_SCHEME_HTTPS = 11
URL_SCHEME_SHELL = 12
URL_SCHEME_SNEWS = 13
URL_SCHEME_LOCAL = 14
URL_SCHEME_JAVASCRIPT = 15
URL_SCHEME_VBSCRIPT = 16
URL_SCHEME_ABOUT = 17
URL_SCHEME_RES = 18
URL_SCHEME_MSSHELLROOTED = 19
URL_SCHEME_MSSHELLIDLIST = 20
URL_SCHEME_MSHELP = 21
URL_SCHEME_MSSHELLDEVICE = 22
URL_SCHEME_WILDCARD = 23
URL_SCHEME_SEARCH_MS = 24
URL_SCHEME_SEARCH = 25
URL_SCHEME_KNOWNFOLDER = 26
URL_SCHEME_MAXVALUE = 27

URL_PART_NONE = 0
URL_PART_SCHEME = 1
URL_PART_HOSTNAME = 2
URL_PART_USERNAME = 3
URL_PART_PASSWORD = 4
URL_PART_PORT = 5
URL_PART_QUERY = 6

URLIS_URL = 0
URLIS_OPAQUE = 1
URLIS_NOHISTORY = 2
URLIS_FILEURL = 3
URLIS_APPLIABLE = 4
URLIS_DIRECTORY = 5
URLIS_HASQUERY = 6

SHREGDEL_DEFAULT = 0x00000000
SHREGDEL_HKCU = 0x00000001
SHREGDEL_HKLM = 0x00000010
SHREGDEL_BOTH = 0x00000011

SHREGENUM_DEFAULT = 0x00000000
SHREGENUM_HKCU = 0x00000001
SHREGENUM_HKLM = 0x00000010
SHREGENUM_BOTH = 0x00000011

ASSOCF_INIT_NOREMAPCLSID = 0x00000001
ASSOCF_INIT_BYEXENAME = 0x00000002
ASSOCF_OPEN_BYEXENAME = 0x00000002
ASSOCF_INIT_DEFAULTTOSTAR = 0x00000004
ASSOCF_INIT_DEFAULTTOFOLDER = 0x00000008
ASSOCF_NOUSERSETTINGS = 0x00000010
ASSOCF_NOTRUNCATE = 0x00000020
ASSOCF_VERIFY = 0x00000040
ASSOCF_REMAPRUNDLL = 0x00000080
ASSOCF_NOFIXUPS = 0x00000100
ASSOCF_IGNOREBASECLASS = 0x00000200
ASSOCF_INIT_IGNOREUNKNOWN = 0x00000400

ASSOCSTR_COMMAND = 1
ASSOCSTR_EXECUTABLE = 2
ASSOCSTR_FRIENDLYDOCNAME = 3
ASSOCSTR_FRIENDLYAPPNAME = 4
ASSOCSTR_NOOPEN = 5
ASSOCSTR_SHELLNEWVALUE = 6
ASSOCSTR_DDECOMMAND = 7
ASSOCSTR_DDEIFEXEC = 8
ASSOCSTR_DDEAPPLICATION = 9
ASSOCSTR_DDETOPIC = 10
ASSOCSTR_INFOTIP = 11
ASSOCSTR_QUICKTIP = 12
ASSOCSTR_TILEINFO = 13
ASSOCSTR_CONTENTTYPE = 14
ASSOCSTR_DEFAULTICON = 15
ASSOCSTR_SHELLEXTENSION = 16
ASSOCSTR_DROPTARGET = 17
ASSOCSTR_DELEGATEEXECUTE = 18
ASSOCSTR_MAX = 19

ASSOCKEY_SHELLEXECCLASS = 1
ASSOCKEY_APP = 2
ASSOCKEY_CLASS = 3
ASSOCKEY_BASECLASS = 4
ASSOCKEY_MAX = 5

ASSOCDATA_MSIDESCRIPTOR = 1
ASSOCDATA_NOACTIVATEHANDLER = 2
ASSOCDATA_QUERYCLASSSTORE = 3
ASSOCDATA_HASPERUSERASSOC = 4
ASSOCDATA_EDITFLAGS = 5
ASSOCDATA_VALUE = 6
ASSOCDATA_MAX = 7

ASSOCENUM_NONE = 0

// enum SHGLOBALCOUNTER
GLOBALCOUNTER_SEARCHMANAGER = 0
GLOBALCOUNTER_SEARCHOPTIONS = 1
GLOBALCOUNTER_FOLDERSETTINGSCHANGE = 2
GLOBALCOUNTER_RATINGS = 3
GLOBALCOUNTER_APPROVEDSITES = 4
GLOBALCOUNTER_RESTRICTIONS = 5
GLOBALCOUNTER_SHELLSETTINGSCHANGED = 6
GLOBALCOUNTER_SYSTEMPIDLCHANGE = 7
GLOBALCOUNTER_OVERLAYMANAGER = 8
GLOBALCOUNTER_QUERYASSOCIATIONS = 9
GLOBALCOUNTER_IESESSIONS = 10
GLOBALCOUNTER_IEONLY_SESSIONS = 11
GLOBALCOUNTER_APPLICATION_DESTINATIONS = 12
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS = 13
GLOBALCOUNTER_BITBUCKETNUMDELETERS = 14
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES = 15
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A = 16
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B = 17
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C = 18
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D = 19
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E = 20
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F = 21
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G = 22
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H = 23
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I = 24
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J = 25
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K = 26
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L = 27
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M = 28
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N = 29
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O = 30
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P = 31
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q = 32
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R = 33
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S = 34
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T = 35
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U = 36
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V = 37
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W = 38
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X = 39
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y = 40
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z = 43
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE = 42
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT = 43
GLOBALCOUNTER_RECYCLEBINENUM = 44
GLOBALCOUNTER_RECYCLEBINCORRUPTED = 45
GLOBALCOUNTER_RATINGS_STATECOUNTER = 46
GLOBALCOUNTER_PRIVATE_PROFILE_CACHE = 47
GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT = 48
GLOBALCOUNTER_FOLDERDEFINITION_CACHE = 49
GLOBALCOUNTER_COMMONPLACES_LIST_CACHE = 50
GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE = 51
GLOBALCOUNTER_ASSOCCHANGED = 53  // throttles reading of the registry value "GlobalAssocChangedCounter" from HKLM\Software\Microsoft\Windows\CurrentVersion\Explorer
GLOBALCOUNTER_MAXIMUMVALUE = 54 // should always be last value

DLLVERSIONINFO STRUCT
	cbSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformID DD
ENDS

// Returns TRUE/FALSE depending on question
#define OS_WINDOWS                  0           // Windows 9x vs. NT
#define OS_NT                       1           // Windows 9x vs. NT
#define OS_WIN95ORGREATER           2           // Win95 or greater
#define OS_NT4ORGREATER             3           // NT4 or greater
#define OS_WIN98ORGREATER           5           // Win98 or greater
#define OS_WIN98_GOLD               6           // Win98 Gold (Version 4.10 build 1998)
#define OS_WIN2000ORGREATER         7           // Some derivative of Win2000

// NOTE: these flags check explicitly for (dwMajorVersion == 5)
#define OS_WIN2000PRO               8           // Windows 2000 Professional (Workstation)
#define OS_WIN2000SERVER            9           // Windows 2000 Server
#define OS_WIN2000ADVSERVER         10          // Windows 2000 Advanced Server
#define OS_WIN2000DATACENTER        11          // Windows 2000 Data Center Server
#define OS_WIN2000TERMINAL          12          // Windows 2000 Terminal Server in "Application Server" mode (now simply called "Terminal Server")

#define OS_EMBEDDED                 13          // Embedded Windows Edition
#define OS_TERMINALCLIENT           14          // Windows Terminal Client (eg user is comming in via tsclient)
#define OS_TERMINALREMOTEADMIN      15          // Terminal Server in "Remote Administration" mode
#define OS_WIN95_GOLD               16          // Windows 95 Gold (Version 4.0 Build 1995)
#define OS_MEORGREATER              17          // Windows Millennium (Version 5.0)
#define OS_XPORGREATER              18          // Windows XP or greater
#define OS_HOME                     19          // Home Edition (eg NOT Professional, Server, Advanced Server, or Datacenter)
#define OS_PROFESSIONAL             20          // Professional     (aka Workstation; eg NOT Server, Advanced Server, or Datacenter)
#define OS_DATACENTER               21          // Datacenter       (eg NOT Server, Advanced Server, Professional, or Personal)
#define OS_ADVSERVER                22          // Advanced Server  (eg NOT Datacenter, Server, Professional, or Personal)
#define OS_SERVER                   23          // Server           (eg NOT Datacenter, Advanced Server, Professional, or Personal)
#define OS_TERMINALSERVER           24          // Terminal Server - server running in what used to be called "Application Server" mode (now simply called "Terminal Server")
#define OS_PERSONALTERMINALSERVER   25          // Personal Terminal Server - per/pro machine running in single user TS mode
#define OS_FASTUSERSWITCHING        26          // Fast User Switching
#define OS_WELCOMELOGONUI           27          // New friendly logon UI
#define OS_DOMAINMEMBER             28          // Is this machine a member of a domain (eg NOT a workgroup)
#define OS_ANYSERVER                29          // is this machine any type of server? (eg datacenter or advanced server or server)?
#define OS_WOW6432                  30          // Is this process a 32-bit process running on an 64-bit platform?
#define OS_WEBSERVER                31          // Web Edition Server
#define OS_SMALLBUSINESSSERVER      32          // SBS Server
#define OS_TABLETPC                 33          // Are we running on a TabletPC?
#define OS_SERVERADMINUI            34          // Should defaults lean towards those preferred by server administrators?
#define OS_MEDIACENTER              35          // eHome Freestyle Project
#define OS_APPLIANCE                36          // Windows .NET Appliance Server

PARSEDURLA STRUCT
	cbSize DD
    // Pointers into the buffer that was provided to ParseURL
	pszProtocol PTR
	cchProtocol INT32
	pszSuffix PTR
	cchSuffix INT32
	nScheme INT32
ENDS

PARSEDURLW STRUCT
	cbSize DD
    // Pointers into the buffer that was provided to ParseURL
	pszProtocol PTR
	cchProtocol INT32
	pszSuffix PTR
	cchSuffix INT32
	nScheme INT32
ENDS

#define DLLVER_PLATFORM_WINDOWS  0x00000001
#define DLLVER_PLATFORM_NT  0x00000002

DLLVERSIONINFO2 STRUCT
	info1 DLLVERSIONINFO <>
	wFlags DD
	ullVersion DQ
ENDS

#define DLLVER_MAJOR_MASK  0xFFFF000000000000
#define DLLVER_MINOR_MASK  0x0000FFFF00000000
#define DLLVER_BUILD_MASK  0x00000000FFFF0000
#define DLLVER_QFE_MASK  0x000000000000FFFF

#IFDEF UNICODE
	#define PARSEDURL PARSEDURLW
	#define ParseURL  ParseURLW
	#define SZ_CONTENTTYPE_HTML SZ_CONTENTTYPE_HTMLW
	#define SZ_CONTENTTYPE_CDF SZ_CONTENTTYPE_CDFW
	#define StrCmpNC  StrCmpNCW
	#define StrCmpNIC  StrCmpNICW
	#define IntlStrEqN IntlStrEqNW
	#define IntlStrEqNI IntlStrEqNIW
	#define StrRetToStr StrRetToStrW
	#define StrRetToBuf StrRetToBufW
	#define SHStrDup SHStrDupW
	#define StrChr StrChrW
	#define StrRChr StrRChrW
	#define StrChrI StrChrIW
	#define StrRChrI StrRChrIW
	#define StrCmpC  StrCmpCW
	#define StrCmpIC  StrCmpICW
	#define StrCmpN StrCmpNW
	#define StrCmpNI StrCmpNIW
	#define StrStr StrStrW
	#define StrStrI StrStrIW
	#define StrDup StrDupW
	#define StrRStrI StrRStrIW
	#define StrCSpn StrCSpnW
	#define StrCSpnI StrCSpnIW
	#define StrSpn StrSpnW
	#define StrToInt StrToIntW
	#define StrPBrk StrPBrkW
	#define StrToIntEx StrToIntExW
	#define StrToInt64Ex StrToInt64ExW
	#define StrIntlEqN StrIntlEqNW
	#define StrIntlEqNI StrIntlEqNIW
	#define StrIsIntlEqual StrIsIntlEqualW
	#define StrFromTimeInterval StrFromTimeIntervalW
	#define StrFormatByteSize StrFormatByteSizeW
	#define StrFormatByteSize64 StrFormatByteSizeW
	#define StrFormatKBSize StrFormatKBSizeW
	#define StrNCat StrNCatW
	#define StrTrim StrTrimW
	#define StrCatBuff StrCatBuffW
	#define ChrCmpI ChrCmpIW
	#define wvnsprintf wvnsprintfW
	#define wnsprintf wnsprintfW
	#define StrCatBuff StrCatBuffW
	#define PathAddBackslash PathAddBackslashW
	#define PathAddExtension PathAddExtensionW
	#define PathBuildRoot PathBuildRootW
	#define PathCombine PathCombineW
	#define PathFileExists PathFileExistsW
	#define PathFindExtension PathFindExtensionW
	#define PathFindFileName PathFindFileNameW
	#define PathFindNextComponent PathFindNextComponentW
	#define PathGetArgs PathGetArgsW
	#define PathFindSuffixArray PathFindSuffixArrayW
	#define PathIsLFNFileSpec PathIsLFNFileSpecW
	#define PathGetDriveNumber PathGetDriveNumberW
	#define PathIsDirectory PathIsDirectoryW
	#define PathIsDirectoryEmpty PathIsDirectoryEmptyW
	#define PathIsFileSpec PathIsFileSpecW
	#define PathIsPrefix PathIsPrefixW
	#define PathIsRelative PathIsRelativeW
	#define PathIsRoot PathIsRootW
	#define PathIsSameRoot PathIsSameRootW
	#define PathIsUNC PathIsUNCW
	#define PathIsNetworkPath PathIsNetworkPathW
	#define PathIsUNCServer PathIsUNCServerW
	#define PathIsUNCServerShare PathIsUNCServerShareW
	#define PathIsURL PathIsURLW
	#define PathRemoveBackslash PathRemoveBackslashW
	#define PathSkipRoot PathSkipRootW
	#define PathStripPath PathStripPathW
	#define PathStripToRoot PathStripToRootW
	#define PathMakeSystemFolder PathMakeSystemFolderW
	#define PathUnmakeSystemFolder PathUnmakeSystemFolderW
	#define PathIsSystemFolder PathIsSystemFolderW
	#define PathUndecorate PathUndecorateW
	#define PathUnExpandEnvStrings PathUnExpandEnvStringsW
	#define PathAppend PathAppendW
	#define PathCanonicalize PathCanonicalizeW
	#define PathCompactPath PathCompactPathW
	#define PathCompactPathEx PathCompactPathExW
	#define PathCommonPrefix PathCommonPrefixW
	#define PathFindOnPath PathFindOnPathW
	#define PathGetCharType PathGetCharTypeW
	#define PathIsContentType PathIsContentTypeW
	#define PathMakePretty PathMakePrettyW
	#define PathMatchSpec PathMatchSpecW
	#define PathParseIconLocation PathParseIconLocationW
	#define PathQuoteSpaces PathQuoteSpacesW
	#define PathRelativePathTo PathRelativePathToW
	#define PathRemoveArgs PathRemoveArgsW
	#define PathRemoveBlanks PathRemoveBlanksW
	#define PathRemoveExtension PathRemoveExtensionW
	#define PathRemoveFileSpec PathRemoveFileSpecW
	#define PathRenameExtension PathRenameExtensionW
	#define PathSearchAndQualify PathSearchAndQualifyW
	#define PathSetDlgItemPath PathSetDlgItemPathW
	#define PathUnquoteSpaces PathUnquoteSpacesW
	#define UrlCompare UrlCompareW
	#define UrlCombine UrlCombineW
	#define UrlCanonicalize UrlCanonicalizeW
	#define UrlIsOpaque UrlIsOpaqueW
	#define UrlIsFileUrl UrlIsFileUrlW
	#define UrlGetLocation UrlGetLocationW
	#define UrlUnescape UrlUnescapeW
	#define UrlEscape UrlEscapeW
	#define UrlCreateFromPath UrlCreateFromPathW
	#define PathCreateFromUrl PathCreateFromUrlW
	#define UrlHash UrlHashW
	#define UrlGetPart UrlGetPartW
	#define UrlApplyScheme UrlApplySchemeW
	#define UrlIs UrlIsW
	#define UrlFixup UrlFixupW
	#define SHDeleteEmptyKey SHDeleteEmptyKeyW
	#define SHDeleteKey SHDeleteKeyW
	#define SHDeleteValue SHDeleteValueW
	#define SHGetValue SHGetValueW
	#define SHSetValue SHSetValueW
	#define SHQueryValueEx SHQueryValueExW
	#define SHEnumKeyEx SHEnumKeyExW
	#define SHEnumValue SHEnumValueW
	#define SHQueryInfoKey SHQueryInfoKeyW
	#define SHCopyKey SHCopyKeyW
	#define SHRegGetPath SHRegGetPathW
	#define SHRegSetPath SHRegSetPathW
	#define SHRegCreateUSKey SHRegCreateUSKeyW
	#define SHRegOpenUSKey SHRegOpenUSKeyW
	#define SHRegQueryUSValue SHRegQueryUSValueW
	#define SHRegWriteUSValue SHRegWriteUSValueW
	#define SHRegDeleteUSValue SHRegDeleteUSValueW
	#define SHRegDeleteEmptyUSKey SHRegDeleteEmptyUSKeyW
	#define SHRegEnumUSKey SHRegEnumUSKeyW
	#define SHRegEnumUSValue SHRegEnumUSValueW
	#define SHRegQueryInfoUSKey SHRegQueryInfoUSKeyW
	#define SHRegGetUSValue SHRegGetUSValueW
	#define SHRegSetUSValue SHRegSetUSValueW
	#define SHRegGetInt SHRegGetIntW
	#define SHRegGetBoolUSValue SHRegGetBoolUSValueW
	#define AssocQueryString AssocQueryStringW
	#define AssocQueryStringByKey AssocQueryStringByKeyW
	#define AssocQueryKey AssocQueryKeyW
	#define SHOpenRegStream SHOpenRegStreamW
	#define SHOpenRegStream2 SHOpenRegStream2W
	#define SHCreateStreamOnFile SHCreateStreamOnFileW
	#define SHLocalStrDup SHLocalStrDupW
	#define IsCharSpace  IsCharSpaceW
	#define SHRegGetValue SHRegGetValueW
	#define GetAcceptLanguages GetAcceptLanguagesW
	#define SHFormatDateTime SHFormatDateTimeW
	#define SHMessageBoxCheck SHMessageBoxCheckW
	#define SHSendMessageBroadcast SHSendMessageBroadcastW
	#define SHStripMneumonic SHStripMneumonicW
#else
	#define PARSEDURL PARSEDURA
	#define ParseURL  ParseURLA
	#define SZ_CONTENTTYPE_HTML SZ_CONTENTTYPE_HTMLA
	#define SZ_CONTENTTYPE_CDF SZ_CONTENTTYPE_CDFA
	#define StrCmpNC  StrCmpNCA
	#define StrCmpNIC  StrCmpNICA
	#define IntlStrEqN IntlStrEqNA
	#define IntlStrEqNI IntlStrEqNIA
	#define StrRetToStr StrRetToStrA
	#define StrRetToBuf StrRetToBufA
	#define SHStrDup SHStrDupA
	#define StrChr StrChrA
	#define StrRChr StrRChrA
	#define StrChrI StrChrIA
	#define StrRChrI StrRChrIA
	#define StrCmpIC  StrCmpICA
	#define StrCmpC  StrCmpCA
	#define StrCmpN StrCmpNA
	#define StrCmpNI StrCmpNIA
	#define StrStr StrStrA
	#define StrStrI StrStrIA
	#define StrDup StrDupA
	#define StrRStrI StrRStrIA
	#define StrCSpn StrCSpnA
	#define StrCSpnI StrCSpnIA
	#define StrSpn StrSpnA
	#define StrToInt StrToIntA
	#define StrPBrk StrPBrkA
	#define StrToIntEx StrToIntExA
	#define StrIntlEqN StrIntlEqNA
	#define StrIntlEqNI StrIntlEqNIA
	#define StrIsIntlEqual StrIsIntlEqualA
	#define StrToInt64Ex StrToInt64ExA
	#define StrFromTimeInterval StrFromTimeIntervalA
	#define StrFormatByteSize StrFormatByteSizeA
	#define StrFormatByteSize64 StrFormatByteSize64A
	#define StrFormatKBSize StrFormatKBSizeA
	#define StrNCat StrNCatA
	#define StrTrim StrTrimA
	#define StrCatBuff StrCatBuffA
	#define ChrCmpI ChrCmpIA
	#define wvnsprintf wvnsprintfA
	#define wnsprintf wnsprintfA
	#define StrCatBuff StrCatBuffA
	#define PathAddBackslash PathAddBackslashA
	#define PathAddExtension PathAddExtensionA
	#define PathBuildRoot PathBuildRootA
	#define PathCombine PathCombineA
	#define PathFileExists PathFileExistsA
	#define PathFindExtension PathFindExtensionA
	#define PathFindFileName PathFindFileNameA
	#define PathFindNextComponent PathFindNextComponentA
	#define PathGetArgs PathGetArgsA
	#define PathFindSuffixArray PathFindSuffixArrayA
	#define PathIsLFNFileSpec PathIsLFNFileSpecA
	#define PathGetDriveNumber PathGetDriveNumberA
	#define PathIsDirectory PathIsDirectoryA
	#define PathIsDirectoryEmpty PathIsDirectoryEmptyA
	#define PathIsFileSpec PathIsFileSpecA
	#define PathIsPrefix PathIsPrefixA
	#define PathIsRelative PathIsRelativeA
	#define PathIsRoot PathIsRootA
	#define PathIsSameRoot PathIsSameRootA
	#define PathIsUNC PathIsUNCA
	#define PathIsNetworkPath PathIsNetworkPathA
	#define PathIsUNCServer PathIsUNCServerA
	#define PathIsUNCServerShare PathIsUNCServerShareA
	#define PathIsURL PathIsURLA
	#define PathRemoveBackslash PathRemoveBackslashA
	#define PathSkipRoot PathSkipRootA
	#define PathStripPath PathStripPathA
	#define PathStripToRoot PathStripToRootA
	#define PathMakeSystemFolder PathMakeSystemFolderA
	#define PathUnmakeSystemFolder PathUnmakeSystemFolderA
	#define PathIsSystemFolder PathIsSystemFolderA
	#define PathUndecorate PathUndecorateA
	#define PathUnExpandEnvStrings PathUnExpandEnvStringsA
	#define PathAppend PathAppendA
	#define PathCanonicalize PathCanonicalizeA
	#define PathCompactPath PathCompactPathA
	#define PathCompactPathEx PathCompactPathExA
	#define PathCommonPrefix PathCommonPrefixA
	#define PathFindOnPath PathFindOnPathA
	#define PathGetCharType PathGetCharTypeA
	#define PathIsContentType PathIsContentTypeA
	#define PathMakePretty PathMakePrettyA
	#define PathMatchSpec PathMatchSpecA
	#define PathParseIconLocation PathParseIconLocationA
	#define PathQuoteSpaces PathQuoteSpacesA
	#define PathRelativePathTo PathRelativePathToA
	#define PathRemoveArgs PathRemoveArgsA
	#define PathRemoveBlanks PathRemoveBlanksA
	#define PathRemoveExtension PathRemoveExtensionA
	#define PathRemoveFileSpec PathRemoveFileSpecA
	#define PathRenameExtension PathRenameExtensionA
	#define PathSearchAndQualify PathSearchAndQualifyA
	#define PathSetDlgItemPath PathSetDlgItemPathA
	#define PathUnquoteSpaces PathUnquoteSpacesA
	#define UrlCompare UrlCompareA
	#define UrlCombine UrlCombineA
	#define UrlCanonicalize UrlCanonicalizeA
	#define UrlIsOpaque UrlIsOpaqueA
	#define UrlIsFileUrl UrlIsFileUrlA
	#define UrlGetLocation UrlGetLocationA
	#define UrlUnescape UrlUnescapeA
	#define UrlEscape UrlEscapeA
	#define UrlCreateFromPath UrlCreateFromPathA
	#define PathCreateFromUrl PathCreateFromUrlA
	#define UrlHash UrlHashA
	#define UrlGetPart UrlGetPartA
	#define UrlApplyScheme UrlApplySchemeA
	#define UrlIs UrlIsA
	#define UrlFixup UrlFixupA
	#define SHDeleteEmptyKey SHDeleteEmptyKeyA
	#define SHDeleteKey SHDeleteKeyA
	#define SHDeleteValue SHDeleteValueA
	#define SHGetValue SHGetValueA
	#define SHSetValue SHSetValueA
	#define SHQueryValueEx SHQueryValueExA
	#define SHEnumKeyEx SHEnumKeyExA
	#define SHEnumValue SHEnumValueA
	#define SHQueryInfoKey SHQueryInfoKeyA
	#define SHCopyKey SHCopyKeyA
	#define SHRegGetPath SHRegGetPathA
	#define SHRegSetPath SHRegSetPathA
	#define SHRegCreateUSKey SHRegCreateUSKeyA
	#define SHRegOpenUSKey SHRegOpenUSKeyA
	#define SHRegQueryUSValue SHRegQueryUSValueA
	#define SHRegWriteUSValue SHRegWriteUSValueA
	#define SHRegDeleteUSValue SHRegDeleteUSValueA
	#define SHRegDeleteEmptyUSKey SHRegDeleteEmptyUSKeyA
	#define SHRegEnumUSKey SHRegEnumUSKeyA
	#define SHRegEnumUSValue SHRegEnumUSValueA
	#define SHRegQueryInfoUSKey SHRegQueryInfoUSKeyA
	#define SHRegGetUSValue SHRegGetUSValueA
	#define SHRegSetUSValue SHRegSetUSValueA
	#define SHRegGetBoolUSValue SHRegGetBoolUSValueA
	#define AssocQueryString AssocQueryStringA
	#define AssocQueryStringByKey AssocQueryStringByKeyA
	#define AssocQueryKey AssocQueryKeyA
	#define SHOpenRegStream SHOpenRegStreamA
	#define SHOpenRegStream2 SHOpenRegStream2A
	#define SHCreateStreamOnFile SHCreateStreamOnFileA
	#define SHLocalStrDup SHLocalStrDupA
	#define IsCharSpace  IsCharSpaceA
	#define SHRegGetValue  SHRegGetValueA
	#define GetAcceptLanguages GetAcceptLanguagesA
	#define SHFormatDateTime SHFormatDateTimeA
	#define SHMessageBoxCheck SHMessageBoxCheckA
	#define SHSendMessageBroadcast SHSendMessageBroadcastA
	#define SHStripMneumonic SHStripMneumonicA
#endif

#undef SHOpenRegStream
#define SHOpenRegStream SHOpenRegStream2

GUID_IID_IQueryAssociations <0xc46ca590,0x3c3f,0x11d2,<0xbe,0xe6,0x00,0x00,0xf8,0x05,0xca,0x57>>

#IFNDEF IQueryAssociations
	IQueryAssociations STRUCT
		UNION
			struct
				QueryInterface		PTR
				AddRef				PTR
				Release				PTR
			ends
			IUnknown Unknown
		ENDUNION
		Init PTR
		GetString PTR
		GetKey PTR
		GetData PTR
		GetEnum PTR
	ENDS
#ENDIF

#endif

