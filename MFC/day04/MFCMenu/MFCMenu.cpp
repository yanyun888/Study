// MFCMenu.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

class CMyFrameWnd: public CFrameWnd{
	DECLARE_MESSAGE_MAP()
private:
	afx_msg void OnNew(void);
	afx_msg void OnExit(void);
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnInitMenuPopup(CMenu* pPopup,UINT nPos,BOOL i);
	afx_msg void OnContextMenu(CWnd* pWnd,CPoint pt);

};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CONTEXTMENU()
	ON_WM_INITMENUPOPUP()
	ON_WM_CREATE()
	ON_COMMAND(ID_NEW,OnNew)
	ON_COMMAND(ID_EXIT,OnExit)
END_MESSAGE_MAP()

void CMyFrameWnd::OnContextMenu(CWnd* pWnd,CPoint pt){
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pPopup = menu.GetSubMenu(0); // 
	/*
	::TrackPopupMenu(pPopup->m_hMenu,TPM_CENTERALIGN|TPM_VCENTERALIGN,
		pt.x, pt.y ,0,pWnd->m_hWnd,NULL);
	*/
	pPopup->TrackPopupMenu(TPM_CENTERALIGN|TPM_VERTICAL,pt.x , pt.y, pWnd);
}

void CMyFrameWnd::OnInitMenuPopup(CMenu* pPopMenu,UINT nPos,BOOL i){
	/*
	::CheckMenuItem(pPopMenu->m_hMenu,ID_NEW,MF_BYCOMMAND|MF_CHECKED);
	::EnableMenuItem(pPopMenu->m_hMenu,ID_EXIT,MF_BYCOMMAND|MF_GRAYED);
	*/
	pPopMenu->CheckMenuItem(ID_NEW,MF_CHECKED);
	pPopMenu->EnableMenuItem(ID_EXIT,MF_GRAYED);
	
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs){
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	SetMenu(&menu);
	return CFrameWnd::OnCreate(pcs);
}

void CMyFrameWnd::OnNew(){
	AfxMessageBox("FrameWnd class is processing New Button Clicked");
}
void CMyFrameWnd::OnExit(){
//	AfxMessageBox("FrameWnd Class is processing Exit Button");
	PostQuitMessage(0);
}


class CMyWinApp: public CWinApp{
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
private:
	afx_msg void OnNew();
	//afx_msg void OnExit();
};
BEGIN_MESSAGE_MAP(CMyWinApp,CWinApp)
	ON_COMMAND(ID_NEW,OnNew)
//	ON_COMMAND(ID_EXIT,OnExit)
END_MESSAGE_MAP()

void CMyWinApp::OnNew(){
	AfxMessageBox("App class is processing WM_NEW");
}

CMyWinApp theApp;
BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	pFrame->Create(NULL,"MFC menu");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}

