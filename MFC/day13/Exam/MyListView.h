#if !defined(AFX_MYLISTVIEW_H__9642D7C8_583C_4F00_8076_9149B069CE1A__INCLUDED_)
#define AFX_MYLISTVIEW_H__9642D7C8_583C_4F00_8076_9149B069CE1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyListView view

#include <afxcview.h>

class CMyListView : public CListView
{
protected:
	CMyListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyListView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyListView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyListView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTVIEW_H__9642D7C8_583C_4F00_8076_9149B069CE1A__INCLUDED_)
