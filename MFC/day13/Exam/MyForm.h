#if !defined(AFX_MYFORM_H__479CDF96_3DAA_492C_A538_8BA8280023B8__INCLUDED_)
#define AFX_MYFORM_H__479CDF96_3DAA_492C_A538_8BA8280023B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyForm form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "MyListView.h"
#include "MyForm.h"
class CMyForm : public CFormView
{
protected:
	CMyForm();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyForm)

// Form Data
public:
	//{{AFX_DATA(CMyForm)
	enum { IDD = IDD_FORMVIEW };
	CString	m_strName;
	CString	m_strAddr;
	CString	m_strAge;
	//}}AFX_DATA

// Attributes
public:
	CMyListView* m_pListView;
	CEditView* m_pEditView;	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyForm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyForm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMyForm)
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFORM_H__479CDF96_3DAA_492C_A538_8BA8280023B8__INCLUDED_)
