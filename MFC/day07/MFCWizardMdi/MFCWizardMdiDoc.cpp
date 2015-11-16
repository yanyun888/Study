// MFCWizardMdiDoc.cpp : implementation of the CMFCWizardMdiDoc class
//

#include "stdafx.h"
#include "MFCWizardMdi.h"

#include "MFCWizardMdiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiDoc

IMPLEMENT_DYNCREATE(CMFCWizardMdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCWizardMdiDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCWizardMdiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiDoc construction/destruction

CMFCWizardMdiDoc::CMFCWizardMdiDoc()
{
	// TODO: add one-time construction code here

}

CMFCWizardMdiDoc::~CMFCWizardMdiDoc()
{
}

BOOL CMFCWizardMdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiDoc serialization

void CMFCWizardMdiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiDoc diagnostics

#ifdef _DEBUG
void CMFCWizardMdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCWizardMdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiDoc commands
