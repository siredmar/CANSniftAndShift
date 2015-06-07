/**
 * \file
 *
 * \brief User board definition template
 *
 */

 /* This file is intended to contain definitions and configuration details for
 * features and devices that are available on the board, e.g., frequency and
 * startup time for an external crystal, external memory devices, LED and USART
 * pins.
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef USER_BOARD_H
#define USER_BOARD_H

#include <conf_board.h>

#define BOARD_OSC0_HZ           16000000
#define BOARD_OSC0_STARTUP_US   1100
#define BOARD_OSC0_IS_XTAL      true

// External oscillator settings.
// Uncomment and set correct values if external oscillator is used.

// External oscillator frequency


// External oscillator type.
//!< External clock signal
//#define BOARD_XOSC_TYPE        XOSC_TYPE_EXTERNAL
////!< 32.768 kHz resonator on TOSC
////#define BOARD_XOSC_TYPE        XOSC_TYPE_32KHZ
////!< 0.4 to 16 MHz resonator on XTALS
////#define BOARD_OSC0_TYPE        OSC0_TYPE_XTAL
//
//// External oscillator startup time
//#define BOARD_OSC0_STARTUP_US  500
//
//#define     OSC0_GAIN_VALUE   AVR32_SCIF_OSCCTRL0_GAIN_G3
//#define     OSC0_MODE_VALUE   OSC_MODE_XTAL
//#define     OSC0_STARTUP_TIMEOUT   640
//#define     OSC0_STARTUP_VALUE   OSC_STARTUP_512

#endif // USER_BOARD_H
