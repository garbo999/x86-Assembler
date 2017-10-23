;=============================================================;
;          lmaudit.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMAUDIT_INC
#Define LMAUDIT_INC

#IFNDEF HLOG
	HLOG Struct
		time DD
		last_flags DD
		offset DD
		rec_offset DD
	EndS

	#Define LOGFLAGS_FORWARD	            0
	#Define LOGFLAGS_BACKWARD	            01H
	#Define LOGFLAGS_SEEK		            02H
#ENDIF

AUDIT_ENTRY Struct
	ae_len DD
	ae_reserved DD
	ae_time DD
	ae_type DD
	ae_data_offset DD
	ae_data_size DD
EndS

AE_SRVSTATUS Struct
	ae_sv_status DD
EndS

AE_SESSLOGON Struct
	ae_so_compname DD
	ae_so_username DD
	ae_so_privilege DD
EndS

AE_SESSLOGOFF Struct
	ae_sf_compname DD
	ae_sf_username DD
	ae_sf_reason DD
EndS

AE_SESSPWERR Struct
	ae_sp_compname DD
	ae_sp_username DD
EndS

AE_CONNSTART Struct
	ae_ct_compname DD
	ae_ct_username DD
	ae_ct_netname DD
	ae_ct_connid DD
EndS

AE_CONNSTOP Struct
	ae_cp_compname DD
	ae_cp_username DD
	ae_cp_netname DD
	ae_cp_connid DD
	ae_cp_reason DD
EndS

AE_CONNREJ Struct
	ae_cr_compname DD
	ae_cr_username DD
	ae_cr_netname DD
	ae_cr_reason DD
EndS

AE_RESACCESS Struct
	ae_ra_compname DD
	ae_ra_username DD
	ae_ra_resname DD
	ae_ra_operation DD
	ae_ra_returncode DD
	ae_ra_restype DD
	ae_ra_fileid DD
EndS

AE_RESACCESSREJ Struct
	ae_rr_compname DD
	ae_rr_username DD
	ae_rr_resname DD
	ae_rr_operation DD
EndS

AE_CLOSEFILE Struct
	ae_cf_compname DD
	ae_cf_username DD
	ae_cf_resname DD
	ae_cf_fileid DD
	ae_cf_duration DD
	ae_cf_reason DD
EndS

AE_SERVICESTAT Struct
	ae_ss_compname DD
	ae_ss_username DD
	ae_ss_svcname DD
	ae_ss_status DD
	ae_ss_code DD
	ae_ss_text DD
	ae_ss_returnval DD
EndS

AE_ACLMOD Struct
	ae_am_compname DD
	ae_am_username DD
	ae_am_resname DD
	ae_am_action DD
	ae_am_datalen DD
EndS

AE_UASMOD Struct
	ae_um_compname DD
	ae_um_username DD
	ae_um_resname DD
	ae_um_rectype DD
	ae_um_action DD
	ae_um_datalen DD
EndS

AE_NETLOGON Struct
	ae_no_compname DD
	ae_no_username DD
	ae_no_privilege DD
	ae_no_authflags DD
EndS

AE_NETLOGOFF Struct
	ae_nf_compname DD
	ae_nf_username DD
	ae_nf_reserved1 DD
	ae_nf_reserved2 DD
EndS

AE_ACCLIM Struct
	ae_al_compname DD
	ae_al_username DD
	ae_al_resname DD
	ae_al_limit DD
EndS

#Define ACTION_LOCKOUT                      00H
#Define ACTION_ADMINUNLOCK                  01H

AE_LOCKOUT Struct
	ae_lk_compname DD
	ae_lk_username DD
	ae_lk_action DD
	ae_lk_bad_pw_count DD
EndS

AE_GENERIC Struct
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
EndS

#Define AE_SRVSTATUS	                    0
#Define AE_SESSLOGON	                    1
#Define AE_SESSLOGOFF	                    2
#Define AE_SESSPWERR	                    3
#Define AE_CONNSTART	                    4
#Define AE_CONNSTOP	                        5
#Define AE_CONNREJ	                        6
#Define AE_RESACCESS	                    7
#Define AE_RESACCESSREJ	                    8
#Define AE_CLOSEFILE	                    9
#Define AE_SERVICESTAT	                    11
#Define AE_ACLMOD	                        12
#Define AE_UASMOD	                        13
#Define AE_NETLOGON	                        14
#Define AE_NETLOGOFF	                    15
#Define AE_NETLOGDENIED                     16
#Define AE_ACCLIMITEXCD                     17
#Define AE_RESACCESS2	                    18
#Define AE_ACLMODFAIL	                    19
#Define AE_LOCKOUT                          20
#Define AE_GENERIC_TYPE                     21

#Define AE_SRVSTART	                        0
#Define AE_SRVPAUSED	                    1
#Define AE_SRVCONT	                        2
#Define AE_SRVSTOP	                        3

#Define AE_GUEST	                        0
#Define AE_USER		                        1
#Define AE_ADMIN	                        2

#Define AE_NORMAL	                        0
#Define AE_USERLIMIT	                    0
#Define AE_GENERAL	                        0
#Define AE_ERROR	                        1
#Define AE_SESSDIS	                        1
#Define AE_BADPW	                        1
#Define AE_AUTODIS	                        2
#Define AE_UNSHARE	                        2
#Define AE_ADMINPRIVREQD                    2
#Define AE_ADMINDIS	                        3
#Define AE_NOACCESSPERM                     3
#Define AE_ACCRESTRICT	                    4

#Define AE_NORMAL_CLOSE	                    0
#Define AE_SES_CLOSE	                    1
#Define AE_ADMIN_CLOSE	                    2

#Define AE_LIM_UNKNOWN	                    0
#Define AE_LIM_LOGONHOURS                   1
#Define AE_LIM_EXPIRED	                    2
#Define AE_LIM_INVAL_WKSTA                  3
#Define AE_LIM_DISABLED                     4
#Define AE_LIM_DELETED	                    5

#Define AE_MOD		                        0
#Define AE_DELETE	                        1
#Define AE_ADD		                        2

#Define AE_UAS_USER	                        0
#Define AE_UAS_GROUP	                    1
#Define AE_UAS_MODALS	                    2

#Define SVAUD_SERVICE                       01H
#Define SVAUD_GOODSESSLOGON                 06H
#Define SVAUD_BADSESSLOGON                  018H
#Define SVAUD_SESSLOGON                     (SVAUD_GOODSESSLOGON | SVAUD_BADSESSLOGON)
#Define SVAUD_GOODNETLOGON                  060H
#Define SVAUD_BADNETLOGON                   0180H
#Define SVAUD_NETLOGON                      (SVAUD_GOODNETLOGON | SVAUD_BADNETLOGON)
#Define SVAUD_LOGON                         (SVAUD_NETLOGON | SVAUD_SESSLOGON)
#Define SVAUD_GOODUSE                       0600H
#Define SVAUD_BADUSE                        01800H
#Define SVAUD_USE                           (SVAUD_GOODUSE | SVAUD_BADUSE)
#Define SVAUD_USERLIST                      02000H
#Define SVAUD_PERMISSIONS                   04000H
#Define SVAUD_RESOURCE                      08000H
#Define SVAUD_LOGONLIM		                000010000H

#Define AA_AUDIT_ALL	                    00001H
#Define AA_A_OWNER	                        00004H
#Define AA_CLOSE	                        00008H
#Define AA_S_OPEN	                        00010H
#Define AA_S_WRITE	                        00020H
#Define AA_S_CREATE	                        00020H
#Define AA_S_DELETE	                        00040H
#Define AA_S_ACL	                        00080H
#Define AA_S_ALL	                        (AA_S_OPEN | AA_S_WRITE | AA_S_DELETE | AA_S_ACL)
#Define AA_F_OPEN	                        00100H
#Define AA_F_WRITE	                        00200H
#Define AA_F_CREATE	                        00200H
#Define AA_F_DELETE	                        00400H
#Define AA_F_ACL	                        00800H
#Define AA_F_ALL	                        (AA_F_OPEN | AA_F_WRITE | AA_F_DELETE | AA_F_ACL)

#Define AA_A_OPEN	                        01000H
#Define AA_A_WRITE	                        02000H
#Define AA_A_CREATE	                        02000H
#Define AA_A_DELETE	                        04000H
#Define AA_A_ACL	                        08000H
#Define AA_A_ALL	                        (AA_F_OPEN | AA_F_WRITE | AA_F_DELETE | AA_F_ACL)

#ENDIF ;LMAUDIT_INC
