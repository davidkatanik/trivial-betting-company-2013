object formRegistrace: TformRegistrace
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Registrace'
  ClientHeight = 365
  ClientWidth = 500
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Cambria'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object sttPrava: TStaticText
    Left = 8
    Top = 335
    Width = 213
    Height = 16
    Caption = 'Copyright David Katanik - All rights reserved'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Cambria'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object lbleJmeno: TLabeledEdit
    Left = 8
    Top = 51
    Width = 201
    Height = 23
    Hint = 'Zadejte jm'#233'no'
    EditLabel.Width = 35
    EditLabel.Height = 15
    EditLabel.Caption = 'Jm'#233'no'
    MaxLength = 49
    OEMConvert = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnExit = lbleJmenoExit
  end
  object lblePrijmeni: TLabeledEdit
    Left = 8
    Top = 101
    Width = 201
    Height = 23
    Hint = 'Zadejte p'#345'ijmen'#237
    EditLabel.Width = 47
    EditLabel.Height = 15
    EditLabel.Caption = 'P'#345#237'jmen'#237
    MaxLength = 49
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnExit = lbleJmenoExit
  end
  object lbleEmail: TLabeledEdit
    Left = 8
    Top = 199
    Width = 201
    Height = 23
    Hint = 'V'#225#353' email (Bude pou'#382'it jako p'#345'ihla'#353'ovac'#237' jm'#233'no)'
    EditLabel.Width = 32
    EditLabel.Height = 15
    EditLabel.Caption = 'Email'
    MaxLength = 99
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    OnExit = lbleEmailExit
  end
  object lbleTelCis: TLabeledEdit
    Left = 231
    Top = 245
    Width = 219
    Height = 23
    Hint = 'Telefonn'#237' '#269#237'slo'
    EditLabel.Width = 41
    EditLabel.Height = 15
    EditLabel.Caption = 'Telefon'
    MaxLength = 29
    ParentShowHint = False
    ShowHint = True
    TabOrder = 13
    OnExit = lbleEmailExit
  end
  object lbleMesto: TLabeledEdit
    Left = 231
    Top = 51
    Width = 219
    Height = 23
    Hint = 'M'#283'sto'
    EditLabel.Width = 34
    EditLabel.Height = 15
    EditLabel.Caption = 'M'#283'sto'
    MaxLength = 49
    ParentShowHint = False
    ShowHint = True
    TabOrder = 9
    OnExit = lbleJmenoExit
  end
  object lbleAdresa: TLabeledEdit
    Left = 231
    Top = 101
    Width = 219
    Height = 23
    Hint = 'Ulice'
    EditLabel.Width = 28
    EditLabel.Height = 15
    EditLabel.Caption = 'Ulice'
    MaxLength = 99
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
    OnExit = lbleJmenoExit
  end
  object lbleCisPop: TLabeledEdit
    Left = 231
    Top = 150
    Width = 121
    Height = 23
    Hint = #268#237'slo popisn'#233
    EditLabel.Width = 75
    EditLabel.Height = 15
    EditLabel.Caption = #268#237'slo popisn'#233
    MaxLength = 6
    ParentShowHint = False
    ShowHint = True
    TabOrder = 11
    OnExit = lbleEmailExit
  end
  object lblePSC: TLabeledEdit
    Left = 231
    Top = 199
    Width = 121
    Height = 23
    Hint = 'Po'#353'tovn'#237' sm'#283'rovac'#237' '#269#237'slo (ZIP code)'
    EditLabel.Width = 20
    EditLabel.Height = 15
    EditLabel.Caption = 'PS'#268
    MaxLength = 19
    ParentShowHint = False
    ShowHint = True
    TabOrder = 12
    OnExit = lbleEmailExit
  end
  object chboPodminky: TCheckBox
    Left = 233
    Top = 274
    Width = 259
    Height = 22
    Cursor = crHandPoint
    Hint = 'Souhlas se v'#353'eobecn'#253'mi podm'#237'nkami'
    Caption = 'Souhlas'#237'm se v'#353'obecn'#253'mi podm'#237'nkami'
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'Cambria'
    Font.Style = [fsBold, fsUnderline]
    ParentColor = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 14
    OnClick = chboPodminkyClick
  end
  object btnRegistrovat: TButton
    Left = 231
    Top = 320
    Width = 178
    Height = 37
    Hint = 'Registrovat'
    Caption = 'REGISTROVAT'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Cambria'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 15
    OnClick = btnRegistrovatClick
  end
  object cboDenNar: TComboBox
    Left = 151
    Top = 150
    Width = 53
    Height = 23
    Hint = 'Den narozen'#237
    ItemHeight = 15
    MaxLength = 2
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
  end
  object cboMesNar: TComboBox
    Left = 92
    Top = 150
    Width = 53
    Height = 23
    Hint = 'M'#283's'#237'c narozen'#237
    ItemHeight = 15
    MaxLength = 2
    TabOrder = 4
    OnChange = cboMesNarChange
  end
  object cboRokNar: TComboBox
    Left = 8
    Top = 150
    Width = 78
    Height = 23
    Hint = 'Rok narozen'#237
    ItemHeight = 15
    MaxLength = 4
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    OnChange = cboMesNarChange
  end
  object lbleHeslo1: TLabeledEdit
    Left = 8
    Top = 245
    Width = 201
    Height = 23
    Hint = 'Heslo'
    EditLabel.Width = 32
    EditLabel.Height = 15
    EditLabel.Caption = 'Heslo'
    MaxLength = 49
    ParentShowHint = False
    PasswordChar = '*'
    ShowHint = True
    TabOrder = 7
    OnExit = lbleEmailExit
  end
  object lbleHeslo2: TLabeledEdit
    Left = 8
    Top = 290
    Width = 201
    Height = 23
    Hint = 'Heslo znovu'
    EditLabel.Width = 69
    EditLabel.Height = 15
    EditLabel.Caption = 'Heslo znovu'
    MaxLength = 49
    ParentShowHint = False
    PasswordChar = '*'
    ShowHint = True
    TabOrder = 8
    OnExit = lbleEmailExit
  end
  object sttRegistrace: TStaticText
    Left = 172
    Top = 0
    Width = 121
    Height = 32
    Caption = 'Registrace'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Cambria'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 17
  end
  object sttDen: TStaticText
    Left = 151
    Top = 130
    Width = 26
    Height = 19
    Caption = 'Den'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 18
  end
  object sttMesic: TStaticText
    Left = 92
    Top = 130
    Width = 37
    Height = 19
    Caption = 'M'#283's'#237'c'
    TabOrder = 19
  end
  object sttRok: TStaticText
    Left = 8
    Top = 130
    Width = 79
    Height = 19
    Caption = 'Rok Narozen'#237
    ParentShowHint = False
    ShowHint = True
    TabOrder = 20
  end
  object btnZrusitReg: TButton
    Left = 415
    Top = 320
    Width = 75
    Height = 37
    Hint = 'Zru'#353'it registraci'
    Caption = 'Zru'#353'it'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Cambria'
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 16
  end
  object sttUdaje: TStaticText
    Left = 233
    Top = 302
    Width = 131
    Height = 16
    Caption = 'Ve'#353'ker'#233' '#250'daje jsou povinn'#233
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Cambria'
    Font.Style = []
    ParentFont = False
    TabOrder = 21
  end
end
