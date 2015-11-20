// MFCDrawingView.h : interface of the CMFCDrawingView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCDRAWINGVIEW_H__F6754073_1F30_4624_A4FC_8CDC66827305__INCLUDED_)
#define AFX_MFCDRAWINGVIEW_H__F6754073_1F30_4624_A4FC_8CDC66827305__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCDrawingView : public CView
{
protected: // create from serialization only
	CMFCDrawingView();
	DECLARE_DYNCREATE(CMFCDrawingView)

// Attributes
public:
	CMFCDrawingDoc* GetDocument();
    HMETAFILE m_hMeta;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDrawingView)
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
	virtual ~CMFCDrawingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCDrawingView)
	afx_msg void OnDcClient();
	afx_msg void OnPaint();
	afx_msg void OnDcMeta();
	afx_msg void OnGdiPen();
	afx_msg void OnGdiBrush();
	afx_msg void OnGdiFont();
	afx_msg void OnGdiBmp();
	afx_msg void OnGdiRgn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCDrawingView.cpp
inline CMFCDrawingDoc* CMFCDrawingView::GetDocument()
   { return (CMFCDrawingDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDRAWINGVIEW_H__F6754073_1F30_4624_A4FC_8CDC66827305__INCLUDED_)
