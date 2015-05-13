#include "std_types.h"

#ifndef PORT_H
#define PORT_H

#define PACKAGE_TQFP64
#define PACKAGE_TQFP100
#define PACKAGE_LQFP144



typedef enum
{
   PORT_PORT_A = (0U),
   PORT_PORT_B,
   PORT_PORT_C,
   PORT_PORT_D,
   PORT_NUMBER_OF_PORTS
}Port_PortType;


typedef struct
{
}Port_ConfigType;


typedef struct
{
   uint8*       Port_PortRegister_pui8;
   uint8*       Port_DirectionRegister_pui8;
   uint8*       Port_InputRgister_pui8;
} Port_RegisterAddresstype;


#endif

