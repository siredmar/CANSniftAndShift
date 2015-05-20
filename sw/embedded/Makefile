# Universal AVR32 Makefile for firmware without operating system.
# Wolfgang Wieser 07/2008.

PART = uc3c264c
CFLAGS = -g -O2 -Wall -ffunction-sections
LDFLAGS = -g -Wl,--gc-sections

HEADERS = inc/Std_Types.h 
SOURCES = src/main.c src/Port/Port.c src/Port/Port_Lcfg.c src/Dio/Dio.c src/Dio/Dio_Lcfg.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all run clean program reset cont erase

all: firmware.elf
run: firmware.elf program

clean:
	rm -f $(OBJECTS)

firmware.elf: $(OBJECTS)
	avr32-gcc $(LDFLAGS) -mpart=$(PART) -o firmware.elf $(OBJECTS)

program: firmware.elf
	avr32program -c USB -pjtagicemkii program -finternal@0x80000000 -v -e --run -R -cint firmware.elf

reset:
	avr32program -c USB -pjtagicemkii reset -r
cont:
	avr32program -c USB -pjtagicemkii run
erase:
	avr32program -c USB -pjtagicemkii erase -finternal@0x80000000
chiperase:
	avr32program -c USB -pjtagicemkii chiperase

.c.o:
	avr32-gcc -c $(CFLAGS) -mpart=$(PART) -o $*.o $<

$(OBJECTS): $(HEADERS)
