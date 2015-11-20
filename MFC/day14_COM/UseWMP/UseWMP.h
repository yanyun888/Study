// UseWMP.h : main header file for the USEWMP application
//

#if !defined(AFX_USEWMP_H__BBC22C32_EAB4_485A_9D61_191D4B8E7DEA__INCLUDED_)
#define AFX_USEWMP_H__BBC22C32_EAB4_485A_9D61_191D4B8E7DEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseWMPApp:
// See UseWMP.cpp for the implementation of this class
//

class CUseWMPApp : public CWinApp
{
public:
	CUseWMPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseWMPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseWMPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEWMP_H__BBC22C32_EAB4_485A_9D61_191D4B8E7DEA__INCLUDED_)
