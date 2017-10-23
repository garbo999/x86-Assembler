#ifndef BATCLASS_H
#define BATCLASS_H

/* Battery class driver interfaces */

#IFDEF LINKFILES
		#dynamiclinkfile Kernel32.dll
#ENDIF

GUID_DEVICE_BATTERY <0x72631e54,0x78A4,0x11d0,<0xbc,0xf7,0x00,0xaa,0x00,0xb7,0xb3,0x2a>>

#define IOCTL_BATTERY_QUERY_TAG  (FILE_DEVICE_BATTERY<<16)|(0x10<<2)|METHOD_BUFFERED|(FILE_READ_ACCESS<<14)
#define IOCTL_BATTERY_QUERY_INFORMATION  (FILE_DEVICE_BATTERY<<16)|(0x11<<2)|METHOD_BUFFERED|(FILE_READ_ACCESS<<14)
#define IOCTL_BATTERY_SET_INFORMATION  (FILE_DEVICE_BATTERY<<16)|(0x12<<2)|METHOD_BUFFERED|(FILE_READ_ACCESS<<14)
#define IOCTL_BATTERY_QUERY_STATUS  (FILE_DEVICE_BATTERY<<16)|(0x13<<2)|METHOD_BUFFERED|(FILE_READ_ACCESS<<14)

#define BATTERY_TAG_INVALID  0

#define BATTERY_SYSTEM_BATTERY  0x80000000
#define BATTERY_CAPACITY_RELATIVE  0x40000000
#define BATTERY_IS_SHORT_TERM  0x20000000
#define BATTERY_SET_CHARGE_SUPPORTED  0x00000001
#define BATTERY_SET_DISCHARGE_SUPPORTED  0x00000002
#define BATTERY_SET_RESUME_SUPPORTED  0x00000004
#define BATTERY_UNKNOWN_CAPACITY  0xFFFFFFFF

#define BATTERY_UNKNOWN_TIME 0xFFFFFFFF

#define MAX_BATTERY_STRING_SIZE 128

#define BATTERY_POWER_ON_LINE  0x00000001
#define BATTERY_DISCHARGING  0x00000002
#define BATTERY_CHARGING  0x00000004
#define BATTERY_CRITICAL  0x00000008

#define BATTERY_UNKNOWN_VOLTAGE  0xFFFFFFFF
#define BATTERY_UNKNOWN_RATE  0x80000000

BatteryInformation = 0
BatteryGranularityInformation = 1
BatteryTemperature = 2
BatteryEstimatedTime = 3
BatteryDeviceName = 4
BatteryManufactureDate = 5
BatteryManufactureName = 6
BatteryUniqueID = 7
BatterySerialNumber = 8

BATTERY_QUERY_INFORMATION STRUCT
	BatteryTag DD
	InformationLevel DD
	AtRate DD
ENDS

BATTERY_INFORMATION STRUCT
	Capabilities DD
	Technology DB
	Reserved DB 3 DUP (?)
	Chemistry DB 4 DUP (?)
	DesignedCapacity DD
	FullChargedCapacity DD
	DefaultAlert1 DD
	DefaultAlert2 DD
	CriticalBias DD
	CycleCount DD
ENDS

#ifndef NTPOAPI_H
	BATTERY_REPORTING_SCALE STRUCT
		Granularity DD
		Capacity DD
	ENDS
#endif

BATTERY_MANUFACTURE_DATE STRUCT
	Day DB
	Month DB
	Year DW
ENDS

BatteryCriticalBias = 0
BatteryCharge = 1
BatteryDischarge = 2

BATTERY_SET_INFORMATION STRUCT
	BatteryTag DD
	InformationLevel DD
	Buffer DB
ENDS

BATTERY_WAIT_STATUS STRUCT
	BatteryTag DD
	Timeout DD
	PowerState DD
	LowCapacity DD
	HighCapacity DD
ENDS

BATTERY_STATUS STRUCT
	PowerState DD
	Capacity DD
	Voltage DD
	Rate DD
ENDS

#ifndef WINDOWS_H
	#define BATTERY_CLASS_MAJOR_VERSION  0x0001
	#define BATTERY_CLASS_MINOR_VERSION  0x0000
	
	BATTERY_NOTIFY STRUCT
		PowerState DD
		LowCapacity DD
		HighCapacity DD
	ENDS
	
	BATTERY_MINIPORT_INFO STRUCT
		MajorVersion DW
		MinorVersion  DW
		Context PTR
		QueryTag PTR
		QueryInformation PTR
		SetInformation PTR
		QueryStatus PTR
		SetStatusNotify PTR
		DisableStatusNotify PTR
		Pdo PTR
		DeviceName PTR
	ENDS
#endif

#endif
