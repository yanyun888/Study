// MFCWizardSdiDoc.cpp : implementation of the CMFCWizardSdiDoc class
//

#include "stdafx.h"
#include "MFCWizardSdi.h"

#include "MFCWizardSdiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiDoc

IMPLEMENT_DYNCREATE(CMFCWizardSdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCWizardSdiDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCWizardSdiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiDoc construction/destruction

CMFCWizardSdiDoc::CMFCWizardSdiDoc()
{
	// TODO: add one-time construction code here

}

CMFCWizardSdiDoc::~CMFCWizardSdiDoc()
{
}

BOOL CMFCWizardSdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiDoc serialization

void CMFCWizardSdiDoc::Serialize(CArchive& ar)
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
// CMFCWizardSdiDoc diagnostics

#ifdef _DEBUG
void CMFCWizardSdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCWizardSdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiDoc commands
