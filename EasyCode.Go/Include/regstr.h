#ifndef REGSTR_H
#define REGSTR_H

/* Windows public Registry definitions */

#define REGSTR_KEY_CLASS  "Class"
#define REGSTR_KEY_CONFIG  "Config"
#define REGSTR_KEY_ENUM  "Enum"
#define REGSTR_KEY_ROOTENUM  "Root"
#define REGSTR_KEY_BIOSENUM  "BIOS"
#define REGSTR_KEY_ACPIENUM  "ACPI"
#define REGSTR_KEY_PCMCIAENUM  "PCMCIA"
#define REGSTR_KEY_PCIENUM  "PCI"
#define REGSTR_KEY_VPOWERDENUM  "VPOWERD"
#define REGSTR_KEY_ISAENUM  "ISAPnP"
#define REGSTR_KEY_EISAENUM  "EISA"
#define REGSTR_KEY_LOGCONFIG  "LogConfig"
#define REGSTR_KEY_SYSTEMBOARD  "*PNP0C01"
#define REGSTR_KEY_APM  "*PNP0C05"
#define REGSTR_KEY_INIUPDATE  "IniUpdate"

#define REG_KEY_INSTDEV  "Installed"

#define REGSTR_KEY_DOSOPTCDROM  "CD-ROM"
#define REGSTR_KEY_DOSOPTMOUSE  "MOUSE"
#define REGSTR_KEY_KNOWNDOCKINGSTATES  "Hardware Profiles"
#define REGSTR_KEY_DEVICEPARAMETERS  "Device Parameters"

#define REGSTR_DEFAULT_INSTANCE  "0000"

#define REGSTR_PATH_MOTHERBOARD  "*PNP0C01\0000"
#define REGSTR_PATH_SETUP  "Software\Microsoft\Windows\CurrentVersion"
#define REGSTR_PATH_DRIVERSIGN  "Software\Microsoft\Driver Signing"
#define REGSTR_PATH_NONDRIVERSIGN  "Software\Microsoft\Non-Driver Signing"
#define REGSTR_PATH_DRIVERSIGN_POLICY  "Software\Policies\Microsoft\Windows NT\Driver Signing"
#define REGSTR_PATH_NONDRIVERSIGN_POLICY  "Software\Policies\Microsoft\Windows NT\Non-Driver Signing"
#define REGSTR_PATH_PIFCONVERT  "Software\Microsoft\Windows\CurrentVersion\PIFConvert"
#define REGSTR_PATH_MSDOSOPTS  "Software\Microsoft\Windows\CurrentVersion\MS-DOSOptions"
#define REGSTR_PATH_NOSUGGMSDOS  "Software\Microsoft\Windows\CurrentVersion\NoMSDOSWarn"
#define REGSTR_PATH_NEWDOSBOX  "Software\Microsoft\Windows\CurrentVersion\MS-DOSSpecialConfig"
#define REGSTR_PATH_RUNONCE  "Software\Microsoft\Windows\CurrentVersion\RunOnce"
#define REGSTR_PATH_RUNONCEEX  "Software\Microsoft\Windows\CurrentVersion\RunOnceEx"
#define REGSTR_PATH_RUN  "Software\Microsoft\Windows\CurrentVersion\Run"
#define REGSTR_PATH_RUNSERVICESONCE  "Software\Microsoft\Windows\CurrentVersion\RunServicesOnce"
#define REGSTR_PATH_RUNSERVICES  "Software\Microsoft\Windows\CurrentVersion\RunServices"
#define REGSTR_PATH_EXPLORER  "Software\Microsoft\Windows\CurrentVersion\Explorer"
#define REGSTR_PATH_DETECT  "Software\Microsoft\Windows\CurrentVersion\Detect"
#define REGSTR_PATH_APPPATHS  "Software\Microsoft\Windows\CurrentVersion\App Paths"
#define REGSTR_PATH_UNINSTALL  "Software\Microsoft\Windows\CurrentVersion\Uninstall"
#define REGSTR_PATH_REALMODENET  "Software\Microsoft\Windows\CurrentVersion\Network\Real Mode Net"
#define REGSTR_PATH_NETEQUIV  "Software\Microsoft\Windows\CurrentVersion\Network\Equivalent"
#define REGSTR_PATH_CVNETWORK  "Software\Microsoft\Windows\CurrentVersion\Network"
#define REGSTR_PATH_RELIABILITY  "Software\Microsoft\Windows\CurrentVersion\Reliability"
#define REGSTR_PATH_NT_CURRENTVERSION  "Software\Microsoft\Windows NT\CurrentVersion"

#define REGSTR_PATH_VOLUMECACHE  "Software\Microsoft\Windows\CurrentVersion\Explorer\VolumeCaches"
#define REGSTR_VAL_DISPLAY  "display"

#define REGSTR_PATH_IDCONFIGDB  "System\CurrentControlSet\Control\IDConfigDB"
#define REGSTR_PATH_CRITICALDEVICEDATABASE  "System\CurrentControlSet\Control\CriticalDeviceDatabase"
#define REGSTR_PATH_CLASS  "System\CurrentControlSet\Services\Class"
#define REGSTR_PATH_DISPLAYSETTINGS  "Display\Settings"
#define REGSTR_PATH_FONTS  "Display\Fonts"
#define REGSTR_PATH_ENUM  "Enum"
#define REGSTR_PATH_ROOT  "Enum\Root"

#define REGSTR_PATH_CURRENTCONTROLSET  "System\CurrentControlSet"
#define REGSTR_PATH_SYSTEMENUM  "System\CurrentControlSet\Enum"
#define REGSTR_PATH_HWPROFILES  "System\CurrentControlSet\Hardware Profiles"
#define REGSTR_PATH_HWPROFILESCURRENT  "System\CurrentControlSet\Hardware Profiles\Current"
#define REGSTR_PATH_CLASS_NT  "System\CurrentControlSet\Control\Class"
#define REGSTR_PATH_DEVICE_CLASSES  "System\CurrentControlSet\Control\DeviceClasses"
#define REGSTR_PATH_CODEVICEINSTALLERS "System\CurrentControlSet\Control\CoDeviceInstallers"

#define REGSTR_PATH_SERVICES  "System\CurrentControlSet\Services"
#define REGSTR_PATH_VXD  "System\CurrentControlSet\Services\VxD"
#define REGSTR_PATH_IOS  "System\CurrentControlSet\Services\VxD\IOS"
#define REGSTR_PATH_VMM  "System\CurrentControlSet\Services\VxD\VMM"
#define REGSTR_PATH_VPOWERD  "System\CurrentControlSet\Services\VxD\VPOWERD"
#define REGSTR_PATH_VNETSUP  "System\CurrentControlSet\Services\VxD\VNETSUP"
#define REGSTR_PATH_NWREDIR  "System\CurrentControlSet\Services\VxD\NWREDIR"
#define REGSTR_PATH_NCPSERVER  "System\CurrentControlSet\Services\NcpServer\Parameters"
#define REGSTR_PATH_VCOMM  "System\CurrentControlSet\Services\VxD\VCOMM"

#define REGSTR_PATH_IOARB  "System\CurrentControlSet\Services\Arbitrators\IOArb"
#define REGSTR_PATH_ADDRARB  "System\CurrentControlSet\Services\Arbitrators\AddrArb"
#define REGSTR_PATH_DMAARB  "System\CurrentControlSet\Services\Arbitrators\DMAArb"
#define REGSTR_PATH_IRQARB  "System\CurrentControlSet\Services\Arbitrators\IRQArb"

#define REGSTR_PATH_CODEPAGE  "System\CurrentControlSet\Control\Nls\Codepage"
#define REGSTR_PATH_FILESYSTEM  "System\CurrentControlSet\Control\FileSystem"
#define REGSTR_PATH_FILESYSTEM_NOVOLTRACK  "System\CurrentControlSet\Control\FileSystem\NoVolTrack"
#define REGSTR_PATH_CDFS  "System\CurrentControlSet\Control\FileSystem\CDFS"
#define REGSTR_PATH_WINBOOT  "System\CurrentControlSet\Control\WinBoot"
#define REGSTR_PATH_INSTALLEDFILES  "System\CurrentControlSet\Control\InstalledFiles"
#define REGSTR_PATH_VMM32FILES  "System\CurrentControlSet\Control\VMM32Files"

#define REGSTR_VAL_SLOTNUMBER  "SlotNumber"
#define REGSTR_VAL_ATTACHEDCOMPONENTS  "AttachedComponents"
#define REGSTR_VAL_BASEDEVICEPATH  "BaseDevicePath"
#define REGSTR_VAL_SYSTEMBUSNUMBER  "SystemBusNumber"
#define REGSTR_VAL_BUSDATATYPE  "BusDataType"
#define REGSTR_VAL_INTERFACETYPE  "InterfaceType"
#define REGSTR_VAL_SERVICE  "Service"
#define REGSTR_VAL_DETECTSIGNATURE  "DetectSignature"
#define REGSTR_VAL_CLASSGUID  "ClassGUID"
#define REGSTR_VAL_INSTANCEIDENTIFIER  "InstanceIdentifier"
#define REGSTR_VAL_DUPLICATEOF  "DuplicateOf"
#define REGSTR_VAL_STATUSFLAGS  "StatusFlags"
#define REGSTR_VAL_DISABLECOUNT  "DisableCount"
#define REGSTR_VAL_UNKNOWNPROBLEMS  "UnknownProblem"
#define REGSTR_VAL_DOCKSTATE  "DockState"
#define REGSTR_VAL_PREFERENCEORDER  "PreferenceOrder"
#define REGSTR_VAL_USERWAITINTERVAL  "UserWaitInterval"
#define REGSTR_VAL_DEVICE_INSTANCE  "DeviceInstance"
#define REGSTR_VAL_SYMBOLIC_LINK  "SymbolicLink"
#define REGSTR_VAL_DEFAULT  "Default"
#define REGSTR_VAL_LOWERFILTERS  "LowerFilters"
#define REGSTR_VAL_UPPERFILTERS  "UpperFilters"
#define REGSTR_VAL_LOCATION_INFORMATION  "LocationInformation"
#define REGSTR_VAL_UI_NUMBER  "UINumber"
#define REGSTR_VAL_UI_NUMBER_DESC_FORMAT  "UINumberDescFormat"
#define REGSTR_VAL_CAPABILITIES  "Capabilities"
#define REGSTR_VAL_DEVICE_TYPE  "DeviceType"
#define REGSTR_VAL_DEVICE_CHARACTERISTICS  "DeviceCharacteristics"
#define REGSTR_VAL_DEVICE_SECURITY_DESCRIPTOR  "Security"
#define REGSTR_VAL_DEVICE_EXCLUSIVE  "Exclusive"
#define REGSTR_KEY_DEVICE_PROPERTIES  "Properties"
#define REGSTR_VAL_RESOURCE_PICKER_TAGS  "ResourcePickerTags"
#define REGSTR_VAL_RESOURCE_PICKER_EXCEPTIONS  "ResourcePickerExceptions"

#define REGSTR_VALUE_DEVICE_OBJECT_NAME  "DeviceObjectName"
#define REGSTR_VALUE_DEVICE_SYMBOLIC_NAME  "DeviceSymbolicName"

#define REGSTR_KEY_CONTROL  "Control"
#define REGSTR_VAL_ACTIVESERVICE  "ActiveService"
#define REGSTR_VAL_LINKED  "Linked"
#define REGSTR_VAL_PHYSICALDEVICEOBJECT  "PhysicalDeviceObject"

#define REGSTR_VAL_CURRENT_VERSION  "CurrentVersion"
#define REGSTR_VAL_CURRENT_BUILD  "CurrentBuildNumber"
#define REGSTR_VAL_CURRENT_CSDVERSION  "CSDVersion"
#define REGSTR_VAL_CURRENT_TYPE  "CurrentType"

#define REGSTR_VAL_BITSPERPIXEL  "BitsPerPixel"
#define REGSTR_VAL_RESOLUTION  "Resolution"
#define REGSTR_VAL_DPILOGICALX  "DPILogicalX"
#define REGSTR_VAL_DPILOGICALY  "DPILogicalY"
#define REGSTR_VAL_DPIPHYSICALX  "DPIPhysicalX"
#define REGSTR_VAL_DPIPHYSICALY  "DPIPhysicalY"
#define REGSTR_VAL_REFRESHRATE  "RefreshRate"
#define REGSTR_VAL_DISPLAYFLAGS  "DisplayFlags"

#define REGSTR_PATH_CONTROLPANEL  "Control Panel"
#define REGSTR_PATH_CONTROLSFOLDER  "Software\Microsoft\Windows\CurrentVersion\Controls Folder"

#define REGSTR_VAL_DOSCP  "OEMCP"
#define REGSTR_VAL_WINCP  "ACP"

#define REGSTR_PATH_DYNA_ENUM  "Config Manager\Enum"

#define REGSTR_VAL_HARDWARE_KEY  "HardWareKey"
#define REGSTR_VAL_ALLOCATION  "Allocation"
#define REGSTR_VAL_PROBLEM  "Problem"
#define REGSTR_VAL_STATUS  "Status"

#define REGSTR_VAL_DONTUSEMEM  "DontAllocLastMem"

#define REGSTR_VAL_SYSTEMROOT  "SystemRoot"
#define REGSTR_VAL_BOOTCOUNT  "BootCount"
#define REGSTR_VAL_REALNETSTART  "RealNetStart"
#define REGSTR_VAL_MEDIA  "MediaPath"
#define REGSTR_VAL_CONFIG  "ConfigPath"
#define REGSTR_VAL_DEVICEPATH  "DevicePath"
#define REGSTR_VAL_SRCPATH  "SourcePath"
#define REGSTR_VAL_SVCPAKSRCPATH  "ServicePackSourcePath"
#define REGSTR_VAL_DRIVERCACHEPATH  "DriverCachePath"
#define REGSTR_VAL_OLDWINDIR  "OldWinDir"
#define REGSTR_VAL_SETUPFLAGS  "SetupFlags"
#define REGSTR_VAL_REGOWNER  "RegisteredOwner"
#define REGSTR_VAL_REGORGANIZATION  "RegisteredOrganization"
#define REGSTR_VAL_LICENSINGINFO  "LicensingInfo"
#define REGSTR_VAL_OLDMSDOSVER  "OldMSDOSVer"
#define REGSTR_VAL_FIRSTINSTALLDATETIME  "FirstInstallDateTime"
#define REGSTR_VAL_INSTALLTYPE  "InstallType"
#define REGSTR_VAL_WRAPPER  "Wrapper"
#define REGSTR_VAL_LASTALIVEINTERVAL  "TimeStampInterval"
#define REGSTR_VAL_LASTALIVESTAMP  "LastAliveStamp"
#define REGSTR_VAL_SHUTDOWNREASON  "ShutdownReason"
#define REGSTR_VAL_SHOWREASONUI  "ShutdownReasonUI"

#define REGSTR_KEY_SETUP  "\Setup"
#define REGSTR_VAL_BOOTDIR  "BootDir"
#define REGSTR_VAL_WINBOOTDIR  "WinbootDir"
#define REGSTR_VAL_WINDIR  "WinDir"

#define REGSTR_VAL_APPINSTPATH  "AppInstallPath"

#define REGSTR_PATH_EBD "Software\Microsoft\Windows\CurrentVersion\Setup\EBD"
#define REGSTR_KEY_EBDFILESLOCAL  "EBDFilesLocale"
#define REGSTR_KEY_EBDFILESKEYBOARD  "EBDFilesKeyboard"
#define REGSTR_KEY_EBDAUTOEXECBATLOCAL  "EBDAutoexecBatLocale"
#define REGSTR_KEY_EBDAUTOEXECBATKEYBOARD  "EBDAutoexecBatKeyboard"
#define REGSTR_KEY_EBDCONFIGSYSLOCAL  "EBDConfigSysLocale"
#define REGSTR_KEY_EBDCONFIGSYSKEYBOARD  "EBDConfigSysKeyboard"

#define REGSTR_VAL_POLICY  "Policy"

#define REGSTR_VAL_BEHAVIOR_ON_FAILED_VERIFY  "BehaviorOnFailedVerify"

#define REGSTR_VAL_MSDOSMODE  "MSDOSMode"
#define REGSTR_VAL_MSDOSMODEDISCARD  "Discard"
#define REGSTR_VAL_DOSOPTGLOBALFLAGS  "GlobalFlags"
#define REGSTR_VAL_DOSOPTFLAGS  "Flags"
#define REGSTR_VAL_OPTORDER  "Order"
#define REGSTR_VAL_CONFIGSYS  "Config.Sys"
#define REGSTR_VAL_AUTOEXEC  "Autoexec.Bat"
#define REGSTR_VAL_STDDOSOPTION  "StdOption"
#define REGSTR_VAL_DOSOPTTIP  "TipText"
#define REGSTR_VAL_DOSPAGER  "DOSPager"
#define REGSTR_VAL_VXDGROUPS  "VXDGroups"
#define REGSTR_VAL_VPOWERDFLAGS  "Flags"

#define REGSTR_VAL_WORKGROUP  "Workgroup"
#define REGSTR_VAL_DIRECTHOST  "DirectHost"
#define REGSTR_VAL_FILESHARING  "FileSharing"
#define REGSTR_VAL_PRINTSHARING  "PrintSharing"

#define REGSTR_VAL_FIRSTNETDRIVE  "FirstNetworkDrive"
#define REGSTR_VAL_MAXCONNECTIONS  "MaxConnections"
#define REGSTR_VAL_APISUPPORT  "APISupport"
#define REGSTR_VAL_MAXRETRY  "MaxRetry"
#define REGSTR_VAL_MINRETRY  "MinRetry"
#define REGSTR_VAL_SUPPORTLFN  "SupportLFN"
#define REGSTR_VAL_SUPPORTBURST  "SupportBurst"
#define REGSTR_VAL_SUPPORTTUNNELLING  "SupportTunnelling"
#define REGSTR_VAL_FULLTRACE  "FullTrace"
#define REGSTR_VAL_READCACHING  "ReadCaching"
#define REGSTR_VAL_SHOWDOTS  "ShowDots"
#define REGSTR_VAL_GAPTIME  "GapTime"
#define REGSTR_VAL_SEARCHMODE  "SearchMode"
#define REGSTR_VAL_SHELLVERSION  "ShellVersion"
#define REGSTR_VAL_MAXLIP "MaxLIP"
#define REGSTR_VAL_PRESERVECASE  "PreserveCase"
#define REGSTR_VAL_OPTIMIZESFN  "OptimizeSFN"

#define REGSTR_VAL_NCP_BROWSEMASTER  "BrowseMaster"
#define REGSTR_VAL_NCP_USEPEERBROWSING  "Use_PeerBrowsing"
#define REGSTR_VAL_NCP_USESAP  "Use_Sap"

#define REGSTR_VAL_PCCARD_POWER  "EnablePowerManagement"

#define REGSTR_VAL_WIN31FILESYSTEM  "Win31FileSystem"
#define REGSTR_VAL_PRESERVELONGNAMES  "PreserveLongNames"
#define REGSTR_VAL_DRIVEWRITEBEHIND  "DriveWriteBehind"
#define REGSTR_VAL_ASYNCFILECOMMIT  "AsyncFileCommit"
#define REGSTR_VAL_PATHCACHECOUNT  "PathCache"
#define REGSTR_VAL_NAMECACHECOUNT  "NameCache"
#define REGSTR_VAL_CONTIGFILEALLOC  "ContigFileAllocSize"
#define REGSTR_VAL_FREESPACERATIO  "FreeSpaceRatio"
#define REGSTR_VAL_VOLIDLETIMEOUT  "VolumeIdleTimeout"
#define REGSTR_VAL_BUFFIDLETIMEOUT  "BufferIdleTimeout"
#define REGSTR_VAL_BUFFAGETIMEOUT  "BufferAgeTimeout"
#define REGSTR_VAL_NAMENUMERICTAIL  "NameNumericTail"
#define REGSTR_VAL_READAHEADTHRESHOLD  "ReadAheadThreshold"
#define REGSTR_VAL_DOUBLEBUFFER  "DoubleBuffer"
#define REGSTR_VAL_SOFTCOMPATMODE  "SoftCompatMode"
#define REGSTR_VAL_DRIVESPINDOWN  "DriveSpinDown"
#define REGSTR_VAL_FORCEPMIO  "ForcePMIO"
#define REGSTR_VAL_FORCERMIO  "ForceRMIO"
#define REGSTR_VAL_LASTBOOTPMDRVS  "LastBootPMDrvs"
#define REGSTR_VAL_ACSPINDOWNPREVIOUS  "ACSpinDownPrevious"
#define REGSTR_VAL_BATSPINDOWNPREVIOUS  "BatSpinDownPrevious"
#define REGSTR_VAL_VIRTUALHDIRQ  "VirtualHDIRQ"
#define REGSTR_VAL_SRVNAMECACHECOUNT  "ServerNameCacheMax"
#define REGSTR_VAL_SRVNAMECACHE  "ServerNameCache"
#define REGSTR_VAL_SRVNAMECACHENETPROV  "ServerNameCacheNumNets"
#define REGSTR_VAL_AUTOMOUNT  "AutoMountDrives"
#define REGSTR_VAL_COMPRESSIONMETHOD  "CompressionAlgorithm"
#define REGSTR_VAL_COMPRESSIONTHRESHOLD  "CompressionThreshold"
#define REGSTR_VAL_ACDRIVESPINDOWN  "ACDriveSpinDown"
#define REGSTR_VAL_BATDRIVESPINDOWN  "BatDriveSpinDown"

#define REGSTR_VAL_CDCACHESIZE  "CacheSize"
#define REGSTR_VAL_CDPREFETCH  "Prefetch"
#define REGSTR_VAL_CDPREFETCHTAIL  "PrefetchTail"
#define REGSTR_VAL_CDRAWCACHE  "RawCache"
#define REGSTR_VAL_CDEXTERRORS  "ExtendedErrors"
#define REGSTR_VAL_CDSVDSENSE  "SVDSense"
#define REGSTR_VAL_CDSHOWVERSIONS  "ShowVersions"
#define REGSTR_VAL_CDCOMPATNAMES  "MSCDEXCompatNames"
#define REGSTR_VAL_CDNOREADAHEAD  "NoReadAhead"

#define REGSTR_VAL_SCSI  "SCSI\"
#define REGSTR_VAL_ESDI  "ESDI\"
#define REGSTR_VAL_FLOP  "FLOP\"

#define REGSTR_VAL_DISK  "GenDisk"
#define REGSTR_VAL_CDROM  "GenCD"
#define REGSTR_VAL_TAPE  "TAPE"
#define REGSTR_VAL_SCANNER  "SCANNER"
#define REGSTR_VAL_FLOPPY  "FLOPPY"

#define REGSTR_VAL_SCSITID  "SCSITargetID"
#define REGSTR_VAL_SCSILUN  "SCSILUN"
#define REGSTR_VAL_REVLEVEL  "RevisionLevel"
#define REGSTR_VAL_PRODUCTID  "ProductId"
#define REGSTR_VAL_PRODUCTTYPE  "ProductType"
#define REGSTR_VAL_DEVTYPE  "DeviceType"
#define REGSTR_VAL_REMOVABLE  "Removable"
#define  REGSTR_VAL_CURDRVLET  "CurrentDriveLetterAssignment"
#define REGSTR_VAL_USRDRVLET  "UserDriveLetterAssignment"
#define REGSTR_VAL_SYNCDATAXFER  "SyncDataXfer"
#define REGSTR_VAL_AUTOINSNOTE  "AutoInsertNotification"
#define REGSTR_VAL_DISCONNECT  "Disconnect"
#define REGSTR_VAL_INT13  "Int13"
#define REGSTR_VAL_PMODE_INT13  "PModeInt13"
#define REGSTR_VAL_USERSETTINGS  "AdapterSettings"
#define REGSTR_VAL_NOIDE  "NoIDE"

#define REGSTR_VAL_DISKCLASSNAME  "DiskDrive"
#define REGSTR_VAL_CDROMCLASSNAME  "CDROM"

#define REGSTR_VAL_FORCELOAD  "ForceLoadPD"

#define REGSTR_VAL_FORCEFIFO  "ForceFIFO"
#define REGSTR_VAL_FORCECL  "ForceChangeLine"

#define REGSTR_VAL_NOUSECLASS  "NoUseClass"
#define REGSTR_VAL_NOINSTALLCLASS  "NoInstallClass"
#define REGSTR_VAL_NODISPLAYCLASS  "NoDisplayClass"
#define REGSTR_VAL_SILENTINSTALL  "SilentInstall"

#define REGSTR_KEY_PCMCIA_CLASS  "PCMCIA"
#define REGSTR_KEY_SCSI_CLASS  "SCSIAdapter"
#define REGSTR_KEY_PORTS_CLASS  "ports"
#define REGSTR_KEY_MEDIA_CLASS  "MEDIA"
#define REGSTR_KEY_DISPLAY_CLASS  "Display"
#define REGSTR_KEY_KEYBOARD_CLASS  "Keyboard"
#define REGSTR_KEY_MOUSE_CLASS  "Mouse"
#define REGSTR_KEY_MONITOR_CLASS  "Monitor"
#define REGSTR_KEY_MODEM_CLASS  "Modem"

#define REGSTR_VAL_PCMCIA_OPT  "Options"
#define REGSTR_VAL_PCMCIA_MEM  "Memory"
#define REGSTR_VAL_PCMCIA_ALLOC "AllocMemWin"
#define REGSTR_VAL_PCMCIA_ATAD  "ATADelay"
#define REGSTR_VAL_PCMCIA_SIZ  "MinRegionSize"

#define REGSTR_VAL_P1284MDL  "Model"
#define REGSTR_VAL_P1284MFG "Manufacturer"

#define REGSTR_VAL_ISAPNP  "ISAPNP"
#define REGSTR_VAL_ISAPNP_RDP_OVERRIDE  "RDPOverRide"

#define REGSTR_VAL_PCI  "PCI"
#define REGSTR_PCI_OPTIONS  "Options"
#define REGSTR_PCI_DUAL_IDE  "PCIDualIDE"

#define REGSTR_KEY_CRASHES  "Crashes"
#define REGSTR_KEY_DANGERS  "Dangers"
#define REGSTR_KEY_DETMODVARS  "DetModVars"
#define REGSTR_KEY_NDISINFO  "NDISInfo"
#define REGSTR_VAL_PROTINIPATH  "ProtIniPath"
#define REGSTR_VAL_RESOURCES  "Resources"
#define REGSTR_VAL_CRASHFUNCS  "CrashFuncs"
#define REGSTR_VAL_CLASS  "Class"
#define REGSTR_VAL_DEVDESC  "DeviceDesc"
#define REGSTR_VAL_BOOTCONFIG  "BootConfig"
#define REGSTR_VAL_DETFUNC  "DetFunc"
#define REGSTR_VAL_DETFLAGS  "DetFlags"
#define REGSTR_VAL_COMPATIBLEIDS  "CompatibleIDs"
#define REGSTR_VAL_DETCONFIG  "DetConfig"
#define REGSTR_VAL_VERIFYKEY  "VerifyKey"
#define REGSTR_VAL_COMINFO  "ComInfo"
#define REGSTR_VAL_INFNAME  "InfName"
#define REGSTR_VAL_CARDSPECIFIC  "CardSpecific"
#define REGSTR_VAL_NETOSTYPE  "NetOSType"
#define REGSTR_DATA_NETOS_NDIS  "NDIS"
#define REGSTR_DATA_NETOS_ODI  "ODI"
#define REGSTR_DATA_NETOS_IPX  "IPX"
#define REGSTR_VAL_MFG  "Mfg"
#define REGSTR_VAL_SCAN_ONLY_FIRST  "ScanOnlyFirstDrive"
#define REGSTR_VAL_SHARE_IRQ  "ForceIRQSharing"
#define REGSTR_VAL_NONSTANDARD_ATAPI  "NonStandardATAPI"
#define REGSTR_VAL_IDE_FORCE_SERIALIZE  "ForceSerialization"
#define REGSTR_VAL_HWREV  "HWRevision"
#define REGSTR_VAL_ENABLEINTS  "EnableInts"

#define REGSTR_VAL_APMBIOSVER  "APMBiosVer"
#define REGSTR_VAL_APMFLAGS  "APMFlags"
#define REGSTR_VAL_SLSUPPORT  "SLSupport"
#define REGSTR_VAL_MACHINETYPE  "MachineType"
#define REGSTR_VAL_SETUPMACHINETYPE  "SetupMachineType"
#define REGSTR_MACHTYPE_UNKNOWN  "Unknown"
#define REGSTR_MACHTYPE_IBMPC  "IBM PC"
#define REGSTR_MACHTYPE_IBMPCJR  "IBM PCjr"
#define REGSTR_MACHTYPE_IBMPCCONV  "IBM PC Convertible"
#define REGSTR_MACHTYPE_IBMPCXT  "IBM PC/XT"
#define REGSTR_MACHTYPE_IBMPCXT_286  "IBM PC/XT 286"
#define REGSTR_MACHTYPE_IBMPCAT  "IBM PC/AT"
#define REGSTR_MACHTYPE_IBMPS2_25  "IBM PS/2-25"
#define REGSTR_MACHTYPE_IBMPS2_30_286  "IBM PS/2-30 286"
#define REGSTR_MACHTYPE_IBMPS2_30  "IBM PS/2-30"
#define REGSTR_MACHTYPE_IBMPS2_50  "IBM PS/2-50"
#define REGSTR_MACHTYPE_IBMPS2_50Z  "IBM PS/2-50Z"
#define REGSTR_MACHTYPE_IBMPS2_55SX  "IBM PS/2-55SX"
#define REGSTR_MACHTYPE_IBMPS2_60  "IBM PS/2-60"
#define REGSTR_MACHTYPE_IBMPS2_65SX  "IBM PS/2-65SX"
#define REGSTR_MACHTYPE_IBMPS2_70  "IBM PS/2-70"
#define REGSTR_MACHTYPE_IBMPS2_P70  "IBM PS/2-P70"
#define REGSTR_MACHTYPE_IBMPS2_70_80  "IBM PS/2-70/80"
#define REGSTR_MACHTYPE_IBMPS2_80  "IBM PS/2-80"
#define REGSTR_MACHTYPE_IBMPS2_90  "IBM PS/2-90"
#define REGSTR_MACHTYPE_IBMPS1  "IBM PS/1"
#define REGSTR_MACHTYPE_PHOENIX_PCAT  "Phoenix PC/AT Compatible"
#define REGSTR_MACHTYPE_HP_VECTRA  "HP Vectra"
#define REGSTR_MACHTYPE_ATT_PC  "AT&T PC"
#define REGSTR_MACHTYPE_ZENITH_PC "Zenith PC"

#define REGSTR_VAL_APMMENUSUSPEND  "APMMenuSuspend"
#define REGSTR_VAL_APMACTIMEOUT  "APMACTimeout"
#define REGSTR_VAL_APMBATTIMEOUT  "APMBatTimeout"
#define REGSTR_VAL_APMSHUTDOWNPOWER "APMShutDownPower"

#define REGSTR_VAL_BUSTYPE  "BusType"
#define REGSTR_VAL_CPU  "CPU"
#define REGSTR_VAL_NDP  "NDP"
#define REGSTR_VAL_PNPBIOSVER  "PnPBIOSVer"
#define REGSTR_VAL_PNPSTRUCOFFSET  "PnPStrucOffset"
#define REGSTR_VAL_PCIBIOSVER  "PCIBIOSVer"
#define REGSTR_VAL_HWMECHANISM  "HWMechanism"
#define REGSTR_VAL_LASTPCIBUSNUM  "LastPCIBusNum"
#define REGSTR_VAL_CONVMEM  "ConvMem"
#define REGSTR_VAL_EXTMEM  "ExtMem"
#define REGSTR_VAL_COMPUTERNAME  "ComputerName"
#define REGSTR_VAL_BIOSNAME  "BIOSName"
#define REGSTR_VAL_BIOSVERSION  "BIOSVersion"
#define REGSTR_VAL_BIOSDATE  "BIOSDate"
#define REGSTR_VAL_MODEL  "Model"
#define REGSTR_VAL_SUBMODEL  "Submodel"
#define REGSTR_VAL_REVISION  "Revision"

#define REGSTR_VAL_FIFODEPTH  "FIFODepth"
#define REGSTR_VAL_RDINTTHRESHOLD  "RDIntThreshold"
#define REGSTR_VAL_WRINTTHRESHOLD  "WRIntThreshold"

#define REGSTR_VAL_PRIORITY  "Priority"
#define REGSTR_VAL_DRIVER  "Driver"
#define REGSTR_VAL_FUNCDESC  "FunctionDesc"
#define REGSTR_VAL_FORCEDCONFIG  "ForcedConfig"
#define REGSTR_VAL_CONFIGFLAGS  "ConfigFlags"
#define REGSTR_VAL_CSCONFIGFLAGS  "CSConfigFlags"

#define REGSTR_VAL_ROOT_DEVNODE  "HTREE\ROOT\0"
#define REGSTR_VAL_RESERVED_DEVNODE  "HTREE\RESERVED\0"
#define REGSTR_PATH_READDATAPORT  "ISAPnP\ReadDataPort\0"

#define REGSTR_PATH_MULTI_FUNCTION  "MF"
#define REGSTR_VAL_RESOURCE_MAP  "ResourceMap"
#define REGSTR_PATH_CHILD_PREFIX  "Child"
#define REGSTR_VAL_MF_FLAGS  "MFFlags"

#define REGSTR_VAL_EISA_RANGES  "EISARanges"
#define REGSTR_VAL_EISA_FUNCTIONS  "EISAFunctions"
#define REGSTR_VAL_EISA_FUNCTIONS_MASK  "EISAFunctionsMask"
#define REGSTR_VAL_EISA_FLAGS  "EISAFlags"
#define REGSTR_VAL_EISA_SIMULATE_INT15  "EISASimulateInt15"

#define REGSTR_VAL_DRVDESC  "DriverDesc"
#define REGSTR_VAL_DEVLOADER  "DevLoader"
#define REGSTR_VAL_STATICVXD  "StaticVxD"
#define REGSTR_VAL_PROPERTIES  "Properties"
#define REGSTR_VAL_MANUFACTURER  "Manufacturer"
#define REGSTR_VAL_EXISTS  "Exists"
#define REGSTR_VAL_CMENUMFLAGS  "CMEnumFlags"
#define REGSTR_VAL_CMDRIVFLAGS  "CMDrivFlags"
#define REGSTR_VAL_ENUMERATOR  "Enumerator"
#define REGSTR_VAL_DEVICEDRIVER  "DeviceDriver"
#define REGSTR_VAL_PORTNAME  "PortName"
#define REGSTR_VAL_INFPATH  "InfPath"
#define REGSTR_VAL_INFSECTION  "InfSection"
#define REGSTR_VAL_INFSECTIONEXT  "InfSectionExt"
#define REGSTR_VAL_POLLING  "Polling"
#define REGSTR_VAL_DONTLOADIFCONFLICT  "DontLoadIfConflict"
#define REGSTR_VAL_PORTSUBCLASS  "PortSubClass"
#define REGSTR_VAL_NETCLEAN  "NetClean"
#define REGSTR_VAL_IDE_NO_SERIALIZE  "IDENoSerialize"
#define REGSTR_VAL_NOCMOSORFDPT  "NoCMOSorFDPT"
#define REGSTR_VAL_COMVERIFYBASE  "COMVerifyBase"
#define REGSTR_VAL_MATCHINGDEVID  "MatchingDeviceId"
#define REGSTR_VAL_DRIVERDATE  "DriverDate"
#define REGSTR_VAL_DRIVERDATEDATA  "DriverDateData"
#define REGSTR_VAL_DRIVERVERSION  "DriverVersion"

#define REGSTR_KEY_OVERRIDE  "Override"

#define REGSTR_VAL_CONFIGMG  "CONFIGMG"
#define REGSTR_VAL_SYSDM  "SysDM"
#define REGSTR_VAL_SYSDMFUNC  "SysDMFunc"
#define REGSTR_VAL_PRIVATE  "Private"
#define REGSTR_VAL_PRIVATEFUNC  "PrivateFunc"
#define REGSTR_VAL_DETECT  "Detect"
#define REGSTR_VAL_DETECTFUNC  "DetectFunc"
#define REGSTR_VAL_ASKFORCONFIG  "AskForConfig"
#define REGSTR_VAL_ASKFORCONFIGFUNC  "AskForConfigFunc"
#define REGSTR_VAL_WAITFORUNDOCK  "WaitForUndock"
#define REGSTR_VAL_WAITFORUNDOCKFUNC  "WaitForUndockFunc"
#define REGSTR_VAL_REMOVEROMOKAY  "RemoveRomOkay"
#define REGSTR_VAL_REMOVEROMOKAYFUNC  "RemoveRomOkayFunc"

#define REGSTR_VAL_CURCONFIG  "CurrentConfig"
#define REGSTR_VAL_FRIENDLYNAME  "FriendlyName"
#define REGSTR_VAL_CURRENTCONFIG  "CurrentConfig"
#define REGSTR_VAL_MAP  "Map"
#define REGSTR_VAL_ID  "CurrentID"
#define REGSTR_VAL_DOCKED  "CurrentDockedState"
#define REGSTR_VAL_CHECKSUM  "CurrentChecksum"
#define REGSTR_VAL_HWDETECT  "HardwareDetect"
#define REGSTR_VAL_INHIBITRESULTS  "InhibitResults"

#define REGSTR_VAL_PROFILEFLAGS  "ProfileFlags"

#define REGSTR_KEY_PCMCIA  "PCMCIA\"
#define REGSTR_KEY_PCUNKNOWN  "UNKNOWN_MANUFACTURER"
#define REGSTR_VAL_PCSSDRIVER  "Driver"
#define REGSTR_KEY_PCMTD  "MTD-"
#define REGSTR_VAL_PCMTDRIVER  "MTD"

#define REGSTR_VAL_HARDWAREID  "HardwareID"

#define REGSTR_VAL_INSTALLER  "Installer"
#define REGSTR_VAL_INSTALLER_32  "Installer32"
#define REGSTR_VAL_INSICON  "Icon"
#define REGSTR_VAL_LEGACYINFOPT  "LegacyInfOption"
#define REGSTR_VAL_ENUMPROPPAGES  "EnumPropPages"
#define REGSTR_VAL_ENUMPROPPAGES_32  "EnumPropPages32"
#define REGSTR_VAL_BASICPROPERTIES  "BasicProperties"
#define REGSTR_VAL_BASICPROPERTIES_32  "BasicProperties32"
#define REGSTR_VAL_COINSTALLERS_32  "CoInstallers32"
#define REGSTR_VAL_PRIVATEPROBLEM  "PrivateProblem"

#define REGSTR_KEY_CURRENT  "Current"
#define REGSTR_KEY_DEFAULT  "Default"
#define REGSTR_KEY_MODES  "Modes"

#define REGSTR_VAL_MODE  "Mode"
#define REGSTR_VAL_BPP  "BPP"
#define REGSTR_VAL_HRES  "HRes"
#define REGSTR_VAL_VRES  "VRes"
#define REGSTR_VAL_FONTSIZE  "FontSize"
#define REGSTR_VAL_DRV  "drv"
#define REGSTR_VAL_GRB  "grb"
#define REGSTR_VAL_VDD  "vdd"
#define REGSTR_VAL_VER  "Ver"
#define REGSTR_VAL_MAXRES  "MaxResolution"
#define REGSTR_VAL_DPMS  "DPMS"
#define REGSTR_VAL_RESUMERESET  "ResumeReset"
#define REGSTR_VAL_DESCRIPTION "Description"

#define REGSTR_KEY_SYSTEM  "System"
#define REGSTR_KEY_USER  "User"
#define REGSTR_VAL_DPI  "dpi"

#define REGSTR_VAL_PCICOPTIONS  "PCICOptions"
#define REGSTR_VAL_PCICIRQMAP  "PCICIRQMap"

#define REGSTR_PATH_APPEARANCE  "Control Panel\Appearance"
#define REGSTR_PATH_LOOKSCHEMES  "Control Panel\Appearance\Schemes"
#define REGSTR_VAL_CUSTOMCOLORS  "CustomColors"

#define REGSTR_PATH_SCREENSAVE  "Control Panel\Desktop"
#define REGSTR_VALUE_USESCRPASSWORD  "ScreenSaveUsePassword"
#define REGSTR_VALUE_SCRPASSWORD  "ScreenSave_Data"

#define REGSTR_VALUE_LOWPOWERTIMEOUT  "ScreenSaveLowPowerTimeout"
#define REGSTR_VALUE_POWEROFFTIMEOUT  "ScreenSavePowerOffTimeout"
#define REGSTR_VALUE_LOWPOWERACTIVE  "ScreenSaveLowPowerActive"
#define REGSTR_VALUE_POWEROFFACTIVE  "ScreenSavePowerOffActive"

#define REGSTR_PATH_WINDOWSAPPLETS "Software\Microsoft\Windows\CurrentVersion\Applets"

#define REGSTR_PATH_SYSTRAY  "Software\Microsoft\Windows\CurrentVersion\Applets\SysTray"
#define REGSTR_VAL_SYSTRAYSVCS  "Services"
#define REGSTR_VAL_SYSTRAYBATFLAGS  "PowerFlags"
#define REGSTR_VAL_SYSTRAYPCCARDFLAGS  "PCMCIAFlags"

#define REGSTR_PATH_NETWORK_USERSETTINGS  "Network"

#define REGSTR_KEY_NETWORK_PERSISTENT  "\Persistent"
#define REGSTR_KEY_NETWORK_RECENT  "\Recent"
#define REGSTR_VAL_REMOTE_PATH  "RemotePath"
#define REGSTR_VAL_USER_NAME  "UserName"
#define REGSTR_VAL_PROVIDER_NAME  "ProviderName"
#define REGSTR_VAL_CONNECTION_TYPE  "ConnectionType"
#define REGSTR_VAL_UPGRADE  "Upgrade"

#define REGSTR_KEY_LOGON  "\Logon"
#define REGSTR_VAL_MUSTBEVALIDATED  "MustBeValidated"
#define REGSTR_VAL_RUNLOGINSCRIPT  "ProcessLoginScript"

#define REGSTR_KEY_NETWORKPROVIDER  "\NetworkProvider"
#define REGSTR_PATH_NW32NETPROVIDER  "System\CurrentControlSet\Services\NWNP32\NetworkProvider"
#define REGSTR_PATH_MS32NETPROVIDER  "System\CurrentControlSet\Services\MSNP32\NetworkProvider"
#define REGSTR_VAL_AUTHENT_AGENT  "AuthenticatingAgent"

#define REGSTR_VAL_PREFREDIR  "PreferredRedir"
#define REGSTR_VAL_AUTOSTART  "AutoStart"
#define REGSTR_VAL_AUTOLOGON  "AutoLogon"
#define REGSTR_VAL_NETCARD  "Netcard"
#define REGSTR_VAL_TRANSPORT  "Transport"
#define REGSTR_VAL_DYNAMIC  "Dynamic"
#define REGSTR_VAL_TRANSITION  "Transition"
#define REGSTR_VAL_STATICDRIVE  "StaticDrive"
#define REGSTR_VAL_LOADHI  "LoadHi"
#define REGSTR_VAL_LOADRMDRIVERS  "LoadRMDrivers"
#define REGSTR_VAL_SETUPN  "SetupN"
#define REGSTR_VAL_SETUPNPATH  "SetupNPath"

#define REGSTR_VAL_WRKGRP_FORCEMAPPING  "WrkgrpForceMapping"
#define REGSTR_VAL_WRKGRP_REQUIRED  "WrkgrpRequired"

#define REGSTR_PATH_CURRENT_CONTROL_SET  "System\CurrentControlSet\Control"
#define REGSTR_VAL_CURRENT_USER  "Current User"

#define REGSTR_PATH_PWDPROVIDER  "System\CurrentControlSet\Control\PwdProvider"
#define REGSTR_VAL_PWDPROVIDER_PATH  "ProviderPath"
#define REGSTR_VAL_PWDPROVIDER_DESC  "Description"
#define REGSTR_VAL_PWDPROVIDER_CHANGEPWD  "ChangePassword"
#define REGSTR_VAL_PWDPROVIDER_CHANGEPWDHWND  "ChangePasswordHwnd"
#define REGSTR_VAL_PWDPROVIDER_GETPWDSTATUS  "GetPasswordStatus"
#define REGSTR_VAL_PWDPROVIDER_ISNP  "NetworkProvider"
#define REGSTR_VAL_PWDPROVIDER_CHANGEORDER  "ChangeOrder"

#define REGSTR_PATH_POLICIES  "Software\Microsoft\Windows\CurrentVersion\Policies"

#define REGSTR_PATH_UPDATE  "System\CurrentControlSet\Control\Update"
#define REGSTR_VALUE_ENABLE  "Enable"
#define REGSTR_VALUE_VERBOSE  "Verbose"
#define REGSTR_VALUE_NETPATH  "NetworkPath"
#define REGSTR_VALUE_DEFAULTLOC  "UseDefaultNetLocation"

#define REGSTR_KEY_NETWORK  "Network"
#define REGSTR_KEY_SYSTEM  "System"
#define REGSTR_KEY_PRINTERS  "Printers"
#define REGSTR_KEY_WINOLDAPP  "WinOldApp"

#define REGSTR_VAL_NOFILESHARING  "NoFileSharing"
#define REGSTR_VAL_NOPRINTSHARING  "NoPrintSharing"
#define REGSTR_VAL_NOFILESHARINGCTRL  "NoFileSharingControl"
#define REGSTR_VAL_NOPRINTSHARINGCTRL  "NoPrintSharingControl"
#define REGSTR_VAL_HIDESHAREPWDS  "HideSharePwds"
#define REGSTR_VAL_DISABLEPWDCACHING  "DisablePwdCaching"
#define REGSTR_VAL_ALPHANUMPWDS  "AlphanumPwds"
#define REGSTR_VAL_NETSETUP_DISABLE  "NoNetSetup"
#define REGSTR_VAL_NETSETUP_NOCONFIGPAGE  "NoNetSetupConfigPage"
#define REGSTR_VAL_NETSETUP_NOIDPAGE  "NoNetSetupIDPage"
#define REGSTR_VAL_NETSETUP_NOSECURITYPAGE  "NoNetSetupSecurityPage"
#define REGSTR_VAL_SYSTEMCPL_NOVIRTMEMPAGE  "NoVirtMemPage"
#define REGSTR_VAL_SYSTEMCPL_NODEVMGRPAGE  "NoDevMgrPage"
#define REGSTR_VAL_SYSTEMCPL_NOCONFIGPAGE  "NoConfigPage"
#define REGSTR_VAL_SYSTEMCPL_NOFILESYSPAGE  "NoFileSysPage"
#define REGSTR_VAL_DISPCPL_NODISPCPL  "NoDispCPL"
#define REGSTR_VAL_DISPCPL_NOBACKGROUNDPAGE  "NoDispBackgroundPage"
#define REGSTR_VAL_DISPCPL_NOSCRSAVPAGE  "NoDispScrSavPage"
#define REGSTR_VAL_DISPCPL_NOAPPEARANCEPAGE  "NoDispAppearancePage"
#define REGSTR_VAL_DISPCPL_NOSETTINGSPAGE  "NoDispSettingsPage"
#define REGSTR_VAL_SECCPL_NOSECCPL  "NoSecCPL"
#define REGSTR_VAL_SECCPL_NOPWDPAGE  "NoPwdPage"
#define REGSTR_VAL_SECCPL_NOADMINPAGE  "NoAdminPage"
#define REGSTR_VAL_SECCPL_NOPROFILEPAGE  "NoProfilePage"
#define REGSTR_VAL_PRINTERS_HIDETABS  "NoPrinterTabs"
#define REGSTR_VAL_PRINTERS_NODELETE  "NoDeletePrinter"
#define REGSTR_VAL_PRINTERS_NOADD  "NoAddPrinter"
#define REGSTR_VAL_WINOLDAPP_DISABLED  "Disabled"
#define REGSTR_VAL_WINOLDAPP_NOREALMODE  "NoRealMode"
#define REGSTR_VAL_NOENTIRENETWORK  "NoEntireNetwork"
#define REGSTR_VAL_NOWORKGROUPCONTENTS  "NoWorkgroupContents"

#define REGSTR_VAL_MINPWDLEN  "MinPwdLen"
#define REGSTR_VAL_PWDEXPIRATION  "PwdExpiration"

#define REGSTR_VAL_WIN31PROVIDER  "Win31Provider"

#define REGSTR_VAL_DISABLEREGTOOLS  "DisableRegistryTools"

#define REGSTR_PATH_WINLOGON  "Software\Microsoft\Windows\CurrentVersion\Winlogon"
#define REGSTR_VAL_LEGALNOTICECAPTION  "LegalNoticeCaption"
#define REGSTR_VAL_LEGALNOTICETEXT  "LegalNoticeText"
#define REGSTR_VAL_DRIVE_SPINDOWN  "NoDispSpinDown"

#define REGSTR_VAL_RESTRICTRUN  "RestrictRun"
#define REGSTR_KEY_POL_USERS  "Users"
#define REGSTR_KEY_POL_COMPUTERS  "Computers"
#define REGSTR_KEY_POL_USERGROUPS  "UserGroups"
#define REGSTR_KEY_POL_DEFAULT  ".default"
#define REGSTR_KEY_POL_USERGROUPDATA  "GroupData\UserGroups\Priority"

#define REGSTR_PATH_TIMEZONE  "System\CurrentControlSet\Control\TimeZoneInformation"
#define REGSTR_VAL_TZBIAS  "Bias"
#define REGSTR_VAL_TZDLTBIAS  "DaylightBias"
#define REGSTR_VAL_TZSTDBIAS  "StandardBias"
#define REGSTR_VAL_TZACTBIAS  "ActiveTimeBias"
#define REGSTR_VAL_TZDLTFLAG  "DaylightFlag"
#define REGSTR_VAL_TZSTDSTART  "StandardStart"
#define REGSTR_VAL_TZDLTSTART  "DaylightStart"
#define REGSTR_VAL_TZDLTNAME  "DaylightName"
#define REGSTR_VAL_TZSTDNAME  "StandardName"
#define REGSTR_VAL_TZNOCHANGESTART  "NoChangeStart"
#define REGSTR_VAL_TZNOCHANGEEND  "NoChangeEnd"
#define REGSTR_VAL_TZNOAUTOTIME  "DisableAutoDaylightTimeSet"

#define REGSTR_PATH_FLOATINGPOINTPROCESSOR  "HARDWARE\DESCRIPTION\System\FloatingPointProcessor"
#define REGSTR_PATH_FLOATINGPOINTPROCESSOR0  "HARDWARE\DESCRIPTION\System\FloatingPointProcessor\0"

#define REGSTR_PATH_COMPUTRNAME  "System\CurrentControlSet\Control\ComputerName\ComputerName"
#define REGSTR_VAL_COMPUTRNAME  "ComputerName"

#define REGSTR_PATH_SHUTDOWN  "System\CurrentControlSet\Control\Shutdown"
#define REGSTR_VAL_FORCEREBOOT  "ForceReboot"
#define REGSTR_VAL_SETUPPROGRAMRAN  "SetupProgramRan"
#define REGSTR_VAL_DOES_POLLING  "PollingSupportNeeded"

#define REGSTR_PATH_KNOWNDLLS  "System\CurrentControlSet\Control\SessionManager\KnownDLLs"
#define REGSTR_PATH_KNOWN16DLLS  "System\CurrentControlSet\Control\SessionManager\Known16DLLs"
#define REGSTR_PATH_CHECKVERDLLS  "System\CurrentControlSet\Control\SessionManager\CheckVerDLLs"
#define REGSTR_PATH_WARNVERDLLS  "System\CurrentControlSet\Control\SessionManager\WarnVerDLLs"
#define REGSTR_PATH_HACKINIFILE  "System\CurrentControlSet\Control\SessionManager\HackIniFiles"
#define REGSTR_PATH_CHECKBADAPPS  "System\CurrentControlSet\Control\SessionManager\CheckBadApps"
#define REGSTR_PATH_APPPATCH  "System\CurrentControlSet\Control\SessionManager\AppPatches"
#define REGSTR_PATH_CHECKBADAPPS400  "System\CurrentControlSet\Control\SessionManager\CheckBadApps400"

#define REGSTR_PATH_SHELLSERVICEOBJECT  "Software\Microsoft\Windows\CurrentVersion\ShellServiceObject"
#define REGSTR_PATH_SHELLSERVICEOBJECTDELAYED  "Software\Microsoft\Windows\CurrentVersion\ShellServiceObjectDelayLoad"

#define REGSTR_PATH_KNOWNVXDS  "System\CurrentControlSet\Control\SessionManager\KnownVxDs"

#define REGSTR_VAL_UNINSTALLER_DISPLAYNAME  "DisplayName"
#define REGSTR_VAL_UNINSTALLER_COMMANDLINE  "UninstallString"

#define REGSTR_PATH_DESKTOP  REGSTR_PATH_SCREENSAVE
#define REGSTR_PATH_MOUSE  "Control Panel\Mouse"
#define REGSTR_PATH_KEYBOARD  "Control Panel\Keyboard"
#define REGSTR_PATH_COLORS  "Control Panel\Colors"
#define REGSTR_PATH_SOUND  "Control Panel\Sound"
#define REGSTR_PATH_METRICS  "Control Panel\Desktop\WindowMetrics"
#define REGSTR_PATH_ICONS  "Control Panel\Icons"
#define REGSTR_PATH_CURSORS  "Control Panel\Cursors"
#define REGSTR_PATH_CHECKDISK  "Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive"
#define REGSTR_PATH_CHECKDISKSET  "Settings"
#define REGSTR_PATH_CHECKDISKUDRVS  "NoUnknownDDErrDrvs"

#define REGSTR_PATH_FAULT  "Software\Microsoft\Windows\CurrentVersion\Fault"
#define REGSTR_VAL_FAULT_LOGFILE  "LogFile"

#define REGSTR_PATH_AEDEBUG  "Software\Microsoft\Windows NT\CurrentVersion\AeDebug"
#define REGSTR_VAL_AEDEBUG_DEBUGGER  "Debugger"
#define REGSTR_VAL_AEDEBUG_AUTO  "Auto"

#define REGSTR_PATH_GRPCONV  "Software\Microsoft\Windows\CurrentVersion\GrpConv"

#define REGSTR_VAL_REGITEMDELETEMESSAGE  "Removal Message"

#define REGSTR_PATH_LASTCHECK  "Software\Microsoft\Windows\CurrentVersion\Explorer\LastCheck"
#define REGSTR_PATH_LASTOPTIMIZE  "Software\Microsoft\Windows\CurrentVersion\Explorer\LastOptimize"
#define REGSTR_PATH_LASTBACKUP  "Software\Microsoft\Windows\CurrentVersion\Explorer\LastBackup"

#define REGSTR_PATH_CHKLASTCHECK  "Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive\LastCheck"
#define REGSTR_PATH_CHKLASTSURFAN  "Software\Microsoft\Windows\CurrentVersion\Applets\Check Drive\LastSurfaceAnalysis"

#define REGSTR_KEY_SHARES  "Software\Microsoft\Windows\CurrentVersion\Network\LanMan"
#define REGSTR_VAL_SHARES_FLAGS  "Flags"
#define REGSTR_VAL_SHARES_TYPE  "Type"
#define REGSTR_VAL_SHARES_PATH  "Path"
#define REGSTR_VAL_SHARES_REMARK  "Remark"
#define REGSTR_VAL_SHARES_RW_PASS  "Parm1"
#define REGSTR_VAL_SHARES_RO_PASS  "Parm2"

#define REGSTR_PATH_PRINT  "System\CurrentControlSet\Control\Print"
#define REGSTR_PATH_PRINTERS  "System\CurrentControlSet\Control\Print\Printers"
#define REGSTR_PATH_PROVIDERS  "System\CurrentControlSet\Control\Print\Providers"
#define REGSTR_PATH_MONITORS  "System\CurrentControlSet\Control\Print\Monitors"
#define REGSTR_PATH_ENVIRONMENTS  "System\CurrentControlSet\Control\Print\Environments"
#define REGSTR_VAL_START_ON_BOOT  "StartOnBoot"
#define REGSTR_VAL_PRINTERS_MASK  "PrintersMask"
#define REGSTR_VAL_DOS_SPOOL_MASK  "DOSSpoolMask"
#define REGSTR_KEY_CURRENT_ENV  "\Windows 4.0"
#define REGSTR_KEY_DRIVERS  "\Drivers"
#define REGSTR_KEY_PRINT_PROC  "\Print Processors"

#define REGSTR_PATH_EVENTLABELS  "AppEvents\EventLabels"
#define REGSTR_PATH_SCHEMES  "AppEvents\Schemes"
#define REGSTR_PATH_APPS  "AppEvents\Schemes\Apps"
#define REGSTR_PATH_APPS_DEFAULT  R"AppEvents\Schemes\Apps\.Default"
#define REGSTR_PATH_NAMES  "AppEvents\Schemes\Names"
#define REGSTR_PATH_MULTIMEDIA  "Software\Microsoft\Windows\CurrentVersion\Multimedia"
#define REGSTR_PATH_MULTIMEDIA_AUDIO  "Software\Microsoft\Multimedia\Audio"

#define REGSTR_PATH_MEDIARESOURCES   "System\CurrentControlSet\Control\MediaResources"
#define REGSTR_PATH_MEDIAPROPERTIES  "System\CurrentControlSet\Control\MediaProperties"
#define REGSTR_PATH_PRIVATEPROPERTIES  "System\CurrentControlSet\Control\MediaProperties\PrivateProperties"
#define REGSTR_PATH_PUBLICPROPERTIES  "System\CurrentControlSet\Control\MediaProperties\PublicProperties"

#define REGSTR_PATH_JOYOEM  "System\CurrentControlSet\Control\MediaProperties\PrivateProperties\Joystick\OEM"
#define REGSTR_PATH_JOYCONFIG  "System\CurrentControlSet\Control\MediaResources\Joystick"
#define REGSTR_KEY_JOYCURR  "CurrentJoystickSettings"
#define REGSTR_KEY_JOYSETTINGS  "JoystickSettings"

#define REGSTR_VAL_JOYUSERVALUES  "JoystickUserValues"
#define REGSTR_VAL_JOYCALLOUT  "JoystickCallout"

#define REGSTR_VAL_JOYNCONFIG  "Joystick%dConfiguration"
#define REGSTR_VAL_JOYNOEMNAME  "Joystick%dOEMName"
#define REGSTR_VAL_JOYNOEMCALLOUT  "Joystick%dOEMCallout"

#define REGSTR_VAL_JOYOEMCALLOUT  "OEMCallout"
#define REGSTR_VAL_JOYOEMNAME  "OEMName"
#define REGSTR_VAL_JOYOEMDATA  "OEMData"
#define REGSTR_VAL_JOYOEMXYLABEL  "OEMXYLabel"
#define REGSTR_VAL_JOYOEMZLABEL  "OEMZLabel"
#define REGSTR_VAL_JOYOEMRLABEL  "OEMRLabel"
#define REGSTR_VAL_JOYOEMPOVLABEL  "OEMPOVLabel"
#define REGSTR_VAL_JOYOEMULABEL  "OEMULabel"
#define REGSTR_VAL_JOYOEMVLABEL  "OEMVLabel"
#define REGSTR_VAL_JOYOEMTESTMOVEDESC  "OEMTestMoveDesc"
#define REGSTR_VAL_JOYOEMTESTBUTTONDESC  "OEMTestButtonDesc"
#define REGSTR_VAL_JOYOEMTESTMOVECAP  "OEMTestMoveCap"
#define REGSTR_VAL_JOYOEMTESTBUTTONCAP  "OEMTestButtonCap"
#define REGSTR_VAL_JOYOEMTESTWINCAP  "OEMTestWinCap"
#define REGSTR_VAL_JOYOEMCALCAP  "OEMCalCap"
#define REGSTR_VAL_JOYOEMCALWINCAP  "OEMCalWinCap"
#define REGSTR_VAL_JOYOEMCAL1  "OEMCal1"
#define REGSTR_VAL_JOYOEMCAL2  "OEMCal2"
#define REGSTR_VAL_JOYOEMCAL3  "OEMCal3"
#define REGSTR_VAL_JOYOEMCAL4  "OEMCal4"
#define REGSTR_VAL_JOYOEMCAL5  "OEMCal5"
#define REGSTR_VAL_JOYOEMCAL6  "OEMCal6"
#define REGSTR_VAL_JOYOEMCAL7  "OEMCal7"
#define REGSTR_VAL_JOYOEMCAL8  "OEMCal8"
#define REGSTR_VAL_JOYOEMCAL9  "OEMCal9"
#define REGSTR_VAL_JOYOEMCAL10  "OEMCal10"
#define REGSTR_VAL_JOYOEMCAL11  "OEMCal11"
#define REGSTR_VAL_JOYOEMCAL12  "OEMCal12"

#define REGSTR_PATH_DEVICEINSTALLER  "Software\Microsoft\Windows\CurrentVersion\Device Installer"

#define REGSTR_VAL_SEARCHOPTIONS  "SearchOptions"

#ifndef KERNEL_PNPI
	#define REGSTR_PATH_BIOSINFO  "System\CurrentControlSet\Control\BiosInfo"
	#define REGSTR_PATH_PCIIR  "System\CurrentControlSet\Control\Pnp\PciIrqRouting"
	#define REGSTR_VAL_OPTIONS  "Options"
	#define REGSTR_VAL_STAT  "Status"
	#define REGSTR_VAL_TABLE_STAT  "TableStatus"
	#define REGSTR_VAL_MINIPORT_STAT  "MiniportStatus"
#else
	#define REGSTR_PATH_BIOSINFO  L"\Registry\Machine\System\CurrentControlSet\Control\BiosInfo"
	#define REGSTR_PATH_PCIIR  L"\Registry\Machine\System\CurrentControlSet\Control\Pnp\PciIrqRouting"
	#define REGSTR_VAL_OPTIONS  L"Options"
	#define REGSTR_VAL_STAT  L"Status"
	#define REGSTR_VAL_TABLE_STAT  L"TableStatus"
	#define REGSTR_VAL_MINIPORT_STAT  L"MiniportStatus"
#endif /* _KERNEL_PNPI_ */

#define REGSTR_MAX_VALUE_LENGTH  256

#define IT_COMPACT  0x0000
#define IT_TYPICAL  0x0001
#define IT_PORTABLE  0x0002
#define IT_CUSTOM  0x0003

#define DRIVERSIGN_NONE  0x00000000
#define DRIVERSIGN_WARNING  0x00000001
#define DRIVERSIGN_BLOCKING  0x00000002

#define DOSOPTGF_DEFCLEAN  0x00000001

#define DOSOPTF_DEFAULT  0x00000001
#define DOSOPTF_SUPPORTED  0x00000002
#define DOSOPTF_ALWAYSUSE  0x00000004
#define DOSOPTF_USESPMODE  0x00000008
#define DOSOPTF_PROVIDESUMB  0x00000010
#define DOSOPTF_NEEDSETUP  0x00000020
#define DOSOPTF_INDOSSTART  0x00000040
#define DOSOPTF_MULTIPLE  0x00000080

#define SUF_FIRSTTIME  0x00000001
#define SUF_EXPRESS  0x00000002
#define SUF_BATCHINF  0x00000004
#define SUF_CLEAN  0x00000008
#define SUF_INSETUP  0x00000010
#define SUF_NETSETUP  0x00000020
#define SUF_NETHDBOOT  0x00000040
#define SUF_NETRPLBOOT  0x00000080
#define SUF_SBSCOPYOK  0x00000100

#define VPDF_DISABLEPWRMGMT  0x00000001
#define VPDF_FORCEAPM10MODE  0x00000002
#define VPDF_SKIPINTELSLCHECK  0x00000004
#define VPDF_DISABLEPWRSTATUSPOLL  0x00000008
#define VPDF_DISABLERINGRESUME  0x00000010
#define VPDF_SHOWMULTIBATT  0x00000020

#define PCMCIA_OPT_HAVE_SOCKET  0x00000001
#define PCMCIA_OPT_AUTOMEM  0x00000004
#define PCMCIA_OPT_NO_SOUND  0x00000008
#define PCMCIA_OPT_NO_AUDIO  0x00000010
#define PCMCIA_OPT_NO_APMREMOVE  0x00000020

#define PCMCIA_DEF_MEMBEGIN  0x000C0000
#define PCMCIA_DEF_MEMEND  0x00FFFFFF
#define PCMCIA_DEF_MEMLEN  0x00001000

#define PCMCIA_DEF_MIN_REGION  0x00010000

#define REGDF_NOTDETIO  0x00000001
#define REGDF_NOTDETMEM  0x00000002
#define REGDF_NOTDETIRQ  0x00000004
#define REGDF_NOTDETDMA  0x00000008
#define REGDF_NOTDETALL  (REGDF_NOTDETIO|REGDF_NOTDETMEM|REGDF_NOTDETIRQ|REGDF_NOTDETDMA)
#define REGDF_NEEDFULLCONFIG  0x00000010
#define REGDF_GENFORCEDCONFIG  0x00000020
#define REGDF_NODETCONFIG  0x00008000
#define REGDF_CONFLICTIO  0x00010000
#define REGDF_CONFLICTMEM  0x00020000
#define REGDF_CONFLICTIRQ  0x00040000
#define REGDF_CONFLICTDMA  0x00080000
#define REGDF_CONFLICTALL  (REGDF_CONFLICTIO|REGDF_CONFLICTMEM|REGDF_CONFLICTIRQ|REGDF_CONFLICTDMA)
#define REGDF_MAPIRQ2TO9  0x00100000
#define REGDF_NOTVERIFIED  0x80000000

#define PCI_OPTIONS_USE_BIOS  0x00000001
#define PCI_OPTIONS_USE_IRQ_STEERING  0x00000002

#define PCI_FLAG_NO_VIDEO_IRQ  0x00000001
#define PCI_FLAG_PCMCIA_WANT_IRQ  0x00000002
#define PCI_FLAG_DUAL_IDE  0x00000004
#define PCI_FLAG_NO_ENUM_AT_ALL  0x00000008
#define PCI_FLAG_ENUM_NO_RESOURCE  0x00000010
#define PCI_FLAG_NEED_DWORD_ACCESS  0x00000020
#define PCI_FLAG_SINGLE_FUNCTION  0x00000040
#define PCI_FLAG_ALWAYS_ENABLED  0x00000080
#define PCI_FLAG_IS_IDE  0x00000100
#define PCI_FLAG_IS_VIDEO  0x00000200
#define PCI_FLAG_FAIL_START  0x00000400
#define PCI_FLAG_GHOST  0x00000800
#define PCI_FLAG_DOUBLE_DECKER  0x00001000
#define PCI_FLAG_ONE_CHILD  0x00002000
#define PCI_FLAG_PRESERVE_COMMAND  0x00004000
#define PCI_FLAG_IS_VGA  0x00008000
#define PCI_FLAG_CB_SHARE_CMD_BITS  0x00010000
#define PCI_FLAG_STRAIGHT_IRQ_ROUTING  0x00020000
#define PCI_FLAG_SUBTRACTIVE_DECODE  0x00040000
#define PCI_FLAG_FDMA_ISA  0x00080000
#define PCI_FLAG_EXCLUSIVE  0x00100000
#define PCI_FLAG_EDGE  0x00200000
#define PCI_FLAG_NO_SUBSYSTEM  0x00400000
#define PCI_FLAG_NO_WPE  0x00800000
#define PCI_FLAG_OLD_ID  0x01000000
#define PCI_FLAG_DONT_SHRINK_BRIDGE  0x02000000
#define PCI_FLAG_TURN_OFF_PARITY  0x04000000
#define PCI_FLAG_NO_NON_PCI_CHILD_BAR  0x08000000
#define PCI_FLAG_NO_ENUM_WITH_DISABLE  0x10000000
#define PCI_FLAG_NO_PM_CAPS  0x20000000
#define PCI_FLAG_NO_DISABLE_DECODES  0x40000000
#define PCI_FLAG_NO_SUBSYSTEM_AFTER_D3  0x80000000

#define REGSTR_VAL_MAX_HCID_LEN  1024

#define APMMENUSUSPEND_DISABLED  0
#define APMMENUSUSPEND_ENABLED  1
#define APMMENUSUSPEND_UNDOCKED  2
#define APMMENUSUSPEND_NOCHANGE  0x80

#define APMTIMEOUT_DISABLED  0

#define CONFIGFLAG_DISABLED  0x00000001
#define CONFIGFLAG_REMOVED  0x00000002
#define CONFIGFLAG_MANUAL_INSTALL  0x00000004
#define CONFIGFLAG_IGNORE_BOOT_LC  0x00000008
#define CONFIGFLAG_NET_BOOT  0x00000010
#define CONFIGFLAG_REINSTALL  0x00000020
#define CONFIGFLAG_FAILEDINSTALL  0x00000040
#define CONFIGFLAG_CANTSTOPACHILD  0x00000080
#define CONFIGFLAG_OKREMOVEROM  0x00000100
#define CONFIGFLAG_NOREMOVEEXIT  0x00000200
#define CONFIGFLAG_FINISH_INSTALL  0x00000400
#define CONFIGFLAG_NEEDS_FORCED_CONFIG  0x00000800
#if defined(REMOTE_BOOT)
#define CONFIGFLAG_NETBOOT_CARD  0x00001000
#endif /* defined(REMOTE_BOOT) */
#define CONFIGFLAG_PARTIAL_LOG_CONF  0x00002000

#define CSCONFIGFLAG_BITS  0x00000007
#define CSCONFIGFLAG_DISABLED  0x00000001
#define CSCONFIGFLAG_DO_NOT_CREATE  0x00000002
#define CSCONFIGFLAG_DO_NOT_START  0x00000004

#define DMSTATEFLAG_APPLYTOALL  0x00000001

#define NUM_RESOURCE_MAP  256

#define MF_FLAGS_EVEN_IF_NO_RESOURCE  0x00000001
#define MF_FLAGS_NO_CREATE_IF_NO_RESOURCE  0x00000002
#define MF_FLAGS_FILL_IN_UNKNOWN_RESOURCE  0x00000004
#define MF_FLAGS_CREATE_BUT_NO_SHOW_DISABLED  0x00000008

#define EISAFLAG_NO_IO_MERGE  0x00000001
#define EISAFLAG_SLOT_IO_FIRST  0x00000002
#define EISA_NO_MAX_FUNCTION  0xFF
#define NUM_EISA_RANGES  4

#define PCIC_DEFAULT_IRQMASK  0x4EB8
#define PCIC_DEFAULT_NUMSOCKETS  0

#define PIR_OPTION_ENABLED  0x00000001
#define PIR_OPTION_REGISTRY  0x00000002
#define PIR_OPTION_MSSPEC  0x00000004
#define PIR_OPTION_REALMODE  0x00000008
#define PIR_OPTION_DEFAULT  0x0000000f

#define PIR_STATUS_ERROR  0x00000000
#define PIR_STATUS_ENABLED  0x00000001
#define PIR_STATUS_DISABLED  0x00000002
#define PIR_STATUS_MAX  0x00000003

#define PIR_STATUS_TABLE_REGISTRY  0x00000000
#define PIR_STATUS_TABLE_MSSPEC  0x00000001
#define PIR_STATUS_TABLE_REALMODE  0x00000002
#define PIR_STATUS_TABLE_NONE  0x00000003
#define PIR_STATUS_TABLE_ERROR  0x00000004
#define PIR_STATUS_TABLE_BAD  0x00000005
#define PIR_STATUS_TABLE_SUCCESS  0x00000006
#define PIR_STATUS_TABLE_MAX  0x00000007

#define PIR_STATUS_MINIPORT_NORMAL  0x00000000
#define PIR_STATUS_MINIPORT_COMPATIBLE  0x00000001
#define PIR_STATUS_MINIPORT_OVERRIDE  0x00000002
#define PIR_STATUS_MINIPORT_NONE  0x00000003
#define PIR_STATUS_MINIPORT_ERROR  0x00000004
#define PIR_STATUS_MINIPORT_NOKEY  0x00000005
#define PIR_STATUS_MINIPORT_SUCCESS  0x00000006
#define PIR_STATUS_MINIPORT_INVALID  0x00000007
#define PIR_STATUS_MINIPORT_MAX  0x00000008

#define DTRESULTOK  0
#define DTRESULTFIX  1
#define DTRESULTPROB  2
#define DTRESULTPART  3

DSKTLSYSTEMTIME STRUCT
	wYear DW
	wMonth DW
	wDayOfWeek DW
	wDay DW
	wHour DW
	wMinute DW
	wSecond DW
	wMilliseconds DW
	wResult DW
ENDS

#endif /* _REGSTR_H */