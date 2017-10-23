
#IFNDEF MSHELPSERVICES_H
#DEFINE MSHELPSERVICES_H

#define GUID_TLBID_MSHelpServices <0x31411197,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

/*
library MSHelpServices
{
    // TLib :     // TLib : OLE Automation : {00020430-0000-0000-C000-000000000046}
    importlib("STDOLE2.TLB");

    // Forward declare all types defined in this typelib
    interface IHxHierarchy;
    interface IHxTopic;
    interface IHxAttributeList;
    interface IHxAttribute;
    interface IEnumHxAttribute;
    interface IHxRegister;
    interface IHxIndex;
    interface IHxSession;
    interface IHxTopicList;
    interface IEnumHxTopic;
    interface IHxQuery;
    interface IHxCollection;
    interface IHxAttrNameList;
    interface IHxAttrName;
    interface IHxAttrValueList;
    interface IHxAttrValue;
    interface IEnumHxAttrValue;
    interface IEnumHxAttrName;
    interface IHxFilters;
    interface IHxRegFilterList;
    interface IHxRegFilter;
    interface IEnumHxRegFilter;
    interface IHxSampleCollection;
    interface IHxSample;
    interface IHxRegistryWalker;
    interface IHxRegNamespaceList;
    interface IHxRegNamespace;
    interface IEnumHxRegNamespace;
    interface IHxRegTitle;
    interface IHxRegTitleList;
    interface IEnumHxRegTitle;
    interface IHxRegPlugIn;
    interface IHxRegPlugInList;
    interface IEnumHxRegPlugIn;
    interface IHxRegisterSession;
    interface IHxPlugIn;
    interface IHxInitialize;
    interface IHxCancel;
    dispinterface IHxSessionEvents;
    dispinterface IHxRegisterSessionEvents;
    interface IHxRegisterProtocol;
*/

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define GUID_IID_IHxHierarchy <0x314111B2,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxHierarchy STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetRoot PTR
	GetParent PTR
	GetSibling PTR
	GetFirstChild PTR
	GetNextFromUrl PTR
	GetPrevFromUrl PTR
	GetType PTR
	IsNew PTR
	HasChild PTR
	GetSyncInfo PTR
	GetTitle PTR
	GetImageIndexes PTR
	GetURL PTR
	OnNavigation PTR
	OnHierarchyNavigation PTR
	GetProperty PTR
	GetNextFromNode PTR
	GetPrevFromNode PTR
	GetTopic PTR
	GetOpenImageIndex PTR
	GetClosedImageIndex PTR
	PrintNode PTR
ENDS

HxHierarchy_Book = 3
HxHierarchy_BookPage = 4
HxHierarchy_Page = 5
HxHierarchy_Unknown = 8

HxHierarchyTocFont = 0
HxHierarchyTocFontSize = 1
HxHierarchyTocLangId = 2
HxHierarchyTocCharSet = 3
HxHierarchyTocId = 4
HxHierarchyTocFileVer = 5
HxHierarchyTocIconFile = 6
HxHierarchyTocParentNodeIcon = 7
HxHierarchyTocIcon = 8

#define GUID_IID_IHxTopic <0x31411196,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxTopic STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Title PTR
	URL PTR
	Location PTR
	Rank PTR
	Attributes PTR
	GetInfo PTR
	GetProperty PTR
	SetProperty PTR
	HasAttribute PTR
	HasAttrName PTR
	HighlightDocument PTR
ENDS

HxTopicGetTOCTitle = 0
HxTopicGetRLTitle = 1
HxTopicGetHTMTitle = 2

HxTopicGetTitleFullURL = 0
HxTopicGetTitleFileName = 1
HxTopicGetTitleNoDefault = 2

#define GUID_IID_IHxAttributeList <0x314111AB,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxAttributeList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Count PTR
	ItemAt PTR
	EnumAttribute PTR
	_NewEnum PTR
	Item PTR
ENDS

#define GUID_IID_IHxAttribute <0x314111A9,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxAttribute STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetProperty PTR
	SetProperty PTR
	Name PTR
	Value PTR
	DisplayName PTR
	DisplayValue PTR
ENDS

HxPropIdQueryFirst = 0

#define GUID_IID_IEnumHxAttribute <0x314111AD,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IEnumHxAttribute STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
	Skip PTR
	Clone PTR
ENDS

HxTopicPropIdFirst = 0

HxHierarchy_PrintNode_Option_Node = 0
HxHierarchy_PrintNode_Option_Children = 1

#define GUID_IID_IHxRegister <0x314111BC,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegister STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	RegisterNamespace PTR
	IsNamespace PTR
	GetCollection PTR
	GetDescription PTR
	RemoveNamespace PTR
	RegisterHelpFile PTR
	RegisterMedia PTR
	RemoveHelpFile PTR
	RegisterHelpFileSet PTR
ENDS

#define GUID_IID_IHxIndex <0x314111CC,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxIndex STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetSession PTR
	Count PTR
	GetStringFromSlot PTR
	GetLevelFromSlot PTR
	GetSlotFromString PTR
	GetTopicsFromSlot PTR
	GetTopicsFromString PTR
	GetInfoFromSlot PTR
	GetProperty PTR
	GetCrossRef PTR
	GetFullStringFromSlot PTR
	GetCrossRefSlot PTR
ENDS

#define GUID_IID_IHxSession <0x31411192,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxSession STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Initialize PTR
	Query PTR
	QueryForTopic PTR
	QueryForUrl PTR
	GetNavigationInterface PTR
	GetNavigationObject PTR
	GetQueryObject PTR
	Collection PTR
	get_LangId PTR
	put_LangId PTR
	GetFilterList PTR
ENDS

#define GUID_IID_IHxTopicList <0x31411194,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxTopicList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Item PTR
	ItemAt PTR
	EnumTopics PTR
	_NewEnum PTR
	Count PTR
ENDS

#define GUID_IID_IEnumHxTopic <0x31411195,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IEnumHxTopic STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
	Skip PTR
	Clone PTR
ENDS

#define GUID_IID_IHxQuery <0x31411193,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxQuery STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Query PTR
	QueryForTopic PTR
	QueryForUrl PTR
ENDS

HxQuery_No_Option = 0
HxQuery_FullTextSearch_Title_Only = 1
HxQuery_FullTextSearch_Enable_Stemming = 2
HxQuery_FullTextSearch_SearchPrevious = 4
HxQuery_KeywordSearch_CaseSensitive = 10
HxQuery_KeywordSearch_AllowDuplicates = 16
HxQuery_FullTextSearch_Wildcard_Preserve = 128
HxQuery_FullTextSearch_ReturnRanking = 256
HxQuery_FullTextSearch_MinImprovements = 512

#define GUID_IID_IHxCollection <0x314111A1,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetProperty PTR
	SetProperty PTR
	URL PTR
	AttributeNames PTR
	Filters PTR
	Title PTR
	MergeIndex PTR
	GetFilterTopicCount PTR
ENDS

HxCollectionProp_NamespaceName = 1
HxCollectionProp_Font = 2
HxCollectionProp_FontSize = 3
HxCollectionProp_LangId = 4
HxCollectionProp_CharSet = 5
HxCollectionProp_Id = 6
HxCollectionProp_FileVer = 7
HxCollectionProp_CopyRight = 8

#define GUID_IID_IHxAttrNameList <0x314111CE,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxAttrNameList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	ItemAt PTR
	EnumAttrName PTR
	NewEnum PTR
	Item PTR
ENDS

#define GUID_IID_IHxAttrName <0x314111D2,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxAttrName STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetProperty PTR
	SetProperty PTR
	Name PTR
	DisplayName PTR
	Flag PTR
	AttributeValues PTR
ENDS

#define GUID_IID_IHxAttrValueList <0x314111D4,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxAttrValueList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Count PTR
	ItemAt PTR
	EnumAttrValue PTR
	_NewEnum PTR
	Item PTR
ENDS

#define GUID_IID_IHxAttrValue <0x314111D8,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxAttrValue STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetProperty PTR
	SetProperty PTR
	Value PTR
	DisplayValue PTR
	Flag PTR
ENDS

#define GUID_IID_IEnumHxAttrValue <0x314111D6,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IEnumHxAttrValue STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
	Skip PTR
	Clone PTR
ENDS

#define GUID_IID_IEnumHxAttrName <0x314111D0,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IEnumHxAttrName STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
	Skip PTR
	Clone PTR
ENDS

#define GUID_IID_IHxFilters <0x314111E3,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxFilters STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Count PTR
	GetFilter PTR
	GetFilterName PTR
	GetFilterQuery PTR
	RegisterFilter PTR
	RemoveFilter PTR
	FindFilter PTR
	SetNamespace PTR
	SetCollectionFiltersFlag PTR
ENDS

#define GUID_IID_IHxRegFilterList <0x31411212,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegFilterList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Item PTR
	ItemAt PTR
	EnumRegFilter PTR
	_NewEnum PTR
	Count PTR
	FindFilter PTR
ENDS

#define GUID_IID_IHxRegFilter <0x31411221,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegFilter STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetProperty PTR
ENDS

HxRegFilterName = 0
HxRegFilterQuery = 1

#define GUID_IID_IEnumHxRegFilter <0x3141121C,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IEnumHxRegFilter STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
	Skip PTR
	Clone PTR
ENDS

HxIndexFont = 0
HxIndexFontSize = 1
HxIndexLangId = 2
HxIndexCharSet = 3
HxIndexTitleStr = 4
HxIndexIsVisible = 5
HxIndexId = 6

#define GUID_IID_IHxSampleCollection <0x314111E6,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxSampleCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetSampleFromId PTR
ENDS

#define GUID_IID_IHxSample <0x314111E8,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxSample STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	SampleId PTR
	LoadString PTR
	DestinationDir PTR
	ProjectFileExt PTR
	FileCount PTR
	GetFileNameAtIndex PTR
	CopyFileAtIndex PTR
	ChooseDirectory PTR
	GetFileTextAtIndex PTR
ENDS

HxSampleFileCopyNoOption = 0
HxSampleFileCopyOverwrite = 1
HxSampleFileCopyFileOnly = 2

#define GUID_IID_IHxRegistryWalker <0x314111EF,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegistryWalker STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	RegisteredNamespaceList PTR
ENDS

#define GUID_IID_IHxRegNamespaceList <0x314111F3,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegNamespaceList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Item PTR
	ItemAt PTR
	EnumRegNamespace PTR
	_NewEnum PTR
	Count PTR
ENDS

#define GUID_IID_IHxRegNamespace <0x314111F1,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegNamespace STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Name PTR
	GetProperty PTR
	IsTitle PTR
ENDS

HxRegNamespaceTitleList = 0
HxRegNamespacePlugInList = 1
HxRegNamespaceName = 2
HxRegNamespaceCollection = 3
HxRegNamespaceDescription = 4
HxRegNamespaceFilterList = 8

#define GUID_IID_IEnumHxRegNamespace <0x314111F5,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IEnumHxRegNamespace STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
	Skip PTR
	Clone PTR
ENDS

#define GUID_IID_IHxRegTitle <0x31411202,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegTitle STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetProperty PTR
ENDS

HxRegTitleFileName = 0
HxRegTitleIndexName = 1
HxRegTitleQueryName = 2
HxRegTitleId = 3
HxRegTitleLangId = 4
HxRegAttrQueryName = 5
HxRegTitleHxsMediaLoc = 6
HxRegTitleHxqMediaLoc = 7
HxRegTitleHxrMediaLoc = 8
HxRegTitleSampleMediaLoc = 9

#define GUID_IID_IHxRegTitleList <0x31411203,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegTitleList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Item PTR
	ItemAt PTR
	EnumRegTitle PTR
	_NewEnum PTR
	Count PTR
ENDS

#define GUID_IID_IEnumHxRegTitle <0x31411204,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IEnumHxRegTitle STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
	Skip PTR
	Clone PTR
ENDS

#define GUID_IID_IHxRegPlugIn <0x3141120A,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegPlugIn STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetProperty PTR
ENDS

HxRegPlugInName = 0

#define GUID_IID_IHxRegPlugInList <0x3141120B,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegPlugInList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Item PTR
	ItemAt PTR
	EnumRegPlugIn PTR
	_NewEnum PTR
	Count PTR
ENDS

#define GUID_IID_IEnumHxRegPlugIn <0x3141120C,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IEnumHxRegPlugIn STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Reset PTR
	Skip PTR
	Clone PTR
ENDS

#define GUID_IID_IHxRegisterSession <0x31411218,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegisterSession STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	CreateTransaction PTR
	PostponeTransaction PTR
	ContinueTransaction PTR
	CommitTransaction PTR
	RevertTransaction PTR
	GetRegistrationObject PTR
ENDS

HxRegisterSession_IHxRegister = 0
HxRegisterSession_IHxFilters = 1
HxRegisterSession_IHxPlugIn = 2

#define GUID_IID_IHxPlugIn <0x314111DA,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxPlugIn STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	RegisterHelpPlugIn PTR
	RemoveHelpPlugIn PTR
ENDS

#define GUID_IID_IHxInitialize <0x314111AE,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxInitialize STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Initialize PTR
	get_filter PTR
	put_filter PTR
ENDS

#define GUID_IID_IHxCancel <0x31411225,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxCancel STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Cancel PTR
	put_Cancel PTR
ENDS

HxCancelStatus_Continue = 0
HxCancelStatus_Cancel = 1

#define GUID_IID_IHxSessionEvents <0x314111ED,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxSessionEvents STRUCT
	QueryCancel PTR
	IndexMergeStatus PTR
	PrintMergeStatus PTR
	MergeIndexFileName PTR
ENDS

#define GUID_IID_IHxRegisterSessionEvents <0x31411223,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegisterSessionEvents STRUCT
	FiltersChanged PTR
ENDS

#define GUID_CLSID_HxSession <0x31411198,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>
#define GUID_CLSID_HxRegistryWalker <0x314111F0,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>
#define GUID_CLSID_HxRegisterSession <0x31411219,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>
#define GUID_CLSID_HxRegisterProtocol <0x31411228,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

#define GUID_IID_IHxRegisterProtocol <0x31411227,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxRegisterProtocol STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Register PTR
	Unregister PTR
ENDS

HxSearchMetaBegin = "[SrchMeta["
HxSearchMetaEnd = "]SrchMeta]"
HxSearchTocBegin = "[Toc["
HxSearchTocEnd = "]Toc]"
HxSearchInclBegin = "[Incl["
HxSearchInclEnd = "]Incl]"
HxSearchExclBegin = "[Excl["
HxSearchExclEnd = "]Excl]"

#define HXSESSION_VI_PROGID "HxDS.HxSession"
#define HXREGISTRYWALKER_VI_PROGID "HxDs.HxRegistryWalker"
#define HXREGISTERSESSION_VI_PROGID "HxDS.HxRegisterSession"
#define HXREGISTERPROTOCOL_VI_PROGID "HxDS.HxRegisterProtocol"

#define HXMONIKER_DEFTOC "!DefaultToc"
#define HXMONIKER_DEFFULLTEXTSRCH "!DefaultFullTextSearch"
#define HXMONIKER_DEFASSOCINDEX "!DefaultAssociativeIndex"
#define HXMONIKER_DEFKWRDINDEX "!DefaultKeywordIndex"
#define HXMONIKER_DEFCTXTWNDINDEX "!DefaultContextWindowIndex"
#define HXMONIKER_DEFSAMPLEINFO "!SampleInfo"

// Named URLs

#DEFINE NAMEDURL_ABOUTPAGEICON "AboutPageIcon"
#DEFINE NAMEDURL_NAVFAILPAGE "NavFailPage"
#DEFINE NAMEDURL_ABOUTPAGEINFO "AboutPageInfo"
#DEFINE NAMEDURL_DEFAULTPAGE "DefaultPage"
#DEFINE NAMEDURL_EMPTYINDEXTERM "EmptyIndexTerm"
#DEFINE NAMEDURL_FILTEREDITPAGE "FilterEditPage"
#DEFINE NAMEDURL_HOMEPAGE "HomePage"
#DEFINE NAMEDURL_PRODUCTID "ProductID"
#DEFINE NAMEDURL_REGISTEREDORGANIZATION1 "RegisteredOrganization1"
#DEFINE NAMEDURL_REGISTEREDUSER1 "RegisteredUser1"
#DEFINE NAMEDURL_SAMPLEDIRPAGE "SampleDirPage"


// Monikers
;<ItemMoniker Name="!DefaultToc" ProgId="HxDs.HxHierarchy" InitData=""/>
;<ItemMoniker Name="!DefaultFullTextSearch" ProgId="HxDs.HxFullTextSearch" InitData=""/>
;<ItemMoniker Name="!DefaultAssociativeIndex" ProgId="HxDs.HxIndex" InitData="A"/>
;<ItemMoniker Name="!DefaultKeywordIndex" ProgId="HxDs.HxIndex" InitData="K"/>
;<ItemMoniker Name="!DefaultContextWindowIndex" ProgId="HxDs.HxIndex" InitData="F"/>
;<ItemMoniker Name="!SampleInfo" ProgId="HxDs.HxSampleCollection" InitData=""/>

#ENDIF