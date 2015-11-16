// SdiDoc.h : interface of the CSdiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDIDOC_H__7A2759E5_6EFD_4299_AE34_5CBA9B3A08BC__INCLUDED_)
#define AFX_SDIDOC_H__7A2759E5_6EFD_4299_AE34_5CBA9B3A08BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSdiDoc : public CDocument
{
protected: // create from serialization only
	CSdiDoc();
	DECLARE_DYNCREATE(CSdiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSdiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSdiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSdiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIDOC_H__7A2759E5_6EFD_4299_AE34_5CBA9B3A08BC__INCLUDED_)
