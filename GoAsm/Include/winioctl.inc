;=============================================================;
;         winioctl.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINIOCTL_INC
#Define WINIOCTL_INC

#Define FILE_DEVICE_BEEP                    000000001H
#Define FILE_DEVICE_CD_ROM                  000000002H
#Define FILE_DEVICE_CD_ROM_FILE_SYSTEM      000000003H
#Define FILE_DEVICE_CONTROLLER              000000004H
#Define FILE_DEVICE_DATALINK                000000005H
#Define FILE_DEVICE_DFS                     000000006H
#Define FILE_DEVICE_DISK                    000000007H
#Define FILE_DEVICE_DISK_FILE_SYSTEM        000000008H
#Define FILE_DEVICE_FILE_SYSTEM             000000009H
#Define FILE_DEVICE_INPORT_PORT             00000000AH
#Define FILE_DEVICE_KEYBOARD                00000000BH
#Define FILE_DEVICE_MAILSLOT                00000000CH
#Define FILE_DEVICE_MIDI_IN                 00000000DH
#Define FILE_DEVICE_MIDI_OUT                00000000EH
#Define FILE_DEVICE_MOUSE                   00000000FH
#Define FILE_DEVICE_MULTI_UNC_PROVIDER      000000010H
#Define FILE_DEVICE_NAMED_PIPE              000000011H
#Define FILE_DEVICE_NETWORK                 000000012H
#Define FILE_DEVICE_NETWORK_BROWSER         000000013H
#Define FILE_DEVICE_NETWORK_FILE_SYSTEM     000000014H
#Define FILE_DEVICE_NULL                    000000015H
#Define FILE_DEVICE_PARALLEL_PORT           000000016H
#Define FILE_DEVICE_PHYSICAL_NETCARD        000000017H
#Define FILE_DEVICE_PRINTER                 000000018H
#Define FILE_DEVICE_SCANNER                 000000019H
#Define FILE_DEVICE_SERIAL_MOUSE_PORT       00000001AH
#Define FILE_DEVICE_SERIAL_PORT             00000001BH
#Define FILE_DEVICE_SCREEN                  00000001CH
#Define FILE_DEVICE_SOUND                   00000001DH
#Define FILE_DEVICE_STREAMS                 00000001EH
#Define FILE_DEVICE_TAPE                    00000001FH
#Define FILE_DEVICE_TAPE_FILE_SYSTEM        000000020H
#Define FILE_DEVICE_TRANSPORT               000000021H
#Define FILE_DEVICE_UNKNOWN                 000000022H
#Define FILE_DEVICE_VIDEO                   000000023H
#Define FILE_DEVICE_VIRTUAL_DISK            000000024H
#Define FILE_DEVICE_WAVE_IN                 000000025H
#Define FILE_DEVICE_WAVE_OUT                000000026H
#Define FILE_DEVICE_8042_PORT               000000027H
#Define FILE_DEVICE_NETWORK_REDIRECTOR      000000028H
#Define FILE_DEVICE_BATTERY                 000000029H
#Define FILE_DEVICE_BUS_EXTENDER            00000002AH
#Define FILE_DEVICE_MODEM                   00000002BH
#Define FILE_DEVICE_VDM                     00000002CH
#Define FILE_DEVICE_MASS_STORAGE            00000002DH
#Define FILE_DEVICE_SMB                     00000002EH
#Define FILE_DEVICE_KS                      00000002FH
#Define FILE_DEVICE_CHANGER                 000000030H
#Define FILE_DEVICE_SMARTCARD               000000031H
#Define FILE_DEVICE_ACPI                    000000032H
#Define FILE_DEVICE_DVD                     000000033H
#Define FILE_DEVICE_FULLSCREEN_VIDEO        000000034H
#Define FILE_DEVICE_DFS_FILE_SYSTEM         000000035H
#Define FILE_DEVICE_DFS_VOLUME              000000036H

#Define METHOD_BUFFERED                     0
#Define METHOD_IN_DIRECT                    1
#Define METHOD_OUT_DIRECT                   2
#Define METHOD_NEITHER                      3

#Define FILE_ANY_ACCESS                     0
#Define FILE_READ_ACCESS                    (00001H)
#Define FILE_WRITE_ACCESS                   (00002H)

#Define IOCTL_STORAGE_BASE                  FILE_DEVICE_MASS_STORAGE

#Define IOCTL_STORAGE_CHECK_VERIFY          (IOCTL_STORAGE_BASE<<16) | (00200H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_STORAGE_MEDIA_REMOVAL         (IOCTL_STORAGE_BASE<<16) | (00201H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_STORAGE_EJECT_MEDIA           (IOCTL_STORAGE_BASE<<16) | (00202H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_STORAGE_LOAD_MEDIA            (IOCTL_STORAGE_BASE<<16) | (00203H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_STORAGE_RESERVE               (IOCTL_STORAGE_BASE<<16) | (00204H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_STORAGE_RELEASE               (IOCTL_STORAGE_BASE<<16) | (00205H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_STORAGE_FIND_NEW_DEVICES      (IOCTL_STORAGE_BASE<<16) | (00206H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)

#Define IOCTL_STORAGE_GET_MEDIA_TYPES       (IOCTL_STORAGE_BASE<<16) | (00300H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_STORAGE_GET_MEDIA_TYPES_EX    (IOCTL_STORAGE_BASE<<16) | (00301H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)

#Define IOCTL_STORAGE_RESET_BUS             (IOCTL_STORAGE_BASE<<16) | (00400H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_STORAGE_RESET_DEVICE          (IOCTL_STORAGE_BASE<<16) | (00401H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)

#Define IOCTL_STORAGE_GET_DEVICE_NUMBER     (IOCTL_STORAGE_BASE<<16) | (00420H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)

STORAGE_DEVICE_NUMBER Struct
	DeviceType DD
	DeviceNumber DD
	PartitionNumber DD
EndS

STORAGE_BUS_RESET_REQUEST Struct
	PathId DB
EndS

PREVENT_MEDIA_REMOVAL Struct
	PreventMediaRemoval DD
EndS

TAPE_STATISTICS Struct
	Version DD
	iFlags DD
	RecoveredWrites DQ
	UnrecoveredWrites DQ
	RecoveredReads DQ
	UnrecoveredReads DQ
	CompressionRatioReads DB
	CompressionRatioWrites DB
EndS

#Define RECOVERED_WRITES_VALID              000000001H
#Define UNRECOVERED_WRITES_VALID            000000002H
#Define RECOVERED_READS_VALID               000000004H
#Define UNRECOVERED_READS_VALID             000000008H
#Define WRITE_COMPRESSION_INFO_VALID        000000010H
#Define READ_COMPRESSION_INFO_VALID         000000020H

TAPE_GET_STATISTICS Struct
	Operation DD
EndS

#Define TAPE_RETURN_STATISTICS              0
#Define TAPE_RETURN_ENV_INFO                1
#Define TAPE_RESET_STATISTICS               2

;STORAGE_MEDIA_TYPE enumeration
#Define DDS_4mm                             32
#Define MiniQic                             33
#Define Travan                              34
#Define QIC                                 35
#Define MP_8mm                              36
#Define AME_8mm                             37
#Define AIT1_8mm                            38
#Define DLT                                 39
#Define NCTP                                40
#Define IBM_3480                            41
#Define IBM_3490E                           42
#Define IBM_Magstar_3590                    43
#Define IBM_Magstar_MP                      44
#Define STK_DATA_D3                         45
#Define SONY_DTF                            46
#Define DV_6mm                              47
#Define DMI                                 48
#Define SONY_D2                             49
#Define CLEANER_CARTRIDGE                   50
#Define CD_ROM                              51
#Define CD_R                                52
#Define CD_RW                               53
#Define DVD_ROM                             54
#Define DVD_R                               55
#Define DVD_RW                              56
#Define MO_3_RW                             57
#Define MO_5_WO                             58
#Define MO_5_RW                             59
#Define MO_5_LIMDOW                         60
#Define PC_5_WO                             61
#Define PC_5_RW                             62
#Define PD_5_RW                             63
#Define ABL_5_WO                            64
#Define PINNACLE_APEX_5_RW                  65
#Define SONY_12_WO                          66
#Define PHILIPS_12_WO                       67
#Define HITACHI_12_WO                       68
#Define CYGNET_12_WO                        69
#Define KODAK_14_WO                         70
#Define MO_NFR_525                          71
#Define NIKON_12_RW                         72
#Define IOMEGA_ZIP                          73
#Define IOMEGA_JAZ                          74
#Define SYQUEST_EZ135                       75
#Define SYQUEST_EZFLYER                     76
#Define SYQUEST_SYJET                       77
#Define AVATAR_F2                           78
#Define MP2_8mm                             79

#Define MEDIA_ERASEABLE                     000000001H
#Define MEDIA_WRITE_ONCE                    000000002H
#Define MEDIA_READ_ONLY                     000000004H
#Define MEDIA_READ_WRITE                    000000008H

#Define MEDIA_WRITE_PROTECTED               000000100H
#Define MEDIA_CURRENTLY_MOUNTED             080000000H

_ScsiInformation Struct
	MediumType DB
	DensityCode DB
EndS

_DiskInfo Struct
	Cylinders DQ
	MediaType DD
	TracksPerCylinder DD
	SectorsPerTrack DD
	BytesPerSector DD
	NumberMediaSides DD
	MediaCharacteristics DD
EndS

_RemovableDiskInfo Struct
	Cylinders DQ
	MediaType DD
	TracksPerCylinder DD
	SectorsPerTrack DD
	BytesPerSector DD
	NumberMediaSides DD
	MediaCharacteristics DD
EndS

_TapeInfo Struct
	MediaType DD
	MediaCharacteristics DD
	CurrentBlockSize DD
	BusType DD
	ScsiInformation _ScsiInformation <>
EndS

DEVICE_MEDIA_INFO Struct
	Union
		DiskInfo _DiskInfo <>
		RemovableDiskInfo _RemovableDiskInfo <>
		TapeInfo _TapeInfo <>
	EndUnion
EndS

GET_MEDIA_TYPES Struct
	DeviceType DD
	MediaInfoCount DD
	MediaInfo DEVICE_MEDIA_INFO <>
EndS

#Define IOCTL_DISK_BASE                     FILE_DEVICE_DISK
#Define IOCTL_DISK_GET_DRIVE_GEOMETRY       (IOCTL_DISK_BASE<<16) | (00000H<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)

#Define IOCTL_DISK_GET_DRIVE_GEOMETRY       (IOCTL_DISK_BASE<<16) | (00000H<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_GET_PARTITION_INFO       (IOCTL_DISK_BASE<<16) | (00001H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_SET_PARTITION_INFO       (IOCTL_DISK_BASE<<16) | (00002H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS
#Define IOCTL_DISK_GET_DRIVE_LAYOUT         (IOCTL_DISK_BASE<<16) | (00003H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_SET_DRIVE_LAYOUT         (IOCTL_DISK_BASE<<16) | (00004H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS
#Define IOCTL_DISK_VERIFY                   (IOCTL_DISK_BASE<<16) | (00005H<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_FORMAT_TRACKS            (IOCTL_DISK_BASE<<16) | (00006H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS
#Define IOCTL_DISK_REASSIGN_BLOCKS          (IOCTL_DISK_BASE<<16) | (00007H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS
#Define IOCTL_DISK_PERFORMANCE              (IOCTL_DISK_BASE<<16) | (00008H<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_IS_WRITABLE              (IOCTL_DISK_BASE<<16) | (00009H<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_LOGGING                  (IOCTL_DISK_BASE<<16) | (0000AH<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_FORMAT_TRACKS_EX         (IOCTL_DISK_BASE<<16) | (0000BH<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS
#Define IOCTL_DISK_HISTOGRAM_STRUCTURE      (IOCTL_DISK_BASE<<16) | (0000CH<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_HISTOGRAM_DATA           (IOCTL_DISK_BASE<<16) | (0000DH<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_HISTOGRAM_RESET          (IOCTL_DISK_BASE<<16) | (0000EH<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_REQUEST_STRUCTURE        (IOCTL_DISK_BASE<<16) | (0000FH<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define IOCTL_DISK_REQUEST_DATA             (IOCTL_DISK_BASE<<16) | (00010H<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)

#Define IOCTL_DISK_CONTROLLER_NUMBER        (IOCTL_DISK_BASE<<16) | (00011H<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)

#Define SMART_GET_VERSION                   (IOCTL_DISK_BASE<<16) | (00020H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define SMART_SEND_DRIVE_COMMAND            (IOCTL_DISK_BASE<<16) | (00021H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS
#Define SMART_RCV_DRIVE_DATA                (IOCTL_DISK_BASE<<16) | (00022H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS

#Define IOCTL_DISK_CHECK_VERIFY             (IOCTL_DISK_BASE<<16) | (00200H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_MEDIA_REMOVAL            (IOCTL_DISK_BASE<<16) | (00201H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_EJECT_MEDIA              (IOCTL_DISK_BASE<<16) | (00202H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_LOAD_MEDIA               (IOCTL_DISK_BASE<<16) | (00203H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_RESERVE                  (IOCTL_DISK_BASE<<16) | (00204H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_RELEASE                  (IOCTL_DISK_BASE<<16) | (00205H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_FIND_NEW_DEVICES         (IOCTL_DISK_BASE<<16) | (00206H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_DISK_GET_MEDIA_TYPES          (IOCTL_DISK_BASE<<16) | (00300H<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)

#Define PARTITION_ENTRY_UNUSED              000H
#Define PARTITION_FAT_12                    001H
#Define PARTITION_XENIX_1                   002H
#Define PARTITION_XENIX_2                   003H
#Define PARTITION_FAT_16                    004H
#Define PARTITION_EXTENDED                  005H
#Define PARTITION_HUGE                      006H
#Define PARTITION_IFS                       007H
#Define PARTITION_FAT32                     00BH
#Define PARTITION_FAT32_XINT13              00CH
#Define PARTITION_XINT13                    00EH
#Define PARTITION_XINT13_EXTENDED           00FH
#Define PARTITION_PREP                      041H
#Define PARTITION_LDM                       042H
#Define PARTITION_UNIX                      063H

#Define VALID_NTFT                          0C0H

#Define PARTITION_NTFT                      080H

;MEDIA_TYPE enumeration
#Define Unknown                             0
#Define F5_1Pt2_512                         1
#Define F3_1Pt44_512                        2
#Define F3_2Pt88_512                        3
#Define F3_20Pt8_512                        4
#Define F3_720_512                          5
#Define F5_360_512                          6
#Define F5_320_512                          7
#Define F5_320_1024                         8
#Define F5_180_512                          9
#Define F5_160_512                          10
#Define RemovableMedia                      11
#Define FixedMedia                          12
#Define F3_120M_512                         13
#Define F3_640_512                          14
#Define F5_640_512                          15
#Define F5_720_512                          16
#Define F3_1Pt2_512                         17
#Define F3_1Pt23_1024                       18
#Define F5_1Pt23_1024                       19
#Define F3_128Mb_512                        20
#Define F3_230Mb_512                        21
#Define F8_256_128                          22

FORMAT_PARAMETERS Struct
	MediaType DD
	StartCylinderNumber DD
	EndCylinderNumber DD
	StartHeadNumber DD
	EndHeadNumber DD
EndS

FORMAT_EX_PARAMETERS Struct
	MediaType DD
	StartCylinderNumber DD
	EndCylinderNumber DD
	StartHeadNumber DD
	EndHeadNumber DD
	FormatGapLength DW
	SectorsPerTrack DW
	SectorNumber DW
EndS

DISK_GEOMETRY Struct
	Cylinders DQ
	MediaType DD
	TracksPerCylinder DD
	SectorsPerTrack DD
	BytesPerSector DD
EndS

PARTITION_INFORMATION Struct
	StartingOffset DQ
	PartitionLength DQ
	HiddenSectors DD
	PartitionNumber DD
	PartitionType DB
	BootIndicator DD
	RecognizedPartition DD
	RewritePartition DD
EndS

SET_PARTITION_INFORMATION Struct
	PartitionType DB
EndS

DRIVE_LAYOUT_INFORMATION Struct
	PartitionCount DD
	Signature DD
	PartitionEntry PARTITION_INFORMATION <>
EndS

VERIFY_INFORMATION Struct
	StartingOffset DQ
	Length DD
EndS

REASSIGN_BLOCKS Struct
	Reserved DW
	Count DW
	BlockNumber DD
EndS

DISK_CONTROLLER_NUMBER Struct
	ControllerNumber DD
	DiskNumber DD
EndS

#Define HIST_NO_OF_BUCKETS                  24

HISTOGRAM_BUCKET Struct
	Reads DD
	Writes DD
EndS

DISK_HISTOGRAM Struct
	DiskSize LARGE_INTEGER <>
	Start LARGE_INTEGER <>
	End LARGE_INTEGER <>
	Average LARGE_INTEGER <>
	AverageRead LARGE_INTEGER <>
	AverageWrite LARGE_INTEGER <>
	Granularity DD
	Size DD
	ReadCount DD
	WriteCount DD
	Histogram DD
EndS

#Define HISTOGRAM_BUCKET_SIZE               SizeOf(HISTOGRAM_BUCKET)

#Define DISK_HISTOGRAM_SIZE                 SizeOf(DISK_HISTOGRAM)

DISK_PERFORMANCE Struct
	BytesRead LARGE_INTEGER <>
	BytesWritten LARGE_INTEGER <>
	ReadTime LARGE_INTEGER <>
	WriteTime LARGE_INTEGER <>
	IdleTime LARGE_INTEGER <>
	ReadCount DD
	WriteCount DD
	QueueDepth DD
	SplitCount DD
	QueryTime LARGE_INTEGER <>
	StorageDeviceNumber DD
	StorageManagerName DW 8 Dup ?
EndS

DISK_RECORD Struct
	ByteOffset LARGE_INTEGER <>
	StartTime LARGE_INTEGER <>
	EndTime LARGE_INTEGER <>
	VirtualAddress DD
	NumberOfBytes DD
	DeviceNumber DB
	ReadRequest DD
EndS

DISK_LOGGING Struct
	Function DB
	BufferAddress DD
	BufferSize DD
EndS

#Define DISK_LOGGING_START                  0
#Define DISK_LOGGING_STOP                   1
#Define DISK_LOGGING_DUMP                   2
#Define DISK_BINNING                        3

;BIN_TYPES enumeration
#Define RequestSize                         0
#Define RequestLocation                     1

BIN_RANGE Struct
	StartValue LARGE_INTEGER <>
	Length LARGE_INTEGER <>
EndS

PERF_BIN Struct
	NumberOfBins DD
	TypeOfBin DD
	BinsRanges BIN_RANGE <>
EndS

BIN_COUNT Struct
	BinRange BIN_RANGE <>
	BinCount DD
EndS

BIN_RESULTS Struct
	NumberOfBins DD
	BinCounts BIN_RANGE <>
EndS

GETVERSIONINPARAMS Struct
	bVersion DB
	bRevision DB
	bReserved DB
	bIDEDeviceMap DB
	fCapabilities DD
	dwReserved DD 4 Dup ?
EndS

#Define CAP_ATA_ID_CMD                      1
#Define CAP_ATAPI_ID_CMD                    2
#Define CAP_SMART_CMD                       4

IDEREGS Struct
	bFeaturesReg DB
	bSectorCountReg DB
	bSectorNumberReg DB
	bCylLowReg DB
	bCylHighReg DB
	bDriveHeadReg DB
	bCommandReg DB
	bReserved DB
EndS

#Define ATAPI_ID_CMD                        0A1H
#Define ID_CMD                              0ECH
#Define SMART_CMD                           0B0H

#Define SMART_CYL_LOW                       04FH
#Define SMART_CYL_HI                        0C2H

SENDCMDINPARAMS Struct
	cBufferSize DD
	irDriveRegs IDEREGS <>
	bDriveNumber DB
	bReserved DB 3 Dup ?
	dwReserved DD 4 Dup ?
	bBuffer DB
EndS

DRIVERSTATUS Struct
	bDriverError DB
	bIDEError DB
	bReserved DB 2 Dup ?
	dwReserved DD 2 Dup ?
EndS

#Define SMART_NO_ERROR                      0
#Define SMART_IDE_ERROR                     1
#Define SMART_INVALID_FLAG                  2
#Define SMART_INVALID_COMMAND               3
#Define SMART_INVALID_BUFFER                4
#Define SMART_INVALID_DRIVE                 5
#Define SMART_INVALID_IOCTL                 6
#Define SMART_ERROR_NO_MEM                  7
#Define SMART_INVALID_REGISTER              8
#Define SMART_NOT_SUPPORTED                 9
#Define SMART_NO_IDE_DEVICE                 10

SENDCMDOUTPARAMS Struct
	cBufferSize DD
	DriverStatus DRIVERSTATUS <>
	bBuffer DB
EndS

#Define READ_ATTRIBUTE_BUFFER_SIZE          512
#Define IDENTIFY_BUFFER_SIZE                512
#Define READ_THRESHOLD_BUFFER_SIZE          512

#Define READ_ATTRIBUTES                     0D0H
#Define READ_THRESHOLDS                     0D1H
#Define ENABLE_DISABLE_AUTOSAVE             0D2H
#Define SAVE_ATTRIBUTE_VALUES               0D3H
#Define EXECUTE_OFFLINE_DIAGS               0D4H
#Define ENABLE_SMART                        0D8H
#Define DISABLE_SMART                       0D9H
#Define RETURN_SMART_STATUS                 0DAH

#Define IOCTL_CHANGER_BASE                  FILE_DEVICE_CHANGER

#Define IOCTL_CHANGER_GET_PARAMETERS        (IOCTL_CHANGER_BASE<<16) | (00000H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)

#Define IOCTL_CHANGER_GET_PARAMETERS        (IOCTL_CHANGER_BASE<<16) | (00000H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_CHANGER_GET_STATUS            (IOCTL_CHANGER_BASE<<16) | (00001H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_CHANGER_GET_PRODUCT_DATA      (IOCTL_CHANGER_BASE<<16) | (00002H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_CHANGER_SET_ACCESS            (IOCTL_CHANGER_BASE<<16) | (00004H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS
#Define IOCTL_CHANGER_GET_ELEMENT_STATUS    (IOCTL_CHANGER_BASE<<16) | (00005H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS
#Define IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS (IOCTL_CHANGER_BASE<<16) | (00006H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_CHANGER_SET_POSITION          (IOCTL_CHANGER_BASE<<16) | (00007H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_CHANGER_EXCHANGE_MEDIUM       (IOCTL_CHANGER_BASE<<16) | (00008H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_CHANGER_MOVE_MEDIUM           (IOCTL_CHANGER_BASE<<16) | (00009H<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_CHANGER_REINITIALIZE_TRANSPORT (IOCTL_CHANGER_BASE<<16) | (0000AH<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14)
#Define IOCTL_CHANGER_QUERY_VOLUME_TAGS     (IOCTL_CHANGER_BASE<<16) | (0000BH<<2) | METHOD_BUFFERED | (FILE_READ_ACCESS<<14) | FILE_WRITE_ACCESS

#Define MAX_VOLUME_ID_SIZE                  36
#Define MAX_VOLUME_TEMPLATE_SIZE            40

#Define VENDOR_ID_LENGTH                    8
#Define PRODUCT_ID_LENGTH                   16
#Define REVISION_LENGTH                     4
#Define SERIAL_NUMBER_LENGTH                32

;ELEMENT_TYPE enumeration
#Define AllElements                         0
#Define ChangerTransport                    1
#Define ChangerSlot                         2
#Define ChangerIEPort                       3
#Define ChangerDrive                        4
#Define ChangerDoor                         5
#Define ChangerKeypad                       6
#Define ChangerMaxElement                   7

CHANGER_ELEMENT Struct
	ElementType DD
	ElementAddress DD
EndS

CHANGER_ELEMENT_LIST Struct
	Element CHANGER_ELEMENT <>
	NumberOfElements DD
EndS

#Define CHANGER_BAR_CODE_SCANNER_INSTALLED  000000001H
#Define CHANGER_INIT_ELEM_STAT_WITH_RANGE   000000002H
#Define CHANGER_CLOSE_IEPORT                000000004H
#Define CHANGER_OPEN_IEPORT                 000000008H

#Define CHANGER_STATUS_NON_VOLATILE         000000010H
#Define CHANGER_EXCHANGE_MEDIA              000000020H
#Define CHANGER_CLEANER_SLOT                000000040H
#Define CHANGER_LOCK_UNLOCK                 000000080H

#Define CHANGER_CARTRIDGE_MAGAZINE          000000100H
#Define CHANGER_MEDIUM_FLIP                 000000200H
#Define CHANGER_POSITION_TO_ELEMENT         000000400H
#Define CHANGER_REPORT_IEPORT_STATE         000000800H

#Define CHANGER_STORAGE_DRIVE               000001000H
#Define CHANGER_STORAGE_IEPORT              000002000H
#Define CHANGER_STORAGE_SLOT                000004000H
#Define CHANGER_STORAGE_TRANSPORT           000008000H

#Define CHANGER_DRIVE_CLEANING_REQUIRED     000010000H
#Define CHANGER_PREDISMOUNT_EJECT_REQUIRED  000020000H
#Define CHANGER_CLEANER_EJECT_REQUIRED      000040000H
#Define CHANGER_PREMOUNT_EJECT_REQUIRED     000080000H

#Define CHANGER_VOLUME_IDENTIFICATION       000100000H
#Define CHANGER_VOLUME_SEARCH               000200000H
#Define CHANGER_VOLUME_ASSERT               000400000H
#Define CHANGER_VOLUME_REPLACE              000800000H
#Define CHANGER_VOLUME_UNDEFINE             001000000H

#Define CHANGER_SERIAL_NUMBER_VALID         004000000H

#Define CHANGER_DEVICE_REINITIALIZE_CAPABLE 008000000H
#Define CHANGER_KEYPAD_ENABLE_DISABLE       010000000H
#Define CHANGER_DRIVE_EMPTY_ON_DOOR_ACCESS  020000000H
#Define CHANGER_PREDISMOUNT_ALIGN_DRIVE_TO_SLOT 040000000H

#Define CHANGER_CLEANER_AUTODISMOUNT        080000000H

#Define CHANGER_TO_TRANSPORT                001H
#Define CHANGER_TO_SLOT                     002H
#Define CHANGER_TO_IEPORT                   004H
#Define CHANGER_TO_DRIVE                    008H

GET_CHANGER_PARAMETERS Struct
	Size DD
	NumberTransportElements DW
	NumberStorageElements DW
	NumberCleanerSlots DW
	NumberIEElements DW
	NumberDataTransferElements DW
	NumberOfDoors DW
	FirstSlotNumber DW
	FirstDriveNumber DW
	FirstTransportNumber DW
	FirstIEPortNumber DW
	FirstCleanerSlotAddress DW
	MagazineSize DW
	DriveCleanTimeout DD
	Features0 DD
	Features1 DD
	MoveFromTransport DB
	MoveFromSlot DB
	MoveFromIePort DB
	MoveFromDrive DB
	ExchangeFromTransport DB
	ExchangeFromSlot DB
	ExchangeFromIePort DB
	ExchangeFromDrive DB
	LockUnlockCapabilities DB
	PositionCapabilities DB
	Reserved1 DB 2 Dup ?
	Reserved2 DD 2 Dup ?
EndS

CHANGER_PRODUCT_DATA Struct
	VendorId DB VENDOR_ID_LENGTH DUP (?)
	ProductId DB PRODUCT_ID_LENGTH DUP (?)
	Revision DB REVISION_LENGTH  DUP (?)
	SerialNumber DB SERIAL_NUMBER_LENGTH DUP (?)
	DeviceType DB
EndS

#Define LOCK_ELEMENT                        0
#Define UNLOCK_ELEMENT                      1
#Define EXTEND_IEPORT                       2
#Define RETRACT_IEPORT                      3

CHANGER_SET_ACCESS Struct
	Element CHANGER_ELEMENT <>
	Control DD
EndS

CHANGER_READ_ELEMENT_STATUS Struct
	ElementList CHANGER_ELEMENT_LIST <>
	VolumeTagInfo DD
EndS

CHANGER_ELEMENT_STATUS Struct
	Element CHANGER_ELEMENT <>
	SrcElementAddress CHANGER_ELEMENT <>
	Flags DD
	ExceptionCode DD
	TargetId DB
	Lun DB
	Reserved DW
	PrimaryVolumeID DB MAX_VOLUME_ID_SIZE Dup ?
	AlternateVolumeID DB MAX_VOLUME_ID_SIZE Dup ?
EndS

#Define ELEMENT_STATUS_FULL                 000000001H
#Define ELEMENT_STATUS_IMPEXP               000000002H
#Define ELEMENT_STATUS_EXCEPT               000000004H
#Define ELEMENT_STATUS_ACCESS               000000008H
#Define ELEMENT_STATUS_EXENAB               000000010H
#Define ELEMENT_STATUS_INENAB               000000020H

#Define ELEMENT_STATUS_LUN_VALID            000001000H
#Define ELEMENT_STATUS_ID_VALID             000002000H
#Define ELEMENT_STATUS_NOT_BUS              000008000H
#Define ELEMENT_STATUS_INVERT               000400000H
#Define ELEMENT_STATUS_SVALID               000800000H

#Define ELEMENT_STATUS_PVOLTAG              010000000H
#Define ELEMENT_STATUS_AVOLTAG              020000000H

#Define ERROR_LABEL_UNREADABLE              000000001H
#Define ERROR_LABEL_QUESTIONABLE            000000002H
#Define ERROR_SLOT_NOT_PRESENT              000000004H
#Define ERROR_DRIVE_NOT_INSTALLED           000000008H
#Define ERROR_TRAY_MALFUNCTION              000000010H
#Define ERROR_INIT_STATUS_NEEDED            000000011H
#Define ERROR_UNHANDLED_ERROR               0FFFFFFFFH

CHANGER_INITIALIZE_ELEMENT_STATUS Struct
	ElementList CHANGER_ELEMENT_LIST <>
	BarCodeScan DD
EndS

CHANGER_SET_POSITION Struct
	Transport CHANGER_ELEMENT <>
	Destination CHANGER_ELEMENT <>
	Flip DD
EndS

CHANGER_EXCHANGE_MEDIUM Struct
	Transport CHANGER_ELEMENT <>
	Source CHANGER_ELEMENT <>
	Destination1 CHANGER_ELEMENT <>
	Destination2 CHANGER_ELEMENT <>
	Flip1 DD
	Flip2 DD
EndS

CHANGER_MOVE_MEDIUM Struct
	Transport CHANGER_ELEMENT <>
	Source CHANGER_ELEMENT <>
	Destination CHANGER_ELEMENT <>
	Flip DD
EndS

CHANGER_SEND_VOLUME_TAG_INFORMATION Struct
	StartingElement CHANGER_ELEMENT <>
	ActionCode DD
	VolumeIDTemplate DB MAX_VOLUME_TEMPLATE_SIZE DUP (?)
EndS

READ_ELEMENT_ADDRESS_INFO Struct
	NumberOfElements DD
	ElementStatus CHANGER_ELEMENT_STATUS <>
EndS

#Define SEARCH_ALL                          00H
#Define SEARCH_PRIMARY                      01H
#Define SEARCH_ALTERNATE                    02H
#Define SEARCH_ALL_NO_SEQ                   04H
#Define SEARCH_PRI_NO_SEQ                   05H
#Define SEARCH_ALT_NO_SEQ                   06H

#Define ASSERT_PRIMARY                      08H
#Define ASSERT_ALTERNATE                    09H

#Define REPLACE_PRIMARY                     0AH
#Define REPLACE_ALTERANTE                   0BH

#Define UNDEFINE_PRIMARY                    0CH
#Define UNDEFINE_ALTERNATE                  0DH

#Define IOCTL_SERIAL_LSRMST_INSERT          (FILE_DEVICE_SERIAL_PORT<<16) | (31<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)

#Define SERIAL_LSRMST_ESCAPE                000H
#Define SERIAL_LSRMST_LSR_DATA              001H
#Define SERIAL_LSRMST_LSR_NODATA            002H
#Define SERIAL_LSRMST_MST                   003H

#Define FSCTL_REQUEST_OPLOCK_LEVEL_1        (FILE_DEVICE_FILE_SYSTEM<<16) | (0<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)

#Define FSCTL_REQUEST_OPLOCK_LEVEL_1        (FILE_DEVICE_FILE_SYSTEM<<16) | (0<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_REQUEST_OPLOCK_LEVEL_2        (FILE_DEVICE_FILE_SYSTEM<<16) | (1<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_REQUEST_BATCH_OPLOCK          (FILE_DEVICE_FILE_SYSTEM<<16) | (2<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_OPLOCK_BREAK_ACKNOWLEDGE      (FILE_DEVICE_FILE_SYSTEM<<16) | (3<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_OPBATCH_ACK_CLOSE_PENDING     (FILE_DEVICE_FILE_SYSTEM<<16) | (4<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_OPLOCK_BREAK_NOTIFY           (FILE_DEVICE_FILE_SYSTEM<<16) | (5<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_LOCK_VOLUME                   (FILE_DEVICE_FILE_SYSTEM<<16) | (6<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_UNLOCK_VOLUME                 (FILE_DEVICE_FILE_SYSTEM<<16) | (7<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_DISMOUNT_VOLUME               (FILE_DEVICE_FILE_SYSTEM<<16) | (8<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_IS_VOLUME_MOUNTED             (FILE_DEVICE_FILE_SYSTEM<<16) | (10<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_IS_PATHNAME_VALID             (FILE_DEVICE_FILE_SYSTEM<<16) | (11<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_MARK_VOLUME_DIRTY             (FILE_DEVICE_FILE_SYSTEM<<16) | (12<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_QUERY_RETRIEVAL_POINTERS      (FILE_DEVICE_FILE_SYSTEM<<16) | (14<<2) | METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_GET_COMPRESSION               (FILE_DEVICE_FILE_SYSTEM<<16) | (15<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_SET_COMPRESSION               (FILE_DEVICE_FILE_SYSTEM<<16) | (16<<2) | METHOD_BUFFERED | (FILE_READ_DATA<<14) | FILE_WRITE_DATA
#Define FSCTL_MARK_AS_SYSTEM_HIVE           (FILE_DEVICE_FILE_SYSTEM<<16) | (19<<2) | METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_OPLOCK_BREAK_ACK_NO_2         (FILE_DEVICE_FILE_SYSTEM<<16) | (20<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_INVALIDATE_VOLUMES            (FILE_DEVICE_FILE_SYSTEM<<16) | (21<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_QUERY_FAT_BPB                 (FILE_DEVICE_FILE_SYSTEM<<16) | (22<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_REQUEST_FILTER_OPLOCK         (FILE_DEVICE_FILE_SYSTEM<<16) | (23<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_FILESYSTEM_GET_STATISTICS     (FILE_DEVICE_FILE_SYSTEM<<16) | (24<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_GET_NTFS_VOLUME_DATA          (FILE_DEVICE_FILE_SYSTEM<<16) | (25<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_GET_NTFS_FILE_RECORD          (FILE_DEVICE_FILE_SYSTEM<<16) | (26<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_GET_VOLUME_BITMAP             (FILE_DEVICE_FILE_SYSTEM<<16) | (27<<2) | METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_GET_RETRIEVAL_POINTERS        (FILE_DEVICE_FILE_SYSTEM<<16) | (28<<2) | METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_MOVE_FILE                     (FILE_DEVICE_FILE_SYSTEM<<16) | (29<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_IS_VOLUME_DIRTY               (FILE_DEVICE_FILE_SYSTEM<<16) | (30<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_GET_HFS_INFORMATION           (FILE_DEVICE_FILE_SYSTEM<<16) | (31<<2) | METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_ALLOW_EXTENDED_DASD_IO        (FILE_DEVICE_FILE_SYSTEM<<16) | (32<<2) | METHOD_NEITHER | (FILE_ANY_ACCESS<<14)

#Define FSCTL_READ_PROPERTY_DATA            (FILE_DEVICE_FILE_SYSTEM<<16) | (33, METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_WRITE_PROPERTY_DATA           (FILE_DEVICE_FILE_SYSTEM<<16) | (34, METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_FIND_FILES_BY_SID             (FILE_DEVICE_FILE_SYSTEM<<16) | (35, METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_DUMP_PROPERTY_DATA            (FILE_DEVICE_FILE_SYSTEM<<16) | (37, METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_SET_OBJECT_ID                 (FILE_DEVICE_FILE_SYSTEM<<16) | (38, METHOD_BUFFERED | (FILE_WRITE_DATA<<14)
#Define FSCTL_GET_OBJECT_ID                 (FILE_DEVICE_FILE_SYSTEM<<16) | (39, METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_DELETE_OBJECT_ID              (FILE_DEVICE_FILE_SYSTEM<<16) | (40, METHOD_BUFFERED | (FILE_WRITE_DATA<<14)
#Define FSCTL_SET_REPARSE_POINT             (FILE_DEVICE_FILE_SYSTEM<<16) | (41, METHOD_BUFFERED | (FILE_WRITE_DATA<<14)
#Define FSCTL_GET_REPARSE_POINT             (FILE_DEVICE_FILE_SYSTEM<<16) | (42, METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_DELETE_REPARSE_POINT          (FILE_DEVICE_FILE_SYSTEM<<16) | (43, METHOD_BUFFERED | (FILE_WRITE_DATA<<14)
#Define FSCTL_ENUM_USN_DATA                 (FILE_DEVICE_FILE_SYSTEM<<16) | (44, METHOD_NEITHER | (FILE_READ_DATA<<14)
#Define FSCTL_SECURITY_ID_CHECK             (FILE_DEVICE_FILE_SYSTEM<<16) | (45, METHOD_NEITHER | (FILE_READ_DATA<<14)
#Define FSCTL_READ_USN_JOURNAL              (FILE_DEVICE_FILE_SYSTEM<<16) | (46, METHOD_NEITHER | (FILE_READ_DATA<<14)
#Define FSCTL_SET_OBJECT_ID_EXTENDED        (FILE_DEVICE_FILE_SYSTEM<<16) | (47, METHOD_BUFFERED | (FILE_WRITE_DATA<<14)
#Define FSCTL_CREATE_OR_GET_OBJECT_ID       (FILE_DEVICE_FILE_SYSTEM<<16) | (48, METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_SET_SPARSE                    (FILE_DEVICE_FILE_SYSTEM<<16) | (49, METHOD_BUFFERED | (FILE_WRITE_DATA<<14)
#Define FSCTL_SET_ZERO_DATA                 (FILE_DEVICE_FILE_SYSTEM<<16) | (50, METHOD_BUFFERED | (FILE_WRITE_DATA<<14)
#Define FSCTL_QUERY_ALLOCATED_RANGES        (FILE_DEVICE_FILE_SYSTEM<<16) | (51, METHOD_NEITHER | (FILE_READ_DATA<<14)
#Define FSCTL_ENABLE_UPGRADE                (FILE_DEVICE_FILE_SYSTEM<<16) | (52, METHOD_BUFFERED | (FILE_WRITE_DATA<<14)
#Define FSCTL_SET_ENCRYPTION                (FILE_DEVICE_FILE_SYSTEM<<16) | (53, METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)
#Define FSCTL_ENCRYPTION_FSCTL_IO           (FILE_DEVICE_FILE_SYSTEM<<16) | (54, METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_WRITE_RAW_ENCRYPTED           (FILE_DEVICE_FILE_SYSTEM<<16) | (55, METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_READ_RAW_ENCRYPTED            (FILE_DEVICE_FILE_SYSTEM<<16) | (56, METHOD_NEITHER | (FILE_ANY_ACCESS<<14)
#Define FSCTL_CREATE_USN_JOURNAL            (FILE_DEVICE_FILE_SYSTEM<<16) | (57, METHOD_NEITHER | (FILE_READ_DATA<<14)
#Define FSCTL_READ_FILE_USN_DATA            (FILE_DEVICE_FILE_SYSTEM<<16) | (58, METHOD_NEITHER | (FILE_READ_DATA<<14)
#Define FSCTL_WRITE_USN_CLOSE_RECORD        (FILE_DEVICE_FILE_SYSTEM<<16) | (59, METHOD_NEITHER | (FILE_READ_DATA<<14)
#Define FSCTL_EXTEND_VOLUME                 (FILE_DEVICE_FILE_SYSTEM<<16) | (60, METHOD_BUFFERED | (FILE_ANY_ACCESS<<14)

PATHNAME_BUFFER Struct
	PathNameLength DD
	Name DW
EndS

FSCTL_QUERY_FAT_BPB_BUFFER Struct
	First0x24BytesOfBootSector DB 024h DUP (?)
EndS

NTFS_VOLUME_DATA_BUFFER Struct
	VolumeSerialNumber LARGE_INTEGER <>
	NumberSectors LARGE_INTEGER <>
	TotalClusters LARGE_INTEGER <>
	FreeClusters LARGE_INTEGER <>
	TotalReserved LARGE_INTEGER <>
	BytesPerSector DD
	BytesPerCluster DD
	BytesPerFileRecordSegment DD
	ClustersPerFileRecordSegment DD
	MftValidDataLength LARGE_INTEGER <>
	MftStartLcn LARGE_INTEGER <>
	Mft2StartLcn LARGE_INTEGER <>
	MftZoneStart LARGE_INTEGER <>
	MftZoneEnd LARGE_INTEGER <>
EndS

STARTING_LCN_INPUT_BUFFER Struct
	StartingLcn LARGE_INTEGER <>
EndS

VOLUME_BITMAP_BUFFER Struct
	StartingLcn LARGE_INTEGER <>
	BitmapSize LARGE_INTEGER <>
	Buffer DB
EndS

STARTING_VCN_INPUT_BUFFER Struct
	StartingVcn LARGE_INTEGER <>
EndS


_Extents Struct
	NextVcn LARGE_INTEGER <>
	Lcn LARGE_INTEGER <>
EndS

RETRIEVAL_POINTERS_BUFFER Struct
	ExtentCount DD
	StartingVcn LARGE_INTEGER <>
	Extents _Extents <>
EndS

NTFS_FILE_RECORD_INPUT_BUFFER Struct
	FileReferenceNumber LARGE_INTEGER <>
EndS

NTFS_FILE_RECORD_OUTPUT_BUFFER Struct
	FileReferenceNumber LARGE_INTEGER <>
	FileRecordLength DD
	FileRecordBuffer DB
EndS

MOVE_FILE_DATA Struct
	FileHandle DD
	StartingVcn LARGE_INTEGER <>
	StartingLcn LARGE_INTEGER <>
	ClusterCount DD
EndS

HFS_INFORMATION_BUFFER Struct
	FinderInfo DB 32 Dup ?
EndS

MFT_ENUM_DATA Struct
	StartFileReferenceNumber DQ
	LowUsn DQ
	HighUsn DQ
EndS

FIND_BY_SID_DATA Struct
	Restart DD
	Sid SID <>
EndS

CREATE_USN_JOURNAL_DATA Struct
	MaximumSize DQ
	AllocationDelta DQ
EndS

READ_USN_JOURNAL_DATA Struct
	StartUsn DQ
	ReasonMask DD
	ReturnOnlyOnClose DD
	Timeout DQ
	BytesToWaitFor DQ
	UsnJournalID DQ
EndS

USN_RECORD Struct
	RecordLength DD
	MajorVersion DW
	MinorVersion DW
	FileReferenceNumber DQ
	ParentFileReferenceNumber DQ
	Usn DQ
	TimeStamp LARGE_INTEGER <>
	Reason DD
	SourceInfo DD
	SecurityId DD
	FileAttributes DD
	FileNameLength DQ
	FileNameOffset DW
	FileName DW
EndS

#Define USN_PAGE_SIZE                       (01000H)

#Define USN_REASON_DATA_OVERWRITE           (000000001H)
#Define USN_REASON_DATA_EXTEND              (000000002H)
#Define USN_REASON_DATA_TRUNCATION          (000000004H)
#Define USN_REASON_NAMED_DATA_OVERWRITE     (000000010H)
#Define USN_REASON_NAMED_DATA_EXTEND        (000000020H)
#Define USN_REASON_NAMED_DATA_TRUNCATION    (000000040H)
#Define USN_REASON_FILE_CREATE              (000000100H)
#Define USN_REASON_FILE_DELETE              (000000200H)
#Define USN_REASON_PROPERTY_CHANGE          (000000400H)
#Define USN_REASON_SECURITY_CHANGE          (000000800H)
#Define USN_REASON_RENAME_OLD_NAME          (000001000H)
#Define USN_REASON_RENAME_NEW_NAME          (000002000H)
#Define USN_REASON_INDEXABLE_CHANGE         (000004000H)
#Define USN_REASON_BASIC_INFO_CHANGE        (000008000H)
#Define USN_REASON_HARD_LINK_CHANGE         (000010000H)
#Define USN_REASON_COMPRESSION_CHANGE       (000020000H)
#Define USN_REASON_ENCRYPTION_CHANGE        (000040000H)
#Define USN_REASON_OBJECT_ID_CHANGE         (000080000H)
#Define USN_REASON_REPARSE_POINT_CHANGE     (000100000H)
#Define USN_REASON_MOUNT_TABLE_CHANGE       (000200000H)

#Define USN_REASON_CLOSE                    (080000000H)

BULK_SECURITY_TEST_DATA STRUCT
	DesiredAccess DD
	SecurityIds DD
ENDS

#Define VOLUME_IS_DIRTY                     (000000001H)
#Define VOLUME_UPGRADE_SCHEDULED            (000000002H)

_MftWritesUserLevel Struct
	Write DW
	Create DW
	SetInfo DW
	Flush DW
EndS

_BitmapWritesUserLevel Struct
	Write DW
	Create DW
	SetInfo DW
EndS

_Allocate Struct
	Calls DD
	Clusters DD
	Hints DD
	RunsReturned DD
	HintsHonored DD
	HintsClusters DD
	Cache DD
	CacheClusters DD
	CacheMiss DD
	CacheMissClusters DD
EndS

NTFS_STATISTICS Struct
	LogFileFullExceptions DD
	OtherExceptions DD
	MftReads DD
	MftReadBytes DD
	MftWrites DD
	MftWriteBytes DD
	MftWritesUserLevel _MftWritesUserLevel <>
	MftWritesFlushForLogFileFull DW
	MftWritesLazyWriter DW
	MftWritesUserRequest DW
	Mft2Writes DD
	Mft2WriteBytes DD
	Mft2WritesUserLevel _MftWritesUserLevel <>
	Mft2WritesFlushForLogFileFull DW
	Mft2WritesLazyWriter DW
	Mft2WritesUserRequest DW
	RootIndexReads DD
	RootIndexReadBytes DD
	RootIndexWrites DD
	RootIndexWriteBytes DD
	BitmapReads DD
	BitmapReadBytes DD
	BitmapWrites DD
	BitmapWriteBytes DD
	BitmapWritesFlushForLogFileFull DW
	BitmapWritesLazyWriter DW
	BitmapWritesUserRequest DW
	BitmapWritesUserLevel _BitmapWritesUserLevel <>
	MftBitmapReads DD
	MftBitmapReadBytes DD
	MftBitmapWrites DD
	MftBitmapWriteBytes DD
	MftBitmapWritesFlushForLogFileFull DW
	MftBitmapWritesLazyWriter DW
	MftBitmapWritesUserRequest DW
	MftBitmapWritesUserLevel _MftWritesUserLevel <>
	UserIndexReads DD
	UserIndexReadBytes DD
	UserIndexWrites DD
	UserIndexWriteBytes DD
	LogFileReads DD
	LogFileReadBytes DD
	LogFileWrites DD
	LogFileWriteBytes DD
	Allocate _Allocate <>
EndS

FAT_STATISTICS Struct
	CreateHits DD
	SuccessfulCreates DD
	FailedCreates DD
	NonCachedReads DD
	NonCachedReadBytes DD
	NonCachedWrites DD
	NonCachedWriteBytes DD
	NonCachedDiskReads DD
	NonCachedDiskWrites DD
EndS

FILESYSTEM_STATISTICS Struct
	FileSystemType DW
	Version DW
	SizeOfCompleteStructure DD
	UserFileReads DD
	UserFileReadBytes DD
	UserDiskReads DD
	UserFileWrites DD
	UserFileWriteBytes DD
	UserDiskWrites DD
	MetaDataReads DD
	MetaDataReadBytes DD
	MetaDataDiskReads DD
	MetaDataWrites DD
	MetaDataWriteBytes DD
	MetaDataDiskWrites DD
EndS

#Define FILESYSTEM_STATISTICS_TYPE_NTFS     1
#Define FILESYSTEM_STATISTICS_TYPE_FAT      2


_ExtendedInfo4union Struct
	BirthVolumeId DB 16 Dup ?
	BirthObjectId DB 16 Dup ?
	DomainId DB 16 Dup ?
EndS

FILE_OBJECTID_BUFFER Struct
	ObjectId DB 16 Dup ?
	 Union
        ExtendedInfostruct _ExtendedInfo4union <>
		ExtendedInfo DB 48 DUP (?)
	 EndUnion
EndS

FILE_ZERO_DATA_INFORMATION Struct
	FileOffset LARGE_INTEGER <>
	BeyondFinalZero LARGE_INTEGER <>
EndS

FILE_ALLOCATED_RANGE_BUFFER Struct
    LARGE_INTEGER FileOffset DQ
    LARGE_INTEGER Length DQ
EndS

ENCRYPTION_BUFFER Struct
	EncryptionOperation DD
	Private DB
EndS

#Define FILE_SET_ENCRYPTION                 000000001H
#Define FILE_CLEAR_ENCRYPTION               000000002H
#Define STREAM_SET_ENCRYPTION               000000003H
#Define STREAM_CLEAR_ENCRYPTION             000000004H

#Define MAXIMUM_ENCRYPTION_VALUE            000000004H

#Define INFO_NO_ENCRYPTED_STREAMS           01H

#Define ENCRYPTION_FORMAT_DEFAULT           (001H)

#Define COMPRESSION_FORMAT_SPARSE           (04000H)

REQUEST_RAW_ENCRYPTED_DATA Struct
	FileOffset DQ
	Length DD
EndS

ENCRYPTED_DATA_INFO Struct
	StartingFileOffset DQ
	OutputBufferOffset DD
	BytesWithinFileSize DD
	BytesWithinValidDataLength DD
	CompressionFormat DW
	DataUnitShift DB
	ChunkShift DB
	ClusterShift DB
	EncryptionFormat DB
	NumberOfDataBlocks DW
	DataBlockSize DD
EndS

#ENDIF ;WINIOCTL_INC
