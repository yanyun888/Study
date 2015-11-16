
//将文档模板添加到
void AddDocTemplate(pTemplate){

	//使用文档管理器的AddDocTemplate
	m_pDocManager->AddDocTemplate(pTemplate){

		//将文档模板对象地址 添加到 文档管理器的链表m_templateList中
		m_templateList.AddTail(pTemplate);
	}
}

void OnFileNew(){
	m_pDocManager->OnFileNew(){

		pTemplate->OpenDocumentFile(LPCSTR lpszPathName,BOOL bMakeVisible){
			CDocument* pDocument = NULL;
			CFrameWnd* pFrame = NULL;
		// 1 创建文档对象
			pDocument = CreateNewDocument(){
				// 1.1 动态创建文档对象
				m_pDocClass->CreateObject();
				// 1.2 将文档对象地址保存到文档模板中
				AddDocument(pDocument){
					m_pOnlyDoc = pDoc;
				}
			}
		//2 创建框架
			pFrame = CreateNewFrame(pDocument,NULL){
				
				CCreateContext context;     // LoadFrame函数的参数
				context.m_pCurrentDoc = pDoc;
				context.m_pNewViewClass = m_pViewClass;
				context.m_pNewDocTemplate = this;
				//2.1 动态创建框架对象
				CFrameWnd* pFrame = (CFrameWnd*) m_pFrameClass->CreateObject();
				//2.2 创建框架窗口库
				pFrame->LoadFrame(m_nIdResource,...,&context);
				//2.3 会触发框架的WM_CREATE消息，进而调用CFrameWnd::OnCreate()函数，
				//在函数中，动态创建视图对象，并且创建视图窗口。

				//2.4 触发视图的WM_CREATE消息，调用CView::OnCreate()函数；
				//在函数中，文档与视图相互保存对方的地址。
			}
			// 将框架对象地址保存到应用程序变量m_pMainWnd中
			pThread->m_pMainWnd = pFrame;  //pThread = pFrame;
			// 初始化更新框架
			InitialUpdateFrame(pFrame,pDocument,bMakeVisible){
				//代理
				pFrame -> InitialUpdateFrame(pDoc,bMakeVisible);
			}
		}
	}
}

