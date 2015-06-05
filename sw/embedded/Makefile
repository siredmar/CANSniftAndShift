# Universal AVR32 Makefile for firmware without operating system.
# Wolfgang Wieser 07/2008.

PART = uc3c264c
INC = -I./inc
INC += -I./src/Dio
INC += -I./src/Port
INC += -I./src/Asf/
INC += -I./src/Asf/ASF/avr32/drivers/flashc/
INC += -I./src/Asf/ASF/avr32/drivers/intc/
INC += -I./src/Asf/ASF/avr32/drivers/scif/
INC += -I./src/Asf/ASF/avr32/drivers/usart/
INC += -I./src/Asf/ASF/avr32/utils/
INC += -I./src/Asf/ASF/avr32/utils/header_files/
INC += -I./src/Asf/ASF/avr32/utils/preprocessor/
INC += -I./src/Asf/ASF/avr32/utils/startup/
INC += -I./src/Asf/ASF/common/services/clock/
INC += -I./src/Asf/ASF/common/services/clock/uc3c/
INC += -I./src/Asf/ASF/common/services/serial/
INC += -I./src/Asf/ASF/common/services/serial/uc3_usart/
INC += -I./src/Asf/ASF/common/utils/
INC += -I./src/Asf/ASF/common/utils/interrupt/
INC += -I./src/Asf/ASF/common/boards/
INC += -I./src/Asf/ASF/common/boards/user_board/
INC += -I./src/Asf/Config/


CFLAGS = -g -O2 -Wall -ffunction-sections $(INC)
LDFLAGS = -g -Wl,--gc-sections
HEADERS = inc/Std_Types.h 
SOURCES = src/main.c 
SOURCES += src/Port/Port.c src/Port/Port_Lcfg.c 
SOURCES += src/Dio/Dio.c src/Dio/Dio_Lcfg.c
SOURCES += src/Asf/ASF/common/services/serial/usart_serial.c
SOURCES += src/Asf/ASF/common/services/clock/uc3c/pll.c
SOURCES += src/Asf/ASF/common/services/clock/uc3c/osc.c
SOURCES += src/Asf/ASF/common/services/clock/uc3c/sysclk.c
SOURCES += src/Asf/ASF/avr32/drivers/intc/intc.c
SOURCES += src/Asf/ASF/avr32/drivers/usart/usart.c
SOURCES += src/Asf/ASF/avr32/drivers/scif/scif_uc3c.c
SOURCES += src/Asf/ASF/avr32/drivers/flashc/flashc.c

BOARD = -DBOARD=USER_BOARD
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all run clean program reset cont erase

all: firmware.elf
run: firmware.elf program

clean:
	rm -f $(OBJECTS)

firmware.elf: $(OBJECTS)
	avr32-gcc $(LDFLAGS) -mpart=$(PART) -o firmware.elf $(OBJECTS)

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

$(OBJECTS): $(HEADERS)
