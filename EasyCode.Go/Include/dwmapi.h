/*=========================================================================*\

    Copyright (c) Microsoft Corporation.  All rights reserved.

    File: dwmapi.h

    Module Name: dwmapi

    Description: DWM API declarations

\*=========================================================================*/
#ifndef DWMAPI_H
#define DWMAPI_H

#IFDEF LINKFILES
	#dynamiclinkfile Dwmapi.dll
#ENDIF

// Blur behind data structures
#define DWM_BB_ENABLE                 0x00000001  // fEnable has been specified
#define DWM_BB_BLURREGION             0x00000002  // hRgnBlur has been specified
#define DWM_BB_TRANSITIONONMAXIMIZED  0x00000004  // fTransitionOnMaximized has been specified

DWM_BLURBEHIND STRUCT
	dwFlags DD
	fEnable BOOL
	hRgnBlur HANDLE
	fTransitionOnMaximized BOOL
ENDS

// Window attributes
// enum DWMWINDOWATTRIBUTE
DWMWA_NCRENDERING_ENABLED = 1          // [get] Is non-client rendering enabled/disabled
DWMWA_NCRENDERING_POLICY = 2           // [set] Non-client rendering policy
DWMWA_TRANSITIONS_FORCEDISABLED = 3    // [set] Potentially enable/forcibly disable transitions
DWMWA_ALLOW_NCPAINT = 4                // [set] Allow contents rendered in the non-client area to be visible on the DWM-drawn frame.
DWMWA_CAPTION_BUTTON_BOUNDS = 5        // [get] Bounds of the caption button area in window-relative space.
DWMWA_NONCLIENT_RTL_LAYOUT = 6         // [set] Is non-client content RTL mirrored
DWMWA_FORCE_ICONIC_REPRESENTATION = 7  // [set] Force this window to display iconic thumbnails.
DWMWA_FLIP3D_POLICY = 8                // [set] Designates how Flip3D will treat the window.
DWMWA_EXTENDED_FRAME_BOUNDS = 9        // [get] Gets the extended frame bounds rectangle in screen space
DWMWA_HAS_ICONIC_BITMAP = 10           // [set] Indicates an available bitmap when there is no better thumbnail representation.
DWMWA_DISALLOW_PEEK = 11               // [set] Don't invoke Peek on the window.
DWMWA_EXCLUDED_FROM_PEEK = 12          // [set] LivePreview exclusion information
DWMWA_LAST = 13

// Non-client rendering policy attribute values
// enum DWMNCRENDERINGPOLICY
DWMNCRP_USEWINDOWSTYLE = 0 // Enable/disable non-client rendering based on window style
DWMNCRP_DISABLED = 1       // Disabled non-client rendering; window style is ignored
DWMNCRP_ENABLED = 2        // Enabled non-client rendering; window style is ignored
DWMNCRP_LAST = 3

// Values designating how Flip3D treats a given window.
// enum DWMFLIP3DWINDOWPOLICY
DWMFLIP3D_DEFAULT = 0      // Hide or include the window in Flip3D based on window style and visibility.
DWMFLIP3D_EXCLUDEBELOW = 1 // Display the window under Flip3D and disabled.
DWMFLIP3D_EXCLUDEABOVE = 2 // Display the window above Flip3D and enabled.
DWMFLIP3D_LAST = 3

#define DWM_TNP_RECTDESTINATION       0x00000001
#define DWM_TNP_RECTSOURCE            0x00000002
#define DWM_TNP_OPACITY               0x00000004
#define DWM_TNP_VISIBLE               0x00000008
#define DWM_TNP_SOURCECLIENTAREAONLY  0x00000010

DWM_THUMBNAIL_PROPERTIES STRUCT
	dwFlags DD
	rcDestination RECT
	rcSource RECT
	opacity BYTE
	fVisible BOOL
	fSourceClientAreaOnly BOOL
ENDS

// Video enabling apis

UNSIGNED_RATIO STRUCT
	uiNumerator DD
	uiDenominator DD
ENDS

DWM_TIMING_INFO STRUCT
	cbSize DD

    // Data on DWM composition overall
    
    // Monitor refresh rate
	rateRefresh UNSIGNED_RATIO

    // Actual period
	qpcRefreshPeriod DQ ; QPC_TIME

    // composition rate     
	rateCompose UNSIGNED_RATIO

    // QPC time at a VSync interupt
	qpcVBlank DQ ; QPC_TIME

    // DWM refresh count of the last vsync
    // DWM refresh count is a 64bit number where zero is
    // the first refresh the DWM woke up to process
	cRefresh DQ ; DWM_FRAME_COUNT

    // DX refresh count at the last Vsync Interupt
    // DX refresh count is a 32bit number with zero 
    // being the first refresh after the card was initialized
    // DX increments a counter when ever a VSync ISR is processed
    // It is possible for DX to miss VSyncs
    //
    // There is not a fixed mapping between DX and DWM refresh counts
    // because the DX will rollover and may miss VSync interupts
	cDXRefresh DD

    // QPC time at a compose time.  
	qpcCompose DQ ; QPC_TIME

    // Frame number that was composed at qpcCompose
	cFrame DQ ; DWM_FRAME_COUNT

    // The present number DX uses to identify renderer frames
	cDXPresent DD

    // Refresh count of the frame that was composed at qpcCompose
	cRefreshFrame DQ ; DWM_FRAME_COUNT


    // DWM frame number that was last submitted
	cFrameSubmitted DQ ; DWM_FRAME_COUNT

    // DX Present number that was last submitted
	cDXPresentSubmitted DD

    // DWM frame number that was last confirmed presented
	cFrameConfirmed DQ ; DWM_FRAME_COUNT

    // DX Present number that was last confirmed presented
	cDXPresentConfirmed DD

    // The target refresh count of the last
    // frame confirmed completed by the GPU
	cRefreshConfirmed DQ ; DWM_FRAME_COUNT

    // DX refresh count when the frame was confirmed presented
	cDXRefreshConfirmed DD

    // Number of frames the DWM presented late
    // AKA Glitches
	cFramesLate DQ ; DWM_FRAME_COUNT
    
    // the number of composition frames that 
    // have been issued but not confirmed completed
	cFramesOutstanding DD


    // Following fields are only relavent when an HWND is specified
    // Display frame


    // Last frame displayed
	cFrameDisplayed DQ ; DWM_FRAME_COUNT

    // QPC time of the composition pass when the frame was displayed
	qpcFrameDisplayed DQ ; QPC_TIME

    // Count of the VSync when the frame should have become visible
	cRefreshFrameDisplayed DQ ; DWM_FRAME_COUNT

    // Complete frames: DX has notified the DWM that the frame is done rendering

    // ID of the the last frame marked complete (starts at 0)
	cFrameComplete DQ ; DWM_FRAME_COUNT

    // QPC time when the last frame was marked complete
	qpcFrameComplete DQ ; QPC_TIME

    // Pending frames:
    // The application has been submitted to DX but not completed by the GPU
 
    // ID of the the last frame marked pending (starts at 0)
	cFramePending DQ ; DWM_FRAME_COUNT

    // QPC time when the last frame was marked pending
	qpcFramePending DQ ; QPC_TIME

    // number of unique frames displayed
	cFramesDisplayed DQ ; DWM_FRAME_COUNT

    // number of new completed frames that have been received
    DWM_FRAME_COUNT cFramesComplete DQ ; DWM_FRAME_COUNT

     // number of new frames submitted to DX but not yet complete
	cFramesPending DQ ; DWM_FRAME_COUNT

    // number of frames available but not displayed, used or dropped
	cFramesAvailable DQ ; DWM_FRAME_COUNT

    // number of rendered frames that were never
    // displayed because composition occured too late
	cFramesDropped DQ ; DWM_FRAME_COUNT
    
    // number of times an old frame was composed 
    // when a new frame should have been used
    // but was not available
	cFramesMissed DQ ; DWM_FRAME_COUNT
    
    // the refresh at which the next frame is
    // scheduled to be displayed
	cRefreshNextDisplayed DQ ; DWM_FRAME_COUNT

    // the refresh at which the next DX present is 
    // scheduled to be displayed
	cRefreshNextPresented DQ ; DWM_FRAME_COUNT

    // The total number of refreshes worth of content
    // for this HWND that have been displayed by the DWM
    // since DwmSetPresentParameters was called
	cRefreshesDisplayed DQ ; DWM_FRAME_COUNT
	
    // The total number of refreshes worth of content
    // that have been presented by the application
    // since DwmSetPresentParameters was called
	cRefreshesPresented DQ ; DWM_FRAME_COUNT


    // The actual refresh # when content for this
    // window started to be displayed
    // it may be different than that requested
    // DwmSetPresentParameters
	cRefreshStarted DQ ; DWM_FRAME_COUNT

    // Total number of pixels DX redirected
    // to the DWM.
    // If Queueing is used the full buffer
    // is transfered on each present.
    // If not queuing it is possible only 
    // a dirty region is updated
	cPixelsReceived DQ

    // Total number of pixels drawn.
    // Does not take into account if
    // if the window is only partial drawn
    // do to clipping or dirty rect management 
	cPixelsDrawn DQ

    // The number of buffers in the flipchain
    // that are empty.   An application can 
    // present that number of times and guarantee 
    // it won't be blocked waiting for a buffer to 
    // become empty to present to
	cBuffersEmpty DQ ; DWM_FRAME_COUNT
ENDS

// enum DWM_SOURCE_FRAME_SAMPLING
// Use the first source frame that 
// includes the first refresh of the output frame
DWM_SOURCE_FRAME_SAMPLING_POINT = 0

// use the source frame that includes the most 
// refreshes of out the output frame
// in case of multiple source frames with the 
// same coverage the last will be used
DWM_SOURCE_FRAME_SAMPLING_COVERAGE = 1

   // Sentinel value
DWM_SOURCE_FRAME_SAMPLING_LAST = 2

c_DwmMaxQueuedBuffers = 8
c_DwmMaxMonitors = 16
c_DwmMaxAdapters = 16

DWM_PRESENT_PARAMETERS STRUCT
	cbSize DD
	fQueue BOOL
	cRefreshStart DQ ;DWM_FRAME_COUNT
	cBuffer DD
	fUseSourceRate BOOL
	rateSource UNSIGNED_RATIO
	cRefreshesPerFrame DD
	eSampling DQ ;DWM_FRAME_COUNT
ENDS

#define DWM_FRAME_DURATION_DEFAULT -1

#define DWM_EC_DISABLECOMPOSITION         0
#define DWM_EC_ENABLECOMPOSITION          1

MilMatrix3x2D STRUCT
	S_11 DOUBLE
	S_12 DOUBLE
	S_21 DOUBLE
	S_22 DOUBLE
	DX DOUBLE
	DY DOUBLE
ENDS

#endif // DWMAPI_H


