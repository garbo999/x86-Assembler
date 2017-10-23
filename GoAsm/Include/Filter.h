#IFNDEF FILTER_H
#DEFINE FILTER_H

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

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF
#IFNDEF PROPIDL_H
	#include "propidl.h"
#ENDIF


//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1993-1998.
//
//--------------------------------------------------------------------------
FULLPROPSPEC STRUCT
	guidPropSet GUID
	psProperty PTR
ENDS

// IFILTER_INIT enumeration
IFILTER_INIT_CANON_PARAGRAPHS	= 1
IFILTER_INIT_HARD_LINE_BREAKS	= 2
IFILTER_INIT_CANON_HYPHENS	= 4
IFILTER_INIT_CANON_SPACES	= 8
IFILTER_INIT_APPLY_INDEX_ATTRIBUTES	= 16
IFILTER_INIT_APPLY_OTHER_ATTRIBUTES	= 32
IFILTER_INIT_APPLY_CRAWL_ATTRIBUTES	= 256
IFILTER_INIT_INDEXING_ONLY	= 64
IFILTER_INIT_SEARCH_LINKS	= 128
IFILTER_INIT_FILTER_OWNED_VALUE_OK	= 512
IFILTER_INIT_FILTER_AGGRESSIVE_BREAK	= 1024
IFILTER_INIT_DISABLE_EMBEDDED	= 2048
IFILTER_INIT_EMIT_FORMATTING	= 4096

// CHUNKSTATE enumeration
CHUNK_TEXT	= 0x1
CHUNK_VALUE	= 0x2
CHUNK_FILTER_OWNED_VALUE	= 0x4

// CHUNK_BREAKTYPE enumeration
CHUNK_NO_BREAK	= 0
CHUNK_EOW	= 1
CHUNK_EOS	= 2
CHUNK_EOP	= 3
CHUNK_EOC	= 4

FILTERREGION STRUCT
	idChunk LONG
	cwcStart LONG
	cwcExtent LONG
ENDS

STAT_CHUNK STRUCT
	idChunk LONG
	breakType ENUM
	flags ENUM
	locale LCID
	attribute FULLPROPSPEC
	idChunkSource LONG
	cwcStartSource LONG
	cwcLenSource LONG
ENDS

#DEFINE GUID_IID_IFilter <0x89BCB740,0x6119,0x101A,<0xBC,0xB7,0x00,0xDD,0x01,0x06,0x55,0xAF>>

IFilter STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
	GetChunk PTR
	GetText PTR
	GetValue PTR
	BindRegion PTR
ENDS

#endif



