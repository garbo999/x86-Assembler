/********
*
*  Copyright (c) 1995  Process Software Corporation
*
*  Copyright (c) 1995-1999  Microsoft Corporation
*
*
*  Module Name  : HttpExt.h
*
*  Abstract :
*
*     This module contains  the structure definitions and prototypes for the
*      HTTP Server Extension interface used to build ISAPI Applications
*
******************/

#ifndef HTTPEXT_H
#define HTTPEXT_H

#IFNDEF WINDOWS_H
	#include "windows.h"
#ENDIF

/************************************************************
 *   Manifest Constants
 ************************************************************/

#define   HSE_VERSION_MAJOR           7      // major version of this spec
#define   HSE_VERSION_MINOR           0      // minor version of this spec
#define   HSE_LOG_BUFFER_LEN         80
#define   HSE_MAX_EXT_DLL_NAME_LEN  256

//
// the following are the status codes returned by the Extension DLL
//

#define   HSE_STATUS_SUCCESS                       1
#define   HSE_STATUS_SUCCESS_AND_KEEP_CONN         2
#define   HSE_STATUS_PENDING                       3
#define   HSE_STATUS_ERROR                         4

//
// The following are the values to request services with the
//   ServerSupportFunction().
//  Values from 0 to 1000 are reserved for future versions of the interface

#define   HSE_REQ_BASE                             0
#define   HSE_REQ_SEND_URL_REDIRECT_RESP           HSE_REQ_BASE + 1
#define   HSE_REQ_SEND_URL                         HSE_REQ_BASE + 2
#define   HSE_REQ_SEND_RESPONSE_HEADER             HSE_REQ_BASE + 3
#define   HSE_REQ_DONE_WITH_SESSION                HSE_REQ_BASE + 4
#define   HSE_REQ_END_RESERVED                     1000

//
//  These are Microsoft specific extensions
//

#define   HSE_REQ_MAP_URL_TO_PATH                  HSE_REQ_END_RESERVED+1
#define   HSE_REQ_GET_SSPI_INFO                    HSE_REQ_END_RESERVED+2
#define   HSE_APPEND_LOG_PARAMETER                 HSE_REQ_END_RESERVED+3
#define   HSE_REQ_IO_COMPLETION                    HSE_REQ_END_RESERVED+5
#define   HSE_REQ_TRANSMIT_FILE                    HSE_REQ_END_RESERVED+6
#define   HSE_REQ_REFRESH_ISAPI_ACL                HSE_REQ_END_RESERVED+7
#define   HSE_REQ_IS_KEEP_CONN                     HSE_REQ_END_RESERVED+8
#define   HSE_REQ_ASYNC_READ_CLIENT                HSE_REQ_END_RESERVED+10
#define   HSE_REQ_GET_IMPERSONATION_TOKEN          HSE_REQ_END_RESERVED+11
#define   HSE_REQ_MAP_URL_TO_PATH_EX               HSE_REQ_END_RESERVED+12
#define   HSE_REQ_ABORTIVE_CLOSE                   HSE_REQ_END_RESERVED+14
#define   HSE_REQ_GET_CERT_INFO_EX                 HSE_REQ_END_RESERVED+15
#define   HSE_REQ_SEND_RESPONSE_HEADER_EX          HSE_REQ_END_RESERVED+16
#define   HSE_REQ_CLOSE_CONNECTION                 HSE_REQ_END_RESERVED+17
#define   HSE_REQ_IS_CONNECTED                     HSE_REQ_END_RESERVED+18
#define   HSE_REQ_MAP_UNICODE_URL_TO_PATH          HSE_REQ_END_RESERVED+23
#define   HSE_REQ_MAP_UNICODE_URL_TO_PATH_EX       HSE_REQ_END_RESERVED+24
#define   HSE_REQ_EXEC_UNICODE_URL                 HSE_REQ_END_RESERVED+25
#define   HSE_REQ_EXEC_URL                         HSE_REQ_END_RESERVED+26
#define   HSE_REQ_GET_EXEC_URL_STATUS              HSE_REQ_END_RESERVED+27
#define   HSE_REQ_SEND_CUSTOM_ERROR                HSE_REQ_END_RESERVED+28
#define   HSE_REQ_IS_IN_PROCESS                    HSE_REQ_END_RESERVED+30
#define   HSE_REQ_REPORT_UNHEALTHY                 HSE_REQ_END_RESERVED+32
#define   HSE_REQ_NORMALIZE_URL                    HSE_REQ_END_RESERVED+33
#define   HSE_REQ_VECTOR_SEND                      HSE_REQ_END_RESERVED+37
#define   HSE_REQ_GET_ANONYMOUS_TOKEN              HSE_REQ_END_RESERVED+38
#define   HSE_REQ_GET_CACHE_INVALIDATION_CALLBACK  HSE_REQ_END_RESERVED+40
#define   HSE_REQ_GET_UNICODE_ANONYMOUS_TOKEN      HSE_REQ_END_RESERVED+41
#define   HSE_REQ_GET_TRACE_INFO                   HSE_REQ_END_RESERVED+42
#define   HSE_REQ_SET_FLUSH_FLAG                   HSE_REQ_END_RESERVED+43
#define   HSE_REQ_GET_TRACE_INFO_EX                HSE_REQ_END_RESERVED+44
#define   HSE_REQ_RAISE_TRACE_EVENT                HSE_REQ_END_RESERVED+45
#define   HSE_REQ_GET_CONFIG_OBJECT                HSE_REQ_END_RESERVED+46
#define   HSE_REQ_GET_WORKER_PROCESS_SETTINGS      HSE_REQ_END_RESERVED+47
#define   HSE_REQ_GET_PROTOCOL_MANAGER_CUSTOM_INTERFACE_CALLBACK HSE_REQ_END_RESERVED+48
#define   HSE_REQ_CANCEL_IO                        HSE_REQ_END_RESERVED+49

//
//  Bit Flags for TerminateExtension
//
//    HSE_TERM_ADVISORY_UNLOAD - Server wants to unload the extension,
//          extension can return TRUE if OK, FALSE if the server should not
//          unload the extension
//
//    HSE_TERM_MUST_UNLOAD - Server indicating the extension is about to be
//          unloaded, the extension cannot refuse.
//

#define HSE_TERM_ADVISORY_UNLOAD                   0x00000001
#define HSE_TERM_MUST_UNLOAD                       0x00000002

//
// Flags for IO Functions, supported for IO Funcs.
//  TF means ServerSupportFunction( HSE_REQ_TRANSMIT_FILE)
//

#define HSE_IO_SYNC                      0x00000001   // for WriteClient
#define HSE_IO_ASYNC                     0x00000002   // for WriteClient/TF/EU
#define HSE_IO_DISCONNECT_AFTER_SEND     0x00000004   // for TF
#define HSE_IO_SEND_HEADERS              0x00000008   // for TF
#define HSE_IO_NODELAY                   0x00001000   // turn off nagling 

//
// These three are only used by VectorSend
//

#define HSE_IO_FINAL_SEND                0x00000010
#define HSE_IO_CACHE_RESPONSE            0x00000020
#define HSE_IO_TRY_SKIP_CUSTOM_ERRORS    0x00000040

//
// structure passed to GetExtensionVersion()
//

HSE_VERSION_INFO STRUCT
	dwExtensionVersion DD
	lpszExtensionDesc DB HSE_MAX_EXT_DLL_NAME_LEN DUP
ENDS


//
// structure passed to extension procedure on a new request
//
EXTENSION_CONTROL_BLOCK STRUCT
	cbSize DD
	dwVersion DD
	ConnID HANDLE // This is LPVOID which is the typedef for HANDLE
	dwHttpStatusCode DD
	lpszLogData DB HSE_LOG_BUFFER_LEN DUP
	lpszMethod PTR
	lpszQueryString PTR
	lpszPathInfo PTR
	lpszPathTranslated PTR
	cbTotalBytes DD
	cbAvailable DD
	lpbData PTR
	lpszContentType PTR
	GetServerVariable PTR
	WriteClient PTR
	ReadClient PTR
	ServerSupportFunction PTR
ENDS

//
//  Bit field of flags that can be on a virtual directory
//

#define HSE_URL_FLAGS_READ          0x00000001    // Allow for Read
#define HSE_URL_FLAGS_WRITE         0x00000002    // Allow for Write
#define HSE_URL_FLAGS_EXECUTE       0x00000004    // Allow for Execute
#define HSE_URL_FLAGS_SSL           0x00000008    // Require SSL
#define HSE_URL_FLAGS_DONT_CACHE    0x00000010    // Don't cache (vroot only)
#define HSE_URL_FLAGS_NEGO_CERT     0x00000020    // Allow client SSL certs
#define HSE_URL_FLAGS_REQUIRE_CERT  0x00000040    // Require client SSL certs
#define HSE_URL_FLAGS_MAP_CERT      0x00000080    // Map SSL cert to NT account
#define HSE_URL_FLAGS_SSL128        0x00000100    // Require 128 bit SSL
#define HSE_URL_FLAGS_SCRIPT        0x00000200    // Allow for Script execution

#define HSE_URL_FLAGS_MASK          0x000003ff

//
//  Structure for extended information on a URL mapping
//

HSE_URL_MAPEX_INFO STRUCT
	lpszPath DB MAX_PATH DUP
	dwFlags DD
	cchMatchingPath DD
	cchMatchingURL DD
	dwReserved1 DD
	dwReserved2 DD
ENDS

HSE_UNICODE_URL_MAPEX_INFO STRUCT
	lpszPath DW MAX_PATH DUP
	dwFlags DD
	cchMatchingPath DD
	cchMatchingURL DD
ENDS

//
// HSE_TF_INFO defines the type for HTTP SERVER EXTENSION support for
//  ISAPI applications to send files using TransmitFile.
// A pointer to this object should be used with ServerSupportFunction()
//  for HSE_REQ_TRANSMIT_FILE.
//

HSE_TF_INFO STRUCT
	pfnHseIO PTR
	pContext PTR
	hFile HANDLE
	pszStatusCode PTR
	BytesToWrite DD
	Offset DD
	pHead PTR
	HeadLength DD
	pTail PTR
	TailLength DD
	dwFlags DD
ENDS

//
// HSE_SEND_HEADER_EX_INFO allows an ISAPI application to send headers
// and specify keep-alive behavior in the same call.
//

HSE_SEND_HEADER_EX_INFO STRUCT
	pszStatus PTR
	pszHeader PTR
	cchStatus DD
	cchHeader DD
	fKeepConn BOOL
ENDS

//
// Flags for use with HSE_REQ_EXEC_URL
//

#define HSE_EXEC_URL_NO_HEADERS                     0x02
#define HSE_EXEC_URL_IGNORE_CURRENT_INTERCEPTOR     0x04
#define HSE_EXEC_URL_IGNORE_VALIDATION_AND_RANGE    0x10
#define HSE_EXEC_URL_DISABLE_CUSTOM_ERROR           0x20
#define HSE_EXEC_URL_SSI_CMD                        0x40
#define HSE_EXEC_URL_HTTP_CACHE_ELIGIBLE            0x80
          
//
// HSE_EXEC_URL_USER_INFO provides a new user content for use with
// HSE_REQ_EXEC_URL
//

HSE_EXEC_URL_USER_INFO STRUCT
	hImpersonationToken HANDLE
	pszCustomUserName PTR
	pszCustomAuthType PTR
ENDS

//
// HSE_EXEC_URL_ENTITY_INFO describes the entity body to be provided
// to the executed request using HSE_REQ_EXEC_URL
//

HSE_EXEC_URL_ENTITY_INFO STRUCT
	cbAvailable DD
	lpbData PTR
ENDS

//
// HSE_EXEC_URL_STATUS provides the status of the last HSE_REQ_EXEC_URL 
// call
//

HSE_EXEC_URL_STATUS STRUCT
	uHttpStatusCode DW
	uHttpSubStatus DW
	dwWin32Error DD
ENDS

//
// HSE_EXEC_URL_INFO provides a description of the request to execute
// on behalf of the ISAPI.  
//

HSE_EXEC_URL_INFO STRUCT
	pszUrl PTR
	pszMethod PTR
	pszChildHeaders PTR
	pUserInfo PTR
	pEntity PTR
	dwExecUrlFlags DD
ENDS

//
// HSE_EXEC_UNICODE_URL_USER_INFO provides a new user content for use with
// HSE_REQ_EXEC_UNICODE_URL
//

HSE_EXEC_UNICODE_URL_USER_INFO STRUCT
	hImpersonationToken HANDLE
	pszCustomUserName PTR
	pszCustomAuthType PTR
ENDS

//
// HSE_EXEC_UNICODE_URL_INFO provides a description of the request to execute
// on behalf of the ISAPI.  
//

HSE_EXEC_UNICODE_URL_INFO STRUCT
	pszUrl PTR
	pszMethod PTR
	pszChildHeaders PTR
	pUserInfo PTR
	pEntity PTR
	dwExecUrlFlags DD
ENDS

//
// HSE_CUSTOM_ERROR_INFO structured used in HSE_REQ_SEND_CUSTOM_ERROR
// 

HSE_CUSTOM_ERROR_INFO STRUCT
	pszStatus PTR
	uHttpSubError DW
	fAsync BOOL
ENDS

//
// structures for the HSE_REQ_VECTOR_SEND ServerSupportFunction
//


//
// Types of vector-elements currently supported
//
#define HSE_VECTOR_ELEMENT_TYPE_MEMORY_BUFFER       0
#define HSE_VECTOR_ELEMENT_TYPE_FILE_HANDLE         1

//
// element of the vector
//

HSE_VECTOR_ELEMENT STRUCT
	ElementType DD
	pvContext PTR
	cbOffset DQ
	cbSize DQ
ENDS

//
// The whole vector to be passed to the ServerSupportFunction
//

HSE_RESPONSE_VECTOR STRUCT
	dwFlags DD
	pszStatus PTR
	pszHeaders PTR
	nElementCount DD
	lpElementArray PTR
ENDS

#if WINVER >= NTDDI_WINNT4
	#IFNDEF WINCRYPT_H
		#include "wincrypt.h"
	#ENDIF
	//
	//      CERT_CONTEXT_EX is passed as an an argument to 
	//  ServerSupportFunction( HSE_REQ_GET_CERT_INFO_EX )
	//
	
	CERT_CONTEXT_EX STRUCT
		CertContext CERT_CONTEXT
		cbAllocated DD
		dwCertificateFlags DD
	ENDS
#endif

//
// HSE_TRACE_INFO structure used to get debug trace info
// from core web server
//

HSE_TRACE_INFO STRUCT
	fTraceRequest BOOL 
	TraceContextId DB 16 DUP
	dwReserved1 DD
	dwReserved2 DD
ENDS

//
// Flags for determining application type
//

#define HSE_APP_FLAG_IN_PROCESS   0
#define HSE_APP_FLAG_ISOLATED_OOP 1
#define HSE_APP_FLAG_POOLED_OOP   2

#endif



