 // no longer used  - but might get
 // our own facility in the future?
 // FacilityNames=(FACILITY_VFW=0x4)
 // To add a message:
 //
 // The MessageId is the number of the message.
 // Accepted severities are 'Success' and 'Warning'.
 //
 // Facility should be FACILITY_ITF (was FACILITY_VFW).
 //
 // The SymbolicName is the name used in the code to identify the message.
 // The text of a message starts the line after 'Language=' and
 // ends before a line with only a '.' in column one.
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: VFW_E_INVALIDMEDIATYPE
//
// MessageText:
//
// An invalid media type was specified.%0
//
#IFNDEF VFWMSGS_H
#DEFINE VFWMSGS_H

#define VFW_E_INVALIDMEDIATYPE           0x80040200

//
// MessageId: VFW_E_INVALIDSUBTYPE
//
// MessageText:
//
// An invalid media subtype was specified.%0
//
#define VFW_E_INVALIDSUBTYPE             0x80040201

//
// MessageId: VFW_E_NEED_OWNER
//
// MessageText:
//
// This object can only be created as an aggregated object.%0
//
#define VFW_E_NEED_OWNER                 0x80040202

//
// MessageId: VFW_E_ENUM_OUT_OF_SYNC
//
// MessageText:
//
// The enumerator has become invalid.%0
//
#define VFW_E_ENUM_OUT_OF_SYNC           0x80040203

//
// MessageId: VFW_E_ALREADY_CONNECTED
//
// MessageText:
//
// At least one of the pins involved in the operation is already connected.%0
//
#define VFW_E_ALREADY_CONNECTED          0x80040204

//
// MessageId: VFW_E_FILTER_ACTIVE
//
// MessageText:
//
// This operation cannot be performed because the filter is active.%0
//
#define VFW_E_FILTER_ACTIVE              0x80040205

//
// MessageId: VFW_E_NO_TYPES
//
// MessageText:
//
// One of the specified pins supports no media types.%0
//
#define VFW_E_NO_TYPES                   0x80040206

//
// MessageId: VFW_E_NO_ACCEPTABLE_TYPES
//
// MessageText:
//
// There is no common media type between these pins.%0
//
#define VFW_E_NO_ACCEPTABLE_TYPES        0x80040207

//
// MessageId: VFW_E_INVALID_DIRECTION
//
// MessageText:
//
// Two pins of the same direction cannot be connected together.%0
//
#define VFW_E_INVALID_DIRECTION          0x80040208

//
// MessageId: VFW_E_NOT_CONNECTED
//
// MessageText:
//
// The operation cannot be performed because the pins are not connected.%0
//
#define VFW_E_NOT_CONNECTED              0x80040209

//
// MessageId: VFW_E_NO_ALLOCATOR
//
// MessageText:
//
// No sample buffer allocator is available.%0
//
#define VFW_E_NO_ALLOCATOR               0x8004020A

//
// MessageId: VFW_E_RUNTIME_ERROR
//
// MessageText:
//
// A run-time error occurred.%0
//
#define VFW_E_RUNTIME_ERROR              0x8004020B

//
// MessageId: VFW_E_BUFFER_NOTSET
//
// MessageText:
//
// No buffer space has been set.%0
//
#define VFW_E_BUFFER_NOTSET              0x8004020C

//
// MessageId: VFW_E_BUFFER_OVERFLOW
//
// MessageText:
//
// The buffer is not big enough.%0
//
#define VFW_E_BUFFER_OVERFLOW            0x8004020D

//
// MessageId: VFW_E_BADALIGN
//
// MessageText:
//
// An invalid alignment was specified.%0
//
#define VFW_E_BADALIGN                   0x8004020E

//
// MessageId: VFW_E_ALREADY_COMMITTED
//
// MessageText:
//
// Cannot change allocated memory while the filter is active.%0
//
#define VFW_E_ALREADY_COMMITTED          0x8004020F

//
// MessageId: VFW_E_BUFFERS_OUTSTANDING
//
// MessageText:
//
// One or more buffers are still active.%0
//
#define VFW_E_BUFFERS_OUTSTANDING        0x80040210

//
// MessageId: VFW_E_NOT_COMMITTED
//
// MessageText:
//
// Cannot allocate a sample when the allocator is not active.%0
//
#define VFW_E_NOT_COMMITTED              0x80040211

//
// MessageId: VFW_E_SIZENOTSET
//
// MessageText:
//
// Cannot allocate memory because no size has been set.%0
//
#define VFW_E_SIZENOTSET                 0x80040212

//
// MessageId: VFW_E_NO_CLOCK
//
// MessageText:
//
// Cannot lock for synchronization because no clock has been defined.%0
//
#define VFW_E_NO_CLOCK                   0x80040213

//
// MessageId: VFW_E_NO_SINK
//
// MessageText:
//
// Quality messages could not be sent because no quality sink has been defined.%0
//
#define VFW_E_NO_SINK                    0x80040214

//
// MessageId: VFW_E_NO_INTERFACE
//
// MessageText:
//
// A required interface has not been implemented.%0
//
#define VFW_E_NO_INTERFACE               0x80040215

//
// MessageId: VFW_E_NOT_FOUND
//
// MessageText:
//
// An object or name was not found.%0
//
#define VFW_E_NOT_FOUND                  0x80040216

//
// MessageId: VFW_E_CANNOT_CONNECT
//
// MessageText:
//
// No combination of intermediate filters could be found to make the connection.%0
//
#define VFW_E_CANNOT_CONNECT             0x80040217

//
// MessageId: VFW_E_CANNOT_RENDER
//
// MessageText:
//
// No combination of filters could be found to render the stream.%0
//
#define VFW_E_CANNOT_RENDER              0x80040218

//
// MessageId: VFW_E_CHANGING_FORMAT
//
// MessageText:
//
// Could not change formats dynamically.%0
//
#define VFW_E_CHANGING_FORMAT            0x80040219

//
// MessageId: VFW_E_NO_COLOR_KEY_SET
//
// MessageText:
//
// No color key has been set.%0
//
#define VFW_E_NO_COLOR_KEY_SET           0x8004021A

//
// MessageId: VFW_E_NOT_OVERLAY_CONNECTION
//
// MessageText:
//
// Current pin connection is not using the IOverlay transport.%0
//
#define VFW_E_NOT_OVERLAY_CONNECTION     0x8004021B

//
// MessageId: VFW_E_NOT_SAMPLE_CONNECTION
//
// MessageText:
//
// Current pin connection is not using the IMemInputPin transport.%0
//
#define VFW_E_NOT_SAMPLE_CONNECTION      0x8004021C

//
// MessageId: VFW_E_PALETTE_SET
//
// MessageText:
//
// Setting a color key would conflict with the palette already set.%0
//
#define VFW_E_PALETTE_SET                0x8004021D

//
// MessageId: VFW_E_COLOR_KEY_SET
//
// MessageText:
//
// Setting a palette would conflict with the color key already set.%0
//
#define VFW_E_COLOR_KEY_SET              0x8004021E

//
// MessageId: VFW_E_NO_COLOR_KEY_FOUND
//
// MessageText:
//
// No matching color key is available.%0
//
#define VFW_E_NO_COLOR_KEY_FOUND         0x8004021F

//
// MessageId: VFW_E_NO_PALETTE_AVAILABLE
//
// MessageText:
//
// No palette is available.%0
//
#define VFW_E_NO_PALETTE_AVAILABLE       0x80040220

//
// MessageId: VFW_E_NO_DISPLAY_PALETTE
//
// MessageText:
//
// Display does not use a palette.%0
//
#define VFW_E_NO_DISPLAY_PALETTE         0x80040221

//
// MessageId: VFW_E_TOO_MANY_COLORS
//
// MessageText:
//
// Too many colors for the current display settings.%0
//
#define VFW_E_TOO_MANY_COLORS            0x80040222

//
// MessageId: VFW_E_STATE_CHANGED
//
// MessageText:
//
// The state changed while waiting to process the sample.%0
//
#define VFW_E_STATE_CHANGED              0x80040223

//
// MessageId: VFW_E_NOT_STOPPED
//
// MessageText:
//
// The operation could not be performed because the filter is not stopped.%0
//
#define VFW_E_NOT_STOPPED                0x80040224

//
// MessageId: VFW_E_NOT_PAUSED
//
// MessageText:
//
// The operation could not be performed because the filter is not paused.%0
//
#define VFW_E_NOT_PAUSED                 0x80040225

//
// MessageId: VFW_E_NOT_RUNNING
//
// MessageText:
//
// The operation could not be performed because the filter is not running.%0
//
#define VFW_E_NOT_RUNNING                0x80040226

//
// MessageId: VFW_E_WRONG_STATE
//
// MessageText:
//
// The operation could not be performed because the filter is in the wrong state.%0
//
#define VFW_E_WRONG_STATE                0x80040227

//
// MessageId: VFW_E_START_TIME_AFTER_END
//
// MessageText:
//
// The sample start time is after the sample end time.%0
//
#define VFW_E_START_TIME_AFTER_END       0x80040228

//
// MessageId: VFW_E_INVALID_RECT
//
// MessageText:
//
// The supplied rectangle is invalid.%0
//
#define VFW_E_INVALID_RECT               0x80040229

//
// MessageId: VFW_E_TYPE_NOT_ACCEPTED
//
// MessageText:
//
// This pin cannot use the supplied media type.%0
//
#define VFW_E_TYPE_NOT_ACCEPTED          0x8004022A

//
// MessageId: VFW_E_SAMPLE_REJECTED
//
// MessageText:
//
// This sample cannot be rendered.%0
//
#define VFW_E_SAMPLE_REJECTED            0x8004022B

//
// MessageId: VFW_E_SAMPLE_REJECTED_EOS
//
// MessageText:
//
// This sample cannot be rendered because the end of the stream has been reached.%0
//
#define VFW_E_SAMPLE_REJECTED_EOS        0x8004022C

//
// MessageId: VFW_E_DUPLICATE_NAME
//
// MessageText:
//
// An attempt to add a filter with a duplicate name failed.%0
//
#define VFW_E_DUPLICATE_NAME             0x8004022D

//
// MessageId: VFW_S_DUPLICATE_NAME
//
// MessageText:
//
// An attempt to add a filter with a duplicate name succeeded with a modified name.%0
//
#define VFW_S_DUPLICATE_NAME             0x0004022D

//
// MessageId: VFW_E_TIMEOUT
//
// MessageText:
//
// A time-out has expired.%0
//
#define VFW_E_TIMEOUT                    0x8004022E

//
// MessageId: VFW_E_INVALID_FILE_FORMAT
//
// MessageText:
//
// The file format is invalid.%0
//
#define VFW_E_INVALID_FILE_FORMAT        0x8004022F

//
// MessageId: VFW_E_ENUM_OUT_OF_RANGE
//
// MessageText:
//
// The list has already been exhausted.%0
//
#define VFW_E_ENUM_OUT_OF_RANGE          0x80040230

//
// MessageId: VFW_E_CIRCULAR_GRAPH
//
// MessageText:
//
// The filter graph is circular.%0
//
#define VFW_E_CIRCULAR_GRAPH             0x80040231

//
// MessageId: VFW_E_NOT_ALLOWED_TO_SAVE
//
// MessageText:
//
// Updates are not allowed in this state.%0
//
#define VFW_E_NOT_ALLOWED_TO_SAVE        0x80040232

//
// MessageId: VFW_E_TIME_ALREADY_PASSED
//
// MessageText:
//
// An attempt was made to queue a command for a time in the past.%0
//
#define VFW_E_TIME_ALREADY_PASSED        0x80040233

//
// MessageId: VFW_E_ALREADY_CANCELLED
//
// MessageText:
//
// The queued command has already been canceled.%0
//
#define VFW_E_ALREADY_CANCELLED          0x80040234

//
// MessageId: VFW_E_CORRUPT_GRAPH_FILE
//
// MessageText:
//
// Cannot render the file because it is corrupt.%0
//
#define VFW_E_CORRUPT_GRAPH_FILE         0x80040235

//
// MessageId: VFW_E_ADVISE_ALREADY_SET
//
// MessageText:
//
// An overlay advise link already exists.%0
//
#define VFW_E_ADVISE_ALREADY_SET         0x80040236

//
// MessageId: VFW_S_STATE_INTERMEDIATE
//
// MessageText:
//
// The state transition has not completed.%0
//
#define VFW_S_STATE_INTERMEDIATE         0x00040237

//
// MessageId: VFW_E_NO_MODEX_AVAILABLE
//
// MessageText:
//
// No full-screen modes are available.%0
//
#define VFW_E_NO_MODEX_AVAILABLE         0x80040238

//
// MessageId: VFW_E_NO_ADVISE_SET
//
// MessageText:
//
// This Advise cannot be canceled because it was not successfully set.%0
//
#define VFW_E_NO_ADVISE_SET              0x80040239

//
// MessageId: VFW_E_NO_FULLSCREEN
//
// MessageText:
//
// A full-screen mode is not available.%0
//
#define VFW_E_NO_FULLSCREEN              0x8004023A

//
// MessageId: VFW_E_IN_FULLSCREEN_MODE
//
// MessageText:
//
// Cannot call IVideoWindow methods while in full-screen mode.%0
//
#define VFW_E_IN_FULLSCREEN_MODE         0x8004023B

//
// MessageId: VFW_E_UNKNOWN_FILE_TYPE
//
// MessageText:
//
// The media type of this file is not recognized.%0
//
#define VFW_E_UNKNOWN_FILE_TYPE          0x80040240

//
// MessageId: VFW_E_CANNOT_LOAD_SOURCE_FILTER
//
// MessageText:
//
// The source filter for this file could not be loaded.%0
//
#define VFW_E_CANNOT_LOAD_SOURCE_FILTER  0x80040241

//
// MessageId: VFW_S_PARTIAL_RENDER
//
// MessageText:
//
// Some of the streams in this movie are in an unsupported format.%0
//
#define VFW_S_PARTIAL_RENDER             0x00040242

//
// MessageId: VFW_E_FILE_TOO_SHORT
//
// MessageText:
//
// A file appeared to be incomplete.%0
//
#define VFW_E_FILE_TOO_SHORT             0x80040243

//
// MessageId: VFW_E_INVALID_FILE_VERSION
//
// MessageText:
//
// The version number of the file is invalid.%0
//
#define VFW_E_INVALID_FILE_VERSION       0x80040244

//
// MessageId: VFW_S_SOME_DATA_IGNORED
//
// MessageText:
//
// The file contained some property settings that were not used.%0
//
#define VFW_S_SOME_DATA_IGNORED          0x00040245

//
// MessageId: VFW_S_CONNECTIONS_DEFERRED
//
// MessageText:
//
// Some connections have failed and have been deferred.%0
//
#define VFW_S_CONNECTIONS_DEFERRED       0x00040246

//
// MessageId: VFW_E_INVALID_CLSID
//
// MessageText:
//
// This file is corrupt: it contains an invalid class identifier.%0
//
#define VFW_E_INVALID_CLSID              0x80040247

//
// MessageId: VFW_E_INVALID_MEDIA_TYPE
//
// MessageText:
//
// This file is corrupt: it contains an invalid media type.%0
//
#define VFW_E_INVALID_MEDIA_TYPE         0x80040248

 // Message id from WINWarning.H
//
// MessageId: VFW_E_BAD_KEY
//
// MessageText:
//
// A registry entry is corrupt.%0
//
#define VFW_E_BAD_KEY                    0x800403F2

 // Message id from WINWarning.H
//
// MessageId: VFW_S_NO_MORE_ITEMS
//
// MessageText:
//
// The end of the list has been reached.%0
//
#define VFW_S_NO_MORE_ITEMS              0x00040103

//
// MessageId: VFW_E_SAMPLE_TIME_NOT_SET
//
// MessageText:
//
// No time stamp has been set for this sample.%0
//
#define VFW_E_SAMPLE_TIME_NOT_SET        0x80040249

//
// MessageId: VFW_S_RESOURCE_NOT_NEEDED
//
// MessageText:
//
// The resource specified is no longer needed.%0
//
#define VFW_S_RESOURCE_NOT_NEEDED        0x00040250

//
// MessageId: VFW_E_MEDIA_TIME_NOT_SET
//
// MessageText:
//
// No media time stamp has been set for this sample.%0
//
#define VFW_E_MEDIA_TIME_NOT_SET         0x80040251

//
// MessageId: VFW_E_NO_TIME_FORMAT_SET
//
// MessageText:
//
// No media time format has been selected.%0
//
#define VFW_E_NO_TIME_FORMAT_SET         0x80040252

//
// MessageId: VFW_E_MONO_AUDIO_HW
//
// MessageText:
//
// Cannot change balance because audio device is mono only.%0
//
#define VFW_E_MONO_AUDIO_HW              0x80040253

//
// MessageId: VFW_S_MEDIA_TYPE_IGNORED
//
// MessageText:
//
// A connection could not be made with the media type in the persistent graph,%0
// but has been made with a negotiated media type.%0
//
#define VFW_S_MEDIA_TYPE_IGNORED         0x00040254

//
// MessageId: VFW_E_NO_DECOMPRESSOR
//
// MessageText:
//
// Cannot play back the video stream: no suitable decompressor could be found.%0
//
#define VFW_E_NO_DECOMPRESSOR            0x80040255

//
// MessageId: VFW_E_NO_AUDIO_HARDWARE
//
// MessageText:
//
// Cannot play back the audio stream: no audio hardware is available, or the hardware is not responding.%0
//
#define VFW_E_NO_AUDIO_HARDWARE          0x80040256

//
// MessageId: VFW_S_VIDEO_NOT_RENDERED
//
// MessageText:
//
// Cannot play back the video stream: no suitable decompressor could be found.%0
//
#define VFW_S_VIDEO_NOT_RENDERED         0x00040257

//
// MessageId: VFW_S_AUDIO_NOT_RENDERED
//
// MessageText:
//
// Cannot play back the audio stream: no audio hardware is available.%0
//
#define VFW_S_AUDIO_NOT_RENDERED         0x00040258

//
// MessageId: VFW_E_RPZA
//
// MessageText:
//
// Cannot play back the video stream: format 'RPZA' is not supported.%0
//
#define VFW_E_RPZA                       0x80040259

//
// MessageId: VFW_S_RPZA
//
// MessageText:
//
// Cannot play back the video stream: format 'RPZA' is not supported.%0
//
#define VFW_S_RPZA                       0x0004025A

//
// MessageId: VFW_E_PROCESSOR_NOT_SUITABLE
//
// MessageText:
//
// ActiveMovie cannot play MPEG movies on this processor.%0
//
#define VFW_E_PROCESSOR_NOT_SUITABLE     0x8004025B

//
// MessageId: VFW_E_UNSUPPORTED_AUDIO
//
// MessageText:
//
// Cannot play back the audio stream: the audio format is not supported.%0
//
#define VFW_E_UNSUPPORTED_AUDIO          0x8004025C

//
// MessageId: VFW_E_UNSUPPORTED_VIDEO
//
// MessageText:
//
// Cannot play back the video stream: the video format is not supported.%0
//
#define VFW_E_UNSUPPORTED_VIDEO          0x8004025D

//
// MessageId: VFW_E_MPEG_NOT_CONSTRAINED
//
// MessageText:
//
// ActiveMovie cannot play this video stream because it falls outside the constrained standard.%0
//
#define VFW_E_MPEG_NOT_CONSTRAINED       0x8004025E

//
// MessageId: VFW_E_NOT_IN_GRAPH
//
// MessageText:
//
// Cannot perform the requested function on an object that is not in the filter graph.%0
//
#define VFW_E_NOT_IN_GRAPH               0x8004025F

//
// MessageId: VFW_S_ESTIMATED
//
// MessageText:
//
// The value returned had to be estimated.  It's accuracy can not be guaranteed.%0
//
#define VFW_S_ESTIMATED                  0x00040260

//
// MessageId: VFW_E_NO_TIME_FORMAT
//
// MessageText:
//
// Cannot get or set time related information on an object that is using a time format of TIME_FORMAT_NONE.%0
//
#define VFW_E_NO_TIME_FORMAT             0x80040261

//
// MessageId: VFW_E_READ_ONLY
//
// MessageText:
//
// The connection cannot be made because the stream is read only and the filter alters the data.%0
//
#define VFW_E_READ_ONLY                  0x80040262

//
// MessageId: VFW_S_RESERVED
//
// MessageText:
//
// This success code is reserved for internal purposes within ActiveMovie.%0
//
#define VFW_S_RESERVED                   0x00040263

//
// MessageId: VFW_E_BUFFER_UNDERFLOW
//
// MessageText:
//
// The buffer is not full enough.%0
//
#define VFW_E_BUFFER_UNDERFLOW           0x80040264

//
// MessageId: VFW_E_UNSUPPORTED_STREAM
//
// MessageText:
//
// Cannot play back the file.  The format is not supported.%0
//
#define VFW_E_UNSUPPORTED_STREAM         0x80040265

//
// MessageId: VFW_E_NO_TRANSPORT
//
// MessageText:
//
// Pins cannot connect due to not supporting the same transport.%0
//
#define VFW_E_NO_TRANSPORT               0x80040266

//
// MessageId: VFW_S_STREAM_OFF
//
// MessageText:
//
// The stream has been turned off.%0
//
#define VFW_S_STREAM_OFF                 0x00040267

//
// MessageId: VFW_S_CANT_CUE
//
// MessageText:
//
// The graph can't be cued because of lack of or corrupt data.%0
//
#define VFW_S_CANT_CUE                   0x00040268

//
// MessageId: VFW_E_BAD_VIDEOCD
//
// MessageText:
//
// The Video CD can't be read correctly by the device or is the data is corrupt.%0
//
#define VFW_E_BAD_VIDEOCD                0x80040269

//
// MessageId: VFW_S_NO_STOP_TIME
//
// MessageText:
//
// The stop time for the sample was not set.%0
//
#define VFW_S_NO_STOP_TIME               0x00040270

//
// MessageId: VFW_E_OUT_OF_VIDEO_MEMORY
//
// MessageText:
//
// There is not enough Video Memory at this display resolution and number of colors. Reducing resolution might help.%0
//
#define VFW_E_OUT_OF_VIDEO_MEMORY        0x80040271

//
// MessageId: VFW_E_VP_NEGOTIATION_FAILED
//
// MessageText:
//
// The VideoPort connection negotiation process has failed.%0
//
#define VFW_E_VP_NEGOTIATION_FAILED      0x80040272

//
// MessageId: VFW_E_DDRAW_CAPS_NOT_SUITABLE
//
// MessageText:
//
// Either DirectDraw has not been installed or the Video Card capabilities are not suitable. Make sure the display is not in 16 color mode or try changing the graphics mode.%0
//
#define VFW_E_DDRAW_CAPS_NOT_SUITABLE    0x80040273

//
// MessageId: VFW_E_NO_VP_HARDWARE
//
// MessageText:
//
// No VideoPort hardware is available, or the hardware is not responding.%0
//
#define VFW_E_NO_VP_HARDWARE             0x80040274

//
// MessageId: VFW_E_NO_CAPTURE_HARDWARE
//
// MessageText:
//
// No Capture hardware is available, or the hardware is not responding.%0
//
#define VFW_E_NO_CAPTURE_HARDWARE        0x80040275

//
// MessageId: VFW_E_DVD_OPERATION_INHIBITED
//
// MessageText:
//
// This User Operation is inhibited by DVD Content at this time.%0
//
#define VFW_E_DVD_OPERATION_INHIBITED    0x80040276

//
// MessageId: VFW_E_DVD_INVALIDDOMAIN
//
// MessageText:
//
// This Operation is not permitted in the current domain.%0
//
#define VFW_E_DVD_INVALIDDOMAIN          0x80040277

//
// MessageId: VFW_E_DVD_NO_BUTTON
//
// MessageText:
//
// The specified button is invalid or is not present at the current time, or there is no button present at the specified location.%0
//
#define VFW_E_DVD_NO_BUTTON              0x80040278

//
// MessageId: VFW_E_DVD_GRAPHNOTREADY
//
// MessageText:
//
// DVD-Video playback graph has not been built yet.%0
//
#define VFW_E_DVD_GRAPHNOTREADY          0x80040279

//
// MessageId: VFW_E_DVD_RENDERFAIL
//
// MessageText:
//
// DVD-Video playback graph building failed.%0
//
#define VFW_E_DVD_RENDERFAIL             0x8004027A

//
// MessageId: VFW_E_DVD_DECNOTENOUGH
//
// MessageText:
//
// DVD-Video playback graph could not be built due to insufficient decoders.%0
//
#define VFW_E_DVD_DECNOTENOUGH           0x8004027B

//
// MessageId: VFW_E_DDRAW_VERSION_NOT_SUITABLE
//
// MessageText:
//
// Version number of DirectDraw not suitable. Make sure to install dx5 or higher version.%0
//
#define VFW_E_DDRAW_VERSION_NOT_SUITABLE 0x8004027C

//
// MessageId: VFW_E_COPYPROT_FAILED
//
// MessageText:
//
// Copy protection cannot be enabled. Please make sure any other copy protected content is not being shown now.%0
//
#define VFW_E_COPYPROT_FAILED            0x8004027D

//
// MessageId: VFW_S_NOPREVIEWPIN
//
// MessageText:
//
// There was no preview pin available, so the capture pin output is being split to provide both capture and preview.%0
//
#define VFW_S_NOPREVIEWPIN               0x0004027E

//
// MessageId: VFW_E_TIME_EXPIRED
//
// MessageText:
//
// This object cannot be used anymore as its time has expired.%0
//
#define VFW_E_TIME_EXPIRED               0x8004027F

//
// MessageId: VFW_S_DVD_NON_ONE_SEQUENTIAL
//
// MessageText:
//
// The current title was not a sequential set of chapters (PGC), and the returned timing information might not be continuous.%0
//
#define VFW_S_DVD_NON_ONE_SEQUENTIAL     0x00040280

//
// MessageId: VFW_E_DVD_WRONG_SPEED
//
// MessageText:
//
// The operation cannot be performed at the current playback speed.%0
//
#define VFW_E_DVD_WRONG_SPEED            0x80040281

//
// MessageId: VFW_E_DVD_MENU_DOES_NOT_EXIST
//
// MessageText:
//
// The specified menu doesn't exist.%0
//
#define VFW_E_DVD_MENU_DOES_NOT_EXIST    0x80040282

//
// MessageId: VFW_E_DVD_CMD_CANCELLED
//
// MessageText:
//
// The specified command was either cancelled or no longer exists.%0
//
#define VFW_E_DVD_CMD_CANCELLED          0x80040283

//
// MessageId: VFW_E_DVD_STATE_WRONG_VERSION
//
// MessageText:
//
// The data did not contain a recognized version.%0
//
#define VFW_E_DVD_STATE_WRONG_VERSION    0x80040284

//
// MessageId: VFW_E_DVD_STATE_CORRUPT
//
// MessageText:
//
// The state data was corrupt.%0
//
#define VFW_E_DVD_STATE_CORRUPT          0x80040285

//
// MessageId: VFW_E_DVD_STATE_WRONG_DISC
//
// MessageText:
//
// The state data is from a different disc.%0
//
#define VFW_E_DVD_STATE_WRONG_DISC       0x80040286

//
// MessageId: VFW_E_DVD_INCOMPATIBLE_REGION
//
// MessageText:
//
// The region was not compatible with the current drive.%0
//
#define VFW_E_DVD_INCOMPATIBLE_REGION    0x80040287

//
// MessageId: VFW_E_DVD_NO_ATTRIBUTES
//
// MessageText:
//
// The requested DVD stream attribute does not exist.%0
//
#define VFW_E_DVD_NO_ATTRIBUTES          0x80040288

//
// MessageId: VFW_E_DVD_NO_GOUP_PGC
//
// MessageText:
//
// Currently there is no GoUp (Annex J user function) program chain (PGC).%0
//
#define VFW_E_DVD_NO_GOUP_PGC            0x80040289

//
// MessageId: VFW_E_DVD_LOW_PARENTAL_LEVEL
//
// MessageText:
//
// The current parental level was too low.%0
//
#define VFW_E_DVD_LOW_PARENTAL_LEVEL     0x8004028A

//
// MessageId: VFW_E_DVD_NOT_IN_KARAOKE_MODE
//
// MessageText:
//
// The current audio is not karaoke content.%0
//
#define VFW_E_DVD_NOT_IN_KARAOKE_MODE    0x8004028B

//
// MessageId: VFW_S_DVD_CHANNEL_CONTENTS_NOT_AVAILABLE
//
// MessageText:
//
// The audio stream did not contain sufficient information to determine the contents of each channel.%0
//
#define VFW_S_DVD_CHANNEL_CONTENTS_NOT_AVAILABLE 0x0004028C

//
// MessageId: VFW_S_DVD_NOT_ACCURATE
//
// MessageText:
//
// The seek into the movie was not frame accurate.%0
//
#define VFW_S_DVD_NOT_ACCURATE           0x0004028D

//
// MessageId: VFW_E_FRAME_STEP_UNSUPPORTED
//
// MessageText:
//
// Frame step is not supported on this configuration.%0
//
#define VFW_E_FRAME_STEP_UNSUPPORTED     0x8004028E

//
// MessageId: VFW_E_DVD_STREAM_DISABLED
//
// MessageText:
//
// The specified stream is disabled and cannot be selected.%0
//
#define VFW_E_DVD_STREAM_DISABLED        0x8004028F

//
// MessageId: VFW_E_DVD_TITLE_UNKNOWN
//
// MessageText:
//
// The operation depends on the current title number, however the navigator has not yet entered the VTSM or the title domains,
// so the 'current' title index is unknown.%0
//
#define VFW_E_DVD_TITLE_UNKNOWN          0x80040290

//
// MessageId: VFW_E_DVD_INVALID_DISC
//
// MessageText:
//
// The specified path does not point to a valid DVD disc.%0
//
#define VFW_E_DVD_INVALID_DISC           0x80040291

//
// MessageId: VFW_E_DVD_NO_RESUME_INFORMATION
//
// MessageText:
//
// There is currently no resume information.%0
//
#define VFW_E_DVD_NO_RESUME_INFORMATION  0x80040292

//
// MessageId: VFW_E_PIN_ALREADY_BLOCKED_ON_THIS_THREAD
//
// MessageText:
//
// This thread has already blocked this output pin.  There is no need to call IPinFlowControl::Block() again.%0
//
#define VFW_E_PIN_ALREADY_BLOCKED_ON_THIS_THREAD 0x80040293

//
// MessageId: VFW_E_PIN_ALREADY_BLOCKED
//
// MessageText:
//
// IPinFlowControl::Block() has been called on another thread.  The current thread cannot make any assumptions about this pin's block state.%0
//
#define VFW_E_PIN_ALREADY_BLOCKED        0x80040294

//
// MessageId: VFW_E_CERTIFICATION_FAILURE
//
// MessageText:
//
// An operation failed due to a certification failure.%0
//
#define VFW_E_CERTIFICATION_FAILURE      0x80040295

//
// MessageId: VFW_E_VMR_NOT_IN_MIXER_MODE
//
// MessageText:
//
// The VMR has not yet created a mixing component.  That is, IVMRFilterConfig::SetNumberofStreams has not yet been called.%0
//
#define VFW_E_VMR_NOT_IN_MIXER_MODE      0x80040296

//
// MessageId: VFW_E_VMR_NO_AP_SUPPLIED
//
// MessageText:
//
// The application has not yet provided the VMR filter with a valid allocator-presenter object.%0
//
#define VFW_E_VMR_NO_AP_SUPPLIED         0x80040297

//
// MessageId: VFW_E_VMR_NO_DEINTERLACE_HW
//
// MessageText:
//
// The VMR could not find any de-interlacing hardware on the current display device.%0
//
#define VFW_E_VMR_NO_DEINTERLACE_HW      0x80040298

//
// MessageId: VFW_E_VMR_NO_PROCAMP_HW
//
// MessageText:
//
// The VMR could not find any ProcAmp hardware on the current display device.%0
//
#define VFW_E_VMR_NO_PROCAMP_HW          0x80040299

//
// MessageId: VFW_E_DVD_VMR9_INCOMPATIBLEDEC
//
// MessageText:
//
// VMR9 does not work with VPE-based hardware decoders.%0
//
#define VFW_E_DVD_VMR9_INCOMPATIBLEDEC   0x8004029A

//
// MessageId: VFW_E_VMR_NO_AP_SUPPLIED
//
// MessageText:
//
//  The application has not yet provided the VMR filter with a valid allocator-presenter object.%0
//
#define VFW_E_VMR_NO_AP_SUPPLIED         0x80040297
//
// MessageId: VFW_E_VMR_NO_DEINTERLACE_HW
//
// MessageText:
//
//  The VMR could not find any de-interlacing hardware on the current display device.%0
//
#define VFW_E_VMR_NO_DEINTERLACE_HW      0x80040298
//
// MessageId: VFW_E_VMR_NO_PROCAMP_HW
//
// MessageText:
//
//  The VMR could not find any ProcAmp hardware on the current display device.%0
//
#define VFW_E_VMR_NO_PROCAMP_HW          0x80040299
//
// MessageId: VFW_E_DVD_VMR9_INCOMPATIBLEDEC
//
// MessageText:
//
//  VMR9 does not work with VPE-based hardware decoders.%0
//
#define VFW_E_DVD_VMR9_INCOMPATIBLEDEC   0x8004029A
//
// MessageId: VFW_E_NO_COPP_HW
//
// MessageText:
//
//  The current display device does not support Content Output Protection Protocol (COPP) H/W.%0
//
#define VFW_E_NO_COPP_HW   0x8004029B
//
// MessageId: VFW_E_DVD_NONBLOCKING
//
// MessageText:
//
//  Nonblocking APIs are enabled and the nav cannot perform the operation at this time (IDVDContro or partially incomplete information may be returned (DVDInfo).%0
//
#define VFW_E_DVD_NONBLOCKING 0x8004029C
//
// MessageId: VFW_E_DVD_TOO_MANY_RENDERERS_IN_FILTER_GRAPH
//
// MessageText:
//
// The DVD Graph Builder cannot build a DVD playback filter graph if the EVR and another renderer are in the graph builder's filter graph.
//
#define VFW_E_DVD_TOO_MANY_RENDERERS_IN_FILTER_GRAPH 0x8004029D

//
// MessageId: VFW_E_DVD_NON_EVR_RENDERER_IN_FILTER_GRAPH
//
// MessageText:
//
// AM_DVD_EVR_ONLY cannot be passed to RenderDvdVideoVolume if the graph builder's filter graph contains a renderer which is not the EVR.
//
#define VFW_E_DVD_NON_EVR_RENDERER_IN_FILTER_GRAPH 0x8004029E

//
// MessageId: VFW_E_DVD_RESOLUTION_ERROR
//
// MessageText:
//
// DVD Video Output is not at a proper resolution.
//
#define VFW_E_DVD_RESOLUTION_ERROR       0x8004029F

//
//
// E_PROP_SET_UNSUPPORTED and E_PROP_ID_UNSUPPORTED are added here using
// HRESULT_FROM_WIN32() because VC5 doesn't have WinNT's new error codes
// from winerror.h, and because it is more convienent to have them already
// formed as HRESULTs.  These should correspond to:
//     HRESULT_FROM_WIN32(ERROR_NOT_FOUND)     == E_PROP_ID_UNSUPPORTED
//     HRESULT_FROM_WIN32(ERROR_SET_NOT_FOUND) == E_PROP_SET_UNSUPPORTED
#if !defined(E_PROP_SET_UNSUPPORTED)
//
// MessageId: E_PROP_SET_UNSUPPORTED
//
// MessageText:
//
// The Specified property set is not supported.%0
//
#define E_PROP_SET_UNSUPPORTED           0x80070492

#endif //!defined(E_PROP_SET_UNSUPPORTED)
#if !defined(E_PROP_ID_UNSUPPORTED)
//
// MessageId: E_PROP_ID_UNSUPPORTED
//
// MessageText:
//
// The specified property ID is not supported for the specified property set.%0
//
#define E_PROP_ID_UNSUPPORTED            0x80070490

#endif //!defined(E_PROP_ID_UNSUPPORTED)
//
// MessageId: VFW_E_CODECAPI_LINEAR_RANGE
//
// MessageText:
//
// Parameter has linear range.%0
//
#define VFW_E_CODECAPI_LINEAR_RANGE      0x80040310

//
// MessageId: VFW_E_CODECAPI_ENUMERATED
//
// MessageText:
//
// Parameter is enumerated. It has no range.%0
//
#define VFW_E_CODECAPI_ENUMERATED        0x80040311

//
// MessageId: VFW_E_CODECAPI_NO_DEFAULT
//
// MessageText:
//
// No default value.%0
//
#define VFW_E_CODECAPI_NO_DEFAULT        0x80040313

//
// MessageId: VFW_E_CODECAPI_NO_CURRENT_VALUE
//
// MessageText:
//
// No current value.%0
//
#define VFW_E_CODECAPI_NO_CURRENT_VALUE  0x80040314

//
// MessageId: VFW_E_DVD_CHAPTER_DOES_NOT_EXIST
//
// MessageText:
//
// The operation failed since the chapter does not exist.%0
//
#define VFW_E_DVD_CHAPTER_DOES_NOT_EXIST 0x80040315

#ENDIF

