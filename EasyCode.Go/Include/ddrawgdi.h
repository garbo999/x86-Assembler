/******************************Module*Header*******************************\
* Module Name: ddrawgdi.h
*
* Structures and defines for the private entry points in GDI to support
* DirectDraw.
*
* Copyright (c) Microsoft Corporation. All rights reserved.
\**************************************************************************/

#ifndef DDRAWGDI_H
#define DDRAWGDI_H

#IFDEF LINKFILES
	#dynamiclinkfile gdi32.dll
#ENDIF

// These are only available in Win2K+

#if WINVER >= NTDDI_WIN2K
	#define DdCreateDirectDrawObject            GdiEntry1
	#define DdQueryDirectDrawObject             GdiEntry2
	#define DdDeleteDirectDrawObject            GdiEntry3
	#define DdCreateSurfaceObject               GdiEntry4
	#define DdDeleteSurfaceObject               GdiEntry5
	#define DdResetVisrgn                       GdiEntry6
	#define DdGetDC                             GdiEntry7
	#define DdReleaseDC                         GdiEntry8
	#define DdCreateDIBSection                  GdiEntry9
	#define DdReenableDirectDrawObject          GdiEntry10
	#define DdAttachSurface                     GdiEntry11
	#define DdUnattachSurface                   GdiEntry12
	#define DdQueryDisplaySettingsUniqueness    GdiEntry13
	#define DdGetDxHandle                       GdiEntry14
	#define DdSetGammaRamp                      GdiEntry15
	#define DdSwapTextureHandles                GdiEntry16
#ENDIF

// No idea where this function is, its not available up to WinVista and is
// not documented any where that I can find even though it is define in the
// Microsoft header file...

#define DdChangeSurfacePointer              GdiEntry17

#endif
