#ifndef GLU_H
#define GLU_H

/* OpenGL Utility Library definitions */

#IFNDEF GL_H
	#include gl\gl.h
#ENDIF

#define GLU_VERSION_1_1  1
#define GLU_VERSION_1_2  1

#define GLU_INVALID_ENUM  100900
#define GLU_INVALID_VALUE  100901
#define GLU_OUT_OF_MEMORY  100902
#define GLU_INCOMPATIBLE_GL_VERSION  100903

#define GLU_VERSION  100800
#define GLU_EXTENSIONS  100801

#define GLU_TRUE  GL_TRUE
#define GLU_FALSE  GL_FALSE

#define GLU_SMOOTH  100000
#define GLU_FLAT  100001
#define GLU_NONE  100002

#define GLU_POINT  100010
#define GLU_LINE  100011
#define GLU_FILL  100012
#define GLU_SILHOUETTE  100013

#define GLU_OUTSIDE  100020
#define GLU_INSIDE  100021

#define GLU_TESS_MAX_COORD  1.0E150

#define GLU_TESS_WINDING_RULE  100140
#define GLU_TESS_BOUNDARY_ONLY  100141
#define GLU_TESS_TOLERANCE  100142

#define GLU_TESS_WINDING_ODD  100130
#define GLU_TESS_WINDING_NONZERO  100131
#define GLU_TESS_WINDING_POSITIVE  100132
#define GLU_TESS_WINDING_NEGATIVE  100133
#define GLU_TESS_WINDING_ABS_GEQ_TWO  100134

#define GLU_TESS_BEGIN  100100
#define GLU_TESS_VERTEX  100101
#define GLU_TESS_END  100102
#define GLU_TESS_ERROR  100103
#define GLU_TESS_EDGE_FLAG  100104
#define GLU_TESS_COMBINE  100105
#define GLU_TESS_BEGIN_DATA  100106
#define GLU_TESS_VERTEX_DATA  100107
#define GLU_TESS_END_DATA  100108
#define GLU_TESS_ERROR_DATA  100109
#define GLU_TESS_EDGE_FLAG_DATA  100110
#define GLU_TESS_COMBINE_DATA  100111

#define GLU_TESS_ERROR1  100151
#define GLU_TESS_ERROR2  100152
#define GLU_TESS_ERROR3  100153
#define GLU_TESS_ERROR4  100154
#define GLU_TESS_ERROR5  100155
#define GLU_TESS_ERROR6  100156
#define GLU_TESS_ERROR7  100157
#define GLU_TESS_ERROR8  100158

#define GLU_TESS_MISSING_BEGIN_POLYGON  GLU_TESS_ERROR1
#define GLU_TESS_MISSING_BEGIN_CONTOUR  GLU_TESS_ERROR2
#define GLU_TESS_MISSING_END_POLYGON  GLU_TESS_ERROR3
#define GLU_TESS_MISSING_END_CONTOUR  GLU_TESS_ERROR4
#define GLU_TESS_COORD_TOO_LARGE  GLU_TESS_ERROR5
#define GLU_TESS_NEED_COMBINE_CALLBACK  GLU_TESS_ERROR6

#define GLU_AUTO_LOAD_MATRIX  100200
#define GLU_CULLING  100201
#define GLU_SAMPLING_TOLERANCE  100203
#define GLU_DISPLAY_MODE  100204
#define GLU_PARAMETRIC_TOLERANCE  100202
#define GLU_SAMPLING_METHOD  100205
#define GLU_U_STEP  100206
#define GLU_V_STEP  100207

#define GLU_PATH_LENGTH  100215
#define GLU_PARAMETRIC_ERROR  100216
#define GLU_DOMAIN_DISTANCE  100217

#define GLU_MAP1_TRIM_2  100210
#define GLU_MAP1_TRIM_3  100211

#define GLU_OUTLINE_POLYGON  100240
#define GLU_OUTLINE_PATCH  100241

#define GLU_NURBS_ERROR1  100251
#define GLU_NURBS_ERROR2  100252
#define GLU_NURBS_ERROR3  100253
#define GLU_NURBS_ERROR4  100254
#define GLU_NURBS_ERROR5  100255
#define GLU_NURBS_ERROR6  100256
#define GLU_NURBS_ERROR7  100257
#define GLU_NURBS_ERROR8  100258
#define GLU_NURBS_ERROR9  100259
#define GLU_NURBS_ERROR10  100260
#define GLU_NURBS_ERROR11  100261
#define GLU_NURBS_ERROR12  100262
#define GLU_NURBS_ERROR13  100263
#define GLU_NURBS_ERROR14  100264
#define GLU_NURBS_ERROR15  100265
#define GLU_NURBS_ERROR16  100266
#define GLU_NURBS_ERROR17  100267
#define GLU_NURBS_ERROR18  100268
#define GLU_NURBS_ERROR19  100269
#define GLU_NURBS_ERROR20  100270
#define GLU_NURBS_ERROR21  100271
#define GLU_NURBS_ERROR22  100272
#define GLU_NURBS_ERROR23  100273
#define GLU_NURBS_ERROR24  100274
#define GLU_NURBS_ERROR25  100275
#define GLU_NURBS_ERROR26  100276
#define GLU_NURBS_ERROR27  100277
#define GLU_NURBS_ERROR28  100278
#define GLU_NURBS_ERROR29  100279
#define GLU_NURBS_ERROR30  100280
#define GLU_NURBS_ERROR31  100281
#define GLU_NURBS_ERROR32  100282
#define GLU_NURBS_ERROR33  100283
#define GLU_NURBS_ERROR34  100284
#define GLU_NURBS_ERROR35  100285
#define GLU_NURBS_ERROR36  100286
#define GLU_NURBS_ERROR37  100287

#define GLU_CW          100120  /*obsolete*/
#define GLU_CCW         100121  /*obsolete*/
#define GLU_INTERIOR    100122  /*obsolete*/
#define GLU_EXTERIOR    100123  /*obsolete*/
#define GLU_UNKNOWN     100124  /*obsolete*/

#define GLU_BEGIN       GLU_TESS_BEGIN
#define GLU_VERTEX      GLU_TESS_VERTEX
#define GLU_END         GLU_TESS_END
#define GLU_ERROR       GLU_TESS_ERROR
#define GLU_EDGE_FLAG   GLU_TESS_EDGE_FLAG

#endif
