//---------------------------------------------------------------------------

#ifndef LogicasH
#define LogicasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include "matriz.h"
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn3;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TStaticText *StaticText5;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TOpenDialog *OpenDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *Abrir1;
        TMenuItem *Salir1;
        TMenuItem *Logicas1;
        TMenuItem *SUMA1;
        TMenuItem *R1;
        TMenuItem *AND1;
        TMenuItem *OR1;
        TPanel *Panel1;
        TImage *Image;
        TPanel *Panel2;
        TImage *Image1;
        TPanel *Panel3;
        TImage *Image2;
        void __fastcall GroupBox1MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall SUMA1Click(TObject *Sender);
        void __fastcall R1Click(TObject *Sender);
        void __fastcall AND1Click(TObject *Sender);
        void __fastcall OR1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall Image2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
        Matriz Original, Auxiliar, Previa;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
