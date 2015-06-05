/*
 * main.c
 *
 *  Created on: May 15, 2015
 *      Author: armin
 */


#include "../inc/Std_Types.h"
#include "Port/Port.h"
#include "Dio/Dio.h"

void main(void)
{
    Port_Init();
    Dio_Init();
    uint32 i;

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
