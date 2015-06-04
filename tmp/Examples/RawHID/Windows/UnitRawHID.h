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

#ifndef UnitRawHIDH
#define UnitRawHIDH
//---------------------------------------------------------------------------

#include <system.hpp>
#include <vcl.h>
//---------------------------------------------------------------------------
// USB information
#define AVR_USB_VENDOR          0x0001
#define AVR_USB_PRODUCT         0x0002
//#define AVR_USB_VENDOR          0x16C0
//#define AVR_USB_PRODUCT         0x0480
#define HID_BUFSIZE             64      // buffer size for HID data exchange
//---------------------------------------------------------------------------
// device open error codes
#define RAWHID_ERROR_OK          0 // open ok
#define RAWHID_ERROR_LIBOPEN     1 // AtUsbHid.dll open failed
#define RAWHID_ERROR_LIBLOAD     2 // AtUsbHid.dll load functions failed
//---------------------------------------------------------------------------

typedef __int8 TBuffer[HID_BUFSIZE];

class TRawHID
{
private:
  HINSTANCE hLib;
  bool FOpened;  // true, if device opened
  int FErrorCode;  // error code at Open call
public:
  __property bool Opened = { read=FOpened };       // true, if device opened
  __property int ErrorCode = { read=FErrorCode };  // error code of Open routine
  __fastcall TRawHID::TRawHID(void);               // constructor
  __fastcall TRawHID::~TRawHID(void);              // destructor
  bool Open();                                     // connect to device
  void Close(void);                                // disconnect from device
  int GetOutDataSize();                            // get raw out data size
  int GetInDataSize();                             // get raw in data size
  bool WriteData(TBuffer Buffer);
  bool ReadData(TBuffer *Buffer);
};

#endif

