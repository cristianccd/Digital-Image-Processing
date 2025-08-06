//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Logicas.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
        Original.Graficar(Image);
        Auxiliar.Graficar(Image1);
        Previa.Graficar(Image2);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::GroupBox1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        if(!((TImage*)Sender)->Picture->Bitmap->Empty)
        {
                Edit1->Text = X;
                Edit2->Text = Y;
                BYTE* LinePtr;
                LinePtr=(BYTE*)((TImage*)Sender)->Picture->Bitmap->ScanLine[Y];
                Edit3->Text =LinePtr[X];
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Abrir1Click(TObject *Sender)
{
        OpenDialog1->Filter = "Bmp files (*.bmp)|*.BMP";
        if (OpenDialog1->Execute())
        {
                AnsiString nombre_archivo=OpenDialog1->FileName;
                Auxiliar.Leer(nombre_archivo);
        }
        Auxiliar.Graficar(Image1);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BitBtn3Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BitBtn1Click(TObject *Sender)
{
        Original=Previa;
        Form1->mtrMiImagen=Original;
        Form1->mtrMiImagen.Graficar(Form1->imgMiImagen);
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SUMA1Click(TObject *Sender)
{
        StaticText1->Visible=true;
        StaticText5->Visible=true;
        for(int f=0;f<256;f++)
                for(int c=0;c<256;c++)
                        Previa.buffer(f,c)=Original.buffer(f,c)+Auxiliar.buffer(f,c);
        Previa.Graficar(Image2);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::R1Click(TObject *Sender)
{
        StaticText2->Visible=true;
        StaticText5->Visible=true;
         for(int f=0;f<256;f++)
                for(int c=0;c<256;c++)
                        Previa.buffer(f,c)=Original.buffer(f,c)+Auxiliar.buffer(f,c);
         Previa.Graficar(Image2);

}
//---------------------------------------------------------------------------

void __fastcall TForm3::AND1Click(TObject *Sender)
{
        StaticText3->Visible=true;
        StaticText5->Visible=true;
        for(int f=0;f<256;f++)
                for(int c=0;c<256;c++)
                        Previa.buffer(f,c)=Original.buffer(f,c)&Auxiliar.buffer(f,c);
        Previa.Graficar(Image2);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::OR1Click(TObject *Sender)
{
        StaticText4->Visible=true;
        StaticText5->Visible=true;
        for(int f=0;f<256;f++)
                for(int c=0;c<256;c++)
                        Previa.buffer(f,c)=Original.buffer(f,c)|Auxiliar.buffer(f,c);
        Previa.Graficar(Image2);

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Salir1Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        if(!((TImage*)Sender)->Picture->Bitmap->Empty)
        {
                Edit1->Text = X;
                Edit2->Text = Y;
                BYTE* LinePtr;
                LinePtr=(BYTE*)((TImage*)Sender)->Picture->Bitmap->ScanLine[Y];
                char Titulo[10];
                sprintf(Titulo,"%d",LinePtr[X]);
                Edit3->Text = Titulo;
        }                
}
//---------------------------------------------------------------------------


