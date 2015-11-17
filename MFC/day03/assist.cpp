
//以WM_CREATE消息为例( 思考WM_PAINT / WM_COMMAND 消息的 )
LRESULT CALLBACK AfxWndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam){

	CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
	//获取和hWnd绑定在一起的框架类对象地址 pFrame === pWnd

	AfxCallWndProc(pWnd..){ // 参数pWnd === pFrame

		lResult = pWnd->WindowProc(nMsg, wParam, lParam){   // 函数内部this为pFrame === pWnd
			OnWndMsg(... ){  // 函数内部this指针为
				const AFX_MSGMAP* pMessageMap = GetMessageMap();  
				//
				AFX_MSGMAP_ENTRY* lpEntry;
				for (   ;pMessageMap != NULL;pMessageMap = pMessageMap->pBaseMap){
					//此for循环就是在遍历链表
					lpEntry = AfxFindMessageEntry(pMessageMap->lpEntries,WM_CREATE);
					//到链表的每个节点中
					if(lpEntry != NULL){
						goto LDispatch; // 一旦找到 跳出for循环(不再遍历)
					}
					LDispatch:
					union MessageMapFunctions mmf;
					mmf.pfn = lpEntry -> pfn;  //将&OnCreate给联合体所有成员赋值
					int nSig = lpEntry -> nSig;  // AfxSig_lwl
					switch(nSig){
						case AfxSig_lwl:
						lResult = (this->*mmf.pfn_lwl)(wParam,lParam);
						break;
					}
				}
			}
		}
	}


}
