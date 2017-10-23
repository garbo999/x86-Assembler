#ifndef DBT_H
#define DBT_H

/* Windows Broadcast Message definitions */

#define WM_DEVICECHANGE  0x0219

#define DBT_APPYBEGIN  0x0000
#define DBT_APPYEND  0x0001
#define DBT_DEVNODES_CHANGED  0x0007
#define DBT_QUERYCHANGECONFIG  0x0017
#define DBT_CONFIGCHANGED  0x0018
#define DBT_CONFIGCHANGECANCELED  0x0019
#define DBT_MONITORCHANGE  0x001B
#define DBT_SHELLLOGGEDON  0x0020
#define DBT_CONFIGMGAPI32  0x0022
#define DBT_VXDINITCOMPLETE  0x0023
#define DBT_VOLLOCKQUERYLOCK  0x8041
#define DBT_VOLLOCKLOCKTAKEN  0x8042
#define DBT_VOLLOCKLOCKFAILED  0x8043
#define DBT_VOLLOCKQUERYUNLOCK  0x8044
#define DBT_VOLLOCKLOCKRELEASED  0x8045
#define DBT_VOLLOCKUNLOCKFAILED  0x8046
#define DBT_NO_DISK_SPACE  0x0047
#define DBT_LOW_DISK_SPACE  0x0048
#define DBT_CONFIGMGPRIVATE  0x7FFF
#define DBT_DEVICEARRIVAL  0x8000
#define DBT_DEVICEQUERYREMOVE  0x8001
#define DBT_DEVICEQUERYREMOVEFAILED  0x8002
#define DBT_DEVICEREMOVEPENDING  0x8003
#define DBT_DEVICEREMOVECOMPLETE  0x8004
#define DBT_DEVICETYPESPECIFIC  0x8005
#define DBT_CUSTOMEVENT  0x8006
#define DBT_VPOWERDAPI  0x8100
#define DBT_USERDEFINED  0xFFFF

#define DBT_DEVTYP_OEM  0x00000000
#define DBT_DEVTYP_DEVNODE  0x00000001
#define DBT_DEVTYP_VOLUME  0x00000002
#define DBT_DEVTYP_PORT  0x00000003
#define DBT_DEVTYP_NET  0x00000004
#define DBT_DEVTYP_DEVICEINTERFACE  0x00000005
#define DBT_DEVTYP_HANDLE  0x00000006

#define DBTF_MEDIA  1
#define DBTF_NET  2

#define DBTF_RESOURCE  1
#define DBTF_XPORT  2
#define DBTF_SLOWNET  4

#define BSF_QUERY  0x00000001
#define BSF_IGNORECURRENTTASK  0x00000002
#define BSF_FLUSHDISK  0x00000004
#define BSF_NOHANG  0x00000008
#define BSF_POSTMESSAGE  0x00000010
#define BSF_FORCEIFHUNG  0x00000020
#define BSF_NOTIMEOUTIFNOTHUNG  0x00000040
#define BSF_MSGSRV32ISOK  0x80000000
#define BSF_MSGSRV32ISOK_BIT  31

#define BSM_ALLCOMPONENTS  0x00000000
#define BSM_VXDS  0x00000001
#define BSM_NETDRIVER  0x00000002
#define BSM_INSTALLABLEDRIVERS  0x00000004
#define BSM_APPLICATIONS  0x00000008

#define LOCKP_ALLOW_WRITES  0x01
#define LOCKP_FAIL_WRITES  0x00
#define LOCKP_FAIL_MEM_MAPPING  0x02
#define LOCKP_ALLOW_MEM_MAPPING  0x00
#define LOCKP_USER_MASK  0x03
#define LOCKP_LOCK_FOR_FORMAT  0x04

#define LOCKF_LOGICAL_LOCK  0x00
#define LOCKF_PHYSICAL_LOCK  0x01

DEV_BROADCAST_HDR STRUCT
	dbch_size DD
	dbch_devicetype DD
	dbch_reserved DD
ENDS

VolLockBroadcast STRUCT
	vlb_dbh DEV_BROADCAST_HDR
	vlb_owner DD
	vlb_perms DB
	vlb_lockType DB
	vlb_drive DB
	vlb_flags DB
ENDS

DEV_BROADCAST_DEVICEINTERFACE_A STRUCT
	dbcc_size DD
	dbcc_devicetype DD
	dbcc_reserved DD
	dbcc_classguid GUID
	dbcc_name DB
ENDS

DEV_BROADCAST_DEVICEINTERFACE_W STRUCT
	dbcc_size DD
	dbcc_devicetype DD
	dbcc_reserved DD
	dbcc_classguid GUID
	dbcc_name DW
ENDS

DEV_BROADCAST_DEVNODE STRUCT
	dbcd_size DD
	dbcd_devicetype DD
	dbcd_reserved DD
	dbcd_devnode DD
ENDS

DEV_BROADCAST_HANDLE STRUCT
	dbch_size DD
	dbch_devicetype DD
	dbch_reserved DD
	dbch_handle DD
	dbch_hdevnotify DD
	dbch_eventguid GUID
	dbch_nameoffset DD
	dbch_data DB
ENDS

DEV_BROADCAST_NET STRUCT
	dbcn_size DD
	dbcn_devicetype DD
	dbcn_reserved DD
	dbcn_resource DD
	dbcn_flags DD
ENDS

DEV_BROADCAST_OEM STRUCT
	dbco_size DD
	dbco_devicetype DD
	dbco_reserved DD
	dbco_identifier DD
	dbco_suppfunc DD
ENDS

DEV_BROADCAST_PORT_A STRUCT
	dbcp_size DD
	dbcp_devicetype DD
	dbcp_reserved DD
	dbcp_name DB
ENDS

DEV_BROADCAST_PORT_W STRUCT
	dbcp_size DD
	dbcp_devicetype DD
	dbcp_reserved DD
	dbcp_name DW
ENDS

DEV_BROADCAST_USERDEFINED STRUCT
	dbud_dbh DEV_BROADCAST_HDR
	dbud_szName DB
ENDS

DEV_BROADCAST_VOLUME STRUCT
	dbcv_size DD
	dbcv_devicetype DD
	dbcv_reserved DD
	dbcv_unitmask DD
	dbcv_flags DW
ENDS

DEV_BROADCAST_HANDLE32 STRUCT
	dbch_size DD
	dbch_devicetype DD
	dbch_reserved DD
	dbch_handle DD
	dbch_hdevnotify DD
	dbch_eventguid GUID
	dbch_nameoffset DD
	dbch_data DB
ENDS

DEV_BROADCAST_HANDLE64 STRUCT
	dbch_size DD
	dbch_devicetype DD
	dbch_reserved DD
	dbch_handle DQ
	dbch_hdevnotify DQ
	dbch_eventguid GUID
	dbch_nameoffset DD
	dbch_data DB
ENDS

#IFDEF UNICODE
	#define DEV_BROADCAST_DEVICEINTERFACE DEV_BROADCAST_DEVICEINTERFACE_W
	#define DEV_BROADCAST_PORT DEV_BROADCAST_PORT_W
#ELSE
	#define DEV_BROADCAST_DEVICEINTERFACE DEV_BROADCAST_DEVICEINTERFACE_A
	#define DEV_BROADCAST_PORT DEV_BROADCAST_PORT_A
#ENDIF

#endif /* DBT_H */
