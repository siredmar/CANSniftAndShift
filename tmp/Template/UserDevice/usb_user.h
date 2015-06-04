/*****************************************************************************

USB-Template: User defined USB device
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

USB Header File

Created: 2010-01-07
Changed: 2011-03-12

*****************************************************************************/

// Usually no changes are necessary in this file!

#ifndef usb_h__
#define usb_h__

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "usb_user_config.h"

//-----------------------------------------------------------------------------
// USB Strings
//-----------------------------------------------------------------------------

struct usb_string_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	int16_t wString[];
};

static struct usb_string_descriptor PROGMEM string0 = {
	4,
	3,
	{0x0409}
};

static struct usb_string_descriptor PROGMEM string1 = {
	sizeof(STR_MANUFACTURER),
	3,
	STR_MANUFACTURER
};

static struct usb_string_descriptor PROGMEM string2 = {
	sizeof(STR_PRODUCT),
	3,
	STR_PRODUCT
};

#if (USESN==1)
static struct usb_string_descriptor PROGMEM string3 = {
	sizeof(STR_SERIAL_NUMBER),
	3,
	STR_SERIAL_NUMBER
};
#endif

#if (USESN==2)
// Your USB serial numebr in RAM. Must be set into RAMSN before calling usb_init!
// Descriptor size, descriptor ID and conversion into widechars wil be done automatically.

#define RAMSNLEN	16	// maximum length of the serial number

struct usb_string_descriptor_ram {
	uint8_t bLength;
	uint8_t bDescriptorType;
	int16_t wString[RAMSNLEN];
};

char RAMSN[RAMSNLEN];	// save the S/N as string here (e.g. read from EEPROM)
#endif

//-----------------------------------------------------------------------------
// Endpoints
//-----------------------------------------------------------------------------

// buffer sizes of an endpoint
// Hint: For 64 byte and more only two endpoints must be activated!
#define EP_SIZE(s)	((s) == 512 ? 0x60 :	\
										((s) == 256 ? 0x50 :	\
										((s) == 128 ? 0x40 :	\
										((s) ==  64 ? 0x30 :	\
										((s) ==  32 ? 0x20 :	\
										((s) ==  16 ? 0x10 :	\
			             								0x00))))))

// endpoint attributes
#define EP_TRANSFER(t) 	((t) == EP_TYPE_ISOCHRONOUS_IN ? 1 : \
												((t) == EP_TYPE_ISOCHRONOUS_OUT ? 1 : \
												((t) == EP_TYPE_BULK_IN ? 2 : \
												((t) == EP_TYPE_BULK_OUT ? 2 : \
												                           3))))

//-----------------------------------------------------------------------------
// Device Descriptor
//-----------------------------------------------------------------------------

#define LSB(n) (n & 255)
#define MSB(n) ((n >> 8) & 255)

static uint8_t PROGMEM device_descriptor[] = {
	18,																// bLength
	1,																// bDescriptorType
	0x00, 0x02,												// bcdUSB
	USBDEVICECLASS,										// bDeviceClass
	0,																// bDeviceSubClass
	0,																// bDeviceProtocol
	ENDPOINT0_SIZE,										// bMaxPacketSize0
	LSB(VENDOR_ID), MSB(VENDOR_ID),		// idVendor
	LSB(PRODUCT_ID), MSB(PRODUCT_ID),	// idProduct
	0x00, 0x01,												// bcdDevice
	1,																// iManufacturer
	2,																// iProduct
	3,																// iSerialNumber
	1																	// bNumConfigurations
};

//-----------------------------------------------------------------------------
// Standard Commands for Control Transfers
//-----------------------------------------------------------------------------

#define GET_STATUS					0
#define CLEAR_FEATURE				1
#define SET_FEATURE					3
#define SET_ADDRESS					5
#define GET_DESCRIPTOR			6
#define GET_CONFIGURATION		8
#define SET_CONFIGURATION		9
#define GET_INTERFACE				10
#define SET_INTERFACE				11

//=============================================================================
// USB Functions
//=============================================================================

//-----------------------------------------------------------------------------
// USB Initializing
//-----------------------------------------------------------------------------
// Has to be called one time before any USB actions.
// Interrupts has to be enabled (call of sei macro)

void usb_init(void);

//-----------------------------------------------------------------------------
// USB State
//-----------------------------------------------------------------------------
// Request of the USB state.
// State is determined with function call.
// Hint: For AT90USB82/162 and ATMEGAxxU2 without VBUSDETECT option, state will 
// not change, if USB connector will be unplugged!
// Possible return values:
#define USB_STATUS_DISCONNECTED	0	// not connected (for self powered devices)
#define USB_STATUS_CONNECTED		1	// connected (for AT90USB82/162 and ATMEGAxxU2 only with option VBUSDETECT)
#define USB_STATUS_ENUMERATED		2	// USB address assigned (USB connection established)
#define USB_STATUS_CONFIGURED		3	// a valid configuration were selected (USB device usable)

uint8_t usb_status(void);

//-----------------------------------------------------------------------------
// USB Configuration
//-----------------------------------------------------------------------------
// Returns the configuration number, set by the host
// If the value is 0, no configuration were selected by the host. No endpoint
// (except ep0 for control transfers) can be used in this case.

uint8_t usb_configuration(void);

//-----------------------------------------------------------------------------
// USB Interface
//-----------------------------------------------------------------------------
// Returns the number of the interface, selected by the host.

uint8_t usb_interface(void);

//-----------------------------------------------------------------------------
// Data Check (Host to Device)
//-----------------------------------------------------------------------------
// This function returns the number of data bytes, contained in the FIFO
// input buffer, for the specified endpoint.

#ifdef MEGA4_6
uint16_t usb_rxavail(uint8_t endpoint);
#else
uint8_t usb_rxavail(uint8_t endpoint);
#endif

//-----------------------------------------------------------------------------
// Data Receive (Host to Device)
//-----------------------------------------------------------------------------
// "endpoint" has to specify an "OUT" endpoint (1..4 or 1..6)!
// Data will be stored into "buffer".
// Returns number of bytes, transfered into buffer
#ifdef MEGA4_6
uint16_t usb_rxdata(uint8_t endpoint, uint8_t *buffer, uint16_t maxdatasize);
#else
uint8_t usb_rxdata(uint8_t endpoint, uint8_t *buffer, uint8_t maxdatasize);
#endif

//-----------------------------------------------------------------------------
// Data Return (Device to Host), Control Transfer
//-----------------------------------------------------------------------------
// Data return for control transfers (endpoint 0)
// "datasize" not greater than size of FIFO buffer (no check!)
// Result is always "true", if no connection to host.
// When a connection is established, result is "false", if data block,
// stored before, is not read from the FIFO buffer.

bool usb_txdata_control(uint8_t *buffer, uint8_t datasize);

//-----------------------------------------------------------------------------
// Data Return (Device to Host)
//-----------------------------------------------------------------------------
// "endpoint" must specify a valid endpoint number (1..4 or 1..6)!
// "datasize" not greater than size of FIFO buffer (no check!)
// Result is always "true", if no connection to host.
// When a connection is established, result is "false", if data block,
// stored before, is not read from the FIFO buffer.

#ifdef MEGA4_6
bool usb_txdata(uint8_t endpoint, uint8_t *buffer, uint16_t datasize);
#else
bool usb_txdata(uint8_t endpoint, uint8_t *buffer, uint8_t datasize);
#endif

//-----------------------------------------------------------------------------
// Free FIFO Buffer
//-----------------------------------------------------------------------------
// Free the FIFO buffer for one endpoint
// Data contained in the buffer will be lost.
// Endpoint usable for new data transfer.
// It is not necessary, to call this routine after read of buffer data with 
// read routine. Routine can be used to clear buffer before writing new data.

void usb_freebuffer(uint8_t endpoint);

#endif
