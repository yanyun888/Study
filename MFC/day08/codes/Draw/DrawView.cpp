// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_COMMAND(ID_DRAW_RECT, OnDrawRect)
	ON_COMMAND(ID_DRAW_ELIP, OnDrawElip)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView construction/destruction

CDrawView::CDrawView()
{
	// TODO: add construction code here
    m_nType=0;
	m_ptBegin=m_ptEnd=0;
	m_bFlag=FALSE;
}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView printing

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::OnDrawLine() 
{
	// TODO: Add your command handler code here
	m_nType=1;//直线
}

void CDrawView::OnDrawRect() 
{
	// TODO: Add your command handler code here
	m_nType=2;//矩形
}

void CDrawView::OnDrawElip() 
{
	// TODO: Add your command handler code here
	m_nType=3;//椭圆

}

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//确定图形的起点
	m_ptBegin=m_ptEnd=point;
    m_bFlag=TRUE;//开始绘图
	CView::OnLButtonDown(nFlags, point);
}

void CDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bFlag)
	{
	  //动态的绘图图形
		CClientDC dc(this);
      // 1 擦除上次绘制的图形
        DrawShape(&dc,m_ptBegin,m_ptEnd);
      // 2 画新的图形
		DrawShape(&dc,m_ptBegin,point);
       //3 修改终点坐标
        m_ptEnd=point;

	}
	CView::OnMouseMove(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//绘制结束
	m_bFlag=FALSE;

	CView::OnLButtonUp(nFlags, point);
}

void CDrawView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CDrawView::DrawShape(CDC *pDC, CPoint p1, CPoint p2)
{
   int nOldMode=pDC->SetROP2(R2_NOT);
   CBrush *pOldBrush=(CBrush*)
	   pDC->SelectStockObject(NULL_BRUSH);
   switch(m_nType)
   {
   case 1:
	   pDC->MoveTo(p1.x,p1.y);
	   pDC->LineTo(p2.x,p2.y);
	   break;
   case 2:
	   pDC->Rectangle(p1.x,p1.y,p2.x,p2.y);
	   break;
   case 3:
	   pDC->Ellipse(p1.x,p1.y,p2.x,p2.y);
	   break;
   }
   pDC->SelectObject(pOldBrush);
   pDC->SetROP2(nOldMode);

}












