#ifndef RASEAPIF_H
#define RASEAPIF_H

/* Remote Access Service PPP engine and third party authentication module interface definitions */

#define RAS_EAP_REGISTRY_LOCATION  "System\CurrentControlSet\Services\Rasman\PPP\EAP"

#define RAS_EAP_VALUENAME_PATH  "Path"
#define RAS_EAP_VALUENAME_CONFIGUI  "ConfigUIPath"
#define RAS_EAP_VALUENAME_INTERACTIVEUI  "InteractiveUIPath"
#define RAS_EAP_VALUENAME_IDENTITY  "IdentityPath"
#define RAS_EAP_VALUENAME_FRIENDLY_NAME  "FriendlyName"
#define RAS_EAP_VALUENAME_DEFAULT_DATA  "ConfigData"
#define RAS_EAP_VALUENAME_REQUIRE_CONFIGUI  "RequireConfigUI"
#define RAS_EAP_VALUENAME_ENCRYPTION  "MPPEEncryptionSupported"
#define RAS_EAP_VALUENAME_INVOKE_NAMEDLG  "InvokeUsernameDialog"
#define RAS_EAP_VALUENAME_INVOKE_PWDDLG  "InvokePasswordDialog"
#define RAS_EAP_VALUENAME_CONFIG_CLSID  "ConfigCLSID"
#define RAS_EAP_VALUENAME_STANDALONE_SUPPORTED  "StandaloneSupported"

#define raatARAPChallenge  33
#define raatARAPOldPassword  19
#define raatARAPNewPassword  20
#define raatARAPPasswordChangeReason  21

#define EAPCODE_Request  1
#define EAPCODE_Response  2
#define EAPCODE_Success  3
#define EAPCODE_Failure  4

#define MAXEAPCODE  4

#define RAS_EAP_FLAG_ROUTER  0x00000001
#define RAS_EAP_FLAG_NON_INTERACTIVE  0x00000002
#define RAS_EAP_FLAG_LOGON  0x00000004
#define RAS_EAP_FLAG_PREVIEW  0x00000008
#define RAS_EAP_FLAG_FIRST_LINK  0x00000010

raatMinimum = 0
raatUserName = 1
raatUserPassword = 2
raatMD5CHAPPassword = 3
raatNASIPAddress = 4
raatNASPort = 5
raatServiceType = 6
raatFramedProtocol = 7
raatFramedIPAddress = 8
raatFramedIPNetmask = 9
raatFramedRouting = 10
raatFilterId = 11
raatFramedMTU = 12
raatFramedCompression = 13
raatLoginIPHost = 14
raatLoginService = 15
raatLoginTCPPort = 16
raatUnassigned17 = 17
raatReplyMessage = 18
raatCallbackNumber = 19
raatCallbackId = 20
raatUnassigned21 = 21
raatFramedRoute = 22
raatFramedIPXNetwork = 23
raatState = 24
raatClass = 25
raatVendorSpecific = 26
raatSessionTimeout = 27
raatIdleTimeout = 28
raatTerminationAction = 29
raatCalledStationId = 30
raatCallingStationId = 31
raatNASIdentifier = 32
raatProxyState = 33
raatLoginLATService = 34
raatLoginLATNode = 35
raatLoginLATGroup = 36
raatFramedAppleTalkLink = 37
raatFramedAppleTalkNetwork = 38
raatFramedAppleTalkZone = 39
raatAcctStatusType = 40
raatAcctDelayTime = 41
raatAcctInputOctets = 42
raatAcctOutputOctets = 43
raatAcctSessionId = 44
raatAcctAuthentic = 45
raatAcctSessionTime = 46
raatAcctInputPackets = 47
raatAcctOutputPackets = 48
raatAcctTerminateCause = 49
raatAcctMultiSessionId = 50
raatAcctLinkCount = 51
raatAcctEventTimeStamp = 55
raatMD5CHAPChallenge = 60
raatNASPortType = 61
raatPortLimit = 62
raatLoginLATPort = 63
raatTunnelType = 64
raatTunnelMediumType = 65
raatTunnelClientEndpoint = 66
raatTunnelServerEndpoint = 67
raatARAPPassword = 70
raatARAPFeatures = 71
raatARAPZoneAccess = 72
raatARAPSecurity = 73
raatARAPSecurityData = 74
raatPasswordRetry = 75
raatPrompt = 76
raatConnectInfo = 77
raatConfigurationToken = 78
raatEAPMessage = 79
raatSignature = 80
raatARAPChallengeResponse = 84
raatAcctInterimInterval = 85
raatARAPGuestLogon = 8096
raatReserved = 0xFFFFFFFF

RAS_AUTH_ATTRIBUTE STRUCT
	raaType DD
	dwLength DD
	Value PTR
ENDS

PPP_EAP_PACKET STRUCT
	Code DB
	Id DB
	Length DB 2 DUP
	Data DB
ENDS

PPP_EAP_INPUT STRUCT
	dwSizeInBytes DD
	fFlags DD
	fAuthenticator DD
	pwszIdentity PTR
	pwszPassword PTR
	bInitialId DB
	pUserAttributes PTR
	fAuthenticationComplete DD
	dwAuthResultCode DD
	hTokenImpersonateUser HANDLE
	fSuccessPacketReceived DD
	fDataReceivedFromInteractiveUI DD
	pDataFromInteractiveUI PTR
	dwSizeOfDataFromInteractiveUI DD
	pConnectionData DD
	dwSizeOfConnectionData DD
	pUserData PTR
	dwSizeOfUserData DD
	hReserved HANDLE
ENDS

EAPACTION_NoAction = 0
EAPACTION_Authenticate = 1
EAPACTION_Done = 2
EAPACTION_SendAndDone = 3
EAPACTION_Send = 4
EAPACTION_SendWithTimeout = 5
EAPACTION_SendWithTimeoutInteractive = 6

PPP_EAP_OUTPUT STRUCT
	dwSizeInBytes DD
	Action DD
	dwAuthResultCode DD
	pUserAttributes PTR
	fInvokeInteractiveUI DD
	pUIContextData DD
	dwSizeOfUIContextData DD
	fSaveConnectionData DD
	pConnectionData PTR
	dwSizeOfConnectionData DD
	fSaveUserData DD
	pUserData PTR
	dwSizeOfUserData DD
ENDS

PPP_EAP_INFO STRUCT
	dwSizeInBytes DD
	dwEapTypeId DD
	RasEapInitialize PTR
	RasEapBegin PTR
	RasEapEnd PTR
	RasEapMakeMessage PTR
ENDS

#endif
