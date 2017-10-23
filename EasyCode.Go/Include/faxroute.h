#ifndef FAXROUTE_H
#define FAXROUTE_H

/* FAX routing extension API definitions */

#IFNDEF COMMCTRL_H
	#include commctrl.h
#ENDIF

#define MS_FAXROUTE_PRINTING_GUID  "{aec1b37c-9af2-11d0-abf7-00c04fd91a4e}"
#define MS_FAXROUTE_INBOX_GUID  "{9d3d0c32-9af2-11d0-abf7-00c04fd91a4e}"
#define MS_FAXROUTE_FOLDER_GUID  "{92041a90-9af2-11d0-abf7-00c04fd91a4e}"
#define MS_FAXROUTE_EMAIL_GUID  "{6bbf7bfe-9af2-11d0-abf7-00c04fd91a4e}"

FAX_ROUTE_CALLBACKROUTINES STRUCT
	SizeOfStruct DD
	FaxRouteAddFile PTR
	FaxRouteDeleteFile PTR
	FaxRouteGetFile PTR
	FaxRouteEnumFiles PTR
	FaxRouteModifyRoutingData PTR
ENDS

FAX_ROUTE STRUCT
	SizeOfStruct DD
	JobId DD
	ElapsedTime DWORDLONG
	ReceiveTime DWORDLONG
	PageCount DD
	Csid PTR
	Tsid PTR
	CallerId PTR
	RoutingInfo PTR
	ReceiverName PTR
	ReceiverNumber PTR
	DeviceName PTR
	DeviceId DD
	RoutingInfoData PTR
	RoutingInfoDataSize DD
ENDS

QUERY_STATUS = -1
STATUS_DISABLE = 0
STATUS_ENABLE = 1

#endif /* FAXROUTE_H */
