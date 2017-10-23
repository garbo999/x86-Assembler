#IFNDEF MSXML_H
#DEFINE MSXML_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF
#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

/* header files for imported files */
#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

XML_ERROR STRUCT
	_nLine DD
	_pchBuf PTR
	_cchBuf DD
	_ich DD
	_pszFound PTR
	_pszExpected PTR
	_reserved1 DD
	_reserved2 DD
ENDS

NODE_INVALID	= 0
NODE_ELEMENT	= 1
NODE_ATTRIBUTE	= 2
NODE_TEXT	= 3
NODE_CDATA_SECTION	= 4
NODE_ENTITY_REFERENCE	= 5
NODE_ENTITY	= 6
NODE_PROCESSING_INSTRUCTION	= 7
NODE_COMMENT	= 8
NODE_DOCUMENT	= 9
NODE_DOCUMENT_TYPE	= 10
NODE_DOCUMENT_FRAGMENT	= 11
NODE_NOTATION	= 12

XMLELEMTYPE_ELEMENT	= 0
XMLELEMTYPE_TEXT	= 1
XMLELEMTYPE_COMMENT	= 2
XMLELEMTYPE_DOCUMENT	= 3
XMLELEMTYPE_DTD	= 4
XMLELEMTYPE_PI	= 5
XMLELEMTYPE_OTHER	= 6

#DEFINE GUID_IID_IXMLDOMImplementation <0x2933BF8F,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMImplementation STRUCT
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
	hasFeature PTR
ENDS

#DEFINE GUID_IID_IXMLDOMNode <0x2933BF80,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMNode STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
ENDS

#DEFINE GUID_IID_IXMLDOMDocumentFragment <0x3efaa413,0x272f,0x11d2,<0x83,0x6f,0x00,0x00,0xf8,0x7a,0x77,0x82>>

IXMLDOMDocumentFragment STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
ENDS

#DEFINE GUID_IID_IXMLDOMDocument <0x2933BF81,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMDocument STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_doctype PTR
	get_implementation PTR
	get_documentElement PTR
	putref_documentElement PTR
	createElement PTR
	createDocumentFragment PTR
	createTextNode PTR
	createComment PTR
	createCDATASection PTR
	createProcessingInstruction PTR
	createAttribute PTR
	createEntityReference PTR
	getElementsByTagName PTR
	createNode PTR
	nodeFromID PTR
	load PTR
	get_readyState PTR
	get_parseError PTR
	get_url PTR
	get_async PTR
	put_async PTR
	abort PTR
	loadXML PTR
	save PTR
	get_validateOnParse PTR
	put_validateOnParse PTR
	get_resolveExternals PTR
	put_resolveExternals PTR
	get_preserveWhiteSpace PTR
	put_preserveWhiteSpace PTR
	put_onreadystatechange PTR
	put_ondataavailable PTR
	put_ontransformnode PTR
ENDS


#DEFINE GUID_IID_IXMLDOMNodeList <0x2933BF82,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMNodeList STRUCT
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
	get_item PTR
	get_length PTR
	nextNode PTR
	reset PTR
	get__newEnum PTR
ENDS


#DEFINE GUID_IID_IXMLDOMNamedNodeMap <0x2933BF83,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMNamedNodeMap STRUCT
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
	getNamedItem PTR
	setNamedItem PTR
	removeNamedItem PTR
	get_item PTR
	get_length PTR
	getQualifiedItem PTR
	removeQualifiedItem PTR
	nextNode PTR
	reset PTR
	get__newEnum PTR
ENDS

#DEFINE GUID_IID_IXMLDOMCharacterData <0x2933BF84,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMCharacterData STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_data PTR
	put_data PTR
	get_length PTR
	substringData PTR
	appendData PTR
	insertData PTR
	deleteData PTR
	replaceData PTR
ENDS

#DEFINE GUID_IID_IXMLDOMAttribute <0x2933BF85,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMAttribute STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_name PTR
	get_value PTR
	put_value PTR
ENDS

#DEFINE GUID_IID_IXMLDOMElement <0x2933BF86,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMElement STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_tagName PTR
	getAttribute PTR
	setAttribute PTR
	removeAttribute PTR
	getAttributeNode PTR
	setAttributeNode PTR
	removeAttributeNode PTR
	getElementsByTagName PTR
	normalize PTR
ENDS

#DEFINE GUID_IID_IXMLDOMText <0x2933BF87,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMText STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_data PTR
	put_data PTR
	get_length PTR
	substringData PTR
	appendData PTR
	insertData PTR
	deleteData PTR
	replaceData PTR
	splitText PTR
ENDS

#DEFINE GUID_IID_IXMLDOMComment <0x2933BF88,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMComment STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_data PTR
	put_data PTR
	get_length PTR
	substringData PTR
	appendData PTR
	insertData PTR
	deleteData PTR
	replaceData PTR
ENDS

#DEFINE GUID_IID_IXMLDOMProcessingInstruction <0x2933BF89,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMProcessingInstruction STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_target PTR
	get_data PTR
	put_data PTR
ENDS

#DEFINE GUID_IID_IXMLDOMCDATASection <0x2933BF8A,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMCDATASection STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_data PTR
	put_data PTR
	get_length PTR
	substringData PTR
	appendData PTR
	insertData PTR
	deleteData PTR
	replaceData PTR
	splitText PTR
ENDS

#DEFINE GUID_IID_IXMLDOMDocumentType <0x2933BF8B,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMDocumentType STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_name PTR
	get_entities PTR
	get_notations PTR
ENDS

#DEFINE GUID_IID_IXMLDOMNotation <0x2933BF8C,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMNotation STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_publicId PTR
	get_systemId PTR
ENDS

#DEFINE GUID_IID_IXMLDOMEntity <0x2933BF8D,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMEntity STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	get_publicId PTR
	get_systemId PTR
	get_notationName PTR
ENDS

#DEFINE GUID_IID_IXMLDOMEntityReference <0x2933BF8E,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

IXMLDOMEntityReference STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
ENDS

#DEFINE GUID_IID_IXMLDOMParseError <0x3efaa426,0x272f,0x11d2,<0x83,0x6f,0x00,0x00,0xf8,0x7a,0x77,0x82>>

IXMLDOMParseError STRUCT
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
	get_errorCode PTR
	get_url PTR
	get_reason PTR
	get_srcText PTR
	get_line PTR
	get_linepos PTR
	get_filepos PTR
ENDS

#DEFINE GUID_IID_IXTLRuntime <0x3efaa425,0x272f,0x11d2,<0x83,0x6f,0x00,0x00,0xf8,0x7a,0x77,0x82>>

IXTLRuntime STRUCT
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
	get_nodeName PTR
	get_nodeValue PTR
	put_nodeValue PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	get_ownerDocument PTR
	cloneNode PTR
	get_nodeTypeString PTR
	get_text PTR
	put_text PTR
	get_specified PTR
	get_definition PTR
	get_nodeTypedValue PTR
	put_nodeTypedValue PTR
	get_dataType PTR
	put_dataType PTR
	get_xml PTR
	transformNode PTR
	selectNodes PTR
	selectSingleNode PTR
	get_parsed PTR
	get_namespaceURI PTR
	get_prefix PTR
	get_baseName PTR
	transformNodeToObject PTR
	uniqueID PTR
	depth PTR
	childNumber PTR
	ancestorChildNumber PTR
	absoluteChildNumber PTR
	formatIndex PTR
	formatNumber PTR
	formatDate PTR
	formatTime PTR
ENDS

#DEFINE GUID_DIID_XMLDOMDocumentEvents <0xefaa427,0x272f,0x11d2,<0x83,0x6f,0x00,0x00,0xf8,0x7a,0x77,0x82>>

XMLDOMDocumentEvents STRUCT
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
ENDS

#DEFINE GUID_CLSID_DOMDocument <0x2933BF90,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>
#DEFINE GUID_CLSID_DOMFreeThreadedDocument <0x2933BF91,0x7B36,0x11d2,<0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60>>

#DEFINE GUID_IID_IXMLHttpRequest <0xED8C108D,0x4349,0x11D2,<0x91,0xA4,0x00,0xC0,0x4F,0x79,0x69,0xE8>>

IXMLHttpRequest STRUCT
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
	open PTR
	setRequestHeader PTR
	getResponseHeader PTR
	getAllResponseHeaders PTR
	send PTR
	abort PTR
	get_status PTR
	get_statusText PTR
	get_responseXML PTR
	get_responseText PTR
	get_responseBody PTR
	get_responseStream PTR
	get_readyState PTR
	put_onreadystatechange PTR
ENDS

#DEFINE GUID_CLSID_XMLHTTPRequest <0xED8C108E,0x4349,0x11D2,<0x91,0xA4,0x00,0xC0,0x4F,0x79,0x69,0xE8>>

#DEFINE GUID_IID_IXMLDSOControl <0x310afa62,0x0575,0x11d2,<0x9c,0xa9,0x00,0x60,0xb0,0xec,0x3d,0x39>>

IXMLDSOControl STRUCT
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
	get_XMLDocument PTR
	put_XMLDocument PTR
	get_JavaDSOCompatible PTR
	put_JavaDSOCompatible PTR
	get_readyState PTR
ENDS

#DEFINE GUID_CLSID_XMLDSOControl <0x550dda30,0x0541,0x11d2,<0x9c,0xa9,0x00,0x60,0xb0,0xec,0x3d,0x39>>

#DEFINE GUID_IID_IXMLElementCollection <0x65725580,0x9B5D,0x11d0,<0x9B,0xFE,0x00,0xC0,0x4F,0xC9,0x9C,0x8E>>

IXMLElementCollection STRUCT
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
	put_length PTR
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_IID_IXMLDocument <0xF52E2B61,0x18A1,0x11d1,<0xB1,0x05,0x00,0x80,0x5F,0x49,0x91,0x6B>>

IXMLDocument STRUCT
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
	get_root PTR
	get_fileSize PTR
	get_fileModifiedDate PTR
	get_fileUpdatedDate PTR
	get_URL PTR
	put_URL PTR
	get_mimeType PTR
	get_readyState PTR
	get_charset PTR
	put_charset PTR
	get_version PTR
	get_doctype PTR
	get_dtdURL PTR
	createElement PTR
ENDS

#DEFINE GUID_IID_IXMLDocument2 <0x2B8DE2FE,0x8D2D,0x11d1,<0xB2,0xFC,0x00,0xC0,0x4F,0xD9,0x15,0xA9>>

IXMLDocument2 STRUCT
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
	get_root PTR
	get_fileSize PTR
	get_fileModifiedDate PTR
	get_fileUpdatedDate PTR
	get_URL PTR
	put_URL PTR
	get_mimeType PTR
	get_readyState PTR
	get_charset PTR
	put_charset PTR
	get_version PTR
	get_doctype PTR
	get_dtdURL PTR
	createElement PTR
	get_async PTR
	put_async PTR
ENDS

#DEFINE GUID_IID_IXMLElement <0x3F7F31AC,0xE15F,0x11d0,<0x9C,0x25,0x00,0xC0,0x4F,0xC9,0x9C,0x8E>>

IXMLElement STRUCT
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
	get_tagName PTR
	put_tagName PTR
	get_parent PTR
	setAttribute PTR
	getAttribute PTR
	removeAttribute PTR
	get_children PTR
	get_type PTR
	get_text PTR
	put_text PTR
	addChild PTR
	removeChild PTR
ENDS

#DEFINE GUID_IID_IXMLElement2 <0x2B8DE2FF,0x8D2D,0x11d1,<0xB2,0xFC,0x00,0xC0,0x4F,0xD9,0x15,0xA9>>

IXMLElement2 STRUCT
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
	get_tagName PTR
	put_tagName PTR
	get_parent PTR
	setAttribute PTR
	getAttribute PTR
	removeAttribute PTR
	get_children PTR
	get_type PTR
	get_text PTR
	put_text PTR
	addChild PTR
	removeChild PTR
	get_attributes PTR
ENDS

#DEFINE GUID_IID_IXMLAttribute <0xD4D4A0FC,0x3B73,0x11d1,<0xB2,0xB4,0x00,0xC0,0x4F,0xB9,0x25,0x96>>

IXMLAttribute STRUCT
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
	get_name PTR
	get_value PTR
ENDS

#DEFINE GUID_IID_IXMLError <0x948C5AD3,0xC58D,0x11d0,<0x9C,0x0B,0x00,0xC0,0x4F,0xC9,0x9C,0x8E>>

IXMLError STRUCT
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

#DEFINE GUID_CLSID_XMLDocument <0xCFC399AF,0xD876,0x11d0,<0x9C,0x10,0x00,0xC0,0x4F,0xC9,0x9C,0x8E>>

#endif



