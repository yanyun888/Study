; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgModeless
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sdi.h"
LastPage=0

ClassCount=7
Class1=CSdiApp
Class2=CSdiDoc
Class3=CSdiView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CDlgModel
Resource3=IDD_ABOUTBOX
Class7=CDlgModeless
Resource4=IDD_DIALOG2

[CLS:CSdiApp]
Type=0
HeaderFile=Sdi.h
ImplementationFile=Sdi.cpp
Filter=N

[CLS:CSdiDoc]
Type=0
HeaderFile=SdiDoc.h
ImplementationFile=SdiDoc.cpp
Filter=N

[CLS:CSdiView]
Type=0
HeaderFile=SdiView.h
ImplementationFile=SdiView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Sdi.cpp
ImplementationFile=Sdi.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_DLG_MODEL
Command18=ID_DLG_MODELESS
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgModel
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlgModel]
Type=0
HeaderFile=DlgModel.h
ImplementationFile=DlgModel.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgModel

[DLG:IDD_DIALOG2]
Type=1
Class=CDlgModeless
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlgModeless]
Type=0
HeaderFile=DlgModeless.h
ImplementationFile=DlgModeless.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgModeless
VirtualFilter=dWC

