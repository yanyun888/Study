// ExamDoc.h : interface of the CExamDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXAMDOC_H__16EFFBB1_A348_4370_962C_B0F34BE6AA48__INCLUDED_)
#define AFX_EXAMDOC_H__16EFFBB1_A348_4370_962C_B0F34BE6AA48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExamDoc : public CDocument
{
protected: // create from serialization only
	CExamDoc();
	DECLARE_DYNCREATE(CExamDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExamDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMDOC_H__16EFFBB1_A348_4370_962C_B0F34BE6AA48__INCLUDED_)
