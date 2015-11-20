// MFCListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCList.h"
#include "MFCListDlg.h"

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
// CMFCListDlg dialog

CMFCListDlg::CMFCListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCListDlg)
	DDX_Control(pDX, IDC_STYLE, m_wndStyle);
	DDX_Control(pDX, IDC_LIST, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCListDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_CBN_SELCHANGE(IDC_STYLE, OnSelchangeStyle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCListDlg message handlers

BOOL CMFCListDlg::OnInitDialog()
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
	m_wndStyle.SetCurSel(3);
	InitListCtrl();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCListDlg::OnPaint() 
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
HCURSOR CMFCListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCListDlg::InitListCtrl()
{
	m_ilNormal.Create(IDB_NORMAL,32,1,RGB(0,0,0));
	m_ilSmall.Create(IDB_SMALL,16,1,RGB(0,0,0));
	
	m_wndList.SetImageList(&m_ilNormal,LVSIL_NORMAL);
	m_wndList.SetImageList(&m_ilSmall,LVSIL_SMALL);
	
	m_wndList.InsertColumn(0,"Name",LVCFMT_LEFT,100);
	m_wndList.InsertColumn(1,"Size",LVCFMT_LEFT,100);
	m_wndList.InsertColumn(2,"Type",LVCFMT_LEFT,100);
	m_wndList.InsertColumn(3,"Time",LVCFMT_LEFT,120);
	
#if 0

	m_wndList.InsertItem(0,"Soft Package",0);
	m_wndList.InsertItem(1,"note.doc",1);

	m_wndList.SetItemText(0,2,"folder");
	m_wndList.SetItemText(0,3,"2015,-11-11");

	m_wndList.SetItemText(1,1,"558k");
	m_wndList.SetItemText(1,3,"2015,-11-12");

#endif
	
	Show("C:");
	AfxOleInit();
	
	m_wndList.SetBkImage("D:\tatoo1.bmp");
	m_wndList.SetTextBkColor(CLR_NONE);

}

void CMFCListDlg::Show(CString strPath)
{
	//在显示时清空原有数据
	m_wndList.DeleteAllItems();
	m_listPath.RemoveAll();

	CFileFind find;
	int nCount = 0;
	
	BOOL bRet = find.FindFile(strPath+"/*.*");
	while(bRet){
		bRet = find.FindNextFile();
		CString strName = find.GetFileName();
		
		CTime t;
		find.GetCreationTime(t);
		CString strTime;
		strTime.Format("%d-%d-%d",
			t.GetYear(),t.GetMonth(),t.GetDay());

		if(find.IsDirectory()){
			m_wndList.InsertItem(nCount,strName,0);
			m_wndList.SetItemText(nCount,2,"Folder");
		}
		else{
			m_wndList.InsertItem(nCount,strName,1);
			m_wndList.SetItemText(nCount,2,"File");
			
			CString strLength;
			strLength.Format("%d",find.GetLength());
			m_wndList.SetItemText(nCount,1,strLength);
		}
		
		m_wndList.SetItemText(nCount,3,strTime);
	//保存文件数据到附加数据中
		/*
		CString* pPath = new CString;
		*pPath=find.GetFilePath();
		m_wndList.SetItemData(nCount,(DWORD)pPath);
		*/
		m_listPath.AddTail(find.GetFilePath());
		
		++nCount;
	}
	find.Close();
}

void CMFCListDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LPNMITEMACTIVATE pItem = (LPNMITEMACTIVATE)pNMHDR;
	int nItem = pItem->iItem;
	if(nItem==-1) return;
/*
	//根据索引值得到对应的文件路径
	CString * pPath = (CString*)m_wndList.GetItemData(nItem);
	Show(*pPath);
*/	
	CString strPath = m_listPath.GetAt(m_listPath.FindIndex(nItem));
	Show(strPath);

	*pResult = 0;
}

void CMFCListDlg::OnSelchangeStyle() 
{
	// TODO: Add your control notification handler code here

	int nIndex = m_wndStyle.GetCurSel();
	switch(nIndex){
	case 0:
		m_wndList.ModifyStyle(LVS_SMALLICON|LVS_LIST|LVS_REPORT,LVS_ICON);
		break;
	case 1:
		m_wndList.ModifyStyle(LVS_ICON|LVS_LIST|LVS_REPORT,LVS_SMALLICON);
		break;
	case 2:
		m_wndList.ModifyStyle(LVS_SMALLICON|LVS_ICON|LVS_REPORT,LVS_LIST);
		break;
	case 3:
		m_wndList.ModifyStyle(LVS_SMALLICON|LVS_LIST|LVS_ICON,LVS_REPORT);
		break;	
	}
	
}
