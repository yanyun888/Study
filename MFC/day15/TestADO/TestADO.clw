; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestADODlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TestADO.h"

ClassCount=3
Class1=CTestADOApp
Class2=CTestADODlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TESTADO_DIALOG

[CLS:CTestADOApp]
Type=0
HeaderFile=TestADO.h
ImplementationFile=TestADO.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CTestADODlg]
Type=0
HeaderFile=TestADODlg.h
ImplementationFile=TestADODlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TestADODlg.h
ImplementationFile=TestADODlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TESTADO_DIALOG]
Type=1
Class=CTestADODlg
ControlCount=4
Control1=IDC_LIST,SysListView32,1350631425
Control2=IDC_OPEN_DB,button,1342242816
Control3=IDC_OPEN_TABLE,button,1342242816
Control4=IDC_SHOW,button,1342242816

