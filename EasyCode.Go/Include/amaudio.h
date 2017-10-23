//------------------------------------------------------------------------------
// File: AMAudio.h
//
// Desc: Audio related definitions and interfaces for ActiveMovie.
//
// Copyright (c) 1992 - 2001, Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------


#ifndef AMAUDIO_H
#define AMAUDIO_H

#include "mmsystem.h"
#include "dsound.h"

// This is the interface the audio renderer supports to give the application
// access to the direct sound object and buffers it is using, to allow the
// application to use things like the 3D features of Direct Sound for the
// soundtrack of a movie being played with Active Movie

// be nice to our friends in C

IAMDirectSound STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDirectSoundInterface PTR
	GetPrimaryBufferInterface PTR
	GetSecondaryBufferInterface PTR
	ReleaseDirectSoundInterface PTR
	ReleasePrimaryBufferInterface PTR
	ReleaseSecondaryBufferInterface PTR
	SetFocusWindow PTR
	GetFocusWindow PTR
ENDS

#endif // __AMAUDIO__


