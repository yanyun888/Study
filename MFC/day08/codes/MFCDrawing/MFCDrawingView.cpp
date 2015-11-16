// MFCDrawingView.cpp : implementation of the CMFCDrawingView class
//

#include "stdafx.h"
#include "MFCDrawing.h"

#include "MFCDrawingDoc.h"
#include "MFCDrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingView

IMPLEMENT_DYNCREATE(CMFCDrawingView, CView)

BEGIN_MESSAGE_MAP(CMFCDrawingView, CView)
	//{{AFX_MSG_MAP(CMFCDrawingView)
	ON_COMMAND(ID_DC_CLIENT, OnDcClient)
	ON_WM_PAINT()
	ON_COMMAND(ID_DC_META, OnDcMeta)
	ON_COMMAND(ID_GDI_PEN, OnGdiPen)
	ON_COMMAND(ID_GDI_BRUSH, OnGdiBrush)
	ON_COMMAND(ID_GDI_FONT, OnGdiFont)
	ON_COMMAND(ID_GDI_BMP, OnGdiBmp)
	ON_COMMAND(ID_GDI_RGN, OnGdiRgn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingView construction/destruction

CMFCDrawingView::CMFCDrawingView()
{
	// TODO: add construction code here
    m_hMeta=NULL;
}

CMFCDrawingView::~CMFCDrawingView()
{
	if(m_hMeta)
		DeleteMetaFile(m_hMeta);
}

BOOL CMFCDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingView drawing

void CMFCDrawingView::OnDraw(CDC* pDC)
{
	CMFCDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingView printing

BOOL CMFCDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingView diagnostics

#ifdef _DEBUG
void CMFCDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawingDoc* CMFCDrawingView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawingDoc)));
	return (CMFCDrawingDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingView message handlers

void CMFCDrawingView::OnDcClient() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOut(0,0,"Hello CClientDC");
}

void CMFCDrawingView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
    dc.TextOut(0,100,"Hello CPaintDC");
	dc.PlayMetaFile(m_hMeta);
}

void CMFCDrawingView::OnDcMeta() 
{
	// TODO: Add your command handler code here
	CMetaFileDC dcMeta;
	dcMeta.Create();
	dcMeta.TextOut(200,180,"Hello CMetaFileDC");
	dcMeta.Rectangle(200,200,300,300);
	dcMeta.MoveTo(200,200);
	dcMeta.LineTo(300,300);
	m_hMeta=dcMeta.Close();
    //Ê¹ÓÃ
	CClientDC dc(this);
	dc.PlayMetaFile(m_hMeta);

}










void CMFCDrawingView::OnGdiPen() 
{
	// TODO: Add your command handler code here
	CPen pen(PS_SOLID,5,RGB(255,0,0));
	CClientDC dc(this);
	CPen *pOldPen=dc.SelectObject(&pen);
    dc.Rectangle(200,200,300,300);
	dc.SelectObject(pOldPen);
	pen.DeleteObject();
}

void CMFCDrawingView::OnGdiBrush() 
{
	// TODO: Add your command handler code here
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bmp);
	CClientDC dc(this);
	CBrush *pOldBrush=dc.SelectObject(&brush);
	dc.Rectangle(200,200,500,500);
	dc.SelectObject(pOldBrush);
	brush.DeleteObject();
}

void CMFCDrawingView::OnGdiFont() 
{
	// TODO: Add your command handler code here
	CFont font;
	font.CreatePointFont(1000,"ºÚÌå");
	CClientDC dc(this);
	CFont *pOldFont=dc.SelectObject(&font);
	dc.TextOut(100,100,"Hello CFont!");
	dc.SelectObject(pOldFont);
	font.DeleteObject();
}

void CMFCDrawingView::OnGdiBmp() 
{
	// TODO: Add your command handler code here
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP2);
	CClientDC dc(this);
	CDC dcBmp;//¼æÈÝdc
	dcBmp.CreateCompatibleDC(&dc);
	dcBmp.SelectObject(&bmp);
	dc.BitBlt(0,0,640,274,&dcBmp,0,0,SRCCOPY);
    dcBmp.DeleteDC();
	bmp.DeleteObject();
}

void CMFCDrawingView::OnGdiRgn() 
{
	// TODO: Add your command handler code here
	CRgn rgn1,rgn2;
	rgn1.CreateEllipticRgn(100,100,300,300);
	rgn2.CreateRectRgn(175,175,225,225);
	rgn1.CombineRgn(&rgn1,&rgn2,RGN_DIFF);
	CClientDC dc(this);
	CBrush brush(RGB(177,167,71));
	dc.FillRgn(&rgn1,&brush);
	CBrush Brush2(RGB(255,0,0));
	dc.FrameRgn(&rgn1,&Brush2,1,1);

	//AfxGetMainWnd()->SetWindowRgn(rgn1,TRUE);

}








