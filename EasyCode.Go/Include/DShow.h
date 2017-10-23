//------------------------------------------------------------------------------
// File: DShow.h
//
// Desc: DirectShow top-level include file
//
// Copyright (c) 2000-2001, Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------

#ifndef DSHOW_H
#define DSHOW_H

///////////////////////////////////////////////////////////////////////////
// Include standard Windows files
///////////////////////////////////////////////////////////////////////////
#IFNDEF WINDOWS_H
	#include "windows.h"
#ENDIF
#IFNDEF OLECTL_H
	#include "olectl.h"
#ENDIF
#IFNDEF DDRAW_H
	#include "ddraw.h"
#ENDIF
#IFNDEF MMSYSTEM_H
	#include "mmsystem.h"
#ENDIF

///////////////////////////////////////////////////////////////////////////
// Include DirectShow include files
///////////////////////////////////////////////////////////////////////////
#IFNDEF STRMIF_H
	#include "strmif.h"     // Generated IDL header file for streams interfaces
#ENDIF
#IFNDEF AMVIDEO_H
	#include "amvideo.h"    // ActiveMovie video interfaces and definitions
#ENDIF

#ifdef DSHOW_USE_AMAUDIO
	#IFNDEF AMAUDIO_H
		#include "amaudio.h"    // ActiveMovie audio interfaces and definitions
	#ENDIF
#endif

#IFNDEF CONTROL_H
	#include "control.h"    // generated from control.odl
#ENDIF
#IFNDEF EVCODE_H
	#include "evcode.h"     // event code definitions
#ENDIF
#IFNDEF UUIDS_H
	#include "uuids.h"      // declaration of type GUIDs and well-known clsids
#ENDIF
#IFNDEF ERRORS_H
	#include "errors.h"     // HRESULT status and error definitions
#ENDIF
#IFNDEF EDEVDEFS_H
	#include "edevdefs.h"   // External device control interface defines
#ENDIF
#IFNDEF AUDEVCOD_H
	#include "audevcod.h"   // audio filter device error event codes
#ENDIF
#IFNDEF DVDEVCOD_H
	#include "dvdevcod.h"   // DVD error event codes
#ENDIF

///////////////////////////////////////////////////////////////////////////
// Define OLE Automation constants
///////////////////////////////////////////////////////////////////////////
#ifndef OATRUE
	#define OATRUE -1
#endif // OATRUE
#ifndef OAFALSE
	#define OAFALSE 0
#endif // OAFALSE

#endif // DSHOW_H

