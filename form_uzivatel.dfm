object formUzivatel: TformUzivatel
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
  object pcUzivatel: TPageControl
    Left = 0
    Top = 0
    Width = 910
    Height = 547
    ActivePage = tsTikety
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Cambria'
    Font.Style = []
    MultiLine = True
    ParentFont = False
    TabOrder = 0
    object tsSazky: TTabSheet
      Caption = 'S'#225'zkov'#233' p'#345#237'le'#382'itosti'
      object libZapasy: TListBox
        Left = 6
        Top = 3
        Width = 388
        Height = 287
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ItemHeight = 15
        ParentFont = False
        ScrollWidth = 800
        TabOrder = 0
        TabWidth = 45
        OnClick = libZapasyClick
      end
      object gboZapas: TGroupBox
        Left = 3
        Top = 296
        Width = 388
        Height = 183
        Color = clSkyBlue
        ParentColor = False
        TabOrder = 1
        Visible = False
        object lblJmenoD: TLabel
          Left = 3
          Top = 16
          Width = 176
          Height = 59
          Alignment = taRightJustify
          AutoSize = False
          BiDiMode = bdLeftToRight
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
          WordWrap = True
        end
        object lblJmenoH: TLabel
          Left = 200
          Top = 16
          Width = 185
          Height = 59
          AutoSize = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          WordWrap = True
        end
        object lblDatZap: TLabel
          Left = 17
          Top = 81
          Width = 3
          Height = 15
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblCasZap: TLabel
          Left = 327
          Top = 81
          Width = 3
          Height = 15
          Alignment = taRightJustify
          BiDiMode = bdRightToLeft
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
        end
        object sttVS1: TStaticText
          Left = 185
          Top = 16
          Width = 8
          Height = 19
          Caption = ':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object stt1: TStaticText
          Left = 3
          Top = 112
          Width = 149
          Height = 29
          Align = alCustom
          Alignment = taCenter
          AutoSize = False
          Caption = '1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
        end
        object stt0: TStaticText
          Left = 158
          Top = 110
          Width = 70
          Height = 29
          Align = alCustom
          Alignment = taCenter
          AutoSize = False
          Caption = '0'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
        end
        object stt2: TStaticText
          Left = 234
          Top = 110
          Width = 151
          Height = 29
          Align = alCustom
          Alignment = taCenter
          AutoSize = False
          Caption = '2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
        end
        object btnPridatD: TButton
          Tag = 1
          Left = 3
          Top = 145
          Width = 149
          Height = 30
          Cursor = crHandPoint
          Hint = 'Vsadit na V'#225'mi vyhran'#253' tip'
          Align = alCustom
          Caption = 'V'#253'hra dom'#225'c'#237'ch'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = []
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = btnPridatDClick
        end
        object btnPridatR: TButton
          Left = 158
          Top = 145
          Width = 70
          Height = 30
          Cursor = crHandPoint
          Hint = 'Vsadit na V'#225'mi vyhran'#253' tip'
          Align = alCustom
          Caption = 'Rem'#237'za'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = []
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
          OnClick = btnPridatDClick
        end
        object btnPridatH: TButton
          Tag = 2
          Left = 234
          Top = 145
          Width = 151
          Height = 30
          Cursor = crHandPoint
          Hint = 'Vsadit na V'#225'mi vyhran'#253' tip'
          Align = alCustom
          Caption = 'V'#253'hra host'#367
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = []
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          OnClick = btnPridatDClick
        end
      end
      object sttPrava: TStaticText
        Left = 20
        Top = 485
        Width = 251
        Height = 19
        Caption = 'Copyright David Katanik - All rights reserved'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object gboTiket: TGroupBox
        Left = 397
        Top = 0
        Width = 504
        Height = 478
        Caption = 'Tiket'
        Color = clMenu
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        TabOrder = 3
        object lblJmenoDTik: TLabel
          Left = 10
          Top = 213
          Width = 217
          Height = 35
          AutoSize = False
          BiDiMode = bdRightToLeft
          Caption = 'Jm'#233'no dom'#225'c'#237'ch'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
          WordWrap = True
        end
        object lblJmenoHTik: TLabel
          Left = 248
          Top = 213
          Width = 203
          Height = 35
          AutoSize = False
          Caption = 'Jm'#233'no host'#237
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          WordWrap = True
        end
        object lblCasZapTik: TLabel
          Left = 368
          Top = 165
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
          Left = 150
          Top = 165
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
        object lblVysTik: TLabel
          Left = 144
          Top = 249
          Width = 45
          Height = 22
          Caption = '1|0|2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblKurzTik: TLabel
          Left = 148
          Top = 277
          Width = 106
          Height = 22
          Caption = 'Kurz z'#225'pasu'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblVyhra: TLabel
          Left = 13
          Top = 414
          Width = 125
          Height = 25
          Caption = 'Mo'#382'n'#225' v'#253'hra'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblCastkaVyhra: TLabel
          Left = 292
          Top = 414
          Width = 12
          Height = 25
          BiDiMode = bdRightToLeft
          Caption = '0'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
        end
        object lblKC: TLabel
          Left = 330
          Top = 414
          Width = 37
          Height = 25
          BiDiMode = bdLeftToRight
          Caption = ',-K'#268
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
        end
        object lblCelkK: TLabel
          Left = 13
          Top = 375
          Width = 125
          Height = 25
          Caption = 'Celkov'#253' kurz'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblCKurz: TLabel
          Left = 289
          Top = 375
          Width = 12
          Height = 25
          BiDiMode = bdRightToLeft
          Caption = '1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentBiDiMode = False
          ParentFont = False
        end
        object libTiket: TListBox
          Left = 3
          Top = 13
          Width = 498
          Height = 141
          ItemHeight = 15
          ScrollWidth = 400
          TabOrder = 3
          TabWidth = 20
          OnClick = libTiketClick
        end
        object sttVS2: TStaticText
          Left = 233
          Top = 213
          Width = 9
          Height = 35
          AutoSize = False
          Caption = ':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object sttVybranoTik: TStaticText
          Left = 13
          Top = 249
          Width = 110
          Height = 26
          Caption = 'Vsazeno na :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object sttKurz: TStaticText
          Left = 13
          Top = 275
          Width = 67
          Height = 26
          Caption = 'KURZ : '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
        end
        object lbleVklad: TLabeledEdit
          Left = 13
          Top = 327
          Width = 188
          Height = 23
          EditLabel.Width = 38
          EditLabel.Height = 15
          EditLabel.Caption = 'Vklad '
          TabOrder = 5
          Text = '0'
        end
        object btnPrepocitat: TButton
          Left = 207
          Top = 327
          Width = 79
          Height = 21
          Hint = 'P'#345'epo'#269#237'tat tiket'
          Caption = 'P'#345'epo'#269#237'tat'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 6
          OnClick = btnPrepocitatClick
        end
        object sttPoplatek: TStaticText
          Left = 13
          Top = 455
          Width = 144
          Height = 15
          Caption = 'Manipula'#269'n'#237' poplatek 10% vkladu'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 9
        end
        object bbtnOdebratZTik: TBitBtn
          Left = 3
          Top = 160
          Width = 121
          Height = 47
          Hint = 'Smazat V'#225'mi vybran'#253' z'#225'pas z tiketu'
          Caption = 'Smazat Z'#225'pas'
          ModalResult = 2
          ParentShowHint = False
          ShowHint = True
          TabOrder = 4
          OnClick = bbtnOdebratZTikClick
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            333333333333333333333333000033338833333333333333333F333333333333
            0000333911833333983333333388F333333F3333000033391118333911833333
            38F38F333F88F33300003339111183911118333338F338F3F8338F3300003333
            911118111118333338F3338F833338F3000033333911111111833333338F3338
            3333F8330000333333911111183333333338F333333F83330000333333311111
            8333333333338F3333383333000033333339111183333333333338F333833333
            00003333339111118333333333333833338F3333000033333911181118333333
            33338333338F333300003333911183911183333333383338F338F33300003333
            9118333911183333338F33838F338F33000033333913333391113333338FF833
            38F338F300003333333333333919333333388333338FFF830000333333333333
            3333333333333333333888330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
        end
        object bbtnVsadit: TBitBtn
          Left = 385
          Top = 414
          Width = 106
          Height = 35
          Hint = 'Vsadit tiket'
          Caption = '&Vsadit'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 8
          OnClick = bbtnVsaditClick
          Kind = bkYes
        end
        object lbleCastka: TLabeledEdit
          Left = 292
          Top = 326
          Width = 168
          Height = 23
          EditLabel.Width = 48
          EditLabel.Height = 15
          EditLabel.Caption = 'Zaplat'#237#353
          Enabled = False
          TabOrder = 7
          Text = '0'
        end
      end
    end
    object tsTikety: TTabSheet
      Caption = 'Moje tikety'
      ImageIndex = 1
      object lblDatTik: TLabel
        Left = 3
        Top = 412
        Width = 305
        Height = 25
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
      end
      object gboTiket2: TGroupBox
        Left = 314
        Top = 3
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
        TabOrder = 3
        object lblJmenoDTik2: TLabel
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
        object lblJmenoHTik2: TLabel
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
        object lblCasZapTik2: TLabel
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
        object lblDatZapTik2: TLabel
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
        object lblCastkaVyhra2: TLabel
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
        object lblCKurz2: TLabel
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
          Left = 310
          Top = 447
          Width = 84
          Height = 22
          AutoSize = False
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
        object lblKurzTik2: TLabel
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
        object lblVysTik2: TLabel
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
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Cambria'
          Font.Style = [fsBold]
          ItemHeight = 15
          ParentFont = False
          ScrollWidth = 400
          TabOrder = 3
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
          TabOrder = 0
        end
        object sttVybranoTik2: TStaticText
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
          TabOrder = 1
        end
        object sttKurzTipu: TStaticText
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
          TabOrder = 2
        end
        object lbleVklad2: TLabeledEdit
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
        object sttPoplatek2: TStaticText
          Left = 23
          Top = 476
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
        object lbleCastka2: TLabeledEdit
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
        object lblCelkK2: TStaticText
          Left = 23
          Top = 385
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
        object lblVyhra2: TStaticText
          Left = 23
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
          Left = 23
          Top = 449
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
        object eSkoreD: TEdit
          Left = 210
          Top = 217
          Width = 61
          Height = 23
          ReadOnly = True
          TabOrder = 12
        end
        object eSkoreH: TEdit
          Left = 310
          Top = 217
          Width = 61
          Height = 23
          ReadOnly = True
          TabOrder = 13
        end
      end
      object libTikety: TListBox
        Left = 3
        Top = 3
        Width = 305
        Height = 368
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = []
        ItemHeight = 15
        ParentFont = False
        ScrollWidth = 300
        TabOrder = 0
        TabWidth = 20
        OnClick = libTiketyClick
      end
      object sttDatumTiketu: TStaticText
        Left = 3
        Top = 377
        Width = 138
        Height = 29
        Caption = 'Datum tiketu : '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
      object btnNajdiTiket: TButton
        Left = 3
        Top = 456
        Width = 88
        Height = 30
        Hint = 'Pomoc'#237' V'#225'mi zadan'#233'ho ID tiketu najde tiket v seznamu tiket'#367
        Caption = 'Najdi Tiket'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = btnNajdiTiketClick
      end
      object eIdTiketu: TEdit
        Left = 115
        Top = 458
        Width = 126
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
    end
    object tsKonto: TTabSheet
      Caption = 'Stav konta'
      ImageIndex = 4
      OnShow = tsKontoShow
      object lbleZustatek: TLabeledEdit
        Left = 50
        Top = 48
        Width = 791
        Height = 40
        EditLabel.Width = 262
        EditLabel.Height = 33
        EditLabel.Caption = 'Moment'#225'ln'#237' z'#367'statek :'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
      end
      object lblePridatPenize: TLabeledEdit
        Left = 50
        Top = 128
        Width = 791
        Height = 40
        EditLabel.Width = 163
        EditLabel.Height = 33
        EditLabel.Caption = 'P'#345'idat pen'#237'ze:'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object btnPridatPenize: TButton
        Left = 310
        Top = 174
        Width = 301
        Height = 49
        Hint = 'P'#345'id'#225' pen'#237'ze na V'#225#353' '#250#269'et'
        Caption = 'P'#345'idat'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = btnPridatPenizeClick
      end
      object lbleVybratPenize: TLabeledEdit
        Left = 50
        Top = 269
        Width = 791
        Height = 40
        EditLabel.Width = 171
        EditLabel.Height = 33
        EditLabel.Caption = 'Vybrat pen'#237'ze:'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object btnVybratPenize: TButton
        Left = 310
        Top = 315
        Width = 301
        Height = 49
        Hint = 'Vybere pen'#237'ze z Va'#353'eho '#250#269'tu'
        Caption = 'Vybrat'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = btnVybratPenizeClick
      end
      object lblePocSpravnychTipu: TLabeledEdit
        Left = 50
        Top = 416
        Width = 281
        Height = 40
        EditLabel.Width = 245
        EditLabel.Height = 33
        EditLabel.Caption = 'Po'#269'et spr'#225'vn'#253'ch tip'#367
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 5
      end
      object lblePocVyhranychTiketu: TLabeledEdit
        Left = 560
        Top = 416
        Width = 281
        Height = 40
        EditLabel.Width = 267
        EditLabel.Height = 33
        EditLabel.Caption = 'Po'#269'et vyhran'#253'ch tiket'#367
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 6
      end
    end
    object tsProfil: TTabSheet
      Caption = 'M'#367'j profil'
      ImageIndex = 4
      OnShow = tsProfilShow
      object lbleMesto: TLabeledEdit
        Left = 36
        Top = 41
        Width = 815
        Height = 40
        EditLabel.Width = 71
        EditLabel.Height = 33
        EditLabel.Caption = 'M'#283'sto'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object lbleUlice: TLabeledEdit
        Left = 36
        Top = 121
        Width = 815
        Height = 40
        EditLabel.Width = 56
        EditLabel.Height = 33
        EditLabel.Caption = 'Ulice'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object lbleCisPop: TLabeledEdit
        Left = 36
        Top = 203
        Width = 365
        Height = 40
        EditLabel.Width = 155
        EditLabel.Height = 33
        EditLabel.Caption = #268#237'slo popisn'#233
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object lblePSC: TLabeledEdit
        Left = 446
        Top = 203
        Width = 405
        Height = 40
        EditLabel.Width = 46
        EditLabel.Height = 33
        EditLabel.Caption = 'PS'#268
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object lbleTelCis: TLabeledEdit
        Left = 36
        Top = 281
        Width = 815
        Height = 40
        EditLabel.Width = 89
        EditLabel.Height = 33
        EditLabel.Caption = 'Telefon'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
      object btnZmenUdaje: TButton
        Left = 386
        Top = 327
        Width = 465
        Height = 42
        Hint = 'Uprav zm'#283'n'#283'n'#233' '#250'daje'
        Caption = 'Uprav '#250'daje'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        OnClick = btnZmenUdajeClick
      end
      object lbleStareHeslo: TLabeledEdit
        Left = 36
        Top = 373
        Width = 275
        Height = 40
        EditLabel.Width = 132
        EditLabel.Height = 33
        EditLabel.Caption = 'Star'#233' heslo'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        PasswordChar = '*'
        TabOrder = 6
      end
      object lbleHeslo1: TLabeledEdit
        Left = 36
        Top = 453
        Width = 275
        Height = 40
        EditLabel.Width = 130
        EditLabel.Height = 33
        EditLabel.Caption = 'Nov'#233' heslo'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        PasswordChar = '*'
        TabOrder = 7
      end
      object lbleHeslo2: TLabeledEdit
        Left = 386
        Top = 453
        Width = 275
        Height = 40
        EditLabel.Width = 208
        EditLabel.Height = 33
        EditLabel.Caption = 'Nov'#233' heslo znovu'
        EditLabel.Font.Charset = DEFAULT_CHARSET
        EditLabel.Font.Color = clWindowText
        EditLabel.Font.Height = -27
        EditLabel.Font.Name = 'Tahoma'
        EditLabel.Font.Style = []
        EditLabel.ParentFont = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        PasswordChar = '*'
        TabOrder = 8
      end
      object btnZmenHeslo: TButton
        Left = 680
        Top = 453
        Width = 171
        Height = 40
        Hint = 'Zm'#283#328' heslo'
        Caption = 'Zm'#283#328' heslo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Cambria'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 9
        OnClick = btnZmenHesloClick
      end
    end
    object tsZadaniPrace: TTabSheet
      Caption = 'Zad'#225'n'#237' DMP'
      ImageIndex = 5
      object mZadani: TMemo
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 896
        Height = 504
        Align = alClient
        BevelInner = bvLowered
        BevelKind = bkSoft
        BorderStyle = bsNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Cambria'
        Font.Style = [fsBold]
        Lines.Strings = (
          'Zad'#225'n'#237' maturitn'#237' pr'#225'ce'
          ''
          ''
          'Jm'#233'no a p'#345#237'jmen'#237' '#382#225'ka: DAVID KATANIK'
          'T'#345#237'da: I4A'#9#352'koln'#237' rok: 2012/2013'
          'Obor vzd'#283'l'#225'n'#237': 18-20-M/01 Informa'#269'n'#237' technologie'
          'Vedouc'#237' MP: Mgr. Monika Pinkasov'#225
          'T'#233'ma: 91. S'#225'zkov'#225' kancel'#225#345
          ''
          'Zad'#225'n'#237' maturitn'#237' pr'#225'ce:'
          
            '  Aplikace realizuj'#237'c'#237' spr'#225'vu s'#225'zkov'#233' kancel'#225#345'e pro registrovan'#233 +
            ' s'#225'zka'#345'e a bookmakery '
          '  Zp'#367'sob zpracov'#225'n'#237' a pokyny k obsahu a rozsahu maturitn'#237' pr'#225'ce:'
          
            '  *) Program bude navr'#382'en jako aplikace s grafick'#253'm u'#382'ivatelsk'#253'm' +
            ' prost'#345'ed'#237'm v'#253'vojov'#233'ho prost'#345'edku Turbo C++'
          
            '  firmy Borland. Aplikace bude obsahovat modul pro registrovan'#233' ' +
            's'#225'zka'#345'e, kte'#345#237' budou zad'#225'vat a kontrolovat'
          
            '  sv'#233' s'#225'zky, vkl'#225'dat, '#269'i vyb'#237'rat sv'#233' pen'#237'ze, sledovat statistiky' +
            ' sv'#253'ch s'#225'zek. Modul pro bookmakery bude'
          
            '  umo'#382#328'ovat zad'#225'v'#225'n'#237' s'#225'zkov'#253'ch p'#345#237'le'#382'itosti a jejich kurzy. P'#345'eh' +
            'led s'#225'zkov'#253'ch p'#345#237'le'#382'itost'#237' a jejich'
          
            '  kurzy se budou b'#283'hem sv'#233' platnosti pravideln'#283' aktualizovat, v'#253 +
            'sledky a v'#253'hry automaticky vyhodnocovat.'
          
            '  Aplikace bude p'#345'ehledn'#225', velmi snadno a intuitivn'#283' obsluhovate' +
            'ln'#225', u'#382'ivatelsky p'#345#237'v'#283'tiv'#225'.'
          ''
          
            '  Vlastn'#237' p'#237'semn'#225' dokumentace bude obsahovat popis aplikace, zpr' +
            'acov'#225'n'#237' '#345'e'#353'en'#233' '#250'lohy, zvolen'#233' metody,'
          '  komponenty a postupy tvorby aplikace s jejich od'#367'vodn'#283'n'#237'm.'
          
            '  Rozsah p'#237'semn'#233' '#269#225'sti bude 8-12 normostran. Dokument bude zprac' +
            'ov'#225'n podle z'#225'kladn'#237'ch typografick'#253'ch z'#225'sad.'
          ''
          
            'P'#345#237'lohy pr'#225'ce:  CD se zdrojov'#253'mi soubory aplikace a p'#237'semn'#225' doku' +
            'mentace (*.doc),p'#237'semn'#225
          
            '                              '#269#225'st maturitn'#237' pr'#225'ce v ti'#353't'#283'n'#233' pod' +
            'ob'#283', souhrnn'#225' prezentace pr'#225'ce.'
          ''
          'Krit'#233'ria hodnocen'#237' maturitn'#237' pr'#225'ce:'
          
            #183#9'50 bod'#367' - obsah pr'#225'ce - spln'#283'n'#237' po'#382'adavk'#367' zad'#225'n'#237' pr'#225'ce, jej'#237' k' +
            'omplexnost,rozsah,'
          
            '                                    logick'#233' '#269'len'#283'n'#237' a uspo'#345#225'd'#225'n'#237 +
            ' v'#253'sledk'#367', originalita p'#345#237'stupu,'
          
            '                                    zhotoven'#237' v'#253'robku, aplikace,' +
            ' programu apod.'
          
            #183#9'20 bod'#367' - form'#225'ln'#237' str'#225'nka - spr'#225'vn'#233' pou'#382#237'v'#225'n'#237' term'#237'n'#367', dodr'#382'o' +
            'v'#225'n'#237' typografick'#253'ch pravidel a'
          
            '                                    technick'#253'ch norem, respektov' +
            #225'n'#237' norem pro citace a pou'#382'it'#233' zdroje,'
          
            '                                    stylistick'#225' '#250'rove'#328', grafick'#225 +
            ' str'#225'nka - vhodn'#225' grafick'#225' '#250'prava'
          
            '                                    (2D, 3D dokumentace, uplatn'#283 +
            'n'#237' estetick'#253'ch vztah'#367' z hlediska pr'#367'myslov'#233'ho'
          
            '                                    designu, apod.), celkov'#225' for' +
            'm'#225'ln'#237' kvalita odevzdan'#233' pr'#225'ce'
          
            #183#9'10 bod'#367' - p'#345#237'stup '#382#225'ka - aktivita studenta, iniciativa a tv'#367'r'#269 +
            #237' p'#345#237'stup, soustavnost pr'#225'ce, schopnost'
          
            '                                    komunikace, rozsah vyu'#382#237'v'#225'n'#237 +
            ' zdroj'#367' informac'#237
          #183#9'20 bod'#367' - prezentace a obhajoba pr'#225'ce'
          ''
          ''
          'P'#345'evod bodov'#233'ho hodnocen'#237' na klasifikaci:'
          
            '  Hodnocen'#237' obsahu pr'#225'ce, form'#225'ln'#237' str'#225'nky a prezentace s obhajo' +
            'bou prov'#225'd'#237' vedouc'#237' pr'#225'ce a oponent. '
          
            '  Sou'#269'et t'#283'chto bod'#367' se vyd'#283'l'#237' dv'#283'ma. K  tomuto bodov'#233'mu hodnoce' +
            'n'#237' se p'#345'ipo'#269'tou body za p'#345#237'stup '#382#225'ka'
          
            '  p'#345'id'#283'len'#233' jen vedouc'#237'm pr'#225'ce. Celkov'#253' bodov'#253' zisk se p'#345'evede n' +
            'a zn'#225'mku:'
          ''
          '  C = (Vo+Vf+Vpo+Oo+Of+Opo)/2+Vp'#382
          ''
          'Celkov'#253' po'#269'et bod'#367':'#9'Zn'#225'mka:'#9
          '        100 - 85'#9'1'
          '        84 - 69'#9'        2'
          '        68 - 49'#9'        3'
          '        48 - 33'#9'        4'
          '        32 - 0'#9'        5'
          
            'Obhajovat nelze pr'#225'ce, u kter'#253'ch bylo zji'#353't'#283'no plagi'#225'torstv'#237' neb' +
            'o sou'#269'et bod'#367', za hodnocen'#237' obsahu pr'#225'ce a '
          
            'form'#225'ln'#237' str'#225'nky pr'#225'ce je men'#353#237' nebo roven 20 bod'#367'm.[ (Vo+Vf+Oo+' +
            'Of)/2 ? 20] Tyto pr'#225'ce budou'
          
            #382#225'k'#367'm vr'#225'ceny k p'#345'epracov'#225'n'#237' a jejich obhajoby se budou konat v ' +
            'dal'#353#237'm maturitn'#237'm term'#237'nu.'
          ''
          '        Po'#269'et vyhotoven'#237' maturitn'#237' pr'#225'ce: 2 vyhotoven'#237
          '        Term'#237'n zad'#225'n'#237' maturitn'#237' pr'#225'ce: 17. prosinec 2012'
          '        Term'#237'n odevzd'#225'n'#237' maturitn'#237' pr'#225'ce: 2. duben 2013'
          'Ostrava 14. prosinec 2012'
          'Ing. Jaroslav KR'#193'L'
          #345'editel '#353'koly')
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
        WantTabs = True
      end
    end
  end
end
