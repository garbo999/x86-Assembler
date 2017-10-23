#ifndef PHYSICALMONITORENUMERATIONAPI_H
#define PHYSICALMONITORENUMERATIONAPI_H

;#include "d3d9.h"

/******************************************************************************
    Physical Monitor Constants
******************************************************************************/

// A physical monitor description is always an array of 128 characters.  Some
// of the characters may not be used.
#define PHYSICAL_MONITOR_DESCRIPTION_SIZE                   128

/******************************************************************************
    Physical Monitor Structures 
******************************************************************************/
PHYSICAL_MONITOR STRUCT
	hPhysicalMonitor HANDLE
	szPhysicalMonitorDescription DW PHYSICAL_MONITOR_DESCRIPTION_SIZE DUP
ENDS

#endif // PhysicalMonitorEnumerationAPI_h

