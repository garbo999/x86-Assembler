/*
 scarderr.mc

   Error message codes from the Smart Card Resource Manager
   These messages must be reconciled with winerror.w
   They exist here to provide error messages on pre-Win2K systems.

*/
#ifndef SCARD_S_SUCCESS
//
// =============================
// Facility SCARD Error Messages
// =============================
//
#define SCARD_S_SUCCESS NO_ERROR
//
//  Values are 32 bit values layed out as follows:
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
#define FACILITY_SYSTEM                  0x0
#define FACILITY_SCARD                   0x10


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: SCARD_F_INTERNAL_ERROR
//
// MessageText:
//
//  An internal consistency check failed.
//
#define SCARD_F_INTERNAL_ERROR           0x80100001

//
// MessageId: SCARD_E_CANCELLED
//
// MessageText:
//
//  The action was cancelled by an SCardCancel request.
//
#define SCARD_E_CANCELLED                0x80100002

//
// MessageId: SCARD_E_INVALID_HANDLE
//
// MessageText:
//
//  The supplied handle was invalid.
//
#define SCARD_E_INVALID_HANDLE           0x80100003

//
// MessageId: SCARD_E_INVALID_PARAMETER
//
// MessageText:
//
//  One or more of the supplied parameters could not be properly interpreted.
//
#define SCARD_E_INVALID_PARAMETER        0x80100004

//
// MessageId: SCARD_E_INVALID_TARGET
//
// MessageText:
//
//  Registry startup information is missing or invalid.
//
#define SCARD_E_INVALID_TARGET           0x80100005

//
// MessageId: SCARD_E_NO_MEMORY
//
// MessageText:
//
//  Not enough memory available to complete this command.
//
#define SCARD_E_NO_MEMORY                0x80100006

//
// MessageId: SCARD_F_WAITED_TOO_LONG
//
// MessageText:
//
//  An internal consistency timer has expired.
//
#define SCARD_F_WAITED_TOO_LONG          0x80100007

//
// MessageId: SCARD_E_INSUFFICIENT_BUFFER
//
// MessageText:
//
//  The data buffer to receive returned data is too small for the returned data.
//
#define SCARD_E_INSUFFICIENT_BUFFER      0x80100008

//
// MessageId: SCARD_E_UNKNOWN_READER
//
// MessageText:
//
//  The specified reader name is not recognized.
//
#define SCARD_E_UNKNOWN_READER           0x80100009

//
// MessageId: SCARD_E_TIMEOUT
//
// MessageText:
//
//  The user-specified timeout value has expired.
//
#define SCARD_E_TIMEOUT                  0x8010000A

//
// MessageId: SCARD_E_SHARING_VIOLATION
//
// MessageText:
//
//  The smart card cannot be accessed because of other connections outstanding.
//
#define SCARD_E_SHARING_VIOLATION        0x8010000B

//
// MessageId: SCARD_E_NO_SMARTCARD
//
// MessageText:
//
//  The operation requires a Smart Card, but no Smart Card is currently in the device.
//
#define SCARD_E_NO_SMARTCARD             0x8010000C

//
// MessageId: SCARD_E_UNKNOWN_CARD
//
// MessageText:
//
//  The specified smart card name is not recognized.
//
#define SCARD_E_UNKNOWN_CARD             0x8010000D

//
// MessageId: SCARD_E_CANT_DISPOSE
//
// MessageText:
//
//  The system could not dispose of the media in the requested manner.
//
#define SCARD_E_CANT_DISPOSE             0x8010000E

//
// MessageId: SCARD_E_PROTO_MISMATCH
//
// MessageText:
//
//  The requested protocols are incompatible with the protocol currently in use with the smart card.
//
#define SCARD_E_PROTO_MISMATCH           0x8010000F

//
// MessageId: SCARD_E_NOT_READY
//
// MessageText:
//
//  The reader or smart card is not ready to accept commands.
//
#define SCARD_E_NOT_READY                0x80100010

//
// MessageId: SCARD_E_INVALID_VALUE
//
// MessageText:
//
//  One or more of the supplied parameters values could not be properly interpreted.
//
#define SCARD_E_INVALID_VALUE            0x80100011

//
// MessageId: SCARD_E_SYSTEM_CANCELLED
//
// MessageText:
//
//  The action was cancelled by the system, presumably to log off or shut down.
//
#define SCARD_E_SYSTEM_CANCELLED         0x80100012

//
// MessageId: SCARD_F_COMM_ERROR
//
// MessageText:
//
//  An internal communications error has been detected.
//
#define SCARD_F_COMM_ERROR               0x80100013

//
// MessageId: SCARD_F_UNKNOWN_ERROR
//
// MessageText:
//
//  An internal error has been detected, but the source is unknown.
//
#define SCARD_F_UNKNOWN_ERROR            0x80100014

//
// MessageId: SCARD_E_INVALID_ATR
//
// MessageText:
//
//  An ATR obtained from the registry is not a valid ATR string.
//
#define SCARD_E_INVALID_ATR              0x80100015

//
// MessageId: SCARD_E_NOT_TRANSACTED
//
// MessageText:
//
//  An attempt was made to end a non-existent transaction.
//
#define SCARD_E_NOT_TRANSACTED           0x80100016

//
// MessageId: SCARD_E_READER_UNAVAILABLE
//
// MessageText:
//
//  The specified reader is not currently available for use.
//
#define SCARD_E_READER_UNAVAILABLE       0x80100017

//
// MessageId: SCARD_P_SHUTDOWN
//
// MessageText:
//
//  The operation has been aborted to allow the server application to exit.
//
#define SCARD_P_SHUTDOWN                 0x80100018

//
// MessageId: SCARD_E_PCI_TOO_SMALL
//
// MessageText:
//
//  The PCI Receive buffer was too small.
//
#define SCARD_E_PCI_TOO_SMALL            0x80100019

//
// MessageId: SCARD_E_READER_UNSUPPORTED
//
// MessageText:
//
//  The reader driver does not meet minimal requirements for support.
//
#define SCARD_E_READER_UNSUPPORTED       0x8010001A

//
// MessageId: SCARD_E_DUPLICATE_READER
//
// MessageText:
//
//  The reader driver did not produce a unique reader name.
//
#define SCARD_E_DUPLICATE_READER         0x8010001B

//
// MessageId: SCARD_E_CARD_UNSUPPORTED
//
// MessageText:
//
//  The smart card does not meet minimal requirements for support.
//
#define SCARD_E_CARD_UNSUPPORTED         0x8010001C

//
// MessageId: SCARD_E_NO_SERVICE
//
// MessageText:
//
//  The Smart card resource manager is not running.
//
#define SCARD_E_NO_SERVICE               0x8010001D

//
// MessageId: SCARD_E_SERVICE_STOPPED
//
// MessageText:
//
//  The Smart card resource manager has shut down.
//
#define SCARD_E_SERVICE_STOPPED          0x8010001E

//
// MessageId: SCARD_E_UNEXPECTED
//
// MessageText:
//
//  An unexpected card error has occurred.
//
#define SCARD_E_UNEXPECTED               0x8010001F

//
// MessageId: SCARD_E_ICC_INSTALLATION
//
// MessageText:
//
//  No Primary Provider can be found for the smart card.
//
#define SCARD_E_ICC_INSTALLATION         0x80100020

//
// MessageId: SCARD_E_ICC_CREATEORDER
//
// MessageText:
//
//  The requested order of object creation is not supported.
//
#define SCARD_E_ICC_CREATEORDER          0x80100021

//
// MessageId: SCARD_E_UNSUPPORTED_FEATURE
//
// MessageText:
//
//  This smart card does not support the requested feature.
//
#define SCARD_E_UNSUPPORTED_FEATURE      0x80100022

//
// MessageId: SCARD_E_DIR_NOT_FOUND
//
// MessageText:
//
//  The identified directory does not exist in the smart card.
//
#define SCARD_E_DIR_NOT_FOUND            0x80100023

//
// MessageId: SCARD_E_FILE_NOT_FOUND
//
// MessageText:
//
//  The identified file does not exist in the smart card.
//
#define SCARD_E_FILE_NOT_FOUND           0x80100024

//
// MessageId: SCARD_E_NO_DIR
//
// MessageText:
//
//  The supplied path does not represent a smart card directory.
//
#define SCARD_E_NO_DIR                   0x80100025

//
// MessageId: SCARD_E_NO_FILE
//
// MessageText:
//
//  The supplied path does not represent a smart card file.
//
#define SCARD_E_NO_FILE                  0x80100026

//
// MessageId: SCARD_E_NO_ACCESS
//
// MessageText:
//
//  Access is denied to this file.
//
#define SCARD_E_NO_ACCESS                0x80100027

//
// MessageId: SCARD_E_WRITE_TOO_MANY
//
// MessageText:
//
//  The smartcard does not have enough memory to store the information.
//
#define SCARD_E_WRITE_TOO_MANY           0x80100028

//
// MessageId: SCARD_E_BAD_SEEK
//
// MessageText:
//
//  There was an error trying to set the smart card file object pointer.
//
#define SCARD_E_BAD_SEEK                 0x80100029

//
// MessageId: SCARD_E_INVALID_CHV
//
// MessageText:
//
//  The supplied PIN is incorrect.
//
#define SCARD_E_INVALID_CHV              0x8010002A

//
// MessageId: SCARD_E_UNKNOWN_RES_MNG
//
// MessageText:
//
//  An unrecognized error code was returned from a layered component.
//
#define SCARD_E_UNKNOWN_RES_MNG          0x8010002B

//
// MessageId: SCARD_E_NO_SUCH_CERTIFICATE
//
// MessageText:
//
//  The requested certificate does not exist.
//
#define SCARD_E_NO_SUCH_CERTIFICATE      0x8010002C

//
// MessageId: SCARD_E_CERTIFICATE_UNAVAILABLE
//
// MessageText:
//
//  The requested certificate could not be obtained.
//
#define SCARD_E_CERTIFICATE_UNAVAILABLE  0x8010002D

//
// MessageId: SCARD_E_NO_READERS_AVAILABLE
//
// MessageText:
//
//  Cannot find a smart card reader.
//
#define SCARD_E_NO_READERS_AVAILABLE     0x8010002E

//
// MessageId: SCARD_E_COMM_DATA_LOST
//
// MessageText:
//
//  A communications error with the smart card has been detected.  Retry the operation.
//
#define SCARD_E_COMM_DATA_LOST           0x8010002F

//
// MessageId: SCARD_E_NO_KEY_CONTAINER
//
// MessageText:
//
//  The requested key container does not exist on the smart card.
//
#define SCARD_E_NO_KEY_CONTAINER         0x80100030

//
// MessageId: SCARD_E_SERVER_TOO_BUSY
//
// MessageText:
//
//  The Smart card resource manager is too busy to complete this operation.
//
#define SCARD_E_SERVER_TOO_BUSY          0x80100031

//
// These are warning codes.
//
//
// MessageId: SCARD_W_UNSUPPORTED_CARD
//
// MessageText:
//
//  The reader cannot communicate with the smart card, due to ATR configuration conflicts.
//
#define SCARD_W_UNSUPPORTED_CARD         0x80100065

//
// MessageId: SCARD_W_UNRESPONSIVE_CARD
//
// MessageText:
//
//  The smart card is not responding to a reset.
//
#define SCARD_W_UNRESPONSIVE_CARD        0x80100066

//
// MessageId: SCARD_W_UNPOWERED_CARD
//
// MessageText:
//
//  Power has been removed from the smart card, so that further communication is not possible.
//
#define SCARD_W_UNPOWERED_CARD           0x80100067

//
// MessageId: SCARD_W_RESET_CARD
//
// MessageText:
//
//  The smart card has been reset, so any shared state information is invalid.
//
#define SCARD_W_RESET_CARD               0x80100068

//
// MessageId: SCARD_W_REMOVED_CARD
//
// MessageText:
//
//  The smart card has been removed, so that further communication is not possible.
//
#define SCARD_W_REMOVED_CARD             0x80100069

//
// MessageId: SCARD_W_SECURITY_VIOLATION
//
// MessageText:
//
//  Access was denied because of a security violation.
//
#define SCARD_W_SECURITY_VIOLATION       0x8010006A

//
// MessageId: SCARD_W_WRONG_CHV
//
// MessageText:
//
//  The card cannot be accessed because the wrong PIN was presented.
//
#define SCARD_W_WRONG_CHV                0x8010006B

//
// MessageId: SCARD_W_CHV_BLOCKED
//
// MessageText:
//
//  The card cannot be accessed because the maximum number of PIN entry attempts has been reached.
//
#define SCARD_W_CHV_BLOCKED              0x8010006C

//
// MessageId: SCARD_W_EOF
//
// MessageText:
//
//  The end of the smart card file has been reached.
//
#define SCARD_W_EOF                      0x8010006D

//
// MessageId: SCARD_W_CANCELLED_BY_USER
//
// MessageText:
//
//  The action was cancelled by the user.
//
#define SCARD_W_CANCELLED_BY_USER        0x8010006E

//
// MessageId: SCARD_W_CARD_NOT_AUTHENTICATED
//
// MessageText:
//
//  No PIN was presented to the smart card.
//
#define SCARD_W_CARD_NOT_AUTHENTICATED   0x8010006F

#endif // SCARD_S_SUCCESS
