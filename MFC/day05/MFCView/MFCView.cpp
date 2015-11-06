// MFCView.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

class CMyView:public CView{
DECLARE_MESSAGE_MAP()
protected:
	virtual void OnDraw(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyView,CView)
	ON_COMMAND(ID_NEW,OnNew)
END_MESSAGE_MAP()

class CMyFrameWnd:public CFrameWnd{
DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CMyView::OnNew(){
	AfxMessageBox("View class is handling new button clicked.");
}


void CMyView::OnPaint(){
//	CView::OnPaint();
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hWnd,&ps);
	::TextOut(hdc,200,200,"Hello1",6);
	::EndPaint(m_hWnd,&ps);
}

void CMyView::OnDraw(CDC* pDC){

	pDC->TextOut(100,100,"CMyView::OnDraw");
}


int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct){
	CMyView* pView = new CMyView;
	pView->Create(NULL,"",WS_CHILD|WS_VISIBLE|WS_BORDER,
		CRect(0,0,200,200),this,AFX_IDW_PANE_FIRST);
	m_pViewActive = pView;
	return CFrameWnd::OnCreate(lpCreateStruct);
}

void CMyFrameWnd::OnPaint(){
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hWnd,&ps);
	::TextOut(hdc,100,100,"Hello",5);
	::EndPaint(m_hWnd,&ps);

}

class CMyWinApp:public CWinApp{

public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;

BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL,"MFCView",WS_OVERLAPPEDWINDOW,CFrameWnd::rectDefault,
		NULL,MAKEINTRESOURCE(IDR_MENU1));
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}


