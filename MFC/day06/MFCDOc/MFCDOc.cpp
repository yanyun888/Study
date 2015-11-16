// MFCDOc.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"


class CMyDoc:public CDocument{
public:
	CMyDoc(){
		m_strData = "Hello World!";
	}
	CString m_strData;
DECLARE_MESSAGE_MAP()
	afx_msg void OnTest();
};
BEGIN_MESSAGE_MAP(CMyDoc,CDocument)
	ON_COMMAND(ID_TEST,OnTest)
END_MESSAGE_MAP()

class CMyView:public CEditView{
//支持动态创建
DECLARE_DYNCREATE(CMyView)
public:
	virtual void OnInitialUpdate();
};
IMPLEMENT_DYNCREATE(CMyView,CEditView)

class CMyFrameWnd:public CFrameWnd{
DECLARE_MESSAGE_MAP()

};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
END_MESSAGE_MAP()

class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;


void CMyDoc::OnTest(){
	AfxMessageBox("OnText function!");
}

void CMyView::OnInitialUpdate(){
	//获取与视图所关联的文档
	CMyDoc* pDoc = (CMyDoc*)GetDocument();
	//获取文档中的数据
	SetWindowText(pDoc->m_strData);
}

BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	m_pMainWnd = pFrame;
//	pFrame->Create(NULL,"MFC_Doc");
	CCreateContext cxt;
	cxt.m_pNewViewClass = RUNTIME_CLASS(CMyView);
	cxt.m_pCurrentDoc = new CMyDoc;
	pFrame->LoadFrame(IDR_MENU1,WS_OVERLAPPEDWINDOW,NULL,&cxt);
	pFrame->InitialUpdateFrame(NULL,true);
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}

