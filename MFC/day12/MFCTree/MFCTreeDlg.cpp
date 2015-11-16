// MFCTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTree.h"
#include "MFCTreeDlg.h"

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
// CMFCTreeDlg dialog

CMFCTreeDlg::CMFCTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCTreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCTreeDlg)
	m_Name = _T("Demo");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	
}

void CMFCTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCTreeDlg)
	DDX_Control(pDX, IDC_TREE, m_wndTree);
	DDX_Text(pDX, IDC_NAME, m_Name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCTreeDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCTreeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INSERT_ROOT, OnInsertRoot)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_INSERT_CHILD, OnInsertChild)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCTreeDlg message handlers

BOOL CMFCTreeDlg::OnInitDialog()
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
	InitTreeCtrl();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCTreeDlg::OnPaint() 
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
HCURSOR CMFCTreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCTreeDlg::InitTreeCtrl()
{
	//设置控件的图标列表
	m_ilNormal.Create(IDB_NORMAL,16,1,RGB(0,0,0));
	//设置控件的背景图标
	m_wndTree.SetImageList(&m_ilNormal,TVSIL_NORMAL);
	//通过节点构造树
	HTREEITEM hRoot = m_wndTree.InsertItem("ThreeKingdoms",0,1);
	HTREEITEM hWei = m_wndTree.InsertItem("Wei",2,3,hRoot);
	HTREEITEM hShu = m_wndTree.InsertItem("Shu",2,3,hRoot);
	HTREEITEM hWu = m_wndTree.InsertItem("Wu",2,3,hRoot);
	HTREEITEM hGuanyu = m_wndTree.InsertItem("Guan Yu",2,3,hShu);
	HTREEITEM hZhaoyun = m_wndTree.InsertItem("Zhao Yun",2,3,hShu);
	HTREEITEM hZhangfei = m_wndTree.InsertItem("Zhang Fei",2,3,hShu,hGuanyu);


	m_wndTree.SetItemHeight(25);
	m_wndTree.Expand(hRoot,TVE_EXPAND);
	m_wndTree.Expand(hShu,TVE_EXPAND);
}

void CMFCTreeDlg::OnInsertRoot() 
{

	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_Name == ""){
		AfxMessageBox("EditBox is Empty");
		return;
	}
	HTREEITEM hSel = m_wndTree.GetSelectedItem();
	//m_wndTree.DeleteItem()
	m_wndTree.InsertItem(m_Name,2,3);
}

void CMFCTreeDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	HTREEITEM hSel = m_wndTree.GetSelectedItem();
	if(hSel==NULL)
		return;
	m_wndTree.DeleteItem(hSel);
	
}

void CMFCTreeDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_Name == ""){
		AfxMessageBox("EditBox is Empty");
		return;
	}
	HTREEITEM hSel = m_wndTree.GetSelectedItem();
	if(hSel==NULL)
		return;
	m_wndTree.SetItemText(hSel,m_Name);
}

void CMFCTreeDlg::OnInsertChild() 
{

	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_Name == ""){
		AfxMessageBox("EditBox is Empty");
		return;
	}
	HTREEITEM hSel = m_wndTree.GetSelectedItem();
	if(hSel==NULL)
		return;
	m_wndTree.InsertItem(m_Name,2,3,hSel);
	m_wndTree.Expand(hSel,TVE_EXPAND);

}
