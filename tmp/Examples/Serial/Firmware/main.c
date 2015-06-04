/*****************************************************************************

Example: USB Serial Communication Device (CDC)
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
- AVR-Stick 162
- AVR-Stick U2

Created: 2010-12-28
Changed: 2011-03-14

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

	// example code
	char r[32];	// use endpoint buffer size (= maximum length of one transfered string)
	char t[32];
	char s[8];
	uint8_t n;

	if (endpoint==CDC_RX_ENDPOINT) {
		// serial data received
		n=usb_rxdata(endpoint,(unsigned char *)r,sizeof(r));  // read data into buffer
		// parse command and prepare response
		t[0]=0;	// clear response string buffer
		switch (r[0]) {	// 1st byte is command
			case '?':	// help command
			case 'h':
				strcpy(t,"Valid commands: ? h i c p");
				break;
			case 'i':	// info command
				strcpy(t,"UxDIL CDC Demo V1.0");
				break;
			case 'c':	// copyright command
				strcpy(t,"(c) 2011 Reusch Elektronik");
				break;
			case 'p':	// parameter settings command
				strcpy(t,"ppp");
				ltoa(cdc_linecoding.dwDTERate,t,10);
				strcat(t,":");
				itoa(cdc_linecoding.bDataBits,s,10);
				strcat(t,s);
				switch (cdc_linecoding.bParityType) {
					case 0: strcat(t,"N");
						break;
					case 1: strcat(t,"O");
						break;
					case 2: strcat(t,"E");
						break;
					case 3: strcat(t,"M");
						break;
					case 4: strcat(t,"S");
						break;
					default: strcat(t,"?");
				};
				switch (cdc_linecoding.bCharFormat) {
					case 0: strcat(t,"1");
						break;
					case 1: strcat(t,"1.5");
						break;
					case 2: strcat(t,"2");
						break;
					default: strcat(t,"?");
				};
				strcat(t," RTS=");
				itoa(cdc_rtsdtr>>1,s,10);
				strcat(t,s);
				strcat(t," DTR=");
				itoa(cdc_rtsdtr&0x01,s,10);
				strcat(t,s);
				break;
				default: strcpy(t,"invalid command");
		}
		strcat(t,"\r\n");
		// response
		usb_txdata(CDC_TX_ENDPOINT,(unsigned char *)t,strlen(t));	// return answer to host
	}
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
