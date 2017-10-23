#ifndef PROPSYS_H
#define PROPSYS_H

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
#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF

#ifndef OLEIDL_H
	#include "oleidl.h"
#endif

#ifndef OCIDL_H
	#include "ocidl.h"
#endif

#IFNDEF SHTYPES_H
	#include "shtypes.h"
#ENDIF

#IFNDEF STRUCTUREDQUERYCONDITION_H
	#include "StructuredQueryCondition.h"
#ENDIF

#define GUID_IID_IInitializeWithFile <0xb7d14566,0x0509,0x4cce,<0xa7,0x1f,0x0a,0x55,0x42,0x33,0xbd,0x9b>>

IInitializeWithFile STRUCT
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

#define GUID_IID_IInitializeWithStream <0xb824b49d,0x22ac,0x4161,<0xac,0x8a,0x99,0x16,0xe8,0xfa,0x3f,0x7f>>

IInitializeWithStream STRUCT
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

#define GUID_IID_IPropertyStore <0x886d8eeb,0x8cf2,0x4446,<0x8d,0x02,0xcd,0xba,0x1d,0xbd,0xcf,0x99>>

IPropertyStore STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCount PTR
	GetAt PTR
	GetValue PTR
	SetValue PTR
	Commit PTR
ENDS

#define GUID_IID_INamedPropertyStore <0x71604b0f,0x97b0,0x4764,<0x85,0x77,0x2f,0x13,0xe9,0x8a,0x14,0x22>>

INamedPropertyStore STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNamedValue PTR
	SetNamedValue PTR
	GetNameCount PTR
	GetNameAt PTR
ENDS

GPS_DEFAULT	= 0
GPS_HANDLERPROPERTIESONLY	= 0x1
GPS_READWRITE	= 0x2
GPS_TEMPORARY	= 0x4
GPS_FASTPROPERTIESONLY	= 0x8
GPS_OPENSLOWITEM	= 0x10
GPS_DELAYCREATION	= 0x20
GPS_BESTEFFORT	= 0x40
GPS_NO_OPLOCK	= 0x80
GPS_MASK_VALID	= 0xff

#define GUID_IID_IObjectWithPropertyKey <0xfc0ca0a7,0xc316,0x4fd2,<0x90,0x31,0x3e,0x62,0x8e,0x6d,0x4f,0x23>>

IObjectWithPropertyKey STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetPropertyKey PTR
	GetPropertyKey PTR
ENDS

PKA_SET	= 0
PKA_APPEND	= 1
PKA_DELETE	= 2 

#define GUID_IID_IPropertyChange <0xf917bc8a,0x1bba,0x4478,<0xa2,0x45,0x1b,0xde,0x03,0xeb,0x94,0x31>>

IPropertyChange STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetPropertyKey PTR
	GetPropertyKey PTR
	ApplyToPropVariant PTR
ENDS

#define GUID_IID_IPropertyChangeArray <0x380f5cad,0x1b5e,0x42f2,<0x80,0x5d,0x63,0x7f,0xd3,0x92,0xd3,0x1e>>

IPropertyChangeArray STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCount PTR
	GetAt PTR
	InsertAt PTR
	Append PTR
	AppendOrReplace PTR
	RemoveAt PTR
	IsKeyInArray PTR
ENDS

#define GUID_IID_IPropertyStoreCapabilities <0xc8e2d566,0x186e,0x4d49,<0xbf,0x41,0x69,0x09,0xea,0xd5,0x6a,0xcc>>

IPropertyStoreCapabilities STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsPropertyWritable PTR
ENDS

PSC_NORMAL	= 0
PSC_NOTINSOURCE	= 1
PSC_DIRTY	= 2
PSC_READONLY	= 3

#define GUID_IID_IPropertyStoreCache <0x3017056d,0x9a91,0x4e90,<0x93,0x7d,0x74,0x6c,0x72,0xab,0xbf,0x4f>>

IPropertyStoreCache STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCount PTR
	GetAt PTR
	GetValue PTR
	SetValue PTR
	Commit PTR
	GetState PTR
	GetValueAndState PTR
	SetState PTR
	SetValueAndState PTR
ENDS

PET_DISCRETEVALUE	= 0
PET_RANGEDVALUE	= 1
PET_DEFAULTVALUE	= 2
PET_ENDRANGE	= 3

#define GUID_IID_IPropertyEnumType <0x11e1fbf9,0x2d56,0x4a6b,<0x8d,0xb3,0x7c,0xd1,0x93,0xa4,0x71,0xf2>>

IPropertyEnumType STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetEnumType PTR
	GetValue PTR
	GetRangeMinValue PTR
	GetRangeSetValue PTR
	GetDisplayText PTR
ENDS

#define GUID_IID_IPropertyEnumType2 <0x9b6e051c,0x5ddd,0x4321,<0x90,0x70,0xfe,0x2a,0xcb,0x55,0xe7,0x94>>

IPropertyEnumType2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetEnumType PTR
	GetValue PTR
	GetRangeMinValue PTR
	GetRangeSetValue PTR
	GetDisplayText PTR
	GetImageReference PTR
ENDS


#define GUID_IID_IPropertyEnumTypeList <0xa99400f4,0x3d84,0x4557,<0x94,0xba,0x12,0x42,0xfb,0x2c,0xc9,0xa6>>

IPropertyEnumTypeList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCount PTR
	GetAt PTR
	GetConditionAt PTR
	FindMatchingIndex PTR
ENDS

PDTF_DEFAULT	= 0
PDTF_MULTIPLEVALUES	= 0x1
PDTF_ISINNATE	= 0x2
PDTF_ISGROUP	= 0x4
PDTF_CANGROUPBY	= 0x8
PDTF_CANSTACKBY	= 0x10
PDTF_ISTREEPROPERTY	= 0x20
PDTF_INCLUDEINFULLTEXTQUERY	= 0x40
PDTF_ISVIEWABLE	= 0x80
PDTF_ISQUERYABLE	= 0x100
PDTF_CANBEPURGED	= 0x200
PDTF_SEARCHRAWVALUE	= 0x400
PDTF_ISSYSTEMPROPERTY	= 0x80000000
PDTF_MASK_ALL	= 0x800007ff

PDVF_DEFAULT	= 0
PDVF_CENTERALIGN	= 0x1
PDVF_RIGHTALIGN	= 0x2
PDVF_BEGINNEWGROUP	= 0x4
PDVF_FILLAREA	= 0x8
PDVF_SORTDESCENDING	= 0x10
PDVF_SHOWONLYIFPRESENT	= 0x20
PDVF_SHOWBYDEFAULT	= 0x40
PDVF_SHOWINPRIMARYLIST	= 0x80
PDVF_SHOWINSECONDARYLIST	= 0x100
PDVF_HIDELABEL	= 0x200
PDVF_HIDDEN	= 0x800
PDVF_CANWRAP	= 0x1000
PDVF_MASK_ALL	= 0x1bff

PDDT_STRING	= 0
PDDT_NUMBER	= 1
PDDT_BOOLEAN	= 2
PDDT_DATETIME	= 3
PDDT_ENUMERATED	= 4

PDGR_DISCRETE	= 0
PDGR_ALPHANUMERIC	= 1
PDGR_SIZE	= 2
PDGR_DYNAMIC	= 3
PDGR_DATE	= 4
PDGR_PERCENT	= 5
PDGR_ENUMERATED	= 6

PDFF_DEFAULT	= 0
PDFF_PREFIXNAME	= 0x1
PDFF_FILENAME	= 0x2
PDFF_ALWAYSKB	= 0x4
PDFF_RESERVED_RIGHTTOLEFT	= 0x8
PDFF_SHORTTIME	= 0x10
PDFF_LONGTIME	= 0x20
PDFF_HIDETIME	= 0x40
PDFF_SHORTDATE	= 0x80
PDFF_LONGDATE	= 0x100
PDFF_HIDEDATE	= 0x200
PDFF_RELATIVEDATE	= 0x400
PDFF_USEEDITINVITATION	= 0x800
PDFF_READONLY	= 0x1000
PDFF_NOAUTOREADINGORDER	= 0x2000

PDSD_GENERAL	= 0
PDSD_A_Z	= 1
PDSD_LOWEST_HIGHEST	= 2
PDSD_SMALLEST_BIGGEST	= 3
PDSD_OLDEST_NEWEST	= 4

PDRDT_GENERAL	= 0
PDRDT_DATE	= 1
PDRDT_SIZE	= 2
PDRDT_COUNT	= 3
PDRDT_REVISION	= 4
PDRDT_LENGTH	= 5
PDRDT_DURATION	= 6
PDRDT_SPEED	= 7
PDRDT_RATE	= 8
PDRDT_RATING	= 9
PDRDT_PRIORITY	= 10

PDAT_DEFAULT	= 0
PDAT_FIRST	= 1
PDAT_SUM	= 2
PDAT_AVERAGE	= 3
PDAT_DATERANGE	= 4
PDAT_UNION	= 5
PDAT_MAX	= 6
PDAT_MIN	= 7

PDCOT_NONE	= 0
PDCOT_STRING	= 1
PDCOT_SIZE	= 2
PDCOT_DATETIME	= 3
PDCOT_BOOLEAN	= 4
PDCOT_NUMBER	= 5

#define GUID_IID_IPropertyDescription <0x6f79d558,0x3e96,0x4549,<0xa1,0xd1,0x7d,0x75,0xd2,0x28,0x88,0x14>>

IPropertyDescription STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPropertyKey PTR
	GetCanonicalName PTR
	GetPropertyType PTR
	GetDisplayName PTR
	GetEditInvitation PTR
	GetTypeFlags PTR
	GetViewFlags PTR
	GetDefaultColumnWidth PTR
	GetDisplayType PTR
	GetColumnState PTR
	GetGroupingRange PTR
	GetRelativeDescriptionType PTR
	GetRelativeDescription PTR
	GetSortDescription PTR
	GetSortDescriptionLabel PTR
	GetAggregationType PTR
	GetConditionType PTR
	GetEnumTypeList PTR
	CoerceToCanonicalValue PTR
	FormatForDisplay PTR
	IsValueCanonical PTR
ENDS

#define GUID_IID_IPropertyDescription2 <0x57d2eded,0x5062,0x400e,<0xb1,0x07,0x5d,0xae,0x79,0xfe,0x57,0xa6>>

IPropertyDescription2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPropertyKey PTR
	GetCanonicalName PTR
	GetPropertyType PTR
	GetDisplayName PTR
	GetEditInvitation PTR
	GetTypeFlags PTR
	GetViewFlags PTR
	GetDefaultColumnWidth PTR
	GetDisplayType PTR
	GetColumnState PTR
	GetGroupingRange PTR
	GetRelativeDescriptionType PTR
	GetRelativeDescription PTR
	GetSortDescription PTR
	GetSortDescriptionLabel PTR
	GetAggregationType PTR
	GetConditionType PTR
	GetEnumTypeList PTR
	CoerceToCanonicalValue PTR
	FormatForDisplay PTR
	IsValueCanonical PTR
	GetImageReferenceForValue PTR
ENDS

#define GUID_IID_IPropertyDescriptionAliasInfo <0xf67104fc,0x2af9,0x46fd,<0xb3,0x2d,0x24,0x3c,0x14,0x04,0xf3,0xd1>>

IPropertyDescriptionAliasInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPropertyKey PTR
	GetCanonicalName PTR
	GetPropertyType PTR
	GetDisplayName PTR
	GetEditInvitation PTR
	GetTypeFlags PTR
	GetViewFlags PTR
	GetDefaultColumnWidth PTR
	GetDisplayType PTR
	GetColumnState PTR
	GetGroupingRange PTR
	GetRelativeDescriptionType PTR
	GetRelativeDescription PTR
	GetSortDescription PTR
	GetSortDescriptionLabel PTR
	GetAggregationType PTR
	GetConditionType PTR
	GetEnumTypeList PTR
	CoerceToCanonicalValue PTR
	FormatForDisplay PTR
	IsValueCanonical PTR
	GetSortByAlias PTR
	GetAdditionalSortByAliases PTR
ENDS

PDSIF_DEFAULT	= 0
PDSIF_ININVERTEDINDEX	= 0x1
PDSIF_ISCOLUMN	= 0x2
PDSIF_ISCOLUMNSPARSE	= 0x4
PDSIF_ALWAYSINCLUDE	= 0x8

PDCIT_NONE	= 0
PDCIT_ONDISK	= 1
PDCIT_INMEMORY	= 2
PDCIT_ONDEMAND	= 3
PDCIT_ONDISKALL	= 4
PDCIT_ONDISKVECTOR	= 5


#define GUID_IID_IPropertyDescriptionSearchInfo <0x078f91bd,0x29a2,0x440f,<0x92,0x4e,0x46,0xa2,0x91,0x52,0x45,0x20>>

IPropertyDescriptionSearchInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPropertyKey PTR
	GetCanonicalName PTR
	GetPropertyType PTR
	GetDisplayName PTR
	GetEditInvitation PTR
	GetTypeFlags PTR
	GetViewFlags PTR
	GetDefaultColumnWidth PTR
	GetDisplayType PTR
	GetColumnState PTR
	GetGroupingRange PTR
	GetRelativeDescriptionType PTR
	GetRelativeDescription PTR
	GetSortDescription PTR
	GetSortDescriptionLabel PTR
	GetAggregationType PTR
	GetConditionType PTR
	GetEnumTypeList PTR
	CoerceToCanonicalValue PTR
	FormatForDisplay PTR
	IsValueCanonical PTR
	GetSearchInfoFlags PTR
	GetColumnIndexType PTR
	GetProjectionString PTR
	GetMaxSize PTR
ENDS

#define GUID_IID_IPropertyDescriptionRelatedPropertyInfo <0x507393f4,0x2a3d,0x4a60,<0xb5,0x9e,0xd9,0xc7,0x57,0x16,0xc2,0xdd>>

IPropertyDescriptionRelatedPropertyInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPropertyKey PTR
	GetCanonicalName PTR
	GetPropertyType PTR
	GetDisplayName PTR
	GetEditInvitation PTR
	GetTypeFlags PTR
	GetViewFlags PTR
	GetDefaultColumnWidth PTR
	GetDisplayType PTR
	GetColumnState PTR
	GetGroupingRange PTR
	GetRelativeDescriptionType PTR
	GetRelativeDescription PTR
	GetSortDescription PTR
	GetSortDescriptionLabel PTR
	GetAggregationType PTR
	GetConditionType PTR
	GetEnumTypeList PTR
	CoerceToCanonicalValue PTR
	FormatForDisplay PTR
	IsValueCanonical PTR
	GetRelatedProperty PTR
ENDS

PDEF_ALL	= 0
PDEF_SYSTEM	= 1
PDEF_NONSYSTEM	= 2
PDEF_VIEWABLE	= 3
PDEF_QUERYABLE	= 4
PDEF_INFULLTEXTQUERY	= 5
PDEF_COLUMN	= 6

#define GUID_IID_IPropertySystem <0xca724e8a,0xc3e6,0x442b,<0x88,0xa4,0x6f,0xb0,0xdb,0x80,0x35,0xa3>>

IPropertySystem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPropertyDescription PTR
	GetPropertyDescriptionByName PTR
	GetPropertyDescriptionListFromString PTR
	EnumeratePropertyDescriptions PTR
	FormatForDisplay PTR
	FormatForDisplayAlloc PTR
	RegisterPropertySchema PTR
	UnregisterPropertySchema PTR
	RefreshPropertySchema PTR
ENDS

#define GUID_IID_IPropertyDescriptionList <0x1f9fc1d0,0xc39b,0x4b26,<0x81,0x7f,0x01,0x19,0x67,0xd3,0x44,0x0e>>

IPropertyDescriptionList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCount PTR
	GetAt PTR
ENDS

#define GUID_IID_IPropertyStoreFactory <0xbc110b6d,0x57e8,0x4148,<0xa9,0xc6,0x91,0x01,0x5a,0xb2,0xf3,0xa5>>

IPropertyStoreFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPropertyStore PTR
	GetPropertyStoreForKeys PTR
ENDS

#define GUID_IID_IDelayedPropertyStoreFactory <0x40d4577f,0xe237,0x4bdb,<0xbd,0x69,0x58,0xf0,0x89,0x43,0x1b,0x6a>>

IDelayedPropertyStoreFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPropertyStore PTR
	GetPropertyStoreForKeys PTR
	GetDelayedPropertyStore PTR
ENDS

FPSPS_DEFAULT	= 0
FPSPS_READONLY	= 0x1

#define GUID_IID_IPersistSerializedPropStorage <0xe318ad57,0x0aa0,0x450f,<0xac,0xa5,0x6f,0xab,0x71,0x03,0xd9,0x17>>

IPersistSerializedPropStorage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFlags PTR
	SetPropertyStorage PTR
	GetPropertyStorage PTR
ENDS

#define GUID_IID_IPersistSerializedPropStorage2 <0x77effa68,0x4f98,0x4366,<0xba,0x72,0x57,0x3b,0x3d,0x88,0x05,0x71>>

IPersistSerializedPropStorage2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFlags PTR
	SetPropertyStorage PTR
	GetPropertyStorage PTR
	GetPropertyStorageSize PTR
	GetPropertyStorageBuffer PTR
ENDS

#define GUID_IID_IPropertySystemChangeNotify <0xfa955fd9,0x38be,0x4879,<0xa6,0xce,0x82,0x4c,0xf5,0x2d,0x60,0x9f>>

IPropertySystemChangeNotify STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SchemaRefreshed PTR
ENDS

#define GUID_IID_ICreateObject <0x75121952,0xe0d0,0x43e5,<0x93,0x80,0x1d,0x80,0x48,0x3a,0xcf,0x72>>

ICreateObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateObject PTR
ENDS

#define GUID_CLSID_InMemoryPropertyStore <0x9a02e012,0x6303,0x4e1e,<0xb9,0xa1,0x63,0x0f,0x80,0x25,0x92,0xc5>>

#define GUID_CLSID_PropertySystem <0xb8967f85,0x58ae,0x4f46,<0x9f,0xb2,0x5d,0x79,0x04,0x79,0x8f,0x4b>>

#endif



