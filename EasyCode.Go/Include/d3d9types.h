/*==========================================================================;
 *
 *  Copyright (C) Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       d3d9types.h
 *  Content:    Direct3D capabilities include file
 *
 ***************************************************************************/

#ifndef D3D9TYPES_H
#define D3D9TYPES_H

#ifndef DIRECT3D_VERSION
	#define DIRECT3D_VERSION         0x0900
#endif  //DIRECT3D_VERSION

// D3DCOLOR is equivalent to D3DFMT_A8R8G8B8
#DEFINE D3DCOLOR DD

D3DVECTOR STRUCT
	x FLOAT
	y FLOAT
	z FLOAT
ENDS

D3DCOLORVALUE STRUCT
	r FLOAT
	g FLOAT
	b FLOAT
	a FLOAT
ENDS

D3DRECT STRUCT
	x1 DD
	y1 DD
	x2 DD
	y2 DD
ENDS

D3DMATRIX STRUCT
	// D3DMATRIX is a 4x4 array of FLOAT
	m FLOAT 16 DUP
ends

D3DVIEWPORT9 STRUCT
	X DD
	Y DD
	Width DD
	Height DD
	MinZ FLOAT
	MaxZ FLOAT
ENDS

#define D3DMAXUSERCLIPPLANES 32

#define D3DCLIPPLANE0 1
#define D3DCLIPPLANE1 2
#define D3DCLIPPLANE2 4
#define D3DCLIPPLANE3 8
#define D3DCLIPPLANE4 16
#define D3DCLIPPLANE5 32

#define D3DCS_LEFT        0x00000001
#define D3DCS_RIGHT       0x00000002
#define D3DCS_TOP         0x00000004
#define D3DCS_BOTTOM      0x00000008
#define D3DCS_FRONT       0x00000010
#define D3DCS_BACK        0x00000020
#define D3DCS_PLANE0      0x00000040
#define D3DCS_PLANE1      0x00000080
#define D3DCS_PLANE2      0x00000100
#define D3DCS_PLANE3      0x00000200
#define D3DCS_PLANE4      0x00000400
#define D3DCS_PLANE5      0x00000800

#define D3DCS_ALL 0xFFF

D3DCLIPSTATUS9 STRUCT
	ClipUnion DD
	ClipIntersection DD
ENDS

D3DMATERIAL9 STRUCT
	Diffuse D3DCOLORVALUE
	Ambient D3DCOLORVALUE
	Specular D3DCOLORVALUE
	Emissive D3DCOLORVALUE
	Power FLOAT
ENDS

// enum D3DLIGHTTYPE
D3DLIGHT_POINT          = 1
D3DLIGHT_SPOT           = 2
D3DLIGHT_DIRECTIONAL    = 3
D3DLIGHT_FORCE_DWORD    = 0x7fffffff

D3DLIGHT9 STRUCT
	Type ENUM // D3DLIGHTTYPE
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

#define D3DCLEAR_TARGET            0x00000001
#define D3DCLEAR_ZBUFFER           0x00000002
#define D3DCLEAR_STENCIL           0x00000004

// enum _D3DSHADEMODE {
D3DSHADE_FLAT               = 1
D3DSHADE_GOURAUD            = 2
D3DSHADE_PHONG              = 3
D3DSHADE_FORCE_DWORD        = 0x7fffffff /* force 32-bit size enum */

// enum _D3DFILLMODE {
D3DFILL_POINT               = 1
D3DFILL_WIREFRAME           = 2
D3DFILL_SOLID               = 3
D3DFILL_FORCE_DWORD         = 0x7fffffff /* force 32-bit size enum */

// enum _D3DBLEND {
D3DBLEND_ZERO               = 1
D3DBLEND_ONE                = 2
D3DBLEND_SRCCOLOR           = 3
D3DBLEND_INVSRCCOLOR        = 4
D3DBLEND_SRCALPHA           = 5
D3DBLEND_INVSRCALPHA        = 6
D3DBLEND_DESTALPHA          = 7
D3DBLEND_INVDESTALPHA       = 8
D3DBLEND_DESTCOLOR          = 9
D3DBLEND_INVDESTCOLOR       = 10
D3DBLEND_SRCALPHASAT        = 11
D3DBLEND_BOTHSRCALPHA       = 12
D3DBLEND_BOTHINVSRCALPHA    = 13
D3DBLEND_BLENDFACTOR        = 14 /* Only supported if D3DPBLENDCAPS_BLENDFACTOR is on */
D3DBLEND_INVBLENDFACTOR     = 15 /* Only supported if D3DPBLENDCAPS_BLENDFACTOR is on */
D3DBLEND_SRCCOLOR2          = 16
D3DBLEND_INVSRCCOLOR2       = 17
D3DBLEND_FORCE_DWORD        = 0x7fffffff /* force 32-bit size enum */

// enum _D3DBLENDOP {
D3DBLENDOP_ADD              = 1
D3DBLENDOP_SUBTRACT         = 2
D3DBLENDOP_REVSUBTRACT      = 3
D3DBLENDOP_MIN              = 4
D3DBLENDOP_MAX              = 5
D3DBLENDOP_FORCE_DWORD      = 0x7fffffff /* force 32-bit size enum */

// enum _D3DTEXTUREADDRESS {
D3DTADDRESS_WRAP            = 1
D3DTADDRESS_MIRROR          = 2
D3DTADDRESS_CLAMP           = 3
D3DTADDRESS_BORDER          = 4
D3DTADDRESS_MIRRORONCE      = 5
D3DTADDRESS_FORCE_DWORD     = 0x7fffffff /* force 32-bit size enum */

// enum _D3DCULL {
D3DCULL_NONE                = 1
D3DCULL_CW                  = 2
D3DCULL_CCW                 = 3
D3DCULL_FORCE_DWORD         = 0x7fffffff /* force 32-bit size enum */

// enum _D3DCMPFUNC {
D3DCMP_NEVER                = 1
D3DCMP_LESS                 = 2
D3DCMP_EQUAL                = 3
D3DCMP_LESSEQUAL            = 4
D3DCMP_GREATER              = 5
D3DCMP_NOTEQUAL             = 6
D3DCMP_GREATEREQUAL         = 7
D3DCMP_ALWAYS               = 8
D3DCMP_FORCE_DWORD          = 0x7fffffff /* force 32-bit size enum */

// enum _D3DSTENCILOP {
D3DSTENCILOP_KEEP           = 1
D3DSTENCILOP_ZERO           = 2
D3DSTENCILOP_REPLACE        = 3
D3DSTENCILOP_INCRSAT        = 4
D3DSTENCILOP_DECRSAT        = 5
D3DSTENCILOP_INVERT         = 6
D3DSTENCILOP_INCR           = 7
D3DSTENCILOP_DECR           = 8
D3DSTENCILOP_FORCE_DWORD    = 0x7fffffff /* force 32-bit size enum */

// enum _D3DFOGMODE {
D3DFOG_NONE                 = 0
D3DFOG_EXP                  = 1
D3DFOG_EXP2                 = 2
D3DFOG_LINEAR               = 3
D3DFOG_FORCE_DWORD          = 0x7fffffff /* force 32-bit size enum */

// enum _D3DZBUFFERTYPE {
D3DZB_FALSE                 = 0
D3DZB_TRUE                  = 1 // Z buffering
D3DZB_USEW                  = 2 // W buffering
D3DZB_FORCE_DWORD           = 0x7fffffff /* force 32-bit size enum */

// Primitives supported by draw-primitive API
// enum _D3DPRIMITIVETYPE {
D3DPT_POINTLIST             = 1
D3DPT_LINELIST              = 2
D3DPT_LINESTRIP             = 3
D3DPT_TRIANGLELIST          = 4
D3DPT_TRIANGLESTRIP         = 5
D3DPT_TRIANGLEFAN           = 6
D3DPT_FORCE_DWORD           = 0x7fffffff /* force 32-bit size enum */

// enum _D3DTRANSFORMSTATETYPE {
D3DTS_VIEW          = 2
D3DTS_PROJECTION    = 3
D3DTS_TEXTURE0      = 16
D3DTS_TEXTURE1      = 17
D3DTS_TEXTURE2      = 18
D3DTS_TEXTURE3      = 19
D3DTS_TEXTURE4      = 20
D3DTS_TEXTURE5      = 21
D3DTS_TEXTURE6      = 22
D3DTS_TEXTURE7      = 23
D3DTS_FORCE_DWORD     = 0x7fffffff /* force 32-bit size enum */

#define D3DTS_WORLD  256
#define D3DTS_WORLD1  257
#define D3DTS_WORLD2  258
#define D3DTS_WORLD3  259

// enum _D3DRENDERSTATETYPE {
D3DRS_ZENABLE                   = 7    /* D3DZBUFFERTYPE (or TRUE/FALSE for legacy) */
D3DRS_FILLMODE                  = 8    /* D3DFILLMODE */
D3DRS_SHADEMODE                 = 9    /* D3DSHADEMODE */
D3DRS_ZWRITEENABLE              = 14   /* TRUE to enable z writes */
D3DRS_ALPHATESTENABLE           = 15   /* TRUE to enable alpha tests */
D3DRS_LASTPIXEL                 = 16   /* TRUE for last-pixel on lines */
D3DRS_SRCBLEND                  = 19   /* D3DBLEND */
D3DRS_DESTBLEND                 = 20   /* D3DBLEND */
D3DRS_CULLMODE                  = 22   /* D3DCULL */
D3DRS_ZFUNC                     = 23   /* D3DCMPFUNC */
D3DRS_ALPHAREF                  = 24   /* D3DFIXED */
D3DRS_ALPHAFUNC                 = 25   /* D3DCMPFUNC */
D3DRS_DITHERENABLE              = 26   /* TRUE to enable dithering */
D3DRS_ALPHABLENDENABLE          = 27   /* TRUE to enable alpha blending */
D3DRS_FOGENABLE                 = 28   /* TRUE to enable fog blending */
D3DRS_SPECULARENABLE            = 29   /* TRUE to enable specular */
D3DRS_FOGCOLOR                  = 34   /* D3DCOLOR */
D3DRS_FOGTABLEMODE              = 35   /* D3DFOGMODE */
D3DRS_FOGSTART                  = 36   /* Fog start (for both vertex and pixel fog) */
D3DRS_FOGEND                    = 37   /* Fog end      */
D3DRS_FOGDENSITY                = 38   /* Fog density  */
D3DRS_RANGEFOGENABLE            = 48   /* Enables range-based fog */
D3DRS_STENCILENABLE             = 52   /* BOOL enable/disable stenciling */
D3DRS_STENCILFAIL               = 53   /* D3DSTENCILOP to do if stencil test fails */
D3DRS_STENCILZFAIL              = 54   /* D3DSTENCILOP to do if stencil test passes and Z test fails */
D3DRS_STENCILPASS               = 55   /* D3DSTENCILOP to do if both stencil and Z tests pass */
D3DRS_STENCILFUNC               = 56   /* D3DCMPFUNC fn.  Stencil Test passes if ((ref & mask) stencilfn (stencil & mask)) is true */
D3DRS_STENCILREF                = 57   /* Reference value used in stencil test */
D3DRS_STENCILMASK               = 58   /* Mask value used in stencil test */
D3DRS_STENCILWRITEMASK          = 59   /* Write mask applied to values written to stencil buffer */
D3DRS_TEXTUREFACTOR             = 60   /* D3DCOLOR used for multi-texture blend */
D3DRS_WRAP0                     = 128  /* wrap for 1st texture coord. set */
D3DRS_WRAP1                     = 129  /* wrap for 2nd texture coord. set */
D3DRS_WRAP2                     = 130  /* wrap for 3rd texture coord. set */
D3DRS_WRAP3                     = 131  /* wrap for 4th texture coord. set */
D3DRS_WRAP4                     = 132  /* wrap for 5th texture coord. set */
D3DRS_WRAP5                     = 133  /* wrap for 6th texture coord. set */
D3DRS_WRAP6                     = 134  /* wrap for 7th texture coord. set */
D3DRS_WRAP7                     = 135  /* wrap for 8th texture coord. set */
D3DRS_CLIPPING                  = 136
D3DRS_LIGHTING                  = 137
D3DRS_AMBIENT                   = 139
D3DRS_FOGVERTEXMODE             = 140
D3DRS_COLORVERTEX               = 141
D3DRS_LOCALVIEWER               = 142
D3DRS_NORMALIZENORMALS          = 143
D3DRS_DIFFUSEMATERIALSOURCE     = 145
D3DRS_SPECULARMATERIALSOURCE    = 146
D3DRS_AMBIENTMATERIALSOURCE     = 147
D3DRS_EMISSIVEMATERIALSOURCE    = 148
D3DRS_VERTEXBLEND               = 151
D3DRS_CLIPPLANEENABLE           = 152
D3DRS_POINTSIZE                 = 154   /* float point size */
D3DRS_POINTSIZE_MIN             = 155   /* float point size min threshold */
D3DRS_POINTSPRITEENABLE         = 156   /* BOOL point texture coord control */
D3DRS_POINTSCALEENABLE          = 157   /* BOOL point size scale enable */
D3DRS_POINTSCALE_A              = 158   /* float point attenuation A value */
D3DRS_POINTSCALE_B              = 159   /* float point attenuation B value */
D3DRS_POINTSCALE_C              = 160   /* float point attenuation C value */
D3DRS_MULTISAMPLEANTIALIAS      = 161  // BOOL - set to do FSAA with multisample buffer
D3DRS_MULTISAMPLEMASK           = 162  // DWORD - per-sample enable/disable
D3DRS_PATCHEDGESTYLE            = 163  // Sets whether patch edges will use float style tessellation
D3DRS_DEBUGMONITORTOKEN         = 165  // DEBUG ONLY - token to debug monitor
D3DRS_POINTSIZE_MAX             = 166   /* float point size max threshold */
D3DRS_INDEXEDVERTEXBLENDENABLE  = 167
D3DRS_COLORWRITEENABLE          = 168  // per-channel write enable
D3DRS_TWEENFACTOR               = 170   // float tween factor
D3DRS_BLENDOP                   = 171   // D3DBLENDOP setting
D3DRS_POSITIONDEGREE            = 172   // NPatch position interpolation degree. D3DDEGREE_LINEAR or D3DDEGREE_CUBIC (default)
D3DRS_NORMALDEGREE              = 173   // NPatch normal interpolation degree. D3DDEGREE_LINEAR (default) or D3DDEGREE_QUADRATIC
D3DRS_SCISSORTESTENABLE         = 174
D3DRS_SLOPESCALEDEPTHBIAS       = 175
D3DRS_ANTIALIASEDLINEENABLE     = 176
D3DRS_MINTESSELLATIONLEVEL      = 178
D3DRS_MAXTESSELLATIONLEVEL      = 179
D3DRS_ADAPTIVETESS_X            = 180
D3DRS_ADAPTIVETESS_Y            = 181
D3DRS_ADAPTIVETESS_Z            = 182
D3DRS_ADAPTIVETESS_W            = 183
D3DRS_ENABLEADAPTIVETESSELLATION = 184
D3DRS_TWOSIDEDSTENCILMODE       = 185   /* BOOL enable/disable 2 sided stenciling */
D3DRS_CCW_STENCILFAIL           = 186   /* D3DSTENCILOP to do if ccw stencil test fails */
D3DRS_CCW_STENCILZFAIL          = 187   /* D3DSTENCILOP to do if ccw stencil test passes and Z test fails */
D3DRS_CCW_STENCILPASS           = 188   /* D3DSTENCILOP to do if both ccw stencil and Z tests pass */
D3DRS_CCW_STENCILFUNC           = 189   /* D3DCMPFUNC fn.  ccw Stencil Test passes if ((ref & mask) stencilfn (stencil & mask)) is true */
D3DRS_COLORWRITEENABLE1         = 190   /* Additional ColorWriteEnables for the devices that support D3DPMISCCAPS_INDEPENDENTWRITEMASKS */
D3DRS_COLORWRITEENABLE2         = 191   /* Additional ColorWriteEnables for the devices that support D3DPMISCCAPS_INDEPENDENTWRITEMASKS */
D3DRS_COLORWRITEENABLE3         = 192   /* Additional ColorWriteEnables for the devices that support D3DPMISCCAPS_INDEPENDENTWRITEMASKS */
D3DRS_BLENDFACTOR               = 193   /* D3DCOLOR used for a constant blend factor during alpha blending for devices that support D3DPBLENDCAPS_BLENDFACTOR */
D3DRS_SRGBWRITEENABLE           = 194   /* Enable rendertarget writes to be DE-linearized to SRGB (for formats that expose D3DUSAGE_QUERY_SRGBWRITE) */
D3DRS_DEPTHBIAS                 = 195
D3DRS_WRAP8                     = 198   /* Additional wrap states for vs_3_0+ attributes with D3DDECLUSAGE_TEXCOORD */
D3DRS_WRAP9                     = 199
D3DRS_WRAP10                    = 200
D3DRS_WRAP11                    = 201
D3DRS_WRAP12                    = 202
D3DRS_WRAP13                    = 203
D3DRS_WRAP14                    = 204
D3DRS_WRAP15                    = 205
D3DRS_SEPARATEALPHABLENDENABLE  = 206  /* TRUE to enable a separate blending function for the alpha channel */
D3DRS_SRCBLENDALPHA             = 207  /* SRC blend factor for the alpha channel when D3DRS_SEPARATEDESTALPHAENABLE is TRUE */
D3DRS_DESTBLENDALPHA            = 208  /* DST blend factor for the alpha channel when D3DRS_SEPARATEDESTALPHAENABLE is TRUE */
D3DRS_BLENDOPALPHA              = 209  /* Blending operation for the alpha channel when D3DRS_SEPARATEDESTALPHAENABLE is TRUE */
D3DRS_FORCE_DWORD               = 0x7fffffff /* force 32-bit size enum */

#define D3D_MAX_SIMULTANEOUS_RENDERTARGETS 4

// enum _D3DMATERIALCOLORSOURCE
D3DMCS_MATERIAL         = 0            // Color from material is used
D3DMCS_COLOR1           = 1            // Diffuse vertex color is used
D3DMCS_COLOR2           = 2            // Specular vertex color is used
D3DMCS_FORCE_DWORD      = 0x7fffffff   // force 32-bit size enum

#define D3DRENDERSTATE_WRAPBIAS 128
#define D3DWRAP_U   0x00000001
#define D3DWRAP_V   0x00000002
#define D3DWRAP_W   0x00000004
#define D3DWRAPCOORD_0   0x00000001    // same as D3DWRAP_U
#define D3DWRAPCOORD_1   0x00000002    // same as D3DWRAP_V
#define D3DWRAPCOORD_2   0x00000004    // same as D3DWRAP_W
#define D3DWRAPCOORD_3   0x00000008
#define D3DCOLORWRITEENABLE_RED    1
#define D3DCOLORWRITEENABLE_GREEN  2
#define D3DCOLORWRITEENABLE_BLUE   4
#define D3DCOLORWRITEENABLE_ALPHA  8

// enum _D3DTEXTURESTAGESTATETYPE
D3DTSS_COLOROP        =  1 /* D3DTEXTUREOP - per-stage blending controls for color channels */
D3DTSS_COLORARG1      =  2 /* D3DTA_* (texture arg) */
D3DTSS_COLORARG2      =  3 /* D3DTA_* (texture arg) */
D3DTSS_ALPHAOP        =  4 /* D3DTEXTUREOP - per-stage blending controls for alpha channel */
D3DTSS_ALPHAARG1      =  5 /* D3DTA_* (texture arg) */
D3DTSS_ALPHAARG2      =  6 /* D3DTA_* (texture arg) */
D3DTSS_BUMPENVMAT00   =  7 /* float (bump mapping matrix) */
D3DTSS_BUMPENVMAT01   =  8 /* float (bump mapping matrix) */
D3DTSS_BUMPENVMAT10   =  9 /* float (bump mapping matrix) */
D3DTSS_BUMPENVMAT11   = 10 /* float (bump mapping matrix) */
D3DTSS_TEXCOORDINDEX  = 11 /* identifies which set of texture coordinates index this texture */
D3DTSS_BUMPENVLSCALE  = 22 /* float scale for bump map luminance */
D3DTSS_BUMPENVLOFFSET = 23 /* float offset for bump map luminance */
D3DTSS_TEXTURETRANSFORMFLAGS = 24 /* D3DTEXTURETRANSFORMFLAGS controls texture transform */
D3DTSS_COLORARG0      = 26 /* D3DTA_* third arg for triadic ops */
D3DTSS_ALPHAARG0      = 27 /* D3DTA_* third arg for triadic ops */
D3DTSS_RESULTARG      = 28 /* D3DTA_* arg for result (CURRENT or TEMP) */
D3DTSS_CONSTANT       = 32 /* Per-stage constant D3DTA_CONSTANT */
D3DTSS_FORCE_DWORD   = 0x7fffffff /* force 32-bit size enum */

// enum _D3DSAMPLERSTATETYPE
D3DSAMP_ADDRESSU       = 1  /* D3DTEXTUREADDRESS for U coordinate */
D3DSAMP_ADDRESSV       = 2  /* D3DTEXTUREADDRESS for V coordinate */
D3DSAMP_ADDRESSW       = 3  /* D3DTEXTUREADDRESS for W coordinate */
D3DSAMP_BORDERCOLOR    = 4  /* D3DCOLOR */
D3DSAMP_MAGFILTER      = 5  /* D3DTEXTUREFILTER filter to use for magnification */
D3DSAMP_MINFILTER      = 6  /* D3DTEXTUREFILTER filter to use for minification */
D3DSAMP_MIPFILTER      = 7  /* D3DTEXTUREFILTER filter to use between mipmaps during minification */
D3DSAMP_MIPMAPLODBIAS  = 8  /* float Mipmap LOD bias */
D3DSAMP_MAXMIPLEVEL    = 9  /* DWORD 0..(n-1) LOD index of largest map to use (0 == largest) */
D3DSAMP_MAXANISOTROPY  = 10 /* DWORD maximum anisotropy */
D3DSAMP_SRGBTEXTURE    = 11 /* Default = 0 (which means Gamma 1.0,
                               no correction required.) else correct for
                               Gamma = 2.2 */
D3DSAMP_ELEMENTINDEX   = 12 /* When multi-element texture is assigned to sampler, this
                                indicates which element index to use.  Default = 0.  */
D3DSAMP_DMAPOFFSET     = 13 /* Offset in vertices in the pre-sampled displacement map.
                                Only valid for D3DDMAPSAMPLER sampler  */
D3DSAMP_FORCE_DWORD   = 0x7fffffff /* force 32-bit size enum */

#define D3DDMAPSAMPLER 256
#define D3DVERTEXTEXTURESAMPLER0 (D3DDMAPSAMPLER+1)
#define D3DVERTEXTEXTURESAMPLER1 (D3DDMAPSAMPLER+2)
#define D3DVERTEXTEXTURESAMPLER2 (D3DDMAPSAMPLER+3)
#define D3DVERTEXTEXTURESAMPLER3 (D3DDMAPSAMPLER+4)

#define D3DTSS_TCI_PASSTHRU                             0x00000000
#define D3DTSS_TCI_CAMERASPACENORMAL                    0x00010000
#define D3DTSS_TCI_CAMERASPACEPOSITION                  0x00020000
#define D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR          0x00030000
#define D3DTSS_TCI_SPHEREMAP                            0x00040000

// enum _D3DTEXTUREOP
D3DTOP_DISABLE              = 1      // disables stage
D3DTOP_SELECTARG1           = 2      // the default
D3DTOP_SELECTARG2           = 3
D3DTOP_MODULATE             = 4      // multiply args together
D3DTOP_MODULATE2X           = 5      // multiply and  1 bit
D3DTOP_MODULATE4X           = 6      // multiply and  2 bits
D3DTOP_ADD                  =  7   // add arguments together
D3DTOP_ADDSIGNED            =  8   // add with -0.5 bias
D3DTOP_ADDSIGNED2X          =  9   // as above but left  1 bit
D3DTOP_SUBTRACT             = 10   // Arg1 - Arg2, with no saturation
D3DTOP_ADDSMOOTH            = 11   // add 2 args, subtract product
D3DTOP_BLENDDIFFUSEALPHA    = 12 // iterated alpha
D3DTOP_BLENDTEXTUREALPHA    = 13 // texture alpha
D3DTOP_BLENDFACTORALPHA     = 14 // alpha from D3DRS_TEXTUREFACTOR
D3DTOP_BLENDTEXTUREALPHAPM  = 15 // texture alpha
D3DTOP_BLENDCURRENTALPHA    = 16 // by alpha of current color
D3DTOP_PREMODULATE            = 17     // modulate with next texture before use
D3DTOP_MODULATEALPHA_ADDCOLOR = 18     // Arg1.RGB + Arg1.A*Arg2.RGB
D3DTOP_MODULATECOLOR_ADDALPHA = 19     // Arg1.RGB*Arg2.RGB + Arg1.A
D3DTOP_MODULATEINVALPHA_ADDCOLOR = 20  // (1-Arg1.A)*Arg2.RGB + Arg1.RGB
D3DTOP_MODULATEINVCOLOR_ADDALPHA = 21  // (1-Arg1.RGB)*Arg2.RGB + Arg1.A
D3DTOP_BUMPENVMAP           = 22 // per pixel env map perturbation
D3DTOP_BUMPENVMAPLUMINANCE  = 23 // with luminance channel
D3DTOP_DOTPRODUCT3          = 24
D3DTOP_MULTIPLYADD          = 25 // Arg0 + Arg1*Arg2
D3DTOP_LERP                 = 26 // (Arg0)*Arg1 + (1-Arg0)*Arg2

D3DTOP_FORCE_DWORD = 0x7fffffff

#define D3DTA_SELECTMASK        0x0000000f  // mask for arg selector
#define D3DTA_DIFFUSE           0x00000000  // select diffuse color (read only)
#define D3DTA_CURRENT           0x00000001  // select stage destination register (read/write)
#define D3DTA_TEXTURE           0x00000002  // select texture color (read only)
#define D3DTA_TFACTOR           0x00000003  // select D3DRS_TEXTUREFACTOR (read only)
#define D3DTA_SPECULAR          0x00000004  // select specular color (read only)
#define D3DTA_TEMP              0x00000005  // select temporary register color (read/write)
#define D3DTA_CONSTANT          0x00000006  // select texture stage constant
#define D3DTA_COMPLEMENT        0x00000010  // take 1.0 - x (read modifier)
#define D3DTA_ALPHAREPLICATE    0x00000020  // replicate alpha to color components (read modifier)

// enum _D3DTEXTUREFILTERTYPE
D3DTEXF_NONE            = 0    // filtering disabled (valid for mip filter only)
D3DTEXF_POINT           = 1    // nearest
D3DTEXF_LINEAR          = 2    // linear interpolation
D3DTEXF_ANISOTROPIC     = 3    // anisotropic
D3DTEXF_PYRAMIDALQUAD   = 6    // 4-sample tent
D3DTEXF_GAUSSIANQUAD    = 7    // 4-sample gaussian
D3DTEXF_CONVOLUTIONMONO = 8    // Convolution filter for monochrome textures
D3DTEXF_FORCE_DWORD     = 0x7fffffff   // force 32-bit size enum

#define D3DPV_DONOTCOPYDATA 1

#define D3DFVF_RESERVED0        0x001
#define D3DFVF_POSITION_MASK    0x400E
#define D3DFVF_XYZ              0x002
#define D3DFVF_XYZRHW           0x004
#define D3DFVF_XYZB1            0x006
#define D3DFVF_XYZB2            0x008
#define D3DFVF_XYZB3            0x00a
#define D3DFVF_XYZB4            0x00c
#define D3DFVF_XYZB5            0x00e
#define D3DFVF_XYZW             0x4002

#define D3DFVF_NORMAL           0x010
#define D3DFVF_PSIZE            0x020
#define D3DFVF_DIFFUSE          0x040
#define D3DFVF_SPECULAR         0x080

#define D3DFVF_TEXCOUNT_MASK    0xf00
#define D3DFVF_TEXCOUNT_SHIFT   8
#define D3DFVF_TEX0             0x000
#define D3DFVF_TEX1             0x100
#define D3DFVF_TEX2             0x200
#define D3DFVF_TEX3             0x300
#define D3DFVF_TEX4             0x400
#define D3DFVF_TEX5             0x500
#define D3DFVF_TEX6             0x600
#define D3DFVF_TEX7             0x700
#define D3DFVF_TEX8             0x800

#define D3DFVF_LASTBETA_UBYTE4   0x1000
#define D3DFVF_LASTBETA_D3DCOLOR 0x8000

#define D3DFVF_RESERVED2         0x6000  // 2 reserved bits

// enum _D3DDECLUSAGE
D3DDECLUSAGE_POSITION = 0
D3DDECLUSAGE_BLENDWEIGHT = 1
D3DDECLUSAGE_BLENDINDICES = 2
D3DDECLUSAGE_NORMAL = 3
D3DDECLUSAGE_PSIZE = 4
D3DDECLUSAGE_TEXCOORD = 5
D3DDECLUSAGE_TANGENT = 6
D3DDECLUSAGE_BINORMAL = 7
D3DDECLUSAGE_TESSFACTOR = 8
D3DDECLUSAGE_POSITIONT = 9
D3DDECLUSAGE_COLOR = 10
D3DDECLUSAGE_FOG = 11
D3DDECLUSAGE_DEPTH = 12
D3DDECLUSAGE_SAMPLE = 13

#define MAXD3DDECLUSAGE         D3DDECLUSAGE_SAMPLE
#define MAXD3DDECLUSAGEINDEX    15
#define MAXD3DDECLLENGTH        64 // does not include "end" marker vertex element

// enum _D3DDECLMETHOD
D3DDECLMETHOD_DEFAULT = 0
D3DDECLMETHOD_PARTIALU = 1
D3DDECLMETHOD_PARTIALV = 2
D3DDECLMETHOD_CROSSUV = 3
D3DDECLMETHOD_UV = 4
D3DDECLMETHOD_LOOKUP = 5
D3DDECLMETHOD_LOOKUPPRESAMPLED = 6

#define MAXD3DDECLMETHOD D3DDECLMETHOD_LOOKUPPRESAMPLED

//enum _D3DDECLTYPE
D3DDECLTYPE_FLOAT1    =  0
D3DDECLTYPE_FLOAT2    =  1
D3DDECLTYPE_FLOAT3    =  2
D3DDECLTYPE_FLOAT4    =  3
D3DDECLTYPE_D3DCOLOR  =  4
D3DDECLTYPE_UBYTE4    =  5
D3DDECLTYPE_SHORT2    =  6
D3DDECLTYPE_SHORT4    =  7
D3DDECLTYPE_UBYTE4N   =  8
D3DDECLTYPE_SHORT2N   =  9
D3DDECLTYPE_SHORT4N   = 10
D3DDECLTYPE_USHORT2N  = 11
D3DDECLTYPE_USHORT4N  = 12
D3DDECLTYPE_UDEC3     = 13
D3DDECLTYPE_DEC3N     = 14
D3DDECLTYPE_FLOAT16_2 = 15
D3DDECLTYPE_FLOAT16_4 = 16
D3DDECLTYPE_UNUSED    = 17

#define MAXD3DDECLTYPE      D3DDECLTYPE_UNUSED

D3DVERTEXELEMENT9 STRUCT
	Stream DW
	Offset DW
	Type DB
	Method DB
	Usage DB
	UsageIndex DB
ENDS

// This is used to initialize the last vertex element in a vertex declaration
// array
//
#define D3DDECL_END <0xFF,0,D3DDECLTYPE_UNUSED,0,0,0>

#define D3DDP_MAXTEXCOORD   8

#define D3DSTREAMSOURCE_INDEXEDDATA  (1<<30)
#define D3DSTREAMSOURCE_INSTANCEDATA (2<<30)

#define D3DSI_OPCODE_MASK       0x0000FFFF

#define D3DSI_INSTLENGTH_MASK   0x0F000000
#define D3DSI_INSTLENGTH_SHIFT  24

// enum _D3DSHADER_INSTRUCTION_OPCODE_TYPE
D3DSIO_NOP          = 0
D3DSIO_MOV          = 1
D3DSIO_ADD          = 2
D3DSIO_SUB          = 3
D3DSIO_MAD          = 4
D3DSIO_MUL          = 5
D3DSIO_RCP          = 6
D3DSIO_RSQ          = 7
D3DSIO_DP3          = 8
D3DSIO_DP4          = 9
D3DSIO_MIN          = 10
D3DSIO_MAX          = 11
D3DSIO_SLT          = 12
D3DSIO_SGE          = 13
D3DSIO_EXP          = 14
D3DSIO_LOG          = 15
D3DSIO_LIT          = 16
D3DSIO_DST          = 17
D3DSIO_LRP          = 18
D3DSIO_FRC          = 19
D3DSIO_M4x4         = 20
D3DSIO_M4x3         = 21
D3DSIO_M3x4         = 22
D3DSIO_M3x3         = 23
D3DSIO_M3x2         = 24
D3DSIO_CALL         = 25
D3DSIO_CALLNZ       = 26
D3DSIO_LOOP         = 27
D3DSIO_RET          = 28
D3DSIO_ENDLOOP      = 29
D3DSIO_LABEL        = 30
D3DSIO_DCL          = 31
D3DSIO_POW          = 32
D3DSIO_CRS          = 33
D3DSIO_SGN          = 34
D3DSIO_ABS          = 35
D3DSIO_NRM          = 36
D3DSIO_SINCOS       = 37
D3DSIO_REP          = 38
D3DSIO_ENDREP       = 39
D3DSIO_IF           = 40
D3DSIO_IFC          = 41
D3DSIO_ELSE         = 42
D3DSIO_ENDIF        = 43
D3DSIO_BREAK        = 44
D3DSIO_BREAKC       = 45
D3DSIO_MOVA         = 46
D3DSIO_DEFB         = 48
D3DSIO_DEFI         = 49
D3DSIO_TEXCOORD     = 64
D3DSIO_TEXKILL      = 65
D3DSIO_TEX          = 66
D3DSIO_TEXBEM       = 67
D3DSIO_TEXBEML      = 68
D3DSIO_TEXREG2AR    = 69
D3DSIO_TEXREG2GB    = 70
D3DSIO_TEXM3x2PAD   = 71
D3DSIO_TEXM3x2TEX   = 72
D3DSIO_TEXM3x3PAD   = 73
D3DSIO_TEXM3x3TEX   = 74
D3DSIO_RESERVED0    = 75
D3DSIO_TEXM3x3SPEC  = 76
D3DSIO_TEXM3x3VSPEC = 77
D3DSIO_EXPP         = 78
D3DSIO_LOGP         = 79
D3DSIO_CND          = 80
D3DSIO_DEF          = 81
D3DSIO_TEXREG2RGB   = 82
D3DSIO_TEXDP3TEX    = 83
D3DSIO_TEXM3x2DEPTH = 84
D3DSIO_TEXDP3       = 85
D3DSIO_TEXM3x3      = 86
D3DSIO_TEXDEPTH     = 87
D3DSIO_CMP          = 88
D3DSIO_BEM          = 89
D3DSIO_DP2ADD       = 90
D3DSIO_DSX          = 91
D3DSIO_DSY          = 92
D3DSIO_TEXLDD       = 93
D3DSIO_SETP         = 94
D3DSIO_TEXLDL       = 95
D3DSIO_BREAKP       = 96
D3DSIO_PHASE        = 0xFFFD
D3DSIO_COMMENT      = 0xFFFE
D3DSIO_END          = 0xFFFF
D3DSIO_FORCE_DWORD  = 0x7fffffff

#define D3DSINCOSCONST1 -1.5500992e-006, -2.1701389e-005,  0.0026041667, 0.00026041668
#define D3DSINCOSCONST2 -0.020833334, -0.12500000, 1.0, 0.50000000

#define D3DSI_COISSUE           0x40000000

#define D3DSP_OPCODESPECIFICCONTROL_MASK  0x00ff0000
#define D3DSP_OPCODESPECIFICCONTROL_SHIFT 16

#define D3DSI_TEXLD_PROJECT (0x01 << 16)
#define D3DSI_TEXLD_BIAS    (0x02 << 16)

// enum _D3DSHADER_COMPARISON
D3DSPC_RESERVED0= 0
D3DSPC_GT       = 1
D3DSPC_EQ       = 2
D3DSPC_GE       = 3
D3DSPC_LT       = 4
D3DSPC_NE       = 5
D3DSPC_LE       = 6
D3DSPC_RESERVED1= 7

// Comparison is part of instruction opcode token:
#define D3DSHADER_COMPARISON_SHIFT D3DSP_OPCODESPECIFICCONTROL_SHIFT
#define D3DSHADER_COMPARISON_MASK  (0x7<<16)

//---------------------------------------------------------------------
// Predication flags on instruction token
#define D3DSHADER_INSTRUCTION_PREDICATED    (0x1 << 28)

//---------------------------------------------------------------------
// DCL Info Token Controls

// For dcl info tokens requiring a semantic (usage + index)
#define D3DSP_DCL_USAGE_SHIFT 0
#define D3DSP_DCL_USAGE_MASK  0x0000000f

#define D3DSP_DCL_USAGEINDEX_SHIFT 16
#define D3DSP_DCL_USAGEINDEX_MASK  0x000f0000

// DCL pixel shader sampler info token.
#define D3DSP_TEXTURETYPE_SHIFT 27
#define D3DSP_TEXTURETYPE_MASK  0x78000000

// enum _D3DSAMPLER_TEXTURE_TYPE
D3DSTT_UNKNOWN = 0<<D3DSP_TEXTURETYPE_SHIFT
D3DSTT_2D      = 2<<D3DSP_TEXTURETYPE_SHIFT
D3DSTT_CUBE    = 3<<D3DSP_TEXTURETYPE_SHIFT
D3DSTT_VOLUME  = 4<<D3DSP_TEXTURETYPE_SHIFT
D3DSTT_FORCE_DWORD  = 0x7fffffff

#define D3DSP_REGNUM_MASK       0x000007FF

#define D3DSP_WRITEMASK_0       0x00010000
#define D3DSP_WRITEMASK_1       0x00020000
#define D3DSP_WRITEMASK_2       0x00040000
#define D3DSP_WRITEMASK_3       0x00080000
#define D3DSP_WRITEMASK_ALL     0x000F0000

#define D3DSP_DSTMOD_SHIFT      20
#define D3DSP_DSTMOD_MASK       0x00F00000

#define    D3DSPDM_NONE                 (0<<D3DSP_DSTMOD_SHIFT)
#define    D3DSPDM_SATURATE             (1<<D3DSP_DSTMOD_SHIFT)
#define    D3DSPDM_PARTIALPRECISION     (2<<D3DSP_DSTMOD_SHIFT)
#define    D3DSPDM_MSAMPCENTROID        (4<<D3DSP_DSTMOD_SHIFT)

#define D3DSP_DSTSHIFT_SHIFT    24
#define D3DSP_DSTSHIFT_MASK     0x0F000000

#define D3DSP_REGTYPE_SHIFT     28
#define D3DSP_REGTYPE_SHIFT2    8
#define D3DSP_REGTYPE_MASK      0x70000000
#define D3DSP_REGTYPE_MASK2     0x00001800

// enum _D3DSHADER_PARAM_REGISTER_TYPE
D3DSPR_TEMP           =  0
D3DSPR_INPUT          =  1
D3DSPR_CONST          =  2
D3DSPR_ADDR           =  3
D3DSPR_TEXTURE        =  3
D3DSPR_RASTOUT        =  4
D3DSPR_ATTROUT        =  5
D3DSPR_TEXCRDOUT      =  6
D3DSPR_OUTPUT         =  6
D3DSPR_CONSTINT       =  7
D3DSPR_COLOROUT       =  8
D3DSPR_DEPTHOUT       =  9
D3DSPR_SAMPLER        = 10
D3DSPR_CONST2         = 11
D3DSPR_CONST3         = 12
D3DSPR_CONST4         = 13
D3DSPR_CONSTBOOL      = 14
D3DSPR_LOOP           = 15
D3DSPR_TEMPFLOAT16    = 16
D3DSPR_MISCTYPE       = 17
D3DSPR_LABEL          = 18
D3DSPR_PREDICATE      = 19
D3DSPR_FORCE_DWORD  = 0x7fffffff

// enum _D3DSHADER_MISCTYPE_OFFSETS
D3DSMO_POSITION   = 0
D3DSMO_FACE   = 1

// enum _D3DVS_RASTOUT_OFFSETS
D3DSRO_POSITION = 0
D3DSRO_FOG = 1
D3DSRO_POINT_SIZE = 2
D3DSRO_FORCE_DWORD  = 0x7fffffff

#define D3DVS_ADDRESSMODE_SHIFT 13
#define D3DVS_ADDRESSMODE_MASK  (1 << D3DVS_ADDRESSMODE_SHIFT)

// enum _D3DVS_ADDRESSMODE_TYPE
D3DVS_ADDRMODE_ABSOLUTE  = (0 << D3DVS_ADDRESSMODE_SHIFT)
D3DVS_ADDRMODE_RELATIVE  = (1 << D3DVS_ADDRESSMODE_SHIFT)
D3DVS_ADDRMODE_FORCE_DWORD = 0x7fffffff

#define D3DSHADER_ADDRESSMODE_SHIFT 13
#define D3DSHADER_ADDRESSMODE_MASK  (1 << D3DSHADER_ADDRESSMODE_SHIFT)

// enum _D3DSHADER_ADDRESSMODE_TYPE
D3DSHADER_ADDRMODE_ABSOLUTE  = (0 << D3DSHADER_ADDRESSMODE_SHIFT)
D3DSHADER_ADDRMODE_RELATIVE  = (1 << D3DSHADER_ADDRESSMODE_SHIFT)
D3DSHADER_ADDRMODE_FORCE_DWORD = 0x7fffffff

#define D3DVS_SWIZZLE_SHIFT     16
#define D3DVS_SWIZZLE_MASK      0x00FF0000

#define D3DVS_X_X       (0 << D3DVS_SWIZZLE_SHIFT)
#define D3DVS_X_Y       (1 << D3DVS_SWIZZLE_SHIFT)
#define D3DVS_X_Z       (2 << D3DVS_SWIZZLE_SHIFT)
#define D3DVS_X_W       (3 << D3DVS_SWIZZLE_SHIFT)

#define D3DVS_Y_X       (0 << (D3DVS_SWIZZLE_SHIFT + 2))
#define D3DVS_Y_Y       (1 << (D3DVS_SWIZZLE_SHIFT + 2))
#define D3DVS_Y_Z       (2 << (D3DVS_SWIZZLE_SHIFT + 2))
#define D3DVS_Y_W       (3 << (D3DVS_SWIZZLE_SHIFT + 2))

#define D3DVS_Z_X       (0 << (D3DVS_SWIZZLE_SHIFT + 4))
#define D3DVS_Z_Y       (1 << (D3DVS_SWIZZLE_SHIFT + 4))
#define D3DVS_Z_Z       (2 << (D3DVS_SWIZZLE_SHIFT + 4))
#define D3DVS_Z_W       (3 << (D3DVS_SWIZZLE_SHIFT + 4))

#define D3DVS_W_X       (0 << (D3DVS_SWIZZLE_SHIFT + 6))
#define D3DVS_W_Y       (1 << (D3DVS_SWIZZLE_SHIFT + 6))
#define D3DVS_W_Z       (2 << (D3DVS_SWIZZLE_SHIFT + 6))
#define D3DVS_W_W       (3 << (D3DVS_SWIZZLE_SHIFT + 6))

#define D3DVS_NOSWIZZLE (D3DVS_X_X | D3DVS_Y_Y | D3DVS_Z_Z | D3DVS_W_W)

#define D3DSP_SWIZZLE_SHIFT     16
#define D3DSP_SWIZZLE_MASK      0x00FF0000

#define D3DSP_NOSWIZZLE \
    ( (0 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (3 << (D3DSP_SWIZZLE_SHIFT + 6)) )

// pixel-shader swizzle ops
#define D3DSP_REPLICATERED \
    ( (0 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (0 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (0 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (0 << (D3DSP_SWIZZLE_SHIFT + 6)) )

#define D3DSP_REPLICATEGREEN \
    ( (1 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (1 << (D3DSP_SWIZZLE_SHIFT + 6)) )

#define D3DSP_REPLICATEBLUE \
    ( (2 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (2 << (D3DSP_SWIZZLE_SHIFT + 6)) )

#define D3DSP_REPLICATEALPHA \
    ( (3 << (D3DSP_SWIZZLE_SHIFT + 0)) | \
      (3 << (D3DSP_SWIZZLE_SHIFT + 2)) | \
      (3 << (D3DSP_SWIZZLE_SHIFT + 4)) | \
      (3 << (D3DSP_SWIZZLE_SHIFT + 6)) )

// source parameter modifiers
#define D3DSP_SRCMOD_SHIFT      24
#define D3DSP_SRCMOD_MASK       0x0F000000

// enum _D3DSHADER_PARAM_SRCMOD_TYPE
D3DSPSM_NONE    = 0<<D3DSP_SRCMOD_SHIFT
D3DSPSM_NEG     = 1<<D3DSP_SRCMOD_SHIFT
D3DSPSM_BIAS    = 2<<D3DSP_SRCMOD_SHIFT
D3DSPSM_BIASNEG = 3<<D3DSP_SRCMOD_SHIFT
D3DSPSM_SIGN    = 4<<D3DSP_SRCMOD_SHIFT
D3DSPSM_SIGNNEG = 5<<D3DSP_SRCMOD_SHIFT
D3DSPSM_COMP    = 6<<D3DSP_SRCMOD_SHIFT
D3DSPSM_X2      = 7<<D3DSP_SRCMOD_SHIFT
D3DSPSM_X2NEG   = 8<<D3DSP_SRCMOD_SHIFT
D3DSPSM_DZ      = 9<<D3DSP_SRCMOD_SHIFT
D3DSPSM_DW      = 10<<D3DSP_SRCMOD_SHIFT
D3DSPSM_ABS     = 11<<D3DSP_SRCMOD_SHIFT
D3DSPSM_ABSNEG  = 12<<D3DSP_SRCMOD_SHIFT
D3DSPSM_NOT     = 13<<D3DSP_SRCMOD_SHIFT
D3DSPSM_FORCE_DWORD = 0x7fffffff

#define D3DSI_COMMENTSIZE_SHIFT     16
#define D3DSI_COMMENTSIZE_MASK      0x7FFF0000

#define D3DPS_END  0x0000FFFF
#define D3DVS_END  0x0000FFFF

// enum _D3DBASISTYPE
D3DBASIS_BEZIER      = 0
D3DBASIS_BSPLINE     = 1
D3DBASIS_CATMULL_ROM = 2
D3DBASIS_FORCE_DWORD = 0x7fffffff

// enum _D3DDEGREETYPE
D3DDEGREE_LINEAR      = 1
D3DDEGREE_QUADRATIC   = 2
D3DDEGREE_CUBIC       = 3
D3DDEGREE_QUINTIC     = 5
D3DDEGREE_FORCE_DWORD = 0x7fffffff

// enum _D3DPATCHEDGESTYLE
D3DPATCHEDGE_DISCRETE    = 0
D3DPATCHEDGE_CONTINUOUS  = 1
D3DPATCHEDGE_FORCE_DWORD = 0x7fffffff

// enum _D3DSTATEBLOCKTYPE
D3DSBT_ALL           = 1
D3DSBT_PIXELSTATE    = 2
D3DSBT_VERTEXSTATE   = 3
D3DSBT_FORCE_DWORD   = 0x7fffffff

// The D3DVERTEXBLENDFLAGS type is used with D3DRS_VERTEXBLEND state.
//
// enum _D3DVERTEXBLENDFLAGS
D3DVBF_DISABLE  = 0
D3DVBF_1WEIGHTS = 1
D3DVBF_2WEIGHTS = 2
D3DVBF_3WEIGHTS = 3
D3DVBF_TWEENING = 255
D3DVBF_0WEIGHTS = 256
D3DVBF_FORCE_DWORD = 0x7fffffff

// enum _D3DTEXTURETRANSFORMFLAGS {
D3DTTFF_DISABLE         = 0
D3DTTFF_COUNT1          = 1
D3DTTFF_COUNT2          = 2
D3DTTFF_COUNT3          = 3
D3DTTFF_COUNT4          = 4
D3DTTFF_PROJECTED       = 256
D3DTTFF_FORCE_DWORD     = 0x7fffffff

// Macros to set texture coordinate format bits in the FVF id

#define D3DFVF_TEXTUREFORMAT2 0         // Two floating point values
#define D3DFVF_TEXTUREFORMAT1 3         // One floating point value
#define D3DFVF_TEXTUREFORMAT3 1         // Three floating point values
#define D3DFVF_TEXTUREFORMAT4 2         // Four floating point values

// enum _D3DDEVTYPE
D3DDEVTYPE_HAL         = 1
D3DDEVTYPE_REF         = 2
D3DDEVTYPE_SW          = 3
D3DDEVTYPE_NULLREF     = 4
D3DDEVTYPE_FORCE_DWORD  = 0x7fffffff

// enum _D3DMULTISAMPLE_TYPE
D3DMULTISAMPLE_NONE            =  0
D3DMULTISAMPLE_NONMASKABLE     =  1
D3DMULTISAMPLE_2_SAMPLES       =  2
D3DMULTISAMPLE_3_SAMPLES       =  3
D3DMULTISAMPLE_4_SAMPLES       =  4
D3DMULTISAMPLE_5_SAMPLES       =  5
D3DMULTISAMPLE_6_SAMPLES       =  6
D3DMULTISAMPLE_7_SAMPLES       =  7
D3DMULTISAMPLE_8_SAMPLES       =  8
D3DMULTISAMPLE_9_SAMPLES       =  9
D3DMULTISAMPLE_10_SAMPLES      = 10
D3DMULTISAMPLE_11_SAMPLES      = 11
D3DMULTISAMPLE_12_SAMPLES      = 12
D3DMULTISAMPLE_13_SAMPLES      = 13
D3DMULTISAMPLE_14_SAMPLES      = 14
D3DMULTISAMPLE_15_SAMPLES      = 15
D3DMULTISAMPLE_16_SAMPLES      = 16
D3DMULTISAMPLE_FORCE_DWORD     = 0x7fffffff

#ifndef MAKEFOURCC
MAKEFOURCC(%ch0, %ch1, %ch2, %ch3) macro
	(%ch0 | (%ch1 << 8) | (%ch2 << 16) | (%ch3 << 24 ))
endm
#endif

// enum _D3DFORMAT
D3DFMT_UNKNOWN              =  0
D3DFMT_R8G8B8               = 20
D3DFMT_A8R8G8B8             = 21
D3DFMT_X8R8G8B8             = 22
D3DFMT_R5G6B5               = 23
D3DFMT_X1R5G5B5             = 24
D3DFMT_A1R5G5B5             = 25
D3DFMT_A4R4G4B4             = 26
D3DFMT_R3G3B2               = 27
D3DFMT_A8                   = 28
D3DFMT_A8R3G3B2             = 29
D3DFMT_X4R4G4B4             = 30
D3DFMT_A2B10G10R10          = 31
D3DFMT_A8B8G8R8             = 32
D3DFMT_X8B8G8R8             = 33
D3DFMT_G16R16               = 34
D3DFMT_A2R10G10B10          = 35
D3DFMT_A16B16G16R16         = 36
D3DFMT_A8P8                 = 40
D3DFMT_P8                   = 41
D3DFMT_L8                   = 50
D3DFMT_A8L8                 = 51
D3DFMT_A4L4                 = 52
D3DFMT_V8U8                 = 60
D3DFMT_L6V5U5               = 61
D3DFMT_X8L8V8U8             = 62
D3DFMT_Q8W8V8U8             = 63
D3DFMT_V16U16               = 64
D3DFMT_A2W10V10U10          = 67
D3DFMT_UYVY                 = MAKEFOURCC('U', 'Y', 'V', 'Y')
D3DFMT_R8G8_B8G8            = MAKEFOURCC('R', 'G', 'B', 'G')
D3DFMT_YUY2                 = MAKEFOURCC('Y', 'U', 'Y', '2')
D3DFMT_G8R8_G8B8            = MAKEFOURCC('G', 'R', 'G', 'B')
D3DFMT_DXT1                 = MAKEFOURCC('D', 'X', 'T', '1')
D3DFMT_DXT2                 = MAKEFOURCC('D', 'X', 'T', '2')
D3DFMT_DXT3                 = MAKEFOURCC('D', 'X', 'T', '3')
D3DFMT_DXT4                 = MAKEFOURCC('D', 'X', 'T', '4')
D3DFMT_DXT5                 = MAKEFOURCC('D', 'X', 'T', '5')
D3DFMT_D16_LOCKABLE         = 70
D3DFMT_D32                  = 71
D3DFMT_D15S1                = 73
D3DFMT_D24S8                = 75
D3DFMT_D24X8                = 77
D3DFMT_D24X4S4              = 79
D3DFMT_D16                  = 80
D3DFMT_D32F_LOCKABLE        = 82
D3DFMT_D24FS8               = 83
D3DFMT_D32_LOCKABLE         = 84
D3DFMT_S8_LOCKABLE          = 85
D3DFMT_L16                  = 81
D3DFMT_VERTEXDATA           =100
D3DFMT_INDEX16              =101
D3DFMT_INDEX32              =102
D3DFMT_Q16W16V16U16         =110
D3DFMT_MULTI2_ARGB8         = MAKEFOURCC('M','E','T','1')
D3DFMT_R16F                 = 111
D3DFMT_G16R16F              = 112
D3DFMT_A16B16G16R16F        = 113
D3DFMT_R32F                 = 114
D3DFMT_G32R32F              = 115
D3DFMT_A32B32G32R32F        = 116
D3DFMT_CxV8U8               = 117
D3DFMT_A1                   = 118
D3DFMT_A2B10G10R10_XR_BIAS  = 119
D3DFMT_BINARYBUFFER         = 199
D3DFMT_FORCE_DWORD          =0x7fffffff

D3DDISPLAYMODE STRUCT
	Width DD
	Height DD
	RefreshRate DD
	Format ENUM // D3DFORMAT
ENDS

D3DDEVICE_CREATION_PARAMETERS STRUCT
	AdapterOrdinal DD
	DeviceType ENUM // D3DDEVTYPE
	hFocusWindow HANDLE
	BehaviorFlags DD
ENDS

// enum _D3DSWAPEFFECT
D3DSWAPEFFECT_DISCARD           = 1
D3DSWAPEFFECT_FLIP              = 2
D3DSWAPEFFECT_COPY              = 3
D3DSWAPEFFECT_OVERLAY           = 4
D3DSWAPEFFECT_FLIPEX            = 5
D3DSWAPEFFECT_FORCE_DWORD       = 0x7fffffff

// enum _D3DPOOL {
D3DPOOL_DEFAULT                 = 0
D3DPOOL_MANAGED                 = 1
D3DPOOL_SYSTEMMEM               = 2
D3DPOOL_SCRATCH                 = 3
D3DPOOL_FORCE_DWORD             = 0x7fffffff

#define D3DPRESENT_RATE_DEFAULT         0x00000000

/* Resize Optional Parameters */
D3DPRESENT_PARAMETERS STRUCT
	BackBufferWidth DD
	BackBufferHeight DD
	BackBufferFormat ENUM // D3DFORMAT
	BackBufferCount DD
	MultiSampleType ENUM // D3DMULTISAMPLE_TYPE
	MultiSampleQuality DD
	SwapEffect ENUM // D3DSWAPEFFECT
	hDeviceWindow HANDLE
	Windowed BOOL
	EnableAutoDepthStencil BOOL
	AutoDepthStencilFormat ENUM // D3DFORMAT
	Flags DD
	FullScreen_RefreshRateInHz DD
	PresentationInterval DD
ENDS

// Values for D3DPRESENT_PARAMETERS.Flags

#define D3DPRESENTFLAG_LOCKABLE_BACKBUFFER      0x00000001
#define D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL     0x00000002
#define D3DPRESENTFLAG_DEVICECLIP               0x00000004
#define D3DPRESENTFLAG_VIDEO                    0x00000010
#define D3DPRESENTFLAG_NOAUTOROTATE                    0x00000020
#define D3DPRESENTFLAG_UNPRUNEDMODE                    0x00000040
#define D3DPRESENTFLAG_OVERLAY_LIMITEDRGB              0x00000080
#define D3DPRESENTFLAG_OVERLAY_YCbCr_BT709             0x00000100
#define D3DPRESENTFLAG_OVERLAY_YCbCr_xvYCC             0x00000200
#define D3DPRESENTFLAG_RESTRICTED_CONTENT              0x00000400
#define D3DPRESENTFLAG_RESTRICT_SHARED_RESOURCE_DRIVER 0x00000800

D3DGAMMARAMP STRUCT
	red   DW 256 DUP
	green DW 256 DUP
	blue  DW 256 DUP
ENDS

// enum _D3DBACKBUFFER_TYPE
D3DBACKBUFFER_TYPE_MONO         = 0
D3DBACKBUFFER_TYPE_LEFT         = 1
D3DBACKBUFFER_TYPE_RIGHT        = 2
D3DBACKBUFFER_TYPE_FORCE_DWORD  = 0x7fffffff

// enum _D3DRESOURCETYPE {
D3DRTYPE_SURFACE                =  1
D3DRTYPE_VOLUME                 =  2
D3DRTYPE_TEXTURE                =  3
D3DRTYPE_VOLUMETEXTURE          =  4
D3DRTYPE_CUBETEXTURE            =  5
D3DRTYPE_VERTEXBUFFER           =  6
D3DRTYPE_INDEXBUFFER            =  7
D3DRTYPE_FORCE_DWORD            = 0x7fffffff


/* Usages */
#define D3DUSAGE_RENDERTARGET       0x00000001
#define D3DUSAGE_DEPTHSTENCIL       0x00000002
#define D3DUSAGE_DYNAMIC            0x00000200
#define D3DUSAGE_NONSECURE          0x00800000
#define D3DUSAGE_AUTOGENMIPMAP      0x00000400
#define D3DUSAGE_DMAP               0x00004000

#define D3DUSAGE_QUERY_LEGACYBUMPMAP            0x00008000
#define D3DUSAGE_QUERY_SRGBREAD                 0x00010000
#define D3DUSAGE_QUERY_FILTER                   0x00020000
#define D3DUSAGE_QUERY_SRGBWRITE                0x00040000
#define D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING 0x00080000
#define D3DUSAGE_QUERY_VERTEXTEXTURE            0x00100000
#define D3DUSAGE_QUERY_WRAPANDMIP	            0x00200000

#define D3DUSAGE_WRITEONLY          0x00000008
#define D3DUSAGE_SOFTWAREPROCESSING 0x00000010
#define D3DUSAGE_DONOTCLIP          0x00000020
#define D3DUSAGE_POINTS             0x00000040
#define D3DUSAGE_RTPATCHES          0x00000080
#define D3DUSAGE_NPATCHES           0x00000100

#define D3DUSAGE_TEXTAPI                         0x10000000
#define D3DUSAGE_RESTRICTED_CONTENT              0x00000800
#define D3DUSAGE_RESTRICT_SHARED_RESOURCE        0x00002000
#define D3DUSAGE_RESTRICT_SHARED_RESOURCE_DRIVER 0x00001000 

// enum _D3DCUBEMAP_FACES
D3DCUBEMAP_FACE_POSITIVE_X     = 0
D3DCUBEMAP_FACE_NEGATIVE_X     = 1
D3DCUBEMAP_FACE_POSITIVE_Y     = 2
D3DCUBEMAP_FACE_NEGATIVE_Y     = 3
D3DCUBEMAP_FACE_POSITIVE_Z     = 4
D3DCUBEMAP_FACE_NEGATIVE_Z     = 5
D3DCUBEMAP_FACE_FORCE_DWORD    = 0x7fffffff

#define D3DLOCK_READONLY           0x00000010
#define D3DLOCK_DISCARD            0x00002000
#define D3DLOCK_NOOVERWRITE        0x00001000
#define D3DLOCK_NOSYSLOCK          0x00000800
#define D3DLOCK_DONOTWAIT          0x00004000                  

#define D3DLOCK_NO_DIRTY_UPDATE     0x00008000

D3DVERTEXBUFFER_DESC STRUCT
	Format ENUM // D3DFORMAT
	Type ENUM // D3DRESOURCETYPE
	Usage DD
	Pool ENUM // D3DPOOL
	Size DD
	FVF DD
ENDS

D3DINDEXBUFFER_DESC STRUCT
	Format ENUM // D3DFORMAT
	Type ENUM // D3DRESOURCETYPE
	Usage DD
	Pool ENUM // D3DPOOL
	Size DD
ENDS

D3DSURFACE_DESC STRUCT
	Format ENUM // D3DFORMAT
	Type ENUM // D3DRESOURCETYPE
	Usage DD
	Pool ENUM // D3DPOOL
	MultiSampleType ENUM // D3DMULTISAMPLE_TYPE
	MultiSampleQuality DD
	Width DD
	Height DD
ENDS

D3DVOLUME_DESC STRUCT
	Format ENUM // D3DFORMAT
	Type ENUM // D3DRESOURCETYPE
	Usage DD
	Pool ENUM // D3DPOOL
	Width DD
	Height DD
	Depth DD
ENDS

D3DLOCKED_RECT STRUCT
	Pitch DD
	pBits PTR
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
	Basis ENUM // D3DBASISTYPE
	Degree ENUM // D3DDEGREETYPE
ENDS

D3DTRIPATCH_INFO STRUCT
	StartVertexOffset DD
	NumVertices DD
	Basis ENUM // D3DBASISTYPE
	Degree ENUM // D3DDEGREETYPE
ENDS

#define MAX_DEVICE_IDENTIFIER_STRING        512

D3DADAPTER_IDENTIFIER9 STRUCT
	Driver CHAR MAX_DEVICE_IDENTIFIER_STRING DUP
	Description CHAR MAX_DEVICE_IDENTIFIER_STRING DUP
	DeviceName CHAR 32 DUP
	DriverVersion LARGE_INTEGER
	VendorId DD
	DeviceId DD
	SubSysId DD
	Revision DD
	DeviceIdentifier GUID
	WHQLLevel DD
ENDS

D3DRASTER_STATUS STRUCT
	InVBlank BOOL
	ScanLine DD
ENDS

// enum _D3DDEBUGMONITORTOKENS {
D3DDMT_ENABLE            = 0
D3DDMT_DISABLE           = 1
D3DDMT_FORCE_DWORD     = 0x7fffffff

// enum _D3DQUERYTYPE {
D3DQUERYTYPE_VCACHE                 = 4
D3DQUERYTYPE_RESOURCEMANAGER        = 5
D3DQUERYTYPE_VERTEXSTATS            = 6
D3DQUERYTYPE_EVENT                  = 8
D3DQUERYTYPE_OCCLUSION              = 9
D3DQUERYTYPE_TIMESTAMP              = 10
D3DQUERYTYPE_TIMESTAMPDISJOINT      = 11
D3DQUERYTYPE_TIMESTAMPFREQ          = 12
D3DQUERYTYPE_PIPELINETIMINGS        = 13
D3DQUERYTYPE_INTERFACETIMINGS       = 14
D3DQUERYTYPE_VERTEXTIMINGS          = 15
D3DQUERYTYPE_PIXELTIMINGS           = 16
D3DQUERYTYPE_BANDWIDTHTIMINGS       = 17
D3DQUERYTYPE_CACHEUTILIZATION       = 18
D3DQUERYTYPE_MEMORYPRESSURE         = 19

#define D3DISSUE_END 1
#define D3DISSUE_BEGIN 2

#define D3DGETDATA_FLUSH 1

D3DRESOURCESTATS STRUCT
	bThrashing BOOL
	ApproxBytesDownloaded DD
	NumEvicts DD
	NumVidCreates DD
	LastPri DD
	NumUsed DD
	NumUsedInVidMem DD
	WorkingSet DD
	WorkingSetBytes DD
	TotalManaged DD
	TotalBytes DD
ENDS

#define D3DRTYPECOUNT (D3DRTYPE_INDEXBUFFER+1)

D3DDEVINFO_RESOURCEMANAGER STRUCT
	stats D3DRESOURCESTATS 8 DUP
ENDS

D3DDEVINFO_D3DVERTEXSTATS STRUCT
	NumRenderedTriangles DD
	NumExtraClippingTriangles DD
ENDS

D3DDEVINFO_VCACHE STRUCT
	Pattern DD
	OptMethod DD
	CacheSize DD
	MagicNumber DD
ENDS

D3DDEVINFO_D3D9PIPELINETIMINGS STRUCT
	VertexProcessingTimePercent FLOAT
	PixelProcessingTimePercent FLOAT
	OtherGPUProcessingTimePercent FLOAT
	GPUIdleTimePercent FLOAT
ENDS

D3DDEVINFO_D3D9INTERFACETIMINGS STRUCT
	WaitingForGPUToUseApplicationResourceTimePercent FLOAT
	WaitingForGPUToAcceptMoreCommandsTimePercent FLOAT
	WaitingForGPUToStayWithinLatencyTimePercent FLOAT
	WaitingForGPUExclusiveResourceTimePercent FLOAT
	WaitingForGPUOtherTimePercent FLOAT
ENDS

D3DDEVINFO_D3D9STAGETIMINGS STRUCT
	MemoryProcessingPercent FLOAT
	ComputationProcessingPercent FLOAT
ENDS

D3DDEVINFO_D3D9BANDWIDTHTIMINGS STRUCT
	MaxBandwidthUtilized FLOAT
	FrontEndUploadMemoryUtilizedPercent FLOAT
	VertexRateUtilizedPercent FLOAT
	TriangleSetupRateUtilizedPercent FLOAT
	FillRateUtilizedPercent FLOAT
ENDS

D3DDEVINFO_D3D9CACHEUTILIZATION STRUCT
	TextureCacheHitRate FLOAT
	PostTransformVertexCacheHitRate FLOAT
ENDS

D3DMEMORYPRESSURE STRUCT
	BytesEvictedFromProcess DQ
	SizeOfInefficientAllocation DQ
	LevelOfEfficiency DD
ENDS

// enum _D3DCOMPOSERECTSOP{
D3DCOMPOSERECTS_COPY     = 1
D3DCOMPOSERECTS_OR       = 2
D3DCOMPOSERECTS_AND      = 3
D3DCOMPOSERECTS_NEG      = 4
D3DCOMPOSERECTS_FORCE_DWORD    = 0x7fffffff

D3DCOMPOSERECTDESC STRUCT
	X DW
    Y DW
	Width DW
	Height DW
ENDS

D3DCOMPOSERECTDESTINATION STRUCT
	SrcRectIndex DW
	Reserved DW
	X DW
	Y DW
ENDS

#define D3DCOMPOSERECTS_MAXNUMRECTS 0xFFFF
#define D3DCONVOLUTIONMONO_MAXWIDTH  7
#define D3DCONVOLUTIONMONO_MAXHEIGHT D3DCONVOLUTIONMONO_MAXWIDTH
#define D3DFMT_A1_SURFACE_MAXWIDTH  8192
#define D3DFMT_A1_SURFACE_MAXHEIGHT 2048

D3DPRESENTSTATS STRUCT
	PresentCount DD
	PresentRefreshCount DD
	SyncRefreshCount DD
	SyncQPCTime LARGE_INTEGER
	SyncGPUTime LARGE_INTEGER
ENDS

// enum D3DSCANLINEORDERING
D3DSCANLINEORDERING_UNKNOWN                    = 0 
D3DSCANLINEORDERING_PROGRESSIVE                = 1
D3DSCANLINEORDERING_INTERLACED                 = 2

D3DDISPLAYMODEEX STRUCT
	Size DD
	Width DD
	Height DD
	RefreshRate DD
	Format ENUM // D3DFORMAT
	ScanLineOrdering ENUM // D3DSCANLINEORDERING
ENDS

D3DDISPLAYMODEFILTER STRUCT
	Size DD
	Format ENUM // D3DFORMAT
	ScanLineOrdering ENUM // D3DSCANLINEORDERING
ENDS


// enum D3DDISPLAYROTATION
D3DDISPLAYROTATION_IDENTITY = 1           
D3DDISPLAYROTATION_90       = 2
D3DDISPLAYROTATION_180      = 3
D3DDISPLAYROTATION_270      = 4

#define D3D9_RESOURCE_PRIORITY_MINIMUM       0x28000000
#define D3D9_RESOURCE_PRIORITY_LOW           0x50000000
#define D3D9_RESOURCE_PRIORITY_NORMAL        0x78000000
#define D3D9_RESOURCE_PRIORITY_HIGH          0xa0000000
#define D3D9_RESOURCE_PRIORITY_MAXIMUM       0xc8000000

#define D3D_OMAC_SIZE    16

D3D_OMAC STRUCT
	Omac DB D3D_OMAC_SIZE DUP
ENDS

// enum _D3DAUTHENTICATEDCHANNELTYPE
D3DAUTHENTICATEDCHANNEL_D3D9            = 1
D3DAUTHENTICATEDCHANNEL_DRIVER_SOFTWARE = 2
D3DAUTHENTICATEDCHANNEL_DRIVER_HARDWARE = 3

D3DAUTHENTICATEDCHANNEL_QUERY_INPUT STRUCT
	QueryType GUID
	hChannel HANDLE
	SequenceNumber DD
ENDS

D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT STRUCT
	omac D3D_OMAC
	QueryType GUID
	hChannel HANDLE
	SequenceNumber DD
	ReturnCode HANDLE
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_PROTECTION <0xa84eb584, 0xc495, 0x48aa, <0xb9, 0x4d, 0x8b, 0xd2, 0xd6, 0xfb, 0xce, 0x5>>

D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS STRUCT
	Value DD
ENDS

D3DAUTHENTICATEDCHANNEL_QUERYPROTECTION_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	ProtectionFlags D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS
ENDS


#DEFINE GUID_D3DAUTHENTICATEDQUERY_CHANNELTYPE <0xbc1b18a5, 0xb1fb, 0x42ab, <0xbd, 0x94, 0xb5, 0x82, 0x8b, 0x4b, 0xf7, 0xbe>>

D3DAUTHENTICATEDCHANNEL_QUERYCHANNELTYPE_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	ChannelType ENUM // D3DAUTHENTICATEDCHANNELTYPE
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_DEVICEHANDLE <0xec1c539d, 0x8cff, 0x4e2a, <0xbc, 0xc4, 0xf5, 0x69, 0x2f, 0x99, 0xf4, 0x80>>

D3DAUTHENTICATEDCHANNEL_QUERYDEVICEHANDLE_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	DeviceHandle HANDLE
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_CRYPTOSESSION <0x2634499e, 0xd018, 0x4d74, <0xac, 0x17, 0x7f, 0x72, 0x40, 0x59, 0x52, 0x8d>>

D3DAUTHENTICATEDCHANNEL_QUERYCRYPTOSESSION_INPUT STRUCT
	Input D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
	DXVA2DecodeHandle HANDLE
ENDS

D3DAUTHENTICATEDCHANNEL_QUERYCRYPTOSESSION_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	DXVA2DecodeHandle HANDLE
	CryptoSessionHandle HANDLE
	DeviceHandle HANDLE
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_RESTRICTEDSHAREDRESOURCEPROCESSCOUNT <0xdb207b3, 0x9450, 0x46a6, <0x82, 0xde, 0x1b, 0x96, 0xd4, 0x4f, 0x9c, 0xf2>>

D3DAUTHENTICATEDCHANNEL_QUERYRESTRICTEDSHAREDRESOURCEPROCESSCOUNT_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	NumRestrictedSharedResourceProcesses DD
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_RESTRICTEDSHAREDRESOURCEPROCESS <0x649bbadb, 0xf0f4, 0x4639, <0xa1, 0x5b, 0x24, 0x39, 0x3f, 0xc3, 0xab, 0xac>>

D3DAUTHENTICATEDCHANNEL_QUERYRESTRICTEDSHAREDRESOURCEPROCESS_INPUT STRUCT
	Input D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
	ProcessIndex DD
ENDS

// enum _D3DAUTHENTICATEDCHANNEL_PROCESSIDENTIFIERTYPE
PROCESSIDTYPE_UNKNOWN  = 0
PROCESSIDTYPE_DWM      = 1
PROCESSIDTYPE_HANDLE   = 2

D3DAUTHENTICATEDCHANNEL_QUERYRESTRICTEDSHAREDRESOURCEPROCESS_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	ProcessIndex DD
	ProcessIdentifer ENUM // D3DAUTHENTICATEDCHANNEL_PROCESSIDENTIFIERTYPE
	ProcessHandle HANDLE
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_UNRESTRICTEDPROTECTEDSHAREDRESOURCECOUNT <0x12f0bd6, 0xe662, 0x4474, <0xbe, 0xfd, 0xaa, 0x53, 0xe5, 0x14, 0x3c, 0x6d>>

D3DAUTHENTICATEDCHANNEL_QUERYUNRESTRICTEDPROTECTEDSHAREDRESOURCECOUNT_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	NumUnrestrictedProtectedSharedResources DD
ENDS

#DEFINE_GUID(D3DAUTHENTICATEDQUERY_OUTPUTIDCOUNT <0x2c042b5e, 0x8c07, 0x46d5, <0xaa, 0xbe, 0x8f, 0x75, 0xcb, 0xad, 0x4c, 0x31>>

D3DAUTHENTICATEDCHANNEL_QUERYOUTPUTIDCOUNT_INPUT STRUCT
	Input D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
	DeviceHandle HANDLE
	CryptoSessionHandle HANDLE
ENDS

D3DAUTHENTICATEDCHANNEL_QUERYOUTPUTIDCOUNT_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	DeviceHandle HANDLE
	CryptoSessionHandle HANDLE
	NumOutputIDs DD
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_OUTPUTID <0x839ddca3, 0x9b4e, 0x41e4, <0xb0, 0x53, 0x89, 0x2b, 0xd2, 0xa1, 0x1e, 0xe7>>

D3DAUTHENTICATEDCHANNEL_QUERYOUTPUTID_INPUT STRUCT
	Input D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
	DeviceHandle HANDLE
	CryptoSessionHandle HANDLE	
	OutputIDIndex DD
ENDS

D3DAUTHENTICATEDCHANNEL_QUERYOUTPUTID_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	DeviceHandle HANDLE
	CryptoSessionHandle HANDLE
	OutputIDIndex DD
	OutputID DQ
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_ACCESSIBILITYATTRIBUTES <0x6214d9d2, 0x432c, 0x4abb, <0x9f, 0xce, 0x21, 0x6e, 0xea, 0x26, 0x9e, 0x3b>>

// enum _D3DBUSTYPE
D3DBUSTYPE_OTHER                                     = 0x00000000
D3DBUSTYPE_PCI                                       = 0x00000001
D3DBUSTYPE_PCIX                                      = 0x00000002
D3DBUSTYPE_PCIEXPRESS                                = 0x00000003
D3DBUSTYPE_AGP                                       = 0x00000004
D3DBUSIMPL_MODIFIER_INSIDE_OF_CHIPSET                = 0x00010000
D3DBUSIMPL_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_CHIP   = 0x00020000
D3DBUSIMPL_MODIFIER_TRACKS_ON_MOTHER_BOARD_TO_SOCKET = 0x00030000
D3DBUSIMPL_MODIFIER_DAUGHTER_BOARD_CONNECTOR         = 0x00040000
D3DBUSIMPL_MODIFIER_DAUGHTER_BOARD_CONNECTOR_INSIDE_OF_NUAE = 0x00050000 
D3DBUSIMPL_MODIFIER_NON_STANDARD                     = 0x80000000

D3DAUTHENTICATEDCHANNEL_QUERYINFOBUSTYPE_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	BusType ENUM // D3DBUSTYPE
	bAccessibleInContiguousBlocks BOOL
	bAccessibleInNonContiguousBlocks BOOL
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_ENCRYPTIONWHENACCESSIBLEGUIDCOUNT <0xb30f7066, 0x203c, 0x4b07, <0x93, 0xfc, 0xce, 0xaa, 0xfd, 0x61, 0x24, 0x1e>>

D3DAUTHENTICATEDCHANNEL_QUERYEVICTIONENCRYPTIONGUIDCOUNT_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	NumEncryptionGuids DD
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_ENCRYPTIONWHENACCESSIBLEGUID <0xf83a5958, 0xe986, 0x4bda, <0xbe, 0xb0, 0x41, 0x1f, 0x6a, 0x7a, 0x1, 0xb7>>

D3DAUTHENTICATEDCHANNEL_QUERYEVICTIONENCRYPTIONGUID_INPUT STRUCT
	Input D3DAUTHENTICATEDCHANNEL_QUERY_INPUT
	EncryptionGuidIndex DD
ENDS

D3DAUTHENTICATEDCHANNEL_QUERYEVICTIONENCRYPTIONGUID_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	EncryptionGuidIndex DD
	EncryptionGuid GUID
ENDS

#DEFINE GUID_D3DAUTHENTICATEDQUERY_CURRENTENCRYPTIONWHENACCESSIBLE <0xec1791c7, 0xdad3, 0x4f15, <0x9e, 0xc3, 0xfa, 0xa9, 0x3d, 0x60, 0xd4, 0xf0>>

D3DAUTHENTICATEDCHANNEL_QUERYUNCOMPRESSEDENCRYPTIONLEVEL_OUTPUT STRUCT
	Output D3DAUTHENTICATEDCHANNEL_QUERY_OUTPUT
	EncryptionGuid GUID
ENDS

D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT STRUCT
	omac D3D_OMAC
	ConfigureType GUID
	hChannel HANDLE
	SequenceNumber DD
ENDS

D3DAUTHENTICATEDCHANNEL_CONFIGURE_OUTPUT STRUCT
	omac D3D_OMAC
	ConfigureType GUID
	hChannel HANDLE
	SequenceNumber DD
	ReturnCode HANDLE
ENDS

#DEFINE GUID_D3DAUTHENTICATEDCONFIGURE_INITIALIZE <0x6114bdb, 0x3523, 0x470a, <0x8d, 0xca, 0xfb, 0xc2, 0x84, 0x51, 0x54, 0xf0>>

D3DAUTHENTICATEDCHANNEL_CONFIGUREINITIALIZE STRUCT
	Parameters D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
	StartSequenceQuery DD
	StartSequenceConfigure DD
ENDS

#DEFINE GUID_D3DAUTHENTICATEDCONFIGURE_PROTECTION <0x50455658, 0x3f47, 0x4362, <0xbf, 0x99, 0xbf, 0xdf, 0xcd, 0xe9, 0xed, 0x29>>

D3DAUTHENTICATEDCHANNEL_CONFIGUREPROTECTION STRUCT
	Parameters D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
	Protections ENUM // D3DAUTHENTICATEDCHANNEL_PROTECTION_FLAGS
ENDS

#DEFINE GUID_D3DAUTHENTICATEDCONFIGURE_CRYPTOSESSION <0x6346cc54, 0x2cfc, 0x4ad4, <0x82, 0x24, 0xd1, 0x58, 0x37, 0xde, 0x77, 0x0>>

D3DAUTHENTICATEDCHANNEL_CONFIGURECRYPTOSESSION STRUCT
	Parameters D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
	DXVA2DecodeHandle HANDLE
	CryptoSessionHandle HANDLE
	DeviceHandle HANDLE
ENDS


#DEFINE GUID_D3DAUTHENTICATEDCONFIGURE_SHAREDRESOURCE <0x772d047, 0x1b40, 0x48e8, <0x9c, 0xa6, 0xb5, 0xf5, 0x10, 0xde, 0x9f, 0x1>>

D3DAUTHENTICATEDCHANNEL_CONFIGURESHAREDRESOURCE STRUCT
	Parameters D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
	ProcessIdentiferType ENUM // D3DAUTHENTICATEDCHANNEL_PROCESSIDENTIFIERTYPE
	ProcessHandle HANDLE
	AllowAccess BOOL
ENDS

#DEFINE GUID_D3DAUTHENTICATEDCONFIGURE_ENCRYPTIONWHENACCESSIBLE <0x41fff286, 0x6ae0, 0x4d43, <0x9d, 0x55, 0xa4, 0x6e, 0x9e, 0xfd, 0x15, 0x8a>>

D3DAUTHENTICATEDCHANNEL_CONFIGUREUNCOMPRESSEDENCRYPTION STRUCT
	Parameters D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT
	EncryptionGuid GUID
ENDS

D3DENCRYPTED_BLOCK_INFO STRUCT
	NumEncryptedBytesAtBeginning DD    
	NumBytesInSkipPattern DD
	NumBytesInEncryptPattern DD
ENDS

D3DAES_CTR_IV STRUCT
	IV DQ
	Count DQ
ENDS

#endif


