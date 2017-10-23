/*==========================================================================;
 *
 *  Copyright (c) Microsoft Corporation.  All rights reserved.
 *
 *  File:       dsound.h
 *  Content:    DirectSound include file
 *
 **************************************************************************/
#ifndef DSOUND_H
#define DSOUND_H

#define COM_NO_WINDOWS_H

#IFNDEF OBJBASE_H
	#include "objbase.h"
#ENDIF
#IFNDEF FLOAT_H
	#include "C99\float.h"
#ENDIF
// #include <sal.h>

#ifndef DIRECTSOUND_VERSION
	#if WINVER < NTDDI_WINXP // Windows 2000
		#define DIRECTSOUND_VERSION 0x0700  // Version 7.0
	#elif WINVER < NTDDI_WINXPSP2 || WINVER == NTDDI_WS03 // Windows XP and SP1, or Windows Server 2003
		#define DIRECTSOUND_VERSION 0x0800  // Version 8.0
	#else // Windows XP SP2 and higher, Windows Server 2003 SP1 and higher, Longhorn, or higher
		#define DIRECTSOUND_VERSION 0x0900  // Version 9.0
	#endif
#endif // DIRECTSOUND_VERSION

#DEFINE D3DCOLOR DD

#ifndef D3DVECTOR
	D3DVECTOR STRUCT
		x FLOAT
		y FLOAT
		z FLOAT
	ENDS
#endif

// These are defined in Macros.h

#IFNDEF MAKE_HRESULT
MAKE_HRESULT(%sev,%fac,%code) MACRO
	((%sev<<31) | (%fac<<16) | %code )
ENDM
#ENDIF

#IFNDEF MAKE_DSHRESULT
MAKE_DSHRESULT(%code) MACRO
	(0x88780000 | %code )
ENDM
#ENDIF

// These are not defined in Macros.h

DSSPEAKER_COMBINED(%c, %g) MACRO
	(%c | (g << 16))
ENDM

DSSPEAKER_GEOMETRY(%a) MACRO
	((%a >> 16) & 0x00FF)
ENDM

#define FACDS  0x878   /* DirectSound's facility code */

// DirectSound Component GUID {47D4D946-62E8-11CF-93BC-444553540000}
#DEFINE GUID_CLSID_DirectSound <0x47d4d946, 0x62e8, 0x11cf, <0x93, 0xbc, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0>>

// DirectSound 8.0 Component GUID {3901CC3F-84B5-4FA4-BA35-AA8172B8A09B}
#DEFINE GUID_CLSID_DirectSound8 <0x3901cc3f, 0x84b5, 0x4fa4, <0xba, 0x35, 0xaa, 0x81, 0x72, 0xb8, 0xa0, 0x9b>>

// DirectSound Capture Component GUID {B0210780-89CD-11D0-AF08-00A0C925CD16}
#DEFINE GUID_CLSID_DirectSoundCapture <0xb0210780, 0x89cd, 0x11d0, <0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16>>

// DirectSound 8.0 Capture Component GUID {E4BCAC13-7F99-4908-9A8E-74E3BF24B6E1}
#DEFINE GUID_CLSID_DirectSoundCapture8 <0xe4bcac13, 0x7f99, 0x4908, <0x9a, 0x8e, 0x74, 0xe3, 0xbf, 0x24, 0xb6, 0xe1>>

// DirectSound Full Duplex Component GUID {FEA4300C-7959-4147-B26A-2377B9E7A91D}
#DEFINE GUID_CLSID_DirectSoundFullDuplex <0xfea4300c, 0x7959, 0x4147, <0xb2, 0x6a, 0x23, 0x77, 0xb9, 0xe7, 0xa9, 0x1d>>

// DirectSound default playback device GUID {DEF00000-9C6D-47ED-AAF1-4DDA8F2B5C03}
#DEFINE GUID_DSDEVID_DefaultPlayback <0xdef00000, 0x9c6d, 0x47ed, <0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03>>

// DirectSound default capture device GUID {DEF00001-9C6D-47ED-AAF1-4DDA8F2B5C03}
#DEFINE GUID_DSDEVID_DefaultCapture <0xdef00001, 0x9c6d, 0x47ed, <0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03>>

// DirectSound default device for voice playback {DEF00002-9C6D-47ED-AAF1-4DDA8F2B5C03}
#DEFINE GUID_DSDEVID_DefaultVoicePlayback <0xdef00002, 0x9c6d, 0x47ed, <0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03>>

// DirectSound default device for voice capture {DEF00003-9C6D-47ED-AAF1-4DDA8F2B5C03}
#DEFINE GUID_DSDEVID_DefaultVoiceCapture <0xdef00003, 0x9c6d, 0x47ed, <0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03>>

//
// DirectSound 8.0 interfaces.
//

#if DIRECTSOUND_VERSION >= 0x0800
// IDirectSound8, IDirectSoundBuffer8 and IDirectSoundCaptureBuffer8 are the
// only DirectSound 7.0 interfaces with changed functionality in version 8.0.
// The other level 8 interfaces as equivalent to their level 7 counterparts:

#define IDirectSoundCapture8            IDirectSoundCapture
#define IDirectSound3DListener8         IDirectSound3DListener
#define IDirectSound3DBuffer8           IDirectSound3DBuffer
#define IDirectSoundNotify8             IDirectSoundNotify
#define IDirectSoundFXGargle8           IDirectSoundFXGargle
#define IDirectSoundFXChorus8           IDirectSoundFXChorus
#define IDirectSoundFXFlanger8          IDirectSoundFXFlanger
#define IDirectSoundFXEcho8             IDirectSoundFXEcho
#define IDirectSoundFXDistortion8       IDirectSoundFXDistortion
#define IDirectSoundFXCompressor8       IDirectSoundFXCompressor
#define IDirectSoundFXParamEq8          IDirectSoundFXParamEq
#define IDirectSoundFXWavesReverb8      IDirectSoundFXWavesReverb
#define IDirectSoundFXI3DL2Reverb8      IDirectSoundFXI3DL2Reverb
#define IDirectSoundCaptureFXAec8       IDirectSoundCaptureFXAec
#define IDirectSoundCaptureFXNoiseSuppress8 IDirectSoundCaptureFXNoiseSuppress
#define IDirectSoundFullDuplex8         IDirectSoundFullDuplex

#endif // DIRECTSOUND_VERSION >= 0x0800
//
// Structures
//

DSCAPS STRUCT
	dwSize DD
	dwFlags DD
	dwMinSecondarySampleRate DD
	dwMaxSecondarySampleRate DD
	dwPrimaryBuffers DD
	dwMaxHwMixingAllBuffers DD
	dwMaxHwMixingStaticBuffers DD
	dwMaxHwMixingStreamingBuffers DD
	dwFreeHwMixingAllBuffers DD
	dwFreeHwMixingStaticBuffers DD
	dwFreeHwMixingStreamingBuffers DD
	dwMaxHw3DAllBuffers DD
	dwMaxHw3DStaticBuffers DD
	dwMaxHw3DStreamingBuffers DD
	dwFreeHw3DAllBuffers DD
	dwFreeHw3DStaticBuffers DD
	dwFreeHw3DStreamingBuffers DD
	dwTotalHwMemBytes DD
	dwFreeHwMemBytes DD
	dwMaxContigFreeHwMemBytes DD
	dwUnlockTransferRateHwBuffers DD
	dwPlayCpuOverheadSwBuffers DD
	dwReserved1 DD
	dwReserved2 DD
ENDS

DSBCAPS STRUCT
	dwSize DD
	dwFlags DD
	dwBufferBytes DD
	dwUnlockTransferRate DD
	dwPlayCpuOverhead DD
ENDS

#if DIRECTSOUND_VERSION >= 0x0800

	DSEFFECTDESC STRUCT
		dwSize DD
		dwFlags DD
		guidDSFXClass GUID
		dwReserved1 DWORD_PTR
		dwReserved2 DWORD_PTR
	ENDS

	#define DSFX_LOCHARDWARE    0x00000001
	#define DSFX_LOCSOFTWARE    0x00000002

	DSFXR_PRESENT = 0
	DSFXR_LOCHARDWARE = 1
	DSFXR_LOCSOFTWARE = 2
	DSFXR_UNALLOCATED = 3
	DSFXR_FAILED = 4
	DSFXR_UNKNOWN = 5
	DSFXR_SENDLOOP = 6

	DSCEFFECTDESC STRUCT
		dwSize DD
		dwFlags DD
		guidDSCFXClass GUID
		guidDSCFXInstance GUID
		dwReserved1 DD
		dwReserved2 DD
	ENDS

	#define DSCFX_LOCHARDWARE   0x00000001
	#define DSCFX_LOCSOFTWARE   0x00000002

	#define DSCFXR_LOCHARDWARE  0x00000010
	#define DSCFXR_LOCSOFTWARE  0x00000020

#endif // DIRECTSOUND_VERSION >= 0x0800

DSBUFFERDESC STRUCT
	dwSize DD
	dwFlags DD
	dwBufferBytes DD
	dwReserved DD
	lpwfxFormat PTR
	#if DIRECTSOUND_VERSION >= 0x0700
		guid3DAlgorithm GUID
	#endif
ENDS

// Older version of this structure:

DSBUFFERDESC1 STRUCT
	dwSize DD
	dwFlags DD
	dwBufferBytes DD
	dwReserved DD
	lpwfxFormat PTR
ENDS

DS3DBUFFER STRUCT
	dwSize DD
	vPosition D3DVECTOR
	vVelocity D3DVECTOR
	dwInsideConeAngle DD
	dwOutsideConeAngle DD
	vConeOrientation D3DVECTOR
	lConeOutsideVolume LONG
	flMinDistance FLOAT
	flMaxDistance FLOAT
	dwMode DD
ENDS

DS3DLISTENER STRUCT
	dwSize DD
	vPosition D3DVECTOR
	vVelocity D3DVECTOR
	vOrientFront D3DVECTOR
	vOrientTop D3DVECTOR
	flDistanceFactor FLOAT
	flRolloffFactor FLOAT
	flDopplerFactor FLOAT
ENDS

DSCCAPS STRUCT
	dwSize DD
	dwFlags DD
	dwFormats DD
	dwChannels DD
ENDS

DSCBUFFERDESC1 STRUCT
	dwSize DD
	dwFlags DD
	dwBufferBytes DD
	dwReserved DD
	lpwfxFormat PTR
ENDS

DSCBUFFERDESC STRUCT
	dwSize DD
	dwFlags DD
	dwBufferBytes DD
	dwReserved DD
	lpwfxFormat PTR
	#if DIRECTSOUND_VERSION >= 0x0800
		dwFXCount DD
		lpDSCFXDesc PTR
	#endif
ENDS

DSCBCAPS STRUCT
	dwSize DD
	dwFlags DD
	dwBufferBytes DD
	dwReserved DD
ENDS

DSBPOSITIONNOTIFY STRUCT
	dwOffset DD
	EventNotify HANDLE
ENDS

#if DIRECTSOUND_VERSION >= 0x0800
	#define DirectSoundFullDuplexCreate8 DirectSoundFullDuplexCreate
#endif

#ifdef UNICODE
	#define DirectSoundEnumerate DirectSoundEnumerateW
	#define DirectSoundCaptureEnumerate DirectSoundCaptureEnumerateW
#else
	#define DirectSoundEnumerate DirectSoundEnumerateA
	#define DirectSoundCaptureEnumerate DirectSoundCaptureEnumerateA
#endif

#DEFINE GUID_IID_IReferenceClock <0x56a86897, 0x0ad4, 0x11ce, <0xb0, 0x3a, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70>>

IReferenceClock STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTime PTR
	AdviseTime PTR
	AdvisePeriodic PTR
	Unadvise PTR
ENDS

//
// IDirectSound
//

#DEFINE GUID_IID_IDirectSound <0x279AFA83, 0x4981, 0x11CE, <0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60>>

IDirectSound STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateSoundBuffer PTR
	GetCaps PTR
	DuplicateSoundBuffer PTR
	SetCooperativeLevel PTR
	Compact PTR
	GetSpeakerConfig PTR
	SetSpeakerConfig PTR
	Initialize PTR
ENDS

#if DIRECTSOUND_VERSION >= 0x0800

#DEFINE GUID_IID_IDirectSound8 <0xC50A7E93, 0xF395, 0x4834, <0x9E, 0xF6, 0x7F, 0xA9, 0x9D, 0xE5, 0x09, 0x66>>

#undef INTERFACE
#define INTERFACE IDirectSound8

IDirectSound8 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateSoundBuffer PTR
	GetCaps PTR
	DuplicateSoundBuffer PTR
	SetCooperativeLevel PTR
	Compact PTR
	GetSpeakerConfig PTR
	SetSpeakerConfig PTR
	Initialize PTR
	VerifyCertification PTR
ENDS

#endif

#DEFINE GUID_IID_IDirectSoundBuffer <0x279AFA85, 0x4981, 0x11CE, <0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60>>

IDirectSoundBuffer STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCaps PTR
	GetCurrentPosition PTR
	GetFormat PTR
	GetVolume PTR
	GetPan PTR
	GetFrequency PTR
	GetStatus PTR
	Initialize PTR
	Lock PTR
	Play PTR
	SetCurrentPosition PTR
	SetFormat PTR
	SetVolume PTR
	SetPan PTR
	SetFrequency PTR
	Stop PTR
	Unlock PTR
	Restore PTR
ENDS

#if DIRECTSOUND_VERSION >= 0x0800

#DEFINE GUID_IID_IDirectSoundBuffer8 <0x6825a449, 0x7524, 0x4d82, <0x92, 0x0f, 0x50, 0xe3, 0x6a, 0xb3, 0xab, 0x1e>>

IDirectSoundBuffer8 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCaps PTR
	GetCurrentPosition PTR
	GetFormat PTR
	GetVolume PTR
	GetPan PTR
	GetFrequency PTR
	GetStatus PTR
	Initialize PTR
	Lock PTR
	Play PTR
	SetCurrentPosition PTR
	SetFormat PTR
	SetVolume PTR
	SetPan PTR
	SetFrequency PTR
	Stop PTR
	Unlock PTR
	Restore PTR
	SetFX PTR
	AcquireResources PTR
	GetObjectInPath PTR
ENDS

#endif

#DEFINE GUID_IID_IDirectSound3DListener <0x279AFA84, 0x4981, 0x11CE, <0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60>>

IDirectSound3DListener STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetAllParameters PTR
	GetDistanceFactor PTR
	GetDopplerFactor PTR
	GetOrientation PTR
	GetPosition PTR
	GetRolloffFactor PTR
	GetVelocity PTR
	SetAllParameters PTR
	SetDistanceFactor PTR
	SetDopplerFactor PTR
	SetOrientation PTR
	SetPosition PTR
	SetRolloffFactor PTR
	SetVelocity PTR
	CommitDeferredSettings PTR
ENDS


#DEFINE GUID_IID_IDirectSound3DBuffer <0x279AFA86, 0x4981, 0x11CE, <0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60>>

IDirectSound3DBuffer STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetAllParameters PTR
	GetConeAngles PTR
	GetConeOrientation PTR
	GetConeOutsideVolume PTR
	GetMaxDistance PTR
	GetMinDistance PTR
	GetMode PTR
	GetPosition PTR
	GetVelocity PTR
	SetAllParameters PTR
	SetConeAngles PTR
	SetConeOrientation PTR
	SetConeOutsideVolume PTR
	SetMaxDistance PTR
	SetMinDistance PTR
	SetMode PTR
	SetPosition PTR
	SetVelocity PTR
ENDS

#DEFINE GUID_IID_IDirectSoundCapture <0xb0210781, 0x89cd, 0x11d0, <0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16>>

IDirectSoundCapture STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateCaptureBuffer PTR
	GetCaps PTR
	Initialize PTR
ENDS

DEFINE GUID_IID_IDirectSoundCaptureBuffer <0xb0210782, 0x89cd, 0x11d0, <0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16>>

IDirectSoundCaptureBuffer STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCaps PTR
	GetCurrentPosition PTR
	GetFormat PTR
	GetStatus PTR
	Initialize PTR
	Lock PTR
	Start PTR
	Stop PTR
	Unlock PTR
ENDS

#if DIRECTSOUND_VERSION >= 0x0800

#DEFINE GUID_IID_IDirectSoundCaptureBuffer8 <0x990df4, 0xdbb, 0x4872, <0x83, 0x3e, 0x6d, 0x30, 0x3e, 0x80, 0xae, 0xb6>>

IDirectSoundCaptureBuffer8 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCaps PTR
	GetCurrentPosition PTR
	GetFormat PTR
	GetStatus PTR
	Initialize PTR
	Lock PTR
	Start PTR
	Stop PTR
	Unlock PTR
	GetObjectInPath PTR
	GetFXStatus PTR
ENDS

#endif

#DEFINE GUID_IID_IDirectSoundNotify <0xb0210783, 0x89cd, 0x11d0, <0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16>>

IDirectSoundNotify STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetNotificationPositions PTR
ENDS

#define KSPROPERTY_SUPPORT_GET  0x00000001
#define KSPROPERTY_SUPPORT_SET  0x00000002

#DEFINE GUID_IID_IKsPropertySet <0x31efac30, 0x515c, 0x11d0, <0xa9, 0xaa, 0x00, 0xaa, 0x00, 0x61, 0xbe, 0x93>>

IKsPropertySet STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Get PTR
	Set PTR
	QuerySupport PTR
ENDS

#if DIRECTSOUND_VERSION >= 0x0800

#DEFINE GUID_IID_IDirectSoundFXGargle <0xd616f352, 0xd622, 0x11ce, <0xaa, 0xc5, 0x00, 0x20, 0xaf, 0x0b, 0x99, 0xa3>>

DSFXGargle STRUCT
	dwRateHz DD
	dwWaveShape DD
ENDS

#define DSFXGARGLE_WAVE_TRIANGLE        0
#define DSFXGARGLE_WAVE_SQUARE          1

#define DSFXGARGLE_RATEHZ_MIN           1
#define DSFXGARGLE_RATEHZ_MAX           1000

IDirectSoundFXGargle STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFXChorus <0x880842e3, 0x145f, 0x43e6, <0xa9, 0x34, 0xa7, 0x18, 0x06, 0xe5, 0x05, 0x47>>

DSFXChorus STRUCT
	fWetDryMix FLOAT
	fDepth FLOAT
	fFeedback FLOAT
	fFrequency FLOAT
	lWaveform LONG
	fDelay FLOAT
	lPhase LONG
ENDS

#define DSFXCHORUS_WAVE_TRIANGLE        0
#define DSFXCHORUS_WAVE_SIN             1

#define DSFXCHORUS_WETDRYMIX_MIN        0.0
#define DSFXCHORUS_WETDRYMIX_MAX        100.0
#define DSFXCHORUS_DEPTH_MIN            0.0
#define DSFXCHORUS_DEPTH_MAX            100.0
#define DSFXCHORUS_FEEDBACK_MIN         -99.0
#define DSFXCHORUS_FEEDBACK_MAX         99.0
#define DSFXCHORUS_FREQUENCY_MIN        0.0
#define DSFXCHORUS_FREQUENCY_MAX        10.0
#define DSFXCHORUS_DELAY_MIN            0.0
#define DSFXCHORUS_DELAY_MAX            20.0
#define DSFXCHORUS_PHASE_MIN            0
#define DSFXCHORUS_PHASE_MAX            4

#define DSFXCHORUS_PHASE_NEG_180        0
#define DSFXCHORUS_PHASE_NEG_90         1
#define DSFXCHORUS_PHASE_ZERO           2
#define DSFXCHORUS_PHASE_90             3
#define DSFXCHORUS_PHASE_180            4

IDirectSoundFXChorus STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFXFlanger <0x903e9878, 0x2c92, 0x4072, <0x9b, 0x2c, 0xea, 0x68, 0xf5, 0x39, 0x67, 0x83>>

DSFXFlanger STRUCT
	fWetDryMix FLOAT
	fDepth FLOAT
	fFeedback FLOAT
	fFrequency FLOAT
	lWaveform LONG
	fDelay FLOAT
	lPhase LONG
ENDS

#define DSFXFLANGER_WAVE_TRIANGLE       0
#define DSFXFLANGER_WAVE_SIN            1

#define DSFXFLANGER_WETDRYMIX_MIN       0.0
#define DSFXFLANGER_WETDRYMIX_MAX       100.0
#define DSFXFLANGER_FREQUENCY_MIN       0.0
#define DSFXFLANGER_FREQUENCY_MAX       10.0
#define DSFXFLANGER_DEPTH_MIN           0.0
#define DSFXFLANGER_DEPTH_MAX           100.0
#define DSFXFLANGER_PHASE_MIN           0
#define DSFXFLANGER_PHASE_MAX           4
#define DSFXFLANGER_FEEDBACK_MIN        -99.0
#define DSFXFLANGER_FEEDBACK_MAX        99.0
#define DSFXFLANGER_DELAY_MIN           0.0
#define DSFXFLANGER_DELAY_MAX           4.0

#define DSFXFLANGER_PHASE_NEG_180       0
#define DSFXFLANGER_PHASE_NEG_90        1
#define DSFXFLANGER_PHASE_ZERO          2
#define DSFXFLANGER_PHASE_90            3
#define DSFXFLANGER_PHASE_180           4

IDirectSoundFXFlanger STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFXEcho <0x8bd28edf, 0x50db, 0x4e92, <0xa2, 0xbd, 0x44, 0x54, 0x88, 0xd1, 0xed, 0x42>>

DSFXEcho STRUCT
	fWetDryMix FLOAT
	fFeedback FLOAT
	fLeftDelay FLOAT
	fRightDelay FLOAT
	lPanDelay LONG
ENDS

#define DSFXECHO_WETDRYMIX_MIN      0.0
#define DSFXECHO_WETDRYMIX_MAX      100.0
#define DSFXECHO_FEEDBACK_MIN       0.0
#define DSFXECHO_FEEDBACK_MAX       100.0
#define DSFXECHO_LEFTDELAY_MIN      1.0
#define DSFXECHO_LEFTDELAY_MAX      2000.0
#define DSFXECHO_RIGHTDELAY_MIN     1.0
#define DSFXECHO_RIGHTDELAY_MAX     2000.0
#define DSFXECHO_PANDELAY_MIN       0
#define DSFXECHO_PANDELAY_MAX       1

IDirectSoundFXEcho STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFXDistortion <0x8ecf4326, 0x455f, 0x4d8b, <0xbd, 0xa9, 0x8d, 0x5d, 0x3e, 0x9e, 0x3e, 0x0b>>

DSFXDistortion STRUCT
	fGain FLOAT
	fEdge FLOAT
	fPostEQCenterFrequency FLOAT
	fPostEQBandwidth FLOAT
	fPreLowpassCutoff FLOAT
ENDS

#define DSFXDISTORTION_GAIN_MIN                     -60.0
#define DSFXDISTORTION_GAIN_MAX                     0.0
#define DSFXDISTORTION_EDGE_MIN                     0.0
#define DSFXDISTORTION_EDGE_MAX                     100.0
#define DSFXDISTORTION_POSTEQCENTERFREQUENCY_MIN    100.0
#define DSFXDISTORTION_POSTEQCENTERFREQUENCY_MAX    8000.0
#define DSFXDISTORTION_POSTEQBANDWIDTH_MIN          100.0
#define DSFXDISTORTION_POSTEQBANDWIDTH_MAX          8000.0
#define DSFXDISTORTION_PRELOWPASSCUTOFF_MIN         100.0
#define DSFXDISTORTION_PRELOWPASSCUTOFF_MAX         8000.0

IDirectSoundFXDistortion STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFXCompressor <0x4bbd1154, 0x62f6, 0x4e2c, <0xa1, 0x5c, 0xd3, 0xb6, 0xc4, 0x17, 0xf7, 0xa0>>

DSFXCompressor STRUCT
	fGain FLOAT
	fAttack FLOAT
	fRelease FLOAT
	fThreshold FLOAT
	fRatio FLOAT
	fPredelay FLOAT
ENDS

#define DSFXCOMPRESSOR_GAIN_MIN             -60.0
#define DSFXCOMPRESSOR_GAIN_MAX             60.0
#define DSFXCOMPRESSOR_ATTACK_MIN           0.01
#define DSFXCOMPRESSOR_ATTACK_MAX           500.0
#define DSFXCOMPRESSOR_RELEASE_MIN          50.0
#define DSFXCOMPRESSOR_RELEASE_MAX          3000.0
#define DSFXCOMPRESSOR_THRESHOLD_MIN        -60.0
#define DSFXCOMPRESSOR_THRESHOLD_MAX        0.0
#define DSFXCOMPRESSOR_RATIO_MIN            1.0
#define DSFXCOMPRESSOR_RATIO_MAX            100.0
#define DSFXCOMPRESSOR_PREDELAY_MIN         0.0
#define DSFXCOMPRESSOR_PREDELAY_MAX         4.0

IDirectSoundFXCompressor STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFXParamEq <0xc03ca9fe, 0xfe90, 0x4204, <0x80, 0x78, 0x82, 0x33, 0x4c, 0xd1, 0x77, 0xda>>

DSFXParamEq STRUCT
	fCenter FLOAT
	fBandwidth FLOAT
	fGain FLOAT
ENDS

#define DSFXPARAMEQ_CENTER_MIN      80.0
#define DSFXPARAMEQ_CENTER_MAX      16000.0
#define DSFXPARAMEQ_BANDWIDTH_MIN   1.0
#define DSFXPARAMEQ_BANDWIDTH_MAX   36.0
#define DSFXPARAMEQ_GAIN_MIN        -15.0
#define DSFXPARAMEQ_GAIN_MAX        15.0

IDirectSoundFXParamEq STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFXI3DL2Reverb <0x4b166a6a, 0x0d66, 0x43f3, <0x80, 0xe3, 0xee, 0x62, 0x80, 0xde, 0xe1, 0xa4>

DSFXI3DL2Reverb STRUCT
	lRoom LONG
	lRoomHF LONG
	flRoomRolloffFactor FLOAT
	flDecayTime FLOAT
	flDecayHFRatio FLOAT
	lReflections LONG
	flReflectionsDelay FLOAT
	lReverb LONG
	flReverbDelay FLOAT
	flDiffusion FLOAT
	flDensity FLOAT
	flHFReference FLOAT
ENDS

#define DSFX_I3DL2REVERB_ROOM_MIN                   -10000
#define DSFX_I3DL2REVERB_ROOM_MAX                   0
#define DSFX_I3DL2REVERB_ROOM_DEFAULT               -1000

#define DSFX_I3DL2REVERB_ROOMHF_MIN                 -10000
#define DSFX_I3DL2REVERB_ROOMHF_MAX                 0
#define DSFX_I3DL2REVERB_ROOMHF_DEFAULT             -100

#define DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MIN      0.0
#define DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MAX      10.0
#define DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_DEFAULT  0.0

#define DSFX_I3DL2REVERB_DECAYTIME_MIN              0.1
#define DSFX_I3DL2REVERB_DECAYTIME_MAX              20.0
#define DSFX_I3DL2REVERB_DECAYTIME_DEFAULT          1.49

#define DSFX_I3DL2REVERB_DECAYHFRATIO_MIN           0.1
#define DSFX_I3DL2REVERB_DECAYHFRATIO_MAX           2.0
#define DSFX_I3DL2REVERB_DECAYHFRATIO_DEFAULT       0.83

#define DSFX_I3DL2REVERB_REFLECTIONS_MIN            -10000
#define DSFX_I3DL2REVERB_REFLECTIONS_MAX            1000
#define DSFX_I3DL2REVERB_REFLECTIONS_DEFAULT        -2602

#define DSFX_I3DL2REVERB_REFLECTIONSDELAY_MIN       0.0
#define DSFX_I3DL2REVERB_REFLECTIONSDELAY_MAX       0.3
#define DSFX_I3DL2REVERB_REFLECTIONSDELAY_DEFAULT   0.007

#define DSFX_I3DL2REVERB_REVERB_MIN                 -10000
#define DSFX_I3DL2REVERB_REVERB_MAX                 2000
#define DSFX_I3DL2REVERB_REVERB_DEFAULT             200

#define DSFX_I3DL2REVERB_REVERBDELAY_MIN            0.0
#define DSFX_I3DL2REVERB_REVERBDELAY_MAX            0.1
#define DSFX_I3DL2REVERB_REVERBDELAY_DEFAULT        0.011

#define DSFX_I3DL2REVERB_DIFFUSION_MIN              0.0
#define DSFX_I3DL2REVERB_DIFFUSION_MAX              100.0
#define DSFX_I3DL2REVERB_DIFFUSION_DEFAULT          100.0

#define DSFX_I3DL2REVERB_DENSITY_MIN                0.0
#define DSFX_I3DL2REVERB_DENSITY_MAX                100.0
#define DSFX_I3DL2REVERB_DENSITY_DEFAULT            100.0

#define DSFX_I3DL2REVERB_HFREFERENCE_MIN            20.0
#define DSFX_I3DL2REVERB_HFREFERENCE_MAX            20000.0
#define DSFX_I3DL2REVERB_HFREFERENCE_DEFAULT        5000.0

#define DSFX_I3DL2REVERB_QUALITY_MIN                0
#define DSFX_I3DL2REVERB_QUALITY_MAX                3
#define DSFX_I3DL2REVERB_QUALITY_DEFAULT            2

IDirectSoundFXI3DL2Reverb STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
	SetPreset PTR
	GetPreset PTR
	SetQuality PTR
	GetQuality PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFXWavesReverb <0x46858c3a,0x0dc6,0x45e3,<0xb7,0x60,0xd4,0xee,0xf1,0x6c,0xb3,0x25>>

DSFXWavesReverb STRUCT
	fInGain FLOAT
	fReverbMix FLOAT
	fReverbTime FLOAT
	fHighFreqRTRatio FLOAT
ENDS

#define DSFX_WAVESREVERB_INGAIN_MIN                 -96.0
#define DSFX_WAVESREVERB_INGAIN_MAX                 0.0
#define DSFX_WAVESREVERB_INGAIN_DEFAULT             0.0
#define DSFX_WAVESREVERB_REVERBMIX_MIN              -96.0
#define DSFX_WAVESREVERB_REVERBMIX_MAX              0.0
#define DSFX_WAVESREVERB_REVERBMIX_DEFAULT          0.0
#define DSFX_WAVESREVERB_REVERBTIME_MIN             0.001
#define DSFX_WAVESREVERB_REVERBTIME_MAX             3000.0
#define DSFX_WAVESREVERB_REVERBTIME_DEFAULT         1000.0
#define DSFX_WAVESREVERB_HIGHFREQRTRATIO_MIN        0.001
#define DSFX_WAVESREVERB_HIGHFREQRTRATIO_MAX        0.999
#define DSFX_WAVESREVERB_HIGHFREQRTRATIO_DEFAULT    0.001

IDirectSoundFXWavesReverb STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
ENDS

#DEFINE GUID_IID_IDirectSoundCaptureFXAec <0xad74143d, 0x903d, 0x4ab7, <0x80, 0x66, 0x28, 0xd3, 0x63, 0x03, 0x6d, 0x65>>

DSCFXAec STRUCT
	fEnable BOOL
	fNoiseFill BOOL
	dwMode DD
ENDS

// These match the AEC_MODE_* constants in the DDK's ksmedia.h file
#define DSCFX_AEC_MODE_PASS_THROUGH                     0x0
#define DSCFX_AEC_MODE_HALF_DUPLEX                      0x1
#define DSCFX_AEC_MODE_FULL_DUPLEX                      0x2

// These match the AEC_STATUS_* constants in ksmedia.h
#define DSCFX_AEC_STATUS_HISTORY_UNINITIALIZED          0x0
#define DSCFX_AEC_STATUS_HISTORY_CONTINUOUSLY_CONVERGED 0x1
#define DSCFX_AEC_STATUS_HISTORY_PREVIOUSLY_DIVERGED    0x2
#define DSCFX_AEC_STATUS_CURRENTLY_CONVERGED            0x8

IDirectSoundCaptureFXAec STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
	GetStatus PTR
	Reset PTR
ENDS

#DEFINE GUID_IID_IDirectSoundCaptureFXNoiseSuppress <0xed311e41, 0xfbae, 0x4175, <0x96, 0x25, 0xcd, 0x8, 0x54, 0xf6, 0x93, 0xca>>

DSCFXNoiseSuppress STRUCT
	fEnable BOOL
ENDS

IDirectSoundCaptureFXNoiseSuppress STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAllParameters PTR
	GetAllParameters PTR
	Reset PTR
ENDS

#DEFINE GUID_IID_IDirectSoundFullDuplex <0xedcb4c7a, 0xdaab, 0x4216, <0xa4, 0x2e, 0x6c, 0x50, 0x59, 0x6d, 0xdc, 0x1d>>

IDirectSoundFullDuplex STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
ENDS

#endif // DIRECTSOUND_VERSION >= 0x0800

#define DS_OK                           S_OK

// The call succeeded, but we had to substitute the 3D algorithm
#define DS_NO_VIRTUALIZATION            ((0x878<<16) | 10)

// The call failed because resources (such as a priority level)
// were already being used by another caller
#define DSERR_ALLOCATED                 (0x88780000 | 10)

// The control (vol, pan, etc.) requested by the caller is not available
#define DSERR_CONTROLUNAVAIL            (0x88780000 | 30)

// An invalid parameter was passed to the returning function
#define DSERR_INVALIDPARAM              E_INVALIDARG

// This call is not valid for the current state of this object
#define DSERR_INVALIDCALL               (0x88780000 | 50)

// An undetermined error occurred inside the DirectSound subsystem
#define DSERR_GENERIC                   E_FAIL

// The caller does not have the priority level required for the function to
// succeed
#define DSERR_PRIOLEVELNEEDED           (0x88780000 | 70)

// Not enough free memory is available to complete the operation
#define DSERR_OUTOFMEMORY               E_OUTOFMEMORY

// The specified WAVE format is not supported
#define DSERR_BADFORMAT                 (0x88780000 | 100)

// The function called is not supported at this time
#define DSERR_UNSUPPORTED               E_NOTIMPL

// No sound driver is available for use
#define DSERR_NODRIVER                  (0x88780000 | 120)

// This object is already initialized
#define DSERR_ALREADYINITIALIZED        (0x88780000 | 130)

// This object does not support aggregation
#define DSERR_NOAGGREGATION             CLASS_E_NOAGGREGATION

// The buffer memory has been lost, and must be restored
#define DSERR_BUFFERLOST                (0x88780000 | 150)

// Another app has a higher priority level, preventing this call from
// succeeding
#define DSERR_OTHERAPPHASPRIO           (0x88780000 | 160)

// This object has not been initialized
#define DSERR_UNINITIALIZED             (0x88780000 | 170)

// The requested COM interface is not available
#define DSERR_NOINTERFACE               E_NOINTERFACE

// Access is denied
#define DSERR_ACCESSDENIED              E_ACCESSDENIED

// Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds
#define DSERR_BUFFERTOOSMALL            (0x88780000 | 180)

// Attempt to use DirectSound 8 functionality on an older DirectSound object
#define DSERR_DS8_REQUIRED              (0x88780000 | 190)

// A circular loop of send effects was detected
#define DSERR_SENDLOOP                  (0x88780000 | 200)

// The GUID specified in an audiopath file does not match a valid MIXIN buffer
#define DSERR_BADSENDBUFFERGUID         (0x88780000 | 210)

// The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)
#define DSERR_OBJECTNOTFOUND            (0x88780000 | 4449)

// The effects requested could not be found on the system, or they were found
// but in the wrong order, or in the wrong hardware/software locations.
#define DSERR_FXUNAVAILABLE             (0x88780000 | 220)

#define DSCAPS_PRIMARYMONO          0x00000001
#define DSCAPS_PRIMARYSTEREO        0x00000002
#define DSCAPS_PRIMARY8BIT          0x00000004
#define DSCAPS_PRIMARY16BIT         0x00000008
#define DSCAPS_CONTINUOUSRATE       0x00000010
#define DSCAPS_EMULDRIVER           0x00000020
#define DSCAPS_CERTIFIED            0x00000040
#define DSCAPS_SECONDARYMONO        0x00000100
#define DSCAPS_SECONDARYSTEREO      0x00000200
#define DSCAPS_SECONDARY8BIT        0x00000400
#define DSCAPS_SECONDARY16BIT       0x00000800

#define DSSCL_NORMAL                0x00000001
#define DSSCL_PRIORITY              0x00000002
#define DSSCL_EXCLUSIVE             0x00000003
#define DSSCL_WRITEPRIMARY          0x00000004

#define DSSPEAKER_DIRECTOUT         0x00000000
#define DSSPEAKER_HEADPHONE         0x00000001
#define DSSPEAKER_MONO              0x00000002
#define DSSPEAKER_QUAD              0x00000003
#define DSSPEAKER_STEREO            0x00000004
#define DSSPEAKER_SURROUND          0x00000005
#define DSSPEAKER_5POINT1           0x00000006  // obsolete 5.1 setting
#define DSSPEAKER_7POINT1           0x00000007  // obsolete 7.1 setting
#define DSSPEAKER_7POINT1_SURROUND  0x00000008  // correct 7.1 Home Theater setting
#define DSSPEAKER_5POINT1_SURROUND  0x00000009  // correct 5.1 setting
#define DSSPEAKER_7POINT1_WIDE      0x00000007
#define DSSPEAKER_5POINT1_BACK      0x00000006

#define DSSPEAKER_GEOMETRY_MIN      0x00000005  //   5 degrees
#define DSSPEAKER_GEOMETRY_NARROW   0x0000000A  //  10 degrees
#define DSSPEAKER_GEOMETRY_WIDE     0x00000014  //  20 degrees
#define DSSPEAKER_GEOMETRY_MAX      0x000000B4  // 180 degrees

#define DSBCAPS_PRIMARYBUFFER       0x00000001
#define DSBCAPS_STATIC              0x00000002
#define DSBCAPS_LOCHARDWARE         0x00000004
#define DSBCAPS_LOCSOFTWARE         0x00000008
#define DSBCAPS_CTRL3D              0x00000010
#define DSBCAPS_CTRLFREQUENCY       0x00000020
#define DSBCAPS_CTRLPAN             0x00000040
#define DSBCAPS_CTRLVOLUME          0x00000080
#define DSBCAPS_CTRLPOSITIONNOTIFY  0x00000100
#define DSBCAPS_CTRLFX              0x00000200
#define DSBCAPS_STICKYFOCUS         0x00004000
#define DSBCAPS_GLOBALFOCUS         0x00008000
#define DSBCAPS_GETCURRENTPOSITION2 0x00010000
#define DSBCAPS_MUTE3DATMAXDISTANCE 0x00020000
#define DSBCAPS_LOCDEFER            0x00040000
#define DSBCAPS_TRUEPLAYPOSITION    0x00080000

#define DSBPLAY_LOOPING             0x00000001
#define DSBPLAY_LOCHARDWARE         0x00000002
#define DSBPLAY_LOCSOFTWARE         0x00000004
#define DSBPLAY_TERMINATEBY_TIME    0x00000008
#define DSBPLAY_TERMINATEBY_DISTANCE    0x000000010
#define DSBPLAY_TERMINATEBY_PRIORITY    0x000000020

#define DSBSTATUS_PLAYING           0x00000001
#define DSBSTATUS_BUFFERLOST        0x00000002
#define DSBSTATUS_LOOPING           0x00000004
#define DSBSTATUS_LOCHARDWARE       0x00000008
#define DSBSTATUS_LOCSOFTWARE       0x00000010
#define DSBSTATUS_TERMINATED        0x00000020

#define DSBLOCK_FROMWRITECURSOR     0x00000001
#define DSBLOCK_ENTIREBUFFER        0x00000002

#define DSBFREQUENCY_ORIGINAL       0
#define DSBFREQUENCY_MIN            100

#if DIRECTSOUND_VERSION >= 0x0900
#define DSBFREQUENCY_MAX            200000
#else
#define DSBFREQUENCY_MAX            100000
#endif

#define DSBPAN_LEFT                 -10000
#define DSBPAN_CENTER               0
#define DSBPAN_RIGHT                10000

#define DSBVOLUME_MIN               -10000
#define DSBVOLUME_MAX               0

#define DSBSIZE_MIN                 4
#define DSBSIZE_MAX                 0x0FFFFFFF
#define DSBSIZE_FX_MIN              150  // NOTE: Milliseconds, not bytes

#define DSBNOTIFICATIONS_MAX        100000

#define DS3DMODE_NORMAL             0x00000000
#define DS3DMODE_HEADRELATIVE       0x00000001
#define DS3DMODE_DISABLE            0x00000002

#define DS3D_IMMEDIATE              0x00000000
#define DS3D_DEFERRED               0x00000001

#define DS3D_MINDISTANCEFACTOR      FLT_MIN
#define DS3D_MAXDISTANCEFACTOR      FLT_MAX
#define DS3D_DEFAULTDISTANCEFACTOR  1.0

#define DS3D_MINROLLOFFFACTOR       0.0
#define DS3D_MAXROLLOFFFACTOR       10.0
#define DS3D_DEFAULTROLLOFFFACTOR   1.0

#define DS3D_MINDOPPLERFACTOR       0.0
#define DS3D_MAXDOPPLERFACTOR       10.0
#define DS3D_DEFAULTDOPPLERFACTOR   1.0

#define DS3D_DEFAULTMINDISTANCE     1.0
#define DS3D_DEFAULTMAXDISTANCE     1000000000.0

#define DS3D_MINCONEANGLE           0
#define DS3D_MAXCONEANGLE           360
#define DS3D_DEFAULTCONEANGLE       360

#define DS3D_DEFAULTCONEOUTSIDEVOLUME 0

// IDirectSoundCapture attributes

#define DSCCAPS_EMULDRIVER          0x00000020
#define DSCCAPS_CERTIFIED           0x00000040
#define DSCCAPS_MULTIPLECAPTURE     0x00000001

// IDirectSoundCaptureBuffer attributes

#define DSCBCAPS_WAVEMAPPED         0x80000000

#if DIRECTSOUND_VERSION >= 0x0800
#define DSCBCAPS_CTRLFX             0x00000200
#endif

#define DSCBLOCK_ENTIREBUFFER       0x00000001

#define DSCBSTATUS_CAPTURING        0x00000001
#define DSCBSTATUS_LOOPING          0x00000002

#define DSCBSTART_LOOPING           0x00000001

#define DSBPN_OFFSETSTOP            0xFFFFFFFF

#define DS_CERTIFIED                0x00000000
#define DS_UNCERTIFIED              0x00000001

DSFX_I3DL2_MATERIAL_PRESET_SINGLEWINDOW = 0
DSFX_I3DL2_MATERIAL_PRESET_DOUBLEWINDOW = 1
DSFX_I3DL2_MATERIAL_PRESET_THINDOOR = 2
DSFX_I3DL2_MATERIAL_PRESET_THICKDOOR = 3
DSFX_I3DL2_MATERIAL_PRESET_WOODWALL = 4
DSFX_I3DL2_MATERIAL_PRESET_BRICKWALL = 5
DSFX_I3DL2_MATERIAL_PRESET_STONEWALL = 6
DSFX_I3DL2_MATERIAL_PRESET_CURTAIN = 7

#define I3DL2_MATERIAL_PRESET_SINGLEWINDOW    -2800,0.71
#define I3DL2_MATERIAL_PRESET_DOUBLEWINDOW    -5000,0.40
#define I3DL2_MATERIAL_PRESET_THINDOOR        -1800,0.66
#define I3DL2_MATERIAL_PRESET_THICKDOOR       -4400,0.64
#define I3DL2_MATERIAL_PRESET_WOODWALL        -4000,0.50
#define I3DL2_MATERIAL_PRESET_BRICKWALL       -5000,0.60
#define I3DL2_MATERIAL_PRESET_STONEWALL       -6000,0.68
#define I3DL2_MATERIAL_PRESET_CURTAIN         -1200,0.15

DSFX_I3DL2_ENVIRONMENT_PRESET_DEFAULT = 0
DSFX_I3DL2_ENVIRONMENT_PRESET_GENERIC = 1
DSFX_I3DL2_ENVIRONMENT_PRESET_PADDEDCELL = 2
DSFX_I3DL2_ENVIRONMENT_PRESET_ROOM = 3
DSFX_I3DL2_ENVIRONMENT_PRESET_BATHROOM = 4
DSFX_I3DL2_ENVIRONMENT_PRESET_LIVINGROOM = 5
DSFX_I3DL2_ENVIRONMENT_PRESET_STONEROOM = 6
DSFX_I3DL2_ENVIRONMENT_PRESET_AUDITORIUM = 7
DSFX_I3DL2_ENVIRONMENT_PRESET_CONCERTHALL = 8
DSFX_I3DL2_ENVIRONMENT_PRESET_CAVE = 9
DSFX_I3DL2_ENVIRONMENT_PRESET_ARENA = 10
DSFX_I3DL2_ENVIRONMENT_PRESET_HANGAR = 11
DSFX_I3DL2_ENVIRONMENT_PRESET_CARPETEDHALLWAY = 12
DSFX_I3DL2_ENVIRONMENT_PRESET_HALLWAY = 13
DSFX_I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR = 14
DSFX_I3DL2_ENVIRONMENT_PRESET_ALLEY = 15
DSFX_I3DL2_ENVIRONMENT_PRESET_FOREST = 16
DSFX_I3DL2_ENVIRONMENT_PRESET_CITY = 17
DSFX_I3DL2_ENVIRONMENT_PRESET_MOUNTAINS = 18
DSFX_I3DL2_ENVIRONMENT_PRESET_QUARRY = 19
DSFX_I3DL2_ENVIRONMENT_PRESET_PLAIN = 20
DSFX_I3DL2_ENVIRONMENT_PRESET_PARKINGLOT = 21
DSFX_I3DL2_ENVIRONMENT_PRESET_SEWERPIPE = 22
DSFX_I3DL2_ENVIRONMENT_PRESET_UNDERWATER = 23
DSFX_I3DL2_ENVIRONMENT_PRESET_SMALLROOM = 24
DSFX_I3DL2_ENVIRONMENT_PRESET_MEDIUMROOM = 25
DSFX_I3DL2_ENVIRONMENT_PRESET_LARGEROOM = 26
DSFX_I3DL2_ENVIRONMENT_PRESET_MEDIUMHALL = 27
DSFX_I3DL2_ENVIRONMENT_PRESET_LARGEHALL = 28
DSFX_I3DL2_ENVIRONMENT_PRESET_PLATE = 29

#DEFINE I3DL2_ENVIRONMENT_PRESET_DEFAULT         -1000, -100, 0.0, 1.49, 0.83, -2602, 0.007,   200, 0.011, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_GENERIC         -1000, -100, 0.0, 1.49, 0.83, -2602, 0.007,   200, 0.011, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_PADDEDCELL      -1000,-6000, 0.0, 0.17, 0.10, -1204, 0.001,   207, 0.002, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_ROOM            -1000, -454, 0.0, 0.40, 0.83, -1646, 0.002,    53, 0.003, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_BATHROOM        -1000,-1200, 0.0, 1.49, 0.54,  -370, 0.007,  1030, 0.011, 100.0,  60.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_LIVINGROOM      -1000,-6000, 0.0, 0.50, 0.10, -1376, 0.003, -1104, 0.004, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_STONEROOM       -1000, -300, 0.0, 2.31, 0.64,  -711, 0.012,    83, 0.017, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_AUDITORIUM      -1000, -476, 0.0, 4.32, 0.59,  -789, 0.020,  -289, 0.030, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_CONCERTHALL     -1000, -500, 0.0, 3.92, 0.70, -1230, 0.020,    -2, 0.029, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_CAVE            -1000,    0, 0.0, 2.91, 1.30,  -602, 0.015,  -302, 0.022, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_ARENA           -1000, -698, 0.0, 7.24, 0.33, -1166, 0.020,    16, 0.030, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_HANGAR          -1000,-1000, 0.0,10.05, 0.23,  -602, 0.020,   198, 0.030, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_CARPETEDHALLWAY -1000,-4000, 0.0, 0.30, 0.10, -1831, 0.002, -1630, 0.030, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_HALLWAY         -1000, -300, 0.0, 1.49, 0.59, -1219, 0.007,   441, 0.011, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR   -1000, -237, 0.0, 2.70, 0.79, -1214, 0.013,   395, 0.020, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_ALLEY           -1000, -270, 0.0, 1.49, 0.86, -1204, 0.007,    -4, 0.011, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_FOREST          -1000,-3300, 0.0, 1.49, 0.54, -2560, 0.162,  -613, 0.088,  79.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_CITY            -1000, -800, 0.0, 1.49, 0.67, -2273, 0.007, -2217, 0.011,  50.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_MOUNTAINS       -1000,-2500, 0.0, 1.49, 0.21, -2780, 0.300, -2014, 0.100,  27.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_QUARRY          -1000,-1000, 0.0, 1.49, 0.83,-10000, 0.061,   500, 0.025, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_PLAIN           -1000,-2000, 0.0, 1.49, 0.50, -2466, 0.179, -2514, 0.100,  21.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_PARKINGLOT      -1000,    0, 0.0, 1.65, 1.50, -1363, 0.008, -1153, 0.012, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_SEWERPIPE       -1000,-1000, 0.0, 2.81, 0.14,   429, 0.014,   648, 0.021,  80.0,  60.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_UNDERWATER      -1000,-4000, 0.0, 1.49, 0.10,  -449, 0.007,  1700, 0.011, 100.0, 100.0, 5000.0

//
// Examples simulating 'musical' reverb presets
//
// Name       Decay time   Description
// Small Room    1.1s      A small size room with a length of 5m or so.
// Medium Room   1.3s      A medium size room with a length of 10m or so.
// Large Room    1.5s      A large size room suitable for live performances.
// Medium Hall   1.8s      A medium size concert hall.
// Large Hall    1.8s      A large size concert hall suitable for a full orchestra.
// Plate         1.3s      A plate reverb simulation.
//

#DEFINE I3DL2_ENVIRONMENT_PRESET_SMALLROOM       -1000, -600, 0.0, 1.10, 0.83,  -400, 0.005,   500, 0.010, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_MEDIUMROOM      -1000, -600, 0.0, 1.30, 0.83, -1000, 0.010,  -200, 0.020, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_LARGEROOM       -1000, -600, 0.0, 1.50, 0.83, -1600, 0.020, -1000, 0.040, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_MEDIUMHALL      -1000, -600, 0.0, 1.80, 0.70, -1300, 0.015,  -800, 0.030, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_LARGEHALL       -1000, -600, 0.0, 1.80, 0.70, -2000, 0.030, -1400, 0.060, 100.0, 100.0, 5000.0
#DEFINE I3DL2_ENVIRONMENT_PRESET_PLATE           -1000, -200, 0.0, 1.30, 0.90,     0, 0.002,     0, 0.010, 100.0,  75.0, 5000.0

//
// DirectSound3D Algorithms
//

// Default DirectSound3D algorithm {00000000-0000-0000-0000-000000000000}
#define DS3DALG_DEFAULT GUID_NULL

// No virtualization (Pan3D) {C241333F-1C1B-11d2-94F5-00C04FC28ACA}
#DEFINE GUID_DS3DALG_NO_VIRTUALIZATION <0xc241333f, 0x1c1b, 0x11d2, <0x94, 0xf5, 0x0, 0xc0, 0x4f, 0xc2, 0x8a, 0xca>>

// High-quality HRTF algorithm {C2413340-1C1B-11d2-94F5-00C04FC28ACA}
#DEFINE GUID_DS3DALG_HRTF_FULL <0xc2413340, 0x1c1b, 0x11d2, <0x94, 0xf5, 0x0, 0xc0, 0x4f, 0xc2, 0x8a, 0xca>>

// Lower-quality HRTF algorithm {C2413342-1C1B-11d2-94F5-00C04FC28ACA}
#DEFINE GUID_DS3DALG_HRTF_LIGHT <0xc2413342, 0x1c1b, 0x11d2, <0x94, 0xf5, 0x0, 0xc0, 0x4f, 0xc2, 0x8a, 0xca>>


#if DIRECTSOUND_VERSION >= 0x0800

//
// DirectSound Internal Effect Algorithms
//


// Gargle {DAFD8210-5711-4B91-9FE3-F75B7AE279BF}
#DEFINE GUID_DSFX_STANDARD_GARGLE <0xdafd8210, 0x5711, 0x4b91, <0x9f, 0xe3, 0xf7, 0x5b, 0x7a, 0xe2, 0x79, 0xbf>>

// Chorus {EFE6629C-81F7-4281-BD91-C9D604A95AF6}
#DEFINE GUID_DSFX_STANDARD_CHORUS <0xefe6629c, 0x81f7, 0x4281, <0xbd, 0x91, 0xc9, 0xd6, 0x04, 0xa9, 0x5a, 0xf6>>

// Flanger {EFCA3D92-DFD8-4672-A603-7420894BAD98}
#DEFINE GUID_DSFX_STANDARD_FLANGER <0xefca3d92, 0xdfd8, 0x4672, <0xa6, 0x03, 0x74, 0x20, 0x89, 0x4b, 0xad, 0x98>>

// Echo/Delay {EF3E932C-D40B-4F51-8CCF-3F98F1B29D5D}
#DEFINE GUID_DSFX_STANDARD_ECHO <0xef3e932c, 0xd40b, 0x4f51, <0x8c, 0xcf, 0x3f, 0x98, 0xf1, 0xb2, 0x9d, 0x5d>>

// Distortion {EF114C90-CD1D-484E-96E5-09CFAF912A21}
#DEFINE GUID_DSFX_STANDARD_DISTORTION <0xef114c90, 0xcd1d, 0x484e, <0x96, 0xe5, 0x09, 0xcf, 0xaf, 0x91, 0x2a, 0x21>>

// Compressor/Limiter {EF011F79-4000-406D-87AF-BFFB3FC39D57}
#DEFINE GUID_DSFX_STANDARD_COMPRESSOR <0xef011f79, 0x4000, 0x406d, <0x87, 0xaf, 0xbf, 0xfb, 0x3f, 0xc3, 0x9d, 0x57>>

// Parametric Equalization {120CED89-3BF4-4173-A132-3CB406CF3231}
#DEFINE GUID_DSFX_STANDARD_PARAMEQ <0x120ced89, 0x3bf4, 0x4173, <0xa1, 0x32, 0x3c, 0xb4, 0x06, 0xcf, 0x32, 0x31>>

// I3DL2 Environmental Reverberation: Reverb (Listener) Effect {EF985E71-D5C7-42D4-BA4D-2D073E2E96F4}
#DEFINE GUID_DSFX_STANDARD_I3DL2REVERB <0xef985e71, 0xd5c7, 0x42d4, <0xba, 0x4d, 0x2d, 0x07, 0x3e, 0x2e, 0x96, 0xf4>>

// Waves Reverberation {87FC0268-9A55-4360-95AA-004A1D9DE26C}
#DEFINE GUID_DSFX_WAVES_REVERB <0x87fc0268, 0x9a55, 0x4360, <0x95, 0xaa, 0x00, 0x4a, 0x1d, 0x9d, 0xe2, 0x6c>>

//
// DirectSound Capture Effect Algorithms
//


// Acoustic Echo Canceller {BF963D80-C559-11D0-8A2B-00A0C9255AC1}
// Matches KSNODETYPE_ACOUSTIC_ECHO_CANCEL in ksmedia.h
#DEFINE GUID_DSCFX_CLASS_AEC <0xBF963D80, 0xC559, 0x11D0, <0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1>>

// Microsoft AEC {CDEBB919-379A-488a-8765-F53CFD36DE40}
#DEFINE GUID_DSCFX_MS_AEC <0xcdebb919, 0x379a, 0x488a, <0x87, 0x65, 0xf5, 0x3c, 0xfd, 0x36, 0xde, 0x40>>

// System AEC {1C22C56D-9879-4f5b-A389-27996DDC2810}
#DEFINE GUID_DSCFX_SYSTEM_AEC <0x1c22c56d, 0x9879, 0x4f5b, <0xa3, 0x89, 0x27, 0x99, 0x6d, 0xdc, 0x28, 0x10>>

// Noise Supression {E07F903F-62FD-4e60-8CDD-DEA7236665B5}
// Matches KSNODETYPE_NOISE_SUPPRESS in post Windows ME DDK's ksmedia.h
#DEFINE GUID_DSCFX_CLASS_NS <0xe07f903f, 0x62fd, 0x4e60, <0x8c, 0xdd, 0xde, 0xa7, 0x23, 0x66, 0x65, 0xb5>>

// Microsoft Noise Suppresion {11C5C73B-66E9-4ba1-A0BA-E814C6EED92D}
#DEFINE GUID_DSCFX_MS_NS <0x11c5c73b, 0x66e9, 0x4ba1, <0xa0, 0xba, 0xe8, 0x14, 0xc6, 0xee, 0xd9, 0x2d>>

// System Noise Suppresion {5AB0882E-7274-4516-877D-4EEE99BA4FD0}
#DEFINE GUID_DSCFX_SYSTEM_NS <0x5ab0882e, 0x7274, 0x4516, <0x87, 0x7d, 0x4e, 0xee, 0x99, 0xba, 0x4f, 0xd0>>

#endif // DIRECTSOUND_VERSION >= 0x0800

#endif


