/*
* internal pidl functions
*
*
* DO NOT use this definitions outside the shell32.dll !
*
* The contents of a pidl should never used from a application
* directly.
*
* Undocumented:
* MS says: the abID of SHITEMID should be treated as binary data and not
* be interpreted by applications. Applies to everyone but MS itself.
* Word95 interprets the contents of abID (Filesize/Date) so we have to go
* for binary compatibility here.
*/

#ifndef PIDL_H
#define PIDL_H

#IFNDEF WINUSER_H
	#include "winuser.h"
#ENDIF

#IFNDEF SHLOBJ_H
	#include "shlobj.h"
#ENDIF

/*
* the pidl does cache fileattributes to speed up SHGetAttributes when
* displaying a big number of files.
*
* a pidl of NULL means the desktop
*
* The structure of the pidl seems to be a union. The first byte of the
* PIDLDATA describes the type of pidl.
*
*       object        ! first byte /  ! format       ! living space
*                     ! size
*       ----------------------------------------------------------------
*       my computer     0x1F/20         guid (2)        (usual)
*       network         0x1F            guid
*       bitbucket       0x1F            guid
*       drive           0x23/25         drive           (usual)
*       drive           0x25/25         drive           (lnk/persistent)
*       drive           0x29/25         drive
*       shell extension 0x2E            guid
*       drive           0x2F            drive           (lnk/persistent)
*       folder/file     0x30            folder/file (1) (lnk/persistent)
*       folder          0x31            folder          (usual)
*       valueA          0x32            file            (ANSI file name) 
*       valueW          0x34            file            (Unicode file name)
*       workgroup       0x41            network (3)
*       computer        0x42            network (4)
*       net provider    0x46            network
*       whole network   0x47            network (5)
*       MSITStore       0x61            htmlhlp (7)
*       printers/ras connections        0x70            guid
*       history/favorites 0xb1          file
*       share           0xc3            network (6)
*
* guess: the persistent elements are non tracking
*
* (1) dummy byte is used, attributes are empty
* (2) IID_MyComputer = 20D04FE0L-3AEA-1069-A2D8-08002B30309D
* (3) two strings       "workgroup" "Microsoft Network"
* (4) two strings       "\\sirius" "Microsoft Network"
* (5) one string        "Entire Network"
* (6) two strings       "\\sirius\c" "Microsoft Network"
* (7) contains string   "mk:@MSITStore:C:\path\file.chm::/path/filename.htm"
*               GUID    871C5380-42A0-1069-A2EA-08002B30309D
*/
 

#define PT_CPLAPPLET    0x00
#define PT_GUID         0x1F
#define PT_DRIVE        0x23
#define PT_DRIVE2       0x25
#define PT_DRIVE3       0x29
#define PT_SHELLEXT     0x2E
#define PT_DRIVE1       0x2F
#define PT_FOLDER1      0x30
#define PT_FOLDER       0x31
#define PT_VALUE        0x32
#define PT_VALUEW       0x34
#define PT_FOLDERW      0x35
#define PT_WORKGRP      0x41
#define PT_COMP         0x42
#define PT_NETPROVIDER  0x46
#define PT_NETWORK      0x47
#define PT_IESPECIAL1   0x61
#define PT_YAGUID       0x70
#define PT_IESPECIAL2   0xb1
#define PT_SHARE        0xc3

PIDLCPanelStruct STRUCT
	dummy DB
	iconIdx DD
	offsDispName DW
	offsComment DW
	szName CHAR
ENDS

GUIDStruct STRUCT
	dummy DB
	guid GUID
ENDS

DriveStruct STRUCT
	szDriveName CHAR 20 DUP
	unknown DW
eNDS

FileStruct STRUCT
	dummy DB
	dwFileSize DD
	uFileDate DW
	uFileTime DW
	uFileAttribs DW
	szNames CHAR
ENDS

FileStructW STRUCT
	cbLen DW
	dummy1 DB 6 DUP
	uCreationDate DW
	uCreationTime DW
	uLastAccessDate DW
	uLastAccessTime DW
	dummy2 DB 4 DUP
	wszName WCHAR
ENDS

ValueW STRUCT
	name WCHAR
ENDS

PIDLDATA STRUCT
	type DB
	UNION
		guid GUIDStruct
		drive DriveStruct
		file FileStruct
		network struct
			dummy DW
			szNames CHAR
		ENDS
		htmlhelp struct
			dummy DW
			dummy1 DD
		szName CHAR
		ENDS
		cpanel PIDLCPanelStruct
		valueW ValueW
	ENDUNION
ENDS

;BOOL WINAPI ILGetDisplayNameExW(LPSHELLFOLDER psf, LPCITEMIDLIST pidl, LPWSTR path, DWORD type);

#endif
