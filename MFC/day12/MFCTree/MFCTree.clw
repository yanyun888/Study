; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFCTreeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCTree.h"

ClassCount=3
Class1=CMFCTreeApp
Class2=CMFCTreeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFCTREE_DIALOG

[CLS:CMFCTreeApp]
Type=0
HeaderFile=MFCTree.h
ImplementationFile=MFCTree.cpp
Filter=N

[CLS:CMFCTreeDlg]
Type=0
HeaderFile=MFCTreeDlg.h
ImplementationFile=MFCTreeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TREE

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCTreeDlg.h
ImplementationFile=MFCTreeDlg.cpp
Filter=D
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFCTREE_DIALOG]
Type=1
Class=CMFCTreeDlg
ControlCount=7
Control1=IDC_TREE,SysTreeView32,1350631431
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NAME,edit,1350631552
Control4=IDC_INSERT_ROOT,button,1342242816
Control5=IDC_INSERT_CHILD,button,1342242816
Control6=IDC_DEL,button,1342242816
Control7=IDC_EDIT,button,1342242816

