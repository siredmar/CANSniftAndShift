/****************************************************************************

UxDIL Device Check Utility

Main Window

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
http://products.reworld.eu/index.htm

Borland C++Builder 6

****************************************************************************/

//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <TabNotBk.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "usb.h"
#include "UnitAbout.h"

#define MY_VID 0x20A0
#define MY_PID 0x411B

#define NUM_U2_PORTS  21
#define NUM_U4_PORTS  26
#define NUM_U6_PORTS  48
#define NUM_B1_PORTS  26

//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
  TStatusBar *StatusBar1;
  TBitBtn *BitBtnExit;
  TTabbedNotebook *TabbedNotebook1;
  TRadioButton *U4_PE6;
  TLabel *Label1;
  TLabel *Label2;
  TLabel *Label3;
  TLabel *Label4;
  TRadioButton *U4_PB0;
  TRadioButton *U4_PB1;
  TRadioButton *U4_PB2;
  TRadioButton *U4_PB3;
  TRadioButton *U4_PB7;
  TRadioButton *U4_PD0;
  TRadioButton *U4_PD1;
  TLabel *Label5;
  TLabel *Label6;
  TLabel *Label7;
  TLabel *Label8;
  TLabel *Label9;
  TRadioButton *U4_PD2;
  TRadioButton *U4_PD3;
  TRadioButton *U4_PD5;
  TImage *Image1;
  TRadioButton *U4_PD4;
  TLabel *Label10;
  TRadioButton *U4_PD6;
  TRadioButton *U4_PD7;
  TRadioButton *U4_PB4;
  TRadioButton *U4_PB5;
  TRadioButton *U4_PB6;
  TRadioButton *U4_PC6;
  TRadioButton *U4_PC7;
  TRadioButton *U4_PF7;
  TRadioButton *U4_PF6;
  TRadioButton *U4_PF5;
  TRadioButton *U4_PF4;
  TRadioButton *U4_PF1;
  TRadioButton *U4_PF0;
  TLabel *Label11;
  TLabel *Label12;
  TLabel *Label13;
  TLabel *Label14;
  TLabel *Label16;
  TLabel *Label17;
  TRadioButton *U2_PC2;
  TRadioButton *U2_PD0;
  TRadioButton *U2_PD1;
  TRadioButton *U2_PD2;
  TRadioButton *U2_PD3;
  TRadioButton *U2_PD4;
  TRadioButton *U2_PD5;
  TRadioButton *U2_PD6;
  TRadioButton *U2_PB0;
  TRadioButton *U2_PB1;
  TRadioButton *U2_PB2;
  TImage *Image2;
  TRadioButton *U2_PB3;
  TRadioButton *U2_PB4;
  TRadioButton *U2_PB5;
  TRadioButton *U2_PB6;
  TRadioButton *U2_PB7;
  TRadioButton *U2_PC7;
  TRadioButton *U2_PC6;
  TLabel *Label19;
  TRadioButton *U2_PC5;
  TRadioButton *U2_PC4;
  TLabel *Label20;
  TLabel *Label21;
  TLabel *Label22;
  TLabel *Label23;
  TBitBtn *BitBtnConnect;
  TBitBtn *BitBtnNext;
  TBitBtn *BitBtnPrevious;
  TBitBtn *BitBtnDisconnect;
  TRadioGroup *RadioGroupLevel;
  TBitBtn *BitBtnAbout;
  TRadioButton *U6_PE6;
  TRadioButton *U6_PE7;
  TLabel *Label25;
  TLabel *Label26;
  TLabel *Label27;
  TLabel *Label28;
  TLabel *Label29;
  TLabel *Label30;
  TRadioButton *U6_PE3;
  TRadioButton *U6_PB0;
  TRadioButton *U6_PB1;
  TRadioButton *U6_PB2;
  TRadioButton *U6_PB3;
  TRadioButton *U6_PB4;
  TRadioButton *U6_PB5;
  TRadioButton *U6_PB6;
  TRadioButton *U6_PB7;
  TRadioButton *U6_PE4;
  TRadioButton *U6_PE5;
  TLabel *Label31;
  TLabel *Label32;
  TLabel *Label33;
  TLabel *Label34;
  TLabel *Label35;
  TRadioButton *U6_PD0;
  TRadioButton *U6_PD1;
  TRadioButton *U6_PD2;
  TRadioButton *U6_PD3;
  TRadioButton *U6_PD4;
  TRadioButton *U6_PD5;
  TRadioButton *U6_PD6;
  TRadioButton *U6_PD7;
  TImage *Image3;
  TRadioButton *U6_PE0;
  TRadioButton *U6_PE1;
  TRadioButton *U6_PC0;
  TRadioButton *U6_PC1;
  TRadioButton *U6_PC2;
  TRadioButton *U6_PC3;
  TRadioButton *U6_PC4;
  TRadioButton *U6_PC5;
  TRadioButton *U6_PC6;
  TRadioButton *U6_PC7;
  TRadioButton *U6_PA7;
  TRadioButton *U6_PA6;
  TRadioButton *U6_PA5;
  TRadioButton *U6_PA4;
  TRadioButton *U6_PA3;
  TRadioButton *U6_PA2;
  TRadioButton *U6_PA1;
  TRadioButton *U6_PA0;
  TLabel *Label36;
  TLabel *Label38;
  TRadioButton *U6_PF7;
  TRadioButton *U6_PF6;
  TRadioButton *U6_PF5;
  TRadioButton *U6_PF4;
  TRadioButton *U6_PF3;
  TRadioButton *U6_PF2;
  TRadioButton *U6_PF1;
  TRadioButton *U6_PF0;
  TLabel *Label39;
  TLabel *Label40;
  TLabel *Label41;
  TRadioButton *U6_PE2;
  TLabel *Label24;
  TLabel *LabelMCU;
  TRadioButton *U2_PD7;
  TRadioButton *U4_PE2;
  TLabel *Label15;
  TImage *Image4;
  TLabel *Label18;
  TLabel *Label37;
  TLabel *Label42;
  TLabel *Label43;
  TLabel *Label44;
  TLabel *Label45;
  TLabel *Label46;
  TLabel *Label47;
  TLabel *Label48;
  TLabel *Label49;
  TLabel *Label50;
  TLabel *Label51;
  TRadioButton *B1_PA00;
  TRadioButton *B1_PA01;
  TRadioButton *B1_PA02;
  TRadioButton *B1_PA03;
  TRadioButton *B1_PA04;
  TRadioButton *B1_PA05;
  TRadioButton *B1_PA06;
  TRadioButton *B1_PA07;
  TRadioButton *B1_PA08;
  TRadioButton *B1_PA09;
  TRadioButton *B1_PA10;
  TRadioButton *B1_PA11;
  TRadioButton *B1_PA12;
  TRadioButton *B1_PA13;
  TRadioButton *B1_PA14;
  TRadioButton *B1_PA15;
  TRadioButton *B1_PA16;
  TRadioButton *B1_PA17;
  TRadioButton *B1_PA20;
  TRadioButton *B1_PA21;
  TRadioButton *B1_PA22;
  TRadioButton *B1_PA23;
  TRadioButton *B1_PA24;
  TRadioButton *B1_PA25;
  TRadioButton *B1_PA26;
  TRadioButton *B1_PA27;
  TLabel *Label52;
  TLabel *Label53;
  TLabel *Label54;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall BitBtnConnectClick(TObject *Sender);
  void __fastcall BitBtnNextClick(TObject *Sender);
  void __fastcall BitBtnPreviousClick(TObject *Sender);
  void __fastcall BitBtnDisconnectClick(TObject *Sender);
  void __fastcall TabbedNotebook1Change(TObject *Sender, int NewTab,
          bool &AllowChange);
  void __fastcall U2_PC2Click(TObject *Sender);
  void __fastcall RadioGroupLevelClick(TObject *Sender);
  void __fastcall BitBtnAboutClick(TObject *Sender);
  void __fastcall U4_PE6Click(TObject *Sender);
  void __fastcall U6_PE6Click(TObject *Sender);
  void __fastcall B1_PA00Click(TObject *Sender);
private:	// Anwender-Deklarationen
  TRadioButton *U2_Ports[NUM_U2_PORTS];
  TRadioButton *U4_Ports[NUM_U4_PORTS];
  TRadioButton *U6_Ports[NUM_U6_PORTS];
  TRadioButton *B1_Ports[NUM_B1_PORTS];
  int U2_Index;
  int U4_Index;
  int U6_Index;
  int B1_Index;
  bool connected;
  bool allowed;
  struct usb_dev_handle *dev;
  usb_dev_handle *open_dev(void);
  int __fastcall DeviceInfo();
  void __fastcall UpdateDlg();
  bool __fastcall TestCommand();
  MESSAGE void __fastcall WMDeviceChange(TMessage &Message);
protected:
  BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(WM_DEVICECHANGE, TMessage, WMDeviceChange)
  END_MESSAGE_MAP(TForm)
public:		// Anwender-Deklarationen
  __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
