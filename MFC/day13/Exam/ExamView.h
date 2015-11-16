// ExamView.h : interface of the CExamView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXAMVIEW_H__126A4E17_C18F_4BD7_BBD4_7B496ECC910F__INCLUDED_)
#define AFX_EXAMVIEW_H__126A4E17_C18F_4BD7_BBD4_7B496ECC910F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExamView : public CView
{
protected: // create from serialization only
	CExamView();
	DECLARE_DYNCREATE(CExamView)

// Attributes
public:
	CExamDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamView)
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
	virtual ~CExamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExamView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ExamView.cpp
inline CExamDoc* CExamView::GetDocument()
   { return (CExamDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMVIEW_H__126A4E17_C18F_4BD7_BBD4_7B496ECC910F__INCLUDED_)
