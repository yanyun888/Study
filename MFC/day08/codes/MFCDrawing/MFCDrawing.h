// MFCDrawing.h : main header file for the MFCDRAWING application
//

#if !defined(AFX_MFCDRAWING_H__4F0EB845_49EE_4E7B_988A_E7D50047214A__INCLUDED_)
#define AFX_MFCDRAWING_H__4F0EB845_49EE_4E7B_988A_E7D50047214A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCDrawingApp:
// See MFCDrawing.cpp for the implementation of this class
//

class CMFCDrawingApp : public CWinApp
{
public:
	CMFCDrawingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDrawingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCDrawingApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDRAWING_H__4F0EB845_49EE_4E7B_988A_E7D50047214A__INCLUDED_)
