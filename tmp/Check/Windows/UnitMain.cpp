/****************************************************************************

UxDIL Device Check Utility

Main Window

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
http://products.reworld.eu/index.htm

Borland C++Builder 6

****************************************************************************/

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
  //
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
// initializations
{
  connected=false;
  allowed=true;
  dev = NULL;
/** changed with V1.2
  usb_init();         // initialize the library
  usb_find_busses();  // find all busses
  usb_find_devices(); // find all connected devices
**/
  // assigment of the radiobuttons to arrays
  // U2DIL
  U2_Ports[0]=U2_PC2;
  U2_Ports[1]=U2_PD0;
  U2_Ports[2]=U2_PD1;
  U2_Ports[3]=U2_PD2;
  U2_Ports[4]=U2_PD3;
  U2_Ports[5]=U2_PD4;
  U2_Ports[6]=U2_PD5;
  U2_Ports[7]=U2_PD6;
  U2_Ports[8]=U2_PD7;
  U2_Ports[9]=U2_PB0;
  U2_Ports[10]=U2_PB1;
  U2_Ports[11]=U2_PB2;
  U2_Ports[12]=U2_PB3;
  U2_Ports[13]=U2_PB4;
  U2_Ports[14]=U2_PB5;
  U2_Ports[15]=U2_PB6;
  U2_Ports[16]=U2_PB7;
  U2_Ports[17]=U2_PC7;
  U2_Ports[18]=U2_PC6;
  U2_Ports[19]=U2_PC5;
  U2_Ports[20]=U2_PC4;
  U2_Index=0;
  U2_Ports[U2_Index]->Checked=true;
  // U4DIL
  U4_Ports[0]=U4_PE6;
  U4_Ports[1]=U4_PB0;
  U4_Ports[2]=U4_PB1;
  U4_Ports[3]=U4_PB2;
  U4_Ports[4]=U4_PB3;
  U4_Ports[5]=U4_PB7;
  U4_Ports[6]=U4_PD0;
  U4_Ports[7]=U4_PD1;
  U4_Ports[8]=U4_PD2;
  U4_Ports[9]=U4_PD3;
  U4_Ports[10]=U4_PD5;
  U4_Ports[11]=U4_PD4;
  U4_Ports[12]=U4_PD6;
  U4_Ports[13]=U4_PD7;
  U4_Ports[14]=U4_PB4;
  U4_Ports[15]=U4_PB5;
  U4_Ports[16]=U4_PB6;
  U4_Ports[17]=U4_PC6;
  U4_Ports[18]=U4_PC7;
  U4_Ports[19]=U4_PE2;
  U4_Ports[20]=U4_PF7;
  U4_Ports[21]=U4_PF6;
  U4_Ports[22]=U4_PF5;
  U4_Ports[23]=U4_PF4;
  U4_Ports[24]=U4_PF1;
  U4_Ports[25]=U4_PF0;
  U4_Index=0;
  U4_Ports[U4_Index]->Checked=true;
  // U6DIL
  U6_Ports[0]=U6_PE6;
  U6_Ports[1]=U6_PE7;
  U6_Ports[2]=U6_PE3;
  U6_Ports[3]=U6_PB0;
  U6_Ports[4]=U6_PB1;
  U6_Ports[5]=U6_PB2;
  U6_Ports[6]=U6_PB3;
  U6_Ports[7]=U6_PB4;
  U6_Ports[8]=U6_PB5;
  U6_Ports[9]=U6_PB6;
  U6_Ports[10]=U6_PB7;
  U6_Ports[11]=U6_PE4;
  U6_Ports[12]=U6_PE5;
  U6_Ports[13]=U6_PD0;
  U6_Ports[14]=U6_PD1;
  U6_Ports[15]=U6_PD2;
  U6_Ports[16]=U6_PD3;
  U6_Ports[17]=U6_PD4;
  U6_Ports[18]=U6_PD5;
  U6_Ports[19]=U6_PD6;
  U6_Ports[20]=U6_PD7;
  U6_Ports[21]=U6_PE0;
  U6_Ports[22]=U6_PE1;
  U6_Ports[23]=U6_PC0;
  U6_Ports[24]=U6_PC1;
  U6_Ports[25]=U6_PC2;
  U6_Ports[26]=U6_PC3;
  U6_Ports[27]=U6_PC4;
  U6_Ports[28]=U6_PC5;
  U6_Ports[29]=U6_PC6;
  U6_Ports[30]=U6_PC7;
  U6_Ports[31]=U6_PE2;
  U6_Ports[32]=U6_PA7;
  U6_Ports[33]=U6_PA6;
  U6_Ports[34]=U6_PA5;
  U6_Ports[35]=U6_PA4;
  U6_Ports[36]=U6_PA3;
  U6_Ports[37]=U6_PA2;
  U6_Ports[38]=U6_PA1;
  U6_Ports[39]=U6_PA0;
  U6_Ports[40]=U6_PF7;
  U6_Ports[41]=U6_PF6;
  U6_Ports[42]=U6_PF5;
  U6_Ports[43]=U6_PF4;
  U6_Ports[44]=U6_PF3;
  U6_Ports[45]=U6_PF2;
  U6_Ports[46]=U6_PF1;
  U6_Ports[47]=U6_PF0;
  U6_Index=0;
  U6_Ports[U6_Index]->Checked=true;
  // B1DIL
  B1_Ports[0]=B1_PA00;
  B1_Ports[1]=B1_PA01;
  B1_Ports[2]=B1_PA02;
  B1_Ports[3]=B1_PA03;
  B1_Ports[4]=B1_PA04;
  B1_Ports[5]=B1_PA05;
  B1_Ports[6]=B1_PA06;
  B1_Ports[7]=B1_PA07;
  B1_Ports[8]=B1_PA08;
  B1_Ports[9]=B1_PA09;
  B1_Ports[10]=B1_PA10;
  B1_Ports[11]=B1_PA11;
  B1_Ports[12]=B1_PA12;
  B1_Ports[13]=B1_PA13;
  B1_Ports[14]=B1_PA14;
  B1_Ports[15]=B1_PA15;
  B1_Ports[16]=B1_PA16;
  B1_Ports[17]=B1_PA17;
  B1_Ports[18]=B1_PA20;
  B1_Ports[19]=B1_PA21;
  B1_Ports[20]=B1_PA22;
  B1_Ports[21]=B1_PA23;
  B1_Ports[22]=B1_PA24;
  B1_Ports[23]=B1_PA25;
  B1_Ports[24]=B1_PA26;
  B1_Ports[25]=B1_PA27;
  B1_Index=0;
  B1_Ports[B1_Index]->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCloseQuery(TObject *Sender, bool &CanClose)
// application is on the way to be terminated
{
  BitBtnDisconnectClick(Sender);  // disconnect USB device
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
  //
}
//---------------------------------------------------------------------------
MESSAGE void __fastcall TFormMain::WMDeviceChange(TMessage &Message)
// handle "device change" message
// (an USB device is connected or unplugged)
{
  if (connected) {  // device opened -> check, if still plugged
    if (!TestCommand()) {  // device no longer connected
      MessageBeep(0);
      BitBtnDisconnectClick(NULL);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::UpdateDlg()
// update dialogue contents
{
  const AnsiString s[2] = {"not connected", "connected"};

  BitBtnConnect->Enabled=!connected;
  BitBtnDisconnect->Enabled=connected;
  StatusBar1->SimpleText=s[connected];
  allowed=!connected;
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
void __fastcall TFormMain::BitBtnConnectClick(TObject *Sender)
// USB connect to module
{
  if (!connected) {
    /** changed with V1.2 **/
    usb_init();         // initialize the library
    usb_find_busses();  // find all busses
    usb_find_devices(); // find all connected devices
    /***/
    dev=open_dev();
    connected=(dev!=NULL);
    if (connected)
      usb_set_configuration(dev, 1);  // select 1st USB configuration
  }
  // choose viewing depending on present module
  switch (DeviceInfo()) {
    case 2: // U2DIL
      TabbedNotebook1->PageIndex=0;
      break;
    case 4: // U4DIL
      TabbedNotebook1->PageIndex=1;
      break;
    case 6: // U6DIL
      TabbedNotebook1->PageIndex=2;
      break;
    case 0x11: // B1DIL
      TabbedNotebook1->PageIndex=3;
      break;
  }
  UpdateDlg();
  TestCommand();
}
//---------------------------------------------------------------------------
int __fastcall TFormMain::DeviceInfo()
// get device information
// returns 0 (no device), 2 (U2DIL), 4 (U4DIL) or 6 (U6DIL)
{
  unsigned __int8 b[3];
  int r, Result;
  AnsiString s;
  struct {
    __int8 Type;
    char   MCU[15];
  } info;

  if (!connected) {
    LabelMCU->Caption="(none)";
    return 0;
  }
  Result=0;
  // output data
  if (dev) {
    b[0]='?'; // request module information
    usb_claim_interface(dev, 0);  // select interface 0
    r=usb_bulk_write(dev, 1, b, sizeof(b), 100);  // output data
    if (r>0) {
      Sleep(100);
      r=usb_bulk_read(dev,0x82,(char *)&info,sizeof(info),100);
      if (r>0) {
        s.SetLength(strlen(info.MCU));
        strcpy(s.c_str(),info.MCU);
        LabelMCU->Caption=s;
        Result=info.Type;
      } else LabelMCU->Caption="(unknown)";
    }
    usb_release_interface(dev, 0);
  }
  return Result;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::BitBtnNextClick(TObject *Sender)
// go to next output
{
  switch (TabbedNotebook1->PageIndex) {
    case 0: // U2DIL module
      U2_Index++;
      if (U2_Index>=NUM_U2_PORTS) U2_Index=0;
      U2_Ports[U2_Index]->Checked=true;
      break;
    case 1: // U4DIL module
      U4_Index++;
      if (U4_Index>=NUM_U4_PORTS) U4_Index=0;
      U4_Ports[U4_Index]->Checked=true;
      break;
    case 2: // U6DIL module
      U6_Index++;
      if (U6_Index>=NUM_U6_PORTS) U6_Index=0;
      U6_Ports[U6_Index]->Checked=true;
      break;
    case 3: // B1DIL module
      B1_Index++;
      if (B1_Index>=NUM_B1_PORTS) B1_Index=0;
      B1_Ports[B1_Index]->Checked=true;
      break;
  }
  TestCommand();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::BitBtnPreviousClick(TObject *Sender)
// go to previous output
{
  switch (TabbedNotebook1->PageIndex) {
    case 0: // U2DIL module
      U2_Index--;
      if (U2_Index<0) U2_Index=NUM_U2_PORTS-1;
      U2_Ports[U2_Index]->Checked=true;
      break;
    case 1: // U4DIL module
      U4_Index--;
      if (U4_Index<0) U4_Index=NUM_U4_PORTS-1;
      U4_Ports[U4_Index]->Checked=true;
      break;
    case 2: // U6DIL module
      U6_Index--;
      if (U6_Index<0) U6_Index=NUM_U6_PORTS-1;
      U6_Ports[U6_Index]->Checked=true;
      break;
    case 3: // B1DIL module
      B1_Index--;
      if (B1_Index<0) B1_Index=NUM_B1_PORTS-1;
      B1_Ports[B1_Index]->Checked=true;
      break;
  }
  TestCommand();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::BitBtnDisconnectClick(TObject *Sender)
// USB disconnect
{
  if (connected) {
    usb_close(dev);
    dev=NULL;
    connected=false;
  }
  DeviceInfo();
  UpdateDlg();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::TabbedNotebook1Change(TObject *Sender,
      int NewTab, bool &AllowChange)
// select module type (U2DIL, U4DIL, U6DIL or B1DIL)
{
  AllowChange=allowed;
}
//---------------------------------------------------------------------------
bool __fastcall TFormMain::TestCommand()
// USB output of test command (port, pin, level)
{
  unsigned __int8 b[3];
  int r;
  char c[4];

  if (!connected) return false;
  switch (TabbedNotebook1->PageIndex) {
    case 0:
      b[0]=U2_Ports[U2_Index]->Name.c_str()[4];
      b[1]=StrToInt(U2_Ports[U2_Index]->Name.c_str()[5]);
      break;
    case 1:
      b[0]=U4_Ports[U4_Index]->Name.c_str()[4];
      b[1]=StrToInt(U4_Ports[U4_Index]->Name.c_str()[5]);
      break;
    case 2:
      b[0]=U6_Ports[U6_Index]->Name.c_str()[4];
      b[1]=StrToInt(U6_Ports[U6_Index]->Name.c_str()[5]);
      break;
    case 3:
      b[0]=B1_Ports[B1_Index]->Name.c_str()[4];
      c[0]=B1_Ports[B1_Index]->Name.c_str()[5];
      c[1]=B1_Ports[B1_Index]->Name.c_str()[6];
      c[2]=0;
      b[1]=StrToInt(c);
      break;
  }
  b[2]=RadioGroupLevel->ItemIndex;  // level
  // output data
  if (dev) {
    usb_claim_interface(dev, 0);  // select interface 0
    r=usb_bulk_write(dev, 1, b, sizeof(b), 100);  // output data
    usb_release_interface(dev, 0);
    StatusBar1->SimpleText="Sent Bytes: "+IntToHex(b[0],2)+"h, "+IntToHex(b[1],2)+"h, "+IntToHex(b[2],2)+"h  Result: "+IntToStr(r);
    return (r>0);
  } else return false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::U2_PC2Click(TObject *Sender)
// U2DIL
{
  for (int i=0; i<NUM_U2_PORTS; i++)
    if (U2_Ports[i]->Checked) U2_Index=i;
  TestCommand();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::U4_PE6Click(TObject *Sender)
// U4DIL
{
  for (int i=0; i<NUM_U4_PORTS; i++)
    if (U4_Ports[i]->Checked) U4_Index=i;
  TestCommand();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::U6_PE6Click(TObject *Sender)
// U6DIL
{
  for (int i=0; i<NUM_U6_PORTS; i++)
    if (U6_Ports[i]->Checked) U6_Index=i;
  TestCommand();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::B1_PA00Click(TObject *Sender)
// B1DIL
{
  for (int i=0; i<NUM_B1_PORTS; i++)
    if (B1_Ports[i]->Checked) B1_Index=i;
  TestCommand();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::RadioGroupLevelClick(TObject *Sender)
{
  TestCommand();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::BitBtnAboutClick(TObject *Sender)
// view "About" dialogue
{
  FormAbout->Execute();
}
//---------------------------------------------------------------------------


