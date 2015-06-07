/*
 * asf.c
 *
 *  Created on: Jun 6, 2015
 *      Author: armin
 */

#include "asf.h"

void Usb_init(void)
{
    udc_start();
}

static usart_serial_options_t usart_options = {
   .baudrate = USART_SERIAL_BAUDRATE,
   .charlength = USART_SERIAL_CHAR_LENGTH,
   .paritytype = USART_SERIAL_PARITY,
   .stopbits = USART_SERIAL_STOP_BIT
};

void Asf_Init(void)
{
    /* Initialize PLL */
    sysclk_init();
    irq_initialize_vectors();
    cpu_irq_enable();
    sleepmgr_init(); // Optional

    Usb_init();

    usart_serial_init(USART_SERIAL, &usart_options);
}


