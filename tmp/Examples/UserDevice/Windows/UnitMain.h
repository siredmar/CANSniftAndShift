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

//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "usb.h"

#define MY_VID 0x0001 // Vendor ID of the device
#define MY_PID 0x0001 // Product ID of the device
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
  TStatusBar *StatusBar1;
  TButton *ButtonOpen;
  TButton *ButtonVersion;
  TLabeledEdit *LabeledEdit1;
  TLabel *Label1;
  TLabel *LabelData;
  TButton *ButtonClose;
  TLabel *LabelVersion;
  TButton *ButtonExit;
  TButton *ButtonTransfer;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall ButtonOpenClick(TObject *Sender);
  void __fastcall ButtonVersionClick(TObject *Sender);
  void __fastcall ButtonCloseClick(TObject *Sender);
  void __fastcall ButtonExitClick(TObject *Sender);
  void __fastcall ButtonTransferClick(TObject *Sender);
private:	// Anwender-Deklarationen
  struct usb_dev_handle *dev;
  usb_dev_handle *open_dev(void);
public:		// Anwender-Deklarationen
  __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
