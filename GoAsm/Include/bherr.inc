;=============================================================;
;           bherr.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF BHERR_INC
#Define BHERR_INC

#Define BHERR_SUCCESS                       0
#Define BHERR_MEMORY_MAPPED_FILE_ERROR      1
#Define BHERR_INVALID_HFILTER               2
#Define BHERR_CAPTURING                     3
#Define BHERR_NOT_CAPTURING                 4
#Define BHERR_NO_MORE_FRAMES                5
#Define BHERR_BUFFER_TOO_SMALL              6
#Define BHERR_FRAME_NOT_RECOGNIZED          7
#Define BHERR_FILE_ALREADY_EXISTS           8
#Define BHERR_DRIVER_NOT_FOUND              9
#Define BHERR_ADDRESS_ALREADY_EXISTS        10
#Define BHERR_INVALID_HFRAME                11
#Define BHERR_INVALID_HPROTOCOL             12
#Define BHERR_INVALID_HPROPERTY             13
#Define BHERR_LOCKED                        14
#Define BHERR_STACK_EMPTY                   15
#Define BHERR_STACK_OVERFLOW                16
#Define BHERR_TOO_MANY_PROTOCOLS            17
#Define BHERR_FILE_NOT_FOUND                18
#Define BHERR_OUT_OF_MEMORY                 19
#Define BHERR_CAPTURE_PAUSED                20
#Define BHERR_NO_BUFFERS                    21
#Define BHERR_BUFFERS_ALREADY_EXIST         22
#Define BHERR_NOT_LOCKED                    23
#Define BHERR_OUT_OF_RANGE                  24
#Define BHERR_LOCK_NESTING_TOO_DEEP         25
#Define BHERR_LOAD_PARSER_FAILED            26
#define BHERR_UNLOAD_PARSER_FAILED          27
#Define BHERR_INVALID_HADDRESSDB            28
#Define BHERR_ADDRESS_NOT_FOUND             29
#Define BHERR_NETWORK_NOT_PRESENT           30
#Define BHERR_NO_PROPERTY_DATABASE          31
#Define BHERR_PROPERTY_NOT_FOUND            32
#Define BHERR_INVALID_HPROPERTYDB           33
#define BHERR_PROTOCOL_NOT_ENABLED          34
#define BHERR_PROTOCOL_NOT_FOUND            35
#define BHERR_INVALID_PARSER_DLL            36
#Define BHERR_NO_ATTACHED_PROPERTIES        37
#Define BHERR_NO_FRAMES                     38
#Define BHERR_INVALID_FILE_FORMAT           39
#Define BHERR_COULD_NOT_CREATE_TEMPFILE     40
#Define BHERR_OUT_OF_DOS_MEMORY             41
#Define BHERR_NO_PROTOCOLS_ENABLED          42
#Define BHERR_UNKNOWN_MACTYPE               46
#Define BHERR_ROUTING_INFO_NOT_PRESENT      47
#Define BHERR_INVALID_HNETWORK              48
#Define BHERR_NETWORK_ALREADY_OPENED        49
#Define BHERR_NETWORK_NOT_OPENED            50
#Define BHERR_FRAME_NOT_FOUND               51
#Define BHERR_NO_HANDLES                    53
#Define BHERR_INVALID_NETWORK_ID            54
#Define BHERR_INVALID_HCAPTURE              55
#Define BHERR_PROTOCOL_ALREADY_ENABLED      56
#Define BHERR_FILTER_INVALID_EXPRESSION     57
#Define BHERR_TRANSMIT_ERROR                58
#Define BHERR_INVALID_HBUFFER               59
#Define BHERR_INVALID_DATA                  60
#Define BHERR_MSDOS_DRIVER_NOT_LOADED       61
#Define BHERR_WINDOWS_DRIVER_NOT_LOADED     62
#Define BHERR_MSDOS_DRIVER_INIT_FAILURE     63
#Define BHERR_WINDOWS_DRIVER_INIT_FAILURE   64
#Define BHERR_NETWORK_BUSY                  65
#Define BHERR_CAPTURE_NOT_PAUSED            66
#Define BHERR_INVALID_PACKET_LENGTH         67
#Define BHERR_INTERNAL_EXCEPTION            69
#define BHERR_PROMISCUOUS_MODE_NOT_SUPPORTED 70
#Define BHERR_MAC_DRIVER_OPEN_FAILURE       71
#Define BHERR_RUNAWAY_PROTOCOL              72
#Define BHERR_PENDING                       73
#Define BHERR_ACCESS_DENIED                 74
#Define BHERR_INVALID_HPASSWORD             75
#Define BHERR_INVALID_PARAMETER             76
#Define BHERR_FILE_READ_ERROR               77
#Define BHERR_FILE_WRITE_ERROR              78
#Define BHERR_PROTOCOL_NOT_REGISTERED       79
#Define BHERR_IP_ADDRESS_NOT_FOUND          80
#Define BHERR_TRANSMIT_CANCELLED            81
#Define BHERR_LOCKED_FRAMES                 82
#Define BHERR_NO_TRANSMITS_PENDING          83
#Define BHERR_PATH_NOT_FOUND                84
#Define BHERR_WINDOWS_ERROR                 85
#Define BHERR_NO_FRAME_NUMBER               86
#Define BHERR_FRAME_HAS_NO_CAPTURE          87
#Define BHERR_FRAME_ALREADY_HAS_CAPTURE     88
#Define BHERR_NAL_IS_NOT_REMOTE             89
#Define BHERR_NOT_SUPPORTED                 90
#Define BHERR_DISCARD_FRAME                 91
#Define BHERR_CANCEL_SAVE_CAPTURE           92
#Define BHERR_LOST_CONNECTION               93
#Define BHERR_INVALID_MEDIA_TYPE            94
#Define BHERR_AGENT_IN_USE                  95
#Define BHERR_TIMEOUT                       96
#Define BHERR_DISCONNECTED                  97
#Define BHERR_SETTIMER_FAILED               98
#Define BHERR_NETWORK_ERROR                 99
#Define BHERR_UPLEVEL_CAPTURE_FILE          113

#ENDIF ;BHERR_INC
