// MyForm.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "MyForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyForm

IMPLEMENT_DYNCREATE(CMyForm, CFormView)

CMyForm::CMyForm()
	: CFormView(CMyForm::IDD)
{
	//{{AFX_DATA_INIT(CMyForm)
	m_strName = _T("");
	m_strAddr = _T("");
	m_strAge = _T("");
	//}}AFX_DATA_INIT

	m_pListView=NULL;
	m_pEditView=NULL;	

}

CMyForm::~CMyForm()
{
}

void CMyForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyForm)
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_ADDRESS, m_strAddr);
	DDX_Text(pDX, IDC_AGE, m_strAge);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyForm, CFormView)
	//{{AFX_MSG_MAP(CMyForm)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyForm diagnostics

#ifdef _DEBUG
void CMyForm::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyForm message handlers

void CMyForm::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	//1 添加到右边的列表那
	static int nItem=0;
	CListCtrl& theCtrl = m_pListView->GetListCtrl();
	theCtrl.InsertItem(nItem,m_strName);
	theCtrl.SetItemText(nItem,1,m_strAge);
	theCtrl.SetItemText(nItem,2,m_strAddr);
	++nItem;
	//CString strMsg();

}
