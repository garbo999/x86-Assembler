/**************************************************************************
*
* Copyright (c) 2000-2001 Microsoft Corporation
*
* Module Name:
*
*   Gdiplus initialization
*
* Abstract:
*
*   GDI+ Startup and Shutdown APIs
*
**************************************************************************/

#ifndef GDIPLUSINIT_H
#define GDIPLUSINIT_H

// Input structure for GdiplusStartup()

GdiplusStartupInput STRUCT
	GdiplusVersion DD
	DebugEventCallback PTR
	SuppressBackgroundThread BOOL
	SuppressExternalCodecs BOOL
ENDS

// Output structure for GdiplusStartup()

GdiplusStartupOutput STRUCT
	NotificationHook PTR
	NotificationUnhook PTR
ENDS

GdiplusStartupDefault = 0
GdiplusStartupNoSetRound = 1
GdiplusStartupSetPSValue = 2
GdiplusStartupTransparencyMask = 0xFF000000


// GDI+ initialization. Must not be called from DllMain - can cause deadlock.
//
// Must be called before GDI+ API's or constructors are used.
//
// token  - may not be NULL - accepts a token to be passed in the corresponding
//          GdiplusShutdown call.
// input  - may not be NULL
// output - may be NULL only if input->SuppressBackgroundThread is FALSE.

// GDI+ termination. Must be called before GDI+ is unloaded. 
// Must not be called from DllMain - can cause deadlock.
//
// GDI+ API's may not be called after GdiplusShutdown. Pay careful attention
// to GDI+ object destructors.

#endif
