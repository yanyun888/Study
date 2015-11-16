// DlgLogin.cpp : implementation file
//

#include "stdafx.h"
#include "Login.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin dialog


CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLogin)
	m_strName = _T("");
	m_strPwd = _T("");
	//}}AFX_DATA_INIT
}


void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLogin)
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_PWD, m_strPwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	//{{AFX_MSG_MAP(CDlgLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin message handlers

void CDlgLogin::OnOK() 
{
	// 登录的验证，csd1506,456
	UpdateData(TRUE);
	if ("csd1506"==m_strName&&"456"==m_strPwd)
	{
		CDialog::OnOK();
	}
	else
	{
		MessageBox("用户名称或者密码错误，请重新输入！");
	}
	
}
