#ifndef CPL_H
#define CPL_H

#define WM_CPL_LAUNCH  (WM_USER+1000)
#define WM_CPL_LAUNCHED  (WM_USER+1001)

#define CPL_DYNAMIC_RES  0
#define CPL_INIT  1
#define CPL_GETCOUNT  2
#define CPL_INQUIRE  3
#define CPL_SELECT  4
#define CPL_DBLCLK  5
#define CPL_STOP  6
#define CPL_EXIT  7
#define CPL_NEWINQUIRE  8
#define CPL_STARTWPARMSA  9
#define CPL_STARTWPARMSW  10
#define CPL_SETUP  200

CPLINFO STRUCT
	idIcon DD
	idName DD
	idInfo DD
	lData DD
ENDS

NEWCPLINFOA STRUCT
	dwSize DD
	dwFlags DD
	dwHelpContext DD
	lData LONG_PTR
	hIcon HANDLE
	szName DB 32 DUP
	szInfo DB 64 DUP
	szHelpFile DB 128 DUP
ENDS

NEWCPLINFOW STRUCT
	dwSize DD
	dwFlags DD
	dwHelpContext DD
	lData LONG_PTR
	hIcon HANDLE
	szName DW 32 DUP
	szInfo DW 64 DUP
	szHelpFile DW 128 DUP
ENDS

#IFDEF UNICODE
	#define NEWCPLINFO NEWCPLINFOW
	#define CPL_STARTWPARMS CPL_STARTWPARMSW
#else
	#define NEWCPLINFO NEWCPLINFOA
	#define CPL_STARTWPARMS CPL_STARTWPARMSA
#endif

#endif /* CPL_H */
