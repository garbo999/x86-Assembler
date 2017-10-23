#ifndef SHLDISP_H
#define SHLDISP_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif

#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

SCEE_PATHNOTFOUND = 1
SCEE_MAXFILESFOUND = 2
SCEE_INDEXSEARCH = 3
SCEE_CONSTRAINT = 4
SCEE_SCOPEMISMATCH = 5
SCEE_CASESENINDEX = 6
SCEE_INDEXNOTCOMPLETE = 7

OFS_INACTIVE = -1
OFS_ONLINE = 0
OFS_OFFLINE = 1
OFS_SERVERBACK = 2
OFS_DIRTYCACHE = 3

#define SZ_MIGWIZPROGRESS_OK  L""

#define SZ_MIGWIZCOMPLETE_OK  L""
#define SZ_MIGWIZCOMPLETE_CANCEL  L"Cancel"
#define SZ_MIGWIZCOMPLETE_FAIL  L"Fail"
#define SZ_MIGWIZCOMPLETE_NODISK  L"No Disk"

SFVVO_SHOWALLOBJECTS = 0x1
SFVVO_SHOWEXTENSIONS = 0x2
SFVVO_SHOWCOMPCOLOR = 0x8
SFVVO_SHOWSYSFILES = 0x20
SFVVO_WIN95CLASSIC = 0x40
SFVVO_DOUBLECLICKINWEBVIEW = 0x80
SFVVO_DESKTOPHTML = 0x200

ssfDESKTOP = 0
ssfPROGRAMS = 0x2
ssfCONTROLS = 0x3
ssfPRINTERS = 0x4
ssfPERSONAL = 0x5
ssfFAVORITES = 0x6
ssfSTARTUP = 0x7
ssfRECENT = 0x8
ssfSENDTO = 0x9
ssfBITBUCKET = 0xa
ssfSTARTMENU = 0xb
ssfDESKTOPDIRECTORY = 0x10
ssfDRIVES = 0x11
ssfNETWORK = 0x12
ssfNETHOOD = 0x13
ssfFONTS = 0x14
ssfTEMPLATES = 0x15
ssfCOMMONSTARTMENU = 0x16
ssfCOMMONPROGRAMS = 0x17
ssfCOMMONSTARTUP = 0x18
ssfCOMMONDESKTOPDIR = 0x19
ssfAPPDATA = 0x1a
ssfPRINTHOOD = 0x1b
ssfLOCALAPPDATA = 0x1c
ssfALTSTARTUP = 0x1d
ssfCOMMONALTSTARTUP = 0x1e
ssfCOMMONFAVORITES = 0x1f
ssfINTERNETCACHE = 0x20
ssfCOOKIES = 0x21
ssfHISTORY = 0x22
ssfCOMMONAPPDATA = 0x23
ssfWINDOWS = 0x24
ssfSYSTEM = 0x25
ssfPROGRAMFILES = 0x26
ssfMYPICTURES = 0x27
ssfPROFILE = 0x28
ssfSYSTEMx86 = 0x29
ssfPROGRAMFILESx86 = 0x30

#define GUID_IID_IFolderViewOC <0x9BA05970,0xF6A8,0x11CF,<0xA4,0x42,0x00,0xA0,0xC9,0x0A,0x8F,0x39>>
IFolderViewOC STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	SetFolderView PTR
ENDS

#define GUID_IID_DShellFolderViewEvents <0x62112AA2,0xEBE4,0x11cf,<0xA5,0xFB,0x00,0x20,0xAF,0xE7,0x29,0x2D>>
DShellFolderViewEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
ENDS

#define GUID_IID_DFConstraint <0x4a3df050,0x23bd,0x11d2,<0x93,0x9f,0x00,0xa0,0xc9,0x1e,0xed,0xba>>
DFConstraint STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Value PTR
ENDS

SCE_SEARCHFORFILES = 0
SCE_SEARCHFORCOMPUTERS = 1

#define GUID_IID_ISearchCommandExt <0x1D2EFD50,0x75CE,0x11d1,<0xB7,0x5A,0x00,0xA0,0xC9,0x05,0x64,0xFE>>
ISearchCommandExt STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	ClearResults PTR
	NavigateToSearchResults PTR
	get_ProgressText PTR
	SaveSearch PTR
	GetErrorInfo PTR
	SearchFor PTR
	GetScopeInfo PTR
	RestoreSavedSearch PTR
	Execute PTR
	AddConstraint PTR
	GetNextConstraint PTR
ENDS

#define GUID_IID_FolderItem <0xFAC32C80,0xCBE4,0x11CE,<0x83,0x50,0x44,0x45,0x53,0x54,0x00,0x00>>
FolderItem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	get_Name PTR
	put_Name PTR
	get_Path PTR
	get_GetLink PTR
	get_GetFolder PTR
	get_IsLink PTR
	get_IsFolder PTR
	get_IsFileSystem PTR
	get_IsBrowsable PTR
	get_ModifyDate PTR
	put_ModifyDate PTR
	get_Size PTR
	get_Type PTR
	Verbs PTR
	InvokeVerb PTR
ENDS

#define GUID_IID_FolderItems <0x744129E0,0xCBE5,0x11CE,<0x83,0x50,0x44,0x45,0x53,0x54,0x00,0x00>>
FolderItems STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Count PTR
	get_Application PTR
	get_Parent PTR
	Item PTR
	_NewEnum PTR
ENDS

#define GUID_IID_FolderItemVerb <0x08EC3E00,0x50B0,0x11CF,<0x96,0x0C,0x00,0x80,0xC7,0xF4,0xEE,0x85>>
FolderItemVerb STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	get_Name PTR
	DoIt PTR
ENDS

#define GUID_IID_FolderItemVerbs <0x1F8352C0,0x50B0,0x11CF,<0x96,0x0C,0x00,0x80,0xC7,0xF4,0xEE,0x85>>
FolderItemVerbs STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Count PTR
	get_Application PTR
	get_Parent PTR
	Item PTR
	_NewEnum PTR
ENDS

#define GUID_IID_Folder <0xBBCBDE60,0xC3FF,0x11CE,<0x83,0x50,0x44,0x45,0x53,0x54,0x00,0x00>>
Folder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Title PTR
	get_Application PTR
	get_Parent PTR
	get_ParentFolder PTR
	Items PTR
	ParseName PTR
	NewFolder PTR
	MoveHere PTR
	CopyHere PTR
	GetDetailsOf PTR
ENDS

#define GUID_IID_Folder2 <0xf0d2d8ef,0x3890,0x11d2,<0xbf,0x8b,0x00,0xc0,0x4f,0xb9,0x36,0x61>>
Folder2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Title PTR
	get_Application PTR
	get_Parent PTR
	get_ParentFolder PTR
	Items PTR
	ParseName PTR
	NewFolder PTR
	MoveHere PTR
	CopyHere PTR
	GetDetailsOf PTR
	get_Self PTR
	get_OfflineStatus PTR
	Synchronize PTR
	get_HaveToShowWebViewBarricade PTR
	DismissedWebViewBarricade PTR
ENDS

#define GUID_IID_Folder3 <0xA7AE5F64,0xC4D7,0x4d7f,<0x93,0x07,0x4D,0x24,0xEE,0x54,0xB8,0x41>>
Folder3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Title PTR
	get_Application PTR
	get_Parent PTR
	get_ParentFolder PTR
	Items PTR
	ParseName PTR
	NewFolder PTR
	MoveHere PTR
	CopyHere PTR
	GetDetailsOf PTR
	get_Self PTR
	get_OfflineStatus PTR
	Synchronize PTR
	get_HaveToShowWebViewBarricade PTR
	DismissedWebViewBarricade PTR
	get_ShowWebViewBarricade PTR
	put_ShowWebViewBarricade PTR
ENDS

#define GUID_IID_FolderItem2 <0xedc817aa,0x92b8,0x11d1,<0xb0,0x75,0x00,0xc0,0x4f,0xc3,0x3a,0xa5>>
FolderItem2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	get_Name PTR
	put_Name PTR
	get_Path PTR
	get_GetLink PTR
	get_GetFolder PTR
	get_IsLink PTR
	get_IsFolder PTR
	get_IsFileSystem PTR
	get_IsBrowsable PTR
	get_ModifyDate PTR
	put_ModifyDate PTR
	get_Size PTR
	get_Type PTR
	Verbs PTR
	InvokeVerb PTR
	InvokeVerbEx PTR
	ExtendedProperty PTR
ENDS

#define GUID_IID_FolderItems2 <0xC94F0AD0,0xF363,0x11d2,<0xA3,0x27,0x00,0xC0,0x4F,0x8E,0xEC,0x7F>>
FolderItems2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Count PTR
	get_Application PTR
	get_Parent PTR
	Item PTR
	_NewEnum PTR
	InvokeVerbEx PTR
ENDS

#define GUID_IID_FolderItems3 <0xeaa7c309,0xbbec,0x49d5,<0x82,0x1d,0x64,0xd9,0x66,0xcb,0x66,0x7f>>
FolderItems3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Count PTR
	get_Application PTR
	get_Parent PTR
	Item PTR
	_NewEnum PTR
	InvokeVerbEx PTR
	Filter PTR
	get_Verbs PTR
ENDS

#define GUID_IID_IShellLinkDual <0x88A05C00,0xF000,0x11CE,<0x83,0x50,0x44,0x45,0x53,0x54,0x00,0x00>>
IShellLinkDual STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Path PTR
	put_Path PTR
	get_Description PTR
	put_Description PTR
	get_WorkingDirectory PTR
	put_WorkingDirectory PTR
	get_Arguments PTR
	put_Arguments PTR
	get_Hotkey PTR
	put_Hotkey PTR
	get_ShowCommand PTR
	put_ShowCommand PTR
	Resolve PTR
	GetIconLocation PTR
	SetIconLocation PTR
	Save PTR
ENDS

#define GUID_IID_IShellLinkDual2 <0x317EE249,0xF12E,0x11d2,<0xB1,0xE4,0x00,0xC0,0x4F,0x8E,0xEB,0x3E>>
IShellLinkDual2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Path PTR
	put_Path PTR
	get_Description PTR
	put_Description PTR
	get_WorkingDirectory PTR
	put_WorkingDirectory PTR
	get_Arguments PTR
	put_Arguments PTR
	get_Hotkey PTR
	put_Hotkey PTR
	get_ShowCommand PTR
	put_ShowCommand PTR
	Resolve PTR
	GetIconLocation PTR
	SetIconLocation PTR
	Save PTR
	get_Target PTR
ENDS

#define GUID_IID_IShellFolderViewDual <0xE7A1AF80,0x4D96,0x11CF,<0x96,0x0C,0x00,0x80,0xC7,0xF4,0xEE,0x85>>
IShellFolderViewDual STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	get_Folder PTR
	SelectedItems PTR
	get_FocusedItem PTR
	SelectItem PTR
	PopupItemMenu PTR
	get_Script PTR
	get_ViewOptions PTR
ENDS

#define GUID_IID_IShellFolderViewDual2 <0x31C147b6,0x0ADE,0x4A3C,<0xB5,0x14,0xDD,0xF9,0x32,0xEF,0x6D,0x17>>
IShellFolderViewDual2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	get_Folder PTR
	SelectedItems PTR
	get_FocusedItem PTR
	SelectItem PTR
	PopupItemMenu PTR
	get_Script PTR
	get_ViewOptions PTR
	get_CurrentViewMode PTR
	put_CurrentViewMode PTR
	SelectItemRelative PTR
ENDS

#define GUID_IID_IMigrationWizardAuto <0xCE20DAB9,0xB353,0x469b,<0x8B,0x4D,0x6D,0xBB,0x3A,0x7B,0xA0,0x16>>
IMigrationWizardAuto STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	CreateToolDisk PTR
	ApplySettings PTR
	Cancel PTR
ENDS

#define GUID_IID_DMigrationWizardAutoEvents <0xD2AC137D,0xA6D8,0x43b6,<0x98,0x79,0xEA,0x34,0xB6,0x7E,0x18,0x80>>
DMigrationWizardAutoEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
ENDS

#define GUID_IID_IShellDispatch <0xD8F015C0,0xC278,0x11CE,<0xA4,0x9E,0x44,0x45,0x53,0x54,0x00,0x00>>
IShellDispatch STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	NameSpace PTR
	BrowseForFolder PTR
	Windows PTR
	Open PTR
	Explore PTR
	MinimizeAll PTR
	UndoMinimizeALL PTR
	FileRun PTR
	CascadeWindows PTR
	TileVertically PTR
	TileHorizontally PTR
	ShutdownWindows PTR
	Suspend PTR
	EjectPC PTR
	SetTime PTR
	TrayProperties PTR
	Help PTR
	FindFiles PTR
	FindComputer PTR
	RefreshMenu PTR
	ControlPanelItem PTR
ENDS


#define GUID_IID_IShellDispatch2 <0xA4C6892C,0x3BA9,0x11d2,<0x9D,0xEA,0x00,0xC0,0x4F,0xB1,0x61,0x62>>
IShellDispatch2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	NameSpace PTR
	BrowseForFolder PTR
	Windows PTR
	Open PTR
	Explore PTR
	MinimizeAll PTR
	UndoMinimizeALL PTR
	FileRun PTR
	CascadeWindows PTR
	TileVertically PTR
	TileHorizontally PTR
	ShutdownWindows PTR
	Suspend PTR
	EjectPC PTR
	SetTime PTR
	TrayProperties PTR
	Help PTR
	FindFiles PTR
	FindComputer PTR
	RefreshMenu PTR
	ControlPanelItem PTR
	IsRestricted PTR
	ShellExecute PTR
	FindPrinter PTR
	GetSystemInformation PTR
	ServiceStart PTR
	ServiceStop PTR
	IsServiceRunning PTR
	CanStartStopService PTR
	ShowBrowserBar PTR
ENDS

#define GUID_IID_IShellDispatch3 <0x177160ca,0xbb5a,0x411c,<0x84,0x1d,0xbd,0x38,0xfa,0xcd,0xea,0xa0>>
IShellDispatch3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	NameSpace PTR
	BrowseForFolder PTR
	Windows PTR
	Open PTR
	Explore PTR
	MinimizeAll PTR
	UndoMinimizeALL PTR
	FileRun PTR
	CascadeWindows PTR
	TileVertically PTR
	TileHorizontally PTR
	ShutdownWindows PTR
	Suspend PTR
	EjectPC PTR
	SetTime PTR
	TrayProperties PTR
	Help PTR
	FindFiles PTR
	FindComputer PTR
	RefreshMenu PTR
	ControlPanelItem PTR
	IsRestricted PTR
	ShellExecute PTR
	FindPrinter PTR
	GetSystemInformation PTR
	ServiceStart PTR
	ServiceStop PTR
	IsServiceRunning PTR
	CanStartStopService PTR
	ShowBrowserBar PTR
	AddToRecent PTR
ENDS

#define GUID_IID_IShellDispatch4 <0xefd84b2d,0x4bcf,0x4298,<0xbe,0x25,0xeb,0x54,0x2a,0x59,0xfb,0xda>>
IShellDispatch4 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Application PTR
	get_Parent PTR
	NameSpace PTR
	BrowseForFolder PTR
	Windows PTR
	Open PTR
	Explore PTR
	MinimizeAll PTR
	UndoMinimizeALL PTR
	FileRun PTR
	CascadeWindows PTR
	TileVertically PTR
	TileHorizontally PTR
	ShutdownWindows PTR
	Suspend PTR
	EjectPC PTR
	SetTime PTR
	TrayProperties PTR
	Help PTR
	FindFiles PTR
	FindComputer PTR
	RefreshMenu PTR
	ControlPanelItem PTR
	IsRestricted PTR
	ShellExecute PTR
	FindPrinter PTR
	GetSystemInformation PTR
	ServiceStart PTR
	ServiceStop PTR
	IsServiceRunning PTR
	CanStartStopService PTR
	ShowBrowserBar PTR
	AddToRecent PTR
	WindowsSecurity PTR
	ToggleDesktop PTR
	ExplorerPolicy PTR
	GetSetting PTR
ENDS

#define GUID_IID_DSearchCommandEvents <0x60890160,0x69f0,0x11d1,<0xb7,0x58,0x00,0xa0,0xc9,0x05,0x64,0xfe>>
DSearchCommandEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
ENDS

#define GUID_IID_IFileSearchBand <0x2D91EEA1,0x9932,0x11d2,<0xBE,0x86,0x00,0xA0,0xC9,0xA8,0x3D,0xA1>>
IFileSearchBand STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	SetFocus PTR
	SetSearchParameters PTR
	get_SearchID PTR
	get_Scope PTR
	get_QueryFile PTR
ENDS

#define GUID_IID_IWebWizardHost <0x18bcc359,0x4990,0x4bfb,<0xb9,0x51,0x3c,0x83,0x70,0x2b,0xe5,0xf9>>
IWebWizardHost STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	FinalBack PTR
	FinalNext PTR
	Cancel PTR
	put_Caption PTR
	get_Caption PTR
	put_Property PTR
	get_Property PTR
	SetWizardButtons PTR
	SetHeaderText PTR
ENDS

#define GUID_IID_INewWDEvents <0x0751c551,0x7568,0x41c9,<0x8e,0x5b,0xe2,0x2e,0x38,0x91,0x92,0x36>>
INewWDEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	FinalBack PTR
	FinalNext PTR
	Cancel PTR
	put_Caption PTR
	get_Caption PTR
	put_Property PTR
	get_Property PTR
	SetWizardButtons PTR
	SetHeaderText PTR
	PassportAuthenticate PTR
ENDS

#define GUID_IID_IPassportClientServices <0xb30f7305,0x5967,0x45d1,<0xb7,0xbc,0xd6,0xeb,0x71,0x63,0xd7,0x70>>
IPassportClientServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	MemberExists PTR
ENDS

#define GUID_IID_IAutoComplete <0x00bb2762,0x6a77,0x11d0,<0xa5,0x35,0x00,0xc0,0x4f,0xd7,0xd0,0x62>>
IAutoComplete STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
	Enable PTR
ENDS

ACO_NONE = 0
ACO_AUTOSUGGEST = 0x1
ACO_AUTOAPPEND = 0x2
ACO_SEARCH = 0x4
ACO_FILTERPREFIXES = 0x8
ACO_USETAB = 0x10
ACO_UPDOWNKEYDROPSLIST = 0x20
ACO_RTLREADING = 0x40

#define GUID_IID_IAutoComplete2 <0xEAC04BC0,0x3791,0x11d2,<0xBB,0x95,0x00,0x60,0x97,0x7B,0x46,0x4C>>
IAutoComplete2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
	Enable PTR
	SetOptions PTR
	GetOptions PTR
ENDS

ACEO_NONE = 0
ACEO_MOSTRECENTFIRST = 0x1
ACEO_FIRSTUNUSED = 0x10000

#define GUID_IID_IEnumACString <0x8E74C210,0xCF9D,0x4eaf,<0xA4,0x03,0x73,0x56,0x42,0x8F,0x0A,0x5A>>
IEnumACString STRUCT
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
	NextItem PTR
	SetEnumOptions PTR
	GetEnumOptions PTR
ENDS

#define GUID_IID_IAsyncOperation <0x3D8B0590,0xF691,0x11d2,<0x8E,0xA9,0x00,0x60,0x97,0xDF,0x5B,0xD4>>
IAsyncOperation STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAsyncMode PTR
	GetAsyncMode PTR
	StartOperation PTR
	InOperation PTR
	EndOperation PTR
ENDS

#endif /* _SHLDISP_H */
