#ifndef NMSUPP_H
#define NMSUPP_H

/* Microsoft Network Monitor support definitions */

#define WINDOWS_VERSION_UNKNOWN  0
#define WINDOWS_VERSION_WIN32S  1
#define WINDOWS_VERSION_WIN32C  2
#define WINDOWS_VERSION_WIN32  3

#define FRAME_MASK_ETHERNET  0xFE
#define FRAME_MASK_TOKENRING  0x7F
#define FRAME_MASK_FDDI 0xFE

#define HANDLE_TYPE_PASSWORD 'PWD$'

AccessRightsNoAccess = 0
AccessRightsMonitoring = 1
AccessRightsUserAccess = 2
AccessRightsAllAccess = 3

#endif /* _NMSUPP_H */
