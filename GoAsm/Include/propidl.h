
#ifndef PROPIDL_H
#define PROPIDL_H

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
#endif /* COM_NO_WINDOWS_H */

#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

VersionedStream STRUCT
	guidVersion GUID
	pStream PTR
ENDS

#define PROPSETFLAG_DEFAULT  0
#define PROPSETFLAG_NONSIMPLE  1
#define PROPSETFLAG_ANSI  2
#define PROPSETFLAG_UNBUFFERED  4
#define PROPSETFLAG_CASE_SENSITIVE  8

#define PROPSET_BEHAVIOR_CASE_SENSITIVE  1

CAC STRUCT
	cElems DD
	pElems PTR
ENDS

/*
typedef struct tagCAC
    {
    ULONG cElems;
    CHAR *pElems;
    } 	CAC;

typedef struct tagCAUB
    {
    ULONG cElems;
    UCHAR *pElems;
    } 	CAUB;

typedef struct tagCAI
    {
    ULONG cElems;
    SHORT *pElems;
    } 	CAI;

typedef struct tagCAUI
    {
    ULONG cElems;
    USHORT *pElems;
    } 	CAUI;

typedef struct tagCAL
    {
    ULONG cElems;
    LONG *pElems;
    } 	CAL;

typedef struct tagCAUL
    {
    ULONG cElems;
    ULONG *pElems;
    } 	CAUL;

typedef struct tagCAFLT
    {
    ULONG cElems;
    FLOAT *pElems;
    } 	CAFLT;

typedef struct tagCADBL
    {
    ULONG cElems;
    DOUBLE *pElems;
    } 	CADBL;

typedef struct tagCACY
    {
    ULONG cElems;
    CY *pElems;
    } 	CACY;

typedef struct tagCADATE
    {
    ULONG cElems;
    DATE *pElems;
    } 	CADATE;

typedef struct tagCABSTR
    {
    ULONG cElems;
    BSTR *pElems;
    } 	CABSTR;

typedef struct tagCABSTRBLOB
    {
    ULONG cElems;
    BSTRBLOB *pElems;
    } 	CABSTRBLOB;

typedef struct tagCABOOL
    {
    ULONG cElems;
    VARIANT_BOOL *pElems;
    } 	CABOOL;

typedef struct tagCASCODE
    {
    ULONG cElems;
    SCODE *pElems;
    } 	CASCODE;

typedef struct tagCAPROPVARIANT
    {
    ULONG cElems;
    PROPVARIANT *pElems;
    } 	CAPROPVARIANT;

typedef struct tagCAH
    {
    ULONG cElems;
    LARGE_INTEGER *pElems;
    } 	CAH;

typedef struct tagCAUH
    {
    ULONG cElems;
    ULARGE_INTEGER *pElems;
    } 	CAUH;

typedef struct tagCALPSTR
    {
    ULONG cElems;
    LPSTR *pElems;
    } 	CALPSTR;

typedef struct tagCALPWSTR
    {
    ULONG cElems;
    LPWSTR *pElems;
    } 	CALPWSTR;

typedef struct tagCAFILETIME
    {
    ULONG cElems;
    FILETIME *pElems;
    } 	CAFILETIME;

typedef struct tagCACLIPDATA
    {
    ULONG cElems;
    CLIPDATA *pElems;
    } 	CACLIPDATA;

typedef struct tagCACLSID
    {
    ULONG cElems;
    CLSID *pElems;
    } 	CACLSID;

*/



#define CAUB CAC
#define CAI CAC
#define CAUI CAC
#define CAUL CAC
#define CAFLT CAC
#define CADBL CAC
#define CACY CAC
#define CADATE CAC
#define CASTR CAC
#define CASTRBLOB CAC
#define CABOOL CAC
#define CASCODE CAC
#define CAPROPVARIANT CAC
#define CAH CAC
#define CAUH CAC
#define CALPSTR CAC
#define CALPWSTR CAC
#define CAFILETIME CAC
#define CACLIPDATA CAC
#define CACLSID CAC

#define PID_DICTIONARY  0
#define PID_CODEPAGE  0x1
#define PID_FIRST_USABLE  0x2
#define PID_FIRST_NAME_DEFAULT  0xfff
#define PID_LOCALE  0x80000000
#define PID_MODIFY_TIME  0x80000001
#define PID_SECURITY  0x80000002
#define PID_BEHAVIOR  0x80000003
#define PID_ILLEGAL  0xffffffff
#define PID_MIN_READONLY  0x80000000
#define PID_MAX_READONLY  0xbfffffff

#define PIDDI_THUMBNAIL  0x00000002

#define PIDSI_TITLE  0x00000002
#define PIDSI_SUBJECT  0x00000003
#define PIDSI_AUTHOR  0x00000004
#define PIDSI_KEYWORDS  0x00000005
#define PIDSI_COMMENTS  0x00000006
#define PIDSI_TEMPLATE  0x00000007
#define PIDSI_LASTAUTHOR  0x00000008
#define PIDSI_REVNUMBER  0x00000009
#define PIDSI_EDITTIME  0x0000000a
#define PIDSI_LASTPRINTED  0x0000000b
#define PIDSI_CREATE_DTM  0x0000000c
#define PIDSI_LASTSAVE_DTM  0x0000000d
#define PIDSI_PAGECOUNT  0x0000000e
#define PIDSI_WORDCOUNT  0x0000000f
#define PIDSI_CHARCOUNT  0x00000010
#define PIDSI_THUMBNAIL  0x00000011
#define PIDSI_APPNAME  0x00000012
#define PIDSI_DOC_SECURITY  0x00000013

#define PIDDSI_CATEGORY  0x00000002
#define PIDDSI_PRESFORMAT  0x00000003
#define PIDDSI_BYTECOUNT  0x00000004
#define PIDDSI_LINECOUNT  0x00000005
#define PIDDSI_PARCOUNT  0x00000006
#define PIDDSI_SLIDECOUNT  0x00000007
#define PIDDSI_NOTECOUNT  0x00000008
#define PIDDSI_HIDDENCOUNT  0x00000009
#define PIDDSI_MMCLIPCOUNT  0x0000000A
#define PIDDSI_SCALE  0x0000000B
#define PIDDSI_HEADINGPAIR  0x0000000C
#define PIDDSI_DOCPARTS  0x0000000D
#define PIDDSI_MANAGER  0x0000000E
#define PIDDSI_COMPANY  0x0000000F
#define PIDDSI_LINKSDIRTY  0x00000010

#define PIDMSI_EDITOR  0x00000002
#define PIDMSI_SUPPLIER  0x00000003
#define PIDMSI_SOURCE  0x00000004
#define PIDMSI_SEQUENCE_NO  0x00000005
#define PIDMSI_PROJECT  0x00000006
#define PIDMSI_STATUS  0x00000007
#define PIDMSI_OWNER  0x00000008
#define PIDMSI_RATING  0x00000009
#define PIDMSI_PRODUCTION  0x0000000A
#define PIDMSI_COPYRIGHT  0x0000000B

PIDMSI_STATUS_NORMAL = 0
PIDMSI_STATUS_NEW = PIDMSI_STATUS_NORMAL + 1
PIDMSI_STATUS_PRELIM = PIDMSI_STATUS_NORMAL + 2
PIDMSI_STATUS_DRAFT = PIDMSI_STATUS_NORMAL + 3
PIDMSI_STATUS_INPROGRESS = PIDMSI_STATUS_NORMAL + 4
PIDMSI_STATUS_EDIT = PIDMSI_STATUS_NORMAL + 5
PIDMSI_STATUS_REVIEW = PIDMSI_STATUS_NORMAL + 6
PIDMSI_STATUS_PROOF = PIDMSI_STATUS_NORMAL + 7
PIDMSI_STATUS_FINAL = PIDMSI_STATUS_NORMAL + 8
PIDMSI_STATUS_OTHER = 0x7fff

#define PRSPEC_INVALID  0xffffffff
#define PRSPEC_LPWSTR  0
#define PRSPEC_PROPID  1

PROPSPEC STRUCT
	ulKind DD
	UNION
		propid DD
		lpwstr PTR
	ENDUNION
ENDS

STATPROPSTG STRUCT
	lpwstrName PTR
	propid DD
	vt DD
ENDS

#define PROPSETHDR_OSVERSION_UNKNOWN  0xFFFFFFFF

STATPROPSETSTG STRUCT
	fmtid DD
	clsid GUID
	grfFlags DD
	mtime FILETIME
	ctime FILETIME
	atime FILETIME
	dwOSVersion DD
ENDS

PROPVARIANT UNION
	STRUCT
		vt VARTYPE
		wReserved1 DW
		wReserved2 DW
		wReserved3 DW
		UNION
			cVal CHAR
			bVal CHAR 
			iVal SHORT
			uiVal SHORT
			lVal LONG
			ulVal LONG
			intVal INT32
			uintVal INT32
			hVal LARGE_INTEGER
			uhVal LARGE_INTEGER
			fltVal FLOAT
			dblVal DOUBLE
			boolVal VARIANT_BOOL
			bool VARIANT_BOOL // Deprecated
			scode LONG // SCODE
			cyVal DQ
			date DATE
			filetime FILETIME
			puuid PTR
			pclipdata PTR
			bstrVal PTR
			bstrblobVal BSTRBLOB
			blob BLOB
			pszVal PTR
			pwszVal PTR
			punkVal PTR
			pdispVal PTR
			pStream PTR
			pStorage PTR
			pVersionedStream PTR
			parray PTR
			cac CAC <>
			caub CAC <>
			cai CAC <>
			caui CAC <>
			cal CAC <>
			caul CAC <>
			cah CAC <>
			cauh CAC <>
			caflt CAC <>
			cadbl CAC <>
			cabool CAC <>
			cascode CAC <>
			cacy CAC <>
			cadate CAC <>
			cafiletime CAC <>
			cauuid CAC <>
			caclipdata CAC <>
			cabstr CAC <>
			cabstrblob CAC <>
			calpstr CAC <>
			calpwstr CAC <>
			capropvar CAC <>
			pcVal PTR
			pbVal PTR
			piVal PTR
			puiVal PTR
			plVal PTR
			pulVal PTR
			pintVal PTR
			puintVal PTR
			pfltVal PTR
			pdblVal PTR
			pboolVal PTR
			pdecVal PTR
			pscode PTR
			pcyVal PTR
			pdate PTR
			pbstrVal PTR
			ppunkVal PTR
			ppdispVal PTR
			pparray PTR
			pvarVal PTR
		ENDS
	ENDS
	decVal DECIMAL
ENDS

#define GUID_IID_IPropertyStorage <0x00000138,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IPropertyStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ReadMultiple PTR
	WriteMultiple PTR
	DeleteMultiple PTR
	ReadPropertyNames PTR
	WritePropertyNames PTR
	DeletePropertyNames PTR
	Commit PTR
	Revert PTR
	Enum PTR
	SetTimes PTR
	SetClass PTR
	Stat PTR
ENDS

#define GUID_IID_IPropertySetStorage <0x0000013A,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IPropertySetStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Create PTR
	Open PTR
	Delete PTR
	Enum PTR
ENDS

#define GUID_IID_IEnumSTATPROPSTG <0x00000139,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IEnumSTATPROPSTG STRUCT
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


#define GUID_IID_IEnumSTATPROPSETSTG <0x0000013B,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IEnumSTATPROPSETSTG STRUCT
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

#endif /* _PROPIDL_H */
