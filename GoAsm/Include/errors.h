//------------------------------------------------------------------------------
// File: Errors.h
//
// Desc:  ActiveMovie error defines.
//
// Copyright (c) 1992 - 2001, Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------


#ifndef ERRORS_H
#define ERRORS_H

#IFDEF LINKFILES
	#dynamiclinkfile Quartz.dll
#ENDIF

// codes 0-01ff are reserved for OLE
#define VFW_FIRST_CODE   0x200
#define MAX_ERROR_TEXT_LEN 160

#IFNDEF VFWMSGS_H
	#include "VFWMSGS.H"                    // includes all message definitions
#ENDIF

#ifdef UNICODE
	#define AMGetErrorText  AMGetErrorTextW
#else
	#define AMGetErrorText  AMGetErrorTextA
#endif

#endif // ERRORS_H

