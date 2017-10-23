#ifndef RASDLG_H
#define RASDLG_H

/* Remote Access Common Dialog API definitions */

#IFDEF LINKFILES
	#dynamiclinkfile Rasdlg.dll
#ENDIF

#IFNDEF RAS_H
	#include ras.h
#ENDIF

#define RASPBDEVENT_AddEntry  1
#define RASPBDEVENT_EditEntry  2
#define RASPBDEVENT_RemoveEntry 3
#define RASPBDEVENT_DialEntry  4
#define RASPBDEVENT_EditGlobals  5
#define RASPBDEVENT_NoUser  6
#define RASPBDEVENT_NoUserEdit  7

#define RASNOUSER_SmartCard  0x00000001

RASNOUSERW STRUCT
	dwSize DD
	dwFlags DD
	dwTimeoutMs DD
	szUserName DW UNLEN+1 DUP
	szPassword DW PWLEN+1 DUP
	szDomain DW DNLEN+1 DUP
ENDS

RASNOUSERA STRUCT
	dwSize DD
	dwFlags DD
	dwTimeoutMs DD
	szUserName DB UNLEN+1 DUP
	szPassword DB PWLEN+1 DUP
	szDomain DB DNLEN+1 DUP
ENDS

#define RASPBDFLAG_PositionDlg  0x00000001
#define RASPBDFLAG_ForceCloseOnDial  0x00000002
#define RASPBDFLAG_NoUser  0x00000010
#define RASPBDFLAG_UpdateDefaults  0x80000000

RASPBDLGW STRUCT
	dwSize DD
	hwndOwner HANDLE
	dwFlags DD
	xDlg DD
	yDlg DD
	dwCallbackId ULONG_PTR
	pCallback PTR
	dwError DD
	reserved ULONG_PTR
	reserved2 ULONG_PTR
ENDS

RASPBDLGA STRUCT
	dwSize DD
	hwndOwner HANDLE
	dwFlags DD
	xDlg DD
	yDlg DD
	dwCallbackId ULONG_PTR
	pCallback DD
	dwError DD
	reserved ULONG_PTR
	reserved2 ULONG_PTR
ENDS

#define RASEDFLAG_PositionDlg  0x00000001
#define RASEDFLAG_NewEntry  0x00000002
#define RASEDFLAG_CloneEntry  0x00000004
#define RASEDFLAG_NoRename  0x00000008
#define RASEDFLAG_ShellOwned  0x40000000
#define RASEDFLAG_NewPhoneEntry  0x00000010
#define RASEDFLAG_NewTunnelEntry  0x00000020
#define RASEDFLAG_NewDirectEntry  0x00000040

RASENTRYDLGW STRUCT
	dwSize DD
	hwndOwner HANDLE
	dwFlags DD
	xDlg DD
	yDlg DD
	szEntry DW RAS_MaxEntryName+1 DUP
	dwError DD
	reserved ULONG_PTR
	reserved2 ULONG_PTR
ENDS

RASENTRYDLGA STRUCT
	dwSize DD
	hwndOwner HANDLE
	dwFlags DD
	xDlg DD
	yDlg DD
	szEntry DW RAS_MaxEntryName+1 DUP
	dwError DD
	reserved ULONG_PTR
	reserved2 ULONG_PTR
ENDS

#define RASDDFLAG_PositionDlg  0x00000001
#define RASDDFLAG_NoPrompt  0x00000002
#define RASDDFLAG_LinkFailure  0x80000000

RASDIALDLG STRUCT
	dwSize DD
	hwndOwner HANDLE
	dwFlags DD
	xDlg DD
	yDlg DD
	dwSubEntry DD
	dwError DD
	reserved ULONG_PTR
	reserved2 ULONG_PTR
ENDS

#define RASMDPAGE_Status  0
#define RASMDPAGE_Summary  1
#define RASMDPAGE_Preferences 2

#define RASMDFLAG_PositionDlg  0x00000001
#define RASMDFLAG_UpdateDefaults  0x80000000

RASMONITORDLG STRUCT
	dwSize DD
	hwndOwner HANDLE
	dwFlags DD
	dwStartPage DD
	xDlg DD
	yDlg DD
	dwError DD
	reserved ULONG_PTR
	reserved2 ULONG_PTR
ENDS

#IFDEF UNICODE
	#define RASPBDLG  RASPBDLGW
	#define RASNOUSER  RASNOUSERW
	#define RASENTRYDLG  RASENTRYDLGW
	#define RasPhonebookDlg  RasPhonebookDlgW
	#define RasEntryDlg  RasEntryDlgW
	#define RasDialDlg  RasDialDlgW
	#define RasMonitorDlg  RasMonitorDlgW
#else
	#define RASENTRYDLG  RASENTRYDLGA
	#define RASPBDLG  RASPBDLGA
	#define RASNOUSER  RASNOUSERA
	#define RasPhonebookDlg  RasPhonebookDlgA
	#define RasEntryDlg  RasEntryDlgA
	#define RasDialDlg  RasDialDlgA
	#define RasMonitorDlg  RasMonitorDlgA
#endif

#endif
