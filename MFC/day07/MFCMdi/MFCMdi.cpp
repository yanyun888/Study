// MFCMdi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

class CMyDoc:public CDocument{
DECLARE_DYNCREATE(CMyDoc)
protected:
public:
	CString m_strData;//������ͼ������
	

};
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)

class CMyView:public CEditView{
DECLARE_DYNCREATE(CMyView)
protected:
	afx_msg void OnEnChange();
	virtual void OnUpdate(CView* pSender,LPARAM lHint,CObject* pHint ); 
DECLARE_MESSAGE_MAP()
};
IMPLEMENT_DYNCREATE(CMyView,CEditView)
BEGIN_MESSAGE_MAP(CMyView,CEditView)
	ON_CONTROL_REFLECT(EN_CHANGE,OnEnChange)
END_MESSAGE_MAP()

//���ĵ����ӿ�ܴ�����
class CChildFrame:public CMDIChildWnd{

protected:
	afx_msg void OnNewWnd();
DECLARE_DYNCREATE(CChildFrame)
DECLARE_MESSAGE_MAP()
};
IMPLEMENT_DYNCREATE(CChildFrame,CMDIChildWnd)
BEGIN_MESSAGE_MAP(CChildFrame,CMDIChildWnd)
	ON_COMMAND(ID_NEW_WND,OnNewWnd)
END_MESSAGE_MAP()

//���ĵ�������ܴ����� - ����Ҫ֧�ֶ�̬����
class CMainFrame:public CMDIFrameWnd{
};

class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
protected:
	afx_msg void OnNew();
DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMyWinApp,CWinApp)
	ON_COMMAND(ID_NEW,OnNew)
END_MESSAGE_MAP()

CMyWinApp theApp;



void CMyView::OnUpdate(CView* pSender,LPARAM lHint,CObject* pHint){
	CMyDoc* pDoc = (CMyDoc*)GetDocument();
	SetWindowText(pDoc->m_strData);
//	pDoc->UpdateAllViews(this);	
}


void CMyView::OnEnChange(){
	CMyDoc* pDoc = (CMyDoc*)GetDocument();
	GetWindowText(pDoc->m_strData);
	pDoc->UpdateAllViews(this);	
}

void CChildFrame::OnNewWnd(){
	//��ȡ����ӿ������Ӧ����ͼ
	CDocument* pDoc = GetActiveDocument();
	
	//��ȡ�ĵ���Ӧ���ĵ�ģ�壬ʹ��ģ�崴���´���
	CDocTemplate* pTemplate=pDoc->GetDocTemplate();
	// ʹ���ĵ�ģ�崴���ӿ�ܴ���
	CFrameWnd* pChildFrame = pTemplate->CreateNewFrame(pDoc,NULL);
	pChildFrame->InitialUpdateFrame(pDoc,true);
}

void CMyWinApp::OnNew(){
	OnFileNew();
}

BOOL CMyWinApp::InitInstance(){
	CMainFrame* pFrame = new CMainFrame;
	pFrame->LoadFrame(IDR_MAINFRAME);
	m_pMainWnd = pFrame;
	CMultiDocTemplate* pTemplate = new CMultiDocTemplate(
		IDR_CHILDFRAME,
		RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CMyView));
	AddDocTemplate(pTemplate);

	OnFileNew();

	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return true;
}


