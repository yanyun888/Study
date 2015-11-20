; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCThread.h"

ClassCount=5
Class1=CMFCThreadApp
Class2=CMFCThreadDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyThread
Resource3=IDD_MFCTHREAD_DIALOG
Class5=CMyDialog
Resource4=IDD_DIALOG1

[CLS:CMFCThreadApp]
Type=0
HeaderFile=MFCThread.h
ImplementationFile=MFCThread.cpp
Filter=N

[CLS:CMFCThreadDlg]
Type=0
HeaderFile=MFCThreadDlg.h
ImplementationFile=MFCThreadDlg.cpp
Filter=D
LastObject=IDC_EDIT1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCThreadDlg.h
ImplementationFile=MFCThreadDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFCTHREAD_DIALOG]
Type=1
Class=CMFCThreadDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_WORKER,button,1342242816
Control4=IDC_UI,button,1342242816
Control5=IDC_LIST,listbox,1352728835

[CLS:CMyThread]
Type=0
HeaderFile=MyThread.h
ImplementationFile=MyThread.cpp
BaseClass=CWinThread
Filter=N

[DLG:IDD_DIALOG1]
Type=1
Class=CMyDialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CMyDialog]
Type=0
HeaderFile=MyDialog.h
ImplementationFile=MyDialog.cpp
BaseClass=CDialog
Filter=D

