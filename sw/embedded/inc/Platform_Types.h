#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


#define FALSE 			(0U)
#define TRUE 			(1U)

#define MASK_8BIT_UI8		    (0xFFU)
#define MASK_8BIT_HI_UI8	    (0xF0U)
#define MASK_8BIT_LO_UI8	    (0x0FU)
#define MASK_16BIT_LO_UI16	    (0x00FFU)
#define MASK_16BIT_HI_UI16	    (0xFF00U)
#define MASK_32BIT_1BYTE_UI32	(0x000000FFU)
#define MASK_32BIT_2BYTE_UI32	(0x0000FF00U)
#define MASK_32BIT_3BYTE_UI32	(0x00FF0000U)
#define MASK_32BIT_4BYTE_UI32	(0xFF000000U)

typedef unsigned char      boolean;
typedef signed char        sint8;
typedef unsigned char      uint8;
typedef signed short       sint16;
typedef unsigned short     uint16;
typedef signed long        sint32;
typedef unsigned long      uint32;
typedef signed long long   sint64;
typedef unsigned long long uint64;
typedef float              float32;
typedef double             float64;



#endif /* PLATFORM_TYPES_H */

