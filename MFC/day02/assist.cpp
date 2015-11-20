//分析过程伪代码
//AFX_MODULE_STATE aaa; 当前程序模块状态信息
//AFX_MODULE_THREAD_STATE bbb;当前程序线程状态信息
//ccc;当前程序线程状态信息

CMyFrameWnd *pFrame = new CMyFrameWnd;
pFrame->Create(NULL,"..."){
//函数内部this指针为pFrame
	//加载菜单
	CreateEx(..,NULL,..){//函数内部的this仍然为pFrame
		CREATESTRUCT cs; 
		...
		cs.lpszClass = lpszClassName;//???(lpszClassName === NULL) 将会被重新赋值更改
		...
		cs.hInstance = AfxGetInstanceHandle();//能够拿到当前程序实例句柄(g_hInstance)
		PreCreateWindow(cs){
			AfxDeferRegisterClass(...){
				WNDCLASS wndcls;
				...
				wndcls.lpfnWndProc=DefWndProc;//???填写默认的窗口处理函数，使用钩子完成
				_AfxRegisterWinthIcon (&wndcls,"AfxFrameOrView42sd",...){
					&wndcls->lpszClassName = "AfxFrameOrView42sd";
					AfxRegisterClass(&wndcls){
						::RegisterClass(...)//注册了一个窗口类
					}
				}
				...
			}
			cs.lpszClass = "AfxFrameOrView42sd";
		}
		AfxHookWindowCreate(pFrame){//此时this为pFrame
			_AFX_THREAD_STATE* pThreadState = _afxThreadState.GetData();//获取当前程序线程信息 的地址
			
			::SetWindowsHookEx(WH_CBT,_AfxCbtFilterHook,...);
			//利用Win32的API函数在程序埋下一个类型为WH_CBT的钩子

			pThreadState->m_pWndInit = pFrame;
			//将自己new的框架类对象pFrame保存到全局变量CCC的一个成员变量中
		}
		::CreateWindowEx(...);//此函数一旦执行成功，立即执行钩子处理程序
	}
}

//钩子处理函数
_AfxCbtFilterHook(...,wParam,...){
	_AFX_THREAD_STATE* pThreadState = _afxThreadState.GetData();//获取全局变量CCC的地址
	CWnd* pWndInit = pThreadState->m_pWndInit;//从CCC中取出保存的框架类对象pFrame赋值给pWndInit
	HWND hWnd = (HWND)wParam; //获取刚刚创建成功的窗口句柄
	pWndInit->Attach(hWnd){//函数内部的this指针为pFrame等同于pWndInit
		CHandleMap* pMap = afxMapHWND(TRUE){ // create map if not exist
			AFX_MODULE_THREAD_STATE* pState = AfxGetModuleThreadState();//获取bbb的地址
			pState->m_pmapHWND = new CHandleMap(...);
			//new了一个映射类对象，并将对象地址保存到全局变量bbb中
			return pState->m_pmapHWND;//返回bbb的成员(映射类对象地址)
		}
		pMap->SetPermanent(pFrame->m_hWnd = hWndNew, pFrame){
			//函数内部的this指针为pMap(映射类对象地址)
			m_permanentMap[hWnd] = pFrame;
			//pFrame和handle进行了捆绑
		}
	}
	WNDPROC afxWndProc = AfxGetAfxWndProc();
	//获取了AfxWndProc函数的地址
	oldWndProc = (WNDPROC)SetWindowLong(hWnd, GWL_WNDPROC,(DWORD)afxWndProc);
	//利用Win32的API函数将窗口处理函数更改为AfxWndProc(真正的窗口的处理函数)
}

//以WM_CREATE消息为例
AfxWndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam){
	CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
	//已知句柄访问对象
	CHandleMap* pMap = afxMapHWND(){
		AFX_MODULE_THREAD_STATE* pState = AfxGetModuleThreadState();
		return pState->m_pmapHWND;//返回的是上面保存的映射类对象地址
	}
	pWnd = pMap->LookupPermanent(hWnd){  //函数内部this为pMap
		return m_permanentMap[hWnd];  //返回的就是pFrame
	}
	return AfxCallWndProc(pWnd,...){ //参数pWnd 等同于 pFrame
		pWnd->WindowProc(nMsg, wParam, lParam){
			//回到自己的代码
		}
	}

}



