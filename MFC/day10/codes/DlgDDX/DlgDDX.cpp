// Dlg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
// 2 对话框类
class CMyDlg:public CDialog
{
public:
	CMyDlg():CDialog(IDD_DIALOG1){}
	virtual BOOL OnInitDialog( );
	virtual void DoDataExchange( CDataExchange* pDX );
    virtual void OnOK();
protected:
	CButton m_wndOK;
	CString m_strEdit;
};
void CMyDlg::OnOK()
{
	UpdateData(TRUE);
	MessageBox(m_strEdit);
}
void CMyDlg::DoDataExchange( CDataExchange* pDX )
{
	//控件与变量的绑定
    DDX_Control(pDX,IDOK,m_wndOK);
	DDX_Text(pDX,IDC_EDIT1,m_strEdit);

}
BOOL CMyDlg::OnInitDialog()
{
	//首先调用父类OnInitDialog()函数
	CDialog::OnInitDialog();

    //各种控件的初始化
    CWnd* pWnd=GetDlgItem(IDCANCEL);
	pWnd->SetWindowText("取消");
    m_wndOK.SetWindowText("确定");
	m_wndOK.MoveWindow(0,0,100,100);
    
	m_strEdit="Hello World";
	UpdateData(FALSE);

	return TRUE;
} 

// 1 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	
	//模式对话框
	CMyDlg dlg;
    m_pMainWnd=&dlg;
	dlg.DoModal();
	return TRUE;
}

