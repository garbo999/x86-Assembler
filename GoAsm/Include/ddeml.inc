;=============================================================;
;           ddeml.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF DDEML_INC
#Define DDEML_INC

#Define XST_NULL              			0
#Define XST_INCOMPLETE        			1
#Define XST_CONNECTED         			2
#Define XST_INIT1             			3
#Define XST_INIT2             			4
#Define XST_REQSENT           			5
#Define XST_DATARCVD          			6
#Define XST_POKESENT          			7
#Define XST_POKEACKRCVD       			8
#Define XST_EXECSENT          			9
#Define XST_EXECACKRCVD      			10
#Define XST_ADVSENT          			11
#Define XST_UNADVSENT        			12
#Define XST_ADVACKRCVD       			13
#Define XST_UNADVACKRCVD     			14
#Define XST_ADVDATASENT      			15
#Define XST_ADVDATAACKRCVD   			16

#Define CADV_LATEACK         			0FFFFH

#Define ST_CONNECTED            		00001H
#Define ST_ADVISE               		00002H
#Define ST_ISLOCAL              		00004H
#Define ST_BLOCKED              		00008H
#Define ST_CLIENT               		00010H
#Define ST_TERMINATED           		00020H
#Define ST_INLIST               		00040H
#Define ST_BLOCKNEXT            		00080H
#Define ST_ISSELF               		00100H


#Define DDE_FACK                		08000H
#Define DDE_FBUSY               		04000H
#Define DDE_FDEFERUPD           		04000H
#Define DDE_FACKREQ             		08000H
#Define DDE_FRELEASE            		02000H
#Define DDE_FREQUESTED          		01000H
#Define DDE_FAPPSTATUS          		000FFH
#Define DDE_FNOTPROCESSED       		00000H

#Define DDE_FACKRESERVED				(~(DDE_FACK | DDE_FBUSY | DDE_FAPPSTATUS))
#Define DDE_FADVRESERVED				(~(DDE_FACKREQ | DDE_FDEFERUPD))
#Define DDE_FDATRESERVED				(~(DDE_FACKREQ | DDE_FRELEASE | DDE_FREQUESTED))
#Define DDE_FPOKRESERVED				(~(DDE_FRELEASE))

#Define MSGF_DDEMGR             		08001H

#Define CP_WINANSI      				1004
#Define CP_WINUNICODE   				1200
#IF STRINGS UNICODE
	#Define CP_WINNEUTRAL				CP_WINUNICODE
#ELSE
	#Define CP_WINNEUTRAL   			CP_WINANSI
#ENDIF

#Define XTYPF_NOBLOCK            		00002H
#Define XTYPF_NODATA             		00004H
#Define XTYPF_ACKREQ             		00008H

#Define XCLASS_MASK              		0FC00H
#Define XCLASS_BOOL              		01000H
#Define XCLASS_DATA              		02000H
#Define XCLASS_FLAGS             		04000H
#Define XCLASS_NOTIFICATION      		08000H

#Define XTYP_ERROR              		(00000H | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#Define XTYP_ADVDATA            		(00010H | XCLASS_FLAGS)
#Define XTYP_ADVREQ             		(00020H | XCLASS_DATA | XTYPF_NOBLOCK)
#Define XTYP_ADVSTART           		(00030H | XCLASS_BOOL)
#Define XTYP_ADVSTOP            		(00040H | XCLASS_NOTIFICATION)
#Define XTYP_EXECUTE            		(00050H | XCLASS_FLAGS)
#Define XTYP_CONNECT            		(00060H | XCLASS_BOOL | XTYPF_NOBLOCK)
#Define XTYP_CONNECT_CONFIRM    		(00070H | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#Define XTYP_XACT_COMPLETE      		(00080H | XCLASS_NOTIFICATION)
#Define XTYP_POKE               		(00090H | XCLASS_FLAGS)
#Define XTYP_REGISTER           		(000A0H | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#Define XTYP_REQUEST            		(000B0H | XCLASS_DATA)
#Define XTYP_DISCONNECT         		(000C0H | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#Define XTYP_UNREGISTER         		(000D0H | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#Define XTYP_WILDCONNECT        		(000E0H | XCLASS_DATA | XTYPF_NOBLOCK)

#Define XTYP_MASK                		000F0H
#Define XTYP_SHIFT               		4

#Define TIMEOUT_ASYNC           		0FFFFFFFFH

#Define QID_SYNC                		0FFFFFFFFH

#IF STRINGS UNICODE
	#Define SZDDESYS_TOPIC         		L"System"
	#Define SZDDESYS_ITEM_TOPICS   		L"Topics"
	#Define SZDDESYS_ITEM_SYSITEMS 		L"SysItems"
	#Define SZDDESYS_ITEM_RTNMSG   		L"ReturnMessage"
	#Define SZDDESYS_ITEM_STATUS   		L"Status"
	#Define SZDDESYS_ITEM_FORMATS  		L"Formats"
	#Define SZDDESYS_ITEM_HELP     		L"Help"
	#Define SZDDE_ITEM_ITEMLIST    		L"TopicItemList"
#ELSE
	#Define SZDDESYS_TOPIC         		"System"
	#Define SZDDESYS_ITEM_TOPICS   		"Topics"
	#Define SZDDESYS_ITEM_SYSITEMS 		"SysItems"
	#Define SZDDESYS_ITEM_RTNMSG   		"ReturnMessage"
	#Define SZDDESYS_ITEM_STATUS   		"Status"
	#Define SZDDESYS_ITEM_FORMATS  		"Formats"
	#Define SZDDESYS_ITEM_HELP     		"Help"
	#Define SZDDE_ITEM_ITEMLIST   		"TopicItemList"
#ENDIF

#Define CBR_BLOCK           			0FFFFFFFFH

#Define CBF_FAIL_SELFCONNECTIONS     	000001000H
#Define CBF_FAIL_CONNECTIONS        	000002000H
#Define CBF_FAIL_ADVISES            	000004000H
#Define CBF_FAIL_EXECUTES           	000008000H
#Define CBF_FAIL_POKES              	000010000H
#Define CBF_FAIL_REQUESTS           	000020000H
#Define CBF_FAIL_ALLSVRXACTIONS     	00003F000H

#Define CBF_SKIP_CONNECT_CONFIRMS   	000040000H
#Define CBF_SKIP_REGISTRATIONS      	000080000H
#Define CBF_SKIP_UNREGISTRATIONS    	000100000H
#Define CBF_SKIP_DISCONNECTS        	000200000H
#Define CBF_SKIP_ALLNOTIFICATIONS   	0003C0000H

#Define APPCMD_CLIENTONLY            	000000010H
#Define APPCMD_FILTERINITS          	000000020H
#Define APPCMD_MASK                 	000000FF0H

#Define APPCLASS_STANDARD            	000000000H
#Define APPCLASS_MASK               	00000000FH

#Define EC_ENABLEALL            		0
#Define EC_ENABLEONE            		ST_BLOCKNEXT
#Define EC_DISABLE              		ST_BLOCKED
#Define EC_QUERYWAITING         		2

#Define DNS_REGISTER        			00001H
#Define DNS_UNREGISTER      			00002H
#Define DNS_FILTERON        			00004H
#Define DNS_FILTEROFF       			00008H

#Define HDATA_APPOWNED          		00001H

#Define DMLERR_NO_ERROR                 0

#Define DMLERR_FIRST                	04000H

#Define DMLERR_ADVACKTIMEOUT            04000H
#Define DMLERR_BUSY                 	04001H
#Define DMLERR_DATAACKTIMEOUT       	04002H
#Define DMLERR_DLL_NOT_INITIALIZED  	04003H
#Define DMLERR_DLL_USAGE            	04004H
#Define DMLERR_EXECACKTIMEOUT       	04005H
#Define DMLERR_INVALIDPARAMETER     	04006H
#Define DMLERR_LOW_MEMORY           	04007H
#Define DMLERR_MEMORY_ERROR         	04008H
#Define DMLERR_NOTPROCESSED         	04009H
#Define DMLERR_NO_CONV_ESTABLISHED  	0400AH
#Define DMLERR_POKEACKTIMEOUT       	0400BH
#Define DMLERR_POSTMSG_FAILED       	0400CH
#Define DMLERR_REENTRANCY           	0400DH
#Define DMLERR_SERVER_DIED          	0400EH
#Define DMLERR_SYS_ERROR            	0400FH
#Define DMLERR_UNADVACKTIMEOUT      	04010H
#Define DMLERR_UNFOUND_QUEUE_ID     	04011H

#Define DMLERR_LAST                 	04011H

#Define MH_CREATE   					1
#Define MH_KEEP     					2
#Define MH_DELETE   					3
#Define MH_CLEANUP  					4

#Define MAX_MONITORS            		4
#Define APPCLASS_MONITOR        		000000001H
#Define XTYP_MONITOR            		(000F0H | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)

#Define MF_HSZ_INFO                  	001000000H
#Define MF_SENDMSGS                 	002000000H
#Define MF_POSTMSGS                 	004000000H
#Define MF_CALLBACKS                	008000000H
#Define MF_ERRORS                   	010000000H
#Define MF_LINKS                    	020000000H
#Define MF_CONV                     	040000000H

#Define MF_MASK                     	0FF000000H


HSZPAIR Struct
	hszSvc DD
	hszTopic DD
EndS

CONVCONTEXT Struct
	cb DD
	wFlags DD
	wCountryID DD
	iCodePage DD
	dwLangID DD
	dwSecurity DD
	qos SECURITY_QUALITY_OF_SERVICE <>
EndS

CONVINFO Struct
	cb DD
	hUser DD
	hConvPartner DD
	hszSvcPartner DD
	hszServiceReq DD
	hszTopic DD
	hszItem DD
	wFmt DD
	wType DD
	wStatus DD
	wConvst DD
	wLastError DD
	hConvList DD
	ConvCtxt CONVCONTEXT <>
	hwnd DD
	hwndPartner DD
EndS

DDEML_MSG_HOOK_DATA Struct
	uiLo DD
	uiHi DD
	cbData DD
	Data DD 8 Dup ?
EndS

MONMSGSTRUCT Struct
	cb DD
	hwndTo DD
	dwTime DD
	hTask DD
	wMsg DD
	wParam DD
	lParam DD
	dmhd DDEML_MSG_HOOK_DATA <>
EndS

MONCBSTRUCT Struct
	cb DD
	dwTime DD
	hTask DD
	dwRet DD
	wType DD
	wFmt DD
	hConv DD
	hsz1 DD
	hsz2 DD
	hData DD
	dwData1 DD
	dwData2 DD
	cc CONVCONTEXT <>
	cbData DD
	Data DD 8 Dup ?
EndS

MONHSZSTRUCTA Struct
	cb DD
	fsAction DD
	dwTime DD
	hsz DD
	hTask DD
	str DB
EndS

MONHSZSTRUCTW Struct
	cb DD
	fsAction DD
	dwTime DD
	hsz DD
	hTask DD
	str DW
EndS

MONERRSTRUCT Struct
	cb DD
	wLastError DD
	dwTime DD
	hTask DD
EndS

MONLINKSTRUCT Struct
	cb DD
	dwTime DD
	hTask DD
	fEstablished DD
	fNoData DD
	hszSvc DD
	hszTopic DD
	hszItem DD
	wFmt DD
	fServer DD
	hConvServer DD
	hConvClient DD
EndS

MONCONVSTRUCT Struct
	cb DD
	fConnect DD
	dwTime DD
	hTask DD
	hszSvc DD
	hszTopic DD
	hConvClient DD
	hConvServer DD
EndS


#IF STRINGS UNICODE
	#Define DdeInitialize DdeInitializeW
	#Define DdeCreateStringHandle DdeCreateStringHandleW
	#Define DdeQueryString DdeQueryStringW
	#Define MONHSZSTRUCT MONHSZSTRUCTW
#ELSE
	#Define DdeInitialize DdeInitializeA
	#Define DdeCreateStringHandle DdeCreateStringHandleA
	#Define DdeQueryString DdeQueryStringA
	#Define MONHSZSTRUCT MONHSZSTRUCTA
#ENDIF

#ENDIF ;DDEML_INC
