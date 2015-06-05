#include "Std_Types.h"
#include "Platform_MCU.h"
#include "Dio.h"
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
   Dio_ChannelType Port_PortPin_e;
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

