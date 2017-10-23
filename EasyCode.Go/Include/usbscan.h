;=============================================================;
;           usbscan.h file for Easy Code visual IDE           ;
;                       (GoAsm version)                       ;
;                                                             ;
;                   Driver Development Kit                    ;
;                                                             ;
;          Version 1.0.00 (created on November, 2010)         ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF USBSCAN_H
#Define USBSCAN_H 1

#IFNDEF MACROS_H
    #Include macros.h
#ENDIF

FILE_DEVICE_USB_SCAN                        Equ         08000H
IOCTL_INDEX                                 Equ         00800H

IOCTL_CANCEL_IO                             Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 1, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_GET_VERSION                           Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 0, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_GET_CHANNEL_ALIGN_RQST                Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 5, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_GET_DEVICE_DESCRIPTOR                 Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 6, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_GET_PIPE_CONFIGURATION                Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 10,METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_GET_USB_DESCRIPTOR                    Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 8, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_READ_REGISTERS                        Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 3, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_RESET_PIPE                            Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 7, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_SEND_USB_REQUEST                      Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 9, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_SET_TIMEOUT                           Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 11,METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_WAIT_ON_DEVICE_EVENT                  Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 2, METHOD_BUFFERED,FILE_ANY_ACCESS)
IOCTL_WRITE_REGISTERS                       Equ         CTL_CODE(FILE_DEVICE_USB_SCAN, IOCTL_INDEX + 4, METHOD_BUFFERED, FILE_ANY_ACCESS)


MAX_NUM_PIPES                               Equ         8

BULKIN_FLAG                                 Equ         080H

CHANNEL_INFO Struct
    EventChannelSize                        DD
    uReadDataAlignment                      DD
    uWriteDataAlignment                     DD
EndS

DEVICE_DESCRIPTOR Struct
    usVendorId                              DW
    usProductId                             DW
    usBcdDevice                             DW
    usLanguageId                            DW
EndS

DRV_VERSION Struct
    major                                   DD
    minor                                   DD
    internal                                DD
EndS

IO_BLOCK Struct
    uOffset                                 DD
    uLength                                 DD
    pbyData                                 DD
    uIndex                                  DD
EndS

IO_BLOCK_EX Struct
    uOffset                                 DD
    uLength                                 DD
    pbyData                                 DD
    uIndex                                  DD
    bRequest                                DB
    bmRequestType                           DB
    fTransferDirectionIn                    DB
EndS

USBSCAN_GET_DESCRIPTOR Struct
    DescriptorType                          DB
    Index                                   DB
    LanguageId                              DW
EndS

;RAW_PIPE_TYPE Enumeration
USBSCAN_PIPE_CONTROL                        Equ         0
USBSCAN_PIPE_ISOCHRONOUS                    Equ         1
USBSCAN_PIPE_BULK                           Equ         2
USBSCAN_PIPE_INTERRUPT                      Equ         3

USBSCAN_PIPE_INFORMATION Struct
    MaximumPacketSize                       DW
    EndpointAddress                         DB
    Interval                                DB
    PipeType                                DD
EndS

USBSCAN_PIPE_CONFIGURATION Struct
    NumberOfPipes                           DD
    PipeInfo                                USBSCAN_PIPE_INFORMATION MAX_NUM_PIPES Dup
EndS

USBSCAN_TIMEOUT Struct
    TimeoutRead                             DD
    TimeoutWrite                            DD
    TimeoutEvent                            DD
EndS

;PIPE_TYPE Enumeration
EVENT_PIPE                                  Equ         0
READ_DATA_PIPE                              Equ         1
WRITE_DATA_PIPE                             Equ         2
ALL_PIPE                                    Equ         3

#ENDIF ;USBSCAN_H
