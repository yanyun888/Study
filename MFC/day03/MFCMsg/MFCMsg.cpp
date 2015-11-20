// MFCMsg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

class CMyFrameWnd:public CFrameWnd{
private:
	POINT m_pos;
	int m_posX;
	int m_posY;
/*
//宏的展开
private:
	static const AFX_MSGMAP_ENTRY _messageEntries[];
protected:
	static AFX_DATA const AFX_MSGMAP messageMap;
	virtual const AFX_MSGMAP* GetMessageMap() const;
	*/
	DECLARE_MESSAGE_MAP()
public:
	CMyFrameWnd();
private:
	LRESULT OnCreate(WPARAM wParam,LPARAM lParam);
	LRESULT OnPaint(WPARAM wParam,LPARAM lParam);
	LRESULT OnMouseMove(WPARAM wParam,LPARAM lParam);
};

/*
//实现虚函数
const AFX_MSGMAP* CMyFrameWnd::GetMessageMap() const{
	return &CMyFrameWnd::messageMap;
} 
//给静态成员赋值
AFX_COMDAT AFX_DATADEF const AFX_MSGMAP CMyFrameWnd::messageMap = {
	&CFrameWnd::messageMap, 
	&CMyFrameWnd::_messageEntries[0]
};
//给静态数组赋值
AFX_COMDAT const AFX_MSGMAP_ENTRY CMyFrameWnd::_messageEntries[] ={
	//ON_MESSAGE(WM_CREATE,OnCreate)
	{WM_CREATE, 0, 0, 0, AfxSig_lwl,
	(AFX_PMSG)(AFX_PMSGW)(LRESULT (AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM))&OnCreate},
	{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
}; 
*/

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_MESSAGE(WM_PAINT,OnPaint)
	ON_MESSAGE(WM_CREATE,OnCreate)
	ON_MESSAGE(WM_MOUSEMOVE,OnMouseMove)
END_MESSAGE_MAP()

CMyFrameWnd::CMyFrameWnd(){
	m_pos.x = 100;
	m_pos.y = 100;
	//= POINT(100,100);
}


LRESULT CMyFrameWnd::OnCreate(WPARAM wParam,LPARAM lParam){
	// 次函数中的this为pFrame
//	AfxMessageBox("CMyFrameWnd::OnCreate");
//	m_pos.x = 100;
//	m_pos.y= 100;
	return 0;
}

LRESULT CMyFrameWnd::OnPaint(WPARAM wParam,LPARAM lParam){
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hWnd,&ps);
	::TextOut(hdc,m_pos.x,m_pos.y,"Hello",5);
	::EndPaint(m_hWnd,&ps);
	return 0;
}

LRESULT CMyFrameWnd::OnMouseMove(WPARAM wParam,LPARAM lParam){
	if(wParam == MK_LBUTTON){
		m_pos.x = LOWORD(lParam);
		m_pos.y = HIWORD(lParam);
		::InvalidateRect(m_hWnd,NULL,true);
	}
	
	return 0;
}

class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;
BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL,"MFC msg");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}

