// Dlg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
// 2 �Ի�����
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
	//�ؼ�������İ�
    DDX_Control(pDX,IDOK,m_wndOK);
	DDX_Text(pDX,IDC_EDIT1,m_strEdit);

}
BOOL CMyDlg::OnInitDialog()
{
	//���ȵ��ø���OnInitDialog()����
	CDialog::OnInitDialog();

    //���ֿؼ��ĳ�ʼ��
    CWnd* pWnd=GetDlgItem(IDCANCEL);
	pWnd->SetWindowText("ȡ��");
    m_wndOK.SetWindowText("ȷ��");
	m_wndOK.MoveWindow(0,0,100,100);
    
	m_strEdit="Hello World";
	UpdateData(FALSE);

	return TRUE;
} 

// 1 Ӧ�ó�����
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	
	//ģʽ�Ի���
	CMyDlg dlg;
    m_pMainWnd=&dlg;
	dlg.DoModal();
	return TRUE;
}

