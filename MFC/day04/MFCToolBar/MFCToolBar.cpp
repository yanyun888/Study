// MFCToolBar.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

UINT g_hIndicator[] = {
	0,
	IDS_TIME,
	IDS_POS
};

class CMyFrameWnd:public CFrameWnd{
DECLARE_MESSAGE_MAP()
public:
private:
	CToolBar toolbar;
	CMenu m_menu;
	CStatusBar m_statusbar;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNew(void);
	afx_msg void OnSet(void);
	afx_msg void OnTool(void);
	afx_msg void OnInitMenuPopup(CMenu* pPopMenu,UINT nPos,BOOL i);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags,CPoint pt);
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_INITMENUPOPUP()
	ON_COMMAND(ID_SET,OnSet)
	ON_WM_CREATE()
	ON_COMMAND(ID_NEW,OnNew)
	ON_COMMAND(ID_TOOL,OnTool)
END_MESSAGE_MAP()

void CMyFrameWnd::OnMouseMove(UINT nFlags,CPoint pt){
	CString str;
	str.Format("key=%d,(x,y)=(%d,%d)",nFlags,pt.x,pt.y);
	m_statusbar.SetPaneText(2,str);
}

void CMyFrameWnd::OnTimer(UINT nIDEvent){
	SYSTEMTIME st = {0};
	::GetLocalTime(&st);
	
	CString str;
	str.Format("%d-%d-%d  %02d:%02d:%02d",st.wYear,st.wMonth,st.wDay,
		st.wHour,st.wMinute,st.wSecond);
	m_statusbar.SetPaneText(1,str);

}

void CMyFrameWnd::OnTool(void){
	if( toolbar.IsWindowVisible() )
		ShowControlBar(&toolbar,false,true);
	else
		ShowControlBar(&toolbar,true,true);
	
}

void CMyFrameWnd::OnInitMenuPopup(CMenu* pPopMenu,UINT nPos,BOOL i){
	if(toolbar.IsWindowVisible())
		pPopMenu->CheckMenuItem(ID_TOOL,MF_CHECKED);
	else
		pPopMenu->CheckMenuItem(ID_TOOL,MF_UNCHECKED);
	//pPopMenu->EnableMenuItem(ID_EXIT,MF_GRAYED);	
}

void CMyFrameWnd::OnSet(void){
	AfxMessageBox("Set button clicked");
}

void CMyFrameWnd::OnNew(void){
	AfxMessageBox("menu New clicked");
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct){
	toolbar.CreateEx(this,TBSTYLE_FLAT,WS_CHILD|WS_VISIBLE|
		CBRS_ALIGN_TOP|CBRS_GRIPPER|CBRS_SIZE_DYNAMIC|CBRS_TOOLTIPS|CBRS_FLYBY);
	toolbar.LoadToolBar(IDR_TOOLBAR1);
	toolbar.EnableDocking(CBRS_ALIGN_ANY);
	toolbar.SetWindowText("tool");

	m_menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_menu);

	m_statusbar.CreateEx(this);
	m_statusbar.SetIndicators(g_hIndicator,3);
	m_statusbar.SetPaneInfo(1,IDS_TIME,SBPS_POPOUT,200);
	m_statusbar.SetPaneInfo(2,IDS_POS,SBPS_NORMAL,200);
	::SetTimer(this->m_hWnd,1,1000,NULL);


	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&toolbar ,AFX_IDW_DOCKBAR_TOP);

	return CFrameWnd::OnCreate(lpCreateStruct);
}

class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
};


CMyWinApp theApp;

BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL,"MFCToolBar",WS_OVERLAPPEDWINDOW,
		CFrameWnd::rectDefault,NULL/*,MAKEINTRESOURCE(IDR_MENU1)*/);
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}



