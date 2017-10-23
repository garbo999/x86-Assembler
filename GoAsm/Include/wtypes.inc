;=============================================================;
;          wtypes.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WTYPES_INC
#Define WTYPES_INC

;MEMCTX enumeration
MEMCTX_TASK							Equ 1
MEMCTX_SHARED						Equ 2
MEMCTX_MACSYSTEM					Equ 3
MEMCTX_UNKNOWN						Equ (-1)
MEMCTX_SAME							Equ (-2)

;CLSCTX enumeration
CLSCTX_INPROC_SERVER				Equ 01H
CLSCTX_INPROC_HANDLER				Equ 02H
CLSCTX_LOCAL_SERVER					Equ 04H
CLSCTX_INPROC_SERVER16				Equ 08H
CLSCTX_REMOTE_SERVER				Equ 010H
CLSCTX_INPROC_HANDLER16				Equ 020H
CLSCTX_INPROC_SERVERX86				Equ 040H
CLSCTX_INPROC_HANDLERX86			Equ 080H
CLSCTX_ESERVER_HANDLER				Equ 0100H

;MSHLFLAGS enumeration
MSHLFLAGS_NORMAL					Equ 0
MSHLFLAGS_TABLESTRONG				Equ 1
MSHLFLAGS_TABLEWEAK					Equ 2
MSHLFLAGS_NOPING					Equ 4

;MSHCTX enumeration
MSHCTX_LOCAL						Equ 0
MSHCTX_NOSHAREDMEM					Equ 1
MSHCTX_DIFFERENTMACHINE				Equ 2
MSHCTX_INPROC						Equ 3

;DVASPECT enumeration
DVASPECT_CONTENT					Equ 1
DVASPECT_THUMBNAIL					Equ 2
DVASPECT_ICON						Equ 4
DVASPECT_DOCPRINT					Equ 8

;STGC enumeration
STGC_DEFAULT						Equ 0
STGC_OVERWRITE						Equ 1
STGC_ONLYIFCURRENT					Equ 2
STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE	Equ 4
STGC_CONSOLIDATE					Equ 8

;STGMOVE enumeration
STGMOVE_MOVE						Equ 0
STGMOVE_COPY						Equ 1
STGMOVE_SHALLOWCOPY					Equ 2

;STATFLAG enumeration
STATFLAG_DEFAULT					Equ 0
STATFLAG_NONAME						Equ 1
STATFLAG_NOOPEN						Equ 2

;VARENUM enumeration
VT_EMPTY							Equ 0
VT_NULL								Equ 1
VT_I2								Equ 2
VT_I4								Equ 3
VT_R4								Equ 4
VT_R8								Equ 5
VT_CY								Equ 6
VT_DATE								Equ 7
VT_BSTR								Equ 8
VT_DISPATCH							Equ 9
VT_ERROR							Equ 10
VT_BOOL								Equ 11
VT_VARIANT							Equ 12
VT_UNKNOWN							Equ 13
VT_DECIMAL							Equ 14
VT_I1								Equ 16
VT_UI1								Equ 17
VT_UI2								Equ 18
VT_UI4								Equ 19
VT_I8								Equ 20
VT_UI8								Equ 21
VT_INT								Equ 22
VT_UINT								Equ 23
VT_VOID								Equ 24
VT_HRESULT							Equ 25
VT_PTR								Equ 26
VT_SAFEARRAY						Equ 27
VT_CARRAY							Equ 28
VT_USERDEFINED						Equ 29
VT_LPSTR							Equ 30
VT_LPWSTR							Equ 31
VT_RECORD							Equ 36
VT_FILETIME							Equ 64
VT_BLOB								Equ 65
VT_STREAM							Equ 66
VT_STORAGE							Equ 67
VT_STREAMED_OBJECT					Equ 68
VT_STORED_OBJECT					Equ 69
VT_BLOB_OBJECT						Equ 70
VT_CF								Equ 71
VT_CLSID							Equ 72
VT_BSTR_BLOB						Equ 0FFFH
VT_VECTOR							Equ 01000H
VT_ARRAY							Equ 02000H
VT_BYREF							Equ 04000H
VT_RESERVED							Equ 08000H
VT_ILLEGAL							Equ 0FFFFH
VT_ILLEGALMASKED					Equ 0FFFH
VT_TYPEMASK							Equ 0FFFH

;TYSPEC enumeration
TYSPEC_CLSID						Equ 0
TYSPEC_FILEEXT						Equ (TYSPEC_CLSID + 1)
TYSPEC_MIMETYPE						Equ (TYSPEC_FILEEXT + 1)
TYSPEC_PROGID						Equ (TYSPEC_MIMETYPE + 1)
TYSPEC_IID							Equ (TYSPEC_PROGID + 1)
TYSPEC_TYPELIB						Equ (TYSPEC_IID + 1)
TYSPEC_FILENAME						Equ (TYSPEC_TYPELIB + 1)
TYSPEC_JAVACLASS					Equ (TYSPEC_FILENAME + 1)
TYSPEC_PACKAGENAME					Equ (TYSPEC_JAVACLASS + 1)

#Define ACTFLG_RunLocally			1
#Define ACTFLG_RunOnce				2
#Define ACTFLG_SystemWide			4
#Define ACTFLG_Published			8
#Define ACTFLG_Assigned				16
#Define ACTFLG_UserInstall			32

;CLASSPATHTYPE enumeration
ExeNamePath							Equ 0
DllNamePath							Equ (ExeNamePath + 1)
TlbNamePath							Equ (DllNamePath + 1)
CabFilePath							Equ (TlbNamePath + 1)
InfFilePath							Equ (CabFilePath + 1)
DrwFilePath							Equ (InfFilePath + 1)
SetupNamePath						Equ (DrwFilePath + 1)


RemHGLOBAL Struct
	fNullHGlobal DD
	cbData DD
	data DB
EndS

RemHMETAFILEPICT Struct
	mm DD
	xExt DD
	yExt DD
	cbData DD
	data DB
EndS

RemHENHMETAFILE Struct
	cbData DD
	data DB
EndS

RemHBITMAP Struct tagRemHBITMAP
	cbData DD
	data DB
EndS

RemHPALETTE Struct
	cbData DD
	data DB
EndS

RemHBRUSH Struct tagRemBRUSH
	cbData DD
	data DB
EndS

PALETTEENTRY Struct
	peRed DB
	peGreen DB
	peBlue DB
	peFlags DB
EndS

LOGPALETTE Struct
	palVersion DW
	palNumEntries DW
	palPalEntry PALETTEENTRY <>
EndS

#IFNDEF WINDEF_INC
	RECT Struct
		left DD
		top DD
		right DD
		bottom DD
	EndS

	RECTL Struct
		left DD
		top DD
		right DD
		bottom DD
	EndS

	POINT Struct
		x DD
		y DD
	EndS

	POINTL Struct
		x DD
		y DD
	EndS

	SIZE Struct
		lx DD
		cy DD
	EndS

	SIZEL Struct
		lx DD
		cy DD
	EndS
#ENDIF

#IF 0
	LARGE_INTEGER Struct
		QuadPart DQ
	EndS

	ULARGE_INTEGER Struct
		QuadPart DQ
	EndS
#ENDIF

#IFNDEF WINBASE_INC
	FILETIME Struct
		dwLowDateTime DD
		dwHighDateTime DD
	EndS

	SYSTEMTIME Struct
		wYear DW
		wMonth DW
		wDayOfWeek DW
		wDay DW
		wHour DW
		wMinute DW
		wSecond DW
		wMilliseconds DW
	EndS
#ENDIF

#IFNDEF WINNT_INC
	SECURITY_DESCRIPTOR Struct
		Revision DB
		Sbz1 DB
		Control DW
		Owner DD
		Group DD
		Sacl DD
		Dacl DD
	EndS

	ACL Struct
		AclRevision DB
		Sbz1 DB
		AclSize DW
		AceCount DW
		Sbz2 DW
	EndS
#ENDIF

COAUTHIDENTITY Struct
	User DD
	UserLength DD
	Domain DD
	DomainLength DD
	Password DD
	PasswordLength DD
	Flags DD
EndS

COAUTHINFO Struct
	dwAuthnSvc DD
	dwAuthzSvc DD
	pwszServerPrincName DD
	dwAuthnLevel DD
	dwImpersonationLevel DD
	pAuthIdentityData DD
	dwCapabilities DD
EndS

#IFNDEF GUID_DEFINED
	#Define GUID_DEFINED
	GUID Struct
		Data1 DD
		Data2 DW
		Data3 DW
		Data4 DB 8 Dup ?
	EndS
#ENDIF

#IFNDEF OBJECTID_DEFINED
	#Define OBJECTID_DEFINED
	OBJECTID Struct
		Lineage GUID <>
		Uniquifier DD
	EndS
#ENDIF

BYTE_BLOB Struct
	clSize DD
	byte abData DB
EndS

WORD_BLOB Struct
	clSize DD
	asData DW
EndS

DWORD_BLOB Struct
	clSize DD
	alData DD
EndS

FLAGGED_BYTE_BLOB Struct
	fFlags DD
	clSize  DD
	abData DB
EndS

FLAGGED_WORD_BLOB Struct
	fFlags DD
	clSize DD
	asData DW
EndS

BYTE_SIZEDARR Struct
	clSize DD
	pData DD
EndS

WORD_SIZEDARR Struct
	clSize DD
	pData DD
EndS

DWORD_SIZEDARR Struct
	clSize DD
	pData DD
EndS

HYPER_SIZEDARR Struct
	clSize DD
	pData DD
EndS

userCLIPFORMAT Struct
	fContext DD
	u Union
		dwValue DD
		pwszName DD
	EndUnion
EndS

GDI_NONREMOTE Struct
	fContext DD
	u Union
		hInproc DD
		hRemote DD
	EndUnion
EndS

userHGLOBAL Struct
	fContext DD
	u Union
		hInproc DD
		hRemote DD
		hGlobal DD
	EndUnion
EndS

userHMETAFILE Struct
	fContext DD
	u Union
		hInproc DD
		hRemote DD
		hGlobal DD
	EndUnion
EndS

remoteMETAFILEPICT Struct
	mm DD
	xExt DD
	yExt DD
	hMF DD
EndS

userHMETAFILEPICT Struct
	fContext DD
	u Union
		hInproc DD
		hRemote DD
		hGlobal DD
	EndUnion
EndS

userHENHMETAFILE Struct
	fContext DD
	u Union
		hInproc DD
		hRemote DD
		hGlobal DD
	EndUnion
EndS

userBITMAP Struct
	bmType DD
	bmWidth DD
	bmHeight DD
	bmWidthBytes DD
	bmPlanes DW
	bmBitsPixel DW
	cbSize DD
	pBuffer DB 1
EndS

userHBITMAP Struct
	fContext DD
	u Union
		hInproc DD
		hRemote DD
		hGlobal DD
	EndUnion
EndS

rpcLOGPALETTE Struct
    WORD palVersion;
    WORD palNumEntries ;
	palPalEntry PALETTEENTRY <>
EndS

userHPALETTE Struct
	fContext DD
	u Union
		hInproc DD
		hRemote DD
		hGlobal DD
	EndUnion
EndS

RemotableHandle Struct
	fContext DD
	u Union
		hInproc DD
		hRemote DD
	EndUnion
EndS

#IF 0
	TEXTMETRICW Struct
		tmHeight DD
		tmAscent DD
		tmDescent DD
		tmInternalLeading DD
		tmExternalLeading DD
		tmAveCharWidth DD
		tmMaxCharWidth DD
		tmWeight DD
		tmOverhang DD
		tmDigitizedAspectX DD
		tmDigitizedAspectY DD
		tmFirstChar DW
		tmLastChar DW
		tmDefaultChar DW
		tmBreakChar DW
		tmItalic DB
		tmUnderlined DB
		tmStruckOut DB
		tmPitchAndFamily DB
		tmCharSet DB
	EndS
#ENDIF

#IFNDEF MSG
	MSG Struct
		hwnd DD
		message DD
		wParam DD
		lParam DD
		time DD
		pt POINT <>
	EndS
#ENDIF

#IF 0
	CY Struct
		int64 DQ
	EndS
#ELSE
	CY Union
	    Struct
			Lo DD
			Hi DD
		EndS
		int64 DQ
	EndUnion
#ENDIF

#IF 0
	DECIMAL Struct
		wReserved DW
		scale DB
		sign DB
		Hi32 DD
		Lo64 DQ
	EndS
#ELSE
	DECIMAL Struct
		wReserved DW
		Union
			Struct
				scale DB
				sign DB
			EndS
			signscale DW
		EndUnion
		Hi32 DD
		Union
			Struct
				Lo32 DD
				Mid32 DD
			EndS
		Lo64 DQ
		EndUnion
	EndS
#ENDIF

BSTRBLOB Struct
	cbSize DD
	pData DD
EndS

#IFNDEF BLOB_DEFINED
	#Define BLOB_DEFINED
	BLOB Struct
		cbSize DD
		pBlobData DD
	EndS
#ENDIF

CLIPDATA Struct
	cbSize DD
	ulClipFmt DD
	pClipData DD
EndS

#IFNDEF SID_IDENTIFIER_AUTHORITY_DEFINED
	#Define SID_IDENTIFIER_AUTHORITY_DEFINED
	SID_IDENTIFIER_AUTHORITY Struct
	    Value DB 6 Dup ?
	EndS
#ENDIF

#IFNDEF SID_DEFINED
	#Define SID_DEFINED
	SID Struct
		Revision DB
		SubAuthorityCount DB
		IdentifierAuthority SID_IDENTIFIER_AUTHORITY <>
		SubAuthority DD ANYSIZE_ARRAY Dup ?
	EndS
#ENDIF

CSPLATFORM Struct
	dwPlatformId DD
	dwVersionHi DD
	dwVersionLo DD
	dwProcessorArch DD
EndS

QUERYCONTEXT Struct
	dwContext DD
	Platform CSPLATFORM <>
	Locale DD
	dwVersionHi DD
	dwVersionLo DD
EndS

uCLSSPEC Struct
	tyspec DD
	tagged_union Union
		clsid DD
		iid DD
		typelibID GUID <>
		pFileExt DD
		pMimeType DD
		pProgId DD
		pFileName DD
		pJavaClassName DD
		pPackageName DD
	EndUnion
EndS

PUBLISHEDAPPINFO Struct
	pwszFileExtension DD
	pwszDisplayName DD
	pwszPackagePath DD
EndS

APPDETAIL Struct
	AppID GUID <>
	cClasses DD
	prgClsIdList DD
	cTypeLibIds DD
	prgTypeLibIdList DD
	cServers DD
	prgServerNames DD
EndS

PACKAGEDETAIL Struct
	PathType DD
	pszPath DD
	pszIconPath DD
	pszSetupCommand DD
	dwActFlags DD
	pszVendor DD
	pszPackageName DD
	pszProductName DD
	dwContext DD
	Platform CSPLATFORM <>
	Locale DD
	dwVersionHi DD
	dwVersionLo DD
	Usn DQ
	cApps DD
	pAppDetail DD
EndS

PACKAGEINFO Struct
	pszClassIconPath DD
	pTreatAsClsid DD
	cPackages DD
	pPackageDetail DD
EndS

#ENDIF ;WTYPES_INC
