// MFCWizardSdiView.h : interface of the CMFCWizardSdiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCWIZARDSDIVIEW_H__7C1B3D33_D5B4_4BE6_95AC_4AB2391018B1__INCLUDED_)
#define AFX_MFCWIZARDSDIVIEW_H__7C1B3D33_D5B4_4BE6_95AC_4AB2391018B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCWizardSdiView : public CView
{
protected: // create from serialization only
	CMFCWizardSdiView();
	DECLARE_DYNCREATE(CMFCWizardSdiView)

// Attributes
public:
	CMFCWizardSdiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCWizardSdiView)
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
	virtual ~CMFCWizardSdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCWizardSdiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCWizardSdiView.cpp
inline CMFCWizardSdiDoc* CMFCWizardSdiView::GetDocument()
   { return (CMFCWizardSdiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCWIZARDSDIVIEW_H__7C1B3D33_D5B4_4BE6_95AC_4AB2391018B1__INCLUDED_)
