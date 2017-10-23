/*
** 2010 August 30
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
#ifndef SQLITE3_H
#define SQLITE3_H

#IFDEF LINKFILES
	#IFNDEF SQLITE3EXT_H
		#dynamiclinkfile sqlite3.dll
	#ENDIF
#ENDIF

#define SQLITE_VERSION        "3.7.3"
#define SQLITE_VERSION_NUMBER 3007003
#define SQLITE_SOURCE_ID      "2010-10-08 02:34:02 2677848087c9c090efb17c1893e77d6136a9111d"

/*
** Result Codes
*/

#define SQLITE_OK           0   /* Successful result */
/* beginning-of-error-codes */
#define SQLITE_ERROR        1   /* SQL error or missing database */
#define SQLITE_INTERNAL     2   /* Internal logic error in SQLite */
#define SQLITE_PERM         3   /* Access permission denied */
#define SQLITE_ABORT        4   /* Callback routine requested an abort */
#define SQLITE_BUSY         5   /* The database file is locked */
#define SQLITE_LOCKED       6   /* A table in the database is locked */
#define SQLITE_NOMEM        7   /* A malloc() failed */
#define SQLITE_READONLY     8   /* Attempt to write a readonly database */
#define SQLITE_INTERRUPT    9   /* Operation terminated by sqlite3_interrupt()*/
#define SQLITE_IOERR       10   /* Some kind of disk I/O error occurred */
#define SQLITE_CORRUPT     11   /* The database disk image is malformed */
#define SQLITE_NOTFOUND    12   /* NOT USED. Table or record not found */
#define SQLITE_FULL        13   /* Insertion failed because database is full */
#define SQLITE_CANTOPEN    14   /* Unable to open the database file */
#define SQLITE_PROTOCOL    15   /* Database lock protocol error */
#define SQLITE_EMPTY       16   /* Database is empty */
#define SQLITE_SCHEMA      17   /* The database schema changed */
#define SQLITE_TOOBIG      18   /* String or BLOB exceeds size limit */
#define SQLITE_CONSTRAINT  19   /* Abort due to constraint violation */
#define SQLITE_MISMATCH    20   /* Data type mismatch */
#define SQLITE_MISUSE      21   /* Library used incorrectly */
#define SQLITE_NOLFS       22   /* Uses OS features not supported on host */
#define SQLITE_AUTH        23   /* Authorization denied */
#define SQLITE_FORMAT      24   /* Auxiliary database format error */
#define SQLITE_RANGE       25   /* 2nd parameter to sqlite3_bind out of range */
#define SQLITE_NOTADB      26   /* File opened that is not a database file */
#define SQLITE_ROW         100  /* sqlite3_step() has another row ready */
#define SQLITE_DONE        101  /* sqlite3_step() has finished executing */
/* end-of-error-codes */

/*
** Extended Result Codes
*/
#define SQLITE_IOERR_READ              (SQLITE_IOERR | (1<<8))
#define SQLITE_IOERR_SHORT_READ        (SQLITE_IOERR | (2<<8))
#define SQLITE_IOERR_WRITE             (SQLITE_IOERR | (3<<8))
#define SQLITE_IOERR_FSYNC             (SQLITE_IOERR | (4<<8))
#define SQLITE_IOERR_DIR_FSYNC         (SQLITE_IOERR | (5<<8))
#define SQLITE_IOERR_TRUNCATE          (SQLITE_IOERR | (6<<8))
#define SQLITE_IOERR_FSTAT             (SQLITE_IOERR | (7<<8))
#define SQLITE_IOERR_UNLOCK            (SQLITE_IOERR | (8<<8))
#define SQLITE_IOERR_RDLOCK            (SQLITE_IOERR | (9<<8))
#define SQLITE_IOERR_DELETE            (SQLITE_IOERR | (10<<8))
#define SQLITE_IOERR_BLOCKED           (SQLITE_IOERR | (11<<8))
#define SQLITE_IOERR_NOMEM             (SQLITE_IOERR | (12<<8))
#define SQLITE_IOERR_ACCESS            (SQLITE_IOERR | (13<<8))
#define SQLITE_IOERR_CHECKRESERVEDLOCK (SQLITE_IOERR | (14<<8))
#define SQLITE_IOERR_LOCK              (SQLITE_IOERR | (15<<8))
#define SQLITE_IOERR_CLOSE             (SQLITE_IOERR | (16<<8))
#define SQLITE_IOERR_DIR_CLOSE         (SQLITE_IOERR | (17<<8))
#define SQLITE_IOERR_SHMOPEN           (SQLITE_IOERR | (18<<8))
#define SQLITE_IOERR_SHMSIZE           (SQLITE_IOERR | (19<<8))
#define SQLITE_IOERR_SHMLOCK           (SQLITE_IOERR | (20<<8))
#define SQLITE_LOCKED_SHAREDCACHE      (SQLITE_LOCKED |  (1<<8))
#define SQLITE_BUSY_RECOVERY           (SQLITE_BUSY   |  (1<<8))
#define SQLITE_CANTOPEN_NOTEMPDIR      (SQLITE_CANTOPEN | (1<<8))

/*
** Flags For File Open Operations
*/
#define SQLITE_OPEN_READONLY         0x00000001  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_READWRITE        0x00000002  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_CREATE           0x00000004  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_DELETEONCLOSE    0x00000008  /* VFS only */
#define SQLITE_OPEN_EXCLUSIVE        0x00000010  /* VFS only */
#define SQLITE_OPEN_AUTOPROXY        0x00000020  /* VFS only */
#define SQLITE_OPEN_MAIN_DB          0x00000100  /* VFS only */
#define SQLITE_OPEN_TEMP_DB          0x00000200  /* VFS only */
#define SQLITE_OPEN_TRANSIENT_DB     0x00000400  /* VFS only */
#define SQLITE_OPEN_MAIN_JOURNAL     0x00000800  /* VFS only */
#define SQLITE_OPEN_TEMP_JOURNAL     0x00001000  /* VFS only */
#define SQLITE_OPEN_SUBJOURNAL       0x00002000  /* VFS only */
#define SQLITE_OPEN_MASTER_JOURNAL   0x00004000  /* VFS only */
#define SQLITE_OPEN_NOMUTEX          0x00008000  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_FULLMUTEX        0x00010000  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_SHAREDCACHE      0x00020000  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_PRIVATECACHE     0x00040000  /* Ok for sqlite3_open_v2() */
#define SQLITE_OPEN_WAL              0x00080000  /* VFS only */

/*
** Device Characteristics
*/
#define SQLITE_IOCAP_ATOMIC                 0x00000001
#define SQLITE_IOCAP_ATOMIC512              0x00000002
#define SQLITE_IOCAP_ATOMIC1K               0x00000004
#define SQLITE_IOCAP_ATOMIC2K               0x00000008
#define SQLITE_IOCAP_ATOMIC4K               0x00000010
#define SQLITE_IOCAP_ATOMIC8K               0x00000020
#define SQLITE_IOCAP_ATOMIC16K              0x00000040
#define SQLITE_IOCAP_ATOMIC32K              0x00000080
#define SQLITE_IOCAP_ATOMIC64K              0x00000100
#define SQLITE_IOCAP_SAFE_APPEND            0x00000200
#define SQLITE_IOCAP_SEQUENTIAL             0x00000400
#define SQLITE_IOCAP_UNDELETABLE_WHEN_OPEN  0x00000800

/*
** File Locking Levels
*/
#define SQLITE_LOCK_NONE          0
#define SQLITE_LOCK_SHARED        1
#define SQLITE_LOCK_RESERVED      2
#define SQLITE_LOCK_PENDING       3
#define SQLITE_LOCK_EXCLUSIVE     4

/*
** Synchronization Type Flags
*/
#define SQLITE_SYNC_NORMAL        0x00002
#define SQLITE_SYNC_FULL          0x00003
#define SQLITE_SYNC_DATAONLY      0x00010

/*
** OS Interface Open File Handle
*/

sqlite3_file STRUCT
	pMethods PTR  /* Methods for an open file */
ENDS

/*
** OS Interface File Virtual Methods Object
*/

sqlite3_io_methods STRUCT
	iVersion INT32
	xClose PTR
	xRead PTR
	xWrite PTR
	xTruncate PTR
	xSync PTR
	xFileSize PTR
	xLock PTR
	xUnlock PTR
	xCheckReservedLock PTR
	xFileControl PTR
	xSectorSize PTR
	xDeviceCharacteristics PTR
	xShmMap PTR
	xShmLock PTR
	xShmBarrier PTR
	xShmUnmap PTR
ENDS

/*
** Standard File Control Opcodes
*/
#define SQLITE_FCNTL_LOCKSTATE        1
#define SQLITE_GET_LOCKPROXYFILE      2
#define SQLITE_SET_LOCKPROXYFILE      3
#define SQLITE_LAST_ERRNO             4
#define SQLITE_FCNTL_SIZE_HINT        5
#define SQLITE_FCNTL_CHUNK_SIZE       6

/*
** OS Interface Object
*/

sqlite3_vfs STRUCT
	iVersion INT32            /* Structure version number (currently 2) */
	szOsFile INT32            /* Size of subclassed sqlite3_file */
	mxPathname INT32          /* Maximum file pathname length */
	pNext PTR                 /* Next registered VFS */
	zName PTR                 /* Name of this virtual file system */
	pAppData PTR              /* Pointer to application-specific data */
	xOpen PTR
	xDelete PTR
	xAccess PTR
	xFullPathname PTR
	xDlOpen PTR
	xDlError PTR
	xDlSym PTR
	xDlClose PTR
	xRandomness PTR
	xSleep PTR
	xCurrentTime PTR
	xGetLastError PTR
	xCurrentTimeInt64 PTR
ENDS

/*
** Flags for the xAccess VFS method
*/
#define SQLITE_ACCESS_EXISTS    0
#define SQLITE_ACCESS_READWRITE 1   /* Used by PRAGMA temp_store_directory */
#define SQLITE_ACCESS_READ      2   /* Unused */

/*
** Flags for the xShmLock VFS method
*/
#define SQLITE_SHM_UNLOCK       1
#define SQLITE_SHM_LOCK         2
#define SQLITE_SHM_SHARED       4
#define SQLITE_SHM_EXCLUSIVE    8

/*
** Maximum xShmLock index
*/
#define SQLITE_SHM_NLOCK        8

sqlite3_mem_methods STRUCT
	xMalloc PTR   /* Memory allocation function */
	xFree PTR     /* Free a prior allocation */
	xRealloc PTR  /* Resize an allocation */
	xSize PTR     /* Return the size of an allocation */
	xRoundup PTR  /* Round up request size to allocation size */
	xInit PTR     /* Initialize the memory allocator */
	xShutdown PTR /* Deinitialize the memory allocator */
	pAppData PTR  /* Argument to xInit() and xShutdown() */
ENDS

/*
** Configuration Options
*/
#define SQLITE_CONFIG_SINGLETHREAD  1  /* nil */
#define SQLITE_CONFIG_MULTITHREAD   2  /* nil */
#define SQLITE_CONFIG_SERIALIZED    3  /* nil */
#define SQLITE_CONFIG_MALLOC        4  /* sqlite3_mem_methods* */
#define SQLITE_CONFIG_GETMALLOC     5  /* sqlite3_mem_methods* */
#define SQLITE_CONFIG_SCRATCH       6  /* void*, int sz, int N */
#define SQLITE_CONFIG_PAGECACHE     7  /* void*, int sz, int N */
#define SQLITE_CONFIG_HEAP          8  /* void*, int nByte, int min */
#define SQLITE_CONFIG_MEMSTATUS     9  /* boolean */
#define SQLITE_CONFIG_MUTEX        10  /* sqlite3_mutex_methods* */
#define SQLITE_CONFIG_GETMUTEX     11  /* sqlite3_mutex_methods* */
/* previously SQLITE_CONFIG_CHUNKALLOC 12 which is now unused. */ 
#define SQLITE_CONFIG_LOOKASIDE    13  /* int int */
#define SQLITE_CONFIG_PCACHE       14  /* sqlite3_pcache_methods* */
#define SQLITE_CONFIG_GETPCACHE    15  /* sqlite3_pcache_methods* */
#define SQLITE_CONFIG_LOG          16  /* xFunc, void* */

/*
** Database Connection Configuration Options
*/
#define SQLITE_DBCONFIG_LOOKASIDE    1001  /* void* int int */

/*
** Authorizer Return Codes
*/
#define SQLITE_DENY   1   /* Abort the SQL statement with an error */
#define SQLITE_IGNORE 2   /* Don't allow access, but don't generate an error */

/*
** Authorizer Action Codes
*/
/******************************************* 3rd ************ 4th ***********/
#define SQLITE_CREATE_INDEX          1   /* Index Name      Table Name      */
#define SQLITE_CREATE_TABLE          2   /* Table Name      NULL            */
#define SQLITE_CREATE_TEMP_INDEX     3   /* Index Name      Table Name      */
#define SQLITE_CREATE_TEMP_TABLE     4   /* Table Name      NULL            */
#define SQLITE_CREATE_TEMP_TRIGGER   5   /* Trigger Name    Table Name      */
#define SQLITE_CREATE_TEMP_VIEW      6   /* View Name       NULL            */
#define SQLITE_CREATE_TRIGGER        7   /* Trigger Name    Table Name      */
#define SQLITE_CREATE_VIEW           8   /* View Name       NULL            */
#define SQLITE_DELETE                9   /* Table Name      NULL            */
#define SQLITE_DROP_INDEX           10   /* Index Name      Table Name      */
#define SQLITE_DROP_TABLE           11   /* Table Name      NULL            */
#define SQLITE_DROP_TEMP_INDEX      12   /* Index Name      Table Name      */
#define SQLITE_DROP_TEMP_TABLE      13   /* Table Name      NULL            */
#define SQLITE_DROP_TEMP_TRIGGER    14   /* Trigger Name    Table Name      */
#define SQLITE_DROP_TEMP_VIEW       15   /* View Name       NULL            */
#define SQLITE_DROP_TRIGGER         16   /* Trigger Name    Table Name      */
#define SQLITE_DROP_VIEW            17   /* View Name       NULL            */
#define SQLITE_INSERT               18   /* Table Name      NULL            */
#define SQLITE_PRAGMA               19   /* Pragma Name     1st arg or NULL */
#define SQLITE_READ                 20   /* Table Name      Column Name     */
#define SQLITE_SELECT               21   /* NULL            NULL            */
#define SQLITE_TRANSACTION          22   /* Operation       NULL            */
#define SQLITE_UPDATE               23   /* Table Name      Column Name     */
#define SQLITE_ATTACH               24   /* Filename        NULL            */
#define SQLITE_DETACH               25   /* Database Name   NULL            */
#define SQLITE_ALTER_TABLE          26   /* Database Name   Table Name      */
#define SQLITE_REINDEX              27   /* Index Name      NULL            */
#define SQLITE_ANALYZE              28   /* Table Name      NULL            */
#define SQLITE_CREATE_VTABLE        29   /* Table Name      Module Name     */
#define SQLITE_DROP_VTABLE          30   /* Table Name      Module Name     */
#define SQLITE_FUNCTION             31   /* NULL            Function Name   */
#define SQLITE_SAVEPOINT            32   /* Operation       Savepoint Name  */
#define SQLITE_COPY                  0   /* No longer used */

/*
** Run-Time Limit Categories
*/
#define SQLITE_LIMIT_LENGTH                    0
#define SQLITE_LIMIT_SQL_LENGTH                1
#define SQLITE_LIMIT_COLUMN                    2
#define SQLITE_LIMIT_EXPR_DEPTH                3
#define SQLITE_LIMIT_COMPOUND_SELECT           4
#define SQLITE_LIMIT_VDBE_OP                   5
#define SQLITE_LIMIT_FUNCTION_ARG              6
#define SQLITE_LIMIT_ATTACHED                  7
#define SQLITE_LIMIT_LIKE_PATTERN_LENGTH       8
#define SQLITE_LIMIT_VARIABLE_NUMBER           9
#define SQLITE_LIMIT_TRIGGER_DEPTH            10

/*
** Fundamental Datatypes
*/
#define SQLITE_INTEGER  1
#define SQLITE_FLOAT    2
#define SQLITE_BLOB     4
#define SQLITE_NULL     5
#define SQLITE_TEXT     3
#define SQLITE3_TEXT    3

/*
** Text Encodings
*/
#define SQLITE_UTF8           1
#define SQLITE_UTF16LE        2
#define SQLITE_UTF16BE        3
#define SQLITE_UTF16          4    /* Use native byte order */
#define SQLITE_ANY            5    /* sqlite3_create_function only */
#define SQLITE_UTF16_ALIGNED  8    /* sqlite3_create_collation only */

/*
** Constants Defining Special Destructor Behavior
*/
#define SQLITE_STATIC      0
#define SQLITE_TRANSIENT   -1

/*
** Virtual Table Object
*/
sqlite3_module STRUCT
	iVersion INT32
	xCreate PTR
	xConnect PTR
	xBestIndex PTR
	xDisconnect PTR
	xDestroy PTR
	xOpen PTR
	xClose PTR
	xFilter PTR
	xNext PTR
	xEof PTR
	xColumn PTR
	xRowid PTR
	xUpdate PTR
	xBegin PTR
	xSync PTR
	xCommit PTR
	xRollback PTR
	xFindFunction PTR
	xRename PTR
ENDS

/*
** Virtual Table Indexing Information
*/
sqlite3_index_info STRUCT
  /* Inputs */
	nConstraint INT32               /* Number of entries in aConstraint */
	sqlite3_index_constraint STRUCT
		iColumn INT32               /* Column on left-hand side of constraint */
		op CHAR                     /* Constraint operator */
		usable CHAR                 /* True if this constraint is usable */
		iTermOffset INT32           /* Used internally - xBestIndex should ignore */
	ENDS
	nOrderBy INT32                  /* Number of terms in the ORDER BY clause */
	sqlite3_index_orderby STRUCT
		iColumn INT32               /* Column number */
		desc CHAR                   /* True for DESC.  False for ASC. */
	ENDS
  /* Outputs */
	sqlite3_index_constraint_usage STRUCT
		argvIndex INT32             /* if >0, constraint is part of argv to xFilter */
		omit CHAR                   /* Do not code a test for this constraint */
	ENDS
	idxNum INT32                    /* Number used to identify the index */
	idxStr PTR                      /* String, possibly obtained from sqlite3_malloc */
	needToFreeIdxStr INT32          /* Free idxStr using sqlite3_free() if true */
	orderByConsumed INT32           /* True if output is already ordered */
	estimatedCost DOUBLE            /* Estimated cost of using this index */
ENDS

/*
** Virtual Table Constraint Operator Codes
*/
#define SQLITE_INDEX_CONSTRAINT_EQ    2
#define SQLITE_INDEX_CONSTRAINT_GT    4
#define SQLITE_INDEX_CONSTRAINT_LE    8
#define SQLITE_INDEX_CONSTRAINT_LT    16
#define SQLITE_INDEX_CONSTRAINT_GE    32
#define SQLITE_INDEX_CONSTRAINT_MATCH 64

/*
** Virtual Table Instance Object
*/
sqlite3_vtab STRUCT
	pModule PTR  /* The module for this virtual table */
	nRef INT32   /* NO LONGER USED */
	zErrMsg PTR  /* Error message from sqlite3_mprintf() */
ENDS

/*
** Virtual Table Cursor Object
*/
sqlite3_vtab_cursor STRUCT
	pVtab PTR      /* Virtual table of this cursor */
ENDS

/*
** Mutex Methods Object
*/

sqlite3_mutex_methods STRUCT
	xMutexInit PTR
	xMutexEnd PTR
	xMutexAlloc PTR
	xMutexFree PTR
	xMutexEnter PTR
	xMutexTry PTR
	xMutexLeave PTR
	xMutexHeld PTR
	xMutexNotheld PTR
ENDS

/*
** Mutex Types
*/
#define SQLITE_MUTEX_FAST             0
#define SQLITE_MUTEX_RECURSIVE        1
#define SQLITE_MUTEX_STATIC_MASTER    2
#define SQLITE_MUTEX_STATIC_MEM       3  /* sqlite3_malloc() */
#define SQLITE_MUTEX_STATIC_MEM2      4  /* NOT USED */
#define SQLITE_MUTEX_STATIC_OPEN      4  /* sqlite3BtreeOpen() */
#define SQLITE_MUTEX_STATIC_PRNG      5  /* sqlite3_random() */
#define SQLITE_MUTEX_STATIC_LRU       6  /* lru page list */
#define SQLITE_MUTEX_STATIC_LRU2      7  /* lru page list */

/*
** Testing Interface Operation Codes
*/
#define SQLITE_TESTCTRL_FIRST                    5
#define SQLITE_TESTCTRL_PRNG_SAVE                5
#define SQLITE_TESTCTRL_PRNG_RESTORE             6
#define SQLITE_TESTCTRL_PRNG_RESET               7
#define SQLITE_TESTCTRL_BITVEC_TEST              8
#define SQLITE_TESTCTRL_FAULT_INSTALL            9
#define SQLITE_TESTCTRL_BENIGN_MALLOC_HOOKS     10
#define SQLITE_TESTCTRL_PENDING_BYTE            11
#define SQLITE_TESTCTRL_ASSERT                  12
#define SQLITE_TESTCTRL_ALWAYS                  13
#define SQLITE_TESTCTRL_RESERVE                 14
#define SQLITE_TESTCTRL_OPTIMIZATIONS           15
#define SQLITE_TESTCTRL_ISKEYWORD               16
#define SQLITE_TESTCTRL_PGHDRSZ                 17
#define SQLITE_TESTCTRL_SCRATCHMALLOC           18
#define SQLITE_TESTCTRL_LAST                    18

/*
** Status Parameters
*/
#define SQLITE_STATUS_MEMORY_USED          0
#define SQLITE_STATUS_PAGECACHE_USED       1
#define SQLITE_STATUS_PAGECACHE_OVERFLOW   2
#define SQLITE_STATUS_SCRATCH_USED         3
#define SQLITE_STATUS_SCRATCH_OVERFLOW     4
#define SQLITE_STATUS_MALLOC_SIZE          5
#define SQLITE_STATUS_PARSER_STACK         6
#define SQLITE_STATUS_PAGECACHE_SIZE       7
#define SQLITE_STATUS_SCRATCH_SIZE         8
#define SQLITE_STATUS_MALLOC_COUNT         9

/*
** Status Parameters for database connections
*/
#define SQLITE_DBSTATUS_LOOKASIDE_USED     0
#define SQLITE_DBSTATUS_CACHE_USED         1
#define SQLITE_DBSTATUS_SCHEMA_USED        2
#define SQLITE_DBSTATUS_STMT_USED          3
#define SQLITE_DBSTATUS_MAX                3   /* Largest defined DBSTATUS */

/*
** Status Parameters for prepared statements
*/
#define SQLITE_STMTSTATUS_FULLSCAN_STEP     1
#define SQLITE_STMTSTATUS_SORT              2
#define SQLITE_STMTSTATUS_AUTOINDEX         3

/*
** Application Defined Page Cache.
*/
sqlite3_pcache_methods STRUCT
	pArg PTR
	xInit PTR
	xShutdown PTR
	xCreate PTR
	xCachesize PTR
	xPagecount PTR
	xFetch PTR
	xUnpin PTR
	xRekey PTR
	xTruncate PTR
	xDestroy PTR
ENDS

/*
** A pointer to a structure of the following type is passed as the first
** argument to callbacks registered using rtree_geometry_callback().
*/
sqlite3_rtree_geometry STRUCT
	pContext PTR      /* Copy of pContext passed to s_r_g_c() */
	nParam INT32      /* Size of array aParam[] */
	aParam PTR        /* Parameters passed to SQL geom function */
	pUser PTR         /* Callback implementation user data */
	xDelUser PTR      /* Called by SQLite to clean up pUser */
ENDS

#endif

