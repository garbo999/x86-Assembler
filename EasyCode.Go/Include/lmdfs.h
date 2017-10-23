#ifndef LMDFS_H
#define LMDFS_H

/* NetDfs API definitions */
#IFNDEF LMCONS_H
	#include lmcons.h
#ENDIF

#define DFS_VOLUME_STATE_OK  1
#define DFS_VOLUME_STATE_INCONSISTENT  2
#define DFS_VOLUME_STATE_OFFLINE  3
#define DFS_VOLUME_STATE_ONLINE  4

#define DFS_STORAGE_STATE_OFFLINE  1
#define DFS_STORAGE_STATE_ONLINE  2
#define DFS_STORAGE_STATE_ACTIVE  4

#define DFS_ADD_VOLUME  1
#define DFS_RESTORE_VOLUME  2

#define NET_DFS_SETDC_FLAGS  0x00000000
#define NET_DFS_SETDC_TIMEOUT  0x00000001
#define NET_DFS_SETDC_INITPKT  0x00000002

#define DFS_SITE_PRIMARY  0x1

DFS_INFO_1 STRUCT
	EntryPath PTR
ENDS

DFS_INFO_2 STRUCT
	EntryPath PTR
	Comment PTR
	State DD
	NumberOfStorages DD
ENDS

DFS_STORAGE_INFO STRUCT
	State DD
	ServerName PTR
	ShareName PTR
ENDS

DFS_INFO_3 STRUCT
	EntryPath PTR
	Comment PTR
	State DD
	NumberOfStorages DD
	Storage PTR
ENDS

DFS_INFO_4 STRUCT
	EntryPath PTR
	Comment PTR
	State DD
	Timeout DD
	Guid GUID
	NumberOfStorages DD
	Storage PTR
ENDS

DFS_INFO_100 STRUCT
	Comment PTR
ENDS

DFS_INFO_101 STRUCT
	State DD
ENDS

DFS_INFO_102 STRUCT
	Timeout DD
ENDS

DFS_INFO_200 STRUCT
	FtDfsName PTR
ENDS

DFS_SITENAME_INFO STRUCT
	SiteFlags DD
	SiteName PTR
ENDS

DFS_SITELIST_INFO STRUCT
	cSites DD
	Site DFS_SITENAME_INFO
ENDS

#endif /* _LMDFS_H */
