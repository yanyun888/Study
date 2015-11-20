

框架窗口类 CFrameWnd
			CWinApp
视图窗口类 CView
文件窗口类

#一 视图窗口
  1 相关问题
     MFC的视图窗口 -  提供了一个专门用于显示数据的窗口，
  2 相关类
     CView及其子类 - 父类CWnd，封装了关于视图窗口类的一些操作。
  3 视图窗口的使用
    3.1 视图窗口的创建
      1) 从CView类公有派生一个自己的视图类(CMyView)，并必须重写父类的纯虚函数OnDraw()
      2) 在处理框架窗口的WM_CREATE消息时，定义一个CMyView类对象，(pView)并利用这个对象调用视图类
   4 命令消息的处理顺序(WM_COMMAND)
      View->Frame->App
        (CFrameWnd::OnCmdMsg 函数内部代码决定程序执行的先后吮吸。)
   5 对象的关系图
      m_pMainWnd = pFrame;
      m_pViewActive = pView;
      theApp
          |-> m_PMainWnd(框架类对象地址pFrame)
                     |->m_pViewActive(视图类对象地址pView)

#二 运行时类信息机制的作用  (MFC的第四大机制)
      1运行时类信息机制的作用
         在程序运行过程中，可以获知 对象 相关类的信息
      2 运行时信息类的信息机制的使用
        2.1 类必须拍升自CObject
        2.2 类内必须添加声明宏DCLEARE_DYNAMIC(theClass)
        2.2 类外必须添加实现宏 IMPLEMENT_DYNAMIC(theClass,baseClass)

        当类具备上述3个条件，可以使用CObject::IsKindOf()进行判断对象是否属于这个类


      3 运行时类信息的实现
        3.1 数据结构
```
struct CRuntimeClass{
	LPCSTR m_lpszClassName;     //类的名称
	int m_nObjectSize;   // 类的大小
	UINT m_wSchema;  // schema number of the loaded class 类的版本0xFFFF
	CObject* (PASCAL* m_pfnCreateObject)(); // NULL => abstract class  
                                     // 动态创建机制使用，运行时类信息机制为NULL
	CRuntimeClass* m_pBaseClass;        //父类静态变量地址(负责连接链表)
	CRuntimeClass* m_pNextClass;       // linked list of registered classes
	                               //运行时类信息机制
};
```
       3.2 宏展开的代码(见代码)
       3.3 宏展开各部分的作用
          classCDog - 静态变量
                  保存类的相关信息，例如: 类大小，类的版本信息，类名称
          GetRuntimeClass() - 成员虚函数
                   获取本类静态变量地址(获取链表头结点)
       3.4 IsKindOf函数的执行过程
         * `RUNTIME_CLASS(theClass) === &theClass::classtheclass`
               返回括号中的类的静态变量地址
          1) 利用类对象(yellowdog)调用宏展开的虚函数GetRuntimeClass获取本类(CDog)的静态变量
              地址(链表头结点)；
          2) 将本类(CDog)静态变量地址和目标(参数)进行比对，如果相等，则证明对象属于这个类；
          3) 如果不相等，利用静态变量的 第五个 成员获取父类静态变量地址，循环和目标进行比对，只
              要有一次成功，则证明 对象 属于这个类。
          4) 循环结束一次比对都不成功，证明对象不属于这个类。

#三 动态创建机制
   1 动态创建机制的作用
      在不知道类名的情况相下，可以讲类的对象创建出来。
   2 动态创建机制的使用
      2.1 类必须派生CObject
      2.2 类内必须添加声明宏 DECLARE_DYNCREATE(theClass)
      2.2 类外必须添加实现宏 IMPLEMENT_DYNCREATE(theClass,baseClass)

      当类具备上述三个条件后，CRuntimeClass::CreateObject函数可以将类的对象创建出来

   3 动态创建机制的实现
     3.1 函数的区别(多了类的静态成员函数)
       CObject* PASCAL CDog::CreateObject(){
       	return new CDog; //new 了一个CDog类对象，并返回对象地址
       }
     3.2 变量的区别(第四个成员不再为NULL)
       第四个成员保存的为新增加静态成员函数名
    4 CRuntimeClass::CreateObject() (对象加工场)函数的执行过程
     4.1 利用本类(CDog)的静态变量的第四个成员，获取CDog类静态成员函数CDog::CreateObject
     4.2 调用这个静态函数(CDog::CreateObject)，在函数内部new了一个CDog类的对象，并返回对象地址。



     PreTranslateMessage











