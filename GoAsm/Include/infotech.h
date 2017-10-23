#ifndef INFOTECH_H
#define INFOTECH_H

#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF

// {1F403BB1-9997-11d0-A850-00AA006C7D01}
#DEFINE GUID_IID_IITPropList <0x1f403bb1, 0x9997, 0x11d0, <0xa8, 0x50, 0x0, 0xaa, 0x0, 0x6c, 0x7d, 0x1>>

// {4662daae-d393-11d0-9a56-00c04fb68bf7}
#DEFINE GUID_CLSID_IITPropList <0x4662daae, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// Operations you can do on a property
#define PROP_ADD    0x00000000
#define PROP_DELETE 0x00000001
#define PROP_UPDATE 0x00000002

// Type of data
#define TYPE_VALUE   0x00000000
#define TYPE_POINTER 0x00000001
#define TYPE_STRING  0x00000002

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

// Class definition of CProperty
CProperty STRUCT
	dwPropID DD        // property ID
	cbData DD           // Amount of data
	dwType DD           // What type this is
	UNION
		lpszwData PTR   // String
		lpvData PTR     // Any kind of data
		dwValue PTR     // Numerical data
	ENDUNION
	fPersist DD          // TRUE to persist this property
ENDS

// Interface def. for IITPropList
IITPropList STRUCT
	//IPersistStreamInit
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	IsDirty PTR
	Load PTR
	Save PTR
	GetSizeMax PTR
	InitNew PTR
	//IITPropList
	Set STRUCT
		PTR
		PTR
		PTR
	ENDS
	Add PTR
	Get PTR
	Clear PTR
	SetPersist STRUCT
		PTR
		PTR
	ENDS
	GetFirst PTR
	GetNext PTR
	GetPropCount PTR
	SaveHeader PTR
	SaveData PTR
	GetHeaderSize PTR
	GetDataSize PTR
	SaveDataToStream PTR
	LoadFromMem PTR
	SaveToMem PTR
ENDS

// {8fa0d5a2-dedf-11d0-9a61-00c04fb68bf7} (changed from IT 3.0)
#DEFINE GUID_IID_IITDatabase <0x8fa0d5a2, 0xdedf, 0x11d0, <0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

#ifdef ITPROXY
	// {66673452-8C23-11d0-A84E-00AA006C7D01}
	#DEFINE GUID_CLSID_IITDatabase <0x66673452, 0x8c23, 0x11d0, <0xa8, 0x4e, 0x0, 0xaa, 0x0, 0x6c, 0x7d, 0x1>>
#else
	// {4662daa9-d393-11d0-9a56-00c04fb68bf7} (changed from IT 3.0)
	#DEFINE GUID_CLSID_IITDatabaseLocal <0x4662daa9, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>
#endif	// ITPROXY


// This value is invalid for dwObjInstance params in IITDatabase methods.
#define	IITDB_OBJINST_NULL 0xFFFFFFFF


IITDatabase STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Open PTR
	Close PTR

	// Creates an unnamed object that can be referenced in the future
	// by *pdwObjInstance.  Note that the value in *pdwObjInstance will be
	// persisted by the database when it is asked to save

	CreateObject PTR

	// Retrieves a specified IUnknown-based interface on the object identified
	// by dwObjInstance.
	GetObject PTR

	// To obtain a pointer to a named object's persistence the object's full
	// name (including any object-specific type prefix) should be passed in
	// lpswszObject.  If *lpwszObject is NULL, then the database's own storage
	// will be returned.  If lpwszObject is NULL, then dwObjInstance will be
	// used to identify the object and locate its persistence.  On exit,
	// *ppvPersistence will be either an IStorage* or an IStream*, depending
	// on what the caller specified with the fStream param.  The caller should
	// assume that only read operations can be performed on *ppvPersistence.
	// If the specified object's persistence doesn't exist, or if it exists
	// but is of the wrong type, then STG_E_FILENOTFOUND will be returned. 
	GetObjectPersistence PTR
ENDS

// Document property macros
#define STDPROP_UID         1
#define STDPROP_TITLE       2
#define STDPROP_USERDATA    3
#define STDPROP_KEY         4

#define STDPROP_SORTKEY		100
#define STDPROP_DISPLAYKEY	101
#define STDPROP_SORTORDINAL 102

#define STDPROP_INDEX_TEXT    200
#define STDPROP_INDEX_VFLD    201
#define STDPROP_INDEX_DTYPE   202
#define STDPROP_INDEX_LENGTH  203
#define STDPROP_INDEX_BREAK   204

#define STDPROP_INDEX_TERM              210
#define STDPROP_INDEX_TERM_RAW_LENGTH   211

#define STDPROP_USERPROP_BASE   0x00010000
#define STDPROP_USERPROP_MAX    0x7FFFFFFF

// Property destinations for word wheels
#define SZ_WWDEST_GLOBAL    L"GLOBAL"
#define SZ_WWDEST_KEY       L"KEY"
#define SZ_WWDEST_OCC       L"OCC"


// {4662daa2-d393-11d0-9a56-00c04fb68bf7}
#DEFINE GUID_CLSID_IITCmdInt <0x4662daa2, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// {4662daa3-d393-11d0-9a56-00c04fb68bf7}
#DEFINE GUID_CLSID_IITSvMgr <0x4662daa3, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// {4CF34C30-9BF9-11d0-8764-00A0C913F764}
#DEFINE GUID_IID_IITCmdInt <0x4cf34c30, 0x9bf9, 0x11d0, <0x87, 0x64, 0x0, 0xa0, 0xc9, 0x13, 0xf7, 0x64>>

// {4E7DA031-9C11-11d0-8764-00A0C913F764}
#DEFINE GUID_IID_IITSvMgr <0x4e7da031, 0x9c11, 0x11d0, <0x87, 0x64, 0x0, 0xa0, 0xc9, 0x13, 0xf7, 0x64>>

// {4662daa5-d393-11d0-9a56-00c04fb68bf7}
#DEFINE GUID_CLSID_IITWordWheelUpdate <0x4662daa5, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>
    
// {8fa0d5a5-dedf-11d0-9a61-00c04fb68bf7}
#DEFINE GUID_IID_IITBuildCollect <0x8fa0d5a5, 0xdedf, 0x11d0, <0x9a, 0x61, 0x0, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// {4662daa4-d393-11d0-9a56-00c04fb68bf7}
#DEFINE GUID_CLSID_IITGroupUpdate <0x4662daa4, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// {8fa0d5aa-dedf-11d0-9a61-00c04fb68bf7}
#DEFINE GUID_CLSID_IITIndexBuild <0x8fa0d5aa, 0xdedf, 0x11d0, <0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// {8fa0d5ab-dedf-11d0-9a61-00c04fb68bf7}
#DEFINE GUID_CLSID_IITWWFilterBuild <0x8fa0d5ab, 0xdedf, 0x11d0, <0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// {8fa0d5a4-dedf-11d0-9a61-00c04fb68bf7}
#DEFINE GUID_IID_IITWordWheel <0x8fa0d5a4, 0xdedf, 0x11d0, <0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

#ifdef ITPROXY
	// {D73725C2-8C12-11d0-A84E-00AA006C7D01}
	#DEFINE GUID_CLSID_IITWordWheel <0xd73725c2, 0x8c12, 0x11d0, <0xa8, 0x4e, 0x0, 0xaa, 0x0, 0x6c, 0x7d, 0x1>>
#else
	// {4662daa8-d393-11d0-9a56-00c04fb68bf7}
	#DEFINE GUID_CLSID_IITWordWheelLocal <0x4662daa8, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>
#endif	// ITPROXY

// Word-wheel open flags
#define ITWW_OPEN_CONNECT	0x00000000    // connect to server on open (the default)
#define ITWW_OPEN_NOCONNECT	0x00000001    // don't connect to server on open

// Constants for IITWordWheel::Lookup.
#define ITWW_CBKEY_MAX		1024		// Max size of keys allowed in Word Wheels.

IITWordWheel STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Open PTR
	Close PTR
	GetLocaleInfo PTR
	GetSorterInstance PTR
	Count PTR
	Lookup STRUCT
		PTR
		PTR
		PTR
	ENDS
	SetGroup PTR
	GetGroup PTR
	GetDataCount PTR
	GetData PTR
	GetDataColumns PTR
ENDS

IStemmer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
	GetLicenseToUse PTR
	StemWord PTR
ENDS

IStemSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	PutAltWord PTR
	PutWord PTR
ENDS

IStemmerConfig STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetLocaleInfo PTR
	GetLocaleInfo PTR
	SetControlInfo PTR
	GetControlInfo PTR
	LoadExternalStemmerData PTR
ENDS


TEXT_SOURCE STRUCT
	pfnFillTextBuffer PTR
	awcBuffer PTR
	iEnd DD
	iCur DD
ENDS

IWordBreaker STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
	BreakText PTR
	ComposePhrase PTR
	GetLicenseToUse PTR
ENDS

// Break word types that can be passed to
// IWordBreakerConfig::SetBreakWordType.
#define IITWBC_BREAKTYPE_TEXT 0
#define IITWBC_BREAKTYPE_NUMBER 1
#define IITWBC_BREAKTYPE_DATE 2
#define IITWBC_BREAKTYPE_TIME 3
#define IITWBC_BREAKTYPE_EPOCH 4


// Breaker control flags that can be passed to
// IWordBreakerConfig::SetControlInfo.
#define IITWBC_BREAK_ACCEPT_WILDCARDS	0x00000001  // Interpret wildcard chars as such.
#define IITWBC_BREAK_AND_STEM           0x00000002  // Stem words after breaking them.

// External data types that can be passed to
// IWordBreakerConfig::LoadExternalBreakerData.
#define IITWBC_EXTDATA_CHARTABLE 0	
#define IITWBC_EXTDATA_STOPWORDLIST 1

IWordBreakerConfig STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetLocaleInfo PTR
	GetLocaleInfo PTR
	SetBreakWordType PTR
	GetBreakWordType PTR
	SetControlInfo PTR
	GetControlInfo PTR
	LoadExternalBreakerData PTR
	SetWordStemmer PTR
	GetWordStemmer PTR
ENDS

//
// The InfoTech error codes
//
#define E_NOTEXIST          0x80001000
#define E_DUPLICATE         0x80001001
#define E_BADVERSION        0x80001002
#define E_BADFILE           0x80001003
#define E_BADFORMAT         0x80001004
#define E_NOPERMISSION      0x80001005
#define E_ASSERT            0x80001006
#define E_INTERRUPT         0x80001007
#define E_NOTSUPPORTED      0x80001008
#define E_OUTOFRANGE        0x80001009                  
#define E_GROUPIDTOOBIG     0x8000100A
#define E_TOOMANYTITLES     0x8000100B
#define E_NOMERGEDDATA      0x8000100C
#define E_NOTFOUND          0x8000100D
#define E_CANTFINDDLL       0x8000100E
#define E_NOHANDLE          0x8000100F 
#define E_GETLASTERROR      0x80001010
#define E_BADPARAM          0x80001011
#define E_INVALIDSTATE      0x80001012
#define E_NOTOPEN           0x80001013
#define E_ALREADYOPEN       0x80001013
#define E_UNKNOWN_TRANSPORT 0x80001016
#define E_UNSUPPORTED_TRANSPORT 0x80001017
#define E_BADFILTERSIZE     0x80001018
#define E_TOOMANYOBJECTS    0x80001019
#define E_NAMETOOLONG       0x80001020

#define E_FILECREATE        0x80001030 
#define E_FILECLOSE         0x80001031
#define E_FILEREAD          0x80001032
#define E_FILESEEK          0x80001033
#define E_FILEWRITE         0x80001034
#define E_FILEDELETE        0x80001035
#define E_FILEINVALID       0x80001036
#define E_FILENOTFOUND      0x80001037
#define E_DISKFULL          0x80001038

#define E_TOOMANYTOPICS     0x80001050
#define E_TOOMANYDUPS       0x80001051
#define E_TREETOOBIG        0x80001052
#define E_BADBREAKER        0x80001053
#define E_BADVALUE          0x80001054
#define E_ALL_WILD          0x80001055
#define E_TOODEEP           0x80001056
#define E_EXPECTEDTERM      0x80001057
#define E_MISSLPAREN        0x80001058
#define E_MISSRPAREN        0x80001059
#define E_MISSQUOTE         0x8000105A
#define E_NULLQUERY         0x8000105B
#define E_STOPWORD          0x8000105C
#define E_BADRANGEOP        0x8000105D
#define E_UNMATCHEDTYPE     0x8000105E
#define E_WORDTOOLONG       0x8000105F
#define E_BADINDEXFLAGS     0x80001060
#define E_WILD_IN_DTYPE     0x80001061   
#define E_NOSTEMMER         0x80001062

// Property list and result set errors
#define E_MISSINGPROP       0x80001080
#define E_PROPLISTNOTEMPTY  0x80001081
#define E_PROPLISTEMPTY     0x80001082
#define E_ALREADYINIT       0x80001083
#define E_NOTINIT           0x80001084
#define E_RESULTSETEMPTY    0x80001085
#define E_TOOMANYCOLUMNS    0x80001086
#define E_NOKEYPROP         0x80001087

// ITResultSet interface declaration

// {3BB91D41-998B-11d0-A850-00AA006C7D01}
#DEFINE GUID_IID_IITResultSet <0x3bb91d41, 0x998b, 0x11d0, <0xa8, 0x50, 0x0, 0xaa, 0x0, 0x6c, 0x7d, 0x1>>

// {4662daa7-d393-11d0-9a56-00c04fb68bf7}
#DEFINE GUID_CLSID_IITResultSet <0x4662daa7, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// maximum number of columns in a row set
#define MAX_COLUMNS  256

// Column priorities

PRIORITY_LOW = 0
PRIORITY_NORMAL = 1
PRIORITY_HIGH = 2

ROWSTATUS STRUCT
 	lRowFirst DD
 	cRows DD
 	cProperties DD
 	cRowsTotal DD
ENDS

COLUMNSTATUS STRUCT
 	cPropCount DD
	cPropsLoaded DD
ENDS

IITResultSet STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetColumnPriority PTR
	SetColumnHeap PTR
	SetKeyProp PTR
	Add STRUCT
		PTR
		PTR
		PTR
		PTR
	ENDS
	Append PTR
	Set STRUCT
		PTR
		PTR
		PTR
		PTR
	ENDS
	Copy PTR
	AppendRows PTR 
	Get PTR
	GetKeyProp PTR
	GetColumnPriority PTR
	GetRowCount PTR
	GetColumnCount PTR
	GetColumn STRUCT
		PTR
		PTR
	ENDS
	GetColumnFromPropID PTR
	Clear PTR
	ClearRows PTR
	Free PTR
	IsCompleted PTR
	Cancel PTR
	Pause PTR
	GetRowStatus PTR
	GetColumnStatus PTR
ENDS

//----------------------------------------------------------------------
//------			Word Breaking Definitions				------------
//----------------------------------------------------------------------

// {D53552C8-77E3-101A-B552-08002B33B0E6}
#DEFINE GUID_IID_IWordBreaker <0xD53552C8, 0x77E3, 0x101A, <0xB5, 0x52, 0x08, 0x00, 0x2B, 0x33, 0xB0, 0xE6>>

// {CC907054-C058-101A-B554-08002B33B0E6}
#DEFINE GUID_IID_IWordSink <0xCC907054, 0xC058, 0x101A, <0xB5, 0x54, 0x08, 0x00, 0x2B, 0x33, 0xB0, 0xE6>>

// {CC906FF0-C058-101A-B554-08002B33B0E6}
#DEFINE GUID_IID_IPhraseSink <0xCC906FF0, 0xC058, 0x101A, <0xB5, 0x54, 0x08, 0x00, 0x2B, 0x33, 0xB0, 0xE6>>

// {8fa0d5a6-dedf-11d0-9a61-00c04fb68bf7}
#DEFINE GUID_IID_IWordBreakerConfig <0x8fa0d5a6, 0xdedf, 0x11d0, <0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// {4662daaf-d393-11d0-9a56-00c04fb68bf7}
#DEFINE GUID_CLSID_ITStdBreaker <0x4662daaf, 0xd393, 0x11d0, <0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>


//----------------------------------------------------------------------
//------			Stop Word List Definitions				------------
//----------------------------------------------------------------------

// {8fa0d5ad-dedf-11d0-9a61-00c04fb68bf7}
#DEFINE GUID_IID_IITStopWordList <0x8fa0d5ad, 0xdedf, 0x11d0, <0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>


//----------------------------------------------------------------------
//------				Stemming Definitions				------------
//----------------------------------------------------------------------

// {efbaf140-7f42-11ce-be57-00aa0051fe20}
#DEFINE GUID_IID_IStemmer <0xefbaf140, 0x7f42, 0x11ce, <0xbe, 0x57, 0x00, 0xaa, 0x00, 0x51, 0xfe, 0x20>>

// {fe77c330-7f42-11ce-be57-00aa0051fe20}
#DEFINE GUID_IID_IStemSink <0xfe77c330, 0x7f42, 0x11ce, <0xbe, 0x57, 0x00, 0xaa, 0x00, 0x51, 0xfe, 0x20>>

// {8fa0d5a7-dedf-11d0-9a61-00c04fb68bf7}
#DEFINE GUID_IID_IStemmerConfig <0x8fa0d5a7, 0xdedf, 0x11d0, <0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

// {8fa0d5a8-dedf-11d0-9a61-00c04fb68bf7}
#DEFINE GUID_CLSID_ITEngStemmer <0x8fa0d5a8, 0xdedf, 0x11d0, <0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7>>

#endif  // __INFOTECH_H__

