// TestADODlg.h : header file
//

#if !defined(AFX_TESTADODLG_H__18B1EC00_275E_45C1_AE2C_35FD6AAE98D8__INCLUDED_)
#define AFX_TESTADODLG_H__18B1EC00_275E_45C1_AE2C_35FD6AAE98D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestADODlg dialog

#include "AdoDatabase.h"
#include "AdoRecordset.h"

class CTestADODlg : public CDialog
{
// Construction
public:
	void ShowData(CAdoRecordset* pSet);
	CTestADODlg(CWnd* pParent = NULL);	// standard constructor
	CAdoDatabase m_db;
// Dialog Data
	//{{AFX_DATA(CTestADODlg)
	enum { IDD = IDD_TESTADO_DIALOG };
	CListCtrl	m_wndList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestADODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestADODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenDb();
	afx_msg void OnOpenTable();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTADODLG_H__18B1EC00_275E_45C1_AE2C_35FD6AAE98D8__INCLUDED_)
