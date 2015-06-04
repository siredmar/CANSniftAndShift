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

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitRawHID.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
  TButton *ButtonOpen;
  TButton *ButtonData;
  TButton *ButtonClose;
  TListBox *ListBox1;
  TButton *ButtonExit;
  TStatusBar *StatusBar1;
  TButton *ButtonSize;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
  void __fastcall ButtonOpenClick(TObject *Sender);
  void __fastcall ButtonDataClick(TObject *Sender);
  void __fastcall ButtonCloseClick(TObject *Sender);
  void __fastcall ButtonExitClick(TObject *Sender);
  void __fastcall ButtonSizeClick(TObject *Sender);
private:	// Anwender-Deklarationen
  TRawHID *RawHID;  // Interface class to HID DLL
public:		// Anwender-Deklarationen
  __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
