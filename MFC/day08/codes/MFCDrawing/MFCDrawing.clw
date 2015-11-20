; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFCDrawingView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCDrawing.h"
LastPage=0

ClassCount=5
Class1=CMFCDrawingApp
Class2=CMFCDrawingDoc
Class3=CMFCDrawingView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CMFCDrawingApp]
Type=0
HeaderFile=MFCDrawing.h
ImplementationFile=MFCDrawing.cpp
Filter=N

[CLS:CMFCDrawingDoc]
Type=0
HeaderFile=MFCDrawingDoc.h
ImplementationFile=MFCDrawingDoc.cpp
Filter=N

[CLS:CMFCDrawingView]
Type=0
HeaderFile=MFCDrawingView.h
ImplementationFile=MFCDrawingView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_GDI_RGN


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=MFCDrawing.cpp
ImplementationFile=MFCDrawing.cpp
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
Command17=ID_DC
Command18=ID_DC_WINDOW
Command19=ID_DC_CLIENT
Command20=ID_DC_META
Command21=ID_GDI_PEN
Command22=ID_GDI_BRUSH
Command23=ID_GDI_FONT
Command24=ID_GDI_BMP
Command25=ID_GDI_RGN
CommandCount=25

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

