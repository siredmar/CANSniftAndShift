rem ----------------------------------------------------------
rem erase flash of U6DIL-AT90USB1286
rem using "Atmel batchisp" (part of "Atmel FLIP" installation)
rem bootloader will not be erased
rem (c) 2011 Reusch Elektronik
rem ----------------------------------------------------------

batchisp -cmdfile "flash_erase.txt"