; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPage1
LastTemplate=CPropertySheet
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sdi.h"
LastPage=0

ClassCount=8
Class1=CSdiApp
Class2=CSdiDoc
Class3=CSdiView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_PAGE1
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX
Class6=CPage1
Class7=CPage2
Class8=CSetSheet
Resource4=IDD_PAGE2

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
BaseClass=CView
VirtualFilter=VWC
LastObject=CSdiView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_PROPERTY_SHEET




[CLS:CAboutDlg]
Type=0
HeaderFile=Sdi.cpp
ImplementationFile=Sdi.cpp
Filter=D
LastObject=CAboutDlg

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
Command17=ID_PROPERTY_SHEET
CommandCount=17

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

[DLG:IDD_PAGE1]
Type=1
Class=CPage1
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_LINE_WIDTH,edit,1350631552

[DLG:IDD_PAGE2]
Type=1
Class=CPage2
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_SETCOLOR,button,1342242816

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPage1
VirtualFilter=idWC

[CLS:CPage2]
Type=0
HeaderFile=Page2.h
ImplementationFile=Page2.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPage2
VirtualFilter=idWC

[CLS:CSetSheet]
Type=0
HeaderFile=SetSheet.h
ImplementationFile=SetSheet.cpp
BaseClass=CPropertySheet
Filter=W

