//--------------------------------------------------------------------
// Microsoft OLE DB Provider for SQL Server
// (C) Copyright 1997 By Microsoft Corporation.
//
// @doc
//
// @module SQLOLEDB.H | Provider Specific definitions
//
//--------------------------------------------------------------------

#ifndef  SQLOLEDB_H
#define  SQLOLEDB_H

#IFNDEF MSC_VER
	#define MSC_VER 1000
#ENDIF

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
#endif /*COM_NO_WINDOWS_H*/

/* header files for imported files */

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#ifndef	 OLEDB_H
;	#include "oledb.h"
#endif

//----------------------------------------------------------------------------
// Provider-specific Class Ids
// Provider CLSID 		{0C7FF16C-38E3-11d0-97AB-00C04FC2AD98}
#define GUID_CLSID_SQLOLEDB          <0xc7ff16c,0x38e3,0x11d0,<0x97,0xab,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
// Error Lookup CLSID 		{C0932C62-38E5-11d0-97AB-00C04FC2AD98}
#define GUID_CLSID_SQLOLEDB_ERROR    <0xc0932c62,0x38e5,0x11d0,<0x97,0xab,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
// Enumerator CLSID 		{DFA22B8E-E68D-11d0-97E4-00C04FC2AD98}
#define GUID_CLSID_SQLOLEDB_ENUMERATOR <0xdfa22b8e,0xe68d,0x11d0,<0x97,0xe4,0x0,0xc0,0x4f,0xc2,0xad,0x98>>

//----------------------------------------------------------------------------
// Provider-specific Interface Ids
#define GUID_IID_ISQLServerErrorInfo <0x5cf4ca12,0xef21,0x11d0,<0x97,0xe7,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
#define GUID_IID_IRowsetFastLoad     <0x5cf4ca13,0xef21,0x11d0,<0x97,0xe7,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
#define GUID_IID_IUMSInitialize      <0x5cf4ca14,0xef21,0x11d0,<0x97,0xe7,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
// {4C2389FB-2511-11d4-B258-00C04F7971CE}
#define GUID_IID_ISchemaLock         <0x4c2389fb,0x2511,0x11d4,<0xb2,0x58,0x0,0xc0,0x4f,0x79,0x71,0xce>>
#define GUID_DBGUID_MSSQLXML         <0x5d531cb2,0xe6ed,0x11d2,<0xb2,0x52,0x00,0xc0,0x4f,0x68,0x1b,0x71>>
#define GUID_DBGUID_XPATH            <0xec2a4293,0xe898,0x11d2,<0xb1,0xb7,0x00,0xc0,0x4f,0x68,0x0c,0x56>>
// This IID_ICommandStream definition is available in later versions of 
// UUID.LIB.  It is also already an extern defined in oledb.h.
//
#if MSC_VER < 1300
#define GUID_IID_ICommandStream      <0x0c733abf,0x2a1c,0x11ce,<0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d>>
#endif // _MSC_VER
#define GUID_IID_ISQLXMLHelper       <0xd22a7678,0xf860,0x40cd,<0xa5,0x67,0x15,0x63,0xde,0xb4,0x6d,0x49>>

//----------------------------------------------------------------------------
// Provider-specific schema rowsets
#define GUID_DBSCHEMA_LINKEDSERVERS  <0x9093caf4,0x2eac,0x11d1,<0x98,0x9,0x0,0xc0,0x4f,0xc2,0xad,0x98>>

//----------------------------------------------------------------------------
// Provider-specific property sets
#define GUID_DBPROPSET_SQLSERVERDATASOURCE <0x28efaee4,0x2d2c,0x11d1,<0x98,0x7,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
#define GUID_DBPROPSET_SQLSERVERDATASOURCEINFO <0xdf10cb94,0x35f6,0x11d2,<0x9c,0x54,0x0,0xc0,0x4f,0x79,0x71,0xd3>>
#define GUID_DBPROPSET_SQLSERVERDBINIT   <0x5cf4ca10,0xef21,0x11d0,<0x97,0xe7,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
#define GUID_DBPROPSET_SQLSERVERROWSET   <0x5cf4ca11,0xef21,0x11d0,<0x97,0xe7,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
#define GUID_DBPROPSET_SQLSERVERSESSION  <0x28efaee5,0x2d2c,0x11d1,<0x98,0x7,0x0,0xc0,0x4f,0xc2,0xad,0x98>>
#define GUID_DBPROPSET_SQLSERVERCOLUMN   <0x3b63fb5e,0x3fbb,0x11d3,<0x9f,0x29,0x0,0xc0,0x4f,0x8e,0xe9,0xdc>>
#define GUID_DBPROPSET_SQLSERVERSTREAM   <0x9f79c073,0x8a6d,0x4bca,<0xa8,0xa8,0xc9,0xb7,0x9a,0x9b,0x96,0x2d>>

//----------------------------------------------------------------------------
// Provider-specific columns for IColumnsRowset
;extern const DBID OLEDBDECLSPEC DBCOLUMN_SS_COMPFLAGS       <0x627bd890,0xed54,0x11d2,<0xb9,0x94,0x0,0xc0,0x4f,0x8c,0xa8,0x2c, DBKIND_GUID_PROPID, (LPOLESTR)100>>
;extern const DBID OLEDBDECLSPEC DBCOLUMN_SS_SORTID          <0x627bd890,0xed54,0x11d2,<0xb9,0x94,0x0,0xc0,0x4f,0x8c,0xa8,0x2c, DBKIND_GUID_PROPID, (LPOLESTR)101>>
;extern const DBID OLEDBDECLSPEC DBCOLUMN_BASETABLEINSTANCE  <0x627bd890,0xed54,0x11d2,<0xb9,0x94,0x0,0xc0,0x4f,0x8c,0xa8,0x2c, DBKIND_GUID_PROPID, (LPOLESTR)102>>
;extern const DBID OLEDBDECLSPEC DBCOLUMN_SS_TDSCOLLATION    <0x627bd890,0xed54,0x11d2,<0xb9,0x94,0x0,0xc0,0x4f,0x8c,0xa8,0x2c, DBKIND_GUID_PROPID, (LPOLESTR)103>>

#define CRESTRICTIONS_DBSCHEMA_LINKEDSERVERS	1

//----------------------------------------------------------------------------
// PropIds for DBPROP_INIT_GENERALTIMEOUT
#define DBPROP_INIT_GENERALTIMEOUT		0x11c

//----------------------------------------------------------------------------
// PropIds for DBPROPSET_SQLSERVERDATASOURCE
#define SSPROP_ENABLEFASTLOAD			2

//----------------------------------------------------------------------------
// PropIds for DBPROPSET_SQLSERVERDATASOURCEINFO
#define SSPROP_UNICODELCID				2
#define SSPROP_UNICODECOMPARISONSTYLE	3
#define SSPROP_COLUMNLEVELCOLLATION     4
#define SSPROP_CHARACTERSET				5
#define	SSPROP_SORTORDER				6
#define SSPROP_CURRENTCOLLATION			7
//----------------------------------------------------------------------------
// PropIds for DBPROPSET_SQLSERVERDBINIT 
#define SSPROP_INIT_CURRENTLANGUAGE		4
#define SSPROP_INIT_NETWORKADDRESS		5
#define SSPROP_INIT_NETWORKLIBRARY		6
#define SSPROP_INIT_USEPROCFORPREP		7
#define SSPROP_INIT_AUTOTRANSLATE		8
#define SSPROP_INIT_PACKETSIZE			9
#define SSPROP_INIT_APPNAME			10
#define SSPROP_INIT_WSID			11
#define SSPROP_INIT_FILENAME			12
#define SSPROP_INIT_ENCRYPT             13 
#define SSPROP_AUTH_REPL_SERVER_NAME	14
#define SSPROP_INIT_TAGCOLUMNCOLLATION	15

//-----------------------------------------------------------------------------
// Values for SSPROP_USEPROCFORPREP
#define SSPROPVAL_USEPROCFORPREP_OFF		0
#define SSPROPVAL_USEPROCFORPREP_ON			1
#define SSPROPVAL_USEPROCFORPREP_ON_DROP	2

//----------------------------------------------------------------------------
// PropIds for DBPROPSET_SQLSERVERSESSION
#define SSPROP_QUOTEDCATALOGNAMES		2
#define SSPROP_ALLOWNATIVEVARIANT		3
#define SSPROP_SQLXMLXPROGID			4

//----------------------------------------------------------------------------
// PropIds for DBPROPSET_SQLSERVERROWSET 
#define SSPROP_MAXBLOBLENGTH			8
#define SSPROP_FASTLOADOPTIONS			9
#define SSPROP_FASTLOADKEEPNULLS		10
#define SSPROP_FASTLOADKEEPIDENTITY		11
#define SSPROP_CURSORAUTOFETCH			12
#define SSPROP_DEFERPREPARE				13
#define SSPROP_IRowsetFastLoad			14

//----------------------------------------------------------------------------
// PropIds for DBPROPSET_SQLSERVERCOLUMN
#define SSPROP_COL_COLLATIONNAME		14

//----------------------------------------------------------------------------
// PropIds for DBPROPSET_SQLSERVERSTREAM
#define SSPROP_STREAM_MAPPINGSCHEMA     15
#define SSPROP_STREAM_XSL               16
#define SSPROP_STREAM_BASEPATH          17
#define SSPROP_STREAM_COMMANDTYPE       18
#define SSPROP_STREAM_XMLROOT           19
#define SSPROP_STREAM_FLAGS             20
#define SSPROP_STREAM_CONTENTTYPE       23

//----------------------------------------------------------------------------
// Possible values for SSPROP_STREAM_FLAGS
#define STREAM_FLAGS_DISALLOW_URL           0x00000001
#define STREAM_FLAGS_DISALLOW_ABSOLUTE_PATH 0x00000002
#define STREAM_FLAGS_DISALLOW_QUERY         0x00000004
#define STREAM_FLAGS_DONTCACHEMAPPINGSCHEMA 0x00000008
#define STREAM_FLAGS_DONTCACHETEMPLATE      0x00000010
#define STREAM_FLAGS_DONTCACHEXSL           0x00000020
#define STREAM_FLAGS_DISALLOW_UPDATEGRAMS   0x00000040
#define STREAM_FLAGS_RESERVED               0xffff0000

// Values for SSPROPVAL_COMMANDTYPE

#define SSPROPVAL_COMMANDTYPE_REGULAR   21
#define SSPROPVAL_COMMANDTYPE_BULKLOAD  22

//-------------------------------------------------------------------
// define SQL Server Spefific Variant Type
//-------------------------------------------------------------------
#define DBTYPE_SQLVARIANT   144

VT_SS_EMPTY = DBTYPE_EMPTY
VT_SS_NULL = DBTYPE_NULL
VT_SS_UI1 = DBTYPE_UI1
VT_SS_I2 = DBTYPE_I2
VT_SS_I4 = DBTYPE_I4
VT_SS_I8 = DBTYPE_I8

//Floats
VT_SS_R4  = DBTYPE_R4
VT_SS_R8 = DBTYPE_R8

//Money
VT_SS_MONEY = DBTYPE_CY
VT_SS_SMALLMONEY = 200

//Strings
VT_SS_WSTRING = 201
VT_SS_WVARSTRING = 202

VT_SS_STRING = 203
VT_SS_VARSTRING	= 204

//Bit
VT_SS_BIT = DBTYPE_BOOL

//Guid
VT_SS_GUID = DBTYPE_GUID

//Exact precision
VT_SS_NUMERIC = DBTYPE_NUMERIC
VT_SS_DECIMAL = 205

//Datetime
VT_SS_DATETIME = DBTYPE_DBTIMESTAMP
VT_SS_SMALLDATETIME = 206

//Binary
VT_SS_BINARY = 207
VT_SS_VARBINARY = 208
//Future
VT_SS_UNKNOWN	= 209

#IFNDEF DBTIMESTAMP
	DBTIMESTAMP STRUCT
		year DW
		month DW
		day DW
		hour DW
		minute DW
		second DW
		fraction DD
	ENDS
#ENDIF

#IFNDEF DB_NUMERIC
	DB_NUMERIC STRUCT
		precision DB
		scale DB
		sign DB
		val DB 16 DUP
	ENDS
#ENDIF

#IFNDEF DBOBJECT
	DBOBJECT STRUCT
		dwFlags DD
		iid GUID
	ENDS
#ENDIF

//Hungarian : ssv (Sql Server Variant)
SSVARIANT STRUCT
	vt DD
	dwReserved1 DD
	dwReserved2 DD
	UNION
		bTinyIntVal DB
		sShortIntVal DW
		lIntVal DD
		llBigIntVal DQ
		fltRealVal FLOAT
		dblFloatVal DOUBLE
		cyMoneyVal DQ
		NCharVal STRUCT
			sActualLength DW
			sMaxLength DW
			pwchNCharVal PTR
			rgbReserved DB 5 DUP
			dwReserved DD
			pwchReserved PTR
		ENDS
		CharVal STRUCT
			sActualLength DW
			sMaxLength DW
			pchCharVal PTR
			rgbReserved DB 5 DUP
			dwReserved DD
			pwchReserved PTR
		ENDS
		fBitVal DW
		rgbGuidVal GUID
		numNumericVal DB_NUMERIC
		BinaryVal STRUCT
			sActualLength DW
			sMaxLength DW
			prgbBinaryVal PTR
			dwReserved DD
		ENDS
		tsDateTimeVal DBTIMESTAMP
		UnknownType STRUCT
			dwActualLength DD
			rgMetadata  DB 16 DUP
			pUnknownData PTR
		ENDS
		BLOBType STRUCT
			dbobj DBOBJECT
			pUnk PTR
		ENDS
	ENDUNION
ENDS

//-----------------------------------------------------------------
// Class Factory Interface used to initialize pointer to UMS. 
//
IUMSInitialize STRUCT
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
//-----------------------------------------------------------------
// Interface used to communicate with UMS.
//
IUMS STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SqlUmsSuspend PTR
	SqlUmsYield PTR
	SqlUmsSwitchPremptive PTR
	SqlUmsSwitchNonPremptive PTR
	SqlUmsFIsPremptive PTR
ENDS

// the structure returned by  ISQLServerErrorInfo::GetSQLServerInfo
SSERRORINFO STRUCT
	pwszMessage PTR
	pwszServer PTR
	pwszProcedure PTR
	lNative DD
	bState DB
	bClass DB
	wLineNumber DW
ENDS

#define GUID_IID_ISQLServerErrorInfo <0x5CF4CA12,0xEF21,0x11d0,<0x97,0xE7,0x00,0xC0,0x4F,0xC2,0xAD,0x98>>

ISQLServerErrorInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetErrorInfo PTR
ENDS

#define GUID_IID_IRowsetFastLoad <0x5CF4CA13,0xEF21,0x11d0,<0x97,0xE7,0x00,0xC0,0x4F,0xC2,0xAD,0x98>>

IRowsetFastLoad STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InsertRow PTR
	Commit PTR
ENDS

LOCKMODE_INVALID	= 0
LOCKMODE_EXCLUSIVE	= 1
LOCKMODE_SHARED	= 2

#define GUID_IID_ISchemaLock <0x4C2389FB,0x2511,0x11d4,<0xB2,0x58,0x00,0xC0,0x4F,0x79,0x71,0xCE>>

ISchemaLock STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSchemaLock PTR
	ReleaseSchemaLock PTR
ENDS

#endif //_SQLOLEDB_H_

