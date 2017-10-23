;=============================================================;
;           usbdi.h file for Easy Code visual IDE             ;
;                       (GoAsm version)                       ;
;                                                             ;
;                   Driver Development Kit                    ;
;                                                             ;
;          Version 1.0.00 (created on November, 2010)         ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF USBDI_H
#Define USBDI_H 1

#Include usb.h
#Include usbioctl.h

USBD_STATUS_CANCELLING                                      Equ         (000020000H)
USBD_STATUS_CANCELING                                       Equ         (000020000H)
USBD_STATUS_NO_MEMORY                                       Equ         (080000100H)
USBD_STATUS_ERROR                                           Equ         (080000000H)
USBD_STATUS_REQUEST_FAILED                                  Equ         (080000500H)
USBD_STATUS_HALTED                                          Equ         (0C0000000H)

URB_FUNCTION_RESERVED0                                      Equ         0016H
URB_FUNCTION_RESERVED                                       Equ         001DH
URB_FUNCTION_LAST                                           Equ         0029H

USBD_PF_DOUBLE_BUFFER                                       Equ         00000002H

USBD_TRANSFER_DIRECTION_BIT                                 Equ         0
USBD_SHORT_TRANSFER_OK_BIT                                  Equ         1
USBD_START_ISO_TRANSFER_ASAP_BIT                            Equ         2

#ENDIF ;USBDI_H
