#ifndef LMALERT_H
#define LMALERT_H

/* Alerter service definitions */

#define ALERTER_MAILSLOT  L"\\.\MAILSLOT\Alerter"

#define ALERT_PRINT_EVENT  L"PRINTING"
#define ALERT_MESSAGE_EVENT  L"MESSAGE"
#define ALERT_ERRORLOG_EVENT  L"ERRORLOG"
#define ALERT_ADMIN_EVENT  L"ADMIN"
#define ALERT_USER_EVENT  L"USER"

#define PRJOB_QSTATUS  0x3
#define PRJOB_DEVSTATUS  0x1FC
#define PRJOB_COMPLETE  0x4
#define PRJOB_INTERV  0x8
#define PRJOB_ERROR  0x10
#define PRJOB_DESTOFFLINE  0x20
#define PRJOB_DESTPAUSED  0x40
#define PRJOB_NOTIFY  0x80
#define PRJOB_DESTNOPAPER  0x100
#define PRJOB_DELETED  0x8000

#define PRJOB_QS_QUEUED  0
#define PRJOB_QS_PAUSED  1
#define PRJOB_QS_SPOOLING  2
#define PRJOB_QS_PRINTING  3

ADMIN_OTHER_INFO STRUCT
	alrtad_errcode DD
	alrtad_numstrings DD
ENDS

STD_ALERT STRUCT
	alrt_timestamp DD
	alrt_eventname DW EVLEN+1 DUP (?)
	alrt_servicename DW SNLEN+1 DUP (?)
ENDS

ERRLOG_OTHER_INFO STRUCT
	alrter_errcode DD
	alrter_offset DD
ENDS

PRINT_OTHER_INFO STRUCT
	alrtpr_jobid DD
	alrtpr_status DD
	alrtpr_submitted DD
	alrtpr_size DD
ENDS

USER_OTHER_INFO STRUCT
	alrtus_errcode DD
	alrtus_numstrings DD
ENDS

#endif /* _LMALERT_H */
