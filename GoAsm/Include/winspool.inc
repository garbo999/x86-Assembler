;=============================================================;
;         winspool.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINSPOOL_INC
#Define WINSPOOL_INC


#IFDEF WINUSER_INC
	#IFNDEF PRSHT_INC
		#Include <prsht.inc>
	#ENDIF
#ENDIF

#Define DSPRINT_PUBLISH         			1
#Define DSPRINT_UPDATE          			2
#Define DSPRINT_UNPUBLISH       			3



#Define PRINTER_CONTROL_PAUSE            	1
#Define PRINTER_CONTROL_RESUME           	2
#Define PRINTER_CONTROL_PURGE            	3
#Define PRINTER_CONTROL_SET_STATUS       	4

#Define PRINTER_STATUS_PAUSED            	000000001H
#Define PRINTER_STATUS_ERROR             	000000002H
#Define PRINTER_STATUS_PENDING_DELETION  	000000004H
#Define PRINTER_STATUS_PAPER_JAM         	000000008H
#Define PRINTER_STATUS_PAPER_OUT         	000000010H
#Define PRINTER_STATUS_MANUAL_FEED       	000000020H
#Define PRINTER_STATUS_PAPER_PROBLEM     	000000040H
#Define PRINTER_STATUS_OFFLINE           	000000080H
#Define PRINTER_STATUS_IO_ACTIVE         	000000100H
#Define PRINTER_STATUS_BUSY              	000000200H
#Define PRINTER_STATUS_PRINTING          	000000400H
#Define PRINTER_STATUS_OUTPUT_BIN_FULL   	000000800H
#Define PRINTER_STATUS_NOT_AVAILABLE     	000001000H
#Define PRINTER_STATUS_WAITING           	000002000H
#Define PRINTER_STATUS_PROCESSING        	000004000H
#Define PRINTER_STATUS_INITIALIZING      	000008000H
#Define PRINTER_STATUS_WARMING_UP        	000010000H
#Define PRINTER_STATUS_TONER_LOW         	000020000H
#Define PRINTER_STATUS_NO_TONER          	000040000H
#Define PRINTER_STATUS_PAGE_PUNT         	000080000H
#Define PRINTER_STATUS_USER_INTERVENTION 	000100000H
#Define PRINTER_STATUS_OUT_OF_MEMORY     	000200000H
#Define PRINTER_STATUS_DOOR_OPEN         	000400000H
#Define PRINTER_STATUS_SERVER_UNKNOWN    	000800000H
#Define PRINTER_STATUS_POWER_SAVE        	001000000H

#Define PRINTER_ATTRIBUTE_QUEUED         	000000001H
#Define PRINTER_ATTRIBUTE_DIRECT         	000000002H
#Define PRINTER_ATTRIBUTE_DEFAULT        	000000004H
#Define PRINTER_ATTRIBUTE_SHARED         	000000008H
#Define PRINTER_ATTRIBUTE_NETWORK        	000000010H
#Define PRINTER_ATTRIBUTE_HIDDEN         	000000020H
#Define PRINTER_ATTRIBUTE_LOCAL          	000000040H

#Define PRINTER_ATTRIBUTE_ENABLE_DEVQ       000000080H
#Define PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS   000000100H
#Define PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST 000000200H

#Define PRINTER_ATTRIBUTE_WORK_OFFLINE   	000000400H
#Define PRINTER_ATTRIBUTE_ENABLE_BIDI    	000000800H
#Define PRINTER_ATTRIBUTE_RAW_ONLY       	000001000H
#Define PRINTER_ATTRIBUTE_PUBLISHED      	000002000H

#Define NO_PRIORITY   						0
#Define MAX_PRIORITY 						99
#Define MIN_PRIORITY  						1
#Define DEF_PRIORITY  						1


#Define JOB_CONTROL_PAUSE              		1
#Define JOB_CONTROL_RESUME             		2
#Define JOB_CONTROL_CANCEL             		3
#Define JOB_CONTROL_RESTART            		4
#Define JOB_CONTROL_DELETE             		5
#Define JOB_CONTROL_SENT_TO_PRINTER    		6
#Define JOB_CONTROL_LAST_PAGE_EJECTED  		7

#Define JOB_STATUS_PAUSED               	000000001H
#Define JOB_STATUS_ERROR                	000000002H
#Define JOB_STATUS_DELETING             	000000004H
#Define JOB_STATUS_SPOOLING             	000000008H
#Define JOB_STATUS_PRINTING             	000000010H
#Define JOB_STATUS_OFFLINE              	000000020H
#Define JOB_STATUS_PAPEROUT             	000000040H
#Define JOB_STATUS_PRINTED              	000000080H
#Define JOB_STATUS_DELETED              	000000100H
#Define JOB_STATUS_BLOCKED_DEVQ         	000000200H
#Define JOB_STATUS_USER_INTERVENTION    	000000400H
#Define JOB_STATUS_RESTART              	000000800H

#Define JOB_POSITION_UNSPECIFIED       		0

#Define DPD_DELETE_UNUSED_FILES          	000000001H
#Define DPD_DELETE_SPECIFIC_VERSION      	000000002H
#Define DPD_DELETE_ALL_FILES             	000000004H

#Define APD_STRICT_UPGRADE               	000000001H
#Define APD_STRICT_DOWNGRADE             	000000002H
#Define APD_COPY_ALL_FILES               	000000004H
#Define APD_COPY_NEW_FILES               	000000008H

#Define DI_CHANNEL              			1

#Define DI_READ_SPOOL_JOB       			3

#Define FORM_USER       					000000000H
#Define FORM_BUILTIN    					000000001H
#Define FORM_PRINTER    					000000002H

#Define PORT_TYPE_WRITE         			00001H
#Define PORT_TYPE_READ          			00002H
#Define PORT_TYPE_REDIRECTED    			00004H
#Define PORT_TYPE_NET_ATTACHED  			00008H


#Define PORT_STATUS_TYPE_ERROR      		1
#Define PORT_STATUS_TYPE_WARNING    		2
#Define PORT_STATUS_TYPE_INFO       		3

#Define PORT_STATUS_OFFLINE                	1
#Define PORT_STATUS_PAPER_JAM              	2
#Define PORT_STATUS_PAPER_OUT              	3
#Define PORT_STATUS_OUTPUT_BIN_FULL        	4
#Define PORT_STATUS_PAPER_PROBLEM          	5
#Define PORT_STATUS_NO_TONER               	6
#Define PORT_STATUS_DOOR_OPEN              	7
#Define PORT_STATUS_USER_INTERVENTION      	8
#Define PORT_STATUS_OUT_OF_MEMORY          	9

#Define PORT_STATUS_TONER_LOW          		10

#Define PORT_STATUS_WARMING_UP         		11
#Define PORT_STATUS_POWER_SAVE              12

#Define PRINTER_ENUM_DEFAULT     			000000001H
#Define PRINTER_ENUM_LOCAL       			000000002H
#Define PRINTER_ENUM_CONNECTIONS 			000000004H
#Define PRINTER_ENUM_FAVORITE    			000000004H
#Define PRINTER_ENUM_NAME        			000000008H
#Define PRINTER_ENUM_REMOTE      			000000010H
#Define PRINTER_ENUM_SHARED      			000000020H
#Define PRINTER_ENUM_NETWORK     			000000040H

#Define PRINTER_ENUM_EXPAND      			000004000H
#Define PRINTER_ENUM_CONTAINER   			000008000H

#Define PRINTER_ENUM_ICONMASK    			000FF0000H
#Define PRINTER_ENUM_ICON1       			000010000H
#Define PRINTER_ENUM_ICON2       			000020000H
#Define PRINTER_ENUM_ICON3       			000040000H
#Define PRINTER_ENUM_ICON4       			000080000H
#Define PRINTER_ENUM_ICON5       			000100000H
#Define PRINTER_ENUM_ICON6       			000200000H
#Define PRINTER_ENUM_ICON7       			000400000H
#Define PRINTER_ENUM_ICON8       			000800000H

#Define PRINTER_NOTIFY_TYPE 				000H
#Define JOB_NOTIFY_TYPE     				001H

#Define PRINTER_NOTIFY_FIELD_SERVER_NAME       		000H
#Define PRINTER_NOTIFY_FIELD_PRINTER_NAME       	001H
#Define PRINTER_NOTIFY_FIELD_SHARE_NAME         	002H
#Define PRINTER_NOTIFY_FIELD_PORT_NAME          	003H
#Define PRINTER_NOTIFY_FIELD_DRIVER_NAME        	004H
#Define PRINTER_NOTIFY_FIELD_COMMENT            	005H
#Define PRINTER_NOTIFY_FIELD_LOCATION           	006H
#Define PRINTER_NOTIFY_FIELD_DEVMODE            	007H
#Define PRINTER_NOTIFY_FIELD_SEPFILE            	008H
#Define PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR    	009H
#Define PRINTER_NOTIFY_FIELD_PARAMETERS         	00AH
#Define PRINTER_NOTIFY_FIELD_DATATYPE           	00BH
#Define PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR	00CH
#Define PRINTER_NOTIFY_FIELD_ATTRIBUTES             00DH
#Define PRINTER_NOTIFY_FIELD_PRIORITY               00EH
#Define PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY       00FH
#Define PRINTER_NOTIFY_FIELD_START_TIME             010H
#Define PRINTER_NOTIFY_FIELD_UNTIL_TIME             011H
#Define PRINTER_NOTIFY_FIELD_STATUS                 012H
#Define PRINTER_NOTIFY_FIELD_STATUS_STRING          013H
#Define PRINTER_NOTIFY_FIELD_CJOBS                  014H
#Define PRINTER_NOTIFY_FIELD_AVERAGE_PPM            015H
#Define PRINTER_NOTIFY_FIELD_TOTAL_PAGES            016H
#Define PRINTER_NOTIFY_FIELD_PAGES_PRINTED          017H
#Define PRINTER_NOTIFY_FIELD_TOTAL_BYTES            018H
#Define PRINTER_NOTIFY_FIELD_BYTES_PRINTED          019H
#Define PRINTER_NOTIFY_FIELD_OBJECT_GUID            01AH

#Define JOB_NOTIFY_FIELD_PRINTER_NAME			000H
#Define JOB_NOTIFY_FIELD_MACHINE_NAME       	001H
#Define JOB_NOTIFY_FIELD_PORT_NAME          	002H
#Define JOB_NOTIFY_FIELD_USER_NAME          	003H
#Define JOB_NOTIFY_FIELD_NOTIFY_NAME        	004H
#Define JOB_NOTIFY_FIELD_DATATYPE           	005H
#Define JOB_NOTIFY_FIELD_PRINT_PROCESSOR    	006H
#Define JOB_NOTIFY_FIELD_PARAMETERS         	007H
#Define JOB_NOTIFY_FIELD_DRIVER_NAME        	008H
#Define JOB_NOTIFY_FIELD_DEVMODE            	009H
#Define JOB_NOTIFY_FIELD_STATUS             	00AH
#Define JOB_NOTIFY_FIELD_STATUS_STRING      	00BH
#Define JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR    00CH
#Define JOB_NOTIFY_FIELD_DOCUMENT               00DH
#Define JOB_NOTIFY_FIELD_PRIORITY               00EH
#Define JOB_NOTIFY_FIELD_POSITION               00FH
#Define JOB_NOTIFY_FIELD_SUBMITTED              010H
#Define JOB_NOTIFY_FIELD_START_TIME             011H
#Define JOB_NOTIFY_FIELD_UNTIL_TIME             012H
#Define JOB_NOTIFY_FIELD_TIME                   013H
#Define JOB_NOTIFY_FIELD_TOTAL_PAGES            014H
#Define JOB_NOTIFY_FIELD_PAGES_PRINTED          015H
#Define JOB_NOTIFY_FIELD_TOTAL_BYTES            016H
#Define JOB_NOTIFY_FIELD_BYTES_PRINTED          017H

#Define PRINTER_NOTIFY_OPTIONS_REFRESH			001H

#Define PRINTER_NOTIFY_INFO_DISCARDED			001H

#Define PRINTER_CHANGE_ADD_PRINTER              	000000001H
#Define PRINTER_CHANGE_SET_PRINTER              	000000002H
#Define PRINTER_CHANGE_DELETE_PRINTER           	000000004H
#Define PRINTER_CHANGE_FAILED_CONNECTION_PRINTER	000000008H
#Define PRINTER_CHANGE_PRINTER                  	0000000FFH
#Define PRINTER_CHANGE_ADD_JOB                  	000000100H
#Define PRINTER_CHANGE_SET_JOB                  	000000200H
#Define PRINTER_CHANGE_DELETE_JOB               	000000400H
#Define PRINTER_CHANGE_WRITE_JOB                	000000800H
#Define PRINTER_CHANGE_JOB                      	00000FF00H
#Define PRINTER_CHANGE_ADD_FORM                 	000010000H
#Define PRINTER_CHANGE_SET_FORM                 	000020000H
#Define PRINTER_CHANGE_DELETE_FORM              	000040000H
#Define PRINTER_CHANGE_FORM                     	000070000H
#Define PRINTER_CHANGE_ADD_PORT                 	000100000H
#Define PRINTER_CHANGE_CONFIGURE_PORT           	000200000H
#Define PRINTER_CHANGE_DELETE_PORT              	000400000H
#Define PRINTER_CHANGE_PORT                     	000700000H
#Define PRINTER_CHANGE_ADD_PRINT_PROCESSOR      	001000000H
#Define PRINTER_CHANGE_DELETE_PRINT_PROCESSOR   	004000000H
#Define PRINTER_CHANGE_PRINT_PROCESSOR          	007000000H
#Define PRINTER_CHANGE_ADD_PRINTER_DRIVER       	010000000H
#Define PRINTER_CHANGE_SET_PRINTER_DRIVER       	020000000H
#Define PRINTER_CHANGE_DELETE_PRINTER_DRIVER    	040000000H
#Define PRINTER_CHANGE_PRINTER_DRIVER           	070000000H
#Define PRINTER_CHANGE_TIMEOUT                  	080000000H
#Define PRINTER_CHANGE_ALL                      	07777FFFFH

#Define PRINTER_ERROR_INFORMATION   			080000000H
#Define PRINTER_ERROR_WARNING       			040000000H
#Define PRINTER_ERROR_SEVERE        			020000000H

#Define PRINTER_ERROR_OUTOFPAPER    			000000001H
#Define PRINTER_ERROR_JAM           			000000002H
#Define PRINTER_ERROR_OUTOFTONER    			000000004H

#IF STRINGS UNICODE
	#Define SPLREG_DEFAULT_SPOOL_DIRECTORY             	L"DefaultSpoolDirectory"
	#Define SPLREG_PORT_THREAD_PRIORITY_DEFAULT        	L"PortThreadPriorityDefault"
	#Define SPLREG_PORT_THREAD_PRIORITY                	L"PortThreadPriority"
	#Define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT   	L"SchedulerThreadPriorityDefault"
	#Define SPLREG_SCHEDULER_THREAD_PRIORITY           	L"SchedulerThreadPriority"
	#Define SPLREG_BEEP_ENABLED                        	L"BeepEnabled"
	#Define SPLREG_NET_POPUP                           	L"NetPopup"
	#Define SPLREG_EVENT_LOG                           	L"EventLog"
	#Define SPLREG_MAJOR_VERSION                       	L"MajorVersion"
	#Define SPLREG_MINOR_VERSION                       	L"MinorVersion"
	#Define SPLREG_ARCHITECTURE                        	L"Architecture"
	#Define SPLREG_OS_VERSION                          	L"OSVersion"
	#Define SPLREG_DS_PRESENT                          	L"DsPresent"
#ELSE
	#Define SPLREG_DEFAULT_SPOOL_DIRECTORY             	"DefaultSpoolDirectory"
	#Define SPLREG_PORT_THREAD_PRIORITY_DEFAULT        	"PortThreadPriorityDefault"
	#Define SPLREG_PORT_THREAD_PRIORITY                	"PortThreadPriority"
	#Define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT   	"SchedulerThreadPriorityDefault"
	#Define SPLREG_SCHEDULER_THREAD_PRIORITY           	"SchedulerThreadPriority"
	#Define SPLREG_BEEP_ENABLED                        	"BeepEnabled"
	#Define SPLREG_NET_POPUP                           	"NetPopup"
	#Define SPLREG_EVENT_LOG                           	"EventLog"
	#Define SPLREG_MAJOR_VERSION                       	"MajorVersion"
	#Define SPLREG_MINOR_VERSION                       	"MinorVersion"
	#Define SPLREG_ARCHITECTURE                        	"Architecture"
	#Define SPLREG_OS_VERSION                          	"OSVersion"
	#Define SPLREG_DS_PRESENT                          	"DsPresent"
#ENDIF

#Define SERVER_ACCESS_ADMINISTER    		000000001H
#Define SERVER_ACCESS_ENUMERATE     		000000002H

#Define PRINTER_ACCESS_ADMINISTER   		000000004H
#Define PRINTER_ACCESS_USE          		000000008H

#Define JOB_ACCESS_ADMINISTER       		000000010H

#Define SERVER_ALL_ACCESS    				(STANDARD_RIGHTS_REQUIRED | SERVER_ACCESS_ADMINISTER | SERVER_ACCESS_ENUMERATE)
#Define SERVER_READ          				(STANDARD_RIGHTS_READ  | SERVER_ACCESS_ENUMERATE)
#Define SERVER_WRITE         				(STANDARD_RIGHTS_WRITE | SERVER_ACCESS_ADMINISTER | SERVER_ACCESS_ENUMERATE)
#Define SERVER_EXECUTE       				(STANDARD_RIGHTS_EXECUTE | SERVER_ACCESS_ENUMERATE)

#Define PRINTER_ALL_ACCESS    				(STANDARD_RIGHTS_REQUIRED | PRINTER_ACCESS_ADMINISTER | PRINTER_ACCESS_USE)
#Define PRINTER_READ          				(STANDARD_RIGHTS_READ | PRINTER_ACCESS_USE)
#Define PRINTER_WRITE         				(STANDARD_RIGHTS_WRITE | PRINTER_ACCESS_USE)
#Define PRINTER_EXECUTE       				(STANDARD_RIGHTS_EXECUTE | PRINTER_ACCESS_USE)

#Define JOB_ALL_ACCESS         				(STANDARD_RIGHTS_REQUIRED | JOB_ACCESS_ADMINISTER)
#Define JOB_READ               				(STANDARD_RIGHTS_READ | JOB_ACCESS_ADMINISTER)
#Define JOB_WRITE              				(STANDARD_RIGHTS_WRITE | JOB_ACCESS_ADMINISTER)
#Define JOB_EXECUTE            				(STANDARD_RIGHTS_EXECUTE | JOB_ACCESS_ADMINISTER)

#IF STRINGS UNICODE
	#Define SPLDS_SPOOLER_KEY                       L"DsSpooler"
	#Define SPLDS_DRIVER_KEY                        L"DsDriver"
	#Define SPLDS_USER_KEY                          L"DsUser"

	#Define SPLDS_ASSET_NUMBER                      L"assetNumber"
	#Define SPLDS_BYTES_PER_MINUTE                  L"bytesPerMinute"
	#Define SPLDS_DESCRIPTION                       L"description"
	#Define SPLDS_DRIVER_NAME                       L"driverName"
	#Define SPLDS_DRIVER_VERSION                    L"driverVersion"
	#Define SPLDS_LOCATION                          L"location"
	#Define SPLDS_PORT_NAME                         L"portName"
	#Define SPLDS_PRINT_ATTRIBUTES                  L"printAttributes"
	#Define SPLDS_PRINT_BIN_NAMES                   L"printBinNames"
	#Define SPLDS_PRINT_COLLATE                     L"printCollate"
	#Define SPLDS_PRINT_COLOR                       L"printColor"
	#Define SPLDS_PRINT_DUPLEX_SUPPORTED            L"printDuplexSupported"
	#Define SPLDS_PRINT_END_TIME                    L"printEndTime"
	#Define SPLDS_PRINTER_CLASS                     L"printQueue"
	#Define SPLDS_PRINTER_NAME                      L"printerName"
	#Define SPLDS_PRINT_KEEP_PRINTED_JOBS           L"printKeepPrintedJobs"
	#Define SPLDS_PRINT_LANGUAGE                    L"printLanguage"
	#Define SPLDS_PRINT_MAC_ADDRESS                 L"printMACAddress"
	#Define SPLDS_PRINT_MAX_X_EXTENT                L"printMaxXExtent"
	#Define SPLDS_PRINT_MAX_Y_EXTENT                L"printMaxYExtent"
	#Define SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED    L"printMaxResolutionSupported"
	#Define SPLDS_PRINT_MEDIA_READY                 L"printMediaReady"
	#Define SPLDS_PRINT_MEDIA_SUPPORTED             L"printMediaSupported"
	#Define SPLDS_PRINT_MEMORY                      L"printMemory"
	#Define SPLDS_PRINT_MIN_X_EXTENT                L"printMinXExtent"
	#Define SPLDS_PRINT_MIN_Y_EXTENT                L"printMinYExtent"
	#Define SPLDS_PRINT_NETWORK_ADDRESS             L"printNetworkAddress"
	#Define SPLDS_PRINT_NOTIFY                      L"printNotify"
	#Define SPLDS_PRINT_NUMBER_UP                   L"printNumberUp"
	#Define SPLDS_PRINT_ORIENTATIONS_SUPPORTED      L"printOrientationsSupported"
	#Define SPLDS_PRINT_OWNER                       L"printOwner"
	#Define SPLDS_PRINT_RATE                        L"printRate"
	#Define SPLDS_PRINT_RATE_UNIT                   L"printRateUnit"
	#Define SPLDS_PRINT_SEPARATOR_FILE              L"printSeparatorFile"
	#Define SPLDS_PRINT_SHARE_NAME                  L"printShareName"
	#Define SPLDS_PRINT_SPOOLING                    L"printSpooling"
	#Define SPLDS_PRINT_STAPLING_SUPPORTED          L"printStaplingSupported"
	#Define SPLDS_PRINT_START_TIME                  L"printStartTime"
	#Define SPLDS_PRINT_STATUS                      L"printStatus"
	#Define SPLDS_PRIORITY                          L"priority"
	#Define SPLDS_SERVER_NAME                       L"serverName"
	#Define SPLDS_UNC_NAME                          L"uNCName"
	#Define SPLDS_URL                               L"url"
	#Define SPLDS_VERSION_NUMBER                    L"versionNumber"
#ELSE
	#Define SPLDS_SPOOLER_KEY                       "DsSpooler"
	#Define SPLDS_DRIVER_KEY                        "DsDriver"
	#Define SPLDS_USER_KEY                          "DsUser"

	#Define SPLDS_ASSET_NUMBER                      "assetNumber"
	#Define SPLDS_BYTES_PER_MINUTE                  "bytesPerMinute"
	#Define SPLDS_DESCRIPTION                       "description"
	#Define SPLDS_DRIVER_NAME                       "driverName"
	#Define SPLDS_DRIVER_VERSION                    "driverVersion"
	#Define SPLDS_LOCATION                          "location"
	#Define SPLDS_PORT_NAME                         "portName"
	#Define SPLDS_PRINT_ATTRIBUTES                  "printAttributes"
	#Define SPLDS_PRINT_BIN_NAMES                   "printBinNames"
	#Define SPLDS_PRINT_COLLATE                     "printCollate"
	#Define SPLDS_PRINT_COLOR                       "printColor"
	#Define SPLDS_PRINT_DUPLEX_SUPPORTED            "printDuplexSupported"
	#Define SPLDS_PRINT_END_TIME                    "printEndTime"
	#Define SPLDS_PRINTER_CLASS                     "printQueue"
	#Define SPLDS_PRINTER_NAME                      "printerName"
	#Define SPLDS_PRINT_KEEP_PRINTED_JOBS           "printKeepPrintedJobs"
	#Define SPLDS_PRINT_LANGUAGE                    "printLanguage"
	#Define SPLDS_PRINT_MAC_ADDRESS                 "printMACAddress"
	#Define SPLDS_PRINT_MAX_X_EXTENT                "printMaxXExtent"
	#Define SPLDS_PRINT_MAX_Y_EXTENT                "printMaxYExtent"
	#Define SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED    "printMaxResolutionSupported"
	#Define SPLDS_PRINT_MEDIA_READY                 "printMediaReady"
	#Define SPLDS_PRINT_MEDIA_SUPPORTED             "printMediaSupported"
	#Define SPLDS_PRINT_MEMORY                      "printMemory"
	#Define SPLDS_PRINT_MIN_X_EXTENT                "printMinXExtent"
	#Define SPLDS_PRINT_MIN_Y_EXTENT                "printMinYExtent"
	#Define SPLDS_PRINT_NETWORK_ADDRESS             "printNetworkAddress"
	#Define SPLDS_PRINT_NOTIFY                      "printNotify"
	#Define SPLDS_PRINT_NUMBER_UP                   "printNumberUp"
	#Define SPLDS_PRINT_ORIENTATIONS_SUPPORTED      "printOrientationsSupported"
	#Define SPLDS_PRINT_OWNER                       "printOwner"
	#Define SPLDS_PRINT_RATE                        "printRate"
	#Define SPLDS_PRINT_RATE_UNIT                   "printRateUnit"
	#Define SPLDS_PRINT_SEPARATOR_FILE              "printSeparatorFile"
	#Define SPLDS_PRINT_SHARE_NAME                  "printShareName"
	#Define SPLDS_PRINT_SPOOLING                    "printSpooling"
	#Define SPLDS_PRINT_STAPLING_SUPPORTED          "printStaplingSupported"
	#Define SPLDS_PRINT_START_TIME                  "printStartTime"
	#Define SPLDS_PRINT_STATUS                      "printStatus"
	#Define SPLDS_PRIORITY                          "priority"
	#Define SPLDS_SERVER_NAME                       "serverName"
	#Define SPLDS_UNC_NAME                          "uNCName"
	#Define SPLDS_URL                               "url"
	#Define SPLDS_VERSION_NUMBER                    "versionNumber"
#ENDIF

#IF STRINGS UNICODE
	#Define SPLDS_PRINTER_NAME_ALIASES              L"printerNameAliases"
	#Define SPLDS_PRINTER_LOCATIONS                 L"printerLocations"
	#Define SPLDS_PRINTER_MODEL                     L"printerModel"
#ELSE
	#Define SPLDS_PRINTER_NAME_ALIASES              "printerNameAliases"
	#Define SPLDS_PRINTER_LOCATIONS                 "printerLocations"
	#Define SPLDS_PRINTER_MODEL                     "printerModel"
#ENDIF

#Define PRINTER_HTML_VIEW_QUEUE				0
#Define PRINTER_HTML_VIEW_PRINTPROPERTIES	1
#Define PRINTER_HTML_VIEW_INSTALL			2
#Define PRINTER_HTML_VIEW_JOBPROPERTIES		3


PRINTER_INFO_1A Struct
	Flags DD
	pDescription DD
	pName DD
	pComment DD
EndS

PRINTER_INFO_1W Struct
	Flags DD
	pDescription DD
	pName DD
	pComment DD
EndS

PRINTER_INFO_2A Struct
	pServerName DD
	pPrinterName DD
	pShareName DD
	pPortName DD
	pDriverName DD
	pComment DD
	pLocation DD
	pDevMode DD
	pSepFile DD
	pPrintProcessor DD
	pDatatype DD
	pParameters DD
	pSecurityDescriptor DD
	Attributes DD
	Priority DD
	DefaultPriority DD
	StartTime DD
	UntilTime DD
	Status DD
	cJobs DD
	AveragePPM DD
EndS

PRINTER_INFO_2W Struct
	pServerName DD
	pPrinterName DD
	pShareName DD
	pPortName DD
	pDriverName DD
	pComment DD
	pLocation DD
	pDevMode DD
	pSepFile DD
	pPrintProcessor DD
	pDatatype DD
	pParameters DD
	pSecurityDescriptor DD
	Attributes DD
	Priority DD
	DefaultPriority DD
	StartTime DD
	UntilTime DD
	Status DD
	cJobs DD
	AveragePPM DD
EndS

PRINTER_INFO_3 Struct
	pSecurityDescriptor DD
EndS

PRINTER_INFO_4A Struct
	pPrinterName DD
	ddpServerName DD
	Attributes DD
EndS

PRINTER_INFO_4W Struct
	pPrinterName DD
	ddpServerName DD
	Attributes DD
EndS

PRINTER_INFO_5A Struct
	pPrinterName DD
	pPortName DD
	Attributes DD
	DeviceNotSelectedTimeout DD
	TransmissionRetryTimeout DD
EndS

PRINTER_INFO_5W Struct
	pPrinterName DD
	pPortName DD
	Attributes DD
	DeviceNotSelectedTimeout DD
	TransmissionRetryTimeout DD
EndS

PRINTER_INFO_6 Struct
	dwStatus DD
EndS

PRINTER_INFO_7A Struct
	pszObjectGUID DD
	dwAction DD
EndS

PRINTER_INFO_7W Struct
	pszObjectGUID DD
	dwAction DD
EndS

JOB_INFO_1A Struct
	JobId DD
	pPrinterName DD
	pMachineName DD
	pUserName DD
	pDocument DD
	pDatatype DD
	pStatus DD
	Status DD
	Priority DD
	Position DD
	TotalPages DD
	PagesPrinted DD
	Submitted SYSTEMTIME <>
EndS

JOB_INFO_1W Struct
	JobId DD
	pPrinterName DD
	pMachineName DD
	pUserName DD
	pDocument DD
	pDatatype DD
	pStatus DD
	Status DD
	Priority DD
	Position DD
	TotalPages DD
	PagesPrinted DD
	Submitted SYSTEMTIME <>
EndS

JOB_INFO_2A Struct
	JobId DD
	pPrinterName DD
	pMachineName DD
	pUserName DD
	pDocument DD
	pNotifyName DD
	pDatatype DD
	pPrintProcessor DD
	pParameters DD
	pDriverName DD
	pDevMode DD
	pStatus DD
	pSecurityDescriptor DD
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
EndS

JOB_INFO_2W Struct
	JobId DD
	pPrinterName DD
	pMachineName DD
	pUserName DD
	pDocument DD
	pNotifyName DD
	pDatatype DD
	pPrintProcessor DD
	pParameters DD
	pDriverName DD
	pDevMode DD
	pStatus DD
	pSecurityDescriptor DD
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
EndS

JOB_INFO_3 Struct
	JobId DD
	NextJobId DD
	Reserved DD
EndS

ADDJOB_INFO_1A Struct
	Path DD
	JobId DD
EndS

ADDJOB_INFO_1W Struct
	Path DD
	JobId DD
EndS

DRIVER_INFO_1A Struct
	pName DD
EndS

DRIVER_INFO_1W Struct
	pName DD
EndS

DRIVER_INFO_2A Struct
	cVersion DD
	pName DD
	pEnvironment DD
	pDriverPath DD
	pDataFile DD
	pConfigFile DD
EndS

DRIVER_INFO_2W Struct
	cVersion DD
	pName DD
	pEnvironment DD
	pDriverPath DD
	pDataFile DD
	pConfigFile DD
EndS

DRIVER_INFO_3A Struct
	cVersion DD
	pName DD
	pEnvironment DD
	pDriverPath DD
	pDataFile DD
	pConfigFile DD
	pHelpFile DD
	pDependentFiles DD
	pMonitorName DD
	pDefaultDataType DD
EndS

DRIVER_INFO_3W Struct
	cVersion DD
	pName DD
	pEnvironment DD
	pDriverPath DD
	pDataFile DD
	pConfigFile DD
	pHelpFile DD
	pDependentFiles DD
	pMonitorName DD
	pDefaultDataType DD
EndS

DOC_INFO_1A Struct
	pDocName DD
	pOutputFile DD
	pDatatype DD
EndS

DOC_INFO_1W Struct
	pDocName DD
	pOutputFile DD
	pDatatype DD
EndS

FORM_INFO_1A Struct
	Flags DD
	pName DD
	Size SIZEL <>
	ImageableArea RECTL <>
EndS

FORM_INFO_1W Struct
	Flags DD
	pName DD
	Size SIZEL <>
	ImageableArea RECTL <>
EndS

DOC_INFO_2A Struct
	pDocName DD
	pOutputFile DD
	pDatatype DD
	dwMode DD
	JobId DD
EndS

DOC_INFO_2W Struct
	pDocName DD
	pOutputFile DD
	pDatatype DD
	dwMode DD
	JobId DD
EndS

PRINTPROCESSOR_INFO_1A Struct
	pName DD
EndS

PRINTPROCESSOR_INFO_1W Struct
	pName DD
EndS

PRINTPROCESSOR_CAPS_1 Struct
	dwLevel DD
	dwNupOptions DD
	dwPageOrderFlags DD
	dwNumberOfCopies DD
EndS

PORT_INFO_1A Struct
	pName DD
EndS

PORT_INFO_1W Struct
	pName DD
EndS

PORT_INFO_2A Struct
	pPortName DD
	pMonitorName DD
	pDescription DD
	fPortType DD
	Reserved DD
EndS

PORT_INFO_2W Struct
	pPortName DD
	pMonitorName DD
	pDescription DD
	fPortType DD
	Reserved DD
EndS

PORT_INFO_3A Struct
	dwStatus DD
	pszStatus DD
	dwSeverity DD
EndS

PORT_INFO_3W Struct
	dwStatus DD
	pszStatus DD
	dwSeverity DD
EndS

MONITOR_INFO_1A Struct
	pName DD
EndS

MONITOR_INFO_1W Struct
	pName DD
EndS

MONITOR_INFO_2A Struct
	pName DD
	pEnvironment DD
	pDLLName DD
EndS

MONITOR_INFO_2W Struct
	pName DD
	pEnvironment DD
	pDLLName DD
EndS

DATATYPES_INFO_1A Struct
	pName DD
EndS

DATATYPES_INFO_1W Struct
	pName DD
EndS

PRINTER_DEFAULTSA Struct
	pDatatype DD
	pDevMode DD
	DesiredAccess DD
EndS

PRINTER_DEFAULTSW Struct
	pDatatype DD
	pDevMode DD
	DesiredAccess DD
EndS

PRINTER_ENUM_VALUESA Struct
	pValueName DD
	cbValueName DD
	dwType DD
	pData DD
	cbData DD
EndS

PRINTER_ENUM_VALUESW Struct
	pValueName DD
	cbValueName DD
	dwType DD
	pData DD
	cbData DD
EndS

PRINTER_NOTIFY_OPTIONS_TYPE struct
	Type DW
	Reserved0 DW
	Reserved1 DD
	Reserved2 DD
	Count DD
	pFields DD
EndS

PRINTER_NOTIFY_OPTIONS struct
	Version DD
	Flags DD
	Count DD
	pTypes PPRINTER_NOTIFY_OPTIONS_TYPE <>
EndS

PRINTER_NOTIFY_INFO_DATA struct
	Type DW
	Field DW
	Reserved DD
	Id DD
	NotifyData Union
	adwData DD 2 Dup ?
		Data Struct
			cbBuf DD
			pBuf DD
		EndS
	EndUnion
EndS

PRINTER_NOTIFY_INFO struct
	Version DD
	Flags DD
	Count DD
	aData PRINTER_NOTIFY_INFO_DATA <>
EndS

PROVIDOR_INFO_1A struct
	pName DD
	pEnvironment DD
	pDLLName DD
EndS

PROVIDOR_INFO_1W struct
	pName DD
	pEnvironment DD
	pDLLName DD
EndS


#IF STRINGS UNICODE
	#Define PRINTER_INFO_1 PRINTER_INFO_1W
	#Define PRINTER_INFO_2 PRINTER_INFO_2W
	#Define PRINTER_INFO_4 PRINTER_INFO_4W
	#Define PRINTER_INFO_5 PRINTER_INFO_5W
	#Define PRINTER_INFO_7 PRINTER_INFO_7W
	#Define JOB_INFO_1 JOB_INFO_1W
	#Define JOB_INFO_2 JOB_INFO_2W
	#Define ADDJOB_INFO_1 ADDJOB_INFO_1W
	#Define DRIVER_INFO_1 DRIVER_INFO_1W
	#Define DRIVER_INFO_2 DRIVER_INFO_2W
	#Define DRIVER_INFO_3 DRIVER_INFO_3W
	#Define DOC_INFO_1 DOC_INFO_1W
	#Define FORM_INFO_1 FORM_INFO_1W
	#Define DOC_INFO_2 DOC_INFO_2W
	#Define PRINTPROCESSOR_INFO_1 PRINTPROCESSOR_INFO_1W
	#Define PORT_INFO_1 PORT_INFO_1W
	#Define PORT_INFO_2 PORT_INFO_2W
	#Define PORT_INFO_3 PORT_INFO_3W
	#Define MONITOR_INFO_1 MONITOR_INFO_1W
	#Define MONITOR_INFO_2 MONITOR_INFO_2W
	#Define DATATYPES_INFO_1 DATATYPES_INFO_1W
	#Define PRINTER_DEFAULTS PRINTER_DEFAULTSW
	#Define PRINTER_ENUM_VALUES PRINTER_ENUM_VALUESW
	#Define EnumPrinters EnumPrintersW
	#Define OpenPrinter OpenPrinterW
	#Define ResetPrinter ResetPrinterW
	#Define SetJob SetJobW
	#Define GetJob GetJobW
	#Define EnumJobs EnumJobsW
	#Define AddPrinter AddPrinterW
	#Define SetPrinter SetPrinterW
	#Define GetPrinter GetPrinterW
	#Define AddPrinterDriver AddPrinterDriverW
	#Define AddPrinterDriverEx AddPrinterDriverExW
	#Define EnumPrinterDrivers EnumPrinterDriversW
	#Define GetPrinterDriver GetPrinterDriverW
	#Define GetPrinterDriverDirectory GetPrinterDriverDirectoryW
	#Define DeletePrinterDriver DeletePrinterDriverW
	#Define DeletePrinterDriverEx DeletePrinterDriverExW
	#Define AddPerMachineConnection AddPerMachineConnectionW
	#Define DeletePerMachineConnection DeletePerMachineConnectionW
	#Define EnumPerMachineConnections EnumPerMachineConnectionsW
	#Define AddPrintProcessor AddPrintProcessorW
	#Define EnumPrintProcessors EnumPrintProcessorsW
	#Define GetPrintProcessorDirectory GetPrintProcessorDirectoryW
	#Define EnumPrintProcessorDatatypes EnumPrintProcessorDatatypesW
	#Define DeletePrintProcessor DeletePrintProcessorW
	#Define StartDocPrinter StartDocPrinterW
	#Define AddJob AddJobW
	#Define DocumentProperties DocumentPropertiesW
	#Define AdvancedDocumentProperties AdvancedDocumentPropertiesW
	#Define GetPrinterData GetPrinterDataW
	#Define EnumPrinterData EnumPrinterDataW
	#Define EnumPrinterDataEx EnumPrinterDataExW
	#Define EnumPrinterKey EnumPrinterKeyW
	#Define SetPrinterData SetPrinterDataW
	#Define SetPrinterDataEx SetPrinterDataExW
	#Define DeletePrinterData DeletePrinterDataW
	#Define DeletePrinterDataEx DeletePrinterDataExW
	#Define DeletePrinterKey DeletePrinterKeyW
	#Define PrinterMessageBox PrinterMessageBoxW
	#Define AddForm AddFormW
	#Define DeleteForm DeleteFormW
	#Define GetForm GetFormW
	#Define SetForm SetFormW
	#Define EnumForms EnumFormsW
	#Define EnumMonitors EnumMonitorsW
	#Define AddMonitor AddMonitorW
	#Define DeleteMonitor DeleteMonitorW
	#Define EnumPorts EnumPortsW
	#Define AddPort AddPortW
	#Define ConfigurePort ConfigurePortW
	#Define DeletePort DeletePortW
	#Define SetPort SetPortW
	#Define AddPrinterConnection AddPrinterConnectionW
	#Define DeletePrinterConnection DeletePrinterConnectionW
	#Define PROVIDOR_INFO_1 PROVIDOR_INFO_1W
	#Define AddPrintProvidor AddPrintProvidorW
	#Define DeletePrintProvidor DeletePrintProvidorW
	#Define SetPrinterHTMLView SetPrinterHTMLViewW
	#Define GetPrinterHTMLView GetPrinterHTMLViewW
#ELSE
	#Define PRINTER_INFO_1 PRINTER_INFO_1A
	#Define PRINTER_INFO_2 PRINTER_INFO_2A
	#Define PRINTER_INFO_4 PRINTER_INFO_4A
	#Define PRINTER_INFO_5 PRINTER_INFO_5A
	#Define PRINTER_INFO_7 PRINTER_INFO_7A
	#Define JOB_INFO_1 JOB_INFO_1A
	#Define JOB_INFO_2 JOB_INFO_2A
	#Define ADDJOB_INFO_1 ADDJOB_INFO_1A
	#Define DRIVER_INFO_1 DRIVER_INFO_1A
	#Define DRIVER_INFO_2 DRIVER_INFO_2A
	#Define DRIVER_INFO_3 DRIVER_INFO_3A
	#Define DOC_INFO_1 DOC_INFO_1A
	#Define FORM_INFO_1 FORM_INFO_1A
	#Define DOC_INFO_2 DOC_INFO_2A
	#Define PRINTPROCESSOR_INFO_1 PRINTPROCESSOR_INFO_1A
	#Define PORT_INFO_1 PORT_INFO_1A
	#Define PORT_INFO_2 PORT_INFO_2A
	#Define PORT_INFO_3 PORT_INFO_3A
	#Define MONITOR_INFO_1 MONITOR_INFO_1A
	#Define MONITOR_INFO_2 MONITOR_INFO_2A
	#Define DATATYPES_INFO_1 DATATYPES_INFO_1A
	#Define PRINTER_DEFAULTS PRINTER_DEFAULTSA
	#Define PRINTER_ENUM_VALUES PRINTER_ENUM_VALUESA
	#Define EnumPrinters EnumPrintersA
	#Define OpenPrinter OpenPrinterA
	#Define ResetPrinter ResetPrinterA
	#Define SetJob SetJobA
	#Define GetJob GetJobA
	#Define EnumJobs EnumJobsA
	#Define AddPrinter AddPrinterA
	#Define SetPrinter SetPrinterA
	#Define GetPrinter GetPrinterA
	#Define AddPrinterDriver AddPrinterDriverA
	#Define AddPrinterDriverEx AddPrinterDriverExA
	#Define EnumPrinterDrivers EnumPrinterDriversA
	#Define GetPrinterDriver GetPrinterDriverA
	#Define GetPrinterDriverDirectory GetPrinterDriverDirectoryA
	#Define DeletePrinterDriver DeletePrinterDriverA
	#Define DeletePrinterDriverEx DeletePrinterDriverExA
	#Define AddPerMachineConnection AddPerMachineConnectionA
	#Define DeletePerMachineConnection DeletePerMachineConnectionA
	#Define EnumPerMachineConnections EnumPerMachineConnectionsA
	#Define AddPrintProcessor AddPrintProcessorA
	#Define EnumPrintProcessors EnumPrintProcessorsA
	#Define GetPrintProcessorDirectory GetPrintProcessorDirectoryA
	#Define EnumPrintProcessorDatatypes EnumPrintProcessorDatatypesA
	#Define DeletePrintProcessor DeletePrintProcessorA
	#Define StartDocPrinter StartDocPrinterA
	#Define AddJob AddJobA
	#Define DocumentProperties DocumentPropertiesA
	#Define AdvancedDocumentProperties AdvancedDocumentPropertiesA
	#Define GetPrinterData GetPrinterDataA
	#Define EnumPrinterData EnumPrinterDataA
	#Define EnumPrinterDataEx EnumPrinterDataExA
	#Define EnumPrinterKey EnumPrinterKeyA
	#Define SetPrinterData SetPrinterDataA
	#Define SetPrinterDataEx SetPrinterDataExA
	#Define DeletePrinterData DeletePrinterDataA
	#Define DeletePrinterDataEx DeletePrinterDataExA
	#Define DeletePrinterKey DeletePrinterKeyA
	#Define PrinterMessageBox PrinterMessageBoxA
	#Define AddForm AddFormA
	#Define DeleteForm DeleteFormA
	#Define GetForm GetFormA
	#Define SetForm SetFormA
	#Define EnumForms EnumFormsA
	#Define EnumMonitors EnumMonitorsA
	#Define AddMonitor AddMonitorA
	#Define DeleteMonitor DeleteMonitorA
	#Define EnumPorts EnumPortsA
	#Define AddPort AddPortA
	#Define ConfigurePort ConfigurePortA
	#Define DeletePort DeletePortA
	#Define SetPort SetPortA
	#Define AddPrinterConnection AddPrinterConnectionA
	#Define DeletePrinterConnection DeletePrinterConnectionA
	#Define PROVIDOR_INFO_1 PROVIDOR_INFO_1A
	#Define AddPrintProvidor AddPrintProvidorA
	#Define DeletePrintProvidor DeletePrintProvidorA
	#Define SetPrinterHTMLView SetPrinterHTMLViewA
	#Define GetPrinterHTMLView GetPrinterHTMLViewA
#ENDIF

#ENDIF ;WINSPOOL_INC
