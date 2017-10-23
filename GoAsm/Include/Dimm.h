#ifndef DIMM_H
#define DIMM_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF
#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

/* header files for imported files */

#IFNDEF IMM_H
	#include "imm.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF REGISTERWORDA
	REGISTERWORDA STRUCT
		lpReading PTR
		lpWord PTR
	ENDS
#ENDIF

#IFNDEF REGISTERWORDW
	REGISTERWORDW STRUCT
		lpReading PTR
		lpWord PTR
	ENDS
#ENDIF

#IFNDEF LOGFONTA
	LOGFONTA STRUCT
		lfHeight DD
		lfWidth DD
		lfEscapement DD
		lfOrientation DD
		lfWeight DD
		lfItalic DB
		lfUnderline DB
		lfStrikeOut DB
		lfCharSet DB
		lfOutPrecision DB
		lfClipPrecision DB
		lfQuality DB
		lfPitchAndFamily DB
		lfFaceName DB LF_FACESIZE DUP
	ENDS
#ENDIF

#IFNDEF LOGFONTW
	LOGFONTW STRUCT
		lfHeight DD
		lfWidth DD
		lfEscapement DD
		lfOrientation DD
		lfWeight DD
		lfItalic DB
		lfUnderline DB
		lfStrikeOut DB
		lfCharSet DB
		lfOutPrecision DB
		lfClipPrecision DB
		lfQuality DB
		lfPitchAndFamily DB
		lfFaceName DW LF_FACESIZE DUP
	ENDS
#ENDIF

#IFNDEF CANDIDATEFORM
	CANDIDATEFORM STRUCT
		dwIndex DD
		dwStyle DD
		ptCurrentPos POINT
		rcArea RECT
	ENDS
#ENDIF

#IFNDEF COMPOSITIONFORM
	COMPOSITIONFORM STRUCT
		dwStyle DD
		ptCurrentPos POINT
		rcArea RECT
	ENDS
#ENDIF

#IFNDEF CANDIDATELIST
	CANDIDATELIST STRUCT
		dwSize DD
		dwStyle DD
		dwCount DD
		dwSelection DD
		dwPageStart DD
		dwPageSize DD
		dwOffset DD
	ENDS
#ENDIF

#IFNDEF STYLEBUFA
	STYLEBUFA STRUCT
		dwStyle DD
		szDescription DB STYLE_DESCRIPTION_SIZE DUP
	ENDS
#ENDIF

#IFNDEF STYLEBUFW
	STYLEBUFW STRUCT
		dwStyle DD
		szDescription DW STYLE_DESCRIPTION_SIZE DUP
	ENDS
#ENDIF

#ifdef WIN9X
	#define IMEMENUITEM_STRING_SIZE 80
	
	#IFNDEF IMEMENUITEMINFOA
		IMEMENUITEMINFOA STRUCT
			cbSize DD
			fType DD
			fState DD
			wID DD
			hbmpChecked HANDLE
			hbmpUnchecked HANDLE
			dwItemData DD
			szString DB IMEMENUITEM_STRING_SIZE DUP
			hbmpItem HANDLE
		ENDS
	#ENDIF
	
	#IFNDEF IMEMENUITEMINFOW
		IMEMENUITEMINFOW STRUCT
			cbSize DD
			fType DD
			fState DD
			wID DD
			hbmpChecked HANDLE
			hbmpUnchecked HANDLE
			dwItemData DD
			szString DW IMEMENUITEM_STRING_SIZE DUP
			hbmpItem HANDLE
		ENDS
	#ENDIF
	
#endif /* WIN9X */

#ifndef DDKIMM_H
	INPUTCONTEXT STRUCT
		hWnd HANDLE
		fOpen DD
		ptStatusWndPos POINT
		ptSoftKbdPos POINT
		fdwConversion DD
		fdwSentence DD
		lfFont UNION
			A LOGFONTA
			W LOGFONTW
		ENDUNION
		cfCompForm COMPOSITIONFORM
		cfCandForm COMPOSITIONFORM 4 DUP
		hCompStr HANDLE
		hCandInfo HANDLE
		hGuideLine HANDLE
		hPrivate HANDLE
		dwNumMsgBuf DD
		hMsgBuf HANDLE
		fdwInit DD
		dwReserve DD 3 DUP
	ENDS
	
	IMEINFO STRUCT
		dwPrivateDataSize DD
		fdwProperty DD
		fdwConversionCaps DD
		fdwSentenceCaps DD
		fdwUICaps DD
		fdwSCSCaps DD
		fdwSelectCaps DD
	ENDS
#endif

#define GUID_IID_IEnumRegisterWordA <08C03412,0xF96B,0x11d0,<0xA4,0x75,0x00,0xAA,0x00,0x6B,0xCC,0x59>>

IEnumRegisterWordA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Clone PTR
	Next PTR
	Reset PTR
	Skip PTR
ENDS

#define GUID_IID_IEnumRegisterWordW <0x4955DD31,0xB159,0x11d0,<0x8F,0xCF,0x00,0xAA,0x00,0x6B,0xCC,0x59>>

IEnumRegisterWordW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Clone PTR
	Next PTR
	Reset PTR
	Skip PTR
ENDS

#IFDEF UNICODE
	#define GUID_IID_IEnumRegisterWord GUID_IID_IEnumRegisterWordW
	#define IEnumRegisterWord IEnumRegisterWordW
#ELSE
	#define GUID_IID_IEnumRegisterWord GUID_IID_IEnumRegisterWordA
	#define IEnumRegisterWord IEnumRegisterWordA
#ENDIF

#define GUID_IID_IEnumInputContext <0x09b5eab0,0xf997,0x11d1,<0x93,0xd4,0x00,0x60,0xb0,0x67,0xb8,0x6e>>

IEnumInputContext STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Clone PTR
	Next PTR
	Reset PTR
	Skip PTR
ENDS

#define GUID_IID_IActiveIMMRegistrar <0xb3458082,0xbd00,0x11d1,<0x93,0x9b,0x00,0x60,0xb0,0x67,0xb8,0x6e>>

IActiveIMMRegistrar STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterIME PTR
	UnregisterIME PTR
ENDS

#define GUID_IID_IActiveIMMMessagePumpOwner <0xb5cf2cfa,0x8aeb,0x11d1,<0x93,0x64,0x00,0x60,0xb0,0x67,0xb8,0x6e>>

IActiveIMMMessagePumpOwner STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Start PTR
	End PTR
	OnTranslateMessage PTR
	Pause PTR
	Resume PTR
ENDS

#define GUID_IID_IActiveIMMApp <0x08c0e040,0x62d1,0x11d1,<0x93,0x26,0x00,0x60,0xb0,0x67,0xb8,0x6e>>

IActiveIMMApp STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AssociateContext PTR
	ConfigureIMEA PTR
	ConfigureIMEW PTR
	CreateContext PTR
	DestroyContext PTR
	EnumRegisterWordA PTR
	EnumRegisterWordW PTR
	EscapeA PTR
	EscapeW PTR
	GetCandidateListA PTR
	GetCandidateListW PTR
	GetCandidateListCountA PTR
	GetCandidateListCountW PTR
	GetCandidateWindow PTR
	GetCompositionFontA PTR
	GetCompositionFontW PTR
	GetCompositionStringA PTR
	GetCompositionStringW PTR
	GetCompositionWindow PTR
	GetContext PTR
	GetConversionListA PTR
	GetConversionListW PTR
	GetConversionStatus PTR
	GetDefaultIMEWnd PTR
	GetDescriptionA PTR
	GetDescriptionW PTR
	GetGuideLineA PTR
	GetGuideLineW PTR
	GetIMEFileNameA PTR
	GetIMEFileNameW PTR
	GetOpenStatus PTR
	GetProperty PTR
	GetRegisterWordStyleA PTR
	GetRegisterWordStyleW PTR
	GetStatusWindowPos PTR
	GetVirtualKey PTR
	InstallIMEA PTR
	InstallIMEW PTR
	IsIME PTR
	IsUIMessageA PTR
	IsUIMessageW PTR
	NotifyIME PTR
	RegisterWordA PTR
	RegisterWordW PTR
	ReleaseContext PTR
	SetCandidateWindow PTR
	SetCompositionFontA PTR
	SetCompositionFontW PTR
	SetCompositionStringA PTR
	SetCompositionStringW PTR
	SetCompositionWindow PTR
	SetConversionStatus PTR
	SetOpenStatus PTR
	SetStatusWindowPos PTR
	SimulateHotKey PTR
	UnregisterWordA PTR
	UnregisterWordW PTR
	Activate PTR
	Deactivate PTR
	OnDefWindowProc PTR
	FilterClientWindows PTR
	GetCodePageA PTR
	GetLangId PTR
	AssociateContextEx PTR
	DisableIME PTR
	GetImeMenuItemsA PTR
	GetImeMenuItemsW PTR
	EnumInputContext PTR
ENDS

#define GUID_IID_IActiveIMMIME <0x08C03411,0xF96B,0x11d0,<0xA4,0x75,0x00,0xAA,0x00,0x6B,0xCC,0x59>>

IActiveIMMIME STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AssociateContext PTR
	ConfigureIMEA PTR
	ConfigureIMEW PTR
	CreateContext PTR
	DestroyContext PTR
	EnumRegisterWordA PTR
	EnumRegisterWordW PTR
	EscapeA PTR
	EscapeW PTR
	GetCandidateListA PTR
	GetCandidateListW PTR
	GetCandidateListCountA PTR
	GetCandidateListCountW PTR
	GetCandidateWindow PTR
	GetCompositionFontA PTR
	GetCompositionFontW PTR
	GetCompositionStringA PTR
	GetCompositionStringW PTR
	GetCompositionWindow PTR
	GetContext PTR
	GetConversionListA PTR
	GetConversionListW PTR
	GetConversionStatus PTR
	GetDefaultIMEWnd PTR
	GetDescriptionA PTR
	GetDescriptionW PTR
	GetGuideLineA PTR
	GetGuideLineW PTR
	GetIMEFileNameA PTR
	GetIMEFileNameW PTR
	GetOpenStatus PTR
	GetProperty PTR
	GetRegisterWordStyleA PTR
	GetRegisterWordStyleW PTR
	GetStatusWindowPos PTR
	GetVirtualKey PTR
	InstallIMEA PTR
	InstallIMEW PTR
	IsIME PTR
	IsUIMessageA PTR
	IsUIMessageW PTR
	NotifyIME PTR
	RegisterWordA PTR
	RegisterWordW PTR
	ReleaseContext PTR
	SetCandidateWindow PTR
	SetCompositionFontA PTR
	SetCompositionFontW PTR
	SetCompositionStringA PTR
	SetCompositionStringW PTR
	SetCompositionWindow PTR
	SetConversionStatus PTR
	SetOpenStatus PTR
	SetStatusWindowPos PTR
	SimulateHotKey PTR
	UnregisterWordA PTR
	UnregisterWordW PTR
	GenerateMessage PTR
	LockIMC PTR
	UnlockIMC PTR
	GetIMCLockCount PTR
	CreateIMCC PTR
	DestroyIMCC PTR
	LockIMCC PTR
	UnlockIMCC PTR
	ReSizeIMCC PTR
	GetIMCCSize PTR
	GetIMCCLockCount PTR
	GetHotKey PTR
	SetHotKey PTR
	CreateSoftKeyboard PTR
	DestroySoftKeyboard PTR
	ShowSoftKeyboard PTR
	GetCodePageA PTR
	GetLangId PTR
	KeybdEvent PTR
	LockModal PTR
	UnlockModal PTR
	AssociateContextEx PTR
	DisableIME PTR
	GetImeMenuItemsA PTR
	GetImeMenuItemsW PTR
	EnumInputContext PTR
	RequestMessageA PTR
	RequestMessageW PTR
	SendIMCA PTR
	SendIMCW PTR
	IsSleeping PTR
ENDS

#define GUID_IID_IActiveIME <0x6FE20962,0xD077,0x11d0,<0x8F,0xE7,0x00,0xAA,0x00,0x6B,0xCC,0x59>>

IActiveIME STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Inquire PTR
	ConversionList PTR
	Configure PTR
	Destroy PTR
	Escape PTR
	SetActiveContext PTR
	ProcessKey PTR
	Notify PTR
	Select PTR
	SetCompositionString PTR
	ToAsciiEx PTR
	RegisterWord PTR
	UnregisterWord PTR
	GetRegisterWordStyle PTR
	EnumRegisterWord PTR
	GetCodePageA PTR
	GetLangId PTR
ENDS

#define GUID_IID_IActiveIME2 <0xe1c4bf0e,0x2d53,0x11d2,<0x93,0xe1,0x00,0x60,0xb0,0x67,0xb8,0x6e>>

IActiveIME2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Inquire PTR
	ConversionList PTR
	Configure PTR
	Destroy PTR
	Escape PTR
	SetActiveContext PTR
	ProcessKey PTR
	Notify PTR
	Select PTR
	SetCompositionString PTR
	ToAsciiEx PTR
	RegisterWord PTR
	UnregisterWord PTR
	GetRegisterWordStyle PTR
	EnumRegisterWord PTR
	GetCodePageA PTR
	GetLangId PTR
	Sleep PTR
	Unsleep PTR
ENDS

#define GUID_CLSID_CActiveIMM <0x4955DD33,0xB159,0x11d0,<0x8F,0xCF,0x00,0xAA,0x00,0x6B,0xCC,0x59>>

#endif



