/*****************************************************************************

USB-Example: Raw Human Interface Device with Atmel HID-DLL
V1.1.0

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
Homepage: http://products.reworld.eu/index.htm

Main routine

Borland C++Builder 6

Created: 2011-03-14
Changed: 2011-03-14

*****************************************************************************/

// This project uses the Atmel HID DLL "AtUsbHid.dll".

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UnitMain.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->CreateForm(__classid(TForm1), &Form1);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  catch (...)
  {
     try
     {
       throw Exception("");
     }
     catch (Exception &exception)
     {
       Application->ShowException(&exception);
     }
  }
  return 0;
}
//---------------------------------------------------------------------------
