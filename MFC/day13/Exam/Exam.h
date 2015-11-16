// Exam.h : main header file for the EXAM application
//

#if !defined(AFX_EXAM_H__7B72A1F2_C1CF_42E4_AAEF_B295D19314E7__INCLUDED_)
#define AFX_EXAM_H__7B72A1F2_C1CF_42E4_AAEF_B295D19314E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExamApp:
// See Exam.cpp for the implementation of this class
//

class CExamApp : public CWinApp
{
public:
	CExamApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExamApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAM_H__7B72A1F2_C1CF_42E4_AAEF_B295D19314E7__INCLUDED_)
