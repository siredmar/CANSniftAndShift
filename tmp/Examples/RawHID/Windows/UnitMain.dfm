object Form1: TForm1
  Left = 580
  Top = 408
  BorderStyle = bsSingle
  Caption = 'RawHID Example'
  ClientHeight = 188
  ClientWidth = 697
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonOpen: TButton
    Left = 8
    Top = 8
    Width = 145
    Height = 25
    Caption = 'Open Device'
    TabOrder = 0
    OnClick = ButtonOpenClick
  end
  object ButtonData: TButton
    Left = 8
    Top = 72
    Width = 145
    Height = 25
    Caption = 'Data Transfer'
    TabOrder = 1
    OnClick = ButtonDataClick
  end
  object ButtonClose: TButton
    Left = 8
    Top = 104
    Width = 145
    Height = 25
    Caption = 'Close Device'
    TabOrder = 2
    OnClick = ButtonCloseClick
  end
  object ListBox1: TListBox
    Left = 160
    Top = 8
    Width = 529
    Height = 153
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Lucida Console'
    Font.Style = []
    ItemHeight = 11
    ParentFont = False
    TabOrder = 3
  end
  object ButtonExit: TButton
    Left = 8
    Top = 136
    Width = 145
    Height = 25
    Caption = 'Exit'
    TabOrder = 4
    OnClick = ButtonExitClick
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 169
    Width = 697
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = '(c) Reusch Elektronik, http://products.reworld.eu/index.htm'
  end
  object ButtonSize: TButton
    Left = 8
    Top = 40
    Width = 145
    Height = 25
    Caption = 'Raw Data Sizes'
    TabOrder = 6
    OnClick = ButtonSizeClick
  end
end
