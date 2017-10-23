#ifndef SHLOBJ_H
#define SHLOBJ_H

/* Windows Shell object definitions */

/*
Dependancies
ole2.h
prsht.h
commctrl.h
shlguid.h
*/


/*
Switches used
UNICODE
*/

#IFDEF LINKFILES
	#dynamiclinkfile Shell32.dll
#ENDIF

#IFNDEF POINT
	POINT STRUCT
		x DD
		y DD
	ENDS
#ENDIF

#IFNDEF GUID
	GUID STRUCT
		Data1	dd
		Data2	dw
		Data3	dw
		Data4	db 8 DUP
	ENDS
#ENDIF

#IFNDEF SIZE
	SIZE STRUCT
		cx DD
		cy DD
	ENDS
#ENDIF

#define SIZEL SIZE
#define POINTL POINT

#IFNDEF MAX_PATH
	#define MAX_PATH 260
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF WININET_H
	#include "wininet.h"
#ENDIF

#IFNDEF COORD
	COORD
		X DW
		Y DW
	ENDS
#ENDIF

#IFNDEF OLE2_H
	#include ole2.h
#ENDIF

#IFNDEF PRSHT_H
	#include prsht.h
#ENDIF

#IFNDEF COMMCTRL_H
	#include commctrl.h
#ENDIF

#IFNDEF SHLGUID_H
	#include shlguid.h
#ENDIF

ISHCUTCMDID_DOWNLOADICON      = 0
ISHCUTCMDID_INTSHORTCUTCREATE = 1
ISHCUTCMDID_COMMITHISTORY     = 2
ISHCUTCMDID_SETUSERAWURL      = 3
#define CMDID_INTSHORTCUTCREATE ISHCUTCMDID_INTSHORTCUTCREATE

#define FCS_READ                    0x00000001
#define FCS_FORCEWRITE              0x00000002
#define FCS_WRITE                   (FCS_READ | FCS_FORCEWRITE)
#define FCS_FLAG_DRAGDROP           2
#define FCSM_VIEWID                 0x00000001    // deprecated
#define FCSM_WEBVIEWTEMPLATE        0x00000002  // deprecated
#define FCSM_INFOTIP                0x00000004
#define FCSM_CLSID                  0x00000008
#define FCSM_ICONFILE               0x00000010
#define FCSM_LOGO                   0x00000020
#define FCSM_FLAGS                  0x00000040

#define OFASI_EDIT          0x0001
#define OFASI_OPENDESKTOP   0x0002

#define SIOM_OVERLAYINDEX         1
#define SIOM_ICONINDEX            2
// #define SIOM_PRIORITY          3
#define SIOM_RESERVED_SHARED      0
#define SIOM_RESERVED_LINK        1
#define SIOM_RESERVED_SLOWFILE    2

#define CMF_NORMAL  0x00000000
#define CMF_DEFAULTONLY  0x00000001
#define CMF_VERBSONLY  0x00000002
#define CMF_EXPLORE  0x00000004
#define CMF_NOVERBS  0x00000008
#define CMF_CANRENAME  0x00000010
#define CMF_NODEFAULT  0x00000020
#define CMF_INCLUDESTATIC  0x00000040
#define CMF_ITEMMENU 0x00000080
#define CMF_FINDHACK  0x00000080
#define CMF_EXTENDEDVERBS 0x00000100
#define CMF_DISABLEDVERBS 0x00000200
#define CMF_RESERVED  0xffff0000
#define CMF_ASYNCVERBSTATE 0x00000400
#define CMF_OPTIMIZEFORINVOKE 0x00000800
#define CMF_SYNCCASCADEMENU 0x00001000
#define CMF_DONOTPICKDEFAULT 0x00002000
#define CMF_RESERVED 0xffff0000

#define GCS_VERBA  0x00000000
#define GCS_HELPTEXTA  0x00000001
#define GCS_VALIDATEA  0x00000002
#define GCS_VERBW  0x00000004
#define GCS_HELPTEXTW  0x00000005
#define GCS_VALIDATEW  0x00000006
#define GCS_UNICODE  0x00000004

#define CMDSTR_NEWFOLDERA  A"NewFolder"
#define CMDSTR_VIEWLISTA  A"ViewList"
#define CMDSTR_VIEWDETAILSA A"ViewDetails"
#define CMDSTR_NEWFOLDERW  L"NewFolder"
#define CMDSTR_VIEWLISTW  L"ViewList"
#define CMDSTR_VIEWDETAILSW  L"ViewDetails"

// SEE_MASK definitions are in shellapi.h
#define CMIC_MASK_HOTKEY  SEE_MASK_HOTKEY
#define CMIC_MASK_ICON  SEE_MASK_ICON
#define CMIC_MASK_FLAG_NO_UI  SEE_MASK_FLAG_NO_UI
#define CMIC_MASK_UNICODE  SEE_MASK_UNICODE
#define CMIC_MASK_NO_CONSOLE  SEE_MASK_NO_CONSOLE
#IF WINVER < NTDDI_VISTA
	#define CMIC_MASK_HASLINKNAME  SEE_MASK_HASLINKNAME
	#define CMIC_MASK_HASTITLE  SEE_MASK_HASTITLE
#ENDIF
#define CMIC_MASK_FLAG_SEP_VDM SEE_MASK_FLAG_SEPVDM
#define CMIC_MASK_ASYNCOK SEE_MASK_ASYNCOK
#define CMIC_MASK_NOASYNC SEE_MASK_NOASYNC
#define CMIC_MASK_SHIFT_DOWN  0x10000000
#define CMIC_MASK_CONTROL_DOWN  0x20000000
#define CMIC_MASK_PTINVOKE  0x20000000

#define GIL_OPENICON      0x0001
#define GIL_FORSHELL      0x0002
#define GIL_ASYNC         0x0020
#define GIL_DEFAULTICON   0x0040
#define GIL_FORSHORTCUT   0x0080
#define GIL_CHECKSHIELD   0x0200
#define GIL_SIMULATEDOC   0x0001
#define GIL_PERINSTANCE   0x0002
#define GIL_PERCLASS      0x0004
#define GIL_NOTFILENAME   0x0008
#define GIL_DONTCACHE     0x0010
#define GIL_SHIELD        0x0200
#define GIL_FORCENOSHIELD 0x0400

#define ISIOI_ICONFILE  0x00000001
#define ISIOI_ICONINDEX  0x00000002

#define TOID_NULL GUID_NULL
#define ITSAT_DEFAULT_LPARAM -1
#define ITSAT_DEFAULT_PRIORITY 0x10000000
#define ITSAT_MAX_PRIORITY 0x7fffffff
#define ITSAT_MIN_PRIORITY 0x00000000
#define ITSSFLAG_COMPLETE_ON_DESTROY 0x0000
#define ITSSFLAG_KILL_ON_DESTROY 0x0001
#define ITSSFLAG_FLAGS_MASK 0x0003
#define ITSS_THREAD_DESTROY_DEFAULT_TIMEOUT  10000
#define ITSS_THREAD_TERMINATE_TIMEOUT INFINITE
#define ITSS_THREAD_TIMEOUT_NO_CHANGE (INFINITE-1)

#define OI_ASYNC 0xFFFFEEEE

#define IDO_SHGIOI_SHARE  0x0FFFFFFF
#define IDO_SHGIOI_LINK  0x0FFFFFFE
#define IDO_SHGIOI_SLOWFILE 0x0FFFFFFFD

#define NT_CONSOLE_PROPS_SIG  0xA0000002
#define NT_FE_CONSOLE_PROPS_SIG  0xA0000004

#ifndef FO_MOVE
	#define FO_MOVE  0x0001
	#define FO_COPY  0x0002
	#define FO_DELETE  0x0003
	#define FO_RENAME  0x0004
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
	#define PO_DELETE  0x0013
	#define PO_RENAME  0x0014
	#define PO_PORTCHANGE  0x0020
	#define PO_REN_PORT  0x0034
#endif /* FO_MOVE */

#define FVSIF_RECT  0x00000001
#define FVSIF_PINNED  0x00000002
#define FVSIF_NEWFAILED 0x08000000
#define FVSIF_NEWFILE  0x80000000
#define FVSIF_CANVIEWIT 0x40000000

#define FCIDM_SHVIEWFIRST  0x0000
#define FCIDM_SHVIEWLAST  0x7fff
#define FCIDM_BROWSERFIRST  0xa000
#define FCIDM_BROWSERLAST  0xbf00
#define FCIDM_GLOBALFIRST  0x8000
#define FCIDM_GLOBALLAST  0x9fff

#define FCIDM_MENU_FILE  (FCIDM_GLOBALFIRST+0x0000)
#define FCIDM_MENU_EDIT  (FCIDM_GLOBALFIRST+0x0040)
#define FCIDM_MENU_VIEW  (FCIDM_GLOBALFIRST+0x0080)
#define FCIDM_MENU_VIEW_SEP_OPTIONS (FCIDM_GLOBALFIRST+0x0081)
#define FCIDM_MENU_TOOLS  (FCIDM_GLOBALFIRST+0x00c0)
#define FCIDM_MENU_TOOLS_SEP_GOTO  (FCIDM_GLOBALFIRST+0x00c1)
#define FCIDM_MENU_HELP  (FCIDM_GLOBALFIRST+0x0100)
#define FCIDM_MENU_FIND  (FCIDM_GLOBALFIRST+0x0140)
#define FCIDM_MENU_EXPLORE  (FCIDM_GLOBALFIRST+0x0150)
#define FCIDM_MENU_FAVORITES  (FCIDM_GLOBALFIRST+0x0170)

#define FCIDM_TOOLBAR  (FCIDM_BROWSERFIRST+0)
#define FCIDM_STATUS  (FCIDM_BROWSERFIRST+1)

#define SBSP_DEFBROWSER  0x0000
#define SBSP_SAMEBROWSER  0x0001
#define SBSP_NEWBROWSER  0x0002
#define SBSP_DEFMODE  0x0000
#define SBSP_OPENMODE  0x0010
#define SBSP_EXPLOREMODE  0x0020
#define SBSP_HELPMODE  0x0040
#define SBSP_NOTRANSFERHIST  0x0080
#define SBSP_ABSOLUTE  0x0000
#define SBSP_RELATIVE  0x1000
#define SBSP_PARENT  0x2000
#define SBSP_NAVIGATEBACK  0x4000
#define SBSP_NAVIGATEFORWARD  0x8000
#define SBSP_ALLOW_AUTONAVIGATE 0x10000
#define SBSP_KEEPSAMETEMPLATE     0x00020000
#define SBSP_KEEPWORDWHEELTEXT    0x00040000
#define SBSP_ACTIVATE_NOFOCUS     0x00080000
#define SBSP_CREATENOHISTORY      0x00100000
#define SBSP_PLAYNOSOUND          0x00200000
#define SBSP_CALLERUNTRUSTED      0x00800000
#define SBSP_TRUSTFIRSTDOWNLOAD   0x01000000
#define SBSP_UNTRUSTEDFORDOWNLOAD 0x02000000
#define SBSP_NOAUTOSELECT  0x04000000
#define SBSP_WRITENOHISTORY  0x08000000
#define SBSP_TRUSTEDFORACTIVEX    0x10000000
#define SBSP_FEEDNAVIGATION       0x20000000
#define SBSP_REDIRECT  0x40000000
#define SBSP_INITIATEDBYHLINKFRAME  0x80000000


#define FCW_STATUS  0x0001
#define FCW_TOOLBAR  0x0002
#define FCW_TREE  0x0003
#define FCW_INTERNETBAR 0x0006
#define FCW_PROGRESS  0x0008

#define FCT_MERGE  0x0001
#define FCT_CONFIGABLE  0x0002
#define FCT_ADDTOEND  0x0004

#define CDBOSC_SETFOCUS  0x00000000
#define CDBOSC_KILLFOCUS  0x00000001
#define CDBOSC_SELCHANGE  0x00000002
#define CDBOSC_RENAME  0x00000003

#define IDC_OFFLINE_HAND  103
#define IDC_PANTOOL_HAND_OPEN   104
#define IDC_PANTOOL_HAND_CLOSED 105

#define CDB2N_CONTEXTMENU_DONE  0x00000001
#define CDB2N_CONTEXTMENU_START  0x00000002

#define CDB2GVF_SHOWALLFILES  0x00000001
#define CDB2GVF_ISFILESAVE          0x00000002 // is file save, else file open
#define CDB2GVF_ALLOWPREVIEWPANE    0x00000004
#define CDB2GVF_NOSELECTVERB        0x00000008
#define CDB2GVF_NOINCLUDEITEM       0x00000010
#define CDB2GVF_ISFOLDERPICKER      0x00000020
#define CDB2GVF_ADDSHIELD           0x00000040

#IFNDEF SVSI_NOSTATECHANGE
	#define SVSI_DESELECT       0x00000000
	#define SVSI_SELECT         0x00000001
	#define SVSI_EDIT           0x00000003  // includes select
	#define SVSI_DESELECTOTHERS 0x00000004
	#define SVSI_ENSUREVISIBLE  0x00000008
	#define SVSI_FOCUSED        0x00000010
	#define SVSI_TRANSLATEPT    0x00000020
	#define SVSI_SELECTIONMARK  0x00000040
	#define SVSI_POSITIONITEM   0x00000080
	#define SVSI_CHECK          0x00000100
	#define SVSI_NOSTATECHANGE  0x80000000
#ENDIF

#IFNDEF SVGIO_FLAG_VIEWORDER
SVGIO_BACKGROUND	= 0
SVGIO_SELECTION	= 0x1
SVGIO_ALLVIEW	= 0x2
SVGIO_CHECKED	= 0x3
SVGIO_TYPE_MASK	= 0xf
SVGIO_FLAG_VIEWORDER	= 0x80000000
#ENDIF

#define SV2GV_CURRENTVIEW -1
#define SV2GV_DEFAULTVIEW -2

#define STRRET_WSTR  0x0000
#define STRRET_OFFSET  0x0001
#define STRRET_CSTR  0x0002

#define REGSTR_PATH_SPECIAL_FOLDERS  "\Shell Folders"

#define CSIDL_DESKTOP                   0x0000        // <desktop>
#define CSIDL_INTERNET                  0x0001        // Internet Explorer (icon on desktop)
#define CSIDL_PROGRAMS                  0x0002        // Start Menu\Programs
#define CSIDL_CONTROLS                  0x0003        // My Computer\Control Panel
#define CSIDL_PRINTERS                  0x0004        // My Computer\Printers
#define CSIDL_PERSONAL                  0x0005        // My Documents
#define CSIDL_FAVORITES                 0x0006        // <user name>\Favorites
#define CSIDL_STARTUP                   0x0007        // Start Menu\Programs\Startup
#define CSIDL_RECENT                    0x0008        // <user name>\Recent
#define CSIDL_SENDTO                    0x0009        // <user name>\SendTo
#define CSIDL_BITBUCKET                 0x000a        // <desktop>\Recycle Bin
#define CSIDL_STARTMENU                 0x000b        // <user name>\Start Menu
#define CSIDL_MYDOCUMENTS               CSIDL_PERSONAL //  Personal was just a silly name for My Documents
#define CSIDL_MYMUSIC                   0x000d        // "My Music" folder
#define CSIDL_MYVIDEO                   0x000e        // "My Videos" folder
#define CSIDL_DESKTOPDIRECTORY          0x0010        // <user name>\Desktop
#define CSIDL_DRIVES                    0x0011        // My Computer
#define CSIDL_NETWORK                   0x0012        // Network Neighborhood (My Network Places)
#define CSIDL_NETHOOD                   0x0013        // <user name>\nethood
#define CSIDL_FONTS                     0x0014        // windows\fonts
#define CSIDL_TEMPLATES                 0x0015
#define CSIDL_COMMON_STARTMENU          0x0016        // All Users\Start Menu
#define CSIDL_COMMON_PROGRAMS           0X0017        // All Users\Start Menu\Programs
#define CSIDL_COMMON_STARTUP            0x0018        // All Users\Startup
#define CSIDL_COMMON_DESKTOPDIRECTORY   0x0019        // All Users\Desktop
#define CSIDL_APPDATA                   0x001a        // <user name>\Application Data
#define CSIDL_PRINTHOOD                 0x001b        // <user name>\PrintHood
#define CSIDL_LOCAL_APPDATA             0x001c        // <user name>\Local Settings\Applicaiton Data (non roaming)
#define CSIDL_ALTSTARTUP                0x001d        // non localized startup
#define CSIDL_COMMON_ALTSTARTUP         0x001e        // non localized common startup
#define CSIDL_COMMON_FAVORITES          0x001f
#define CSIDL_INTERNET_CACHE            0x0020
#define CSIDL_COOKIES                   0x0021
#define CSIDL_HISTORY                   0x0022
#define CSIDL_COMMON_APPDATA            0x0023        // All Users\Application Data
#define CSIDL_WINDOWS                   0x0024        // GetWindowsDirectory()
#define CSIDL_SYSTEM                    0x0025        // GetSystemDirectory()
#define CSIDL_PROGRAM_FILES             0x0026        // C:\Program Files
#define CSIDL_MYPICTURES                0x0027        // C:\Program Files\My Pictures
#define CSIDL_PROFILE                   0x0028        // USERPROFILE
#define CSIDL_SYSTEMX86                 0x0029        // x86 system directory on RISC
#define CSIDL_PROGRAM_FILESX86          0x002a        // x86 C:\Program Files on RISC
#define CSIDL_PROGRAM_FILES_COMMON      0x002b        // C:\Program Files\Common
#define CSIDL_PROGRAM_FILES_COMMONX86   0x002c        // x86 Program Files\Common on RISC
#define CSIDL_COMMON_TEMPLATES          0x002d        // All Users\Templates
#define CSIDL_COMMON_DOCUMENTS          0x002e        // All Users\Documents
#define CSIDL_COMMON_ADMINTOOLS         0x002f        // All Users\Start Menu\Programs\Administrative Tools
#define CSIDL_ADMINTOOLS                0x0030        // <user name>\Start Menu\Programs\Administrative Tools
#define CSIDL_CONNECTIONS               0x0031        // Network and Dial-up Connections
#define CSIDL_COMMON_MUSIC              0x0035        // All Users\My Music
#define CSIDL_COMMON_PICTURES           0x0036        // All Users\My Pictures
#define CSIDL_COMMON_VIDEO              0x0037        // All Users\My Video
#define CSIDL_RESOURCES                 0x0038        // Resource Direcotry
#define CSIDL_RESOURCES_LOCALIZED       0x0039        // Localized Resource Direcotry
#define CSIDL_COMMON_OEM_LINKS          0x003a        // Links to All Users OEM specific apps
#define CSIDL_CDBURN_AREA               0x003b        // USERPROFILE\Local Settings\Application Data\Microsoft\CD Burning
#define CSIDL_COMPUTERSNEARME           0x003d        // Computers Near Me (computered from Workgroup membership)

#define CSIDL_FLAG_CREATE  0x8000
#define CSIDL_FLAG_DONT_VERIFY  0x4000
#define CSIDL_FLAG_NO_ALIAS 0x1000
#define CSIDL_FLAG_PER_USER_INIT 0x0800
#define CSIDL_FLAG_MASK  0xFF00

#define BIF_RETURNONLYFSDIRS  0x0001
#define BIF_DONTGOBELOWDOMAIN  0x0002
#define BIF_STATUSTEXT  0x0004
#define BIF_RETURNFSANCESTORS  0x0008
#define BIF_EDITBOX  0x0010
#define BIF_VALIDATE  0x0020
#define BIF_NEWDIALOGSTYLE  0x0040
#define BIF_USENEWUI  (BIF_NEWDIALOGSTYLE|BIF_EDITBOX)
#define BIF_BROWSEINCLUDEURLS  0x0080
#define BIF_BROWSEFORCOMPUTER  0x1000
#define BIF_BROWSEFORPRINTER  0x2000
#define BIF_BROWSEINCLUDEFILES 0x4000
#define BIF_SHAREABLE  0x8000

#define BFFM_INITIALIZED  1
#define BFFM_SELCHANGED  2
#define BFFM_VALIDATEFAILEDA  3
#define BFFM_VALIDATEFAILEDW  4
#define BFFM_IUNKNOWN 5

#define BFFM_SETSTATUSTEXTA  (WM_USER+100)
#define BFFM_ENABLEOK  (WM_USER+101)
#define BFFM_SETSELECTIONA  (WM_USER+102)
#define BFFM_SETSELECTIONW  (WM_USER+103)
#define BFFM_SETSTATUSTEXTW  (WM_USER+104)
#define BFFM_SETOKTEXT (WM_USER + 105) // Unicode only
#define BFFM_SETEXPANDED (WM_USER + 106) // Unicode only

GPFIDL_DEFAULT    = 0x0000
GPFIDL_ALTNAME    = 0x0001
GPFIDL_UNCPRINTER = 0x0002

#define DROPEFFECT_COPY 0x1
#define DROPEFFECT_MOVE 0x2
#define DROPEFFECT_LINK 0x4

#IFNDEF SFGAO_STORAGECAPMASK
#define SHCIDS_ALLFIELDS        0x80000000
#define SHCIDS_CANONICALONLY    0x10000000
#define SHCIDS_BITMASK          0xFFFF0000
#define SHCIDS_COLUMNMASK       0x0000FFFF
#define SFGAO_CANCOPY           DROPEFFECT_COPY // Objects can be copied    (0x1)
#define SFGAO_CANMOVE           DROPEFFECT_MOVE // Objects can be moved     (0x2)
#define SFGAO_CANLINK           DROPEFFECT_LINK // Objects can be linked    (0x4)
#define SFGAO_STORAGE           0x00000008     // supports BindToObject(IID_IStorage)
#define SFGAO_CANRENAME         0x00000010     // Objects can be renamed
#define SFGAO_CANDELETE         0x00000020     // Objects can be deleted
#define SFGAO_HASPROPSHEET      0x00000040     // Objects have property sheets
#define SFGAO_DROPTARGET        0x00000100     // Objects are drop target
#define SFGAO_CAPABILITYMASK    0x00000177
#define SFGAO_ENCRYPTED         0x00002000     // object is encrypted (use alt color)
#define SFGAO_ISSLOW            0x00004000     // 'slow' object
#define SFGAO_GHOSTED           0x00008000     // ghosted icon
#define SFGAO_LINK              0x00010000     // Shortcut (link)
#define SFGAO_SHARE             0x00020000     // shared
#define SFGAO_READONLY          0x00040000     // read-only
#define SFGAO_HIDDEN            0x00080000     // hidden object
#define SFGAO_DISPLAYATTRMASK   0x000FC000
#define SFGAO_FILESYSANCESTOR   0x10000000     // may contain children with SFGAO_FILESYSTEM
#define SFGAO_FOLDER            0x20000000     // support BindToObject(IID_IShellFolder)
#define SFGAO_FILESYSTEM        0x40000000     // is a win32 file system object (file/folder/root)
#define SFGAO_HASSUBFOLDER      0x80000000     // may contain children with SFGAO_FOLDER
#define SFGAO_CONTENTSMASK      0x80000000
#define SFGAO_VALIDATE          0x01000000     // invalidate cached information
#define SFGAO_REMOVABLE         0x02000000     // is this removeable media?
#define SFGAO_COMPRESSED        0x04000000     // Object is compressed (use alt color)
#define SFGAO_BROWSABLE         0x08000000     // supports IShellFolder, but only implements CreateViewObject() (non-folder view)
#define SFGAO_NONENUMERATED     0x00100000     // is a non-enumerated object
#define SFGAO_NEWCONTENT        0x00200000     // should show bold in explorer tree
#define SFGAO_CANMONIKER        0x00400000     // defunct
#define SFGAO_HASSTORAGE        0x00400000     // defunct
#define SFGAO_STREAM            0x00400000     // supports BindToObject(IID_IStream)
#define SFGAO_STORAGEANCESTOR   0x00800000     // may contain children with SFGAO_STORAGE or SFGAO_STREAM
#define SFGAO_STORAGECAPMASK    0x70C50008     // for determining storage capabilities, ie for open/save semantics
#define SFGAO_PKEYSFGAOMASK     0x81044000
#ENDIF

#define STR_BIND_FORCE_FOLDER_SHORTCUT_RESOLVE L"Force Folder Shortcut Resolve"
#define STR_AVOID_DRIVE_RESTRICTION_POLICY L"Avoid Drive Restriction Policy"
#define STR_AVOID_DRIVE_RESTRICTION_POLICY L"Avoid Drive Restriction Policy"
#define STR_SKIP_BINDING_CLSID L"Skip Binding CLSID"
#define STR_PARSE_PREFER_FOLDER_BROWSING L"Parse Prefer Folder Browsing"
#define STR_DONT_PARSE_RELATIVE L"Don't Parse Relative"
#define STR_PARSE_TRANSLATE_ALIASES L"Parse Translate Aliases"
#define STR_PARSE_SKIP_NET_CACHE L"Skip Net Resource Cache"
#define STR_PARSE_SHELL_PROTOCOL_TO_FILE_OBJECTS L"Parse Shell Protocol To File Objects"
#define STR_TRACK_CLSID L"Track the CLSID"
#define STR_INTERNAL_NAVIGATE L"Internal Navigation"
#define STR_PARSE_PROPERTYSTORE L"DelegateNamedProperties"
#define STR_NO_VALIDATE_FILENAME_CHARS L"NoValidateFilenameChars"
#define STR_BIND_DELEGATE_CREATE_OBJECT L"Delegate Object Creation"
#define STR_PARSE_ALLOW_INTERNET_SHELL_FOLDERS L"Allow binding to Internet shell folder handlers and negate STR_PARSE_PREFER_WEB_BROWSING"
#define STR_PARSE_PREFER_WEB_BROWSING L"Do not bind to Internet shell folder handlers"
#define STR_PARSE_SHOW_NET_DIAGNOSTICS_UI L"Show network diagnostics UI"
#define STR_PARSE_DONT_REQUIRE_VALIDATED_URLS L"Do not require validated URLs"
#define STR_INTERNETFOLDER_PARSE_ONLY_URLMON_BINDABLE L"Validate URL"


#if WINVER >= NTDDI_WIN7
	#define STR_BIND_FOLDERS_READ_ONLY L"Folders As Read Only"
	#define STR_BIND_FOLDER_ENUM_MODE L"Folder Enum Mode"
	
	FEM_VIEWRESULT	= 0
	FEM_NAVIGATION	= 1
	
	IObjectWithFolderEnumMode STRUCT
		UNION
			struct
				QueryInterface		PTR
				AddRef				PTR
				Release				PTR
			ends
			IUnknown Unknown
		ENDUNION
		SetMode PTR
		GetMode PTR
	ENDS
	
	#define STR_PARSE_WITH_EXPLICIT_PROGID L"ExplicitProgid"
	#define STR_PARSE_WITH_EXPLICIT_ASSOCAPP L"ExplicitAssociationApp"
	#define STR_PARSE_EXPLICIT_ASSOCIATION_SUCCESSFUL L"ExplicitAssociationSuccessful"
	#define STR_PARSE_AND_CREATE_ITEM    L"ParseAndCreateItem"
	
	IParseAndCreateItem STRUCT
		UNION
			struct
				QueryInterface		PTR
				AddRef				PTR
				Release				PTR
			ends
			IUnknown Unknown
		ENDUNION
		SetItem PTR
		GetItem PTR
	ENDS
	
	#define STR_ITEM_CACHE_CONTEXT       L"ItemCacheContext"
#endif

#define PANE_NONE        -1
#define PANE_ZONE        1
#define PANE_OFFLINE     2
#define PANE_PRINTER     3
#define PANE_SSL         4
#define PANE_NAVIGATION  5
#define PANE_PROGRESS    6
#define PANE_PRIVACY     7

#IFNDEF STR_SKIP_BINDING_CLSID
	#define STR_SKIP_BINDING_CLSID      L"Skip Binding CLSID"
#ENDIF
#define STR_FILE_SYS_BIND_DATA  L"File System Bind Data"

#define PROGDLG_NORMAL  0x00000000
#define PROGDLG_MODAL  0x00000001
#define PROGDLG_AUTOTIME  0x00000002
#define PROGDLG_NOTIME  0x00000004
#define PROGDLG_NOMINIMIZE  0x00000008
#define PROGDLG_NOPROGRESSBAR  0x00000010
#define PROGDLG_MARQUEEPROGRESS 0x00000020
#define PROGDLG_NOCANCEL 0x00000040

#define PDTIMER_RESET 0x00000001
#define PDTIMER_PAUSE 0x00000002
#define PDTIMER_RESUME 0x00000003

#define DWFRF_NORMAL  0x0000
#define DWFRF_DELETECONFIGDATA  0x0001

#define DWFAF_HIDDEN  0x0001
#define DWFAF_GROUP1    0x0002
#define DWFAF_GROUP2    0x0004
#define DWFAF_AUTOHIDE  0x0010

#define DBIM_MINSIZE  0x0001
#define DBIM_MAXSIZE  0x0002
#define DBIM_INTEGRAL  0x0004
#define DBIM_ACTUAL  0x0008
#define DBIM_TITLE  0x0010
#define DBIM_MODEFLAGS  0x0020
#define DBIM_BKCOLOR  0x0040

#define DBIMF_NORMAL  0x0000
#define DBIMF_VARIABLEHEIGHT  0x0008
#define DBIMF_DEBOSSED  0x0020
#define DBIMF_BKCOLOR  0x0040

#define DBIF_VIEWMODE_NORMAL  0x0000
#define DBIF_VIEWMODE_VERTICAL  0x0001
#define DBIF_VIEWMODE_FLOATING  0x0002
#define DBIF_VIEWMODE_TRANSPARENT  0x0004

#define CFSTR_SHELLIDLIST "Shell IDList Array"
#define CFSTR_SHELLIDLISTOFFSET "Shell Object Offsets"
#define CFSTR_NETRESOURCES "Net Resource"
#define CFSTR_FILEDESCRIPTORA "FileGroupDescriptor"
#define CFSTR_FILEDESCRIPTORW "FileGroupDescriptorW"
#define CFSTR_FILECONTENTS "FileContents"
#define CFSTR_FILENAMEA "FileName"
#define CFSTR_FILENAMEW "FileNameW"
#define CFSTR_PRINTERGROUP "PrinterFriendlyName"
#define CFSTR_FILENAMEMAPA "FileNameMap"
#define CFSTR_FILENAMEMAPW "FileNameMapW"
#define CFSTR_SHELLURL "UniformResourceLocator"
#define CFSTR_INETURLA CFSTR_SHELLURL
#define CFSTR_INETURLW "UniformResourceLocatorW"
#define CFSTR_PREFERREDDROPEFFECT "Preferred DropEffect"
#define CFSTR_PERFORMEDDROPEFFECT "Performed DropEffect"
#define CFSTR_PASTESUCCEEDED "Paste Succeeded"
#define CFSTR_INDRAGLOOP "InShellDragLoop"
#define CFSTR_MOUNTEDVOLUME "MountedVolume"
#define CFSTR_PERSISTEDDATAOBJECT "PersistedDataObject"
#define CFSTR_TARGETCLSID "TargetCLSID"
#define CFSTR_LOGICALPERFORMEDDROPEFFECT "Logical Performed DropEffect"
#define CFSTR_AUTOPLAY_SHELLIDLISTS "Autoplay Enumerated IDList Array"
#define CFSTR_UNTRUSTEDDRAGDROP "UntrustedDragDrop"
#define CFSTR_FILE_ATTRIBUTES_ARRAY "File Attributes Array"
#define CFSTR_INVOKECOMMAND_DROPPARAM "InvokeCommand DropParam"
#define CFSTR_SHELLDROPHANDLER "DropHandlerCLSID"
#define CFSTR_DROPDESCRIPTION "DropDescription"

#ifdef UNICODE
	#define CFSTR_FILEDESCRIPTOR    CFSTR_FILEDESCRIPTORW
	#define CFSTR_FILENAME          CFSTR_FILENAMEW
	#define CFSTR_FILENAMEMAP       CFSTR_FILENAMEMAPW
	#define CFSTR_INETURL           CFSTR_INETURLW
#else
	#define CFSTR_FILEDESCRIPTOR    CFSTR_FILEDESCRIPTORA
	#define CFSTR_FILENAME          CFSTR_FILENAMEA
	#define CFSTR_FILENAMEMAP       CFSTR_FILENAMEMAPA
	#define CFSTR_INETURL           CFSTR_INETURLA
#endif

#define DVASPECT_SHORTNAME  2
#define DVASPECT_COPY  3
#define DVASPECT_LINK  4

#define SHCNE_RENAMEITEM  0x00000001
#define SHCNE_CREATE  0x00000002
#define SHCNE_DELETE  0x00000004
#define SHCNE_MKDIR  0x00000008
#define SHCNE_RMDIR  0x00000010
#define SHCNE_MEDIAINSERTED  0x00000020
#define SHCNE_MEDIAREMOVED  0x00000040
#define SHCNE_DRIVEREMOVED  0x00000080
#define SHCNE_DRIVEADD  0x00000100
#define SHCNE_NETSHARE  0x00000200
#define SHCNE_NETUNSHARE  0x00000400
#define SHCNE_ATTRIBUTES  0x00000800
#define SHCNE_UPDATEDIR  0x00001000
#define SHCNE_UPDATEITEM  0x00002000
#define SHCNE_SERVERDISCONNECT  0x00004000
#define SHCNE_UPDATEIMAGE  0x00008000
#define SHCNE_DRIVEADDGUI  0x00010000
#define SHCNE_RENAMEFOLDER  0x00020000
#define SHCNE_FREESPACE  0x00040000
#define SHCNE_EXTENDED_EVENT  0x04000000
#define SHCNE_ASSOCCHANGED  0x08000000
#define SHCNE_DISKEVENTS  0x0002381F
#define SHCNE_GLOBALEVENTS  0x0C0581E0
#define SHCNE_ALLEVENTS  0x7FFFFFFF
#define SHCNE_INTERRUPT  0x80000000

#define SHCNEE_ORDERCHANGED  2
#define SHCNEE_MSI_CHANGE  4
#define SHCNEE_MSI_UNINSTALL  5

#define SHCNF_IDLIST  0x0000
#define SHCNF_PATHA  0x0001
#define SHCNF_PRINTERA  0x0002
#define SHCNF_DWORD  0x0003
#define SHCNF_PATHW  0x0005
#define SHCNF_PRINTERW  0x0006
#define SHCNF_TYPE  0x00FF
#define SHCNF_FLUSH  0x1000
#define SHCNF_FLUSHNOWAIT 0x2000

#define QITIPF_DEFAULT  0x00000000
#define QITIPF_USENAME  0x00000001
#define QITIPF_LINKNOTARGET  0x00000002
#define QITIPF_LINKUSETARGET  0x00000004
#define QITIPF_USESLOWTIP       0x00000008
#define QITIPF_SINGLELINE       0x00000010

#define QIF_CACHED  0x00000001
#define QIF_DONTEXPANDFOLDER 0x00000002

#define SHARD_PIDL  0x00000001
#define SHARD_PATHA  0x00000002
#define SHARD_PATHW  0x00000003

#define SHGDFIL_FINDDATA  1
#define SHGDFIL_NETRESOURCE  2
#define SHGDFIL_DESCRIPTIONID  3

#define SHDID_ROOT_REGITEM  1
#define SHDID_FS_FILE  2
#define SHDID_FS_DIRECTORY  3
#define SHDID_FS_OTHER  4
#define SHDID_COMPUTER_DRIVE35  5
#define SHDID_COMPUTER_DRIVE525  6
#define SHDID_COMPUTER_REMOVABLE  7
#define SHDID_COMPUTER_FIXED  8
#define SHDID_COMPUTER_NETDRIVE  9
#define SHDID_COMPUTER_CDROM  10
#define SHDID_COMPUTER_RAMDISK  11
#define SHDID_COMPUTER_OTHER  12
#define SHDID_NET_DOMAIN  13
#define SHDID_NET_SERVER  14
#define SHDID_NET_SHARE  15
#define SHDID_NET_RESTOFNET  16
#define SHDID_NET_OTHER  17
#define SHDID_COMPUTER_IMAGING      18
#define SHDID_COMPUTER_AUDIO        19
#define SHDID_COMPUTER_SHAREDDOCS   20
#define SHDID_MOBILE_DEVICE         21  // PDA/PalmPC

#define PID_IS_URL  2
#define PID_IS_NAME  4
#define PID_IS_WORKINGDIR  5
#define PID_IS_HOTKEY  6
#define PID_IS_SHOWCMD  7
#define PID_IS_ICONINDEX  8
#define PID_IS_ICONFILE  9
#define PID_IS_WHATSNEW  10
#define PID_IS_AUTHOR  11
#define PID_IS_DESCRIPTION  12
#define PID_IS_COMMENT  13

#define PID_INTSITE_WHATSNEW  2
#define PID_INTSITE_AUTHOR  3
#define PID_INTSITE_LASTVISIT  4
#define PID_INTSITE_LASTMOD  5
#define PID_INTSITE_VISITCOUNT  6
#define PID_INTSITE_DESCRIPTION  7
#define PID_INTSITE_COMMENT  8
#define PID_INTSITE_FLAGS  9
#define PID_INTSITE_CONTENTLEN  10
#define PID_INTSITE_CONTENTCODE  11
#define PID_INTSITE_RECURSE  12
#define PID_INTSITE_WATCH  13
#define PID_INTSITE_SUBSCRIPTION  14
#define PID_INTSITE_URL  15
#define PID_INTSITE_TITLE  16
#define PID_INTSITE_CODEPAGE  18
#define PID_INTSITE_TRACKING  19
#define PID_INTSITE_ICONINDEX  20
#define PID_INTSITE_ICONFILE  21

#define PIDISF_RECENTLYCHANGED  0x00000001
#define PIDISF_CACHEDSTICKY  0x00000002
#define PIDISF_CACHEIMAGES  0x00000010
#define PIDISF_FOLLOWALLLINKS  0x00000020

#define PIDISM_GLOBAL  0
#define PIDISM_WATCH  1
#define PIDISM_DONTWATCH  2

#define SSF_SHOWALLOBJECTS  0x00000001
#define SSF_SHOWEXTENSIONS  0x00000002
#define SSF_SHOWCOMPCOLOR  0x00000008
#define SSF_SHOWSYSFILES  0x00000020
#define SSF_DOUBLECLICKINWEBVIEW  0x00000080
#define SSF_SHOWATTRIBCOL  0x00000100
#define SSF_DESKTOPHTML  0x00000200
#define SSF_WIN95CLASSIC  0x00000400
#define SSF_DONTPRETTYPATH  0x00000800
#define SSF_SHOWINFOTIP  0x00002000
#define SSF_MAPNETDRVBUTTON  0x00001000
#define SSF_NOCONFIRMRECYCLE  0x00008000
#define SSF_HIDEICONS  0x00004000

#define SHPPFW_NONE  0x00000000
#define SHPPFW_DEFAULT  SHPPFW_DIRCREATE
#define SHPPFW_DIRCREATE  0x00000001
#define SHPPFW_ASKDIRCREATE  0x00000002
#define SHPPFW_IGNOREFILENAME  0x00000004
#define SHPPFW_NOWRITECHECK  0x00000008
#if WINVER >= NTDDI_WINXP
	#define SHPPFW_MEDIACHECKONLY   0x00000010
#endif 

#define KF_FLAG_CREATE              0x00008000
#define KF_FLAG_DONT_VERIFY         0x00004000
#define KF_FLAG_DONT_UNEXPAND       0x00002000
#define KF_FLAG_NO_ALIAS            0x00001000
#define KF_FLAG_INIT                0x00000800
#define KF_FLAG_DEFAULT_PATH        0x00000400
#define KF_FLAG_NOT_PARENT_RELATIVE 0x00000200
#define KF_FLAG_SIMPLE_IDLIST       0x00000100

#define SHIMSTCAPFLAG_LOCKABLE    0x0001
#define SHIMSTCAPFLAG_PURGEABLE   0x0002

#define VALIDATEUNC_CONNECT     0x0001          // connect a drive letter
#define VALIDATEUNC_NOUI        0x0002          // don't bring up UI
#define VALIDATEUNC_PRINT       0x0004          // validate as print share instead of disk share
#if WINVER >= NTDDI_VISTA
	#define VALIDATEUNC_PERSIST     0x0008          // the connection should be made persistent
	#define VALIDATEUNC_VALID       0x000F          // valid flags
#else
	#define VALIDATEUNC_VALID       0x0007          // valid flags
#ENDIF

CM_MASK_WIDTH	= 0x1
CM_MASK_DEFAULTWIDTH	= 0x2
CM_MASK_IDEALWIDTH	= 0x4
CM_MASK_NAME	= 0x8
CM_MASK_STATE	= 0x10

CM_STATE_NONE	= 0
CM_STATE_VISIBLE	= 0x1
CM_STATE_FIXEDWIDTH	= 0x2
CM_STATE_NOSORTBYFOLDERNESS	= 0x4
CM_STATE_ALWAYSVISIBLE	= 0x8

CM_ENUM_ALL	= 0x1
CM_ENUM_VISIBLE	= 0x2

CM_WIDTH_USEDEFAULT	= -1
CM_WIDTH_AUTOSIZE	= -2

CM_COLUMNINFO STRUCT
	cbSize DD
	dwMask DD
	dwState DD
	uWidth DD
	uDefaultWidth DD
	uIdealWidth DD
	wszName WCHAR 80 DUP
ENDS

ENUMSHELLIMAGESTOREDATA STRUCT
	szPath DW MAX_PATH DUP
	ftTimeStamp FILETIME
ENDS

SHFOLDERCUSTOMSETTINGS STRUCT
	dwSize DD
	dwMask DD
	pvid PTR
	pszWebViewTemplate PTR
	cchWebViewTemplate DD
	pszWebViewTemplateVersion PTR
	pszInfoTip PTR
	cchInfoTip DD
	pclsid PTR
	dwFlags DD
	pszIconFile PTR
	cchIconFile DD
	iIconIndex DD
	pszLogo PTR
	cchLogo DD
ENDS

SHITEMID STRUCT
	cb DW
	abID DB
ENDS

ITEMIDLIST STRUCT
	mkid SHITEMID
ENDS

CMINVOKECOMMANDINFO STRUCT
	cbSize DD
	fMask DD
	hwnd HANDLE
	lpVerb PTR
	lpParameters PTR
	lpDirectory PTR
	nShow DD
	dwHotKey DD
	hIcon HANDLE
ENDS

CMINVOKECOMMANDINFOEX STRUCT
	cbSize DD
	fMask DD
	hwnd HANDLE
	lpVerb PTR
	lpParameters PTR
	lpDirectory PTR
	nShow DD
	dwHotKey DD
	hIcon HANDLE
	lpTitle PTR
	lpVerbW PTR
	lpParametersW PTR
	lpDirectoryW PTR
	lpTitleW PTR
	ptInvoke POINT
ENDS

IContextMenu STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryContextMenu PTR
	InvokeCommand PTR
	GetCommandString PTR
ENDS

IContextMenu2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryContextMenu PTR
	InvokeCommand PTR
	GetCommandString PTR
	HandleMenuMsg PTR
ENDS

IContextMenu3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryContextMenu PTR
	InvokeCommand PTR
	GetCommandString PTR
	HandleMenuMsg PTR
	HandleMenuMsg2 PTR
ENDS

IShellExtInit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
ENDS

IShellPropSheetExt STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddPages PTR
	ReplacePage PTR
ENDS

#IFDEF IPersistFolder
IPersistFolder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR 
	Initialize PTR
ENDS
#ENDIF

#IFDEF IPersistFolder2
IPersistFolder2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	Initialize PTR
	GetCurFolder PTR
ENDS
#ENDIF

#define CSIDL_FLAG_PFTI_TRACKTARGET CSIDL_FLAG_DONT_VERIFY

PERSIST_FOLDER_TARGET_INFO STRUCT
	pidlTargetFolder PTR
	szTargetParsingName DW MAX_PATH DUP
	szNetworkProvider DW MAX_PATH DUP
	dwAttributes DD
	csidl DD
ENDS

IPersistFolder3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	Initialize PTR
	GetCurFolder PTR
	InitializeEx PTR
	GetFolderTargetInfo PTR
ENDS

IPersistIDList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	SetIDList PTR
	GetIDList PTR
ENDS

IEnumIDList STRUCT
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
ENDS

IEnumFullIDList STRUCT
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
ENDS

IRemoteComputer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
ENDS

ISearchFolderItemFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetDisplayName PTR
	SetFolderTypeID PTR
	SetFolderLogicalViewMode PTR
	SetIconSize PTR
	SetVisibleColumns PTR
	SetSortColumns PTR
	SetGroupColumn PTR
	SetStacks PTR
	SetScope PTR
	SetCondition PTR
	GetShellItem PTR
	GetIDList PTR
ENDS

IExtractIconA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetIconLocation PTR
	Extract PTR
ENDS

IExtractIconW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetIconLocation PTR
	Extract PTR
ENDS

IShellIcon STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetIconOf PTR
ENDS

IShellIconOverlayIdentifier STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsMemberOf PTR
	GetOverlayInfo PTR
	GetPriority PTR
ENDS

IShellIconOverlay STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetOverlayIndex PTR
	GetOverlayIconIndex PTR
ENDS

SLR_NO_UI = 0x0001
SLR_ANY_MATCH = 0x0002
SLR_UPDATE = 0x0004
SLR_NOUPDATE = 0x0008
SLR_NOSEARCH = 0x0010
SLR_NOTRACK = 0x0020
SLR_NOLINKINFO = 0x0040
SLR_INVOKE_MSI = 0x0080
SLR_NO_UI_WITH_MSG_PUMP	= 0x101
SLR_OFFER_DELETE_WITHOUT_FILE	= 0x200
SLR_KNOWNFOLDER	= 0x400
SLR_MACHINE_IN_LOCAL_TARGET	= 0x800
SLR_UPDATE_MACHINE_AND_SID	= 0x1000

SLGP_SHORTPATH = 0x0001
SLGP_UNCPRIORITY = 0x0002
SLGP_RAWPATH = 0x0004
SLGP_RELATIVEPRIORITY	= 0x8

IShellLinkA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPath PTR
	GetIDList PTR
	SetIDList PTR
	GetDescription PTR
	SetDescription PTR
	GetWorkingDirectory PTR
	SetWorkingDirectory PTR
	GetArguments PTR
	SetArguments PTR
	GetHotkey PTR
	SetHotkey PTR
	GetShowCmd PTR
	SetShowCmd PTR
	GetIconLocation PTR
	SetIconLocation PTR
	SetRelativePath PTR
	Resolve PTR
	SetPath PTR
ENDS

IShellLinkW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPath PTR
	GetIDList PTR
	SetIDList PTR
	GetDescription PTR
	SetDescription PTR
	GetWorkingDirectory PTR
	SetWorkingDirectory PTR
	GetArguments PTR
	SetArguments PTR
	GetHotkey PTR
	SetHotkey PTR
	GetShowCmd PTR
	SetShowCmd PTR
	GetIconLocation PTR
	SetIconLocation PTR
	SetRelativePath PTR
	Resolve PTR
	SetPath PTR
ENDS

SLDF_HAS_ID_LIST                            = 0x00000001   // Shell link saved with ID list
SLDF_HAS_LINK_INFO                          = 0x00000002   // Shell link saved with LinkInfo
SLDF_HAS_NAME                               = 0x00000004
SLDF_HAS_RELPATH                            = 0x00000008
SLDF_HAS_WORKINGDIR                         = 0x00000010
SLDF_HAS_ARGS                               = 0x00000020
SLDF_HAS_ICONLOCATION                       = 0x00000040
SLDF_UNICODE                                = 0x00000080   // the strings are unicode
SLDF_FORCE_NO_LINKINFO                      = 0x00000100   // disable LINKINFO tracking information (used to track network drives and compute UNC paths if one exists)
SLDF_HAS_EXP_SZ                             = 0x00000200   // the link contains expandable env strings
SLDF_RUN_IN_SEPARATE                        = 0x00000400   // Run the 16-bit target exe in a separate VDM/WOW
SLDF_HAS_LOGO3ID                            = 0x00000800   // not used anymore
SLDF_HAS_DARWINID                           = 0x00001000   // MSI (Darwin) link that can be installed on demand
SLDF_RUNAS_USER                             = 0x00002000   // Run target as a different user
SLDF_HAS_EXP_ICON_SZ                        = 0x00004000   // contains expandable env string for icon path
SLDF_NO_PIDL_ALIAS                          = 0x00008000   // disable IDList alias mapping when parsing the IDList from the path
SLDF_FORCE_UNCNAME                          = 0x00010000   // make GetPath() prefer the UNC name to the local name
SLDF_RUN_WITH_SHIMLAYER                     = 0x00020000   // activate target of this link with shim layer active
SLDF_FORCE_NO_LINKTRACK                     = 0x00040000   // disable ObjectID tracking information
SLDF_ENABLE_TARGET_METADATA                 = 0x00080000   // enable caching of target metadata into link
SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING  = 0x00200000   // disable KnownFolder tracking information (EXP_KNOWN_FOLDER)
SLDF_VALID                                  = 0x003FF7FF   // bits that are valid for ::SetFlags()
SLDF_RESERVED                               = 0x80000000   // Reserved-- so we can use the low word as an index value in the future

DATABLOCK_HEADER STRUCT
	cbSize DD
	dwSignature DD
ENDS

NT_CONSOLE_PROPS STRUCT
	dbh DATABLOCK_HEADER
	wFillAttribute DW
	wPopupFillAttribute DW
	dwScreenBufferSize COORD
	dwWindowSize COORD
	dwWindowOrigin COORD
	nFont DD
	nInputBufferSize DD
	dwFontSize COORD
	uFontFamily DD
	uFontWeight DD
	FaceName DW LF_FACESIZE DUP
	uCursorSize DD
	bFullScreen DD
	bQuickEdit DD
	bInsertMode DD
	bAutoPosition DD
	uHistoryBufferSize DD
	uNumberOfHistoryBuffers DD
	bHistoryNoDup DD
	ColorTable DD 16 DUP
ENDS

NT_FE_CONSOLE_PROPS STRUCT
	dbh DATABLOCK_HEADER
	uCodePage DD
ENDS

EXP_DARWIN_LINK STRUCT
	dbh DATABLOCK_HEADER
	szDarwinID DB MAX_PATH DUP
	szwDarwinID DW MAX_PATH DUP
ENDS

#define EXP_DARWIN_ID_SIG  0xA0000006
#define EXP_LOGO3_ID_SIG  0xA0000007

#define EXP_SPECIAL_FOLDER_SIG  0xA0000005

EXP_SPECIAL_FOLDER STRUCT
	cbSize DD
	dwSignature DD
	idSpecialFolder DD
	cbOffset DD
ENDS

EXP_SZ_LINK STRUCT
	cbSize DD
	dwSignature DD
	szTarget DB MAX_PATH DUP
	swzTarget DW MAX_PATH DUP
ENDS

#define EXP_SZ_LINK_SIG  0xA0000001
#define EXP_SZ_ICON_SIG  0xA0000007

EXP_PROPERTYSTORAGE STRUCT
	cbSize DD
	dwSignature DD
	abPropertyStorage DB
ENDS

#define EXP_PROPERTYSTORAGE_SIG     0xA0000009

IShellLinkDataList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddDataBlock PTR
	CopyDataBlock PTR
	RemoveDataBlock PTR
	GetFlags PTR
	SetFlags PTR
ENDS

IResolveShellLink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ResolveShellLink PTR
ENDS

IShellExecuteHookA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Execute PTR
ENDS

IShellExecuteHookW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Execute PTR
ENDS

IURLSearchHook STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Translate PTR
ENDS

ISearchContext STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSearchUrl PTR
	GetSearchText PTR
	GetSearchStyle PTR
ENDS

IURLSearchHook2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Translate PTR
	TranslateWithSearchContext PTR
ENDS

INewShortcutHookA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetReferent PTR
	GetReferent PTR
	SetFolder PTR
	GetFolder PTR
	GetName PTR
	GetExtension PTR
ENDS

INewShortcutHookW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetReferent PTR
	GetReferent PTR
	SetFolder PTR
	GetFolder PTR
	GetName PTR
	GetExtension PTR
ENDS

ICopyHookA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CopyCallback PTR
ENDS

ICopyHookW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CopyCallback PTR
ENDS

IFileViewerSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetPinnedWindow PTR
	GetPinnedWindow PTR
ENDS

FVSHOWINFO STRUCT
	cbSize DD
	hwndOwner HANDLE
	iShow DD
	dwFlags DD
	rect RECT
	punkRel PTR
	strNewFile DW MAX_PATH 256 DUP
ENDS

IFileViewerA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowInitialize PTR
	Show PTR
	PrintTo PTR
ENDS

IFileViewerW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowInitialize PTR
	Show PTR
	PrintTo PTR
ENDS

#IFNDEF FWF_CHECKSELECT
FWF_AUTOARRANGE	= 0x1
FWF_ABBREVIATEDNAMES	= 0x2
FWF_SNAPTOGRID	= 0x4
FWF_OWNERDATA	= 0x8
FWF_BESTFITWINDOW	= 0x10
FWF_DESKTOP	= 0x20
FWF_SINGLESEL	= 0x40
FWF_NOSUBFOLDERS	= 0x80
FWF_TRANSPARENT	= 0x100
FWF_NOCLIENTEDGE	= 0x200
FWF_NOSCROLL	= 0x400
FWF_ALIGNLEFT	= 0x800
FWF_NOICONS	= 0x1000
FWF_SHOWSELALWAYS	= 0x2000
FWF_NOVISIBLE	= 0x4000
FWF_SINGLECLICKACTIVATE	= 0x8000
FWF_NOWEBVIEW	= 0x10000
FWF_HIDEFILENAMES	= 0x20000
FWF_CHECKSELECT	= 0x40000
#ENDIF

#IFNDEF FVM_LAST
FVM_FIRST	= 1
FVM_ICON	= 1
FVM_SMALLICON	= 2
FVM_LIST	= 3
FVM_DETAILS	= 4
FVM_THUMBNAIL	= 5
FVM_TILE	= 6
FVM_THUMBSTRIP	= 7
FVM_LAST	= 7
#ENDIF

#IFNDEF FLVM_LAST
FLVM_UNSPECIFIED	= -1
FLVM_FIRST	= 1
FLVM_DETAILS	= 1
FLVM_TILES	= 2
FLVM_ICONS	= 3
FLVM_LIST	= 4
FLVM_CONTENT	= 5
FLVM_LAST	= 5
#ENDIF

#IFNDEF FOLDERSETTINGS
FOLDERSETTINGS STRUCT
	ViewMode DD
	fFlags DD
ENDS
#ENDIF

IShellBrowser STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	InsertMenusSB PTR
	SetMenuSB PTR
	RemoveMenusSB PTR
	SetStatusTextSB PTR
	EnableModelessSB PTR
	TranslateAcceleratorSB PTR
	BrowseObject PTR
	GetViewStateStream PTR
	GetControlWindow PTR
	SendControlMsg PTR
	QueryActiveShellView PTR
	OnViewWindowActive PTR
	SetToolbarItems PTR
ENDS

SBSC_HIDE = 0
SBSC_SHOW = 1
SBSC_TOGGLE = 2
SBSC_QUERY =  3

SBO_DEFAULT = 0
SBO_NOBROWSERPAGES = 1

ICommDlgBrowser STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnDefaultCommand PTR
	OnStateChange PTR
	IncludeObject PTR
ENDS

ICommDlgBrowser2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnDefaultCommand PTR
	OnStateChange PTR
	IncludeObject PTR
	Notify PTR
	GetDefaultMenuText PTR
	GetViewFlags PTR
ENDS

#IFNDEF SVUIA_INPLACEACTIVATE
SVUIA_DEACTIVATE	= 0
SVUIA_ACTIVATE_NOFOCUS	= 1
SVUIA_ACTIVATE_FOCUS	= 2
SVUIA_INPLACEACTIVATE	= 3
#ENDIF

#IFNDEF IShellView
IShellView STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	TranslateAccelerator PTR
	EnableModeless PTR
	UIActivate PTR
	Refresh PTR
	CreateViewWindow PTR
	DestroyViewWindow PTR
	GetCurrentInfo PTR
	AddPropertySheetPages PTR
	SaveViewState PTR
	SelectItem PTR
	GetItemObject PTR
ENDS
#ENDIF

SV2CVW2_PARAMS STRUCT
	cbSize DD
	psvPrev PTR
	pfs PTR
	psbOwner PTR
	prcView PTR
	pvid PTR
	hwndView HANDLE
ENDS

IShellView2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	TranslateAccelerator PTR
	EnableModeless PTR
	UIActivate PTR
	Refresh PTR
	CreateViewWindow PTR
	DestroyViewWindow PTR
	GetCurrentInfo PTR
	AddPropertySheetPages PTR
	SaveViewState PTR
	SelectItem PTR
	GetItemObject PTR
	GetView PTR
	CreateViewWindow2 PTR
	HandleRename PTR
	SelectAndPositionItem PTR
ENDS

SV3CVW3_DEFAULT	= 0
SV3CVW3_NONINTERACTIVE	= 0x1
SV3CVW3_FORCEVIEWMODE	= 0x2
SV3CVW3_FORCEFOLDERFLAGS	= 0x4

IShellView3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	TranslateAccelerator PTR
	EnableModeless PTR
	UIActivate PTR
	Refresh PTR
	CreateViewWindow PTR
	DestroyViewWindow PTR
	GetCurrentInfo PTR
	AddPropertySheetPages PTR
	SaveViewState PTR
	SelectItem PTR
	GetItemObject PTR
	GetView PTR
	CreateViewWindow2 PTR
	HandleRename PTR
	SelectAndPositionItem PTR
	CreateViewWindow3 PTR
ENDS

IFolderView STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCurrentViewMode PTR
	SetCurrentViewMode PTR
	GetFolder PTR
	Item PTR
	ItemCount PTR
	Items PTR
	GetSelectionMarkedItem PTR
	GetFocusedItem PTR
	GetItemPosition PTR
	GetSpacing PTR
	GetDefaultSpacing PTR
	GetAutoArrange PTR
	SelectItem PTR
	SelectAndPositionItems PTR
ENDS

IFolderView2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCurrentViewMode PTR
	SetCurrentViewMode PTR
	GetFolder PTR
	Item PTR
	ItemCount PTR
	Items PTR
	GetSelectionMarkedItem PTR
	GetFocusedItem PTR
	GetItemPosition PTR
	GetSpacing PTR
	GetDefaultSpacing PTR
	GetAutoArrange PTR
	SelectItem PTR
	SelectAndPositionItems PTR
	SetGroupBy PTR
	GetGroupBy PTR
	SetViewProperty PTR
	GetViewProperty PTR
	SetTileViewProperties PTR
	SetExtendedTileViewProperties PTR
	SetText PTR
	SetCurrentFolderFlags PTR
	GetCurrentFolderFlags PTR
	GetSortColumnCount PTR
	SetSortColumns PTR
	GetSortColumns PTR
	GetItem PTR
	GetVisibleItem PTR
	GetSelectedItem PTR
	GetSelection PTR
	GetSelectionState PTR
	InvokeVerbOnSelection PTR
	SetViewModeAndIconSize PTR
	GetViewModeAndIconSize PTR
	SetGroupSubsetCount PTR
	GetGroupSubsetCount PTR
	SetRedraw PTR
	IsMoveInSameFolder PTR
	DoRename PTR
ENDS

IPreviewHandlerVisuals STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetBackgroundColor PTR
	SetFont PTR
	SetTextColor PTR
ENDS

VPWF_DEFAULT	= 0
VPWF_ALPHABLEND	= 0x1

VPCF_TEXT	= 1
VPCF_BACKGROUND	= 2
VPCF_SORTCOLUMN	= 3
VPCF_SUBTEXT	= 4
VPCF_TEXTBACKGROUND	= 5

IVisualProperties STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetWatermark PTR
	SetColor PTR
	GetColor PTR
	SetItemHeight PTR
	GetItemHeight PTR
	SetFont PTR
	GetFont PTR
	SetTheme PTR
ENDS

#define CDBOSC_SETFOCUS     0x00000000
#define CDBOSC_KILLFOCUS    0x00000001
#define CDBOSC_SELCHANGE    0x00000002
#define CDBOSC_RENAME       0x00000003
#define CDBOSC_STATECHANGE  0x00000004

ICommDlgBrowser STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnDefaultCommand PTR
	OnStateChange PTR
	IncludeObject PTR
ENDS

ICommDlgBrowser2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnDefaultCommand PTR
	OnStateChange PTR
	IncludeObject PTR
	Notify PTR
	GetDefaultMenuText PTR
	GetViewFlags PTR
ENDS

ICommDlgBrowser3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnDefaultCommand PTR
	OnStateChange PTR
	IncludeObject PTR
	Notify PTR
	GetDefaultMenuText PTR
	GetViewFlags PTR
	OnColumnClicked PTR
	GetCurrentFilter PTR
	OnPreViewCreated PTR
ENDS

IColumnManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetColumnInfo PTR
	GetColumnInfo PTR
	GetColumnCount PTR
	GetColumns PTR
	SetColumns PTR
ENDS

IFolderFilterSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFilter PTR
ENDS

IFolderFilter STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShouldShow PTR
	GetEnumFlags PTR
ENDS

IInputObjectSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnFocusChangeIS PTR
ENDS

IInputObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UIActivateIO PTR
	HasFocusIO PTR
	TranslateAcceleratorIO PTR
ENDS

IInputObject2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UIActivateIO PTR
	HasFocusIO PTR
	TranslateAcceleratorIO PTR
	TranslateAcceleratorGlobal PTR
ENDS

IFolderViewSettings STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetColumnPropertyList PTR
	GetGroupByProperty PTR
	GetViewMode PTR
	GetIconSize PTR
	GetFolderFlags PTR
	GetSortColumns PTR
	GetGroupSubsetCount PTR
ENDS

ISearchBoxInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCondition PTR
	GetText PTR
ENDS

SORT_DESCENDING	= -1
SORT_ASCENDING	= 1

FVST_EMPTYTEXT	= 0

#IFNDEF PROPERTYKEY
	PROPERTYKEY struct
		fmtid GUID
		pid DD
	ENDS
#ENDIF

SORTCOLUMN STRUCT
	propkey PROPERTYKEY
	direction DD
ENDS

STRRET STRUCT
	uType DD
	UNION
		pOleStr PTR
		pStr PTR
		uOffset DD
		cStr DB MAX_PATH DUP
	ENDUNION
ENDS

SHGFP_TYPE_CURRENT = 0
SHGFP_TYPE_DEFAULT = 1

BROWSEINFOA STRUCT
	hwndOwner HANDLE
	pidlRoot PTR
	pszDisplayName PTR
	lpszTitle PTR
	ulFlags DD
	lpfn PTR
	lParam LPARAM
	iImage DD
ENDS

BROWSEINFOW STRUCT
	hwndOwner HANDLE
	pidlRoot PTR
	pszDisplayName PTR
	lpszTitle PTR
	ulFlags DD
	lpfn PTR
	lParam LPARAM
	iImage DD
ENDS

#IFNDEF IEnumIDList
IEnumIDList STRUCT
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
ENDS
#ENDIF

#IFNDEF SHGDN_FORPARSING
SHGDN_NORMAL             = 0x0000  // default (display purpose)
SHGDN_INFOLDER           = 0x0001  // displayed under a folder (relative)
SHGDN_FOREDITING         = 0x1000  // for in-place editing
SHGDN_FORADDRESSBAR      = 0x4000  // UI friendly parsing name (remove ugly stuff)
SHGDN_FORPARSING         = 0x8000  // parsing name for ParseDisplayName()
#ENDIF

#IFNDEF SHCONTF_STORAGE
SHCONTF_FOLDERS             = 0x0020   // only want folders enumerated (SFGAO_FOLDER)
SHCONTF_NONFOLDERS          = 0x0040   // include non folders
SHCONTF_INCLUDEHIDDEN       = 0x0080   // show items normally hidden
SHCONTF_INIT_ON_FIRST_NEXT  = 0x0100   // allow EnumObject() to return before validating enum
SHCONTF_NETPRINTERSRCH      = 0x0200   // hint that client is looking for printers
SHCONTF_SHAREABLE           = 0x0400   // hint that client is looking sharable resources (remote shares)
SHCONTF_STORAGE             = 0x0800   // include all items with accessible storage and their ancestors
#ENDIF

#IFNDEF IShellFolder
IShellFolder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseDisplayName PTR
	EnumObjects PTR
	BindToObject PTR
	BindToStorage PTR
	CompareIDs PTR
	CreateViewObject PTR
	GetAttributesOf PTR
	GetUIObjectOf PTR
	GetDisplayNameOf PTR
	SetNameOf PTR
ENDS
#ENDIF

IFileSystemBindData STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFindData PTR
	GetFindData PTR
ENDS

SHELLDETAILS STRUCT
	fmt DD
	xcxChar DD
	str STRRET
ENDS

IShellDetails STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDetailsOf PTR
	ColumnClick PTR
ENDS

#IFNDEF EXTRASEARCH
EXTRASEARCH STRUCT
	guidSearch GUID
	wszFriendlyName DW 80 DUP
	wszUrl DW 2084 DUP
ENDS
#ENDIF

#IFNDEF IEnumExtraSearch
IEnumExtraSearch STRUCT
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
ENDS
#ENDIF

#IFNDEF SHCOLSTATE_PREFER_VARCMP
SHCOLSTATE_TYPE_STR	= 0x1
SHCOLSTATE_TYPE_INT	= 0x2
SHCOLSTATE_TYPE_DATE	= 0x3
SHCOLSTATE_TYPEMASK	= 0xf
SHCOLSTATE_ONBYDEFAULT	= 0x10
SHCOLSTATE_SLOW	= 0x20
SHCOLSTATE_EXTENDED	= 0x40
SHCOLSTATE_SECONDARYUI	= 0x80
SHCOLSTATE_HIDDEN	= 0x100
SHCOLSTATE_PREFER_VARCMP	= 0x200
#ENDIF

#define ISFB_MASK_STATE          0x00000001
#define ISFB_MASK_BKCOLOR        0x00000002
#define ISFB_MASK_VIEWMODE       0x00000004
#define ISFB_MASK_SHELLFOLDER    0x00000008
#define ISFB_MASK_IDLIST         0x00000010
#define ISFB_MASK_COLORS         0x00000020

#define ISFB_STATE_DEFAULT       0x00000000
#define ISFB_STATE_DEBOSSED      0x00000001
#define ISFB_STATE_ALLOWRENAME   0x00000002
#define ISFB_STATE_NOSHOWTEXT    0x00000004
#define ISFB_STATE_CHANNELBAR    0x00000010
#define ISFB_STATE_QLINKSMODE    0x00000020
#define ISFB_STATE_FULLOPEN      0x00000040
#define ISFB_STATE_NONAMESORT    0x00000080
#define ISFB_STATE_BTNMINSIZE    0x00000100

#define ISFBVIEWMODE_SMALLICONS   0x0001
#define ISFBVIEWMODE_LARGEICONS   0x0002
#define ISFBVIEWMODE_LOGOS        0x0003

#IFNDEF SHCOLUMNID
SHCOLUMNID STRUCT
	fmtid GUID
	pid PTR
ENDS
#ENDIF

IEnumShellImageStore STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Reset PTR
	Next PTR
	Skip PTR
	Clone PTR
ENDS

IShellImageStore STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Open PTR
	Create PTR
	ReleaseLock PTR
	Close PTR
	Commit PTR
	IsLocked PTR
	GetMode PTR
	GetCapabilities PTR
	AddEntry PTR
	GetEntry PTR
	DeleteEntry PTR
	IsEntryInStore PTR
	Enum PTR
ENDS

IThumbnailCapture STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CaptureThumbnail PTR
ENDS

IShellFolder2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParseDisplayName PTR
	EnumObjects PTR
	BindToObject PTR
	BindToStorage PTR
	CompareIDs PTR
	CreateViewObject PTR
	GetAttributesOf PTR
	GetUIObjectOf PTR
	GetDisplayNameOf PTR
	SetNameOf PTR
	GetDefaultSearchGUID PTR
	EnumSearches PTR
	GetDefaultColumn PTR
	GetDefaultColumnState PTR
	GetDetailsEx PTR
	GetDetailsOf PTR
	MapColumnToSCID PTR
ENDS

#IFNDEF ITaskbarList
ITaskbarList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	HrInit PTR
	AddTab PTR
	DeleteTab PTR
	ActivateTab PTR
	SetActiveAlt PTR
ENDS
#ENDIF

IObjMgr STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Append PTR
	Remove PTR
ENDS

ICurrentWorkingDirectory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDirectory PTR
	SetDirectory PTR
ENDS

IACList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Expand PTR
ENDS

ACLO_NONE = 0
ACLO_CURRENTDIR = 1
ACLO_MYCOMPUTER = 2
ACLO_DESKTOP = 4
ACLO_FAVORITES = 8
ACLO_FILESYSONLY = 16
ACLO_FILESYSDIRS     = 32
ACLO_VIRTUALNAMESPACE = 64

IACList2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Expand PTR
	SetOptions PTR
	GetOptions PTR
ENDS

IProgressDialog STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	StartProgressDialog PTR
	StopProgressDialog PTR
	SetTitle PTR
	SetAnimation PTR
	HasUserCancelled PTR
	SetProgress PTR
	SetProgress64 PTR
	SetLine PTR
	SetCancelMsg PTR
	Timer PTR
ENDS

IInputObjectSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnFocusChangeIS PTR
ENDS

IInputObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UIActivateIO PTR
	HasFocusIO PTR
	TranslateAcceleratorIO PTR
ENDS

IDockingWindowSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	GetBorderDW PTR
	RequestBorderSpaceDW PTR
	SetBorderSpaceDW PTR
ENDS

IDockingWindowFrame STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	AddToolbar PTR
	RemoveToolbar PTR
	FindToolbar PTR
ENDS

IDockingWindow STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	ShowDW PTR
	CloseDW PTR
	ResizeBorderDW PTR
ENDS

DESKBANDINFO STRUCT
	dwMask DD
	ptMinSize POINTL
	ptMaxSize POINTL
	ptIntegral POINTL
	ptActual POINTL
	wszTitle DW 256 DUP
	dwModeFlags DD
	crBkgnd DD
ENDS

BANDINFOSFB STRUCT
	dwMask DD
	dwStateMask DD
	dwState DD
	crBkgnd DD
	crBtnLt DD
	crBtnDk DD
	wViewMode DW
	wAlign DW
	psf PTR
	pidl PTR
ENDS

IShellFolderBand STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitializeSFB PTR
	SetBandInfoSFB PTR
	GetBandInfoSFB PTR
ENDS

IDeskBarClient STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
    // *** IOleWindow methods ***
	GetWindow PTR
	ContextSensitiveHelp PTR
    // *** IDeskBarClient methods ***
	SetDeskBarSite PTR
	SetModeDBC PTR
	UIActivateDBC PTR
	GetSize PTR
ENDS

#define DBC_GS_IDEAL          0  // get the ideal size
#define DBC_GS_SIZEDOWN       1  // clip the height of a rect to a multiple of the rebar's integral size

#define DBC_HIDE        0 // Band is hidden (being destroyed)
#define DBC_SHOW        1 // Band is visible
#define DBC_SHOWOBSCURE 2 // Band is completely obscured

DBCID_EMPTY = 0
DBCID_ONDRAG = 1
DBCID_CLSIDOFBAR = 2
DBCID_RESIZE = 3
DBCID_GETBAR = 4

IDeskBand STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	ShowDW PTR
	CloseDW PTR
	ResizeBorderDW PTR
	GetBandInfo PTR
ENDS

DBID_BANDINFOCHANGED = 0
DBID_SHOWONLY = 1
DBID_MAXIMIZEBAND = 2
DBID_PUSHCHEVRON = 3
DBID_DELAYINIT = 4
DBID_FINISHINIT = 5

#define IRTIR_TASK_NOT_RUNNING  0
#define IRTIR_TASK_RUNNING  1
#define IRTIR_TASK_SUSPENDED  2
#define IRTIR_TASK_PENDING  3
#define IRTIR_TASK_FINISHED  4

IRunnableTask STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Run PTR
	Kill PTR
	Suspend PTR
	Resume PTR
	IsRunning PTR
ENDS

#define IEI_PRIORITY_MAX ITSAT_MAX_PRIORITY
#define IEI_PRIORITY_MIN ITSAT_MIN_PRIORITY
#define IEIT_PRIORITY_NORMAL ITSAT_DEFAULT_PRIORITY

#define IEIFLAG_ASYNC 0x0001
#define IEIFLAG_CACHE 0x0002
#define IEIFLAG_ASPECT 0x0004
#define IEIFLAG_OFFLINE 0x0008
#define IEIFLAG_GLEAM 0x0010
#define IEIFLAG_SCREEN 0x0020
#define IEIFLAG_ORIGSIZE 0x0040
#define IEIFLAG_NOSTAMP 0x0080
#define IEIFLAG_NOBORDER 0x0100
#define IEIFLAG_QUALITY 0x0200
#define IEIFLAG_REFRESH 0x0400 

IExtractImage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLocation PTR
	Extract PTR
ENDS

IExtractImage2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLocation PTR
	Extract PTR
	GetDateStamp PTR
ENDS

WALLPAPEROPT STRUCT
	dwSize DD
	dwStyle DD
ENDS

COMPONENTSOPT STRUCT
	dwSize DD
	fEnableComponents DD
	fActiveDesktop DD
ENDS

COMPPOS STRUCT
	dwSize DD
	iLeft DD
	iTop DD
	dwWidth DD
	dwHeight DD
	izIndex DD
	fCanResize DD
	fCanResizeX DD
	fCanResizeY DD
	iPreferredLeftPercent DD
	iPreferredTopPercent DD
ENDS

COMPSTATEINFO STRUCT
	dwSize DD
	iLeft DD
	iTop DD
	dwWidth DD
	dwHeight DD
	dwItemState DD
ENDS

#define COMPONENT_TOP  (0x3fffffff)

#define COMP_TYPE_HTMLDOC  0
#define COMP_TYPE_PICTURE  1
#define COMP_TYPE_WEBSITE  2
#define COMP_TYPE_CONTROL  3
#define COMP_TYPE_CFHTML  4
#define COMP_TYPE_MAX  4

IE4COMPONENT STRUCT
	dwSize DD
	dwID DD
	iComponentType DD
	fChecked DD
	fDirty DD
	fNoScrollDD
	cpPos COMPPOS
	wszFriendlyName DW MAX_PATH DUP
	wszSource DW INTERNET_MAX_URL_LENGTH DUP
	wszSubscribedURL DW INTERNET_MAX_URL_LENGTH DUP
ENDS

COMPONENT STRUCT
	dwSize DD
	dwID DD
	iComponentType DD
	fChecked DD
	fDirty DD
	fNoScrollDD
	cpPos COMPPOS
	wszFriendlyName DW MAX_PATH DUP
	wszSource DW INTERNET_MAX_URL_LENGTH DUP
	wszSubscribedURL DW INTERNET_MAX_URL_LENGTH DUP
	dwCurItemState DD
	csiOriginal COMPSTATEINFO
	csiRestored COMPSTATEINFO
ENDS

#define IS_NORMAL  0x00000001
#define IS_FULLSCREEN  0x00000002
#define IS_SPLIT  0x00000004
#define IS_VALIDSIZESTATEBITS  (IS_NORMAL|IS_SPLIT|IS_FULLSCREEN)
#define IS_VALIDSTATEBITS  (IS_NORMAL|IS_SPLIT|IS_FULLSCREEN|0x80000000|0x40000000)

#define AD_APPLY_SAVE  0x00000001
#define AD_APPLY_HTMLGEN  0x00000002
#define AD_APPLY_REFRESH  0x00000004
#define AD_APPLY_ALL  (AD_APPLY_SAVE|AD_APPLY_HTMLGEN|AD_APPLY_REFRESH)
#define AD_APPLY_FORCE  0x00000008
#define AD_APPLY_BUFFERED_REFRESH 0x00000010
#define AD_APPLY_DYNAMICREFRESH  0x00000020

#define WPSTYLE_CENTER  0
#define WPSTYLE_TILE  1
#define WPSTYLE_STRETCH  2
#define WPSTYLE_MAX  3

#define COMP_ELEM_TYPE  0x00000001
#define COMP_ELEM_CHECKED  0x00000002
#define COMP_ELEM_DIRTY  0x00000004
#define COMP_ELEM_NOSCROLL  0x00000008
#define COMP_ELEM_POS_LEFT  0x00000010
#define COMP_ELEM_POS_TOP  0x00000020
#define COMP_ELEM_SIZE_WIDTH  0x00000040
#define COMP_ELEM_SIZE_HEIGHT  0x00000080
#define COMP_ELEM_POS_ZINDEX  0x00000100
#define COMP_ELEM_SOURCE  0x00000200
#define COMP_ELEM_FRIENDLYNAME  0x00000400
#define COMP_ELEM_SUBSCRIBEDURL 0x00000800
#define COMP_ELEM_ORIGINAL_CSI  0x00001000
#define COMP_ELEM_RESTORED_CSI  0x00002000
#define COMP_ELEM_CURITEMSTATE  0x00004000

#define COMP_ELEM_ALL  (COMP_ELEM_TYPE|COMP_ELEM_CHECKED|COMP_ELEM_DIRTY|COMP_ELEM_NOSCROLL|COMP_ELEM_POS_LEFT|COMP_ELEM_SIZE_WIDTH|COMP_ELEM_SIZE_HEIGHT|COMP_ELEM_POS_ZINDEX|COMP_ELEM_SOURCE|COMP_ELEM_FRIENDLYNAME|COMP_ELEM_POS_TOP|COMP_ELEM_SUBSCRIBEDURL|COMP_ELEM_ORIGINAL_CSI|COMP_ELEM_RESTORED_CSI|COMP_ELEM_CURITEMSTATE)

DTI_ADDUI_DEFAULT = 0x00000000
DTI_ADDUI_DISPSUBWIZARD = 0x00000001
DTI_ADDUI_POSITIONITEM = 0x00000002

#define ADDURL_SILENT  0X0001

#define COMPONENT_DEFAULT_LEFT  0xFFFF
#define COMPONENT_DEFAULT_TOP  0xFFFF

IActiveDesktop STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ApplyChanges PTR
	GetWallpaper PTR
	SetWallpaper PTR
	GetWallpaperOptions PTR
	SetWallpaperOptions PTR
	GetPattern PTR
	SetPattern PTR
	GetDesktopItemOptions PTR
	SetDesktopItemOptions PTR
	AddDesktopItem PTR
	AddDesktopItemWithUI PTR
	ModifyDesktopItem PTR
	RemoveDesktopItem PTR
	GetDesktopItemCount PTR
	GetDesktopItem PTR
	GetDesktopItemByID PTR
	GenerateDesktopItemHtml PTR
	AddUrl PTR
	GetDesktopItemBySource PTR
ENDS

#define MAX_COLUMN_NAME_LEN  80
#define MAX_COLUMN_DESC_LEN  128

// Flags for SetSafeMode
#define SSM_CLEAR   0x0000
#define SSM_SET     0x0001
#define SSM_REFRESH 0x0002
#define SSM_UPDATE  0x0004

// Flags for Set/GetScheme
#define SCHEME_DISPLAY          0x0001
#define SCHEME_EDIT             0x0002
#define SCHEME_LOCAL            0x0004
#define SCHEME_GLOBAL           0x0008
#define SCHEME_REFRESH          0x0010
#define SCHEME_UPDATE           0x0020
#define SCHEME_DONOTUSE 0x0040 // used to be SCHEME_ENUMERATE; no longer supported
#define SCHEME_CREATE           0x0080

IActiveDesktopP STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetSafeMode PTR
	EnsureUpdateHTML PTR
	SetScheme PTR
	GetScheme PTR
ENDS

//Flags for GetObjectFlags
#define GADOF_DIRTY    0x00000001

IADesktopP2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ReReadWallpaper PTR
	GetADObjectFlags PTR
	UpdateAllDesktopSubscriptions PTR
	MakeDynamicChanges PTR
ENDS

#define ARCONTENT_AUTORUNINF             0x00000002   // That's the one we have today, and always had
#define ARCONTENT_AUDIOCD                0x00000004   // Audio CD (not MP3 and the like, the stuff you buy at the store)
#define ARCONTENT_DVDMOVIE               0x00000008   // DVD Movie (not MPEGs, the stuff you buy at the store)
#define ARCONTENT_BLANKCD                0x00000010   // Blank CD-R/CD-RW)
#define ARCONTENT_BLANKDVD               0x00000020   // Blank DVD-R/DVD-RW
#define ARCONTENT_UNKNOWNCONTENT         0x00000040   // Whatever files.  Mean that it's formatted.
#define ARCONTENT_AUTOPLAYPIX            0x00000080   // Any files classified by shell as image. (jpg, bmp, etc.)
#define ARCONTENT_AUTOPLAYMUSIC          0x00000100   // Any files classified by shell as music. (wma, mp3, etc.)
#define ARCONTENT_AUTOPLAYVIDEO          0x00000200   // Any files classified by shell as video. (mpg, avi, etc.)
#if WINVER >= NTDDI_VISTA
#define ARCONTENT_VCD                    0x00000400   // VCD format
#define ARCONTENT_SVCD                   0x00000800   // Super-VCD format
#define ARCONTENT_DVDAUDIO               0x00001000   // DVD-Audio
#define ARCONTENT_BLANKBD                0x00002000   // Blank BD-R/BD-RW
#define ARCONTENT_BLURAY                 0x00004000   // Blu-ray Disc
#define ARCONTENT_NONE                   0x00000000   // Empty (but formatted)
#define ARCONTENT_MASK                   0x00007FFE   // Bits that denote valid content types
#define ARCONTENT_PHASE_UNKNOWN          0x00000000   // We can be in any phase.  This is XP behavior.
#define ARCONTENT_PHASE_PRESNIFF         0x10000000   // These are contents we know w/o scanning the media for complete data (e.g. Audio track, DVD Movie).
#define ARCONTENT_PHASE_SNIFFING         0x20000000   // We are in the middle of searching the media.  There could be more contents to be found than currently reported.
#define ARCONTENT_PHASE_FINAL            0x40000000   // We have finished searching; contents we report are final.
#define ARCONTENT_PHASE_MASK             0x70000000   // Bits that denote what phase we are in the Autoplay process.
#endif  // NTDDI_VISTA

IQueryCancelAutoPlay STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AllowAutoPlay PTR
ENDS

IDynamicHWHandler STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDynamicInfo PTR
ENDS

SPBEGINF_NORMAL	= 0
SPBEGINF_AUTOTIME = 0x2
SPBEGINF_NOPROGRESSBAR = 0x10
SPBEGINF_MARQUEEPROGRESS = 0x20
SPBEGINF_NOCANCELBUTTON	= 0x40

SPACTION_NONE = 0
SPACTION_MOVING	= 1
SPACTION_COPYING = 2
SPACTION_RECYCLING	= 3
SPACTION_APPLYINGATTRIBS = 4
SPACTION_DOWNLOADING = 5
SPACTION_SEARCHING_INTERNET	= 6
SPACTION_CALCULATING = 7
SPACTION_UPLOADING = 8
SPACTION_SEARCHING_FILES = 9
SPACTION_DELETING = 10
SPACTION_RENAMING = 11
SPACTION_FORMATTING	= 12
SPACTION_COPY_MOVING = 13

SPTEXT_ACTIONDESCRIPTION = 1
SPTEXT_ACTIONDETAIL	= 2

IActionProgress STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Begin PTR
	UpdateProgress PTR
	UpdateText PTR
	QueryCancel PTR
	ResetCancel PTR
	End PTR
ENDS

SHCOLUMNINIT STRUCT
	dwFlags DD
	dwReserved DD
	wszFolder DW MAX_PATH DUP
ENDS

SHCOLUMNINFO STRUCT
	scid SHCOLUMNID
	vt DD
	fmt DD
	cChars DD
	csFlags DD
	wszTitle DW MAX_COLUMN_NAME_LEN DUP
	wszDescription DW MAX_COLUMN_DESC_LEN DUP
ENDS

#define SHCDF_UPDATEITEM  0x00000001

SHCOLUMNDATA STRUCT
	dwFlags DD
	dwFileAttributes DD
	dwReserved DD
	pwszExt PTR
	wszFile DW MAX_PATH DUP
ENDS

IColumnProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
	GetColumnInfo PTR
	GetItemData PTR
ENDS

SHDRAGIMAGE STRUCT
	sizeDragImage SIZE
	ptOffset POINT
	hbmpDragImage HANDLE
	crColorKey DD
ENDS

#define DI_GETDRAGIMAGE  "ShellGetDragImage"

IDropTargetHelper STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	DragEnter PTR
	DragLeave PTR
	DragOver PTR
	Drop PTR
	Show PTR
ENDS

IDragSourceHelper STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitializeFromBitmap PTR
	InitializeFromWindow PTR
ENDS

DSH_ALLOWDROPDESCRIPTIONTEXT	= 0x1

IDragSourceHelper2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitializeFromBitmap PTR
	InitializeFromWindow PTR
	SetFlags PTR
ENDS

NRESARRAY STRUCT
	cItems DD
	nr NETRESOURCE
ENDS

CIDA STRUCT
	cidl DD
	aoffset DD
ENDS

FD_CLSID = 0x0001
FD_SIZEPOINT = 0x0002
FD_ATTRIBUTES = 0x0004
FD_CREATETIME = 0x0008
FD_ACCESSTIME = 0x0010
FD_WRITESTIME = 0x0020
FD_FILESIZE = 0x0040
FD_PROGRESSUI = 0x00004000
FD_LINKUI  = 0x00008000
FD_UNICODE = 0x80000000

FILEDESCRIPTORA STRUCT
	dwFlags DD
	clsid GUID
	sizel SIZEL
	pointl POINTL
	dwFileAttributes DD
	ftCreationTime FILETIME
	ftLastAccessTime FILETIME
	ftLastWriteTime FILETIME
	nFileSizeHigh DD
	nFileSizeLow DD
	cFileName DB MAX_PATH DUP
ENDS

FILEDESCRIPTORW STRUCT
	dwFlags DD
	clsid GUID
	sizel SIZEL
	pointl POINTL
	dwFileAttributes DD
	ftCreationTime FILETIME
	ftLastAccessTime FILETIME
	ftLastWriteTime FILETIME
	nFileSizeHigh DD
	nFileSizeLow DD
	cFileName DW MAX_PATH DUP
ENDS

FILEGROUPDESCRIPTORA STRUCT
	cItems DD
	fgd FILEDESCRIPTORA
ENDS

FILEGROUPDESCRIPTORW STRUCT
	cItems DD
	fgd FILEDESCRIPTORW
ENDS

DROPFILES STRUCT
	pFiles DD
	pt POINT
	fNC DD
	fWide DD
ENDS

#IF WINVER >= NTDDI_VISTA

FILE_ATTRIBUTES_ARRAY STRUCT
	cItems DD
	dwSumFileAttributes DD
	dwProductFileAttributes DD
	rgdwFileAttributes DD
ENDS

DROPIMAGE_INVALID             = -1
DROPIMAGE_NONE                = 0
DROPIMAGE_COPY                = DROPEFFECT_COPY
DROPIMAGE_MOVE                = DROPEFFECT_MOVE
DROPIMAGE_LINK                = DROPEFFECT_LINK
DROPIMAGE_LABEL               = 6
DROPIMAGE_WARNING             = 7

DROPDESCRIPTION STRUCT
	type DD
	szMessage DW MAX_PATH DUP
	szInsert DW MAX_PATH DUP
ENDS

#ENDIF

#define SHCNRF_InterruptLevel      0x0001
#define SHCNRF_ShellLevel          0x0002
#define SHCNRF_RecursiveInterrupt  0x1000
#define SHCNRF_NewDelivery         0x8000

#define SHCNE_RENAMEITEM          0x00000001
#define SHCNE_CREATE              0x00000002
#define SHCNE_DELETE              0x00000004
#define SHCNE_MKDIR               0x00000008
#define SHCNE_RMDIR               0x00000010
#define SHCNE_MEDIAINSERTED       0x00000020
#define SHCNE_MEDIAREMOVED        0x00000040
#define SHCNE_DRIVEREMOVED        0x00000080
#define SHCNE_DRIVEADD            0x00000100
#define SHCNE_NETSHARE            0x00000200
#define SHCNE_NETUNSHARE          0x00000400
#define SHCNE_ATTRIBUTES          0x00000800
#define SHCNE_UPDATEDIR           0x00001000
#define SHCNE_UPDATEITEM          0x00002000
#define SHCNE_SERVERDISCONNECT    0x00004000
#define SHCNE_UPDATEIMAGE         0x00008000
#define SHCNE_DRIVEADDGUI         0x00010000
#define SHCNE_RENAMEFOLDER        0x00020000
#define SHCNE_FREESPACE           0x00040000

#define PRF_VERIFYEXISTS            0x0001
#define PRF_TRYPROGRAMEXTENSIONS    (0x0002 | PRF_VERIFYEXISTS)
#define PRF_FIRSTDIRDEF             0x0004
#define PRF_DONTFINDLNK             0x0008      // if PRF_TRYPROGRAMEXTENSIONS is specified
#define PRF_REQUIREABSOLUTE         0x0010

#define PCS_FATAL           0x80000000
#define PCS_REPLACEDCHAR    0x00000001
#define PCS_REMOVEDCHAR     0x00000002
#define PCS_TRUNCATED       0x00000004
#define PCS_PATHTOOLONG     0x00000008  // Always combined with FATAL

#define MM_ADDSEPARATOR         0x00000001
#define MM_SUBMENUSHAVEIDS      0x00000002
#define MM_DONTREMOVESEPS       0x00000004

#define SHOP_PRINTERNAME 0x00000001
#define SHOP_FILEPATH    0x00000002
#define SHOP_VOLUMEGUID  0x00000004

#define SHFMT_ID_DEFAULT    0xFFFF
#define SHFMT_OPT_FULL     0x0001
#define SHFMT_OPT_SYSONLY  0x0002
#define SHFMT_ERROR     0xFFFFFFFF
#define SHFMT_CANCEL    0xFFFFFFFE
#define SHFMT_NOFORMAT  0xFFFFFFFD

REST_NONE                       = 0x00000000
REST_NORUN                      = 0x00000001
REST_NOCLOSE                    = 0x00000002
REST_NOSAVESET                  = 0x00000004
REST_NOFILEMENU                 = 0x00000008
REST_NOSETFOLDERS               = 0x00000010
REST_NOSETTASKBAR               = 0x00000020
REST_NODESKTOP                  = 0x00000040
REST_NOFIND                     = 0x00000080
REST_NODRIVES                   = 0x00000100
REST_NODRIVEAUTORUN             = 0x00000200
REST_NODRIVETYPEAUTORUN         = 0x00000400
REST_NONETHOOD                  = 0x00000800
REST_STARTBANNER                = 0x00001000
REST_RESTRICTRUN                = 0x00002000
REST_NOPRINTERTABS              = 0x00004000
REST_NOPRINTERDELETE            = 0x00008000
REST_NOPRINTERADD               = 0x00010000
REST_NOSTARTMENUSUBFOLDERS      = 0x00020000
REST_MYDOCSONNET                = 0x00040000
REST_NOEXITTODOS                = 0x00080000
REST_ENFORCESHELLEXTSECURITY    = 0x00100000
REST_LINKRESOLVEIGNORELINKINFO  = 0x00200000
REST_NOCOMMONGROUPS             = 0x00400000
REST_SEPARATEDESKTOPPROCESS     = 0x00800000
REST_NOWEB                      = 0x01000000
REST_NOTRAYCONTEXTMENU          = 0x02000000
REST_NOVIEWCONTEXTMENU          = 0x04000000
REST_NONETCONNECTDISCONNECT     = 0x08000000
REST_STARTMENULOGOFF            = 0x10000000
REST_NOSETTINGSASSIST           = 0x20000000
REST_NOINTERNETICON             = 0x40000001
REST_NORECENTDOCSHISTORY        = 0x40000002
REST_NORECENTDOCSMENU           = 0x40000003
REST_NOACTIVEDESKTOP            = 0x40000004
REST_NOACTIVEDESKTOPCHANGES     = 0x40000005
REST_NOFAVORITESMENU            = 0x40000006
REST_CLEARRECENTDOCSONEXIT      = 0x40000007
REST_CLASSICSHELL               = 0x40000008
REST_NOCUSTOMIZEWEBVIEW         = 0x40000009
REST_NOHTMLWALLPAPER            = 0x40000010
REST_NOCHANGINGWALLPAPER        = 0x40000011
REST_NODESKCOMP                 = 0x40000012
REST_NOADDDESKCOMP              = 0x40000013
REST_NODELDESKCOMP              = 0x40000014
REST_NOCLOSEDESKCOMP            = 0x40000015
REST_NOCLOSE_DRAGDROPBAND       = 0x40000016   // Disable Close and Drag & Drop on ALL Bands
REST_NOMOVINGBAND               = 0x40000017   // Disable Moving ALL Bands
REST_NOEDITDESKCOMP             = 0x40000018
REST_NORESOLVESEARCH            = 0x40000019
REST_NORESOLVETRACK             = 0x4000001A
REST_FORCECOPYACLWITHFILE       = 0x4000001B
REST_NOLOGO3CHANNELNOTIFY       = 0x4000001C
REST_NOFORGETSOFTWAREUPDATE     = 0x4000001D
REST_NOSETACTIVEDESKTOP         = 0x4000001E   // No Active desktop on Settings Menu
REST_NOUPDATEWINDOWS            = 0x4000001F   // No Windows Update on Settings Menu
REST_NOCHANGESTARMENU           = 0x40000020   // No Context menu or Drag and Drop on Start menu
REST_NOFOLDEROPTIONS            = 0x40000021   // No Folder Options on Settings Menu
REST_HASFINDCOMPUTERS           = 0x40000022   // Show Start/Search/Computers
REST_INTELLIMENUS               = 0x40000023
REST_RUNDLGMEMCHECKBOX          = 0x40000024
REST_ARP_ShowPostSetup          = 0x40000025   // ARP: Show Post-Setup page
REST_NOCSC                      = 0x40000026   // Disable the ClientSide caching on SM
REST_NOCONTROLPANEL             = 0x40000027   // Remove the Control Panel only from SM|Settings
REST_ENUMWORKGROUP              = 0x40000028   // Enumerate workgroup in root of nethood
REST_ARP_NOARP                  = 0x40000029   // ARP: Don't Allow ARP to come up at all
REST_ARP_NOREMOVEPAGE           = 0x4000002A   // ARP: Don't allow Remove page
REST_ARP_NOADDPAGE              = 0x4000002B   // ARP: Don't allow Add page
REST_ARP_NOWINSETUPPAGE         = 0x4000002C   // ARP: Don't allow opt components page
REST_GREYMSIADS                 = 0x4000002D    // SM: Allow the greying of Darwin Ads in SM
REST_NOCHANGEMAPPEDDRIVELABEL   = 0x4000002E   // Don't enable the UI which allows users to rename mapped drive labels
REST_NOCHANGEMAPPEDDRIVECOMMENT = 0x4000002F   // Don't enable the UI which allows users to change mapped drive comments
REST_MaxRecentDocs              = 0x40000030
REST_NONETWORKCONNECTIONS       = 0x40000031   // No Start Menu | Settings |Network Connections
REST_FORCESTARTMENULOGOFF       = 0x40000032   // Force logoff on the Start Menu
REST_NOWEBVIEW                  = 0x40000033   // Disable Web View
REST_NOCUSTOMIZETHISFOLDER      = 0x40000034   // Disable Customize This Folder
REST_NOENCRYPTION               = 0x40000035   // Don't allow file encryption
//  Do NOT use me                     0x40000036
REST_DONTSHOWSUPERHIDDEN        = 0x40000037   // don't show super hidden files
REST_NOSHELLSEARCHBUTTON        = 0x40000038
REST_NOHARDWARETAB              = 0x40000039   // No Hardware tab on Drives or in control panel
REST_NORUNASINSTALLPROMPT       = 0x4000003A   // Don't bring up "Run As" prompt for install programs
REST_PROMPTRUNASINSTALLNETPATH  = 0x4000003B   // Force the  "Run As" prompt for install programs on unc/network shares
REST_NOMANAGEMYCOMPUTERVERB     = 0x4000003C   // No Manage verb on My Computer
//  Do NOT use me                     0x4000003D
REST_DISALLOWRUN                = 0x4000003E   // don't allow certain apps to be run
REST_NOWELCOMESCREEN            = 0x4000003F   // don't allow the welcome screen to be displayed.
REST_RESTRICTCPL                = 0x40000040   // only allow certain cpls to be run
REST_DISALLOWCPL                = 0x40000041   // don't allow certain cpls to be run
REST_NOSMBALLOONTIP             = 0x40000042   // No Start Menu Balloon Tip
REST_NOSMHELP                   = 0x40000043   // No Help on the Start Menu
REST_NOWINKEYS                  = 0x40000044   // No Windows-X Hot keys
REST_NOENCRYPTONMOVE            = 0x40000045   // Don't automatically try to encrypt files that are moved to encryped directories
REST_NOLOCALMACHINERUN          = 0x40000046   // ignore HKLM\sw\ms\win\cv\Run and all of it's sub keys
REST_NOCURRENTUSERRUN           = 0x40000047   // ignore HKCU\sw\ms\win\cv\Run and all of it's sub keys
REST_NOLOCALMACHINERUNONCE      = 0x40000048   // ignore HKLM\sw\ms\win\cv\RunOnce and all of it's sub keys
REST_NOCURRENTUSERRUNONCE       = 0x40000049   // ignore HKCU\sw\ms\win\cv\RunOnce and all of it's sub keys
REST_FORCEACTIVEDESKTOPON       = 0x4000004A   // Force ActiveDesktop to be turned ON all the time.
//  Do NOT use me                     0x4000004B
REST_NOVIEWONDRIVE              = 0x4000004C   // disallows CreateViewObject() on specified drives (CFSFolder only)
REST_NONETCRAWL                 = 0x4000004D   // disables the crawling of the WNet namespace.
REST_NOSHAREDDOCUMENTS          = 0x4000004E   // don't auto share the Shared Documents/create link
REST_NOSMMYDOCS                 = 0x4000004F   // Don't show the My Documents item on the Start Menu.
REST_NOSMMYPICS                 = 0x40000050   // Don't show the My Pictures item on the Start Menu
REST_ALLOWBITBUCKDRIVES         = 0x40000051   // Bit mask indicating which which drives have bit bucket support
REST_NONLEGACYSHELLMODE         = 0x40000052   // new consumer shell modes
REST_NOCONTROLPANELBARRICADE    = 0x40000053   // The webview barricade in Control Panel
REST_NOSTARTPAGE                = 0x40000054   // Whistler Start Page on desktop.
REST_NOAUTOTRAYNOTIFY           = 0x40000055   // Whistler auto-tray notify feature
REST_NOTASKGROUPING             = 0x40000056   // Whistler taskbar button grouping feature
REST_NOCDBURNING                = 0x40000057   // whistler cd burning feature
REST_MYCOMPNOPROP               = 0x40000058   // disables Properties on My Computer's context menu
REST_MYDOCSNOPROP               = 0x40000059   // disables Properties on My Documents' context menu
REST_NOSTARTPANEL               = 0x4000005A   // Windows start panel (New start menu) for Whistler.
REST_NODISPLAYAPPEARANCEPAGE    = 0x4000005B   // disable Themes and Appearance tabs in the Display Control Panel.
REST_NOTHEMESTAB                = 0x4000005C   // disable the Themes tab in the Display Control Panel.
REST_NOVISUALSTYLECHOICE        = 0x4000005D   // disable the visual style drop down in the Appearance tab of the Display Control Panel.
REST_NOSIZECHOICE               = 0x4000005E   // disable the size drop down in the Appearance tab of the Display Control Panel.
REST_NOCOLORCHOICE              = 0x4000005F   // disable the color drop down in the Appearance tab of the Display Control Panel.
REST_SETVISUALSTYLE             = 0x40000060   // Load the specified file as the visual style.
REST_STARTRUNNOHOMEPATH         = 0x40000061   // dont use the %HOMEPATH% env var for the Start-Run dialog
REST_NOUSERNAMEINSTARTPANEL     = 0x40000062   // don't show the username is the startpanel.
REST_NOMYCOMPUTERICON           = 0x40000063   // don't show my computer anywhere hide its contents
REST_NOSMNETWORKPLACES          = 0x40000064   // don't show network places in startpanel.
REST_NOSMPINNEDLIST             = 0x40000065   // don't show the pinned list in startpanel.
REST_NOSMMYMUSIC                = 0x40000066   // don't show MyMusic folder in startpanel
REST_NOSMEJECTPC                = 0x40000067   // don't show "Undoc PC" command in startmenu
REST_NOSMMOREPROGRAMS           = 0x40000068   // don't show "More Programs" button in StartPanel.
REST_NOSMMFUPROGRAMS            = 0x40000069   // don't show the MFU programs list in StartPanel.
REST_NOTRAYITEMSDISPLAY         = 0x4000006A   // disables the display of the system tray
REST_NOTOOLBARSONTASKBAR        = 0x4000006B   // disables toolbar display on the taskbar
REST_NOSMCONFIGUREPROGRAMS      = 0x4000006F   // No Configure Programs on Settings Menu
REST_HIDECLOCK                  = 0x40000070   // don't show the clock
REST_NOLOWDISKSPACECHECKS       = 0x40000071   // disable the low disk space checking
REST_NOENTIRENETWORK            = 0x40000072   // removes the "Entire Network" link (i.e. from "My Network Places")
REST_NODESKTOPCLEANUP           = 0x40000073   // disable the desktop cleanup wizard
REST_BITBUCKNUKEONDELETE        = 0x40000074   // disables recycling of files
REST_BITBUCKCONFIRMDELETE       = 0x40000075   // always show the delete confirmation dialog when deleting files
REST_BITBUCKNOPROP              = 0x40000076   // disables Properties on Recycle Bin's context menu
REST_NODISPBACKGROUND           = 0x40000077   // disables the Desktop tab in the Display CPL
REST_NODISPSCREENSAVEPG         = 0x40000078   // disables the Screen Saver tab in the Display CPL
REST_NODISPSETTINGSPG           = 0x40000079   // disables the Settings tab in the Display CPL
REST_NODISPSCREENSAVEPREVIEW    = 0x4000007A   // disables the screen saver on the Screen Saver tab in the Display CPL
REST_NODISPLAYCPL               = 0x4000007B   // disables the Display CPL
REST_HIDERUNASVERB              = 0x4000007C   // hides the "Run As..." context menu item
REST_NOTHUMBNAILCACHE           = 0x4000007D   // disables use of the thumbnail cache
REST_NOSTRCMPLOGICAL            = 0x4000007E   // dont use StrCmpLogical() instead use default CompareString()
REST_NOPUBLISHWIZARD            = 0x4000007F   // disables publishing wizard (WPW)
REST_NOONLINEPRINTSWIZARD       = 0x40000080   // disables online prints wizard (OPW)
REST_NOWEBSERVICES              = 0x40000081   // disables the web specified services for both OPW and WPW
REST_ALLOWUNHASHEDWEBVIEW       = 0x40000082   // allow the user to be promted to accept web view templates that don't already have an md5 hash in the registry
REST_ALLOWLEGACYWEBVIEW         = 0x40000083   // allow legacy webview template to be shown.
REST_REVERTWEBVIEWSECURITY      = 0x40000084   // disable added webview security measures (revert to w2k functionality).
REST_INHERITCONSOLEHANDLES      = 0x40000086   // ShellExec() will check for the current process and target process being console processes to inherit handles
REST_SORTMAXITEMCOUNT           = 0x40000087   // Do not sort views with more items than this key. Useful for viewing big amount of files in one folder.
REST_NOREMOTERECURSIVEEVENTS    = 0x40000089   // Dont register network change events recursively to avoid network traffic
REST_NOREMOTECHANGENOTIFY       = 0x40000091   // Do not notify for remote changy notifies
REST_NOSIMPLENETIDLIST          = 0x40000092   // No simple network IDLists
REST_NOENUMENTIRENETWORK        = 0x40000093   // Don't enumerate entire network if we happen to get to it (in conjunction with REST_NOENTIRENETWORK)
REST_NODETAILSTHUMBNAILONNETWORK= 0x40000094   // Disable Thumbnail for Network files in DUI Details pane
REST_NOINTERNETOPENWITH         = 0x40000095   // dont allow looking on the internet for file associations
REST_DONTRETRYBADNETNAME        = 0x4000009B   // In Network Places: if provider returns ERROR_BAD_NET_NAME give up
REST_ALLOWFILECLSIDJUNCTIONS    = 0x4000009C   // re-enable legacy support for file.{guid} junctions in FileSystem Folder
REST_NOUPNPINSTALL              = 0x4000009D   // disable "install UPnP" task in My Net Places
REST_ARP_DONTGROUPPATCHES       = 0x400000AC   //List individual patches in Add/Remove Programs
REST_ARP_NOCHOOSEPROGRAMSPAGE   = 0x400000AD   //Choose programs page
REST_NODISCONNECT               = 0x41000001   // No Disconnect option in Start menu
REST_NOSECURITY                 = 0x41000002   // No Security option in start menu
REST_NOFILEASSOCIATE            = 0x41000003   // Do not allow user to change file association
REST_ALLOWCOMMENTTOGGLE         = 0x41000004   // Allow the user to toggle the positions of the Comment and the Computer Name
REST_USEDESKTOPINICACHE         = 0x41000005   // Cache desktop.ini entries from network folders

#define PPCF_ADDQUOTES               0x00000001        // return a quoted name if required
#define PPCF_ADDARGUMENTS            0x00000003        // appends arguments (and wraps in quotes if required)
#define PPCF_NODIRECTORIES           0x00000010        // don't match to directories
#define PPCF_FORCEQUALIFY            0x00000040        // qualify even non-relative names
#define PPCF_LONGESTPOSSIBLE         0x00000080        // always find the longest possible name

OAIF_ALLOW_REGISTRATION = 0x00000001     // enable the "always use this file" checkbox (NOTE if you don't pass this, it will be disabled)
OAIF_REGISTER_EXT       = 0x00000002     // do the registration after the user hits "ok"
OAIF_EXEC               = 0x00000004     // execute file after registering
OAIF_FORCE_REGISTRATION = 0x00000008     // force the "always use this file" checkbox to be checked (normally, you won't use the OAIF_ALLOW_REGISTRATION when you pass this)
OAIF_HIDE_REGISTRATION  = 0x00000020     // hide the "always use this file" checkbox
OAIF_URL_PROTOCOL       = 0x00000040     // the "extension" passed is actually a protocol, and open with should show apps registered as capable of handling that protocol

OPENASINFO STRUCT
	pcszFile PTR
	pcszClass PTR
	oaifInFlags DD
ENDS

#define NUM_POINTS      3

AUTO_SCROLL_DATA STRUCT
	iNextSample DD
	dwLastScroll DD
	bFull DD
	pts POINT NUM_POINTS DUP
	dwTimes DD NUM_POINTS DUP
ENDS

CABINETSTATE STRUCT
	cLength DW
	nVersion DW
	fFullPathTitle DD
	fSaveLocalView DD
	fNotShell DD
	fSimpleDefault DD
	fDontShowDescBar DD
	fNewWindowMode DD
	fShowCompColor DD
	fDontPrettyNames DD
	fAdminsCreateCommonGroups DD
	fUnusedFlags DD
	fMenuEnumFilter DD
ENDS 

IShellChangeNotify STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnChange PTR
ENDS

IQueryInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetInfoTip PTR
	GetInfoFlags PTR
ENDS

SHChangeUpdateImageIDList STRUCT
	cb DW
	iIconIndex DD
	iCurIndex DD
	uFlags DD
	dwProcessID DD
	szName DW MAX_PATH DUP
	cbZero DW
ENDS

SHChangeProductKeyAsIDList STRUCT
	cb DW
	wszProductKey DW 39 DUP
	cbZero DW
ENDS

SHDESCRIPTIONID STRUCT
	dwDescriptionId DD
	clsid GUID
ENDS

SHELLFLAGSTATE STRUCT
	fShowAllObjects DD
	fShowExtensions DD
	fNoConfirmRecycle DD
	fShowSysFiles DD
	fShowCompColor DD
	fDoubleClickInWebView DD
	fDesktopHTML DD
	fWin95Classic DD
	fDontPrettyPath DD
	fShowAttribCol DD
	fMapNetDrvBtn DD
	fShowInfoTip DD
	fHideIcons DD
	fRestFlags DD
ENDS

SCNRT_ENABLE  = 0
SCNRT_DISABLE = 1

#if WINVER < NTDDI_VISTA
IDefViewFrame STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindowLV PTR
	ReleaseWindowLV PTR
	GetShellFolder PTR
ENDS
#endif

IDocViewSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnSetTitle PTR
ENDS

#define OPENPROPS_NONE          0x0000
#define OPENPROPS_INHIBITPIF    0x8000
#define GETPROPS_NONE           0x0000
#define SETPROPS_NONE           0x0000
#define CLOSEPROPS_NONE         0x0000
#define CLOSEPROPS_DISCARD      0x0001

#define PIFNAMESIZE     30
#define PIFSTARTLOCSIZE 63
#define PIFDEFPATHSIZE  64
#define PIFPARAMSSIZE   64
#define PIFSHPROGSIZE   64
#define PIFSHDATASIZE   64
#define PIFDEFFILESIZE  80
#define PIFMAXFILEPATH  260

PROPPRG STRUCT
	flPrg DW
	flPrgInit DW
	achTitle DB PIFNAMESIZE DUP
	achCmdLine DB PIFSTARTLOCSIZE+PIFPARAMSSIZE+1 DUP
	achWorkDir DB PIFDEFPATHSIZE DUP
	wHotKey DW
	achIconFile DB PIFDEFFILESIZE DUP
	wIconIndex DW
	dwEnhModeFlags DD
	dwRealModeFlags DD
	achOtherFile DB PIFDEFFILESIZE DUP
	achPIFFile DB PIFMAXFILEPATH DUP
ENDS

IInitializeObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
ENDS

BMICON_LARGE = 0
BMICON_SMALL = 1

IBanneredBar STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetIconSize PTR
	GetIconSize PTR
	SetBitmap PTR
	GetBitmap PTR
ENDS

IShellFolderViewCB STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	MessageSFVCB PTR
ENDS

IShellBrowser STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetWindow PTR
	ContextSensitiveHelp PTR
	InsertMenusSB PTR
	SetMenuSB PTR
	RemoveMenusSB PTR
	SetStatusTextSB PTR
	EnableModelessSB PTR
	TranslateAcceleratorSB PTR
	BrowseObject PTR
	GetViewStateStream PTR
	GetControlWindow PTR
	SendControlMsg PTR
	QueryActiveShellView PTR
	OnViewWindowActive PTR
	SetToolbarItems PTR
ENDS

IProfferService STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ProfferService PTR
	RevokeService PTR
ENDS

#define SID_SProfferService IID_IProfferService
#define STR_DONT_RESOLVE_LINK L"Don't Resolve Link"
#define STR_GET_ASYNC_HANDLER L"GetAsyncHandler"

IShellItem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	BindToHandler PTR
	GetParent PTR
	GetDisplayName PTR
	GetAttributes PTR
	Compare PTR
ENDS

IShellItem2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	BindToHandler PTR
	GetParent PTR
	GetDisplayName PTR
	GetAttributes PTR
	Compare PTR
	GetPropertyStore PTR
	GetPropertyStoreWithCreateObject PTR
	GetPropertyStoreForKeys PTR
	GetPropertyDescriptionList PTR
	Update PTR
	GetProperty PTR
	GetCLSID PTR
	GetFileTime PTR
	GetInt32 PTR
	GetString PTR
	GetUInt32 PTR
	GetUInt64 PTR
	GetBool PTR
ENDS

SIIGBF_RESIZETOFIT	= 0
SIIGBF_BIGGERSIZEOK	= 0x1
SIIGBF_MEMORYONLY	= 0x2
SIIGBF_ICONONLY	= 0x4
SIIGBF_THUMBNAILONLY	= 0x8
SIIGBF_INCACHEONLY	= 0x10

IShellItemImageFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetImage PTR
ENDS

IUserAccountChangeCallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnPictureChange PTR
ENDS

IEnumShellItems STRUCT
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
ENDS

STGOP_MOVE	= 1
STGOP_COPY	= 2
STGOP_SYNC	= 3
STGOP_REMOVE	= 5
STGOP_RENAME	= 6
STGOP_APPLYPROPERTIES	= 8
STGOP_NEW	= 10

TSF_NORMAL	= 0
TSF_FAIL_EXIST	= 0
TSF_RENAME_EXIST	= 0x1
TSF_OVERWRITE_EXIST	= 0x2
TSF_ALLOW_DECRYPTION	= 0x4
TSF_NO_SECURITY	= 0x8
TSF_COPY_CREATION_TIME	= 0x10
TSF_COPY_WRITE_TIME	= 0x20
TSF_USE_FULL_ACCESS	= 0x40
TSF_DELETE_RECYCLE_IF_POSSIBLE	= 0x80
TSF_COPY_HARD_LINK	= 0x100
TSF_COPY_LOCALIZED_NAME	= 0x200
TSF_MOVE_AS_COPY_DELETE	= 0x400
TSF_SUSPEND_SHELLEVENTS	= 0x800

TS_NONE	= 0
TS_PERFORMING	= 0x1
TS_PREPARING	= 0x2
TS_INDETERMINATE	= 0x4

ITransferAdviseSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UpdateProgress PTR
	UpdateTransferState PTR
	ConfirmOverwrite PTR
	ConfirmEncryptionLoss PTR
	FileFailure PTR
	SubStreamFailure PTR
	PropertyFailure PTR
ENDS

ITransferSource STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Advise PTR
	Unadvise PTR
	SetProperties PTR
	OpenItem PTR
	MoveItem PTR
	RecycleItem PTR
	RemoveItem PTR
	RenameItem PTR
	LinkItem PTR
	ApplyPropertiesToItem PTR
	GetDefaultDestinationName PTR
	EnterFolder PTR
	LeaveFolder PTR
ENDS

SHELL_ITEM_RESOURCE STRUCT
	guidType GUID
	szName WCHAR 260 DUP
ENDS

IEnumResources STRUCT
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
ENDS

IShellItemResources STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetAttributes PTR
	GetSize PTR
	GetTimes PTR
	SetTimes PTR
	GetResourceDescription PTR
	EnumResources PTR
	SupportsResource PTR
	OpenResource PTR
	CreateResource PTR
	MarkForDelete PTR
ENDS

#IFNDEF OVERLAPPED
	OVERLAPPED STRUCT
		Internal PTR
		InternalHigh PTR
		UNION
			STRUCT
					Offset DD
					OffsetHigh DD
			ENDS
			Pointer PTR
		ENDUNION
		hEvent HANDLE
	ENDS
#ENDIF

IStreamAsync STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Read PTR
	Write PTR
	Seek PTR
	SetSize PTR
	CopyTo PTR
	ommit PTR
	Revert PTR
	LockRegion PTR
	UnlockRegion PTR
	Stat PTR
	Clone PTR
	ReadAsync PTR
	WriteAsync PTR
	OverlappedResult PTR
	CancelIo PTR
ENDS

IStreamUnbufferedInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSectorSize PTR
ENDS

IFileOperationProgressSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	StartOperations PTR
	FinishOperations PTR
	PreRenameItem PTR
	PostRenameItem PTR
	PreMoveItem PTR
	PostMoveItem PTR
	PreCopyItem PTR
	PostCopyItem PTR
	PreDeleteItem PTR
	PostDeleteItem PTR
	PreNewItem PTR
	PostNewItem PTR
	UpdateProgress PTR
	ResetTimer PTR
	PauseTimer PTR
	ResumeTimer PTR
ENDS

ITransferDestination STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Advise PTR
	Unadvise PTR
	CreateItem PTR
ENDS

SIATTRIBFLAGS_AND	= 0x1
SIATTRIBFLAGS_OR	= 0x2
SIATTRIBFLAGS_APPCOMPAT	= 0x3
SIATTRIBFLAGS_MASK	= 0x3
SIATTRIBFLAGS_ALLITEMS	= 0x4000

IShellItemArray STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	BindToHandler PTR
	GetPropertyStore PTR
	GetPropertyDescriptionList PTR
	GetAttributes PTR
	GetCount PTR
	GetItemAt PTR
	EnumItems PTR
ENDS

IInitializeWithItem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
ENDS

IObjectWithSelection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetSelection PTR
	GetSelection PTR
ENDS

IObjectWithBackReferences STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RemoveBackReferences PTR
ENDS

PUIFNF_DEFAULT	= 0
PUIFNF_MNEMONIC	= 0x1

PUIF_DEFAULT	= 0
PUIF_RIGHTALIGN	= 0x1
PUIF_NOLABELININFOTIP	= 0x2

PUIFFDF_DEFAULT	= 0
PUIFFDF_RIGHTTOLEFT	= 0x1
PUIFFDF_SHORTFORMAT	= 0x2
PUIFFDF_NOTIME	= 0x4
PUIFFDF_FRIENDLYDATE	= 0x8

IPropertyUI STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ParsePropertyName PTR
	GetCannonicalName PTR
	GetDisplayName PTR
	GetPropertyDescription PTR
	GetDefaultWidth PTR
	GetFlags PTR
	FormatForDisplay PTR
	GetHelpInfo PTR
ENDS

ICategoryProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CanCategorizeOnSCID PTR
	GetDefaultCategory PTR
	GetCategoryForSCID PTR
	EnumCategories PTR
	GetCategoryName PTR
	CreateCategory PTR
ENDS

CATINFO_NORMAL	= 0
CATINFO_COLLAPSED	= 0x1
CATINFO_HIDDEN	= 0x2
CATINFO_EXPANDED	= 0x4
CATINFO_NOHEADER	= 0x8
CATINFO_NOTCOLLAPSIBLE	= 0x10
CATINFO_NOHEADERCOUNT	= 0x20
CATINFO_SUBSETTED	= 0x40

CATSORT_DEFAULT	= 0
CATSORT_NAME	= 0x1

CATEGORY_INFO STRUCT
	cif DD
	wszName WCHAR 260 DUP
ENDS

ICategorizer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDescription PTR
	GetCategory PTR
	GetCategoryInfo PTR
	CompareCategory PTR
ENDS

DOGIF_DEFAULT	= 0
DOGIF_TRAVERSE_LINK	= 0x1
DOGIF_NO_HDROP	= 0x2
DOGIF_NO_URL	= 0x4
DOGIF_ONLY_IF_ONE	= 0x8

#define STR_GPS_HANDLERPROPERTIESONLY      L"GPS_HANDLERPROPERTIESONLY"
#define STR_GPS_FASTPROPERTIESONLY         L"GPS_FASTPROPERTIESONLY"
#define STR_GPS_OPENSLOWITEM               L"GPS_OPENSLOWITEM"
#define STR_GPS_DELAYCREATION              L"GPS_DELAYCREATION"
#define STR_GPS_BESTEFFORT                 L"GPS_BESTEFFORT"
#define STR_GPS_NO_OPLOCK                  L"GPS_NO_OPLOCK"

#define QCMINFO_PLACE_BEFORE    0
#define QCMINFO_PLACE_AFTER     1

QCMINFO_IDMAP_PLACEMENT STRUCT
	id DD
	fFlags DD
ENDS

QCMINFO_IDMAP STRUCT
	nMaxIds DD
	pIdList QCMINFO_IDMAP_PLACEMENT
ENDS

QCMINFO STRUCT
	hmenu HANDLE
	indexMenu DD
	idCmdFirst DD
	idCmdLast DD
	pIdMap PTR
ENDS

#define TBIF_APPEND     0
#define TBIF_PREPEND    1
#define TBIF_REPLACE    2
#define TBIF_DEFAULT      0x00000000
#define TBIF_INTERNETBAR  0x00010000
#define TBIF_STANDARDTOOLBAR   0x00020000
#define TBIF_NOTOOLBAR  0x00030000

TBINFO STRUCT
	cbuttons DD
	uFlags DD
ENDS

DETAILSINFO STRUCT
	pidl PTR
	fmt DD
	cxChar DD
	str STRRET
	iImage DD
ENDS

SFVM_PROPPAGE_DATA STRUCT
	dwReserved DD
	pfn PTR
	lParam LPARAM
ENDS

SFVM_HELPTOPIC_DATA STRUCT
	wszHelpFile DW MAX_PATH DUP
	wszHelpTopic DW MAX_PATH DUP
ENDS

#define SFVM_MERGEMENU             1    // -                  LPQCMINFO
#define SFVM_INVOKECOMMAND         2    // idCmd              -
#define SFVM_GETHELPTEXT           3    // idCmd,cchMax       pszText
#define SFVM_GETTOOLTIPTEXT        4    // idCmd,cchMax       pszText
#define SFVM_GETBUTTONINFO         5    // -                  LPTBINFO
#define SFVM_GETBUTTONS            6    // idCmdFirst,cbtnMax LPTBBUTTON
#define SFVM_INITMENUPOPUP         7    // idCmdFirst,nIndex  hmenu
#define SFVM_FSNOTIFY             14    // LPCITEMIDLIST*     lEvent
#define SFVM_WINDOWCREATED        15    // hwnd               -
#define SFVM_GETDETAILSOF         23    // iColumn            DETAILSINFO*
#define SFVM_COLUMNCLICK          24    // iColumn            -
#define SFVM_QUERYFSNOTIFY        25    // -                  SHChangeNotifyEntry *
#define SFVM_DEFITEMCOUNT         26    // -                  UINT*
#define SFVM_DEFVIEWMODE          27    // -                  FOLDERVIEWMODE*
#define SFVM_UNMERGEMENU          28    // -                  hmenu
#define SFVM_UPDATESTATUSBAR      31    // fInitialize        -
#define SFVM_BACKGROUNDENUM       32    // -                  -
#define SFVM_DIDDRAGDROP          36    // dwEffect           IDataObject *
#define SFVM_SETISFV              39    // -                  IShellFolderView*
#define SFVM_THISIDLIST           41    // -                  LPITMIDLIST*
#define SFVM_ADDPROPERTYPAGES     47    // -                  SFVM_PROPPAGE_DATA *
#define SFVM_BACKGROUNDENUMDONE   48    // -                  -
#define SFVM_GETNOTIFY            49    // LPITEMIDLIST*      LONG*
// Note: SFVM_QUERYSTANDARDVIEWS NOT USED: must use SFVM_GETVIEWDATA instead
#define SFVM_GETSORTDEFAULTS      53    // iDirection         iParamSort
#define SFVM_SIZE                 57    // -                  -
#define SFVM_GETZONE              58    // -                  DWORD*
#define SFVM_GETPANE              59    // Pane ID            DWORD*
#define SFVM_GETHELPTOPIC         63    // -                  SFVM_HELPTOPIC_DATA *
#define SFVM_GETANIMATION         68    // HINSTANCE *        WCHAR *

ITEMSPACING STRUCT
	cxSmall DD
	cySmall DD
	cxLarge DD
	cyLarge DD
ENDS

// defines for IShellFolderView::SetObjectCount
#define SFVSOC_INVALIDATE_ALL 0x00000001  // Assumed to reset only what is neccessary...
#define SFVSOC_NOSCROLL LVSICF_NOSCROLL

// defines for IShellFolderView::SelectItems()
#define SFVS_SELECT_NONE        0x0 // unselect all
#define SFVS_SELECT_ALLITEMS    0x1 // select all
#define SFVS_SELECT_INVERT      0x2 // Inver the selection

IShellFolderView STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Rearrange PTR
	GetArrangeParam PTR
	ArrangeGrid PTR
	AutoArrange PTR
	GetAutoArrange PTR
	AddObject PTR
	GetObject PTR
	RemoveObject PTR
	GetObjectCount PTR
	SetObjectCount PTR
	UpdateObject PTR
	RefreshObject PTR
	SetRedraw PTR
	GetSelectedCount PTR
    // NOTE: GetSelectedObjects hands out const pointers to internal ITEMID_CHILD structures. The caller is expected to act on them immediately (and not cache them).  LocalFree the array, but not the items it contains.
	GetSelectedObjects PTR
	IsDropOnSource PTR
	GetDragPoint PTR
	GetDropPoint PTR
	MoveIcons PTR
	SetItemPos PTR
	IsBkDropTarget PTR
	SetClipboard PTR
	SetPoints PTR
	GetItemSpacing PTR
	SetCallback PTR
	Select PTR
	QuerySupport PTR
	SetAutomationObject PTR
ENDS

SFV_CREATE STRUCT
	cbSize DD
	pshf PTR
	psvOuter PTR
	psfvcb PTR
ENDS

DEFCONTEXTMENU STRUCT
	hwnd HANDLE
	pcmcb PTR
	pidlFolder PTR
	psf PTR
	cidl DD
	apidl PTR
	punkAssociationInfo PTR
	cKeys DD
	aKeys PTR
ENDS

DFMICS STRUCT
	cbSize DD
	fMask DD
	lParam LPARAM
	idCmdFirst DD
	idDefMax DD
	pici PTR
#if WINVER >= NTDDI_VISTA
	punkSite PTR
#endif
ENDS

#define DFM_MERGECONTEXTMENU         1      // uFlags       LPQCMINFO
#define DFM_INVOKECOMMAND            2      // idCmd        pszArgs
#define DFM_GETHELPTEXT              5      // idCmd,cchMax pszText -Ansi
#define DFM_WM_MEASUREITEM           6      // ---from the message---
#define DFM_WM_DRAWITEM              7      // ---from the message---
#define DFM_WM_INITMENUPOPUP         8      // ---from the message---
#define DFM_VALIDATECMD              9      // idCmd        0
#define DFM_MERGECONTEXTMENU_TOP     10     // uFlags       LPQCMINFO
#define DFM_GETHELPTEXTW             11     // idCmd,cchMax pszText -Unicode
#define DFM_INVOKECOMMANDEX          12     // idCmd        PDFMICS
#define DFM_MAPCOMMANDNAME           13     // idCmd *      pszCommandName
#define DFM_GETDEFSTATICID           14     // idCmd *      0
#define DFM_GETVERBW                 15     // idCmd,cchMax pszText -Unicode
#define DFM_GETVERBA                 16     // idCmd,cchMax pszText -Ansi
#define DFM_MERGECONTEXTMENU_BOTTOM  17     // uFlags       LPQCMINFO

// Commands from DFM_INVOKECOMMAND when strings are passed in
#define DFM_CMD_DELETE          -1
#define DFM_CMD_MOVE            -2
#define DFM_CMD_COPY            -3
#define DFM_CMD_LINK            -4
#define DFM_CMD_PROPERTIES      -5
#define DFM_CMD_NEWFOLDER       -6
#define DFM_CMD_PASTE           -7
#define DFM_CMD_VIEWLIST        -8
#define DFM_CMD_VIEWDETAILS     -9
#define DFM_CMD_PASTELINK       -10
#define DFM_CMD_PASTESPECIAL    -11
#define DFM_CMD_MODALPROP       -12
#define DFM_CMD_RENAME          -13

CSFV STRUCT
	cbSize DD
	pshf PTR
	psvOuter PTR
	pidl PTR
	lEvents DD
	pfnCallback PTR
	fvm DD
ENDS

SFV_SETITEMPOS STRUCT
	pidl PTR
	pt POINT
ENDS

#define SFVM_REARRANGE          0x00000001
#define SFVM_ADDOBJECT         0x00000003
#define SFVM_REMOVEOBJECT         0x00000006
#define SFVM_UPDATEOBJECT         0x00000007
#define SFVM_GETSELECTEDOBJECTS 0x00000009
#define SFVM_SETITEMPOS         0x0000000e
#define SFVM_SETCLIPBOARD       0x00000010
#define SFVM_SETPOINTS           0x00000017

SHELLSTATEA STRUCT
	fShowAllObjects DD
	fShowExtensions DD
	fNoConfirmRecycle DD
	fShowSysFiles DD
	fShowCompColor DD
	fDoubleClickInWebView DD
	fDesktopHTML DD
	fWin95Classic DD
	fDontPrettyPath DD
	fShowAttribCol DD // No longer used, dead bit
	fMapNetDrvBtn DD
	fShowInfoTip DD
	fHideIcons DD
	fWebView DD
	fFilter DD
	fShowSuperHidden DD
	fNoNetCrawling DD
	dwWin95Unused DD // Win95 only - no longer supported pszHiddenFileExts
	uWin95Unused DD // Win95 only - no longer supported cbHiddenFileExts
    // Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
	lParamSort DD
	iSortDirection DD
	version DD
    // new for win2k. need notUsed var to calc the right size of ie4 struct
    // FIELD_OFFSET does not work on bit fields
	uNotUsed; // feel free to rename and use
	fSepProcess DD
    // new for Whistler.
	fStartPanelOn DD       //Indicates if the Whistler StartPanel mode is ON or OFF.
	fShowStartPage DD      //Indicates if the Whistler StartPage on desktop is ON or OFF.
    // new for Longhorn
	fAutoCheckSelect DD
	fIconsOnly DD
	fShowTypeOverlay DD
	fSpareFlags DD
ENDS

SHELLSTATEW STRUCT
	fShowAllObjects DD
	fShowExtensions DD
	fNoConfirmRecycle DD
	fShowSysFiles DD
	fShowCompColor DD
	fDoubleClickInWebView DD
	fDesktopHTML DD
	fWin95Classic DD
	fDontPrettyPath DD
	fShowAttribCol DD
	fMapNetDrvBtn DD
	fShowInfoTip DD
	fHideIcons DD
	fWebView DD
	fFilter DD
	fShowSuperHidden DD
	fNoNetCrawling DD
	dwWin95Unused DD // Win95 only - no longer supported pszHiddenFileExts
	uWin95Unused DD // Win95 only - no longer supported cbHiddenFileExts
    // Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
	lParamSort DD
	iSortDirection DD
	version DD
    // new for win2k. need notUsed var to calc the right size of ie4 struct
    // FIELD_OFFSET does not work on bit fields
	uNotUsed DD // feel free to rename and use
	fSepProcess DD
    // new for Whistler.
	fStartPanelOn DD       //Indicates if the Whistler StartPage mode is ON or OFF.
	fShowStartPage DD      //Indicates if the Whistler StartPage on desktop is ON or OFF.
    // new for Longhorn
	fAutoCheckSelect DD
	fIconsOnly DD
	fShowTypeOverlay DD
    // If you need a new flag, steal a bit from from fSpareFlags.
	fSpareFlags DD
ENDS

#define SHELLSTATEVERSION_IE4   9
#define SHELLSTATEVERSION_WIN2K 10

SHELLFLAGSTATE STRUCT
	fShowAllObjects DD
	fShowExtensions DD
	fNoConfirmRecycle DD
	fShowSysFiles DD
	fShowCompColor DD
	fDoubleClickInWebView DD
	fDesktopHTML DD
	fWin95Classic DD
	fDontPrettyPath DD
	fShowAttribCol DD
	fMapNetDrvBtn DD
	fShowInfoTip DD
	fHideIcons DD
#if WINVER >= NTDDI_VISTA
	fAutoCheckSelect DD
	fIconsOnly DD
	fRestFlags DD
#else
	fRestFlags DD
#endif
ENDS

#define SSF_SHOWALLOBJECTS          0x00000001
#define SSF_SHOWEXTENSIONS          0x00000002
#define SSF_HIDDENFILEEXTS          0x00000004
#define SSF_SERVERADMINUI           0x00000004
#define SSF_SHOWCOMPCOLOR           0x00000008
#define SSF_SORTCOLUMNS             0x00000010
#define SSF_SHOWSYSFILES            0x00000020
#define SSF_DOUBLECLICKINWEBVIEW    0x00000080
#define SSF_SHOWATTRIBCOL           0x00000100
#define SSF_DESKTOPHTML             0x00000200
#define SSF_WIN95CLASSIC            0x00000400
#define SSF_DONTPRETTYPATH          0x00000800
#define SSF_SHOWINFOTIP             0x00002000
#define SSF_MAPNETDRVBUTTON         0x00001000
#define SSF_NOCONFIRMRECYCLE        0x00008000
#define SSF_HIDEICONS               0x00004000
#define SSF_FILTER                  0x00010000
#define SSF_WEBVIEW                 0x00020000
#define SSF_SHOWSUPERHIDDEN         0x00040000
#define SSF_SEPPROCESS              0x00080000
#if WINVER >= NTDDI_WINXP
	#define SSF_NONETCRAWLING           0x00100000
	#define SSF_STARTPANELON            0x00200000
	#define SSF_SHOWSTARTPAGE           0x00400000
#endif  // NTDDI_WINXP
#if WINVER >= NTDDI_VISTA
	#define SSF_AUTOCHECKSELECT         0x00800000
	#define SSF_ICONSONLY               0x01000000
	#define SSF_SHOWTYPEOVERLAY         0x02000000
#endif  // NTDDI_VISTA

INamedPropertyBag STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ReadPropertyNPB PTR
	WritePropertyNPB PTR
	RemovePropertyNPB PTR
ENDS

AASHELLMENUFILENAME STRUCT
	cbTotal DW
	rgbReserved DB 12 DUP
	szFileName DW
ENDS

AASHELLMENUITEM STRUCT
	lpReserved1 PTR
	iReserved DD
	uiReserved DD
	lpName PTR
	psz PTR
ENDS

IESHORTCUT_NEWBROWSER    = 0x01
IESHORTCUT_OPENNEWTAB    = 0x02
IESHORTCUT_FORCENAVIGATE = 0x04
IESHORTCUT_BACKGROUNDTAB = 0x08

#IFDEF UNICODE
	#define SHELLSTATE SHELLSTATEW
	#define GCS_VERB GCS_VERBW
	#define GCS_HELPTEXT GCS_HELPTEXTW
	#define GCS_VALIDATE GCS_VALIDATEW
	#define CMDSTR_NEWFOLDER CMDSTR_NEWFOLDERW
	#define CMDSTR_VIEWLIST CMDSTR_VIEWLISTW
	#define CMDSTR_VIEWDETAILS CMDSTR_VIEWDETAILSW
	#define IExtractIcon IExtractIconW
	#define IExtractIconVtbl IExtractIconWVtbl
	#define SHGetIconOverlayIndex  SHGetIconOverlayIndexW
	#define IShellLink  IShellLinkW
	#define IShellLinkVtbl  IShellLinkWVtbl
	#define IShellExecuteHook IShellExecuteHookW
	#define IShellExecuteHookVtbl IShellExecuteHookWVtbl
	#define INewShortcutHook INewShortcutHookW
	#define INewShortcutHookVtbl INewShortcutHookWVtbl
	#define ICopyHook ICopyHookW
	#define ICopyHookVtbl ICopyHookWVtbl
	#define IFileViewer IFileViewerW
	#define SHGetPathFromIDList SHGetPathFromIDListW
	#define SHCreateDirectoryEx SHCreateDirectoryExW
	#define SHGetSpecialFolderPath  SHGetSpecialFolderPathW
	#define SHGetFolderPath  SHGetFolderPathW
	#define BROWSEINFO  BROWSEINFOW
	#define SHBrowseForFolder SHBrowseForFolderW
	#define BFFM_SETSTATUSTEXT BFFM_SETSTATUSTEXTW
	#define BFFM_SETSELECTION BFFM_SETSELECTIONW
	#define BFFM_VALIDATEFAILED BFFM_VALIDATEFAILEDW
	#define FILEDESCRIPTOR  FILEDESCRIPTORW
	#define FILEGROUPDESCRIPTOR  FILEGROUPDESCRIPTORW
	#define SHCNF_PATH  SHCNF_PATHW
	#define SHCNF_PRINTER  SHCNF_PRINTERW
	#define SHARD_PATH  SHARD_PATHW
	#define SHUpdateImage  SHUpdateImageW
	#define SHGetDataFromIDList  SHGetDataFromIDListW
	#define SHPathPrepareForWrite  SHPathPrepareForWriteW
	#define SHGetFolderPathAndSubDir  SHGetFolderPathAndSubDirW
	#define SHSetFolderPath  SHSetFolderPathW
	#define SHCreateFileExtractIcon  SHCreateFileExtractIconW
#else
	#define SHELLSTATE SHELLSTATEA
	#define GCS_VERB GCS_VERBA
	#define GCS_HELPTEXT GCS_HELPTEXTA
	#define GCS_VALIDATE GCS_VALIDATEA
	#define CMDSTR_NEWFOLDER CMDSTR_NEWFOLDERA
	#define CMDSTR_VIEWLIST CMDSTR_VIEWLISTA
	#define CMDSTR_VIEWDETAILS CMDSTR_VIEWDETAILSA
	#define IExtractIcon IExtractIconA
	#define IExtractIconVtbl IExtractIconAVtbl
	#define SHGetIconOverlayIndex  SHGetIconOverlayIndexA
	#define IShellLink  IShellLinkA
	#define IShellLinkVtbl  IShellLinkAVtbl
	#define IShellExecuteHook IShellExecuteHookA
	#define IShellExecuteHookVtbl IShellExecuteHookAVtbl
	#define INewShortcutHook INewShortcutHookA
	#define INewShortcutHookVtbl INewShortcutHookAVtbl
	#define ICopyHook ICopyHookA
	#define ICopyHookVtbl ICopyHookAVtbl
	#define IFileViewer IFileViewerA
	#define SHGetPathFromIDList SHGetPathFromIDListA
	#define SHCreateDirectoryEx SHCreateDirectoryExA
	#define SHGetSpecialFolderPath  SHGetSpecialFolderPathA
	#define SHGetFolderPath  SHGetFolderPathA
	#define BROWSEINFO  BROWSEINFOA
	#define SHBrowseForFolder SHBrowseForFolderA
	#define BFFM_SETSTATUSTEXT BFFM_SETSTATUSTEXTA
	#define BFFM_SETSELECTION BFFM_SETSELECTIONA
	#define BFFM_VALIDATEFAILED BFFM_VALIDATEFAILEDA
	#define FILEDESCRIPTOR  FILEDESCRIPTORA
	#define FILEGROUPDESCRIPTOR  FILEGROUPDESCRIPTORA
	#define SHCNF_PATH  SHCNF_PATHA
	#define SHCNF_PRINTER  SHCNF_PRINTERA
	#define SHARD_PATH  SHARD_PATHA
	#define SHUpdateImage  SHUpdateImageA
	#define SHGetDataFromIDList  SHGetDataFromIDListA
	#define SHPathPrepareForWrite  SHPathPrepareForWriteA
	#define SHGetFolderPathAndSubDir  SHGetFolderPathAndSubDirA
	#define SHSetFolderPath  SHSetFolderPathA
	#define SHCreateFileExtractIcon  SHCreateFileExtractIconA
#endif

#endif

