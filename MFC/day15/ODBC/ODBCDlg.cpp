// ODBCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ODBC.h"
#include "ODBCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDlg dialog

CODBCDlg::CODBCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CODBCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CODBCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CODBCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CODBCDlg)
	DDX_Control(pDX, IDC_LIST, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CODBCDlg, CDialog)
	//{{AFX_MSG_MAP(CODBCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDlg message handlers

BOOL CODBCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CODBCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CODBCDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CODBCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


#include <afxdb.h>
void CODBCDlg::OnShow() 
{
	// TODO: Add your control notification handler code here
	
	// 1 打开数据源
	CDatabase db;
	if(!db.Open("TestDB")){
		MessageBox("连接数据库失败！");
		return;
	}
	//执行sql语句
	//CString sql = "insert into TBL_MSG(msg_id,msg_sender) values('9','789')";
	//CString sql = "Update TBL_MSG set msg_sender='10000' where msg_id='9'";
	CString sql = "delete from TBL_MSG where msg_id = '9' ";
	db.ExecuteSQL(sql);

	
	// 2 打开表获得数据
	CRecordset set(&db);
	//打开记录集
	if( !set.Open(CRecordset::forwardOnly,"Select * from TBL_MSG") ){
		MessageBox("打开记录集失败");
		db.Close();
		return;
	}
	
	//获取记录集的数据显示到列表控件


	//添加前需要删除所有的行和列
	while(m_wndList.DeleteColumn(0));
	m_wndList.DeleteAllItems();

	//获取表中字段的数量
	int nCount = set.GetODBCFieldCount();
	CODBCFieldInfo info;
	
	for(int i=0; i<nCount ;++i){
		//获取字段的标题
		set.GetODBCFieldInfo(i, info);
		m_wndList.InsertColumn(i,info.m_strName,LVCFMT_LEFT,100);
	}

	int nItem = 0; // 控件中选项的索引值
	while(!set.IsEOF()){
		CString strData;
		for(int i=0;i<nCount;++i){
			set.GetFieldValue(i,strData);
			if(i==0)
				m_wndList.InsertItem(nItem,strData);
			else
				m_wndList.SetItemText(nItem,i,strData);
		}
		++nItem;

		//将记录的指针移动到下一条
		set.MoveNext();
	}



	//关闭记录集
	set.Close();
	
	//关闭
	db.Close();
}
