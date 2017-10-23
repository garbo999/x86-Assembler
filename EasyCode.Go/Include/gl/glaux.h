#ifndef GLAUX_H
#define GLAUX_H

/* OpenGL Auxiliary Library definitions */

#IFNDEF WINDOWS_H
	#include windows.h
#ENDIF

#IFNDEF GL_H
	#include gl\gl.h
#ENDIF

#IFNDEF GLU_H
	#include gl\glu.h
#ENDIF

#define AUX_RGB  0
#define AUX_RGBA  AUX_RGB
#define AUX_INDEX  1
#define AUX_SINGLE  0
#define AUX_DOUBLE  2
#define AUX_DIRECT  0
#define AUX_INDIRECT  4

#define AUX_ACCUM  8
#define AUX_ALPHA  16
#define AUX_DEPTH24  32
#define AUX_STENCIL  64
#define AUX_AUX  128
#define AUX_DEPTH16  256
#define AUX_FIXED_332_PAL  512
#define AUX_DEPTH  AUX_DEPTH16

#define AUX_EXPOSE  1
#define AUX_CONFIG  2
#define AUX_DRAW  4
#define AUX_KEYEVENT  8
#define AUX_MOUSEDOWN  16
#define AUX_MOUSEUP  32
#define AUX_MOUSELOC  64

#define AUX_WINDOWX  0
#define AUX_WINDOWY  1
#define AUX_MOUSEX  0
#define AUX_MOUSEY  1
#define AUX_MOUSESTATUS  3
#define AUX_KEY  0
#define AUX_KEYSTATUS  1

#define AUX_LEFTBUTTON  1
#define AUX_RIGHTBUTTON  2
#define AUX_MIDDLEBUTTON  4
#define AUX_SHIFT  1
#define AUX_CONTROL  2

#define AUX_RETURN  0x0D
#define AUX_ESCAPE  0x1B
#define AUX_SPACE  0x20
#define AUX_LEFT  0x25
#define AUX_UP  0x26
#define AUX_RIGHT  0x27
#define AUX_DOWN  0x28
#define AUX_A  'A'
#define AUX_B  'B'
#define AUX_C  'C'
#define AUX_D  'D'
#define AUX_E  'E'
#define AUX_F  'F'
#define AUX_G  'G'
#define AUX_H  'H'
#define AUX_I  'I'
#define AUX_J  'J'
#define AUX_K  'K'
#define AUX_L  'L'
#define AUX_M  'M'
#define AUX_N  'N'
#define AUX_O  'O'
#define AUX_P  'P'
#define AUX_Q  'Q'
#define AUX_R  'R'
#define AUX_S  'S'
#define AUX_T  'T'
#define AUX_U  'U'
#define AUX_V  'V'
#define AUX_W  'W'
#define AUX_X  'X'
#define AUX_Y  'Y'
#define AUX_Z  'Z'
#define AUX_a  'a'
#define AUX_b  'b'
#define AUX_c  'c'
#define AUX_d  'd'
#define AUX_e  'e'
#define AUX_f  'f'
#define AUX_g  'g'
#define AUX_h  'h'
#define AUX_i  'i'
#define AUX_j  'j'
#define AUX_k  'k'
#define AUX_l  'l'
#define AUX_m  'm'
#define AUX_n  'n'
#define AUX_o  'o'
#define AUX_p  'p'
#define AUX_q  'q'
#define AUX_r  'r'
#define AUX_s  's'
#define AUX_t  't'
#define AUX_u  'u'
#define AUX_v  'v'
#define AUX_w  'w'
#define AUX_x  'x'
#define AUX_y  'y'
#define AUX_z  'z'
#define AUX_0  '0'
#define AUX_1  '1'
#define AUX_2  '2'
#define AUX_3  '3'
#define AUX_4  '4'
#define AUX_5  '5'
#define AUX_6  '6'
#define AUX_7  '7'
#define AUX_8  '8'
#define AUX_9  '9'

#define AUX_FD  1
#define AUX_COLORMAP  3
#define AUX_GREYSCALEMAP  4
#define AUX_FOGMAP  5
#define AUX_ONECOLOR  6

#define AUX_BLACK  0
#define AUX_RED  13
#define AUX_GREEN  14
#define AUX_YELLOW  15
#define AUX_BLUE  16
#define AUX_MAGENTA  17
#define AUX_CYAN  18
#define AUX_WHITE  19

AUX_EVENTREC STRUCT
	event DD
	data DD 4 DUP (?)
ENDS

AUX_RGBImageRec STRUCT
	sizeX DD
	sizeY DD
	data  DD
ENDS

AUX_USE_ID = 1
AUX_EXACT_MATCH = 2
AUX_MINIMUM_CRITERIA = 3

#IFDEF UNICODE
	#define auxInitWindow auxInitWindowW
	#define auxRGBImageLoad auxRGBImageLoadW
	#define auxDIBImageLoad auxDIBImageLoadW
	#define auxDrawStr auxDrawStrW
#else
	#define auxInitWindow auxInitWindowA
	#define auxRGBImageLoad auxRGBImageLoadA
	#define auxDIBImageLoad auxDIBImageLoadA
	#define auxDrawStr auxDrawStrA
#endif

#endif /* GLAUX_H */
