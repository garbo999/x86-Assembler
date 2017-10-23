
#ifndef SHOBJIDL_H
#define SHOBJIDL_H

#IFNDEF RPC_H
	#include rpc.h ; Windows RPC definitions
#ENDIF

#IFNDEF RPCNDR_H
	#include rpcndr.h
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include windows.h
	#ENDIF
	#IFNDEF OLE2_H
		#include ole2.h
	#ENDIF
#endif

/* header files for imported files */
#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF

#IFNDEF OLEIDL_H
	#include "oleidl.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF SHTYPES_H
	#include "shtypes.h"
#ENDIF

#IFNDEF SERVPROV_H
	#include "servprov.h"
#ENDIF

#IFNDEF COMCAT_H
	#include "comcat.h"
#ENDIF

#IFNDEF PROPIDL_H
	#include "propidl.h"
#ENDIF

#IFNDEF PRSHT_H
	#include "prsht.h"
#ENDIF

#IFNDEF PROPSYS_H
	#include "propsys.h"
#ENDIF

#IFNDEF MSXML_H
	#include "msxml.h"
#ENDIF

#IFNDEF OBJECTARRAY_H
	#include "ObjectArray.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF SHLGUID_H
	#include "shlguid.h"
#ENDIF

#IFNDEF IPersistFolder

;#define GUID_IID_IPersistFolder <0x000214EA,0,0,<0xC0,0,0,0,0,0,0,0x46>>

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

#ENDIF // IPersistFolder

#IFNDEF IPersistFolder2

;#define GUID_IID_IPersistFolder2 <0x1ac3d9f0,0x175c,0x11d1,<0x95,0xbe,0x0,0x60,0x97,0x97,0xea,0x4f>>

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

#ENDIF // IPersistFolder2

#IFNDEF IPersistIDList

;#DEFINE GUID_IID_IPersistIDList <0x1079acfc,0x29bd,0x11d3,<0x8e,0x0d,0x00,0xc0,0x4f,0x68,0x37,0xd5>>

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

;#ENDIF // IPersistIDList

#IFNDEF IEnumIDList

;#DEFINE GUID_IID_IEnumIDList <0x000214F2,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>

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

#ENDIF // IEnumIDList

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
#ENDIF

#IFNDEF STR_SKIP_BINDING_CLSID
	#define STR_SKIP_BINDING_CLSID      L"Skip Binding CLSID"
#ENDIF

#define STR_PARSE_PREFER_FOLDER_BROWSING     L"Parse Prefer Folder Browsing"
#define STR_DONT_PARSE_RELATIVE              L"Don't Parse Relative"
#define STR_PARSE_TRANSLATE_ALIASES          L"Parse Translate Aliases"
#define STR_PARSE_SHELL_PROTOCOL_TO_FILE_OBJECTS     L"Parse Shell Protocol To File Objects"

#IFNDEF IShellFolder

;#DEFINE GUID_IID_IShellFolder <0x000214E6,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>

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

#ENDIF // IShellFolder

#IFNDEF EXTRASEARCH
EXTRASEARCH STRUCT
	guidSearch GUID
	wszFriendlyName DW 80 DUP (?)
	wszUrl DW 2084 DUP (?)
ENDS
#ENDIF

#IFNDEF IEnumExtraSearch
;#DEFINE GUID_IID_IEnumExtraSearch <0x0E700BE1,0x9DB6,0x11d1,<0xA1,0xCE,0x00,0xC0,0x4F,0xD7,0x5D,0x13>>

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
#ENDIF // IEnumExtraSearch

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

#IFNDEF SHCOLUMNID
SHCOLUMNID STRUCT
	fmtid GUID
	pid PTR
ENDS
#ENDIF

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

#IFNDEF FOLDERSETTINGS
FOLDERSETTINGS STRUCT
	ViewMode DD
	fFlags DD
ENDS
#ENDIF

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

#IFNDEF SVUIA_INPLACEACTIVATE
SVUIA_DEACTIVATE	= 0
SVUIA_ACTIVATE_NOFOCUS	= 1
SVUIA_ACTIVATE_FOCUS	= 2
SVUIA_INPLACEACTIVATE	= 3
#ENDIF

#ifdef FIX_ENABLEMODELESS_CONFLICT
	#define EnableModeless EnableModelessSV
#endif

;#define GUID_IID_IShellView <0x000214E3,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>

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

#ENDIF // IShellView

;#DEFINE GUID_IID_IExtractImage2 <0x53BB1EE,0x93B4,0x11d1,<0x98,0xA3,0x00,0xC0,0x4F,0xB6,0x87,0xDA>>

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

;#DEFINE GUID_IID_IUserEventTimerCallback <0xe9ead8e6,0x2a25,0x410e,<0x9b,0x58,0xa9,0xfb,0xef,0x1d,0xd1,0xa2>>

IUserEventTimerCallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UserEventTimerProc PTR
ENDS

;#DEFINE GUID_IID_IUserEventTimer <0x0F504B94,0x6E42,0x42E6,<0x99,0xE0,0xE2,0x0F,0xAF,0xE5,0x2A,0xB4>>

IUserEventTimer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetUserEventTimer PTR
	KillUserEventTimer PTR
	GetUserEventTimerElapsed PTR
	InitTimerTickInterval PTR
ENDS

;#DEFINE GUID_IID_IDockingWindow <0x12dd920,0x7b26,0x11d0,<0x8c,0xa9,0x00,0xa0,0xc9,0x2d,0xbf,0xe8>>

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

#define DBIM_MINSIZE    0x0001
#define DBIM_MAXSIZE    0x0002
#define DBIM_INTEGRAL   0x0004
#define DBIM_ACTUAL     0x0008
#define DBIM_TITLE      0x0010
#define DBIM_MODEFLAGS  0x0020
#define DBIM_BKCOLOR    0x0040

#IFNDEF DESKBANDINFO
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
#ENDIF // DESKBANDINFO

#define DBIMF_NORMAL            0x0000
#define DBIMF_FIXED             0x0001
#define DBIMF_FIXEDBMP          0x0004   // a fixed background bitmap (if supported)
#define DBIMF_VARIABLEHEIGHT    0x0008
#define DBIMF_UNDELETEABLE      0x0010
#define DBIMF_DEBOSSED          0x0020
#define DBIMF_BKCOLOR           0x0040
#define DBIMF_USECHEVRON        0x0080
#define DBIMF_BREAK             0x0100
#define DBIMF_ADDTOFRONT        0x0200
#define DBIMF_TOPALIGN          0x0400
#define DBIF_VIEWMODE_NORMAL         0x0000
#define DBIF_VIEWMODE_VERTICAL       0x0001
#define DBIF_VIEWMODE_FLOATING       0x0002
#define DBIF_VIEWMODE_TRANSPARENT    0x0004

DBID_BANDINFOCHANGED	= 0
DBID_SHOWONLY	= 1
DBID_MAXIMIZEBAND	= 2
DBID_PUSHCHEVRON	= 3
DBID_DELAYINIT	= 4
DBID_FINISHINIT	= 5
DBID_SETWINDOWTHEME	= 6
DBID_PERMITAUTOHIDE	= 7

#define DBPC_SELECTFIRST -1
#define DBPC_SELECTLAST -2

;#DEFINE GUID_IID_IDeskBand <0xEB0FE172,0x1A3A,0x11D0,<0x89,0xB3,0x00,0xA0,0xC9,0x0A,0x90,0xAC>>
;#define GUID_CGID_DeskBand GUID_IID_IDeskBand

#IFNDEF IDeskBand
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
#ENDIF // IDeskBand

;#define GUID_IID_ITaskbarList <0x56fdf342,0xfd6d,0x11d0,<0x95,0x8a,0x0,0x60,0x97,0xc9,0xa0,0x90>>
    
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
#ENDIF // ITaskbarList

;#define GUID_IID_ITaskbarList2 <0x602D4995,0xB13A,0x429b,<0xA6,0x6E,0x19,0x35,0xE4,0x4F,0x43,0x17>>

#IFNDEF ITaskbarList2
ITaskbarList2 STRUCT
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
	MarkFullscreenWindow PTR
ENDS
#ENDIF // ITaskbarList2

;#define GUID_IID_ICDBurn <0x3d73a659,0xe5d0,0x4d42,<0xaf,0xc0,0x51,0x21,0xba,0x42,0x5c,0x8d>>

#IFNDEF ICDBurn
ICDBurn STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetRecorderDriveLetter PTR
	Burn PTR
	HasRecordableDrive PTR
ENDS
#ENDIF // ICDBurn

#define IDD_WIZEXTN_FIRST    0x5000
#define IDD_WIZEXTN_LAST     0x5100

;#define GUID_IID_IWizardSite <0x88960f5b,0x422f,0x4e7b,<0x80,0x13,0x73,0x41,0x53,0x81,0xc3,0xc3>>

#IFNDEF IWizardSite
IWizardSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPreviousPage PTR
	GetNextPage PTR
	GetCancelledPage PTR
ENDS
#ENDIF // IWizardSite

;#define GUID_IID_IWizardExtension <0xc02ea696,0x86cc,0x491e,<0x9b,0x23,0x74,0x39,0x4a,0x04,0x44,0xa8>>

#IFNDEF IWizardExtension
IWizardExtension STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddPages PTR
	GetFirstPage PTR
	GetLastPage PTR
ENDS
#ENDIF // IWizardExtension

;#define GUID_IID_IWebWizardExtension <0x0e6b3f66,0x98d1,0x48c0,<0xa2,0x22,0xfb,0xde,0x74,0xe2,0xfb,0xc5>>

#IFNDEF IWebWizardExtension
IWebWizardExtension STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddPages PTR
	GetFirstPage PTR
	GetLastPage PTR
	SetInitialURL PTR
	SetErrorURL PTR
ENDS
#ENDIF // IWebWizardExtension

#define SID_WebWizardHost IID_IWebWizardExtension
#define SHPWHF_NORECOMPRESS             0x00000001  // don't allow/prompt for recompress of streams
#define SHPWHF_NONETPLACECREATE         0x00000002  // don't create a network place when transfer is complete
#define SHPWHF_NOFILESELECTOR           0x00000004  // don't show the file selector
#define SHPWHF_VALIDATEVIAWEBFOLDERS    0x00010000  // enable web folders to validate network places (ANP support)

;#define GUID_IID_IPublishingWizard <0xaa9198bb,0xccec,0x472d,<0xbe,0xed,0x19,0xa4,0xf6,0x73,0x3f,0x7a>>

#IFNDEF IPublishingWizard
IPublishingWizard STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddPages PTR
	GetFirstPage PTR
	GetLastPage PTR
	Initialize PTR
	GetTransferManifest PTR
ENDS
#ENDIF // IPublishingWizard

;#define GUID_IID_IFolderViewHost <0x1ea58f02,0xd55a,0x411d,<0xb0,0x9e,0x9e,0x65,0xac,0x21,0x60,0x5b>>

#IFNDEF IFolderViewHost
IFolderViewHost STRUCT
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
#ENDIF // IFolderViewHost

#define ACDD_VISIBLE        0x0001

;#define GUID_IID_IAutoCompleteDropDown <0x3CD141F4,0x3C6A,0x11d2,<0xBC,0xAA,0x00,0xC0,0x4F,0xD9,0x29,0xDB>>

#IFNDEF IAutoCompleteDropDown
IAutoCompleteDropDown STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDropDownStatus PTR
	ResetEnumerator PTR
ENDS
#ENDIF // IAutoCompleteDropDown

#define PPW_LAUNCHEDBYUSER       0x00000001      // The wizard was launch explicitly by the user, not on demand by the key manager

;#define GUID_IID_IModalWindow <0xb4db1657,0x70d7,0x485e,<0x8e,0x3e,0x6f,0xcb,0x5a,0x5c,0x18,0x02>>

#IFNDEF IModalWindow
IModalWindow STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Show PTR
ENDS
#ENDIF // IModalWindow

;#define GUID_IID_IPassportWizard <0xa09db586,0x9180,0x41ac,<0x91,0x14,0x46,0x0a,0x7f,0x36,0x2b,0x76>>

#IFNDEF IPassportWizard
IPassportWizard STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Show PTR
	SetOptions PTR
ENDS
#ENDIF // IPassportWizard

#define PROPSTR_EXTENSIONCOMPLETIONSTATE L"ExtensionCompletionState"

CDBE_RET_DEFAULT	= 0
CDBE_RET_DONTRUNOTHEREXTS	= 0x1
CDBE_RET_STOPWIZARD	= 0x2

CDBE_TYPE_MUSIC	= 0x1
CDBE_TYPE_DATA	= 0x2
CDBE_TYPE_ALL	= 0xffffffff

;#define GUID_IID_ICDBurnExt <0x2271dcca,0x74fc,0x4414,<0x8f,0xb7,0xc5,0x6b,0x05,0xac,0xe2,0xd7>>
#define GUID_SID_CDWizardHost GUID_IID_ICDBurnExt

#IFNDEF ICDBurnExt
ICDBurnExt STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSupportedActionTypes PTR 
ENDS
#ENDIF // ICDBurnExt

;#define GUID_IID_IDVGetEnum <0x70F55181,0x5FEA,0x4900,<0xB6,0xB8,0x73,0x43,0xCB,0x0A,0x34,0x8C>>

#IFNDEF IDVGetEnum
IDVGetEnum STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetEnumReadyCallback PTR
	CreateEnumIDListFromContents PTR
ENDS
#ENDIF // IDVGetEnum

;#define GUID_IID_IInsertItem <0xD2B57227,0x3D23,0x4b95,<0x93,0xC0,0x49,0x2B,0xD4,0x54,0xC3,0x56>>

#IFNDEF IInsertItem
IInsertItem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InsertItem PTR
ENDS
#ENDIF // IInsertItem

;#define GUID_IID_IDeskBar <0xEB0FE173,0x1A3A,0x11D0,<0x89,0xB3,0x00,0xA0,0xC9,0x0A,0x90,0xAC>>

#IFNDEF IDeskBar
IDeskBar STRUCT
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
	SetClient PTR
	GetClient PTR
	OnPosRectChangeDB PTR
ENDS
#ENDIF // IDeskBar

MBHANDCID_PIDLSELECT	= 0

;#define GUID_IID_IMenuBand <0x568804CD,0xCBD7,0x11d0,<0x98,0x16,0x00,0xC0,0x4F,0xD9,0x19,0x72>>

#IFNDEF IMenuBand
IMenuBand STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsMenuMessage PTR
	TranslateMenuMessage PTR
ENDS
#ENDIF // IMenuBand

;#define GUID_IID_IFolderBandPriv <0x47c01f95,0xe185,0x412c,<0xb5,0xc5,0x4f,0x27,0xdf,0x96,0x5a,0xea>>

#IFDEF IFolderBandPriv
IFolderBandPriv STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetCascade PTR
	SetAccelerators PTR
	SetNoIcons PTR
	SetNoText PTR
ENDS
#ENDIF // IFolderBandPriv

BANDSITEINFO STRUCT
	dwMask DD
	dwState DD
	dwStyle DD
ENDS

BSID_BANDADDED	= 0
BSID_BANDREMOVED	= BSID_BANDADDED + 1

#define BSIM_STATE          0x00000001
#define BSIM_STYLE          0x00000002
#define BSSF_VISIBLE        0x00000001
#define BSSF_NOTITLE        0x00000002
#define BSSF_UNDELETEABLE   0x00001000
#define BSIS_AUTOGRIPPER    0x00000000
#define BSIS_NOGRIPPER      0x00000001
#define BSIS_ALWAYSGRIPPER  0x00000002
#define BSIS_LEFTALIGN      0x00000004
#define BSIS_SINGLECLICK    0x00000008
#define BSIS_NOCONTEXTMENU  0x00000010
#define BSIS_NODROPTARGET   0x00000020
#define BSIS_NOCAPTION      0x00000040
#define BSIS_PREFERNOLINEBREAK   0x00000080
#define BSIS_LOCKED         0x00000100

;#define GUID_IID_IBandSite <0x4CF504B0,0xDE96,0x11D0,<0x8B,0x3F,0x00,0xA0,0xC9,0x11,0xE8,0xE5>>
#define SID_SBandSite IID_IBandSite
#define CGID_BandSite IID_IBandSite

#IFNDEF IBandSite
IBandSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddBand PTR
	EnumBands PTR
	QueryBand PTR
	SetBandState PTR
	RemoveBand PTR
	GetBandObject PTR
	SetBandSiteInfo PTR
	GetBandSiteInfo PTR
ENDS
#ENDIF // IBandSite

;#define GUID_IID_INamespaceWalkCB <0xd92995f8,0xcf5e,0x4a76,<0xbf,0x59,0xea,0xd3,0x9e,0xa2,0xb9,0x7e>>

#IFNDEF INamespaceWalkCB
INamespaceWalkCB STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	FoundItem PTR
	EnterFolder PTR
	LeaveFolder PTR
	InitializeProgressDialog PTR
ENDS
#ENDIF // INamespaceWalkCB

NSWF_NONE_IMPLIES_ALL	= 0x1
NSWF_ONE_IMPLIES_ALL	= 0x2
NSWF_DONT_TRAVERSE_LINKS	= 0x4
NSWF_DONT_ACCUMULATE_RESULT	= 0x8
NSWF_TRAVERSE_STREAM_JUNCTIONS	= 0x10
NSWF_FILESYSTEM_ONLY	= 0x20
NSWF_SHOW_PROGRESS	= 0x40
NSWF_FLAG_VIEWORDER	= 0x80
NSWF_IGNORE_AUTOPLAY_HIDA	= 0x100

;#define GUID_IID_INamespaceWalk <0x57ced8a7,0x3f4a,0x432c,<0x93,0x50,0x30,0xf2,0x44,0x83,0xf7,0x4f>>

#IFNDEF INamespaceWalk
INamespaceWalk STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Walk PTR
	GetIDArrayResult PTR
ENDS
#ENDIF // INamespaceWalk

;#define GUID_IID_IRegTreeItem <0xA9521922,0x0812,0x4d44,<0x9E,0xC3,0x7F,0xD3,0x8C,0x72,0x6F,0x3D>>

#IFNDEF IRegTreeItem
IRegTreeItem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCheckState PTR
	SetCheckState PTR
ENDS
#ENDIF // IRegTreeItem

MPOS_EXECUTE	= 0
MPOS_FULLCANCEL	= MPOS_EXECUTE + 1
MPOS_CANCELLEVEL	= MPOS_FULLCANCEL + 1
MPOS_SELECTLEFT	= MPOS_CANCELLEVEL + 1
MPOS_SELECTRIGHT	= MPOS_SELECTLEFT + 1
MPOS_CHILDTRACKING	= MPOS_SELECTRIGHT + 1

MPPF_SETFOCUS	= 0x1
MPPF_INITIALSELECT	= 0x2
MPPF_NOANIMATE	= 0x4
MPPF_KEYBOARD	= 0x10
MPPF_REPOSITION	= 0x20
MPPF_FORCEZORDER	= 0x40
MPPF_FINALSELECT	= 0x80
MPPF_TOP	= 0x20000000
MPPF_LEFT	= 0x40000000
MPPF_RIGHT	= 0x60000000
MPPF_BOTTOM	= 0x80000000
MPPF_POS_MASK	= 0xe0000000

;#define GUID_IID_IMenuPopup <0xD1E7AFEB,0x6A2E,0x11d0,<0x8C,0x78,0x00,0xC0,0x4F,0xD9,0x18,0xB4>>

#IFNDEF IMenuPopup
IMenuPopup STRUCT
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
	SetClient PTR
	GetClient PTR
	OnPosRectChangeDB PTR
	Popup PTR
	OnSelect PTR
	SetSubMenu PTR
ENDS
#ENDIF // IMenuPopup

SIGDN_NORMALDISPLAY	= 0
SIGDN_PARENTRELATIVEPARSING	= 0x80018001
SIGDN_PARENTRELATIVEFORADDRESSBAR	= 0x8001c001
SIGDN_DESKTOPABSOLUTEPARSING	= 0x80028000
SIGDN_PARENTRELATIVEEDITING	= 0x80031001
SIGDN_DESKTOPABSOLUTEEDITING	= 0x8004c000
SIGDN_FILESYSPATH	= 0x80058000
SIGDN_URL	= 0x80068000

SICHINT_DISPLAY	= 0
SICHINT_ALLFIELDS	= 0x80000000
SICHINT_CANONICAL	= 0x10000000

;#define GUID_IID_IShellItem <0x43826d1e,0xe718,0x42ee,<0xbc,0x55,0xa1,0xe2,0x61,0xc3,0x7b,0xfe>>

#IFNDEF IShellItem
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
#ENDIF // IShellItem

;#define GUID_IID_IImageRecompress <0x505f1513,0x6b3e,0x4892,<0xa2,0x72,0x59,0xf8,0x88,0x9a,0x4d,0x3e>>

#IFNDEF IImageRecompress
IImageRecompress STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RecompressImage PTR
ENDS
#ENDIF // IImageRecompress

;#define GUID_IID_IDefViewSafety <0x9A93B3FB,0x4E75,0x4c74,<0x87,0x1A,0x2C,0xDA,0x66,0x7F,0x39,0xA5>>

#IFNDEF IDefViewSafety
IDefViewSafety STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsSafePage PTR
ENDS
#ENDIF // IDefViewSafety

;#define GUID_IID_IContextMenuSite <0x0811AEBE,0x0B87,0x4C54,<0x9E,0x72,0x54,0x8C,0xF6,0x49,0x01,0x6B>>

#IFNDEF IContextMenuSite
IContextMenuSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	DoContextMenuPopup PTR
ENDS
#ENDIF // IContextMenuSite

DELEGATEITEMID STRUCT
	cbSize DW
	wOuter DW
	cbInner DW
	rgb DB
ENDS

;#define GUID_IID_IDelegateFolder <0xADD8BA80,0x002B,0x11D0,<0x8F,0x0F,0x00,0xC0,0x4F,0xD7,0xD0,0x62>>

#IFNDEF IDelegateFolder
IDelegateFolder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetItemAlloc PTR
ENDS
#ENDIF // IDelegateFolder

BFO_NONE	= 0
BFO_BROWSER_PERSIST_SETTINGS	= 0x1
BFO_RENAME_FOLDER_OPTIONS_TOINTERNET	= 0x2
BFO_BOTH_OPTIONS	= 0x4
BIF_PREFER_INTERNET_SHORTCUT	= 0x8
BFO_BROWSE_NO_IN_NEW_PROCESS	= 0x10
BFO_ENABLE_HYPERLINK_TRACKING	= 0x20
BFO_USE_IE_OFFLINE_SUPPORT	= 0x40
BFO_SUBSTITUE_INTERNET_START_PAGE	= 0x80
BFO_USE_IE_LOGOBANDING	= 0x100
BFO_ADD_IE_TOCAPTIONBAR	= 0x200
BFO_USE_DIALUP_REF	= 0x400
BFO_USE_IE_TOOLBAR	= 0x800
BFO_NO_PARENT_FOLDER_SUPPORT	= 0x1000
BFO_NO_REOPEN_NEXT_RESTART	= 0x2000
BFO_GO_HOME_PAGE	= 0x4000
BFO_PREFER_IEPROCESS	= 0x8000
BFO_SHOW_NAVIGATION_CANCELLED	= 0x10000
BFO_USE_IE_STATUSBAR	= 0x20000
BFO_QUERY_ALL	= 0xffffffff

;#define GUID_IID_IBrowserFrameOptions <0x10DF43C8,0x1DBE,0x11d3,<0x8B,0x34,0x00,0x60,0x97,0xDF,0x5B,0xD4>>

#IFNDEF IBrowserFrameOptions
BrowserFrameOptions STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetFrameOptions PTR
ENDS
#ENDIF // IBrowserFrameOptions

NWMF_UNLOADING	= 0x1
NWMF_USERINITED	= 0x2
NWMF_FIRST	= 0x4
NWMF_OVERRIDEKEY	= 0x8
NWMF_SHOWHELP	= 0x10
NWMF_HTMLDIALOG	= 0x20
NWMF_FROMDIALOGCHILD	= 0x40
NWMF_USERREQUESTED	= 0x80
NWMF_USERALLOWED	= 0x100

;#define GUID_IID_INewWindowManager <0xD2BC4C84,0x3F72,0x4a52,<0xA6,0x04,0x7B,0xCB,0xF3,0x98,0x2C,0xBB>>
#define SID_SNewWindowManager IID_INewWindowManager

#IFNDEF INewWindowManager
INewWindowManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	EvaluateNewWindow PTR 
ENDS
#ENDIF // INewWindowManager

SMDATA STRUCT
	dwMask DD
	dwFlags DD
	hmenu HANDLE
	hwnd HANDLE
	uId DD
	uIdParent DD
	uIdAncestor DD
	punk PTR
	pidlFolder PTR
	pidlItem PTR
	psf PTR
	pvUserData PTR
ENDS

// Mask
#define SMDM_SHELLFOLDER               0x00000001  // This is for an item in the band
#define SMDM_HMENU                     0x00000002  // This is for the Band itself
#define SMDM_TOOLBAR                   0x00000004  // Plain toolbar, not associated with a shell folder or hmenu

SMINFO STRUCT
	dwMask DD
	dwType DD
	dwFlags DD
	iIcon DD
ENDS

KF_CATEGORY_VIRTUAL	= 1
KF_CATEGORY_FIXED	= 2
KF_CATEGORY_COMMON	= 3
KF_CATEGORY_PERUSER	= 4

KFDF_LOCAL_REDIRECT_ONLY	= 0x2
KFDF_ROAMABLE	= 0x4
KFDF_PRECREATE	= 0x8
KFDF_STREAM	= 0x10
KFDF_PUBLISHEXPANDEDPATH	= 0x20

KF_REDIRECT_USER_EXCLUSIVE = 0x1
KF_REDIRECT_COPY_SOURCE_DACL = 0x2
KF_REDIRECT_OWNER_USER = 0x4
KF_REDIRECT_SET_OWNER_EXPLICIT = 0x8
KF_REDIRECT_CHECK_ONLY = 0x10
KF_REDIRECT_WITH_UI = 0x20
KF_REDIRECT_UNPIN = 0x40
KF_REDIRECT_PIN = 0x80
KF_REDIRECT_COPY_CONTENTS = 0x200
KF_REDIRECT_DEL_SOURCE_CONTENTS = 0x400
KF_REDIRECT_EXCLUDE_ALL_KNOWN_SUBFOLDERS = 0x800

KF_REDIRECTION_CAPABILITIES_ALLOW_ALL = 0xff
KF_REDIRECTION_CAPABILITIES_REDIRECTABLE = 0x1
KF_REDIRECTION_CAPABILITIES_DENY_ALL = 0xfff00
KF_REDIRECTION_CAPABILITIES_DENY_POLICY_REDIRECTED = 0x100
KF_REDIRECTION_CAPABILITIES_DENY_POLICY = 0x200
KF_REDIRECTION_CAPABILITIES_DENY_PERMISSIONS = 0x400

KNOWNFOLDER_DEFINITION STRUCT
	category DD
	pszName PTR
	pszDescription PTR
	fidParent GUID
	pszRelativePath PTR
	pszParsingName PTR
	pszTooltip PTR
	pszLocalizedName PTR
	pszIcon PTR
	pszSecurity PTR
	dwAttributes DD
	kfdFlags DD
	ftidType GUID
ENDS

;#define GUID_IID_IKnownFolder <0x3AA7AF7E,0x9B36,0x420c,<0xA8,0xE3,0xF7,0x7D,0x46,0x74,0xA4,0x88>>

IKnownFolder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetId PTR
	GetCategory PTR
	GetShellItem PTR
	GetPath PTR
	SetPath PTR
	GetIDList PTR
	GetFolderType PTR
	GetRedirectionCapabilities PTR
	GetFolderDefinition PTR
ENDS

FFFP_EXACTMATCH	= 0
FFFP_NEARESTPARENTMATCH	= 1

;#define GUID_IID_IKnownFolderManager <0x8BE2D872,0x86AA,0x4d47,<0xB7,0x76,0x32,0xCC,0xA4,0x0C,0x70,0x18>>

IKnownFolderManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	FolderIdFromCsidl PTR
	FolderIdToCsidl PTR
	GetFolderIds PTR
	GetFolder PTR
	GetFolderByName PTR
	RegisterFolder PTR
	UnregisterFolder PTR
	FindFolderFromPath PTR
	FindFolderFromIDList PTR
	Redirect PTR
ENDS

SHARE_ROLE_INVALID	= -1
SHARE_ROLE_READER	= 0
SHARE_ROLE_CONTRIBUTOR	= 1
SHARE_ROLE_CO_OWNER	= 2
SHARE_ROLE_OWNER	= 3
SHARE_ROLE_CUSTOM	= 4
SHARE_ROLE_MIXED	= 5

DEFSHAREID_USERS	= 1
DEFSHAREID_PUBLIC	= 2

;#define GUID_IID_ISharingConfigurationManager <0xB4CD448A,0x9C86,0x4466,<0x92,0x01,0x2E,0x62,0x10,0x5B,0x87,0xAE>>

ISharingConfigurationManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateShare PTR
	DeleteShare PTR
	ShareExists PTR
	GetSharePermissions PTR
	SharePrinters PTR
	StopSharingPrinters PTR
	ArePrintersShared PTR
ENDS

;#define GUID_IID_IPreviousVersionsInfo <0x76e54780,0xad74,0x48e3,<0xa6,0x95,0x3b,0xa9,0xa0,0xaf,0xf1,0x0d>>

IPreviousVersionsInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AreSnapshotsAvailable PTR
ENDS

#define GUID_IID_IRelatedItem

#ENDIF // SHOBJIDL_H