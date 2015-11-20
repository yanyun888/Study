// MFCCmd.cpp : Defines the entry point for the application.
//
WM_CREATE
#include "stdafx.h"
#define WM_MYMESSAGE WM_USER+1001

class CMyFrameWnd:public CFrameWnd{
	CPoint m_mousepoint;

	DECLARE_MESSAGE_MAP()
		//afx_msg 是一个占位符，用于指示该函数的功能是处理消息的
	afx_msg int OnCreate( LPCREATESTRUCT pcs);
	afx_msg void OnPaint( );
	afx_msg void OnMouseMove(UINT nFlags,CPoint point);
	afx_msg LRESULT OnMyMessage(WPARAM wParam,LPARAM lParam);
	afx_msg void OnOkBtn(void);
	afx_msg void OnEnChange(void);
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_EN_CHANGE(1002,OnEnChange)
	ON_COMMAND(1001,OnOkBtn)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MYMESSAGE,OnMyMessage)
END_MESSAGE_MAP()

void CMyFrameWnd::OnEnChange(){
	AfxMessageBox("内容被修改");
}

void CMyFrameWnd::OnOkBtn(void){
	AfxMessageBox("OK clicked");
}

LRESULT CMyFrameWnd::OnMyMessage(WPARAM wParam,LPARAM lParam){
	CString str;
	str.Format("自定义消息被处理wParam=%d,lParam=%d",wParam,lParam);
	AfxMessageBox(str);
	return 0;
}
void CMyFrameWnd::OnMouseMove(UINT nFlags,CPoint point){
	if(nFlags == MK_LBUTTON){
		m_mousepoint = point;
		::InvalidateRect(m_hWnd,NULL,true);
	}
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs){
	//AfxMessageBox("CMyFrameWnd");
	//::PostMessage(m_hWnd,WM_MYMESSAGE,1,2);
	::CreateWindowEx(0,"BUTTON","OK",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
		100,100,100,40,m_hWnd,(HMENU)1001,AfxGetInstanceHandle(),NULL);
	::CreateWindowEx(0,"EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,
		400,100,100,100,m_hWnd,(HMENU)1002,AfxGetInstanceHandle(),NULL);
	m_mousepoint = CPoint(100,400);
	return CFrameWnd::OnCreate(pcs);
}
void CMyFrameWnd::OnPaint(){
	PAINTSTRUCT ps;
	HDC hdc = ::BeginPaint(m_hWnd,&ps);
	::TextOut(hdc,m_mousepoint.x,m_mousepoint.y,"Hello",5);
	::EndPaint(m_hWnd,&ps);
}


class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;

BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL,"MFCCmd");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}



