;=============================================================;
;          lmwksta.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMWKSTA_INC
#Define LMWKSTA_INC

#IFNDEF LMUSEFLG_INC
	#Include lmuseflg.inc
#ENDIF

WKSTA_INFO_100 Struct
	wki100_platform_id DD
	wki100_computername DD
	wki100_langroup DD
	wki100_ver_major DD
	wki100_ver_minor DD
EndS

WKSTA_INFO_101 Struct
	wki101_platform_id DD
	wki101_computername DD
	wki101_langroup DD
	wki101_ver_major DD
	wki101_ver_minor DD
	wki101_lanroot DD
EndS

WKSTA_INFO_102 Struct
	wki102_platform_id DD
	wki102_computername DD
	wki102_langroup DD
	wki102_ver_major DD
	wki102_ver_minor DD
	wki102_lanroot DD
	wki102_logged_on_users DD
EndS

WKSTA_INFO_302 Struct
	wki302_char_wait DD
	wki302_collection_time DD
	wki302_maximum_collection_count DD
	wki302_keep_conn DD
	wki302_keep_search DD
	wki302_max_cmds DD
	wki302_num_work_buf DD
	wki302_siz_work_buf DD
	wki302_max_wrk_cache DD
	wki302_sess_timeout DD
	wki302_siz_error DD
	wki302_num_alerts DD
	wki302_num_services DD
	wki302_errlog_sz DD
	wki302_print_buf_time DD
	wki302_num_char_buf DD
	wki302_siz_char_buf DD
	wki302_wrk_heuristics DD
	wki302_mailslots DD
	wki302_num_dgram_buf DD
EndS

WKSTA_INFO_402 Struct
	wki402_char_wait DD
	wki402_collection_time DD
	wki402_maximum_collection_count DD
	wki402_keep_conn DD
	wki402_keep_search DD
	wki402_max_cmds DD
	wki402_num_work_buf DD
	wki402_siz_work_buf DD
	wki402_max_wrk_cache DD
	wki402_sess_timeout DD
	wki402_siz_error DD
	wki402_num_alerts DD
	wki402_num_services DD
	wki402_errlog_sz DD
	wki402_print_buf_time DD
	wki402_num_char_buf DD
	wki402_siz_char_buf DD
	wki402_wrk_heuristics DD
	wki402_mailslots DD
	wki402_num_dgram_buf DD
	wki402_max_threads DD
EndS

WKSTA_INFO_502 Struct
	wki502_char_wait DD
	wki502_collection_time DD
	wki502_maximum_collection_count DD
	wki502_keep_conn DD
	wki502_max_cmds DD
	wki502_sess_timeout DD
	wki502_siz_char_buf DD
	wki502_max_threads DD
	wki502_lock_quota DD
	wki502_lock_increment DD
	wki502_lock_maximum DD
	wki502_pipe_increment DD
	wki502_pipe_maximum DD
	wki502_cache_file_timeout DD
	wki502_dormant_file_limit DD
	wki502_read_ahead_throughput DD
	wki502_num_mailslot_buffers DD
	wki502_num_srv_announce_buffers DD
	wki502_max_illegal_datagram_events DD
	wki502_illegal_datagram_event_reset_frequency DD
	wki502_log_election_packets DD
	wki502_use_opportunistic_locking DD
	wki502_use_unlock_behind DD
	wki502_use_close_behind DD
	wki502_buf_named_pipes DD
	wki502_use_lock_read_unlock DD
	wki502_utilize_nt_caching DD
	wki502_use_raw_read DD
	wki502_use_raw_write DD
	wki502_use_write_raw_data DD
	wki502_use_encryption DD
	wki502_buf_files_deny_write DD
	wki502_buf_read_only_files DD
	wki502_force_core_create_mode DD
	wki502_use_512_byte_max_transfer DD
EndS

WKSTA_INFO_1010 Struct
	wki1010_char_wait DD
EndS

WKSTA_INFO_1011 Struct
	wki1011_collection_time DD
EndS

WKSTA_INFO_1012 Struct
	wki1012_maximum_collection_count DD
EndS

WKSTA_INFO_1027 Struct
	wki1027_errlog_sz DD
EndS

WKSTA_INFO_1028 Struct
	wki1028_print_buf_time DD
EndS

WKSTA_INFO_1032 Struct
	wki1032_wrk_heuristics DD
EndS

WKSTA_INFO_1013 Struct
	wki1013_keep_conn DD
EndS

WKSTA_INFO_1018 Struct
	wki1018_sess_timeout DD
EndS

WKSTA_INFO_1023 Struct
	wki1023_siz_char_buf DD
EndS

WKSTA_INFO_1033 Struct
	wki1033_max_threads DD
EndS

WKSTA_INFO_1041 Struct
	wki1041_lock_quota DD
EndS

WKSTA_INFO_1042 Struct
	wki1042_lock_increment DD
EndS

WKSTA_INFO_1043 Struct
	wki1043_lock_maximum DD
EndS

WKSTA_INFO_1044 Struct
	wki1044_pipe_increment DD
EndS

WKSTA_INFO_1045 Struct
	wki1045_pipe_maximum DD
EndS

WKSTA_INFO_1046 Struct
	wki1046_dormant_file_limit DD
EndS

WKSTA_INFO_1047 Struct
	wki1047_cache_file_timeout DD
EndS

WKSTA_INFO_1048 Struct
	wki1048_use_opportunistic_locking DD
EndS

WKSTA_INFO_1049 Struct
	wki1049_use_unlock_behind DD
EndS

WKSTA_INFO_1050 Struct
	wki1050_use_close_behind DD
EndS

WKSTA_INFO_1051 Struct
	wki1051_buf_named_pipes DD
EndS

WKSTA_INFO_1052 Struct
	wki1052_use_lock_read_unlock DD
EndS

WKSTA_INFO_1053 Struct
	wki1053_utilize_nt_caching DD
EndS

WKSTA_INFO_1054 Struct
	wki1054_use_raw_read DD
EndS

WKSTA_INFO_1055 Struct
	wki1055_use_raw_write DD
EndS

WKSTA_INFO_1056 Struct
	wki1056_use_write_raw_data DD
EndS

WKSTA_INFO_1057 Struct
	wki1057_use_encryption DD
EndS

WKSTA_INFO_1058 Struct
	wki1058_buf_files_deny_write DD
EndS

WKSTA_INFO_1059 Struct
	wki1059_buf_read_only_files DD
EndS

WKSTA_INFO_1060 Struct
	wki1060_force_core_create_mode DD
EndS

WKSTA_INFO_1061 Struct
	wki1061_use_512_byte_max_transfer DD
EndS

WKSTA_INFO_1062 Struct
	wki1062_read_ahead_throughput DD
EndS

WKSTA_USER_INFO_0 Struct
	wkui0_username DD
EndS

WKSTA_USER_INFO_1 Struct
	wkui1_username DD
	wkui1_logon_domain DD
	wkui1_oth_domains DD
	wkui1_logon_server DD
EndS

WKSTA_USER_INFO_1101 Struct
	wkui1101_oth_domains DD
EndS

WKSTA_TRANSPORT_INFO_0 Struct
	wkti0_quality_of_service DD
	wkti0_number_of_vcs DD
	wkti0_transport_name DD
	wkti0_transport_address DD
	wkti0_wan_ish DD
EndS

#Define WKSTA_PLATFORM_ID_PARMNUM           100
#Define WKSTA_COMPUTERNAME_PARMNUM          1
#Define WKSTA_LANGROUP_PARMNUM              2
#Define WKSTA_VER_MAJOR_PARMNUM             4
#Define WKSTA_VER_MINOR_PARMNUM             5
#Define WKSTA_LOGGED_ON_USERS_PARMNUM       6
#Define WKSTA_LANROOT_PARMNUM               7
#Define WKSTA_LOGON_DOMAIN_PARMNUM          8
#Define WKSTA_LOGON_SERVER_PARMNUM          9
#Define WKSTA_CHARWAIT_PARMNUM              10
#Define WKSTA_CHARTIME_PARMNUM              11
#Define WKSTA_CHARCOUNT_PARMNUM             12
#Define WKSTA_KEEPCONN_PARMNUM              13
#Define WKSTA_KEEPSEARCH_PARMNUM            14
#Define WKSTA_MAXCMDS_PARMNUM               15
#Define WKSTA_NUMWORKBUF_PARMNUM            16
#Define WKSTA_MAXWRKCACHE_PARMNUM           17
#Define WKSTA_SESSTIMEOUT_PARMNUM           18
#Define WKSTA_SIZERROR_PARMNUM              19
#Define WKSTA_NUMALERTS_PARMNUM             20
#Define WKSTA_NUMSERVICES_PARMNUM           21
#Define WKSTA_NUMCHARBUF_PARMNUM            22
#Define WKSTA_SIZCHARBUF_PARMNUM            23
#Define WKSTA_ERRLOGSZ_PARMNUM              27
#Define WKSTA_PRINTBUFTIME_PARMNUM          28
#Define WKSTA_SIZWORKBUF_PARMNUM            29
#Define WKSTA_MAILSLOTS_PARMNUM             30
#Define WKSTA_NUMDGRAMBUF_PARMNUM           31
#Define WKSTA_WRKHEURISTICS_PARMNUM         32
#Define WKSTA_MAXTHREADS_PARMNUM            33

#Define WKSTA_LOCKQUOTA_PARMNUM             41
#Define WKSTA_LOCKINCREMENT_PARMNUM         42
#Define WKSTA_LOCKMAXIMUM_PARMNUM           43
#Define WKSTA_PIPEINCREMENT_PARMNUM         44
#Define WKSTA_PIPEMAXIMUM_PARMNUM           45
#Define WKSTA_DORMANTFILELIMIT_PARMNUM      46
#Define WKSTA_CACHEFILETIMEOUT_PARMNUM      47
#Define WKSTA_USEOPPORTUNISTICLOCKING_PARMNUM 48
#Define WKSTA_USEUNLOCKBEHIND_PARMNUM       49
#Define WKSTA_USECLOSEBEHIND_PARMNUM        50
#Define WKSTA_BUFFERNAMEDPIPES_PARMNUM      51
#Define WKSTA_USELOCKANDREADANDUNLOCK_PARMNUM 52
#Define WKSTA_UTILIZENTCACHING_PARMNUM      53
#Define WKSTA_USERAWREAD_PARMNUM            54
#Define WKSTA_USERAWWRITE_PARMNUM           55
#Define WKSTA_USEWRITERAWWITHDATA_PARMNUM   56
#Define WKSTA_USEENCRYPTION_PARMNUM         57
#Define WKSTA_BUFFILESWITHDENYWRITE_PARMNUM 58
#Define WKSTA_BUFFERREADONLYFILES_PARMNUM   59
#Define WKSTA_FORCECORECREATEMODE_PARMNUM   60
#Define WKSTA_USE512BYTESMAXTRANSFER_PARMNUM 61
#Define WKSTA_READAHEADTHRUPUT_PARMNUM      62

#Define WKSTA_OTH_DOMAINS_PARMNUM           101

#Define TRANSPORT_QUALITYOFSERVICE_PARMNUM  201
#Define TRANSPORT_NAME_PARMNUM              202

#ENDIF ;LMWKSTA_INC
