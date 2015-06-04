/*****************************************************************************

USB-Example: User defined USB device
V1.0.0

(c) 2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
Homepage: http://products.reworld.eu/index.htm

Main Form

Borland C++Builder 6

Created: 2011-05-30
Changed: 2011-05-30

*****************************************************************************/

/*
This example uses the "LibUSB-Win32" library and driver collection, to communicate
with the USB device.
The example shows, how to use control transfers for the own usage.
It defines two additional endpoints for bulk transfer (write and read) of data.
*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------

__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

usb_dev_handle * TFormMain::open_dev(void)
// open USB device with defined VID and PID
{
  struct usb_bus *bus;
  struct usb_device *dev;

  for (bus = usb_get_busses(); bus; bus = bus->next) {
    for (dev = bus->devices; dev; dev = dev->next) {
      if ((dev->descriptor.idVendor==MY_VID)&&(dev->descriptor.idProduct==MY_PID)) {
        return usb_open(dev);
      }
    }
  }
  return NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCreate(TObject *Sender)
{
  //  USB initializations
  dev=0;
  usb_init();         // initialize the library
  usb_find_busses();  // find all busses
  usb_find_devices(); // find all connected devices
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  ButtonCloseClick(Sender);
  CanClose=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
  //
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonOpenClick(TObject *Sender)
// open USB device
{
  dev=open_dev();
  if (dev) {
    usb_set_configuration(dev, 1);  // select 1st USB configuration
    StatusBar1->SimpleText="USB device opened";
  } else
    StatusBar1->SimpleText="opening failed";
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonVersionClick(TObject *Sender)
// user defined control transfer
{
  #define CONTROLBUFSIZE      16    // USB buffer size for control transfers
  #define USER_REQUESTTYPE    0xC3  // a user defined request type with response (means, no standard request)
  #define USER_REQUESTVERSION 0x01  // a self defined request: get version info
  int r;
  char buf[CONTROLBUFSIZE];
  AnsiString s;

  if (dev) {
    r=usb_control_msg(dev,USER_REQUESTTYPE,USER_REQUESTVERSION,0,1,(char *)(&buf),sizeof(buf),100);
    if (r>0) {
      s.SetLength(strlen(buf));
      strcpy(s.c_str(),buf);
      LabelVersion->Caption=s;
      StatusBar1->SimpleText="version info received";
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonTransferClick(TObject *Sender)
// transfer data to device and receive response
// (bulk transfer via user defined endpoints)
{
  #define BUFSIZE 32  // USB buffer size (= max. data size for one data block)
  #define EP_TODEVICE   0x01 // endpoint for data to device (OUT)
  #define EP_FROMDEVICE 0x82 // endpoint for data from device (IN)
  char buf[BUFSIZE];
  int r;
  AnsiString s;

  if (dev) {
    strcpy(buf,LabeledEdit1->Text.c_str());
    usb_claim_interface(dev, 0);  // select interface 0
    r=usb_bulk_write(dev,EP_TODEVICE,buf,sizeof(buf),100);  // output data
    if (r>0) {  // data was transmitted successfully, now wait for response
      Sleep(100);
      r=usb_bulk_read(dev,EP_FROMDEVICE,(char *)&buf,sizeof(buf),100);
      if (r>0) {  // data received from device
        s.SetLength(strlen(buf));
        strcpy(s.c_str(),buf);
        LabelData->Caption=s;
        StatusBar1->SimpleText="data sent and received";
      } else {  // error
        LabelData->Caption="(no response)";
        StatusBar1->SimpleText="no response from device";
      }
    }
    usb_release_interface(dev, 0);  // close pipe
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonCloseClick(TObject *Sender)
// close USB device
{
  if (dev) {
    usb_close(dev);
    dev=NULL;
    StatusBar1->SimpleText="USB device closed";
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonExitClick(TObject *Sender)
// exit program
{
  Close();
}
//---------------------------------------------------------------------------

