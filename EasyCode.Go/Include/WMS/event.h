

/* this ALWAYS GENERATED file contains the definitions for the interfaces */

#ifndef EVENT_H
#define EVENT_H

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif /* COM_NO_WINDOWS_H */

/* header files for imported files */
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

;#include "WMSContext.h"
;#include "WMSEvent.h"
 
#DEFINE GUID_IID_IWMSEventNotificationPlugin <0xBE185FF0,0x6932,0x11d2,0x8B,0x3B,0x00,0x60,0x97,0xB0,0x12,0x06>
#DEFINE GUID_IID_IWMSEventAuthorizationPlugin <0xBE185FF1,0x6932,0x11d2,0x8B,0x3B,0x00,0x60,0x97,0xB0,0x12,0x06>
#DEFINE GUID_IID_IWMSEventAuthorizationCallback <0xBE185FF2,0x6932,0x11d2,0x8B,0x3B,0x00,0x60,0x97,0xB0,0x12,0x06>
#DEFINE GUID_IID_IWMSCustomEventCallback <0x8fbd4d04,0x970d,0x4d37,0xbb,0xc6,0x6f,0xbb,0xb7,0x4e,0xac,0x9d>

WMS_EVENT_SERVER_ONLINE	= 0
WMS_EVENT_SERVER_OFFLINE	= 1
WMS_EVENT_SERVER_CRITICAL_ERROR	= 2
WMS_EVENT_SERVER_PROPERTY_CHANGE	= 3
WMS_EVENT_SERVER_ALLOW_CLIENTS_TO_CONNECT_CHANGE	= 4
WMS_EVENT_SERVER_PLUGIN_LOAD_TYPE_CHANGE	= 5
WMS_EVENT_SERVER_REVERSE_PROXY_MODE_CHANGE	= 6
WMS_EVENT_SERVER_DOWNLOAD_START	= 7
WMS_EVENT_SERVER_DOWNLOAD_COMPLETE	= 8
WMS_NUM_SERVER_EVENTS	= 9

WMS_EVENT_PUBLISHING_POINT_ADD	= 0
WMS_EVENT_PUBLISHING_POINT_REMOVE	= 1
WMS_EVENT_PUBLISHING_POINT_ALLOW_CLIENTS_TO_CONNECT_CHANGE	= 2
WMS_EVENT_PUBLISHING_POINT_START_WITHOUT_DATA	= 3
WMS_EVENT_PUBLISHING_POINT_START	= 4
WMS_EVENT_PUBLISHING_POINT_STOP	= 5
WMS_EVENT_PUBLISHING_POINT_START_ARCHIVE	= 6
WMS_EVENT_PUBLISHING_POINT_STOP_ARCHIVE	= 7
WMS_EVENT_PUBLISHING_POINT_NAME_CHANGE	= 8
WMS_EVENT_PUBLISHING_POINT_PATH_CHANGE	= 9
WMS_EVENT_PUBLISHING_POINT_ALLOW_CLIENT_TO_START_AND_STOP_CHANGE	= 10
WMS_EVENT_PUBLISHING_POINT_PROPERTY_CHANGE	= 11
WMS_EVENT_PUBLISHING_POINT_WRAPPER_PATH_CHANGE	= 12
WMS_EVENT_PUBLISHING_POINT_ENABLE_WRAPPER_PATH_CHANGE	= 13
WMS_EVENT_PUBLISHING_POINT_ALLOW_CONTENT_CACHING_CHANGE	= 14
WMS_EVENT_PUBLISHING_POINT_STREAM_END	= 15
WMS_EVENT_PUBLISHING_POINT_CRITICAL_ERROR	= 16
WMS_EVENT_PUBLISHING_POINT_ENABLE_CLIENT_WILDCARD_DIRECTORY_ACCESS_CHANGE	= 17
WMS_EVENT_PUBLISHING_POINT_DISTRIBUTION_USER_NAME_CHANGE	= 18
WMS_EVENT_PUBLISHING_POINT_DISTRIBUTION_PASSWORD_CHANGE	= 19
WMS_EVENT_PUBLISHING_POINT_ALLOW_PLAYER_SIDE_DISK_CACHING_CHANGE	= 20
WMS_EVENT_PUBLISHING_POINT_BUFFER_SETTING_CHANGE	= 21
WMS_EVENT_PUBLISHING_POINT_ENABLE_FEC_CHANGE	= 22
WMS_EVENT_PUBLISHING_POINT_ENABLE_STARTUPPROFILE_CHANGE	= 23
WMS_EVENT_PUBLISHING_POINT_ENABLE_VROOT_START_CHANGE	= 24
WMS_NUM_PUBLISHINGPOINT_EVENTS	= 25

WMS_EVENT_LIMIT_CHANGE_CONNECTED_PLAYERS	= 0
WMS_EVENT_LIMIT_CHANGE_PLAYER_BANDWIDTH	= 1
WMS_EVENT_LIMIT_CHANGE_PLAYER_CONNECTION_BANDWIDTH	= 2
WMS_EVENT_LIMIT_CHANGE_DISTRIBUTION_CONNECTIONS	= 3
WMS_EVENT_LIMIT_CHANGE_PLAYER_INACTIVITY_TIMEOUT	= 4
WMS_EVENT_LIMIT_CHANGE_PLAYER_ACKNOWLEDGEMENT_TIMEOUT	= 5
WMS_EVENT_LIMIT_CHANGE_CONNECTION_RATE	= 6
WMS_EVENT_LIMIT_CHANGE_CPU_UTILIZATION_DURING_CONNECTION	= 7
WMS_EVENT_LIMIT_CHANGE_DISTRIBUTION_BANDWIDTH	= 8
WMS_EVENT_LIMIT_CHANGE_DISTRIBUTION_CONNECTION_BANDWIDTH	= 9
WMS_EVENT_LIMIT_CHANGE_DIAGNOSTIC_EVENTS	= 10
WMS_EVENT_LIMIT_CHANGE_PLAYER_CACHE_DELIVERY_RATE	= 11
WMS_EVENT_LIMIT_CHANGE_FEC_PACKET_SPAN	= 12
WMS_EVENT_LIMIT_CHANGE_INCOMING_BANDWIDTH	= 13
WMS_NUM_LIMIT_CHANGE_EVENTS	= 14

WMS_EVENT_LIMIT_HIT_CONNECTED_PLAYERS	= 0
WMS_EVENT_LIMIT_HIT_PLAYER_BANDWIDTH	= 1
WMS_EVENT_LIMIT_HIT_PLAYER_CONNECTION_BANDWIDTH	= 2
WMS_EVENT_LIMIT_HIT_DISTRIBUTION_CONNECTIONS	= 3
WMS_EVENT_LIMIT_HIT_PLAYER_INACTIVITY_TIMEOUT	= 4
WMS_EVENT_LIMIT_HIT_PLAYER_ACKNOWLEDGEMENT_TIMEOUT	= 5
WMS_EVENT_LIMIT_HIT_CONNECTION_RATE	= 6
WMS_EVENT_LIMIT_HIT_CPU_UTILIZATION_DURING_CONNECTION	= 7
WMS_EVENT_LIMIT_HIT_DISTRIBUTION_BANDWIDTH	= 8
WMS_EVENT_LIMIT_HIT_DISTRIBUTION_CONNECTION_BANDWIDTH	= 9
WMS_EVENT_LIMIT_HIT_INCOMING_BANDWIDTH	= 10
WMS_NUM_LIMIT_HIT_EVENTS	= 11

WMS_EVENT_PLUGIN_ADD	= 0
WMS_EVENT_PLUGIN_REMOVE	= 1
WMS_EVENT_PLUGIN_ENABLE	= 2
WMS_EVENT_PLUGIN_DISABLE	= 3
WMS_EVENT_PLUGIN_PROPERTY_CHANGE	= 4
WMS_EVENT_PLUGIN_ERROR	= 5
WMS_EVENT_PLUGIN_NAME_CHANGE	= 6
WMS_EVENT_PLUGIN_LOAD_TYPE_CHANGE	= 7
WMS_EVENT_PLUGIN_SELECTION_ORDER_CHANGE	= 8
WMS_NUM_PLUGIN_EVENTS	= 9

WMS_EVENT_CACHE_HIT	= 0
WMS_EVENT_CACHE_MISS	= 1
WMS_EVENT_CACHE_DOWNLOAD_START	= 2
WMS_EVENT_CACHE_DOWNLOAD_COMPLETE	= 3
WMS_EVENT_CACHE_REDIRECT	= 4
WMS_EVENT_CACHE_REDIRECT_TO_PROXY	= 5
WMS_EVENT_CACHE_PRESTUFF_COMPLETE	= 6
WMS_NUM_CACHE_EVENTS	= 7

WMS_EVENT_PLAYLIST_SWITCH	= 0
WMS_EVENT_PLAYLIST_CUE	= 1
WMS_EVENT_PLAYLIST_MODIFY	= 2
WMS_EVENT_PLAYLIST_FAILOVER	= 3
WMS_NUM_PLAYLIST_EVENTS	= 4

WMS_RECORD_PROGRESS_ARCHIVE_STARTED	= 0
WMS_RECORD_PROGRESS_ARCHIVE_FINISHED	= 1

IWMSEventNotificationPlugin STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetHandledEvents PTR
	OnEvent PTR
ENDS

IWMSEventAuthorizationPlugin STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetAuthorizedEvents PTR
	AuthorizeEvent PTR
ENDS

IWMSEventAuthorizationCallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnAuthorizeEvent PTR
ENDS

#endif



