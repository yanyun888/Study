// SetSheet.cpp : implementation file
//

#include "stdafx.h"
#include "Sdi.h"
#include "SetSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetSheet

IMPLEMENT_DYNAMIC(CSetSheet, CPropertySheet)

CSetSheet::CSetSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_page1);
	AddPage(&m_page2);
}

CSetSheet::CSetSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_page1);
	AddPage(&m_page2);
}

CSetSheet::~CSetSheet()
{
}


BEGIN_MESSAGE_MAP(CSetSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSetSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetSheet message handlers
