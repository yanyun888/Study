入口程序机制：
实际上MFC入口函数也是main()，通过重写InitInstance() 虚函数来实现

窗口创建机制：
attach - 窗口对象地址 和 窗口句柄绑定
钩子函数 - 更改默认的消息处理函数

消息映射机制：（基于事件驱动的消息处理）
添加消息宏，产生消息信息链表，遍历链表，根据消息ID查找所对应的处理函数
COMMAND消息，没有默认处理；WM窗口消息 拥有默认处理

运行时类信息
在程序运行时，我们能够得到对象的类信息(能够判断对象属于某个类，得到类的继承信息)
关键点：结构体CRunTimeClass，IsKindOf()函数

动态创建机制
基于类信息，多了一个CreateObject函数，并将函数信息保存到CRuntimeClass的成员变量中，
动态创建的意义：
1 创建对象的函数CRuntimeClass::CreateObject()
2 程序员定义自己所需要的类
3 使用（MFC提供的）函数创建该类的对象
有了动态创建，底层代码(MFC框架)可以创建上层用户类(用户定义的类)的对象；这样，框架和用户代码可以
更好的协作。

视图窗口View
专门用于处理某个窗口的任务

day06
#一、窗口的切分
    1  分类
     动态切分：程序在运行时，由用户实时完成窗口的切分；最大切分数量2*2个。
            通常使用相同的视图类，在切分前后每个视图类相同。
     静态切分：在程序编码阶段，由程序员完成窗口的切分；最大切分数量16*16个。
            通常每个窗口可以使用不同的视图类。
    2  相关类
     CSplitterWnd类提供提供了窗口切分的功能。
     `#include <afxext.h>`
     `CFrameWnd::OnCreateClient()`是一个虚函数，功能是用来创建框架的客户区对象的；默认会被OnCreate()函数调用。
     OnCreateClient()需要放在CMyFrameWnd函数中实现
```
virtual BOOL OnCreateClient(
	LPCREATESTRUCT lpcs,  //结构体指针，包含窗口特征
	CCreateContext* pContext 
	); 
struct CCreateContext {
	CRuntimeClass* m_pNewViewClass;  // 视图类的运行时类信息
	CDocument* m_pCurrentDoc;
	CDocTemplate* m_pNewDocTemplate;
	CView* m_pLastView;
	CFrameWnd* m_pCurrentFrame;
	CCreateContext(); 
}; 
```
     3  动态切分窗口
       3.1 指定所需要的视图类CCreateContext
       3.2 创建动态切分
           CSplitterWnd::Create();
           SPY++ 小工具可以查看任意窗口的信息和消息
           动态切分的每个窗口都是独立的视图窗口，都有各自的句柄值。

     4  静态切分窗口
     		可以将类作为CMyFrameWnd成员声明出来。
       4.1 先创建静态切分
            CSplitterWnd::CreateStatic()
       4.2 创建每个视图
       	CSplitterWnd::CreateView();
  课堂练习：创建一个3*3的静态切分窗口，要求窗口的的尺寸大致相同
     5  静态切分窗口的再切分
       5.1 再切分窗口的的父窗口不再是框架窗口，而是第一次切分窗口对象，
       	窗口Id需要通过函数获取`CSplitterWnd::IdFromRowCol();`
       5.2 在计算坐标时，我们无须考虑上一次的切分，是单独计算的。
       5.3 根据索引坐标获取某个视图窗口
            `CSplitterWnd::GetPane()`
       5.4 设置窗口的尺寸(宽和高)
            `CSplitterWnd::SetColumnInfo()`
            `CSplitterWnd::SetRowInfo()`

#二、文档类
  文档类是用来保存数据的
    1  相关类
    CDocument类 - 提供了保存数据的功能(存储、加载)。
    2  创建过程
	视图的创建、视图和文档之间的关系  是什么？
     2.1 Frame的WM_CREATE：CFrameWnd::OnCreate() 函数
        动态创建视图对象，并且创建视图窗口
     2.2 View 的 WM_CREATE：CView::OnCreate()函数
        文件与视图相互保存对方地址

    3 使用（在视图中显示文档的数据）
     3.1 CView::OnInitialUpdate()  -  视图类初始化更新函数
       虚函数，子类可以重写，该函数在视图第一次附加文档之后，初始化显示之前调用
     3.2 CView::GetDocument()  -  获取与视图关联的文档
     3.3 CFrameWnd::InitialUpdateFrame(CDocument* pDoc, BOOL bMakeVisible)
            -  框架类的初始化更新函数
          在框架窗口创建之后调用，会引起所有与之关联了视图OnInitialUpdate函数的调用。
        







