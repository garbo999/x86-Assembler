//------------------------------------------------------------------------------
// File: EDevDefs.h
//
// Desc: External Device (such as a VCR) control interface parameter and
//       value definitions.  
//
//       Note:  new constants added:  ED_BASE+800L -> ED_BASE+811L
//
// Copyright (c) 1992 - 2002, Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------


#ifndef EDEVDEFS_H
#define EDEVDEFS_H


#define ED_BASE		        		0x1000

// this is used to tell the device communications object which
// physical communications port to use.
#define DEV_PORT_SIM	1
#define DEV_PORT_COM1	2	// standard serial ports
#define DEV_PORT_COM2	3
#define DEV_PORT_COM3	4
#define DEV_PORT_COM4	5
#define DEV_PORT_DIAQ	6	// Diaquest driver
#define DEV_PORT_ARTI	7	// ARTI driver
#define DEV_PORT_1394	8	// IEEE 1394 Serial Bus
#define DEV_PORT_USB	9	// Universal Serial Bus
#define DEV_PORT_MIN	DEV_PORT_SIM
#define DEV_PORT_MAX	DEV_PORT_USB


//	IAMExtDevice Capability Items:  unless otherwise specified, these items return 
//	   OATRUE or OAFALSE.  All return values are in pdwValue unless otherwise specified:

#define ED_DEVCAP_CAN_RECORD			ED_BASE+1
#define ED_DEVCAP_CAN_RECORD_STROBE		ED_BASE+2	// for multitrack devices: 
													// switches currently recording tracks off 
													// and selected non-recording tracks into record
#define ED_DEVCAP_HAS_AUDIO			ED_BASE+3
#define ED_DEVCAP_HAS_VIDEO			ED_BASE+4
#define ED_DEVCAP_USES_FILES		ED_BASE+5
#define ED_DEVCAP_CAN_SAVE			ED_BASE+6

#define ED_DEVCAP_DEVICE_TYPE		ED_BASE+7	// returns one of the following:
#define ED_DEVTYPE_VCR				ED_BASE+8
#define ED_DEVTYPE_LASERDISK		ED_BASE+9
#define ED_DEVTYPE_ATR 				ED_BASE+10
#define ED_DEVTYPE_DDR				ED_BASE+11
#define ED_DEVTYPE_ROUTER 			ED_BASE+12
#define ED_DEVTYPE_KEYER 			ED_BASE+13
#define ED_DEVTYPE_MIXER_VIDEO 		ED_BASE+14
#define ED_DEVTYPE_DVE 				ED_BASE+15
#define ED_DEVTYPE_WIPEGEN 			ED_BASE+16
#define ED_DEVTYPE_MIXER_AUDIO 		ED_BASE+17
#define ED_DEVTYPE_CG 				ED_BASE+18
#define ED_DEVTYPE_TBC 				ED_BASE+19
#define ED_DEVTYPE_TCG 				ED_BASE+20
#define ED_DEVTYPE_GPI 				ED_BASE+21
#define ED_DEVTYPE_JOYSTICK 		ED_BASE+22
#define ED_DEVTYPE_KEYBOARD			ED_BASE+23

// returns mfr-specific ID from external device.
#define ED_DEVCAP_EXTERNAL_DEVICE_ID	ED_BASE+24

#define ED_DEVCAP_TIMECODE_READ		ED_BASE+25
#define ED_DEVCAP_TIMECODE_WRITE	ED_BASE+26
//	used for seekable non-timecode enabled devices
#define ED_DEVCAP_CTLTRK_READ		ED_BASE+27
//	used for seekable non-timecode enabled devices
#define ED_DEVCAP_INDEX_READ		ED_BASE+28

// returns device preroll time in current time format
#define ED_DEVCAP_PREROLL			ED_BASE+29
// returns device postroll time in current time format
#define ED_DEVCAP_POSTROLL			ED_BASE+30

// returns indication of device's synchronization accuracy.
#define ED_DEVCAP_SYNC_ACCURACY		ED_BASE+31	// returns one of the following:
#define ED_SYNCACC_PRECISE			ED_BASE+32
#define ED_SYNCACC_FRAME			ED_BASE+33
#define ED_SYNCACC_ROUGH			ED_BASE+34

// returns device's normal framerate.
#define ED_DEVCAP_NORMAL_RATE	ED_BASE+35	// returns one of the following:
#define ED_RATE_24				ED_BASE+36
#define ED_RATE_25				ED_BASE+37
#define ED_RATE_2997			ED_BASE+38
#define ED_RATE_30				ED_BASE+39

#define ED_DEVCAP_CAN_PREVIEW	ED_BASE+40
#define ED_DEVCAP_CAN_MONITOR_SOURCES	ED_BASE+41

// indicates implementation allows testing of methods/parameters by
// setting the hi bit of a parm that makes sense - see individual methods
// for details.
#define ED_DEVCAP_CAN_TEST			ED_BASE+42
	
// indicates device accepts video as an input.
#define ED_DEVCAP_VIDEO_INPUTS		ED_BASE+43

// indicates device accepts audio as an input.
#define ED_DEVCAP_AUDIO_INPUTS		ED_BASE+44

#define ED_DEVCAP_NEEDS_CALIBRATING	ED_BASE+45

#define ED_DEVCAP_SEEK_TYPE			ED_BASE+46	// returns one of the following:
#define ED_SEEK_PERFECT				ED_BASE+47	// indicates device can execute seek 
												// within 1 video frames without signal 
												//	break (like a DDR)
#define ED_SEEK_FAST				ED_BASE+48	// indicates device can move pretty quick 
												//  with short break in signal
#define ED_SEEK_SLOW				ED_BASE+49	// seeks like a tape transport

#define ED_POWER_ON					ED_BASE+50
#define ED_POWER_OFF				ED_BASE+51
#define ED_POWER_STANDBY			ED_BASE+52

#define ED_ACTIVE					ED_BASE+53
#define ED_INACTIVE 				ED_BASE+54
#define ED_ALL						ED_BASE+55
#define ED_TEST						ED_BASE+56

//	IAMExtTransport Capability Items:  unless otherwise specified, these items return 
//	   OATRUE or OAFALSE.  All return values are in pdwValue unless otherwise specified:

#define ED_TRANSCAP_CAN_EJECT			ED_BASE+100
#define ED_TRANSCAP_CAN_BUMP_PLAY		ED_BASE+101	// variable speed for synchronizing
#define ED_TRANSCAP_CAN_PLAY_BACKWARDS	ED_BASE+102	// servo locked for use during an edit
#define ED_TRANSCAP_CAN_SET_EE			ED_BASE+103	// show device's input on its output
#define ED_TRANSCAP_CAN_SET_PB			ED_BASE+104	// show media playback on device's output
#define ED_TRANSCAP_CAN_DELAY_VIDEO_IN	ED_BASE+105	// transport can do delayed-in video edits
#define ED_TRANSCAP_CAN_DELAY_VIDEO_OUT	ED_BASE+106	// transport can do delayed-out video edits
#define ED_TRANSCAP_CAN_DELAY_AUDIO_IN	ED_BASE+107	// transport can do delayed-in audio edits
#define ED_TRANSCAP_CAN_DELAY_AUDIO_OUT	ED_BASE+108	// transport can do delayed-out audio edits
#define ED_TRANSCAP_FWD_VARIABLE_MAX	ED_BASE+109	// max forward speed (multiple of play speed) 
														//  in pdblValue
#define ED_TRANSCAP_FWD_VARIABLE_MIN	ED_BASE+800	// min forward speed (multiple of play speed) 
														//  in pdblValue
#define ED_TRANSCAP_REV_VARIABLE_MAX	ED_BASE+110	// max reverse speed (multiple of play speed) in
														//  pdblValue
#define ED_TRANSCAP_REV_VARIABLE_MIN	ED_BASE+801	// min reverse speed (multiple of play speed)
														//  in pdblValue
#define ED_TRANSCAP_FWD_SHUTTLE_MAX		ED_BASE+802	// max forward speed in Shuttle mode (multiple
														//  of play speed) in pdblValue
#define ED_TRANSCAP_FWD_SHUTTLE_MIN		ED_BASE+803	// min forward speed in Shuttle mode (multiple
														//  of play speed) in pdblValue
#define ED_TRANSCAP_REV_SHUTTLE_MAX		ED_BASE+804	// max reverse speed in Shuttle mode (multiple
														//  of play speed) in pdblValue
#define ED_TRANSCAP_REV_SHUTTLE_MIN		ED_BASE+805	// min reverse speed in Shuttle mode (multiple
														//  of play speed) in pdblValue
#define ED_TRANSCAP_NUM_AUDIO_TRACKS	ED_BASE+111	// returns number of audio tracks
#define ED_TRANSCAP_LTC_TRACK			ED_BASE+112	// returns track number of LTC timecode track.
														//  ED_ALL means no dedicated timecode track
#define ED_TRANSCAP_NEEDS_TBC			ED_BASE+113	// device's output not stable
#define ED_TRANSCAP_NEEDS_CUEING		ED_BASE+114	// device must be cued prior to performing edit
#define ED_TRANSCAP_CAN_INSERT			ED_BASE+115
#define ED_TRANSCAP_CAN_ASSEMBLE		ED_BASE+116
#define ED_TRANSCAP_FIELD_STEP			ED_BASE+117	// device responds to Frame Advance command by 
														//  advancing one field
#define ED_TRANSCAP_CLOCK_INC_RATE		ED_BASE+118	// VISCA command - keep for compatibility
#define ED_TRANSCAP_CAN_DETECT_LENGTH	ED_BASE+119
#define ED_TRANSCAP_CAN_FREEZE			ED_BASE+120
#define ED_TRANSCAP_HAS_TUNER			ED_BASE+121
#define ED_TRANSCAP_HAS_TIMER			ED_BASE+122
#define ED_TRANSCAP_HAS_CLOCK			ED_BASE+123
#define ED_TRANSCAP_MULTIPLE_EDITS		ED_BASE+806	// OATRUE means device/filter can support
														//  multiple edit events
#define ED_TRANSCAP_IS_MASTER			ED_BASE+807	// OATRUE means device is the master clock
														//  for synchronizing (this sets timecode-to-
														//  reference clock offset for editing)
#define ED_TRANSCAP_HAS_DT				ED_BASE+814	// OATRUE means device has Dynamic Tracking

//	IAMExtTransport Media States
#define ED_MEDIA_SPIN_UP			ED_BASE+130
#define ED_MEDIA_SPIN_DOWN			ED_BASE+131
#define ED_MEDIA_UNLOAD				ED_BASE+132

//	IAMExtTransport Modes
#define	ED_MODE_PLAY				ED_BASE+200
#define	ED_MODE_STOP				ED_BASE+201
#define	ED_MODE_FREEZE				ED_BASE+202	// really "pause"
#define	ED_MODE_THAW				ED_BASE+203
#define	ED_MODE_FF					ED_BASE+204
#define	ED_MODE_REW					ED_BASE+205
#define	ED_MODE_RECORD				ED_BASE+206
#define	ED_MODE_RECORD_STROBE		ED_BASE+207
#define ED_MODE_RECORD_FREEZE		ED_BASE+808   // pause recording	
#define	ED_MODE_STEP				ED_BASE+208	// same as "jog"
#define	ED_MODE_STEP_FWD			ED_BASE+208	// same as ED_MODE_STEP
#define	ED_MODE_STEP_REV			ED_BASE+809
#define	ED_MODE_SHUTTLE				ED_BASE+209
#define	ED_MODE_EDIT_CUE			ED_BASE+210
#define ED_MODE_VAR_SPEED			ED_BASE+211
#define ED_MODE_PERFORM				ED_BASE+212	// returned status only
#define	ED_MODE_LINK_ON				ED_BASE+280
#define	ED_MODE_LINK_OFF			ED_BASE+281
#define ED_MODE_NOTIFY_ENABLE		ED_BASE+810
#define ED_MODE_NOTIFY_DISABLE		ED_BASE+811
#define ED_MODE_SHOT_SEARCH			ED_BASE+812

//	IAMTimecodeReader/Generator/Display defines
//
// Timecode Generator Mode params and values:
//
#define ED_TCG_TIMECODE_TYPE		ED_BASE+400	// can be one of the following:
#define ED_TCG_SMPTE_LTC			ED_BASE+401
#define ED_TCG_SMPTE_VITC			ED_BASE+402
#define ED_TCG_MIDI_QF				ED_BASE+403
#define ED_TCG_MIDI_FULL			ED_BASE+404

#define ED_TCG_FRAMERATE			ED_BASE+405	// can be one of the following:
#define ED_FORMAT_SMPTE_30			ED_BASE+406
#define ED_FORMAT_SMPTE_30DROP		ED_BASE+407
#define ED_FORMAT_SMPTE_25			ED_BASE+408
#define ED_FORMAT_SMPTE_24			ED_BASE+409

#define ED_TCG_SYNC_SOURCE			ED_BASE+410	// can be one of the following:
#define ED_TCG_VIDEO				ED_BASE+411
#define ED_TCG_READER				ED_BASE+412
#define ED_TCG_FREE					ED_BASE+413

#define ED_TCG_REFERENCE_SOURCE		ED_BASE+414	// can have one these values:
													//	ED_TCG_FREE || ED_TCG_READER 
													//	(for regen/jamsync)

// TimeCodeReader Mode params and values:
#define ED_TCR_SOURCE			ED_BASE+416	// can be one of the following:
// ED_TCG (already defined)
#define ED_TCR_LTC				ED_BASE+417
#define ED_TCR_VITC				ED_BASE+418
#define ED_TCR_CT				ED_BASE+419	// Control Track
#define ED_TCR_FTC				ED_BASE+420	// File TimeCode - for file-based devices
												//  that wish they were transports
// ED_MODE_NOTIFY_ENABLE can be OATRUE or OAFALSE (defined in transport mode
//  section of this file).  
#define ED_TCR_LAST_VALUE		ED_BASE+421	// for notification mode - 
												//  successive calls to GetTimecode
												//  return the last read value
// TimeCode Display Mode params and values:
//
#define ED_TCD_SOURCE			ED_BASE+422	// can be one of the following:
#define ED_TCR					ED_BASE+423
#define ED_TCG					ED_BASE+424

#define ED_TCD_SIZE				ED_BASE+425	// can be one of the following:
#define ED_SMALL				ED_BASE+426
#define ED_MED					ED_BASE+427
#define ED_LARGE				ED_BASE+428

#define ED_TCD_POSITION			ED_BASE+429	// can be one of the following:
#define ED_TOP					0x0001
#define ED_MIDDLE				0x0002
#define ED_BOTTOM				0x0004			// or'd  with
#define ED_LEFT					0x0100
#define ED_CENTER				0x0200
#define ED_RIGHT				0x0400

#define ED_TCD_INTENSITY		ED_BASE+436	// can be one of the following:
#define ED_HIGH					ED_BASE+437
#define ED_LOW					ED_BASE+438

#define ED_TCD_TRANSPARENCY		ED_BASE+439	// 0-4, 0 is opaque

#define ED_TCD_INVERT			ED_BASE+440	// OATRUE=black on white
												// OAFALSE=white on black
//	IAMExtTransport defines
//
// Transport status, params and values
//

// IAMExtTransport Status items and and values:
#define ED_MODE					ED_BASE+500	// see ED_MODE_xxx values above
#define	ED_ERROR				ED_BASE+501
#define	ED_LOCAL				ED_BASE+502
#define	ED_RECORD_INHIBIT		ED_BASE+503
#define	ED_SERVO_LOCK			ED_BASE+504
#define	ED_MEDIA_PRESENT		ED_BASE+505
#define	ED_MEDIA_LENGTH			ED_BASE+506
#define	ED_MEDIA_SIZE			ED_BASE+507
#define	ED_MEDIA_TRACK_COUNT	ED_BASE+508
#define	ED_MEDIA_TRACK_LENGTH	ED_BASE+509
#define	ED_MEDIA_SIDE			ED_BASE+510

#define	ED_MEDIA_TYPE			ED_BASE+511	// can be one of the following:
#define	ED_MEDIA_VHS			ED_BASE+512
#define	ED_MEDIA_SVHS			ED_BASE+513
#define	ED_MEDIA_HI8			ED_BASE+514
#define	ED_MEDIA_UMATIC			ED_BASE+515
#define	ED_MEDIA_DVC			ED_BASE+516
#define	ED_MEDIA_1_INCH			ED_BASE+517
#define	ED_MEDIA_D1				ED_BASE+518
#define	ED_MEDIA_D2				ED_BASE+519
#define	ED_MEDIA_D3				ED_BASE+520
#define	ED_MEDIA_D5				ED_BASE+521
#define	ED_MEDIA_DBETA			ED_BASE+522
#define	ED_MEDIA_BETA			ED_BASE+523
#define	ED_MEDIA_8MM			ED_BASE+524
#define	ED_MEDIA_DDR			ED_BASE+525
#define	ED_MEDIA_SX				ED_BASE+813
#define	ED_MEDIA_OTHER			ED_BASE+526
#define	ED_MEDIA_CLV			ED_BASE+527
#define	ED_MEDIA_CAV			ED_BASE+528
#define ED_MEDIA_POSITION		ED_BASE+529

#define ED_LINK_MODE			ED_BASE+530	// OATRUE if transport controls
							 					// are linked to graph's RUN, 
							 					// STOP, and PAUSE methods

// IAMExtTransport Basic Parms
#define	ED_TRANSBASIC_TIME_FORMAT	ED_BASE+540	// can be one of the following:
#define	ED_FORMAT_MILLISECONDS		ED_BASE+541
#define	ED_FORMAT_FRAMES			ED_BASE+542
#define ED_FORMAT_REFERENCE_TIME	ED_BASE+543

#define	ED_FORMAT_HMSF				ED_BASE+547
#define	ED_FORMAT_TMSF				ED_BASE+548

#define	ED_TRANSBASIC_TIME_REFERENCE	ED_BASE+549	// can be one of the following:
#define	ED_TIMEREF_TIMECODE			ED_BASE+550
#define	ED_TIMEREF_CONTROL_TRACK	ED_BASE+551
#define	ED_TIMEREF_INDEX			ED_BASE+552

#define	ED_TRANSBASIC_SUPERIMPOSE		ED_BASE+553	// enable/disable onscreen display
#define	ED_TRANSBASIC_END_STOP_ACTION	ED_BASE+554	// can be one of: ED_MODE_STOP |
														//	ED_MODE_REWIND | ED_MODE_FREEZE
#define	ED_TRANSBASIC_RECORD_FORMAT	ED_BASE+555	// can be one of the following:
#define	ED_RECORD_FORMAT_SP			ED_BASE+556
#define	ED_RECORD_FORMAT_LP			ED_BASE+557
#define	ED_RECORD_FORMAT_EP			ED_BASE+558

#define	ED_TRANSBASIC_STEP_COUNT	ED_BASE+559
#define	ED_TRANSBASIC_STEP_UNIT		ED_BASE+560	// can be one of the following:
#define	ED_STEP_FIELD				ED_BASE+561
#define	ED_STEP_FRAME				ED_BASE+562
#define	ED_STEP_3_2					ED_BASE+563

#define	ED_TRANSBASIC_PREROLL		ED_BASE+564
#define	ED_TRANSBASIC_RECPREROLL	ED_BASE+565
#define	ED_TRANSBASIC_POSTROLL		ED_BASE+566
#define	ED_TRANSBASIC_EDIT_DELAY	ED_BASE+567
#define	ED_TRANSBASIC_PLAYTC_DELAY	ED_BASE+568
#define	ED_TRANSBASIC_RECTC_DELAY	ED_BASE+569
#define ED_TRANSBASIC_EDIT_FIELD	ED_BASE+570
#define	ED_TRANSBASIC_FRAME_SERVO	ED_BASE+571
#define	ED_TRANSBASIC_CF_SERVO		ED_BASE+572
#define	ED_TRANSBASIC_SERVO_REF		ED_BASE+573	// can be one of the following:
#define	ED_REF_EXTERNAL				ED_BASE+574
#define	ED_REF_INPUT				ED_BASE+575
#define	ED_REF_INTERNAL				ED_BASE+576
#define	ED_REF_AUTO					ED_BASE+577

#define	ED_TRANSBASIC_WARN_GL		ED_BASE+578
#define	ED_TRANSBASIC_SET_TRACKING	ED_BASE+579	// can be one of the following:
#define	ED_TRACKING_PLUS			ED_BASE+580
#define	ED_TRACKING_MINUS			ED_BASE+581
#define	ED_TRACKING_RESET			ED_BASE+582

#define	ED_TRANSBASIC_SET_FREEZE_TIMEOUT	ED_BASE+583
#define	ED_TRANSBASIC_VOLUME_NAME		ED_BASE+584
#define	ED_TRANSBASIC_BALLISTIC_1		ED_BASE+585	// space for proprietary data
#define	ED_TRANSBASIC_BALLISTIC_2		ED_BASE+586
#define	ED_TRANSBASIC_BALLISTIC_3		ED_BASE+587
#define	ED_TRANSBASIC_BALLISTIC_4		ED_BASE+588
#define	ED_TRANSBASIC_BALLISTIC_5		ED_BASE+589
#define	ED_TRANSBASIC_BALLISTIC_6		ED_BASE+590
#define	ED_TRANSBASIC_BALLISTIC_7		ED_BASE+591
#define	ED_TRANSBASIC_BALLISTIC_8		ED_BASE+592
#define	ED_TRANSBASIC_BALLISTIC_9		ED_BASE+593
#define	ED_TRANSBASIC_BALLISTIC_10		ED_BASE+594
#define	ED_TRANSBASIC_BALLISTIC_11		ED_BASE+595
#define	ED_TRANSBASIC_BALLISTIC_12		ED_BASE+596
#define	ED_TRANSBASIC_BALLISTIC_13		ED_BASE+597
#define	ED_TRANSBASIC_BALLISTIC_14		ED_BASE+598
#define	ED_TRANSBASIC_BALLISTIC_15		ED_BASE+599
#define	ED_TRANSBASIC_BALLISTIC_16		ED_BASE+600
#define	ED_TRANSBASIC_BALLISTIC_17		ED_BASE+601
#define	ED_TRANSBASIC_BALLISTIC_18		ED_BASE+602
#define	ED_TRANSBASIC_BALLISTIC_19		ED_BASE+603
#define	ED_TRANSBASIC_BALLISTIC_20		ED_BASE+604

// consumer VCR items
#define	ED_TRANSBASIC_SETCLOCK			ED_BASE+605
#define	ED_TRANSBASIC_SET_COUNTER_FORMAT	ED_BASE+606	// uses time format flags
#define	ED_TRANSBASIC_SET_COUNTER_VALUE	ED_BASE+607

#define	ED_TRANSBASIC_SETTUNER_CH_UP	ED_BASE+608
#define	ED_TRANSBASIC_SETTUNER_CH_DN	ED_BASE+609
#define	ED_TRANSBASIC_SETTUNER_SK_UP	ED_BASE+610
#define	ED_TRANSBASIC_SETTUNER_SK_DN	ED_BASE+611
#define	ED_TRANSBASIC_SETTUNER_CH		ED_BASE+612
#define	ED_TRANSBASIC_SETTUNER_NUM		ED_BASE+613

#define	ED_TRANSBASIC_SETTIMER_EVENT	ED_BASE+614
#define	ED_TRANSBASIC_SETTIMER_STARTDAY	ED_BASE+615
#define	ED_TRANSBASIC_SETTIMER_STARTTIME	ED_BASE+616
#define	ED_TRANSBASIC_SETTIMER_STOPDAY	ED_BASE+617
#define	ED_TRANSBASIC_SETTIMER_STOPTIME	ED_BASE+618

// IAMExtTransport video parameters
#define	ED_TRANSVIDEO_SET_OUTPUT	ED_BASE+630	// can be one of the following:
#define	ED_E2E						ED_BASE+631
#define	ED_PLAYBACK					ED_BASE+632
#define	ED_OFF						ED_BASE+633

#define	ED_TRANSVIDEO_SET_SOURCE	ED_BASE+634

// IAMExtTransport audio parameters
#define	ED_TRANSAUDIO_ENABLE_OUTPUT	ED_BASE+640	// can be the following:
#define	ED_AUDIO_ALL				0x10000000	//	or any of the following OR'd together
#define ED_AUDIO_1					0x0000001
#define ED_AUDIO_2					0x0000002
#define ED_AUDIO_3					0x0000004
#define ED_AUDIO_4					0x0000008
#define ED_AUDIO_5					0x0000010
#define ED_AUDIO_6					0x0000020
#define ED_AUDIO_7					0x0000040
#define ED_AUDIO_8					0x0000080
#define ED_AUDIO_9					0x0000100
#define ED_AUDIO_10					0x0000200
#define ED_AUDIO_11					0x0000400
#define ED_AUDIO_12					0x0000800
#define ED_AUDIO_13					0x0001000
#define ED_AUDIO_14					0x0002000
#define ED_AUDIO_15					0x0004000
#define ED_AUDIO_16					0x0008000
#define ED_AUDIO_17					0x0010000
#define ED_AUDIO_18					0x0020000
#define ED_AUDIO_19					0x0040000
#define ED_AUDIO_20					0x0080000
#define ED_AUDIO_21					0x0100000
#define ED_AUDIO_22					0x0200000
#define ED_AUDIO_23					0x0400000
#define ED_AUDIO_24					0x0800000
#define ED_VIDEO					0x2000000	// for Edit props below

#define	ED_TRANSAUDIO_ENABLE_RECORD		ED_BASE+642
#define	ED_TRANSAUDIO_ENABLE_SELSYNC	ED_BASE+643
#define	ED_TRANSAUDIO_SET_SOURCE		ED_BASE+644
#define	ED_TRANSAUDIO_SET_MONITOR		ED_BASE+645


// Edit Property Set-related defs

// The following values reflect (and control) the state of an 
// edit property set
#define ED_INVALID		ED_BASE+652
#define ED_EXECUTING	ED_BASE+653
#define ED_REGISTER		ED_BASE+654
#define ED_DELETE		ED_BASE+655

// Edit property set parameters and values
#define ED_EDIT_HEVENT	ED_BASE+656	// event handle to signal event 
										// completion
#define ED_EDIT_TEST	ED_BASE+657	// returns OAFALSE if filter thinks
										//  edit can be done, OATRUE if not
#define ED_EDIT_IMMEDIATE	ED_BASE+658	// OATRUE means start put the 
										// device into edit mode (editing
										// "on the fly") immediately upon
										//  execution of Mode(ED_MODE_EDIT_CUE)
#define ED_EDIT_MODE	ED_BASE+659L
// can be one of the following values:
#define ED_EDIT_MODE_ASSEMBLE		ED_BASE+660
#define ED_EDIT_MODE_INSERT			ED_BASE+661
#define ED_EDIT_MODE_CRASH_RECORD	ED_BASE+662
#define ED_EDIT_MODE_BOOKMARK_TIME	ED_BASE+663		// these two are for
#define ED_EDIT_MODE_BOOKMARK_CHAPTER	ED_BASE+664	// laserdisks

#define ED_EDIT_MASTER	ED_BASE+666	// OATRUE causes device 
										//  not to synchronize

#define ED_EDIT_TRACK		ED_BASE+667
// can be one of the following possible OR'd values:
//	ED_VIDEO, ED_AUDIO_1 thru ED_AUDIO_24 (or ED_AUDIO_ALL)

#define ED_EDIT_SRC_INPOINT		ED_BASE+668	// in current time format
#define ED_EDIT_SRC_OUTPOINT	ED_BASE+669	// in current time format
#define ED_EDIT_REC_INPOINT		ED_BASE+670	// in current time format
#define ED_EDIT_REC_OUTPOINT	ED_BASE+671	// in current time format

#define ED_EDIT_REHEARSE_MODE	ED_BASE+672
// can be one of the following possible values:
#define ED_EDIT_BVB		ED_BASE+673	// means rehearse the edit with 
										//  "black-video-black"
#define ED_EDIT_VBV		ED_BASE+674
#define ED_EDIT_VVV		ED_BASE+675
#define ED_EDIT_PERFORM	ED_BASE+676	// means perform the edit with no 
										//  rehearsal.

// Set this property to OATRUE to kill the edit if in progress
#define ED_EDIT_ABORT	ED_BASE+677
// how long to wait for edit to complete
#define ED_EDIT_TIMEOUT	ED_BASE+678		// in current time format

// This property causes the device to seek to a point specified by
// ED_EDIT_SEEK_MODE (see below).  NOTE: Only one event at a time can seek.
#define ED_EDIT_SEEK		ED_BASE+679	// OATRUE means do it now.  
#define ED_EDIT_SEEK_MODE	ED_BASE+680
//possible values:
#define ED_EDIT_SEEK_EDIT_IN	ED_BASE+681	// seek to edit's inpoint
#define ED_EDIT_SEEK_EDIT_OUT	ED_BASE+682	// seek to edit's outpoint
#define ED_EDIT_SEEK_PREROLL	ED_BASE+683	// seek to edit's 
												//  inpoint-preroll
#define ED_EDIT_SEEK_PREROLL_CT	ED_BASE+684	// seek to preroll point 
							// using control track (used for tapes with 
							// discontinuoustimecode before edit point: seek
							// to inpoint using timecode, then backup to 
							// preroll point using control track)
#define ED_EDIT_SEEK_BOOKMARK	ED_BASE+685	// seek to bookmark (just like 
												//  timecode search)
// This property is used for multiple-VCR systems where each machine must
//  cue to a different location relative to the graph's reference clock.  The
//  basic idea is that an edit event is setup with an ED_EDIT_OFFSET property
//  that tells the VCR what offset to maintain between it's timecode (converted
//	to reference clock units) and the reference clock.
#define ED_EDIT_OFFSET	ED_BASE+686		// in current time format

#define ED_EDIT_PREREAD	ED_BASE+815		// OATRUE means device supports
											//  pre-read (recorder can also be
											//  player

//
// Some error codes:
// 
// device could be in local mode
#define ED_ERR_DEVICE_NOT_READY		ED_BASE+700

#endif // EDEVDEFS_H

