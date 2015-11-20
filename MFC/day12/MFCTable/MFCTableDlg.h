// MFCTableDlg.h : header file
//

#if !defined(AFX_MFCTABLEDLG_H__72B73B90_2237_46A6_A98D_3222B2931ABC__INCLUDED_)
#define AFX_MFCTABLEDLG_H__72B73B90_2237_46A6_A98D_3222B2931ABC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCTableDlg dialog

#include "Dialog1.h"
#include "Dialog2.h"

class CMFCTableDlg : public CDialog
{
// Construction
public:
	void InitTableCtrl();
	CMFCTableDlg(CWnd* pParent = NULL);	// standard constructor
	CDialog1 m_dlg1;
	CDialog2 m_dlg2;

// Dialog Data
	//{{AFX_DATA(CMFCTableDlg)
	enum { IDD = IDD_MFCTABLE_DIALOG };
	CTabCtrl	m_wndTable;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCTableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCTableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTABLEDLG_H__72B73B90_2237_46A6_A98D_3222B2931ABC__INCLUDED_)
