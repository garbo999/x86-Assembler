#ifndef SHELLAPI_H
#define SHELLAPI_H

#DEFINE SHELLAPI_H_REQVER 100

/*
Switches used
SHUSEORDINALS = Default to settlement API by ordinal
SHVISTAORDINALS = Use undocumented Vista ordinals
SHUSEUNDOC = Defines certain undocumented APIs by ordinal
VISTA = Target OS is Windows Vista
UNICODE = Use UNICODE versions
*/

/* Windows Shell API definitions */

#IFNDEF POINT
	POINT STRUCT
		x DD
		y DD
	ENDS
#ENDIF

#IFNDEF MAX_PATH
	#define MAX_PATH 260
#ENDIF

#IFNDEF RECT
	RECT STRUCT
		left DD
		top DD
		right DD
		bottom DD
	ENDS
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile Shell32.dll
#ENDIF

#define ABM_NEW  0x00000000
#define ABM_REMOVE  0x00000001
#define ABM_QUERYPOS  0x00000002
#define ABM_SETPOS  0x00000003
#define ABM_GETSTATE  0x00000004
#define ABM_GETTASKBARPOS  0x00000005
#define ABM_ACTIVATE  0x00000006
#define ABM_GETAUTOHIDEBAR  0x00000007
#define ABM_SETAUTOHIDEBAR  0x00000008
#define ABM_WINDOWPOSCHANGED  0x00000009
#define ABM_SETSTATE         0x0000000a

#define ABN_STATECHANGE  0x00000000
#define ABN_POSCHANGED  0x00000001
#define ABN_FULLSCREENAPP  0x00000002
#define ABN_WINDOWARRANGE  0x00000003

#define ABS_AUTOHIDE  0x00000001
#define ABS_ALWAYSONTOP  0x00000002

#define ABE_LEFT  0
#define ABE_TOP  1
#define ABE_RIGHT  2
#define ABE_BOTTOM  3

#IF WINVER >= NTDDI_VISTA
	QUNS_NOT_PRESENT               = 1    // The user is not present.  Heuristic check for modes like: screen saver, locked machine, non-active FUS session
	QUNS_BUSY                      = 2    // The user is busy.  Heuristic check for modes like: full-screen app
	QUNS_RUNNING_D3D_FULL_SCREEN   = 3    // full-screen (exlusive-mode) D3D app
	QUNS_PRESENTATION_MODE         = 4    // Windows presentation mode (laptop feature) is turned on
	QUNS_ACCEPTS_NOTIFICATIONS     = 5    // notifications can be freely sent
#ENDIF
#if WINVER >= NTDDI_WIN7
	QUNS_QUIET_TIME           = 6    // We are in OOBE quiet period
#endif

#define SE_ERR_FNF  2
#define SE_ERR_PNF  3
#define SE_ERR_ACCESSDENIED  5
#define SE_ERR_OOM  8
#define SE_ERR_SHARE  26
#define SE_ERR_ASSOCINCOMPLETE  27
#define SE_ERR_DDETIMEOUT  28
#define SE_ERR_DDEFAIL  29
#define SE_ERR_DDEBUSY  30
#define SE_ERR_NOASSOC  31
#define SE_ERR_DLLNOTFOUND  32

#define SEE_MASK_CLASSNAME  0x00000001
#define SEE_MASK_CLASSKEY  0x00000003
#define SEE_MASK_IDLIST  0x00000004
#define SEE_MASK_INVOKEIDLIST  0x0000000c
#IF WINVER < NTDDI_VISTA
#define SEE_MASK_ICON  0x00000010
#ENDIF
#define SEE_MASK_HOTKEY  0x00000020
#define SEE_MASK_NOCLOSEPROCESS  0x00000040
#define SEE_MASK_CONNECTNETDRV  0x00000080
#define SEE_MASK_FLAG_DDEWAIT  0x00000100
#define SEE_MASK_DOENVSUBST  0x00000200
#define SEE_MASK_FLAG_NO_UI  0x00000400
#define SEE_MASK_UNICODE  0x00004000
#define SEE_MASK_NO_CONSOLE  0x00008000
#define SEE_MASK_ASYNCOK  0x00100000
#define SEE_MASK_HMONITOR  0x00200000
#IF WINVER >= NTDDI_WINXPSP1
#define SEE_MASK_NOZONECHECKS      0x00800000
#ENDIF
#define SEE_MASK_NOQUERYCLASSSTORE  0x01000000
#define SEE_MASK_WAITFORINPUTIDLE  0x02000000
#IF WINVER >= NTDDI_WINXP
#define SEE_MASK_FLAG_LOG_USAGE    0x04000000
#ENDIF

#IF WINVER >= NTDDI_VISTA

	ASSOCCLASS_SHELL_KEY = 0       //  hkeyClass
	ASSOCCLASS_PROGID_KEY = 1      //  hkeyClass
	ASSOCCLASS_PROGID_STR = 2      //  pszClass (HKCR\pszClass)
	ASSOCCLASS_CLSID_KEY = 3       //  hkeyClass
	ASSOCCLASS_CLSID_STR = 4       //  pszClass (HKCR\CLSID\pszClass)
	ASSOCCLASS_APP_KEY = 5         //  hkeyClass
	ASSOCCLASS_APP_STR = 6         //  pszClass (HKCR\Applications\PathFindFileName(pszClass))
	ASSOCCLASS_SYSTEM_STR = 7      //  pszClass
	ASSOCCLASS_FOLDER = 8          //  none
	ASSOCCLASS_STAR = 9            //  none

	ASSOCIATIONELEMENT STRUCT
		ac DD              // required
		hkClass HANDLE               // may be NULL
		pszClass PTR            // may be NULL
	ENDS
#ENDIF

#define SHERB_NOCONFIRMATION  0x00000001
#define SHERB_NOPROGRESSUI  0x00000002
#define SHERB_NOSOUND  0x00000004

QUNS_NOT_PRESENT               = 1    // The user is not present.  Heuristic check for modes like: screen saver, locked machine, non-active FUS session
QUNS_BUSY                      = 2    // The user is busy.  Heuristic check for modes like: full-screen app
QUNS_RUNNING_D3D_FULL_SCREEN   = 3    // full-screen (exlusive-mode) D3D app
QUNS_PRESENTATION_MODE         = 4    // Windows presentation mode (laptop feature) is turned on
QUNS_ACCEPTS_NOTIFICATIONS     = 5    // none of the above
#if WINVER >= NTDDI_WIN7
	QUNS_QUIET_TIME           = 6     // We are in OOBE quiet period
#endif

#define NIM_ADD  0x00000000
#define NIM_MODIFY  0x00000001
#define NIM_DELETE  0x00000002

#define NIF_MESSAGE  0x00000001
#define NIF_ICON  0x00000002
#define NIF_TIP  0x00000004

#define NIN_SELECT  (WM_USER+0)
#define NIN_KEYSELECT  (NIN_SELECT|NINF_KEY)
#define NINF_KEY  0x1

#define NIN_BALLOONSHOW  (WM_USER+2)
#define NIN_BALLOONHIDE  (WM_USER+3)
#define NIN_BALLOONTIMEOUT  (WM_USER+4)
#define NIN_BALLOONUSERCLICK  (WM_USER+5)
#define NIN_POPUPOPEN           (WM_USER + 6)
#define NIN_POPUPCLOSE          (WM_USER + 7)

#define NIM_SETFOCUS  0x00000003
#define NIM_SETVERSION  0x00000004

#define NOTIFYICON_VERSION 3
#define NOTIFYICON_VERSION_4 4

#define NIF_STATE  0x00000008
#define NIF_INFO  0x00000010
#define NIF_GUID        0x00000020
#define NIF_REALTIME    0x00000040
#define NIF_SHOWTIP     0x00000080

#define NIS_HIDDEN  0x00000001
#define NIS_SHAREDICON  0x00000002

#define NIIF_NONE  0x00000000
#define NIIF_INFO  0x00000001
#define NIIF_WARNING  0x00000002
#define NIIF_ERROR  0x00000003
#IF WINVER >= NTDDI_WINXPSP2
#define NIIF_USER       0x00000004
#ENDIF
#define NIIF_ICON_MASK  0x0000000F
#define NIIF_NOSOUND  0x00000010
#IF WINVER >= NTDDI_VISTA
#define NIIF_LARGE_ICON 0x00000020
#ENDIF
#IF WINVER >= NTDDI_WIN7
#define NIIF_RESPECT_QUIET_TIME 0x00000080
#ENDIF

#define SHGFI_ICON  0x000000100
#define SHGFI_DISPLAYNAME  0x000000200
#define SHGFI_TYPENAME  0x000000400
#define SHGFI_ATTRIBUTES  0x000000800
#define SHGFI_ICONLOCATION  0x000001000
#define SHGFI_EXETYPE  0x000002000
#define SHGFI_SYSICONINDEX  0x000004000
#define SHGFI_LINKOVERLAY  0x000008000
#define SHGFI_SELECTED  0x000010000
#define SHGFI_ATTR_SPECIFIED  0x000020000
#define SHGFI_LARGEICON  0x000000000
#define SHGFI_SMALLICON  0x000000001
#define SHGFI_OPENICON  0x000000002
#define SHGFI_SHELLICONSIZE  0x000000004
#define SHGFI_PIDL  0x000000008
#define SHGFI_USEFILEATTRIBUTES  0x000000010
#define SHGFI_ADDOVERLAYS  0x000000020
#define SHGFI_OVERLAYINDEX  0x000000040

#if WINVER >= NTDDI_VISTA
SHSTOCKICONINFO STRUCT
	cbSize DD
	hIcon HANDLE
	iSysImageIndex DD
	iIcon DD
	szPath WCHAR MAX_PATH DUP
ENDS

#define SHGSI_ICONLOCATION      0 // you always get the icon location
#define SHGSI_ICON              SHGFI_ICON
#define SHGSI_SYSICONINDEX      SHGFI_SYSICONINDEX
#define SHGSI_LINKOVERLAY       SHGFI_LINKOVERLAY
#define SHGSI_SELECTED          SHGFI_SELECTED
#define SHGSI_LARGEICON         SHGFI_LARGEICON
#define SHGSI_SMALLICON         SHGFI_SMALLICON
#define SHGSI_SHELLICONSIZE     SHGFI_SHELLICONSIZE

//  Shell icons

SIID_DOCNOASSOC = 0          // document (blank page), no associated program
SIID_DOCASSOC = 1            // document with an associated program
SIID_APPLICATION = 2         // generic application with no custom icon
SIID_FOLDER = 3              // folder (closed)
SIID_FOLDEROPEN = 4          // folder (open)
SIID_DRIVE525 = 5            // 5.25" floppy disk drive
SIID_DRIVE35 = 6             // 3.5" floppy disk drive
SIID_DRIVEREMOVE = 7         // removable drive
SIID_DRIVEFIXED = 8          // fixed (hard disk) drive
SIID_DRIVENET = 9            // network drive
SIID_DRIVENETDISABLED = 10   // disconnected network drive
SIID_DRIVECD = 11            // CD drive
SIID_DRIVERAM = 12           // RAM disk drive
SIID_WORLD = 13              // entire network
SIID_SERVER = 15             // a computer on the network
SIID_PRINTER = 16            // printer
SIID_MYNETWORK = 17          // My network places
SIID_FIND = 22               // Find
SIID_HELP = 23               // Help
SIID_SHARE = 28              // overlay for shared items
SIID_LINK = 29               // overlay for shortcuts to items
SIID_SLOWFILE = 30           // overlay for slow items
SIID_RECYCLER = 31           // empty recycle bin
SIID_RECYCLERFULL = 32       // full recycle bin
SIID_MEDIACDAUDIO = 40       // Audio CD Media
SIID_LOCK = 47               // Security lock
SIID_AUTOLIST = 49           // AutoList
SIID_PRINTERNET = 50         // Network printer
SIID_SERVERSHARE = 51        // Server share
SIID_PRINTERFAX = 52         // Fax printer
SIID_PRINTERFAXNET = 53      // Networked Fax Printer
SIID_PRINTERFILE = 54        // Print to File
SIID_STACK = 55              // Stack
SIID_MEDIASVCD = 56          // SVCD Media
SIID_STUFFEDFOLDER = 57      // Folder containing other items
SIID_DRIVEUNKNOWN = 58       // Unknown drive
SIID_DRIVEDVD = 59           // DVD Drive
SIID_MEDIADVD = 60           // DVD Media
SIID_MEDIADVDRAM = 61        // DVD-RAM Media
SIID_MEDIADVDRW = 62         // DVD-RW Media
SIID_MEDIADVDR = 63          // DVD-R Media
SIID_MEDIADVDROM = 64        // DVD-ROM Media
SIID_MEDIACDAUDIOPLUS = 65   // CD+ (Enhanced CD) Media
SIID_MEDIACDRW = 66          // CD-RW Media
SIID_MEDIACDR = 67           // CD-R Media
SIID_MEDIACDBURN = 68        // Burning CD
SIID_MEDIABLANKCD = 69       // Blank CD Media
SIID_MEDIACDROM = 70         // CD-ROM Media
SIID_AUDIOFILES = 71         // Audio files
SIID_IMAGEFILES = 72         // Image files
SIID_VIDEOFILES = 73         // Video files
SIID_MIXEDFILES = 74         // Mixed files
SIID_FOLDERBACK = 75         // Folder back
SIID_FOLDERFRONT = 76        // Folder front
SIID_SHIELD = 77             // Security shield. Use for UAC prompts only.
SIID_WARNING = 78            // Warning
SIID_INFO = 79               // Informational
SIID_ERROR = 80              // Error
SIID_KEY = 81                // Key / Secure
SIID_SOFTWARE = 82           // Software
SIID_RENAME = 83             // Rename
SIID_DELETE = 84             // Delete
SIID_MEDIAAUDIODVD = 85      // Audio DVD Media
SIID_MEDIAMOVIEDVD = 86      // Movie DVD Media
SIID_MEDIAENHANCEDCD = 87    // Enhanced CD Media
SIID_MEDIAENHANCEDDVD = 88   // Enhanced DVD Media
SIID_MEDIAHDDVD = 89         // HD-DVD Media
SIID_MEDIABLURAY = 90        // BluRay Media
SIID_MEDIAVCD = 91           // VCD Media
SIID_MEDIADVDPLUSR = 92      // DVD+R Media
SIID_MEDIADVDPLUSRW = 93     // DVD+RW Media
SIID_DESKTOPPC = 94          // desktop computer
SIID_MOBILEPC = 95           // mobile computer (laptop/notebook)
SIID_USERS = 96              // users
SIID_MEDIASMARTMEDIA = 97    // Smart Media
SIID_MEDIACOMPACTFLASH = 98  // Compact Flash
SIID_DEVICECELLPHONE = 99    // Cell phone
SIID_DEVICECAMERA = 100      // Camera
SIID_DEVICEVIDEOCAMERA = 101 // Video camera
SIID_DEVICEAUDIOPLAYER = 102 // Audio player
SIID_NETWORKCONNECT = 103    // Connect to network
SIID_INTERNET = 104          // Internet
SIID_ZIPFILE = 105           // ZIP file
SIID_SETTINGS = 106          // Settings
// 107-131 are internal Vista RTM icons
// 132-159 for SP1 icons
SIID_DRIVEHDDVD = 132        // HDDVD Drive (all types)
SIID_DRIVEBD = 133           // BluRay Drive (all types)
SIID_MEDIAHDDVDROM = 134     // HDDVD-ROM Media
SIID_MEDIAHDDVDR = 135       // HDDVD-R Media
SIID_MEDIAHDDVDRAM = 136     // HDDVD-RAM Media
SIID_MEDIABDROM = 137        // BluRay ROM Media
SIID_MEDIABDR = 138          // BluRay R Media
SIID_MEDIABDRE = 139         // BluRay RE Media (Rewriable and RAM)
SIID_CLUSTEREDDRIVE = 140    // Clustered disk
// 160+ are for Windows 7 icons
SIID_MAX_ICONS = 174

#define SIID_INVALID -1

#endif // (NTDDI_VERSION >= NTDDI_VISTA)

#define SHGSI_ICONLOCATION      0 // you always get the icon location
#define SHGSI_ICON              SHGFI_ICON
#define SHGSI_SYSICONINDEX      SHGFI_SYSICONINDEX
#define SHGSI_LINKOVERLAY       SHGFI_LINKOVERLAY
#define SHGSI_SELECTED          SHGFI_SELECTED
#define SHGSI_LARGEICON         SHGFI_LARGEICON
#define SHGSI_SMALLICON         SHGFI_SMALLICON
#define SHGSI_SHELLICONSIZE     SHGFI_SHELLICONSIZE

#define SHGNLI_PIDL  0x000000001
#define SHGNLI_PREFIXNAME  0x000000002
#define SHGNLI_NOUNIQUE  0x000000004
#define SHGNLI_NOLNK  0x000000008
#define SHGNLI_NOLOCNAME        0x000000010
#if WINVER >= NTDDI_WIN7
#define SHGNLI_USEURLEXT        0x000000020     // use ".url" extension instead of ".lnk"
#endif

#define PRINTACTION_OPEN  0
#define PRINTACTION_PROPERTIES  1
#define PRINTACTION_NETINSTALL  2
#define PRINTACTION_NETINSTALLLINK  3
#define PRINTACTION_TESTPAGE  4
#define PRINTACTION_OPENNETPRN  5
#define PRINTACTION_DOCUMENTDEFAULTS  6
#define PRINTACTION_SERVERPROPERTIES  7

SIID_DOCNOASSOC = 0          // document (blank page) no associated program
SIID_DOCASSOC = 1            // document with an associated program
SIID_APPLICATION = 2         // generic application with no custom icon
SIID_FOLDER = 3              // folder (closed)
SIID_FOLDEROPEN = 4          // folder (open)
SIID_DRIVE525 = 5            // 5.25" floppy disk drive
SIID_DRIVE35 = 6             // 3.5" floppy disk drive
SIID_DRIVEREMOVE = 7         // removable drive
SIID_DRIVEFIXED = 8          // fixed (hard disk) drive
SIID_DRIVENET = 9            // network drive
SIID_DRIVENETDISABLED = 10   // disconnected network drive
SIID_DRIVECD = 11            // CD drive
SIID_DRIVERAM = 12           // RAM disk drive
SIID_WORLD = 13              // entire network
SIID_SERVER = 15             // a computer on the network
SIID_PRINTER = 16            // printer
SIID_MYNETWORK = 17          // My network places
SIID_FIND = 22               // Find
SIID_HELP = 23               // Help
SIID_SHARE = 28              // overlay for shared items
SIID_LINK = 29               // overlay for shortcuts to items
SIID_SLOWFILE = 30           // overlay for slow items
SIID_RECYCLER = 31           // empty recycle bin
SIID_RECYCLERFULL = 32       // full recycle bin
SIID_MEDIACDAUDIO = 40       // Audio CD Media
SIID_LOCK = 47               // Security lock
SIID_AUTOLIST = 49           // AutoList
SIID_PRINTERNET = 50         // Network printer
SIID_SERVERSHARE = 51        // Server share
SIID_PRINTERFAX = 52         // Fax printer
SIID_PRINTERFAXNET = 53      // Networked Fax Printer
SIID_PRINTERFILE = 54        // Print to File
SIID_STACK = 55              // Stack
SIID_MEDIASVCD = 56          // SVCD Media
SIID_STUFFEDFOLDER = 57      // Folder containing other items
SIID_DRIVEUNKNOWN = 58       // Unknown drive
SIID_DRIVEDVD = 59           // DVD Drive
SIID_MEDIADVD = 60           // DVD Media
SIID_MEDIADVDRAM = 61        // DVD-RAM Media
SIID_MEDIADVDRW = 62         // DVD-RW Media
SIID_MEDIADVDR = 63          // DVD-R Media
SIID_MEDIADVDROM = 64        // DVD-ROM Media
SIID_MEDIACDAUDIOPLUS = 65   // CD+ (Enhanced CD) Media
SIID_MEDIACDRW = 66          // CD-RW Media
SIID_MEDIACDR = 67           // CD-R Media
SIID_MEDIACDBURN = 68        // Burning CD
SIID_MEDIABLANKCD = 69       // Blank CD Media
SIID_MEDIACDROM = 70         // CD-ROM Media
SIID_AUDIOFILES = 71         // Audio files
SIID_IMAGEFILES = 72         // Image files
SIID_VIDEOFILES = 73         // Video files
SIID_MIXEDFILES = 74         // Mixed files
SIID_FOLDERBACK = 75         // Folder back
SIID_FOLDERFRONT = 76        // Folder front
SIID_SHIELD = 77             // Security shield. Use for UAC prompts only.
SIID_WARNING = 78            // Warning
SIID_INFO = 79               // Informational
SIID_ERROR = 80              // Error
SIID_KEY = 81                // Key / Secure
SIID_SOFTWARE = 82           // Software
SIID_RENAME = 83             // Rename
SIID_DELETE = 84             // Delete
SIID_MEDIAAUDIODVD = 85      // Audio DVD Media
SIID_MEDIAMOVIEDVD = 86      // Movie DVD Media
SIID_MEDIAENHANCEDCD = 87    // Enhanced CD Media
SIID_MEDIAENHANCEDDVD = 88   // Enhanced DVD Media
SIID_MEDIAHDDVD = 89         // HD-DVD Media
SIID_MEDIABLURAY = 90        // BluRay Media
SIID_MEDIAVCD = 91           // VCD Media
SIID_MEDIADVDPLUSR = 92      // DVD+R Media
SIID_MEDIADVDPLUSRW = 93     // DVD+RW Media
SIID_DESKTOPPC = 94          // desktop computer
SIID_MOBILEPC = 95           // mobile computer (laptop/notebook)
SIID_USERS = 96              // users
SIID_MEDIASMARTMEDIA = 97    // Smart Media
SIID_MEDIACOMPACTFLASH = 98  // Compact Flash
SIID_DEVICECELLPHONE = 99    // Cell phone
SIID_DEVICECAMERA = 100      // Camera
SIID_DEVICEVIDEOCAMERA = 101 // Video camera
SIID_DEVICEAUDIOPLAYER = 102 // Audio player
SIID_NETWORKCONNECT = 103    // Connect to network
SIID_INTERNET = 104          // Internet
SIID_ZIPFILE = 105           // ZIP file
SIID_SETTINGS = 106          // Settings
// 107-131 are internal Vista RTM icons
// 132+ for SP1 icons
SIID_DRIVEHDDVD = 132        // HDDVD Drive (all types)
SIID_DRIVEBD = 133           // BluRay Drive (all types)
SIID_MEDIAHDDVDROM = 134     // HDDVD-ROM Media
SIID_MEDIAHDDVDR = 135       // HDDVD-R Media
SIID_MEDIAHDDVDRAM = 136     // HDDVD-RAM Media
SIID_MEDIABDROM = 137        // BluRay ROM Media
SIID_MEDIABDR = 138          // BluRay R Media
SIID_MEDIABDRE = 139         // BluRay RE Media (Rewriable and RAM)
SIID_CLUSTEREDDRIVE = 140    // Clustered disk
SIID_MAX_ICONS = 141
SIID_INVALID = -1

#ifndef FO_MOVE
	#define FO_MOVE  0x0001
	#define FO_COPY  0x0002
	#define FO_DELETE  0x0003
	#define FO_RENAME  0x0004
	
	#define PO_DELETE  0x0013
	#define PO_RENAME  0x0014
	#define PO_PORTCHANGE  0x0020
	#define PO_REN_PORT  0x0034
	
	#define FOF_MULTIDESTFILES  0x0001
	#define FOF_CONFIRMMOUSE  0x0002
	#define FOF_SILENT  0x0004
	#define FOF_RENAMEONCOLLISION  0x0008
	#define FOF_NOCONFIRMATION  0x0010
	#define FOF_WANTMAPPINGHANDLE  0x0020
	#define FOF_ALLOWUNDO  0x0040
	#define FOF_FILESONLY  0x0080
	#define FOF_SIMPLEPROGRESS  0x0100
	#define FOF_NOCONFIRMMKDIR  0x0200
	#define FOF_NOERRORUI  0x0400
	#define FOF_NOCOPYSECURITYATTRIBS  0x0800
	#define FOF_NORECURSION  0x1000
	#define FOF_NO_CONNECTED_ELEMENTS  0x2000
	#define FOF_WANTNUKEWARNING  0x4000
	#define FOF_NORECURSEREPARSE  0x8000
#endif

#define OFFLINE_STATUS_LOCAL  0x0001
#define OFFLINE_STATUS_REMOTE  0x0002
#define OFFLINE_STATUS_INCOMPLETE  0x0004

#define WC_NETADDRESS L"msctls_netaddress"

#define SHIL_LARGE          0   // normally 32x32
#define SHIL_SMALL          1   // normally 16x16
#define SHIL_EXTRALARGE     2
#define SHIL_SYSSMALL       3   // like SHIL_SMALL, but tracks system small icon metric correctly
#if WINVER >= NTDDI_VISTA
	#define SHIL_JUMBO          4   // normally 256x256
	#define SHIL_LAST           SHIL_JUMBO
#else
	#define SHIL_LAST           SHIL_SYSSMALL
#ENDIF

DRAGINFOA STRUCT
	uSize DD
	pt POINT <>
	fNC DD
	lpFileList PTR
	grfKeyState DD
ENDS

#define DRAGINFOW DRAGINFOA

APPBARDATA STRUCT
	cbSize DD
	hWnd HANDLE
	uCallbackMessage DD
	uEdge DD
	rc RECT <>
	lParam LPARAM
ENDS

SHFILEOPSTRUCTA STRUCT
	hwnd HANDLE
	wFunc DD
	pFrom PTR
	pTo PTR
	fFlags DD
	fAnyOperationsAborted DD
	hNameMappings PTR
	lpszProgressTitle PTR
ENDS

#define SHFILEOPSTRUCTW SHFILEOPSTRUCTA

SHNAMEMAPPINGA STRUCT
	pszOldPath PTR
	pszNewPath PTR
	cchOldPath DD
	cchNewPath DD
ENDS

#define SHNAMEMAPPINGW SHNAMEMAPPINGA

SHELLEXECUTEINFOA STRUCT
	cbSize DD
	fMask DD
	hwnd HANDLE
	lpVerb PTR
	lpFile PTR
	lpParameters PTR
	lpDirectory PTR
	nShow DD
	hInstApp HANDLE
	lpIDList PTR
	lpClass PTR
	hkeyClass HANDLE
	dwHotKey DD
	UNION
		hIcon HANDLE
		hMonitor HANDLE
	ENDUNION
	hProcess HANDLE
ENDS

#define SHELLEXECUTEINFOW SHELLEXECUTEINFOA

SHCREATEPROCESSINFOW STRUCT
	cbSize DD
	fMask DD
	hwnd HANDLE
	pszFile PTR
	pszParameters PTR
	pszCurrentDirectory PTR
	hUserToken HANDLE
	lpProcessAttributes PTR
	lpThreadAttributes PTR
	bInheritHandles DD
	dwCreationFlags DD
	lpStartupInfo PTR
	lpProcessInformation PTR
ENDS

SHQUERYRBINFO STRUCT
	cbSize DD
	i64Size DQ
	i64NumItems DQ
ENDS

NOTIFYICONDATAA STRUCT
	cbSize DD
	hWnd HANDLE
	uID DD
	uFlags DD
	uCallbackMessage DD
	hIcon HANDLE
	#IF WINVER < NTDDI_WIN2K
		szTip DB 64 DUP
	#ENDIF
	#IF WINVER >= NTDDI_WIN2K
		szTip DB 128 DUP
		dwState DD
		dwStateMask DD
		szInfo DB 256 DUP
		UNION
			uTimeout DD
			uVersion DD
		ENDUNION
		szInfoTitle DB 64 DUP
		dwInfoFlags DD
	#ENDIF
	#IF WINVER >= NTDDI_WINXP
		guidItem GUID
	#ENDIF
	#IF WINVER >= NTDDI_VISTA
		hBalloonIcon HANDLE
	#ENDIF
ENDS

NOTIFYICONDATAW STRUCT
	cbSize DD
	hWnd HANDLE
	uID DD
	uFlags DD
	uCallbackMessage DD
	hIcon HANDLE
	#IF WINVER < NTDDI_WIN2K
		szTip DW 64 DUP
	#ENDIF
	#IF WINVER >= NTDDI_WIN2K
		szTip DW 128 DUP
		dwState DD
		dwStateMask DD
		szInfo DW 256 DUP
		UNION
			uTimeout DD
			uVersion DD
		ENDUNION
		szInfoTitle DW 64 DUP
		dwInfoFlags DD
	#ENDIF
	#IF WINVER >= NTDDI_WINXP
		guidItem GUID
	#ENDIF
	#IF WINVER >= NTDDI_VISTA
		hBalloonIcon HANDLE
	#ENDIF
ENDS

// GoAsm Applications should use SIZEOF

// 32bit WIN9X size
#define NOTIFYICONDATAA_V1_SIZE  88
#define NOTIFYICONDATAW_V1_SIZE  152

// 32bit WIN2K size
#define NOTIFYICONDATAA_V2_SIZE  488
#define NOTIFYICONDATAW_V2_SIZE  936

// 32bit WINXP size
#define NOTIFYICONDATAA_V3_SIZE  504
#define NOTIFYICONDATAW_V3_SIZE  952

// 32bit VISTA size
#define NOTIFYICONDATAA_V4_SIZE  508
#define NOTIFYICONDATAW_V4_SIZE  956

SHFILEINFOA STRUCT
	hIcon HANDLE
	iIcon DD
	dwAttributes DD
	szDisplayName DB MAX_PATH DUP
	szTypeName DB 80 DUP
ENDS

SHFILEINFOW STRUCT
	hIcon HANDLE
	iIcon DD
	dwAttributes DD
	szDisplayName DW MAX_PATH DUP
	szTypeName DW 80 DUP
ENDS

OPEN_PRINTER_PROPS_INFOA STRUCT
	dwSize DD
	pszSheetName PTR
	uSheetIndex DD
	dwFlags DD
	bModal DD
ENDS

OPEN_PRINTER_PROPS_INFOW STRUCT
	dwSize DD
	pszSheetName PTR
	uSheetIndex DD
	dwFlags DD
	bModal DD
ENDS

#IFDEF SHUSEORDINALS

	; Shell32.dll v4.0
	#IF SHELLVER >= WIN32_SHELL_400
		#define SHChangeNotifyRegister SHELL32.DLL:2 // v5
		#define SHChangeNotifyDeregister SHELL32.DLL:4 // v5
		#define PifMgr_OpenProperties SHELL32.DLL:9 // v5
		#define PifMgr_GetProperties SHELL32.DLL:10 // v5
		#define PifMgr_SetProperties SHELL32.DLL:11 // v5
		#define PifMgr_CloseProperties SHELL32.DLL:13 // v5
		#define ILFindLastID SHELL32.DLL:16 // v5
		#define ILRemoveLastID SHELL32.DLL:17 // v5
		#define ILClone SHELL32.DLL:18 // v5
		#define ILCloneFirst SHELL32.DLL:19 // v5
		#define ILIsEqual SHELL32.DLL:21 // v5
		#define ILIsParent SHELL32.DLL:23 // v5
		#define ILFindChild SHELL32.DLL:24 // v5
		#define ILCombine SHELL32.DLL:25 // v5
		#define ILLoadFromStream SHELL32.DLL:26 // v5
		#define ILSaveToStream SHELL32.DLL:27 // v5
		#define SHILCreateFromPath SHELL32.DLL:28 // v5
		#define PathIsExe SHELL32.DLL:43 // v5
		#define PathMakeUniqueName SHELL32.DLL:47 // v5
		#define PathQualify SHELL32.DLL:49
		#define PathResolve SHELL32.DLL:51
		#define RestartDialog Shell32.dll:59
		#define PickIconDlg Shell32.dll:62
		#define GetFileNameFromBrowse Shell32.dll:63
		#define DriveType Shell32.dll:64
		#define IsNetDrive SHELL32.DLL:66
		#define Shell_MergeMenus SHELL32.DLL:67
		#define SHGetSetSettings SHELL32.DLL:68
		#define Shell_GetImageLists Shell32.DLL:71
		#define Shell_GetCachedImageIndex SHELL32.DLL:72
		#define SHShellFolderView_Message SHELL32.DLL:73
		#define SHCreateStdEnumFmtEtc SHELL32.DLL:74
		#define PathYetAnotherMakeUniqueName SHELL32.DLL:75
		#define SHMapPIDLToSystemImageListIndex SHELL32.DLL:77
		#define OpenRegStream SHELL32.DLL:85
		#define SHDoDragDrop SHELL32.DLL:88
		#define SHCloneSpecialIDList SHELL32.DLL:89
		#define SHFindFiles Shell32.DLL:90
		#define PathGetShortPath Shell32.DLL:92
		#define SHWaitForFileToOpen Shell32.dll:97
		#define SHGetRealIDL Shell32.DLL:98
		#define SHRestricted SHELL32.DLL:100
		#define SHCoCreateInstance SHELL32.DLL:102
		#define SignalFileOpen SHELL32.DLL:103
		#define SHFlushClipboard SHELL32.DLL:121
		#define DllGetClassObject SHELL32.DLL:128
		#define DAD_AutoScroll SHELL32.DLL:129
		#define DAD_DragEnter SHELL32.DLL:130
		#define DAD_DragEnterEx SHELL32.DLL:131
		#define DAD_DragLeave SHELL32.DLL:132
		#define DAD_DragMove SHELL32.DLL:133
		#define DAD_SetDragImage SHELL32.DLL:134
		#define DAD_ShowDragImage SHELL32.DLL:135
		#define SHCLSIDFromString SHELL32.DLL:147
		#define SHFind_InitMenuPopup SHELL32.DLL:149
		#define SHLoadOLE SHELL32.DLL:151
		#define ILGetSize SHELL32.DLL:152
		#define ILGetNext SHELL32.DLL:153
		#define ILAppendID SHELL32.DLL:154
		#define ILFree SHELL32.DLL:155
		#define ILCreateFromPath SHELL32.DLL:157
		#define SHSimpleIDListFromPath SHELL32.DLL:162
		#define Win32DeleteFile SHELL32.DLL:164
		#define SHCreateDirectory SHELL32.DLL:165
		#define CallCPLEntry16 SHELL32.DLL:166
		#define SHAddFromPropSheetExtArray SHELL32.DLL:167
		#define SHCreatePropSheetExtArray SHELL32.DLL:168
		#define SHDestroyPropSheetExtArray SHELL32.DLL:169
		#define SHReplaceFromPropSheetExtArray SHELL32.DLL:170
		#define PathCleanupSpec SHELL32.DLL:171
		#define SHValidateUNC SHELL32.DLL:173
		#define SHCreateShellFolderViewEx SHELL32.DLL:174
		#define SHSetInstanceExplorer SHELL32.DLL:176
		#define SHObjectProperties Shell32.DLL:178
		#define SHGetNewLinkInfoA SHELL32.DLL:179
		#define SHGetNewLinkInfoW SHELL32.DLL:180
		#define ShellMessageBoxW SHELL32.DLL:182
		#define ShellMessageBoxA SHELL32.DLL:183
		#define SHFree Shell32.DLL:195
		#define SHAlloc Shell32.DLL:196
		#define ShortSizeFormatW Shell32.DLL:204
		#define SHStartNetConnectionDialog Shell32.DLL:215
		#IF WINVER < NTDDI_VISTA
			#define SHRegCloseKey Shell32.DLL:505
			#define SHRegOpenKeyA SHELL32.DLL:506
			#define SHRegOpenKeyW SHELL32.DLL:507
			#define SHRegQueryValueA SHELL32.DLL:508
			#define SHRegQueryValueW SHELL32.DLL:509
			#define SHRegQueryValueExA SHELL32.DLL:510
			#define SHRegQueryValueExW SHELL32.DLL:511
		#ENDIF
		#define SHRegDeleteKeyW Shell32.DLL:512
		#define SHAllocShared Shell32.DLL:520
		#define SHFreeShared Shell32.DLL:521
		#define SHLockShared Shell32.DLL:522
		#define SHUnlockShared Shell32.DLL:523
		#define RealDriveType SHELL32.DLL:524
		#define SHChangeNotification_Lock SHELL32.DLL:644
		#define SHChangeNotification_Unlock SHELL32.DLL:645
		#define SHWaitOp_Operate SHELL32.DLL:648
		#define WriteCabinetState SHELL32.DLL:652
		#define FileIconInit SHELL32.DLL:660
		#define IsUserAnAdmin SHELL32.DLL:680
	#ENDIF

	; Shell32.dll v4.71
	#IF SHELLVER >= WIN32_SHELL_471
		#IF SHELLVER <= WIN32_SHELL_500
			#define SHStartNetConnectionDialogA SHELL32.DLL:12 // v5
			#define SHStartNetConnectionDialogW SHELL32.DLL:14 // v5
			#define SHOpenPropSheetW SHELL32.DLL:80 // v5
			#define ILCreateFromPathW SHELL32.DLL:190 // v5
			#define SHHandleUpdateImage SHELL32.DLL:193 // v5
			#define SHCreateShellFolderView SHELL32.DLL:256 // v5
			#define ReadCabinetState SHELL32.DLL:654 // v5
			#define CDefFolderMenu_Create2 SHELL32.DLL:701 // v5
		#ENDIF

		#IF SHELLVER <= WIN32_SHELL_600
			#define SHDefExtractIconA SHELL32.DLL:5 // v6
			#define SHDefExtractIconW SHELL32.DLL:6 // v6
			#define SHFlushSFCache SHELL32.DLL:526 // v6
		#ENDIF
	#ENDIF

	; Shell32.dll v5.00
	#IF SHELLVER >= WIN32_SHELL_500
		#define DAD_DragEnterEx2 SHELL32.DLL:22
		#define PathIsSlowW SHELL32.DLL:239
		#define PathIsSlowA SHELL32.DLL:240
		#define SHPropStgCreate SHELL32.DLL:685
		#define SHPropStgReadMultiple SHELL32.DLL:688
		#define SHPropStgWriteMultiple SHELL32.DLL:689
		#define SHGetSetFolderCustomSettingsA SHELL32.DLL:708
		#define SHGetSetFolderCustomSettingsW SHELL32.DLL:709
		#define SHMultiFileProperties SHELL32.DLL:716
	#ENDIF

	; Shell32.dll v6.00
	#IF SHELLVER >= WIN32_SHELL_600
		#define SHMapIDListToImageListIndexAsync SHELL32.DLL:148
		#define SHTestTokenMembership SHELL32.DLL:245
		#define RestartDialogEx SHELL32.DLL:730
		#define SHCreateFileExtractIconW SHELL32.DLL:743
		#define SHLimitInputEdit SHELL32.DLL:747
		#define SHGetShellStyleHInstance SHELL32.DLL:749
		#define SHGetAttributesFromDataObject SHELL32.DLL:750
	#ENDIF

	#IFDEF UNICODE
		#define SHDefExtractIcon SHDefExtractIconW
		#define PathIsSlow PathIsSlowW
		#define SHStartNetConnectionDialog SHStartNetConnectionDialogW
		#define ShellMessageBox ShellMessageBoxW
		#define SHGetNewLinkInfo SHGetNewLinkInfoW
		#define SHGetSetFolderCustomSettings SHGetSetFolderCustomSettingsW
	#ELSE
		#define SHDefExtractIcon SHDefExtractIconA
		#define PathIsSlow PathIsSlowA
		#define SHStartNetConnectionDialog SHStartNetConnectionDialogA
		#define ShellMessageBox ShellMessageBoxA
		#define SHGetNewLinkInfo SHGetNewLinkInfoA
		#define SHGetSetFolderCustomSettings SHGetSetFolderCustomSettingsA
	#ENDIF

#ENDIF

#IFDEF SHUSEUNDOC
	; Unknown and untested
	#define PathStripPathAW SHELL32.DLL:38
	#define PathIsUNCAW SHELL32.DLL:39
	#define PathIsRelativeAW SHELL32.DLL:40
	#define Control_RunDLLA SHELL32.DLL:41
	#define Control_RunDLLW SHELL32.DLL:42
	#define PathFileExistsAW SHELL32.DLL:45
	#define PathMatchSpecAW SHELL32.DLL:46
	#define SetAppStartingCursor SHELL32.DLL:99
	#define FileMenu_DeleteAllItems SHELL32.DLL:104
	#define FileMenu_TrackPopupMenuEx SHELL32.DLL:116
	#define FileMenu_DeleteItemByCmd SHELL32.DLL:117
	#define FileMenu_Destroy SHELL32.DLL:118
	#define IsLFNDrive SHELL32.DLL:119

	#define FileMenu_AbortInitMenu SHELL32.DLL:120
	#define RunDLL_CallEntry16 SHELL32.DLL:122
	#define RLBuildListOfPaths SHELL32.DLL:146
	#define ArrangeWindows SHELL32.DLL:184
	#define SHHandleDiskFull SHELL32.DLL:185
	#define ILGetDisplayNameEx SHELL32.DLL:186
	#define ILGetPseudoNameW SHELL32.DLL:187
	#define ShellDDEInit SHELL32.DLL:188
	#define ILCreateFromPathA SHELL32.DLL:189

	#define ILGetDisplayName SHELL32.DLL:15
	#define ExitWindowsDialog Shell32.dll:60
	#define RunFileDlg Shell32.dll:61
	#define SHFindComputer Shell32.DLL:91
	#define SHWaitForFileToOpen SHELL32.DLL:97
	#define SHSimulateDropOnClsid SHELL32.DLL:751
	#define SHGetComputerDisplayNameW SHELL32.DLL:752
	#define CheckStagingArea SHELL32.DLL:753
	#define SHLimitInputEditWithFlags SHELL32.DLL:754
	#define PathIsEqualOrSubFolder SHELL32.DLL:755

	#IF WINVER < NTDDI_VISTA
		#define SHGetUserPicturePathW SHELL32.DLL:233 ; retired in Windows Vista and higher
		#define SHSetUserPicturePathW SHELL32.DLL:234 ; retired in Windows Vista and higher
		#define SHOpenEffectiveToken SHELL32.DLL:235 ; retired in Windows Vista and higher
	#ENDIF
	#define SHTestTokenPrivilegeW SHELL32.DLL:236
	#define SHShouldShowWizards SHELL32.DLL:237
	#define SHGetUserDisplayName SHELL32.DLL:241
	#define SHInvokePrivilegedFunctionW SHELL32.DLL:246
	#define SHGetActiveConsoleSessionId SHELL32.DLL:247
	#define SHGetUserSessionId SHELL32.DLL:248
	#define SHIsCurrentProcessConsoleSession SHELL32.DLL:253
	#define DisconnectWindowsDialog SHELL32.DLL:254

#ENDIF

#IFDEF SHVISTAORDINALS
	; Shell.dll v6.00 VISTA or greater
	#define CreateInfoTipFromItem SHELL32.DLL:260
	#define SHGetUserPicturePath SHELL32.DLL:261
	#define SHSetUserPicturePath SHELL32.DLL:262
	#define CreateInfoTipFromItem2 SHELL32.DLL:264
	#define ShellExecCmdLine SHELL32.DLL:265
	#define ShellExecPidl SHELL32.DLL:266
	#define SHResolveUserNames SHELL32.DLL:270
	#define DisplayNameOfW SHELL32.DLL:757
	#define SHCreateThreadUndoManager SHELL32.DLL:758
	#define SHGetThreadUndoManager SHELL32.DLL:759
	#define SHConfirmOperation SHELL32.DLL:760
	#define SHChangeNotifyDeregisterWindow SHELL32.DLL:761
	#define Create_IUICommandFromDef SHELL32.DLL:762
	#define Create_IEnumUICommandFromDefArray SHELL32.DLL:763
	#define AssocCreateElement SHELL32.DLL:764
	#define SHCopyStreamWithProgress SHELL32.DLL:766
	#define SHGetAssocKeys SHELL32.DLL:777
	#define AssocGetPropListForExt SHELL32.DLL:778
	#define SHApplyPropertiesToItem SHELL32.DLL:781
	#define SHCreateCategoryEnum SHELL32.DLL:786
	#define SHMapIDListToSystemImageListIndexAsync SHELL32.DLL:787
	#define SHCreateRelatedItemFromIDList SHELL32.DLL:788
	#define SHCreateRelatedItemWithParent SHELL32.DLL:789
	#define SHMapIDListToSystemImageListIndex SHELL32.DLL:790
	#define SHGetUserPicturePathEx SHELL32.DLL:810
	#define SHGetDefaultUserPicture SHELL32.DLL:811
	#define SHUserGetPasswordHint SHELL32.DLL:812
	#define SHUserSetPasswordHint SHELL32.DLL:813
	#define SHCreateLeafConditionEx SHELL32.DLL:814
	#define SHCreateAndOrConditionEx SHELL32.DLL:815
	#define SHCreateAndOrCondition SHELL32.DLL:816
	#define SHCreateLeafCondition SHELL32.DLL:817
	#define SHCreateFilter SHELL32.DLL:818
	#define SHLoadFilterFromStream SHELL32.DLL:819
	#define SHCreateAutoList SHELL32.DLL:820
	#define SHCreateSearchIDListFromAutoList SHELL32.DLL:821
	#define SHCreateSearchIDList SHELL32.DLL:822
	#define SHGetFolderTypeDescription SHELL32.DLL:823
	#define SHGetFolderTypeFromCanonicalName SHELL32.DLL:824
	#define SHCombineMultipleConditions SHELL32.DLL:825
	#define SHCreateAutoListWithID SHELL32.DLL:826
	#define SHCreateTransientVFolderIDList SHELL32.DLL:827
	#define DrawMenuItem SHELL32.DLL:828
	#define MeasureMenuItem SHELL32.DLL:829
	#define SHCreateNotConditionEx SHELL32.DLL:830
	#define SHCreateFilterFromFullText SHELL32.DLL:831
	#define SHKnownFolderToCSIDL SHELL32.DLL:832
	#define SHKnownFolderFromCSIDL SHELL32.DLL:833
	#define SHCreateScopeFromIDLists SHELL32.DLL:834
	#define SHCreateScopeItemFromIDList SHELL32.DLL:835
	#define SHCreateScopeFromShellItemArray SHELL32.DLL:836
	#define SHCreateScopeItemFromShellItem SHELL32.DLL:837
	#define SHCreateScopeItemFromKnownFolder SHELL32.DLL:838
	#define CreateSingleVisibleInList SHELL32.DLL:839
	#define PathGetPathDisplayName SHELL32.DLL:840
	#define SHFilterConditionFromString SHELL32.DLL:841
	#define SHFilterConditionToString SHELL32.DLL:842
	#define SHGetIdentifyItem SHELL32.DLL:843
	#define SHCreateNotCondition SHELL32.DLL:844
	#define CreateConditionRange SHELL32.DLL:845
	#define SHCombineMultipleConditionsEx SHELL32.DLL:847
	#define SHGetNoAssocIconIndex SHELL32.DLL:848
	#define SHCreateConditionFactory SHELL32.DLL:849
	#define PathComparePaths SHELL32.DLL:850
	#define SHInitializeControlPanelRegkeys SHELL32.DLL:852
	#define IsShellItemInSearchIndex SHELL32.DLL:854
	#define CPL_ExecuteTask SHELL32.DLL:856
	#define CPL_CreateCondition SHELL32.DLL:857
	#define POOBE_CreateIndirectGraphic SHELL32.DLL:858
	#define WPC_InstallState SHELL32.DLL:859
	#define SHGetCorrectOwnerSid SHELL32.DLL:860
	#define SHDisplayNameFromScopeAndSubQueries SHELL32.DLL:861
	#define SHCompareIDsFull SHELL32.DLL:862
	#define GetTryHarderIDList SHELL32.DLL:863
	#define StampIconForElevation SHELL32.DLL:864
	#define IsElevationRequired SHELL32.DLL:865
	#define SHExtCoCreateInstance SHELL32.DLL:866
	#define CreateVisibleInDescription SHELL32.DLL:867
	#define CreateVisibleInList SHELL32.DLL:868
	#define PathGetPathDisplayNameAlloc SHELL32.DLL:869
	#define DUI_Shell32_StartDeferUninitialization SHELL32.DLL:870
	#define DUI_Shell32_EndDeferUninitialization SHELL32.DLL:871
	#define SHCreateKindFilter SHELL32.DLL:872
	#define SHIconIndexFromPIDL SHELL32.DLL:873
#ENDIF

#IFDEF UNICODE
	#DEFINE OPEN_PRINTER_PROPS_INFO OPEN_PRINTER_PROPS_INFOW
	#define SHFILEINFO SHFILEINFOW
	#define DRAGINFO DRAGINFOW
	#define SHFILEOPSTRUCT SHFILEOPSTRUCTW
	#define SHNAMEMAPPING SHNAMEMAPPINGW
	#define SHELLEXECUTEINFO SHELLEXECUTEINFOW
	#define NOTIFYICONDATA NOTIFYICONDATAW
	#define NOTIFYICONDATA_V1_SIZE NOTIFYICONDATAW_V1_SIZE
	#define NOTIFYICONDATA_V2_SIZE NOTIFYICONDATAW_V2_SIZE
	#define NOTIFYICONDATA_V3_SIZE NOTIFYICONDATAW_V3_SIZE
	#define NOTIFYICONDATA_V4_SIZE NOTIFYICONDATAW_V4_SIZE
	#define DragQueryFile DragQueryFileW
	#define ShellExecute ShellExecuteW
	#define FindExecutable FindExecutableW
	#define ShellAbout ShellAboutW
	#define ExtractAssociatedIcon ExtractAssociatedIconW
	#define ExtractIcon ExtractIconW
	#define DoEnvironmentSubst DoEnvironmentSubstW
	#define ExtractIconEx ExtractIconExW
	#define SHFileOperation SHFileOperationW
	#define ShellExecuteEx ShellExecuteExW
	#define WinExecError WinExecErrorW
	#define SHQueryRecycleBin SHQueryRecycleBinW
	#define SHEmptyRecycleBin SHEmptyRecycleBinW
	#define Shell_NotifyIcon Shell_NotifyIconW
	#define SHGetFileInfo SHGetFileInfoW
	#define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExW
	#define SHGetNewLinkInfo SHGetNewLinkInfoW
	#define SHInvokePrinterCommand SHInvokePrinterCommandW
	#define SHEnumerateUnreadMailAccounts SHEnumerateUnreadMailAccountsW
	#define SHGetUnreadMailCount  SHGetUnreadMailCountW
	#define SHSetUnreadMailCount  SHSetUnreadMailCountW
	#define ShellMessageBox  ShellMessageBoxW
#else
	#DEFINE OPEN_PRINTER_PROPS_INFO OPEN_PRINTER_PROPS_INFOA
	#define SHFILEINFO SHFILEINFOA
	#define DRAGINFO DRAGINFOA
	#define SHFILEOPSTRUCT SHFILEOPSTRUCTA
	#define SHNAMEMAPPING SHNAMEMAPPINGA
	#define SHELLEXECUTEINFO SHELLEXECUTEINFOA
	#define NOTIFYICONDATA NOTIFYICONDATAA
	#define NOTIFYICONDATA_V1_SIZE NOTIFYICONDATAA_V1_SIZE
	#define NOTIFYICONDATA_V2_SIZE NOTIFYICONDATAA_V2_SIZE
	#define NOTIFYICONDATA_V3_SIZE NOTIFYICONDATAA_V3_SIZE
	#define NOTIFYICONDATA_V4_SIZE NOTIFYICONDATAA_V4_SIZE
	#define DragQueryFile DragQueryFileA
	#define ShellExecute ShellExecuteA
	#define FindExecutable FindExecutableA
	#define ShellAbout ShellAboutA
	#define ExtractAssociatedIcon ExtractAssociatedIconA
	#define ExtractIcon ExtractIconA
	#define DoEnvironmentSubst DoEnvironmentSubstA
	#define ExtractIconEx ExtractIconExA
	#define SHFileOperation SHFileOperationA
	#define ShellExecuteEx ShellExecuteExA
	#define WinExecError WinExecErrorA
	#define SHQueryRecycleBin SHQueryRecycleBinA
	#define SHEmptyRecycleBin SHEmptyRecycleBinA
	#define Shell_NotifyIcon Shell_NotifyIconA
	#define SHGetFileInfo SHGetFileInfoA
	#define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExA
	#define SHGetNewLinkInfo SHGetNewLinkInfoA
	#define SHInvokePrinterCommand SHInvokePrinterCommandA
	#define SHEnumerateUnreadMailAccounts  SHEnumerateUnreadMailAccountsA
	#define SHGetUnreadMailCount  SHGetUnreadMailCountA
	#define SHSetUnreadMailCount  SHSetUnreadMailCountA
	#define ShellMessageBox  ShellMessageBoxA
#endif

#define SHGetDiskFreeSpace  SHGetDiskFreeSpaceEx

#endif

