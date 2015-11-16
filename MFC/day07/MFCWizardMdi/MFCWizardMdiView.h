// MFCWizardMdiView.h : interface of the CMFCWizardMdiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCWIZARDMDIVIEW_H__5A0D2DB7_BF7B_47AA_B232_48D44B942B15__INCLUDED_)
#define AFX_MFCWIZARDMDIVIEW_H__5A0D2DB7_BF7B_47AA_B232_48D44B942B15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCWizardMdiView : public CView
{
protected: // create from serialization only
	CMFCWizardMdiView();
	DECLARE_DYNCREATE(CMFCWizardMdiView)

// Attributes
public:
	CMFCWizardMdiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCWizardMdiView)
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
	virtual ~CMFCWizardMdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCWizardMdiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCWizardMdiView.cpp
inline CMFCWizardMdiDoc* CMFCWizardMdiView::GetDocument()
   { return (CMFCWizardMdiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCWIZARDMDIVIEW_H__5A0D2DB7_BF7B_47AA_B232_48D44B942B15__INCLUDED_)
