//------------------------------------------------------------------------------
// File: AMVideo.h
//
// Desc: Video related definitions and interfaces for ActiveMovie.
//
// Copyright (c) 1992 - 2001, Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------

#ifndef AMVIDEO_H
#define AMVIDEO_H

#IFNDEF DDRAW_H
	#include "ddraw.h"
#ENDIF

// This is an interface on the video renderer that provides information about
// DirectDraw with respect to its use by the renderer. For example it allows
// an application to get details of the surface and any hardware capabilities
// that are available. It also allows someone to adjust the surfaces that the
// renderer should use and furthermore even set the DirectDraw instance. We
// allow someone to set the DirectDraw instance because DirectDraw can only
// be opened once per process so it helps resolve conflicts. There is some
// duplication in this interface as the hardware/emulated/FOURCCs available
// can all be found through the IDirectDraw interface, this interface allows
// simple access to that information without calling the DirectDraw provider
// itself. The AMDDS prefix is ActiveMovie DirectDraw Switches abbreviated.

#define AMDDS_NONE 0x00             // No use for DCI/DirectDraw
#define AMDDS_DCIPS 0x01            // Use DCI primary surface
#define AMDDS_PS 0x02               // Use DirectDraw primary
#define AMDDS_RGBOVR 0x04           // RGB overlay surfaces
#define AMDDS_YUVOVR 0x08           // YUV overlay surfaces
#define AMDDS_RGBOFF 0x10           // RGB offscreen surfaces
#define AMDDS_YUVOFF 0x20           // YUV offscreen surfaces
#define AMDDS_RGBFLP 0x40           // RGB flipping surfaces
#define AMDDS_YUVFLP 0x80           // YUV flipping surfaces
#define AMDDS_ALL 0xFF              // ALL the previous flags
#define AMDDS_DEFAULT AMDDS_ALL     // Use all available surfaces

#define AMDDS_YUV (AMDDS_YUVOFF | AMDDS_YUVOVR | AMDDS_YUVFLP)
#define AMDDS_RGB (AMDDS_RGBOFF | AMDDS_RGBOVR | AMDDS_RGBFLP)
#define AMDDS_PRIMARY (AMDDS_DCIPS | AMDDS_PS)

IDirectDrawVideo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSwitches PTR
	SetSwitches PTR
	GetCaps PTR
	GetEmulatedCaps PTR
	GetSurfaceDesc PTR
	GetFourCCCodes PTR
	SetDirectDraw PTR
	GetDirectDraw PTR
	GetSurfaceType PTR
	SetDefault PTR
	UseScanLine PTR
	CanUseScanLine PTR
	UseOverlayStretch PTR
	CanUseOverlayStretch PTR
	UseWhenFullScreen PTR
	WillUseFullScreen PTR
ENDS

IQualProp STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_FramesDroppedInRenderer PTR
	get_FramesDrawn PTR
	get_AvgFrameRate PTR
	get_Jitter PTR
	get_AvgSyncOffset PTR
	get_DevSyncOffset PTR
ENDS


// This interface allows an application or plug in distributor to control a
// full screen renderer. The Modex renderer supports this interface. When
// connected a renderer should load the display modes it has available
// The number of modes available can be obtained through CountModes. Then
// information on each individual mode is available by calling GetModeInfo
// and IsModeAvailable. An application may enable and disable any modes
// by calling the SetEnabled flag with OATRUE or OAFALSE (not C/C++ TRUE
// and FALSE values) - the current value may be queried by IsModeEnabled

// A more generic way of setting the modes enabled that is easier to use
// when writing applications is the clip loss factor. This defines the
// amount of video that can be lost when deciding which display mode to
// use. Assuming the decoder cannot compress the video then playing an
// MPEG file (say 352x288) into a 320x200 display will lose about 25% of
// the image. The clip loss factor specifies the upper range permissible.
// To allow typical MPEG video to be played in 320x200 it defaults to 25%

IFullScreenVideo STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CountModes PTR
	GetModeInfo PTR
	GetCurrentMode PTR
	IsModeAvailable PTR
	IsModeEnabled PTR
	SetEnabled PTR
	GetClipFactor PTR
	SetClipFactor PTR
	SetMessageDrain PTR
	GetMessageDrain PTR
	SetMonitor PTR
	GetMonitor PTR
	HideOnDeactivate PTR
	IsHideOnDeactivate PTR
	SetCaption PTR
	GetCaption PTR
	SetDefault PTR
ENDS

// This adds the accelerator table capabilities in fullscreen. This is being
// added between the original runtime release and the full SDK release. We
// cannot just add the method to IFullScreenVideo as we don't want to force
// applications to have to ship the ActiveMovie support DLLs - this is very
// important to applications that plan on being downloaded over the Internet

IFullScreenVideoEx STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CountModes PTR
	GetModeInfo PTR
	GetCurrentMode PTR
	IsModeAvailable PTR
	IsModeEnabled PTR
	SetEnabled PTR
	GetClipFactor PTR
	SetClipFactor PTR
	SetMessageDrain PTR
	GetMessageDrain PTR
	SetMonitor PTR
	GetMonitor PTR
	HideOnDeactivate PTR
	IsHideOnDeactivate PTR
	SetCaption PTR
	GetCaption PTR
	SetDefault PTR
	SetAcceleratorTable PTR
	GetAcceleratorTable PTR
	KeepPixelAspectRatio PTR
	IsKeepPixelAspectRatio PTR
ENDS

// The SDK base classes contain a base video mixer class. Video mixing in a
// software environment is tricky because we typically have multiple streams
// each sending data at unpredictable times. To work with this we defined a
// pin that is the lead pin, when data arrives on this pin we do a mix. As
// an alternative we may not want to have a lead pin but output samples at
// predefined spaces, like one every 1/15 of a second, this interfaces also
// supports that mode of operations (there is a working video mixer sample)

IBaseVideoMixer STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetLeadPin PTR
	GetLeadPin PTR
	GetInputPinCount PTR
	IsUsingClock PTR
	SetUsingClock PTR
	GetClockPeriod PTR
	SetClockPeriod PTR
ENDS

#define iPALETTE_COLORS 256     // Maximum colours in palette
#define iEGA_COLORS 16          // Number colours in EGA palette
#define iMASK_COLORS 3          // Maximum three components
#define iTRUECOLOR 16           // Minimum true colour device
#define iRED 0                  // Index position for RED mask
#define iGREEN 1                // Index position for GREEN mask
#define iBLUE 2                 // Index position for BLUE mask
#define iPALETTE 8              // Maximum colour depth using a palette
#define iMAXBITS 8              // Maximum bits per colour component

// Used for true colour images that also have a palette

TRUECOLORINFO STRUCT
	dwBitMasks DD iMASK_COLORS DUP
	bmiColors RGBQUAD iPALETTE_COLORS DUP
ENDS

// The BITMAPINFOHEADER contains all the details about the video stream such
// as the actual image dimensions and their pixel depth. A source filter may
// also request that the sink take only a section of the video by providing a
// clipping rectangle in rcSource. In the worst case where the sink filter
// forgets to check this on connection it will simply render the whole thing
// which isn't a disaster. Ideally a sink filter will check the rcSource and
// if it doesn't support image extraction and the rectangle is not empty then
// it will reject the connection. A filter should use SetRectEmpty to reset a
// rectangle to all zeroes (and IsRectEmpty to later check the rectangle).
// The rcTarget specifies the destination rectangle for the video, for most
// source filters they will set this to all zeroes, a downstream filter may
// request that the video be placed in a particular area of the buffers it
// supplies in which case it will call QueryAccept with a non empty target

VIDEOINFOHEADER STRUCT
	rcSource RECT
	rcTarget RECT
	dwBitRate DD
	dwBitErrorRate DD
	AvgTimePerFrame LONGLONG
	bmiHeader BITMAPINFOHEADER
ENDS

// All the image based filters use this to communicate their media types. It's
// centred principally around the BITMAPINFO. This structure always contains a
// BITMAPINFOHEADER followed by a number of other fields depending on what the
// BITMAPINFOHEADER contains. If it contains details of a palettised format it
// will be followed by one or more RGBQUADs defining the palette. If it holds
// details of a true colour format then it may be followed by a set of three
// DWORD bit masks that specify where the RGB data can be found in the image
// (For more information regarding BITMAPINFOs see the Win32 documentation)

// The rcSource and rcTarget fields are not for use by filters supplying the
// data. The destination (target) rectangle should be set to all zeroes. The
// source may also be zero filled or set with the dimensions of the video. So
// if the video is 352x288 pixels then set it to (0,0,352,288). These fields
// are mainly used by downstream filters that want to ask the source filter
// to place the image in a different position in an output buffer. So when
// using for example the primary surface the video renderer may ask a filter
// to place the video images in a destination position of (100,100,452,388)
// on the display since that's where the window is positioned on the display

// !!! WARNING !!!
// DO NOT use this structure unless you are sure that the BITMAPINFOHEADER
// has a normal biSize == sizeof(BITMAPINFOHEADER) !
// !!! WARNING !!!

VIDEOINFO STRUCT
	rcSource RECT
	rcTarget RECT
	dwBitRate DD
	dwBitErrorRate DD
	AvgTimePerFrame LONGLONG
	bmiHeader BITMAPINFOHEADER
	UNION
		bmiColors RGBQUAD iPALETTE_COLORS DUP
		dwBitMasks DD iMASK_COLORS DUP
		TrueColorInfo TRUECOLORINFO
	ENDUNION
ENDS

// MPEG variant - includes a DWORD length followed by the
// video sequence header after the video header.
//
// The sequence header includes the sequence header start code and the
// quantization matrices associated with the first sequence header in the
// stream so is a maximum of 140 bytes long.

MPEG1VIDEOINFO STRUCT
	hdr VIDEOINFOHEADER
	dwStartTimeCode DD
	cbSequenceHeader DD
	bSequenceHeader DB
ENDS

#define MAX_SIZE_MPEG1_SEQUENCE_INFO 140

// Analog video variant - Use this when the format is FORMAT_AnalogVideo
//
// rcSource defines the portion of the active video signal to use
// rcTarget defines the destination rectangle
//    both of the above are relative to the dwActiveWidth and dwActiveHeight fields
// dwActiveWidth is currently set to 720 for all formats (but could change for HDTV)
// dwActiveHeight is 483 for NTSC and 575 for PAL/SECAM  (but could change for HDTV)

ANALOGVIDEOINFO STRUCT
	rcSource RECT
	rcTarget RECT
	dwActiveWidth DD
	dwActiveHeight DD
	AvgTimePerFrame LONGLONG
ENDS

//
// AM_KSPROPSETID_FrameStep property set definitions
//
// AM_PROPERTY_FRAMESTEP
	AM_PROPERTY_FRAMESTEP_STEP   = 0x01
	AM_PROPERTY_FRAMESTEP_CANCEL = 0x02
	AM_PROPERTY_FRAMESTEP_CANSTEP = 0x03
	AM_PROPERTY_FRAMESTEP_CANSTEPMULTIPLE = 0x04

AM_FRAMESTEP_STEP STRUCT
	dwFramesToStep DD
ENDS

#endif // AMVIDEO_H


