// MFCBase.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

class CMyFrameWnd : public CFrameWnd{
public:



};
class CMyWinApp : public CWinApp{
public:
	CMyWinApp();
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	/*virtual*/ int Run();
	virtual BOOL OnIdle(LONG lCount);
	virtual int ExitInstance();
};

CMyWinApp::CMyWinApp(){

}


BOOL CMyWinApp::InitApplication(){
	AfxMessageBox("初始化");
	return CWinApp::InitApplication();
	//这里做的是非破坏性更改(调用了父类的虚函数)
}

int CMyWinApp::Run(){
	AfxMessageBox("消息循环");
	return CWinApp::Run();
}

BOOL CMyWinApp::OnIdle(LONG lCount){
	//AfxMessageBox("空闲处理");
	return CWinApp::OnIdle(lCount);

}
int CMyWinApp::ExitInstance(){
	AfxMessageBox("善后处理");
	return CWinApp::ExitInstance();
}



BOOL CMyWinApp::InitInstance(){
	//此函数的this为theApp
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL,"MFCBase");
	m_pMainWnd = pFrame;
	//theApp.m_pMainWnd
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}

//全局对象(爆破点)
CMyWinApp theApp;
