.Const

.Data

DRIVES_MESSAGES		DD	WM_CREATE, OnDrivesCreate
					DD	WM_COMMAND, OnDrivesCommand
					DD	WM_TIMER, OnDrivesTimer
					DD	WM_CLOSE, OnDrivesClose

szDrive         	DSS	'A:\', 0
szGB            	DSS	' GB', 0
szMB            	DSS	' MB', 0
szFormat        	DSS	'%lu', 0
szDecimal       	DSS	',', 0
szBuffer        	DSS	MAX_PATH Dup 0

dwLogicalDrives 	DD  0
hWndListBox     	DD  NULL


.Code

DrivesProcedure Frame hWnd, uMsg, wParam, lParam
	Mov Eax, [uMsg]
	Mov Ecx, SizeOf DRIVES_MESSAGES / 8
	Mov Edx, Addr DRIVES_MESSAGES
:	Dec Ecx
	Js > L2
	Cmp [Edx + Ecx * 8], Eax
	Jne <
	Call [Edx + Ecx * 8 + 4]
	Ret
L2:	Xor Eax, Eax	;Return (FALSE)
	Ret
EndF

OnDrivesCreate:
	UseData DrivesProcedure

	Invoke SetWaitCursor, [hWnd]
	Invoke ShowWindow, [hWnd], SW_SHOWNORMAL
	Invoke UpdateWindow, [hWnd]
	Invoke LoadString, [App.Instance], IDS_DECIMAL, Addr szDecimal, 2
	Invoke GetPlatform, NULL
	Cmp Eax, ecWin98
	Jle >
	Invoke GetRegistryValue, HKEY_CURRENT_USER, TEXT("Control Panel\International"), TEXT("sDecimal"), Addr szDecimal
	Jmp > L2
:	Invoke GetProfileString, TEXT("intl"), TEXT("sDecimal"), Addr szDecimal, Addr szDecimal, 2

L2:	Invoke GetWindowItem, [hWnd], IDC_DRIVES_LIST1
	Mov [hWndListBox], Eax
	Call RefreshDrives
	Invoke GetLogicalDrives
	Mov [dwLogicalDrives], Eax
	Invoke SetDefaultCursor
	Xor Eax, Eax	;Return (FALSE)
	Ret
EndU

OnDrivesCommand:
	UseData DrivesProcedure

	LoWord ([wParam])
	Cmp Ax, IDC_DRIVES_LIST1
	Jne >
	HiWord ([wParam])
	Cmp Ax, LBN_SELCHANGE
	Jne >
	Invoke SetWaitCursor, [hWnd]
	Invoke SetDriveParameters, [hWndListBox]
	Invoke SetDefaultCursor
	Mov Eax, TRUE
	Ret
:	Xor Eax, Eax	;Return (FALSE)
	Ret
EndU

OnDrivesTimer:
	UseData DrivesProcedure

	Invoke GetLogicalDrives
	Cmp Eax, [dwLogicalDrives]
	Je >
	Mov D[dwLogicalDrives], Eax
	Invoke SetWaitCursor, [hWnd]
	Invoke RefreshDrives
	Invoke SetDefaultCursor
:	Mov Eax, TRUE
	Ret
EndU

OnDrivesClose:
	UseData DrivesProcedure

    Invoke IsModal, [hWnd]
    Or Eax, Eax     ;Cmp Eax, FALSE
    Jz >
    Invoke EndModal, [hWnd], IDCANCEL
    Mov Eax, TRUE   ;Return (TRUE)
:   Ret
EndU

GetCapacityString Frame dwValue, dwDiv1, dwDiv2 Uses Edi, Esi
    Mov Eax, [dwValue]
    Xor Edx, Edx
    Div d[dwDiv1]
    Mov Esi, Edx
    Invoke wsprintf, Addr szBuffer, Addr szFormat, Eax
    Add Esp, 12
    Xchg Eax, Esi
    Add Esi, Offset szBuffer
    Xor Edx, Edx
    Div D[dwDiv2]
    Mov Edi, Edx
    Cmp Eax, 10
    Jl >
    Mov Eax, 9
:   Mov Cl, [szDecimal]
    Mov [Esi], Cl
    Inc Esi
    Invoke wsprintf, Esi, Addr szFormat, Eax
    Add Esp, 12
    Add Esi, Eax
    Mov Eax, [dwDiv2]
    Mov Ecx, 10
    Xor Edx, Edx
    Div Ecx
    Xchg Eax, Edi
    Xor Edx, Edx
    Div Edi
    Shr Edi, 1
    Cmp Eax, 9
    Jge >
    Cmp Edx, Edi
    Jle >
    Add Eax, 1
:   Invoke wsprintf, Esi, Addr szFormat, Eax
    Add Esp, 12
    Ret
EndF

GetDriveTypeStr Frame lType, lpszBuf Uses Edi
    Cmp D[lType], DRIVE_REMOVABLE
    Jne >
    Mov Edi, IDS_REMOVABLE_DRIVE
    Jmp > L2
:   Cmp D[lType], DRIVE_FIXED
    Jne >
    Mov Edi, IDS_FIXED_DRIVE
    Jmp > L2
:   Cmp D[lType], DRIVE_REMOTE
    Jne >
    Mov Edi, IDS_NETWORK_DRIVE
    Jmp > L2
:   Cmp D[lType], DRIVE_CDROM
    Jne >
    Mov Edi, IDS_CD_DVD
    Jmp > L2
:   Cmp D[lType], DRIVE_RAMDISK
    Jne >
    Mov Edi, IDS_RAM_DRIVE
    Jmp > L2
:   Mov Edi, IDS_UNKNOWN

L2: Invoke lstrlen, [lpszBuf]
    Add Eax, [lpszBuf]
    Invoke LoadString, [App.Instance], Edi, Eax, 64
    Invoke lstrlen, [lpszBuf]
    Add Eax, [lpszBuf]
    Mov B[Eax], ')'
    Mov B[Eax + 1], 0
    Ret
EndF

GetNameAndFileSystem Frame lpszDrive
	Local dwMaxCompLen:D, dwFSFlags:D
	Local lpszVolumeName:D, lpszFileSystem:D

	Invoke GlobalAlloc, GPTR, 128
	Or Eax, Eax
	Jz >
	Mov [lpszVolumeName], Eax
	Add Eax, 68
	Mov [lpszFileSystem], Eax
	Invoke GetVolumeInformation, [lpszDrive], [lpszVolumeName], 64, NULL, Addr dwMaxCompLen, Addr dwFSFlags, [lpszFileSystem], 32
	Invoke GetWindowItem, [App.Main], IDC_DRIVES_STCVOLUMELABEL
	Invoke SetWindowText, Eax, [lpszVolumeName]
	Invoke GetWindowItem, [App.Main], IDC_DRIVES_STCFILESYSTEM
	Invoke SetWindowText, Eax, [lpszFileSystem]
	Invoke GlobalFree, [lpszVolumeName]
:	Ret
EndF

RefreshDrives:
    Uses Ebx, Edi, Esi

    Invoke SendMessage, [hWndListBox], LB_GETCURSEL, 0, 0
    Cmp Eax, LB_ERR
    Jne >
    Xor Eax, Eax
:   Mov Ebx, Eax
    Invoke SendMessage, [hWndListBox], LB_RESETCONTENT, 0, 0
    Lea Esi, szDrive
    Mov B[Esi], 'A'
L2: Cmp B[Esi], 'Z'
    Jg > L4
    Invoke GetDriveType, Addr szDrive
    Cmp Eax, DRIVE_NO_ROOT_DIR
    Je >
    Mov Edi, Eax
    Invoke lstrcpy, Addr szBuffer, Addr szDrive
    Lea Eax, szBuffer
    Add Eax, 2
    Mov B[Eax], ' '
    Mov B[Eax + 1], '('
    Mov B[Eax + 2], 0
    Invoke GetDriveTypeStr, Edi, Addr szBuffer
    Invoke SendMessage, [hWndListBox], LB_ADDSTRING, 0, Addr szBuffer
:   Inc B[Esi]
    Jmp < L2
L4: Invoke UpdateWindow, [hWndListBox]
    Invoke SendMessage, [hWndListBox], LB_GETCOUNT, 0, 0
    Or Eax, Eax
    Jz > L6
    Cmp Ebx, Eax
    Jl >
    Mov Ebx, Eax
    Dec Ebx
:   Invoke SendMessage, [hWndListBox], LB_SETCURSEL, Ebx, 0

L6: Invoke SetDriveParameters, [hWndListBox]
    Ret
EndU

SetDriveParameters Frame hLBHandle Uses Ebx, Edi, Esi
    Local dwSectors:D, dwBytes:D, dwFreeClusters:D
    Local dwTotalClusters:D, dwAvailable:Q
    Local dwFreeSpace:Q, dwTotalSpace:Q

    Lea Esi, szBuffer
    Invoke SendMessage, [hLBHandle], LB_GETCURSEL, 0, 0
    Cmp Eax, (-1)
    Jne > L6
    Mov D[Esi], 0
L2: Invoke SetLabelText, IDC_DRIVES_STCTOTALSPACE, Addr szBuffer
    Invoke SetLabelText, IDC_DRIVES_STCFREESPACE, Addr szBuffer
L4: Invoke SetLabelText, IDC_DRIVES_STCTOTAL, Addr szBuffer
    Invoke SetLabelText, IDC_DRIVES_STCFREE, Addr szBuffer
    Invoke SetLabelText, IDC_DRIVES_STCSECTORS, Addr szBuffer
    Invoke SetLabelText, IDC_DRIVES_STCBYTES, Addr szBuffer
    Ret
L6: Invoke SendMessage, [hLBHandle], LB_GETTEXT, Eax, Addr szBuffer
    Mov Al, [Esi]
    Mov [szDrive], Al
    Invoke SetErrorMode, SEM_FAILCRITICALERRORS
    Push Eax
	Invoke GetNameAndFileSystem, Addr szDrive
    Invoke GetDiskFreeSpace, Addr szDrive, Addr dwSectors, Addr dwBytes, Addr dwFreeClusters, Addr dwTotalClusters
    Mov Edi, Eax
    Or Eax, Eax
    Jz > L8
    Invoke GetPlatform, NULL
    Cmp Eax, ecWin98
    Jg > L8
    Cmp Eax, ecWin95
    Jne >
    Invoke LoadLibrary, TEXT("Kernel32.dll")
    Mov Ebx, Eax
    Invoke GetProcAddress, Eax, TEXT("GetDiskFreeSpaceEx")
    Push Eax
    Invoke FreeLibrary, Ebx
    Pop Eax
    Or Eax, Eax
    Jz > L8
:   Invoke GetDiskFreeSpaceEx, Addr szDrive, Addr dwAvailable, Addr dwTotalSpace, Addr dwFreeSpace
    Mov Edi, Eax
    Or Eax, Eax
    Jz > L8
    Lea Edx, dwTotalSpace
    Mov Eax, [Edx]
    Mov Edx, [Edx + 4]
    IDiv D[dwSectors]
    Xor Edx, Edx
    Div D[dwBytes]
    Mov [dwTotalClusters], Eax
    Lea Edx, [dwFreeSpace]
    Mov Eax, [Edx]
    Mov Edx, [Edx + 4]
    IDiv D[dwSectors]
    Xor Edx, Edx
    Div D[dwBytes]
    Mov [dwFreeClusters], Eax
L8: Pop Eax
    Invoke SetErrorMode, Eax
    Or Edi, Edi
    Jnz >
    Invoke LoadString, [App.Instance], IDS_NO_DISK_IN, Addr szBuffer, 64
    Invoke SetLabelText, IDC_DRIVES_STCTOTALSPACE, Addr szBuffer
    Invoke SetLabelText, IDC_DRIVES_STCFREESPACE, Addr szBuffer
    Mov B[Esi], '0'
    Mov B[Esi + 1], 0
    Jmp << L4
:   Mov Eax, [dwTotalClusters]
    Mul D[dwSectors]
    Mov Ecx, 1024
    Div Ecx
    Mov Ecx, Edx
    Shr Ecx, 1
    Mul D[dwBytes]
    Add Eax, Ecx
    Cmp Eax, 1048576 ;(1024 * 1024)
    Jl >
    Lea Ebx, szGB
    Mov Edi, 1048576
    Mov Esi, 104857
    Jmp > L10
:   Lea Ebx, szMB
    Mov Edi, 1024
    Mov Esi, 102
L10:
    Invoke GetCapacityString, Eax, Edi, Esi
    Invoke lstrcat, Addr szBuffer, Ebx
    Invoke SetLabelText, IDC_DRIVES_STCTOTALSPACE, Addr szBuffer

    Mov Eax, [dwFreeClusters]
    Mul D[dwSectors]
    Mov Ecx, 1024
    Div Ecx
    Mov Ecx, Edx
    Shr Ecx, 1
    Mul D[dwBytes]
    Add Eax, Ecx
    Cmp Eax, 1048576 ;(1024 * 1024)
    Jl >
    Lea Ebx, szGB
    Mov Edi, 1048576
    Mov Esi, 104857
    Jmp > L12
:   Lea Ebx, szMB
    Mov Edi, 1024
    Mov Esi, 102
L12:
    Invoke GetCapacityString, Eax, Edi, Esi
    Invoke lstrcat, Addr szBuffer, Ebx
    Invoke SetLabelText, IDC_DRIVES_STCFREESPACE, Addr szBuffer

    Invoke String, [dwTotalClusters], Addr szBuffer, ecDecimal
    Invoke SetLabelText, IDC_DRIVES_STCTOTAL, Addr szBuffer
    Invoke String, [dwFreeClusters], Addr szBuffer, ecDecimal
    Invoke SetLabelText, IDC_DRIVES_STCFREE, Addr szBuffer
    Invoke String, [dwSectors], Addr szBuffer, ecDecimal
    Invoke SetLabelText, IDC_DRIVES_STCSECTORS, Addr szBuffer
    Invoke String, [dwBytes], Addr szBuffer, ecDecimal
    Invoke SetLabelText, IDC_DRIVES_STCBYTES, Addr szBuffer
    Ret
EndF

SetLabelText Frame ulID, lpszText
    Invoke GetWindowItem, [App.Main], [ulID]
    Invoke SetWindowText, Eax, [lpszText]
    Ret
EndF
