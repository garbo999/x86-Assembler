#ifndef MAPIFORM_H
#define MAPIFORM_H

/* MAPI definitions */

#ifndef MAPIDEFS_H
	#include mapidefs.h
#endif

#ifndef MAPICODE_H
	#include mapicode.h
#endif

#ifndef MAPIGUID_H
	#include mapiguid.h
#endif

#ifndef MAPITAGS_H
	#include mapitags.h
#endif

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define HFRMREG_DEFAULT  0
#define HFRMREG_LOCAL  1
#define HFRMREG_PERSONAL 2
#define HFRMREG_FOLDER  3

;#define MAPI_GETLASTERROR_METHOD(IPURE)  \
;    MAPIMETHOD(GetLastError)(THIS_ HRESULT,ULONG,LPMAPIERROR*) IPURE;

IPersistMessage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	GetClassID PTR
	IsDirty PTR
	InitNew PTR
	Load PTR
	Save PTR
	SaveCompleted PTR
	HandsOffMessage PTR
ENDS


IMAPIMessageSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	GetSession PTR
	GetStore PTR
	GetFolder PTR
	GetMessage PTR
	GetFormManager PTR
	NewMessage PTR
	CopyMessage PTR
	MoveMessage PTR
	DeleteMessage PTR
	SaveMessage PTR
	SubmitMessage PTR
	GetSiteStatus PTR
ENDS

IMAPIForm STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SetViewContext PTR
	GetViewContext PTR
	ShutdownForm PTR
	DoVerb PTR
	Advise PTR
	Unadvise PTR
ENDS

SAVEOPTS_SAVEIFDIRTY = 0
SAVEOPTS_NOSAVE = 1
SAVEOPTS_PROMPTSAVE = 2

FORMPRINTSETUP STRUCT
	ulFlags DD
	hDevMode HANDLE
	hDevNames HANDLE
	ulFirstPageNumber DD
	fPrintAttachments DD
ENDS

#define SAVE_FORMAT_TEXT  1
#define SAVE_FORMAT_RICHTEXT  2

IMAPIViewContext STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SetAdviseSink PTR
	ActivateNext PTR
	GetPrintSetup PTR
	GetSaveStream PTR
	GetViewStatus PTR
ENDS

#define VCSTATUS_NEXT  0x00000001
#define VCSTATUS_PREV  0x00000002
#define VCSTATUS_MODAL  0x00000004
#define VCSTATUS_INTERACTIVE  0x00000008
#define VCSTATUS_READONLY  0x00000010
#define VCSTATUS_DELETE  0x00010000
#define VCSTATUS_COPY  0x00020000
#define VCSTATUS_MOVE  0x00040000
#define VCSTATUS_SUBMIT  0x00080000
#define VCSTATUS_DELETE_IS_MOVE  0x00100000
#define VCSTATUS_SAVE  0x00200000
#define VCSTATUS_NEW_MESSAGE  0x00400000

#define VCDIR_NEXT  VCSTATUS_NEXT
#define VCDIR_PREV  VCSTATUS_PREV
#define VCDIR_DELETE  VCSTATUS_DELETE
#define VCDIR_MOVE  VCSTATUS_MOVE

#IFNDEF MAPINAMEID
MAPINAMEID STRUCT
	lpguid PTR
	ulKind DD
	Kind UNION
		lID DD
		lpwstrName PTR
	ENDUNION
ENDS
#ENDIF

IMAPIFormAdviseSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnChange PTR
	OnActivateNext PTR
ENDS

IMAPIViewAdviseSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnShutdown PTR
	OnNewMessage PTR
	OnPrint PTR
	OnSubmitted PTR
	OnSaved PTR
ENDS

SMAPIFormPropEnumVal STRUCT
	pszDisplayName PTR
	nVal DD
ENDS

#define FPST_VANILLA  0
#define FPST_ENUM_PROP  1

SMAPIFormProp STRUCT
	ulFlags DD
	nPropType DD
	nmid MAPINAMEID
	pszDisplayName PTR
	nSpecialType DD
	s1 STRUCT
		nmidIdx MAPINAMEID
		cfpevAvailable DD
		pfpevAvailable PTR
	ENDS
ENDS

SMAPIFormPropArray STRUCT
	cProps DD
	ulPad DD
	aFormProp SMAPIFormProp MAPI_DIM DUP <>
ENDS

SMAPIVerb STRUCT
	lVerb DD
	szVerbname PTR
	fuFlags DD
	grfAttribs DD
	ulFlags DD
ENDS

SMAPIVerbArray STRUCT
	cMAPIVerb DD
	aMAPIVerb SMAPIVerb MAPI_DIM DUP (?)
ENDS

#IFNDEF IMAPIProp
	IMAPIProp STRUCT
		UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
		GetLastError PTR
		SaveChanges PTR
		GetProps PTR
		GetPropList PTR
		OpenProperty PTR
		SetProps PTR
		DeleteProps PTR
		CopyTo PTR
		CopyProps PTR
		GetNamesFromIDs PTR
	ENDS
#ENDIF

IMAPIFormInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	CalcFormPropSet PTR
	CalcVerbSet PTR
	MakeIconFromBinary PTR
	SaveForm PTR
	OpenFormContainer PTR
ENDS

#define MAPI_MESSAGE_BEHAVIOR_IPM  0
#define MAPI_MESSAGE_BEHAVIOR_FOLDER  1

SMessageClassArray STRUCT
	cValues DD
	aMessageClass DD MAPI_DIM DUP (?)
ENDS

SMAPIFormInfoArray STRUCT
	cForms DD
	aFormInfo DD MAPI_DIM DUP (?)
ENDS

#define MAPIFORM_SELECT_ALL_REGISTRIES  0
#define MAPIFORM_SELECT_FOLDER_REGISTRY_ONLY  1
#define MAPIFORM_SELECT_NON_FOLDER_REGISTRY_ONLY  2

#define FORMPROPSET_UNION  0
#define FORMPROPSET_INTERSECTION  1

#define MAPIFORM_EXACTMATCH  0x0020

IMAPIFormMgr STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	LoadForm PTR
	ResolveMessageClass PTR
	ResolveMultipleMessageClasses PTR
	CalcFormPropSet PTR
	CreateForm PTR
	SelectForm PTR
	SelectMultipleForms PTR
	SelectFormContainer PTR
	OpenFormContainer PTR
	PrepareForm PTR
	IsInConflict PTR
ENDS

#define MAPIFORM_CPU_X86  1
#define MAPIFORM_CPU_MIP  2
#define MAPIFORM_CPU_AXP  3
#define MAPIFORM_CPU_PPC  4
#define MAPIFORM_CPU_M68  5

#define MAPIFORM_OS_WIN_31  1
#define MAPIFORM_OS_WINNT_35  2
#define MAPIFORM_OS_WIN_95  3
#define MAPIFORM_OS_MAC_7x  4
#define MAPIFORM_OS_WINNT_40  5

#define MAPIFORM_INSTALL_DIALOG  MAPI_DIALOG
#define MAPIFORM_INSTALL_OVERWRITEONCONFLICT  0x0010

IMAPIFormContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	InstallForm PTR
	RemoveForm PTR
	ResolveMessageClass PTR
	ResolveMultipleMessageClasses PTR
	CalcFormPropSet PTR
	GetDisplay PTR
ENDS

IMAPIFormFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	CreateClassFactory PTR
	LockServer PTR
ENDS

#endif /* _MAPIFORM_H */
