#include "Dio.h"

const Dio_ConfigType Dio_InitialConfiguration_s ;



const void *Dio_GetLcfgData(void)
{
   return ((void*) &Dio_InitialConfiguration_s);
}
