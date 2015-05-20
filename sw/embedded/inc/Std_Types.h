
#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"

#define E_OK		 (0x00U)
#define E_NOT_OK	 (0x01U)
#define STD_ACTIVE   (0x01U)     /**<\brief Logical state active */
#define STD_IDLE     (0x00U)     /**<\brief Logical state idle */
#define STD_ON       (0x01U)     /**<\brief Standard ON type */
#define STD_OFF      (0x00U)     /**<\brief Standard OFF type */
#define STD_ENABLE   (0x01U)     /**<\brief Standard ENABLE type */
#define STD_DISABLE  (0x00U)     /**<\brief Standard DISABLE type */

typedef uint8 Std_VersionInfoType;

#define NULL_PTR ((void *)0)
#endif /* STD_TYPES_H */


