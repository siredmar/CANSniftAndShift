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

    while(1);
    {
        Dio_WriteChannel(DIO_CHANNEL_PA0, STD_HIGH);
        Dio_WriteChannel(DIO_CHANNEL_PA0, STD_LOW);
        Dio_WriteChannel(DIO_CHANNEL_PB0, STD_HIGH);
        Dio_WriteChannel(DIO_CHANNEL_PB0, STD_LOW);
        Dio_WriteChannel(DIO_CHANNEL_PC16, STD_HIGH);
        Dio_WriteChannel(DIO_CHANNEL_PC16, STD_LOW);
    }
}
