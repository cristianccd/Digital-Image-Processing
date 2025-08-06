//Procesamiento Digital de Imágenes
//Universidad Favaloro
//Bioing. Sebastián Graf

//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include "matriz.h"
#include <Menus.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *imgMiImagen;
        TOpenDialog *OpenDialog1;
        TGroupBox *GroupBox1;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit3;
        TLabel *Label4;
        TSaveDialog *SaveDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *Formas1;
        TMenuItem *BarrasHoriz1;
        TMenuItem *BarrasVert1;
        TMenuItem *Circunf1;
        TMenuItem *Cuadrado1;
        TMenuItem *Cruz1;
        TMenuItem *Contraste1;
        TMenuItem *Senoidal1;
        TMenuItem *IzqDer1;
        TMenuItem *DerIzq1;
        TMenuItem *UpDown1;
        TMenuItem *DownUp1;
        TMenuItem *Senoidal2;
        TMenuItem *IzqDer2;
        TMenuItem *DerIzq2;
        TMenuItem *UpDown2;
        TMenuItem *DownUp2;
        TMenuItem *Iluminacion1;
        TMenuItem *IzqDer3;
        TMenuItem *DerIzq3;
        TMenuItem *UpDown3;
        TMenuItem *DownUp3;
        TMenuItem *Logicas1;
        TMenuItem *Negativo1;
        TScrollBar *ScrollBar1;
        TScrollBar *ScrollBar2;
        TLabel *Label5;
        TLabel *Label6;
        TMenuItem *RangoDinamico1;
        TMenuItem *Binarizacion1;
        TChart *Chart1;
        TBarSeries *Series1;
        TMenuItem *Bits1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TEdit *Edit4;
        TEdit *Edit5;
        TMenuItem *Archivo1;
        TMenuItem *Abrir1;
        TMenuItem *Guardar1;
        TMenuItem *ConfirmarImagen1;
        TMenuItem *Restaurar1;
        TMenuItem *Salir1;
        TMenuItem *AbrirTRUECOLOR1;
        TMenuItem *Ecualizacion1;
        TMenuItem *Mascaras1;
        TMenuItem *PasaBajos;
        TMenuItem *SaltPepper1;
        TMenuItem *MedianaMovil1;
        TMenuItem *Ver1;
        TMenuItem *Zoom1;
        TMenuItem *Bilineal1;
        TMenuItem *Rotar1;
        TGroupBox *GroupBox3;
        TUpDown *UpDown4;
        TEdit *Edit6;
        TMenuItem *Trasladar1;
        TMenuItem *PasaAltos1;
        TMenuItem *HighBoost1;
        TMenuItem *Filtros1;
        TMenuItem *Sobel1;
        TMenuItem *Transformaciones1;
        TMenuItem *FFT1;
        TMenuItem *IFFT1;
        TMenuItem *Laplaciano1;
        TMenuItem *Prewitt1;
        TMenuItem *FiltrosFrecuenciales1;
        TMenuItem *Notch;
        TGroupBox *GroupBox2;
        TUpDown *UpDown5;
        TEdit *Edit7;
        TShape *Shape1;
        TMenuItem *PasaAltos2;
        TMenuItem *PasaBajos1;
        TShape *Shape2;
        TGroupBox *GroupBox4;
        TUpDown *UpDown6;
        TEdit *Edit8;
        TMenuItem *Deteccion1;
        TMenuItem *Puntos1;
        TMenuItem *Lineas1;
        TMenuItem *Horizontal1;
        TMenuItem *Vertica1;
        TMenuItem *N451;
        TMenuItem *N452;
        TMenuItem *UmbralFijo1;
        TMenuItem *Isodata1;
        TMenuItem *LadyBug1;
        TGroupBox *GroupBox5;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *Edit9;
        TEdit *Edit10;
        TMenuItem *Formas2;
        TMenuItem *Degrade1;
        TMenuItem *SlicingX1;
        TGroupBox *GroupBox6;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TEdit *Edit11;
        TEdit *Edit12;
        TEdit *Edit13;
        TMenuItem *ContrastStrechingX1;
        TMenuItem *Geometricas1;
        TMenuItem *Filtrado1;
        TMenuItem *TP81;
        TMenuItem *Segmentacion1;
        TMenuItem *Logicas2;
        void __fastcall datosImg(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall BarrasHoriz1Click(TObject *Sender);
        void __fastcall BarrasVert1Click(TObject *Sender);
        void __fastcall Circunf1Click(TObject *Sender);
        void __fastcall Cuadrado1Click(TObject *Sender);
        void __fastcall Cruz1Click(TObject *Sender);
        void __fastcall Contraste1Click(TObject *Sender);
        void __fastcall IzqDer1Click(TObject *Sender);
        void __fastcall DerIzq1Click(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender);
        void __fastcall DownUp1Click(TObject *Sender);
        void __fastcall IzqDer2Click(TObject *Sender);
        void __fastcall DerIzq2Click(TObject *Sender);
        void __fastcall UpDown2Click(TObject *Sender);
        void __fastcall DownUp2Click(TObject *Sender);
        void __fastcall IzqDer3Click(TObject *Sender);
        void __fastcall DerIzq3Click(TObject *Sender);
        void __fastcall UpDown3Click(TObject *Sender);
        void __fastcall DownUp3Click(TObject *Sender);
        void __fastcall Negativo1Click(TObject *Sender);
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall ScrollBar2Change(TObject *Sender);
        void __fastcall RangoDinamico1Click(TObject *Sender);
        void __fastcall Binarizacion1Click(TObject *Sender);
        void __fastcall Bits1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall AbrirTRUECOLOR1Click(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall ConfirmarImagen1Click(TObject *Sender);
        void __fastcall Restaurar1Click(TObject *Sender);
        void __fastcall Ecualizacion1Click(TObject *Sender);
        void __fastcall SaltPepper1Click(TObject *Sender);
        void __fastcall MedianaMovil1Click(TObject *Sender);
        void __fastcall Zoom1Click(TObject *Sender);
        void __fastcall Bilineal1Click(TObject *Sender);
        void __fastcall UpDown4Changing(TObject *Sender,
          bool &AllowChange);
        void __fastcall Edit6Change(TObject *Sender);
        void __fastcall Rotar1Click(TObject *Sender);
        void __fastcall Trasladar1Click(TObject *Sender);
        void __fastcall PasaAltos1Click(TObject *Sender);
        void __fastcall PasaBajosClick(TObject *Sender);
        void __fastcall HighBoost1Click(TObject *Sender);
        void __fastcall Sobel1Click(TObject *Sender);
        void __fastcall FFT1Click(TObject *Sender);
        void __fastcall IFFT1Click(TObject *Sender);
        void __fastcall Laplaciano1Click(TObject *Sender);
        void __fastcall Prewitt1Click(TObject *Sender);
        void __fastcall NotchClick(TObject *Sender);
        void __fastcall UpDown5Changing(TObject *Sender,
          bool &AllowChange);
        void __fastcall Edit7Change(TObject *Sender);
        void __fastcall imgMiImagenClick(TObject *Sender);
        void __fastcall PasaAltos2Click(TObject *Sender);
        void __fastcall UpDown6Click(TObject *Sender, TUDBtnType Button);
        void __fastcall Edit8Change(TObject *Sender);
        void __fastcall PasaBajos1Click(TObject *Sender);
        void __fastcall Puntos1Click(TObject *Sender);
        void __fastcall Horizontal1Click(TObject *Sender);
        void __fastcall Vertica1Click(TObject *Sender);
        void __fastcall N451Click(TObject *Sender);
        void __fastcall N452Click(TObject *Sender);
        void __fastcall UmbralFijo1Click(TObject *Sender);
        void __fastcall Isodata1Click(TObject *Sender);
        void __fastcall LadyBug1Click(TObject *Sender);
        void __fastcall SlicingX1Click(TObject *Sender);
        void __fastcall ContrastStrechingX1Click(TObject *Sender);
        void __fastcall Logicas2Click(TObject *Sender);

private:	// User declarations

public:		// User declarations
        
        __fastcall TForm1(TComponent* Owner);
        Matriz mtrMiImagen, AUX;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
