
#IFNDEF SEARCHAPI_H
#DEFINE SEARCHAPI_H

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
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF
#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF
#IFNDEF PROPIDL_H
	#include "propidl.h"
#ENDIF
#IFNDEF FILTER_H
	#include "filter.h"
#ENDIF
#IFNDEF FILTEREG_H
	#include "filtereg.h"
#ENDIF
#IFNDEF PROPSYS_H
	#include "propsys.h"
#ENDIF
#IFNDEF OLEDB_H
	#include "oledb.h"
#ENDIF
#IFNDEF STRUCTUREDQUERY_H
	#include "StructuredQuery.h"
#ENDIF


//+----------------------------------------------------------------------------
//
//    Copyright (c) 2005 Microsoft Corporation.
//    Search API Interface
//
//-----------------------------------------------------------------------------

#DEFINE GUID_IID_IUrlAccessor <0x0b63e318,0x9ccc,0x11d0,<0xbc,0xdb,0x00,0x80,0x5f,0xcc,0xce,0x04>>

IUrlAccessor STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddRequestParameter PTR
	GetDocFormat PTR
	GetCLSID PTR
	GetHost PTR
	IsDirectory PTR
	GetSize PTR
	GetLastModified PTR
	GetFileName PTR
	GetSecurityDescriptor PTR
	GetRedirectedURL PTR
	GetSecurityProvider PTR
	BindToStream PTR
	BindToFilter PTR
ENDS

#DEFINE GUID_IID_IUrlAccessor2 <0xc7310734,0xac80,0x11d1,<0x8d,0xf3,0x00,0xc0,0x4f,0xb6,0xef,0x4f>>

IUrlAccessor2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddRequestParameter PTR
	GetDocFormat PTR
	GetCLSID PTR
	GetHost PTR
	IsDirectory PTR
	GetSize PTR
	GetLastModified PTR
	GetFileName PTR
	GetSecurityDescriptor PTR
	GetRedirectedURL PTR
	GetSecurityProvider PTR
	BindToStream PTR
	BindToFilter PTR
	GetDisplayUrl PTR
	IsDocument PTR
	GetCodePage PTR
ENDS

#DEFINE GUID_IID_IUrlAccessor3 <0x6FBC7005,0x0455,0x4874,<0xB8,0xFF,0x74,0x39,0x45,0x02,0x41,0xA3>>

IUrlAccessor3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddRequestParameter PTR
	GetDocFormat PTR
	GetCLSID PTR
	GetHost PTR
	IsDirectory PTR
	GetSize PTR
	GetLastModified PTR
	GetFileName PTR
	GetSecurityDescriptor PTR
	GetRedirectedURL PTR
	GetSecurityProvider PTR
	BindToStream PTR
	BindToFilter PTR
	GetDisplayUrl PTR
	IsDocument PTR
	GetCodePage PTR
	GetImpersonationSidBlobs PTR
ENDS

#DEFINE GUID_IID_IUrlAccessor4 <0x5CC51041,0xC8D2,0x41d7,<0xBC,0xA3,0x9E,0x9E,0x28,0x62,0x97,0xDC>>

IUrlAccessor4 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddRequestParameter PTR
	GetDocFormat PTR
	GetCLSID PTR
	GetHost PTR
	IsDirectory PTR
	GetSize PTR
	GetLastModified PTR
	GetFileName PTR
	GetSecurityDescriptor PTR
	GetRedirectedURL PTR
	GetSecurityProvider PTR
	BindToStream PTR
	BindToFilter PTR
	GetDisplayUrl PTR
	IsDocument PTR
	GetCodePage PTR
	GetImpersonationSidBlobs PTR
	ShouldIndexItemContent PTR
	ShouldIndexProperty PTR
ENDS

#DEFINE GUID_IID_IOpLockStatus <0xc731065d,0xac80,0x11d1,<0x8d,0xf3,0x00,0xc0,0x4f,0xb6,0xef,0x4f>>

IOpLockStatus STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsOplockValid PTR
	IsOplockBroken PTR
	GetOplockEventHandle PTR
ENDS

#DEFINE GUID_IID_ISearchProtocolThreadContext <0xc73106e1,0xac80,0x11d1,<0x8d,0xf3,0x00,0xc0,0x4f,0xb6,0xef,0x4f>>

ISearchProtocolThreadContext STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ThreadInit PTR
	ThreadShutdown PTR
	ThreadIdle PTR
ENDS

TIMEOUT_INFO STRUCT
	dwSize DD
	dwConnectTimeout DD
	dwDataTimeout DD
ENDS

// PROXY_ACCESS enumeration
PROXY_ACCESS_PRECONFIG	= 0
PROXY_ACCESS_DIRECT	= 1
PROXY_ACCESS_PROXY	= 2

PROXY_INFO STRUCT
	dwSize DD
	pcwszUserAgent PTR
	paUseProxy ENUM
	fLocalBypass BOOL
	dwPortNumber DD
	pcwszProxyName PTR
	pcwszBypassList PTR
ENDS

// AUTH_TYPE enumeration
eAUTH_TYPE_ANONYMOUS = 0
eAUTH_TYPE_NTLM = 1
eAUTH_TYPE_BASIC = 2 

AUTHENTICATION_INFO STRUCT
	dwSize DD
	atAuthenticationType ENUM
	pcwszUser PTR
	pcwszPassword PTR
ENDS

INCREMENTAL_ACCESS_INFO STRUCT
	dwSize DD
	ftLastModifiedTime FILETIME
ENDS

ITEM_INFO STRUCT
	dwSize DD
	pcwszFromEMail PTR
	pcwszApplicationName PTR
	pcwszCatalogName PTR
	pcwszContentClass PTR
ENDS

#DEFINE GUID_IID_ISearchProtocol <0xc73106ba,0xac80,0x11d1,<0x8d,0xf3,0x00,0xc0,0x4f,0xb6,0xef,0x4f>>

ISearchProtocol STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
	CreateAccessor PTR
	CloseAccessor PTR
	ShutDown PTR
ENDS

#DEFINE GUID_IID_ISearchProtocol2 <0x7789F0B2,0xB5B2,0x4722,<0x8B,0x65,0x5D,0xBD,0x15,0x06,0x97,0xA9>>

ISearchProtocol2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
	CreateAccessor PTR
	CloseAccessor PTR
	ShutDown PTR
	CreateAccessorEx PTR
ENDS

#DEFINE GUID_IID_IProtocolHandlerSite <0x0b63e385,0x9ccc,0x11d0,<0xbc,0xdb,0x00,0x80,0x5f,0xcc,0xce,0x04>>

IProtocolHandlerSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetFilter PTR
ENDS

#DEFINE GUID_IID_ISearchRoot <0x04C18CCF,0x1F57,0x4CBD,<0x88,0xCC,0x39,0x00,0xF5,0x19,0x5C,0xE3>>

ISearchRoot STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	put_Schedule PTR
	get_Schedule PTR
	put_RootURL PTR
	get_RootURL PTR
	put_IsHierarchical PTR
	get_IsHierarchical PTR
	put_ProvidesNotifications PTR
	get_ProvidesNotifications PTR
	put_UseNotificationsOnly PTR
	get_UseNotificationsOnly PTR
	put_EnumerationDepth PTR
	get_EnumerationDepth PTR
	put_HostDepth PTR
	get_HostDepth PTR
	put_FollowDirectories PTR
	get_FollowDirectories PTR
	put_AuthenticationType PTR
	get_AuthenticationType PTR
	put_User PTR
	get_User PTR
	put_Password PTR
	get_Password PTR
ENDS

#DEFINE GUID_IID_IEnumSearchRoots <0xAB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x52>>

IEnumSearchRoots STRUCT
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

// FOLLOW_FLAGS enumeration
FF_INDEXCOMPLEXURLS	= 0x1
FF_SUPPRESSINDEXING	= 0x2

#DEFINE GUID_IID_ISearchScopeRule <0xB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x53>>

ISearchScopeRule STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_PatternOrURL PTR
	get_IsIncluded PTR
	get_IsDefault PTR
	get_FollowFlags PTR
ENDS

#DEFINE GUID_IID_IEnumSearchScopeRules <0xAB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x54>>

IEnumSearchScopeRules STRUCT
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
 
// CLUSION_REASON enumeration
CLUSIONREASON_UNKNOWNSCOPE	= 0
CLUSIONREASON_DEFAULT	= 1
CLUSIONREASON_USER	= 2
CLUSIONREASON_GROUPPOLICY	= 3

#DEFINE GUID_IID_ISearchCrawlScopeManager <0xAB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x55>>

ISearchCrawlScopeManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddDefaultScopeRule PTR
	AddRoot PTR
	RemoveRoot PTR
	EnumerateRoots PTR
	AddHierarchicalScope PTR
	AddUserScopeRule PTR
	RemoveScopeRule PTR
	EnumerateScopeRules PTR
	HasParentScopeRule PTR
	HasChildScopeRule PTR
	IncludedInCrawlScope PTR
	IncludedInCrawlScopeEx PTR
	RevertToDefaultScopes PTR
	SaveAll PTR
	GetParentScopeVersionId PTR
	RemoveDefaultScopeRule PTR
ENDS

#DEFINE GUID_IID_ISearchCrawlScopeManager2 <0x6292F7AD,0x4E19,0x4717,<0xA5,0x34,0x8F,0xC2,0x2B,0xCD,0x5C,0xCD>>

ISearchCrawlScopeManager2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddDefaultScopeRule PTR
	AddRoot PTR
	RemoveRoot PTR
	EnumerateRoots PTR
	AddHierarchicalScope PTR
	AddUserScopeRule PTR
	RemoveScopeRule PTR
	EnumerateScopeRules PTR
	HasParentScopeRule PTR
	HasChildScopeRule PTR
	IncludedInCrawlScope PTR
	IncludedInCrawlScopeEx PTR
	RevertToDefaultScopes PTR
	SaveAll PTR
	GetParentScopeVersionId PTR
	RemoveDefaultScopeRule PTR
	GetVersion PTR
ENDS

// SEARCH_KIND_OF_CHANGE enumeration
SEARCH_CHANGE_ADD	= 0
SEARCH_CHANGE_DELETE	= 1
SEARCH_CHANGE_MODIFY	= 2
SEARCH_CHANGE_MOVE_RENAME	= 3
SEARCH_CHANGE_SEMANTICS_DIRECTORY	= 0x40000
SEARCH_CHANGE_SEMANTICS_SHALLOW	= 0x80000
SEARCH_CHANGE_SEMANTICS_UPDATE_SECURITY	= 0x400000

// SEARCH_NOTIFICATION_PRIORITY enumeration
SEARCH_NORMAL_PRIORITY	= 0
SEARCH_HIGH_PRIORITY	= 1


SEARCH_ITEM_CHANGE STRUCT
	Change ENUM
	Priority ENUM
	pUserData PTR
	lpwszURL PTR
	lpwszOldURL PTR
ENDS

#DEFINE GUID_IID_ISearchItemsChangedSink <0xAB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x58>>

ISearchItemsChangedSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	StartedMonitoringScope PTR
	StoppedMonitoringScope PTR
	OnItemsChanged PTR
ENDS

SEARCH_ITEM_PERSISTENT_CHANGE STRUCT
	Change ENUM
	URL PTR
	OldURL PTR
	Priority ENUM
ENDS

#DEFINE GUID_IID_ISearchPersistentItemsChangedSink <0xA2FFDF9B,0x4758,0x4F84,<0xB7,0x29,0xDF,0x81,0xA1,0xA0,0x61,0x2F>>

ISearchPersistentItemsChangedSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	StartedMonitoringScope PTR
	StoppedMonitoringScope PTR
	OnItemsChanged PTR
ENDS

#DEFINE GUID_IID_ISearchViewChangedSink <0xAB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x65>>

ISearchViewChangedSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnChange PTR
ENDS

INLINE_NOTIFY_DATA_CHANGE_ENTRY STRUCT
	eChangeAdviseCode LONG
	pszPhysicalAddress PTR
	pUserData PTR
ENDS

#DEFINE GUID_IID_IGatherNotifyInline <0x7900F4F4,0xBA3F,0x4D53,<0x87,0x44,0x51,0x62,0x65,0x42,0x35,0x1A>>

IGatherNotifyInline STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
	OnDataChange PTR
ENDS

// SEARCH_INDEXING_PHASE enumeration
SEARCH_INDEXING_PHASE_GATHERER	= 0
SEARCH_INDEXING_PHASE_QUERYABLE	= 1
SEARCH_INDEXING_PHASE_PERSISTED	= 2

SEARCH_ITEM_INDEXING_STATUS STRUCT
	dwDocID DD
	hrIndexingStatus LONG
ENDS

#DEFINE GUID_IID_ISearchNotifyInlineSite <0xB5702E61,0xE75C,0x4B64,<0x82,0xA1,0x6C,0xB4,0xF8,0x32,0xFC,0xCF>>

ISearchNotifyInlineSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnItemIndexedStatusChange PTR
	OnCatalogStatusChange PTR
ENDS

#DEFINE GUID_IID_IGatherNotifyInlineInternal <0x2E5C2EC6,0x4FF9,0x44B7,<0x98,0x69,0x6A,0xF9,0xA8,0xD3,0xFD,0x67>>

IGatherNotifyInlineInternal STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterInlineNotificationClient PTR
	OnDataChangeInline PTR
	SendItemIndexedStatusChange PTR
	ReleaseInlineNotificationClient PTR
ENDS

#DEFINE GUID_IID_IGatherInlineStatus <0x2137B63B,0xBBB0,0x4bee,<0x94,0xB3,0x46,0x91,0xCC,0xEF,0x38,0x9A>>

IGatherInlineStatus STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SendInlineStatusChange PTR
ENDS

// CatalogStatus enumeration
CATALOG_STATUS_IDLE	= 0
CATALOG_STATUS_PAUSED	= 1
CATALOG_STATUS_RECOVERING	= 2
CATALOG_STATUS_FULL_CRAWL	= 3
CATALOG_STATUS_INCREMENTAL_CRAWL	= 4
CATALOG_STATUS_PROCESSING_NOTIFICATIONS	= 5
CATALOG_STATUS_SHUTTING_DOWN	= 6

// CatalogPausedReason enumeration
CATALOG_PAUSED_REASON_NONE	= 0
CATALOG_PAUSED_REASON_HIGH_IO	= 1
CATALOG_PAUSED_REASON_HIGH_CPU	= 2
CATALOG_PAUSED_REASON_HIGH_NTF_RATE	= 3
CATALOG_PAUSED_REASON_LOW_BATTERY	= 4
CATALOG_PAUSED_REASON_LOW_MEMORY	= 5
CATALOG_PAUSED_REASON_LOW_DISK	= 6
CATALOG_PAUSED_REASON_DELAYED_RECOVERY	= 7
CATALOG_PAUSED_REASON_USER_ACTIVE	= 8
CATALOG_PAUSED_REASON_EXTERNAL	= 9
CATALOG_PAUSED_REASON_UPGRADING	= 10

#DEFINE GUID_IID_ISearchCatalogManager <0xAB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x50>>

ISearchCatalogManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	GetParameter PTR
	SetParameter PTR
	GetCatalogStatus PTR
	Reset PTR
	Reindex PTR
	ReindexMatchingURLs PTR
	ReindexSearchRoot PTR
	put_ConnectTimeout PTR
	get_ConnectTimeout PTR
	put_DataTimeout PTR
	get_DataTimeout PTR
	NumberOfItems PTR
	NumberOfItemsToIndex PTR
	URLBeingIndexed PTR
	GetURLIndexingState PTR
	GetPersistentItemsChangedSink PTR
	RegisterViewForNotification PTR
	GetItemsChangedSink PTR
	UnregisterViewForNotification PTR
	SetExtensionClusion PTR
	EnumerateExcludedExtensions PTR
	GetQueryHelper PTR
	put_DiacriticSensitivity PTR
	get_DiacriticSensitivity PTR
	GetCrawlScopeManager PTR
ENDS

// PRIORITIZE_FLAGS enumeration
PRIORITIZE_FLAG_RETRYFAILEDITEMS	= 0x1
PRIORITIZE_FLAG_IGNOREFAILURECOUNT	= 0x2

#DEFINE GUID_IID_ISearchCatalogManager2 <0x7AC3286D,0x4D1D,0x4817,<0x84,0xFC,0xC1,0xC8,0x5E,0x3A,0xF0,0xD9>>

ISearchCatalogManager2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_Name PTR
	GetParameter PTR
	SetParameter PTR
	GetCatalogStatus PTR
	Reset PTR
	Reindex PTR
	ReindexMatchingURLs PTR
	ReindexSearchRoot PTR
	put_ConnectTimeout PTR
	get_ConnectTimeout PTR
	put_DataTimeout PTR
	get_DataTimeout PTR
	NumberOfItems PTR
	NumberOfItemsToIndex PTR
	URLBeingIndexed PTR
	GetURLIndexingState PTR
	GetPersistentItemsChangedSink PTR
	RegisterViewForNotification PTR
	GetItemsChangedSink PTR
	UnregisterViewForNotification PTR
	SetExtensionClusion PTR
	EnumerateExcludedExtensions PTR
	GetQueryHelper PTR
	put_DiacriticSensitivity PTR
	get_DiacriticSensitivity PTR
	GetCrawlScopeManager PTR
	PrioritizeMatchingURLs PTR
ENDS

// SEARCH_TERM_EXPANSION enumeration
SEARCH_TERM_NO_EXPANSION	= 0
SEARCH_TERM_PREFIX_ALL	= 1
SEARCH_TERM_STEM_ALL	= 2

// SEARCH_QUERY_SYNTAX enumeration
SEARCH_NO_QUERY_SYNTAX	= 0
SEARCH_ADVANCED_QUERY_SYNTAX	= 1
SEARCH_NATURAL_QUERY_SYNTAX	= 2

SEARCH_COLUMN_PROPERTIES STRUCT
	Value PROPVARIANT
	lcid LCID
ENDS

#DEFINE GUID_IID_ISearchQueryHelper <0xAB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x63>>

ISearchQueryHelper STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_ConnectionString PTR
	put_QueryContentLocale PTR
	get_QueryContentLocale PTR
	put_QueryKeywordLocale PTR
	get_QueryKeywordLocale PTR
	put_QueryTermExpansion PTR
	get_QueryTermExpansion PTR
	put_QuerySyntax PTR
	get_QuerySyntax PTR
	put_QueryContentProperties PTR
	get_QueryContentProperties PTR
	put_QuerySelectColumns PTR
	get_QuerySelectColumns PTR
	put_QueryWhereRestrictions PTR
	get_QueryWhereRestrictions PTR
	put_QuerySorting PTR
	get_QuerySorting PTR
	GenerateSQLFromUserQuery PTR
	WriteProperties PTR
	put_QueryMaxResults PTR
	get_QueryMaxResults PTR
ENDS

// PRIORITY_LEVEL enumeration
PRIORITY_LEVEL_FOREGROUND	= 0
PRIORITY_LEVEL_HIGH	= 1
PRIORITY_LEVEL_LOW	= 2
PRIORITY_LEVEL_DEFAULT	= 3

#DEFINE GUID_IID_IRowsetPrioritization <0x42811652,0x079D,0x481B,<0x87,0xA2,0x09,0xA6,0x9E,0xCC,0x5F,0x44>>

IRowsetPrioritization STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetScopePriority PTR
	GetScopePriority PTR
	GetScopeStatistics PTR
ENDS

// ROWSETEVENT_ITEMSTATE enumeration
ROWSETEVENT_ITEMSTATE_NOTINROWSET	= 0
ROWSETEVENT_ITEMSTATE_INROWSET	= 1
ROWSETEVENT_ITEMSTATE_UNKNOWN	= 2

// ROWSETEVENT_TYPE enumeration
ROWSETEVENT_TYPE_DATAEXPIRED	= 0
ROWSETEVENT_TYPE_FOREGROUNDLOST	= 1
ROWSETEVENT_TYPE_SCOPESTATISTICS	= 2

#DEFINE GUID_IID_IRowsetEvents <0x1551AEA5,0x5D66,0x4B11,<0x86,0xF5,0xD5,0x63,0x4C,0xB2,0x11,0xB9>>

IRowsetEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnNewItem PTR
	OnChangedItem PTR
	OnDeletedItem PTR
	OnRowsetEvent PTR
ENDS

#DEFINE GUID_IID_ISearchManager <0xAB310581,0xAC80,0x11D1,<0x8D,0xF3,0x00,0xC0,0x4F,0xB6,0xEF,0x69>>

ISearchManager STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetIndexerVersionStr PTR
	GetIndexerVersion PTR
	GetParameter PTR
	SetParameter PTR
	get_ProxyName PTR
	get_BypassList PTR
	SetProxy PTR
	GetCatalog PTR
	get_UserAgent PTR
	put_UserAgent PTR
	get_UseProxy PTR
	get_LocalBypass PTR
	get_PortNumber PTR
ENDS

#DEFINE GUID_CLSID_CSearchLanguageSupport <0x6A68CC80,0x4337,0x4dbc,<0xBD,0x27,0xFB,0xFB,0x10,0x53,0x82,0x0B>>

#DEFINE GUID_IID_ISearchLanguageSupport <0x24C3CBAA,0xEBC1,0x491a,<0x9E,0xF1,0x9F,0x6D,0x8D,0xEB,0x1B,0x8F>>

ISearchLanguageSupport STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetDiacriticSensitivity PTR
	GetDiacriticSensitivity PTR
	LoadWordBreaker PTR
	LoadStemmer PTR
	IsPrefixNormalized PTR
ENDS

#DEFINE GUID_CLSID_CSearchManager <0x7D096C5F,0xAC08,0x4f1f,<0xBE,0xB7,0x5C,0x22,0xC5,0x17,0xCE,0x39>>

#DEFINE GUID_CLSID_CSearchRoot <0x30766BD2,0xEA1C,0x4F28,<0xBF,0x27,0x0B,0x44,0xE2,0xF6,0x8D,0xB7>>

#DEFINE GUID_CLSID_CSearchScopeRule <0xE63DE750,0x3BD7,0x4BE5,<0x9C,0x84,0x6B,0x42,0x81,0x98,0x8C,0x44>>

#DEFINE GUID_CLSID_FilterRegistration <0x9E175B8D,0xF52A,0x11D8,<0xB9,0xA5,0x50,0x50,0x54,0x50,0x30,0x30>>

#endif



