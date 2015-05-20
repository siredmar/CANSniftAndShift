#include "../../inc/Std_Types.h"
#include "../../inc/Platform_MCU.h"

#ifndef PORT_H
#define PORT_H


#ifdef PACKAGE_TQFP64
#define PORT_PORTA_NUMBER_OF_PINS (16U)
#endif
#ifdef PACKAGE_TQFP100
#define PORT_PORTA_NUMBER_OF_PINS (31U)
#endif
#ifdef PACKAGE_LQFP144
#define PORT_PORTA_NUMBER_OF_PINS (27U)
#endif

#ifdef PACKAGE_TQFP64
#define PORT_PORTB_NUMBER_OF_PINS (4U)
#endif
#ifdef PACKAGE_TQFP100
#define PORT_PORTB_NUMBER_OF_PINS (14U)
#endif
#ifdef PACKAGE_LQFP144
#define PORT_PORTB_NUMBER_OF_PINS (32U)
#endif

#ifdef PACKAGE_TQFP64
#define PORT_PORTC_NUMBER_OF_PINS (12U)
#endif
#ifdef PACKAGE_TQFP100
#define PORT_PORTC_NUMBER_OF_PINS (23U)
#endif
#ifdef PACKAGE_LQFP144
#define PORT_PORTC_NUMBER_OF_PINS (32U)
#endif

#ifdef PACKAGE_TQFP64
#define PORT_PORTD_NUMBER_OF_PINS (14U)
#endif
#ifdef PACKAGE_TQFP100
#define PORT_PORTD_NUMBER_OF_PINS (20U)
#endif
#ifdef PACKAGE_LQFP144
#define PORT_PORTD_NUMBER_OF_PINS (31U)
#endif

#define PORT_MAX_NUMBER_OF_PINS (PORT_PORTA_NUMBER_OF_PINS + PORT_PORTB_NUMBER_OF_PINS + PORT_PORTC_NUMBER_OF_PINS + PORT_PORTD_NUMBER_OF_PINS)
#define PORT_MAX_NUMBER_OF_PORTS (4U)

typedef enum
{
   /* Port A */
   PORT_PA0   = (0x0100U),
   PORT_PA1   = (0x0101U),
   PORT_PA2   = (0x0102U),
   PORT_PA3   = (0x0103U),
   PORT_PA4   = (0x0104U),
   PORT_PA5   = (0x0105U),
   PORT_PA6   = (0x0106U),
   PORT_PA7   = (0x0107U),
   PORT_PA8   = (0x0108U),
   PORT_PA9   = (0x0109U),
#ifndef PACKAGE_TQFP64
   PORT_PA10  = (0x010AU),
   PORT_PA11  = (0x010BU),
   PORT_PA12  = (0x010CU),
   PORT_PA13  = (0x010DU),
   PORT_PA14  = (0x010EU),
   PORT_PA15  = (0x010FU),
#endif
   PORT_PA16  = (0x0110U),
   PORT_PA19  = (0x0113U),
   PORT_PA20  = (0x0114U),
   PORT_PA21  = (0x0115U),
   PORT_PA22  = (0x0116U),
   PORT_PA23  = (0x0117U),
#ifndef PACKAGE_TQFP64
   PORT_PA24  = (0x0118U),
   PORT_PA25  = (0x0119U),
#endif
#ifndef PACKAGE_TQFP64
#ifndef PACKAGE_TQFP100
   PORT_PA26  = (0x011AU),
   PORT_PA27  = (0x011BU),
   PORT_PA28  = (0x011CU),
   PORT_PA29  = (0x011DU),
#endif
#endif

/* Port B */
   PORT_PB0   = (0x0100U),
   PORT_PB1   = (0x0101U),
#ifndef PACKAGE_TQFP64
   PORT_PB2   = (0x0102U),
   PORT_PB3   = (0x0103U),
   PORT_PB4   = (0x0104U),
   PORT_PB5   = (0x0105U),
   PORT_PB6   = (0x0106U),
#ifndef PACKAGE_TQFP100
   PORT_PB7   = (0x0107U),
   PORT_PB8   = (0x0108U),
   PORT_PB9   = (0x0109U),
   PORT_PB10  = (0x010AU),
   PORT_PB11  = (0x010BU),
   PORT_PB12  = (0x010CU),
   PORT_PB13  = (0x010DU),
   PORT_PB14  = (0x010EU),
   PORT_PB15  = (0x010FU),
   PORT_PB16  = (0x0110U),
   PORT_PB17  = (0x0111U),
   PORT_PB18  = (0x0112U),
#endif
   PORT_PB19  = (0x0113U),
   PORT_PB20  = (0x0114U),
   PORT_PB21  = (0x0115U),
   PORT_PB22  = (0x0116U),
   PORT_PB23  = (0x0117U),
#ifndef PACKAGE_TQFP100
   PORT_PB24  = (0x0118U),
   PORT_PB25  = (0x0119U),
   PORT_PB26  = (0x011AU),
   PORT_PB27  = (0x011BU),
   PORT_PB28  = (0x011CU),
   PORT_PB29  = (0x011DU),
#endif
#endif
   PORT_PB30  = (0x011EU),
   PORT_PB31  = (0x011FU),

   /* Port C */
#ifndef PACKAGE_TQFP64
   PORT_PC0   = (0x0200U),
   PORT_PC1   = (0x0201U),
#endif
   PORT_PC2   = (0x0202U),
   PORT_PC3   = (0x0203U),
   PORT_PC4   = (0x0204U),
   PORT_PC5   = (0x0205U),
#ifndef PACKAGE_TQFP64
   PORT_PC6   = (0x0206U),
   PORT_PC7   = (0x0207U),
#ifndef PACKAGE_TQFP100
   PORT_PC8   = (0x0208U),
   PORT_PC9   = (0x0209U),
   PORT_PC10  = (0x020AU),
#endif
   PORT_PC11  = (0x020BU),
   PORT_PC12  = (0x020CU),
   PORT_PC13  = (0x020DU),
   PORT_PC14  = (0x020EU),
#endif
   PORT_PC15  = (0x020FU),
   PORT_PC16  = (0x0210U),
   PORT_PC17  = (0x0211U),
   PORT_PC18  = (0x0212U),
   PORT_PC19  = (0x0213U),
   PORT_PC20  = (0x0214U),
   PORT_PC21  = (0x0215U),
   PORT_PC22  = (0x0216U),
#ifndef PACKAGE_TQFP64
   PORT_PC23  = (0x0217U),
   PORT_PC24  = (0x0218U),
#ifndef PACKAGE_TQFP100
   PORT_PC25  = (0x0219U),
   PORT_PC26  = (0x021AU),
   PORT_PC27  = (0x021BU),
   PORT_PC28  = (0x021CU),
   PORT_PC29  = (0x021DU),
   PORT_PC30  = (0x021EU),
#endif
   PORT_PC31  = (0x021FU),
#endif

   /* Port D */
   PORT_PD0   = (0x0300U),
   PORT_PD1   = (0x0301U),
   PORT_PD2   = (0x0302U),
   PORT_PD3   = (0x0303U),
#ifndef PACKAGE_TQFP64
#ifndef PACKAGE_TQFP100
   PORT_PD4   = (0x0304U),
   PORT_PD5   = (0x0305U),
   PORT_PD6   = (0x0306U),
#endif
   PORT_PD7   = (0x0307U),
   PORT_PD8   = (0x0308U),
   PORT_PD9   = (0x0309U),
   PORT_PD10  = (0x030AU),
#endif
   PORT_PD11  = (0x030BU),
   PORT_PD12  = (0x030CU),
   PORT_PD13  = (0x030DU),
   PORT_PD14  = (0x030EU),
#ifndef PACKAGE_TQFP64
#ifndef PACKAGE_TQFP100
   PORT_PD15  = (0x030FU),
   PORT_PD16  = (0x0310U),
   PORT_PD17  = (0x0311U),
   PORT_PD18  = (0x0312U),
   PORT_PD19  = (0x0313U),
   PORT_PD20  = (0x0314U),
#endif
#endif
   PORT_PD21  = (0x0315U),
#ifndef PACKAGE_TQFP64
   PORT_PD22  = (0x0316U),
   PORT_PD23  = (0x0317U),
   PORT_PD24  = (0x0318U),
#ifndef PACKAGE_TQFP100
   PORT_PD25  = (0x0319U),
   PORT_PD26  = (0x031AU),
#endif
#endif
   PORT_PD27  = (0x031BU),
   PORT_PD28  = (0x031CU),
   PORT_PD29  = (0x031DU),
   PORT_PD30  = (0x031EU),
   PORT_PD31  = (0x031FU)
} Port_PortPinType;

typedef enum
{
   PORT_PORT_A = (0U),
   PORT_PORT_B,
   PORT_PORT_C,
   PORT_PORT_D,
   PORT_NUMBER_OF_PORTS
}Port_PortType;

typedef enum
{
   PERIPHERAL_FUNC_A = (0U),
   PERIPHERAL_FUNC_B,
   PERIPHERAL_FUNC_C,
   PERIPHERAL_FUNC_D,
   PERIPHERAL_FUNC_E,
   PERIPHERAL_FUNC_F,
   PERIPHERAL_FUNC_G,
   PERIPHERAL_FUNC_H,
   GPIO_MODE
} Port_PeripheralFunctionType;

typedef enum
{
   PIN_OUTPUT = (0U),
   PIN_INPUT
} Port_PinInOutType;

typedef enum
{
   OUTPUT_VALUE_ZERO = (0U),
   OUTPUT_VALUE_ONE
} Port_OutputValueType;

typedef enum
{
   INPUT_VALUE_ZERO = (0U),
   INPUT_VALUE_ONE
} Port_Type;

/* TODO: write PUER and PDER Registers */
typedef enum
{
   NO_PULLUP_PULLDOWN = (0U),
   PULLDOWN_ENABLED,
   PULLUP_ENABLED,
   BUSKEEPER_ENABLED
} Port_PullUpTypeType;

typedef enum
{
   INTERRUPT_DISABLED = (0U),
   INTERRUPT_PIN_CHANGE,
   INTERRUPT_RISING_EDGE,
   INTERRUPT_FALLING_EDGE
} Port_InterruptModeType;

typedef enum
{
   GLITCH_FILTER_DISABLED = (0U),
   GLITCH_FILTER_ENABLED
} Port_GlitchFilterType;

typedef enum
{
   NO_INTERRUPT_DETECED = (0U),
   INTERRUPT_DETECED
} Port_InterruptFlagType;

typedef enum
{
   OUTPUT_DRIVING_LOW = (0U),
   OUTPUT_DRIVING_LOW_MID,
   OUTPUT_DRIVING_HIGH_MID,
   OUTPUT_DRIVING_HIGH
} Port_OutputDrivingCapabilityType;

typedef enum
{
   PIN_UNIMPLEMENTED = (0U),
   PIN_IMPLEMENTED
} Port_ParameterType;

typedef enum
{
   PIN_LOW = (0U),
   PIN_HIGH
} Port_PinInitialStateType;

typedef struct
{
   uint32*       Port_GpioEnableRegister_pui32;
   uint32*       Port_GpioEnableRegisterS_pui32;
   uint32*       Port_GpioEnableRegisterC_pui32;
   uint32*       Port_GpioEnableRegisterT_pui32;

   uint32*       Port_PeripheralMux0Register_pui32;
   uint32*       Port_PeripheralMux0RegisterS_pui32;
   uint32*       Port_PeripheralMux0RegisterC_pui32;
   uint32*       Port_PeripheralMux0RegisterT_pui32;

   uint32*       Port_PeripheralMux1Register_pui32;
   uint32*       Port_PeripheralMux1RegisterS_pui32;
   uint32*       Port_PeripheralMux1RegisterC_pui32;
   uint32*       Port_PeripheralMux1RegisterT_pui32;

   uint32*       Port_PeripheralMux2Register_pui32;
   uint32*       Port_PeripheralMux2RegisterS_pui32;
   uint32*       Port_PeripheralMux2RegisterC_pui32;
   uint32*       Port_PeripheralMux2RegisterT_pui32;

   uint32*       Port_OutputDriverEnableRegister_pui32;
   uint32*       Port_OutputDriverEnableRegisterS_pui32;
   uint32*       Port_OutputDriverEnableRegisterC_pui32;
   uint32*       Port_OutputDriverEnableRegisterT_pui32;

   uint32*       Port_OutputValueRegister_pui32;
   uint32*       Port_OutputValueRegisterS_pui32;
   uint32*       Port_OutputValueRegisterC_pui32;
   uint32*       Port_OutputValueRegisterT_pui32;

   uint32*       Port_PinValueRegister_pui32;

   uint32*       Port_PullUpEnableRegister_pui32;
   uint32*       Port_PullUpEnableRegisterS_pui32;
   uint32*       Port_PullUpEnableRegisterC_pui32;
   uint32*       Port_PullUpEnableRegisterT_pui32;

   uint32*       Port_PullDownEnableRegister_pui32;
   uint32*       Port_PullDownEnableRegisterS_pui32;
   uint32*       Port_PullDownEnableRegisterC_pui32;
   uint32*       Port_PullDownEnableRegisterT_pui32;

   uint32*       Port_InterruptEnableRegister_pui32;
   uint32*       Port_InterruptEnableRegisterS_pui32;
   uint32*       Port_InterruptEnableRegisterC_pui32;
   uint32*       Port_InterruptEnableRegisterT_pui32;

   uint32*       Port_InterruptMode0Register_pui32;
   uint32*       Port_InterruptMode0RegisterS_pui32;
   uint32*       Port_InterruptMode0RegisterC_pui32;
   uint32*       Port_InterruptMode0RegisterT_pui32;

   uint32*       Port_InterruptMode1Register_pui32;
   uint32*       Port_InterruptMode1RegisterS_pui32;
   uint32*       Port_InterruptMode1RegisterC_pui32;
   uint32*       Port_InterruptMode1RegisterT_pui32;

   uint32*       Port_GlitchFilterEnableRegister_pui32;
   uint32*       Port_GlitchFilterEnableRegisterS_pui32;
   uint32*       Port_GlitchFilterEnableRegisterC_pui32;
   uint32*       Port_GlitchFilterEnableRegisterT_pui32;

   uint32*       Port_InterruptFlagRegister_pui32;
   uint32*       Port_InterruptFlagRegisterC_pui32;

   uint32*       Port_OutputDriverCapa0Register_pui32;
   uint32*       Port_OutputDriverCapa0RegisterS_pui32;
   uint32*       Port_OutputDriverCapa0RegisterC_pui32;
   uint32*       Port_OutputDriverCapa0RegisterT_pui32;

   uint32*       Port_OutputDriverCapa1Register_pui32;
   uint32*       Port_OutputDriverCapa1RegisterS_pui32;
   uint32*       Port_OutputDriverCapa1RegisterC_pui32;
   uint32*       Port_OutputDriverCapa1RegisterT_pui32;

   uint32*       Port_LockRegister_pui32;
   uint32*       Port_LockRegisterS_pui32;
   uint32*       Port_LockRegisterC_pui32;
   uint32*       Port_LockRegisterT_pui32;

   uint32*       Port_UnlockRegister_pui32;

   uint32*       Port_AccessStatusRegister_pui32;

   uint32*       Port_ParameterRegister_pui32;

   uint32*       Port_VersionRegister_pui32;
} Port_RegisterAddresstype;


typedef struct
{
   Port_PortPinType Port_PortPin_e;
   Port_PeripheralFunctionType Port_PeripheralMode_e;
   Port_PinInOutType Port_PinInOut_e;
   Port_PinInitialStateType Port_PinInitialState_e;
   Port_PullUpTypeType Port_PullUpDown_e;
   Port_InterruptModeType Port_Interrupt_Mode_e;
   Port_GlitchFilterType Port_GlitchFilterState_e;
   Port_OutputDrivingCapabilityType Port_OutputDriver_e;
} Port_PinConfigType;



typedef struct
{
   Port_PinConfigType Pin[PORT_MAX_NUMBER_OF_PINS];
} Port_ConfigType;

void Port_Init(void);

#endif

