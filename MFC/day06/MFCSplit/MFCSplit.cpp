// MFCSplit.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <afxhtml.h>




class CMyView:public CView{
DECLARE_DYNCREATE(CMyView)
public:
	virtual void OnDraw(CDC* pDC);	
};
IMPLEMENT_DYNCREATE(CMyView,CView)


class CMyFrameWnd:public CFrameWnd{
public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs,CCreateContext* pContext); 
	CSplitterWnd m_wndSplit; // �зִ��ڶ���
	CSplitterWnd m_wndSplit2;
};
class CMyWinApp:public CWinApp{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;

BOOL CMyFrameWnd::OnCreateClient(LPCREATESTRUCT lpcs,CCreateContext* pContext){

#if 0  // ������̬�зִ��� 
	//1 ָ������Ҫ����ͼ��
	CCreateContext cxt;
	cxt.m_pNewViewClass = RUNTIME_CLASS(CMyView);
	//2 ������̬�з�
	m_wndSplit.Create(this,2,2,CSize(200,200),&cxt);	
#else  //��̬�зִ��ڵĴ���
	//1 ������̬�з�
	m_wndSplit.CreateStatic(this,2,1);
	//������������д����Ĭ��id����������ͻ�������
	m_wndSplit.CreateView(0,0,RUNTIME_CLASS(CHtmlView),CSize(200,200),pContext);
//	m_wndSplit.CreateView(1,0,RUNTIME_CLASS(CHtmlView),CSize(200,200),pContext);

	m_wndSplit2.CreateStatic(&m_wndSplit,1,2,WS_CHILD|WS_VISIBLE,
		m_wndSplit.IdFromRowCol(1,0));
	m_wndSplit2.CreateView(0,0,RUNTIME_CLASS(CMyView),CSize(100,100),pContext);
	m_wndSplit2.CreateView(0,1,RUNTIME_CLASS(CMyView),CSize(100,100),pContext);
	
	m_wndSplit2.SetColumnInfo(0,200,10);
	/*
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j)
		m_wndSplit.CreateView(i,j,RUNTIME_CLASS(CEditView),CSize(200,200),pContext);
	}
	*/
	//2 ��ȡ�����õ���ͼ
	CHtmlView* pHtmlView = (CHtmlView*) m_wndSplit.GetPane(0,0);
	pHtmlView -> Navigate("D:/");
#endif
	return true;	
}

void CMyView::OnDraw(CDC* pDC){
	pDC->TextOut(1,1,"Hello CMyView");
}

BOOL CMyWinApp::InitInstance(){
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	m_pMainWnd = pFrame;
	pFrame->Create(NULL,"MFCSplit");
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return true;
}





