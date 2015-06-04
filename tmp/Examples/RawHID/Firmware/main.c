/*****************************************************************************

Example: Raw Human Interface Device
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

Firmware main routine

Created: 2011-03-14
Changed: 2011-03-14

*****************************************************************************/

#include <avr/io.h>
//#include <avr/pgmspace.h>
#include <avr/interrupt.h>
//#include <stdint.h>
//#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "usb_rawhid_config.h"	// USB configuration
#include "usb_rawhid.h"					// USB functions

#ifdef USERDEFCONTROLS	// see usb_rawhid_config.h
//-----------------------------------------------------------------------------
bool usb_controlrequest(usb_control_request *ucr)
//-----------------------------------------------------------------------------
// Handle user defined control requests
// "ucr" contains the data of the control request
// function has to return "true", if request is handled (otherwise "false")

	// can't be used with Atmel USB HID DLL
	return true;	// means request is handled
}
#endif

//-----------------------------------------------------------------------------
void usb_ep(uint8_t endpoint, uint16_t datasize)
//-----------------------------------------------------------------------------
// handle of endpoint interrupt for incoming data
// "datasize" contains the number od bytes in the USB FIFO buffer
{
	// insert your own program code here (read of USB FIFO buffer UEDATX)

	// example code
	unsigned char buffer[RAWHID_RX_SIZE];	// max. 64 byte
	uint8_t n, i;

	n=usb_rxdata(endpoint,buffer,sizeof(buffer));  // read data into buffer
	if (n && (endpoint==RAWHID_RX_ENDPOINT)) {
		for (i=0; i<n; i++) buffer[i]=127-i;	// modify buffer contents as demo result
		usb_txdata(RAWHID_TX_ENDPOINT,buffer,n);	// answer with modified data
	}
}

//-----------------------------------------------------------------------------
int main(void)
//-----------------------------------------------------------------------------
{	// main routine

	usb_init();		// initialize USB
	sei();				// enable interrupts (strictly necessary!)

	// Example
	DDRD=0xFF;	// port D as output
	if (usb_status()==USB_STATUS_CONNECTED) PORTD|=_BV(PD4);	// turn on LED, if USB connected


	while (1) {		// main loop
	}
}
