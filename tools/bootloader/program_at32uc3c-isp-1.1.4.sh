#!/bin/sh

# This shell script programs the ISP (flash array), the ISP configuration words
# (User page) and the general-purpose fuse bits.

# Copyright (c) 2009 Atmel Corporation. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# 3. The name of Atmel may not be used to endorse or promote products derived
# from this software without specific prior written permission.
#
# 4. This software may only be redistributed and used in connection with an Atmel
# AVR product.
#
# THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
# EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
#


echo
echo Performing a JTAG Chip Erase command.
avr32program chiperase
sleep 2
echo
echo Programming MCU memory from \`at32uc3c-isp-H.hex\'.
avr32-objcopy -I ihex -O binary at32uc3c-isp-1.1.4.hex at32uc3c-isp-1.1.4.bin
avr32program program -finternal@0x80000000,512Kb -cint -e -v -O0x80000000 -Fbin at32uc3c-isp-1.1.4.bin
rm -f at32uc3c-isp-1.1.4.bin
sleep 2

echo
echo Programming ISP configuration words \(default for UC3_C2_Xplained i.e. Word2 == 0x929E7504 and Word1 == 0xE11EFFD7\)
avr32program program -finternal@0x80000000 -cint -e -v -O0x808001F8 -Fbin at32uc3c-isp_cfg-1.1.4.dat
sleep 2

echo
echo Programming general-purpose fuse bits.
avr32program writefuses -finternal@0x80000000 gp=0xF877FFFF
sleep 2

echo Reading general-purpose fuse bits.
avr32program readfuses -finternal@0x80000000 gp
sleep 2

echo
echo Resetting MCU.
avr32program reset
