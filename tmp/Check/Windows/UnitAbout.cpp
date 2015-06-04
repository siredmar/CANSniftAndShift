/****************************************************************************

UxDIL Device Check Utility

About Dialogue

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
http://products.reworld.eu/index.htm

Borland C++Builder 6

****************************************************************************/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VersionInfo"
#pragma link "JDUrlLabel"
#pragma resource "*.dfm"
TFormAbout *FormAbout;
//---------------------------------------------------------------------------
__fastcall TFormAbout::TFormAbout(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAbout::FormCreate(TObject *Sender)
{
  LabelVersion->Caption="Version "+VersionInfo1->FileVersion;
}
//---------------------------------------------------------------------------
void __fastcall TFormAbout::Execute()
{
  ShowModal();
}
//---------------------------------------------------------------------------
