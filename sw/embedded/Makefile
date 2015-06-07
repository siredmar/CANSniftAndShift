# Universal AVR32 Makefile for firmware without operating system.
# based on Makefile from Wolfgang Wieser 07/2008.

PART = uc3c264c
HEADERS = inc/Std_Types.h

# Software includes
INC = -I/data/programme/avr32_gcc/avr32-tools/avr32/include/
INC += -I./inc/
INC += -I./src/Dio/
INC += -I./src/Port/
INC += -I./src/Asf/
INC += -I./src/Asf/ASF/avr32/drivers/flashc/
INC += -I./src/Asf/ASF/avr32/drivers/intc/
INC += -I./src/Asf/ASF/avr32/drivers/scif/
INC += -I./src/Asf/ASF/avr32/drivers/usart/
INC += -I./src/Asf/ASF/avr32/drivers/cpu/cycle_counter/
INC += -I./src/Asf/ASF/avr32/utils/
INC += -I./src/Asf/ASF/avr32/utils/header_files/
INC += -I./src/Asf/ASF/avr32/utils/preprocessor/
INC += -I./src/Asf/ASF/avr32/utils/startup/
INC += -I./src/Asf/ASF/common/services/clock/
INC += -I./src/Asf/ASF/common/services/clock/uc3c/
INC += -I./src/Asf/ASF/common/services/delay/
INC += -I./src/Asf/ASF/common/services/serial/
INC += -I./src/Asf/ASF/common/services/serial/uc3_usart/
INC += -I./src/Asf/ASF/common/utils/
INC += -I./src/Asf/ASF/common/utils/interrupt/
INC += -I./src/Asf/ASF/common/boards/
INC += -I./src/Asf/ASF/common/boards/user_board/
INC += -I./src/Asf/Config/
INC += -I./src/Asf/
 # USB HID driver 
INC += -I./src/Asf/ASF/avr32/drivers/pm/
INC += -I./src/Asf/ASF/avr32/drivers/usbc/
INC += -I./src/Asf/ASF/common/services/sleepmgr/
INC += -I./src/Asf/ASF/common/services/sleepmgr/uc3
INC += -I./src/Asf/ASF/common/services/usb/
INC += -I./src/Asf/ASF/common/services/usb/class/hid/
INC += -I./src/Asf/ASF/common/services/usb/class/hid/device/
INC += -I./src/Asf/ASF/common/services/usb/class/hid/device/generic/
INC += -I./src/Asf/ASF/common/services/usb/udc/
INC += -I./src/Asf/ASF/common/utils
INC += -I./src/Asf/ASF/common/utils/interrupt/

OutputFileName = CANSniftAndShift

CFLAGS = -g -O2 -Wall -ffunction-sections -DUDD_ENABLE $(INC)
LDFLAGS = -nostartfiles -Wl,-Map="$(OutputFileName).map" -Wl,--start-group -lm  -Wl,--end-group -Wl,--gc-sections --rodata-writable -Wl,--direct-data -mpart=uc3c264c -Wl,--relax -Wl,-e,_trampoline
 
SOURCES = src/main.c 
SOURCES += src/Port/Port.c src/Port/Port_Lcfg.c 
SOURCES += src/Dio/Dio.c src/Dio/Dio_Lcfg.c
SOURCES += src/Asf/asf.c
SOURCES += src/Asf/ASF/common/services/serial/usart_serial.c
SOURCES += src/Asf/ASF/common/services/clock/uc3c/pll.c
SOURCES += src/Asf/ASF/common/services/clock/uc3c/osc.c
SOURCES += src/Asf/ASF/common/services/clock/uc3c/sysclk.c
SOURCES += src/Asf/ASF/avr32/drivers/intc/intc.c
SOURCES += src/Asf/ASF/avr32/drivers/usart/usart.c
SOURCES += src/Asf/ASF/avr32/drivers/scif/scif_uc3c.c
SOURCES += src/Asf/ASF/avr32/drivers/flashc/flashc.c
# USB HID driver
SOURCES += src/Asf/ASF/avr32/drivers/pm/pm_uc3c.c
SOURCES += src/Asf/ASF/avr32/drivers/pm/power_clocks_lib.c
SOURCES += src/Asf/ASF/avr32/drivers/usbc/usbc_device.c
SOURCES += src/Asf/ASF/common/services/sleepmgr/uc3/sleepmgr.c
SOURCES += src/Asf/ASF/common/services/usb/class/hid/device/udi_hid.c
SOURCES += src/Asf/ASF/common/services/usb/class/hid/device/generic/udi_hid_generic.c
SOURCES += src/Asf/ASF/common/services/usb/class/hid/device/generic/udi_hid_generic_desc.c
SOURCES += src/Asf/ASF/common/services/usb/udc/udc.c

BOARD = -DBOARD=USER_BOARD
OBJECTS = $(SOURCES:.c=.o)
OBJECTS += src/Asf/ASF/avr32/drivers/intc/exception.o
OBJECTS += src/Asf/ASF/avr32/utils/startup/trampoline_uc3.o
OBJECTS += src/Asf/ASF/avr32/utils/startup/startup_uc3.o

.PHONY: all run clean program reset cont erase

all: firmware.elf
run: firmware.elf program cont

clean:
	rm -f $(OBJECTS)

firmware.elf: asm $(OBJECTS) 
	avr32-gcc -o firmware.elf $(OBJECTS) $(LDFLAGS)

program: firmware.elf
	avr32program -c USB program -finternal@0x80000000 -v -e --run -R -cint firmware.elf
	

reset:
	avr32program -c USB reset -r
cont:
	avr32program -c USB run
erase:
	avr32program -c USB erase -finternal@0x80000000
chiperase:
	avr32program -c USB chiperase

.c.o:
	avr32-gcc -c $(CFLAGS) $(BOARD) -mpart=$(PART) -o $*.o $<
asm:
	avr32-gcc -x assembler-with-cpp -c -mpart=$(PART) -mrelax -D__AT32UC3C264C__ -DBOARD=USER_BOARD -DUDD_ENABLE $(INC) -MD -MP -MF src/Asf/ASF/avr32/drivers/intc/exception.d -MT src/Asf/ASF/avr32/drivers/intc/exception.d -MT src/Asf/ASF/avr32/drivers/intc/exception.o -Wa,-g   -o src/Asf/ASF/avr32/drivers/intc/exception.o src/Asf/ASF/avr32/drivers/intc/exception.S
	avr32-gcc -x assembler-with-cpp -c -mpart=$(PART) -mrelax -D__AT32UC3C264C__ -DBOARD=USER_BOARD -DUDD_ENABLE $(INC) -MD -MP -MF src/Asf/ASF/avr32/utils/startup/trampoline_uc3.d -MT src/Asf/ASF/avr32/utils/startup/trampoline_uc3.d -MT src/Asf/ASF/avr32/utils/startup/trampoline_uc3.o -Wa,-g   -o src/Asf/ASF/avr32/utils/startup/trampoline_uc3.o src/Asf/ASF/avr32/utils/startup/trampoline_uc3.S
	avr32-gcc -x assembler-with-cpp -c -mpart=$(PART) -mrelax -D__AT32UC3C264C__ -DBOARD=USER_BOARD -DUDD_ENABLE $(INC) -MD -MP -MF src/Asf/ASF/avr32/utils/startup/startup_uc3.d -MT src/Asf/ASF/avr32/utils/startup/startup_uc3.d -MT src/Asf/ASF/avr32/utils/startup/startup_uc3.o -Wa,-g   -o src/Asf/ASF/avr32/utils/startup/startup_uc3.o src/Asf/ASF/avr32/utils/startup/startup_uc3.S
	 
$(OBJECTS): $(HEADERS)





















