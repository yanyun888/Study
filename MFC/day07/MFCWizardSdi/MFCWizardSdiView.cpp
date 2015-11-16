// MFCWizardSdiView.cpp : implementation of the CMFCWizardSdiView class
//

#include "stdafx.h"
#include "MFCWizardSdi.h"

#include "MFCWizardSdiDoc.h"
#include "MFCWizardSdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiView

IMPLEMENT_DYNCREATE(CMFCWizardSdiView, CView)

BEGIN_MESSAGE_MAP(CMFCWizardSdiView, CView)
	//{{AFX_MSG_MAP(CMFCWizardSdiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiView construction/destruction

CMFCWizardSdiView::CMFCWizardSdiView()
{
	// TODO: add construction code here

}

CMFCWizardSdiView::~CMFCWizardSdiView()
{
}

BOOL CMFCWizardSdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiView drawing

void CMFCWizardSdiView::OnDraw(CDC* pDC)
{
	CMFCWizardSdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiView printing

BOOL CMFCWizardSdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCWizardSdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCWizardSdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiView diagnostics

#ifdef _DEBUG
void CMFCWizardSdiView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCWizardSdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCWizardSdiDoc* CMFCWizardSdiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCWizardSdiDoc)));
	return (CMFCWizardSdiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiView message handlers
