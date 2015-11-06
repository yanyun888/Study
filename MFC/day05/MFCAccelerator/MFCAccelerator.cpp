// MFCAccelerator.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

class CMyFrameWnd:public CFrameWnd{
DECLARE_MESSAGE_MAP()


protected:
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_COMMAND(ID_NEW,OnNew)
END_MESSAGE_MAP()

class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMSG);
};

CMyWinApp theApp;

BOOL CMyWinApp::PreTranslateMessage(MSG* pMSG){
	HACCEL hAccel = ::LoadAccelerators(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDR_ACCELERATOR1));
	int nRet = ::TranslateAccelerator(
		this->m_pMainWnd->m_hWnd, hAccel, pMSG);
	if(nRet == 0)
		return false;
	return true;
}


void CMyFrameWnd::OnNew(){
	AfxMessageBox("New Clicked!");
}


BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	m_pMainWnd = pFrame;
	pFrame->Create(NULL,"MFC Acc",WS_OVERLAPPEDWINDOW,CFrameWnd::rectDefault,
		NULL,MAKEINTRESOURCE(IDR_MENU1));
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	
	
	


	return true;
}


