#IFNDEF STRUCTUREDQUERY_H
#DEFINE STRUCTUREDQUERY_H

#IFDEF LINKFILES
	#dynamiclinkfile OLEAUT32.DLL
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

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

/* header files for imported files */
#IFNDEF STRUCTUREDQUERYCONDITION_H
	#include "StructuredQueryCondition.h"
#ENDIF
#IFNDEF OBJECTARRAY_H
	#include "ObjectArray.h"
#ENDIF


// STRUCTURED_QUERY_SYNTAX enumeration
SQS_NO_SYNTAX	= 0
SQS_ADVANCED_QUERY_SYNTAX	= 1
SQS_NATURAL_QUERY_SYNTAX	= 2

// STRUCTURED_QUERY_SINGLE_OPTION enumeration
SQSO_SCHEMA	= 0
SQSO_LOCALE_WORD_BREAKING	= 1
SQSO_WORD_BREAKER	= 2
SQSO_NATURAL_SYNTAX	= 3
SQSO_AUTOMATIC_WILDCARD	= 4
SQSO_TRACE_LEVEL	= 5
SQSO_LANGUAGE_KEYWORDS	= 6
SQSO_SYNTAX	= 7
SQSO_TIME_ZONE	= 8
SQSO_IMPLICIT_CONNECTOR	= 9
SQSO_CONNECTOR_CASE	= 10

// STRUCTURED_QUERY_MULTIOPTION enumeration
SQMO_VIRTUAL_PROPERTY	= 0
SQMO_DEFAULT_PROPERTY	= 1
SQMO_GENERATOR_FOR_TYPE	= 2
SQMO_MAP_PROPERTY	= 3

// STRUCTURED_QUERY_PARSE_ERROR enumeration
SQPE_NONE	= 0
SQPE_EXTRA_OPENING_PARENTHESIS	= 1
SQPE_EXTRA_CLOSING_PARENTHESIS	= 2
SQPE_IGNORED_MODIFIER	= 3
SQPE_IGNORED_CONNECTOR	= 4
SQPE_IGNORED_KEYWORD	= 5
SQPE_UNHANDLED	= 6

// STRUCTURED_QUERY_RESOLVE_OPTION enumeration
SQRO_DEFAULT	= 0
SQRO_DONT_RESOLVE_DATETIME	= 0x1
SQRO_ALWAYS_ONE_INTERVAL	= 0x2
SQRO_DONT_SIMPLIFY_CONDITION_TREES	= 0x4
SQRO_DONT_MAP_RELATIONS	= 0x8
SQRO_DONT_RESOLVE_RANGES	= 0x10
SQRO_DONT_REMOVE_UNRESTRICTED_KEYWORDS	= 0x20
SQRO_DONT_SPLIT_WORDS	= 0x40
SQRO_IGNORE_PHRASE_ORDER	= 0x80
SQRO_ADD_VALUE_TYPE_FOR_PLAIN_VALUES	= 0x100
SQRO_ADD_ROBUST_ITEM_NAME	= 0x200

// CASE_REQUIREMENT enumeration
CASE_REQUIREMENT_ANY	= 0
CASE_REQUIREMENT_UPPER_IF_AQS	= 1

// INTERVAL_LIMIT_KIND enumeration
ILK_EXPLICIT_INCLUDED	= 0
ILK_EXPLICIT_EXCLUDED	= 1
ILK_NEGATIVE_INFINITY	= 2
ILK_POSITIVE_INFINITY	= 3

// QUERY_PARSER_MANAGER_OPTION enumeration
QPMO_SCHEMA_BINARY_NAME	= 0
QPMO_PRELOCALIZED_SCHEMA_BINARY_PATH	= 1
QPMO_UNLOCALIZED_SCHEMA_BINARY_PATH	= 2
QPMO_LOCALIZED_SCHEMA_BINARY_PATH	= 3
QPMO_APPEND_LCID_TO_LOCALIZED_PATH	= 4
QPMO_LOCALIZER_SUPPORT	= 5

#DEFINE GUID_IID_IQueryParser <0x2EBDEE67,0x3505,0x43f8,<0x99,0x46,0xEA,0x44,0xAB,0xC8,0xE5,0xB0>>

IQueryParser STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Parse PTR
	SetOption PTR
	GetOption PTR
	SetMultiOption PTR
	GetSchemaProvider PTR
	RestateToString PTR
	ParsePropertyValue PTR
	RestatePropertyValueToString PTR
ENDS

#DEFINE GUID_IID_IConditionFactory <0xA5EFE073,0xB16F,0x474f,<0x9F,0x3E,0x9F,0x8B,0x49,0x7A,0x3E,0x08>>

IConditionFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	MakeNot PTR
	MakeAndOr PTR
	MakeLeaf PTR
	Resolve PTR
ENDS

#DEFINE GUID_IID_IQuerySolution <0xD6EBC66B,0x8921,0x4193,<0xAF,0xDD,0xA1,0x78,0x9F,0xB7,0xFF,0x57>>

IQuerySolution STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	MakeNot PTR
	MakeAndOr PTR
	MakeLeaf PTR
	Resolve PTR
	GetQuery PTR
	GetErrors PTR
	GetLexicalData PTR
ENDS

// CONDITION_CREATION_OPTIONS enumeration
CONDITION_CREATION_DEFAULT	= 0
CONDITION_CREATION_NONE	= 0
CONDITION_CREATION_SIMPLIFY	= 0x1
CONDITION_CREATION_VECTOR_AND	= 0x2
CONDITION_CREATION_VECTOR_OR	= 0x4
CONDITION_CREATION_VECTOR_LEAF	= 0x8
CONDITION_CREATION_USE_CONTENT_LOCALE	= 0x10

#DEFINE GUID_IID_IConditionFactory2 <0x71D222E1,0x432F,0x429e,<0x8C,0x13,0xB6,0xDA,0xFD,0xE5,0x07,0x7A>>

IConditionFactory2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	MakeNot PTR
	MakeAndOr PTR
	MakeLeaf PTR
	Resolve PTR
	CreateTrueFalse PTR
	CreateNegation PTR
	CreateCompoundFromObjectArray PTR
	CreateCompoundFromArray PTR
	CreateStringLeaf PTR
	CreateIntegerLeaf PTR
	CreateBooleanLeaf PTR
	CreateLeaf PTR
	ResolveCondition PTR
ENDS

#DEFINE GUID_IID_IConditionGenerator <0x92D2CC58,0x4386,0x45a3,<0xB9,0x8C,0x7E,0x0C,0xE6,0x4A,0x41,0x17>>

IConditionGenerator STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
	RecognizeNamedEntities PTR
	GenerateForLeaf PTR
	DefaultPhrase PTR
ENDS

#DEFINE GUID_IID_IInterval <0x6BF0A714,0x3C18,0x430b,<0x8B,0x5D,0x83,0xB1,0xC2,0x34,0xD3,0xDB>>

IInterval STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLimits PTR
ENDS

#DEFINE GUID_IID_IMetaData <0x780102B0,0xC43B,0x4876,<0xBC,0x7B,0x5E,0x9B,0xA5,0xC8,0x87,0x94>>

IMetaData STRUCT
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

#DEFINE GUID_IID_IEntity <0x24264891,0xE80B,0x4fd3,<0xB7,0xCE,0x4F,0xF2,0xFA,0xE8,0x93,0x1F>>

IEntity STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Name PTR
	Base PTR
	Relationships PTR
	GetRelationship PTR
	MetaData PTR
	NamedEntities PTR
	GetNamedEntity PTR
	DefaultPhrase PTR
ENDS

#DEFINE GUID_IID_IRelationship <0x2769280B,0x5108,0x498c,<0x9C,0x7F,0xA5,0x12,0x39,0xB6,0x31,0x47>>

IRelationship STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Name PTR
	IsReal PTR
	Destination PTR
	MetaData PTR
	DefaultPhrase PTR
ENDS

#DEFINE GUID_IID_INamedEntity <0xABDBD0B1,0x7D54,0x49fb,<0xAB,0x5C,0xBF,0xF4,0x13,0x00,0x04,0xCD>>

INamedEntity STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetValue PTR
	DefaultPhrase PTR
ENDS

#DEFINE GUID_IID_ISchemaProvider <0x8CF89BCB,0x394C,0x49b2,<0xAE,0x28,0xA5,0x9D,0xD4,0xED,0x7F,0x68>>

ISchemaProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Entities PTR
	RootEntity PTR
	GetEntity PTR
	MetaData PTR
	Localize PTR
	SaveBinary PTR
	LookupAuthoredNamedEntity PTR
ENDS

#DEFINE GUID_IID_ITokenCollection <0x22D8B4F2,0xF577,0x4adb,<0xA3,0x35,0xC2,0xAE,0x88,0x41,0x6F,0xAB>>

ITokenCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	NumberOfTokens PTR
	GetToken PTR
ENDS

// NAMED_ENTITY_CERTAINTY enumeration
NEC_LOW	= 0
NEC_MEDIUM	= 1
NEC_HIGH	= 2 

#DEFINE GUID_IID_INamedEntityCollector <0xAF2440F6,0x8AFC,0x47d0,<0x9A,0x7F,0x39,0x6A,0x0A,0xCF,0xB4,0x3D>>

INamedEntityCollector STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Add PTR
ENDS

#DEFINE GUID_IID_ISchemaLocalizerSupport <0xCA3FDCA2,0xBFBE,0x4eed,<0x90,0xD7,0x0C,0xAE,0xF0,0xA1,0xBD,0xA1>>

ISchemaLocalizerSupport STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Localize PTR
ENDS

#DEFINE GUID_IID_IQueryParserManager <0xA879E3C4,0xAF77,0x44fb,<0x8F,0x37,0xEB,0xD1,0x48,0x7C,0xF9,0x20>>

IQueryParserManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateLoadedParser PTR
	InitializeOptions PTR
	SetOption PTR
ENDS

HITRANGE STRUCT
	iPosition LONG
	cLength LONG
ENDS


#DEFINE GUID_CLSID_QueryParser <0xB72F8FD8,0x0FAB,0x4dd9,<0xBD,0xBF,0x24,0x5A,0x6C,0xE1,0x48,0x5B>>

#DEFINE GUID_CLSID_NegationCondition <0x8DE9C74C,0x605A,0x4acd,<0xBE,0xE3,0x2B,0x22,0x2A,0xA2,0xD2,0x3D>>

#DEFINE GUID_CLSID_CompoundCondition <0x116F8D13,0x101E,0x4fa5,<0x84,0xD4,0xFF,0x82,0x79,0x38,0x19,0x35>>

#DEFINE GUID_CLSID_LeafCondition <0x52F15C89,0x5A17,0x48e1,<0xBB,0xCD,0x46,0xA3,0xF8,0x9C,0x7C,0xC2>>

#DEFINE GUID_CLSID_ConditionFactory <0xE03E85B0,0x7BE3,0x4000,<0xBA,0x98,0x6C,0x13,0xDE,0x9F,0xA4,0x86>>

#DEFINE GUID_CLSID_Interval <0xD957171F,0x4BF9,0x4de2,<0xBC,0xD5,0xC7,0x0A,0x7C,0xA5,0x58,0x36>>

#DEFINE GUID_CLSID_QueryParserManager <0x5088B39A,0x29B4,0x4d9d,<0x82,0x45,0x4E,0xE2,0x89,0x22,0x2F,0x66>>

#endif



