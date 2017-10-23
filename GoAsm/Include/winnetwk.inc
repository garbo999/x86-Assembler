;=============================================================;
;         winnetwk.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINNETWK_INC
#Define WINNETWK_INC

#Define WNNC_NET_MSNET      				000010000H
#Define WNNC_NET_LANMAN     				000020000H
#Define WNNC_NET_NETWARE    				000030000H
#Define WNNC_NET_VINES      				000040000H
#Define WNNC_NET_10NET      				000050000H
#Define WNNC_NET_LOCUS      				000060000H
#Define WNNC_NET_SUN_PC_NFS 				000070000H
#Define WNNC_NET_LANSTEP    				000080000H
#Define WNNC_NET_9TILES     				000090000H
#Define WNNC_NET_LANTASTIC  				0000A0000H
#Define WNNC_NET_AS400      				0000B0000H
#Define WNNC_NET_FTP_NFS    				0000C0000H
#Define WNNC_NET_PATHWORKS  				0000D0000H
#Define WNNC_NET_LIFENET    				0000E0000H
#Define WNNC_NET_POWERLAN   				0000F0000H
#Define WNNC_NET_BWNFS      				000100000H
#Define WNNC_NET_COGENT     				000110000H
#Define WNNC_NET_FARALLON   				000120000H
#Define WNNC_NET_APPLETALK  				000130000H
#Define WNNC_NET_INTERGRAPH 				000140000H
#Define WNNC_NET_SYMFONET   				000150000H
#Define WNNC_NET_CLEARCASE  				000160000H
#Define WNNC_NET_FRONTIER   				000170000H
#Define WNNC_NET_BMC        				000180000H
#Define WNNC_NET_DCE        				000190000H
#Define WNNC_NET_DECORB     				000200000H
#Define WNNC_NET_PROTSTOR   				000210000H
#Define WNNC_NET_FJ_REDIR   				000220000H
#Define WNNC_NET_DISTINCT   				000230000H
#Define WNNC_NET_TWINS      				000240000H
#Define WNNC_NET_RDR2SAMPLE 				000250000H

#Define RESOURCE_CONNECTED      			000000001H
#Define RESOURCE_GLOBALNET      			000000002H
#Define RESOURCE_REMEMBERED     			000000003H
#Define RESOURCE_RECENT         			000000004H
#Define RESOURCE_CONTEXT        			000000005H

#Define RESOURCETYPE_ANY        			000000000H
#Define RESOURCETYPE_DISK       			000000001H
#Define RESOURCETYPE_PRINT      			000000002H
#Define RESOURCETYPE_RESERVED   			000000008H
#Define RESOURCETYPE_UNKNOWN    			0FFFFFFFFH

#Define RESOURCEUSAGE_CONNECTABLE   		000000001H
#Define RESOURCEUSAGE_CONTAINER     		000000002H
#Define RESOURCEUSAGE_NOLOCALDEVICE 		000000004H
#Define RESOURCEUSAGE_SIBLING       		000000008H
#Define RESOURCEUSAGE_ATTACHED      		000000010H
#Define RESOURCEUSAGE_ALL					(RESOURCEUSAGE_CONNECTABLE | RESOURCEUSAGE_CONTAINER | RESOURCEUSAGE_ATTACHED)
#Define RESOURCEUSAGE_RESERVED      		080000000H

#Define RESOURCEDISPLAYTYPE_GENERIC        	000000000H
#Define RESOURCEDISPLAYTYPE_DOMAIN         	000000001H
#Define RESOURCEDISPLAYTYPE_SERVER         	000000002H
#Define RESOURCEDISPLAYTYPE_SHARE          	000000003H
#Define RESOURCEDISPLAYTYPE_FILE           	000000004H
#Define RESOURCEDISPLAYTYPE_GROUP          	000000005H
#Define RESOURCEDISPLAYTYPE_NETWORK        	000000006H
#Define RESOURCEDISPLAYTYPE_ROOT           	000000007H
#Define RESOURCEDISPLAYTYPE_SHAREADMIN     	000000008H
#Define RESOURCEDISPLAYTYPE_DIRECTORY      	000000009H
#Define RESOURCEDISPLAYTYPE_TREE           	00000000AH
#Define RESOURCEDISPLAYTYPE_NDSCONTAINER	00000000BH

#Define NETPROPERTY_PERSISTENT				1

#Define CONNECT_UPDATE_PROFILE      		000000001H
#Define CONNECT_UPDATE_RECENT       		000000002H
#Define CONNECT_TEMPORARY           		000000004H
#Define CONNECT_INTERACTIVE         		000000008H
#Define CONNECT_PROMPT              		000000010H
#Define CONNECT_NEED_DRIVE          		000000020H
#Define CONNECT_REFCOUNT            		000000040H
#Define CONNECT_REDIRECT            		000000080H
#Define CONNECT_LOCALDRIVE          		000000100H
#Define CONNECT_CURRENT_MEDIA       		000000200H
#Define CONNECT_DEFERRED            		000000400H
#Define CONNECT_RESERVED            		0FF000000H

#Define CONNDLG_RO_PATH     				000000001H
#Define CONNDLG_CONN_POINT  				000000002H
#Define CONNDLG_USE_MRU     				000000004H
#Define CONNDLG_HIDE_BOX    				000000008H

#Define CONNDLG_PERSIST     				000000010H
#Define CONNDLG_NOT_PERSIST					000000020H

#Define DISC_UPDATE_PROFILE         		000000001H
#Define DISC_NO_FORCE               		000000040H

#Define UNIVERSAL_NAME_INFO_LEVEL   		000000001H
#Define REMOTE_NAME_INFO_LEVEL      		000000002H

#Define WNFMT_MULTILINE         			001H
#Define WNFMT_ABBREVIATED       			002H
#Define WNFMT_INENUM            			010H
#Define WNFMT_CONNECTION        			020H

#Define NETINFO_DLL16       				000000001H
#Define NETINFO_DISKRED     				000000004H
#Define NETINFO_PRINTERRED  				000000008H

#Define WN_SUCCESS                      	NO_ERROR
#Define WN_NO_ERROR                     	NO_ERROR
#Define WN_NOT_SUPPORTED                	ERROR_NOT_SUPPORTED
#Define WN_CANCEL                       	ERROR_CANCELLED
#Define WN_RETRY                        	ERROR_RETRY
#Define WN_NET_ERROR                    	ERROR_UNEXP_NET_ERR
#Define WN_MORE_DATA                    	ERROR_MORE_DATA
#Define WN_BAD_POINTER                  	ERROR_INVALID_ADDRESS
#Define WN_BAD_VALUE                    	ERROR_INVALID_PARAMETER
#Define WN_BAD_USER                     	ERROR_BAD_USERNAME
#Define WN_BAD_PASSWORD                 	ERROR_INVALID_PASSWORD
#Define WN_ACCESS_DENIED                	ERROR_ACCESS_DENIED
#Define WN_FUNCTION_BUSY                	ERROR_BUSY
#Define WN_WINDOWS_ERROR                	ERROR_UNEXP_NET_ERR
#Define WN_OUT_OF_MEMORY                	ERROR_NOT_ENOUGH_MEMORY
#Define WN_NO_NETWORK                   	ERROR_NO_NETWORK
#Define WN_EXTENDED_ERROR               	ERROR_EXTENDED_ERROR
#Define WN_BAD_LEVEL                    	ERROR_INVALID_LEVEL
#Define WN_BAD_HANDLE                   	ERROR_INVALID_HANDLE
#Define WN_NOT_INITIALIZING             	ERROR_ALREADY_INITIALIZED
#Define WN_NO_MORE_DEVICES              	ERROR_NO_MORE_DEVICES

#Define WN_NOT_CONNECTED                	ERROR_NOT_CONNECTED
#Define WN_OPEN_FILES                   	ERROR_OPEN_FILES
#Define WN_DEVICE_IN_USE                	ERROR_DEVICE_IN_USE
#Define WN_BAD_NETNAME                  	ERROR_BAD_NET_NAME
#Define WN_BAD_LOCALNAME                	ERROR_BAD_DEVICE
#Define WN_ALREADY_CONNECTED            	ERROR_ALREADY_ASSIGNED
#Define WN_DEVICE_ERROR                 	ERROR_GEN_FAILURE
#Define WN_CONNECTION_CLOSED            	ERROR_CONNECTION_UNAVAIL
#Define WN_NO_NET_OR_BAD_PATH           	ERROR_NO_NET_OR_BAD_PATH
#Define WN_BAD_PROVIDER                 	ERROR_BAD_PROVIDER
#Define WN_CANNOT_OPEN_PROFILE          	ERROR_CANNOT_OPEN_PROFILE
#Define WN_BAD_PROFILE                  	ERROR_BAD_PROFILE
#Define WN_BAD_DEV_TYPE                 	ERROR_BAD_DEV_TYPE
#Define WN_DEVICE_ALREADY_REMEMBERED    	ERROR_DEVICE_ALREADY_REMEMBERED
#Define WN_CONNECTED_OTHER_PASSWORD     	ERROR_CONNECTED_OTHER_PASSWORD

#Define WN_NO_MORE_ENTRIES              	ERROR_NO_MORE_ITEMS
#Define WN_NOT_CONTAINER                	ERROR_NOT_CONTAINER

#Define WN_NOT_AUTHENTICATED            	ERROR_NOT_AUTHENTICATED
#Define WN_NOT_LOGGED_ON                	ERROR_NOT_LOGGED_ON
#Define WN_NOT_VALIDATED                	ERROR_NO_LOGON_SERVERS

#Define WNCON_FORNETCARD        			000000001H
#Define WNCON_NOTROUTED         			000000002H
#Define WNCON_SLOWLINK          			000000004H
#Define WNCON_DYNAMIC           			000000008H


NETRESOURCEA Struct
	dwScope DD
	dwType DD
	dwDisplayType DD
	dwUsage DD
	lpLocalName DD
	lpRemoteName DD
	lpComment DD
	lpProvider DD
EndS

NETRESOURCEW Struct
	dwScope DD
	dwType DD
	dwDisplayType DD
	dwUsage DD
	lpLocalName DD
	lpRemoteName DD
	lpComment DD
	lpProvider DD
EndS

CONNECTDLGSTRUCTA Struct
	cbStructure DD
	hwndOwner DD
	lpConnRes DD
	dwFlags DD
	dwDevNum DD
EndS

CONNECTDLGSTRUCTW Struct
	cbStructure DD
	hwndOwner DD
	lpConnRes DD
	dwFlags DD
	dwDevNum DD
EndS

DISCDLGSTRUCTA Struct
	cbStructure DD
	hwndOwner DD
	lpLocalName DD
	lpRemoteName DD
	dwFlags DD
EndS

DISCDLGSTRUCTW Struct
	cbStructure DD
	hwndOwner DD
	lpLocalName DD
	lpRemoteName DD
	dwFlags DD
EndS

UNIVERSAL_NAME_INFOA Struct
	lpUniversalName DD
EndS

UNIVERSAL_NAME_INFOW Struct
	lpUniversalName DD
EndS

REMOTE_NAME_INFOA Struct
	lpUniversalName DD
	lpConnectionName DD
	lpRemainingPath DD
EndS

REMOTE_NAME_INFOW Struct
	lpUniversalName DD
	lpConnectionName DD
	lpRemainingPath DD
EndS

NETINFOSTRUCT Struct
	cbStructure DD
	dwProviderVersion DD
	dwStatus DD
	dwCharacteristics DD
	dwHandle DD
	wNetType DW
	dwPrinters DD
	dwDrives DD
EndS

NETCONNECTINFOSTRUCT Struct
	cbStructure DD
	dwFlags DD
	dwSpeed DD ;
	dwDelay DD
	dwOptDataSize DD
EndS


#IF STRINGS UNICODE
	#Define NETRESOURCE NETRESOURCEW
	#Define WNetAddConnection WNetAddConnectionW
	#Define WNetAddConnection2 WNetAddConnection2W
	#Define WNetAddConnection3 WNetAddConnection3W
	#Define WNetCancelConnection WNetCancelConnectionW
	#Define WNetCancelConnection2 WNetCancelConnection2W
	#Define WNetGetConnection WNetGetConnectionW
	#Define WNetUseConnection WNetUseConnectionW
	#Define CONNECTDLGSTRUCT CONNECTDLGSTRUCTW
	#Define WNetConnectionDialog1 WNetConnectionDialog1W
	#Define DISCDLGSTRUCT DISCDLGSTRUCTW
	#Define WNetDisconnectDialog1 WNetDisconnectDialog1W
	#Define WNetOpenEnum WNetOpenEnumW
	#Define WNetEnumResource WNetEnumResourceW
	#Define UNIVERSAL_NAME_INFO UNIVERSAL_NAME_INFOW
	#Define REMOTE_NAME_INFO REMOTE_NAME_INFOW
	#Define WNetGetUniversalName WNetGetUniversalNameW
	#Define WNetGetUser WNetGetUserW
	#Define WNetGetProviderName WNetGetProviderNameW
	#Define WNetGetNetworkInformation WNetGetNetworkInformationW
	#Define PFNGETPROFILEPATH PFNGETPROFILEPATHW
	#Define PFNRECONCILEPROFILE PFNRECONCILEPROFILEW
	#Define PFNPROCESSPOLICIES PFNPROCESSPOLICIESW
	#Define WNetGetLastError WNetGetLastErrorW
	#Define MultinetGetConnectionPerformance MultinetGetConnectionPerformanceW
#ELSE
	#Define NETRESOURCE NETRESOURCEA
	#Define WNetAddConnection WNetAddConnectionA
	#Define WNetAddConnection2 WNetAddConnection2A
	#Define WNetAddConnection3 WNetAddConnection3A
	#Define WNetCancelConnection WNetCancelConnectionA
	#Define WNetCancelConnection2 WNetCancelConnection2A
	#Define WNetGetConnection WNetGetConnectionA
	#Define WNetUseConnection WNetUseConnectionA
	#Define CONNECTDLGSTRUCT CONNECTDLGSTRUCTA
	#Define WNetConnectionDialog1 WNetConnectionDialog1A
	#Define DISCDLGSTRUCT DISCDLGSTRUCTA
	#Define WNetDisconnectDialog1 WNetDisconnectDialog1A
	#Define WNetOpenEnum WNetOpenEnumA
	#Define WNetEnumResource WNetEnumResourceA
	#Define UNIVERSAL_NAME_INFO UNIVERSAL_NAME_INFOA
	#Define REMOTE_NAME_INFO REMOTE_NAME_INFOA
	#Define WNetGetUniversalName WNetGetUniversalNameA
	#Define WNetGetUser WNetGetUserA
	#Define WNetGetProviderName WNetGetProviderNameA
	#Define WNetGetNetworkInformation WNetGetNetworkInformationA
	#Define PFNGETPROFILEPATH PFNGETPROFILEPATHA
	#Define PFNRECONCILEPROFILE PFNRECONCILEPROFILEA
	#Define PFNPROCESSPOLICIES PFNPROCESSPOLICIESA
	#Define WNetGetLastError WNetGetLastErrorA
	#Define MultinetGetConnectionPerformance MultinetGetConnectionPerformanceA
#ENDIF

#ENDIF ;WINNETWK_INC
