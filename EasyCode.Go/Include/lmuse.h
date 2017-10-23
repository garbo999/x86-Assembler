#ifndef LMUSE_H
#define LMUSE_H

/* NetUse API definitions */

#IFNDEF LMCONS_H
	#include lmcons.h
#ENDIF

#IFNDEF LMUSEFLG_H
	#include lmuseflg.h
#ENDIF

#define USE_LOCAL_PARMNUM  1
#define USE_REMOTE_PARMNUM  2
#define USE_PASSWORD_PARMNUM  3
#define USE_ASGTYPE_PARMNUM  4
#define USE_USERNAME_PARMNUM  5
#define USE_DOMAINNAME_PARMNUM  6

#define USE_OK  0
#define USE_PAUSED  1
#define USE_SESSLOST  2
#define USE_DISCONN  2
#define USE_NETERR  3
#define USE_CONN  4
#define USE_RECONN  5

#define USE_WILDCARD  ((DWORD)-1)
#define USE_DISKDEV  0
#define USE_SPOOLDEV  1
#define USE_CHARDEV  2
#define USE_IPC  3

#define CREATE_NO_CONNECT  1
#define CREATE_BYPASS_CSC  2

USE_INFO_0 STRUCT
	ui0_local PTR
	ui0_remote PTR
ENDS

USE_INFO_1 STRUCT
	ui1_local PTR
	ui1_remote PTR
	ui1_password PTR
	ui1_status DD
	ui1_asg_type DD
	ui1_refcount DD
	ui1_usecount DD
ENDS

USE_INFO_2 STRUCT
	ui2_local PTR
	ui2_remote PTR
	ui2_password PTR
	ui2_status DD
	ui2_asg_type DD
	ui2_refcount DD
	ui2_usecount DD
	ui2_username PTR
	ui2_domainname PTR
ENDS

USE_INFO_3 STRUCT
	ui3_ui2 USE_INFO_2
	ui3_flags DD
ENDS

#endif /* _LMUSE_H */
