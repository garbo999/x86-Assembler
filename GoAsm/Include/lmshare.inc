;=============================================================;
;          lmshare.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMSHARE_INC
#Define LMSHARE_INC

SHARE_INFO_0 Struct
	shi0_netname DD
EndS

SHARE_INFO_1 Struct
	shi1_netname DD
	shi1_type DD
	shi1_remark DD
EndS

SHARE_INFO_2 Struct
	shi2_netname DD
	shi2_type DD
	shi2_remark DD
	shi2_permissions DD
	shi2_max_uses DD
	shi2_current_uses DD
	shi2_path DD
	shi2_passwd DD
EndS

SHARE_INFO_501 Struct
	shi501_netname DD
	shi501_type DD
	shi501_remark DD
	shi501_flags DD
EndS

SHARE_INFO_502 Struct
	shi502_netname DD
	shi502_type DD
	shi502_remark DD
	shi502_permissions DD
	shi502_max_uses DD
	shi502_current_uses DD
	shi502_path DD
	shi502_passwd DD
	shi502_reserved DD
	shi502_security_descriptor DD
EndS

SHARE_INFO_1004 Struct
	shi1004_remark DD
EndS

SHARE_INFO_1005 Struct
	shi1005_flags DD
EndS

SHARE_INFO_1006 Struct
	shi1006_max_uses DD
EndS

SHARE_INFO_1007 Struct
	shi1007_flags DD
	shi1007_AlternateDirectoryName DD
EndS

SHARE_INFO_1501 Struct
	shi1501_reserved DD
	shi1501_security_descriptor DD
EndS

#Define SHARE_NETNAME_PARMNUM               1
#Define SHARE_TYPE_PARMNUM                  3
#Define SHARE_REMARK_PARMNUM                4
#Define SHARE_PERMISSIONS_PARMNUM           5
#Define SHARE_MAX_USES_PARMNUM              6
#Define SHARE_CURRENT_USES_PARMNUM          7
#Define SHARE_PATH_PARMNUM                  8
#Define SHARE_PASSWD_PARMNUM                9
#Define SHARE_FILE_SD_PARMNUM               501

#Define SHARE_REMARK_INFOLEVEL              (PARMNUM_BASE_INFOLEVEL + SHARE_REMARK_PARMNUM)
#Define SHARE_MAX_USES_INFOLEVEL            (PARMNUM_BASE_INFOLEVEL + SHARE_MAX_USES_PARMNUM)
#Define SHARE_FILE_SD_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + SHARE_FILE_SD_PARMNUM)

#Define SHI1_NUM_ELEMENTS                   4
#Define SHI2_NUM_ELEMENTS                   10

#Define STYPE_DISKTREE                      0
#Define STYPE_PRINTQ                        1
#Define STYPE_DEVICE                        2
#Define STYPE_IPC                           3

#Define STYPE_SPECIAL                       080000000H

#Define SHI_USES_UNLIMITED                  (-1)

#Define SHI1005_FLAGS_DFS                   001H
#Define SHI1005_FLAGS_DFS_ROOT              002H

#Define COW_PERMACHINE                      004H
#Define COW_PERUSER                         008H

#Define CSC_CACHEABLE                       010H
#Define CSC_NOFLOWOPS                       020H
#Define CSC_AUTO_INWARD                     040H
#Define CSC_AUTO_OUTWARD                    080H

#Define SHI1005_VALID_FLAGS_SET            (CSC_CACHEABLE | CSC_NOFLOWOPS | CSC_AUTO_INWARD | CSC_AUTO_OUTWARD | COW_PERMACHINE | COW_PERUSER)

#Define SHI1007_VALID_FLAGS_SET             SHI1005_VALID_FLAGS_SET

SESSION_INFO_0 Struct
	sesi0_cname DD
EndS

SESSION_INFO_1 Struct
	sesi1_cname DD
	sesi1_username DD
	sesi1_num_opens DD
	sesi1_time DD
	sesi1_idle_time DD
	sesi1_user_flags DD
EndS

SESSION_INFO_2 Struct
	sesi2_cname DD
	sesi2_username DD
	sesi2_num_opens DD
	sesi2_time DD
	sesi2_idle_time DD
	sesi2_user_flags DD
	sesi2_cltype_name DD
EndS

SESSION_INFO_10 Struct
	sesi10_cname DD
	sesi10_username DD
	sesi10_time DD
	sesi10_idle_time DD
EndS

SESSION_INFO_502 Struct
	sesi502_cname DD
	sesi502_username DD
	sesi502_num_opens DD
	sesi502_time DD
	sesi502_idle_time DD
	sesi502_user_flags DD
	sesi502_cltype_name DD
	sesi502_transport DD
EndS

#Define SESS_GUEST                          000000001H
#Define SESS_NOENCRYPTION                   000000002H

#Define SESI1_NUM_ELEMENTS                  8
#Define SESI2_NUM_ELEMENTS                  9

CONNECTION_INFO_0 Struct
	coni0_id DD
EndS

CONNECTION_INFO_1 Struct
	coni1_id DD
	coni1_type DD
	coni1_num_opens DD
	coni1_num_users DD
	coni1_time DD
	coni1_username DD
	coni1_netname DD
EndS

FILE_INFO_2 Struct
	fi2_id DD
EndS

FILE_INFO_3 Struct
	fi3_id DD
	fi3_permissions DD
	fi3_num_locks DD
	fi3_pathname DD
	fi3_username DD
EndS

#Define PERM_FILE_READ                      01H
#Define PERM_FILE_WRITE                     02H
#Define PERM_FILE_CREATE                    04H

#ENDIF ;LMSHARE_INC
