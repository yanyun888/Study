MFC day04

#MFC的菜单
1. 相关问题
   Win32 - HMENU
   MFC - CMenu 类对象
2. 相关类
   CMenu - 封装了关于菜单的各种操作，还封装了非常重要的成员变量m_hMenu
                 m_hMenu 保存的为菜单句柄
3. 菜单资源的使用
  3.1 添加菜单资源
  3.2 将菜单设置到窗口
     - 1) 在调用框架类成员函数Create创建主框架窗口时传参
     - 2) 在处理框架窗口的WM_CREATE消息时
            CMenu menu;
            menu.LoadMenu - 加载菜单，并将菜单句柄和CMenu类对象建立一对一的绑定关系
            CFrameWnd::SetMenu；
  3.3 菜单项被点击消息(WM_COMMAND)的处理
     ON_COMMAND(菜单项id, 处理的函数名)
  3.4 设置菜单项的状态
    WM_INITMENUPOPUP - 菜单已经激活，即将显示没有显示的时候
    ON_WM_INITMENUPOPUP - 用于处理菜单初始状态的消息
    ::CheckMenuItem()   -  CMenu::CheckMenuItem
    ::EnableMenuItem()   -   CMenu::EnableMenuItem

   3.5 命令消息的处理顺序
   	Frame -->  App ( 暂时排名)
   	CFrameWnd::OnCmdMessage 函数内部代码的施行先后顺序将决定 Frame 和 App消息处理的先后顺序
  3.6 右键菜单(上下文菜单)
     ON_WM_CONTEXTMENU
     ::TrackPopupMenu   -   CMenu::TrackPopupMenu
     顶层菜单，弹出式菜单
     ::GetSubMenu / CMenu::GetSubMenu - 可以获取指定的顶层菜单项 的 下拉菜单
     ::TrackPopupMenu / CMenu::TrackPopupMenu

#MFC的工具栏
工具栏是资源的一种，能够使用可视化图形的方式创建一个工具栏
1. 相关类
   CToolBarCtrl - 父类是 CWnd类；CToolBarCtrl本身不代表工具栏，其代表的是工具栏的工具按钮
   CToolBar - 父类是CControlBar类；CToolBar代表整个工具栏，实际上是一个容器，
		     封装了关于工具栏的各种操作，例如创建工具栏等；还封装了工具栏跟框架窗口之间的关系(停靠关系)
                 还
2. 工具栏的使用
   2.1 添加工具栏资源
 	`#include <afxext.h>`
   2.2 创建工具栏 CToolBar::Create  /  CToolBar::CreateEx
   2.3 加载工具栏 CToolBar::LoadToolBar  /  
   2.4 工具栏的停靠(船坞化)
     1) 工具栏准备停靠的位置CToolBar::EnableDocking
     2) 框架窗口允许停靠的位置CFrameWnd::EnableDocking
     3) 框架窗口设置临时停靠的位置 CFrameWnd::DockControlBar	
   2.5 关于工具栏的显示和隐藏
      CFrameWnd::ShowControlBar
      void ShowControlBar(
      	CControlBar* pBar,  //被操作的工具栏
      	BOOL bShow,          //true - 显示 / false-隐藏
      	BOOL bDelay          // 是否延迟操作 false-不延迟
     		);
     	CWnd::IsWindowVisible(); - 能够判断一个窗口显示和隐藏的状态，可用来检测工具栏是显示还是隐藏
    2.6 工具栏的风格
        CBRS_GRIPPER  -  把手/夹子 风格
        CBRS_SIZE_DYNAMIC  -  工具栏变形风格
        CBRS_TOOLTIPS  -  标签风格

        TBSTYLE_FLAT  -  工具栏按钮平滑
        TBSTYLE_TRANSPARENT  -  工具栏按钮凸起

3. 工具栏按钮被点击(WM_COMMAND) 消息的处理
   ON_COMMAND(工具按钮的ID, 成员处理函数名)

练习:
   菜单项“工具栏”
   1) 当“工具栏”处于显示状态，菜单项勾选，工具栏处理隐藏状态，菜单项非勾选。
   2) 菜单项 每点击一次，工具栏 显示/隐藏 状态切换一次
   3) 不要添加任何变量
  tips: WM_INITMENUPOPUP 消息 在每次菜单将要显示的时候进行触发


#三  状态栏
  1 相关类
      CStatusBar  -  封装了关于状态栏的各种操作，其父类CControlBar
  2 状态栏的使用
    2.1 创建状态栏
       CStatusBar::Create  /  CStatusBar::CreateEx
    2.2 设置状态栏的指示器
       CStatusBar::SetIndicators
    2.3 设置指示器的风格及宽度
       CStatusBar::SetPanelInfo
       ID为0的指示器就是显示提示内容的，需要工具栏CBRS_FLYBY风格的支持。
    2.4 设置指示器的文本内容
       CStatusBar::SetPaneText;

