#ifndef CERTBCLI_H
#define CERTBCLI_H

#IFDEF LINKFILES
	#IFNDEF CERTADM_DLL
	#DEFINE CERTADM_DLL
		#dynamiclinkfile Certadm.dll
	#ENDIF
#ENDIF

/* Certificate Server backup clipent API definitions */

#define szBACKUPANNOTATION  A"Cert Server Backup Interface"
#define wszBACKUPANNOTATION  L"Cert Server Backup Interface"

#define szRESTOREANNOTATION  A"Cert Server Restore Interface"
#define wszRESTOREANNOTATION L"Cert Server Restore Interface"

#define CSBACKUP_TYPE_FULL  0x00000001
#define CSBACKUP_TYPE_LOGS_ONLY  0x00000002
#define CSBACKUP_TYPE_MASK  0x00000003

#define CSRESTORE_TYPE_FULL  0x00000001
#define CSRESTORE_TYPE_ONLINE  0x00000002
#define CSRESTORE_TYPE_CATCHUP  0x00000004
#define CSRESTORE_TYPE_MASK  0x00000005

#define CSBACKUP_DISABLE_INCREMENTAL  0xffffffff

#define CSCONTROL_SHUTDOWN  0x000000001
#define CSCONTROL_SUSPEND  0x000000002
#define CSCONTROL_RESTART  0x000000003

#define CSBFT_DIRECTORY  0x80
#define CSBFT_DATABASE_DIRECTORY  0x40
#define CSBFT_LOG_DIRECTORY  0x20

;#define CSBFT_LOG  ((CSBFT)(TEXT('\x01')|CSBFT_LOG_DIRECTORY))
;#define CSBFT_LOG_DIR  ((CSBFT)(TEXT('\x02')|CSBFT_DIRECTORY))
;#define CSBFT_CHECKPOINT_DIR  ((CSBFT)(TEXT('\x03')|CSBFT_DIRECTORY))
;#define CSBFT_CERTSERVER_DATABASE ((CSBFT)(TEXT('\x04')|CSBFT_DATABASE_DIRECTORY))
;#define CSBFT_PATCH_FILE  ((CSBFT)(TEXT('\x05')|CSBFT_LOG_DIRECTORY))
;#define CSBFT_UNKNOWN  ((CSBFT)(TEXT('\x0f')))

CSEDB_RSTMAPW STRUCT
	pwszDatabaseName PTR
	pwszNewDatabaseName PTR
ENDS
#define CSEDB_RSTMAP CSEDB_RSTMAPW

#define CertSrvIsServerOnline  CertSrvIsServerOnlineW
#define CertSrvBackupGetDynamicFileList CertSrvBackupGetDynamicFileListW
#define CertSrvBackupPrepare  CertSrvBackupPrepareW
#define CertSrvBackupGetDatabaseNames  CertSrvBackupGetDatabaseNamesW
#define CertSrvBackupOpenFile  CertSrvBackupOpenFileW
#define CertSrvBackupGetBackupLogs  CertSrvBackupGetBackupLogsW
#define CertSrvRestoreGetDatabaseLocations CertSrvRestoreGetDatabaseLocationsW
#define CertSrvRestorePrepare  CertSrvRestorePrepareW
#define CertSrvRestoreRegister  CertSrvRestoreRegisterW
#define CertSrvServerControl  CertSrvServerControlW

#endif /* CERTBCLI_H */
