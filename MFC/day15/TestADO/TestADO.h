// TestADO.h : main header file for the TESTADO application
//

#if !defined(AFX_TESTADO_H__8AF6B041_FC58_49D0_AB04_FCC1704B7D87__INCLUDED_)
#define AFX_TESTADO_H__8AF6B041_FC58_49D0_AB04_FCC1704B7D87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestADOApp:
// See TestADO.cpp for the implementation of this class
//

class CTestADOApp : public CWinApp
{
public:
	CTestADOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestADOApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestADOApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTADO_H__8AF6B041_FC58_49D0_AB04_FCC1704B7D87__INCLUDED_)
