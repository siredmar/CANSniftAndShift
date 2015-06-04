/*****************************************************************************

UxDIL Device Check Firmware

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
Homepage: http://products.reworld.eu/index.htm

Supported devices:
U2DIL, assembled with AT90USB162
U2DIL, assembled with ATMEGA32U2
U4DIL, assembled with ATMEGA32U4
U6DIL, assembled with AT90USB1286
U6DIL, assembled with AT90USB1287

Created: 2010-03-12
Changed: 2011-04-30

*****************************************************************************/

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
//#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "usb_user_config.h"	// USB configuration
#include "usb_user.h"				// USB functions

#define TIMEREF		10			// time reference in ms (approx.), created with timer 0, 0<TIMEREF<17 (1..16ms)
#define TCNT0VAL	(256-(TIMEREF*F_CPU)/1024000)		// Timer0 time value

volatile uint8_t *checkddr	= NULL;		// ddr of port to check
volatile uint8_t *checkport	= NULL;		// port to check
volatile uint8_t checkpin		= 0;			// pin to check
volatile uint8_t checklevel	= 0;			// level (0=low, 1=high, 2=square wave)

#ifdef USERDEFCONTROLS	// see usbconfig.h
//-----------------------------------------------------------------------------
bool usb_controlrequest(struct usb_control_request *ucr)
//-----------------------------------------------------------------------------
// Handle user defined control requests
// "ucr" contains the data of the control request
// function has to return "true", if request is handled (otherwise "false")
{
	// insert your own program code here
	return true;
}
#endif

//-----------------------------------------------------------------------------
void usb_ep(uint8_t endpoint, uint16_t datasize)
//-----------------------------------------------------------------------------
// handle of endpoint interrupt for incoming data
// "datasize" contains the number od bytes in the USB FIFO buffer
{
	// insert your own program code here (read of USB FIFO buffer UEDATX)

	unsigned char d[3];
	uint8_t n;
	struct {
		uint8_t	Type;			// 2=U2DIL, 4=U4DIL, 6=U6DIL
		char		MCU[15];	// e.g.: "AT90USB1286"
	} info;

	n=usb_rxdata(endpoint,d,sizeof(d));
	if (n>=3) {
		switch (d[0]) {
			case '?':	// request information about module
				info.Type=0;
				#ifdef MEGA2
					info.Type=2;
				#endif
				#ifdef MEGA4
					info.Type=4;
				#endif
				#ifdef MEGA6
					info.Type=6;
				#endif
				strcpy(info.MCU,"(unknown)");
				#if defined (__AVR_AT90USB82__)
					strcpy(info.MCU,"AT90USB82");
				#endif
				#if defined (__AVR_AT90USB162__)
					strcpy(info.MCU,"AT90USB162");
				#endif
				#if defined (__AVR_ATmega8U2__)
					strcpy(info.MCU,"ATMEGA8U2");
				#endif
				#if defined (__AVR_ATmega32U2__)
					strcpy(info.MCU,"ATMEGA32U2");
				#endif
				#if defined (__AVR_ATmega16U4__)
					strcpy(info.MCU,"ATMEGA16U4");
				#endif
				#if defined (__AVR_ATmega32U4__)
					strcpy(info.MCU,"ATMEGA32U4");
				#endif
				#if defined (__AVR_AT90USB646__)
					strcpy(info.MCU,"AT90USB646");
				#endif
				#if defined (__AVR_AT90USB647__)
					strcpy(info.MCU,"AT90USB647");
				#endif
				#if defined (__AVR_AT90USB1286__)
					strcpy(info.MCU,"AT90USB1286");
				#endif
				#if defined (__AVR_AT90USB1287__)
					strcpy(info.MCU,"AT90USB1287");
				#endif
				usb_txdata(2,(uint8_t *)&info,sizeof(info));	// response
				break;
			#ifdef MEGA6
			case 'A': checkddr  = &DDRA;
								checkport = &PORTA;
			  break;
			#endif
			case 'B': checkddr  = &DDRB;
								checkport = &PORTB;
			  break;
			case 'C': checkddr  = &DDRC;
								checkport = &PORTC;
			  break;
			case 'D': checkddr  = &DDRD;
								checkport = &PORTD;
			  break;
			#ifdef MEGA4_6
			case 'E': checkddr  = &DDRE;
								checkport = &PORTE;
			  break;
			case 'F': checkddr  = &DDRF;
								checkport = &PORTF;
			  break;
			#endif
      default : checkddr  = NULL;
								checkport = NULL;
		}
		checkpin=d[1]&0x07;
		if (d[2]<3) checklevel=d[2];
		// set all ports as input
		#ifdef MEGA6
		DDRA=0;
		#endif
		DDRB=0;
		DDRC=0;
		DDRD=0;
		#ifdef MEGA4_6
		DDRE=0;
		DDRF=0;
		#endif
		// set selected port pin as output
		if (checkddr)	(*checkddr)=_BV(checkpin);
 	}
}

//-----------------------------------------------------------------------------
ISR (TIMER0_OVF_vect)
//-----------------------------------------------------------------------------
// Timer/Counter0 Overflow 
{
	if (checkport) {
		// set level at selected port
	  switch (checklevel) {
			case 0: (*checkport)&=~_BV(checkpin);	// low
				break;
			case 1: (*checkport)|=_BV(checkpin);	// high
				break;
			case 2: (*checkport)^=_BV(checkpin);	// toggle (square wave)
				break;
		}
	}
	TCNT0=TCNT0VAL-TCNT0;	// restart timer
}

//-----------------------------------------------------------------------------
int main(void)
//-----------------------------------------------------------------------------
{	// main routine

	// disable JTAG interface
	#ifndef MEGA2
	MCUCR|=_BV(JTD);
	MCUCR|=_BV(JTD);	// has to be written twice within 4 clock cycles
	#endif

	// initialize timer 0
	TCCR0B = _BV(CS02)|_BV(CS00);	// clock div 1024
	TCNT0 = TCNT0VAL;							// counter start value
	TIMSK0 = _BV(TOIE0);					// overflow interrupt

	usb_init();		// initialize USB
	sei();				// enable interrupts (strictly necessary!)

	while (1) {		// main loop
	}
}
