//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Ayuda.h"
#include "Matriz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Matriz Imagen;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        AnsiString Linea1,Linea2,Linea3,Linea4,Fecha;
        Linea1=L"Compilado   por  última   vez  el 14/9/2011";
        Fecha=DateToStr(Date());
        Linea2=L"Programa creado por Cristian D'Alessandro";
        Linea3=L"en  base  a  las guias propuestas para la";
        Linea4=L"materia PDI del año 2011.";
        Label1->Caption=Linea1;//+Fecha;
        Label2->Caption=Linea2;
        Label3->Caption=Linea3;
        Label4->Caption=Linea4;




}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
        MediaPlayer1->Stop();
        Form2->Close();

}
//---------------------------------------------------------------------------

