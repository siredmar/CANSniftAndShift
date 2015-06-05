#include "Std_Types.h"
#include "Platform_MCU.h"


#ifndef DIO_H
#define DIO_H

#define DIO_MAX_NUM_OF_CHANNEL_GROUPS (0U)


typedef enum
{
    /* Port A */
    DIO_CHANNEL_PA0   = (0x0000U),
    DIO_CHANNEL_PA1   = (0x0001U),
    DIO_CHANNEL_PA2   = (0x0002U),
    DIO_CHANNEL_PA3   = (0x0003U),
    DIO_CHANNEL_PA4   = (0x0004U),
    DIO_CHANNEL_PA5   = (0x0005U),
    DIO_CHANNEL_PA6   = (0x0006U),
    DIO_CHANNEL_PA7   = (0x0007U),
    DIO_CHANNEL_PA8   = (0x0008U),
    DIO_CHANNEL_PA9   = (0x0009U),
#ifndef PACKAGE_TQFP64
    DIO_CHANNEL_PA10  = (0x000AU),
    DIO_CHANNEL_PA11  = (0x000BU),
    DIO_CHANNEL_PA12  = (0x000CU),
    DIO_CHANNEL_PA13  = (0x000DU),
    DIO_CHANNEL_PA14  = (0x000EU),
    DIO_CHANNEL_PA15  = (0x000FU),
#endif
    DIO_CHANNEL_PA16  = (0x0010U),
    DIO_CHANNEL_PA19  = (0x0013U),
    DIO_CHANNEL_PA20  = (0x0014U),
    DIO_CHANNEL_PA21  = (0x0015U),
    DIO_CHANNEL_PA22  = (0x0016U),
    DIO_CHANNEL_PA23  = (0x0017U),
#ifndef PACKAGE_TQFP64
    DIO_CHANNEL_PA24  = (0x0018U),
    DIO_CHANNEL_PA25  = (0x0019U),
#endif
#ifndef PACKAGE_TQFP64
#ifndef PACKAGE_TQFP100
    DIO_CHANNEL_PA26  = (0x001AU),
    DIO_CHANNEL_PA27  = (0x001BU),
    DIO_CHANNEL_PA28  = (0x001CU),
    DIO_CHANNEL_PA29  = (0x001DU),
#endif
#endif

    /* Port B */
    DIO_CHANNEL_PB0   = (0x0100U),
    DIO_CHANNEL_PB1   = (0x0101U),
#ifndef PACKAGE_TQFP64
    DIO_CHANNEL_PB2   = (0x0102U),
    DIO_CHANNEL_PB3   = (0x0103U),
    DIO_CHANNEL_PB4   = (0x0104U),
    DIO_CHANNEL_PB5   = (0x0105U),
    DIO_CHANNEL_PB6   = (0x0106U),
#ifndef PACKAGE_TQFP100
    DIO_CHANNEL_PB7   = (0x0107U),
    DIO_CHANNEL_PB8   = (0x0108U),
    DIO_CHANNEL_PB9   = (0x0109U),
    DIO_CHANNEL_PB10  = (0x010AU),
    DIO_CHANNEL_PB11  = (0x010BU),
    DIO_CHANNEL_PB12  = (0x010CU),
    DIO_CHANNEL_PB13  = (0x010DU),
    DIO_CHANNEL_PB14  = (0x010EU),
    DIO_CHANNEL_PB15  = (0x010FU),
    DIO_CHANNEL_PB16  = (0x0110U),
    DIO_CHANNEL_PB17  = (0x0111U),
    DIO_CHANNEL_PB18  = (0x0112U),
#endif
    DIO_CHANNEL_PB19  = (0x0113U),
    DIO_CHANNEL_PB20  = (0x0114U),
    DIO_CHANNEL_PB21  = (0x0115U),
    DIO_CHANNEL_PB22  = (0x0116U),
    DIO_CHANNEL_PB23  = (0x0117U),
#ifndef PACKAGE_TQFP100
    DIO_CHANNEL_PB24  = (0x0118U),
    DIO_CHANNEL_PB25  = (0x0119U),
    DIO_CHANNEL_PB26  = (0x011AU),
    DIO_CHANNEL_PB27  = (0x011BU),
    DIO_CHANNEL_PB28  = (0x011CU),
    DIO_CHANNEL_PB29  = (0x011DU),
#endif
#endif
    DIO_CHANNEL_PB30  = (0x011EU),
    DIO_CHANNEL_PB31  = (0x011FU),

    /* Port C */
#ifndef PACKAGE_TQFP64
    DIO_CHANNEL_PC0   = (0x0200U),
    DIO_CHANNEL_PC1   = (0x0201U),
#endif
    DIO_CHANNEL_PC2   = (0x0202U),
    DIO_CHANNEL_PC3   = (0x0203U),
    DIO_CHANNEL_PC4   = (0x0204U),
    DIO_CHANNEL_PC5   = (0x0205U),
#ifndef PACKAGE_TQFP64
    DIO_CHANNEL_PC6   = (0x0206U),
    DIO_CHANNEL_PC7   = (0x0207U),
#ifndef PACKAGE_TQFP100
    DIO_CHANNEL_PC8   = (0x0208U),
    DIO_CHANNEL_PC9   = (0x0209U),
    DIO_CHANNEL_PC10  = (0x020AU),
#endif
    DIO_CHANNEL_PC11  = (0x020BU),
    DIO_CHANNEL_PC12  = (0x020CU),
    DIO_CHANNEL_PC13  = (0x020DU),
    DIO_CHANNEL_PC14  = (0x020EU),
#endif
    DIO_CHANNEL_PC15  = (0x020FU),
    DIO_CHANNEL_PC16  = (0x0210U),
    DIO_CHANNEL_PC17  = (0x0211U),
    DIO_CHANNEL_PC18  = (0x0212U),
    DIO_CHANNEL_PC19  = (0x0213U),
    DIO_CHANNEL_PC20  = (0x0214U),
    DIO_CHANNEL_PC21  = (0x0215U),
    DIO_CHANNEL_PC22  = (0x0216U),
#ifndef PACKAGE_TQFP64
    DIO_CHANNEL_PC23  = (0x0217U),
    DIO_CHANNEL_PC24  = (0x0218U),
#ifndef PACKAGE_TQFP100
    DIO_CHANNEL_PC25  = (0x0219U),
    DIO_CHANNEL_PC26  = (0x021AU),
    DIO_CHANNEL_PC27  = (0x021BU),
    DIO_CHANNEL_PC28  = (0x021CU),
    DIO_CHANNEL_PC29  = (0x021DU),
    DIO_CHANNEL_PC30  = (0x021EU),
#endif
    DIO_CHANNEL_PC31  = (0x021FU),
#endif

    /* Port D */
    DIO_CHANNEL_PD0   = (0x0300U),
    DIO_CHANNEL_PD1   = (0x0301U),
    DIO_CHANNEL_PD2   = (0x0302U),
    DIO_CHANNEL_PD3   = (0x0303U),
#ifndef PACKAGE_TQFP64
#ifndef PACKAGE_TQFP100
    DIO_CHANNEL_PD4   = (0x0304U),
    DIO_CHANNEL_PD5   = (0x0305U),
    DIO_CHANNEL_PD6   = (0x0306U),
#endif
    DIO_CHANNEL_PD7   = (0x0307U),
    DIO_CHANNEL_PD8   = (0x0308U),
    DIO_CHANNEL_PD9   = (0x0309U),
    DIO_CHANNEL_PD10  = (0x030AU),
#endif
    DIO_CHANNEL_PD11  = (0x030BU),
    DIO_CHANNEL_PD12  = (0x030CU),
    DIO_CHANNEL_PD13  = (0x030DU),
    DIO_CHANNEL_PD14  = (0x030EU),
#ifndef PACKAGE_TQFP64
#ifndef PACKAGE_TQFP100
    DIO_CHANNEL_PD15  = (0x030FU),
    DIO_CHANNEL_PD16  = (0x0310U),
    DIO_CHANNEL_PD17  = (0x0311U),
    DIO_CHANNEL_PD18  = (0x0312U),
    DIO_CHANNEL_PD19  = (0x0313U),
    DIO_CHANNEL_PD20  = (0x0314U),
#endif
#endif
    DIO_CHANNEL_PD21  = (0x0315U),
#ifndef PACKAGE_TQFP64
    DIO_CHANNEL_PD22  = (0x0316U),
    DIO_CHANNEL_PD23  = (0x0317U),
    DIO_CHANNEL_PD24  = (0x0318U),
#ifndef PACKAGE_TQFP100
    DIO_CHANNEL_PD25  = (0x0319U),
    DIO_CHANNEL_PD26  = (0x031AU),
#endif
#endif
    DIO_CHANNEL_PD27  = (0x031BU),
    DIO_CHANNEL_PD28  = (0x031CU),
    DIO_CHANNEL_PD29  = (0x031DU),
    DIO_CHANNEL_PD30  = (0x031EU),
    DIO_CHANNEL_PD31  = (0x031FU)
} Dio_ChannelType;

typedef enum
{
    DIO_PORT_A = (0U),
    DIO_PORT_B,
    DIO_PORT_C,
    DIO_PORT_D,
    DIO_NUMBER_OF_PORTS
} Dio_PortType;

typedef enum
{
    STD_LOW = (0U),
    STD_HIGH
} Dio_LevelType;

typedef uint32 Dio_PortLevelType;

typedef struct
{
    uint32*       Dio_GpioEnableRegister_pui32;
    uint32*       Dio_GpioEnableRegisterS_pui32;
    uint32*       Dio_GpioEnableRegisterC_pui32;
    uint32*       Dio_GpioEnableRegisterT_pui32;

    uint32*       Dio_OutputDriverEnableRegister_pui32;
    uint32*       Dio_OutputDriverEnableRegisterS_pui32;
    uint32*       Dio_OutputDriverEnableRegisterC_pui32;
    uint32*       Dio_OutputDriverEnableRegisterT_pui32;

    uint32*       Dio_OutputValueRegister_pui32;
    uint32*       Dio_OutputValueRegisterS_pui32;
    uint32*       Dio_OutputValueRegisterC_pui32;
    uint32*       Dio_OutputValueRegisterT_pui32;

    uint32*       Dio_PinValueRegister_pui32;
} Dio_RegisterAddresstype;


typedef struct
{
    uint32 mask;
    uint8 offset;
    Dio_PortType port;
} Dio_ChannelGroupType;

typedef struct
{
    Dio_ChannelGroupType Dio_ChannelGroup[DIO_MAX_NUM_OF_CHANNEL_GROUPS];
} Dio_ConfigType;


void Dio_Init(void);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);

#endif

