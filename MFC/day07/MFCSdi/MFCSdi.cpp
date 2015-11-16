// MFCSdi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"


class CMyView:public CEditView{
DECLARE_DYNCREATE(CMyView)

};
IMPLEMENT_DYNCREATE(CMyView,CEditView)

class CMyDoc:public CDocument{
DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)

class CMyFrameWnd:public CFrameWnd{
DECLARE_DYNCREATE(CMyFrameWnd)
};
IMPLEMENT_DYNCREATE(CMyFrameWnd,CFrameWnd)

class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;

BOOL CMyWinApp::InitInstance(){
	//创建当文档模板对象
	CSingleDocTemplate* pTemplate = new CSingleDocTemplate(
		IDR_MENU1,
		RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CMyFrameWnd),
		RUNTIME_CLASS(CMyView));

	//将文档模板添加到应用程序
	AddDocTemplate(pTemplate);
	
	OnFileNew();

	m_pMainWnd->ShowWindow(SW_MAXIMIZE);
	m_pMainWnd->UpdateWindow();



	return true;	
}
