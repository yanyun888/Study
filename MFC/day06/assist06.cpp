

//1 CFrameWnd::OnCreate 
int CFrameWnd::OnCreate(LPCREATESTRUCT lpcs){
	CCreateContext* pContext = (CCreateContext*)lpcs->lpCreateParams;
	//pContext 保存了视图类的运行时类信息，文档对象地址
	return OnCreateHelper(lpcs, pContext){
		return OnCreateClient(){
			CreateView(pContext, AFX_IDW_PANE_FIRST){
				//动态创建视图对象
				CWnd* pView = (CWnd*)pContext->m_pNewViewClass->CreateObject();
				//创建视图窗口
				pView->Create(...,pContext);
			}
		}	
	}
}

//2 CView::OnCreate()
int CView::OnCreate(LPCREATESTRUCT lpcs){
	//保存于ViewCore.cpp
	pContext->m_pCurrentDoc->AddView(CView* pView){
		//将视图对象地址保存到文档成员m_viewList链表中
		m_viewList.AddTail(pView);
		//将文档的地址保存到视图的成员中
		pView->m_pDocument = this；
	}
}
//文档与视图相互保存对方地址，一个文档可以对应多个视图，一个视图只可以对应一个文档

