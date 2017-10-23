#IFNDEF AHADMIN_H
#DEFINE AHADMIN_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF
#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

/* header files for imported files */
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF
#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#DEFINE GUID_IID_IAppHostMethodExtension <0x70184ac9,0x7673,0x4770,<0x96,0xb1,0x44,0x5c,0xe0,0x35,0xcf,0x70>>

IAppHostMethodExtension STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ProvideMethod PTR 
ENDS

#DEFINE GUID_IID_IAppHostPropertyExtension <0x88e220f3,0x33e8,0x4534,<0xaf,0xac,0xb4,0xa9,0x8e,0xcc,0xf9,0xae>>

IAppHostPropertyExtension STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ProvideGetProperty PTR
ENDS

#DEFINE GUID_IID_IAppHostElementExtension <0x518eb37d,0x1ff4,0x42dd,<0x86,0xc3,0x31,0x40,0xbc,0x35,0xb8,0x23>>

IAppHostElementExtension STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ProvideElement PTR
ENDS

#DEFINE GUID_IID_IAppHostMappingExtension <0x31a83ea0,0xc0e4,0x4a2c,<0x8a,0x01,0x35,0x3c,0xc2,0xa4,0xc6,0x0a>>

IAppHostMappingExtension STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSiteNameFromSiteId PTR
	GetSiteIdFromSiteName PTR
	GetSiteElementFromSiteId PTR
	MapPath PTR
ENDS

#DEFINE GUID_IID_IAppHostChildElementCollection <0x08a90f5f,0x0702,0x48d6,<0xb4,0x5f,0x02,0xa9,0x88,0x5a,0x97,0x68>>

IAppHostChildElementCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
ENDS

#DEFINE GUID_IID_IAppHostPropertyCollection <0x0191775e,0xbcff,0x445a,<0xb4,0xf4,0x3b,0xdd,0xa5,0x4e,0x28,0x16>>

IAppHostPropertyCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
ENDS

#DEFINE GUID_IID_IAppHostConfigLocationCollection <0x832a32f7,0xb3ea,0x4b8c,<0xb2,0x60,0x9a,0x29,0x23,0x00,0x11,0x84>>

IAppHostConfigLocationCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
	AddLocation PTR
	DeleteLocation PTR
	RenameLocation PTR
ENDS

#DEFINE GUID_IID_IAppHostMethodCollection <0xd6c7cd8f,0xbb8d,0x4f96,<0xb5,0x91,0xd3,0xa5,0xf1,0x32,0x02,0x69>>

IAppHostMethodCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
ENDS

#DEFINE GUID_IID_IAppHostElementSchemaCollection <0x0344cdda,0x151e,0x4cbf,<0x82,0xda,0x66,0xae,0x61,0xe9,0x77,0x54>>

IAppHostElementSchemaCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
ENDS

#DEFINE GUID_IID_IAppHostPropertySchemaCollection <0x8bed2c68,0xa5fb,0x4b28,<0x85,0x81,0xa0,0xdc,0x52,0x67,0x41,0x9f>>

IAppHostPropertySchemaCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
ENDS

#DEFINE GUID_IID_IAppHostConstantValueCollection <0x5b5a68e6,0x8b9f,0x45e1,<0x81,0x99,0xa9,0x5f,0xfc,0xcd,0xff,0xff>>

IAppHostConstantValueCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
ENDS

#DEFINE GUID_IID_IAppHostConstantValue <0x0716caf8,0x7d05,0x4a46,<0x80,0x99,0x77,0x59,0x4b,0xe9,0x13,0x94>>

IAppHostConstantValue STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	get_Value PTR
ENDS

#DEFINE GUID_IID_IAppHostPropertySchema <0x450386db,0x7409,0x4667,<0x93,0x5e,0x38,0x4d,0xbb,0xee,0x2a,0x9e>>

IAppHostPropertySchema STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	get_Type PTR
	get_DefaultValue PTR
	get_IsRequired PTR
	get_IsUniqueKey PTR
	get_IsCombinedKey PTR
	get_IsExpanded PTR
	get_ValidationType PTR
	get_ValidationParameter PTR
	GetMetadata PTR
	get_IsCaseSensitive PTR
	get_PossibleValues PTR
	get_DoesAllowInfinite PTR
	get_IsEncrypted PTR
	get_TimeSpanFormat PTR
ENDS

#DEFINE GUID_IID_IAppHostCollectionSchema <0xde095db1,0x5368,0x4d11,<0x81,0xf6,0xef,0xef,0x61,0x9b,0x7b,0xcf>>

IAppHostCollectionSchema STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_AddElementNames PTR
	GetAddElementSchema PTR
	get_RemoveElementSchema PTR
	get_ClearElementSchema PTR
	get_IsMergeAppend PTR
	GetMetadata PTR
	get_DoesAllowDuplicates PTR
ENDS

#DEFINE GUID_IID_IAppHostElementSchema <0xef13d885,0x642c,0x4709,<0x99,0xec,0xb8,0x95,0x61,0xc6,0xbc,0x69>>

IAppHostElementSchema STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	get_DoesAllowUnschematizedProperties PTR
	GetMetadata PTR
	get_CollectionSchema PTR
	get_ChildElementSchemas PTR
	get_PropertySchemas PTR
	get_IsCollectionDefault PTR
ENDS

#DEFINE GUID_IID_IAppHostMethodSchema <0x2d9915fb,0x9d42,0x4328,<0xb7,0x82,0x1b,0x46,0x81,0x9f,0xab,0x9e>>

IAppHostMethodSchema STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	get_InputSchema PTR
	get_OutputSchema PTR
	GetMetadata PTR
ENDS

#DEFINE GUID_IID_IAppHostMethodInstance <0xb80f3c42,0x60e0,0x4ae0,<0x90,0x07,0xf5,0x28,0x52,0xd3,0xdb,0xed>>

IAppHostMethodInstance STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Input PTR
	get_Output PTR
 	Execute PTR
	GetMetadata PTR
	SetMetadata PTR
ENDS

#DEFINE GUID_IID_IAppHostMethod <0x7883ca1c,0x1112,0x4447,<0x84,0xc3,0x52,0xfb,0xeb,0x38,0x06,0x9d>>

IAppHostMethod STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	get_Schema PTR
	CreateInstance PTR
ENDS

#DEFINE GUID_IID_IAppHostConfigException <0x4dfa1df3,0x8900,0x4bc7,<0xbb,0xb5,0xd1,0xa4,0x58,0xc5,0x24,0x10>>

IAppHostConfigException STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_LineNumber PTR
	get_FileName PTR
	get_ConfigPath PTR
	get_ErrorLine PTR
	get_PreErrorLine PTR
	get_PostErrorLine PTR
	get_ErrorString PTR
ENDS

#DEFINE GUID_IID_IAppHostPropertyException <0xeafe4895,0xa929,0x41ea,<0xb1,0x4d,0x61,0x3e,0x23,0xf6,0x2b,0x71>>

IAppHostPropertyException STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_LineNumber PTR
	get_FileName PTR
	get_ConfigPath PTR
	get_ErrorLine PTR
	get_PreErrorLine PTR
	get_PostErrorLine PTR
	get_ErrorString PTR
	get_InvalidValue PTR
	get_ValidationFailureReason PTR
	get_ValidationFailureParameters PTR
ENDS

#DEFINE GUID_IID_IAppHostElementCollection <0xc8550bff,0x5281,0x4b1e,<0xac,0x34,0x99,0xb6,0xfa,0x38,0x46,0x4d>>

IAppHostElementCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
	AddElement PTR
	DeleteElement PTR
	Clear PTR
	CreateNewElement PTR
	get_Schema PTR
ENDS

#DEFINE GUID_IID_IAppHostElement <0x64ff8ccc,0xb287,0x4dae,<0xb0,0x8a,0xa7,0x2c,0xbf,0x45,0xf4,0x53>>

IAppHostElement STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	get_Collection PTR
	get_Properties PTR
	get_ChildElements PTR
	GetMetadata PTR
	SetMetadata PTR
	get_Schema PTR
	GetElementByName PTR
	GetPropertyByName PTR
	Clear PTR
	get_Methods PTR
ENDS

#DEFINE GUID_IID_IAppHostProperty <0xed35f7a1,0x5024,0x4e7b,<0xa4,0x4d,0x07,0xdd,0xaf,0x4b,0x52,0x4d>>

IAppHostProperty STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	get_Value PTR
	put_Value PTR
	Clear PTR
	get_StringValue PTR
	get_Exception PTR
	GetMetadata PTR
	SetMetadata PTR
	get_Schema PTR
ENDS

#DEFINE GUID_IID_IAppHostConfigLocation <0x370af178,0x7758,0x4dad,<0x81,0x46,0x73,0x91,0xf6,0xe1,0x85,0x85>>

IAppHostConfigLocation STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Path PTR
	get_Count PTR
	get_Item PTR
	AddConfigSection PTR
	DeleteConfigSection PTR
ENDS

#DEFINE GUID_IID_IAppHostSectionDefinition <0xc5c04795,0x321c,0x4014,<0x8f,0xd6,0xd4,0x46,0x58,0x79,0x93,0x93>>

IAppHostSectionDefinition STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	get_Type PTR
	put_Type PTR
	get_OverrideModeDefault PTR
	put_OverrideModeDefault PTR
	get_AllowDefinition PTR
	put_AllowDefinition PTR
	get_AllowLocation PTR
	put_AllowLocation PTR
	get_RequirePermission PTR
	put_RequirePermission PTR
ENDS

#DEFINE GUID_IID_IAppHostSectionDefinitionCollection <0xb7d381ee,0x8860,0x47a1,<0x8a,0xf4,0x1f,0x33,0xb2,0xb1,0xf3,0x25>>

IAppHostSectionDefinitionCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
	AddSection PTR
	DeleteSection PTR
ENDS

#DEFINE GUID_IID_IAppHostSectionGroup <0x0dd8a158,0xebe6,0x4008,<0xa1,0xd9,0xb7,0xec,0xc8,0xf1,0x10,0x4b>>

IAppHostSectionGroup STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Count PTR
	get_Item PTR
	get_Sections PTR
	AddSectionGroup PTR
	DeleteSectionGroup PTR
	get_Name PTR
	get_Type PTR
	put_Type PTR
ENDS

#DEFINE GUID_IID_IAppHostConfigFile <0xada4e6fb,0xe025,0x401e,<0xa5,0xd0,0xc3,0x13,0x4a,0x28,0x1f,0x07>>

IAppHostConfigFile STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_ConfigPath PTR
	get_FilePath PTR
	get_Locations PTR
	GetAdminSection PTR
	GetMetadata PTR
	SetMetadata PTR
	ClearInvalidSections PTR
	get_RootSectionGroup PTR
ENDS

#DEFINE GUID_IID_IAppHostPathMapper <0xe7927575,0x5cc3,0x403b,<0x82,0x2e,0x32,0x8a,0x6b,0x90,0x4b,0xee>>

IAppHostPathMapper STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	MapPath PTR
ENDS

#DEFINE GUID_IID_IAppHostPathMapper2 <0x0f80e901,0x8f4c,0x449a,<0xbf,0x90,0x13,0xd5,0xd0,0x82,0xf1,0x87>>

IAppHostPathMapper2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	MapPath PTR
ENDS

#DEFINE GUID_IID_IAppHostChangeHandler <0x09829352,0x87c2,0x418d,<0x8d,0x79,0x41,0x33,0x96,0x9a,0x48,0x9d>>

IAppHostChangeHandler STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnSectionChanges PTR
ENDS

#DEFINE GUID_IID_IAppHostAdminManager <0x9be77978,0x73ed,0x4a9a,<0x87,0xfd,0x13,0xf0,0x9f,0xec,0x1b,0x13>>

IAppHostAdminManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetAdminSection PTR
	GetMetadata PTR
	SetMetadata PTR
	get_ConfigManager PTR
ENDS

#DEFINE GUID_IID_IAppHostWritableAdminManager <0xfa7660f6,0x7b3f,0x4237,<0xa8,0xbf,0xed,0x0a,0xd0,0xdc,0xbb,0xd9>>

IAppHostWritableAdminManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetAdminSection PTR
	GetMetadata PTR
	SetMetadata PTR
	get_ConfigManager PTR
	CommitChanges PTR
	get_CommitPath PTR
	put_CommitPath PTR
ENDS

#DEFINE GUID_IID_IAppHostConfigManager <0x8f6d760f,0xf0cb,0x4d69,<0xb5,0xf6,0x84,0x8b,0x33,0xe9,0xbd,0xc6>>

IAppHostConfigManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetConfigFile PTR
	GetUniqueConfigPath PTR
ENDS

#DEFINE GUID_CLSID_AppHostAdminManager <0x228fb8f7,0xfb53,0x4fd5,<0x8c,0x7b,0xff,0x59,0xde,0x60,0x6c,0x5b>>

#DEFINE GUID_CLSID_AppHostWritableAdminManager <0x2b72133b,0x3f5b,0x4602,<0x89,0x52,0x80,0x35,0x46,0xce,0x33,0x44>>

#endif



