;=============================================================;
;          objidl.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF OBJIDL_INC
#Define OBJIDL_INC

;SRVINFO enumeration
SRVINFO_F_COSERVERINFO				Equ 0
SRVINFO_F_COSERVERINFO2				Equ 1

;EXTCONN enumeration
EXTCONN_STRONG						01H
EXTCONN_WEAK						02H
EXTCONN_CALLABLE					04H

;BIND_FLAGS enumeration
BIND_MAYBOTHERUSER					Equ 1
BIND_JUSTTESTEXISTENCE				Equ 2

;MKSYS enumeration
MKSYS_NONE							Equ 0
MKSYS_GENERICCOMPOSITE				Equ 1
MKSYS_FILEMONIKER					Equ 2
MKSYS_ANTIMONIKER					3
MKSYS_ITEMMONIKER					4
MKSYS_POINTERMONIKER				5
MKSYS_CLASSMONIKER					7

;MKRREDUCE enumeration
MKRREDUCE_ONE						Equ 03000H
MKRREDUCE_TOUSER					Equ 02000H
MKRREDUCE_THROUGHUSER				Equ 01000H
MKRREDUCE_ALL						Equ 0

;STGTY enumeration
STGTY_STORAGE						Equ 1
STGTY_STREAM						Equ 2
STGTY_LOCKBYTES						Equ 3
STGTY_PROPERTY						Equ 4

;STREAM_SEEK enumeration
STREAM_SEEK_SET						Equ 0
STREAM_SEEK_CUR						Equ 1
STREAM_SEEK_END						Equ 2

;LOCKTYPE enumeration
LOCK_WRITE							Equ 1
LOCK_EXCLUSIVE						Equ 2
LOCK_ONLYONCE						Equ 4

;ADVF enumeration
ADVF_NODATA							Equ 1
ADVF_PRIMEFIRST						Equ 2
ADVF_ONLYONCE						Equ 4
ADVF_DATAONSTOP						Equ 64
ADVFCACHE_NOHANDLER					Equ 8
ADVFCACHE_FORCEBUILTIN				Equ 16
ADVFCACHE_ONSAVE					Equ 2

;TYMED enumeration
TYMED_HGLOBAL						Equ 1
TYMED_FILE							Equ 2
TYMED_ISTREAM						Equ 4
TYMED_ISTORAGE						Equ 8
TYMED_GDI							Equ 6
TYMED_MFPICT						Equ 32
TYMED_ENHMF							Equ 64
TYMED_NULL							0

;DATADIR enumeration
DATADIR_GET							Equ 1
DATADIR_SET							Equ 2

;CALLTYPE enumeration
CALLTYPE_TOPLEVEL					Equ 1
CALLTYPE_NESTED						Equ 2
CALLTYPE_ASYNC						Equ 3
CALLTYPE_TOPLEVEL_CALLPENDING		Equ 4
CALLTYPE_ASYNC_CALLPENDING			Equ 5

;SERVERCALL enumeration
SERVERCALL_ISHANDLED				Equ 0
SERVERCALL_REJECTED					Equ 1
SERVERCALL_RETRYLATER				Equ 2

;PENDINGTYPE enumeration
PENDINGTYPE_TOPLEVEL				Equ 1
PENDINGTYPE_NESTED					Equ 2

;PENDINGMSG enumeration
PENDINGMSG_CANCELCALL				Equ 0
PENDINGMSG_WAITNOPROCESS			Equ 1
PENDINGMSG_WAITDEFPROCESS			Equ 2

#Define PROPSETFLAG_DEFAULT			0
#Define PROPSETFLAG_NONSIMPLE		1
#Define PROPSETFLAG_ANSI			2
#Define PROPSETFLAG_UNBUFFERED		4

#Define PID_DICTIONARY				0
#Define PID_CODEPAGE				01H
#Define PID_FIRST_USABLE			02H
#Define PID_FIRST_NAME_DEFAULT		0FFFH
#Define PID_LOCALE					080000000H
#Define PID_MODIFY_TIME				080000001H
#Define PID_SECURITY				080000002H
#Define PID_ILLEGAL					0FFFFFFFFH

#Define PIDSI_TITLE               	000000002H
#Define PIDSI_SUBJECT             	000000003H
#Define PIDSI_AUTHOR              	000000004H
#Define PIDSI_KEYWORDS            	000000005H
#Define PIDSI_COMMENTS            	000000006H
#Define PIDSI_TEMPLATE            	000000007H
#Define PIDSI_LASTAUTHOR          	000000008H
#Define PIDSI_REVNUMBER           	000000009H
#Define PIDSI_EDITTIME            	00000000AH
#Define PIDSI_LASTPRINTED         	00000000BH
#Define PIDSI_CREATE_DTM          	00000000CH
#Define PIDSI_LASTSAVE_DTM        	00000000DH
#Define PIDSI_PAGECOUNT           	00000000EH
#Define PIDSI_WORDCOUNT           	00000000FH
#Define PIDSI_CHARCOUNT           	000000010H
#Define PIDSI_THUMBNAIL           	000000011H
#Define PIDSI_APPNAME             	000000012H
#Define PIDSI_DOC_SECURITY        	000000013H

#Define PRSPEC_INVALID				0FFFFFFFFH
#Define PRSPEC_LPWSTR				0
#Define PRSPEC_PROPID				1

;EOLE_AUTHENTICATION_CAPABILITIES enumeration
EOAC_NONE							Equ 0
EOAC_MUTUAL_AUTH					Equ 01H
EOAC_CLOAKING						Equ 010H
EOAC_SECURE_REFS					Equ 02H
EOAC_ACCESS_CONTROL					Equ 04H
EOAC_APPID							Equ 08H

;__MIDL___MIDL_itf_objidl_0052_0001 enumeration
COMBND_RPCSTRINGS					Equ 01H

;DCOM_CALL_STATE enumeration
DCOM_NONE							Equ 0
DCOM_CALL_COMPLETE					Equ 01H
DCOM_CALL_CANCELED					Equ 02H


COSERVERINFO Struct
	dwReserved1 DD
	pwszName DD
	pAuthInfo DD
	dwReserved2 DD
EndS

COSERVERINFO2 Struct
	dwFlags DD
	pwszName DD
	pAuthInfo DD
	ppCall DD
	pwszCodeURL DD
	dwFileVersionMS DD
	dwFileVersionLS DD
	pwszContentType DD
EndS

#IFNDEF Unknown
	Unknown Struct
	   QueryInterface DD
	   AddRef DD
	   Release DD
	EndS
#ENDIF

MULTI_QI Struct
	pIID DD
	pItf DD
	hr DD
EndS

BIND_OPTS Struct
	cbStruct DD
	grfFlags DD
	grfMode DD
	dwTickCountDeadline DD
EndS

BIND_OPTS2 Struct
	cbStruct DD
	grfFlags DD
	grfMode DD
	dwTickCountDeadline DD
	dwTrackFlags DD
	dwClassContext DD
	locale DD
	pServerInfo DD
EndS

STATSTG Struct
	pwcsName DD
	type DD
	cbSize DD
	mtime FILETIME <>
	ctime FILETIME <>
	atime FILETIME <>
	grfMode DD
	grfLocksSupported DD
	clsid GUID <>
	grfStateBits DD
	reserved DD
EndS

RemSNB Struct
	ulCntStr DD
	ulCntChar DD
	rgString DW
EndS

DVTARGETDEVICE Struct
	tdSize DD
	tdDriverNameOffset DW
	tdDeviceNameOffset DW
	tdPortNameOffset DW
	tdExtDevmodeOffset DW
	tdData DB
EndS

FORMATETC Struct
	cfFormat DD
	ptd DD
	dwAspect DD
	lindex DD
	tymed DD
EndS

STATDATA Struct
	FORMATETC FORMATETC <>
	advf DD
	pAdvSink DD
	dwConnection DD
EndS

remSTGMEDIUM Struct
	tymed DD
	dwHandleType DD
	pData DD
	pUnkForRelease DD
	cbData DD
	data DB
EndS

STGMEDIUM Struct
	tymed DD
	Union
		hBitmap DD
		hMetaFilePict DD
		hEnhMetaFile DD
		hGlobal DD
		lpszFileName DD
		pstm DD
		pstg DD
	EndUnion
	pUnkForRelease DD
EndS

GDI_OBJECT Struct
	ObjectType DD
	Union ;u
		hBitmap DD
		hPalette DD
		hGeneric DD
	EndUnion
EndS

userSTGMEDIUM Struct
	tymed DD
	Union ;u
		hMetaFilePict DD
		hHEnhMetaFile DD
		hGdiHandle DD
		hGlobal DD
		lpszFileName DD
		pstm DD
		pstg DD
   	EndUnion
	pUnkForRelease DD
EndS

userFLAG_STGMEDIUM Struct
	ContextFlags DD
	fPassOwnership DD
	Stgmed userSTGMEDIUM <>
EndS

FLAG_STGMEDIUM Struct
	ContextFlags DD
	fPassOwnership DD
	Stgmed STGMEDIUM <>
EndS

INTERFACEINFO Struct
	pUnk DD
    iid GUID <>
	wMethod DW
EndS

RPCOLEMESSAGE Struct
	reserved1 DD
	dataRepresentation DD
	Buffer DD
	cbBuffer DD
	iMethod DD
	reserved2 DD 5 Dup ?
	rpcFlags DD
EndS

SChannelHookCallInfo Struct
	iid GUID <>
	cbSize DD
	uCausality GUID <>
	dwServerPid DD
	iMethod DD
	pObject DD
EndS

CAUB Struct
	cElems DD
	pElems DD
EndS

CAI Struct
	cElems DD
	pElems DD
EndS

CAUI Struct
	cElems DD
	pElems DD
EndS

CAL Struct
	cElems DD
	pElems DD
EndS

CAUL Struct
	cElems DD
	pElems DD
EndS

CAFLT Struct
	cElems DD
	pElems DD
EndS

CADBL Struct
	cElems DD
	pElems DD
EndS

CACY Struct
	cElems DD
	pElems DD
EndS

CADATE Struct
	cElems DD
	pElems DD
EndS

CABSTR Struct
	cElems DD
	pElems DD
EndS

CABSTRBLOB Struct
	cElems DD
	pElems DD
EndS

CABOOL Struct
	cElems DD
	pElems DD
EndS

CASCODE Struct
	cElems DD
	pElems DD
EndS

CAPROPVARIANT Struct
	cElems DD
	pElems DD
EndS

CAH Struct
	cElems DD
	pElems DD
EndS

CAUH Struct
	cElems DD
	pElems DD
EndS

CALPSTR Struct
	cElems DD
	pElems DD
EndS

CALPWSTR Struct
	cElems DD
	pElems DD
EndS

CAFILETIME Struct
	cElems DD
	pElems DD
EndS

CACLIPDATA Struct
	cElems DD
	pElems DD
EndS

CACLSID Struct
	cElems DD
	pElems DD
EndS

PROPSPEC Struct
	ulKind DD
	Union
		propid DD
		lpwstr DD
	EndUnion
EndS

STATPROPSTG Struct
	lpwstrName DD
	propid DD
	vt DW
EndS

STATPROPSETSTG Struct
	fmtid GUID <>
    clsid GUID <>
	grfFlags DD
	mtime FILETIME <>
	ctime FILETIME <>
	atime FILETIME <>
	dwOSVersion DD
EndS

SOLE_AUTHENTICATION_SERVICE Struct
	dwAuthnSvc DD
	dwAuthzSvc DD
	pPrincipalName DD
	hr DD
EndS

StorageLayout Struct
	LayoutType DD
	pwcsElementName DD
	cOffset LARGE_INTEGER <>
	cBytes LARGE_INTEGER <>
EndS

PUBLISHEDINFOLIST Struct
	cPublApps DD
	pPublAppInfo DD
EndS

PACKAGEINFOLIST Struct
	cPackInfo DD
	pPackageInfo DD
EndS

CLASSDETAIL Struct
	Clsid GUID <>
	pszDesc DD
	pszIconPath DD
	TreatAsClsid GUID <>
	AutoConvertClsid GUID <>
	cFileExt DD
	prgFileExt DD
	pMimeType DD
	pDefaultProgId DD
	cOtherProgId DD
	prgOtherProgId DD
EndS

#ENDIF ;OBJIDL_INC
