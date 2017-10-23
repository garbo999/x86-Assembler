#ifndef HIGHLEVELMONITORCONFIGURATIONAPI_H
#define HIGHLEVELMONITORCONFIGURATIONAPI_H

#IFNDEF WINDOWS_H
	#include "windows.h"
#ENDIF

#IFNDEF PHYSICALMONITORENUMERATIONAPI_H
	#include "PhysicalMonitorEnumerationAPI.h"
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile dxva2.dll
#ENDIF

/******************************************************************************
    Flags
******************************************************************************/
#define MC_CAPS_NONE                                            0x00000000
#define MC_CAPS_MONITOR_TECHNOLOGY_TYPE                         0x00000001
#define MC_CAPS_BRIGHTNESS                                      0x00000002  
#define MC_CAPS_CONTRAST                                        0x00000004
#define MC_CAPS_COLOR_TEMPERATURE                               0x00000008
#define MC_CAPS_RED_GREEN_BLUE_GAIN                             0x00000010
#define MC_CAPS_RED_GREEN_BLUE_DRIVE                            0x00000020
#define MC_CAPS_DEGAUSS                                         0x00000040
#define MC_CAPS_DISPLAY_AREA_POSITION                           0x00000080
#define MC_CAPS_DISPLAY_AREA_SIZE                               0x00000100
#define MC_CAPS_RESTORE_FACTORY_DEFAULTS                        0x00000400
#define MC_CAPS_RESTORE_FACTORY_COLOR_DEFAULTS                  0x00000800
#define MC_RESTORE_FACTORY_DEFAULTS_ENABLES_MONITOR_SETTINGS    0x00001000          

#define MC_SUPPORTED_COLOR_TEMPERATURE_NONE                     0x00000000
#define MC_SUPPORTED_COLOR_TEMPERATURE_4000K                    0x00000001
#define MC_SUPPORTED_COLOR_TEMPERATURE_5000K                    0x00000002
#define MC_SUPPORTED_COLOR_TEMPERATURE_6500K                    0x00000004
#define MC_SUPPORTED_COLOR_TEMPERATURE_7500K                    0x00000008
#define MC_SUPPORTED_COLOR_TEMPERATURE_8200K                    0x00000010
#define MC_SUPPORTED_COLOR_TEMPERATURE_9300K                    0x00000020
#define MC_SUPPORTED_COLOR_TEMPERATURE_10000K                   0x00000040
#define MC_SUPPORTED_COLOR_TEMPERATURE_11500K                   0x00000080

/******************************************************************************
    Enumerations
******************************************************************************/

MC_SHADOW_MASK_CATHODE_RAY_TUBE = 0
MC_APERTURE_GRILL_CATHODE_RAY_TUBE = 1
MC_THIN_FILM_TRANSISTOR = 2
MC_LIQUID_CRYSTAL_ON_SILICON = 3
MC_PLASMA = 4
MC_ORGANIC_LIGHT_EMITTING_DIODE = 5
MC_ELECTROLUMINESCENT = 6
MC_MICROELECTROMECHANICAL = 7
MC_FIELD_EMISSION_DEVICE = 8

MC_RED_DRIVE = 0
MC_GREEN_DRIVE = 1
MC_BLUE_DRIVE = 2

MC_RED_GAIN = 0
MC_GREEN_GAIN = 1
MC_BLUE_GAIN = 2

MC_HORIZONTAL_POSITION = 0
MC_VERTICAL_POSITION = 1

MC_WIDTH = 0
MC_HEIGHT = 1

MC_COLOR_TEMPERATURE_UNKNOWN = 0
MC_COLOR_TEMPERATURE_4000K = 1
MC_COLOR_TEMPERATURE_5000K = 2
MC_COLOR_TEMPERATURE_6500K = 3
MC_COLOR_TEMPERATURE_7500K = 4
MC_COLOR_TEMPERATURE_8200K = 5
MC_COLOR_TEMPERATURE_9300K = 6
MC_COLOR_TEMPERATURE_10000K = 7
MC_COLOR_TEMPERATURE_11500K = 8

#endif // HIGHLEVELMONITORCONFIGURATIONAPI_H

