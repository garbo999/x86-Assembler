/*++

Copyright (c) 1997-1999  Microsoft Corporation

Module Name:

    httpfilt.h

Abstract:

    This module contains the Microsoft HTTP filter extension info

Revision History:

--*/

#ifndef HTTPFILT_H
#define HTTPFILT_H

#define SF_MAX_USERNAME         (256+1)
#define SF_MAX_PASSWORD         (256+1)
#define SF_MAX_AUTH_TYPE        (32+1)

#define SF_MAX_FILTER_DESC_LEN  (256+1)


//
//  These values can be used with the pfnSFCallback function supplied in
//  the filter context structure
//
SF_REQ_SEND_RESPONSE_HEADER = 0
SF_REQ_ADD_HEADERS_ON_DENIAL = 1
SF_REQ_SET_NEXT_READ_SIZE = 2
SF_REQ_SET_PROXY_INFO = 3
SF_REQ_GET_CONNID = 4
SF_REQ_SET_CERTIFICATE_INFO = 5
SF_REQ_GET_PROPERTY = 6
SF_REQ_NORMALIZE_URL = 7
SF_REQ_DISABLE_NOTIFICATIONS = 8

SF_PROPERTY_SSL_CTXT = 0
SF_PROPERTY_INSTANCE_NUM_ID = 1

//
//  These values are returned by the filter entry point when a new request is
//  received indicating their interest in this particular request
//
SF_STATUS_REQ_FINISHED = 0x8000000
SF_STATUS_REQ_FINISHED_KEEP_CONN = 0x8000001
SF_STATUS_REQ_NEXT_NOTIFICATION = 0x8000002
SF_STATUS_REQ_HANDLED_NOTIFICATION = 0x8000003
SF_STATUS_REQ_ERROR = 0x8000004
SF_STATUS_REQ_READ_NEXT = 0x8000005

HTTP_FILTER_CONTEXT STRUCT
	cbSize DD
	Revision DD
	ServerContext PTR
	ulReserved DD
	fIsSecurePort BOOL
	pFilterContext PTR
	GetServerVariable PTR
	AddResponseHeaders PTR
	WriteClient PTR
	AllocMem PTR
	ServerSupportFunction PTR
ENDS

//
//  This structure is the notification info for the read and send raw data
//  notification types
//

HTTP_FILTER_RAW_DATA STRUCT
	pvInData PTR
	cbInData DD
	cbInBuffer DD
	dwReserved DD
ENDS

//
//  This structure is the notification info for when the server is about to
//  process the client headers
//

HTTP_FILTER_PREPROC_HEADERS STRUCT
	GetHeader PTR
	SetHeader PTR
	AddHeader PTR
	HttpStatus DD
	dwReserved DD
ENDS

//
//  Authentication information for this request.
//

HTTP_FILTER_AUTHENT STRUCT
	pszUser PTR
	cbUserBuff DD
	pszPassword PTR
	cbPasswordBuff DD
ENDS

//
//  Indicates the server is going to use the specific physical mapping for
//  the specified URL.  Filters can modify the physical path in place.
//

HTTP_FILTER_URL_MAP STRUCT
	pszURL PTR
	pszPhysicalPath PTR
	cbPathBuff DD
ENDS
//
//  Indicates the server is going to use the specific physical mapping for
//  the specified URL.  Filters can modify the physical path in place.
//
//  Additional members beyond those from HTTP_FILTER_URL_MAP are
//  informational.
//
HTTP_FILTER_URL_MAP_EX STRUCT
	pszURL PTR
	pszPhysicalPath PTR
	cbPathBuff DD
	dwFlags DD
	cchMatchingPath DD
	cchMatchingURL DD
	pszScriptMapEntry PTR
ENDS
//
//  Bitfield indicating the requested resource has been denied by the server due
//  to a logon failure, an ACL on a resource, an ISAPI Filter or an
//  ISAPI Application/CGI Application.
//
//  SF_DENIED_BY_CONFIG can appear with SF_DENIED_LOGON if the server
//  configuration did not allow the user to logon.
//
#define SF_DENIED_LOGON             0x00000001
#define SF_DENIED_RESOURCE          0x00000002
#define SF_DENIED_FILTER            0x00000004
#define SF_DENIED_APPLICATION       0x00000008

#define SF_DENIED_BY_CONFIG         0x00010000

HTTP_FILTER_ACCESS_DENIED STRUCT
	pszURL PTR
	pszPhysicalPath PTR
	dwReason DD
ENDS
//
//  The log information about to be written to the server log file.  The
//  string pointers can be replaced but the memory must remain valid until
//  the next notification
//
HTTP_FILTER_LOG STRUCT
	pszClientHostName PTR
	pszClientUserName PTR
	pszServerName PTR
	pszOperation PTR
	pszTarget PTR
	pszParameters PTR
	dwHttpStatus DD
	dwWin32Status DD
	dwBytesSent DD
	dwBytesRecvd DD
	msTimeForProcessing DD
ENDS

//
// Called once the client request has been authenticated.
//

HTTP_FILTER_AUTH_COMPLETE_INFO STRUCT
	GetHeader PTR
	SetHeader PTR
	AddHeader PTR
	GetUserToken PTR
	HttpStatus DD
	fResetAuth BOOL
	dwReserved DD
ENDS
//
//  Notification Flags
//
//  SF_NOTIFY_SECURE_PORT
//  SF_NOTIFY_NONSECURE_PORT
//
//      Indicates whether the application wants to be notified for transactions
//      that are happenning on the server port(s) that support data encryption
//      (such as PCT and SSL), on only the non-secure port(s) or both.
//
//  SF_NOTIFY_READ_RAW_DATA
//
//      Applications are notified after the server reads a block of memory
//      from the client but before the server does any processing on the
//      block.  The data block may contain HTTP headers and entity data.
//
//
//
#define SF_NOTIFY_SECURE_PORT               0x00000001
#define SF_NOTIFY_NONSECURE_PORT            0x00000002

#define SF_NOTIFY_READ_RAW_DATA             0x00008000
#define SF_NOTIFY_PREPROC_HEADERS           0x00004000
#define SF_NOTIFY_AUTHENTICATION            0x00002000
#define SF_NOTIFY_URL_MAP                   0x00001000
#define SF_NOTIFY_ACCESS_DENIED             0x00000800
#define SF_NOTIFY_SEND_RESPONSE             0x00000040
#define SF_NOTIFY_SEND_RAW_DATA             0x00000400
#define SF_NOTIFY_LOG                       0x00000200
#define SF_NOTIFY_END_OF_REQUEST            0x00000080
#define SF_NOTIFY_END_OF_NET_SESSION        0x00000100
#define SF_NOTIFY_AUTH_COMPLETE             0x04000000
//
//  Filter ordering flags
//
//  Filters will tend to be notified by their specified
//  ordering.  For ties, notification order is determined by load order.
//
//  SF_NOTIFY_ORDER_HIGH - Authentication or data transformation filters
//  SF_NOTIFY_ORDER_MEDIUM
//  SF_NOTIFY_ORDER_LOW  - Logging filters that want the results of any other
//                      filters might specify this order.
//
#define SF_NOTIFY_ORDER_HIGH               0x00080000
#define SF_NOTIFY_ORDER_MEDIUM             0x00040000
#define SF_NOTIFY_ORDER_LOW                0x00020000
#define SF_NOTIFY_ORDER_DEFAULT            SF_NOTIFY_ORDER_LOW
#define SF_NOTIFY_ORDER_MASK               (SF_NOTIFY_ORDER_HIGH|SF_NOTIFY_ORDER_MEDIUM |SF_NOTIFY_ORDER_LOW)
//
//  Filter version information, passed to GetFilterVersion
//
HTTP_FILTER_VERSION STRUCT
	dwServerFilterVersion DD
	dwFilterVersion DD
	lpszFilterDesc DB SF_MAX_FILTER_DESC_LEN DUP
	dwFlags DD
ENDS

#endif //HTTPFILT_H



