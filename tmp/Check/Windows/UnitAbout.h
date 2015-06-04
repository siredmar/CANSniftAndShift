/****************************************************************************

UxDIL Device Check Utility

About Dialogue

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
http://products.reworld.eu/index.htm

Borland C++Builder 6

****************************************************************************/

//---------------------------------------------------------------------------

#ifndef UnitAboutH
#define UnitAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "VersionInfo.hpp"
#include "JDUrlLabel.hpp"
//---------------------------------------------------------------------------
class TFormAbout : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
  TBitBtn *BitBtnClose;
  TImage *Image1;
  TPanel *Panel1;
  TLabel *Label1;
  TLabel *LabelVersion;
  TVersionInfo *VersionInfo1;
  TLabel *LabelCopyright;
  TJDUrlLabel *JDUrlLabel1;
  TPanel *Panel2;
  TLabel *Label2;
  TLabel *Label3;
  void __fastcall FormCreate(TObject *Sender);
private:	// Anwender-Deklarationen
public:		// Anwender-Deklarationen
  __fastcall TFormAbout(TComponent* Owner);
  void __fastcall Execute();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAbout *FormAbout;
//---------------------------------------------------------------------------
#endif
