// MFCWizardMdiDoc.h : interface of the CMFCWizardMdiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCWIZARDMDIDOC_H__988E60C0_0F75_4D89_95BF_FF61F7B6788B__INCLUDED_)
#define AFX_MFCWIZARDMDIDOC_H__988E60C0_0F75_4D89_95BF_FF61F7B6788B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCWizardMdiDoc : public CDocument
{
protected: // create from serialization only
	CMFCWizardMdiDoc();
	DECLARE_DYNCREATE(CMFCWizardMdiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCWizardMdiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCWizardMdiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCWizardMdiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCWIZARDMDIDOC_H__988E60C0_0F75_4D89_95BF_FF61F7B6788B__INCLUDED_)
