/*****************************************************************************\
*                                                                             *
* powrprof.h - - Interface for powrprof.dll, the power policy applicator      *
*                                                                             *
* Version 1.0                                                                 *
*                                                                             *
* Copyright (c) Microsoft Corporation. All rights reserved.                   *
*                                                                             *
\*****************************************************************************/

// Registry storage structures for the GLOBAL_POWER_POLICY data. There are two
// structures, GLOBAL_MACHINE_POWER_POLICY and GLOBAL_USER_POWER_POLICY. the
// GLOBAL_MACHINE_POWER_POLICY stores per machine data for which there is no UI.
// GLOBAL_USER_POWER_POLICY stores the per user data.

#IFNDEF POWRPROF_H
#DEFINE POWRPROF_H

#IFDEF LINKFILES
	#dynamiclinkfile PowrProf.dll
#ENDIF

// SYSTEM_POWER_STATE enum
PowerSystemUnspecified   = 0
PowerSystemWorking       = 1
PowerSystemSleeping1     = 2
PowerSystemSleeping2     = 3
PowerSystemSleeping3     = 4
PowerSystemHibernate     = 5
PowerSystemShutdown      = 6
PowerSystemMaximum       = 7 

// POWER_ACTION enum
PowerActionNone          = 0
PowerActionReserved      = 1
PowerActionSleep         = 2
PowerActionHibernate     = 3
PowerActionShutdown      = 4
PowerActionShutdownReset = 5
PowerActionShutdownOff   = 6
PowerActionWarmEject     = 7


GLOBAL_MACHINE_POWER_POLICY STRUCT
	Revision LONG
	LidOpenWakeAc ENUM // SYSTEM_POWER_STATE
	LidOpenWakeDc ENUM // SYSTEM_POWER_STATE
	BroadcastCapacityResolution LONG
ENDS

POWER_ACTION_POLICY STRUCT
	Action ENUM //POWER_ACTION
	Flags LONG
	EventCode LONG
ENDS

SYSTEM_POWER_LEVEL STRUCT
	Enable BOOLEAN
	Spare CHAR 3 DUP
	BatteryLevel LONG
	PowerPolicy POWER_ACTION_POLICY
	MinSystemState ENUM // SYSTEM_POWER_STATE
ENDS

GLOBAL_USER_POWER_POLICY STRUCT
	Revision LONG
	PowerButtonAc POWER_ACTION_POLICY
	PowerButtonDc POWER_ACTION_POLICY
	SleepButtonAc POWER_ACTION_POLICY
	SleepButtonDc POWER_ACTION_POLICY
	LidCloseAc POWER_ACTION_POLICY
	LidCloseDc POWER_ACTION_POLICY
	DischargePolicy SYSTEM_POWER_LEVEL NUM_DISCHARGE_POLICIES DUP
	GlobalFlags LONG
ENDS

// Structure to manage global power policies at the user level. This structure
// contains data which is common across all power policy profiles.

GLOBAL_POWER_POLICY STRUCT
	user GLOBAL_USER_POWER_POLICY
	mach GLOBAL_MACHINE_POWER_POLICY
ENDS

// Registry storage structures for the POWER_POLICY data. There are three
// structures, MACHINE_POWER_POLICY, MACHINE_PROCESSOR_POWER_POLICY and
// USER_POWER_POLICY. the MACHINE_POWER_POLICY stores per machine data for 
// which there is no UI.  USER_POWER_POLICY stores the per user data.

MACHINE_POWER_POLICY STRUCT
	Revision LONG // 1

    // meaning of power action "sleep"
	MinSleepAc ENUM // SYSTEM_POWER_STATE
	MinSleepDc ENUM // SYSTEM_POWER_STATE
	ReducedLatencySleepAc ENUM // SYSTEM_POWER_STATE
	ReducedLatencySleepDc ENUM // SYSTEM_POWER_STATE

    // parameters for dozing
	DozeTimeoutAc LONG
	DozeTimeoutDc LONG
	DozeS4TimeoutAc LONG
	DozeS4TimeoutDc LONG

    // processor policies
	MinThrottleAc CHAR
	MinThrottleDc CHAR
	pad1 CHAR 2 DUP
	OverThrottledAc POWER_ACTION_POLICY
	OverThrottledDc POWER_ACTION_POLICY
ENDS

//
// deprecated
//

PROCESSOR_POWER_POLICY_INFO STRUCT
	TimeCheck LONG
	DemoteLimit LONG
	PromoteLimit LONG
	DemotePercent CHAR
	PromotePercent CHAR
	Spare CHAR 2 DUP
	AllowDemotion LONG
	AllowPromotion LONG
	Reserved LONG
ENDS

PROCESSOR_POWER_POLICY STRUCT
	Revision DD
	DynamicThrottle DB
	Spare DB 3 DUP
	DisableCStates DD
	Reserved DD
	PolicyCount DD
	Policy PROCESSOR_POWER_POLICY_INFO 3 DUP
ENDS

MACHINE_PROCESSOR_POWER_POLICY STRUCT
	Revision LONG // 1
	ProcessorPolicyAc PROCESSOR_POWER_POLICY
	ProcessorPolicyDc PROCESSOR_POWER_POLICY
ENDS

USER_POWER_POLICY STRUCT
	Revision LONG // 1

    // "system idle" detection
	IdleAc POWER_ACTION_POLICY
	IdleDc POWER_ACTION_POLICY
	IdleTimeoutAc LONG
	IdleTimeoutDc LONG
	IdleSensitivityAc CHAR
	IdleSensitivityDc CHAR
    
    // Throttling Policy
	ThrottlePolicyAc CHAR
	ThrottlePolicyDc CHAR

    // meaning of power action "sleep"
	MaxSleepAc ENUM // SYSTEM_POWER_STATE
	MaxSleepDc ENUM // SYSTEM_POWER_STATE

    // For future use
	Reserved LONG 2 DUP

    // video policies
	VideoTimeoutAc LONG
	VideoTimeoutDc LONG

    // hard disk policies
	SpindownTimeoutAc LONG
	SpindownTimeoutDc LONG

    // processor policies
	OptimizeForPowerAc BOOLEAN
	OptimizeForPowerDc BOOLEAN
	FanThrottleToleranceAc CHAR
	FanThrottleToleranceDc CHAR
	ForcedThrottleAc CHAR
	ForcedThrottleDc CHAR
ENDS

// Structure to manage power policies at the user level. This structure
// contains data which is unique across power policy profiles.

POWER_POLICY STRUCT
	user USER_POWER_POLICY
	mach MACHINE_POWER_POLICY
ENDS

// Constants for GlobalFlags

#define EnableSysTrayBatteryMeter   0x01
#define EnableMultiBatteryDisplay   0x02
#define EnablePasswordLogon         0x04
#define EnableWakeOnRing            0x08
#define EnableVideoDimDisplay       0x10

//
// Power setting attribute flags
//

#define POWER_ATTRIBUTE_HIDE        0x00000001

// This constant is passed as a uiID to WritePwrScheme.
#define NEWSCHEME -1

// ENUM POWER_DATA_ACCESSOR

ACCESS_AC_POWER_SETTING_INDEX = 0
ACCESS_DC_POWER_SETTING_INDEX = 1
ACCESS_FRIENDLY_NAME = 2
ACCESS_DESCRIPTION = 3
ACCESS_POSSIBLE_POWER_SETTING = 4
ACCESS_POSSIBLE_POWER_SETTING_FRIENDLY_NAME = 5
ACCESS_POSSIBLE_POWER_SETTING_DESCRIPTION = 6
ACCESS_DEFAULT_AC_POWER_SETTING = 7
ACCESS_DEFAULT_DC_POWER_SETTING = 8
ACCESS_POSSIBLE_VALUE_MIN = 9
ACCESS_POSSIBLE_VALUE_MAX = 10
ACCESS_POSSIBLE_VALUE_INCREMENT = 11
ACCESS_POSSIBLE_VALUE_UNITS = 12
ACCESS_ICON_RESOURCE = 13
ACCESS_DEFAULT_SECURITY_DESCRIPTOR = 14
ACCESS_ATTRIBUTES = 15
ACCESS_SCHEME = 16
ACCESS_SUBGROUP = 17
ACCESS_INDIVIDUAL_SETTING = 18
ACCESS_ACTIVE_SCHEME = 19
ACCESS_CREATE_SCHEME = 20
ACCESS_AC_POWER_SETTING_MAX = 21
ACCESS_DC_POWER_SETTING_MAX = 22
ACCESS_AC_POWER_SETTING_MIN = 23
ACCESS_DC_POWER_SETTING_MIN = 24

#define DEVICEPOWER_HARDWAREID 0x80000000
#define DEVICEPOWER_AND_OPERATION 0x40000000
#define DEVICEPOWER_FILTER_DEVICES_PRESENT 0x20000000
#define DEVICEPOWER_FILTER_HARDWARE 0x10000000
#define DEVICEPOWER_FILTER_WAKEENABLED 0x08000000
#define DEVICEPOWER_FILTER_WAKEPROGRAMMABLE 0x04000000
#define DEVICEPOWER_FILTER_ON_NAME 0x02000000
#define DEVICEPOWER_SET_WAKEENABLED 0x00000001
#define DEVICEPOWER_CLEAR_WAKEENABLED 0x00000002

#define PDCAP_S0_SUPPORTED              0x00010000
#define PDCAP_S1_SUPPORTED              0x00020000
#define PDCAP_S2_SUPPORTED              0x00040000
#define PDCAP_S3_SUPPORTED              0x00080000
#define PDCAP_WAKE_FROM_S0_SUPPORTED    0x00100000
#define PDCAP_WAKE_FROM_S1_SUPPORTED    0x00200000
#define PDCAP_WAKE_FROM_S2_SUPPORTED    0x00400000
#define PDCAP_WAKE_FROM_S3_SUPPORTED    0x00800000
#define PDCAP_S4_SUPPORTED              0x01000000
#define PDCAP_S5_SUPPORTED              0x02000000

#endif

