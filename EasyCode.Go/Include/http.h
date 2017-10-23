#ifndef HTTP_H
#define HTTP_H

#IFDEF LINKFILES
	#dynamiclinkfile httpapi.dll
#ENDIF

// This header is for Windows XP Service pack 2 and above only
#if WINVER >= NTDDI_WINXPSP2

#IFNDEF WINSOCK2_H
	#include "winsock2.h"
#ENDIF

#IFNDEF WS2TCPIP_H
	;#include "ws2tcpip.h"
#ENDIF

#define HTTP_INITIALIZE_SERVER          0x00000001
#define HTTP_INITIALIZE_CONFIG          0x00000002

#if WINVER >= NTDDI_VISTA

//
// Following section defines the properties supported by the
// server side HTTP API.
//

HttpServerAuthenticationProperty = 0
HttpServerLoggingProperty = 1
HttpServerQosProperty = 2
HttpServerTimeoutsProperty = 3
HttpServerQueueLengthProperty = 4
HttpServerStateProperty = 5
HttpServer503VerbosityProperty = 5
HttpServerBindingProperty = 7
HttpServerExtendedAuthenticationProperty = 8
HttpServerListenEndpointProperty = 9

#define HTTP_MAX_SERVER_QUEUE_LENGTH    0x7FFFFFFF
#define HTTP_MIN_SERVER_QUEUE_LENGTH    1

//
// Generic property flags. Each structure defining a property info typically
// contain an element of this type.
//

HTTP_PROPERTY_FLAGS STRUCT
	Present DD
ENDS

//
// Enabled state.
//

HttpEnabledStateActive = 0
HttpEnabledStateInactive= 1

HTTP_STATE_INFO STRUCT
	Flags DD
	State DD
ENDS

//
// Defines the verbosity level for a request queue which will be used
// when sending "503 - Service Unavailable" type error responses. Note that
// this setting only affects the error responses generated internally
// by HTTPAPI.
//

Http503ResponseVerbosityBasic = 0
Http503ResponseVerbosityLimited = 1
Http503ResponseVerbosityFull = 2

//
// Network QoS related.
//

HttpQosSettingTypeBandwidth = 0
HttpQosSettingTypeConnectionLimit = 1

HTTP_QOS_SETTING_INFO STRUCT
	QosType DD
	QosSetting PTR
ENDS

HTTP_CONNECTION_LIMIT_INFO STRUCT
	Flags DD
	MaxConnections DD
ENDS

HTTP_BANDWIDTH_LIMIT_INFO STRUCT
    HTTP_PROPERTY_FLAGS Flags DD
    ULONG MaxBandwidth DD
ENDS

//
// Bandwidth throttling limit can not be set lower than the following
// number. The value is in bytes/sec.
//

#define HTTP_MIN_ALLOWED_BANDWIDTH_THROTTLING_RATE 1024

//
// Distinguished value for bandwidth, connection limits and logging rollover
// size indicating "no limit".
//

#define HTTP_LIMIT_INFINITE  -1

//
// Timeout information.
//

//
// For manipulating global timeout settings.
// These timers run when connection does not belong to any application.
// Value zero is not allowed for driver wide timeout settings.
//

IdleConnectionTimeout = 0
HeaderWaitTimeout = 1

//
// To set a timeout value use the set structure. To query/delete use the key
// directly. When you query a timeout value the output buffer must be exactly
// the sizeof param.
//

HTTP_SERVICE_CONFIG_TIMEOUT_SET STRUCT
	KeyDesc DD
	ParamDesc DW
ENDS

//
// For manipulating application specific timeout settings.
// These timers run when there's a request being processed on a connection
// and HTTPAPI has already associated the request with an application.
// Setting a timeout value to zero will cause HTTPAPI to revert to default.
//

HTTP_TIMEOUT_LIMIT_INFO STRUCT
	Flags DD
	EntityBody DW
	DrainEntityBody DW
	RequestQueue DW
	IdleConnection DW
	HeaderWait DW
	MinSendRate DD
ENDS

//
// Controls whether IP-based URLs should listen on the specific IP or wildcard.
//

HTTP_LISTEN_ENDPOINT_INFO STRUCT
	Flags DD
	EnableSharing BOOLEAN
ENDS

HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS STRUCT
	DomainNameLength DW
	DomainName PTR
	RealmLength DW
	Realm PTR
ENDS

HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS STRUCT
	RealmLength DW
	Realm PTR
ENDS

//
// Definitions used for setting server side authentication property.
//

#define HTTP_AUTH_ENABLE_BASIC          0x00000001
#define HTTP_AUTH_ENABLE_DIGEST         0x00000002
#define HTTP_AUTH_ENABLE_NTLM           0x00000004
#define HTTP_AUTH_ENABLE_NEGOTIATE      0x00000008
#define HTTP_AUTH_ENABLE_KERBEROS       0x00000010

#define HTTP_AUTH_ENABLE_ALL (HTTP_AUTH_ENABLE_BASIC|HTTP_AUTH_ENABLE_DIGEST|HTTP_AUTH_ENABLE_NTLM|HTTP_AUTH_ENABLE_NEGOTIATE|HTTP_AUTH_ENABLE_KERBEROS)

#define HTTP_AUTH_EX_FLAG_ENABLE_KERBEROS_CREDENTIAL_CACHING 0x01
#define HTTP_AUTH_EX_FLAG_CAPTURE_CREDENTIAL 0x02

HTTP_SERVER_AUTHENTICATION_INFO STRUCT
	Flags DD
	AuthSchemes DD
	ReceiveMutualAuth BOOLEAN
	ReceiveContextHandle BOOLEAN
	DisableNTLMCredentialCaching BOOLEAN
	ExFlags DB
	DigestParams DD
	BasicParams DD
ENDS

//
// Definitions used for setting logging property.
//

//
// The known log fields recognized/supported by HTTPAPI. Following fields
// are used for W3C logging. Subset of them are also used for error
// logging.
//

#define HTTP_LOG_FIELD_DATE                  0x00000001
#define HTTP_LOG_FIELD_TIME                  0x00000002
#define HTTP_LOG_FIELD_CLIENT_IP             0x00000004
#define HTTP_LOG_FIELD_USER_NAME             0x00000008
#define HTTP_LOG_FIELD_SITE_NAME             0x00000010
#define HTTP_LOG_FIELD_COMPUTER_NAME         0x00000020
#define HTTP_LOG_FIELD_SERVER_IP             0x00000040
#define HTTP_LOG_FIELD_METHOD                0x00000080
#define HTTP_LOG_FIELD_URI_STEM              0x00000100
#define HTTP_LOG_FIELD_URI_QUERY             0x00000200
#define HTTP_LOG_FIELD_STATUS                0x00000400
#define HTTP_LOG_FIELD_WIN32_STATUS          0x00000800
#define HTTP_LOG_FIELD_BYTES_SENT            0x00001000
#define HTTP_LOG_FIELD_BYTES_RECV            0x00002000
#define HTTP_LOG_FIELD_TIME_TAKEN            0x00004000
#define HTTP_LOG_FIELD_SERVER_PORT           0x00008000
#define HTTP_LOG_FIELD_USER_AGENT            0x00010000
#define HTTP_LOG_FIELD_COOKIE                0x00020000
#define HTTP_LOG_FIELD_REFERER               0x00040000
#define HTTP_LOG_FIELD_VERSION               0x00080000
#define HTTP_LOG_FIELD_HOST                  0x00100000
#define HTTP_LOG_FIELD_SUB_STATUS            0x00200000

//
// Fields that are used only for error logging.
//

#define HTTP_LOG_FIELD_CLIENT_PORT           0x00400000
#define HTTP_LOG_FIELD_URI                   0x00800000
#define HTTP_LOG_FIELD_SITE_ID               0x01000000
#define HTTP_LOG_FIELD_REASON                0x02000000
#define HTTP_LOG_FIELD_QUEUE_NAME            0x04000000

//
// Defines the logging type.
//

HttpLoggingTypeW3C = 0
HttpLoggingTypeIIS = 1
HttpLoggingTypeNCSA = 2
HttpLoggingTypeRaw = 3

//
// Defines the rollover type for log files.
//

HttpLoggingRolloverSize = 0
HttpLoggingRolloverDaily = 1
HttpLoggingRolloverWeekly = 2
HttpLoggingRolloverMonthly = 3
HttpLoggingRolloverHourly = 4

//
// Log file rollover size can not be set lower than the following
// limit. The value is in bytes.
//

#define HTTP_MIN_ALLOWED_LOG_FILE_ROLLOVER_SIZE (1 * 1024 * 1024)

//
// Logging option flags. When used in the logging configuration alters
// some default logging behaviour.
//
// HTTP_LOGGING_FLAG_LOCAL_TIME_ROLLOVER - This flag is used to change
//      the log file rollover to happen by local time based. By default
//      log file rollovers happen by GMT time.
//
// HTTP_LOGGING_FLAG_USE_UTF8_CONVERSION - When set the unicode fields
//      will be converted to UTF8 multibytes when writting to the log
//      files. When this flag is not present, the local code page
//      conversion happens.
//
// HTTP_LOGGING_FLAG_LOG_ERRORS_ONLY -
// HTTP_LOGGING_FLAG_LOG_SUCCESS_ONLY - These two flags are used to
//      to do selective logging. If neither of them are present both
//      types of requests will be logged. Only one these flags can be
//      set at a time. They are mutually exclusive.
//

#define HTTP_LOGGING_FLAG_LOCAL_TIME_ROLLOVER         0x00000001
#define HTTP_LOGGING_FLAG_USE_UTF8_CONVERSION         0x00000002
#define HTTP_LOGGING_FLAG_LOG_ERRORS_ONLY             0x00000004
#define HTTP_LOGGING_FLAG_LOG_SUCCESS_ONLY            0x00000008

//
// Configuration structure used for setting the logging property.
//

HTTP_LOGGING_INFO STRUCT
	Flags DD
	LoggingFlags DD
	SoftwareName PTR
	SoftwareNameLength DW
	DirectoryNameLength DW
	DirectoryName PTR
	Format DD
	Fields DD
	pExtFields PTR
	NumOfExtFields DW
	MaxRecordSize DW
	RolloverType DD
	RolloverSize DD
	pSecurityDescriptor PTR
ENDS

//
// Binding information.
//

HTTP_BINDING_INFO STRUCT
	Flags DD
	RequestQueueHandle HANDLE
ENDS

//
// Definitions for request queue manipulation.
//
// These flags are used with HttpCreateRequestQueue() API.
//
// HTTP_CREATE_REQUEST_QUEUE_FLAG_OPEN_EXISTING - To open an existing request
// queue. The request queue name must be supplied.
//
// HTTP_CREATE_REQUEST_QUEUE_FLAG_CONTROLLER - Creates the request queue and
// marks that the caller process is not willing to do send/receive (HTTP I/O)on
// the handle directly.
//

#define HTTP_CREATE_REQUEST_QUEUE_FLAG_OPEN_EXISTING       0x00000001
#define HTTP_CREATE_REQUEST_QUEUE_FLAG_CONTROLLER          0x00000002

#endif // NTDDI_VISTA

//
// Flags for HttpReceiveHttpRequest().
//
// HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY - Specifies that the caller would like
// any available entity body to be copied along with the protocol headers.
//
// HTTP_RECEIVE_REQUEST_FLAG_FLUSH_BODY - Specifies that the caller would like
// all of the entity bodies to be copied along with the protocol headers.
//

#define HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY         0x00000001
#define HTTP_RECEIVE_REQUEST_FLAG_FLUSH_BODY        0x00000002


#if WINVER >= NTDDI_VISTA

//
// Flags for HttpReceiveRequestEntityBody().
//
// HTTP_RECEIVE_REQUEST_ENTITY_BODY_FLAG_FILL_BUFFER - Specifies that the
// caller would like the buffer to get filled up with entity bodies unless
// there are no more entity bodies to be copied.
//

#define HTTP_RECEIVE_REQUEST_ENTITY_BODY_FLAG_FILL_BUFFER   0x00000001

#endif //NTDDI_VISTA


//
// Flags for HttpSendHttpResponse() and HttpSendResponseEntityBody().
//
// HTTP_SEND_RESPONSE_FLAG_DISCONNECT - Specifies that the network connection
// should be disconnected immediately after sending the response, overriding
// the HTTP protocol's persistent connection features, such as
// "Connection: keep-alive".
//
// HTTP_SEND_RESPONSE_FLAG_MORE_DATA - Specifies that additional entity body
// data will be sent by the caller.
//
// HTTP_SEND_RESPONSE_FLAG_BUFFER_DATA - Specifies that a caller wants the
// response to complete as soon as possible at the cost of buffering partial
// or the entire response.
//
// HTTP_SEND_RESPONSE_FLAG_ENABLE_NAGLING - Specifies that a caller wants to
// enable the TCP nagling algorithm for this particular send.
//

#define HTTP_SEND_RESPONSE_FLAG_DISCONNECT          0x00000001
#define HTTP_SEND_RESPONSE_FLAG_MORE_DATA           0x00000002
#define HTTP_SEND_RESPONSE_FLAG_BUFFER_DATA         0x00000004
#define HTTP_SEND_RESPONSE_FLAG_ENABLE_NAGLING      0x00000008


//
// Flags for HttpFlushResponseCache().
//
// HTTP_FLUSH_RESPONSE_FLAG_RECURSIVE - Flushes the specified URL and all
// hierarchally-related sub-URLs from the response or fragment cache.
//

#define HTTP_FLUSH_RESPONSE_FLAG_RECURSIVE          0x00000001

//
// This structure defines a file byte range.
//
// If the Length field is HTTP_BYTE_RANGE_TO_EOF then the remainder of the
// file (everything after StartingOffset) is sent.
//

#define HTTP_BYTE_RANGE_TO_EOF 0xFFFFFFFFFFFFFFFF // this must be a ULONGLONG

HTTP_BYTE_RANGE STRUCT
	StartingOffset DQ
	Length DQ
ENDS

//
// The type for HTTP protocol version numbers.
//

HTTP_VERSION STRUCT
	MajorVersion DW
	MinorVersion DW
ENDS

//
// Some useful macros for HTTP protocol version manipulation.
//

#define HTTP_VERSION_UNKNOWN    <0, 0>
#define HTTP_VERSION_0_9        <0, 9>
#define HTTP_VERSION_1_0        <1, 0>
#define HTTP_VERSION_1_1        <1, 1>

//
// The enum type for HTTP verbs.
//

HttpVerbUnparsed = 0
HttpVerbUnknown = 1
HttpVerbInvalid = 2
HttpVerbOPTIONS = 3
HttpVerbGET = 4
HttpVerbHEAD = 5
HttpVerbPOST = 6
HttpVerbPUT = 7
HttpVerbDELETE = 8
HttpVerbTRACE = 9
HttpVerbCONNECT = 10
HttpVerbTRACK = 11  // used by Microsoft Cluster Server for a non-logged trace
HttpVerbMOVE = 12
HttpVerbCOPY = 13
HttpVerbPROPFIND = 14
HttpVerbPROPPATCH = 15
HttpVerbMKCOL = 16
HttpVerbLOCK = 17
HttpVerbUNLOCK = 18
HttpVerbSEARCH = 19
HttpVerbMaximum = 20

//
// Symbols for all HTTP/1.1 headers and other tokens. Notice request +
// response values overlap. Make sure you know which type of header array
// you are indexing.
//
// These values are used as offsets into arrays and as token values in
// HTTP_KNOWN_HEADER arrays in HTTP_REQUEST_HEADERS and HTTP_RESPONSE_HEADERS.
//
// See RFC 2616, HTTP/1.1, for further explanation of most of these headers.
//

HttpHeaderCacheControl          = 0    // general-header [section 4.5]
HttpHeaderConnection            = 1    // general-header [section 4.5]
HttpHeaderDate                  = 2    // general-header [section 4.5]
HttpHeaderKeepAlive             = 3    // general-header [not in rfc]
HttpHeaderPragma                = 4    // general-header [section 4.5]
HttpHeaderTrailer               = 5    // general-header [section 4.5]
HttpHeaderTransferEncoding      = 6    // general-header [section 4.5]
HttpHeaderUpgrade               = 7    // general-header [section 4.5]
HttpHeaderVia                   = 8    // general-header [section 4.5]
HttpHeaderWarning               = 9    // general-header [section 4.5]

HttpHeaderAllow                 = 10   // entity-header  [section 7.1]
HttpHeaderContentLength         = 11   // entity-header  [section 7.1]
HttpHeaderContentType           = 12   // entity-header  [section 7.1]
HttpHeaderContentEncoding       = 13   // entity-header  [section 7.1]
HttpHeaderContentLanguage       = 14   // entity-header  [section 7.1]
HttpHeaderContentLocation       = 15   // entity-header  [section 7.1]
HttpHeaderContentMd5            = 16   // entity-header  [section 7.1]
HttpHeaderContentRange          = 17   // entity-header  [section 7.1]
HttpHeaderExpires               = 18   // entity-header  [section 7.1]
HttpHeaderLastModified          = 19   // entity-header  [section 7.1]


// Request Headers

HttpHeaderAccept                = 20   // request-header [section 5.3]
HttpHeaderAcceptCharset         = 21   // request-header [section 5.3]
HttpHeaderAcceptEncoding        = 22   // request-header [section 5.3]
HttpHeaderAcceptLanguage        = 23   // request-header [section 5.3]
HttpHeaderAuthorization         = 24   // request-header [section 5.3]
HttpHeaderCookie                = 25   // request-header [not in rfc]
HttpHeaderExpect                = 26   // request-header [section 5.3]
HttpHeaderFrom                  = 27   // request-header [section 5.3]
HttpHeaderHost                  = 28   // request-header [section 5.3]
HttpHeaderIfMatch               = 29   // request-header [section 5.3]

HttpHeaderIfModifiedSince       = 30   // request-header [section 5.3]
HttpHeaderIfNoneMatch           = 31   // request-header [section 5.3]
HttpHeaderIfRange               = 32   // request-header [section 5.3]
HttpHeaderIfUnmodifiedSince     = 33   // request-header [section 5.3]
HttpHeaderMaxForwards           = 34   // request-header [section 5.3]
HttpHeaderProxyAuthorization    = 35   // request-header [section 5.3]
HttpHeaderReferer               = 36   // request-header [section 5.3]
HttpHeaderRange                 = 37   // request-header [section 5.3]
HttpHeaderTe                    = 38   // request-header [section 5.3]
HttpHeaderTranslate             = 39   // request-header [webDAV not in rfc 2518]

HttpHeaderUserAgent             = 40   // request-header [section 5.3]

HttpHeaderRequestMaximum        = 41


// Response Headers

HttpHeaderAcceptRanges          = 20   // response-header [section 6.2]
HttpHeaderAge                   = 21   // response-header [section 6.2]
HttpHeaderEtag                  = 22   // response-header [section 6.2]
HttpHeaderLocation              = 23   // response-header [section 6.2]
HttpHeaderProxyAuthenticate     = 24   // response-header [section 6.2]
HttpHeaderRetryAfter            = 25   // response-header [section 6.2]
HttpHeaderServer                = 26   // response-header [section 6.2]
HttpHeaderSetCookie             = 27   // response-header [not in rfc]
HttpHeaderVary                  = 28   // response-header [section 6.2]
HttpHeaderWwwAuthenticate       = 29   // response-header [section 6.2]

HttpHeaderResponseMaximum       = 30


HttpHeaderMaximum               = 41


//
// Structure defining format of a known HTTP header.
// Name is from HTTP_HEADER_ID.
//

HTTP_KNOWN_HEADER STRUCT
	RawValueLength DW
	pRawValue PTR
ENDS

//
// Structure defining format of an unknown header.
//

HTTP_UNKNOWN_HEADER STRUCT
	NameLength DW
	RawValueLength DW
	pName PTR
	pRawValue PTR
ENDS

#if WINVER >= NTDDI_VISTA

//
// Log fields data structure is used for logging a request. This structure must
// be provided along with an HttpSendHttpResponse or HttpSendResponseEntityBody
// call that concludes the send.
//

// Base structure is for future versioning.

HttpLogDataTypeFields = 0

// should we DECLSPEC_ALIGN(4 or 8) == DECLSPEC_POINTERALIGN?
HTTP_LOG_DATA STRUCT
	Type DD
ENDS

// Current log fields data structure for of type HttpLogDataTypeFields.

HTTP_LOG_FIELDS_DATA STRUCT
	Base HTTP_LOG_DATA
	UserNameLength DW
	UriStemLength DW
	ClientIpLength DW
	ServerNameLength DW
	ServiceNameLength DW
	ServerIpLength DW
	MethodLength DW
	UriQueryLength DW
	HostLength DW
	UserAgentLength DW
	CookieLength DW
	ReferrerLength DW
	UserName PTR
	UriStem PTR
	ClientIp PTR
	ServerName PTR
	ServiceName PTR
	ServerIp PTR
	Method PTR
	UriQuery PTR
	Host PTR
	UserAgent PTR
	Cookie PTR
	Referrer PTR
	ServerPort DW
	ProtocolStatus DW
	Win32Status DD
	MethodNum DD
	SubStatus DW
ENDS

#endif // _WIN32_WINNT >= 0x0600

//
// This enum defines a data source for a particular chunk of data.
//

HttpDataChunkFromMemory = 0
HttpDataChunkFromFileHandle = 1
HttpDataChunkFromFragmentCache = 2
HttpDataChunkFromFragmentCacheEx = 3

HttpDataChunkMaximum = 4

//
// This structure describes an individual data chunk.
//

HTTP_DATA_CHUNK STRUCT
	DataChunkType DD
	UNION
		FromMemory STRUCT
			pBuffer PTR
			BufferLength DD
		ENDS
		FromFileHandle STRUCT
			ByteRange HTTP_BYTE_RANGE
			FileHandle HANDLE
		ENDS
		FromFragmentCache STRUCT
			FragmentNameLength DW
			pFragmentName PTR
		ENDS
		FromFragmentCacheEx STRUCT
			ByteRange HTTP_BYTE_RANGE
			pFragmentName PTR
		ENDS
	ENDUNION
ENDS

//
// Structure defining format of request headers.
//

HTTP_REQUEST_HEADERS STRUCT
	UnknownHeaderCount DW
	pUnknownHeaders PTR
	TrailerCount DW
	pTrailers PTR
	KnownHeaders HTTP_KNOWN_HEADER HttpHeaderRequestMaximum DUP
ENDS

//
// Structure defining format of response headers.
//

HTTP_RESPONSE_HEADERS STRUCT
	UnknownHeaderCount DW
	pUnknownHeaders PTR
	TrailerCount DW
	pTrailers PTR
	KnownHeaders HTTP_KNOWN_HEADER HttpHeaderResponseMaximum DUP
ENDS

//
// Structure defining format of transport address. Use pLocalAddress->sa_family
// to determine whether this is an IPv4 address (AF_INET) or IPv6 (AF_INET6).
//
// pRemoteAddress->sa_family will be the same as pLocalAddress->sa_family.
//
// SOCKADDRs are always in network order, not host order.
//

HTTP_TRANSPORT_ADDRESS STRUCT
	pRemoteAddress PTR
	pLocalAddress PTR
ENDS

//
// Structure defining format of cooked URL.
//

HTTP_COOKED_URL STRUCT
	FullUrlLength DW
	HostLength DW
	AbsPathLength DW
	QueryStringLength DW
	pFullUrl PTR
	pHost PTR
	pAbsPath PTR
	pQueryString PTR
ENDS

//
// An opaque context for URL manipulation.
//

#if WINVER >= NTDDI_VISTA

//
// Optional flags for URL manipulation functions.
//
// HTTP_URL_FLAG_REMOVE_ALL : When this flag is used
// when removing a Url from a url group, regardless of
// the passed URL, all of the Urls from the url group
// will be removed.
//

#define HTTP_URL_FLAG_REMOVE_ALL                0x00000001

HttpAuthStatusSuccess = 0
HttpAuthStatusNotAuthenticated = 1
HttpAuthStatusFailure = 2

HttpRequestAuthTypeNone = 0
HttpRequestAuthTypeBasic = 1
HttpRequestAuthTypeDigest = 2
HttpRequestAuthTypeNTLM = 3
HttpRequestAuthTypeNegotiate = 4
HttpRequestAuthTypeKerberos = 5

#endif // WINVER >= NTDDI_VISTA

//
// SSL Client certificate information.
//

HTTP_SSL_CLIENT_CERT_INFO STRUCT
	CertFlags DD
	CertEncodedSize DD
	pCertEncoded PTR
	Token HANDLE
	CertDeniedByMapper BOOLEAN
ENDS

//
// Data computed during SSL handshake.
//

HTTP_SSL_INFO STRUCT
	ServerCertKeySize DW
	ConnectionKeySize DW
	ServerCertIssuerSize DD
	ServerCertSubjectSize DD
	pServerCertIssuer PTR
	pServerCertSubject PTR
	pClientCertInfo PTR
	SslClientCertNegotiated DD
ENDS


#if WINVER >= NTDDI_VISTA

//
// Generic request information type.
//

HttpRequestInfoTypeAuth = 0

HTTP_REQUEST_INFO STRUCT
	InfoType DD
	InfoLength DD
	pInfo PTR
ENDS

//
// Authentication request info structure
//

#define HTTP_REQUEST_AUTH_FLAG_TOKEN_FOR_CACHED_CRED 0x00000001

HTTP_REQUEST_AUTH_INFO STRUCT
	AuthStatus DD
	SecStatus DD
	Flags DD
	AuthType DD
	AccessToken HANDLE
	ContextAttributes DD
	PackedContextLength DD
	PackedContextType DD
	PackedContext PTR
	MutualAuthDataLength DD
    PCHAR pMutualAuthData PTR
	PackageNameLength DW
	pPackageName PTR
ENDS

#endif // WINVER >= NTDDI_VISTA

//
// The structure of an HTTP request for downlevel OS
//

HTTP_REQUEST_V1 STRUCT
	Flags DD
	ConnectionId DD
	RequestId DD
	UrlContext DQ
	Version HTTP_VERSION
	Verb DD
	UnknownVerbLength DW
	RawUrlLength DW
	pUnknownVerb PTR
	pRawUrl PTR
	CookedUrl HTTP_COOKED_URL
	Address HTTP_TRANSPORT_ADDRESS
	Headers HTTP_REQUEST_HEADERS
	BytesReceived DQ
	EntityChunkCount DW
	pEntityChunks PTR
	RawConnectionId DD
	pSslInfo PTR
ENDS

#if WINVER >= NTDII_VISTA

// Longhorn

HTTP_REQUEST_V2 STRUCT
	Flags DD
	ConnectionId DD
	RequestId DD
	UrlContext DQ
	Version HTTP_VERSION
	Verb DD
	UnknownVerbLength DW
	RawUrlLength DW
	pUnknownVerb PTR
	pRawUrl PTR
	CookedUrl HTTP_COOKED_URL
	Address HTTP_TRANSPORT_ADDRESS
	Headers HTTP_REQUEST_HEADERS
	BytesReceived DQ
	EntityChunkCount DW
	pEntityChunks PTR
	RawConnectionId DD
	pSslInfo PTR
	RequestInfoCount DW
	pRequestInfo PTR
ENDS


#DEFINE HTTP_REQUEST HTTP_REQUEST_V2

#else // WINVER < NTDII_VISTA

#DEFINE HTTP_REQUEST HTTP_REQUEST_V1

#endif  // _WIN32_WINNT >= 0x0600

//
// Values for HTTP_REQUEST::Flags. Zero or more of these may be ORed together.
//
// HTTP_REQUEST_FLAG_MORE_ENTITY_BODY_EXISTS - there is more entity body
// to be read for this request. Otherwise, there is no entity body or
// all of the entity body was copied into pEntityChunks.
// HTTP_REQUEST_FLAG_IP_ROUTED - This flag indicates that the request has been
// routed based on host plus ip or ip binding.This is a hint for the application
// to include the local ip while flushing kernel cache entries build for this
// request if any.
//

#define HTTP_REQUEST_FLAG_MORE_ENTITY_BODY_EXISTS   0x00000001
#define HTTP_REQUEST_FLAG_IP_ROUTED                 0x00000002


//
// This structure describes an HTTP response.
//

HTTP_RESPONSE_V1 STRUCT
	Flags DD
	Version DD
	StatusCode DW
	ReasonLength DW
	pReason PTR
	Headers HTTP_RESPONSE_HEADERS
	EntityChunkCount DW
	pEntityChunks PTR
ENDS

#if WINVER >= NTDII_VISTA

// Longhorn

HttpResponseInfoTypeMultipleKnownHeaders = 0
HttpResponseInfoTypeAuthenticationProperty = 1

HTTP_RESPONSE_INFO STRUCT
	Type DD
	Length DD
	pInfo PTR
ENDS

#define HTTP_RESPONSE_INFO_FLAGS_PRESERVE_ORDER         0x00000001

//
// This structure allows the provision of providing multiple known headers.
//

HTTP_MULTIPLE_KNOWN_HEADERS STRUCT
	HeaderId DD
	Flags DD
	KnownHeaderCount DW
	KnownHeaders PTR
ENDS

HTTP_RESPONSE_V2 STRUCT
	Flags DD
	Version DD
	StatusCode DW
	ReasonLength DW
	pReason PTR
	Headers HTTP_RESPONSE_HEADERS
	EntityChunkCount DW
	pEntityChunks PTR
	ResponseInfoCount DW
	pResponseInfo PTR
ENDS


#define HTTP_RESPONSE HTTP_RESPONSE_V2

#else // WINVER < NTDII_VISTA

#define HTTP_RESPONSE HTTP_RESPONSE_V1

#endif

//
// Api Version. This is used to ensure compatibility between applications and
// httpapi.dll and http.sys.
//
// This must not be confused with the HTTP Protocol version.
//

HTTPAPI_VERSION STRUCT
	HttpApiMajorVersion DW
	HttpApiMinorVersion DW
ENDS


#if WINVER >= NTDII_VISTA
	#define HTTPAPI_VERSION_2 <2, 0>
#endif
#define HTTPAPI_VERSION_1 <1, 0>

HttpCachePolicyNocache = 0
HttpCachePolicyUserInvalidates = 1
HttpCachePolicyTimeToLive = 2
HttpCachePolicyMaximum = 3

//
//  Only cache unauthorized GETs + HEADs.
//

HTTP_CACHE_POLICY STRUCT
	Policy DD
	SecondsToLive DD
ENDS

//
// Enum that is used with HttpSetServiceConfiguration(),
// HttpQueryServiceConfiguration(), and HttpDeleteServiceConfiguration() APIs.
//

HttpServiceConfigIPListenList = 0
HttpServiceConfigSSLCertInfo = 1
HttpServiceConfigUrlAclInfo = 2
HttpServiceConfigTimeout = 3
HttpServiceConfigMax = 4

//
// Generic Query enum that can be used with HttpQueryServiceConfiguration()
//

HttpServiceConfigQueryExact = 0
HttpServiceConfigQueryNext = 1
HttpServiceConfigQueryMax = 2

//
// This data structure is used to define a key of the SSL certificate hash
// store.
//

HTTP_SERVICE_CONFIG_SSL_KEY STRUCT
	pIpPort PTR
ENDS

//
// This defines a record for the SSL config store.
//

HTTP_SERVICE_CONFIG_SSL_PARAM STRUCT
	SslHashLength DW
	pSslHash PTR
	AppId GUID
	pSslCertStoreName PTR
	DefaultCertCheckMode DD
	DefaultRevocationFreshnessTime DD
	DefaultRevocationUrlRetrievalTimeout DD
	pDefaultSslCtlIdentifier PTR
	pDefaultSslCtlStoreName PTR
	DefaultFlags DD
ENDS

#define HTTP_SERVICE_CONFIG_SSL_FLAG_USE_DS_MAPPER         0x00000001
#define HTTP_SERVICE_CONFIG_SSL_FLAG_NEGOTIATE_CLIENT_CERT 0x00000002
#if WINVER < NTDII_VISTA
	#define HTTP_SERVICE_CONFIG_SSL_FLAG_NO_RAW_FILTER         0x00000004
#endif // WINVER < NTDII_VISTA

//
// This data structure is used by HttpSetServiceConfiguration() for the
// config ID HttpServiceConfigSSLCertInfo.  It's used to add a new record
// to the SSL store.
//

HTTP_SERVICE_CONFIG_SSL_SET STRUCT
	KeyDesc HTTP_SERVICE_CONFIG_SSL_KEY
	ParamDesc HTTP_SERVICE_CONFIG_SSL_PARAM
ENDS

//
// This data structure is used by HttpQueryServiceConfiguration() for the
// config ID HttpServiceConfigSSLCertInfo. It's used to query a particular
// record from the SSL store.
//
// If QueryType is HttpServiceConfigQueryExact, then one particular record of
// the type HTTP_SERVICE_CONFIG_SSL_SET is returned. If the QueryType is
// HttpServiceConfigQueryNext, then the next instance of
// HTTP_SERVICE_CONFIG_SSL_SET is returned. In such cases, the dwToken field
// represents the cursor. For the first item,  dwToken has to be 0.
// For subsequent items, dwToken has to be incremented by 1,
// until ERROR_NO_MORE_ITEMS is returned.
//

HTTP_SERVICE_CONFIG_SSL_QUERY STRUCT
	QueryDesc DD
	KeyDesc HTTP_SERVICE_CONFIG_SSL_KEY
	dwToken DD
ENDS

//
// Set/Delete IP Listen-Only List record
//
// Used as a parameter to both HttpSetServiceConfiguration() and
// HttpDeleteServiceConfiguration() functions.
//

HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM STRUCT
	AddrLength DW
	pAddress PTR
ENDS

//
// Query IP Listen-Only List record.
//
// Parameter to HttpQueryServiceConfiguration() for the config ID
// HttpServiceConfigIPListenList.  On successful return, AddrList
// contains an array of AddrCount elements.  Caller must provide a
// large enough buffer to hold all elements in one call.
//
// Caller may determine the type of each returned element by examining
// AddrList[i].ss_family. If it's AF_INET, use ((PSOCKADDR_IN) &AddrList[i]);
// otherwise, for AF_INET6, use ((PSOCKADDR_IN6) &AddrList[i])
// to select the appropriate address type.
//
#IFNDEF SOCKADDR_STORAGE
	SOCKADDR_STORAGE STRUCT
		ss_family DD
		__ss_pad1 DB 6 DUP
		__ss_align DQ
		__ss_pad2 DB 112 DUP
	ENDS
#ENDIF


HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY STRUCT
	AddrCount DD
	AddrList SOCKADDR_STORAGE
ENDS

//
// URL ACL
//
//
HTTP_SERVICE_CONFIG_URLACL_KEY STRUCT
	pUrlPrefix PTR
ENDS

//
// This defines a record for the SSL config store.
//

HTTP_SERVICE_CONFIG_URLACL_PARAM STRUCT
	pStringSecurityDescriptor PTR
ENDS

//
// This data structure is used by HttpSetServiceConfiguration for the config ID
// HttpServiceConfigUrlAclInfo. It is used to add a new record to the URL ACL
// store.
//

HTTP_SERVICE_CONFIG_URLACL_SET STRUCT
	KeyDesc HTTP_SERVICE_CONFIG_URLACL_KEY
	ParamDesc HTTP_SERVICE_CONFIG_URLACL_PARAM
ENDS

//
// This data structure is used by HttpQueryServiceConfiguration() for the
// config ID HttpServiceConfigUrlAclInfo. It's used to query a particular
// record from the URL ACL store.
//
// If QueryType is HttpServiceConfigQueryExact, then one particular record of
// the type HTTP_SERVICE_CONFIG_URLACL_SET is returned. If the QueryType is
// HttpServiceConfigQueryNext, then the next instance of
// HTTP_SERVICE_CONFIG_URLACL_SET is returned. In such cases, the dwToken field
// represents the cursor. For the first item,  dwToken has to be 0.
// For subsequent items, dwToken has to be incremented by 1,
// until ERROR_NO_MORE_ITEMS is returned.
//

HTTP_SERVICE_CONFIG_URLACL_QUERY STRUCT
	QueryDesc DD
	KeyDesc HTTP_SERVICE_CONFIG_URLACL_KEY
	dwToken DD
ENDS

#endif // WINVER >= NTDDI_WINXPSP2

#endif //


