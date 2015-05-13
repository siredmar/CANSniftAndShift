#include "gpio.h"
#include "Port_cfg.h"
#include "Port_lcfg.h"
#include "std_types.h"

static volatile Port_ConfigType *localConfig;

volatile const Port_RegisterAddresstype Port_RegisterAdress_as[MAX_NUM_OF_PORTS] =
{
      {
            (uint8*) PORT_PORTA_ADDRESS,
            (uint8*) PORT_DDRA_ADDRESS,
            (uint8*) PORT_PINA_ADDRESS
      },
      {
            (uint8*) PORT_PORTB_ADDRESS,
            (uint8*) PORT_DDRB_ADDRESS,
            (uint8*) PORT_PINB_ADDRESS
      },
      {
            (uint8*) PORT_PORTC_ADDRESS,
            (uint8*) PORT_DDRC_ADDRESS,
            (uint8*) PORT_PINC_ADDRESS
      },
      {
            (uint8*) PORT_PORTD_ADDRESS,
            (uint8*) PORT_DDRD_ADDRESS,
            (uint8*) PORT_PIND_ADDRESS
      }
};


void Port_init()
{
   uint8 forCounter1_ui8;
   uint8 forCounter2_ui8;
   Port_PinInOutType Port_LocalPinInOut;
   Port_PinInitialType Port_LocalPinInitial;
   Port_PortType port_e;
   Port_PinType pin_e;
   uint16 channel_ui16;

   localConfig = (Port_ConfigType*) Port_getlcfgdata();

   for(forCounter1_ui8 = 0; forCounter1_ui8 < MAX_NUM_OF_PORTS * MAX_NUM_OF_PINS; forCounter1_ui8++)
   {
      if(localConfig->Port_PinConfig[forCounter1_ui8].Port_ConfireAllowed == PORT_TRUE)
      {
         Port_LocalPinInOut = localConfig->Port_PinConfig[forCounter1_ui8].Port_PinInOut;
         Port_LocalPinInitial = localConfig->Port_PinConfig[forCounter1_ui8].Port_PinInitial;
         channel_ui16 = localConfig->Port_PinConfig[forCounter1_ui8].Port_Pin;
         port_e = (uint8)(channel_ui16 >> 8);
         pin_e = (uint8)((channel_ui16 & 0xFF));

         *(Port_RegisterAdress_as[port_e].Port_DirectionRegister_pui8) |= (uint8)(Port_LocalPinInOut << pin_e);
         if(Port_LocalPinInOut == PORT_OUTPUT)
         {
          *(Port_RegisterAdress_as[port_e].Port_PortRegister_pui8) |= (uint8)(Port_LocalPinInitial << pin_e);
         }
      }
   }
}


void Port_WriteChannel(Port_ChannelType channel, Port_PinState state)
{
   Port_PortType port_ui8 = (channel >> 8);
   Port_PinType pin_ui8 = (channel & 0xFF);

   if(state == PORT_HIGH)
      *(Port_RegisterAdress_as[port_ui8].Port_PortRegister_pui8) |= (1 << pin_ui8);
   else
      *(Port_RegisterAdress_as[port_ui8].Port_PortRegister_pui8) &= ~(1 << pin_ui8);
}

void Port_ToggleChannel(Port_ChannelType channel)
{
   Port_PortType port_ui8 = (channel >> 8);
   Port_PinType pin_ui8 = (channel & 0xFF);

   *(Port_RegisterAdress_as[port_ui8].Port_PortRegister_pui8) ^= (uint8)(1 << pin_ui8);
}

Port_PinState Port_ReadChannel(Port_ChannelType channel)
{
   Port_PortType port_ui8 = (channel >> 8);
   Port_PinType pin_ui8 = (channel & 0xFF);

   return *(Port_RegisterAdress_as[port_ui8].Port_InputRgister_pui8) & (uint8)(1 << pin_ui8);
}
