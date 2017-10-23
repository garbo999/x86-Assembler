#ifndef LMSHARE_H
#define LMSHARE_H

/* NetShare, NetSession, NetFile and NetConnection API definitions */

#IFNDEF LMCONS_H
	#include lmcons.h
#ENDIF

#define SHARE_NETNAME_PARMNUM  1
#define SHARE_TYPE_PARMNUM  3
#define SHARE_REMARK_PARMNUM  4
#define SHARE_PERMISSIONS_PARMNUM  5
#define SHARE_MAX_USES_PARMNUM  6
#define SHARE_CURRENT_USES_PARMNUM  7
#define SHARE_PATH_PARMNUM  8
#define SHARE_PASSWD_PARMNUM  9
#define SHARE_FILE_SD_PARMNUM  501
#define SHARE_REMARK_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+SHARE_REMARK_PARMNUM)
#define SHARE_MAX_USES_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+SHARE_MAX_USES_PARMNUM)
#define SHARE_FILE_SD_INFOLEVEL  (PARMNUM_BASE_INFOLEVEL+SHARE_FILE_SD_PARMNUM)

#define SHI1_NUM_ELEMENTS  4
#define SHI2_NUM_ELEMENTS  10

#define STYPE_DISKTREE  0
#define STYPE_PRINTQ  1
#define STYPE_DEVICE  2
#define STYPE_IPC  3
#define STYPE_SPECIAL  0x80000000

#define SHI_USES_UNLIMITED  -1

#define SHI1005_FLAGS_DFS  0x01
#define SHI1005_FLAGS_DFS_ROOT  0x02

#define CSC_MASK  0x30
#define CSC_CACHE_MANUAL_REINT  0x00
#define CSC_CACHE_AUTO_REINT  0x10
#define CSC_CACHE_VDO  0x20
#define CSC_CACHE_NONE  0x30

#define SHI1005_VALID_FLAGS_SET  CSC_MASK

#define SESS_GUEST  0x00000001
#define SESS_NOENCRYPTION  0x00000002

#define SESI1_NUM_ELEMENTS  8
#define SESI2_NUM_ELEMENTS  9

#define PERM_FILE_READ  0x1
#define PERM_FILE_WRITE  0x2
#define PERM_FILE_CREATE  0x4

SHARE_INFO_0 STRUCT
	shi0_netname PTR
ENDS

SHARE_INFO_1 STRUCT
	shi1_netname PTR
	shi1_type DD
	shi1_remark PTR
ENDS

SHARE_INFO_2 STRUCT
	shi2_netname PTR
	shi2_type DD
	shi2_remark PTR
	shi2_permissions DD
	shi2_max_uses DD
	shi2_current_uses DD
	shi2_path PTR
	shi2_passwd PTR
ENDS

SHARE_INFO_501 STRUCT
	shi501_netname PTR
	shi501_type DD
	shi501_remark DD
	shi501_flags DD
ENDS

SHARE_INFO_502 STRUCT
	shi502_netname PTR
	shi502_type DD
	shi502_remark PTR
	shi502_permissions DD
	shi502_max_uses DD
	shi502_current_uses DD
	shi502_path PTR
	shi502_passwd PTR
	shi502_reserved DD
	shi502_security_descriptor PTR
ENDS

SHARE_INFO_1004 STRUCT
	shi1004_remark PTR
ENDS

SHARE_INFO_1005 STRUCT
	shi1005_flags DD
ENDS

SHARE_INFO_1006 STRUCT
	shi1006_max_uses DD
ENDS

SHARE_INFO_1501 STRUCT
	shi1501_reserved DD
	shi1501_security_descriptor PTR
ENDS

SESSION_INFO_0 STRUCT
	sesi0_cname PTR
ENDS

SESSION_INFO_1 STRUCT
	sesi1_cname PTR
	sesi1_username PTR
	sesi1_num_opens DD
	sesi1_time DD
	sesi1_idle_time DD
	sesi1_user_flags DD
ENDS

SESSION_INFO_2 STRUCT
	sesi2_cname PTR
	sesi2_username PTR
	sesi2_num_opens DD
	sesi2_time DD
	sesi2_idle_time DD
	sesi2_user_flags DD
	sesi2_cltype_name PTR
ENDS

SESSION_INFO_10 STRUCT
	sesi10_cname PTR
	sesi10_username PTR
	sesi10_time DD
	sesi10_idle_time DD
ENDS

SESSION_INFO_502 STRUCT
	sesi502_cname PTR
	sesi502_username PTR
	sesi502_num_opens DD
	sesi502_time DD
	sesi502_idle_time DD
	sesi502_user_flags DD
	sesi502_cltype_name PTR
	sesi502_transport PTR
ENDS

CONNECTION_INFO_0 STRUCT
	coni0_id DD
ENDS

CONNECTION_INFO_1 STRUCT
	coni1_id DD
	coni1_type DD
	coni1_num_opens DD
	coni1_num_users DD
	coni1_time DD
	coni1_username PTR
	coni1_netname PTR
ENDS

FILE_INFO_2 STRUCT
	fi2_id DD
ENDS

FILE_INFO_3 STRUCT
	fi3_id DD
	fi3_permissions DD
	fi3_num_locks DD
	fi3_pathname PTR
	fi3_username PTR
ENDS

#endif /* _LMSHARE_H */
