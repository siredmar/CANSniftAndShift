/*
 * main.c
 *
 *  Created on: May 15, 2015
 *      Author: armin
 */


#include "Std_Types.h"
#include "Port.h"
#include "Dio.h"
#include "preprocessor.h"
#include "asf.h"
//#include <avr32/io.h>

void main(void)
{
    Port_Init();
    Dio_Init();


    while(1)
    {
        if(Dio_ReadChannel(DIO_CHANNEL_PA16) == STD_HIGH)
        {
            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
        }
        else
        {
            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_LOW);
        }
    }
}
