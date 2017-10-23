.Const

.Data

FileBoxHandle	DD	?
ByteWrite 		DD	?
TotalHandle 	DD	?
PassHandle 		DD	?
hInstance 		DD	?
ShredHandle 	DD	?
SlideHandle 	DD	?


MESSAGES		DD	WM_CREATE, OnCreate
				DD	WM_COMMAND, OnCommand
				DD	WM_CLOSE, OnClose

FilePath		DSS	257 Dup 0
DataByte		DD	01010101010101010101010101010101B
mbText			DSS	TEXT("The file has been shredded")
				DSS	0
mbCaption		DSS	TEXT("Done")
				DSS	0
mbError			DSS	TEXT("Error")
				DSS	0
Ofn				OPENFILENAME <>
FilterString	DSS	TEXT("All Files")
				DSS	0
				DSS	TEXT("*.*")
				DSS	0, 0
AboutCaption	DSS	TEXT("BieberWorks File Shredder")
				DSS	0, 13, 10
AboutText		DSS	TEXT("BieberWorks File Shredder")
				DSS	13, 10
				DSS	TEXT("BieberWorks Software")
				DSS	13, 10
				DSS	TEXT("http://www.bieberworks.net")
				DSS	0

.Code

;;    Copyright Robert Bieber, 2006
;;    This program is free software; you can redistribute it and/or modify
;;    it under the terms of the GNU General Public License as published by
;;    the Free Software Foundation; either version 2 of the License, or
;;    (at your option) any later version.
;;
;;    This program is distributed in the hope that it will be useful,
;;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;    GNU General Public License for more details.
;;
;;    You should have received a copy of the GNU General Public License along
;;    with this program; if not, write to the Free Software Foundation, Inc.,
;;    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

Window1Procedure Frame hWnd, uMsg, wParam, lParam
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf MESSAGES / 8
	Mov Edx, Addr MESSAGES
:	Dec Ecx
	Js >L1
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret

L1:
	Xor Eax, Eax	;Mov Eax, FALSE
	Ret
EndF

OnCreate:
	UseData Window1Procedure
	;Retrieve and store handle to the edit box
	Invoke GetWindowItem, [hWnd], IDC_WINDOW1_FILEBOX
	Mov [FileBoxHandle], Eax
	;Retrieve and store the handle to the upper status bar
	Invoke GetWindowItem, [hWnd], IDC_WINDOW1_TOTALBAR
	Mov [TotalHandle], Eax
	;Retrieve and store the handle to the lower status bar
	Invoke GetWindowItem, [hWnd], IDC_WINDOW1_PASSBAR
	Mov [PassHandle], Eax
	;Retrieve and store the handle of the shred button
	Invoke GetWindowItem, [hWnd], IDC_WINDOW1_SHREDBUTTON
	Mov [ShredHandle], Eax
	;Retrieve and store the handle of the slider bar
	Invoke GetWindowItem, [hWnd], IDC_WINDOW1_PASSSLIDER
	Mov [SlideHandle], Eax
	Mov Eax, TRUE
	Ret
EndU

OnCommand:
	UseData Window1Procedure
	Mov Eax, [wParam]
	Cmp Ax, IDC_WINDOW1_SHREDBUTTON
	Jne >wmc2
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
	Jne >>L2
	;Code to execute if the shred button has been clicked
;	Invoke GetWindowText, [FileBoxHandle], Addr FilePath, 256
	Invoke ShredFile
	Jmp >> L1
wmc2:
	Cmp Ax, IDC_WINDOW1_BROWSEBUTTON
	Jne >wmc4
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
	Jne >> L2
	;Fill the OPENFILENAME structure
	Invoke RtlFillMemory, Addr Ofn, SizeOf OPENFILENAME, 0
	Mov Eax, [App.Instance]
	Mov [hInstance], Eax
	Mov D[Ofn.lStructSize], SizeOf Ofn
	Push [hWnd]
	Pop [Ofn.hwndOwner]
	Push [hInstance]
	Pop [Ofn.hInstance]
	Mov D[Ofn.lpstrFilter], Offset FilterString
	Mov D[Ofn.lpstrFile], Offset FilePath
	Mov D[Ofn.nMaxFile], 257
	Mov D[Ofn.Flags], OFN_FILEMUSTEXIST | \
                      OFN_PATHMUSTEXIST | OFN_LONGNAMES | \
                      OFN_EXPLORER | OFN_HIDEREADONLY
	Invoke GetOpenFileName, Addr Ofn
	Or Eax, Eax
	Jz >L1
	Invoke SetWindowText, [FileBoxHandle], Addr FilePath
	Jmp >L1
wmc4:
	Cmp Ax, IDC_WINDOW1_ABOUTBUTTON
	Jne >L2
	Shr Eax, 16
	Cmp Ax, BN_CLICKED
	Jne >L2
	Invoke MessageBox, NULL, Addr AboutText, Addr AboutCaption, MB_OK

L1:
	Mov Eax, TRUE
	Ret

L2:
	Xor Eax, Eax
	Ret
EndU

OnClose:
	UseData Window1Procedure
	Invoke IsModal, [hWnd]
	Or Eax, Eax
	Jz >
	Invoke EndModal, [hWnd], IDCANCEL
	Mov Eax, TRUE
:	Ret
EndU

;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

ShredFile Frame
	Local lDWORD:D
	Local hDWORD:D
	Local hFile:D
	Local Pass:D
	Local BytesLeft:D
	Local TempValue:D

.AAA_break_1

	Invoke SetEnabled, [ShredHandle], FALSE
	Invoke GetValue, [SlideHandle]
	Mov [TempValue], Eax
	Invoke SetMaxValue, [TotalHandle], [TempValue]
	Invoke CreateFile, Addr FilePath, GENERIC_READ Or GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
	Cmp Eax, INVALID_HANDLE_VALUE
	Je >ExitProcError
	Mov [hFile], Eax
	Invoke GetFileSize, [hFile], Addr hDWORD
	Cmp Eax, INVALID_HANDLE_VALUE
	Je >ExitProcError
	Cmp Eax, 0
	Je >ExitProcError
	;Divide total filesize by four to allow writing one DWORD at a time
	;Then add 1 to the value to compensate for any possible remainder
	Mov Ecx, 4
	Xor Edx, Edx
	Div Ecx
	Mov [lDWORD], Eax
	Invoke GetValue, [SlideHandle]
	Add Eax, 1
	Mov [Pass], Eax
	;The MaxValue and MinValue of
	;a Progress bar are two-byte
	;values (from 0 to 65535). So,
	;we will work with a percentage
	Invoke SetMaxValue, [PassHandle], 100 ;lDWORD
PassLabel:
	Invoke SetFilePointer, [hFile], 0, NULL, FILE_BEGIN
	Mov Ecx, [lDWORD]
	Mov [BytesLeft], Ecx

	Invoke SetValue, [PassHandle], 0 ; [BytesLeft]
	Dec D[Pass]
	Invoke SetValue, [TotalHandle], [Pass]

	;Divide total size by 100 in
	;order to get the percentage,
	;and store it in Edi register
	Mov Eax, [lDWORD]
	Mov Ecx, 100
	Xor Edx, Edx
	Div Ecx
	Mov Edi, Eax

ByteLabel:
	Invoke WriteFile, [hFile], Addr DataByte, 4, Addr ByteWrite, NULL
	Dec D[BytesLeft]

	;Get the percentage done
	;and update ProgressBar
	Mov Eax, [lDWORD]
	Sub Eax, [BytesLeft]
	Xor Edx, Edx
	; gary
	; gary del Div Edi
	; gary next two lines added
	;Div Ecx
	;Mov Edi, Eax
	; gary

	Invoke SetValue, [PassHandle], Eax

	;This line allows the message queue
	;to be watched. Only needed if you
	;want the user to able to interrupt
	Invoke DoEvents

	Invoke GetTickCount
	And [DataByte], Eax
	Xor [DataByte], Eax
	Cmp D[BytesLeft], 0
	Jne <ByteLabel
	Cmp D[Pass], 0
	Jne <PassLabel
	Jmp >ExitProc
ExitProcError:
	Invoke SetEnabled, [ShredHandle], TRUE
	Invoke MessageBox, NULL, Addr mbError, NULL, MB_OK
	Jmp >ErrorExit2
ExitProc:
	Invoke CloseHandle, [hFile]
	Invoke MessageBox, NULL, Addr mbText, Addr mbCaption, MB_OK
	Invoke SetValue, [PassHandle], 0
	Invoke SetEnabled, [ShredHandle], TRUE
	Invoke DeleteFile, Addr FilePath
ErrorExit2:
	Ret
EndF

;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
