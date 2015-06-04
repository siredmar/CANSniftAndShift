/*****************************************************************************

USB-Example: Raw Human Interface Device with Atmel HID-DLL
V1.1.0

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
Homepage: http://products.reworld.eu/index.htm

Interfacing HID DLL

Borland C++Builder 6

Created: 2011-03-14
Changed: 2011-03-14

*****************************************************************************/

// This project uses the Atmel HID DLL "AtUsbHid.dll".

// Note: The control transfer DLL functions getFeatureReportLength() and
// setFeature() are not supported by the demo firmware.

//---------------------------------------------------------------------------

#pragma hdrstop

#include "AtUsbHid.h"
#include "UnitRawHID.h"

#pragma package(smart_init)

//---------------------------------------------------------------------------

__fastcall TRawHID::TRawHID(void)
// constructor
{
  // Initialization
  FOpened=false;
  hLib=NULL;
  FErrorCode=RAWHID_ERROR_OK;
  hLib=LoadLibrary(AT_USB_HID_DLL);
  if (hLib!=NULL) {
    if (!loadFuncPointers(hLib)) {
      FreeLibrary(hLib);
      hLib=NULL;
      FErrorCode=RAWHID_ERROR_LIBLOAD;
    }
  } else FErrorCode=RAWHID_ERROR_LIBOPEN;
}
//---------------------------------------------------------------------------

__fastcall TRawHID::~TRawHID(void)
// destructor
{
  Close();  // close USB device (if opened)
}
//---------------------------------------------------------------------------

bool TRawHID::Open()
// open the device
// returns: false = can't be opened (not connected)
//          true  = success
// for detailed error information see ErrorCode
{
  if (!FOpened)
    if (hLib!=NULL)
      if (DYNCALL(findHidDevice)(AVR_USB_VENDOR,AVR_USB_PRODUCT)) FOpened=true;
  return FOpened;
}
//---------------------------------------------------------------------------

void TRawHID::Close(void)
// close opened device
{
  if (FOpened) {
    DYNCALL(closeDevice)();
    FOpened=false;
  }
}
//---------------------------------------------------------------------------

int TRawHID::GetOutDataSize()
// get raw data size
{
  if (FOpened) return (DYNCALL(getOutputReportLength)());
  else return 0;
}
//---------------------------------------------------------------------------

int TRawHID::GetInDataSize()
// get raw in data size
{
  if (FOpened) return (DYNCALL(getInputReportLength)());
  else return 0;
}
//---------------------------------------------------------------------------

bool TRawHID::WriteData(TBuffer Buffer)
// write raw data over OUT endpoint to device
{
  if (FOpened) return (DYNCALL(writeData)(Buffer));
  else return false;
}
//---------------------------------------------------------------------------

bool TRawHID::ReadData(TBuffer *Buffer)
// read raw data over IN endpoint from device
{
  if (FOpened) return (DYNCALL(readData)(*Buffer));
  else return false;
}
//---------------------------------------------------------------------------
