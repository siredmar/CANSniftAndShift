*******************************************************************************

UxDIL Software Collection

Templates, examples and applications for U2DIL, U4DIL and U6DIL AVR-USB modules

(c) 2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
Homepage: http://products.reworld.eu

Release number: Beta 2
Release date:   2011-08-02

*******************************************************************************

LICENCE AGREEMENT:
THIS SOFTWARE COLLECTION IS PROTECTED BY COPYRIGHT LAW.  IT IS NO FREEWARE! THIS COLLECTION CAN BE USED BY CUSTOMERS OF REUSCH ELEKTRONIK FOR THERE OWN PURPOSES WITHOUT ANY LICENCE FEE. THIS APPLIES THE  PRIVATE  AS WELL AS COMMERCIAL USAGE. IT IS STRICTLY PROHIBITED TO COPY, DISTRIBUTE, OR SELL THE COMPONENT COLLECTION.
THE PUBLICATION OF THE SOURCES IS MADE "AS IS". THERE IS NO WARRANTY OR LIABILITY GIVEN FOR ADHERENCE, ASSURED PROPERTIES, OR DAMAGES WHICH MIGHT BE CAUSED BY THE USE OF THIS SOFTWARE. USAGE IS ON YOUR OWN RISK!

-------------------------------------------------------------------------------
1. Introduction
-------------------------------------------------------------------------------

This is a beta release of the software collection. It doesn't contain any documentation.
Feel free for use and have fun! No support!

-------------------------------------------------------------------------------
2. Used Development Tools
-------------------------------------------------------------------------------

Firmware:
AVR-Studio 4.18 SP3

Windows:
Borland C++Builder 6

The source files should be suitable (with small adaptions) for newer releases and other development tools.

-------------------------------------------------------------------------------
3. Contents
-------------------------------------------------------------------------------

index.htm: The entry file for detailed information about this demo package.

Template: Firmware templates
- UserDevice: User defined USB device (requires drivers, e.g. "LibUSB-Win32")
- Serial: Communication device class (CDC), communication via virtual COM port
- RawHID: User defined Human interface device (HID)

Examples: Usable examples with Windows software
- UserDevice: User defined USB device (uses drivers "LibUSB-Win32")
- Serial: Communication device class (CDC), communication via virtual COM port, terminal program
- RawHID: User defined Human interface device (HID), uses Atmel DLL.

Drivers_Win: "LibUSB-Win32" driver package
for user defined devices

Check: Firmware und Windows tool to check the UxDIL (and B1DIL) modules
- Firmware for all module types
- Windows application
You will find the check tool as a easy to use installation package as a standalone download (see homepage).

*** end of file ***
