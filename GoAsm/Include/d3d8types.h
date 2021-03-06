#ifndef D3D8TYPES_H
#define D3D8TYPES_H

/* Direct3D type definitions */

#ifndef DIRECT3D_VERSION
	#define DIRECT3D_VERSION  0x0800
#endif

#if DIRECT3D_VERSION >= 0x0800

#ifndef D3DVECTOR
	D3DVECTOR STRUCT
		x FLOAT
		y FLOAT
		z FLOAT
	ENDS
#endif

#ifndef D3DCOLORVALUE
	D3DCOLORVALUE STRUCT
		r FLOAT
		g FLOAT
		b FLOAT
		a FLOAT
	ENDS
#endif

#ifndef D3DRECT
	D3DRECT STRUCT
		x1 DD
		y1 DD
		x2 DD
		y2 DD
	ENDS
#endif

#ifndef D3DMATRIX
	D3DMATRIX STRUCT
		UNION
			matrix STRUCT
				_11 DD
				_12 DD
				_13 DD
				_14 DD
				_21 DD
				_22 DD
				_23 DD
				_24 DD
				_31 DD
				_32 DD
				_33 DD
				_34 DD
				_41 DD
				_42 DD
				_43 DD
				_44 DD
			ENDS
		ENDUNION
	ENDS
#endif

D3DVIEWPORT8 STRUCT
	X DD
	Y DD
	Width DD
	Height DD
	MinZ FLOAT
	MaxZ FLOAT
ENDS

#define D3DMAXUSERCLIPPLANES 32

#define D3DCLIPPLANE0  1
#define D3DCLIPPLANE1  2
#define D3DCLIPPLANE2  4
#define D3DCLIPPLANE3  8
#define D3DCLIPPLANE4  16
#define D3DCLIPPLANE5  32

#define D3DCS_LEFT  0x00000001
#define D3DCS_RIGHT  0x00000002
#define D3DCS_TOP  0x00000004
#define D3DCS_BOTTOM  0x00000008
#define D3DCS_FRONT  0x00000010
#define D3DCS_BACK  0x00000020
#define D3DCS_PLANE0  0x00000040
#define D3DCS_PLANE1  0x00000080
#define D3DCS_PLANE2  0x00000100
#define D3DCS_PLANE3  0x00000200
#define D3DCS_PLANE4  0x00000400
#define D3DCS_PLANE5  0x00000800

#define D3DCS_ALL (D3DCS_LEFT|D3DCS_RIGHT|D3DCS_TOP|D3DCS_BOTTOM|D3DCS_FRONT|D3DCS_BACK|D3DCS_PLANE0|D3DCS_PLANE1|D3DCS_PLANE2|D3DCS_PLANE3|D3DCS_PLANE4|D3DCS_PLANE5)

#define D3DCLEAR_TARGET  0x00000001l
#define D3DCLEAR_ZBUFFER  0x00000002l
#define D3DCLEAR_STENCIL  0x00000004l

#define D3DTS_WORLD  256
#define D3DTS_WORLD1  257
#define D3DTS_WORLD2 258
#define D3DTS_WORLD3  259

#define D3DRENDERSTATE_WRAPBIAS  128

#define D3DWRAP_U  0x00000001
#define D3DWRAP_V  0x00000002
#define D3DWRAP_W  0x00000004

#define D3DWRAPCOORD_0  0x00000001
#define D3DWRAPCOORD_1  0x00000002
#define D3DWRAPCOORD_2  0x00000004
#define D3DWRAPCOORD_3  0x00000008

#define D3DCOLORWRITEENABLE_RED  1
#define D3DCOLORWRITEENABLE_GREEN  2
#define D3DCOLORWRITEENABLE_BLUE  4
#define D3DCOLORWRITEENABLE_ALPHA  8

#define D3DTSS_TCI_PASSTHRU  0x00000000
#define D3DTSS_TCI_CAMERASPACENORMAL  0x00010000
#define D3DTSS_TCI_CAMERASPACEPOSITION  0x00020000
#define D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR  0x00030000

#define D3DTA_SELECTMASK  0x0000000f
#define D3DTA_DIFFUSE  0x00000000
#define D3DTA_CURRENT  0x00000001
#define D3DTA_TEXTURE  0x00000002
#define D3DTA_TFACTOR  0x00000003
#define D3DTA_SPECULAR  0x00000004
#define D3DTA_TEMP  0x00000005
#define D3DTA_COMPLEMENT  0x00000010
#define D3DTA_ALPHAREPLICATE  0x00000020

#define D3DPV_DONOTCOPYDATA  1

#define D3DFVF_RESERVED0  0x001
#define D3DFVF_POSITION_MASK  0x00E
#define D3DFVF_XYZ  0x002
#define D3DFVF_XYZRHW  0x004
#define D3DFVF_XYZB1  0x006
#define D3DFVF_XYZB2  0x008
#define D3DFVF_XYZB3  0x00a
#define D3DFVF_XYZB4  0x00c
#define D3DFVF_XYZB5  0x00e

#define D3DFVF_NORMAL  0x010
#define D3DFVF_PSIZE  0x020
#define D3DFVF_DIFFUSE  0x040
#define D3DFVF_SPECULAR  0x080

#define D3DFVF_TEXCOUNT_MASK  0xf00
#define D3DFVF_TEXCOUNT_SHIFT  8
#define D3DFVF_TEX0  0x000
#define D3DFVF_TEX1  0x100
#define D3DFVF_TEX2  0x200
#define D3DFVF_TEX3  0x300
#define D3DFVF_TEX4  0x400
#define D3DFVF_TEX5  0x500
#define D3DFVF_TEX6  0x600
#define D3DFVF_TEX7  0x700
#define D3DFVF_TEX8  0x800

#define D3DFVF_LASTBETA_UBYTE4  0x1000
#define D3DFVF_RESERVED2  0xE000

#define D3DVSD_TOKENTYPESHIFT  29
#define D3DVSD_TOKENTYPEMASK  (7<<D3DVSD_TOKENTYPESHIFT)

#define D3DVSD_STREAMNUMBERSHIFT  0
#define D3DVSD_STREAMNUMBERMASK  (0xF<<D3DVSD_STREAMNUMBERSHIFT)

#define D3DVSD_DATALOADTYPESHIFT  28
#define D3DVSD_DATALOADTYPEMASK  (0x1<<D3DVSD_DATALOADTYPESHIFT)

#define D3DVSD_DATATYPESHIFT  16
#define D3DVSD_DATATYPEMASK  (0xF<<D3DVSD_DATATYPESHIFT)

#define D3DVSD_SKIPCOUNTSHIFT  16
#define D3DVSD_SKIPCOUNTMASK  (0xF<<D3DVSD_SKIPCOUNTSHIFT)

#define D3DVSD_VERTEXREGSHIFT  0
#define D3DVSD_VERTEXREGMASK  (0x1F<<D3DVSD_VERTEXREGSHIFT)

#define D3DVSD_VERTEXREGINSHIFT  20
#define D3DVSD_VERTEXREGINMASK  (0xF<<D3DVSD_VERTEXREGINSHIFT)

#define D3DVSD_CONSTCOUNTSHIFT  25
#define D3DVSD_CONSTCOUNTMASK  (0xF<<D3DVSD_CONSTCOUNTSHIFT)

#define D3DVSD_CONSTADDRESSSHIFT  0
#define D3DVSD_CONSTADDRESSMASK  (0x7F<<D3DVSD_CONSTADDRESSSHIFT)

#define D3DVSD_CONSTRSSHIFT  16
#define D3DVSD_CONSTRSMASK  (0x1FFF<<D3DVSD_CONSTRSSHIFT)

#define D3DVSD_EXTCOUNTSHIFT  24
#define D3DVSD_EXTCOUNTMASK  (0x1F<<D3DVSD_EXTCOUNTSHIFT)

#define D3DVSD_EXTINFOSHIFT  0
#define D3DVSD_EXTINFOMASK  (0xFFFFFF<<D3DVSD_EXTINFOSHIFT)

#define D3DVSD_MAKETOKENTYPE(tokenType)  ((tokenType<<D3DVSD_TOKENTYPESHIFT)&D3DVSD_TOKENTYPEMASK)

#define D3DVSD_STREAM(_StreamNumber)  (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAM)|(_StreamNumber))

#define D3DVSD_STREAMTESSSHIFT  28
#define D3DVSD_STREAMTESSMASK  (1<<D3DVSD_STREAMTESSSHIFT)

#define D3DVSD_END  0xFFFFFFFF
#define D3DVSD_NOP  0x00000000

#define D3DVSDT_FLOAT1  0x00
#define D3DVSDT_FLOAT2  0x01
#define D3DVSDT_FLOAT3  0x02
#define D3DVSDT_FLOAT4  0x03
#define D3DVSDT_D3DCOLOR  0x04

#define D3DVSDT_UBYTE4  0x05
#define D3DVSDT_SHORT2  0x06
#define D3DVSDT_SHORT4  0x07

#define D3DVSDE_POSITION  0
#define D3DVSDE_BLENDWEIGHT  1
#define D3DVSDE_BLENDINDICES  2
#define D3DVSDE_NORMAL  3
#define D3DVSDE_PSIZE  4
#define D3DVSDE_DIFFUSE  5
#define D3DVSDE_SPECULAR  6
#define D3DVSDE_TEXCOORD0  7
#define D3DVSDE_TEXCOORD1  8
#define D3DVSDE_TEXCOORD2  9
#define D3DVSDE_TEXCOORD3  10
#define D3DVSDE_TEXCOORD4  11
#define D3DVSDE_TEXCOORD5  12
#define D3DVSDE_TEXCOORD6  13
#define D3DVSDE_TEXCOORD7  14
#define D3DVSDE_POSITION2  15
#define D3DVSDE_NORMAL2  16

#define D3DDP_MAXTEXCOORD  8

#define D3DSI_OPCODE_MASK  0x0000FFFF

#define D3DSI_COISSUE  0x40000000

#define D3DSP_REGNUM_MASK  0x00001FFF

#define D3DSP_WRITEMASK_0  0x00010000
#define D3DSP_WRITEMASK_1  0x00020000
#define D3DSP_WRITEMASK_2  0x00040000
#define D3DSP_WRITEMASK_3  0x00080000
#define D3DSP_WRITEMASK_ALL  0x000F0000

#define D3DSP_DSTMOD_SHIFT  20
#define D3DSP_DSTMOD_MASK  0x00F00000

#define D3DSP_DSTSHIFT_SHIFT  24
#define D3DSP_DSTSHIFT_MASK  0x0F000000

#define D3DSP_REGTYPE_SHIFT  28
#define D3DSP_REGTYPE_MASK  0x70000000

#define D3DVS_ADDRESSMODE_SHIFT  13
#define D3DVS_ADDRESSMODE_MASK  1<<13

#define D3DVS_SWIZZLE_SHIFT  16
#define D3DVS_SWIZZLE_MASK  0x00FF0000

#define D3DVS_X_X  (0<<D3DVS_SWIZZLE_SHIFT)
#define D3DVS_X_Y  (1<<D3DVS_SWIZZLE_SHIFT)
#define D3DVS_X_Z  (2<<D3DVS_SWIZZLE_SHIFT)
#define D3DVS_X_W  (3<<D3DVS_SWIZZLE_SHIFT)

#define D3DVS_Y_X  (0<<(D3DVS_SWIZZLE_SHIFT+2))
#define D3DVS_Y_Y  (1<<(D3DVS_SWIZZLE_SHIFT+2))
#define D3DVS_Y_Z  (2<<(D3DVS_SWIZZLE_SHIFT+2))
#define D3DVS_Y_W  (3<<(D3DVS_SWIZZLE_SHIFT+2))

#define D3DVS_Z_X  (0<<(D3DVS_SWIZZLE_SHIFT+4))
#define D3DVS_Z_Y  (1<<(D3DVS_SWIZZLE_SHIFT+4))
#define D3DVS_Z_Z  (2<<(D3DVS_SWIZZLE_SHIFT+4))
#define D3DVS_Z_W  (3<<(D3DVS_SWIZZLE_SHIFT+4))

#define D3DVS_W_X  (0<<(D3DVS_SWIZZLE_SHIFT+6))
#define D3DVS_W_Y  (1<<(D3DVS_SWIZZLE_SHIFT+6))
#define D3DVS_W_Z  (2<<(D3DVS_SWIZZLE_SHIFT+6))
#define D3DVS_W_W  (3<<(D3DVS_SWIZZLE_SHIFT+6))

#define D3DVS_NOSWIZZLE  (D3DVS_X_X|D3DVS_Y_Y|D3DVS_Z_Z|D3DVS_W_W)

#define D3DSP_SWIZZLE_SHIFT  16
#define D3DSP_SWIZZLE_MASK  0x00FF0000

#define D3DSP_NOSWIZZLE  (1<<(D3DSP_SWIZZLE_SHIFT+2))|(2<<(D3DSP_SWIZZLE_SHIFT+4))|(3<<(D3DSP_SWIZZLE_SHIFT+6)))
#define D3DSP_REPLICATERED  0
#define D3DSP_REPLICATEGREEN  ((1<<(D3DSP_SWIZZLE_SHIFT+0))|(1<<(D3DSP_SWIZZLE_SHIFT+2))|(1<<(D3DSP_SWIZZLE_SHIFT+4))|(1<<(D3DSP_SWIZZLE_SHIFT+6)))
#define D3DSP_REPLICATEBLUE  ((2<<(D3DSP_SWIZZLE_SHIFT+0))|(2<<(D3DSP_SWIZZLE_SHIFT+2))|(2<<(D3DSP_SWIZZLE_SHIFT+4))|(2<<(D3DSP_SWIZZLE_SHIFT+6)))
#define D3DSP_REPLICATEALPHA  ((3<<(D3DSP_SWIZZLE_SHIFT+0))|(3<<(D3DSP_SWIZZLE_SHIFT+2))|(3<<(D3DSP_SWIZZLE_SHIFT+4))|(3<<(D3DSP_SWIZZLE_SHIFT+6)))

#define D3DSP_SRCMOD_SHIFT  24
#define D3DSP_SRCMOD_MASK  0x0F000000

#define D3DSI_COMMENTSIZE_SHIFT  16
#define D3DSI_COMMENTSIZE_MASK  0x7FFF0000

#define D3DPS_END  0x0000FFFF
#define D3DVS_END  0x0000FFFF

#define D3DFVF_TEXTUREFORMAT2  0
#define D3DFVF_TEXTUREFORMAT1  3
#define D3DFVF_TEXTUREFORMAT3  1
#define D3DFVF_TEXTUREFORMAT4  2

#define D3DPRESENT_RATE_DEFAULT  0x00000000
#define D3DPRESENT_RATE_UNLIMITED  0x7fffffff

#define D3DPRESENTFLAG_LOCKABLE_BACKBUFFER  0x00000001

#define D3DUSAGE_RENDERTARGET  0x00000001
#define D3DUSAGE_DEPTHSTENCIL  0x00000002
#define D3DUSAGE_WRITEONLY  0x00000008
#define D3DUSAGE_SOFTWAREPROCESSING  0x00000010
#define D3DUSAGE_DONOTCLIP  0x00000020
#define D3DUSAGE_POINTS  0x00000040
#define D3DUSAGE_RTPATCHES  0x00000080
#define D3DUSAGE_NPATCHES  0x00000100
#define D3DUSAGE_DYNAMIC  0x00000200

#define D3DLOCK_READONLY  0x00000010
#define D3DLOCK_DISCARD  0x00002000
#define D3DLOCK_NOOVERWRITE  0x00001000
#define D3DLOCK_NOSYSLOCK  0x00000800
#define D3DLOCK_NO_DIRTY_UPDATE  0x00008000

#define MAX_DEVICE_IDENTIFIER_STRING  512

D3DCLIPSTATUS8 STRUCT
	ClipUnion DD
	ClipIntersection DD
ENDS

D3DMATERIAL8 STRUCT
	Diffuse D3DCOLORVALUE
	Ambient D3DCOLORVALUE
	Specular D3DCOLORVALUE
	Emissive D3DCOLORVALUE
	Power FLOAT
ENDS

D3DLIGHT_POINT = 1
D3DLIGHT_SPOT = 2
D3DLIGHT_DIRECTIONAL = 3
D3DLIGHT_FORCE_DWORD = 0x7fffffff

D3DLIGHT8 STRUCT
	Type DD
	Diffuse D3DCOLORVALUE
	Specular D3DCOLORVALUE
	Ambient D3DCOLORVALUE
	Position D3DVECTOR
	Direction D3DVECTOR
	Range FLOAT
	Falloff FLOAT
	Attenuation0 FLOAT
	Attenuation1 FLOAT
	Attenuation2 FLOAT
	Theta FLOAT
	Phi FLOAT
ENDS

D3DSHADE_FLAT  = 1
D3DSHADE_GOURAUD = 2
D3DSHADE_PHONG = 3
D3DSHADE_FORCE_DWORD = 0x7fffffff

D3DFILL_POINT  = 1
D3DFILL_WIREFRAME  = 2
D3DFILL_SOLID = 3
D3DFILL_FORCE_DWORD = 0x7fffffff

D3DLINEPATTERN STRUCT
	wRepeatFactor DW
	wLinePattern DW
ENDS

D3DBLEND_ZERO = 1
D3DBLEND_ONE = 2
D3DBLEND_SRCCOLOR = 3
D3DBLEND_INVSRCCOLOR = 4
D3DBLEND_SRCALPHA = 5
D3DBLEND_INVSRCALPHA = 6
D3DBLEND_DESTALPHA = 7
D3DBLEND_INVDESTALPHA = 8
D3DBLEND_DESTCOLOR = 9
D3DBLEND_INVDESTCOLOR = 10
D3DBLEND_SRCALPHASAT = 11
D3DBLEND_BOTHSRCALPHA = 12
D3DBLEND_BOTHINVSRCALPHA = 13
D3DBLEND_FORCE_DWORD = 0x7fffffff

D3DBLENDOP_ADD = 1
D3DBLENDOP_SUBTRACT = 2
D3DBLENDOP_REVSUBTRACT = 3
D3DBLENDOP_MIN = 4
D3DBLENDOP_MAX = 5
D3DBLENDOP_FORCE_DWORD = 0x7fffffff

D3DTADDRESS_WRAP = 1
D3DTADDRESS_MIRROR = 2
D3DTADDRESS_CLAMP = 3
D3DTADDRESS_BORDER = 4
D3DTADDRESS_MIRRORONCE = 5
D3DTADDRESS_FORCE_DWORD = 0x7fffffff

D3DCULL_NONE = 1
D3DCULL_CW = 2
D3DCULL_CCW = 3
D3DCULL_FORCE_DWORD = 0x7fffffff

D3DCMP_NEVER = 1
D3DCMP_LESS = 2
D3DCMP_EQUAL = 3
D3DCMP_LESSEQUAL = 4
D3DCMP_GREATER = 5
D3DCMP_NOTEQUAL = 6
D3DCMP_GREATEREQUAL = 7
D3DCMP_ALWAYS = 8
D3DCMP_FORCE_DWORD = 0x7fffffff

D3DSTENCILOP_KEEP = 1
D3DSTENCILOP_ZERO = 2
D3DSTENCILOP_REPLACE = 3
D3DSTENCILOP_INCRSAT = 4
D3DSTENCILOP_DECRSAT = 5
D3DSTENCILOP_INVERT = 6
D3DSTENCILOP_INCR = 7
D3DSTENCILOP_DECR = 8
D3DSTENCILOP_FORCE_DWORD = 0x7fffffff

D3DFOG_NONE = 0
D3DFOG_EXP = 1
D3DFOG_EXP2 = 2
D3DFOG_LINEAR = 3
D3DFOG_FORCE_DWORD = 0x7fffffff

D3DZB_FALSE = 0
D3DZB_TRUE = 1
D3DZB_USEW = 2
D3DZB_FORCE_DWORD = 0x7fffffff

D3DPT_POINTLIST = 1
D3DPT_LINELIST = 2
D3DPT_LINESTRIP = 3
D3DPT_TRIANGLELIST = 4
D3DPT_TRIANGLESTRIP = 5
D3DPT_TRIANGLEFAN = 6
D3DPT_FORCE_DWORD = 0x7fffffff

D3DTS_VIEW = 2
D3DTS_PROJECTION = 3
D3DTS_TEXTURE0 = 16
D3DTS_TEXTURE1 = 17
D3DTS_TEXTURE2 = 18
D3DTS_TEXTURE3 = 19
D3DTS_TEXTURE4 = 20
D3DTS_TEXTURE5 = 21
D3DTS_TEXTURE6 = 22
D3DTS_TEXTURE7 = 23
D3DTS_FORCE_DWORD = 0x7fffffff

D3DRS_ZENABLE = 7
D3DRS_FILLMODE = 8
D3DRS_SHADEMODE = 9
D3DRS_LINEPATTERN = 10
D3DRS_ZWRITEENABLE = 14
D3DRS_ALPHATESTENABLE = 15
D3DRS_LASTPIXEL = 16
D3DRS_SRCBLEND = 19
D3DRS_DESTBLEND = 20
D3DRS_CULLMODE = 22
D3DRS_ZFUNC = 23
D3DRS_ALPHAREF = 24
D3DRS_ALPHAFUNC = 25
D3DRS_DITHERENABLE = 26
D3DRS_ALPHABLENDENABLE = 27
D3DRS_FOGENABLE = 28
D3DRS_SPECULARENABLE = 29
D3DRS_ZVISIBLE = 30
D3DRS_FOGCOLOR = 34
D3DRS_FOGTABLEMODE = 35
D3DRS_FOGSTART = 36
D3DRS_FOGEND = 37
D3DRS_FOGDENSITY = 38
D3DRS_EDGEANTIALIAS = 40
D3DRS_ZBIAS = 47
D3DRS_RANGEFOGENABLE = 48
D3DRS_STENCILENABLE = 52
D3DRS_STENCILFAIL = 53
D3DRS_STENCILZFAIL = 54
D3DRS_STENCILPASS = 55
D3DRS_STENCILFUNC = 56
D3DRS_STENCILREF = 57
D3DRS_STENCILMASK = 58
D3DRS_STENCILWRITEMASK = 59
D3DRS_TEXTUREFACTOR = 60
D3DRS_WRAP0 = 128
D3DRS_WRAP1 = 129
D3DRS_WRAP2 = 130
D3DRS_WRAP3 = 131
D3DRS_WRAP4 = 132
D3DRS_WRAP5 = 133
D3DRS_WRAP6 = 134
D3DRS_WRAP7 = 135
D3DRS_CLIPPING = 136
D3DRS_LIGHTING = 137
D3DRS_AMBIENT = 139
D3DRS_FOGVERTEXMODE = 140
D3DRS_COLORVERTEX = 141
D3DRS_LOCALVIEWER = 142
D3DRS_NORMALIZENORMALS = 143
D3DRS_DIFFUSEMATERIALSOURCE = 145
D3DRS_SPECULARMATERIALSOURCE = 146
D3DRS_AMBIENTMATERIALSOURCE = 147
D3DRS_EMISSIVEMATERIALSOURCE = 148
D3DRS_VERTEXBLEND = 151
D3DRS_CLIPPLANEENABLE = 152
D3DRS_SOFTWAREVERTEXPROCESSING = 153
D3DRS_POINTSIZE = 154
D3DRS_POINTSIZE_MIN = 155
D3DRS_POINTSPRITEENABLE = 156
D3DRS_POINTSCALEENABLE = 157
D3DRS_POINTSCALE_A = 158
D3DRS_POINTSCALE_B = 159
D3DRS_POINTSCALE_C = 160
D3DRS_MULTISAMPLEANTIALIAS = 161
D3DRS_MULTISAMPLEMASK = 162
D3DRS_PATCHEDGESTYLE = 163
D3DRS_PATCHSEGMENTS = 164
D3DRS_DEBUGMONITORTOKEN = 165
D3DRS_POINTSIZE_MAX = 166
D3DRS_INDEXEDVERTEXBLENDENABLE = 167
D3DRS_COLORWRITEENABLE = 168
D3DRS_TWEENFACTOR = 170
D3DRS_BLENDOP = 171
D3DRS_POSITIONORDER = 172
D3DRS_NORMALORDER = 173
D3DRS_FORCE_DWORD = 0x7fffffff

D3DMCS_MATERIAL = 0
D3DMCS_COLOR1 = 1
D3DMCS_COLOR2 = 2
D3DMCS_FORCE_DWORD = 0x7fffffff

D3DTSS_COLOROP = 1
D3DTSS_COLORARG1 = 2
D3DTSS_COLORARG2 = 3
D3DTSS_ALPHAOP = 4
D3DTSS_ALPHAARG1 = 5
D3DTSS_ALPHAARG2 = 6
D3DTSS_BUMPENVMAT00 = 7
D3DTSS_BUMPENVMAT01 = 8
D3DTSS_BUMPENVMAT10 = 9
D3DTSS_BUMPENVMAT11 = 10
D3DTSS_TEXCOORDINDEX = 11
D3DTSS_ADDRESSU = 13
D3DTSS_ADDRESSV = 14
D3DTSS_BORDERCOLOR = 15
D3DTSS_MAGFILTER = 16
D3DTSS_MINFILTER = 17
D3DTSS_MIPFILTER = 18
D3DTSS_MIPMAPLODBIAS = 19
D3DTSS_MAXMIPLEVEL = 20
D3DTSS_MAXANISOTROPY = 21
D3DTSS_BUMPENVLSCALE = 22
D3DTSS_BUMPENVLOFFSET = 23
D3DTSS_TEXTURETRANSFORMFLAGS = 24
D3DTSS_ADDRESSW = 25
D3DTSS_COLORARG0 = 26
D3DTSS_ALPHAARG0 = 27
D3DTSS_RESULTARG = 28
D3DTSS_FORCE_DWORD = 0x7fffffff

D3DTOP_DISABLE = 1
D3DTOP_SELECTARG1 = 2
D3DTOP_SELECTARG2 = 3
D3DTOP_MODULATE = 4
D3DTOP_MODULATE2X = 5
D3DTOP_MODULATE4X = 6
D3DTOP_ADD = 7
D3DTOP_ADDSIGNED = 8
D3DTOP_ADDSIGNED2X = 9
D3DTOP_SUBTRACT = 10
D3DTOP_ADDSMOOTH = 11
D3DTOP_BLENDDIFFUSEALPHA = 12
D3DTOP_BLENDTEXTUREALPHA = 13
D3DTOP_BLENDFACTORALPHA = 14
D3DTOP_BLENDTEXTUREALPHAPM = 15
D3DTOP_BLENDCURRENTALPHA = 16
D3DTOP_PREMODULATE = 17
D3DTOP_MODULATEALPHA_ADDCOLOR = 18
D3DTOP_MODULATECOLOR_ADDALPHA = 19
D3DTOP_MODULATEINVALPHA_ADDCOLOR = 20
D3DTOP_MODULATEINVCOLOR_ADDALPHA = 21
D3DTOP_BUMPENVMAP = 22
D3DTOP_BUMPENVMAPLUMINANCE = 23
D3DTOP_DOTPRODUCT3 = 24
D3DTOP_MULTIPLYADD = 25
D3DTOP_LERP = 26
D3DTOP_FORCE_DWORD = 0x7fffffff

D3DTEXF_NONE = 0
D3DTEXF_POINT = 1
D3DTEXF_LINEAR = 2
D3DTEXF_ANISOTROPIC = 3
D3DTEXF_FLATCUBIC = 4
D3DTEXF_GAUSSIANCUBIC = 5
D3DTEXF_FORCE_DWORD = 0x7fffffff

D3DVSD_TOKEN_NOP = 0
D3DVSD_TOKEN_STREAM = 1
D3DVSD_TOKEN_STREAMDATA = 2
D3DVSD_TOKEN_TESSELLATOR = 3
D3DVSD_TOKEN_CONSTMEM = 4
D3DVSD_TOKEN_EXT = 5
D3DVSD_TOKEN_END = 7
D3DVSD_FORCE_DWORD = 0x7fffffff

D3DSIO_NOP = 0
D3DSIO_MOV = 1
D3DSIO_ADD = 2
D3DSIO_SUB = 3
D3DSIO_MAD = 4
D3DSIO_MUL = 5
D3DSIO_RCP = 6
D3DSIO_RSQ = 7
D3DSIO_DP3 = 8
D3DSIO_DP4 = 9
D3DSIO_MIN = 10
D3DSIO_MAX = 11
D3DSIO_SLT = 12
D3DSIO_SGE = 13
D3DSIO_EXP = 14
D3DSIO_LOG = 15
D3DSIO_LIT = 16
D3DSIO_DST = 17
D3DSIO_LRP = 18
D3DSIO_FRC = 19
D3DSIO_M4x4 = 20
D3DSIO_M4x3 = 21
D3DSIO_M3x4 = 22
D3DSIO_M3x3 = 23
D3DSIO_M3x2 = 24
D3DSIO_TEXCOORD = 64
D3DSIO_TEXKILL = 65
D3DSIO_TEX = 66
D3DSIO_TEXBEM = 67
D3DSIO_TEXBEML = 68
D3DSIO_TEXREG2AR = 69
D3DSIO_TEXREG2GB = 70
D3DSIO_TEXM3x2PAD = 71
D3DSIO_TEXM3x2TEX = 72
D3DSIO_TEXM3x3PAD = 73
D3DSIO_TEXM3x3TEX = 74
D3DSIO_TEXM3x3DIFF = 75
D3DSIO_TEXM3x3SPEC = 76
D3DSIO_TEXM3x3VSPEC = 77
D3DSIO_EXPP = 78
D3DSIO_LOGP = 79
D3DSIO_CND = 80
D3DSIO_DEF = 81
D3DSIO_TEXREG2RGB = 82
D3DSIO_TEXDP3TEX = 83
D3DSIO_TEXM3x2DEPTH = 84
D3DSIO_TEXDP3 = 85
D3DSIO_TEXM3x3 = 86
D3DSIO_TEXDEPTH = 87
D3DSIO_CMP = 88
D3DSIO_BEM = 89
D3DSIO_PHASE = 0xFFFD
D3DSIO_COMMENT = 0xFFFE
D3DSIO_END = 0xFFFF
D3DSIO_FORCE_DWORD  = 0x7fffffff

D3DSPDM_NONE = 0
D3DSPDM_SATURATE = 1<<20
D3DSPDM_FORCE_DWORD = 0x7fffffff

D3DSPR_TEMP = 0
D3DSPR_INPUT = 1<<28
D3DSPR_CONST = 2<<28
D3DSPR_ADDR = 3<<28
D3DSPR_TEXTURE = 3<<28
D3DSPR_RASTOUT = 4<<28
D3DSPR_ATTROUT = 5<<28
D3DSPR_TEXCRDOUT = 6<<28
D3DSPR_FORCE_DWORD = 0x7fffffff

D3DSRO_POSITION = 0
D3DSRO_FOG = 1
D3DSRO_POINT_SIZE = 2
D3DSRO_FORCE_DWORD  = 0x7fffffff

D3DVS_ADDRMODE_ABSOLUTE = 0
D3DVS_ADDRMODE_RELATIVE = 1<<13
D3DVS_ADDRMODE_FORCE_DWORD = 0x7fffffff

D3DSPSM_NONE = 0
D3DSPSM_NEG = 1<<24
D3DSPSM_BIAS = 2<<24
D3DSPSM_BIASNEG = 3<<24
D3DSPSM_SIGN = 4<<24
D3DSPSM_SIGNNEG = 5<<24
D3DSPSM_COMP = 6<<24
D3DSPSM_X2 = 7<<24
D3DSPSM_X2NEG = 8<<24
D3DSPSM_DZ = 9<<24
D3DSPSM_DW = 10<<24
D3DSPSM_FORCE_DWORD = 0x7fffffff

D3DBASIS_BEZIER = 0
D3DBASIS_BSPLINE = 1
D3DBASIS_INTERPOLATE = 2
D3DBASIS_FORCE_DWORD = 0x7fffffff

D3DORDER_LINEAR = 1
D3DORDER_QUADRATIC = 2
D3DORDER_CUBIC = 3
D3DORDER_QUINTIC = 5
D3DORDER_FORCE_DWORD = 0x7fffffff

D3DPATCHEDGE_DISCRETE = 0
D3DPATCHEDGE_CONTINUOUS = 1
D3DPATCHEDGE_FORCE_DWORD = 0x7fffffff

D3DSBT_ALL = 1
D3DSBT_PIXELSTATE = 2
D3DSBT_VERTEXSTATE = 3
D3DSBT_FORCE_DWORD = 0x7fffffff

D3DVBF_DISABLE = 0
D3DVBF_1WEIGHTS = 1
D3DVBF_2WEIGHTS = 2
D3DVBF_3WEIGHTS = 3
D3DVBF_TWEENING = 255
D3DVBF_0WEIGHTS = 256
D3DVBF_FORCE_DWORD = 0x7fffffff

D3DTTFF_DISABLE = 0
D3DTTFF_COUNT1 = 1
D3DTTFF_COUNT2 = 2
D3DTTFF_COUNT3 = 3
D3DTTFF_COUNT4 = 4
D3DTTFF_PROJECTED = 256
D3DTTFF_FORCE_DWORD = 0x7fffffff

D3DDEVTYPE_HAL = 1
D3DDEVTYPE_REF = 2
D3DDEVTYPE_SW = 3
D3DDEVTYPE_FORCE_DWORD = 0x7fffffff

D3DMULTISAMPLE_NONE = 0
D3DMULTISAMPLE_2_SAMPLES = 2
D3DMULTISAMPLE_3_SAMPLES = 3
D3DMULTISAMPLE_4_SAMPLES = 4
D3DMULTISAMPLE_5_SAMPLES = 5
D3DMULTISAMPLE_6_SAMPLES = 6
D3DMULTISAMPLE_7_SAMPLES = 7
D3DMULTISAMPLE_8_SAMPLES = 8
D3DMULTISAMPLE_9_SAMPLES = 9
D3DMULTISAMPLE_10_SAMPLES = 10
D3DMULTISAMPLE_11_SAMPLES = 11
D3DMULTISAMPLE_12_SAMPLES = 12
D3DMULTISAMPLE_13_SAMPLES = 13
D3DMULTISAMPLE_14_SAMPLES = 14
D3DMULTISAMPLE_15_SAMPLES = 15
D3DMULTISAMPLE_16_SAMPLES = 16
D3DMULTISAMPLE_FORCE_DWORD = 0x7fffffff

D3DFMT_UNKNOWN =  0
D3DFMT_R8G8B8 = 20
D3DFMT_A8R8G8B8 = 21
D3DFMT_X8R8G8B8 = 22
D3DFMT_R5G6B5 = 23
D3DFMT_X1R5G5B5 = 24
D3DFMT_A1R5G5B5 = 25
D3DFMT_A4R4G4B4 = 26
D3DFMT_R3G3B2 = 27
D3DFMT_A8 = 28
D3DFMT_A8R3G3B2 = 29
D3DFMT_X4R4G4B4 = 30
D3DFMT_A2B10G10R10 = 31
D3DFMT_G16R16 = 34
D3DFMT_A8P8 = 40
D3DFMT_P8 = 41
D3DFMT_L8 = 50
D3DFMT_A8L8 = 51
D3DFMT_A4L4 = 52
D3DFMT_V8U8 = 60
D3DFMT_L6V5U5 = 61
D3DFMT_X8L8V8U8 = 62
D3DFMT_Q8W8V8U8 = 63
D3DFMT_V16U16 = 64
D3DFMT_W11V11U10 = 65
D3DFMT_A2W10V10U10 = 67
D3DFMT_UYVY = A'UYVY'
D3DFMT_YUY2 = A'YUY2'
D3DFMT_DXT1 = A'DXT1'
D3DFMT_DXT2 = A'DXT2'
D3DFMT_DXT3 = A'DXT3'
D3DFMT_DXT4 = A'DXT4'
D3DFMT_DXT5 = A'DXT5'
D3DFMT_D16_LOCKABLE = 70
D3DFMT_D32 = 71
D3DFMT_D15S1 = 73
D3DFMT_D24S8 = 75
D3DFMT_D16 = 80
D3DFMT_D24X8 = 77
D3DFMT_D24X4S4 = 79
D3DFMT_VERTEXDATA = 100
D3DFMT_INDEX16 = 101
D3DFMT_INDEX32 = 102
D3DFMT_FORCE_DWORD = 0x7fffffff

D3DDISPLAYMODE
	Width DD
	Height DD
	RefreshRate DD
	Format DD
ENDS

D3DDEVICE_CREATION_PARAMETERS STRUCT
	AdapterOrdinal DD
	DeviceType DD
	hFocusWindow DD
ENDS

D3DSWAPEFFECT_DISCARD = 1
D3DSWAPEFFECT_FLIP = 2
D3DSWAPEFFECT_COPY = 3
D3DSWAPEFFECT_COPY_VSYNC = 4
D3DSWAPEFFECT_FORCE_DWORD = 0x7fffffff

D3DPOOL_DEFAULT = 0
D3DPOOL_MANAGED = 1
D3DPOOL_SYSTEMMEM = 2
D3DPOOL_SCRATCH = 3
D3DPOOL_FORCE_DWORD = 0x7fffffff

D3DPRESENT_PARAMETERS STRUCT
	BackBufferWidth DD
	BackBufferHeight DD
	BackBufferFormat DD
	BackBufferCount DD
	MultiSampleType DD
	SwapEffect DD
	hDeviceWindow HANDLE
	Windowed DD
	EnableAutoDepthStencil DD
	AutoDepthStencilFormat DD
	Flags DD
	FullScreen_RefreshRateInHz DD
	FullScreen_PresentationInterval DD
ENDS

D3DGAMMARAMP STRUCT
	red DW 256 DUP (?)
	green DW 256 DUP (?)
	blue DW 256 DUP (?)
ENDS

D3DBACKBUFFER_TYPE_MONO = 0
D3DBACKBUFFER_TYPE_LEFT = 1
D3DBACKBUFFER_TYPE_RIGHT = 2
D3DBACKBUFFER_TYPE_FORCE_DWORD = 0x7fffffff

D3DRTYPE_SURFACE = 1
D3DRTYPE_VOLUME = 2
D3DRTYPE_TEXTURE = 3
D3DRTYPE_VOLUMETEXTURE = 4
D3DRTYPE_CUBETEXTURE = 5
D3DRTYPE_VERTEXBUFFER = 6
D3DRTYPE_INDEXBUFFER = 7
D3DRTYPE_FORCE_DWORD = 0x7fffffff

D3DCUBEMAP_FACE_POSITIVE_X = 0
D3DCUBEMAP_FACE_NEGATIVE_X = 1
D3DCUBEMAP_FACE_POSITIVE_Y = 2
D3DCUBEMAP_FACE_NEGATIVE_Y = 3
D3DCUBEMAP_FACE_POSITIVE_Z = 4
D3DCUBEMAP_FACE_NEGATIVE_Z = 5
D3DCUBEMAP_FACE_FORCE_DWORD = 0x7fffffff

D3DVERTEXBUFFER_DESC STRUCT
	Format DD
	Type DD
	Usage DD
	Pool DD
	Size DD
	FVF DD
ENDS

D3DINDEXBUFFER_DESC STRUCT
	Format DD
	Type DD
	Usage DD
	Pool DD
	Size DD
ENDS

D3DSURFACE_DESC STRUCT
	Format DD
	Type DD
	Usage DD
	Pool DD
	Size DD
	MultiSampleType DD
	Width DD
	Height DD
ENDS

D3DVOLUME_DESC STRUCT
	Format DD
	Type DD
	Usage DD
	Pool DD
	Size DD
	Width DD
	Height DD
	Depth DD
ENDS

D3DLOCKED_RECT STRUCT
	Pitch DD
	pBits DD
ENDS

D3DBOX STRUCT
	Left DD
	Top DD
	Right DD
	Bottom DD
	Front DD
	Back DD
ENDS

D3DLOCKED_BOX STRUCT
	RowPitch DD
	SlicePitch DD
	pBits PTR
ENDS

D3DRANGE STRUCT
	Offset DD
	Size DD
ENDS

D3DRECTPATCH_INFO STRUCT
	StartVertexOffsetWidth DD
	StartVertexOffsetHeight DD
	Width DD
	Height DD
	Stride DD
	Basis DD
	Order DD
ENDS

D3DTRIPATCH_INFO STRUCT
	StartVertexOffset DD
	NumVertices DD
	Basis DD
	Order DD
ENDS

D3DADAPTER_IDENTIFIER8 STRUCT
	Driver DB MAX_DEVICE_IDENTIFIER_STRING DUP (?)
	Description DB MAX_DEVICE_IDENTIFIER_STRING DUP (?)
	DriverVersion DQ
	VendorId DD
	DeviceId DD
	SubSysId DD
	Revision DD
	DeviceIdentifier GUID
	WHQLLevel DD
ENDS

D3DRASTER_STATUS STRUCT
	InVBlank DD
	ScanLine DD
ENDS

D3DDMT_ENABLE = 0
D3DDMT_DISABLE = 1
D3DDMT_FORCE_DWORD = 0x7fffffff

#endif // DIRECT3D_VERSION >= 0x0800
#endif // D3D8TYPES_H

