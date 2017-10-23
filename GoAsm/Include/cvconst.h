#IFNDEF CVCONST_H
#DEFINE CVCONST_H
// symbols & types enumeration

// SymTagEnum enumeration
#IFNDEF SymTagNull
	SymTagNull = 0
	SymTagExe = 1
	SymTagCompiland = 2
	SymTagCompilandDetails = 3
	SymTagCompilandEnv = 4
	SymTagFunction = 5
	SymTagBlock = 6
	SymTagData = 7
	SymTagAnnotation = 8
	SymTagLabel = 9
	SymTagPublicSymbol = 10
	SymTagUDT = 11
	SymTagEnum = 12
	SymTagFunctionType = 13
	SymTagPointerType = 14
	SymTagArrayType = 15
	SymTagBaseType = 16
	SymTagTypedef = 17
	SymTagBaseClass = 18
	SymTagFriend = 19
	SymTagFunctionArgType = 20
	SymTagFuncDebugStart = 21
	SymTagFuncDebugEnd = 22
	SymTagUsingNamespace = 23
	SymTagVTableShape = 24
	SymTagVTable = 25
	SymTagCustom = 26
	SymTagThunk = 27
	SymTagCustomType = 28
	SymTagManagedType = 29
	SymTagDimension = 30
	SymTagMax = 31
#ENDIF

// BasicType enumeration
btNoType = 0
btVoid = 1
btChar = 2
btWChar = 3
btInt = 6
btUInt = 7
btFloat = 8
btBCD = 9
btBool = 10
btLong = 13
btULong = 14
btCurrency = 25
btDate = 26
btVariant = 27
btComplex = 28
btBit = 29
btBSTR = 30
btHresult = 31

// UdtKind enumeration
UdtStruct = 0
UdtClass = 1
UdtUnion = 2

// LocationType enumeration
LocIsNull = 0
LocIsStatic = 1
LocIsTLS = 2
LocIsRegRel = 3
LocIsThisRel = 4
LocIsEnregistered = 5
LocIsBitField = 6
LocIsSlot = 7
LocIsIlRel = 8
LocInMetaData = 9
LocIsConstant = 10

// DataKind enumeration
DataIsUnknown = 0
DataIsLocal = 1
DataIsStaticLocal = 2
DataIsParam = 3
DataIsObjectPtr = 4
DataIsFileStatic = 5
DataIsGlobal = 6
DataIsMember = 7
DataIsStaticMember = 8
DataIsConstant = 9

// CV_access_e enumeration 
CV_private   = 1
CV_protected = 2
CV_public    = 3

// CV_call_e enumeration 
CV_CALL_NEAR_C    = 0x00
CV_CALL_NEAR_FAST = 0x04
CV_CALL_NEAR_STD  = 0x07
CV_CALL_NEAR_SYS  = 0x09
CV_CALL_THISCALL  = 0x0b
CV_CALL_CLRCALL   = 0x16

// CV_CFL_LANG enumeration 
CV_CFL_C       = 0x00
CV_CFL_CXX     = 0x01
CV_CFL_FORTRAN = 0x02
CV_CFL_MASM    = 0x03
CV_CFL_PASCAL  = 0x04
CV_CFL_BASIC   = 0x05
CV_CFL_COBOL   = 0x06
CV_CFL_LINK    = 0x07
CV_CFL_CVTRES  = 0x08
CV_CFL_CVTPGD  = 0x09
CV_CFL_CSHARP  = 0x0A
CV_CFL_VB      = 0x0B
CV_CFL_ILASM   = 0x0C
CV_CFL_JAVA    = 0x0D
CV_CFL_JSCRIPT = 0x0E
CV_CFL_MSIL    = 0x0F

// CV_CPU_TYPE_e enumeration
CV_CFL_8080         = 0x00
CV_CFL_8086         = 0x01
CV_CFL_80286        = 0x02
CV_CFL_80386        = 0x03
CV_CFL_80486        = 0x04
CV_CFL_PENTIUM      = 0x05
CV_CFL_PENTIUMII    = 0x06
CV_CFL_PENTIUMPRO   = CV_CFL_PENTIUMII
CV_CFL_PENTIUMIII   = 0x07
CV_CFL_MIPS         = 0x10
CV_CFL_MIPSR4000    = CV_CFL_MIPS
CV_CFL_MIPS16       = 0x11
CV_CFL_MIPS32       = 0x12
CV_CFL_MIPS64       = 0x13
CV_CFL_MIPSI        = 0x14
CV_CFL_MIPSII       = 0x15
CV_CFL_MIPSIII      = 0x16
CV_CFL_MIPSIV       = 0x17
CV_CFL_MIPSV        = 0x18
CV_CFL_M68000       = 0x20
CV_CFL_M68010       = 0x21
CV_CFL_M68020       = 0x22
CV_CFL_M68030       = 0x23
CV_CFL_M68040       = 0x24
CV_CFL_ALPHA        = 0x30
CV_CFL_ALPHA_21064  = 0x30
CV_CFL_ALPHA_21164  = 0x31
CV_CFL_ALPHA_21164A = 0x32
CV_CFL_ALPHA_21264  = 0x33
CV_CFL_ALPHA_21364  = 0x34
CV_CFL_PPC601       = 0x40
CV_CFL_PPC603       = 0x41
CV_CFL_PPC604       = 0x42
CV_CFL_PPC620       = 0x43
CV_CFL_PPCFP        = 0x44
CV_CFL_SH3          = 0x50
CV_CFL_SH3E         = 0x51
CV_CFL_SH3DSP       = 0x52
CV_CFL_SH4          = 0x53
CV_CFL_SHMEDIA      = 0x54
CV_CFL_ARM3         = 0x60
CV_CFL_ARM4         = 0x61
CV_CFL_ARM4T        = 0x62
CV_CFL_ARM5         = 0x63
CV_CFL_ARM5T        = 0x64
CV_CFL_ARM6         = 0x65
CV_CFL_ARM_XMAC     = 0x66
CV_CFL_ARM_WMMX     = 0x67
CV_CFL_OMNI         = 0x70
CV_CFL_IA64         = 0x80
CV_CFL_IA64_1       = 0x80
CV_CFL_IA64_2       = 0x81
CV_CFL_CEE          = 0x90
CV_CFL_AM33         = 0xA0
CV_CFL_M32R         = 0xB0
CV_CFL_TRICORE      = 0xC0
CV_CFL_X64          = 0xD0
CV_CFL_AMD64        = CV_CFL_X64
CV_CFL_EBC          = 0xE0
CV_CFL_THUMB        = 0xF0

// MemoryTypeEnum enumeration
MemTypeCode = 0
MemTypeData = 1
MemTypeStack = 2
MemTypeAny = -1

// NameSearchOptions enumeration 
nsNone = 0
nsfCaseSensitive     = 0x1
nsfCaseInsensitive   = 0x2
nsfFNameExt          = 0x4
nsfRegularExpression = 0x8
nsfUndecoratedName   = 0x10

// For backward compabibility:
nsCaseSensitive = 0x1
nsCaseInsensitive = 0x2
nsFNameExt = 0x4
nsRegularExpression       = nsfRegularExpression | nsfCaseSensitive
nsCaseInRegularExpression = nsfRegularExpression | nsfCaseInsensitive

// StackFrameTypeEnum enumeration
FrameTypeFPO = 0
FrameTypeTrap = 1
FrameTypeTSS = 2
FrameTypeStandard = 3
FrameTypeFrameData = 4
FrameTypeUnknown = -1

// CV_HREG_e enumeration

// those values are common to all supported CPUs (and CPU independant)
CV_ALLREG_ERR       = 30000
CV_ALLREG_TEB       = 30001
CV_ALLREG_TIMER     = 30002
CV_ALLREG_EFAD1     = 30003
CV_ALLREG_EFAD2     = 30004
CV_ALLREG_EFAD3     = 30005
CV_ALLREG_VFRAME    = 30006
CV_ALLREG_HANDLE    = 30007
CV_ALLREG_PARAMS    = 30008
CV_ALLREG_LOCALS    = 30009

// Intel x86 CPU
CV_REG_NONE         = 0
CV_REG_AL           = 1
CV_REG_CL           = 2
CV_REG_DL           = 3
CV_REG_BL           = 4
CV_REG_AH           = 5
CV_REG_CH           = 6
CV_REG_DH           = 7
CV_REG_BH           = 8
CV_REG_AX           = 9
CV_REG_CX           = 10
CV_REG_DX           = 11
CV_REG_BX           = 12
CV_REG_SP           = 13
CV_REG_BP           = 14
CV_REG_SI           = 15
CV_REG_DI           = 16
CV_REG_EAX          = 17
CV_REG_ECX          = 18
CV_REG_EDX          = 19
CV_REG_EBX          = 20
CV_REG_ESP          = 21
CV_REG_EBP          = 22
CV_REG_ESI          = 23
CV_REG_EDI          = 24
CV_REG_ES           = 25
CV_REG_CS           = 26
CV_REG_SS           = 27
CV_REG_DS           = 28
CV_REG_FS           = 29
CV_REG_GS           = 30
CV_REG_IP           = 31
CV_REG_FLAGS        = 32
CV_REG_EIP          = 33
CV_REG_EFLAGS       = 34

// <pcode>
CV_REG_TEMP         = 40
CV_REG_TEMPH        = 41
CV_REG_QUOTE        = 42
CV_REG_PCDR3        = 43   // this includes PCDR4 to PCDR7
CV_REG_CR0          = 80   // this includes CR1 to CR4
CV_REG_DR0          = 90   // this includes DR1 to DR7
// </pcode>

CV_REG_GDTR         = 110
CV_REG_GDTL         = 111
CV_REG_IDTR         = 112
CV_REG_IDTL         = 113
CV_REG_LDTR         = 114
CV_REG_TR           = 115

CV_REG_PSEUDO1      = 116 // this includes Pseudo02 to Pseuso09
CV_REG_ST0          = 128 // this includes ST1 to ST7
CV_REG_CTRL         = 136
CV_REG_STAT         = 137
CV_REG_TAG          = 138
CV_REG_FPIP         = 139
CV_REG_FPCS         = 140
CV_REG_FPDO         = 141
CV_REG_FPDS         = 142
CV_REG_ISEM         = 143
CV_REG_FPEIP        = 144
CV_REG_FPEDO        = 145
CV_REG_MM0          = 146 // this includes MM1 to MM7
CV_REG_XMM0         = 154 // this includes XMM1 to XMM7
CV_REG_XMM00        = 162
CV_REG_XMM0L        = 194 // this includes XMM1L to XMM7L
CV_REG_XMM0H        = 202 // this includes XMM1H to XMM7H
CV_REG_MXCSR        = 211
CV_REG_EDXEAX       = 212
CV_REG_EMM0L        = 220
CV_REG_EMM0H        = 228
CV_REG_MM00         = 236
CV_REG_MM01         = 237
CV_REG_MM10         = 238
CV_REG_MM11         = 239
CV_REG_MM20         = 240
CV_REG_MM21         = 241
CV_REG_MM30         = 242
CV_REG_MM31         = 243
CV_REG_MM40         = 244
CV_REG_MM41         = 245
CV_REG_MM50         = 246
CV_REG_MM51         = 247
CV_REG_MM60         = 248
CV_REG_MM61         = 249
CV_REG_MM70         = 250
CV_REG_MM71         = 251

// Motorola 68K CPU
CV_R68_D0           = 0 // this includes D1 to D7 too
CV_R68_A0           = 8 // this includes A1 to A7 too
CV_R68_CCR          = 16
CV_R68_SR           = 17
CV_R68_USP          = 18
CV_R68_MSP          = 19
CV_R68_SFC          = 20
CV_R68_DFC          = 21
CV_R68_CACR         = 22
CV_R68_VBR          = 23
CV_R68_CAAR         = 24
CV_R68_ISP          = 25
CV_R68_PC           = 26
CV_R68_FPCR         = 28
CV_R68_FPSR         = 29
CV_R68_FPIAR        = 30
CV_R68_FP0          = 32 // this includes FP1 to FP7
CV_R68_MMUSR030     = 41
CV_R68_MMUSR        = 42
CV_R68_URP          = 43
CV_R68_DTT0         = 44
CV_R68_DTT1         = 45
CV_R68_ITT0         = 46
CV_R68_ITT1         = 47
CV_R68_PSR          = 51
CV_R68_PCSR         = 52
CV_R68_VAL          = 53
CV_R68_CRP          = 54
CV_R68_SRP          = 55
CV_R68_DRP          = 56
CV_R68_TC           = 57
CV_R68_AC           = 58
CV_R68_SCC          = 59
CV_R68_CAL          = 60
CV_R68_TT0          = 61
CV_R68_TT1          = 62
CV_R68_BAD0         = 64 // this includes BAD1 to BAD7
CV_R68_BAC0         = 72 // this includes BAC1 to BAC7

// MIPS 4000 CPU
CV_M4_NOREG         = CV_REG_NONE
CV_M4_IntZERO       = 10
CV_M4_IntAT         = 11
CV_M4_IntV0         = 12
CV_M4_IntV1         = 13
CV_M4_IntA0         = 14 // this includes IntA1 to IntA3
CV_M4_IntT0         = 18 // this includes IntT1 to IntT7
CV_M4_IntS0         = 26 // this includes IntS1 to IntS7
CV_M4_IntT8         = 34
CV_M4_IntT9         = 35
CV_M4_IntKT0        = 36
CV_M4_IntKT1        = 37
CV_M4_IntGP         = 38
CV_M4_IntSP         = 39
CV_M4_IntS8         = 40
CV_M4_IntRA         = 41
CV_M4_IntLO         = 42
CV_M4_IntHI         = 43
CV_M4_Fir           = 50
CV_M4_Psr           = 51
CV_M4_FltF0         = 60 // this includes FltF1 to Flt31
CV_M4_FltFsr        = 92

// Alpha AXP CPU
CV_ALPHA_NOREG      = CV_REG_NONE
CV_ALPHA_FltF0      = 10 // this includes FltF1 to FltF31
CV_ALPHA_IntV0      = 42
CV_ALPHA_IntT0      = 43 // this includes T1 to T7
CV_ALPHA_IntS0      = 51 // this includes S1 to S5
CV_ALPHA_IntFP      = 57
CV_ALPHA_IntA0      = 58 // this includes A1 to A5
CV_ALPHA_IntT8      = 64
CV_ALPHA_IntT9      = 65
CV_ALPHA_IntT10     = 66
CV_ALPHA_IntT11     = 67
CV_ALPHA_IntRA      = 68
CV_ALPHA_IntT12     = 69
CV_ALPHA_IntAT      = 70
CV_ALPHA_IntGP      = 71
CV_ALPHA_IntSP      = 72
CV_ALPHA_IntZERO    = 73
CV_ALPHA_Fpcr       = 74
CV_ALPHA_Fir        = 75
CV_ALPHA_Psr        = 76
CV_ALPHA_FltFsr     = 77
CV_ALPHA_SoftFpcr   = 78

// Motorola & IBM PowerPC CPU
CV_PPC_GPR0         = 1 // this includes GPR1 to GPR31
CV_PPC_CR           = 33
CV_PPC_CR0          = 34 // this includes CR1 to CR7
CV_PPC_FPR0         = 42 // this includes FPR1 to FPR31

CV_PPC_FPSCR        = 74
CV_PPC_MSR          = 75
CV_PPC_SR0          = 76 // this includes SR1 to SR15
// some PPC registers missing

// Hitachi SH3 CPU
CV_SH3_NOREG        = CV_REG_NONE
CV_SH3_IntR0        = 10 // this include R1 to R13
CV_SH3_IntFp        = 24
CV_SH3_IntSp        = 25
CV_SH3_Gbr          = 38
CV_SH3_Pr           = 39
CV_SH3_Mach         = 40
CV_SH3_Macl         = 41
CV_SH3_Pc           = 50
CV_SH3_Sr           = 51
CV_SH3_BarA         = 60
CV_SH3_BasrA        = 61
CV_SH3_BamrA        = 62
CV_SH3_BbrA         = 63
CV_SH3_BarB         = 64
CV_SH3_BasrB        = 65
CV_SH3_BamrB        = 66
CV_SH3_BbrB         = 67
CV_SH3_BdrB         = 68
CV_SH3_BdmrB        = 69
CV_SH3_Brcr         = 70
CV_SH_Fpscr         = 75
CV_SH_Fpul          = 76
CV_SH_FpR0          = 80 // this includes FpR1 to FpR15
CV_SH_XFpR0         = 96 // this includes XFpR1 to XXFpR15

// ARM CPU
CV_ARM_NOREG        = CV_REG_NONE
CV_ARM_R0           = 10 // this includes R1 to R12
CV_ARM_SP           = 23
CV_ARM_LR           = 24
CV_ARM_PC           = 25
CV_ARM_CPSR         = 26

// Intel IA64 CPU
CV_IA64_NOREG       = CV_REG_NONE
CV_IA64_Br0         = 512 // this includes Br1 to Br7
CV_IA64_P0          = 704 // this includes P1 to P63
CV_IA64_Preds       = 768
CV_IA64_IntH0       = 832 // this includes H1 to H15
CV_IA64_Ip          = 1016
CV_IA64_Umask       = 1017
CV_IA64_Cfm         = 1018
CV_IA64_Psr         = 1019
CV_IA64_Nats        = 1020
CV_IA64_Nats2       = 1021
CV_IA64_Nats3       = 1022
CV_IA64_IntR0       = 1024 // this includes R1 to R127
CV_IA64_FltF0       = 2048 // this includes FltF1 to FltF127
// some IA64 registers missing

// TriCore CPU
CV_TRI_NOREG        = CV_REG_NONE
CV_TRI_D0           = 10 // includes D1 to D15
CV_TRI_A0           = 26 // includes A1 to A15
CV_TRI_E0           = 42
CV_TRI_E2           = 43
CV_TRI_E4           = 44
CV_TRI_E6           = 45
CV_TRI_E8           = 46
CV_TRI_E10          = 47
CV_TRI_E12          = 48
CV_TRI_E14          = 49
CV_TRI_EA0          = 50
CV_TRI_EA2          = 51
CV_TRI_EA4          = 52
CV_TRI_EA6          = 53
CV_TRI_EA8          = 54
CV_TRI_EA10         = 55
CV_TRI_EA12         = 56
CV_TRI_EA14         = 57
// some TriCode registers missing

// AM33 (and the likes) CPU
CV_AM33_NOREG       = CV_REG_NONE
CV_AM33_E0          = 10 // this includes E1 to E7
CV_AM33_A0          = 20 // this includes A1 to A3
CV_AM33_D0          = 30 // this includes D1 to D3
CV_AM33_FS0         = 40 // this includes FS1 to FS31

// Mitsubishi M32R CPU
CV_M32R_NOREG       = CV_REG_NONE
CV_M32R_R0          = 10 // this includes R1 to R11
CV_M32R_R12         = 22
CV_M32R_R13         = 23
CV_M32R_R14         = 24
CV_M32R_R15         = 25
CV_M32R_PSW         = 26
CV_M32R_CBR         = 27
CV_M32R_SPI         = 28
CV_M32R_SPU         = 29
CV_M32R_SPO         = 30
CV_M32R_BPC         = 31
CV_M32R_ACHI        = 32
CV_M32R_ACLO        = 33
CV_M32R_PC          = 34

// THUNK_ORDINAL enumeration
THUNK_ORDINAL_NOTYPE = 0
THUNK_ORDINAL_ADJUSTOR = 1
THUNK_ORDINAL_VCALL = 2
THUNK_ORDINAL_PCODE = 3
THUNK_ORDINAL_LOAD = 4

#ENDIF