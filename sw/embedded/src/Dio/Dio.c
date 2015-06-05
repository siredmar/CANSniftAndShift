#include "Dio.h"
#include "Dio_Cfg.h"
#include "Dio_Lcfg.h"

const Dio_RegisterAddresstype Dio_RegisterAdress_as[DIO_NUMBER_OF_PORTS] =
{
        {
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_GPER_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_GPERS_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_GPERC_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_GPERT_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_ODER_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_ODERS_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_ODERC_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_ODERT_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_OVR_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_OVRS_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_OVRC_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_OVRT_REGISTER_OFFSET),
                (uint32*) (DIO_A_REGISTER_OFFSET + DIO_PVR_REGISTER_OFFSET)
        },
        {
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_GPER_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_GPERS_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_GPERC_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_GPERT_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_ODER_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_ODERS_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_ODERC_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_ODERT_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_OVR_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_OVRS_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_OVRC_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_OVRT_REGISTER_OFFSET),
                (uint32*) (DIO_B_REGISTER_OFFSET + DIO_PVR_REGISTER_OFFSET)
        },
        {
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_GPER_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_GPERS_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_GPERC_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_GPERT_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_ODER_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_ODERS_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_ODERC_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_ODERT_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_OVR_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_OVRS_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_OVRC_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_OVRT_REGISTER_OFFSET),
                (uint32*) (DIO_C_REGISTER_OFFSET + DIO_PVR_REGISTER_OFFSET)
        },
        {
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_GPER_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_GPERS_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_GPERC_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_GPERT_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_ODER_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_ODERS_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_ODERC_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_ODERT_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_OVR_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_OVRS_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_OVRC_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_OVRT_REGISTER_OFFSET),
                (uint32*) (DIO_D_REGISTER_OFFSET + DIO_PVR_REGISTER_OFFSET)
        }
};


void Dio_Init(void)
{
    /* ... */
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 Port_ui8;
    uint8 Pin_ui8;
    Pin_ui8 = (uint8)(ChannelId & 0xFF);
    Port_ui8 = (uint8)(((uint16)(ChannelId >> 8)) & 0xFF);

    *(Dio_RegisterAdress_as[Port_ui8].Dio_GpioEnableRegister_pui32) |= ((uint32)(1 << Pin_ui8));
    *(Dio_RegisterAdress_as[Port_ui8].Dio_OutputDriverEnableRegister_pui32) |= ((uint32)(1 << Pin_ui8));
    if(Level == STD_HIGH)
    {
        *(Dio_RegisterAdress_as[Port_ui8].Dio_OutputValueRegister_pui32) |= ((uint32)(1 << Pin_ui8));
    }
    else
    {
        *(Dio_RegisterAdress_as[Port_ui8].Dio_OutputValueRegister_pui32)  &= ~((uint32)(1 << Pin_ui8));
    }
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8 Port_ui8;
    uint8 Channel_ui8;

    Channel_ui8 = (uint8)(ChannelId & 0xFF);
    Port_ui8 = (uint8)(((uint16)(ChannelId >> 8)) & 0xFF);

    return (Dio_LevelType)((*(Dio_RegisterAdress_as[Port_ui8].Dio_PinValueRegister_pui32) >> Channel_ui8) & 0x01U);
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    uint8 Port_ui8;
    uint8 Channel_ui8;
    Channel_ui8 = (uint8)(ChannelId & 0xFF);
    Port_ui8 = (uint8)(((uint16)(ChannelId >> 8)) & 0xFF);

    *(Dio_RegisterAdress_as[Port_ui8].Dio_OutputDriverEnableRegister_pui32) |= ((uint32)(1 << Channel_ui8));
    *(Dio_RegisterAdress_as[Port_ui8].Dio_GpioEnableRegister_pui32) |= ((uint32)(1 << Channel_ui8));
    *(Dio_RegisterAdress_as[Port_ui8].Dio_OutputValueRegister_pui32) ^= ((uint32)(1 << Channel_ui8));

    return (Dio_LevelType)((*(Dio_RegisterAdress_as[Port_ui8].Dio_PinValueRegister_pui32) >> Channel_ui8) & 0x01U);
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    *(Dio_RegisterAdress_as[PortId].Dio_OutputValueRegisterS_pui32) = (uint32)Level;
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    return  *(Dio_RegisterAdress_as[PortId].Dio_PinValueRegister_pui32);
}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{

    Dio_PortLevelType portVal;
    portVal = Dio_ReadPort(ChannelGroupIdPtr->port) & (~ChannelGroupIdPtr->mask);
    Level = (Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask;
    portVal |= Level;

    Dio_WritePort(ChannelGroupIdPtr->port, portVal);
}

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
    Dio_PortLevelType level;

    level = Dio_ReadPort(ChannelGroupIdPtr->port) & ChannelGroupIdPtr->mask;
    level = level >> ChannelGroupIdPtr->offset;

    return level;
}

void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    /* ... */
}

