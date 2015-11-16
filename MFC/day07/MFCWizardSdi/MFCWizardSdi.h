// MFCWizardSdi.h : main header file for the MFCWIZARDSDI application
//

#if !defined(AFX_MFCWIZARDSDI_H__0885CCAD_5F8F_405F_8B10_56C877ED1E85__INCLUDED_)
#define AFX_MFCWIZARDSDI_H__0885CCAD_5F8F_405F_8B10_56C877ED1E85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCWizardSdiApp:
// See MFCWizardSdi.cpp for the implementation of this class
//

class CMFCWizardSdiApp : public CWinApp
{
public:
	CMFCWizardSdiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCWizardSdiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCWizardSdiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCWIZARDSDI_H__0885CCAD_5F8F_405F_8B10_56C877ED1E85__INCLUDED_)
