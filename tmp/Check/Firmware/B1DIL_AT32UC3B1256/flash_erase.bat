rem ----------------------------------------------------------
rem erase flash of B1DIL-AT32UC3B1256
rem using "Atmel batchisp" (part of "Atmel FLIP" installation)
rem bootloader will not be erased
rem (c) 2011 Reusch Elektronik
rem ----------------------------------------------------------

batchisp -cmdfile "flash_erase.txt"
