#ifndef WINSPOOL_H
#define WINSPOOL_H

#DEFINE WINSPOOL_H_REQVER 100

#ifndef FILETIME
	FILETIME STRUCT
		dwLowDateTime DD
		dwHighDateTime DD
	ENDS
#ENDIF

#IFDEF LINKFILES
	#IF WINVER <= NTDDI_WIN9XALL
		#dynamiclinkfile spoolss.dll
	#ENDIF
		#dynamiclinkfile winspool.drv
#ENDIF

/* Windows Print API definitions */

#define DSPRINT_PUBLISH  0x00000001
#define DSPRINT_UPDATE  0x00000002
#define DSPRINT_UNPUBLISH  0x00000004
#define DSPRINT_REPUBLISH  0x00000008
#define DSPRINT_PENDING  0x80000000

#define PRINTER_CONTROL_PAUSE  1
#define PRINTER_CONTROL_RESUME  2
#define PRINTER_CONTROL_PURGE  3
#define PRINTER_CONTROL_SET_STATUS  4

#define PRINTER_STATUS_PAUSED  0x00000001
#define PRINTER_STATUS_ERROR  0x00000002
#define PRINTER_STATUS_PENDING_DELETION  0x00000004
#define PRINTER_STATUS_PAPER_JAM  0x00000008
#define PRINTER_STATUS_PAPER_OUT  0x00000010
#define PRINTER_STATUS_MANUAL_FEED  0x00000020
#define PRINTER_STATUS_PAPER_PROBLEM  0x00000040
#define PRINTER_STATUS_OFFLINE  0x00000080
#define PRINTER_STATUS_IO_ACTIVE  0x00000100
#define PRINTER_STATUS_BUSY  0x00000200
#define PRINTER_STATUS_PRINTING  0x00000400
#define PRINTER_STATUS_OUTPUT_BIN_FULL  0x00000800
#define PRINTER_STATUS_NOT_AVAILABLE  0x00001000
#define PRINTER_STATUS_WAITING  0x00002000
#define PRINTER_STATUS_PROCESSING  0x00004000
#define PRINTER_STATUS_INITIALIZING  0x00008000
#define PRINTER_STATUS_WARMING_UP  0x00010000
#define PRINTER_STATUS_TONER_LOW  0x00020000
#define PRINTER_STATUS_NO_TONER  0x00040000
#define PRINTER_STATUS_PAGE_PUNT  0x00080000
#define PRINTER_STATUS_USER_INTERVENTION  0x00100000
#define PRINTER_STATUS_OUT_OF_MEMORY  0x00200000
#define PRINTER_STATUS_DOOR_OPEN  0x00400000
#define PRINTER_STATUS_SERVER_UNKNOWN  0x00800000
#define PRINTER_STATUS_POWER_SAVE  0x01000000

#define PRINTER_ATTRIBUTE_QUEUED  0x00000001
#define PRINTER_ATTRIBUTE_DIRECT  0x00000002
#define PRINTER_ATTRIBUTE_DEFAULT  0x00000004
#define PRINTER_ATTRIBUTE_SHARED  0x00000008
#define PRINTER_ATTRIBUTE_NETWORK  0x00000010
#define PRINTER_ATTRIBUTE_HIDDEN  0x00000020
#define PRINTER_ATTRIBUTE_LOCAL  0x00000040

#define PRINTER_ATTRIBUTE_ENABLE_DEVQ  0x00000080
#define PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS  0x00000100
#define PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST 0x00000200

#define PRINTER_ATTRIBUTE_WORK_OFFLINE  0x00000400
#define PRINTER_ATTRIBUTE_ENABLE_BIDI  0x00000800
#define PRINTER_ATTRIBUTE_RAW_ONLY  0x00001000
#define PRINTER_ATTRIBUTE_PUBLISHED  0x00002000

#define NO_PRIORITY  0
#define MAX_PRIORITY  99
#define MIN_PRIORITY  1
#define DEF_PRIORITY  1

#define JOB_CONTROL_PAUSE  1
#define JOB_CONTROL_RESUME  2
#define JOB_CONTROL_CANCEL  3
#define JOB_CONTROL_RESTART  4
#define JOB_CONTROL_DELETE  5
#define JOB_CONTROL_SENT_TO_PRINTER  6
#define JOB_CONTROL_LAST_PAGE_EJECTED  7

#define JOB_STATUS_PAUSED  0x00000001
#define JOB_STATUS_ERROR  0x00000002
#define JOB_STATUS_DELETING  0x00000004
#define JOB_STATUS_SPOOLING  0x00000008
#define JOB_STATUS_PRINTING  0x00000010
#define JOB_STATUS_OFFLINE  0x00000020
#define JOB_STATUS_PAPEROUT  0x00000040
#define JOB_STATUS_PRINTED  0x00000080
#define JOB_STATUS_DELETED  0x00000100
#define JOB_STATUS_BLOCKED_DEVQ  0x00000200
#define JOB_STATUS_USER_INTERVENTION  0x00000400
#define JOB_STATUS_RESTART  0x00000800

#define JOB_POSITION_UNSPECIFIED  0

#define DRIVER_KERNELMODE  0x00000001
#define DRIVER_USERMODE  0x00000002

#define DPD_DELETE_UNUSED_FILES  0x00000001
#define DPD_DELETE_SPECIFIC_VERSION  0x00000002
#define DPD_DELETE_ALL_FILES  0x00000004

#define APD_STRICT_UPGRADE  0x00000001
#define APD_STRICT_DOWNGRADE  0x00000002
#define APD_COPY_ALL_FILES  0x00000004
#define APD_COPY_NEW_FILES  0x00000008

#define DI_CHANNEL  1
#define DI_READ_SPOOL_JOB  3

#define DI_MEMORYMAP_WRITE  0x00000001

#define FORM_USER  0x00000000
#define FORM_BUILTIN  0x00000001
#define FORM_PRINTER  0x00000002

#define PORT_TYPE_WRITE  0x0001
#define PORT_TYPE_READ  0x0002
#define PORT_TYPE_REDIRECTED  0x0004
#define PORT_TYPE_NET_ATTACHED  0x0008

#define PORT_STATUS_TYPE_ERROR  1
#define PORT_STATUS_TYPE_WARNING  2
#define PORT_STATUS_TYPE_INFO  3

#define PORT_STATUS_OFFLINE  1
#define PORT_STATUS_PAPER_JAM  2
#define PORT_STATUS_PAPER_OUT  3
#define PORT_STATUS_OUTPUT_BIN_FULL  4
#define PORT_STATUS_PAPER_PROBLEM  5
#define PORT_STATUS_NO_TONER  6
#define PORT_STATUS_DOOR_OPEN  7
#define PORT_STATUS_USER_INTERVENTION  8
#define PORT_STATUS_OUT_OF_MEMORY  9
#define PORT_STATUS_TONER_LOW  10
#define PORT_STATUS_WARMING_UP  11
#define PORT_STATUS_POWER_SAVE  12

#define PRINTER_ENUM_DEFAULT  0x00000001
#define PRINTER_ENUM_LOCAL  0x00000002
#define PRINTER_ENUM_CONNECTIONS  0x00000004
#define PRINTER_ENUM_FAVORITE  0x00000004
#define PRINTER_ENUM_NAME  0x00000008
#define PRINTER_ENUM_REMOTE  0x00000010
#define PRINTER_ENUM_SHARED  0x00000020
#define PRINTER_ENUM_NETWORK  0x00000040
#define PRINTER_ENUM_EXPAND  0x00004000
#define PRINTER_ENUM_CONTAINER  0x00008000
#define PRINTER_ENUM_ICONMASK  0x00ff0000
#define PRINTER_ENUM_ICON1  0x00010000
#define PRINTER_ENUM_ICON2  0x00020000
#define PRINTER_ENUM_ICON3  0x00040000
#define PRINTER_ENUM_ICON4  0x00080000
#define PRINTER_ENUM_ICON5  0x00100000
#define PRINTER_ENUM_ICON6  0x00200000
#define PRINTER_ENUM_ICON7  0x00400000
#define PRINTER_ENUM_ICON8  0x00800000
#define PRINTER_ENUM_HIDE  0x01000000

#define SPOOL_FILE_PERSISTENT  0x00000001
#define SPOOL_FILE_TEMPORARY  0x00000002

#define PRINTER_NOTIFY_TYPE  0x00
#define JOB_NOTIFY_TYPE  0x01

#define PRINTER_NOTIFY_FIELD_SERVER_NAME  0x00
#define PRINTER_NOTIFY_FIELD_PRINTER_NAME  0x01
#define PRINTER_NOTIFY_FIELD_SHARE_NAME  0x02
#define PRINTER_NOTIFY_FIELD_PORT_NAME  0x03
#define PRINTER_NOTIFY_FIELD_DRIVER_NAME  0x04
#define PRINTER_NOTIFY_FIELD_COMMENT  0x05
#define PRINTER_NOTIFY_FIELD_LOCATION  0x06
#define PRINTER_NOTIFY_FIELD_DEVMODE  0x07
#define PRINTER_NOTIFY_FIELD_SEPFILE  0x08
#define PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR  0x09
#define PRINTER_NOTIFY_FIELD_PARAMETERS  0x0A
#define PRINTER_NOTIFY_FIELD_DATATYPE  0x0B
#define PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR  0x0C
#define PRINTER_NOTIFY_FIELD_ATTRIBUTES  0x0D
#define PRINTER_NOTIFY_FIELD_PRIORITY  0x0E
#define PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY  0x0F
#define PRINTER_NOTIFY_FIELD_START_TIME  0x10
#define PRINTER_NOTIFY_FIELD_UNTIL_TIME  0x11
#define PRINTER_NOTIFY_FIELD_STATUS  0x12
#define PRINTER_NOTIFY_FIELD_STATUS_STRING  0x13
#define PRINTER_NOTIFY_FIELD_CJOBS  0x14
#define PRINTER_NOTIFY_FIELD_AVERAGE_PPM  0x15
#define PRINTER_NOTIFY_FIELD_TOTAL_PAGES  0x16
#define PRINTER_NOTIFY_FIELD_PAGES_PRINTED  0x17
#define PRINTER_NOTIFY_FIELD_TOTAL_BYTES  0x18
#define PRINTER_NOTIFY_FIELD_BYTES_PRINTED  0x19
#define PRINTER_NOTIFY_FIELD_OBJECT_GUID  0x1A

#define JOB_NOTIFY_FIELD_PRINTER_NAME  0x00
#define JOB_NOTIFY_FIELD_MACHINE_NAME  0x01
#define JOB_NOTIFY_FIELD_PORT_NAME  0x02
#define JOB_NOTIFY_FIELD_USER_NAME  0x03
#define JOB_NOTIFY_FIELD_NOTIFY_NAME  0x04
#define JOB_NOTIFY_FIELD_DATATYPE  0x05
#define JOB_NOTIFY_FIELD_PRINT_PROCESSOR  0x06
#define JOB_NOTIFY_FIELD_PARAMETERS  0x07
#define JOB_NOTIFY_FIELD_DRIVER_NAME  0x08
#define JOB_NOTIFY_FIELD_DEVMODE  0x09
#define JOB_NOTIFY_FIELD_STATUS  0x0A
#define JOB_NOTIFY_FIELD_STATUS_STRING  0x0B
#define JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR  0x0C
#define JOB_NOTIFY_FIELD_DOCUMENT  0x0D
#define JOB_NOTIFY_FIELD_PRIORITY  0x0E
#define JOB_NOTIFY_FIELD_POSITION  0x0F
#define JOB_NOTIFY_FIELD_SUBMITTED  0x10
#define JOB_NOTIFY_FIELD_START_TIME  0x11
#define JOB_NOTIFY_FIELD_UNTIL_TIME  0x12
#define JOB_NOTIFY_FIELD_TIME  0x13
#define JOB_NOTIFY_FIELD_TOTAL_PAGES  0x14
#define JOB_NOTIFY_FIELD_PAGES_PRINTED  0x15
#define JOB_NOTIFY_FIELD_TOTAL_BYTES  0x16
#define JOB_NOTIFY_FIELD_BYTES_PRINTED  0x17

#define PRINTER_NOTIFY_OPTIONS_REFRESH  0x01
#define PRINTER_NOTIFY_INFO_DISCARDED  0x01

#define PRINTER_CHANGE_ADD_PRINTER  0x00000001
#define PRINTER_CHANGE_SET_PRINTER  0x00000002
#define PRINTER_CHANGE_DELETE_PRINTER  0x00000004
#define PRINTER_CHANGE_FAILED_CONNECTION_PRINTER  0x00000008
#define PRINTER_CHANGE_PRINTER  0x000000FF
#define PRINTER_CHANGE_ADD_JOB  0x00000100
#define PRINTER_CHANGE_SET_JOB  0x00000200
#define PRINTER_CHANGE_DELETE_JOB  0x00000400
#define PRINTER_CHANGE_WRITE_JOB  0x00000800
#define PRINTER_CHANGE_JOB  0x0000FF00
#define PRINTER_CHANGE_ADD_FORM  0x00010000
#define PRINTER_CHANGE_SET_FORM  0x00020000
#define PRINTER_CHANGE_DELETE_FORM  0x00040000
#define PRINTER_CHANGE_FORM  0x00070000
#define PRINTER_CHANGE_ADD_PORT  0x00100000
#define PRINTER_CHANGE_CONFIGURE_PORT  0x00200000
#define PRINTER_CHANGE_DELETE_PORT  0x00400000
#define PRINTER_CHANGE_PORT  0x00700000
#define PRINTER_CHANGE_ADD_PRINT_PROCESSOR  0x01000000
#define PRINTER_CHANGE_DELETE_PRINT_PROCESSOR  0x04000000
#define PRINTER_CHANGE_PRINT_PROCESSOR  0x07000000
#define PRINTER_CHANGE_ADD_PRINTER_DRIVER  0x10000000
#define PRINTER_CHANGE_SET_PRINTER_DRIVER  0x20000000
#define PRINTER_CHANGE_DELETE_PRINTER_DRIVER  0x40000000
#define PRINTER_CHANGE_PRINTER_DRIVER  0x70000000
#define PRINTER_CHANGE_TIMEOUT  0x80000000
#define PRINTER_CHANGE_ALL  0x7777FFFF

#define PRINTER_ERROR_INFORMATION  0x80000000
#define PRINTER_ERROR_WARNING  0x40000000
#define PRINTER_ERROR_SEVERE  0x20000000

#define PRINTER_ERROR_OUTOFPAPER  0x00000001
#define PRINTER_ERROR_JAM  0x00000002
#define PRINTER_ERROR_OUTOFTONER  0x00000004

#define SERVER_ACCESS_ADMINISTER  0x00000001
#define SERVER_ACCESS_ENUMERATE  0x00000002

#define PRINTER_ACCESS_ADMINISTER  0x00000004
#define PRINTER_ACCESS_USE  0x00000008

#define JOB_ACCESS_ADMINISTER  0x00000010

#define SERVER_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SERVER_ACCESS_ADMINISTER|SERVER_ACCESS_ENUMERATE)
#define SERVER_READ  (STANDARD_RIGHTS_READ|SERVER_ACCESS_ENUMERATE)
#define SERVER_WRITE  (STANDARD_RIGHTS_WRITE|SERVER_ACCESS_ADMINISTER|SERVER_ACCESS_ENUMERATE)
#define SERVER_EXECUTE  (STANDARD_RIGHTS_EXECUTE|SERVER_ACCESS_ENUMERATE)

#define PRINTER_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|PRINTER_ACCESS_ADMINISTER|PRINTER_ACCESS_USE)
#define PRINTER_READ  (STANDARD_RIGHTS_READ|PRINTER_ACCESS_USE)
#define PRINTER_WRITE  (STANDARD_RIGHTS_WRITE|PRINTER_ACCESS_USE)
#define PRINTER_EXECUTE  (STANDARD_RIGHTS_EXECUTE|PRINTER_ACCESS_USE)

#define JOB_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|JOB_ACCESS_ADMINISTER)
#define JOB_READ  (STANDARD_RIGHTS_READ|JOB_ACCESS_ADMINISTER)
#define JOB_WRITE  (STANDARD_RIGHTS_WRITE|JOB_ACCESS_ADMINISTER)
#define JOB_EXECUTE  (STANDARD_RIGHTS_EXECUTE|JOB_ACCESS_ADMINISTER)

#define SPLREG_DEFAULT_SPOOL_DIRECTORY  "DefaultSpoolDirectory"
#define SPLREG_PORT_THREAD_PRIORITY_DEFAULT  "PortThreadPriorityDefault"
#define SPLREG_PORT_THREAD_PRIORITY  "PortThreadPriority"
#define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT  "SchedulerThreadPriorityDefault"
#define SPLREG_SCHEDULER_THREAD_PRIORITY  "SchedulerThreadPriority"
#define SPLREG_BEEP_ENABLED  "BeepEnabled"
#define SPLREG_NET_POPUP  "NetPopup"
#define SPLREG_RETRY_POPUP  "RetryPopup"
#define SPLREG_NET_POPUP_TO_COMPUTER  "NetPopupToComputer"
#define SPLREG_EVENT_LOG  "EventLog"
#define SPLREG_MAJOR_VERSION  "MajorVersion"
#define SPLREG_MINOR_VERSION  "MinorVersion"
#define SPLREG_ARCHITECTURE  "Architecture"
#define SPLREG_OS_VERSION  "OSVersion"
#define SPLREG_DS_PRESENT  "DsPresent"
#define SPLREG_DS_PRESENT_FOR_USER  "DsPresentForUser"
#define SPLREG_REMOTE_FAX  "RemoteFax"
#define SPLREG_RESTART_JOB_ON_POOL_ERROR  "RestartJobOnPoolError"
#define SPLREG_RESTART_JOB_ON_POOL_ENABLED  "RestartJobOnPoolEnabled"
#define SPLREG_DNS_MACHINE_NAME  "DNSMachineName"

#define SPLDS_SPOOLER_KEY  "DsSpooler"
#define SPLDS_DRIVER_KEY  "DsDriver"
#define SPLDS_USER_KEY  "DsUser"
#define SPLDS_ASSET_NUMBER  "assetNumber"
#define SPLDS_BYTES_PER_MINUTE  "bytesPerMinute"
#define SPLDS_DESCRIPTION  "description"
#define SPLDS_DRIVER_NAME  "driverName"
#define SPLDS_DRIVER_VERSION  "driverVersion"
#define SPLDS_LOCATION  "location"
#define SPLDS_PORT_NAME  "portName"
#define SPLDS_PRINT_ATTRIBUTES  "printAttributes"
#define SPLDS_PRINT_BIN_NAMES  "printBinNames"
#define SPLDS_PRINT_COLLATE  "printCollate"
#define SPLDS_PRINT_COLOR  "printColor"
#define SPLDS_PRINT_DUPLEX_SUPPORTED  "printDuplexSupported"
#define SPLDS_PRINT_END_TIME  "printEndTime"
#define SPLDS_PRINTER_CLASS  "printQueue"
#define SPLDS_PRINTER_NAME  "printerName"
#define SPLDS_PRINT_KEEP_PRINTED_JOBS  "printKeepPrintedJobs"
#define SPLDS_PRINT_LANGUAGE  "printLanguage"
#define SPLDS_PRINT_MAC_ADDRESS  "printMACAddress"
#define SPLDS_PRINT_MAX_X_EXTENT  "printMaxXExtent"
#define SPLDS_PRINT_MAX_Y_EXTENT  "printMaxYExtent"
#define SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED  "printMaxResolutionSupported"
#define SPLDS_PRINT_MEDIA_READY  "printMediaReady"
#define SPLDS_PRINT_MEDIA_SUPPORTED  "printMediaSupported"
#define SPLDS_PRINT_MEMORY  "printMemory"
#define SPLDS_PRINT_MIN_X_EXTENT  "printMinXExtent"
#define SPLDS_PRINT_MIN_Y_EXTENT  "printMinYExtent"
#define SPLDS_PRINT_NETWORK_ADDRESS  "printNetworkAddress"
#define SPLDS_PRINT_NOTIFY  "printNotify"
#define SPLDS_PRINT_NUMBER_UP  "printNumberUp"
#define SPLDS_PRINT_ORIENTATIONS_SUPPORTED  "printOrientationsSupported"
#define SPLDS_PRINT_OWNER  "printOwner"
#define SPLDS_PRINT_PAGES_PER_MINUTE  "printPagesPerMinute"
#define SPLDS_PRINT_RATE  "printRate"
#define SPLDS_PRINT_RATE_UNIT  "printRateUnit"
#define SPLDS_PRINT_SEPARATOR_FILE  "printSeparatorFile"
#define SPLDS_PRINT_SHARE_NAME  "printShareName"
#define SPLDS_PRINT_SPOOLING  "printSpooling"
#define SPLDS_PRINT_STAPLING_SUPPORTED  "printStaplingSupported"
#define SPLDS_PRINT_START_TIME  "printStartTime"
#define SPLDS_PRINT_STATUS  "printStatus"
#define SPLDS_PRIORITY  "priority"
#define SPLDS_SERVER_NAME  "serverName"
#define SPLDS_SHORT_SERVER_NAME  "shortServerName"
#define SPLDS_UNC_NAME  "uNCName"
#define SPLDS_URL  "url"
#define SPLDS_FLAGS  "flags"
#define SPLDS_VERSION_NUMBER  "versionNumber"
#define SPLDS_PRINTER_NAME_ALIASES  "printerNameAliases"
#define SPLDS_PRINTER_LOCATIONS  "printerLocations"
#define SPLDS_PRINTER_MODEL  "printerModel"

PRINTER_INFO_1A STRUCT
	Flags DD
	pDescription PTR
	pName PTR
	pComment PTR
ENDS

PRINTER_INFO_1W STRUCT
	Flags DD
	pDescription PTR
	pName PTR
	pComment PTR
ENDS

PRINTER_INFO_2A STRUCT
	pServerName PTR
	pPrinterName PTR
	pShareName PTR
	pPortName PTR
	pDriverName PTR
	pComment PTR
	pLocation PTR
	pDevMode PTR
	pSepFile PTR
	pPrintProcessor PTR
	pDatatype PTR
	pParameters PTR
	pSecurityDescriptor PTR
	Attributes DD
	Priority DD
	DefaultPriority DD
	StartTime DD
	UntilTime DD
	Status DD
	cJobs DD
	AveragePPM DD
ENDS

PRINTER_INFO_2W STRUCT
	pServerName PTR
	pPrinterName PTR
	pShareName PTR
	pPortName PTR
	pDriverName PTR
	pComment PTR
	pLocation PTR
	pDevMode PTR
	pSepFile PTR
	pPrintProcessor PTR
	pDatatype PTR
	pParameters PTR
	pSecurityDescriptor PTR
	Attributes DD
	Priority DD
	DefaultPriority DD
	StartTime DD
	UntilTime DD
	Status DD
	cJobs DD
	AveragePPM DD
ENDS

PRINTER_INFO_3 STRUCT
	pSecurityDescriptor PTR
ENDS

PRINTER_INFO_4A STRUCT
	pPrinterName PTR
	pServerName PTR
	Attributes DD
ENDS

PRINTER_INFO_4W STRUCT
	pPrinterName PTR
	pServerName PTR
	Attributes DD
ENDS

PRINTER_INFO_5A STRUCT
	pPrinterName PTR
	pPortName PTR
	Attributes DD
	DeviceNotSelectedTimeout DD
	TransmissionRetryTimeout DD
ENDS

PRINTER_INFO_5W STRUCT
	pPrinterName PTR
	pPortName PTR
	Attributes DD
	DeviceNotSelectedTimeout DD
	TransmissionRetryTimeout DD
ENDS

PRINTER_INFO_6 STRUCT
	dwStatus DD
ENDS

PRINTER_INFO_7A STRUCT
	pszObjectGUID PTR
	dwAction DD
ENDS

PRINTER_INFO_7W STRUCT
	pszObjectGUID PTR
	dwAction DD
ENDS

PRINTER_INFO_8A STRUCT
	pDevMode PTR
ENDS

PRINTER_INFO_8W STRUCT
	pDevMode PTR
ENDS

PRINTER_INFO_9A STRUCT
	pDevMode PTR
ENDS

PRINTER_INFO_9W STRUCT
	pDevMode PTR
ENDS

JOB_INFO_1A STRUCT
	JobId DD
	pPrinterName PTR
	pMachineName PTR
	pUserName PTR
	pDocument PTR
	pDatatype PTR
	pStatus PTR
	Status DD
	Priority DD
	Position DD
	TotalPages DD
	PagesPrinted DD
	Submitted SYSTEMTIME <>
ENDS

JOB_INFO_1W STRUCT
	JobId DD
	pPrinterName PTR
	pMachineName PTR
	pUserName PTR
	pDocument PTR
	pDatatype PTR
	pStatus PTR
	Status DD
	Priority DD
	Position DD
	TotalPages DD
	PagesPrinted DD
	Submitted SYSTEMTIME <>
ENDS

JOB_INFO_2A STRUCT
	JobId DD
	pPrinterName PTR
	pMachineName PTR
	pUserName PTR
	pDocument PTR
	pNotifyName PTR
	pDatatype PTR
	pPrintProcessor PTR
	pParameters PTR
	pDriverName PTR
	pDevMode PTR
	pStatus PTR
	pSecurityDescriptor PTR
	Status DD
	Priority DD
	Position DD
	StartTime DD
	UntilTime DD
	TotalPages DD
	Size DD
	Submitted SYSTEMTIME <>
	Time DD
	PagesPrinted DD
ENDS

JOB_INFO_2W STRUCT
	JobId DD
	pPrinterName PTR
	pMachineName PTR
	pUserName PTR
	pDocument PTR
	pNotifyName PTR
	pDatatype PTR
	pPrintProcessor PTR
	pParameters PTR
	pDriverName PTR
	pDevMode PTR
	pStatus PTR
	pSecurityDescriptor PTR
	Status DD
	Priority DD
	Position DD
	StartTime DD
	UntilTime DD
	TotalPages DD
	Size DD
	Submitted SYSTEMTIME <>
	Time DD
	PagesPrinted DD
ENDS

JOB_INFO_3 STRUCT
	JobId DD
	NextJobId DD
	Reserved DD
ENDS

ADDJOB_INFO_1A STRUCT
	Path PTR
	JobId DD
ENDS

ADDJOB_INFO_1W STRUCT
	Path PTR
	JobId DD
ENDS

DRIVER_INFO_1A STRUCT
	pName PTR
ENDS

DRIVER_INFO_1W STRUCT
	pName PTR
ENDS

DRIVER_INFO_2A STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
ENDS

DRIVER_INFO_2W STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
ENDS

DRIVER_INFO_3A STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
	pHelpFile PTR
	pDependentFiles PTR
	pMonitorName PTR
	pDefaultDataType PTR
ENDS

DRIVER_INFO_3W STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
	pHelpFile PTR
	pDependentFiles PTR
	pMonitorName PTR
	pDefaultDataType PTR
ENDS

DRIVER_INFO_4A STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
	pHelpFile PTR
	pDependentFiles PTR
	pMonitorName PTR
	pDefaultDataType PTR
	pszzPreviousNames PTR
ENDS

DRIVER_INFO_4W STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
	pHelpFile PTR
	pDependentFiles PTR
	pMonitorName PTR
	pDefaultDataType PTR
	pszzPreviousNames PTR
ENDS

DRIVER_INFO_5A STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
	dwDriverAttributes DD
	dwConfigVersion DD
	dwDriverVersion DD
ENDS

DRIVER_INFO_5W STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
	dwDriverAttributes DD
	dwConfigVersion DD
	dwDriverVersion DD
ENDS

DRIVER_INFO_6A STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
	pHelpFile PTR
	pDependentFiles PTR
	pMonitorName PTR
	pDefaultDataType PTR
	pszzPreviousNames PTR
	ftDriverDate FILETIME <>
	dwlDriverVersion DD
	pszMfgName PTR
	pszOEMUrl PTR
	pszHardwareID PTR
	pszProvider PTR
ENDS

DRIVER_INFO_6W STRUCT
	cVersion DD
	pName PTR
	pEnvironment PTR
	pDriverPath PTR
	pDataFile PTR
	pConfigFile PTR
	pHelpFile PTR
	pDependentFiles PTR
	pMonitorName PTR
	pDefaultDataType PTR
	pszzPreviousNames PTR
	ftDriverDate FILETIME <>
	dwlDriverVersion DD
	pszMfgName PTR
	pszOEMUrl PTR
	pszHardwareID PTR
	pszProvider PTR
ENDS

DOC_INFO_1A STRUCT
	pDocName PTR
	pOutputFile PTR
	pDatatype PTR
ENDS

DOC_INFO_1W STRUCT
	pDocName PTR
	pOutputFile PTR
	pDatatype PTR
ENDS

FORM_INFO_1A STRUCT
	Flags DD
	pName PTR
	Size SIZE <>
	ImageableArea RECT <>
ENDS

FORM_INFO_1W STRUCT
	Flags DD
	pName PTR
	Size SIZE <>
	ImageableArea RECT <>
ENDS

DOC_INFO_2A STRUCT
	pDocName PTR
	pOutputFile PTR
	pDatatype PTR
	dwMode DD
	JobId DD
ENDS

DOC_INFO_2W STRUCT
	pDocName PTR
	pOutputFile PTR
	pDatatype PTR
	dwMode DD
	JobId DD
ENDS

DOC_INFO_3A STRUCT
	pDocName PTR
	pOutputFile PTR
	pDatatype PTR
	dwFlags DD
ENDS

DOC_INFO_3W STRUCT
	pDocName PTR
	pOutputFile PTR
	pDatatype PTR
	dwFlags DD
ENDS

PRINTPROCESSOR_INFO_1A STRUCT
	pName PTR
ENDS

PRINTPROCESSOR_INFO_1W STRUCT
	pName PTR
ENDS

PORT_INFO_1A STRUCT
	pName PTR
ENDS

PORT_INFO_1W STRUCT
	pName PTR
ENDS

PORT_INFO_2A STRUCT
	pPortName PTR
	pMonitorName PTR
	pDescription PTR
	fPortType DD
	Reserved DD
ENDS

PORT_INFO_2W STRUCT
	pPortName PTR
	pMonitorName PTR
	pDescription PTR
	fPortType DD
	Reserved DD
ENDS

PORT_INFO_3A STRUCT
	dwStatus DD
	pszStatus PTR
	dwSeverity DD
ENDS

PORT_INFO_3W STRUCT
	dwStatus DD
	pszStatus PTR
	dwSeverity DD
ENDS

MONITOR_INFO_1A STRUCT
	pName PTR
ENDS

MONITOR_INFO_1W STRUCT
	pName PTR
ENDS

MONITOR_INFO_2A STRUCT
	pName PTR
	pEnvironment PTR
	pDLLName PTR
ENDS

MONITOR_INFO_2W STRUCT
	pName PTR
	pEnvironment PTR
	pDLLName PTR
ENDS

DATATYPES_INFO_1A STRUCT
	pName PTR
ENDS

DATATYPES_INFO_1W STRUCT
	pName PTR
ENDS

PRINTER_DEFAULTSA STRUCT
	pDatatype PTR
	pDevMode PTR
	DesiredAccess; DD
ENDS

PRINTER_DEFAULTSW STRUCT
	pDatatype PTR
	pDevMode PTR
	DesiredAccess; DD
ENDS

PRINTER_ENUM_VALUESA STRUCT
	pValueName PTR
	cbValueName DD
	dwType DD
	pData PTR
	cbData DD
ENDS

PRINTER_ENUM_VALUESW STRUCT
	pValueName PTR
	cbValueName DD
	dwType DD
	pData PTR
	cbData DD
ENDS

PRINTER_NOTIFY_OPTIONS_TYPE STRUCT
	Type DW
	Reserved0 DW
	Reserved1 DD
	Reserved2 DD
	Count DD
	pFields PTR
ENDS

PRINTER_NOTIFY_OPTIONS STRUCT
	Version DD
	Flags DD
	Count DD
	pTypes PTR
ENDS

PRINTER_NOTIFY_INFO_DATA STRUCT
	Type DW
	Field DW
	Reserved DD
	Id DD
	UNION
		adwData DD 2 DUP
		data STRUCT
			cbBuf DD
			pBuf PTR
		ENDS
	ENDUNION
ENDS

PRINTER_NOTIFY_INFO STRUCT
	Version DD
	Flags DD
	Count DD
	aData PRINTER_NOTIFY_INFO_DATA <>
ENDS

PROVIDOR_INFO_1A STRUCT
	pName PTR
	pEnvironment PTR
	pDLLName PTR
ENDS

PROVIDOR_INFO_1W STRUCT
	pName PTR
	pEnvironment PTR
	pDLLName PTR
ENDS

PROVIDOR_INFO_2A STRUCT
	pOrder PTR
ENDS

PROVIDOR_INFO_2W STRUCT
	pOrder PTR
ENDS

#IFDEF UNICODE
	#define PRINTER_INFO_1 PRINTER_INFO_1W
	#define PRINTER_INFO_2 PRINTER_INFO_2W
	#define PRINTER_INFO_4 PRINTER_INFO_4W
	#define PRINTER_INFO_5 PRINTER_INFO_5W
	#define PRINTER_INFO_7 PRINTER_INFO_7W
	#define PRINTER_INFO_8 PRINTER_INFO_8W
	#define PRINTER_INFO_9 PRINTER_INFO_9W
	#define JOB_INFO_1 JOB_INFO_1W
	#define JOB_INFO_2 JOB_INFO_2W
	#define ADDJOB_INFO_1 ADDJOB_INFO_1W
	#define DRIVER_INFO_1 DRIVER_INFO_1W
	#define DRIVER_INFO_2 DRIVER_INFO_2W
	#define DRIVER_INFO_3 DRIVER_INFO_3W
	#define DRIVER_INFO_4 DRIVER_INFO_4W
	#define DRIVER_INFO_5 DRIVER_INFO_5W
	#define DRIVER_INFO_6 DRIVER_INFO_6W
	#define DOC_INFO_1 DOC_INFO_1W
	#define FORM_INFO_1 FORM_INFO_1W
	#define DOC_INFO_2 DOC_INFO_2W
	#define DOC_INFO_3 DOC_INFO_3W
	#define PRINTPROCESSOR_INFO_1 PRINTPROCESSOR_INFO_1W
	#define PORT_INFO_1 PORT_INFO_1W
	#define PORT_INFO_2 PORT_INFO_2W
	#define PORT_INFO_3 PORT_INFO_3W
	#define MONITOR_INFO_1 MONITOR_INFO_1W
	#define MONITOR_INFO_2 MONITOR_INFO_2W
	#define DATATYPES_INFO_1 DATATYPES_INFO_1W
	#define PRINTER_DEFAULTS PRINTER_DEFAULTSW
	#define PRINTER_ENUM_VALUES PRINTER_ENUM_VALUESW
	#define PROVIDOR_INFO_1 PROVIDOR_INFO_1W
	#define PROVIDOR_INFO_2 PROVIDOR_INFO_2W

	#define EnumPrinters EnumPrintersW
	#define OpenPrinter OpenPrinterW
	#define ResetPrinter ResetPrinterW
	#define SetJob SetJobW
	#define GetJob GetJobW
	#define EnumJobs EnumJobsW
	#define AddPrinter AddPrinterW
	#define SetPrinter SetPrinterW
	#define GetPrinter GetPrinterW
	#define AddPrinterDriver AddPrinterDriverW
	#define AddPrinterDriverEx AddPrinterDriverExW
	#define EnumPrinterDrivers EnumPrinterDriversW
	#define GetPrinterDriver GetPrinterDriverW
	#define GetPrinterDriverDirectory GetPrinterDriverDirectoryW
	#define DeletePrinterDriver DeletePrinterDriverW
	#define DeletePrinterDriverEx DeletePrinterDriverExW
	#define AddPrintProcessor AddPrintProcessorW
	#define EnumPrintProcessors EnumPrintProcessorsW
	#define GetPrintProcessorDirectory GetPrintProcessorDirectoryW
	#define EnumPrintProcessorDatatypes EnumPrintProcessorDatatypesW
	#define DeletePrintProcessor DeletePrintProcessorW
	#define StartDocPrinter StartDocPrinterW
	#define AddJob AddJobW
	#define DocumentProperties DocumentPropertiesW
	#define AdvancedDocumentProperties AdvancedDocumentPropertiesW
	#define GetPrinterData GetPrinterDataW
	#define GetPrinterDataEx GetPrinterDataExW
	#define EnumPrinterData EnumPrinterDataW
	#define EnumPrinterDataEx EnumPrinterDataExW
	#define EnumPrinterKey EnumPrinterKeyW
	#define SetPrinterData SetPrinterDataW
	#define SetPrinterDataEx SetPrinterDataExW
	#define DeletePrinterData DeletePrinterDataW
	#define DeletePrinterDataEx DeletePrinterDataExW
	#define DeletePrinterKey DeletePrinterKeyW
	#define PrinterMessageBox PrinterMessageBoxW
	#define AddForm AddFormW
	#define DeleteForm DeleteFormW
	#define GetForm GetFormW
	#define SetForm SetFormW
	#define EnumForms EnumFormsW
	#define EnumMonitors EnumMonitorsW
	#define AddMonitor AddMonitorW
	#define DeleteMonitor DeleteMonitorW
	#define EnumPorts EnumPortsW
	#define AddPort AddPortW
	#define ConfigurePort ConfigurePortW
	#define DeletePort DeletePortW
	#define GetDefaultPrinter GetDefaultPrinterW
	#define SetDefaultPrinter SetDefaultPrinterW
	#define SetPort SetPortW
	#define AddPrinterConnection AddPrinterConnectionW
	#define DeletePrinterConnection DeletePrinterConnectionW
	#define AddPrintProvidor AddPrintProvidorW
	#define DeletePrintProvidor DeletePrintProvidorW
#else
	#define PRINTER_INFO_1 PRINTER_INFO_1A
	#define PRINTER_INFO_2 PRINTER_INFO_2A
	#define PRINTER_INFO_4 PRINTER_INFO_4A
	#define PRINTER_INFO_5 PRINTER_INFO_5A
	#define PRINTER_INFO_7 PRINTER_INFO_7A
	#define PRINTER_INFO_8 PRINTER_INFO_8A
	#define PRINTER_INFO_9 PRINTER_INFO_9A
	#define JOB_INFO_1 JOB_INFO_1A
	#define JOB_INFO_2 JOB_INFO_2A
	#define ADDJOB_INFO_1 ADDJOB_INFO_1A
	#define DRIVER_INFO_1 DRIVER_INFO_1A
	#define DRIVER_INFO_2 DRIVER_INFO_2A
	#define DRIVER_INFO_3 DRIVER_INFO_3A
	#define DRIVER_INFO_4 DRIVER_INFO_4A
	#define DRIVER_INFO_5 DRIVER_INFO_5A
	#define DRIVER_INFO_6 DRIVER_INFO_6A
	#define DOC_INFO_1 DOC_INFO_1A
	#define FORM_INFO_1 FORM_INFO_1A
	#define DOC_INFO_2 DOC_INFO_2A
	#define DOC_INFO_3 DOC_INFO_3A
	#define PRINTPROCESSOR_INFO_1 PRINTPROCESSOR_INFO_1A
	#define PORT_INFO_1 PORT_INFO_1A
	#define PORT_INFO_2 PORT_INFO_2A
	#define PORT_INFO_3 PORT_INFO_3A
	#define MONITOR_INFO_1 MONITOR_INFO_1A
	#define MONITOR_INFO_2 MONITOR_INFO_2A
	#define DATATYPES_INFO_1 DATATYPES_INFO_1A
	#define PRINTER_DEFAULTS PRINTER_DEFAULTSA
	#define PRINTER_ENUM_VALUES PRINTER_ENUM_VALUESA
	#define PROVIDOR_INFO_1 PROVIDOR_INFO_1A
	#define PROVIDOR_INFO_2 PROVIDOR_INFO_2A

	#define EnumPrinters EnumPrintersA
	#define OpenPrinter OpenPrinterA
	#define ResetPrinter ResetPrinterA
	#define SetJob SetJobA
	#define GetJob GetJobA
	#define EnumJobs EnumJobsA
	#define AddPrinter AddPrinterA
	#define SetPrinter SetPrinterA
	#define GetPrinter GetPrinterA
	#define AddPrinterDriver AddPrinterDriverA
	#define AddPrinterDriverEx AddPrinterDriverExA
	#define EnumPrinterDrivers EnumPrinterDriversA
	#define GetPrinterDriver GetPrinterDriverA
	#define GetPrinterDriverDirectory GetPrinterDriverDirectoryA
	#define DeletePrinterDriver DeletePrinterDriverA
	#define DeletePrinterDriverEx DeletePrinterDriverExA
	#define AddPrintProcessor AddPrintProcessorA
	#define EnumPrintProcessors EnumPrintProcessorsA
	#define GetPrintProcessorDirectory GetPrintProcessorDirectoryA
	#define EnumPrintProcessorDatatypes EnumPrintProcessorDatatypesA
	#define DeletePrintProcessor DeletePrintProcessorA
	#define StartDocPrinter StartDocPrinterA
	#define AddJob AddJobA
	#define DocumentProperties DocumentPropertiesA
	#define AdvancedDocumentProperties AdvancedDocumentPropertiesA
	#define GetPrinterData GetPrinterDataA
	#define GetPrinterDataEx GetPrinterDataExA
	#define EnumPrinterData EnumPrinterDataA
	#define EnumPrinterDataEx EnumPrinterDataExA
	#define EnumPrinterKey EnumPrinterKeyA
	#define SetPrinterData SetPrinterDataA
	#define SetPrinterDataEx SetPrinterDataExA
	#define DeletePrinterData DeletePrinterDataA
	#define DeletePrinterDataEx DeletePrinterDataExA
	#define DeletePrinterKey DeletePrinterKeyA
	#define PrinterMessageBox PrinterMessageBoxA
	#define AddForm AddFormA
	#define DeleteForm DeleteFormA
	#define GetForm GetFormA
	#define SetForm SetFormA
	#define EnumForms EnumFormsA
	#define EnumMonitors EnumMonitorsA
	#define AddMonitor AddMonitorA
	#define DeleteMonitor DeleteMonitorA
	#define EnumPorts EnumPortsA
	#define AddPort AddPortA
	#define ConfigurePort ConfigurePortA
	#define DeletePort DeletePortA
	#define GetDefaultPrinter GetDefaultPrinterA
	#define SetDefaultPrinter SetDefaultPrinterA
	#define SetPort SetPortA
	#define AddPrinterConnection AddPrinterConnectionA
	#define DeletePrinterConnection DeletePrinterConnectionA
	#define AddPrintProvidor AddPrintProvidorA
	#define DeletePrintProvidor DeletePrintProvidorA
#endif /* UNICODE */


#endif /* WINSPOOL_H */
