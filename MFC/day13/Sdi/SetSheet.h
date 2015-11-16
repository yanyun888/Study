#if !defined(AFX_SETSHEET_H__39A8305C_6D5F_4894_818E_2AD676FF880F__INCLUDED_)
#define AFX_SETSHEET_H__39A8305C_6D5F_4894_818E_2AD676FF880F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetSheet.h : header file
//

#include "Page1.h"
#include "Page2.h"

/////////////////////////////////////////////////////////////////////////////
// CSetSheet

class CSetSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSetSheet)

// Construction
public:
	CSetSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSetSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CPage1 m_page1;
	CPage2 m_page2;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSetSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSetSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSHEET_H__39A8305C_6D5F_4894_818E_2AD676FF880F__INCLUDED_)
