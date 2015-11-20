
#一 列表控件
##1 相关类
    CListControl类 - 父类是CWnd类，是一个控件类。常用于对话框程序，提供了列表控件的功能。
    CListView类 - 父类是CtrlView类，是一个视图类。常用于文档视视图程序中。
    				通过调用GEtListControl获取与视图相关联的列表控件
##2 CListControl类的使用
    2.1 设置控件的图标列表
        2.1.1 添加位图资源，设计图标列表
        2.1.2 使用位图创建图标列表
        2.1.3 将图标列表设置到控件
    2.2 添加控件的列
    	CListCtrl::InsertColumn
    2.3 添加选项
    	CLIstCtrl::InsertItem
    2.4 设置列的文本
    	CListCtrl::SetItemText
    2.5 删除所有选项
    	CListCtrl::DeleteAllItems
    2.6 设置/获取附加数据
    	AfxOleInit();
    	m_wndList.SetBkImage("e:/cup.bmp");
    	m_wndList.SetBkColor(CLR_NONE);   //字体的背景色透明

#二 树控件
	1 相关类
	  CTreeCtrl 类 - 父类也是CWnd类
	  CTreeView - 父类是CCtrlView类，是视图类。常用于文档视图程序，
		通过调用GetTreeCtrl函数获取与之关联的树控件。
	2 CTreeCtrl类的使用
		可是设置选中和未选中是两种图标
	  2.1 设置控件的图标列表
	    CTreeCtrl::SetImageList
	  2.2 添加节点
	     CTreeCtrl::InsertItem(
	     		LPCTSTR lpszItem,   // 节点文本
	     		int nImage,    // 节点图标
	     		int nSelectedImage,   //节点被选中时的图标
	     		HTREEITEM hParent = TVI_ROOT,  //使用默认值表示是根节点，否则是添加节点的父节点句柄
	     		HTREEITEM hInsertAfter = TVI_LAST   //使用默认值在末尾添加节点，否则在HInsertAfter后添加节点
	     	)
	    2.3 获取当前选中的节点
	      CTreeCtrl::GetSelectedItem
	    2.4 删除当前选中的结点
	    	CTreeCtrl::DeleteItem
	    2.5 设置节点的文本(修改节点)
	       CTreeCtrl::SetItemText
	    2.6 设置节点的展开状态
	       CTreeCtrl::Expand

	XML文件用于保存层次结构(树形结构)

#三 属性页控件
	1 相关类
		CTabCtrl类 - 提供了属性页控件的功能。
	2 CTabCtrl类的使用
	  2.1 插入标签
	     CTabCtrl::InsertItem
	  2.2 设计每个标签所对应的对话框，并生成对应的对话框类
	  2.3 以table控件为父窗口创建对话框
	  2.4 根据控件的大小调整对话框窗口的位置和大小
	  2.5 设置对话框的显示状态
	  2.6 在Tab控件的SelChange消息处理函数中，重新设置对话框的显示状态。

属性页表单完成的表格
CPropertySheet
CPropertyPage

