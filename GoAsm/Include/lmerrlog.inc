;=============================================================;
;         lmerrlog.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMERRLOG_INC
#Define LMERRLOG_INC

ERROR_LOG Struct
	el_len DD
	el_reserved DD
	el_time DD
	el_error DD
	el_name DD
	el_text DD
	el_data DD
	el_data_size DD
	el_nstrings DD
EndS

#IFNDEF HLOG
	HLOG Struct
		time DD
		last_flags DD
		offset DD
		rec_offset DD
	EndS

	#Define LOGFLAGS_FORWARD                0
	#Define LOGFLAGS_BACKWARD               01H
	#Define LOGFLAGS_SEEK                   02H
#ENDIF

#Define ERRLOG_BASE                         3100

#Define NELOG_Internal_Error                (ERRLOG_BASE + 0)
#Define NELOG_Resource_Shortage             (ERRLOG_BASE + 1)
#Define NELOG_Unable_To_Lock_Segment        (ERRLOG_BASE + 2)
#Define NELOG_Unable_To_Unlock_Segment      (ERRLOG_BASE + 3)
#Define NELOG_Uninstall_Service             (ERRLOG_BASE + 4)
#Define NELOG_Init_Exec_Fail                (ERRLOG_BASE + 5)
#Define NELOG_Ncb_Error                     (ERRLOG_BASE + 6)
#Define NELOG_Net_Not_Started               (ERRLOG_BASE + 7)
#Define NELOG_Ioctl_Error                   (ERRLOG_BASE + 8)
#Define NELOG_System_Semaphore              (ERRLOG_BASE + 9)
#Define NELOG_Init_OpenCreate_Err           (ERRLOG_BASE + 10)
#Define NELOG_NetBios                       (ERRLOG_BASE + 11)
#Define NELOG_SMB_Illegal                   (ERRLOG_BASE + 12)
#Define NELOG_Service_Fail                  (ERRLOG_BASE + 13)
#Define NELOG_Entries_Lost                  (ERRLOG_BASE + 14)
#Define NELOG_Init_Seg_Overflow             (ERRLOG_BASE + 20)
#Define NELOG_Srv_No_Mem_Grow               (ERRLOG_BASE + 21)
#Define NELOG_Access_File_Bad               (ERRLOG_BASE + 22)
#Define NELOG_Srvnet_Not_Started            (ERRLOG_BASE + 23)
#Define NELOG_Init_Chardev_Err              (ERRLOG_BASE + 24)
#Define NELOG_Remote_API                    (ERRLOG_BASE + 25)
#Define NELOG_Ncb_TooManyErr                (ERRLOG_BASE + 26)
#Define NELOG_Mailslot_err                  (ERRLOG_BASE + 27)
#Define NELOG_ReleaseMem_Alert              (ERRLOG_BASE + 28)
#Define NELOG_AT_cannot_write               (ERRLOG_BASE + 29)
#Define NELOG_Cant_Make_Msg_File            (ERRLOG_BASE + 30)
#Define NELOG_Exec_Netservr_NoMem           (ERRLOG_BASE + 31)
#Define NELOG_Server_Lock_Failure           (ERRLOG_BASE + 32)
#Define NELOG_Msg_Shutdown                  (ERRLOG_BASE + 40)
#Define NELOG_Msg_Sem_Shutdown              (ERRLOG_BASE + 41)
#Define NELOG_Msg_Log_Err                   (ERRLOG_BASE + 50)
#Define NELOG_VIO_POPUP_ERR                 (ERRLOG_BASE + 51)
#Define NELOG_Msg_Unexpected_SMB_Type       (ERRLOG_BASE + 52)
#Define NELOG_Wksta_Infoseg                 (ERRLOG_BASE + 60)
#Define NELOG_Wksta_Compname                (ERRLOG_BASE + 61)
#Define NELOG_Wksta_BiosThreadFailure       (ERRLOG_BASE + 62)
#Define NELOG_Wksta_IniSeg                  (ERRLOG_BASE + 63)
#Define NELOG_Wksta_HostTab_Full            (ERRLOG_BASE + 64)
#Define NELOG_Wksta_Bad_Mailslot_SMB        (ERRLOG_BASE + 65)
#Define NELOG_Wksta_UASInit                 (ERRLOG_BASE + 66)
#Define NELOG_Wksta_SSIRelogon              (ERRLOG_BASE + 67)
#Define NELOG_Build_Name                    (ERRLOG_BASE + 70)
#Define NELOG_Name_Expansion                (ERRLOG_BASE + 71)
#Define NELOG_Message_Send                  (ERRLOG_BASE + 72)
#Define NELOG_Mail_Slt_Err                  (ERRLOG_BASE + 73)
#Define NELOG_AT_cannot_read                (ERRLOG_BASE + 74)
#Define NELOG_AT_sched_err                  (ERRLOG_BASE + 75)
#Define NELOG_AT_schedule_file_created      (ERRLOG_BASE + 76)
#Define NELOG_Srvnet_NB_Open                (ERRLOG_BASE + 77)
#Define NELOG_AT_Exec_Err                   (ERRLOG_BASE + 78)
#Define NELOG_Lazy_Write_Err                (ERRLOG_BASE + 80)
#Define NELOG_HotFix                        (ERRLOG_BASE + 81)
#Define NELOG_HardErr_From_Server           (ERRLOG_BASE + 82)
#Define NELOG_LocalSecFail1                 (ERRLOG_BASE + 83)
#Define NELOG_LocalSecFail2                 (ERRLOG_BASE + 84)
#Define NELOG_LocalSecFail3                 (ERRLOG_BASE + 85)
#Define NELOG_LocalSecGeneralFail           (ERRLOG_BASE + 86)
#Define NELOG_NetWkSta_Internal_Error       (ERRLOG_BASE + 90)
#Define NELOG_NetWkSta_No_Resource          (ERRLOG_BASE + 91)
#Define NELOG_NetWkSta_SMB_Err              (ERRLOG_BASE + 92)
#Define NELOG_NetWkSta_VC_Err               (ERRLOG_BASE + 93)
#Define NELOG_NetWkSta_Stuck_VC_Err         (ERRLOG_BASE + 94)
#Define NELOG_NetWkSta_NCB_Err              (ERRLOG_BASE + 95)
#Define NELOG_NetWkSta_Write_Behind_Err     (ERRLOG_BASE + 96)
#Define NELOG_NetWkSta_Reset_Err            (ERRLOG_BASE + 97)
#Define NELOG_NetWkSta_Too_Many             (ERRLOG_BASE + 98)
#Define NELOG_Srv_Thread_Failure            (ERRLOG_BASE + 104)
#Define NELOG_Srv_Close_Failure             (ERRLOG_BASE + 105)
#Define NELOG_ReplUserCurDir                (ERRLOG_BASE + 106)
#Define NELOG_ReplCannotMasterDir           (ERRLOG_BASE + 107)
#Define NELOG_ReplUpdateError               (ERRLOG_BASE + 108)
#Define NELOG_ReplLostMaster                (ERRLOG_BASE + 109)
#Define NELOG_NetlogonAuthDCFail            (ERRLOG_BASE + 110)
#Define NELOG_ReplLogonFailed               (ERRLOG_BASE + 111)
#Define NELOG_ReplNetErr                    (ERRLOG_BASE + 112)
#Define NELOG_ReplMaxFiles                  (ERRLOG_BASE + 113)
#Define NELOG_ReplMaxTreeDepth              (ERRLOG_BASE + 114)
#Define NELOG_ReplBadMsg                    (ERRLOG_BASE + 115)
#Define NELOG_ReplSysErr                    (ERRLOG_BASE + 116)
#Define NELOG_ReplUserLoged                 (ERRLOG_BASE + 117)
#Define NELOG_ReplBadImport                 (ERRLOG_BASE + 118)
#Define NELOG_ReplBadExport                 (ERRLOG_BASE + 119)
#Define NELOG_ReplSignalFileErr             (ERRLOG_BASE + 120)
#Define NELOG_DiskFT                        (ERRLOG_BASE + 121)
#Define NELOG_ReplAccessDenied              (ERRLOG_BASE + 122)
#Define NELOG_NetlogonFailedPrimary         (ERRLOG_BASE + 123)
#Define NELOG_NetlogonPasswdSetFailed       (ERRLOG_BASE + 124)
#Define NELOG_NetlogonTrackingError         (ERRLOG_BASE + 125)
#Define NELOG_NetlogonSyncError             (ERRLOG_BASE + 126)
#Define NELOG_UPS_PowerOut                  (ERRLOG_BASE + 130)
#Define NELOG_UPS_Shutdown                  (ERRLOG_BASE + 131)
#Define NELOG_UPS_CmdFileError              (ERRLOG_BASE + 132)
#Define NELOG_UPS_CannotOpenDriver          (ERRLOG_BASE + 133)
#Define NELOG_UPS_PowerBack                 (ERRLOG_BASE + 134)
#Define NELOG_UPS_CmdFileConfig             (ERRLOG_BASE + 135)
#Define NELOG_UPS_CmdFileExec               (ERRLOG_BASE + 136)
#Define NELOG_Missing_Parameter             (ERRLOG_BASE + 150)
#Define NELOG_Invalid_Config_Line           (ERRLOG_BASE + 151)
#Define NELOG_Invalid_Config_File           (ERRLOG_BASE + 152)
#Define NELOG_File_Changed                  (ERRLOG_BASE + 153)
#Define NELOG_Files_Dont_Fit                (ERRLOG_BASE + 154)
#Define NELOG_Wrong_DLL_Version             (ERRLOG_BASE + 155)
#Define NELOG_Error_in_DLL                  (ERRLOG_BASE + 156)
#Define NELOG_System_Error                  (ERRLOG_BASE + 157)
#Define NELOG_FT_ErrLog_Too_Large           (ERRLOG_BASE + 158)
#Define NELOG_FT_Update_In_Progress         (ERRLOG_BASE + 159)

#Define NELOG_OEM_Code                      (ERRLOG_BASE + 199)

#Define ERRLOG2_BASE                        5700
#Define NELOG_NetlogonSSIInitError          (ERRLOG2_BASE + 0)
#Define NELOG_NetlogonFailedToUpdateTrustList (ERRLOG2_BASE + 1)
#Define NELOG_NetlogonFailedToAddRpcInterface (ERRLOG2_BASE + 2)
#Define NELOG_NetlogonFailedToReadMailslot  (ERRLOG2_BASE + 3)
#Define NELOG_NetlogonFailedToRegisterSC    (ERRLOG2_BASE + 4)
#Define NELOG_NetlogonChangeLogCorrupt      (ERRLOG2_BASE + 5)
#Define NELOG_NetlogonFailedToCreateShare   (ERRLOG2_BASE + 6)
#Define NELOG_NetlogonDownLevelLogonFailed  (ERRLOG2_BASE + 7)
#Define NELOG_NetlogonDownLevelLogoffFailed (ERRLOG2_BASE + 8)
#Define NELOG_NetlogonNTLogonFailed         (ERRLOG2_BASE + 9)
#Define NELOG_NetlogonNTLogoffFailed        (ERRLOG2_BASE + 10)
#Define NELOG_NetlogonPartialSyncCallSuccess (ERRLOG2_BASE + 11)
#Define NELOG_NetlogonPartialSyncCallFailed (ERRLOG2_BASE + 12)
#Define NELOG_NetlogonFullSyncCallSuccess   (ERRLOG2_BASE + 13)
#Define NELOG_NetlogonFullSyncCallFailed    (ERRLOG2_BASE + 14)
#Define NELOG_NetlogonPartialSyncSuccess    (ERRLOG2_BASE + 15)
#Define NELOG_NetlogonPartialSyncFailed     (ERRLOG2_BASE + 16)
#define NELOG_NetlogonFullSyncSuccess           (ERRLOG2_BASE + 17)
#define NELOG_NetlogonFullSyncFailed            (ERRLOG2_BASE + 18)
#define NELOG_NetlogonAuthNoDomainController    (ERRLOG2_BASE + 19)
#define NELOG_NetlogonAuthNoTrustLsaSecret      (ERRLOG2_BASE + 20)
#define NELOG_NetlogonAuthNoTrustSamAccount     (ERRLOG2_BASE + 21)
#define NELOG_NetlogonServerAuthFailed          (ERRLOG2_BASE + 22)
#Define NELOG_NetlogonServerAuthNoTrustSamAccount (ERRLOG2_BASE + 23)
#Define NELOG_FailedToRegisterSC            (ERRLOG2_BASE + 24)
#Define NELOG_FailedToSetServiceStatus      (ERRLOG2_BASE + 25)
#Define NELOG_FailedToGetComputerName       (ERRLOG2_BASE + 26)
#Define NELOG_DriverNotLoaded               (ERRLOG2_BASE + 27)
#Define NELOG_NoTranportLoaded              (ERRLOG2_BASE + 28)
#Define NELOG_NetlogonFailedDomainDelta     (ERRLOG2_BASE + 29)
#Define NELOG_NetlogonFailedGlobalGroupDelta (ERRLOG2_BASE + 30)
#Define NELOG_NetlogonFailedLocalGroupDelta (ERRLOG2_BASE + 31)
#Define NELOG_NetlogonFailedUserDelta       (ERRLOG2_BASE + 32)
#Define NELOG_NetlogonFailedPolicyDelta     (ERRLOG2_BASE + 33)
#Define NELOG_NetlogonFailedTrustedDomainDelta (ERRLOG2_BASE + 34)
#Define NELOG_NetlogonFailedAccountDelta    (ERRLOG2_BASE + 35)
#Define NELOG_NetlogonFailedSecretDelta     (ERRLOG2_BASE + 36)
#Define NELOG_NetlogonSystemError           (ERRLOG2_BASE + 37)
#Define NELOG_NetlogonDuplicateMachineAccounts (ERRLOG2_BASE + 38)
#Define NELOG_NetlogonTooManyGlobalGroups   (ERRLOG2_BASE + 39)
#Define NELOG_NetlogonBrowserDriver         (ERRLOG2_BASE + 40)
#Define NELOG_NetlogonAddNameFailure        (ERRLOG2_BASE + 41)
#Define NELOG_RplMessages                   (ERRLOG2_BASE + 42)
#Define NELOG_RplXnsBoot                    (ERRLOG2_BASE + 43)
#Define NELOG_RplSystem                     (ERRLOG2_BASE + 44)
#Define NELOG_RplWkstaTimeout               (ERRLOG2_BASE + 45)
#Define NELOG_RplWkstaFileOpen              (ERRLOG2_BASE + 46)
#Define NELOG_RplWkstaFileRead              (ERRLOG2_BASE + 47)
#Define NELOG_RplWkstaMemory                (ERRLOG2_BASE + 48)
#Define NELOG_RplWkstaFileChecksum          (ERRLOG2_BASE + 49)
#Define NELOG_RplWkstaFileLineCount         (ERRLOG2_BASE + 50)
#Define NELOG_RplWkstaBbcFile               (ERRLOG2_BASE + 51)
#Define NELOG_RplWkstaFileSize              (ERRLOG2_BASE + 52)
#Define NELOG_RplWkstaInternal              (ERRLOG2_BASE + 53)
#Define NELOG_RplWkstaWrongVersion          (ERRLOG2_BASE + 54)
#Define NELOG_RplWkstaNetwork               (ERRLOG2_BASE + 55)
#Define NELOG_RplAdapterResource            (ERRLOG2_BASE + 56)
#Define NELOG_RplFileCopy                   (ERRLOG2_BASE + 57)
#Define NELOG_RplFileDelete                 (ERRLOG2_BASE + 58)
#Define NELOG_RplFilePerms                  (ERRLOG2_BASE + 59)
#Define NELOG_RplCheckConfigs               (ERRLOG2_BASE + 60)
#Define NELOG_RplCreateProfiles             (ERRLOG2_BASE + 61)
#Define NELOG_RplRegistry                   (ERRLOG2_BASE + 62)
#Define NELOG_RplReplaceRPLDISK             (ERRLOG2_BASE + 63)
#Define NELOG_RplCheckSecurity              (ERRLOG2_BASE + 64)
#Define NELOG_RplBackupDatabase             (ERRLOG2_BASE + 65)
#Define NELOG_RplInitDatabase               (ERRLOG2_BASE + 66)
#Define NELOG_RplRestoreDatabaseFailure     (ERRLOG2_BASE + 67)
#Define NELOG_RplRestoreDatabaseSuccess     (ERRLOG2_BASE + 68)
#Define NELOG_RplInitRestoredDatabase       (ERRLOG2_BASE + 69)
#Define NELOG_NetlogonSessionTypeWrong      (ERRLOG2_BASE + 70)
#Define NELOG_RplUpgradeDBTo40              (ERRLOG2_BASE + 71)
#Define NELOG_NetlogonLanmanBdcsNotAllowed  (ERRLOG2_BASE + 72)
#Define NELOG_NetlogonNoDynamicDns          (ERRLOG2_BASE + 73)
#Define NELOG_NetlogonDynamicDnsRegisterFailure (ERRLOG2_BASE + 74)
#Define NELOG_NetlogonDynamicDnsDeregisterFailure (ERRLOG2_BASE + 75)
#Define NELOG_NetlogonFailedFileCreate      (ERRLOG2_BASE + 76)
#Define NELOG_NetlogonGetSubnetToSite       (ERRLOG2_BASE + 77)
#Define NELOG_NetlogonNoSiteForClient       (ERRLOG2_BASE + 78)
#Define NELOG_NetlogonBadSiteName           (ERRLOG2_BASE + 79)
#Define NELOG_NetlogonBadSubnetName         (ERRLOG2_BASE + 80)

#ENDIF ;LMERRLOG_INC
