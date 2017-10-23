#ifndef LMAUDIT_H
#define LMAUDIT_H

// lmaudit.h is for user mode WIN32 only !!!
// no WIN64 port

/* NetAudit API definitions */

#define REVISED_AUDIT_ENTRY_STRUCT

#define ACTION_LOCKOUT  0
#define ACTION_ADMINUNLOCK  1

#define AE_SRVSTART  0
#define AE_SRVPAUSED  1
#define AE_SRVCONT  2
#define AE_SRVSTOP  3

#define AE_GUEST  0
#define AE_USER  1
#define AE_ADMIN  2

#define AE_NORMAL  0
#define AE_USERLIMIT  0
#define AE_GENERAL  0
#define AE_ERROR  1
#define AE_SESSDIS  1
#define AE_BADPW  1
#define AE_AUTODIS  2
#define AE_UNSHARE  2
#define AE_ADMINPRIVREQD  2
#define AE_ADMINDIS  3
#define AE_NOACCESSPERM  3
#define AE_ACCRESTRICT  4

#define AE_NORMAL_CLOSE  0
#define AE_SES_CLOSE  1
#define AE_ADMIN_CLOSE  2

#define AE_LIM_UNKNOWN  0
#define AE_LIM_LOGONHOURS  1
#define AE_LIM_EXPIRED  2
#define AE_LIM_INVAL_WKSTA  3
#define AE_LIM_DISABLED  4
#define AE_LIM_DELETED  5

#define AE_MOD  0
#define AE_DELETE  1
#define AE_ADD  2

#define AE_UAS_USER  0
#define AE_UAS_GROUP  1
#define AE_UAS_MODALS  2

#define SVAUD_SERVICE  0x00000001
#define SVAUD_GOODSESSLOGON  0x00000006
#define SVAUD_BADSESSLOGON  0x00000018
#define SVAUD_SESSLOGON  (SVAUD_GOODSESSLOGON|SVAUD_BADSESSLOGON)
#define SVAUD_GOODNETLOGON  0x00000060
#define SVAUD_BADNETLOGON  0x00000180
#define SVAUD_NETLOGON  (SVAUD_GOODNETLOGON|SVAUD_BADNETLOGON)
#define SVAUD_LOGON  (SVAUD_NETLOGON|SVAUD_SESSLOGON)
#define SVAUD_GOODUSE  0x00000600
#define SVAUD_BADUSE  0x00001800
#define SVAUD_USE  (SVAUD_GOODUSE|SVAUD_BADUSE)
#define SVAUD_USERLIST  0x00002000
#define SVAUD_PERMISSIONS  0x00004000
#define SVAUD_RESOURCE  0x00008000
#define SVAUD_LOGONLIM  0x00010000

#define AA_AUDIT_ALL  0x0001
#define AA_A_OWNER  0x0004
#define AA_CLOSE  0x0008
#define AA_S_OPEN  0x0010
#define AA_S_WRITE  0x0020
#define AA_S_CREATE  0x0020
#define AA_S_DELETE  0x0040
#define AA_S_ACL  0x0080
#define AA_S_ALL  (AA_S_OPEN|AA_S_WRITE|AA_S_DELETE|AA_S_ACL)
#define AA_F_OPEN  0x0100
#define AA_F_WRITE  0x0200
#define AA_F_CREATE  0x0200
#define AA_F_DELETE  0x0400
#define AA_F_ACL  0x0800
#define AA_F_ALL  (AA_F_OPEN|AA_F_WRITE|AA_F_DELETE|AA_F_ACL)

#define AA_A_OPEN  0x1000
#define AA_A_WRITE  0x2000
#define AA_A_CREATE  0x2000
#define AA_A_DELETE  0x4000
#define AA_A_ACL  0x8000
#define AA_A_ALL  (AA_F_OPEN|AA_F_WRITE|AA_F_DELETE|AA_F_ACL)

#IFNDEF HLOG
	HLOG STRUCT
		time DD
		last_flags DD
		offset DD
		rec_offset DD
	ENDS
	
	#define LOGFLAGS_FORWARD  0
	#define LOGFLAGS_BACKWARD  1
	#define LOGFLAGS_SEEK  2
#ENDIF

AUDIT_ENTRY STRUCT
	ae_len DD
	ae_reserved DD
	ae_time DD
	ae_type DD
	ae_data_offset DD
	ae_data_size DD
ENDS

AE_SRVSTATUS STRUCT
	ae_sv_status DD
ENDS

AE_SESSLOGON STRUCT
	ae_so_compname DD
	ae_so_username DD
	ae_so_privilege DD
ENDS

AE_SESSLOGOFF STRUCT
	ae_sf_compname DD
	ae_sf_username DD
	ae_sf_reason DD
ENDS

AE_SESSPWERR STRUCT
	ae_sp_compname DD
	ae_sp_username DD
ENDS

AE_CONNSTART STRUCT
	ae_ct_compname DD
	ae_ct_username DD
	ae_ct_netname DD
	ae_ct_connid DD
ENDS

AE_CONNSTOP STRUCT
	ae_cp_compname DD
	ae_cp_username DD
	ae_cp_netname DD
	ae_cp_connid DD
	ae_cp_reason DD
ENDS

AE_CONNREJ STRUCT
	ae_cr_compname DD
	ae_cr_username DD
	ae_cr_netname DD
	ae_cr_reason DD
ENDS

AE_RESACCESS STRUCT
	ae_ra_compname DD
	ae_ra_username DD
	ae_ra_resname DD
	ae_ra_operation DD
	ae_ra_returncode DD
	ae_ra_restype DD
	ae_ra_fileid DD
ENDS

AE_RESACCESSREJ STRUCT
	ae_rr_compname DD
	ae_rr_username DD
	ae_rr_resname DD
	ae_rr_operation DD
ENDS

AE_CLOSEFILE STRUCT
	ae_cf_compname DD
	ae_cf_username DD
	ae_cf_resname DD
	ae_cf_fileid DD
	ae_cf_duration DD
	ae_cf_reason DD
ENDS

AE_SERVICESTAT STRUCT
	ae_ss_compname DD
	ae_ss_username DD
	ae_ss_svcname DD
	ae_ss_status DD
	ae_ss_code DD
	ae_ss_text DD
	ae_ss_returnval DD
ENDS

AE_ACLMOD STRUCT
	ae_am_compname DD
	ae_am_username DD
	ae_am_resname DD
	ae_am_action DD
	ae_am_datalen DD
ENDS

AE_UASMOD STRUCT
	ae_um_compname DD
	ae_um_username DD
	ae_um_resname DD
	ae_um_rectype DD
	ae_um_action DD
	ae_um_datalen DD
ENDS

AE_NETLOGON STRUCT
	ae_no_compname DD
	ae_no_username DD
	ae_no_privilege DD
	ae_no_authflags DD
ENDS

AE_NETLOGOFF STRUCT
	ae_nf_compname DD
	ae_nf_username DD
	ae_nf_reserved1 DD
	ae_nf_reserved2 DD
ENDS

AE_ACCLIM STRUCT
	ae_al_compname DD
	ae_al_username DD
	ae_al_resname DD
	ae_al_limit DD
ENDS

AE_LOCKOUT STRUCT
	ae_lk_compname DD
	ae_lk_username DD
	ae_lk_action DD
	ae_lk_bad_pw_count DD
ENDS

AE_GENERIC STRUCT
	ae_ge_msgfile DD
	ae_ge_msgnum DD
	ae_ge_params DD
	ae_ge_param1 DD
	ae_ge_param2 DD
	ae_ge_param3 DD
	ae_ge_param4 DD
	ae_ge_param5 DD
	ae_ge_param6 DD
	ae_ge_param7 DD
	ae_ge_param8 DD
	ae_ge_param9 DD
ENDS

/* avoid conflicts with structure names */
#define AE_SRVSTATUS  0
#define AE_SESSLOGON  1
#define AE_SESSLOGOFF  2
#define AE_SESSPWERR  3
#define AE_CONNSTART  4
#define AE_CONNSTOP  5
#define AE_CONNREJ  6
#define AE_RESACCESS  7
#define AE_RESACCESSREJ  8
#define AE_CLOSEFILE  9
#define AE_SERVICESTAT  11
#define AE_ACLMOD  12
#define AE_UASMOD  13
#define AE_NETLOGON  14
#define AE_NETLOGOFF  15
#define AE_NETLOGDENIED  16
#define AE_ACCLIMITEXCD  17
#define AE_RESACCESS2  18
#define AE_ACLMODFAIL  19
#define AE_LOCKOUT  20
#define AE_GENERIC_TYPE  21

#endif /* _LMAUDIT_H */
