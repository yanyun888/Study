
MFC day01

#一. 课程的大致安排
 MFC - 微软基础类库和框架
 SOCKET - windows平台下的网络通信编程
 ADO - 数据库操作的一套接口函数
 COM - 组件编程的应用

#二. 需要掌握一些技能
 数量使用 断点 调试程序的方法
 学会使用CALL STACK(调用堆栈) 查看函数之间的调用关系
 掌握VC的向导和工具 (生成向导/类向导：类向导也是一个代码生成工具)
 借助MSDN

#三. 对大家的期望(要求)
 不要缺课，课程连续性极强
 多思考，多练习
 营造一个良好的课堂气氛

-看C++代码最重要的是知道this指针是谁

-MFC视频 孙鑫讲解


#一. MFC的概念和作用
 1 什么是MFC?
   全称 Microsoft Foundation Class Library 我们一般称之为 微软基础类库。
   1.1 从硬盘的存在形式上来说MFC就是一个库(动态、静态)
   1.2 从原理上来说，MFC还是一个程序的框架
	java的三大框架
 2 问什么要使用MFC
   MFC功能并不如Win32强大
   基于框架进行框架，可以提高工作效率，减少开发周期，节约开发成本。

#二. 几个比较重要的头文件
 afx.h - 包含了MFC库中几乎所有类的声明
 afxwin.h - 包含了<afx.h> 和 <windows.h>
 afxext.h - 提供了一些扩展类的支持，比如：工具栏 类，状态栏 类 ...

*附：以Afx开头的函数，可以确定这是MFC库总封装的全局函数
     以::开头的函数，可以确定这是Win32的API函数(为了避免与类中的函数重名)

#三. MFC应用程序的类型
 MFC和Win32
 1 使用MFC库制作自己的控制台程序
  多了一个全局变量(对象)CWinApp the app;
  入口函数不同于以往的入口函数 _tmain

 2 使用MFC库制作自己的库程序
   2.1 使用MFC库制作自己的静态库程序
   2.2 使用MFC库制作自己的 规则 动态库程序
   2.3 使用MFC库制作自己的 扩展 动态库程序
   - 规则动态库和扩展动态库有什么区别

 3 使用MFC库制作自己的窗口程序
 - 单文档视图构架程序
    CFrameWnd - 框架窗口类，封装了关于框架窗口的各种操作；
    CWinApp - 应用程序类，代表了程序的流程，封装了关于程序流程的管理；
    CDocument - 文档类，封装了关于数据的操作(提取数据，转换数据，存储数据)；
    CView - 视图窗口类，封装了关于视图窗口的操作(显示数据)。

 - 多文档视图构架程序
   CMDIChildWnd - 子框架窗口类，封装了关于子框架窗口的操作；
   CMDIFrameWnd - 主框架窗口类，封装了关于主框架窗口的操作；
   CWinApp - 应用程序类，代表了程序的流程，封装了关于程序流程的管理；
   CDocument - 文档类，封装了关于数据的操作(提取数据，转换数据，储存数据);
   CView - 视图窗口类，封装了关于视图窗口的操作(显示数据)。

 - 对话框构架程序
   CWinApp - 应用程序类，封装了关于程序流程的管理；
   CDialog - 对话框窗口类，封装了关于对话框窗口的操作。

#四. MFC库中的概述
   1. CObject - MFC库中绝大部分类的最基类
    封装了三种机制 ：运行时类信息机制/动态创建机制/序列化机制
    运行时类信息机制 - 在运行时能够获取对象是哪一种类
    动态创建机制 - 可以不知道类就创建对象
    序列化机制 - 二进制流读写硬盘
   2. CCmdTarget - 消息映射机制的最基类
   3. CWinThread/CWinApp - 应用程序类，负责管理程序流程
   4. CDocument 及其子类 - 文档类，封装了关于各种格式数据操作
   5. CException - 异常处理类，封装了MFC库中各种异常情况的处理。
   6. CFile及其子类 - 文件操作类，封装了关于各种文件的读写等操作
   7. CWnd - 是所有窗口类的最基类
   8. FrameWindows - 框架窗口类，封装了关于框架窗口的操作
   9. DialogBoxes - 对话画框窗口类，封装了各种视图窗口的操作
   10. Views - 视图窗口类，封装了关于各种视图窗口的操作
   11. Controls - 控件窗口类，封装了关于各种控件窗口的操作
   12. CDC 及其子类 - 封装了各种绘图函数以及绘图设备
   13. CGdiObject及其子类 - 封装关于各种GDI绘图对象的操作
   14. CArray/CList/CMap 及其子类 - 封装了C++语法中相应的数据结构
   15. 非CObject类 - 封装了各种相应数据结构的操作


#五. 第一个MFC程序
   使用静态MFC库，保证能够看到源代码。
   1. 配置环境
    1.1 删除入口函数WinMain
    1.2 将头文件更改为<afxwin.h>
    1.3 Project settings 中选择使用MFC库(动态/静态)
   2. 代码的书写
    2.1 从CFrameWnd公有派生了自己的框架窗口类CMyFrameWnd
    2.2 从CWinApp公有派生了一个自己的应用程序类CMyWinApp
       并重写了父类的成员虚函数
    2.3 在虚函数中创建并显示了一个主框架窗口
   3. 程序的执行流程
    3.1 构造全局对象theApp(爆破点)
     1) 将 &theApp 保存到 当前程序线程状态信息中(AFX_MODULE_THREAD_STATE)
     2) 将 &theApp 保存到 当前程序模块状态信息中(AFX_MODULE_STATE)
     3) AfxGetThread() / AfxGetApp() - 都能够返回&theApp
    3.2 进入入口函数
     1) 利用AfxGetThread()/AfxGetApp() 获取&theApp
     2) 利用theApp调用应用程序类的成员虚函数InitApplication(初始化)
     3) 利用theApp调用应用程序类的成员虚函数InitInstance(创建/显示窗口)
     4) 利用theApp调用应用程序类的成员虚函数Run(消息循环)
     5) 如果没有消息，利用theApp调用应用程序类的成员虚函数OnIdle(空闲处理)
     6) 程序退出时，利用theApp调用应用程序类的成员虚函数ExitInstance(善后处理)

#六. CWinApp类的成员虚函数
  InitApplication
  InitInstance
  Run
  OnIdle
  ExitInstance

#七. CWinApp类的成员变量
  m_pMainWnd - 保存的为框架窗口类的对象地址
  
全局变量的构造优先于入口函数
要实现


关于虚函数的特性



