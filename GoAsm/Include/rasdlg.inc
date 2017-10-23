;=============================================================;
;           rasdlg.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RASDLG_INC
#Define RASDLG_INC

#Define RASPBDEVENT_AddEntry    		1
#Define RASPBDEVENT_EditEntry   		2
#Define RASPBDEVENT_RemoveEntry 		3
#Define RASPBDEVENT_DialEntry   		4
#Define RASPBDEVENT_EditGlobals 		5
#Define RASPBDEVENT_NoUser      		6
#Define RASPBDEVENT_NoUserEdit  		7

#Define RASPBDFLAG_PositionDlg      	000000001H
#Define RASPBDFLAG_ForceCloseOnDial 	000000002H
#Define RASPBDFLAG_NoUser           	000000010H
#Define RASPBDFLAG_UpdateDefaults   	080000000H

#Define RASEDFLAG_PositionDlg 			000000001H
#Define RASEDFLAG_NewEntry    			000000002H
#Define RASEDFLAG_CloneEntry  			000000004H
#Define RASEDFLAG_NoRename    			000000008H
#Define RASEDFLAG_ShellOwned  			040000000H

#Define RASDDFLAG_PositionDlg 			000000001H
#Define RASDDFLAG_LinkFailure 			080000000H

#Define RASMDPAGE_Status            	0
#Define RASMDPAGE_Summary           	1
#Define RASMDPAGE_Preferences       	2

#Define RASMDFLAG_PositionDlg       	000000001H
#Define RASMDFLAG_UpdateDefaults    	080000000H


RASNOUSERW Struct
	dwSize DD
	dwFlags DD
	dwTimeoutMs DD
	szUserName DW (UNLEN + 1) Dup ?
	szPassword DW (PWLEN + 1) Dup ?
	szDomain DW (DNLEN + 1) Dup ?
EndS

RASNOUSERA Struct
	dwSize DD
	dwFlags DD
	dwTimeoutMs DD
	szUserName DB (UNLEN + 1) Dup ?
	szPassword DB (PWLEN + 1) Dup ?
	szDomain DB (DNLEN + 1) Dup ?
EndS

RASPBDLGW Struct
	dwSize DD
	hwndOwner DD
	dwFlags DD
	xDlg DD
	yDlg DD
	dwCallbackId DD
	pCallback DD
	dwError DD
	reserved DD
	reserved2 DD
EndS

RASPBDLGA Struct
	dwSize DD
	hwndOwner DD
	dwFlags DD
	xDlg DD
	yDlg DD
	dwCallbackId DD
	pCallback DD
	dwError DD
	reserved DD
	reserved2 DD
EndS

RASENTRYDLGW Struct
	dwSize DD
	hwndOwner DD
	dwFlags DD
	xDlg DD
	yDlg DD
	szEntry DW (RAS_MaxEntryName + 1) Dup ?
	dwError DD
	reserved DD
	reserved2 DD
EndS

RASENTRYDLGA Struct
	dwSize DD
	hwndOwner DD
	dwFlags DD
	xDlg DD
	yDlg DD
	szEntry DW (RAS_MaxEntryName + 1) Dup ?
	dwError DD
	reserved DD
	reserved2 DD
EndS

RASDIALDLG Struct
	dwSize DD
	hwndOwner DD
	dwFlags DD
	xDlg DD
	yDlg DD
	dwSubEntry DD
	dwError DD
	reserved DD
	reserved2 DD
EndS

RASMONITORDLG Struct
	dwSize DD
	hwndOwner DD
	dwFlags DD
	dwStartPage DD
	xDlg DD
	yDlg DD
	dwError DD
	reserved DD
	reserved2 DD
EndS


#IF STRINGS UNICODE
	#Define RASNOUSER RASNOUSERW
	#Define RASPBDLG RASPBDLGW
	#Define RASENTRYDLG RASENTRYDLGW
	#Define RasPhonebookDlg RasPhonebookDlgW
	#Define RasEntryDlg RasEntryDlgW
	#Define RasDialDlg RasDialDlgW
	#Define RasMonitorDlg RasMonitorDlgW
#ELSE
	#Define RASNOUSER RASNOUSERA
	#Define RASPBDLG RASPBDLGA
	#Define RASENTRYDLG RASENTRYDLGA
	#Define RasPhonebookDlg RasPhonebookDlgA
	#Define RasEntryDlg RasEntryDlgA
	#Define RasDialDlg RasDialDlgA
	#Define RasMonitorDlg RasMonitorDlgA
#ENDIF

#ENDIF ;RASDLG_INC
