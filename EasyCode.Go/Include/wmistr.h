#ifndef WMISTR_H
#define WMISTR_H

/* WMI structure definitions */

#define WNODE_FLAG_ALL_DATA  0x00000001
#define WNODE_FLAG_SINGLE_INSTANCE  0x00000002
#define WNODE_FLAG_SINGLE_ITEM  0x00000004
#define WNODE_FLAG_EVENT_ITEM  0x00000008
#define WNODE_FLAG_FIXED_INSTANCE_SIZE  0x00000010
#define WNODE_FLAG_TOO_SMALL  0x00000020
#define WNODE_FLAG_INSTANCES_SAME  0x00000040
#define WNODE_FLAG_STATIC_INSTANCE_NAMES  0x00000080
#define WNODE_FLAG_INTERNAL  0x00000100
#define WNODE_FLAG_USE_TIMESTAMP  0x00000200
#define WNODE_FLAG_PERSIST_EVENT  0x00000400
#define WNODE_FLAG_EVENT_REFERENCE  0x00002000
#define WNODE_FLAG_ANSI_INSTANCENAMES  0x00004000
#define WNODE_FLAG_METHOD_ITEM  0x00008000
#define WNODE_FLAG_PDO_INSTANCE_NAMES  0x00010000
#define WNODE_FLAG_TRACED_GUID  0x00020000
#define WNODE_FLAG_LOG_WNODE  0x00040000
#define WNODE_FLAG_USE_GUID_PTR  0x00080000
#define WNODE_FLAG_USE_MOF_PTR  0x00100000
#define WNODE_FLAG_NO_HEADER  0x00200000
#define WNODE_FLAG_SEVERITY_MASK  0xff000000

#define WMIREG_FLAG_EXPENSIVE  0x00000001
#define WMIREG_FLAG_INSTANCE_LIST  0x00000004
#define WMIREG_FLAG_INSTANCE_BASENAME  0x00000008
#define WMIREG_FLAG_INSTANCE_PDO  0x00000020
#define WMIREG_FLAG_REMOVE_GUID  0x00010000
#define WMIREG_FLAG_RESERVED1  0x00020000
#define WMIREG_FLAG_RESERVED2  0x00040000
#define WMIREG_FLAG_TRACED_GUID  0x00080000
#define WMIREG_FLAG_TRACE_CONTROL_GUID  0x00001000
#define WMIREG_FLAG_EVENT_ONLY_GUID  0x00000040

#define WMI_GUIDTYPE_TRACECONTROL  0
#define WMI_GUIDTYPE_TRACE  1
#define WMI_GUIDTYPE_DATA  2
#define WMI_GUIDTYPE_EVENT  3

#define WMIGUID_QUERY  0x0001
#define WMIGUID_SET  0x0002
#define WMIGUID_NOTIFICATION  0x0004
#define WMIGUID_READ_DESCRIPTION  0x0008
#define WMIGUID_EXECUTE  0x0010
#define TRACELOG_CREATE_REALTIME  0x0020
#define TRACELOG_CREATE_ONDISK  0x0040
#define TRACELOG_GUID_ENABLE  0x0080
#define TRACELOG_ACCESS_KERNEL_LOGGER  0x0100
#define TRACELOG_CREATE_INPROC  0x0200
#define TRACELOG_ACCESS_REALTIME  0x0400
#define TRACELOG_REGISTER_GUIDS  0x0800

#define WMIGUID_ALL_ACCESS (STANDARD_RIGHTS_READ|SYNCHRONIZE|WMIGUID_QUERY|WMIGUID_SET|WMIGUID_NOTIFICATION|WMIGUID_READ_DESCRIPTION|WMIGUID_EXECUTE|TRACELOG_CREATE_REALTIME|TRACELOG_CREATE_ONDISK|TRACELOG_GUID_ENABLE|TRACELOG_ACCESS_KERNEL_LOGGER|TRACELOG_CREATE_INPROC|TRACELOG_ACCESS_REALTIME|TRACELOG_REGISTER_GUIDS)

#define WMI_GLOBAL_LOGGER_ID  0x0001

WNODE_HEADER STRUCT
	BufferSize DD
	ProviderId UINT_PTR
	UNION
		HistoricalContext DQ
		STRUCT
			Version DD
			Linkage DD
		ENDS
	ENDUNION
	UNION
		CountLost DD
		KernelHandle HANDLE
		TimeStamp LARGE_INTEGER
	ENDUNION
	Guid GUID
	ClientContext DD
	Flags DD
ENDS

OFFSETINSTANCEDATAANDLENGTH STRUCT
	OffsetInstanceData DD
	LengthInstanceData DD
ENDS

WNODE_ALL_DATA STRUCT
	WnodeHeader WNODE_HEADER
	DataBlockOffset DD
	InstanceCount DD
	OffsetInstanceNameOffsets DD
	UNION
		FixedInstanceSize DD
		OffsetInstanceDataAndLength OFFSETINSTANCEDATAANDLENGTH
	ENDUNION
ENDS

WNODE_SINGLE_INSTANCE STRUCT
	WnodeHeader WNODE_HEADER
	OffsetInstanceName DD
	InstanceIndex DD
	DataBlockOffset DD
	SizeDataBlock DD
	VariableData DB
ENDS

WNODE_SINGLE_ITEM STRUCT
	WnodeHeader WNODE_HEADER
	OffsetInstanceName DD
	InstanceIndex DD
	ItemId DD
	DataBlockOffset DD
	SizeDataItem DD
	VariableData DB
ENDS

WNODE_METHOD_ITEM STRUCT
	WnodeHeader WNODE_HEADER
	OffsetInstanceName DD
	InstanceIndex DD
	MethodId DD
	DataBlockOffset DD
	SizeDataBlock DD
	VariableData DB
ENDS

WNODE_EVENT_ITEM STRUCT
	WnodeHeader WNODE_HEADER
ENDS

WNODE_EVENT_REFERENCE STRUCT
	WnodeHeader WNODE_HEADER
	TargetGuid GUID
	TargetDataBlockSize DD
	UNION
		TargetInstanceIndex DD
 		TargetInstanceName DW
	ENDUNION
ENDS

WNODE_TOO_SMALL STRUCT
	WnodeHeader WNODE_HEADER
	SizeNeeded DD
ENDS

WMIREGGUIDW STRUCT
	Guid GUID
	Flags DD
	InstanceCount DD
	UNION
		InstanceNameList DD
		BaseNameOffset DD
		Pdo ULONG_PTR
		InstanceInfo ULONG_PTR
	ENDUNION
ENDS

#define WMIREGGUID WMIREGGUIDW

WMIREGINFOW STRUCT
	BufferSize DD
	NextWmiRegInfo DD
	RegistryPath DD
	MofResourceName DD
	GuidCount DD
	WmiRegGuid WMIREGGUIDW
ENDS

#define WMIREGINFO WMIREGINFOW

WMI_GET_ALL_DATA = 0
WMI_GET_SINGLE_INSTANCE = 1
WMI_SET_SINGLE_INSTANCE = 2
WMI_SET_SINGLE_ITEM = 3
WMI_ENABLE_EVENTS = 4
WMI_DISABLE_EVENTS = 5
WMI_ENABLE_COLLECTION = 6
WMI_DISABLE_COLLECTION = 7
WMI_REGINFO = 8
WMI_EXECUTE_METHOD = 9

#endif
