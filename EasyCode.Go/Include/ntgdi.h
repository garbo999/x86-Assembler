/******************************Module*Header*******************************\
* Module Name: ntgdi.h
*
* Structures defining kernel-mode entry points for GDI.
*
* Copyright (c) 1994-1999 Microsoft Corporation
\**************************************************************************/

#IFNDEF NTGDI_H
#DEFINE NTGDI_H

// flags returned from GetUFI and passed to GetUFIBits
#define FL_UFI_PRIVATEFONT      1
#define FL_UFI_DESIGNVECTOR_PFF 2
#define FL_UFI_MEMORYFONT       4

#define ICM_SET_MODE             1
#define ICM_SET_CALIBRATE_MODE   2
#define ICM_SET_COLOR_MODE       3
#define ICM_CHECK_COLOR_MODE     4

LOGCOLORSPACEEXW STRUCT
	lcsColorSpace LOGCOLORSPACEW
	dwFlags DD
ENDS

#define LCSEX_ANSICREATED    0x0001 // Created by CreateColorSpaceA()
#define LCSEX_TEMPPROFILE    0x0002 // Color profile is temporary file

IcmQueryBrush = 0
IcmSetBrush = 1

#define GS_NUM_OBJS_ALL    0
#define GS_HANDOBJ_CURRENT 1
#define GS_HANDOBJ_MAX     2
#define GS_HANDOBJ_ALLOC   3
#define GS_LOOKASIDE_INFO  4

#define TYPE_ENUMFONTS          1
#define TYPE_ENUMFONTFAMILIES   2
#define TYPE_ENUMFONTFAMILIESEX 3

#ENDIF