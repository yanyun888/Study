// McdPpg.cpp : Implementation of the CMcdPropPage property page class.

#include "stdafx.h"
#include "Mcd.h"
#include "McdPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CMcdPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMcdPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CMcdPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMcdPropPage, "MCD.McdPropPage.1",
	0xd4b1ef96, 0xf15c, 0x41fa, 0x86, 0xae, 0xfe, 0x89, 0x1c, 0x5e, 0x93, 0x1c)


/////////////////////////////////////////////////////////////////////////////
// CMcdPropPage::CMcdPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMcdPropPage

BOOL CMcdPropPage::CMcdPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MCD_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CMcdPropPage::CMcdPropPage - Constructor

CMcdPropPage::CMcdPropPage() :
	COlePropertyPage(IDD, IDS_MCD_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CMcdPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CMcdPropPage::DoDataExchange - Moves data between page and properties

void CMcdPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CMcdPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CMcdPropPage message handlers
