;=============================================================;
;           lmdfs.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMDFS_INC
#Define LMDFS_INC

#Define DFS_VOLUME_STATE_OK                 1
#Define DFS_VOLUME_STATE_INCONSISTENT       2
#Define DFS_VOLUME_STATE_OFFLINE            3
#Define DFS_VOLUME_STATE_ONLINE             4

#Define DFS_STORAGE_STATE_OFFLINE           1
#Define DFS_STORAGE_STATE_ONLINE            2

DFS_INFO_1 Struct
	EntryPath DD
EndS

DFS_INFO_2 Struct
	EntryPath DD
	Comment DD
	State DD
	NumberOfStorages DD
EndS

DFS_STORAGE_INFO Struct
	State DD
	ServerName DD
	ShareName DD
EndS

DFS_INFO_3 Struct
	EntryPath DD
	Comment DD
	State DD
	NumberOfStorages DD
	Storage DD
EndS

DFS_INFO_100 Struct
	Comment DD
EndS

DFS_INFO_101 Struct
	State DD
EndS

#Define DFS_ADD_VOLUME                      1
#Define DFS_RESTORE_VOLUME                  2

#ENDIF ;LMDFS_INC
