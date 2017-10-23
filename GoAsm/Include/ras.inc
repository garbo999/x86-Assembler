;=============================================================;
;            ras.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RAS_INC
#Define RAS_INC

#Define RAS_MaxDeviceType     				16
#Define RAS_MaxPhoneNumber    				128
#Define RAS_MaxIpAddress      				15
#Define RAS_MaxIpxAddress     				21

#IF (WINVER >= 0400H)
	#Define RAS_MaxEntryName      			256
	#Define RAS_MaxDeviceName     			128
	#Define RAS_MaxCallbackNumber 			RAS_MaxPhoneNumber
#ELSE
	#Define RAS_MaxEntryName      			20
	#Define RAS_MaxDeviceName     			32
	#Define RAS_MaxCallbackNumber 			48
#ENDIF

#Define RAS_MaxAreaCode       				10
#Define RAS_MaxPadType        				32
#Define RAS_MaxX25Address     				200
#Define RAS_MaxFacilities     				200
#Define RAS_MaxUserData       				200

#Define RASCS_PAUSED 						01000H
#Define RASCS_DONE   						02000H

;RASCONNSTATE enumeration
RASCS_OpenPort								Equ 0
RASCS_PortOpened							Equ 1
RASCS_ConnectDevice							Equ 2
RASCS_DeviceConnected						Equ 3
RASCS_AllDevicesConnected					Equ 4
RASCS_Authenticate							Equ 5
RASCS_AuthNotify							Equ 6
RASCS_AuthRetry								Equ 7
RASCS_AuthCallback							Equ 8
RASCS_AuthChangePassword					Equ 9
RASCS_AuthProject							Equ 10
RASCS_AuthLinkSpeed							Equ 11
RASCS_AuthAck								Equ 12
RASCS_ReAuthenticate						Equ 13
RASCS_Authenticated							Equ 14
RASCS_PrepareForCallback					Equ 15
RASCS_WaitForModemReset						Equ 16
RASCS_WaitForCallback						Equ 17
RASCS_Projected								Equ 18
RASCS_StartAuthentication					Equ 19
RASCS_CallbackComplete						Equ 20
RASCS_LogonNetwork							Equ 21
RASCS_SubEntryConnected						Equ 22
RASCS_SubEntryDisconnected					Equ 23

RASCS_Interactive							Equ RASCS_PAUSED
RASCS_RetryAuthentication					Equ (RASCS_PAUSED + 1)
RASCS_CallbackSetByCaller					Equ (RASCS_PAUSED + 2)
RASCS_PasswordExpired						Equ (RASCS_PAUSED + 3)
RASCS_InvokeEapUI							Equ (RASCS_PAUSED + 4)

RASCS_Connected								RASCS_DONE
RASCS_Disconnected							Equ (RASCS_DONE + 1)

#Define RDEOPT_UsePrefixSuffix          	000000001H
#Define RDEOPT_PausedStates             	000000002H
#Define RDEOPT_IgnoreModemSpeaker       	000000004H
#Define RDEOPT_SetModemSpeaker          	000000008H
#Define RDEOPT_IgnoreSoftwareCompression	000000010H
#Define RDEOPT_SetSoftwareCompression   	000000020H
#Define RDEOPT_DisableConnectedUI       	000000040H
#Define RDEOPT_DisableReconnectUI       	000000080H
#Define RDEOPT_DisableReconnect         	000000100H
#Define RDEOPT_NoUser                   	000000200H
#Define RDEOPT_PauseOnScript            	000000400H
#Define RDEOPT_Router                   	000000800H

;RASPROJECTION enumeration
RASP_Amb									Equ 010000H
RASP_PppNbf									Equ 0803FH
RASP_PppIpx									Equ 0802BH
RASP_PppIp									Equ 08021H
RASP_PppLcp									Equ 0C021H
RASP_Slip									Equ 020000H

#Define RASDIALEVENT    					"RasDialEvent"
#Define WM_RASDIALEVENT						0CCCDH

#Define RASEO_UseCountryAndAreaCodes    	000000001H
#Define RASEO_SpecificIpAddr            	000000002H
#Define RASEO_SpecificNameServers       	000000004H
#Define RASEO_IpHeaderCompression       	000000008H
#Define RASEO_RemoteDefaultGateway      	000000010H
#Define RASEO_DisableLcpExtensions      	000000020H
#Define RASEO_TerminalBeforeDial        	000000040H
#Define RASEO_TerminalAfterDial         	000000080H
#Define RASEO_ModemLights               	000000100H
#Define RASEO_SwCompression             	000000200H
#Define RASEO_RequireEncryptedPw        	000000400H
#Define RASEO_RequireMsEncryptedPw      	000000800H
#Define RASEO_RequireDataEncryption     	000001000H
#Define RASEO_NetworkLogon              	000002000H
#Define RASEO_UseLogonCredentials       	000004000H
#Define RASEO_PromoteAlternates         	000008000H
#Define RASEO_SecureLocalFiles          	000010000H

#Define RASNP_NetBEUI                   	000000001H
#Define RASNP_Ipx                       	000000002H
#Define RASNP_Ip                        	000000004H

#Define RASFP_Ppp                       	000000001H
#Define RASFP_Slip                      	000000002H
#Define RASFP_Ras                       	000000004H

#IF STRINGS UNICODE
	#Define RASDT_Modem                     L"modem"
	#Define RASDT_Isdn                      L"isdn"
	#Define RASDT_X25                       L"x25"
	#Define RASDT_Vpn                       L"vpn"
	#Define RASDT_Pad                       L"pad"
#ELSE
	#Define RASDT_Modem                     "modem"
	#Define RASDT_Isdn                      "isdn"
	#Define RASDT_X25                       "x25"
	#Define RASDT_Vpn                       "vpn"
	#Define RASDT_Pad                       "pad"
#ENDIF

#Define RASCN_Connection        			000000001H
#Define RASCN_Disconnection     			000000002H
#Define RASCN_BandwidthAdded    			000000004H
#Define RASCN_BandwidthRemoved  			000000008H

#Define RASEDM_DialAll                  	1
#Define RASEDM_DialAsNeeded             	2

#Define RASIDS_Disabled                 	0FFFFFFFFH
#Define RASIDS_UseGlobalValue           	0

#Define RASADFLG_PositionDlg            	000000001H

#Define RASCM_UserName       				000000001H
#Define RASCM_Password       				000000002H
#Define RASCM_Domain         				000000004H

#Define RASADP_DisableConnectionQuery       0
#Define RASADP_LoginSessionDisable          1
#Define RASADP_SavedAddressesLimit          2
#Define RASADP_FailedConnectionTimeout      3
#Define RASADP_ConnectionQueryTimeout       4


RASCONNW Struct
	dwSize DD
    hrasconn DD
	szEntryName DW (RAS_MaxEntryName + 1) Dup ?
#IF (WINVER >= 0400H)
	szDeviceType DW (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DW (RAS_MaxDeviceName + 1) Dup ?
#ENDIF
#IF (WINVER >= 0401H)
	szPhonebook DW MAX_PATH Dup ?
	dwSubEntry DD
#ENDIF
EndS

RASCONNA Struct
	dwSize DD
    hrasconn DD
	szEntryName DB (RAS_MaxEntryName + 1) Dup ?

#IF (WINVER >= 0400H)
	szDeviceType DB (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DB (RAS_MaxDeviceName + 1) Dup ?
#ENDIF
#IF (WINVER >= 0401H)
    CHAR     szPhonebook [ MAX_PATH ];
	dwSubEntry DD
#ENDIF
EndS

RASCONNSTATUSW Struct
	dwSize DD
	rasconnstate DD
	dwError DD
	szDeviceType DW (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DW (RAS_MaxDeviceName + 1) Dup ?
#IF (WINVER >= 0401H)
	szPhoneNumber DW (RAS_MaxPhoneNumber + 1) Dup ?
#ENDIF
EndS

#define RASCONNSTATUSA struct tagRASCONNSTATUSA
RASCONNSTATUSA Struct
	dwSize DD
	rasconnstate DD
	dwError DD
	szDeviceType DB (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DB (RAS_MaxDeviceName + 1) Dup ?
#IF (WINVER >= 0401H)
	szPhoneNumber DB (RAS_MaxPhoneNumber + 1) Dup ?
#ENDIF
EndS

RASDIALPARAMSW Struct
	dwSize DD
	szEntryName DW (RAS_MaxEntryName + 1) Dup ?
	szPhoneNumber DW (RAS_MaxPhoneNumber + 1) Dup ?
	szCallbackNumber DW (RAS_MaxCallbackNumber + 1) Dup ?
	szUserName DW (UNLEN + 1) Dup ?
	szPassword DW (PWLEN + 1) Dup ?
	szDomain DW (DNLEN + 1) Dup ?
#IF (WINVER >= 0401H)
	dwSubEntry DD
	dwCallbackId DD
#ENDIF
EndS

RASDIALPARAMSA Struct
	dwSize DD
	szEntryName DB (RAS_MaxEntryName + 1) Dup ?
	szPhoneNumber DB (RAS_MaxPhoneNumber + 1) Dup ?
	szCallbackNumber DB (RAS_MaxCallbackNumber + 1) Dup ?
	szUserName DB (UNLEN + 1) Dup ?
	szPassword DB (PWLEN + 1) Dup ?
	szDomain DB (DNLEN + 1) Dup ?
#IF (WINVER >= 0401H)
	dwSubEntry DD
	dwCallbackId DD
#ENDIF
EndS

RASDIALEXTENSIONS Struct
	dwSize DD
	dwfOptions DD
	hwndParent DD
	reserved DD
#IF (WINVER >= 0500H)
	reserved1 DD
#ENDIF
EndS

RASENTRYNAMEW Struct
	dwSize DD
	szEntryName DW (RAS_MaxEntryName + 1) Equ
EndS

RASENTRYNAMEA Struct
	dwSize DD
	szEntryName DB (RAS_MaxEntryName + 1) Equ
EndS

RASAMBW Struct
	dwSize DD
	dwError DD
	szNetBiosError DW (NETBIOS_NAME_LEN + 1) Dup ?
	bLana DB
EndS

RASAMBA Struct
	dwSize DD
	dwError DD
	szNetBiosError DB (NETBIOS_NAME_LEN + 1) Dup ?
	bLana DB
EndS

RASPPPNBFW Struct
	dwSize DD
	dwError DD
	dwNetBiosError DD
	szNetBiosError DW (NETBIOS_NAME_LEN + 1)
	szWorkstationName DW (NETBIOS_NAME_LEN + 1) Dup ?
	bLana DB
EndS

RASPPPNBFA Struct
	dwSize DD
	dwError DD
	dwNetBiosError DD
	szNetBiosError DB (NETBIOS_NAME_LEN + 1)
	szWorkstationName DB (NETBIOS_NAME_LEN + 1) Dup ?
	bLana DB
EndS

RASPPPIPXW Struct
	dwSize DD
	dwError DD
	szIpxAddress DW (RAS_MaxIpxAddress + 1) Dup ?
EndS

RASPPPIPXA Struct
	dwSize DD
	dwError DD
	szIpxAddress DB (RAS_MaxIpxAddress + 1) Dup ?
EndS

RASPPPIPW Struct
	dwSize DD
	dwError DD
	szIpAddress DW (RAS_MaxIpAddress + 1) Dup ?
	szServerIpAddress DW (RAS_MaxIpAddress + 1) Dup ?
EndS

RASPPPIPA Struct
	dwSize DD
	dwError DD
	szIpAddress DB (RAS_MaxIpAddress + 1) Dup ?
	szServerIpAddress DB (RAS_MaxIpAddress + 1) Dup ?
EndS

RASPPPLCP Struct
	dwSize DD
	fBundled DD
EndS

RASSLIPW Struct
	dwSize DD
	dwError DD
	szIpAddress DW (RAS_MaxIpAddress + 1) Dup ?
EndS

RASSLIPA Struct
	dwSize DD
	dwError DD
	szIpAddress DB (RAS_MaxIpAddress + 1) Dup ?
EndS

RASDEVINFOW Struct
	dwSize DD
	szDeviceType DW (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DW (RAS_MaxDeviceName + 1) Dup ?
EndS

RASDEVINFOA Struct
	dwSize DD
	szDeviceType DB (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DB (RAS_MaxDeviceName + 1) Dup ?
EndS

RASCTRYINFO Struct
	dwSize DD
	dwCountryID DD
	dwNextCountryID DD
	dwCountryCode DD
	dwCountryNameOffset DD
EndS

RASIPADDR Struct
	a DB
	b DB
	c DB
	d DB
EndS

RASENTRYA Struct
	dwSize DD
	dwfOptions DD
	dwCountryID DD
	dwCountryCode DD
	szAreaCode DB (RAS_MaxAreaCode + 1) Dup ?
	szLocalPhoneNumber DB (RAS_MaxPhoneNumber + 1) Dup ?
	dwAlternateOffset DD
	ipaddr RASIPADDR <>
	ipaddrDns RASIPADDR <>
	ipaddrDnsAlt RASIPADDR <>
	ipaddrWins RASIPADDR <>
	ipaddrWinsAlt RASIPADDR <>
	dwFrameSize DD
	dwfNetProtocols DD
	dwFramingProtocol DD
	szScript DB (MAX_PATH) Dup ?
	szAutodialDll DB (MAX_PATH) Dup ?
	szAutodialFunc DB (MAX_PATH) Dup ?
	szDeviceType DB (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DB (RAS_MaxDeviceName + 1) Dup ?
	szX25PadType DB (RAS_MaxPadType + 1) Dup ?
	szX25Address DB (RAS_MaxX25Address + 1) Dup ?
	szX25Facilities DB (RAS_MaxFacilities + 1) Dup ?
	szX25UserData DB (RAS_MaxUserData + 1) Dup ?
	dwChannels DD
	dwReserved1 DD
	dwReserved2 DD
#IF (WINVER >= 0401H)
	dwSubEntries DD
	dwDialMode DD
	dwDialExtraPercent DD
	dwDialExtraSampleSeconds DD
	dwHangUpExtraPercent DD
	dwHangUpExtraSampleSeconds DD
	dwIdleDisconnectSeconds DD
#ENDIF
#IF (WINVER >= 0500H)
	szPortName DB (RAS_MaxDeviceName + 1) Dup ?
#ENDIF
EndS

RASENTRYW Struct
	dwSize DD
	dwfOptions DD
	dwCountryID DD
	dwCountryCode DD
	szAreaCode DW (RAS_MaxAreaCode + 1) Dup ?
	szLocalPhoneNumber DW (RAS_MaxPhoneNumber + 1) Dup ?
	dwAlternateOffset DD
	ipaddr RASIPADDR <>
	ipaddrDns RASIPADDR <>
	ipaddrDnsAlt RASIPADDR <>
	ipaddrWins RASIPADDR <>
	ipaddrWinsAlt RASIPADDR <>
	dwFrameSize DD
	dwfNetProtocols DD
	dwFramingProtocol DD
	szScript DW (MAX_PATH) Dup ?
	szAutodialDll DW (MAX_PATH) Dup ?
	szAutodialFunc DW (MAX_PATH) Dup ?
	szDeviceType DW (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DW (RAS_MaxDeviceName + 1) Dup ?
	szX25PadType DW (RAS_MaxPadType + 1) Dup ?
	szX25Address DW (RAS_MaxX25Address + 1) Dup ?
	szX25Facilities DW (RAS_MaxFacilities + 1) Dup ?
	szX25UserData DW (RAS_MaxUserData + 1) Dup ?
	dwChannels DD
	dwReserved1 DD
	dwReserved2 DD
#IF (WINVER >= 0401H)
	dwSubEntries DD
	dwDialMode DD
	dwDialExtraPercent DD
	dwDialExtraSampleSeconds DD
	dwHangUpExtraPercent DD
	dwHangUpExtraSampleSeconds DD
	dwIdleDisconnectSeconds DD
#ENDIF
#IF (WINVER >= 0500H)
	szPortName DW (RAS_MaxDeviceName + 1) Dup ?
#ENDIF
EndS

RASADPARAMS Struct
	dwSize DD
	hwndOwner DD
	dwFlags DD
	xDlg DD
	yDlg DD
EndS

RASSUBENTRYA Struct
	dwSize DD
	dwfFlags DD
	szDeviceType DB (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DB (RAS_MaxDeviceName + 1) Dup ?
	szLocalPhoneNumber DB (RAS_MaxPhoneNumber + 1) Dup ?
	dwAlternateOffset DD
#IF (WINVER >= 0500H)
	szPortName DB (RAS_MaxDeviceName + 1) Dup ?
#ENDIF
EndS

RASSUBENTRYW Struct
	dwSize DD
	dwfFlags DD
	szDeviceType DW (RAS_MaxDeviceType + 1) Dup ?
	szDeviceName DW (RAS_MaxDeviceName + 1) Dup ?
	szLocalPhoneNumber DW (RAS_MaxPhoneNumber + 1) Dup ?
	dwAlternateOffset DD
#IF (WINVER >= 0500H)
	szPortName DW (RAS_MaxDeviceName + 1) Dup ?
#ENDIF
EndS

RASCREDENTIALSA Struct
	dwSize DD
	dwMask DD
	szUserName DB (UNLEN + 1) Dup ?
	szPassword DB (PWLEN + 1) Dup ?
	szDomain DB (DNLEN + 1) Dup ?
EndS

RASCREDENTIALSW Struct
	dwSize DD
	dwMask DD
	szUserName DW (UNLEN + 1) Dup ?
	szPassword DW (PWLEN + 1) Dup ?
	szDomain DW (DNLEN + 1) Dup ?
EndS

RASAUTODIALENTRYA Struct
	dwSize DD
	dwFlags DD
	dwDialingLocation DD
	szEntry DB (RAS_MaxEntryName + 1) Dup ?
EndS

RASAUTODIALENTRYW Struct
	dwSize DD
	dwFlags DD
	dwDialingLocation DD
	szEntry DW (RAS_MaxEntryName + 1) Dup ?
EndS


#IF STRINGS UNICODE
	#Define RASCONN RASCONNW
	#Define RASCONNSTATUS RASCONNSTATUSW
	#Define RASDIALPARAMS RASDIALPARAMSW
	#Define RASENTRYNAME RASENTRYNAMEW
	#Define RASAMB RASAMBW
	#Define RASPPPNBF RASPPPNBFW
	#Define RASPPPIPX RASPPPIPXW
	#Define RASPPPIP RASPPPIPW
	#Define RASSLIP RASSLIPW
	#Define RASDEVINFO RASDEVINFOW
	#Define RASENTRY RASENTRYW
	#Define RASSUBENTRY RASSUBENTRYW
	#Define RASCREDENTIALS RASCREDENTIALSW
	#Define RASAUTODIALENTRY RASAUTODIALENTRYW
	#Define RasDial RasDialW
	#Define RasEnumConnections RasEnumConnectionsW
	#Define RasEnumEntries RasEnumEntriesW
	#Define RasGetConnectStatus RasGetConnectStatusW
	#Define RasGetErrorString RasGetErrorStringW
	#Define RasHangUp RasHangUpW
	#Define RasGetProjectionInfo RasGetProjectionInfoW
	#Define RasCreatePhonebookEntry RasCreatePhonebookEntryW
	#Define RasEditPhonebookEntry RasEditPhonebookEntryW
	#Define RasSetEntryDialParams RasSetEntryDialParamsW
	#Define RasGetEntryDialParams RasGetEntryDialParamsW
	#Define RasEnumDevices RasEnumDevicesW
	#Define RasGetCountryInfo RasGetCountryInfoW
	#Define RasGetEntryProperties RasGetEntryPropertiesW
	#Define RasSetEntryProperties RasSetEntryPropertiesW
	#Define RasRenameEntry RasRenameEntryW
	#Define RasDeleteEntry RasDeleteEntryW
	#Define RasValidateEntryName RasValidateEntryNameW
	#Define RasGetSubEntryHandle RasGetSubEntryHandleW
	#Define RasConnectionNotification RasConnectionNotificationW
	#Define RasGetSubEntryProperties RasGetSubEntryPropertiesW
	#Define RasSetSubEntryProperties RasSetSubEntryPropertiesW
	#Define RasGetCredentials RasGetCredentialsW
	#Define RasSetCredentials RasSetCredentialsW
	#Define RasGetAutodialAddress RasGetAutodialAddressW
	#Define RasSetAutodialAddress RasSetAutodialAddressW
	#Define RasEnumAutodialAddresses RasEnumAutodialAddressesW
	#Define RasGetAutodialEnable RasGetAutodialEnableW
	#Define RasSetAutodialEnable RasSetAutodialEnableW
	#Define RasGetAutodialParam RasGetAutodialParamW
	#Define RasSetAutodialParam RasSetAutodialParamW
#ELSE
	#Define RASCONN RASCONNA
	#Define RASCONNSTATUS RASCONNSTATUSA
	#Define RASDIALPARAMS RASDIALPARAMSA
	#Define RASENTRYNAME RASENTRYNAMEA
	#Define RASAMB RASAMBA
	#Define RASPPPNBF RASPPPNBFA
	#Define RASPPPIPX RASPPPIPXA
	#Define RASPPPIP RASPPPIPA
	#Define RASSLIP RASSLIPA
	#Define RASDEVINFO RASDEVINFOA
	#Define RASENTRY RASENTRYA
	#Define RASSUBENTRY RASSUBENTRYA
	#Define RASCREDENTIALS RASCREDENTIALSA
	#Define RASAUTODIALENTRY RASAUTODIALENTRYA
	#Define RasDial RasDialA
	#Define RasEnumConnections RasEnumConnectionsA
	#Define RasEnumEntries RasEnumEntriesA
	#Define RasGetConnectStatus RasGetConnectStatusA
	#Define RasGetErrorString RasGetErrorStringA
	#Define RasHangUp RasHangUpA
	#Define RasGetProjectionInfo RasGetProjectionInfoA
	#Define RasCreatePhonebookEntry RasCreatePhonebookEntryA
	#Define RasEditPhonebookEntry RasEditPhonebookEntryA
	#Define RasSetEntryDialParams RasSetEntryDialParamsA
	#Define RasGetEntryDialParams RasGetEntryDialParamsA
	#Define RasEnumDevices RasEnumDevicesA
	#Define RasGetCountryInfo RasGetCountryInfoA
	#Define RasGetEntryProperties RasGetEntryPropertiesA
	#Define RasSetEntryProperties RasSetEntryPropertiesA
	#Define RasRenameEntry RasRenameEntryA
	#Define RasDeleteEntry RasDeleteEntryA
	#Define RasValidateEntryName RasValidateEntryNameA
	#Define RasGetSubEntryHandle RasGetSubEntryHandleA
	#Define RasConnectionNotification RasConnectionNotificationA
	#Define RasGetSubEntryProperties RasGetSubEntryPropertiesA
	#Define RasSetSubEntryProperties RasSetSubEntryPropertiesA
	#Define RasGetCredentials RasGetCredentialsA
	#Define RasSetCredentials RasSetCredentialsA
	#Define RasGetAutodialAddress RasGetAutodialAddressA
	#Define RasSetAutodialAddress RasSetAutodialAddressA
	#Define RasEnumAutodialAddresses RasEnumAutodialAddressesA
	#Define RasGetAutodialEnable RasGetAutodialEnableA
	#Define RasSetAutodialEnable RasSetAutodialEnableA
	#Define RasGetAutodialParam RasGetAutodialParamA
	#Define RasSetAutodialParam RasSetAutodialParamA
#ENDIF

#ENDIF ;RAS_INC
