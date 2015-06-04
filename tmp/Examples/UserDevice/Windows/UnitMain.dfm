object FormMain: TFormMain
  Left = 1154
  Top = 299
  BorderStyle = bsSingle
  Caption = 'UxDIL - User Device Demo'
  ClientHeight = 276
  ClientWidth = 329
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
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 152
    Width = 256
    Height = 13
    Caption = 'Received (converted) string from device (bulk transfer)'
  end
  object LabelData: TLabel
    Left = 8
    Top = 168
    Width = 45
    Height = 16
    Caption = '(none)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHotLight
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LabelVersion: TLabel
    Left = 216
    Top = 48
    Width = 9
    Height = 16
    Caption = '?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHotLight
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 257
    Width = 329
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = '(c) 2011 Reusch Elektronik'
  end
  object ButtonOpen: TButton
    Left = 8
    Top = 8
    Width = 193
    Height = 25
    Caption = '&Open Device'
    TabOrder = 1
    OnClick = ButtonOpenClick
  end
  object ButtonVersion: TButton
    Left = 8
    Top = 40
    Width = 193
    Height = 25
    Caption = 'Firmware &Version (control transfer)'
    TabOrder = 2
    OnClick = ButtonVersionClick
  end
  object LabeledEdit1: TLabeledEdit
    Left = 8
    Top = 88
    Width = 289
    Height = 21
    EditLabel.Width = 77
    EditLabel.Height = 13
    EditLabel.Caption = 'String for device'
    LabelPosition = lpAbove
    LabelSpacing = 3
    MaxLength = 31
    TabOrder = 3
  end
  object ButtonClose: TButton
    Left = 8
    Top = 192
    Width = 193
    Height = 25
    Caption = '&Close Device'
    TabOrder = 4
    OnClick = ButtonCloseClick
  end
  object ButtonExit: TButton
    Left = 8
    Top = 224
    Width = 193
    Height = 25
    Caption = 'E&xit'
    TabOrder = 5
    OnClick = ButtonExitClick
  end
  object ButtonTransfer: TButton
    Left = 8
    Top = 120
    Width = 193
    Height = 25
    Caption = 'Convert &String (bulk transfer)'
    TabOrder = 6
    OnClick = ButtonTransferClick
  end
end
