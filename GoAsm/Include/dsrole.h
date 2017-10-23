#ifndef DSROLE_H
#define DSROLE_H

#IFDEF LINKFILES
	#dynamiclinkfile Netapi32.dll
#ENDIF

#define DSROLE_PRIMARY_DS_RUNNING  0x00000001
#define DSROLE_PRIMARY_DS_MIXED_MODE  0x00000002
#define DSROLE_UPGRADE_IN_PROGRESS  0x00000004
#define DSROLE_PRIMARY_DOMAIN_GUID_PRESENT  0x01000000

DsRole_RoleStandaloneWorkstation = 0
DsRole_RoleMemberWorkstation = 1
DsRole_RoleStandaloneServer = 2
DsRole_RoleMemberServer = 3
DsRole_RoleBackupDomainController = 4
DsRole_RolePrimaryDomainController = 5

DsRoleServerUnknown = 0
DsRoleServerPrimary = 1
DsRoleServerBackup = 2

DsRolePrimaryDomainInfoBasic = 1
DsRoleUpgradeStatus = 2
DsRoleOperationState = 3

DSROLE_PRIMARY_DOMAIN_INFO_BASIC STRUCT
	MachineRole DD
	Flags DD
	DomainNameFlat PTR
	DomainNameDns PTR
	DomainForestName PTR
	DomainGuid GUID <>
ENDS

DSROLE_UPGRADE_STATUS_INFO STRUCT
	OperationState DD
	PreviousServerState DD
ENDS

DsRoleOperationIdle = 0
DsRoleOperationActive = 1
DsRoleOperationNeedReboot = 2

DSROLE_OPERATION_STATE_INFO STRUCT
    DSROLE_OPERATION_STATE OperationState DD
ENDS

#endif
