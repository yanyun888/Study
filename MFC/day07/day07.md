

MFC day07

#一、文档类
    继承自CCmdTarget，并且具有消息映射宏，就可以处理消息。
##1 默认消息处理顺序App/Frame/View/Document
  	CFrameWnd::OnCmdMsg    -->     ActiveView-Frame-App
  	CView::OnCmdMsg    -->    ActiveView-Document

  	最终顺序为： ActiveView ->  Document ->   Frame ->  App
  	消息操作的顺序是是由MFC的底层决定的，可以通过重写虚函数来更改其默认顺序
##2 类与类(对象与对象)之间的关系
     CWinApp
         | -> m_pMainWnd  (CFrameWnd*)
                  | -> m_pViewActive  (CView*)
                           | ->m_pDocument  (CDocument*
                                   |  -> m_viewList  (CView* List)
          MFC的各个类是通过保存对方地址产生关系的     

#二、使用文档模板创建视图应用程序
##1 文档模板类的介绍
    	   引入文档模板类使得程序中各个对象的创建更加规范和统一。
       CDocTemplate类 - 抽象基类，定义了文档模板的基本功能。
       CSingleDocTemplate类 - 父类是CDocTemplate类，完成单文档模板的创建。
       CMultipleDocTemplate类 - 父类是CDocTemplate类，完成多文档模板的创建。                                                                
     2 单文档视图应用程序
       2.1 相关类
          CWinApp类
          CFrameWnd类
          CView类
          CDocument类
          CSingleDocTemplate类 - 单文档模板类
          
          CSingleDocTemplate( //构造函数
          	UINT nIDResource,  //资源ID
          	CRuntimeClass* pDocClass,   //文档类运行时类信息
          	CRuntimeClass* pFrameClass,
          	CRuntimeClass* pViewClass
          );

          单文档模板的成员如下：（构造函数实现的过程就是给下列量进行赋值）
          CDocument* m_pOnlyDoc;  //保存单文档对象地址
          从父类继承的成员
          UNIT m_nIDResource;
          CRuntimeClass* m_pDocClass;
          CRuntimeClass* m_pFrameClass;
          CRuntimeClass* m_pViewClass;

       2.2 创建过程
         1) 创建单文档模板
         2) 将文档模板添加到应用程序
         		AddDocTemplate()
         3) 新建文档
         		OnFileNew() 

         断言的使用：ASSERT / VERIFY

       2.3 各个类(对象)之间的关系
       CWinApp
            | -> m_pDocManager(CDocManager*)  // 文档管理器
                      | -> m_TemplateList   (CSingleDocTemplate  List)
                               | -> m_pOnlyDoc    (CDocument* )
                               | -> m_pDocClass/m_pViewClass/m_pFrameClass
            | -> m_pMainWnd  (CFrameWnd*)
                  | -> m_pViewActive  (CView*)
                           | ->m_pDocument  (CDocument*)
                                   |  -> m_viewList  (CView* List)


       2.4 与MFC向导生成的单文档视图程序对比
       App::
       	InitInstance()
       Frame::
       	OnCreate()/OnCreateClient()
       	PreCreateWindow()
       View::
       	OnCreate()
       	PreCreateWindow()
       	OnDraw()
       Document::
       	Serialize() // 序列化，将数据以二进制流的方式写入到文件(硬盘)，文件的读写
   3 使用文档模板创建多文档视图程序
    3.1 概念
      同时可以管理多个文档，
    3.2 相关类
      CMDIFrameWnd - 多文档的主框架窗口
      CMDIChildWnd - 多文档的子框架窗口类
      CMultiDocTemplate - 多文档的文档模板
      CWinApp / CView / CDocument - 与当文档的相同

      注意：主框架和子框架窗口分别拥有自己的资源(菜单和图标)
      CMultiDocTemplate::CMultiDocTemplate{
      	UINT nIDResource,    // 子框架的资源ID
      	CRuntimeClass* pDocClass,
      	CRuntimeClass* pFrameClass,   //  子框架的运行时类信息
      	CRuntimeClass* pViewClass
      };
    3.3 创建（多个视图数据同步的例子）
       1)  新建 
            OnFileNew();  //文档、子框架、和视图等对象都被创建
       2)  新建窗口
       	基于原有活动文档创建新的子框架和视图窗口；得到的效果，一个文档对应多个视图。
       3)  捕获当前活动视图内容发生变化的消息，在消息处理函数中，将视图的数据保存到文档
            中，文档通知其他视图。
       4)  重写视图类的OnUpdate()函数，在函数中，获取文档的数据，显示到视图。                          
