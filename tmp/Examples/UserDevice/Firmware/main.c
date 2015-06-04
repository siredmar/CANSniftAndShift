/*****************************************************************************

Example: User defined USB device
V1.0.0

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

Created: 2011-05-30
Changed: 2011-05-30

*****************************************************************************/

/*
This example demonstrates, how to create a user defined USB device.
Special O/S drivers are required, that the host can communicate with a device
like this. The "LibUSB-Win32" driver library can be used for this purpose.
This example uses a control transfer to request a version string and two additional
bulk transfer endpoints for data receive and transmission. For the demo,
simply a string (max. length of 32 chars) is converted into capital letters.
*/

#include <avr/io.h>
//#include <avr/pgmspace.h>
#include <avr/interrupt.h>
//#include <stdint.h>
//#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "usb_user_config.h"	// USB configuration
#include "usb_user.h"				// USB functions

#ifdef USERDEFCONTROLS	// see usbconfig.h
//-----------------------------------------------------------------------------
bool usb_controlrequest(struct usb_control_request *ucr)
//-----------------------------------------------------------------------------
// Handle user defined control requests
// "ucr" contains the data of the control request
// function has to return "true", if request is handled (otherwise "false")
{
  #define USER_REQUESTTYPE  	0xC3  // a user defined request type (means, no standard request)
  #define USER_REQUESTVERSION 0x01  // a self defined request: get version info
	bool Result;
	const char VersionInfo[ENDPOINT0_SIZE] = {"Version 1.0"};

	Result=false;
	if (ucr->bmRequestType==USER_REQUESTTYPE) {
		// handle the requests (only one defined in this example)
		switch (ucr->bRequest) {
			case USER_REQUESTVERSION:	// request for version info)
				usb_txdata_control((uint8_t *)VersionInfo,sizeof(VersionInfo));
				Result=true;
				break; 
		}
	}
	return Result;	// true means, request is handled
}
#endif

//-----------------------------------------------------------------------------
void usb_ep(uint8_t endpoint, uint16_t datasize)
//-----------------------------------------------------------------------------
// handle of endpoint interrupt for incoming data
// "datasize" contains the number of bytes in the USB FIFO buffer
{
	#define RXENDPOINT	0x01	// endpoint, used for data transfer host->device (defined in "usb_user_config.h")
	#define	TXENDPOINT	0x82	// endpoint, used for data transfer device->host
	#define BUFSIZE 32	// USB FIFO buffer size (see usb_user_config.h at "endpoints")
	
	char buf[BUFSIZE];	// buffer for received data from host and data to transmit to host
	uint8_t n;

	if (endpoint==RXENDPOINT) {	// data from host by our defined data receive endpoint
		n=usb_rxdata(endpoint,(uint8_t *)buf,sizeof(buf));  // read data into buffer
		if (n) {	// data read into local buffer
			buf[BUFSIZE-1]=0;	// for security: terminate string
			strupr(buf);	// upper case string
			// response to host with converted string
			usb_txdata(TXENDPOINT,(uint8_t *)buf,sizeof(buf));	// transfer data to host
		}
	}
}

//-----------------------------------------------------------------------------
int main(void)
//-----------------------------------------------------------------------------
{	// main routine

	usb_init();		// initialize USB
	sei();				// enable interrupts (strictly necessary!)

	while (1) {		// main loop
		// all happens within the two callback routines "usb_controlrequest" and "usb_ep"
	}
}
