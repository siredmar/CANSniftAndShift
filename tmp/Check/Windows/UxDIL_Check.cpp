/****************************************************************************

UxDIL Device Check Utility

Main Program

(c) 2010-2011 Reusch Elektronik, Dipl.-Ing. (FH) Rainer Reusch
http://products.reworld.eu/index.htm

Borland C++Builder 6

****************************************************************************/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UnitMain.cpp", FormMain);
USEFORM("UnitAbout.cpp", FormAbout);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->Title = "UxDIL Check";
     Application->CreateForm(__classid(TFormMain), &FormMain);
     Application->CreateForm(__classid(TFormAbout), &FormAbout);
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
