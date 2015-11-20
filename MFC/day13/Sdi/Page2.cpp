// Page2.cpp : implementation file
//

#include "stdafx.h"
#include "Sdi.h"
#include "Page2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage2 property page

IMPLEMENT_DYNCREATE(CPage2, CPropertyPage)

CPage2::CPage2() : CPropertyPage(CPage2::IDD)
{
	//{{AFX_DATA_INIT(CPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CPage2)
	ON_BN_CLICKED(IDC_SETCOLOR, OnSetColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2 message handlers

void CPage2::OnSetColor() 
{
	// TODO: Add your control notification handler code here
	//1 ��Ӧ�ð�ť���ÿ���
	SetModified(true);
	//2 ��������ʾ��ɫ�Ի���
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK){
		//3 ��ȡ��ɫ����������ĳ�Ա������
		m_Color = dlg.GetColor();
		TRACE("RGB value of the selected color - red = %u, green = %u, blue = %u\n",
			GetRValue(m_Color), GetGValue(m_Color), GetBValue(m_Color));
			
	}
}


#include "SdiView.h"
BOOL CPage2::OnApply() 
{
	// TODO: Add your specialized code here and/or call the base class
	

	//4 ��ȡ��ͼ����
	CSdiView *pView = (CSdiView*)
	((CFrameWnd*) AfxGetMainWnd() )->GetActiveView();
	//m_nLineWidth
	//5 ���Ի��е���ɫ��ֵ����ͼ�ĳ�Ա
	pView->m_lineColor = m_Color;
	//6 ��ͼ�ػ�
	pView->Invalidate();

	return CPropertyPage::OnApply();
}

BOOL CPage2::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_FINISH|PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}
