// MFCDll.h : main header file for the MFCDLL DLL
//

#if !defined(AFX_MFCDLL_H__37DE97C5_C5C7_4D26_8436_07420A85640F__INCLUDED_)
#define AFX_MFCDLL_H__37DE97C5_C5C7_4D26_8436_07420A85640F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCDllApp
// See MFCDll.cpp for the implementation of this class
//

class CMFCDllApp : public CWinApp
{
public:
	CMFCDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMFCDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDLL_H__37DE97C5_C5C7_4D26_8436_07420A85640F__INCLUDED_)
