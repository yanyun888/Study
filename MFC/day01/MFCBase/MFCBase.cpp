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
	AfxMessageBox("��ʼ��");
	return CWinApp::InitApplication();
	//���������Ƿ��ƻ��Ը���(�����˸�����麯��)
}

int CMyWinApp::Run(){
	AfxMessageBox("��Ϣѭ��");
	return CWinApp::Run();
}

BOOL CMyWinApp::OnIdle(LONG lCount){
	//AfxMessageBox("���д���");
	return CWinApp::OnIdle(lCount);

}
int CMyWinApp::ExitInstance(){
	AfxMessageBox("�ƺ���");
	return CWinApp::ExitInstance();
}



BOOL CMyWinApp::InitInstance(){
	//�˺�����thisΪtheApp
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL,"MFCBase");
	m_pMainWnd = pFrame;
	//theApp.m_pMainWnd
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}

//ȫ�ֶ���(���Ƶ�)
CMyWinApp theApp;
