;=============================================================;
;         lmaccess.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMACCESS_INC
#Define LMACCESS_INC

#IFNDEF LMCONS_INC
	#Include lmcons.inc
#ENDIF

USER_INFO_0 Struct
	usri0_name DD
EndS

USER_INFO_1 Struct
	usri1_name DD
	usri1_password DD
	usri1_password_age DD
	usri1_priv DD
	usri1_home_dir DD
	usri1_comment DD
	usri1_flags DD
	usri1_script_path DD
EndS

USER_INFO_2 Struct
	usri2_name DD
	usri2_password DD
	usri2_password_age DD
	usri2_priv DD
	usri2_home_dir DD
	usri2_comment DD
	usri2_flags DD
	usri2_script_path DD
	usri2_auth_flags DD
	usri2_full_name DD
	usri2_usr_comment DD
	usri2_parms DD
	usri2_workstations DD
	usri2_last_logon DD
	usri2_last_logoff DD
	usri2_acct_expires DD
	usri2_max_storage DD
	usri2_units_per_week DD
	usri2_logon_hours DD
	usri2_bad_pw_count DD
	usri2_num_logons DD
	usri2_logon_server DD
	usri2_country_code DD
	usri2_code_page DD
EndS

USER_INFO_3 Struct
	usri3_name DD
	usri3_password DD
	usri3_password_age DD
	usri3_priv DD
	usri3_home_dir DD
	usri3_comment DD
	usri3_flags DD
	usri3_script_path DD
	usri3_auth_flags DD
	usri3_full_name DD
	usri3_usr_comment DD
	usri3_parms DD
	usri3_workstations DD
	usri3_last_logon DD
	usri3_last_logoff DD
	usri3_acct_expires DD
	usri3_max_storage DD
	usri3_units_per_week DD
	usri3_logon_hours DD
	usri3_bad_pw_count DD
	usri3_num_logons DD
	usri3_logon_server DD
	usri3_country_code DD
	usri3_code_page DD
	usri3_user_id DD
	usri3_primary_group_id DD
	usri3_profile DD
	usri3_home_dir_drive DD
	usri3_password_expired DD
EndS

USER_INFO_10 Struct
	usri10_name DD
	usri10_comment DD
	usri10_usr_comment DD
	usri10_full_name DD
EndS

USER_INFO_11 Struct
	usri11_name DD
	usri11_comment DD
	usri11_usr_comment DD
	usri11_full_name DD
	usri11_priv DD
	usri11_auth_flags DD
	usri11_password_age DD
	usri11_home_dir DD
	usri11_parms DD
	usri11_last_logon DD
	usri11_last_logoff DD
	usri11_bad_pw_count DD
	usri11_num_logons DD
	usri11_logon_server DD
	usri11_country_code DD
	usri11_workstations DD
	usri11_max_storage DD
	usri11_units_per_week DD
	usri11_logon_hours DD
	usri11_code_page DD
EndS

USER_INFO_20 Struct
	usri20_name DD
	usri20_full_name DD
	usri20_comment DD
	usri20_flags DD
	usri20_user_id DD
EndS

USER_INFO_21 Struct
    BYTE usri21_password[ENCRYPTED_PWLEN] DD
EndS

USER_INFO_22 Struct
	usri22_name DD
    BYTE usri22_password[ENCRYPTED_PWLEN] DD
	usri22_password_age DD
	usri22_priv DD
	usri22_home_dir DD
	usri22_comment DD
	usri22_flags DD
	usri22_script_path DD
	usri22_auth_flags DD
	usri22_full_name DD
	usri22_usr_comment DD
	usri22_parms DD
	usri22_workstations DD
	usri22_last_logon DD
	usri22_last_logoff DD
	usri22_acct_expires DD
	usri22_max_storage DD
	usri22_units_per_week DD
	usri22_logon_hours DD
	usri22_bad_pw_count DD
	usri22_num_logons DD
	usri22_logon_server DD
	usri22_country_code DD
	usri22_code_page DD
EndS

USER_INFO_1003 Struct
	usri1003_password DD
EndS

USER_INFO_1005 Struct
	usri1005_priv DD
EndS

USER_INFO_1006 Struct
	usri1006_home_dir DD
EndS

USER_INFO_1007 Struct
	usri1007_comment DD
EndS

USER_INFO_1008 Struct
	usri1008_flags DD
EndS

USER_INFO_1009 Struct
	usri1009_script_path DD
EndS

USER_INFO_1010 Struct
	usri1010_auth_flags DD
EndS

USER_INFO_1011 Struct
	usri1011_full_name DD
EndS

USER_INFO_1012 Struct
	usri1012_usr_comment DD
EndS

USER_INFO_1013 Struct
	usri1013_parms DD
EndS

USER_INFO_1014 Struct
	usri1014_workstations DD
EndS

USER_INFO_1017 Struct
	usri1017_acct_expires DD
EndS

USER_INFO_1018 Struct
	usri1018_max_storage DD
EndS

USER_INFO_1020 Struct
	usri1020_units_per_week DD
	usri1020_logon_hours DD
EndS

USER_INFO_1023 Struct
	usri1023_logon_server DD
EndS

USER_INFO_1024 Struct
	usri1024_country_code DD
EndS

USER_INFO_1025 Struct
	usri1025_code_page DD
EndS

USER_INFO_1051 Struct
	usri1051_primary_group_id DD
EndS

USER_INFO_1052 Struct
	usri1052_profile DD
EndS

USER_INFO_1053 Struct
	usri1053_home_dir_drive DD
EndS

USER_MODALS_INFO_0 Struct
	usrmod0_min_passwd_len DD
	usrmod0_max_passwd_age DD
	usrmod0_min_passwd_age DD
	usrmod0_force_logoff DD
	usrmod0_password_hist_len DD
EndS

USER_MODALS_INFO_1 Struct
	usrmod1_role DD
	usrmod1_primary DD
EndS

USER_MODALS_INFO_2 Struct
	usrmod2_domain_name DD
	usrmod2_domain_id DD
EndS

USER_MODALS_INFO_3 Struct
	usrmod3_lockout_duration DD
	usrmod3_lockout_observation_window DD
	usrmod3_lockout_threshold DD
EndS

USER_MODALS_INFO_1001 Struct
	usrmod1001_min_passwd_len DD
EndS

USER_MODALS_INFO_1002 Struct
	usrmod1002_max_passwd_age DD
EndS

USER_MODALS_INFO_1003 Struct
	usrmod1003_min_passwd_age DD
EndS

USER_MODALS_INFO_1004 Struct
	usrmod1004_force_logoff DD
EndS

USER_MODALS_INFO_1005 Struct
	usrmod1005_password_hist_len DD
EndS

USER_MODALS_INFO_1006 Struct
	usrmod1006_role DD
EndS

USER_MODALS_INFO_1007 Struct
	usrmod1007_primary DD
EndS

#Define UF_SCRIPT                           00001H
#Define UF_ACCOUNTDISABLE                   00002H
#Define UF_HOMEDIR_REQUIRED                 00008H
#Define UF_LOCKOUT                          00010H
#Define UF_PASSWD_NOTREQD                   00020H
#Define UF_PASSWD_CANT_CHANGE               00040H

#Define UF_TEMP_DUPLICATE_ACCOUNT           00100H
#Define UF_NORMAL_ACCOUNT                   00200H
#Define UF_INTERDOMAIN_TRUST_ACCOUNT        00800H
#Define UF_WORKSTATION_TRUST_ACCOUNT        01000H
#Define UF_SERVER_TRUST_ACCOUNT             02000H

#Define UF_MACHINE_ACCOUNT_MASK             (UF_INTERDOMAIN_TRUST_ACCOUNT | UF_WORKSTATION_TRUST_ACCOUNT | UF_SERVER_TRUST_ACCOUNT)

#Define UF_ACCOUNT_TYPE_MASK                (UF_TEMP_DUPLICATE_ACCOUNT | UF_NORMAL_ACCOUNT | UF_INTERDOMAIN_TRUST_ACCOUNT | UF_WORKSTATION_TRUST_ACCOUNT | UF_SERVER_TRUST_ACCOUNT)

#Define UF_DONT_EXPIRE_PASSWD               010000H
#Define UF_MNS_LOGON_ACCOUNT                020000H

#Define UF_SETTABLE_BITS                    (UF_SCRIPT | UF_ACCOUNTDISABLE | UF_LOCKOUT | UF_HOMEDIR_REQUIRED | UF_PASSWD_NOTREQD | UF_PASSWD_CANT_CHANGE | UF_ACCOUNT_TYPE_MASK | UF_DONT_EXPIRE_PASSWD | UF_MNS_LOGON_ACCOUNT)

#Define FILTER_TEMP_DUPLICATE_ACCOUNT       (00001H)
#Define FILTER_NORMAL_ACCOUNT               (00002H)
#Define FILTER_INTERDOMAIN_TRUST_ACCOUNT    (00008H)
#Define FILTER_WORKSTATION_TRUST_ACCOUNT    (00010H)
#Define FILTER_SERVER_TRUST_ACCOUNT         (00020H)

#Define LG_INCLUDE_INDIRECT                 (00001H)

#Define AF_OP_PRINT                         01H
#Define AF_OP_COMM                          02H
#Define AF_OP_SERVER                        04H
#Define AF_OP_ACCOUNTS                      08H
#Define AF_SETTABLE_BITS                    (AF_OP_PRINT | AF_OP_COMM | AF_OP_SERVER | AF_OP_ACCOUNTS)

#Define UAS_ROLE_STANDALONE                 0
#Define UAS_ROLE_MEMBER                     1
#Define UAS_ROLE_BACKUP                     2
#Define UAS_ROLE_PRIMARY                    3

#Define USER_NAME_PARMNUM                   1
#Define USER_PASSWORD_PARMNUM               3
#Define USER_PASSWORD_AGE_PARMNUM           4
#Define USER_PRIV_PARMNUM                   5
#Define USER_HOME_DIR_PARMNUM               6
#Define USER_COMMENT_PARMNUM                7
#Define USER_FLAGS_PARMNUM                  8
#Define USER_SCRIPT_PATH_PARMNUM            9
#Define USER_AUTH_FLAGS_PARMNUM             10
#Define USER_FULL_NAME_PARMNUM              11
#Define USER_USR_COMMENT_PARMNUM            12
#Define USER_PARMS_PARMNUM                  13
#Define USER_WORKSTATIONS_PARMNUM           14
#Define USER_LAST_LOGON_PARMNUM             15
#Define USER_LAST_LOGOFF_PARMNUM            16
#Define USER_ACCT_EXPIRES_PARMNUM           17
#Define USER_MAX_STORAGE_PARMNUM            18
#Define USER_UNITS_PER_WEEK_PARMNUM         19
#Define USER_LOGON_HOURS_PARMNUM            20
#Define USER_PAD_PW_COUNT_PARMNUM           21
#Define USER_NUM_LOGONS_PARMNUM             22
#Define USER_LOGON_SERVER_PARMNUM           23
#Define USER_COUNTRY_CODE_PARMNUM           24
#Define USER_CODE_PAGE_PARMNUM              25
#Define USER_PRIMARY_GROUP_PARMNUM          51
#Define USER_PROFILE                        52
#Define USER_PROFILE_PARMNUM                52
#Define USER_HOME_DIR_DRIVE_PARMNUM         53

#Define USER_NAME_INFOLEVEL                 (PARMNUM_BASE_INFOLEVEL + USER_NAME_PARMNUM)
#Define USER_PASSWORD_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + USER_PASSWORD_PARMNUM)
#Define USER_PASSWORD_AGE_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + USER_PASSWORD_AGE_PARMNUM)
#Define USER_PRIV_INFOLEVEL                 (PARMNUM_BASE_INFOLEVEL + USER_PRIV_PARMNUM)
#Define USER_HOME_DIR_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + USER_HOME_DIR_PARMNUM)
#Define USER_COMMENT_INFOLEVEL              (PARMNUM_BASE_INFOLEVEL + USER_COMMENT_PARMNUM)
#Define USER_FLAGS_INFOLEVEL                (PARMNUM_BASE_INFOLEVEL + USER_FLAGS_PARMNUM)
#Define USER_SCRIPT_PATH_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + USER_SCRIPT_PATH_PARMNUM)
#Define USER_AUTH_FLAGS_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + USER_AUTH_FLAGS_PARMNUM)
#Define USER_FULL_NAME_INFOLEVEL            (PARMNUM_BASE_INFOLEVEL + USER_FULL_NAME_PARMNUM)
#Define USER_USR_COMMENT_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + USER_USR_COMMENT_PARMNUM)
#Define USER_PARMS_INFOLEVEL                (PARMNUM_BASE_INFOLEVEL + USER_PARMS_PARMNUM)
#Define USER_WORKSTATIONS_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + USER_WORKSTATIONS_PARMNUM)
#Define USER_LAST_LOGON_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + USER_LAST_LOGON_PARMNUM)
#Define USER_LAST_LOGOFF_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + USER_LAST_LOGOFF_PARMNUM)
#Define USER_ACCT_EXPIRES_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + USER_ACCT_EXPIRES_PARMNUM)
#Define USER_MAX_STORAGE_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + USER_MAX_STORAGE_PARMNUM)
#Define USER_UNITS_PER_WEEK_INFOLEVEL       (PARMNUM_BASE_INFOLEVEL + USER_UNITS_PER_WEEK_PARMNUM)
#Define USER_LOGON_HOURS_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + USER_LOGON_HOURS_PARMNUM)
#Define USER_PAD_PW_COUNT_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + USER_PAD_PW_COUNT_PARMNUM)
#Define USER_NUM_LOGONS_INFOLEVEL           (PARMNUM_BASE_INFOLEVEL + USER_NUM_LOGONS_PARMNUM)
#Define USER_LOGON_SERVER_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + USER_LOGON_SERVER_PARMNUM)
#Define USER_COUNTRY_CODE_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + USER_COUNTRY_CODE_PARMNUM)
#Define USER_CODE_PAGE_INFOLEVEL            (PARMNUM_BASE_INFOLEVEL + USER_CODE_PAGE_PARMNUM)
#Define USER_PRIMARY_GROUP_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + USER_PRIMARY_GROUP_PARMNUM)
#Define USER_POSIX_ID_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + USER_POSIX_ID_PARMNUM)
#Define USER_HOME_DIR_DRIVE_INFOLEVEL       (PARMNUM_BASE_INFOLEVEL + USER_HOME_DIR_DRIVE_PARMNUM)

#Define NULL_USERSETINFO_PASSWD             "              "

#Define TIMEQ_FOREVER                       (-1)
#Define USER_MAXSTORAGE_UNLIMITED           (-1)
#Define USER_NO_LOGOFF                      (-1)
#Define UNITS_PER_DAY                       24
#Define UNITS_PER_WEEK                      UNITS_PER_DAY * 7

#Define USER_PRIV_MASK                      03H
#Define USER_PRIV_GUEST                     0
#Define USER_PRIV_USER                      1
#Define USER_PRIV_ADMIN                     2

#Define MAX_PASSWD_LEN                      PWLEN
#Define DEF_MIN_PWLEN                       6
#Define DEF_PWUNIQUENESS                    5
#Define DEF_MAX_PWHIST                      8

#Define DEF_MAX_PWAGE                       TIMEQ_FOREVER
#Define DEF_MIN_PWAGE                       0
#Define DEF_FORCE_LOGOFF                    0FFFFFFFFH
#Define DEF_MAX_BADPW                       0
#Define ONE_DAY                             01 * 24 * 3600

#Define VALIDATED_LOGON                     0
#Define PASSWORD_EXPIRED                    2
#Define NON_VALIDATED_LOGON                 3

#Define VALID_LOGOFF                        1

#define MODALS_MIN_PASSWD_LEN_PARMNUM       1
#define MODALS_MAX_PASSWD_AGE_PARMNUM       2
#define MODALS_MIN_PASSWD_AGE_PARMNUM       3
#define MODALS_FORCE_LOGOFF_PARMNUM         4
#Define MODALS_PASSWD_HIST_LEN_PARMNUM      5
#define MODALS_ROLE_PARMNUM                 6
#define MODALS_PRIMARY_PARMNUM              7
#define MODALS_DOMAIN_NAME_PARMNUM          8
#define MODALS_DOMAIN_ID_PARMNUM            9
#define MODALS_LOCKOUT_DURATION_PARMNUM     10
#define MODALS_LOCKOUT_OBSERVATION_WINDOW_PARMNUM 11
#define MODALS_LOCKOUT_THRESHOLD_PARMNUM    12

#Define MODALS_MIN_PASSWD_LEN_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + MODALS_MIN_PASSWD_LEN_PARMNUM)
#Define MODALS_MAX_PASSWD_AGE_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + MODALS_MAX_PASSWD_AGE_PARMNUM)
#Define MODALS_MIN_PASSWD_AGE_INFOLEVEL     (PARMNUM_BASE_INFOLEVEL + MODALS_MIN_PASSWD_AGE_PARMNUM)
#Define MODALS_FORCE_LOGOFF_INFOLEVEL       (PARMNUM_BASE_INFOLEVEL + MODALS_FORCE_LOGOFF_PARMNUM)
#Define MODALS_PASSWD_HIST_LEN_INFOLEVEL    (PARMNUM_BASE_INFOLEVEL + MODALS_PASSWD_HIST_LEN_PARMNUM)
#Define MODALS_ROLE_INFOLEVEL               (PARMNUM_BASE_INFOLEVEL + MODALS_ROLE_PARMNUM)
#Define MODALS_PRIMARY_INFOLEVEL            (PARMNUM_BASE_INFOLEVEL + MODALS_PRIMARY_PARMNUM)
#Define MODALS_DOMAIN_NAME_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + MODALS_DOMAIN_NAME_PARMNUM)
#Define MODALS_DOMAIN_ID_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + MODALS_DOMAIN_ID_PARMNUM)

GROUP_INFO_0 Struct
	grpi0_name DD
EndS

GROUP_INFO_1 Struct
	grpi1_name DD
	grpi1_comment DD
EndS

GROUP_INFO_2 Struct
	grpi2_name DD
	grpi2_comment DD
	grpi2_group_id DD
	grpi2_attributes DD
EndS

GROUP_INFO_1002 Struct
	grpi1002_comment DD
EndS

GROUP_INFO_1005 Struct
	grpi1005_attributes DD
EndS

GROUP_USERS_INFO_0 Struct
	grui0_name DD
EndS

GROUP_USERS_INFO_1 Struct
	grui1_name DD
	grui1_attributes DD
EndS

#Define GROUPIDMASK                         08000H

#Define GROUP_SPECIALGRP_USERS              L"USERS"
#Define GROUP_SPECIALGRP_ADMINS             L"ADMINS"
#Define GROUP_SPECIALGRP_GUESTS             L"GUESTS"
#Define GROUP_SPECIALGRP_LOCAL              L"LOCAL"

#Define GROUP_ALL_PARMNUM                   0
#Define GROUP_NAME_PARMNUM                  1
#Define GROUP_COMMENT_PARMNUM               2
#Define GROUP_ATTRIBUTES_PARMNUM            3

#Define GROUP_ALL_INFOLEVEL                 (PARMNUM_BASE_INFOLEVEL + GROUP_ALL_PARMNUM)
#Define GROUP_NAME_INFOLEVEL                (PARMNUM_BASE_INFOLEVEL + GROUP_NAME_PARMNUM)
#Define GROUP_COMMENT_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + GROUP_COMMENT_PARMNUM)
#Define GROUP_ATTRIBUTES_INFOLEVEL          (PARMNUM_BASE_INFOLEVEL + GROUP_ATTRIBUTES_PARMNUM)
#Define GROUP_POSIX_ID_INFOLEVEL            (PARMNUM_BASE_INFOLEVEL + GROUP_POSIX_ID_PARMNUM)

LOCALGROUP_INFO_0 Struct
	lgrpi0_name DD
EndS

LOCALGROUP_INFO_1 Struct
	lgrpi1_name DD
	lgrpi1_comment DD
EndS

LOCALGROUP_INFO_1002 Struct
	lgrpi1002_comment DD
EndS

LOCALGROUP_MEMBERS_INFO_0 Struct
	lgrmi0_sid DD
EndS

LOCALGROUP_MEMBERS_INFO_1 Struct
	lgrmi1_sid DD
	lgrmi1_sidusage SID_NAME_USE <>
	lgrmi1_name DD
EndS

LOCALGROUP_MEMBERS_INFO_2 Struct
	lgrmi2_sid DD
	lgrmi2_sidusage SID_NAME_USE <>
	lgrmi2_domainandname DD
EndS

LOCALGROUP_MEMBERS_INFO_3 Struct
	lgrmi3_domainandname DD
EndS

LOCALGROUP_USERS_INFO_0 Struct
	lgrui0_name DD
EndS

#Define LOCALGROUP_NAME_PARMNUM             1
#Define LOCALGROUP_COMMENT_PARMNUM          2

NET_DISPLAY_USER Struct
	usri1_name DD
	usri1_comment DD
	usri1_flags DD
	usri1_full_name DD
	usri1_user_id DD
	usri1_next_index DD
EndS

NET_DISPLAY_MACHINE Struct
	usri2_name DD
	usri2_comment DD
	usri2_flags DD
	usri2_user_id DD
	usri2_next_index DD
EndS

NET_DISPLAY_GROUP Struct
	grpi3_name DD
	grpi3_comment DD
	grpi3_group_id DD
	grpi3_attributes DD
	grpi3_next_index DD
EndS

#Define NetAccessAdd                        RxNetAccessAdd
#Define NetAccessEnum                       RxNetAccessEnum
#Define NetAccessGetInfo                    RxNetAccessGetInfo
#Define NetAccessSetInfo                    RxNetAccessSetInfo
#Define NetAccessDel                        RxNetAccessDel
#Define NetAccessGetUserPerms               RxNetAccessGetUserPerms

ACCESS_INFO_0 Struct
	acc0_resource_name DD
EndS

ACCESS_INFO_1 Struct
	acc1_resource_name DD
	acc1_attr DD
	acc1_count DD
EndS

ACCESS_INFO_1002 Struct
	acc1002_attr DD
EndS

ACCESS_LIST Struct
	acl_ugname DD
	acl_access DD
EndS

#Define MAXPERMENTRIES                      64
#Define ACCESS_NONE                         0
#Define ACCESS_ALL                          (ACCESS_READ | ACCESS_WRITE | ACCESS_CREATE | ACCESS_EXEC | ACCESS_DELETE | ACCESS_ATRIB | ACCESS_PERM)

#Define ACCESS_READ                         001H
#Define ACCESS_WRITE                        002H
#Define ACCESS_CREATE                       004H
#Define ACCESS_EXEC                         008H
#Define ACCESS_DELETE                       010H
#Define ACCESS_ATRIB                        020H
#Define ACCESS_PERM                         040H

#Define ACCESS_GROUP                        08000H

#Define ACCESS_AUDIT                        01H

#Define ACCESS_SUCCESS_OPEN                 010H
#Define ACCESS_SUCCESS_WRITE                020H
#Define ACCESS_SUCCESS_DELETE               040H
#Define ACCESS_SUCCESS_ACL                  080H
#Define ACCESS_SUCCESS_MASK                 0F0H

#Define ACCESS_FAIL_OPEN                    0100H
#Define ACCESS_FAIL_WRITE                   0200H
#Define ACCESS_FAIL_DELETE                  0400H
#Define ACCESS_FAIL_ACL                     0800H
#Define ACCESS_FAIL_MASK                    0F00H

#Define ACCESS_FAIL_SHIFT                   4

#Define ACCESS_RESOURCE_NAME_PARMNUM        1
#Define ACCESS_ATTR_PARMNUM                 2
#Define ACCESS_COUNT_PARMNUM                3
#Define ACCESS_ACCESS_LIST_PARMNUM          4

#Define ACCESS_RESOURCE_NAME_INFOLEVEL      (PARMNUM_BASE_INFOLEVEL + ACCESS_RESOURCE_NAME_PARMNUM)
#Define ACCESS_ATTR_INFOLEVEL               (PARMNUM_BASE_INFOLEVEL + ACCESS_ATTR_PARMNUM)
#Define ACCESS_COUNT_INFOLEVEL              (PARMNUM_BASE_INFOLEVEL + ACCESS_COUNT_PARMNUM)
#Define ACCESS_ACCESS_LIST_INFOLEVEL        (PARMNUM_BASE_INFOLEVEL + ACCESS_ACCESS_LIST_PARMNUM)

#Define ACCESS_LETTERS                      "RWCXDAP         "

#Define NETLOGON_CONTROL_QUERY              1
#Define NETLOGON_CONTROL_REPLICATE          2
#Define NETLOGON_CONTROL_SYNCHRONIZE        3
#Define NETLOGON_CONTROL_PDC_REPLICATE      4
#Define NETLOGON_CONTROL_REDISCOVER         5
#Define NETLOGON_CONTROL_TC_QUERY           6
#Define NETLOGON_CONTROL_TRANSPORT_NOTIFY   7
#Define NETLOGON_CONTROL_FIND_USER          8

#Define NETLOGON_CONTROL_UNLOAD_NETLOGON_DLL 0FFFBH
#Define NETLOGON_CONTROL_BACKUP_CHANGE_LOG  0FFFCH
#Define NETLOGON_CONTROL_TRUNCATE_LOG       0FFFDH
#Define NETLOGON_CONTROL_SET_DBFLAG         0FFFEH
#Define NETLOGON_CONTROL_BREAKPOINT         0FFFFH

NETLOGON_INFO_1 Struct
	netlog1_flags DD
	netlog1_pdc_connection_status DD
EndS

NETLOGON_INFO_2 Struct
	netlog2_flags DD
	netlog2_pdc_connection_status
	netlog2_trusted_dc_name DD
	netlog2_tc_connection_status
EndS

NETLOGON_INFO_3 Struct
	netlog3_flags DD
	netlog3_logon_attempts DD
	netlog3_reserved1 DD
	netlog3_reserved2 DD
	netlog3_reserved3 DD
	netlog3_reserved4 DD
	netlog3_reserved5 DD
EndS

NETLOGON_INFO_4 Struct
	netlog4_trusted_dc_name DD
	netlog4_trusted_domain_name DD
EndS

#Define NETLOGON_REPLICATION_NEEDED         001H
#Define NETLOGON_REPLICATION_IN_PROGRESS    002H
#Define NETLOGON_FULL_SYNC_REPLICATION      004H
#Define NETLOGON_REDO_NEEDED                008H

#ENDIF ;LMACCESS_INC
