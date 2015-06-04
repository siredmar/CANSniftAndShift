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

Please note: 
The USB Vendor and Product ID, used in this file, is NOT for official use!

Created: 2010-12-28
Changed: 2011-03-12

*****************************************************************************/

// in this file you will make changes for your purposes

#ifndef usbconfig_h__
#define usbconfig_h__

#if defined (__AVR_AT90USB82__) || (__AVR_AT90USB162__) || (__AVR_ATmega8U2__) || (__AVR_ATmega32U2__)
#define MEGA2		// AT90USB82/162, ATMEGAxxU2
#endif
#if defined (__AVR_ATmega16U4__) || (__AVR_ATmega32U4__)
#define MEGA4		// ATMEGAxxU4
#define MEGA4_6
#endif
#if defined (__AVR_AT90USB646__) || (__AVR_AT90USB647__) || (__AVR_AT90USB1286__) || (__AVR_AT90USB1287__)
#define MEGA6		// AT90USB646, -647, -1286, -1287
#define MEGA4_6
#endif

#include <stdint.h>
#include <stdbool.h>

#if (F_CPU==8000000)
#define FREQ_OK
#endif
#if (F_CPU==16000000)
#define FREQ_OK
#endif
#ifndef FREQ_OK
#error "Invalid clock frequency (only 8 or 16MHz)!"
#endif

//-----------------------------------------------------------------------------
// General USB commitments
//-----------------------------------------------------------------------------

#define CDC		// additional code for Communication Device Class

// Vendor Name
// will be a part of the descriptor and can be requested by the host
#define STR_MANUFACTURER	L"Your Vendor Name"

// Product Name
// will be a part of the descriptor and can be requested by the host
#define STR_PRODUCT				L"Your Product Name"

// USB Serial Number (optional)
// will be a part of the descriptor and can be requested by the host
#define USESN 0	// Options: 0= no S/N; 1= S/N inside the flash memory; 2= S/N inside RAM
#if (USESN==1)
#define STR_SERIAL_NUMBER	L"000000"	// your serial number, stored in flash memory
#endif

// Vendor ID
// set your vendor ID here
#define VENDOR_ID		0x0001	// !!! THIS ID IS NOT FOR OFFICIAL USE, FOR YOUR PERSONAL TESTING PURPOSES ONLY !!!

// Product ID
// set your product ID here
#define PRODUCT_ID	0x0003	// !!! THIS ID IS NOT FOR OFFICIAL USE, FOR YOUR PERSONAL TESTING PURPOSES ONLY !!!

// USB device class
#define USBDEVICECLASS	0x02	// class for DCD devices

// power supply
#define SELFPOWERED	0x40
#define BUSPOWERED	0x80
#define	POWERING		BUSPOWERED	// Alternatives: SELFPOWERED or SELFPOWERED | BUSPOWERED

// current consumption
// in mA (milliamperes), uses only even values between 2 and 500
#define MAXPOWER	50

#ifdef MEGA2
// The controllers AT90USB82/162 and ATMEGAxxU2 are not able, to detect a 
// plugged USB connector (presence of VBUS voltage). As alternative an input
// port, which is connected with the 5V line of the USB connector, can be 
// used. A pull down resistor at the input port is recommended.
// Uncomment the following line, if a port pin is used for this purpose.
//#define VBUSDETECT
#define VBUSDIR		DDRC	// Data Direction Register of the used port
#define VBUSPORT	PINC	// used port
#define VBUSPIN		PC4		// used pin (PC4 as example)
#endif

//-----------------------------------------------------------------------------
// Additional CDC Configuration Descriptor Parameters
//-----------------------------------------------------------------------------
#ifdef CDC
#define CDC_DESCRIPTORSIZE 19	// size of additional CDC descriptor
static const uint8_t CDCDescriptorData[CDC_DESCRIPTORSIZE] = {
	0x05, 0x24, 0x00, 0x10, 0x01,
	0x05, 0x24, 0x01, 0x01, 0x01,
	0x04, 0x24, 0x02, 0x06,
	0x05, 0x24, 0x06, 0x00, 0x01
};
#endif

//-----------------------------------------------------------------------------
// Data Set for a USB Control Request
//-----------------------------------------------------------------------------

// Nothing to change here!

struct usb_control_request {
	uint8_t bmRequestType;
	uint8_t bRequest;
	uint16_t wValue;
	uint16_t wIndex;
	uint16_t wLength;
};

//-----------------------------------------------------------------------------
// Interfaces
//-----------------------------------------------------------------------------
// Number of interfaces and interface descriptor topics for each interface

#define NUMINTERFACES 2	// number of supported interfaces (1...3) (use 2 for CDC)
#if (NUMINTERFACES>3)
#error "Only up to 3 interfaces are supported!"
#endif

// Interface classes for each interface
#define INTERFACE_CLASS_0	0x02	// Communication Interface Class
#define INTERFACE_CLASS_1	0x0A	// Data Interface Class
#define INTERFACE_CLASS_2	0xFF	// not used in CDC

// Interface sub classes for each interface
#define INTERFACE_SUBCLASS_0	0x02	// Abstract Control Model
#define INTERFACE_SUBCLASS_1	0x00	// always 0 at CDC
#define INTERFACE_SUBCLASS_2	0xFF	// not used in CDC

// Interface protocols for each interface
#define INTERFACE_PROTOCOL_0	0x01	// AT commands V250, set to 0x00, if no protocol
#define INTERFACE_PROTOCOL_1	0x00	// always 0 at CDC
#define INTERFACE_PROTOCOL_2	0xFF	// not used in CDC

//-----------------------------------------------------------------------------
// Endpoints
//-----------------------------------------------------------------------------

// maximum number of endpoints (don't change!)
#ifdef MEGA4_6
#define MAX_ENDPOINT							6
#else
#define MAX_ENDPOINT							4
#endif

// Constants for endpoint configuration (don't change!)
#define EP_TYPE_DISABLED					0xFF	// endpoint not used
#define EP_TYPE_CONTROL						0x00
#define EP_TYPE_BULK_IN						0x81
#define EP_TYPE_BULK_OUT					0x80
#define EP_TYPE_INTERRUPT_IN			0xC1
#define EP_TYPE_INTERRUPT_OUT			0xC0
#define EP_TYPE_ISOCHRONOUS_IN		0x41
#define EP_TYPE_ISOCHRONOUS_OUT		0x40
#define EP_SINGLE_BUFFER					0x02
#define EP_DOUBLE_BUFFER					0x06

// Endpoint 0
// (for Control Transfers, must be defined always)
#define ENDPOINT0_SIZE						16	// control endpoint
// uncomment the following line to handle user defined control request
// of endpoint 0 in the main program
//#define USERDEFCONTROLS
#ifdef USERDEFCONTROLS
// function prototype to handle user defined control requests.
// Function has to return "true", if request is handled.
// If result is "false", a "stall" will be returned to host.
bool usb_controlrequest(struct usb_control_request *ucr);
#endif

typedef struct {
	uint8_t	ep_type;			// transfer
	uint8_t ep_size;			// buffer size
	uint8_t ep_buffer;		// buffer configuration
	uint8_t ep_interval;	// interval
} ep_config;

#ifdef CDC
  #define STATICENDPOINTS		// endpoint defintions in descriptors and physical (may differ)
#else
//  #define STATICENDPOINTS	// if comment: the following endpoint defintions are valid for descriptors and physical
#endif

// configuration of the endpoints
// EP_TYPE constant, buffer size (8, 16, 32 or 64 byte), single or double buffer

// Hint: Use only two endpoints, if buffer size is 64 byte!

// Additional hints, if more than one USB interfaces are defined:
// - after configuration change (only configuration 1 is possible), 
//   interface 0 will be selected
// - to chose another interface, the control request command SET_INTERFACE
//   with the request type 0x20 has to be executed

// if STATICENDPOINTS is defined, the following agreements are only used in the descriptors.

#if (NUMINTERFACES>1)
static const ep_config EP_CONFIG[NUMINTERFACES][MAX_ENDPOINT] = {{
#else
static const ep_config EP_CONFIG[MAX_ENDPOINT] = {
#endif
  // modify the following lines for your purposes
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_INTERRUPT_IN, 16, EP_SINGLE_BUFFER, 0x40},	// interval for CDC			
	{EP_TYPE_DISABLED, 32, EP_DOUBLE_BUFFER, 0x00},	
	{EP_TYPE_DISABLED, 32, EP_DOUBLE_BUFFER, 0x00}	
	#ifdef MEGA4_6	// the following endpoints are only available on ATMEGAxxU4 and AT90USB64x/128x controllers
	,
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00} 				
	#endif
	#if (NUMINTERFACES>1)
	},{
  // modify the following lines for your purposes
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_BULK_OUT, 32, EP_DOUBLE_BUFFER, 0x00},				
	{EP_TYPE_BULK_IN, 32, EP_DOUBLE_BUFFER, 0x00}				
	#ifdef MEGA4_6	// the following endpoints are only available on ATMEGAxxU4 and AT90USB64x/128x controllers
	,
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00}				
	#endif
	}
	// more interfaces...
	#if (NUMINTERFACES==3)
	,{
  // modify the following lines for your purposes
	{EP_TYPE_BULK_IN, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00}				
	#ifdef MEGA4_6	// the following endpoints are only available on ATMEGAxxU4 and AT90USB64x/128x controllers
	,
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00}				
	#endif
	}
	#endif
	#endif
};

#ifdef STATICENDPOINTS
// If defined, the physical endpoint configuration, valid for each interface, is defined here.
// It should correspond with the upper definitions!
static const ep_config EP_CONFIG_STATIC[MAX_ENDPOINT] = {
  // modify the following lines for your purposes
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_INTERRUPT_IN, 16, EP_SINGLE_BUFFER, 0x40},	// interval for CDC			
	{EP_TYPE_BULK_OUT, 32, EP_DOUBLE_BUFFER, 0x00},				
	{EP_TYPE_BULK_IN, 32, EP_DOUBLE_BUFFER, 0x00}				
	#ifdef MEGA4_6	// the following endpoints are only available on ATMEGAxxU4 and AT90USB64x/128x controllers
	,
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00},				
	{EP_TYPE_DISABLED, 32, EP_SINGLE_BUFFER, 0x00} 				
	#endif
};
#endif

// the following defintions has to correspond with upper endpoint configuration!!!
#define CDC_ACM_ENDPOINT	2	// handshake line state request
#define CDC_RX_ENDPOINT		3	// data receive from host
#define CDC_TX_ENDPOINT		4	// data transmitt to host

//-----------------------------------------------------------------------------
// Interface Routines
//-----------------------------------------------------------------------------
// Function prototypes to handle serial communication
// The routines will be a part of the main program

void cdc_notify_setlinecoding(void);
void cdc_notify_getlinecoding(void);
void cdc_notify_setcontrollinestate(void);

//-----------------------------------------------------------------------------
// Endpoint Interrupt
//-----------------------------------------------------------------------------
// Function prototype to handle endpoint interrupts for incoming data
// The routine will be a part of the main program

void usb_ep(uint8_t endpoint, uint16_t datasize);

//-----------------------------------------------------------------------------
// Functional Purposes
//-----------------------------------------------------------------------------

// "Endpoint Halt" option
// Comment the following to save code memory. But USB conformity is lost.
#define SUPPORT_ENDPOINT_HALT

#endif
