
MFC day13
<!-- MarkdownTOC -->

- 一 属性页对话框
    - 1 分类
    - 2 相关类
    - 3 标签式属性页的创建
    - 4 向导式属性页的使用步骤
- 二 MFC的线程
    - 1 MFC线程的分类
    - 2 工作者线程的使用
    - 3 用户界面线程的使用
- 课堂练习

<!-- /MarkdownTOC -->


# 一 属性页对话框
## 1 分类
    标签式 - 通常用于参数选项等配置
    向导式 - 通常用于引导用户按照步骤一步步完成某种操作。
## 2 相关类
    CPropertyPage类 - 页面类，父类是CDialog类
    CPropertySheet类 - 表单类，父类是CWnd类，从功能上可以认为是一个框架窗口。
    一个

## 3 标签式属性页的创建
- 3.1 添加页面类的资源模板，并生成相应的类，注意父类一定是CPropertyPage类
    注意需要修改语言Chinese(PRC)
- 3.2 在工程中添加CPropertySheet类的派生类CSetupSheet类
- 3.3 将页面对象添加到表单中
    CPropertySheet::AddPage
- 3.4 创建和显示表单
    CPropertySheet::DoModal
    ((CFrameWnd*)AfxGetMainWnd()  )
    CColorDialog 颜色对话框，对颜色进行更改
- 3.5 将应用按钮设置为可用
    + CPropertyPage::SetModified
- 3.6 消息处理(通过添加虚函数完成的)
    + CPropertyPage::OnApply
    + CPropertyPage::OnCancel
    + CPropertyPage::OnOk
    注意：当点击应用按钮时，所有页面的OnApply函数都会被调用。

## 4 向导式属性页的使用步骤
- 4.1 添加页面类的资源模板，并生成相应的类，注意父类一定是CPropertyPage类
    注意需要修改语言Chinese(PRC)
- 4.2 在工程中添加CPropertySheet类的派生类CSetupSheet类
- 4.3 将页面对象添加到表单中
    CPropertySheet::AddPage
- 4.4 将属性页对话框设置为向导模式
    + CPropertySheet::SetWizardMode
- 4.5 创建和显示
    + CPropertySheet::DoModel
- 4.6 设置页面的向导按钮
    + 第一个页面，中间所有页，最后一个页面
    + 根据页面获取表单
        * CPropertyPage::GetParent
    + 设置向导按钮
        * CPropertyPage::SetWizardButtons
        在(虚函数)CPropertyPage::OnSetActive函数内完成操作。
- 4.7 消息处理(重写虚函数)
    + CPropertyPage::OnWizardNext
    + CPropertyPage::OnWizardBack
    + CPropertyPage::OnWizardFinish
    + CPropertyPage::OnCancel
    注意：当点击向导按钮时，只有当前页面的消息处理函数被调用

# 二 MFC的线程
    把耗时的操作放在一个单独的线程中。MFC的线程更加侧重于使用。
## 1 MFC线程的分类
- 从用途方面讲，线程分为工作者线程，和用户界面线程。
    + 工作者线程 - 通常没有单独的用户界面，主要完成后台的耗时的操作。
    + 用户界面线程 - 拥有独立的用户界面和消息队列。(消息队列是以线程为划分单位的)
## 2 工作者线程的使用
- 2.1 定义线程函数(全局函数或类的静态成员函数)，函数原型
    + `UINT MyControllingFunction(LPVOID pParam);`
- 2.2 创建和启动线程
    + AfxBeginThread
## 3 用户界面线程的使用
- 3.1 添加CWinThread类的派生类CMyThread类
- 3.2 在CMyThread::InitInstancee()函数中创建自线程的用户界面和对象
- 3.3 创建和启动线程
    + AfxBeginThread


# 课堂练习
在一个视图中包含另外两个视图的地址，这样就能在一个视图操作另外一个视图的对象。



