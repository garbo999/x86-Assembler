#ifndef PDH_H
#define PDH_H

#IFNDEF WINDOWS_H
	#include windows.h
#ENDIF
#IFNDEF WINPERF_H
	#include winperf.h
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile Pdh.dll
#ENDIF

#IFNDEF FILETIME
	FILETIME STRUCT
		dwLowDateTime DD
		dwHighDateTime DD
	ENDS
#ENDIF

#define PDH_CVERSION_WIN40  0x0400
#define PDH_CVERSION_WIN50  0x0500
#define PDH_VERSION  PDH_CVERSION_WIN50+0x0003

#define MAX_TIME_VALUE  0x7FFFFFFFFFFFFFFF
#define MIN_TIME_VALUE  0

#define PDH_FMT_RAW  0x00000010
#define PDH_FMT_ANSI  0x00000020
#define PDH_FMT_UNICODE  0x00000040
#define PDH_FMT_LONG  0x00000100
#define PDH_FMT_DOUBLE  0x00000200
#define PDH_FMT_LARGE  0x00000400
#define PDH_FMT_NOSCALE  0x00001000
#define PDH_FMT_1000  0x00002000
#define PDH_FMT_NODATA  0x00004000
#define PDH_FMT_NOCAP100  0x00008000
#define PERF_DETAIL_COSTLY  0x00010000
#define PERF_DETAIL_STANDARD  0x0000FFFF

#define PDH_MAX_SCALE  7
#define PDH_MIN_SCALE  -7

#define PDH_PATH_WBEM_RESULT  0x00000001
#define PDH_PATH_WBEM_INPUT  0x00000002

#define PDH_NOEXPANDCOUNTERS  1
#define PDH_NOEXPANDINSTANCES  2

#define PDH_LOG_READ_ACCESS  0x00010000
#define PDH_LOG_WRITE_ACCESS  0x00020000
#define PDH_LOG_UPDATE_ACCESS  0x00040000
#define PDH_LOG_ACCESS_MASK  0x000F0000
#define PDH_LOG_CREATE_NEW  0x00000001
#define PDH_LOG_CREATE_ALWAYS  0x00000002
#define PDH_LOG_OPEN_ALWAYS  0x00000003
#define PDH_LOG_OPEN_EXISTING  0x00000004
#define PDH_LOG_CREATE_MASK  0x0000000F
#define PDH_LOG_OPT_USER_STRING  0x01000000
#define PDH_LOG_OPT_CIRCULAR  0x02000000
#define PDH_LOG_OPT_MAX_IS_BYTES  0x04000000
#define PDH_LOG_OPT_MASK  0x0F000000
#define PDH_LOG_TYPE_UNDEFINED  0
#define PDH_LOG_TYPE_CSV  1
#define PDH_LOG_TYPE_TSV  2
#define PDH_LOG_TYPE_BINARY  3
#define PDH_LOG_TYPE_TRACE_KERNEL  4
#define PDH_LOG_TYPE_TRACE_GENERIC  5
#define PDH_LOG_TYPE_PERFMON  6

#define PDH_FLAGS_CLOSE_QUERY  0x00000001
#define PDH_FLAGS_FILE_BROWSER_ONLY 0x00000001

#define DATA_SOURCE_REGISTRY  0x00000001
#define DATA_SOURCE_LOGFILE  0x00000002
#define DATA_SOURCE_WBEM  0x00000004

#define PDH_LOGSVC_NO_WAIT  0x80000000
#define PDH_LOGSVC_ALL_QUERIES  0x00000001
#define PDH_LOGSVC_TRACE_LOG  0x00000002
#define PDH_LOGSVC_CMD_START  0x00000010
#define PDH_LOGSVC_CMD_STOP  0x00000020
#define PDH_LOGSVC_CTRL_ADD  0x00000100
#define PDH_LOGSVC_CTRL_REMOVE  0x00000200
#define PDH_LOGSVC_CTRL_INFO  0x00000400
#define PDH_LOGSVC_STATUS_RUNNING  0x00001000
#define PDH_LOGSVC_STATUS_STOPPED  0x00002000
#define PDH_LOGSVC_STATUS_PAUSED  0x00004000
#define PDH_LOGSVC_STATUS_ERROR  0x00008000
#define PDH_LOGSVC_STATUS_PENDING  0x00010000
#define PDH_LOGSVC_NAME_UNDEFINED  -1
#define PDH_LOGSVC_NAME_MMDDHH  0
#define PDH_LOGSVC_NAME_NNNNNN  1
#define PDH_LOGSVC_NAME_YYDDD  2
#define PDH_LOGSVC_NAME_YYMM  3
#define PDH_LOGSVC_NAME_YYMMDD  4
#define PDH_LOGSVC_NAME_YYMMDDHH  5
#define PDH_LOGSVC_RENAME_UNDEFINED -1
#define PDH_LOGSVC_RENAME_HOURS  0
#define PDH_LOGSVC_RENAME_DAYS  1
#define PDH_LOGSVC_RENAME_MONTHS  2
#define PDH_LOGSVC_RENAME_KBYTES  3
#define PDH_LOGSVC_RENAME_MBYTES  4

PDH_RAW_COUNTER STRUCT
	CStatus DD
	TimeStamp FILETIME
	FirstValue DQ
	SecondValue DQ
	MultiCount DD
ENDS

PDH_RAW_COUNTER_ITEM_A STRUCT
	szName PTR
	RawValue PDH_RAW_COUNTER
ENDS

PDH_RAW_COUNTER_ITEM_W STRUCT
	szName PTR
	RawValue PDH_RAW_COUNTER
ENDS

PDH_FMT_COUNTERVALUE STRUCT
	CStatus DD
	UNION
		longValue DD
		doubleValue DQ
		largeValue DQ
		AnsiStringValue PTR
		WideStringValue PTR
	ENDUNION
ENDS

PDH_FMT_COUNTERVALUE_ITEM_A STRUCT
	szName PTR
	FmtValue PDH_FMT_COUNTERVALUE
ENDS

PDH_FMT_COUNTERVALUE_ITEM_W STRUCT
	szName PTR
	FmtValue PDH_FMT_COUNTERVALUE
ENDS

PDH_STATISTICS STRUCT
	dwFormat DD
	count DD
	min PDH_FMT_COUNTERVALUE
	max PDH_FMT_COUNTERVALUE
	mean PDH_FMT_COUNTERVALUE
ENDS

PDH_COUNTER_PATH_ELEMENTS_A STRUCT
	szMachineName PTR
	szObjectName PTR
	szInstanceName PTR
	szParentInstance PTR
	dwInstanceIndex DD
	szCounterName PTR
ENDS

PDH_COUNTER_PATH_ELEMENTS_W STRUCT
	szMachineName PTR
	szObjectName PTR
	szInstanceName PTR
	szParentInstance PTR
	dwInstanceIndex DD
	szCounterName PTR
ENDS

PDH_DATA_ITEM_PATH_ELEMENTS_A STRUCT
	szMachineName PTR
	ObjectGUID GUID
	dwItemId DD
	szInstanceName PTR
ENDS

PDH_DATA_ITEM_PATH_ELEMENTS_W STRUCT
	szMachineName PTR
	ObjectGUID GUID
	dwItemId DD
	szInstanceName PTR
ENDS

PDH_COUNTER_INFO_UNION STRUCT
	szMachineName PTR
	szObjectName PTR
	szInstanceName PTR
	szParentInstance PTR
	dwInstanceIndex DD
	szCounterName PTR
ENDS

PDH_COUNTER_INFO_A STRUCT
	dwLength DD
	dwType DD
	CVersion DD
	CStatus DD
	lScale DD
	lDefaultScale DD
	dwUserData DWORD_PTR
	dwQueryUserData DWORD_PTR
	szFullPath PTR
	UNION
		DataItemPath PDH_DATA_ITEM_PATH_ELEMENTS_A
		CounterPath PDH_COUNTER_PATH_ELEMENTS_A
		STRUCT
			szMachineName PTR
			szObjectName PTR
			szInstanceName PTR
			szParentInstance PTR
			dwInstanceIndex DD
			szCounterName PTR
		ENDS
	ENDUNION
	szExplainText PTR
	DataBuffer  DD
ENDS

PDH_COUNTER_INFO_W STRUCT
	dwLength DD
	dwType DD
	CVersion DD
	CStatus DD
	lScale DD
	lDefaultScale DD
	dwUserData DWORD_PTR
	dwQueryUserData DWORD_PTR
	szFullPath PTR
	UNION
		DataItemPath PDH_DATA_ITEM_PATH_ELEMENTS_A
		CounterPath PDH_COUNTER_PATH_ELEMENTS_A
		STRUCT
			szMachineName PTR
			szObjectName PTR
			szInstanceName PTR
			szParentInstance PTR
			dwInstanceIndex DD
			szCounterName PTR
		ENDS
	ENDUNION
	szExplainText PTR
	DataBuffer  DD
ENDS

PDH_TIME_INFO STRUCT
	StartTime DQ
	EndTime DQ
	SampleCount DD
ENDS

PDH_RAW_LOG_RECORD STRUCT
	dwStructureSize DD
	dwRecordType DD
	dwItems DD
	RawBytes DB
ENDS

PDH_LOG_SERVICE_QUERY_INFO_A STRUCT
	dwSize DD
	dwFlags DD
	dwLogQuota DD
	szLogFileCaption DD
	szDefaultDir DD
	szBaseFileName DD
	dwFileType DD
	dwReserved DD
	UNION
		STRUCT
			UNION
				PdlAutoNameInterval DD
				PdlAutoNameUnits DD
				PdlCommandFilename DD
				PdlCounterList DD
				PdlAutoNameFormat DD
				PdlSampleInterval DD
				PdlLogStartTime FILETIME
				PdlLogEndTime FILETIME
			ENDUNION
		ENDS
		STRUCT
			UNION
				TlNumberOfBuffers DD
				TlMinimumBuffers DD
				TlMaximumBuffers DD
				TlFreeBuffers DD
				TlBufferSize DD
				TlEventsLost DD
				TlLoggerThreadId DD
				TlBuffersWritten DD
				TlLogHandle DD
				TlLogFileName DD
			ENDUNION
		ENDS
	ENDUNION
ENDS

PDH_LOG_SERVICE_QUERY_INFO_W STRUCT
	dwSize DD
	dwFlags DD
	dwLogQuota DD
	szLogFileCaption DD
	szDefaultDir DD
	szBaseFileName DD
	dwFileType DD
	dwReserved DD
	UNION
		STRUCT
			UNION
				PdlAutoNameInterval DD
				PdlAutoNameUnits DD
				PdlCommandFilename DD
				PdlCounterList DD
				PdlAutoNameFormat DD
				PdlSampleInterval DD
				PdlLogStartTime FILETIME
				PdlLogEndTime FILETIME
			ENDUNION
		ENDS
		STRUCT
			UNION
				TlNumberOfBuffers DD
				TlMinimumBuffers DD
				TlMaximumBuffers DD
				TlFreeBuffers DD
				TlBufferSize DD
				TlEventsLost DD
				TlLoggerThreadId DD
				TlBuffersWritten DD
				TlLogHandle DD
				TlLogFileName DD
			ENDUNION
		ENDS
	ENDUNION
ENDS

PDH_BROWSE_DLG_CONFIG_W STRUCT
	flags DD
	hWndOwner HANDLE
	szDataSource PTR
	szReturnPathBuffer PTR
	cchReturnPathLength DD
	pCallBack PTR
	dwCallBackArg DWORD_PTR
	CallBackStatus DD
	dwDefaultDetailLevel DD
	szDialogBoxCaption PTR
ENDS

PDH_BROWSE_DLG_CONFIG_A STRUCT
	flags DD
	hWndOwner HANDLE
	szDataSource PTR
	szReturnPathBuffer PTR
	cchReturnPathLength DD
	pCallBack PTR
	dwCallBackArg DWORD_PTR
	CallBackStatus DD
	dwDefaultDetailLevel DD
	szDialogBoxCaption PTR
ENDS

PDH_BROWSE_DLG_CONFIG_H STRUCT
	flags DD
	hWndOwner HANDLE
	hDataSource HANDLE
	szReturnPathBuffer PTR
	cchReturnPathLength DD
	pCallBack PTR
	dwCallBackArg DWORD_PTR
	CallBackStatus DD
	dwDefaultDetailLevel DD
	szDialogBoxCaption PTR
ENDS

#IFDEF UNICODE
	#define PdhOpenQuery  PdhOpenQueryW
	#define PdhAddCounter  PdhAddCounterW
	#define PdhGetCounterInfo  PdhGetCounterInfoW
	#define PDH_COUNTER_INFO  PDH_COUNTER_INFO_W
	#define PdhConnectMachine  PdhConnectMachineW
	#define PdhEnumMachines  PdhEnumMachinesW
	#define PdhEnumObjects  PdhEnumObjectsW
	#define PdhEnumObjectItems  PdhEnumObjectItemsW
	#define PdhMakeCounterPath  PdhMakeCounterPathW
	#define PDH_COUNTER_PATH_ELEMENTS  PDH_COUNTER_PATH_ELEMENTS_W
	#define PdhParseCounterPath  PdhParseCounterPathW
	#define PdhParseInstanceName  PdhParseInstanceNameW
	#define PdhValidatePath  PdhValidatePathW
	#define PdhGetDefaultPerfObject  PdhGetDefaultPerfObjectW
	#define PdhGetDefaultPerfCounter  PdhGetDefaultPerfCounterW
	#define PdhBrowseCounters  PdhBrowseCountersW
	#define PDH_BROWSE_DLG_CONFIG  PDH_BROWSE_DLG_CONFIG_W
	#define PdhExpandCounterPath  PdhExpandCounterPathW
	#define PDH_FMT_COUNTERVALUE_ITEM  PDH_FMT_COUNTERVALUE_ITEM_W
	#define PDH_RAW_COUNTER_ITEM  PDH_RAW_COUNTER_ITEM_W
	#define PdhGetFormattedCounterArray PdhGetFormattedCounterArrayW
	#define PdhGetRawCounterArray  PdhGetRawCounterArrayW
	#define PdhLookupPerfNameByIndex  PdhLookupPerfNameByIndexW
	#define PdhLookupIndexByPerfName  PdhLookupIndexByPerfNameW
	#define PdhOpenLog  PdhOpenLogW
	#define PdhUpdateLog  PdhUpdateLogW
	#define PdhSelectDataSource  PdhSelectDataSourceW
	#define PdhGetDataSourceTimeRange  PdhGetDataSourceTimeRangeW
	#define PDH_LOG_SERVICE_QUERY_INFO  PDH_LOG_SERVICE_QUERY_INFO_W
	#define PdhLogServiceControl  PdhLogServiceControlW
	#define PdhLogServiceQuery  PdhLogServiceQueryW
	#define PdhExpandWildCardPath  PdhExpandWildCardPathW
#else
	#define PdhOpenQuery  PdhOpenQueryA
	#define PdhAddCounter  PdhAddCounterA
	#define PdhGetCounterInfo  PdhGetCounterInfoA
	#define PDH_COUNTER_INFO  PDH_COUNTER_INFO_A
	#define PdhConnectMachine  PdhConnectMachineA
	#define PdhEnumMachines  PdhEnumMachinesA
	#define PdhEnumObjects  PdhEnumObjectsA
	#define PdhEnumObjectItems  PdhEnumObjectItemsA
	#define PdhMakeCounterPath  PdhMakeCounterPathA
	#define PDH_COUNTER_PATH_ELEMENTS  PDH_COUNTER_PATH_ELEMENTS_A
	#define PdhParseCounterPath  PdhParseCounterPathA
	#define PdhParseInstanceName  PdhParseInstanceNameA
	#define PdhValidatePath  PdhValidatePathA
	#define PdhGetDefaultPerfObject  PdhGetDefaultPerfObjectA
	#define PdhGetDefaultPerfCounter  PdhGetDefaultPerfCounterA
	#define PdhBrowseCounters  PdhBrowseCountersA
	#define PDH_BROWSE_DLG_CONFIG  PDH_BROWSE_DLG_CONFIG_A
	#define PdhExpandCounterPath  PdhExpandCounterPathA
	#define PDH_FMT_COUNTERVALUE_ITEM  PDH_FMT_COUNTERVALUE_ITEM_A
	#define PDH_RAW_COUNTER_ITEM  PDH_RAW_COUNTER_ITEM_A
	#define PdhGetFormattedCounterArray PdhGetFormattedCounterArrayA
	#define PdhGetRawCounterArray  PdhGetRawCounterArrayA
	#define PdhLookupPerfNameByIndex  PdhLookupPerfNameByIndexA
	#define PdhLookupIndexByPerfName  PdhLookupIndexByPerfNameA
	#define PdhOpenLog  PdhOpenLogA
	#define PdhUpdateLog  PdhUpdateLogA
	#define PdhSelectDataSource  PdhSelectDataSourceA
	#define PdhGetDataSourceTimeRange  PdhGetDataSourceTimeRangeA
	#define PDH_LOG_SERVICE_QUERY_INFO  PDH_LOG_SERVICE_QUERY_INFO_A
	#define PdhLogServiceControl  PdhLogServiceControlA
	#define PdhLogServiceQuery  PdhLogServiceQueryA
	#define PdhExpandWildCardPath  PdhExpandWildCardPathA
#endif

#endif
