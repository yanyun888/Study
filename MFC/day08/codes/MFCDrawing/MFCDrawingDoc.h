// MFCDrawingDoc.h : interface of the CMFCDrawingDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCDRAWINGDOC_H__6040EA05_1439_4CFD_8FBE_2E06089E7D34__INCLUDED_)
#define AFX_MFCDRAWINGDOC_H__6040EA05_1439_4CFD_8FBE_2E06089E7D34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCDrawingDoc : public CDocument
{
protected: // create from serialization only
	CMFCDrawingDoc();
	DECLARE_DYNCREATE(CMFCDrawingDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDrawingDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCDrawingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCDrawingDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDRAWINGDOC_H__6040EA05_1439_4CFD_8FBE_2E06089E7D34__INCLUDED_)
