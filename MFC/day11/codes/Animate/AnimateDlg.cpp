// AnimateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Animate.h"
#include "AnimateDlg.h"

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
// CAnimateDlg dialog

CAnimateDlg::CAnimateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnimateDlg)
	m_strFilePath = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnimateDlg)
	DDX_Control(pDX, IDC_PLAY_COUNT, m_wndPlayCount);
	DDX_Control(pDX, IDC_REPLAY, m_wndReplay);
	DDX_Control(pDX, IDC_ANIMATE, m_wndAnimate);
	DDX_Control(pDX, IDC_FILE_LIST, m_wndFileList);
	DDX_Text(pDX, IDC_FILE_PATH, m_strFilePath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnimateDlg, CDialog)
	//{{AFX_MSG_MAP(CAnimateDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_FILE, OnOpenFile)
	ON_LBN_DBLCLK(IDC_FILE_LIST, OnDblclkFileList)
    ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_REPLAY, OnRePlay)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimateDlg message handlers

BOOL CAnimateDlg::OnInitDialog()
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
	m_wndPlayCount.EnableWindow(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAnimateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAnimateDlg::OnPaint() 
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
HCURSOR CAnimateDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAnimateDlg::OnOpenFile() 
{
	// 1 弹出文件对话框，获取文件路径和文件名称
	char szFilter[]="动画文件(*.avi)|*.avi|所有文件(*.*)|*.*||";
	CFileDialog dlg(TRUE,NULL,NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter);
	if (dlg.DoModal()==IDCANCEL)return;

	// 2 将文件路径显示到文本框控件中
    m_strFilePath=dlg.GetPathName();
	UpdateData(FALSE);
	
	// 3 在列表框控件中添加文件名称
	CString strName=dlg.GetFileName();
	if(-1==m_wndFileList.FindString(0,strName))
	{
		int nIndex=m_wndFileList.AddString(strName);
		//在添加选项的同时添加文件路径
        CString *pPath=new CString;
		*pPath=m_strFilePath;
		m_wndFileList.SetItemData(nIndex,(DWORD)pPath);
	}

	// 4 播放动画
    Play();

}

void CAnimateDlg::OnDblclkFileList() 
{
	// 1 获取双击时的选项的索引
     int curSel=m_wndFileList.GetCurSel();
	 if (-1==curSel)return;
	// 2 根据索引值获取对应的文件路径，并在文本框中显示
    CString* pPath=
		(CString*)m_wndFileList.GetItemData(curSel);
	m_strFilePath=*pPath;
	UpdateData(FALSE);
	// 3 根据路径播放文件
    Play();
	
}
void CAnimateDlg::Play()
{
	int nCount=0;

	if (m_wndReplay.GetCheck())
	{
		//根据列表框选项设置次数
		int nCur=m_wndPlayCount.GetCurSel();
		switch(nCur)
		{
		case 0:
			nCount=2;
			break;
		case 1:
			nCount=3;
			break;
		case 2:
			nCount=-1;
			break;
		default:
			nCount=1;
		}
	}
	else
	{
		nCount=1;
	}
	m_wndAnimate.Open(m_strFilePath);
	m_wndAnimate.Play(0,-1,nCount);
}
void CAnimateDlg::OnClose( )
{
   int nCount=m_wndFileList.GetCount();
   for (int i=0;i<nCount;i++)
   {
	   CString *pPath=
		   (CString*)m_wndFileList.GetItemData(i);
       delete pPath;  
   }
   CDialog::OnClose();
} 
void CAnimateDlg::OnRePlay()
{
	if (m_wndReplay.GetCheck())
	{
		m_wndPlayCount.EnableWindow(TRUE);
	}
	else
	{
		m_wndPlayCount.EnableWindow(FALSE);
	}
}


void CAnimateDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	Play();
}

void CAnimateDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	m_wndAnimate.Stop();
}
