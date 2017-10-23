#ifndef AUTHIF_H
#define AUTHIF_H

/* Internet Authentication Service extension definitions */

#define AUTHSRV_PARAMETERS_KEY_W  L"System\\CurrentControlSet\\Services\\AuthSrv\\Parameters"
#define AUTHSRV_EXTENSIONS_VALUE_W  L"ExtensionDLLs"
#define AUTHSRV_AUTHORIZATION_VALUE_W  L"AuthorizationDLLs"

#define AUTHSRV_PARAMETERS_KEY_A  A"System\\CurrentControlSet\\Services\\AuthSrv\\Parameters"
#define AUTHSRV_EXTENSIONS_VALUE_A  A"ExtensionDLLs"
#define AUTHSRV_AUTHORIZATION_VALUE_A  A"AuthorizationDLLs"

#IFDEF UNICODE
	#define AUTHSRV_PARAMETERS_KEY AUTHSRV_PARAMETERS_KEY_W
	#define AUTHSRV_EXTENSIONS_VALUE AUTHSRV_EXTENSIONS_VALUE_W
	#define AUTHSRV_AUTHORIZATION_VALUE AUTHSRV_AUTHORIZATION_VALUE_W
#ELSE
	#define AUTHSRV_PARAMETERS_KEY AUTHSRV_PARAMETERS_KEY_A
	#define AUTHSRV_EXTENSIONS_VALUE AUTHSRV_EXTENSIONS_VALUE_A
	#define AUTHSRV_AUTHORIZATION_VALUE AUTHSRV_AUTHORIZATION_VALUE_A
#ENDIF

#define RADIUS_EXTENSION_INIT  "RadiusExtensionInit"
#define RADIUS_EXTENSION_TERM  "RadiusExtensionTerm"
#define RADIUS_EXTENSION_PROCESS  "RadiusExtensionProcess"
#define RADIUS_EXTENSION_PROCESS_EX  "RadiusExtensionProcessEx"
#define RADIUS_EXTENSION_FREE_ATTRIBUTES  "RadiusExtensionFreeAttributes"

ratMinimum = 0
ratUserName = 1
ratUserPassword = 2
ratCHAPPassword = 3
ratNASIPAddress = 4
ratNASPort = 5
ratServiceType = 6
ratFramedProtocol = 7
ratFramedIPAddress = 8
ratFramedIPNetmask = 9
ratFramedRouting = 10
ratFilterId = 11
ratFramedMTU = 12
ratFramedCompression = 13
ratLoginIPHost = 14
ratLoginService = 15
ratLoginPort = 16
ratReplyMessage = 18
ratCallbackNumber = 19
ratCallbackId = 20
ratFramedRoute = 22
ratFramedIPXNetwork = 23
ratState = 24
ratClass = 25
ratVendorSpecific = 26
ratSessionTimeout = 27
ratIdleTimeout = 28
ratTerminationAction = 29
ratCalledStationId = 30
ratCallingStationId = 31
ratNASIdentifier = 32
ratProxyState = 33
ratLoginLATService = 34
ratLoginLATNode = 35
ratLoginLATGroup = 36
ratFramedAppleTalkLink = 37
ratFramedAppleTalkNetwork = 38
ratFramedAppleTalkZone = 39
ratAcctStatusType = 40
ratAcctDelayTime = 41
ratAcctInputOctets = 42
ratAcctOutputOctets = 43
ratAcctSessionId = 44
ratAcctAuthentic = 45
ratAcctSessionTime = 46
ratAcctInputPackets = 47
ratAcctOutputPackets = 48
ratAcctTerminationCause = 49
ratCHAPChallenge = 60
ratNASPortType = 61
ratPortLimit = 62
ratCode = 262
ratIdentifier = 263
ratAuthenticator = 264
ratSrcIPAddress = 265
ratSrcPort = 266
ratProvider = 267
ratStrippedUserName = 268
ratFQUserName = 269
ratPolicyName = 270

rapUnknown = 0
rapUsersFile = 1
rapProxy = 2
rapWindowsNT = 3
rapMCIS = 4
rapODBC = 5

rdtUnknown = 0
rdtString = 1
rdtAddress = 2
rdtInteger = 3
rdtTime = 4

RADIUS_ATTRIBUTE STRUCT
	dwAttrType DD
	fDataType DD
	cbDataLength DD
	UNION
		dwValue DD
		lpValue PTR
	ENDUNION
ENDS

raContinue = 0
raReject = 1
raAccept = 2

#endif /* _AUTHIF_H */
