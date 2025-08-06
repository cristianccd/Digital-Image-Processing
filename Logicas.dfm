object Form3: TForm3
  Left = 342
  Top = 256
  Width = 900
  Height = 370
  AutoSize = True
  Caption = 'Operaciones Logicas'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object BitBtn1: TBitBtn
    Left = 280
    Top = 287
    Width = 97
    Height = 25
    Caption = 'ACEPTAR'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = BitBtn1Click
    Kind = bkYes
  end
  object BitBtn3: TBitBtn
    Left = 408
    Top = 287
    Width = 81
    Height = 25
    Caption = 'SALIR'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = BitBtn3Click
    Kind = bkAbort
  end
  object StaticText1: TStaticText
    Left = 280
    Top = 88
    Width = 39
    Height = 84
    Caption = '+'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -67
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Visible = False
  end
  object StaticText2: TStaticText
    Left = 280
    Top = 88
    Width = 24
    Height = 84
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -67
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Visible = False
  end
  object StaticText3: TStaticText
    Left = 264
    Top = 104
    Width = 73
    Height = 41
    Caption = 'AND'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    Visible = False
  end
  object StaticText4: TStaticText
    Left = 272
    Top = 104
    Width = 51
    Height = 41
    Caption = 'OR'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Visible = False
  end
  object StaticText5: TStaticText
    Left = 600
    Top = 112
    Width = 23
    Height = 41
    Caption = '='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    Visible = False
  end
  object GroupBox1: TGroupBox
    Left = 640
    Top = 263
    Width = 225
    Height = 49
    Caption = 'Datos Imagen'
    TabOrder = 7
    OnMouseMove = GroupBox1MouseMove
    object Label1: TLabel
      Left = 10
      Top = 23
      Width = 13
      Height = 13
      Caption = 'X='
    end
    object Label2: TLabel
      Left = 66
      Top = 24
      Width = 13
      Height = 13
      Caption = 'Y='
    end
    object Label3: TLabel
      Left = 125
      Top = 23
      Width = 55
      Height = 13
      Caption = 'Valor Pixel='
    end
    object Edit1: TEdit
      Left = 26
      Top = 20
      Width = 33
      Height = 21
      Enabled = False
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 81
      Top = 20
      Width = 33
      Height = 21
      Enabled = False
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 184
      Top = 20
      Width = 33
      Height = 21
      Enabled = False
      TabOrder = 2
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 260
    Height = 260
    TabOrder = 8
    object Image: TImage
      Left = 2
      Top = 0
      Width = 256
      Height = 256
      AutoSize = True
    end
  end
  object Panel2: TPanel
    Left = 336
    Top = 0
    Width = 260
    Height = 260
    TabOrder = 9
    object Image1: TImage
      Left = 2
      Top = 0
      Width = 256
      Height = 256
      AutoSize = True
    end
  end
  object Panel3: TPanel
    Left = 624
    Top = 0
    Width = 260
    Height = 260
    TabOrder = 10
    object Image2: TImage
      Left = 2
      Top = 0
      Width = 256
      Height = 256
      AutoSize = True
      OnMouseMove = Image2MouseMove
    end
  end
  object OpenDialog1: TOpenDialog
    InitialDir = '.'
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 8
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object Abrir1: TMenuItem
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFF8F8F8E8E8E8E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4
          E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E8E8E8F0F0F0F6F6F6769DB14A90B2
          4A90B24A90B24A90B24A90B24A90B24A90B24A90B24A90B24A90B24A90B24A90
          B26E98ADE0E0E0EEEEEE589FC36FC1E786D0EF85CFEE85CFEE85CFEE85CFEE85
          CFEE85CFEE85CFEE85CFEE85CFEE87D0F064ADD0BBD3DFFFFFFF66ADD157B5DF
          8DD6F187D1EE87D1EE87D1EE87D1EE87D1EE87D1EE87D1EE87D1EE87D1EE88D1
          EE82CDEB85C2E0FFFFFF69B1D646ADDC97DFF694DBF494DBF494DBF494DBF494
          DBF494DBF494DBF494DBF494DBF494DBF49BE1F879C1E4DCEEF76DB5DA60BEE7
          85D7F2A1E6FAA0E5FAA0E5FAA0E5FAA0E5FAA2E8FAA5EAFBA5EAFBA5EAFBA5EA
          FBA6ECFB8AD4EFABD8EF71B9DD7DCFF069C7ECAFF3FFADF1FEADF1FEADF1FEAD
          F1FE98E5F849B2E349B2E349B2E34DB6E53CA5DA83C8EB83C8EB75BCE096DEF6
          4EB8E74EB8E74EB8E74EB8E74EB8E74EB8E74EB8E781D1F092DAF392DAF399E0
          F675BCE0FFFFFFFFFFFF79C0E39FE5F998DFF698DFF698DFF698DFF698DFF698
          DFF698DFF698DFF698DFF698DFF69FE5F979C0E3FFFFFFFFFFFF7DC3E6A3E9FB
          9DE3F99DE3F99DE3F99DE3F99DE3F99DE3F99DE3F99DE3F99DE3F99DE3F9A3E9
          FB7DC3E6FFFFFFFFFFFF7FC5E8A8EDFDA2E7FBA2E7FBA2E7FBA2E7FBA2E7FBA2
          E7FBA2E7FBA2E7FBA2E7FBA2E7FBA8EDFD7FC5E8FFFFFFFFFFFF83C8EBAEF3FF
          ABF0FEABF0FEABF0FEABF0FEABF0FEABF0FEABF0FEABF0FEABF0FEABF0FEAEF3
          FF83C8EBFFFFFFFFFFFFA3D7F185CAED85CAED85CAED85CAED85CAED85CAEDFE
          FEFDF5F5EEEBEBDDFEC941F4B62E85CAEDA3D7F1FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFD4EDF987CBEE87CBEE87CBEE87CBEE87CBEED4ED
          F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        Caption = 'Abrir Imagen...'
        OnClick = Abrir1Click
      end
      object Salir1: TMenuItem
        Bitmap.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFE8E8E7BCBBB9BCBBB9BCBBB9BCBBB9BCBBB9BCBBB9BCBBB9BCBB
          B9BCBBB9BCBBB9E8E8E7FFFFFFFFFFFFFFFFFFFFFFFFBCBBBA5D5F5A2E66442E
          66442E66442E66442E66442E66442E66442E664431553DBCBBB9FFFFFFFFFFFF
          FFFFFFFFFFFFB1AFD6726FB6B7B8BA6C8A794274572E6F4A31734D33764F3477
          50347851346245BCBBB9FFFFFFFFFFFFFFFFFFFFFFFFABABDF0A08B4807DBFCD
          CDD0A3ACA8657A6F2B67452B6C472F714B31744D316243BCBBB9E3E2F4A8A7DE
          A5A5DEA5A5DE706FCA0100DD0504D65755B5BDBFC2C7C8C89596963761492A69
          452D6E49306042BCBBB9ADADE10707CE0707E10707E10707E10202EF0000E903
          02E1605EAAB0B0B4B1B2B239614A2965422B6A462F5E41BCBBB9ADADE10F0EE0
          0000E00000DE0000DE0000DE0000DE0000F00808E64642ABAAABAC395B47285C
          3E2A5F402E593EBCBBB9ADADE11A1AE00000F80000F60000F60000F60000F70D
          0DF80808E64946ACAAABAC37584526573B27593C2D573CBCBBB9ADADE11818CE
          1F1FE21F1FE22020E22020F61414FC1311E16764A74E4E51818282334D3E1F48
          30214A322A5038BCBBB9E5E4F5AAAAE1AAAAE2AAAAE27171CD2222E01D1AD76D
          6AB9BABCBE7A7B7B8889893045391A3B281C3D29284B35BCBBB9FFFFFFFFFFFF
          FFFFFFFFFFFFACABDF211DB49F9DC3CFD1D1BDC0C0B7B9B9ADAFAF2D40351431
          20153221264732BCBBB9FFFFFFFFFFFFFFFFFFFFFFFFB6B4CC908DB3DFE1E1D0
          D2D2BDC0C0B7B9B9ADAFAF2B3D33102B1B112B1C23442FBCBBB9FFFFFFFFFFFF
          FFFFFFFFFFFFBCBBB9B1B2B0DFE2E2D0D2D2BDC0C0B4B6B6999A9A1A2B220C25
          170C251722422DBCBBB9FFFFFFFFFFFFFFFFFFFFFFFFBCBBB9B1B2B0DFE2E2D0
          D2D2B9BCBC92959580818112231A0C25170C251722422DBCBBB9FFFFFFFFFFFF
          FFFFFFFFFFFFBCBBB97C7C788A8A88767775585A575052505F5F5D1E28201A2A
          1E1A2A1E283D2DBCBBB9FFFFFFFFFFFFFFFFFFFFFFFFE8E8E7BCBBB9BCBBB9BC
          BBB9BCBBB9BCBBB9BCBBB9BCBBB9BCBBB9BCBBB9BCBBB9E8E8E7}
        Caption = 'Cerrar...'
        OnClick = Salir1Click
      end
    end
    object Logicas1: TMenuItem
      Caption = 'Operaciones'
      object SUMA1: TMenuItem
        Caption = 'Suma'
        OnClick = SUMA1Click
      end
      object R1: TMenuItem
        Caption = 'Resta'
        OnClick = R1Click
      end
      object AND1: TMenuItem
        Caption = 'AND'
        OnClick = AND1Click
      end
      object OR1: TMenuItem
        Caption = 'OR'
        OnClick = OR1Click
      end
    end
  end
end
