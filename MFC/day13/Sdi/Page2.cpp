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
	//1 将应用按钮设置可用
	SetModified(true);
	//2 创建和显示颜色对话框
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK){
		//3 获取颜色，保存在类的成员变量中
		m_Color = dlg.GetColor();
		TRACE("RGB value of the selected color - red = %u, green = %u, blue = %u\n",
			GetRValue(m_Color), GetGValue(m_Color), GetBValue(m_Color));
			
	}
}


#include "SdiView.h"
BOOL CPage2::OnApply() 
{
	// TODO: Add your specialized code here and/or call the base class
	

	//4 获取视图对象
	CSdiView *pView = (CSdiView*)
	((CFrameWnd*) AfxGetMainWnd() )->GetActiveView();
	//m_nLineWidth
	//5 将对话中的颜色赋值给视图的成员
	pView->m_lineColor = m_Color;
	//6 视图重绘
	pView->Invalidate();

	return CPropertyPage::OnApply();
}

BOOL CPage2::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_FINISH|PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}
