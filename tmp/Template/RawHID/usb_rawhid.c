/*****************************************************************************

USB-Template: Raw Human Interface Device
V1.1.1

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

USB Function Implementation

Created: 2010-05-12
Changed: 2011-08-02

*****************************************************************************/

// Usually no changes are necessary in this file!

#include <stdlib.h>
#include <stdbool.h>
#include "usb_rawhid_config.h"
#include "usb_rawhid.h"

//-----------------------------------------------------------------------------
// Internal Variables
//-----------------------------------------------------------------------------

// USB State
static volatile uint8_t usb_stat = USB_STATUS_DISCONNECTED;

// USB configuration, selected by host (0=none)
// In this version only 0 or 1 is possible (support of only one configuration)
static volatile uint8_t usb_conf = 0;

// USB interface, selected by host
// In this version the value 0 and optional more cfgs are possible (see usbconfig.h)
#if (NUMINTERFACES>1)
static volatile uint8_t usb_if = 0xFF;	// 0xFF: no interface selected
#endif

//-----------------------------------------------------------------------------
// Descriptors
//-----------------------------------------------------------------------------

// configuration descriptor
typedef struct {
	uint8_t   bLength;
	uint8_t   bDescriptorType;
	uint16_t  wTotalLength;
	uint8_t   bNumInterfaces;
	uint8_t   bConfigurationValue;
	uint8_t   iConfiguration;
	uint8_t   bmAttributes;
	uint8_t   bMaxPower;
} cfg_desc;

// interface descriptor
typedef struct {
	uint8_t   bLength;
	uint8_t   bDescriptorType;
	uint8_t   bInterfaceNumber;
	uint8_t   bAlternateSetting;
	uint8_t   bNumEndpoints;
	uint8_t   bInterfaceClass;
	uint8_t   bInterfaceSubClass;
	uint8_t   bInterfaceProtocol;
	uint8_t   iInterface;
} if_desc;

// HID class descriptor
typedef struct {
	uint8_t   bLength;
	uint8_t   bDescriptorType;
	uint16_t	bcdHID;
	uint8_t		bCountryCode;
	uint8_t		bNumDescriptors;
	uint8_t		bReportDescriptorType;
	uint16_t	wDescriptorLength;
} hid_desc;

// endpoint descriptor
typedef struct {
	uint8_t   bLength;
	uint8_t   bDescriptorType;
	uint8_t   bEndpointAddress;
	uint8_t   bmAttributes;
	uint16_t  wMaxPacketSize;
	uint8_t   bInterval;
} ep_desc;

//-----------------------------------------------------------------------------
// USB Initializing
//-----------------------------------------------------------------------------

#if defined (__AVR_AT90USB1286__) || (__AVR_AT90USB1287__)
#define AT128X
#endif

void usb_init(void)
{
	#ifdef MEGA4
	UHWCON = _BV(UVREGE);							// enable PAD regulator
	#endif
	#ifdef MEGA6
	UHWCON = _BV(UIMOD)|_BV(UVREGE);	// set device mode, enable PAD regulator
	#endif
  USBCON = _BV(USBE) | _BV(FRZCLK);	// enable USB
	#if (F_CPU==16000000)
	// 16MHz
	#ifdef MEGA2
  PLLCSR = _BV(PLLE) | _BV(PLLP0);	// config PLL, 16 MHz xtal
	#endif
	#ifdef MEGA4
  PLLCSR = _BV(PINDIV) | _BV(PLLE);	// config PLL, 16 MHz xtal
	#endif

	#ifdef MEGA6
	#ifdef AT128X
  PLLCSR = _BV(PLLP2) | _BV(PLLP0) | _BV(PLLE);	// config PLL, 16 MHz xtal (AT90USB128x)
	#else
  PLLCSR = _BV(PLLP2) | _BV(PLLP1) | _BV(PLLE);	// config PLL, 16 MHz xtal (AT90USB64x and ATMEGA32U6)
	#endif
	#endif

	#else

	// 8MHz
	#ifdef MEGA6
  PLLCSR = _BV(PLLP1) | _BV(PLLP0) |_BV(PLLE);	// config PLL, 8 MHz xtal
	#else
  PLLCSR = _BV(PLLE);								// config PLL, 8 MHz xtal
	#endif

	#endif

  while (!(PLLCSR & _BV(PLOCK))) ;	// wait for PLL lock
	#ifdef MEGA4_6
  USBCON = _BV(USBE)|_BV(OTGPADE);	// start USB clock
	#else
  USBCON = _BV(USBE);								// start USB clock
	#endif
  UDCON = 0;												// enable attach resistor
	usb_conf = 0;
	#if (NUMINTERFACES>1)
	usb_if = 0xFF;
	#endif
	#ifdef MEGA2
	// port for VBUS detection
	VBUSDIR &= ~_BV(VBUSPIN);					// port as input
	#endif
  UDIEN = _BV(EORSTE);							// enable "end of reset" interrupt
}

//-----------------------------------------------------------------------------
// Initializing Endpoints
//-----------------------------------------------------------------------------

#if (NUMINTERFACES>1)
void usb_endpoints(uint8_t ifnumber)	// with interface number
#else
void usb_endpoints(void)
#endif
{
	#if (NUMINTERFACES>1)
	#define EPC	EP_CONFIG[ifnumber][i]
	#define IN_TRANSFER	EP_CONFIG[ifnumber][i].ep_type & 0x01
	#else
	#define EPC	EP_CONFIG[i]
	#define IN_TRANSFER	EP_CONFIG[i].ep_type & 0x01
	#endif
	uint8_t i;

	for (i=0; i<MAX_ENDPOINT; i++) {
		if (EPC.ep_type!=EP_TYPE_DISABLED) {
			UENUM = i+1;											// select endpoint
			UECONX = _BV(EPEN); 							// enable endpoint
			UECFG0X = EPC.ep_type;						// transfer type and direction
			UECFG1X = EP_SIZE(EPC.ep_size)|
			          (EPC.ep_buffer);				// bufer size and bank
			if (IN_TRANSFER) UEIENX = 0;			// no interrupts handling for IN endpoints
			else UEIENX = _BV(RXOUTE);				// interrupt handling for incoming data (OUT endpoint)
		}
	}
	#ifdef MEGA4_6
	UERST = 0x7E;	// endpoint FIFO reset for endpoint 1, 2, 3, 4, 5 and 6
	#else
	UERST = 0x1E;	// endpoint FIFO reset for endpoint 1, 2, 3 and 4
	#endif
	UERST = 0;
}

//-----------------------------------------------------------------------------
// USB State
//-----------------------------------------------------------------------------

uint8_t usb_status(void)
{
	uint8_t r;

	r = USB_STATUS_DISCONNECTED;
	#ifdef MEGA4_6
	if (USBSTA & _BV(VBUS)) {
		r = USB_STATUS_CONNECTED;
		if (UDADDR & _BV(ADDEN)) {
			r = USB_STATUS_ENUMERATED;
			if (usb_conf) r = USB_STATUS_CONFIGURED;
		}
	}
	#endif
	#ifdef MEGA2
	#ifdef VBUSDETECT
	if (VBUSPORT & _BV(VBUSPIN)) {
		r = USB_STATUS_CONNECTED;
	#endif
		if (UDADDR & _BV(ADDEN)) {
			r = USB_STATUS_ENUMERATED;
			if (usb_conf) r = USB_STATUS_CONFIGURED;
		}
	#ifdef VBUSDETECT
	}
	#endif
	#endif
	return r;
}

//-----------------------------------------------------------------------------
// USB Configuration
//-----------------------------------------------------------------------------

uint8_t usb_configuration(void)
{
	return usb_conf;
}

//-----------------------------------------------------------------------------
// USB Interface
//-----------------------------------------------------------------------------

#if (NUMINTERFACES>1)
uint8_t usb_interface(void)
{
	return usb_if;
}
#endif

//-----------------------------------------------------------------------------
// Internal used USB routines and macros
//-----------------------------------------------------------------------------

#define USB_SEND_IN		UEINTX = ~(1<<TXINI)

#define STALL					UECONX = _BV(STALLRQ) | _BV(EPEN)

static inline void usb_wait_in_ready(void)
{
	while (!(UEINTX & _BV(TXINI)));
}

void usb_wait_in(void)
// wait for host, until it's ready to receive IN package
{
	uint8_t i;
	do {
		i = UEINTX;
	} while (!(i & (_BV(TXINI)|_BV(RXOUTI))));
}

static inline void usb_wait_receive_out(void)
{
	while (!(UEINTX & _BV(RXOUTI)));
}

void usb_desc_out(bool isRAM, uint8_t *pgmaddr, uint8_t size, uint16_t maxsize)
// return descriptor over endpoint 0 to host from flash memory or RAM
{	
	uint8_t i, len, n;
	uint8_t *addr;

	addr=pgmaddr;
	len=size;
	if (len>maxsize) len=maxsize;
	do {
		usb_wait_in();
		if (i & _BV(RXOUTI)) return;	// cancel
		// send IN package
		n = (len < ENDPOINT0_SIZE) ? len : ENDPOINT0_SIZE;
		for (i = n; i; i--) 
			UEDATX = isRAM ? *addr++ : pgm_read_byte(addr++);
		len -= n;
		USB_SEND_IN;
	} while (len || n == ENDPOINT0_SIZE);
}

//-----------------------------------------------------------------------------
// Free FIFO Buffer
//-----------------------------------------------------------------------------

void usb_freebuffer(uint8_t endpoint)
{
	UENUM = endpoint;				// select endpoint
	UERST = _BV(endpoint);	// endpoint FIFO reset
	UERST = 0;
}

//-----------------------------------------------------------------------------
// Data Check (Host to Device)
//-----------------------------------------------------------------------------

#ifdef MEGA4_6
uint16_t usb_rxavail(uint8_t endpoint)
#else
uint8_t usb_rxavail(uint8_t endpoint)
#endif
{
	UENUM = endpoint;	// select endpoint
	#ifdef MEGA4_6
	return ((uint16_t)(UEBCHX)<<8)+UEBCLX;
	#else
	return UEBCLX;
	#endif
}

//-----------------------------------------------------------------------------
// Data Receive (Host to Device)
//-----------------------------------------------------------------------------

#ifdef MEGA4_6
uint16_t usb_rxdata(uint8_t endpoint, uint8_t *buffer, uint16_t maxdatasize)
#else
uint8_t usb_rxdata(uint8_t endpoint, uint8_t *buffer, uint8_t maxdatasize)
#endif
{
	#ifdef MEGA4_6
	uint16_t r, i;
	#else
	uint8_t r, i;
	#endif

	UENUM = endpoint;	// select endpoint
	#ifdef MEGA4_6
	r = ((uint16_t)(UEBCHX)<<8)+UEBCLX;
	#else
	r = UEBCLX;
	#endif
	if (r>maxdatasize) r = maxdatasize;
	if (r) {	// data available in input endpoint
		for (i=0; i<r; i++) buffer[i]=UEDATX;
		#ifdef MEGA4_6
		if ((((uint16_t)(UEBCHX)<<8)+UEBCLX)==0) {	// buffer is empty
		#else
		if (UEBCLX==0) {	// buffer is empty
		#endif
			UERST = _BV(endpoint);	// endpoint FIFO reset
 			UERST = 0;
		}
	}
	return r;
}

//-----------------------------------------------------------------------------
// Data Return (Device to Host), Control Transfers
//-----------------------------------------------------------------------------

bool usb_txdata_control(uint8_t *buffer, uint8_t datasize)
{
	uint8_t i;

	if (datasize) {
		UENUM = 0;
		usb_wait_in_ready();
		#ifdef MEGA4_6
		if ((((uint16_t)(UEBCHX)<<8)+UEBCLX)==0) {	// buffer is empty
		#else
		if (UEBCLX==0) {	// buffer is empty
		#endif
			for (i=0; i<datasize; i++) UEDATX = buffer[i];
			UEINTX&=~_BV(TXINI);	// necessary (in this order)	(changed V1.1.1)
			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------------------------
// Data Return (Device to Host)
//-----------------------------------------------------------------------------
// This routine has to be used for all transfer types, except control transfers

#ifdef MEGA4_6
bool usb_txdata(uint8_t endpoint, uint8_t *buffer, uint16_t datasize)
#else
bool usb_txdata(uint8_t endpoint, uint8_t *buffer, uint8_t datasize)
#endif
{
	#ifdef MEGA4_6
	uint16_t i;
	#else
	uint8_t i;
	#endif

	if (datasize) {
		UENUM = endpoint;
		usb_wait_in_ready();
		#ifdef MEGA4_6
		if ((((uint16_t)(UEBCHX)<<8)+UEBCLX)==0) {	// buffer is empty
		#else
		if (UEBCLX==0) {	// buffer is empty
		#endif
			for (i=0; i<datasize; i++) 
				if (UEINTX & _BV(RWAL)) UEDATX = buffer[i];
			UEINTX&=~_BV(TXINI);	// necessary (in this order) (changed V1.1.1)
			UEINTX=0x7F;	// (uint8_t)~_BV(FIFOCON);
			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------------------------
// USB Device Interrupt
//-----------------------------------------------------------------------------
// Hardware interrupts of the USB controller

ISR(USB_GEN_vect)
{
	uint8_t intbits;

  intbits = UDINT;	// save flags
  UDINT = 0;				// reset flags
  if (intbits & _BV(EORSTI)) {	// End Of Reset Interrupt Flag
		// initialize endpoint 0 for control transfers
		UENUM = 0;
		UECONX = _BV(EPEN);
		UECFG0X = EP_TYPE_CONTROL;
		UECFG1X = EP_SIZE(ENDPOINT0_SIZE) | EP_SINGLE_BUFFER;
		UEIENX = _BV(RXSTPE);	// enable interrupt for incoming data
		usb_conf = 0;
		#if (NUMINTERFACES>1)
		usb_if = 0xFF;
		#endif
  }
}

//-----------------------------------------------------------------------------
// Endpoint Interrupts
//-----------------------------------------------------------------------------
// Interrupts, triggered by incoming data in an endpoint, are handled here.

ISR(USB_COM_vect)
{
	#if (NUMINTERFACES>1)
	#define EPCO	EP_CONFIG[j][i]
	#else
	#define EPCO	EP_CONFIG[i]
	#endif

  uint8_t intbits;
	uint8_t i, j, n, s;
	cfg_desc *cfg;
	if_desc *ifp;
	hid_desc *hidp;
	ep_desc *epp;
	#if (USESN==2)	// serial number in RAM
	struct usb_string_descriptor_ram buf;
	#endif
	usb_control_request ucr;

	if (UEINT & 0x01) {
		// handle interrupts of endpoint 0 (control transfers)
	  UENUM = 0;
	  intbits = UEINTX;	// save interrupt flags of the endpoint
	  if (intbits & _BV(RXSTPI)) {	// control transfer, setup
	    ucr.bmRequestType = UEDATX;
	    ucr.bRequest = UEDATX;
	    ucr.wValue = UEDATX;
	    ucr.wValue |= (UEDATX << 8);
	    ucr.wIndex = UEDATX;
	    ucr.wIndex |= (UEDATX << 8);
	    ucr.wLength = UEDATX;
	    ucr.wLength |= (UEDATX << 8);
	    UEINTX = ~(_BV(RXSTPI) | _BV(RXOUTI) | _BV(TXINI));
	    if (ucr.bRequest == GET_DESCRIPTOR) {
				switch (ucr.wValue) {
				  case 0x0100:	// device descriptor
						usb_desc_out(false,&device_descriptor[0],pgm_read_byte(&device_descriptor[0]),ucr.wLength);
						break;
					case 0x0200:	// configuration descriptor
						// get number of activated endpoints
						n=0;
						#if (NUMINTERFACES>1)
						for (j=0; j<NUMINTERFACES; j++)
							for (i=0; i<MAX_ENDPOINT; i++) n+=(EP_CONFIG[j][i].ep_type!=EP_TYPE_DISABLED);
						#else
						for (i=0; i<MAX_ENDPOINT; i++) n+=(EP_CONFIG[i].ep_type!=EP_TYPE_DISABLED);
						#endif
						s = sizeof(cfg_desc)+NUMINTERFACES*sizeof(if_desc)+sizeof(hid_desc)+n*sizeof(ep_desc);
						cfg = malloc(s);	// allocate memory
						// initialize configuration descriptor
						cfg->bLength = sizeof(cfg_desc);
						cfg->bDescriptorType = 2;
						cfg->wTotalLength = s;
						cfg->bNumInterfaces = NUMINTERFACES;
						cfg->bConfigurationValue = 1;
						cfg->iConfiguration = 0;
						cfg->bmAttributes = POWERING;
						cfg->bMaxPower = MAXPOWER>>1;
						// initialize interface descriptor
						ifp = (if_desc *)((uint16_t)(cfg)+sizeof(cfg_desc));
						#if (NUMINTERFACES>1)
						for (j=0; j<NUMINTERFACES; j++) {
							n = 0;
							for (i=0; i<MAX_ENDPOINT; i++) n+=(EP_CONFIG[j][i].ep_type!=EP_TYPE_DISABLED);	// number of endpoints for one interface
						#else
							j = 0;
						#endif
							ifp->bLength = sizeof(if_desc);
							ifp->bDescriptorType = 4;
							ifp->bInterfaceNumber = j;
							ifp->bAlternateSetting = 0;
							ifp->bNumEndpoints = n;
							ifp->bInterfaceClass = 0x03;	// HID  #######0xFF;
							ifp->bInterfaceSubClass = 0x00;
							ifp->bInterfaceProtocol = 0x00;	// HID   #######0xFF;
							ifp->iInterface = 0;
							// initialize HID class descriptor
							hidp = (hid_desc *)((uint16_t)(ifp)+sizeof(if_desc));
							hidp->bLength=sizeof(hid_desc);
							hidp->bDescriptorType=0x21;
							hidp->bcdHID=0x0111;
							hidp->bCountryCode=0;
							hidp->bNumDescriptors=1;
							hidp->bReportDescriptorType=0x22;
							hidp->wDescriptorLength=sizeof(rawhid_report_descriptor);
							// endpoints
							epp = (ep_desc *)((uint16_t)(hidp)+sizeof(hid_desc));
							if (n) {	
								for (i=0; i<MAX_ENDPOINT; i++) {
									if (EPCO.ep_type!=EP_TYPE_DISABLED) {
										epp->bLength = sizeof(ep_desc);
										epp->bDescriptorType = 5;
										epp->bEndpointAddress = (i+1)|(EPCO.ep_type<<7);
										epp->bmAttributes = EP_TRANSFER(EPCO.ep_type);
										epp->wMaxPacketSize = EPCO.ep_size;
										epp->bInterval = 0;
										epp = (ep_desc *)((uint16_t)(epp)+sizeof(ep_desc));
									}
								}
							}
						#if (NUMINTERFACES>1)
							ifp = (if_desc *)epp;
						}
						#endif
						// finally
						usb_desc_out(true,(uint8_t *)cfg,s,ucr.wLength);
						free(cfg);
						break;
				  case 0x2100:	// HID descriptor
						hidp = malloc(sizeof(hid_desc));	// allocate memory
						hidp->bLength=sizeof(hid_desc);
						hidp->bDescriptorType=0x21;
						hidp->bcdHID=0x0111;
						hidp->bCountryCode=0;
						hidp->bNumDescriptors=1;
						hidp->bReportDescriptorType=0x22;
						hidp->wDescriptorLength=sizeof(rawhid_report_descriptor);
						usb_desc_out(true,(uint8_t *)hidp,sizeof(hid_desc),ucr.wLength);
						free(hidp);
						break;
				  case 0x2200:	// HID report descriptor
						usb_desc_out(false,&rawhid_report_descriptor[0],sizeof(rawhid_report_descriptor),ucr.wLength);
						break;
					case 0x0300:	// String 0
						usb_desc_out(false,(uint8_t *)&string0.bLength,pgm_read_byte(&string0.bLength),ucr.wLength);
						break;
					case 0x0301:	// String 1
						usb_desc_out(false,(uint8_t *)&string1.bLength,pgm_read_byte(&string1.bLength),ucr.wLength);
						break;
					case 0x0302:	// String 2
						usb_desc_out(false,(uint8_t *)&string2.bLength,pgm_read_byte(&string2.bLength),ucr.wLength);
						break;
					#if (USESN>0)
					case 0x0303:	// String 3, serial number
						#if (USESN==1)	// serial number in the flash memory
						usb_desc_out(false,(uint8_t *)&string3.bLength,pgm_read_byte(&string3.bLength),ucr.wLength);
						#endif
						#if (USESN==2)	// serial number in the RAM
						buf.bDescriptorType=3;	// has to be 3 always
						i = 0;
						while (RAMSN[i]) {
							buf.wString[i] = RAMSN[i];
							i++;
						}
						buf.bLength=2*i+2;	// total length of the data set
						usb_desc_out(true,(uint8_t *)&buf,buf.bLength,ucr.wLength);
						#endif
						break;
					#endif
					default: 
						STALL;  // stall
				}
				return;
	    }
			if (ucr.bRequest == SET_ADDRESS) {
				USB_SEND_IN;
				usb_wait_in_ready();
				UDADDR = ucr.wValue | _BV(ADDEN);
				return;
			}
			if (ucr.bRequest == SET_CONFIGURATION && ucr.bmRequestType == 0) {	// another configuration will be chosen
				if (ucr.wValue==1) {	// configuration 1 will be chosen
					usb_conf = ucr.wValue;
					USB_SEND_IN;
					#if (NUMINTERFACES==1)
					usb_endpoints();	// initialize endpoints
					#else
					usb_if = 0;	// select interface 0
					usb_endpoints(usb_if);	// initialize endpoints
					#endif
				} else {	// other configurations are not supported in this version
					STALL;	// stall
				} 
				return;
			}
			if (ucr.bRequest == GET_CONFIGURATION && ucr.bmRequestType == 0x80) {
				usb_wait_in_ready();
				UEDATX = usb_conf;
				USB_SEND_IN;
				return;
			}
			if (ucr.bRequest == GET_STATUS) {
				usb_wait_in_ready();
				i = 0;
				#ifdef SUPPORT_ENDPOINT_HALT
				if (ucr.bmRequestType == 0x82) {
					UENUM = ucr.wIndex;
					if (UECONX & _BV(STALLRQ)) i = 1;
					UENUM = 0;
				}
				#endif
				UEDATX = i;
				UEDATX = 0;
				USB_SEND_IN;
				return;
			}
			if ((ucr.bRequest == CLEAR_FEATURE || ucr.bRequest == SET_FEATURE) && ucr.bmRequestType == 0x02 && ucr.wValue == 0) {
				i = ucr.wIndex & 0x7F;
				if (i >= 1 && i <= MAX_ENDPOINT) {
					USB_SEND_IN;
					UENUM = i;
					if (ucr.bRequest == SET_FEATURE) {
						UECONX = (1<<STALLRQ)|(1<<EPEN);
					} else {
						UECONX = (1<<STALLRQC)|(1<<RSTDT)|(1<<EPEN);
						UERST = (1 << i);
						UERST = 0;
					}
					return;
				}
			}
			if (ucr.wIndex == RAWHID_INTERFACE) {
				if (ucr.bmRequestType == 0xA1 && ucr.bRequest == HID_GET_REPORT) {
					j = RAWHID_TX_SIZE;
					do {
						// wait for host ready for IN packet
						do {
							i = UEINTX;
						} while (!(i & ((1<<TXINI)|(1<<RXOUTI))));
						if (i & (1<<RXOUTI)) return;	// abort
						// send IN packet
						n = j < ENDPOINT0_SIZE ? j : ENDPOINT0_SIZE;
						for (i = n; i; i--) {
							// just send zeros
							UEDATX = 0;
						}
						j -= n;
						USB_SEND_IN;
					} while (j || n == ENDPOINT0_SIZE);
					return;
				}
				if (ucr.bmRequestType == 0x21 && ucr.bRequest == HID_SET_REPORT) {
					j = RAWHID_RX_SIZE;
					do {
						n = j < ENDPOINT0_SIZE ? j : ENDPOINT0_SIZE;
						usb_wait_receive_out();
						UEINTX = ~_BV(RXOUTI);	// ignore incoming bytes
						j -= n;
					} while (j);
					usb_wait_in_ready();
					USB_SEND_IN;
					return;
				}
			}
			#if (NUMINTERFACES>1)
			if (ucr.bRequest == SET_INTERFACE && (ucr.bmRequestType == 0x20 || ucr.bmRequestType == 0)) {	// another interface will be chosen
				if (ucr.wIndex<NUMINTERFACES) {	// defined interface will be chosen
					usb_if = ucr.wIndex;
					USB_SEND_IN;
					usb_endpoints(usb_if);	// initialize endpoints
				} else {	// other configurations are not supported in this version
					STALL;	// stall
				}
				return;
			}
			if (ucr.bRequest == GET_INTERFACE && ucr.bmRequestType == 0x80) {
				usb_wait_in_ready();
				UEDATX = usb_if;
				USB_SEND_IN;
				return;
			}
			#endif
			#ifdef SUPPORT_ENDPOINT_HALT
			if ((ucr.bRequest == CLEAR_FEATURE || ucr.bRequest == SET_FEATURE)
			  && ucr.bmRequestType == 0x02 && ucr.wValue == 0) {
				i = ucr.wIndex & 0x7F;
				if (i >= 1 && i <= MAX_ENDPOINT) {
					USB_SEND_IN;
					UENUM = i;
					if (ucr.bRequest == SET_FEATURE) {
						UECONX = _BV(STALLRQ)|_BV(EPEN);
					} else {
						UECONX = _BV(STALLRQC)|_BV(RSTDT)|_BV(EPEN);
						UERST = _BV(i);
						UERST = 0;
					}
					return;
				}
			}
			#endif
			#ifdef USERDEFCONTROLS
			// handle user defined  control requests
			if (!usb_controlrequest(&ucr))
				UECONX = _BV(STALLRQ) | _BV(EPEN);	// stall
				return;
			#endif
	  }
		UECONX = _BV(STALLRQ) | _BV(EPEN);	// stall
	}

	// handle interrupts for further endpoints
	for (i=1; i<=MAX_ENDPOINT; i++) {
		if (UEINT & _BV(i)) {
			UENUM=i;	// select endpoint
		  intbits = UEINTX;	// save interrupt bits of the endpoint
		  if (intbits & _BV(RXOUTI)) {	// interrupt occured by incoming data
				#ifdef MEGA4_6
				if (((uint16_t)(UEBCHX)<<8)+UEBCLX) {	// data available in input endpoint
					usb_ep(i,((uint16_t)(UEBCHX)<<8)+UEBCLX);
				#else
				if (UEBCLX) {	// data available in input endpoint
					usb_ep(i,UEBCLX);
				#endif
					UENUM=i;	// reselect endpoint (if changed by handling routine)
				}
		    UEINTX = ~(_BV(RXOUTI)|_BV(STALLEDI)); 	// clear interrupt flags
				UEINTX = 0x7F;	// free bank (FIFOCON), has to be executed after RXOUTI!
				return;
			}
			STALL;	// stall
		}
	}
	STALL;	// stall
}
