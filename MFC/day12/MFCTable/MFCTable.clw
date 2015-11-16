; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialog1
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCTable.h"

ClassCount=5
Class1=CMFCTableApp
Class2=CMFCTableDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Resource4=IDD_MFCTABLE_DIALOG
Class4=CDialog2
Class5=CDialog1
Resource5=IDD_DIALOG2

[CLS:CMFCTableApp]
Type=0
HeaderFile=MFCTable.h
ImplementationFile=MFCTable.cpp
Filter=N

[CLS:CMFCTableDlg]
Type=0
HeaderFile=MFCTableDlg.h
ImplementationFile=MFCTableDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCTableDlg.h
ImplementationFile=MFCTableDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFCTABLE_DIALOG]
Type=1
Class=CMFCTableDlg
ControlCount=1
Control1=IDC_TAB,SysTabControl32,1342177280

[DLG:IDD_DIALOG1]
Type=1
Class=CDialog1
ControlCount=3
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG2]
Type=1
Class=CDialog2
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDialog2]
Type=0
HeaderFile=Dialog2.h
ImplementationFile=Dialog2.cpp
BaseClass=CDialog
Filter=D

[CLS:CDialog1]
Type=0
HeaderFile=Dialog1.h
ImplementationFile=Dialog1.cpp
BaseClass=CDialog
Filter=D

