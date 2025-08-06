//Procesamiento Digital de Imágenes
//Universidad Favaloro
//Bioing. Sebastián Graf

//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <StrUtils.hpp>
#pragma hdrstop
#include "Main.h"
#include "Ayuda.h"
#include "Logicas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Ayuda"
#pragma link "Logicas"
#pragma resource "*.dfm"

typedef struct {
  TLogPalette lpal;
  TPaletteEntry dummy[256];
} LogPal;

TForm1 *Form1;
int X,Y,R,Rint;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        DoubleBuffered=true;
        mtrMiImagen.Graficar(imgMiImagen);
        Shape1->Visible=false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::datosImg(TObject *Sender, TShiftState Shift,
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

void __fastcall TForm1::BarrasHoriz1Click(TObject *Sender)
{
        AnsiString Texto = "20";
        bool SI = InputQuery("Ingresar Ancho de las barras", "Ancho[pxl]:", Texto);
        if(!SI) return;
        int ancho = atoi(Texto.c_str());
        mtrMiImagen.BarrasH(ancho);
        mtrMiImagen.Graficar(imgMiImagen);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BarrasVert1Click(TObject *Sender)
{

        AnsiString Texto = "20";
        bool SI = InputQuery("Ingresar Ancho de las barras", "Ancho[pxl]:", Texto);
        if(!SI) return;
        int ancho = atoi(Texto.c_str());
        mtrMiImagen.BarrasV(ancho);
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Circunf1Click(TObject *Sender)
{
        AnsiString Texto = "20";
        bool SI = InputQuery("Ingresar radio de la circunf.", "Ancho[pxl]:", Texto);
        if(!SI) return;
        int radio = atoi(Texto.c_str());
        mtrMiImagen.Circunf(radio);
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cuadrado1Click(TObject *Sender)
{
        AnsiString Texto = "20";
        bool SI = InputQuery("Ingresar el lado", "Ancho[pxl]:", Texto);
        if(!SI) return;
        int radio = atoi(Texto.c_str());
        mtrMiImagen.Cuadrado(radio);
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cruz1Click(TObject *Sender)
{
        AnsiString Texto = "20";
        bool SI = InputQuery("Ingresar Ancho de las barras", "Ancho[pxl]:", Texto);
        if(!SI) return;
        int ancho = atoi(Texto.c_str());
        mtrMiImagen.Cruz(ancho);
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Contraste1Click(TObject *Sender)
{
        AnsiString Texto = "20";
        bool SI = InputQuery("Ingresar el ancho del cuadrado", "Ancho[pxl]:", Texto);
        if(!SI) return;
        int ladocuadr = atoi(Texto.c_str());
        AnsiString Texto1 = "10";
        bool SI1 = InputQuery("Ingresar la intensidad del exterior", "Intensidad[0-255]:", Texto1);
        if(!SI1) return;
        int fuerte = atoi(Texto1.c_str());
        AnsiString Texto2 = "200";
        bool SI2 = InputQuery("Ingresar la intensidad del interior", "Intensidad[0-255]:", Texto2);
        if(!SI2) return;
        int claro = atoi(Texto2.c_str());
        mtrMiImagen.VerContras(fuerte, claro, ladocuadr);
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IzqDer1Click(TObject *Sender)
{
        mtrMiImagen.IzqDer();
        AUX=mtrMiImagen;
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DerIzq1Click(TObject *Sender)
{
        mtrMiImagen.DerIzq();
        AUX=mtrMiImagen;
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown1Click(TObject *Sender)
{
        mtrMiImagen.UpDown();
        AUX=mtrMiImagen;
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DownUp1Click(TObject *Sender)
{
        mtrMiImagen.DownUp();
        AUX=mtrMiImagen;
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IzqDer2Click(TObject *Sender)
{

        AnsiString Texto = "1";
        bool SI = InputQuery("Ingresar la frecuencia deseada", "Frecuencia[Hz]:", Texto);
        if(!SI) return;
        int freq = atoi(Texto.c_str());
        mtrMiImagen.SIzqDer(freq);
        AUX=mtrMiImagen;
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DerIzq2Click(TObject *Sender)
{
        AnsiString Texto = "1";
        bool SI = InputQuery("Ingresar la frecuencia deseada", "Frecuencia[Hz]:", Texto);
        if(!SI) return;
        int freq = atoi(Texto.c_str());
        mtrMiImagen.SDerIzq(freq);
        AUX=mtrMiImagen;
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown2Click(TObject *Sender)
{
        AnsiString Texto = "1";
        bool SI = InputQuery("Ingresar la frecuencia deseada", "Frecuencia[Hz]:", Texto);
        if(!SI) return;
        int freq = atoi(Texto.c_str());
        mtrMiImagen.SUpDown(freq);
        AUX=mtrMiImagen;
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DownUp2Click(TObject *Sender)
{
        AnsiString Texto = "1";
        bool SI = InputQuery("Ingresar la frecuencia deseada", "Frecuencia[Hz]:", Texto);
        if(!SI) return;
        int freq = atoi(Texto.c_str());
        mtrMiImagen.SDownUp(freq);
        AUX=mtrMiImagen;
        mtrMiImagen.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IzqDer3Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AUX.IIzqDer();
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DerIzq3Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AUX.IDerIzq();
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown3Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AUX.IUpDown();
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DownUp3Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AUX.IDownUp();
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Negativo1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AUX.Negative();
        mtrMiImagen=AUX;
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
        Edit4->Text=ScrollBar1->Position;
        Edit5->Text=ScrollBar2->Position-100;
        AUX=mtrMiImagen;
        AUX.briycontr(ScrollBar1->Position,ScrollBar2->Position);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScrollBar2Change(TObject *Sender)
{
        Edit4->Text=ScrollBar1->Position;
        Edit5->Text=ScrollBar2->Position-100;
        AUX=mtrMiImagen;
        AUX.briycontr(ScrollBar1->Position,ScrollBar2->Position);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RangoDinamico1Click(TObject *Sender)
{
        AUX=mtrMiImagen;

        AnsiString Texto = "45";
        bool SI = InputQuery("Ingresar la tasa de conpresion.", "Compresion[]:", Texto);
        if(!SI) return;
        int c = atoi(Texto.c_str());

        AUX.dinrange(c);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Binarizacion1Click(TObject *Sender)
{
        AUX=mtrMiImagen;

        AnsiString Texto = "45";
        bool SI = InputQuery("Ingresar el umbral.", "Umbral[0-255]:", Texto);
        if(!SI) return;
        int m = atoi(Texto.c_str());

        AUX.binarizacion(m);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Bits1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "8";
        bool SI = InputQuery("Ingresar la cantidad de bits deseados", "Bits:", Texto);
        if(!SI) return;
        int cant = atoi(Texto.c_str());
        AUX.NivGris(cant);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
        mtrMiImagen=AUX;
        Series1->Clear();
        mtrMiImagen.Graficar(imgMiImagen);
        int min=-1, max=-1, mediana=-1,acum=0;
        for(int i=0;i<256;i++)
        {
                Series1->AddXY(i,mtrMiImagen.Histograma(i));
                if(mtrMiImagen.Histograma(i)>0&&min==-1)
                {
                        min=i;
                }
                if(mtrMiImagen.Histograma(255-i)>0&&max==-1)
                {
                        max=255-i;
                }
                acum=acum+mtrMiImagen.Histograma(i);
        }
        mediana=acum/255;
        Edit11->Text=max;
        Edit12->Text=min;
        Edit13->Text=mediana;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
        if( MessageBox(NULL, "Desea Salir?", "Salir",MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Abrir1Click(TObject *Sender)
{

OpenDialog1->Filter = "Bmp files (*.bmp)|*.BMP";
if (OpenDialog1->Execute())
        {
        AnsiString nombre_archivo=OpenDialog1->FileName;
        mtrMiImagen.Leer(nombre_archivo);
        }
        mtrMiImagen.Graficar(imgMiImagen);
        AUX=mtrMiImagen;
        Series1->Clear();
        mtrMiImagen.Graficar(imgMiImagen);
        int min=-1, max=-1, mediana=-1,acum=0;
        for(int i=0;i<256;i++)
        {
                Series1->AddXY(i,mtrMiImagen.Histograma(i));
                if(mtrMiImagen.Histograma(i)>0&&min==-1)
                {
                        min=i;
                }
                if(mtrMiImagen.Histograma(255-i)>0&&max==-1)
                {
                        max=255-i;
                }
                acum=acum+mtrMiImagen.Histograma(i);
        }
        mediana=acum/255;
        Edit11->Text=max;
        Edit12->Text=min;
        Edit13->Text=mediana;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AbrirTRUECOLOR1Click(TObject *Sender)
{
        OpenDialog1->Filter = "Bmp files (*.bmp)|*.BMP";
        if (OpenDialog1->Execute())
        {
                AnsiString nombre_archivo=OpenDialog1->FileName;
                mtrMiImagen.Leer(nombre_archivo);
        }
        mtrMiImagen.GraficarColor(imgMiImagen);
        AUX=mtrMiImagen;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Guardar1Click(TObject *Sender)
{
SaveDialog1->Filter = "Bmp files (*.bmp)|*.BMP";
if (SaveDialog1->Execute())
        {
        imgMiImagen->Picture->Bitmap->SaveToFile(SaveDialog1->FileName);
        }                
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Salir1Click(TObject *Sender)
{
        if( MessageBox(NULL, "Desea Salir?", "Salir",MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ConfirmarImagen1Click(TObject *Sender)
{
        mtrMiImagen=AUX;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Restaurar1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AUX.Graficar(imgMiImagen);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ecualizacion1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AUX.Ecualizar();
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaltPepper1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "50";
        bool SI = InputQuery("Ingresar el porcentaje de ruido", "Ruido %", Texto);
        if(!SI) return;
        int n=AnsiReplaceText(Texto,".",",").ToInt();
        AUX.SaltPepper(100-n);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MedianaMovil1Click(TObject *Sender)
{
        mtrMiImagen.Mediana(AUX);
        AUX.Graficar(imgMiImagen);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Zoom1Click(TObject *Sender)
{
        AnsiString Texto = "1.5";
        bool SI = InputQuery("Ingresar el zoom", "Zoom:", Texto);
        if(!SI) return;
        double fe=AnsiReplaceText(Texto,".",",").ToDouble();
        mtrMiImagen.Escalar(AUX,fe,128,128);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Bilineal1Click(TObject *Sender)
{

        AnsiString Texto = "1.5";
        bool SI = InputQuery("Ingresar el zoom", "Zoom:", Texto);
        if(!SI) return;
        double fe=AnsiReplaceText(Texto,",",".").ToDouble();
        mtrMiImagen.Bilinear(AUX,fe,128,128);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::UpDown4Changing(TObject *Sender, bool &AllowChange)
{
        Edit6->Text=UpDown4->Position;
        int angle,x=128,y=128;
        angle=Edit6->Text.ToInt();
        mtrMiImagen.Rotar(AUX,angle,x,y);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Change(TObject *Sender)
{
        UpDown4->Position=Edit6->Text.ToInt();
        int angle,x=128,y=128;
        angle=Edit6->Text.ToInt();
        mtrMiImagen.Rotar(AUX,angle,x,y);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rotar1Click(TObject *Sender)
{
        AnsiString Texto = "45";
        bool SI = InputQuery("Ingresar el angulo", "Grados:", Texto);
        if(!SI) return;
        int ang=Texto.ToInt();
        mtrMiImagen.Rotar(AUX,ang,128,128);
        mtrMiImagen.Bilinear(mtrMiImagen,1,128,128);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Trasladar1Click(TObject *Sender)
{
        AnsiString Texto = "128";
        bool SI = InputQuery("Ingrese la coordenada X:", "Grados:", Texto);
        AnsiString Texto1 = "128";
        bool SI1 = InputQuery("Ingrese la coordenada Y:", "Grados:", Texto1);
        if(!SI) return;
        if(!SI1) return;
        int X=Texto.ToInt();
        int Y=Texto1.ToInt();
        mtrMiImagen.Trasladar(AUX,X,Y);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PasaAltos1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "1";
        bool SI = InputQuery("Cantidad de filtrados:", "Cantidad:", Texto);
        if(!SI) return;
        double coef=AnsiReplaceText(Texto,".",",").ToDouble();
        for(int i=0;i<coef;i++)
                mtrMiImagen.PAltos(AUX);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PasaBajosClick(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "5";
        bool SI = InputQuery("Cantidad de filtrados:", "Cantidad:", Texto);
        if(!SI) return;
        double coef=AnsiReplaceText(Texto,".",",").ToDouble();
        for(int i=0;i<coef;i++)
                AUX.PBajos(AUX);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HighBoost1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "2";
        bool SI = InputQuery("Ingrese el coeficiente deseado:", "Coeficiente:", Texto);
        if(!SI) return;
        double coef=AnsiReplaceText(Texto,".",",").ToDouble();
        mtrMiImagen.HighBoost(AUX,coef);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Sobel1Click(TObject *Sender)
{
        mtrMiImagen.Sobel(AUX);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FFT1Click(TObject *Sender)
{
        mtrMiImagen.applyFFT(AUX,false);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::IFFT1Click(TObject *Sender)
{
        mtrMiImagen.applyFFT(AUX,true);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Laplaciano1Click(TObject *Sender)
{
        mtrMiImagen.Laplaciano(AUX);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Prewitt1Click(TObject *Sender)
{
        mtrMiImagen.Prewitt(AUX);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NotchClick(TObject *Sender)
{
        mtrMiImagen.FNotch(AUX,X,Y,R);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown5Changing(TObject *Sender, bool &AllowChange)
{
        Edit7->Text=UpDown5->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7Change(TObject *Sender)
{
        Shape1->Visible=false;
        Shape1->Width=Edit7->Text.ToInt();
        R=Edit7->Text.ToInt();
        Shape1->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::imgMiImagenClick(TObject *Sender)
{
        R=Edit7->Text.ToInt();
        X=Edit1->Text.ToInt();
        Y=Edit2->Text.ToInt();
        Edit9->Text=X;
        Edit10->Text=Y;
        Shape1->Width=R;
        Shape1->Left=X+imgMiImagen->Left-R/2;
        Shape1->Top=Y-imgMiImagen->Top+3;
        Shape1->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PasaAltos2Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        Shape1->Visible=false;
        Shape2->Visible=false;
        R=Edit7->Text.ToInt();
        Rint=Edit8->Text.ToInt();
        Shape1->Width=R;
        Shape2->Width=Rint;
        Shape1->Left=128+imgMiImagen->Left-R/2;
        Shape1->Top=128-imgMiImagen->Top+3;
        Shape2->Left=128+imgMiImagen->Left-Rint/2;
        Shape2->Top=128-imgMiImagen->Top+3;


        Shape1->Visible=true;
        Shape2->Visible=true;
        if( MessageBox(NULL, "Le parece bien?", "OK?",MB_YESNO|MB_ICONQUESTION) == IDNO)
        {
                Shape1->Visible=false;
                Shape2->Visible=false;
                return;
        }
        Shape1->Visible=false;
        Shape2->Visible=false;
        mtrMiImagen.FPAltos(AUX,R,Rint);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::UpDown6Click(TObject *Sender, TUDBtnType Button)
{
        Edit8->Text=UpDown6->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8Change(TObject *Sender)
{
        Rint=Edit8->Text.ToInt();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PasaBajos1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        Shape1->Visible=false;
        Shape2->Visible=false;
        R=Edit7->Text.ToInt();
        Rint=Edit8->Text.ToInt();
        Shape1->Width=R;
        Shape2->Width=Rint;
        Shape1->Left=128+imgMiImagen->Left-R/2;
        Shape1->Top=128-imgMiImagen->Top+3;
        Shape2->Left=128+imgMiImagen->Left-Rint/2;
        Shape2->Top=128-imgMiImagen->Top+3;
        Shape1->Visible=true;
        Shape2->Visible=true;
        if( MessageBox(NULL, "Le parece bien?", "OK?",MB_YESNO|MB_ICONQUESTION) == IDNO)
	{
                Shape1->Visible=false;
                Shape2->Visible=false;
                return;
        }
        Shape1->Visible=false;
        Shape2->Visible=false;
        mtrMiImagen.FPBajos(AUX,R,Rint);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Puntos1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "100";
        bool SI = InputQuery("Ingrese el umbral deseado:", "Umbral:", Texto);
        if(!SI) return;
        double T=AnsiReplaceText(Texto,".",",").ToDouble();
        mtrMiImagen.DetectPtos(AUX,T);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Horizontal1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "100";
        bool SI = InputQuery("Ingrese el umbral deseado:", "Umbral:", Texto);
        if(!SI) return;
        double T=AnsiReplaceText(Texto,".",",").ToDouble();
        double Mask[9]={-1,-1,-1,2,2,2,-1,-1,-1};
        mtrMiImagen.DetectLineas(AUX,T,Mask);
        AUX.Graficar(imgMiImagen);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Vertica1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "100";
        bool SI = InputQuery("Ingrese el umbral deseado:", "Umbral:", Texto);
        if(!SI) return;
        double T=AnsiReplaceText(Texto,".",",").ToDouble();
        double Mask[9]={-1,2,-1,-1,2,-1,-1,2,-1};
        mtrMiImagen.DetectLineas(AUX,T,Mask);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N451Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "100";
        bool SI = InputQuery("Ingrese el umbral deseado:", "Umbral:", Texto);
        if(!SI) return;
        double T=AnsiReplaceText(Texto,".",",").ToDouble();
        double Mask[9]={-1,-1,2,-1,2,-1,2,-1,-1};
        mtrMiImagen.DetectLineas(AUX,T,Mask);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N452Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "100";
        bool SI = InputQuery("Ingrese el umbral deseado:", "Umbral:", Texto);
        if(!SI) return;
        double T=AnsiReplaceText(Texto,".",",").ToDouble();
        double Mask[9]={2,-1,-1,-1,2,-1,-1,-1,2};
        mtrMiImagen.DetectLineas(AUX,T,Mask);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UmbralFijo1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "100";
        bool SI = InputQuery("Ingrese el umbral deseado:", "Umbral:", Texto);
        if(!SI) return;
        double T=AnsiReplaceText(Texto,".",",").ToDouble();
        mtrMiImagen.UmbralFijo(AUX,T);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Isodata1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        double T=mtrMiImagen.Isodata(AUX);
        mtrMiImagen.UmbralFijo(AUX,T);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LadyBug1Click(TObject *Sender)
{
        mtrMiImagen.LadyBug(AUX,Edit9->Text.ToInt(),Edit10->Text.ToInt());
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SlicingX1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        AnsiString Texto = "200";
        AnsiString Texto1 = "100";
        bool SI = InputQuery("Ingrese el umbral superior deseado:", "Umbral:", Texto);
        if(!SI) return;
        bool SI1 = InputQuery("Ingrese el umbral inferior deseado:", "Umbral:", Texto1);
        if(!SI1) return;
        double sup=AnsiReplaceText(Texto,".",",").ToDouble();
        double inf=AnsiReplaceText(Texto1,".",",").ToDouble();
        mtrMiImagen.Slicing(AUX,sup,inf);
        AUX.Graficar(imgMiImagen);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContrastStrechingX1Click(TObject *Sender)
{
        AUX=mtrMiImagen;
        mtrMiImagen.ContrastStrech(AUX);
        AUX.Graficar(imgMiImagen);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Logicas2Click(TObject *Sender)
{
        Form3->Show();
        Form3->Original=mtrMiImagen;
        Form3->Original.Graficar(Form3->Image);
}
//---------------------------------------------------------------------------

