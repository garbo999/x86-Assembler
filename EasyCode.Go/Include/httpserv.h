#ifndef HTTPSERV_H
#define HTTPSERV_H

#IFNDEF AHADMIN_H
	#include "ahadmin.h"
#ENDIF

#IFNDEF HTTP_H
	#include "http.h"
#ENDIF

//
// Request triggered notifications
//

//
// Request deterministic notifications
//

// request is beginning
#define RQ_BEGIN_REQUEST               0x00000001
// request is being authenticated
#define RQ_AUTHENTICATE_REQUEST        0x00000002
// request is being authorized
#define RQ_AUTHORIZE_REQUEST           0x00000004
// satisfy request from cache
#define RQ_RESOLVE_REQUEST_CACHE       0x00000008
// map handler for request
#define RQ_MAP_REQUEST_HANDLER         0x00000010
// acquire request state
#define RQ_ACQUIRE_REQUEST_STATE       0x00000020
// pre-execute handler
#define RQ_PRE_EXECUTE_REQUEST_HANDLER 0x00000040 
// execute handler
#define RQ_EXECUTE_REQUEST_HANDLER     0x00000080
// release request state
#define RQ_RELEASE_REQUEST_STATE       0x00000100
// update cache
#define RQ_UPDATE_REQUEST_CACHE        0x00000200
// log request
#define RQ_LOG_REQUEST                 0x00000400
// end request
#define RQ_END_REQUEST                 0x00000800

//
// Request non-deterministic notifications
//

// custom notification
#define RQ_CUSTOM_NOTIFICATION         0x10000000
// send response
#define RQ_SEND_RESPONSE               0x20000000
// read entity
#define RQ_READ_ENTITY                 0x40000000
// map a url to a physical path
#define RQ_MAP_PATH                    0x80000000

// 
// Global notifications
//

// stop accepting new requests
#define GL_STOP_LISTENING               0x00000002
// cache cleanup before termination
#define GL_CACHE_CLEANUP                0x00000004
// cache operation
#define GL_CACHE_OPERATION              0x00000010
// health check
#define GL_HEALTH_CHECK                 0x00000020
// configuration changed
#define GL_CONFIGURATION_CHANGE         0x00000040
// file changed
#define GL_FILE_CHANGE                  0x00000080
// before request pipeline has started
#define GL_PRE_BEGIN_REQUEST            0x00000100
// application start
#define GL_APPLICATION_START            0x00000200
// resolve modules for an application
#define GL_APPLICATION_RESOLVE_MODULES  0x00000400
// application end
#define GL_APPLICATION_STOP             0x00000800
// RSCA query
#define GL_RSCA_QUERY                   0x00001000
// trace event was raised
#define GL_TRACE_EVENT                  0x00002000
// custom notification
#define GL_CUSTOM_NOTIFICATION          0x00004000
// thread cleanup notification
#define GL_THREAD_CLEANUP               0x00008000

//
// Request notification return status
//

RQ_NOTIFICATION_CONTINUE = 0
RQ_NOTIFICATION_PENDING = 1
RQ_NOTIFICATION_FINISH_REQUEST = 2
//
// Out of band return codes
//

GL_NOTIFICATION_CONTINUE = 0
GL_NOTIFICATION_HANDLED = 1

// 
// Priority class aliases
//

#define PRIORITY_ALIAS_FIRST              L"FIRST"
#define PRIORITY_ALIAS_HIGH               L"HIGH"
#define PRIORITY_ALIAS_MEDIUM             L"MEDIUM"
#define PRIORITY_ALIAS_LOW                L"LOW"
#define PRIORITY_ALIAS_LAST               L"LAST"

//
// Cache operations
//

CACHE_OPERATION_RETRIEVE = 0
CACHE_OPERATION_ADD = 1
CACHE_OPERATION_DELETE = 2
CACHE_OPERATION_FLUSH_PREFIX = 3
CACHE_OPERATION_ENUM = 4

//
// Flags for IHttpContext->CloneContext()
//

#define CLONE_FLAG_BASICS              0x01 
#define CLONE_FLAG_HEADERS             0x02 
#define CLONE_FLAG_ENTITY              0x04 
#define CLONE_FLAG_NO_PRECONDITION     0x08 
#define CLONE_FLAG_NO_DAV              0x10

//
// Flags for IHttpContext->ExecuteRequest()
//

#define EXECUTE_FLAG_NO_HEADERS                     0x01
#define EXECUTE_FLAG_IGNORE_CURRENT_INTERCEPTOR     0x02
#define EXECUTE_FLAG_IGNORE_APPPOOL                 0x04
#define EXECUTE_FLAG_DISABLE_CUSTOM_ERROR           0x08
#define EXECUTE_FLAG_SAME_URL                       0x10
// do not flush the child response but copy it back to the parent
#define EXECUTE_FLAG_BUFFER_RESPONSE                0x20
// child response is still eligible for http.sys caching
#define EXECUTE_FLAG_HTTP_CACHE_ELIGIBLE            0x40

#define HTTP_USER_VARIABLE_SID              "SID"
#define HTTP_USER_VARIABLE_CTXT_HANDLE      "CtxtHandle"
#define HTTP_USER_VARIABLE_CRED_HANDLE      "CredHandle"

#define MODULE_REGISTERMODULE   "RegisterModule"

#endif


