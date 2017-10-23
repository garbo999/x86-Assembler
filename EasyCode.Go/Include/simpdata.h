#ifndef SIMPDATA_H
#define SIMPDATA_H

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

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define OSP_IndexLabel 0
#define OSP_IndexAll -1
#define OSP_IndexUnknown -1

OSPFORMAT_RAW	= 0
OSPFORMAT_DEFAULT	= 0
OSPFORMAT_FORMATTED	= 1
OSPFORMAT_HTML	= 2

OSPRW_DEFAULT	= 1
OSPRW_READONLY	= 0
OSPRW_READWRITE	= 1
OSPRW_MIXED	= 2

OSPFIND_DEFAULT	= 0
OSPFIND_UP	= 1
OSPFIND_CASESENSITIVE	= 2
OSPFIND_UPCASESENSITIVE	= 3

OSPCOMP_EQ	= 1
OSPCOMP_DEFAULT	= 1
OSPCOMP_LT	= 2
OSPCOMP_LE	= 3
OSPCOMP_GE	= 4
OSPCOMP_GT	= 5
OSPCOMP_NE	= 6

OSPXFER_COMPLETE	= 0
OSPXFER_ABORT	= 1
OSPXFER_ERROR	= 2

#DEFINE GUID_IID_OLEDBSimpleProviderListener <0xE0E270C1,0xC0BE,0x11d0,<0x8F,0xE4,0x00,0xA0,0xC9,0x0A,0x63,0x41>>

OLEDBSimpleProviderListener STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	aboutToChangeCell PTR
	cellChanged PTR
	aboutToDeleteRows PTR
	deletedRows PTR
	aboutToInsertRows PTR
	insertedRows PTR
	rowsAvailable PTR
	transferComplete PTR
ENDS

#DEFINE GUID_IID_OLEDBSimpleProvider <0xE0E270C0,0xC0BE,0x11d0,<0x8F,0xE4,0x00,0xA0,0xC9,0x0A,0x63,0x41>>

OLEDBSimpleProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	getRowCount PTR
	getColumnCount PTR
	getRWStatus PTR
	getVariant PTR
	setVariant PTR
	getLocale PTR
	deleteRows PTR
	insertRows PTR
	find PTR
	addOLEDBSimpleProviderListener PTR
	removeOLEDBSimpleProviderListener PTR
	isAsync PTR
	getEstimatedRows PTR
	stopTransfer PTR
ENDS

#endif