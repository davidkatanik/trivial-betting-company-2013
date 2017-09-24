object formPrihlaseni: TformPrihlaseni
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'S'#225'zkov'#225' kancel'#225#345
  ClientHeight = 370
  ClientWidth = 600
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -21
  Font.Name = 'Cambria'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 25
  object lblUvitaci: TLabel
    Left = 106
    Top = 24
    Width = 377
    Height = 37
    Caption = 'Program s'#225'zkov'#233' kancel'#225#345'e'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Cambria'
    Font.Style = []
    ParentFont = False
  end
  object lblePriJmeno: TLabeledEdit
    Left = 40
    Top = 104
    Width = 197
    Height = 33
    EditLabel.Width = 51
    EditLabel.Height = 25
    EditLabel.Caption = 'Email'
    MaxLength = 99
    TabOrder = 0
  end
  object lbleHeslo: TLabeledEdit
    Left = 354
    Top = 104
    Width = 207
    Height = 33
    EditLabel.Width = 50
    EditLabel.Height = 25
    EditLabel.Caption = 'Heslo'
    MaxLength = 49
    PasswordChar = '*'
    TabOrder = 1
  end
  object btnPrihlasit: TButton
    Left = 196
    Top = 160
    Width = 201
    Height = 25
    Caption = 'P'#344'IHL'#193'SIT'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Cambria'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 2
    OnClick = btnPrihlasitClick
  end
  object sttPrava: TStaticText
    Left = 60
    Top = 320
    Width = 251
    Height = 19
    Caption = 'Copyright David Katanik - All rights reserved'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Cambria'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object btnRegistrovat: TButton
    Left = 196
    Top = 217
    Width = 201
    Height = 25
    Caption = 'REGISTROVAT'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Cambria'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = btnRegistrovatClick
  end
end
