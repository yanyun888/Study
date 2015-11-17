
MFC day02

#一. 窗口的创建

钩子：钩子拥有优先勾取消息的权利，钩子是Win32的技术
如果想要使用钩子获取消息，你必须要在程序中埋下一个钩子。

埋钩子
HHOOK SetWindowsHookEx(
  int idHook,        // hook type钩子类型
  HOOKPROC lpfn,     // hook procedure钩子处理函数
  HINSTANCE hMod,    // handle to application instance应用程序实例句柄
  DWORD dwThreadId   // thread identifier线程ID
);
如果hMod为空，可以勾取任何句柄的钩子
如果dwThread为空，可以任何线程的钩子

名为WH_CBT的钩子类型

钩子处理函数的原型
LRESULT CALLBACK CBTProc(
  int nCode,      // hook code钩子码
  WPARAM wParam,  // depends on hook code
  LPARAM lParam   // depends on hook code
);
钩子码：HCBT_CREATEWND
wParam：刚刚创建成功的窗口的句柄

LONG SetWindowLong{
	HWND hWnd;   //handle to window 窗口句柄
	int nIndex;        //offset of value to set GWL_WNDPROC
	LONG dwNewLong; //新的窗口处理函数名(函数地址)
};


 1 加载菜单
 2 调用CreateEx函数，注册窗口类并创建窗口
  2.1 调用PreCreateWindow设计并注册一个窗口类
  	WNDCLASS wndcls;
  	wndcls.lpfnWndProc=DefWndProc;//???填写默认的窗口处理函数
  2.2 调用AfxHookWindowCreate函数
    1) 利用Win32de API函数 SetWindowsHookEx在程序埋下一个类型为WH_CBT的钩子
    2) 将自己的new的框架类对象地址pFrame保存到当前程序线程信息中
  2.3 调用Win32的API函数CreateWindowEx，此函数一旦执行成功，立即执行钩子处理函数
 3 钩子处理函数
  3.1 将 窗口句柄 和 框架类对象地址(pFrame)建立一对一的绑定关系
     pFrame->m_hWnd = hWnd;  //hWnd是pFrame的一个成员
     m_permanentMap[hWnd] = pFrame; //可以通过hWnd访问内核中的一个数组
     即通过其中一个和可以获得另外一个。
  3.2 利用Win32的API函数SetWindowLong将窗口处理函数更改为AfxWndProc(真正的窗口处理函数)

#二. 消息的处理
 1 消息一旦产生 进入窗口处理函数AfxWndProc
 2 根据已知的窗口句柄找到和它绑定在一起的框架类对象地址pFrame
 3 利用框架类对象pFrame调用框架类的成员虚函数WindowProc完成消息的处理

消息映射机制：可以不重写WndProc也可以处理消息，MFC的第三大机制

