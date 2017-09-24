object formBookmaker: TformBookmaker
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'S'#225'zkov'#225' kancel'#225#345
  ClientHeight = 547
  ClientWidth = 910
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pcBookmaker: TPageControl
    Left = 0
    Top = 0
    Width = 909
    Height = 545
    ActivePage = tsBookmakeri
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Cambria'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
    object tsZapasy: TTabSheet
      Caption = 'Spr'#225'va z'#225'pas'#367
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      object libZapasy: TListBox
        Left = 8
        Top = 16
        Width = 530
        Height = 409
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = []
        ItemHeight = 15
        ParentFont = False
        ScrollWidth = 500
        TabOrder = 0
        TabWidth = 45
        OnClick = libZapasyClick
      end
      object lbleJmenoD: TLabeledEdit
        Left = 551
        Top = 80
        Width = 210
        Height = 27
        EditLabel.Width = 53
        EditLabel.Height = 19
        EditLabel.Caption = 'Dom'#225'c'#237
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnExit = lbleJmenoDExit
      end
      object lbleJmenoH: TLabeledEdit
        Left = 551
        Top = 128
        Width = 210
        Height = 27
        EditLabel.Width = 40
        EditLabel.Height = 19
        EditLabel.Caption = 'Host'#233
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnExit = lbleJmenoDExit
      end
      object eSkoreH: TEdit
        Left = 720
        Top = 181
        Width = 41
        Height = 27
        BiDiMode = bdLeftToRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentBiDiMode = False
        ParentFont = False
        TabOrder = 4
        Text = '0'
      end
      object eSkoreD: TEdit
        Left = 554
        Top = 183
        Width = 40
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Text = '0'
        OnExit = lbleJmenoDExit
      end
      object sttVS: TStaticText
        Left = 661
        Top = 187
        Width = 8
        Height = 23
        Caption = ':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 17
      end
      object btnPridatZ: TButton
        Left = 767
        Top = 78
        Width = 123
        Height = 29
        Hint = 'P'#345'id'#225' nov'#253' z'#225'pas do seznamu z'#225'pas'#367
        Caption = 'P'#345'idat z'#225'pas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 10
        OnClick = btnPridatZClick
      end
      object lbleKurzD: TLabeledEdit
        Left = 554
        Top = 342
        Width = 48
        Height = 27
        Hint = 'Kurz dom'#225'c'#237'ch'
        EditLabel.Width = 9
        EditLabel.Height = 19
        EditLabel.BiDiMode = bdLeftToRight
        EditLabel.Caption = '1'
        EditLabel.ParentBiDiMode = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 7
        Text = '1'
      end
      object lbleKurzRem: TLabeledEdit
        Left = 620
        Top = 342
        Width = 49
        Height = 27
        Hint = 'Kurz na rem'#237'zu'
        EditLabel.Width = 9
        EditLabel.Height = 19
        EditLabel.Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 8
        Text = '1'
      end
      object lbleKurzH: TLabeledEdit
        Left = 690
        Top = 342
        Width = 50
        Height = 27
        Hint = 'Kurz host'#367
        EditLabel.Width = 9
        EditLabel.Height = 19
        EditLabel.Caption = '2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 9
        Text = '1'
      end
      object sttResult: TStaticText
        Left = 554
        Top = 161
        Width = 69
        Height = 23
        Caption = 'V'#253'sledky'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 18
      end
      object sttKurzy: TStaticText
        Left = 554
        Top = 302
        Width = 45
        Height = 23
        Caption = 'Kurzy'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 19
      end
      object dtpDatum: TDateTimePicker
        Left = 554
        Top = 216
        Width = 207
        Height = 27
        Date = 41262.000000000000000000
        Time = 41262.000000000000000000
        DateMode = dmUpDown
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
      end
      object dtpCas: TDateTimePicker
        Left = 554
        Top = 243
        Width = 207
        Height = 27
        Date = 41262.000000000000000000
        Format = 'HH:mm:ss'
        Time = 41262.000000000000000000
        DateMode = dmUpDown
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        Kind = dtkTime
        ParentFont = False
        TabOrder = 6
      end
      object btnOdebratZ: TButton
        Left = 767
        Top = 128
        Width = 123
        Height = 27
        Hint = 'Odebere z'#225'pas ze seznamu z'#225'pas'#367
        Caption = 'Odebrat z'#225'pas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 11
        OnClick = btnOdebratZClick
      end
      object btnZmenZ: TButton
        Left = 767
        Top = 216
        Width = 123
        Height = 54
        Hint = 'Uprav'#237' V'#225'mi zadan'#253' z'#225'pas'
        Caption = 'Uprav z'#225'pas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 13
        OnClick = btnZmenZClick
      end
      object cboDohrano: TCheckBox
        Left = 767
        Top = 182
        Width = 123
        Height = 25
        Hint = 
          'Jestli je z'#225'pas dohr'#225'n, tak za'#353'krtn'#283'te toto pole a ur'#269'ete v'#253'sled' +
          'ky, n'#225'sledn'#283' klikn'#283'te na Uprav z'#225'pas'
        Caption = 'Dohr'#225'no?'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -21
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 12
        OnClick = cboDohranoClick
      end
      object eVyhledanyZ: TEdit
        Left = 8
        Top = 464
        Width = 530
        Height = 27
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 16
      end
      object eIdZ: TEdit
        Left = 8
        Top = 431
        Width = 121
        Height = 27
        Hint = 'Pomoc'#237' V'#225'mi zadan'#233'ho ID z'#225'pasu vyhled'#225' z'#225'pas v seznamu z'#225'pas'#367
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 14
      end
      object btnNajdiZ: TButton
        Left = 135
        Top = 431
        Width = 121
        Height = 27
        Hint = 'Pomoc'#237' V'#225'mi zadan'#233'ho ID z'#225'pasu vyhled'#225' z'#225'pas v seznamu z'#225'pas'#367
        Caption = 'Najdi zapas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 15
        OnClick = btnNajdiZClick
      end
    end
    object tsTikety: TTabSheet
      Caption = 'Spr'#225'va tiket'#367
      ImageIndex = 3
      object lblDatTik: TLabel
        Left = 160
        Top = 377
        Width = 196
        Height = 22
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object libTikety: TListBox
        Left = 3
        Top = 3
        Width = 353
        Height = 368
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ItemHeight = 15
        ParentFont = False
        ScrollWidth = 500
        TabOrder = 0
        TabWidth = 30
        OnClick = libTiketyClick
      end
      object sttDatumTiketu: TStaticText
        Left = 3
        Top = 377
        Width = 131
        Height = 26
        Caption = 'Datum tiketu : '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
      end
      object eIdTiketu: TEdit
        Left = 180
        Top = 405
        Width = 176
        Height = 30
        Hint = 'Pomoc'#237' V'#225'mi zadan'#233'ho ID tiketu najde tiket v seznamu tiket'#367
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
      end
      object gboTiket2: TGroupBox
        Left = 362
        Top = 0
        Width = 536
        Height = 495
        Caption = 'Tiket'
        Color = clInactiveBorder
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        TabOrder = 6
        object lblJmenoDTik: TLabel
          Left = 23
          Top = 244
          Width = 244
          Height = 49
          AutoSize = False
          Caption = 'Jm'#233'no dom'#225'c'#237'ch'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = []
          ParentFont = False
          WordWrap = True
        end
        object lblJmenoHTik: TLabel
          Left = 290
          Top = 244
          Width = 224
          Height = 39
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Jm'#233'no host'#237
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = []
          ParentFont = False
          WordWrap = True
        end
        object lblCasZapTik: TLabel
          Left = 410
          Top = 215
          Width = 94
          Height = 22
          Alignment = taRightJustify
          BiDiMode = bdRightToLeft
          Caption = #268'as z'#225'pasu'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
        end
        object lblDatZapTik: TLabel
          Left = 23
          Top = 215
          Width = 126
          Height = 22
          Caption = 'Datum  z'#225'pasu'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblCastkaVyhra: TLabel
          Left = 380
          Top = 419
          Width = 11
          Height = 22
          BiDiMode = bdRightToLeft
          Caption = '0'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
        end
        object lblCKurz: TLabel
          Left = 380
          Top = 384
          Width = 11
          Height = 22
          BiDiMode = bdRightToLeft
          Caption = '1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
        end
        object lblVyhodnoceno: TLabel
          Left = 384
          Top = 448
          Width = 4
          Height = 22
          BiDiMode = bdRightToLeft
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
        end
        object lblVyhraZap: TLabel
          Left = 383
          Top = 338
          Width = 4
          Height = 22
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblKurzTip: TLabel
          Left = 428
          Top = 292
          Width = 4
          Height = 22
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblVysTik: TLabel
          Left = 154
          Top = 292
          Width = 4
          Height = 22
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object libZapasyTiketu: TListBox
          Left = 13
          Top = 16
          Width = 508
          Height = 190
          ItemHeight = 15
          ScrollWidth = 400
          TabOrder = 0
          TabWidth = 20
          OnClick = libZapasyTiketuClick
        end
        object sttVS3: TStaticText
          Left = 283
          Top = 212
          Width = 9
          Height = 26
          Caption = ':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object sttVybranoTik: TStaticText
          Left = 23
          Top = 292
          Width = 110
          Height = 26
          Caption = 'Vsazeno na :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
        end
        object sttKurz: TStaticText
          Left = 313
          Top = 292
          Width = 67
          Height = 26
          Caption = 'KURZ : '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
        object lbleVklad: TLabeledEdit
          Left = 23
          Top = 341
          Width = 115
          Height = 27
          EditLabel.Width = 38
          EditLabel.Height = 15
          EditLabel.Caption = 'Vklad '
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
          Text = '0'
        end
        object sttPoplatek: TStaticText
          Left = 113
          Top = 475
          Width = 180
          Height = 16
          Caption = 'Manipula'#269'n'#237' poplatek 10% vkladu'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
        end
        object lbleCastka: TLabeledEdit
          Left = 144
          Top = 341
          Width = 107
          Height = 27
          EditLabel.Width = 48
          EditLabel.Height = 15
          EditLabel.Caption = 'Zaplat'#237#353
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          Text = '0'
        end
        object sttVyhra: TStaticText
          Left = 257
          Top = 338
          Width = 108
          Height = 26
          Caption = 'Spr'#225'vny tip:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 7
        end
        object lblCelkK: TStaticText
          Left = 113
          Top = 384
          Width = 130
          Height = 26
          Caption = 'Celkov'#253' kurz : '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 8
        end
        object lblVyhra: TStaticText
          Left = 113
          Top = 417
          Width = 128
          Height = 26
          Caption = 'Mo'#382'n'#225' v'#253'hra : '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 9
        end
        object sttVyhodnoceno: TStaticText
          Left = 113
          Top = 450
          Width = 135
          Height = 26
          Caption = 'Vyhodnoceno : '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 10
        end
        object sttKC: TStaticText
          Left = 410
          Top = 419
          Width = 38
          Height = 26
          Caption = ',-K'#268
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 11
        end
        object eSD: TEdit
          Left = 210
          Top = 217
          Width = 61
          Height = 23
          ReadOnly = True
          TabOrder = 12
        end
        object eSH: TEdit
          Left = 310
          Top = 217
          Width = 61
          Height = 23
          ReadOnly = True
          TabOrder = 13
        end
      end
      object btnSmazatTiket: TButton
        Left = 3
        Top = 450
        Width = 171
        Height = 39
        Hint = 'Sma'#382'e tiket a vyma'#382'e v'#353'echny tipy na tento tiket'
        Caption = 'Smazat tiket'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = btnSmazatTiketClick
      end
      object btnVyhodnotitZnovu: TButton
        Left = 180
        Top = 450
        Width = 171
        Height = 39
        Hint = 
          'Vyhodnot'#237' tiket znovu. ( POZOR : P'#344'I VYHODNOCEN'#205' JI'#381' SPR'#193'VN'#282' VYH' +
          'ODNOCEN'#201'HO TIKETU P'#344'I'#268'TE PEN'#205'ZE ZA V'#221'HRU ZNOVU !!!)'
        Caption = 'Vyhodnotit znovu'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = btnVyhodnotitZnovuClick
        OnEnter = btnVyhodnotitZnovuEnter
      end
      object btnNajdiTiket: TButton
        Left = 3
        Top = 405
        Width = 171
        Height = 30
        Hint = 'Pomoc'#237' V'#225'mi zadan'#233'ho ID tiketu najde tiket v seznamu tiket'#367
        Caption = 'Najdi tiket'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = btnNajdiTiketClick
      end
    end
    object tsBookmakeri: TTabSheet
      Caption = 'Spr'#225'va bookmaker'#367
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 2
      ParentFont = False
      object btnPridatBmk: TButton
        Left = 637
        Top = 39
        Width = 224
        Height = 36
        Hint = 'P'#345#237'd'#225' nov'#233'ho bookmakera'
        Caption = 'P'#345#237'dat bookmakera'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = btnPridatBmkClick
      end
      object libBmakeri: TListBox
        Left = 8
        Top = 16
        Width = 613
        Height = 419
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = []
        ItemHeight = 15
        ParentFont = False
        TabOrder = 0
        TabWidth = 40
        OnClick = libBmakeriClick
      end
      object btnNajdiBmk: TButton
        Left = 637
        Top = 221
        Width = 224
        Height = 34
        Hint = 
          'Pomoc'#237' V'#225'mi zadan'#233'ho ID bookmakera vyhled'#225' bookmakera v seznamu ' +
          'bookmakeru'
        Caption = 'Najdi bookmakera'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = btnNajdiBmkClick
      end
      object eVybranyBmk: TEdit
        Left = 8
        Top = 441
        Width = 613
        Height = 30
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
      end
      object btnOdebratBmk: TButton
        Left = 637
        Top = 399
        Width = 224
        Height = 36
        Hint = 'Odebere V'#225'mi vybran'#233'ho bookmakera'
        Caption = 'Odebrat bookmakera'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        OnClick = btnOdebratBmkClick
      end
      object btnUpravBmk: TButton
        Left = 637
        Top = 81
        Width = 224
        Height = 32
        Hint = 'Uprav'#237' V'#225'mi zadan'#233'ho bookmakera'
        Caption = 'Uprav bookmakera '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = btnUpravBmkClick
      end
      object lbleIdBmk: TLabeledEdit
        Left = 637
        Top = 185
        Width = 121
        Height = 30
        EditLabel.Width = 147
        EditLabel.Height = 23
        EditLabel.Caption = 'ID bookmakera : '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
    object tsUzivatele: TTabSheet
      Caption = 'Spr'#225'va u'#382'ivatel'#367
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      object btnPridatUziv: TButton
        Left = 637
        Top = 39
        Width = 224
        Height = 36
        Hint = 'P'#345'id'#225' nov'#233'ho u'#382'ivatele'
        Caption = 'P'#345#237'dat u'#382'ivatele'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = btnPridatUzivClick
      end
      object libUzivatele: TListBox
        Left = 3
        Top = 16
        Width = 613
        Height = 377
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = []
        ItemHeight = 15
        ParentFont = False
        TabOrder = 11
        TabWidth = 100
        OnClick = libUzivateleClick
      end
      object btnNajdiUziv: TButton
        Left = 637
        Top = 183
        Width = 224
        Height = 34
        Hint = 
          'Pomoc'#237' V'#225'mi zadan'#233'ho ID u'#382'ivatele vVyhled'#225' u'#382'ivatele v seznamu u' +
          #382'ivatel'#367
        Caption = 'Najdi u'#382'ivatele'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = btnNajdiUzivClick
      end
      object eVybranyUziv: TEdit
        Left = 3
        Top = 399
        Width = 613
        Height = 30
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 12
      end
      object btnOdebratUziv: TButton
        Left = 637
        Top = 399
        Width = 224
        Height = 36
        Hint = 'Odebere V'#225'mi vybran'#233'ho u'#382'ivatele'
        Caption = 'Odebrat u'#382'ivatele'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 8
        OnClick = btnOdebratUzivClick
      end
      object btnUpravUziv: TButton
        Left = 637
        Top = 81
        Width = 224
        Height = 32
        Hint = 'Uprav'#237' V'#225'mi vybran'#233'ho u'#382'ivatele'
        Caption = 'Uprav u'#382'ivatele'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = btnUpravUzivClick
      end
      object lbleIdUziv: TLabeledEdit
        Left = 637
        Top = 147
        Width = 121
        Height = 30
        EditLabel.Width = 117
        EditLabel.Height = 23
        EditLabel.Caption = 'ID u'#382'ivatele : '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object lbleStavKonta: TLabeledEdit
        Left = 637
        Top = 248
        Width = 241
        Height = 31
        Hint = 'Moment'#225'ln'#237' stav '#250#269'tu V'#225'mi vybran'#233'ho u'#382'ivatele'
        EditLabel.Width = 88
        EditLabel.Height = 23
        EditLabel.Caption = 'Stav konta'
        ParentShowHint = False
        ReadOnly = True
        ShowHint = True
        TabOrder = 4
      end
      object lbleOdecistPenize: TLabeledEdit
        Left = 637
        Top = 312
        Width = 241
        Height = 31
        Hint = 'Ode'#269'te, nebo p'#345'i'#269'te V'#225'mi zadanou '#269#225'stku pen'#283'z'
        EditLabel.Width = 189
        EditLabel.Height = 23
        EditLabel.Caption = 'Ode'#269#237'st/P'#345'i'#269#237'st pen'#237'ze :'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
      end
      object btnOdecistPenize: TButton
        Left = 637
        Top = 357
        Width = 104
        Height = 36
        Hint = 'Ode'#269'te V'#225'mi zadanou '#269#225'stku pen'#283'z'
        Caption = 'Ode'#269#237'st'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 6
        OnClick = btnOdecistPenizeClick
      end
      object btnPricistPenize: TButton
        Left = 757
        Top = 357
        Width = 104
        Height = 36
        Hint = 'P'#345'i'#269'te V'#225'mi zadanou '#269#225'stku pen'#283'z'
        Caption = 'P'#345'i'#269#237'st'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 7
        OnClick = btnPricistPenizeClick
      end
      object lblePocSpravnychTipu: TLabeledEdit
        Left = 3
        Top = 461
        Width = 278
        Height = 31
        Hint = 'Po'#269'et tip'#367
        EditLabel.Width = 174
        EditLabel.Height = 23
        EditLabel.Caption = 'Po'#269'et spr'#225'vn'#253'ch tip'#367
        ParentShowHint = False
        ReadOnly = True
        ShowHint = True
        TabOrder = 9
      end
      object lblePocVyhranychTiketu: TLabeledEdit
        Left = 345
        Top = 461
        Width = 276
        Height = 31
        Hint = 'Po'#269'et tiket'#367
        EditLabel.Width = 188
        EditLabel.Height = 23
        EditLabel.Caption = 'Po'#269'et spr'#225'vn'#253'ch tiket'#367
        ParentShowHint = False
        ReadOnly = True
        ShowHint = True
        TabOrder = 10
      end
    end
    object tsStatistiky: TTabSheet
      Caption = 'Statistiky'
      ImageIndex = 4
      OnShow = tsStatistikyShow
      object lblePocetUzivatelu: TLabeledEdit
        Left = 20
        Top = 48
        Width = 381
        Height = 30
        EditLabel.Width = 266
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et registrovan'#253'ch u'#382'ivatel'#367
        ReadOnly = True
        TabOrder = 0
      end
      object lblePocetBmakeru: TLabeledEdit
        Left = 20
        Top = 112
        Width = 381
        Height = 30
        EditLabel.Width = 299
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et registrovan'#253'ch bookmaker'#367
        ReadOnly = True
        TabOrder = 1
      end
      object lblePocetSpravnychTipu: TLabeledEdit
        Left = 20
        Top = 368
        Width = 381
        Height = 30
        EditLabel.Width = 267
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et spr'#225'vn'#253'ch tip'#367' na z'#225'pasy'
        ReadOnly = True
        TabOrder = 5
      end
      object lblePocetZapasu: TLabeledEdit
        Left = 20
        Top = 176
        Width = 381
        Height = 30
        EditLabel.Width = 113
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et z'#225'pas'#367
        ReadOnly = True
        TabOrder = 2
      end
      object lblePocetDohZapasu: TLabeledEdit
        Left = 20
        Top = 240
        Width = 381
        Height = 30
        EditLabel.Width = 250
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et vyhodnocen'#253'ch z'#225'pas'#367
        ReadOnly = True
        TabOrder = 3
      end
      object lblePocetTipu: TLabeledEdit
        Left = 20
        Top = 304
        Width = 381
        Height = 30
        EditLabel.Width = 176
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et tip'#367' na z'#225'pasy'
        ReadOnly = True
        TabOrder = 4
      end
      object lblePenizeUzivatelu: TLabeledEdit
        Left = 20
        Top = 428
        Width = 381
        Height = 30
        EditLabel.Width = 270
        EditLabel.Height = 22
        EditLabel.Caption = 'Mno'#382'stv'#237' pen'#283'z v'#353'ech u'#382'ivatel'#367
        ReadOnly = True
        TabOrder = 6
      end
      object lbleVydelanePenize: TLabeledEdit
        Left = 500
        Top = 48
        Width = 381
        Height = 30
        EditLabel.Width = 227
        EditLabel.Height = 22
        EditLabel.Caption = 'Mno'#382'stv'#237' vyhran'#253'ch pen'#283'z'
        ReadOnly = True
        TabOrder = 7
      end
      object lbleProhranePenize: TLabeledEdit
        Left = 500
        Top = 112
        Width = 381
        Height = 30
        EditLabel.Width = 238
        EditLabel.Height = 22
        EditLabel.Caption = 'Mno'#382'stv'#237' prohran'#253'ch pen'#283'z'
        ReadOnly = True
        TabOrder = 8
      end
      object lblePocetProTiketu: TLabeledEdit
        Left = 500
        Top = 368
        Width = 381
        Height = 30
        EditLabel.Width = 219
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et ne'#250'sp'#283#353'n'#253'ch tiket'#367
        ReadOnly = True
        TabOrder = 12
      end
      object lblePocetVyhTiketu: TLabeledEdit
        Left = 500
        Top = 304
        Width = 381
        Height = 30
        EditLabel.Width = 198
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et '#250'sp'#283#353'n'#253'ch tiket'#367
        ReadOnly = True
        TabOrder = 11
      end
      object lbleVsazenePenize: TLabeledEdit
        Left = 500
        Top = 176
        Width = 381
        Height = 30
        EditLabel.Width = 339
        EditLabel.Height = 22
        EditLabel.Caption = 'Mno'#382'stv'#237' moment'#225'ln'#283' vsazen'#253'ch pen'#283'z'
        ReadOnly = True
        TabOrder = 9
      end
      object lblePocetTiketu: TLabeledEdit
        Left = 500
        Top = 240
        Width = 381
        Height = 30
        EditLabel.Width = 105
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et tiket'#367
        ReadOnly = True
        TabOrder = 10
      end
      object lblePocetNevyhodnocenych: TLabeledEdit
        Left = 500
        Top = 428
        Width = 381
        Height = 30
        EditLabel.Width = 263
        EditLabel.Height = 22
        EditLabel.Caption = 'Po'#269'et nevyhodnocen'#253'ch tiket'#367
        ReadOnly = True
        TabOrder = 13
      end
    end
  end
end
