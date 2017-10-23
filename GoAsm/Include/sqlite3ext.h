/*
** 2006 June 7
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
*/
#ifndef SQLITE3EXT_H
#define SQLITE3EXT_H

#IFNDEF SQLITE3_H
	#include "sqlite3.h"
#ENDIF

/*
The following redefinitions are for use with a static lib version of sqlite
To use them you must define SQLITELIB with the path of the static library file
for example
#define SQLITELIB C:\MyLibs\libsqlite3.lib

There is no need to use this file if you are using the DLL version of sqlite3
the API is automatically imported by defining LINKFILES.

Including this file will disable the importation of the functions from the DLL
version of sqlite3.
*/

#IFNDEF SQLITELIB
	// If you do not define SQLITELIB it will default to the current folder
	#DEFINE SQLITELIB libsqlite3.lib
#ENDIF

#ifndef SQLITE_CORE
	#ifndef SQLITE_OMIT_DEPRECATED
		#define sqlite3_aggregate_count    SQLITELIB:sqlite3_aggregate_count
		#define sqlite3_global_recover     SQLITELIB:sqlite3_global_recover
		#define sqlite3_expired            SQLITELIB:sqlite3_expired
		#define sqlite3_transfer_bindings  SQLITELIB:sqlite3_transfer_bindings
	#endif

	#define sqlite3_aggregate_context      SQLITELIB:sqlite3_aggregate_context
	#define sqlite3_bind_blob              SQLITELIB:sqlite3_bind_blob
	#define sqlite3_bind_double            SQLITELIB:sqlite3_bind_double
	#define sqlite3_bind_int               SQLITELIB:sqlite3_bind_int
	#define sqlite3_bind_int64             SQLITELIB:sqlite3_bind_int64
	#define sqlite3_bind_null              SQLITELIB:sqlite3_bind_null
	#define sqlite3_bind_parameter_count   SQLITELIB:sqlite3_bind_parameter_count
	#define sqlite3_bind_parameter_index   SQLITELIB:sqlite3_bind_parameter_index
	#define sqlite3_bind_parameter_name    SQLITELIB:sqlite3_bind_parameter_name
	#define sqlite3_bind_text              SQLITELIB:sqlite3_bind_text
	#define sqlite3_bind_text16            SQLITELIB:sqlite3_bind_text16
	#define sqlite3_bind_value             SQLITELIB:sqlite3_bind_value
	#define sqlite3_busy_handler           SQLITELIB:sqlite3_busy_handler
	#define sqlite3_busy_timeout           SQLITELIB:sqlite3_busy_timeout
	#define sqlite3_changes                SQLITELIB:sqlite3_changes
	#define sqlite3_close                  SQLITELIB:sqlite3_close
	#define sqlite3_collation_needed       SQLITELIB:sqlite3_collation_needed
	#define sqlite3_collation_needed16     SQLITELIB:sqlite3_collation_needed16
	#define sqlite3_column_blob            SQLITELIB:sqlite3_column_blob
	#define sqlite3_column_bytes           SQLITELIB:sqlite3_column_bytes
	#define sqlite3_column_bytes16         SQLITELIB:sqlite3_column_bytes16
	#define sqlite3_column_count           SQLITELIB:sqlite3_column_count
	#define sqlite3_column_database_name   SQLITELIB:sqlite3_column_database_name
	#define sqlite3_column_database_name16 SQLITELIB:sqlite3_column_database_name16
	#define sqlite3_column_decltype        SQLITELIB:sqlite3_column_decltype
	#define sqlite3_column_decltype16      SQLITELIB:sqlite3_column_decltype16
	#define sqlite3_column_double          SQLITELIB:sqlite3_column_double
	#define sqlite3_column_int             SQLITELIB:sqlite3_column_int
	#define sqlite3_column_int64           SQLITELIB:sqlite3_column_int64
	#define sqlite3_column_name            SQLITELIB:sqlite3_column_name
	#define sqlite3_column_name16          SQLITELIB:sqlite3_column_name16
	#define sqlite3_column_origin_name     SQLITELIB:sqlite3_column_origin_name
	#define sqlite3_column_origin_name16   SQLITELIB:sqlite3_column_origin_name16
	#define sqlite3_column_table_name      SQLITELIB:sqlite3_column_table_name
	#define sqlite3_column_table_name16    SQLITELIB:sqlite3_column_table_name16
	#define sqlite3_column_text            SQLITELIB:sqlite3_column_text
	#define sqlite3_column_text16          SQLITELIB:sqlite3_column_text16
	#define sqlite3_column_type            SQLITELIB:sqlite3_column_type
	#define sqlite3_column_value           SQLITELIB:sqlite3_column_value
	#define sqlite3_commit_hook            SQLITELIB:sqlite3_commit_hook
	#define sqlite3_complete               SQLITELIB:sqlite3_complete
	#define sqlite3_complete16             SQLITELIB:sqlite3_complete16
	#define sqlite3_create_collation       SQLITELIB:sqlite3_create_collation
	#define sqlite3_create_collation16     SQLITELIB:sqlite3_create_collation16
	#define sqlite3_create_function        SQLITELIB:sqlite3_create_function
	#define sqlite3_create_function16      SQLITELIB:sqlite3_create_function16
	#define sqlite3_create_module          SQLITELIB:sqlite3_create_module
	#define sqlite3_create_module_v2       SQLITELIB:sqlite3_create_module_v2
	#define sqlite3_data_count             SQLITELIB:sqlite3_data_count
	#define sqlite3_db_handle              SQLITELIB:sqlite3_db_handle
	#define sqlite3_declare_vtab           SQLITELIB:sqlite3_declare_vtab
	#define sqlite3_enable_shared_cache    SQLITELIB:sqlite3_enable_shared_cache
	#define sqlite3_errcode                SQLITELIB:sqlite3_errcode
	#define sqlite3_errmsg                 SQLITELIB:sqlite3_errmsg
	#define sqlite3_errmsg16               SQLITELIB:sqlite3_errmsg16
	#define sqlite3_exec                   SQLITELIB:sqlite3_exec
	#define sqlite3_finalize               SQLITELIB:sqlite3_finalize
	#define sqlite3_free                   SQLITELIB:sqlite3_free
	#define sqlite3_free_table             SQLITELIB:sqlite3_free_table
	#define sqlite3_get_autocommit         SQLITELIB:sqlite3_get_autocommit
	#define sqlite3_get_auxdata            SQLITELIB:sqlite3_get_auxdata
	#define sqlite3_get_table              SQLITELIB:sqlite3_get_table
	#define sqlite3_interrupt              SQLITELIB:sqlite3_interruptx
	#define sqlite3_last_insert_rowid      SQLITELIB:sqlite3_last_insert_rowid
	#define sqlite3_libversion             SQLITELIB:sqlite3_libversion
	#define sqlite3_libversion_number      SQLITELIB:sqlite3_libversion_number
	#define sqlite3_malloc                 SQLITELIB:sqlite3_malloc
	#define sqlite3_mprintf                SQLITELIB:sqlite3_mprintf
	#define sqlite3_open                   SQLITELIB:sqlite3_open
	#define sqlite3_open16                 SQLITELIB:sqlite3_open16
	#define sqlite3_prepare                SQLITELIB:sqlite3_prepare
	#define sqlite3_prepare16              SQLITELIB:sqlite3_prepare16
	#define sqlite3_prepare_v2             SQLITELIB:sqlite3_prepare_v2
	#define sqlite3_prepare16_v2           SQLITELIB:sqlite3_prepare16_v2
	#define sqlite3_profile                SQLITELIB:sqlite3_profile
	#define sqlite3_progress_handler       SQLITELIB:sqlite3_progress_handler
	#define sqlite3_realloc                SQLITELIB:sqlite3_realloc
	#define sqlite3_reset                  SQLITELIB:sqlite3_reset
	#define sqlite3_result_blob            SQLITELIB:sqlite3_result_blob
	#define sqlite3_result_double          SQLITELIB:sqlite3_result_double
	#define sqlite3_result_error           SQLITELIB:sqlite3_result_error
	#define sqlite3_result_error16         SQLITELIB:sqlite3_result_error16
	#define sqlite3_result_int             SQLITELIB:sqlite3_result_int
	#define sqlite3_result_int64           SQLITELIB:sqlite3_result_int64
	#define sqlite3_result_null            SQLITELIB:sqlite3_result_null
	#define sqlite3_result_text            SQLITELIB:sqlite3_result_text
	#define sqlite3_result_text16          SQLITELIB:sqlite3_result_text16
	#define sqlite3_result_text16be        SQLITELIB:sqlite3_result_text16be
	#define sqlite3_result_text16le        SQLITELIB:sqlite3_result_text16le
	#define sqlite3_result_value           SQLITELIB:sqlite3_result_value
	#define sqlite3_rollback_hook          SQLITELIB:sqlite3_rollback_hook
	#define sqlite3_set_authorizer         SQLITELIB:sqlite3_set_authorizer
	#define sqlite3_set_auxdata            SQLITELIB:sqlite3_set_auxdata
	#define sqlite3_snprintf               SQLITELIB:sqlite3_snprintf
	#define sqlite3_step                   SQLITELIB:sqlite3_step
	#define sqlite3_table_column_metadata  SQLITELIB:sqlite3_table_column_metadata
	#define sqlite3_thread_cleanup         SQLITELIB:sqlite3_thread_cleanup
	#define sqlite3_total_changes          SQLITELIB:sqlite3_total_changes
	#define sqlite3_trace                  SQLITELIB:sqlite3_trace
	#define sqlite3_update_hook            SQLITELIB:sqlite3_update_hook
	#define sqlite3_user_data              SQLITELIB:sqlite3_user_data
	#define sqlite3_value_blob             SQLITELIB:sqlite3_value_blob
	#define sqlite3_value_bytes            SQLITELIB:sqlite3_value_bytes
	#define sqlite3_value_bytes16          SQLITELIB:sqlite3_value_bytes16
	#define sqlite3_value_double           SQLITELIB:sqlite3_value_double
	#define sqlite3_value_int              SQLITELIB:sqlite3_value_int
	#define sqlite3_value_int64            SQLITELIB:sqlite3_value_int64
	#define sqlite3_value_numeric_type     SQLITELIB:sqlite3_value_numeric_type
	#define sqlite3_value_text             SQLITELIB:sqlite3_value_text
	#define sqlite3_value_text16           SQLITELIB:sqlite3_value_text16
	#define sqlite3_value_text16be         SQLITELIB:sqlite3_value_text16be
	#define sqlite3_value_text16le         SQLITELIB:sqlite3_value_text16le
	#define sqlite3_value_type             SQLITELIB:sqlite3_value_type
	#define sqlite3_vmprintf               SQLITELIB:sqlite3_vmprintf
	#define sqlite3_overload_function      SQLITELIB:sqlite3_overload_function
	#define sqlite3_prepare_v2             SQLITELIB:sqlite3_prepare_v2
	#define sqlite3_prepare16_v2           SQLITELIB:sqlite3_prepare16_v2
	#define sqlite3_clear_bindings         SQLITELIB:sqlite3_clear_bindings
	#define sqlite3_bind_zeroblob          SQLITELIB:sqlite3_bind_zeroblob
	#define sqlite3_blob_bytes             SQLITELIB:sqlite3_blob_bytes
	#define sqlite3_blob_close             SQLITELIB:sqlite3_blob_close
	#define sqlite3_blob_open              SQLITELIB:sqlite3_blob_open
	#define sqlite3_blob_read              SQLITELIB:sqlite3_blob_read
	#define sqlite3_blob_write             SQLITELIB:sqlite3_blob_write
	#define sqlite3_create_collation_v2    SQLITELIB:sqlite3_create_collation_v2
	#define sqlite3_file_control           SQLITELIB:sqlite3_file_control
	#define sqlite3_memory_highwater       SQLITELIB:sqlite3_memory_highwater
	#define sqlite3_memory_used            SQLITELIB:sqlite3_memory_used
	#define sqlite3_mutex_alloc            SQLITELIB:sqlite3_mutex_alloc
	#define sqlite3_mutex_enter            SQLITELIB:sqlite3_mutex_enter
	#define sqlite3_mutex_free             SQLITELIB:sqlite3_mutex_free
	#define sqlite3_mutex_leave            SQLITELIB:sqlite3_mutex_leave
	#define sqlite3_mutex_try              SQLITELIB:sqlite3_mutex_try
	#define sqlite3_open_v2                SQLITELIB:sqlite3_open_v2
	#define sqlite3_release_memory         SQLITELIB:sqlite3_release_memory
	#define sqlite3_result_error_nomem     SQLITELIB:sqlite3_result_error_nomem
	#define sqlite3_result_error_toobig    SQLITELIB:sqlite3_result_error_toobig
	#define sqlite3_sleep                  SQLITELIB:sqlite3_sleep
	#define sqlite3_soft_heap_limit        SQLITELIB:sqlite3_soft_heap_limit
	#define sqlite3_vfs_find               SQLITELIB:sqlite3_vfs_find
	#define sqlite3_vfs_register           SQLITELIB:sqlite3_vfs_register
	#define sqlite3_vfs_unregister         SQLITELIB:sqlite3_vfs_unregister
	#define sqlite3_threadsafe             SQLITELIB:sqlite3_xthreadsafe
	#define sqlite3_result_zeroblob        SQLITELIB:sqlite3_result_zeroblob
	#define sqlite3_result_error_code      SQLITELIB:sqlite3_result_error_code
	#define sqlite3_test_control           SQLITELIB:sqlite3_test_control
	#define sqlite3_randomness             SQLITELIB:sqlite3_randomness
	#define sqlite3_context_db_handle      SQLITELIB:sqlite3_context_db_handle
	#define sqlite3_extended_result_codes  SQLITELIB:sqlite3_extended_result_codes
	#define sqlite3_limit                  SQLITELIB:sqlite3_limit
	#define sqlite3_next_stmt              SQLITELIB:sqlite3_next_stmt
	#define sqlite3_sql                    SQLITELIB:sqlite3_sql
	#define sqlite3_status                 SQLITELIB:sqlite3_status
#endif

#endif
