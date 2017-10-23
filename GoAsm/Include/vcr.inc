;=============================================================;
;            vcr.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF VCR_INC
#Define VCR_INC

#Define MCI_VCR_OFFSET                      1280

#Define MCI_LIST                            00878H
#Define MCI_SETAUDIO                        00873H
#Define MCI_SETVIDEO                        00876H
#Define MCI_SIGNAL                          00875H

#Define MCI_MARK                            (MCI_USER_MESSAGES + 0)
#Define MCI_INDEX                           (MCI_USER_MESSAGES + 1)
#Define MCI_SETTUNER                        (MCI_USER_MESSAGES + 2)
#Define MCI_SETVCR                          (MCI_USER_MESSAGES + 3)
#Define MCI_SETTIMECODE                     (MCI_USER_MESSAGES + 4)

#Define MCI_TEST                            0x00000020L

#Define MCI_VCR_GETDEVCAPS_CAN_DETECT_LENGTH    000004001H
#Define MCI_VCR_GETDEVCAPS_SEEK_ACCURACY        000004002H
#Define MCI_VCR_GETDEVCAPS_HAS_CLOCK            000004003H
#Define MCI_VCR_GETDEVCAPS_CAN_REVERSE          000004004H
#Define MCI_VCR_GETDEVCAPS_NUMBER_OF_MARKS      000004005H
#Define MCI_VCR_GETDEVCAPS_CAN_TEST             000004006H
#Define MCI_VCR_GETDEVCAPS_CAN_PREROLL          000004007H
#Define MCI_VCR_GETDEVCAPS_CAN_PREVIEW          000004008H
#Define MCI_VCR_GETDEVCAPS_CAN_MONITOR_SOURCES  000004009H
#Define MCI_VCR_GETDEVCAPS_HAS_TIMECODE         00000400AH
#Define MCI_VCR_GETDEVCAPS_CAN_FREEZE           00000401BH
#Define MCI_VCR_GETDEVCAPS_CLOCK_INCREMENT_RATE 00000401CH

#Define MCI_VCR_INFO_VERSION                    000010000H

#Define MCI_VCR_PLAY_REVERSE                    000010000H
#Define MCI_VCR_PLAY_AT                         000020000H
#Define MCI_VCR_PLAY_SCAN                       000040000H

#Define MCI_VCR_RECORD_INITIALIZE               000010000H
#Define MCI_VCR_RECORD_AT                       000020000H
#Define MCI_VCR_RECORD_PREVIEW                  000040000H

#Define MCI_VCR_CUE_INPUT                       000010000H
#Define MCI_VCR_CUE_OUTPUT                      000020000H
#Define MCI_VCR_CUE_PREROLL                     000040000H
#Define MCI_VCR_CUE_REVERSE                     000080000H

#Define MCI_VCR_SEEK_REVERSE                    000010000H
#Define MCI_VCR_SEEK_MARK                       000020000H
#Define MCI_VCR_SEEK_AT                         000040000H
                                               
#Define MCI_VCR_SETTUNER_CHANNEL                000010000H
#Define MCI_VCR_SETTUNER_CHANNEL_UP             000020000H
#Define MCI_VCR_SETTUNER_CHANNEL_DOWN           000040000H
#Define MCI_VCR_SETTUNER_CHANNEL_SEEK_UP        000080000H
#Define MCI_VCR_SETTUNER_CHANNEL_SEEK_DOWN      000100000H
#Define MCI_VCR_SETTUNER_NUMBER                 000200000H

#Define MCI_VCR_SET_TIME_MODE                   000010000H
#Define MCI_VCR_SET_POWER                       000020000H
#Define MCI_VCR_SET_RECORD_FORMAT               000040000H
#Define MCI_VCR_SET_COUNTER_FORMAT              000080000H
#Define MCI_VCR_SET_INDEX                       000100000H
#Define MCI_VCR_SET_ASSEMBLE_RECORD             000200000H
#Define MCI_VCR_SET_TRACKING                    000400000H
#Define MCI_VCR_SET_SPEED                       000800000H
#Define MCI_VCR_SET_TAPE_LENGTH                 001000000H
#Define MCI_VCR_SET_COUNTER_VALUE               002000000H
#Define MCI_VCR_SET_CLOCK                       004000000H
#Define MCI_VCR_SET_PAUSE_TIMEOUT               008000000H
#Define MCI_VCR_SET_PREROLL_DURATION            010000000H
#Define MCI_VCR_SET_POSTROLL_DURATION           020000000H

#Define MCI_VCR_SETTIMECODE_RECORD              000010000H

#Define MCI_VCR_STATUS_FRAME_RATE               000004001H
#Define MCI_VCR_STATUS_SPEED                    000004002H
#Define MCI_VCR_STATUS_MEDIA_TYPE               000004003H
#Define MCI_VCR_STATUS_RECORD_FORMAT            000004004H
#Define MCI_VCR_STATUS_PLAY_FORMAT              000004005H
#Define MCI_VCR_STATUS_AUDIO_SOURCE             000004006H
#Define MCI_VCR_STATUS_AUDIO_SOURCE_NUMBER      000004007H
#Define MCI_VCR_STATUS_VIDEO_SOURCE             000004008H
#Define MCI_VCR_STATUS_VIDEO_SOURCE_NUMBER      000004009H
#Define MCI_VCR_STATUS_AUDIO_MONITOR            00000400AH
#Define MCI_VCR_STATUS_AUDIO_MONITOR_NUMBER     00000400BH
#Define MCI_VCR_STATUS_VIDEO_MONITOR            00000400CH
#Define MCI_VCR_STATUS_VIDEO_MONITOR_NUMBER     00000400DH
#Define MCI_VCR_STATUS_INDEX_ON                 00000400EH
#Define MCI_VCR_STATUS_INDEX                    00000400FH
#Define MCI_VCR_STATUS_COUNTER_FORMAT           000004010H
#Define MCI_VCR_STATUS_COUNTER_RESOLUTION       000004011H
#Define MCI_VCR_STATUS_TIMECODE_TYPE            000004012H
#Define MCI_VCR_STATUS_COUNTER_VALUE            000004013H
#Define MCI_VCR_STATUS_TUNER_CHANNEL            000004014H
#Define MCI_VCR_STATUS_WRITE_PROTECTED          000004015H
#Define MCI_VCR_STATUS_TIMECODE_RECORD          000004016H
#Define MCI_VCR_STATUS_VIDEO_RECORD             000004017H
#Define MCI_VCR_STATUS_AUDIO_RECORD             000004018H
#Define MCI_VCR_STATUS_TIME_TYPE                000004019H
#Define MCI_VCR_STATUS_TIME_MODE                00000401AH
#Define MCI_VCR_STATUS_POWER_ON                 00000401BH
#Define MCI_VCR_STATUS_CLOCK                    00000401CH
#Define MCI_VCR_STATUS_ASSEMBLE_RECORD          00000401DH
#Define MCI_VCR_STATUS_TIMECODE_PRESENT         00000401EH
#Define MCI_VCR_STATUS_NUMBER_OF_VIDEO_TRACKS   00000401FH
#Define MCI_VCR_STATUS_NUMBER_OF_AUDIO_TRACKS   000004020H
#Define MCI_VCR_STATUS_CLOCK_ID                 000004021H
#Define MCI_VCR_STATUS_PAUSE_TIMEOUT            000004022H
#Define MCI_VCR_STATUS_PREROLL_DURATION         000004023H
#Define MCI_VCR_STATUS_POSTROLL_DURATION        000004024H
#Define MCI_VCR_STATUS_VIDEO                    000004025H
#Define MCI_VCR_STATUS_AUDIO                    000004026H

#Define MCI_VCR_STATUS_NUMBER                   000080000H

#Define MCI_VCR_ESCAPE_STRING                   000000100H

#Define MCI_VCR_LIST_VIDEO_SOURCE               000010000H
#Define MCI_VCR_LIST_AUDIO_SOURCE               000020000H
#Define MCI_VCR_LIST_COUNT                      000040000H
#Define MCI_VCR_LIST_NUMBER                     000080000H

#Define MCI_VCR_MARK_WRITE                      000010000H
#Define MCI_VCR_MARK_ERASE                      000020000H

#Define MCI_VCR_SETAUDIO_RECORD                 000010000H
#Define MCI_VCR_SETAUDIO_SOURCE                 000020000H
#Define MCI_VCR_SETAUDIO_MONITOR                000040000H
#Define MCI_VCR_SETAUDIO_TO                     000200000H
#Define MCI_VCR_SETAUDIO_NUMBER                 000400000H

#Define MCI_VCR_SETVIDEO_RECORD                 000010000H
#Define MCI_VCR_SETVIDEO_SOURCE                 000020000H
#Define MCI_VCR_SETVIDEO_MONITOR                000040000H
#Define MCI_VCR_SETVIDEO_TO                     000100000H
#Define MCI_VCR_SETVIDEO_NUMBER                 000200000H

#Define MM_MCISIGNAL                            03CBH

#Define MCI_VCR_SIGNAL_AT                       000010000H
#Define MCI_VCR_SIGNAL_EVERY                    000020000H
#Define MCI_VCR_SIGNAL_USERVAL                  000040000H
#Define MCI_VCR_SIGNAL_CANCEL                   000080000H
#Define MCI_VCR_SIGNAL_POSITION                 000100000H

#Define MCI_VCR_STEP_FRAMES                     000010000H
#Define MCI_VCR_STEP_REVERSE                    000020000H

#Define MCI_VCR_FREEZE_INPUT                    000010000H
#Define MCI_VCR_FREEZE_OUTPUT                   000020000H
#Define MCI_VCR_FREEZE_FIELD                    000040000H
#Define MCI_VCR_FREEZE_FRAME                    000080000H

#Define MCI_VCR_UNFREEZE_INPUT                  000010000H
#Define MCI_VCR_UNFREEZE_OUTPUT                 000020000H

#Define MCI_VCR_MEDIA_8MM                       (MCI_VCR_OFFSET + 1)
#Define MCI_VCR_MEDIA_HI8                       (MCI_VCR_OFFSET + 2)
#Define MCI_VCR_MEDIA_VHS                       (MCI_VCR_OFFSET + 3)
#Define MCI_VCR_MEDIA_SVHS                      (MCI_VCR_OFFSET + 4)
#Define MCI_VCR_MEDIA_BETA                      (MCI_VCR_OFFSET + 5)
#Define MCI_VCR_MEDIA_EDBETA                    (MCI_VCR_OFFSET + 6)
#Define MCI_VCR_MEDIA_OTHER                     (MCI_VCR_OFFSET + 7)

#Define MCI_VCR_FORMAT_SP                       (MCI_VCR_OFFSET + 8)
#Define MCI_VCR_FORMAT_LP                       (MCI_VCR_OFFSET + 9)
#Define MCI_VCR_FORMAT_EP                       (MCI_VCR_OFFSET + 10)
#Define MCI_VCR_FORMAT_OTHER                    (MCI_VCR_OFFSET + 11)

#Define MCI_VCR_TIME_TIMECODE                   (MCI_VCR_OFFSET + 12)
#Define MCI_VCR_TIME_COUNTER                    (MCI_VCR_OFFSET + 13)
#Define MCI_VCR_TIME_DETECT                     (MCI_VCR_OFFSET + 14)

#Define MCI_VCR_SRC_TYPE_TUNER                  (MCI_VCR_OFFSET + 15)
#Define MCI_VCR_SRC_TYPE_LINE                   (MCI_VCR_OFFSET + 16)
#Define MCI_VCR_SRC_TYPE_SVIDEO                 (MCI_VCR_OFFSET + 17)
#Define MCI_VCR_SRC_TYPE_RGB                    (MCI_VCR_OFFSET + 18)
#Define MCI_VCR_SRC_TYPE_AUX                    (MCI_VCR_OFFSET + 19)
#Define MCI_VCR_SRC_TYPE_GENERIC                (MCI_VCR_OFFSET + 20)
#Define MCI_VCR_SRC_TYPE_MUTE                   (MCI_VCR_OFFSET + 21)
#Define MCI_VCR_SRC_TYPE_OUTPUT                 (MCI_VCR_OFFSET + 22)

#Define MCI_VCR_INDEX_TIMECODE                  (MCI_VCR_OFFSET + 23)
#Define MCI_VCR_INDEX_COUNTER                   (MCI_VCR_OFFSET + 24)
#Define MCI_VCR_INDEX_DATE                      (MCI_VCR_OFFSET + 25)
#Define MCI_VCR_INDEX_TIME                      (MCI_VCR_OFFSET + 26)

#Define MCI_VCR_COUNTER_RES_SECONDS             (MCI_VCR_OFFSET + 27)
#Define MCI_VCR_COUNTER_RES_FRAMES              (MCI_VCR_OFFSET + 28)

#Define MCI_VCR_TIMECODE_TYPE_SMPTE             (MCI_VCR_OFFSET + 29)
#Define MCI_VCR_TIMECODE_TYPE_SMPTE_DROP        (MCI_VCR_OFFSET + 30)
#Define MCI_VCR_TIMECODE_TYPE_OTHER             (MCI_VCR_OFFSET + 31)
#Define MCI_VCR_TIMECODE_TYPE_NONE              (MCI_VCR_OFFSET + 32)

#Define MCI_VCR_PLUS                            (MCI_VCR_OFFSET + 33)
#Define MCI_VCR_MINUS                           (MCI_VCR_OFFSET + 34)
#Define MCI_VCR_RESET                           (MCI_VCR_OFFSET + 35)

MCI_VCR_SEEK_PARMS Struct
	dwCallback DD
	dwTo DD
	dwMark DD
	dwAt DD
EndS

MCI_VCR_SET_PARMS Struct
	dwCallback DD
	dwTimeFormat DD
	dwAudio DD
	dwTimeMode DD
	dwRecordFormat DD
	dwCounterFormat DD
	dwIndex DD
	dwTracking DD
	dwSpeed DD
	dwLength DD
	dwCounter DD
	dwClock DD
	dwPauseTimeout DD
	dwPrerollDuration DD
	dwPostrollDuration DD
EndS

MCI_VCR_SETTUNER_PARMS Struct
	dwCallback DD
	dwChannel DD
	dwNumber DD
EndS

MCI_VCR_ESCAPE_PARMS Struct
	dwCallback DD
	lpstrCommand DD
EndS

MCI_VCR_LIST_PARMS Struct
	dwCallback DD
	dwReturn DD
	dwNumber DD
EndS

MCI_VCR_RECORD_PARMS Struct
	dwCallback DD
	dwFrom DD
	dwTo DD
	dwAt DD
EndS

MCI_VCR_PLAY_PARMS Struct
	dwCallback DD
	dwFrom DD
	dwTo DD
	dwAt DD
EndS

MCI_VCR_SETAUDIO_PARMS Struct
	dwCallback DD
	dwTrack DD
	dwTo DD
	dwNumber DD
EndS

MCI_VCR_SIGNAL_PARMS Struct
	dwCallback DD
	dwPosition DD
	dwPeriod DD
	dwUserParm DD
EndS

MCI_VCR_STATUS_PARMS Struct
	dwCallback DD
	dwReturn DD
	dwItem DD
	dwTrack DD
	dwNumber DD
EndS

MCI_VCR_SETVIDEO_PARMS Struct
	dwCallback DD
	dwTrack DD
	dwTo DD
	dwNumber DD
EndS

MCI_VCR_STEP_PARMS Struct
	dwCallback DD
	dwFrames DD
EndS

MCI_VCR_CUE_PARMS STRUCT
	dwCallback DD
	dwFrom DD
	dwTo DD
ENDS

#Define MCIERR_VCR_CANNOT_OPEN_COMM         (MCIERR_CUSTOM_DRIVER_BASE + 1)
#Define MCIERR_VCR_CANNOT_WRITE_COMM        (MCIERR_CUSTOM_DRIVER_BASE + 2)
#Define MCIERR_VCR_READ_TIMEOUT             (MCIERR_CUSTOM_DRIVER_BASE + 3)
#Define MCIERR_VCR_COMMAND_BUFFER_FULL      (MCIERR_CUSTOM_DRIVER_BASE + 4)
#Define MCIERR_VCR_COMMAND_CANCELLED        (MCIERR_CUSTOM_DRIVER_BASE + 5)
#Define MCIERR_VCR_POWER_OFF                (MCIERR_CUSTOM_DRIVER_BASE + 6)
#Define MCIERR_VCR_COMMAND_FAILED           (MCIERR_CUSTOM_DRIVER_BASE + 7)
#Define MCIERR_VCR_SEARCH                   (MCIERR_CUSTOM_DRIVER_BASE + 8)
#Define MCIERR_VCR_CONDITION                (MCIERR_CUSTOM_DRIVER_BASE + 9)
#Define MCIERR_VCR_CAMERA_MODE              (MCIERR_CUSTOM_DRIVER_BASE + 10)
#Define MCIERR_VCR_VCR_MODE                 (MCIERR_CUSTOM_DRIVER_BASE + 11)
#Define MCIERR_VCR_COUNTER_TYPE             (MCIERR_CUSTOM_DRIVER_BASE + 12)
#Define MCIERR_VCR_TUNER                    (MCIERR_CUSTOM_DRIVER_BASE + 13)
#Define MCIERR_VCR_EMERGENCY_STOP           (MCIERR_CUSTOM_DRIVER_BASE + 14)
#Define MCIERR_VCR_MEDIA_UNMOUNTED          (MCIERR_CUSTOM_DRIVER_BASE + 15)
#Define MCIERR_VCR_REGISTER                 (MCIERR_CUSTOM_DRIVER_BASE + 16)
#Define MCIERR_VCR_TRACK_FAILURE            (MCIERR_CUSTOM_DRIVER_BASE + 17)
#Define MCIERR_VCR_CUE_FAILED_FLAGS         (MCIERR_CUSTOM_DRIVER_BASE + 18)
#Define MCIERR_VCR_ISWRITEPROTECTED         (MCIERR_CUSTOM_DRIVER_BASE + 19)

#ENDIF ;VCR_INC
