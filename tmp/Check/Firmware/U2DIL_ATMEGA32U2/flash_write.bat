rem ----------------------------------------------------------
rem flash check firmware for U2DIL-ATMEGA32U2
rem using "Atmel batchisp" (part of "Atmel FLIP" installation)
rem after flashing UxDIL_Check utility can be used
rem (c) 2011 Reusch Elektronik
rem ----------------------------------------------------------

batchisp -cmdfile "flash_write.txt"
