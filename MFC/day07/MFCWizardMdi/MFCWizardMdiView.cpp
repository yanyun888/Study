// MFCWizardMdiView.cpp : implementation of the CMFCWizardMdiView class
//

#include "stdafx.h"
#include "MFCWizardMdi.h"

#include "MFCWizardMdiDoc.h"
#include "MFCWizardMdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiView

IMPLEMENT_DYNCREATE(CMFCWizardMdiView, CView)

BEGIN_MESSAGE_MAP(CMFCWizardMdiView, CView)
	//{{AFX_MSG_MAP(CMFCWizardMdiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiView construction/destruction

CMFCWizardMdiView::CMFCWizardMdiView()
{
	// TODO: add construction code here

}

CMFCWizardMdiView::~CMFCWizardMdiView()
{
}

BOOL CMFCWizardMdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiView drawing

void CMFCWizardMdiView::OnDraw(CDC* pDC)
{
	CMFCWizardMdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiView printing

BOOL CMFCWizardMdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCWizardMdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCWizardMdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiView diagnostics

#ifdef _DEBUG
void CMFCWizardMdiView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCWizardMdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCWizardMdiDoc* CMFCWizardMdiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCWizardMdiDoc)));
	return (CMFCWizardMdiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardMdiView message handlers
