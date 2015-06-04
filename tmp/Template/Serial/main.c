/*****************************************************************************

USB-Template: USB Serial Communication Device (CDC)
V1.1.0

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
Homepage: http://products.reworld.eu/index.htm

Supported devices:
- AT90USB82, AT90USB162
- ATMEGA8U2, ATMEGA16U2, ATMEGA32U2
- ATMEGA8U4, ATMEGA16U4, ATMEGA32U4
- AT90USB646, AT90USB647, AT90USB1286, AT90USB1287

Supported modules:
- U2DIL-AT90USB162
- U2DIL-ATMEGA32U2
- U4DIL-ATMEGA32U4
- U6DIL-AT90USB1286

Main routine

Created: 2010-12-28
Changed: 2011-03-12

*****************************************************************************/

#include <avr/io.h>
//#include <avr/pgmspace.h>
#include <avr/interrupt.h>
//#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "usb_serial_config.h"	// USB configuration
#include "usb_serial.h"					// USB functions

// the following routines are called by USB interface. Don't call them yourself!
// You can add own code for your application.

#ifdef USERDEFCONTROLS	// see usbconfig.h
//-----------------------------------------------------------------------------
bool usb_controlrequest(struct usb_control_request *ucr)
//-----------------------------------------------------------------------------
// Handle user defined control requests
// "ucr" contains the data of the control request
// function has to return "true", if request is handled (otherwise "false")
{
	// insert your own program code here
	return true;	// means request is handled
}
#endif

//-----------------------------------------------------------------------------
void cdc_notify_getlinecoding(void)
//-----------------------------------------------------------------------------
// This routine is called, when baudrate and transmission parameters (see
// cdc_linecoding in usb_serial.h) are requested by the host.
// Parameters of this variable can be modified in this routine, before they
// will be sent to host.
{
	// your code here
}

//-----------------------------------------------------------------------------
void cdc_notify_setlinecoding(void)
//-----------------------------------------------------------------------------
// This routine is called, when baudrate and transmission parameters (see
// cdc_linecoding in usb_serial.h) are set by the host.
// New settings are available in this variable, when this routine is called.
{
	// your code here
}

//-----------------------------------------------------------------------------
void cdc_notify_setcontrollinestate(void)
//-----------------------------------------------------------------------------
// This routine is called, when host is changing handshake output lines RTS and 
// DTR.
// New settings are available in the global variable cdc_rtsdtr (see 
// usb_serial.h).
{
	// your code here
}

//-----------------------------------------------------------------------------
void usb_ep(uint8_t endpoint, uint16_t datasize)
//-----------------------------------------------------------------------------
// handle of endpoint interrupt for incoming data
// "datasize" contains the number od bytes in the USB FIFO buffer
{
	// insert your own program code here (read of USB FIFO buffer UEDATX)
}

//-----------------------------------------------------------------------------
int main(void)
//-----------------------------------------------------------------------------
{	// main routine
	usb_init();		// initialize USB
	sei();				// enable interrupts (strictly necessary!)

	while (1) {		// main loop
	}
}
