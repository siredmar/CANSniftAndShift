/*****************************************************************************

USB-Example: Raw Human Interface Device with Atmel HID-DLL
V1.1.0

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
Homepage: http://products.reworld.eu/index.htm

Form

Borland C++Builder 6

Created: 2011-03-14
Changed: 2011-03-14

*****************************************************************************/

// This project uses the Atmel HID DLL "AtUsbHid.dll".

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
// constructor
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
// Initialization
{
  RawHID = new TRawHID(); // create interface class
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  delete RawHID;  // free interface class
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonOpenClick(TObject *Sender)
// button "Open Device" pressed
{
  ListBox1->Clear();
  if (RawHID->Open())
    ListBox1->Items->Add("opened (error code: "+IntToStr(RawHID->ErrorCode)+")");
  else
    ListBox1->Items->Add("opening failed (error code: "+IntToStr(RawHID->ErrorCode)+")");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSizeClick(TObject *Sender)
// get size of transferable raw data 
{
  int o, i;

  o=RawHID->GetOutDataSize();
  ListBox1->Items->Add("output data size: "+IntToStr(o));
  i=RawHID->GetInDataSize();
  ListBox1->Items->Add("input data size:  "+IntToStr(i));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDataClick(TObject *Sender)
// button "Data Transfer" pressed
{
  TBuffer iodata;
  AnsiString s;
  __int8 i;

  for (i=0; i<HID_BUFSIZE; i++) iodata[i]=i+'A';  // prepare transmitt data
  if (RawHID->WriteData(iodata)) {
    ListBox1->Items->Add("data written:");
    s.SetLength(HID_BUFSIZE);
    strcpy(s.c_str(),iodata);
    ListBox1->Items->Add(s);
    Sleep(20);  // wait a little bit
      if (RawHID->ReadData(&iodata)) {
        ListBox1->Items->Add("data read:");
        s.SetLength(HID_BUFSIZE);
        strcpy(s.c_str(),iodata);
        ListBox1->Items->Add(s);
      }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCloseClick(TObject *Sender)
// button "Close Device" pressed
{
  RawHID->Close();
  ListBox1->Items->Add("closed");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------


