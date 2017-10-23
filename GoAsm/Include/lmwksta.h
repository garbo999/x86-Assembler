#ifndef LMWKSTA_H
#define LMWKSTA_H

/* NetWorkstation and NetWkstaTransport API definitions */

#IFNDEF LMCONS_H
	#include lmcons.h
#ENDIF

#IFNDEF LMUSEFLG_H
	#include lmuseflg.h
#ENDIF

#define WKSTA_PLATFORM_ID_PARMNUM  100
#define WKSTA_COMPUTERNAME_PARMNUM  1
#define WKSTA_LANGROUP_PARMNUM  2
#define WKSTA_VER_MAJOR_PARMNUM  4
#define WKSTA_VER_MINOR_PARMNUM  5
#define WKSTA_LOGGED_ON_USERS_PARMNUM  6
#define WKSTA_LANROOT_PARMNUM  7
#define WKSTA_LOGON_DOMAIN_PARMNUM  8
#define WKSTA_LOGON_SERVER_PARMNUM  9
#define WKSTA_CHARWAIT_PARMNUM  10
#define WKSTA_CHARTIME_PARMNUM  11
#define WKSTA_CHARCOUNT_PARMNUM  12
#define WKSTA_KEEPCONN_PARMNUM  13
#define WKSTA_KEEPSEARCH_PARMNUM  14
#define WKSTA_MAXCMDS_PARMNUM  15
#define WKSTA_NUMWORKBUF_PARMNUM  16
#define WKSTA_MAXWRKCACHE_PARMNUM  17
#define WKSTA_SESSTIMEOUT_PARMNUM  18
#define WKSTA_SIZERROR_PARMNUM  19
#define WKSTA_NUMALERTS_PARMNUM  20
#define WKSTA_NUMSERVICES_PARMNUM  21
#define WKSTA_NUMCHARBUF_PARMNUM  22
#define WKSTA_SIZCHARBUF_PARMNUM  23
#define WKSTA_ERRLOGSZ_PARMNUM  27
#define WKSTA_PRINTBUFTIME_PARMNUM  28
#define WKSTA_SIZWORKBUF_PARMNUM  29
#define WKSTA_MAILSLOTS_PARMNUM  30
#define WKSTA_NUMDGRAMBUF_PARMNUM  31
#define WKSTA_WRKHEURISTICS_PARMNUM  32
#define WKSTA_MAXTHREADS_PARMNUM  33
#define WKSTA_LOCKQUOTA_PARMNUM  41
#define WKSTA_LOCKINCREMENT_PARMNUM  42
#define WKSTA_LOCKMAXIMUM_PARMNUM  43
#define WKSTA_PIPEINCREMENT_PARMNUM  44
#define WKSTA_PIPEMAXIMUM_PARMNUM  45
#define WKSTA_DORMANTFILELIMIT_PARMNUM  46
#define WKSTA_CACHEFILETIMEOUT_PARMNUM  47
#define WKSTA_USEOPPORTUNISTICLOCKING_PARMNUM  48
#define WKSTA_USEUNLOCKBEHIND_PARMNUM  49
#define WKSTA_USECLOSEBEHIND_PARMNUM  50
#define WKSTA_BUFFERNAMEDPIPES_PARMNUM  51
#define WKSTA_USELOCKANDREADANDUNLOCK_PARMNUM  52
#define WKSTA_UTILIZENTCACHING_PARMNUM  53
#define WKSTA_USERAWREAD_PARMNUM  54
#define WKSTA_USERAWWRITE_PARMNUM  55
#define WKSTA_USEWRITERAWWITHDATA_PARMNUM  56
#define WKSTA_USEENCRYPTION_PARMNUM  57
#define WKSTA_BUFFILESWITHDENYWRITE_PARMNUM  58
#define WKSTA_BUFFERREADONLYFILES_PARMNUM  59
#define WKSTA_FORCECORECREATEMODE_PARMNUM  60
#define WKSTA_USE512BYTESMAXTRANSFER_PARMNUM  61
#define WKSTA_READAHEADTHRUPUT_PARMNUM  62
#define WKSTA_OTH_DOMAINS_PARMNUM  101

#define TRANSPORT_QUALITYOFSERVICE_PARMNUM  201
#define TRANSPORT_NAME_PARMNUM  202

WKSTA_INFO_100 STRUCT
	wki100_platform_id DD
	wki100_computername PTR
	wki100_langroup PTR
	wki100_ver_major DD
	wki100_ver_minor DD
ENDS

WKSTA_INFO_101 STRUCT
	wki101_platform_id DD
	wki101_computername PTR
	wki101_langroup PTR
	wki101_ver_major DD
	wki101_ver_minor DD
	wki101_lanroot PTR
ENDS

WKSTA_INFO_102 STRUCT
	wki102_platform_id DD
	wki102_computername PTR
	wki102_langroup PTR
	wki102_ver_major DD
	wki102_ver_minor DD
	wki102_lanroot PTR
	wki102_logged_on_users DD
ENDS

WKSTA_INFO_302 STRUCT
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
ENDS

WKSTA_INFO_402 STRUCT
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
ENDS

WKSTA_INFO_502STRUCT
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
ENDS

WKSTA_INFO_1010 STRUCT
	wki1010_char_wait DD
ENDS

WKSTA_INFO_1011 STRUCT
	wki1011_collection_time DD
ENDS

WKSTA_INFO_1012 STRUCT
	wki1012_maximum_collection_count DD
ENDS

WKSTA_INFO_1027 STRUCT
	wki1027_errlog_sz DD
ENDS

WKSTA_INFO_1028 STRUCT
	wki1028_print_buf_time DD
ENDS

WKSTA_INFO_1032 STRUCT
	wki1032_wrk_heuristics DD
ENDS

WKSTA_INFO_1013 STRUCT
	wki1013_keep_conn DD
ENDS

WKSTA_INFO_1018 STRUCT
	wki1018_sess_timeout DD
ENDS

WKSTA_INFO_1023 STRUCT
	wki1023_siz_char_buf DD
ENDS

WKSTA_INFO_1033 STRUCT
	wki1033_max_threads DD
ENDS

WKSTA_INFO_1041 STRUCT
	wki1041_lock_quota DD
ENDS

WKSTA_INFO_1042 STRUCT
	wki1042_lock_increment DD
ENDS

WKSTA_INFO_1043 STRUCT
	wki1043_lock_maximum DD
ENDS

WKSTA_INFO_1044 STRUCT
	wki1044_pipe_increment DD
ENDS

WKSTA_INFO_1045 STRUCT
	wki1045_pipe_maximum DD
ENDS

WKSTA_INFO_1046 STRUCT
	wki1046_dormant_file_limit DD
ENDS

WKSTA_INFO_1047 STRUCT
	wki1047_cache_file_timeout DD
ENDS

WKSTA_INFO_1048 STRUCT
	wki1048_use_opportunistic_locking DD
ENDS

WKSTA_INFO_1049 STRUCT
	wki1049_use_unlock_behind DD
ENDS

WKSTA_INFO_1050 STRUCT
	wki1050_use_close_behind DD
ENDS

WKSTA_INFO_1051 STRUCT
	wki1051_buf_named_pipes DD
ENDS

WKSTA_INFO_1052 STRUCT
	wki1052_use_lock_read_unlock DD
ENDS

WKSTA_INFO_1053 STRUCT
	wki1053_utilize_nt_caching DD
ENDS

WKSTA_INFO_1054 STRUCT
	wki1054_use_raw_read DD
ENDS

WKSTA_INFO_1055 STRUCT
	wki1055_use_raw_write DD
ENDS

WKSTA_INFO_1056 STRUCT
	wki1056_use_write_raw_data DD
ENDS

WKSTA_INFO_1057 STRUCT
	wki1057_use_encryption DD
ENDS

WKSTA_INFO_1058 STRUCT
	wki1058_buf_files_deny_write DD
ENDS

WKSTA_INFO_1059 STRUCT
	wki1059_buf_read_only_files DD
ENDS

WKSTA_INFO_1060 STRUCT
	wki1060_force_core_create_mode DD
ENDS

WKSTA_INFO_1061 STRUCT
	wki1061_use_512_byte_max_transfer DD
ENDS

WKSTA_INFO_1062 STRUCT
	wki1062_read_ahead_throughput DD
ENDS

WKSTA_USER_INFO_0 STRUCT
	wkui0_username DD
ENDS

WKSTA_USER_INFO_1 STRUCT
	wkui1_username DD
	wkui1_logon_domain DD
	wkui1_oth_domains DD
	wkui1_logon_server DD
ENDS

WKSTA_USER_INFO_1101 STRUCT
	wkui1101_oth_domains DD
ENDS

WKSTA_TRANSPORT_INFO_0 STRUCT
	wkti0_quality_of_service DD
	wkti0_number_of_vcs DD
	wkti0_transport_name DD
	wkti0_transport_address DD
	wkti0_wan_ish DD
ENDS

#endif /* _LMWKSTA_H */
