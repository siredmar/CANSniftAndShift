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
#include "delay.h"


//#include <avr32/io.h>
#define PRESCALER (8)
#define PRESCALER_2 (1)
#define MS (250)

#define BLINK()            { \
        Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);\
        delay_ms(40);\
        Dio_WriteChannel(DIO_CHANNEL_PA19, STD_LOW);\
        delay_ms(40); \
}

//void delay_fixed(void)
//{
//    uint32 cnt;
//    uint32 ms_step;
//
//
//#if CONFIG_SYSCLK_SOURCE == SYSCLK_SRC_OSC0
//    ms_step = 16000000UL / PRESCALER;
//#elif CONFIG_SYSCLK_SOURCE == SYSCLK_SRC_PLL0
//    ms_step = 48000000UL / PRESCALER;
//#elif CONFIG_SYSCLK_SOURCE == SYSCLK_SRC_RCSYS
//    ms_step = 115200 / PRESCALER;
//#endif
//    for(cnt = 0; cnt < ms_step; cnt++)
//    {
//        __asm("nop");
//    }
//}
//
//void delay_ms(uint32 ms)
//{
//    uint32 cnt;
//    uint32 ms_step;
//
//#if CONFIG_SYSCLK_SOURCE == SYSCLK_SRC_OSC0
//    ms_step = ms * ((BOARD_OSC0_HZ / 1000) / PRESCALER);
//#elif CONFIG_SYSCLK_SOURCE == SYSCLK_SRC_PLL0
//    ms_step = ms * ((((BOARD_OSC0_HZ * CONFIG_PLL0_MUL) / CONFIG_PLL0_DIV) / 1000) / PRESCALER);
//#elif CONFIG_SYSCLK_SOURCE == SYSCLK_SRC_RCSYS
//    ms_step = ms * ((115200 / 1000) / PRESCALER);
//#endif
//
//    for(cnt = 0; cnt < ms_step; cnt++)
//    {
//        __asm("nop");
//    }
//}



void main(void)
{
    uint8 buf[255];
    uint8 cnt = 0;
    Asf_Init();
    Port_Init();
    Dio_Init();

//    while(1){
//        if(sysclk_get_cpu_hz() == 48000000UL / PRESCALER_2)
//        {
//
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//            delay_ms(MS);
//            BLINK();
//
//            //            delay_fixed();
//            Dio_WriteChannel(DIO_CHANNEL_PA19, STD_LOW);
//            //            delay_fixed();
//            delay_ms(MS * 5);
//        }
//        else
//        {
//            if(sysclk_get_cpu_hz() == 16000000UL / PRESCALER_2)
//            {
//
//                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                delay_ms(MS);
//                BLINK();
//                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                delay_ms(MS);
//                BLINK();
//                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                delay_ms(MS);
//                BLINK();
//                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                delay_ms(MS);
//                BLINK();
//                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                delay_ms(MS);
//                BLINK();
//                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                delay_ms(MS);
//                BLINK();
//                //            delay_fixed();
//                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_LOW);
//                //            delay_fixed();
//                delay_ms(MS);
//            }
//            else
//            {
//                if(sysclk_get_cpu_hz() == 115200UL / PRESCALER_2)
//                {
//
//                    Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                    delay_ms(MS);
//                    BLINK();
//                    Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                    delay_ms(MS);
//                    BLINK();
//                    //            delay_fixed();
//                    Dio_WriteChannel(DIO_CHANNEL_PA19, STD_LOW);
//                    //            delay_fixed();
//                    delay_ms(MS);
//                }
//                else
//                {
//                    Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
//                    delay_ms(25);
//                    //            delay_fixed();
//                    Dio_WriteChannel(DIO_CHANNEL_PA19, STD_LOW);
//                    //            delay_fixed();
//                    delay_ms(25);
//                }
//            }
//        }
//    }

        while(1)
        {
//            if(Dio_ReadChannel(DIO_CHANNEL_PA16) == STD_HIGH)
            {
                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_HIGH);
                delay_s(1u);
                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_LOW);
                delay_s(1u);
            }
            sprintf(buf, "cnt: %d\r\n", cnt++);
            usart_write_line(USART_SERIAL, (const char*)buf);

            //            else
//            {
//                Dio_WriteChannel(DIO_CHANNEL_PA19, STD_LOW);
//            }
        }
}
