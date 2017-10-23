#ifndef RAS_H
#define RAS_H

/* Remote Access API definitions */

#ifndef LMCONS_H
	#include lmcons.h
#endif

#IFDEF LINKFILES
	#dynamiclinkfile Rasapi32.dll
#ENDIF

#ifdef USES_RAS_QUARANTINE_APIS

isolationStateNotRestricted	= 1
isolationStateInProbation	= 2
isolationStateRestrictedAccess	= 3

#define RASNAP_ProbationTime            0x00000001

RASNAPSTATE STRUCT
	dwSize DD
	dwFlags DD
	isolationState DD
	probationTime DD
ENDS

#endif // USES_RAS_QUARANTINE_APIS

#define RAS_MaxDeviceType  16
#define RAS_MaxPhoneNumber  128
#define RAS_MaxIpAddress  15
#define RAS_MaxIpxAddress  21
#ifndef WIN9X
	#define RAS_MaxEntryName  256
	#define RAS_MaxDeviceName  128
	#define RAS_MaxCallbackNumber RAS_MaxPhoneNumber
#else
	 ; Windows 95 only
	#define RAS_MaxEntryName  20
	#define RAS_MaxDeviceName  32
	#define RAS_MaxCallbackNumber 48
#endif
#define RAS_MaxAreaCode       10
#define RAS_MaxPadType        32
#define RAS_MaxX25Address     200
#define RAS_MaxFacilities     200
#define RAS_MaxUserData       200
#define RAS_MaxReplyMessage   1024
#define RAS_MaxDnsSuffix      256

#define RASCF_AllUsers	      0x00000001
#define RASCF_GlobalCreds     0x00000002
#define RASCF_OwnerKnown      0x00000004
#define RASCF_OwnerMatch      0x00000008

RASCONNW STRUCT
	dwSize DD
	hrasconn HANDLE
	szEntryName DW RAS_MaxEntryName+1 DUP
	szDeviceType DW RAS_MaxDeviceType+1 DUP
	szDeviceName DW RAS_MaxDeviceName+1 DUP
	szPhonebook DW MAX_PATH DUP
	dwSubEntry DD
#IFDEF WINXP
	guidEntry GUID
	dwFlags DD
	luid LUID
#ENDIF
#IFDEF VISTA
	guidEntry GUID
	dwFlags DD
	luid LUID
	guidCorrelationId GUID
#ENDIF
ENDS

RASCONNA STRUCT
	dwSize DD
	hrasconn DD
	szEntryName DB RAS_MaxEntryName+1 DUP
	szDeviceType DB RAS_MaxDeviceType+1 DUP
	szDeviceName DB RAS_MaxDeviceName+1 DUP
	szPhonebook DB MAX_PATH DUP
	dwSubEntry DD
#IFDEF WINXP
	guidEntry GUID
	dwFlags DD
	luid LUID
#ENDIF
#IFDEF VISTA
	guidEntry GUID
	dwFlags DD
	luid LUID
	guidCorrelationId GUID
#ENDIF
ENDS

#define RASCS_PAUSED 0x1000
#define RASCS_DONE  0x2000

RASCS_OpenPort = 0
RASCS_PortOpened = 2
RASCS_ConnectDevice = 3
RASCS_DeviceConnected = 4
RASCS_AllDevicesConnected = 5
RASCS_Authenticate = 6
RASCS_AuthNotify = 7
RASCS_AuthRetry = 8
RASCS_AuthCallback = 9
RASCS_AuthChangePassword = 10
RASCS_AuthProject = 11
RASCS_AuthLinkSpeed = 12
RASCS_AuthAck = 13
RASCS_ReAuthenticate = 14
RASCS_Authenticated = 15
RASCS_PrepareForCallback = 16
RASCS_WaitForModemReset = 17
RASCS_WaitForCallback = 18
RASCS_Projected = 19
RASCS_StartAuthentication = 20
RASCS_CallbackComplete = 21
RASCS_LogonNetwork = 22
RASCS_SubEntryConnected = 23
RASCS_SubEntryDisconnected = 24
RASCS_Interactive = RASCS_PAUSED
RASCS_RetryAuthentication = 26
RASCS_CallbackSetByCaller = 27
RASCS_PasswordExpired = 28
RASCS_InvokeEapUI = 29
RASCS_Connected = RASCS_DONE
RASCS_Disconnected = 31

RASCONNSTATUSW STRUCT
	dwSize DD
	rasconnstate DD
	dwError DD
	szDeviceType DW RAS_MaxDeviceType+1 DUP
	szDeviceName DW RAS_MaxDeviceName+1 DUP
#IFNDEF WIN9X
	szPhoneNumber DW RAS_MaxPhoneNumber+1 DUP
#ENDIF
ENDS

RASCONNSTATUSA STRUCT
	dwSize DD
	rasconnstate DD
	dwError DD
	szDeviceType DB RAS_MaxDeviceType+1 DUP
	szDeviceName DB RAS_MaxDeviceName+1 DUP
#IFNDEF WIN9X
	szPhoneNumber DW RAS_MaxPhoneNumber+1 DUP
#ENDIF
ENDS

RASDIALPARAMSW STRUCT
	dwSize DD
	szEntryName DW RAS_MaxEntryName+1 DUP
	szPhoneNumber DW RAS_MaxPhoneNumber+1 DUP
	szCallbackNumber DW RAS_MaxCallbackNumber+1 DUP
	szUserName DW UNLEN+1 DUP
	szPassword DW PWLEN+1 DUP
	szDomain DW DNLEN+1 DUP
#IFNDEF WIN9X
	dwSubEntry DD
	dwCallbackId ULONG_PTR
#ENDIF
ENDS

RASDIALPARAMSA STRUCT
	dwSize DD
	szEntryName DB RAS_MaxEntryName+1 DUP
	szPhoneNumber DB RAS_MaxPhoneNumber+1 DUP
	szCallbackNumber DB RAS_MaxCallbackNumber+1 DUP
	szUserName DB UNLEN+1 DUP
	szPassword DB PWLEN+1 DUP
	szDomain DB DNLEN+1 DUP
#IFNDEF WIN9X
	dwSubEntry DD
	dwCallbackId ULONG_PTR
#ENDIF
ENDS

RASEAPINFO STRUCT
	dwSizeofEapInfo DD
	pbEapInfo PTR
ENDS

RASDIALEXTENSIONS STRUCT
	dwSize DD
	dwfOptions DD
	hwndParent HANDLE
	reserved ULONG_PTR
#IFNDEF WINNT4
	reserved1 ULONG_PTR
	RasEapInfo RASEAPINFO
#ENDIF
ENDS

#define RDEOPT_UsePrefixSuffix  0x00000001
#define RDEOPT_PausedStates  0x00000002
#define RDEOPT_IgnoreModemSpeaker  0x00000004
#define RDEOPT_SetModemSpeaker  0x00000008
#define RDEOPT_IgnoreSoftwareCompression 0x00000010
#define RDEOPT_SetSoftwareCompression  0x00000020
#define RDEOPT_DisableConnectedUI  0x00000040
#define RDEOPT_DisableReconnectUI  0x00000080
#define RDEOPT_DisableReconnect  0x00000100
#define RDEOPT_NoUser  0x00000200
#define RDEOPT_PauseOnScript  0x00000400
#define RDEOPT_Router  0x00000800

#define RDEOPT_CustomDial  0x00001000
#define RDEOPT_UseCustomScripting  0x00002000

#define REN_User  0x00000000
#define REN_AllUsers  0x00000001

RASENTRYNAMEW STRUCT
	dwSize DD
	szEntryName DW RAS_MaxEntryName+1 DUP
#IFNDEF WIN9X
	dwFlags DD
	szPhonebookPath DW MAX_PATH+1 DUP
#ENDIF
ENDS

RASENTRYNAMEA STRUCT
	dwSize DD
	szEntryName DB RAS_MaxEntryName+1 DUP
#IFNDEF WIN9X
	dwFlags DD
	szPhonebookPath DB MAX_PATH+1 DUP
#ENDIF
ENDS

RASP_Amb = 0x10000
RASP_PppNbf = 0x803F
RASP_PppIpx = 0x802B
RASP_PppIp = 0x8021
RASP_PppCcp = 0x80FD
RASP_PppLcp = 0xC021
RASP_Slip = 0x20000

RASAMBW STRUCT
	dwSize DD
	dwError DD
	szNetBiosError DW NETBIOS_NAME_LEN+1 DUP
	bLana DB
ENDS

RASAMBW STRUCT
	dwSize DD
	dwError DD
	szNetBiosError DB NETBIOS_NAME_LEN+1 DUP
	bLana DB
ENDS

RASPPPNBFW STRUCT
	dwSize DD
	dwError DD
	dwNetBiosError DD
	szNetBiosError DW NETBIOS_NAME_LEN+1 DUP
	szWorkstationName DW NETBIOS_NAME_LEN+1 DUP
	bLana DB
ENDS

RASPPPNBFA STRUCT
	dwSize DD
	dwError DD
	dwNetBiosError DD
	szNetBiosError DB NETBIOS_NAME_LEN+1 DUP
	szWorkstationName DB NETBIOS_NAME_LEN+1 DUP
	bLana DB
ENDS

RASPPPIPXW STRUCT
	dwSize DD
	dwError DD
	szIpxAddress DW RAS_MaxIpxAddress+1 DUP
ENDS

RASPPPIPXA STRUCT
	dwSize DD
	dwError DD
	szIpxAddress DB RAS_MaxIpxAddress+1 DUP
ENDS

#define RASIPO_VJ  0x00000001

RASPPPIPW STRUCT
	dwSize DD
	dwError DD
	szIpAddress DW RAS_MaxIpAddress+1 DUP
	szServerIpAddress DW RAS_MaxIpAddress+1 DUP
#IFNDEF WINNT4
	dwOptions DD
	dwServerOptions DD
#ENDIF
ENDS

RASPPPIPA STRUCT
	dwSize DD
	dwError DD
	szIpAddress DB RAS_MaxIpAddress+1 DUP
	szServerIpAddress DB RAS_MaxIpAddress+1 DUP
#IFNDEF WINNT4
	dwOptions DD
	dwServerOptions DD
#ENDIF
ENDS

#define RASLCPAP_PAP  0xC023
#define RASLCPAP_SPAP  0xC027
#define RASLCPAP_CHAP  0xC223
#define RASLCPAP_EAP  0xC227

#define RASLCPAD_CHAP_MD5  0x05
#define RASLCPAD_CHAP_MS  0x80
#define RASLCPAD_CHAP_MSV2  0x81

#define RASLCPO_PFC  0x00000001
#define RASLCPO_ACFC  0x00000002
#define RASLCPO_SSHF  0x00000004
#define RASLCPO_DES_56  0x00000008
#define RASLCPO_3_DES  0x00000010

RASPPPLCPW STRUCT
	dwSize DD
	fBundled DD
#IFNDEF WINNT4
	dwError DD
	dwAuthenticationProtocol DD
	dwAuthenticationData DD
	dwEapTypeId DD
	dwServerAuthenticationProtocol DD
	dwServerAuthenticationData DD
	dwServerEapTypeId DD
	fMultilink DD
	dwTerminateReason DD
	dwServerTerminateReason DD
	szReplyMessage DW RAS_MaxReplyMessage DUP
	dwOptions DD
	dwServerOptions DD
#ENDIF
ENDS

RASPPPLCPA STRUCT
	dwSize DD
	fBundled DD
#IFNDEF WINNT4
	dwError DD
	dwAuthenticationProtocol DD
	dwAuthenticationData DD
	dwEapTypeId DD
	dwServerAuthenticationProtocol DD
	dwServerAuthenticationData DD
	dwServerEapTypeId DD
	fMultilink DD
	dwTerminateReason DD
	dwServerTerminateReason DD
	szReplyMessage DB RAS_MaxReplyMessage DUP
	dwOptions DD
	dwServerOptions DD
#ENDIF
ENDS

RASSLIPW STRUCT
	dwSize DD
	dwError DD
	szIpAddress DW RAS_MaxIpAddress+1 DUP
ENDS

RASSLIPA STRUCT
	dwSize DD
	dwError DD
	szIpAddress DB RAS_MaxIpAddress+1 DUP
ENDS

#define RASCCPCA_MPPC  0x00000006
#define RASCCPCA_STAC  0x00000005

#define RASCCPO_Compression  0x00000001
#define RASCCPO_HistoryLess  0x00000002
#define RASCCPO_Encryption56bit  0x00000010
#define RASCCPO_Encryption40bit  0x00000020
#define RASCCPO_Encryption128bit  0x00000040

RASPPPCCP STRUCT
	dwSize DD
	dwError DD
	dwCompressionAlgorithm DD
	dwOptions DD
	dwServerCompressionAlgorithm DD
	dwServerOptions DD
ENDS

#define RASDIALEVENT  "RasDialEvent"
#define WM_RASDIALEVENT 0xCCCD

RASDEVINFOW STRUCT
	dwSize DD
	szDeviceType DW RAS_MaxDeviceType+1 DUP
	szDeviceName DW RAS_MaxDeviceName+1 DUP
ENDS

RASDEVINFOA STRUCT
	dwSize DD
	szDeviceType DB RAS_MaxDeviceType+1 DUP
	szDeviceName DB RAS_MaxDeviceName+1 DUP
ENDS

RASCTRYINFO STRUCT
	dwSize DD
	dwCountryID DD
	dwNextCountryID DD
	dwCountryCode DD
	dwCountryNameOffset DD
ENDS

#define RASCTRYINFO RASCTRYINFOW
#define RASCTRYINFO RASCTRYINFOA

RASIPADDR STRUCT
	a DB
	b DB
	c DB
	d DB
ENDS

#IFNDEF IN6_ADDR
IN6_ADDR STRUCT
	UNION
		Byte DB 16 DUP
		Word DW 8 DUP
	ENDUNION
ENDS
#ENDIF

#define RASIPV6ADDR IN6_ADDR

#define ET_40Bit  1
#define ET_128Bit  2

#define ET_None  0
#define ET_Require  1
#define ET_RequireMax  2
#define ET_Optional  3

#define VS_Default  0
#define VS_PptpOnly  1
#define VS_PptpFirst  2
#define VS_L2tpOnly  3
#define VS_L2tpFirst  4

RASENTRYA STRUCT
	dwSize DD
	dwfOptions DD
	dwCountryID DD
	dwCountryCode DD
	szAreaCode DB RAS_MaxAreaCode+1 DUP
	szLocalPhoneNumber DB RAS_MaxPhoneNumber+1 DUP
	dwAlternateOffset DD
	ipaddr RASIPADDRRAS
	ipaddrDns RASIPADDR
	ipaddrDnsAlt RASIPADDR
	ipaddrWins RASIPADDR
	ipaddrWinsAlt RASIPADDR
	dwFrameSize DD
	dwfNetProtocols DD
	dwFramingProtocol DD
	szScript DB MAX_PATH DUP
	szAutodialDll DB MAX_PATH DUP
	szAutodialFunc DB MAX_PATH DUP
	szDeviceType DB RAS_MaxDeviceType+1 DUP
	szDeviceName DB RAS_MaxDeviceName+1 DUP
	szX25PadType DB RAS_MaxPadType+1 DUP
	szX25Address DB RAS_MaxX25Address+1 DUP
	szX25Facilities DB RAS_MaxFacilities+1 DUP
	szX25UserData DB RAS_MaxUserData+1 DUP
	dwChannels DD
	dwReserved1 DD
	dwReserved2 DD
	dwSubEntries DD
	dwDialMode DD
	dwDialExtraPercent DD
	dwDialExtraSampleSeconds DD
	dwHangUpExtraPercent DD
	dwHangUpExtraSampleSeconds DD
	dwIdleDisconnectSeconds DD
#IFDEF WINXP
	dwType DD
	dwEncryptionType DD
	dwCustomAuthKey DD
	guidId GUID
	szCustomDialDll DB MAX_PATH DUP
	dwVpnStrategy DD
	dwfOptions2 DD
	dwfOptions3 DD
	szDnsSuffix DB RAS_MaxDnsSuffix DUP
	dwTcpWindowSize DD
	szPrerequisitePbk DB MAX_PATH DUP
	szPrerequisiteEntry DB RAS_MaxEntryName+1 DUP
	dwRedialCount DD
	dwRedialPause DD
#ENDIF
#IFDEF VISTA
	dwType DD
	dwEncryptionType DD
	dwCustomAuthKey DD
	guidId GUID
	szCustomDialDll DB MAX_PATH DUP
	dwVpnStrategy DD
	dwfOptions2 DD
	dwfOptions3 DD
	szDnsSuffix DB RAS_MaxDnsSuffix DUP
	dwTcpWindowSize DD
	szPrerequisitePbk DB MAX_PATH DUP
	szPrerequisiteEntry DB RAS_MaxEntryName+1 DUP
	dwRedialCount DD
	dwRedialPause DD
	ipv6addrDns RASIPV6ADDR
	ipv6addrDnsAlt RASIPV6ADDR
	dwIPv4InterfaceMetric DD
	dwIPv6InterfaceMetric DD
#ENDIF
ENDS

RASENTRYW STRUCT
	dwSize DD
	dwfOptions DD
	dwCountryID DD
	dwCountryCode DD
	szAreaCode DW RAS_MaxAreaCode+1 DUP
	szLocalPhoneNumber DW RAS_MaxPhoneNumber+1 DUP
	dwAlternateOffset DD
	ipaddr RASIPADDR
	ipaddrDns RASIPADDR
	ipaddrDnsAlt RASIPADDR
	ipaddrWins RASIPADDR
	ipaddrWinsAlt RASIPADDR
	dwFrameSize DD
	dwfNetProtocols DD
	dwFramingProtocol DD
	szScript DW MAX_PATH DUP
	szAutodialDll DW MAX_PATH DUP
	szAutodialFunc DW MAX_PATH DUP
	szDeviceType DW RAS_MaxDeviceType+1 DUP
	szDeviceName DW RAS_MaxDeviceName+1 DUP
	szX25PadType DW RAS_MaxPadType+1 DUP
	szX25Address DW RAS_MaxX25Address+1 DUP
	szX25Facilities DW RAS_MaxFacilities+1 DUP
	szX25UserData DW RAS_MaxUserData+1 DUP
	dwChannels DD
	dwReserved1 DD
	dwReserved2 DD
	dwSubEntries DD
	dwDialMode DD
	dwDialExtraPercent DD
	dwDialExtraSampleSeconds DD
	dwHangUpExtraPercent DD
	dwHangUpExtraSampleSeconds DD
	dwIdleDisconnectSeconds DD
#IFDEF WINXP
	dwType DD
	dwEncryptionType DD
	dwCustomAuthKey DD
	guidId GUID
	szCustomDialDll DW MAX_PATH DUP
	dwVpnStrategy DD
	dwfOptions2 DD
	dwfOptions3 DD
	szDnsSuffix DW RAS_MaxDnsSuffix DUP
	dwTcpWindowSize DD
	szPrerequisitePbk DW MAX_PATH DUP
	szPrerequisiteEntry DW RAS_MaxEntryName+1 DUP
	dwRedialCount DD
	dwRedialPause DD
#ENDIF
#IFDEF VISTA
	dwType DD
	dwEncryptionType DD
	dwCustomAuthKey DD
	guidId GUID
	szCustomDialDll DW MAX_PATH DUP
	dwVpnStrategy DD
	dwfOptions2 DD
	dwfOptions3 DD
	szDnsSuffix DW RAS_MaxDnsSuffix DUP
	dwTcpWindowSize DD
	szPrerequisitePbk DW MAX_PATH DUP
	szPrerequisiteEntry DW RAS_MaxEntryName+1 DUP
	dwRedialCount DD
	dwRedialPause DD
	ipv6addrDns RASIPV6ADDR
	ipv6addrDnsAlt RASIPV6ADDR
	dwIPv4InterfaceMetric DD
	dwIPv6InterfaceMetric DD
#ENDIF
ENDS

#define RASEO_UseCountryAndAreaCodes  0x00000001
#define RASEO_SpecificIpAddr  0x00000002
#define RASEO_SpecificNameServers  0x00000004
#define RASEO_IpHeaderCompression  0x00000008
#define RASEO_RemoteDefaultGateway  0x00000010
#define RASEO_DisableLcpExtensions  0x00000020
#define RASEO_TerminalBeforeDial  0x00000040
#define RASEO_TerminalAfterDial  0x00000080
#define RASEO_ModemLights  0x00000100
#define RASEO_SwCompression  0x00000200
#define RASEO_RequireEncryptedPw  0x00000400
#define RASEO_RequireMsEncryptedPw  0x00000800
#define RASEO_RequireDataEncryption  0x00001000
#define RASEO_NetworkLogon  0x00002000
#define RASEO_UseLogonCredentials  0x00004000
#define RASEO_PromoteAlternates  0x00008000
#define RASEO_SecureLocalFiles  0x00010000

#define RASEO_RequireEAP  0x00020000
#define RASEO_RequirePAP  0x00040000
#define RASEO_RequireSPAP  0x00080000
#define RASEO_Custom  0x00100000

#define RASEO_PreviewPhoneNumber  0x00200000
#define RASEO_SharedPhoneNumbers  0x00800000
#define RASEO_PreviewUserPw  0x01000000
#define RASEO_PreviewDomain  0x02000000
#define RASEO_ShowDialingProgress  0x04000000
#define RASEO_RequireCHAP  0x08000000
#define RASEO_RequireMsCHAP  0x10000000
#define RASEO_RequireMsCHAP2  0x20000000
#define RASEO_RequireW95MSCHAP  0x40000000
#define RASEO_CustomScript  0x80000000

#define RASEO2_SecureFileAndPrint  0x00000001
#define RASEO2_SecureClientForMSNet  0x00000002
#define RASEO2_DontNegotiateMultilink  0x00000004
#define RASEO2_DontUseRasCredentials  0x00000008
#define RASEO2_UsePreSharedKey  0x00000010
#define RASEO2_Internet  0x00000020
#define RASEO2_DisableNbtOverIP  0x00000040
#define RASEO2_UseGlobalDeviceSettings  0x00000080
#define RASEO2_ReconnectIfDropped  0x00000100
#define RASEO2_SharePhoneNumbers  0x00000200

#define RASNP_NetBEUI  0x00000001
#define RASNP_Ipx  0x00000002
#define RASNP_Ip  0x00000004

#define RASFP_Ppp  0x00000001
#define RASFP_Slip  0x00000002
#define RASFP_Ras  0x00000004

#define RASDT_Modem  "modem"
#define RASDT_Isdn  "isdn"
#define RASDT_X25  "x25"
#define RASDT_Vpn  "vpn"
#define RASDT_Pad  "pad"
#define RASDT_Generic  "GENERIC"
#define RASDT_Serial  "SERIAL"
#define RASDT_FrameRelay  "FRAMERELAY"
#define RASDT_Atm  "ATM"
#define RASDT_Sonet  "SONET"
#define RASDT_SW56  "SW56"
#define RASDT_Irda  "IRDA"
#define RASDT_Parallel  "PARALLEL"
#define RASDT_PPPoE  "PPPoE"

#define RASET_Phone  1
#define RASET_Vpn  2
#define RASET_Direct  3
#define RASET_Internet  4
#define RASET_Broadband  5

#define RASCN_Connection  0x00000001
#define RASCN_Disconnection  0x00000002
#define RASCN_BandwidthAdded  0x00000004
#define RASCN_BandwidthRemoved  0x00000008

#define RASEDM_DialAll  1
#define RASEDM_DialAsNeeded  2

#define RASIDS_Disabled  0xffffffff
#define RASIDS_UseGlobalValue  0

RASADPARAMS STRUCT
	dwSize DD
	hwndOwner HANDLE
	dwFlags DD
	xDlg DD
	yDlg DD
ENDS

#define RASADFLG_PositionDlg  0x00000001

RASSUBENTRYA STRUCT
	dwSize DD
	dwfFlags DD
	szDeviceType DB RAS_MaxDeviceType+1 DUP
	szDeviceName DB RAS_MaxDeviceName+1 DUP
	szLocalPhoneNumber DB RAS_MaxPhoneNumber+1 DUP
	dwAlternateOffset DD
ENDS

RASSUBENTRYW STRUCT
	dwSize DD
	dwfFlags DD
	szDeviceType DW RAS_MaxDeviceType+1 DUP
	szDeviceName DW RAS_MaxDeviceName+1 DUP
	szLocalPhoneNumber DW RAS_MaxPhoneNumber+1 DUP
	dwAlternateOffset DD
ENDS

RASCREDENTIALSA STRUCT
	dwSize DD
	dwMask DD
	szUserName DB UNLEN+1 DUP
	szPassword DB PWLEN+1 DUP
	szDomain DB DNLEN+1 DUP
ENDS

RASCREDENTIALSW STRUCT
	dwSize DD
	dwMask DD
	szUserName DW UNLEN+1 DUP
	szPassword DW PWLEN+1 DUP
	szDomain DW DNLEN+1 DUP
ENDS

#define RASCM_UserName  0x00000001
#define RASCM_Password  0x00000002
#define RASCM_Domain  0x00000004
#define RASCM_DefaultCreds  0x00000008
#define RASCM_PreSharedKey  0x00000010
#define RASCM_ServerPreSharedKey  0x00000020
#define RASCM_DDMPreSharedKey  0x00000040

RASAUTODIALENTRYA STRUCT
	dwSize DD
	dwFlags DD
	dwDialingLocation DD
	szEntry DB RAS_MaxEntryName+1 DUP
ENDS

RASAUTODIALENTRYW STRUCT
	dwSize DD
	dwFlags DD
	dwDialingLocation DD
	szEntry DW RAS_MaxEntryName+1 DUP
ENDS

#define RASADP_DisableConnectionQuery  0
#define RASADP_LoginSessionDisable  1
#define RASADP_SavedAddressesLimit  2
#define RASADP_FailedConnectionTimeout  3
#define RASADP_ConnectionQueryTimeout  4

#define RASEAPF_NonInteractive  0x00000002
#define RASEAPF_Logon  0x00000004
#define RASEAPF_Preview  0x00000008

RASEAPUSERIDENTITYA STRUCT
	szUserName DB UNLEN+1 DUP
	dwSizeofEapInfo DD
	pbEapInfo PTR
ENDS

RASEAPUSERIDENTITYW STRUCT
	szUserName DW UNLEN+1 DUP
	dwSizeofEapInfo DD
	pbEapInfo PTR
ENDS

RASCOMMSETTINGS STRUCT
	dwSize DD
	bParity DB
	bStop DB
	bByteSize DB
	bAlign DB
ENDS

RASCUSTOMSCRIPTEXTENSIONS STRUCT
	dwSize DD
	pfnRasSetCommSettings PTR
ENDS

RAS_STATS STRUCT
	dwSize DD
	dwBytesXmited DD
	dwBytesRcved DD
	dwFramesXmited DD
	dwFramesRcved DD
	dwCrcErr DD
	dwTimeoutErr DD
	dwAlignmentErr DD
	dwHardwareOverrunErr DD
	dwFramingErr DD
	dwBufferOverrunErr DD
	dwCompressionRatioIn DD
	dwCompressionRatioOut DD
	dwBps DD
	dwConnectDuration DD
ENDS

#define RCD_SingleUser  0
#define RCD_AllUsers  0x00000001
#define RCD_Eap  0x00000002

#IFDEF UNICODE
	#define RASCONN RASCONNW
	#define RASCONNSTATUS RASCONNSTATUSW
	#define RASDIALPARAMS RASDIALPARAMSW
	#define RASENTRYNAME RASENTRYNAMEW
	#define RASAMB RASAMBW
	#define RASPPPNBF RASPPPNBFW
	#define RASPPPIPX RASPPPIPXW
	#define RASPPPIP RASPPPIPW
	#define RASPPPLCP RASPPPLCPW
	#define RASSLIP RASSLIPW
	#define RASDEVINFO RASDEVINFOW
	#define RASENTRY RASENTRYW
	#define RASSUBENTRY RASSUBENTRYW
	#define RASCREDENTIALS RASCREDENTIALSW
	#define RASAUTODIALENTRY RASAUTODIALENTRYW
	#define RASEAPUSERIDENTITY RASEAPUSERIDENTITYW
	#define RasDial  RasDialW
	#define RasEnumConnections  RasEnumConnectionsW
	#define RasEnumEntries  RasEnumEntriesW
	#define RasGetConnectStatus  RasGetConnectStatusW
	#define RasGetErrorString  RasGetErrorStringW
	#define RasHangUp  RasHangUpW
	#define RasGetProjectionInfo  RasGetProjectionInfoW
	#define RasCreatePhonebookEntry RasCreatePhonebookEntryW
	#define RasEditPhonebookEntry  RasEditPhonebookEntryW
	#define RasSetEntryDialParams  RasSetEntryDialParamsW
	#define RasGetEntryDialParams  RasGetEntryDialParamsW
	#define RasEnumDevices  RasEnumDevicesW
	#define RasGetCountryInfo  RasGetCountryInfoW
	#define RasGetEntryProperties  RasGetEntryPropertiesW
	#define RasSetEntryProperties  RasSetEntryPropertiesW
	#define RasRenameEntry  RasRenameEntryW
	#define RasDeleteEntry  RasDeleteEntryW
	#define RasValidateEntryName  RasValidateEntryNameW
	#define RasGetSubEntryHandle  RasGetSubEntryHandleW
	#define RasConnectionNotification  RasConnectionNotificationW
	#define RasGetSubEntryProperties  RasGetSubEntryPropertiesW
	#define RasSetSubEntryProperties  RasSetSubEntryPropertiesW
	#define RasGetCredentials  RasGetCredentialsW
	#define RasSetCredentials  RasSetCredentialsW
	#define RasGetAutodialAddress  RasGetAutodialAddressW
	#define RasSetAutodialAddress  RasSetAutodialAddressW
	#define RasEnumAutodialAddresses  RasEnumAutodialAddressesW
	#define RasGetAutodialEnable  RasGetAutodialEnableW
	#define RasSetAutodialEnable  RasSetAutodialEnableW
	#define RasGetAutodialParam  RasGetAutodialParamW
	#define RasSetAutodialParam  RasSetAutodialParamW
	#define RasGetEapUserData  RasGetEapUserDataW
	#define RasSetEapUserData  RasSetEapUserDataW
	#define RasGetCustomAuthData  RasGetCustomAuthDataW
	#define RasSetCustomAuthData  RasSetCustomAuthDataW
	#define RasGetEapUserIdentity  RasGetEapUserIdentityW
	#define RasFreeEapUserIdentity  RasFreeEapUserIdentityW
	#define RasDeleteSubEntry RasDeleteSubEntryW
#else
	#define RASCONN RASCONNA
	#define RASCONNSTATUS RASCONNSTATUSA
	#define RASDIALPARAMS RASDIALPARAMSA
	#define RASENTRYNAME RASENTRYNAMEA
	#define RASAMB RASAMBA
	#define RASPPPNBF RASPPPNBFA
	#define RASPPPIPX RASPPPIPXA
	#define RASPPPIP RASPPPIPA
	#define RASPPPLCP RASPPPLCPA
	#define RASSLIP RASSLIPA
	#define RASDEVINFO RASDEVINFOA
	#define RASENTRY RASENTRYA
	#define RASSUBENTRY RASSUBENTRYA
	#define RASCREDENTIALS RASCREDENTIALSA
	#define RASAUTODIALENTRY RASAUTODIALENTRYA
	#define RASEAPUSERIDENTITY RASEAPUSERIDENTITYA
	#define RasDial  RasDialA
	#define RasEnumConnections  RasEnumConnectionsA
	#define RasEnumEntries  RasEnumEntriesA
	#define RasGetConnectStatus  RasGetConnectStatusA
	#define RasGetErrorString  RasGetErrorStringA
	#define RasHangUp  RasHangUpA
	#define RasGetProjectionInfo  RasGetProjectionInfoA
	#define RasCreatePhonebookEntry RasCreatePhonebookEntryA
	#define RasEditPhonebookEntry  RasEditPhonebookEntryA
	#define RasSetEntryDialParams  RasSetEntryDialParamsA
	#define RasGetEntryDialParams  RasGetEntryDialParamsA
	#define RasEnumDevices  RasEnumDevicesA
	#define RasGetCountryInfo  RasGetCountryInfoA
	#define RasGetEntryProperties  RasGetEntryPropertiesA
	#define RasSetEntryProperties  RasSetEntryPropertiesA
	#define RasRenameEntry  RasRenameEntryA
	#define RasDeleteEntry  RasDeleteEntryA
	#define RasValidateEntryName  RasValidateEntryNameA
	#define RasGetSubEntryHandle  RasGetSubEntryHandleA
	#define RasConnectionNotification  RasConnectionNotificationA
	#define RasGetSubEntryProperties  RasGetSubEntryPropertiesA
	#define RasSetSubEntryProperties  RasSetSubEntryPropertiesA
	#define RasGetCredentials  RasGetCredentialsA
	#define RasSetCredentials  RasSetCredentialsA
	#define RasGetAutodialAddress  RasGetAutodialAddressA
	#define RasSetAutodialAddress  RasSetAutodialAddressA
	#define RasEnumAutodialAddresses  RasEnumAutodialAddressesA
	#define RasGetAutodialEnable  RasGetAutodialEnableA
	#define RasSetAutodialEnable  RasSetAutodialEnableA
	#define RasGetAutodialParam  RasGetAutodialParamA
	#define RasSetAutodialParam  RasSetAutodialParamA
	#define RasGetEapUserData  RasGetEapUserDataA
	#define RasSetEapUserData  RasSetEapUserDataA
	#define RasGetCustomAuthData  RasGetCustomAuthDataA
	#define RasSetCustomAuthData  RasSetCustomAuthDataA
	#define RasGetEapUserIdentity  RasGetEapUserIdentityA
	#define RasFreeEapUserIdentity  RasFreeEapUserIdentityA
	#define RasDeleteSubEntry  RasDeleteSubEntryA
#endif

#endif
