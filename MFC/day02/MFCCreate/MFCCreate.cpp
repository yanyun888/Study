// MFCCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

class CMyFrameWnd:public CFrameWnd{
public:
	virtual LRESULT WindowProc(UINT message,
		WPARAM wParam,LPARAM lParam);
private:
	int m_posX;
	int m_posY;
	void OnMouseMove(HWND hWnd,WPARAM wParam,LPARAM lParam);
	void OnPaint(HWND hWnd,WPARAM wParam,LPARAM lParam);
};

class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;
void CMyFrameWnd::OnPaint(HWND hWnd,WPARAM wParam,LPARAM lParam){
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(this->m_hWnd,&ps);
	::TextOut(hdc,m_posX-30,m_posY-10,"hello",5);
	::EndPaint(this->m_hWnd,&ps);

}

void CMyFrameWnd::OnMouseMove(HWND hWnd,WPARAM wParam,LPARAM lParam){
	m_posX = LOWORD(lParam);
	m_posY = HIWORD(lParam);
	::InvalidateRect(m_hWnd,NULL,true);
}

LRESULT CMyFrameWnd::WindowProc(UINT message,
								WPARAM wParam,LPARAM lParam){
	// 此函数的this指针为pFrame
	
	switch(message){
	case WM_MOUSEMOVE:
		OnMouseMove(m_hWnd,wParam,lParam);
		break;
	case WM_PAINT:
		OnPaint(m_hWnd,wParam,lParam);
		break;
	case WM_CREATE:
		//AfxMessageBox("WM_CREATE");
		break;
	}
	return CFrameWnd::WindowProc(message,wParam,lParam);
}



BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame -> Create(NULL,"MFCCreate");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}


	



