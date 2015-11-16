// SdiView.h : interface of the CSdiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDIVIEW_H__5BD10C96_9A21_4238_A94F_AE2A7C7F6D13__INCLUDED_)
#define AFX_SDIVIEW_H__5BD10C96_9A21_4238_A94F_AE2A7C7F6D13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SdiDoc.h"
class CSdiView : public CView
{
protected: // create from serialization only
	CSdiView();
	DECLARE_DYNCREATE(CSdiView)

// Attributes
public:
	CSdiDoc* GetDocument();
	COLORREF m_lineColor;  // ÑÕÉ«
	int m_lineWidth;       // Ïß¿í   
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSdiView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSdiView)
	afx_msg void OnPropertySheet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SdiView.cpp
inline CSdiDoc* CSdiView::GetDocument()
   { return (CSdiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIVIEW_H__5BD10C96_9A21_4238_A94F_AE2A7C7F6D13__INCLUDED_)
