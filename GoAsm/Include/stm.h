#ifndef STM_H
#define STM_H

/* IPX Routing Protocol Service Table Manager API definitions */

#define SERVICES  0x00000002
#define DEMAND_UPDATE_SERVICES  0x00000008

#define STM_ONLY_THIS_INTERFACE  0x00000001
#define STM_ONLY_THIS_PROTOCOL  0x00000002
#define STM_ONLY_THIS_TYPE  0x00000004
#define STM_ONLY_THIS_NAME  0x00000008

#define STM_ORDER_BY_TYPE_AND_NAME  0
#define STM_ORDER_BY_INTERFACE_TYPE_NAME  1

IPX_SERVER_ENTRY STRUCT
	Type DW
	Name DB 48 DUP
	Network DB 4 DUP
	Node DB 6 DUP
	Socket DB 2 DUP
	HopCount DW
ENDS

IPX_SERVICE STRUCT
	InterfaceIndex DD
	Protocol DD
	Server IPX_SERVER_ENTRY
ENDS

MPR40_SERVICE_CHARACTERISTICS STRUCT
	dwVersion DD
	dwProtocolId DD
	fSupportedFunctionality DD
	pfnIsService PTR
	pfnUpdateServices PTR
	pfnCreateServiceEnumerationHandle PTR
	pfnEnumerateGetNextService PTR
	pfnCloseServiceEnumerationHandle PTR
	pfnGetServiceCount PTR
	pfnCreateStaticService PTR
	pfnDeleteStaticService PTR
	pfnBlockConvertServicesToStatic PTR
	pfnBlockDeleteStaticServices PTR
	pfnGetFirstOrderedService PTR
	pfnGetNextOrderedService PTR
ENDS

#define MPR50_SERVICE_CHARACTERISTICS MPR40_SERVICE_CHARACTERISTICS

#endif /* _STM_H */
