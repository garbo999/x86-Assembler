#IFNDEF STRUCTUREDQUERYCONDITION_H
#DEFINE STRUCTUREDQUERYCONDITION_H

#ifndef RPC_H
	#include "rpc.h"
#endif
#ifndef RPCNDR_H
	#include "rpcndr.h"
#endif

#ifndef COM_NO_WINDOWS_H
	#ifndef WINDOWS_H
		#include "windows.h"
	#endif
	#ifndef OLE2_H
		#include "ole2.h"
	#endif
#endif /*COM_NO_WINDOWS_H*/

/* header files for imported files */
#ifndef OAIDL_H
	#include "oaidl.h"
#endif

#ifndef OCIDL_H
	#include "ocidl.h"
#endif

#ifndef PROPIDL_H
	#include "propidl.h"
#endif

CT_AND_CONDITION	= 0
CT_OR_CONDITION	= 1
CT_NOT_CONDITION	= 2
CT_LEAF_CONDITION	= 3

COP_IMPLICIT	= 0
COP_EQUAL	= 1
COP_NOTEQUAL	= 2
COP_LESSTHAN	= 3
COP_GREATERTHAN	= 4
COP_LESSTHANOREQUAL	= 5
COP_GREATERTHANOREQUAL	= 6
COP_VALUE_STARTSWITH	= 7
COP_VALUE_ENDSWITH	= 8
COP_VALUE_CONTAINS	= 9
COP_VALUE_NOTCONTAINS	= 10
COP_DOSWILDCARDS	= 11
COP_WORD_EQUAL	= 12
COP_WORD_STARTSWITH	= 13
COP_APPLICATION_SPECIFIC	= 14

#define GUID_IID_IRichChunk <0x4FDEF69C,0xDBC9,0x454e,<0x99,0x10,0xB3,0x4F,0x3C,0x64,0xB5,0x10>>

IRichChunk STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetData PTR
ENDS

#define GUID_IID_ICondition <0x0FC988D4,0xC935,0x4b97,<0xA9,0x73,0x46,0x28,0x2E,0xA1,0x75,0xC8>>

ICondition STRUCT
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
	GetConditionType PTR
	GetSubConditions PTR
	GetComparisonInfo PTR
	GetValueType PTR
	GetValueNormalization PTR
	GetInputTerms PTR
	Clone PTR
ENDS

#define GUID_IID_ICondition2 <0x0DB8851D,0x2E5B,0x47eb,<0x92,0x08,0xD2,0x8C,0x32,0x5A,0x01,0xD7>>

ICondition2 STRUCT
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
	GetConditionType PTR
	GetSubConditions PTR
	GetComparisonInfo PTR
	GetValueType PTR
	GetValueNormalization PTR
	GetInputTerms PTR
	Clone PTR
	GetLocale PTR
	GetLeafConditionInfo PTR
ENDS

#endif



