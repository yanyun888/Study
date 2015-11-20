// MFCDrawingDoc.cpp : implementation of the CMFCDrawingDoc class
//

#include "stdafx.h"
#include "MFCDrawing.h"

#include "MFCDrawingDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingDoc

IMPLEMENT_DYNCREATE(CMFCDrawingDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCDrawingDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCDrawingDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingDoc construction/destruction

CMFCDrawingDoc::CMFCDrawingDoc()
{
	// TODO: add one-time construction code here

}

CMFCDrawingDoc::~CMFCDrawingDoc()
{
}

BOOL CMFCDrawingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingDoc serialization

void CMFCDrawingDoc::Serialize(CArchive& ar)
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
// CMFCDrawingDoc diagnostics

#ifdef _DEBUG
void CMFCDrawingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCDrawingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingDoc commands
