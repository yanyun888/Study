// UseWMPDlg.h : header file
//
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
//}}AFX_INCLUDES

#if !defined(AFX_USEWMPDLG_H__E92F18CD_F430_4122_ADDD_14D67E0A15D5__INCLUDED_)
#define AFX_USEWMPDLG_H__E92F18CD_F430_4122_ADDD_14D67E0A15D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseWMPDlg dialog

class CUseWMPDlg : public CDialog
{
// Construction
public:
	CUseWMPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseWMPDlg)
	enum { IDD = IDD_USEWMP_DIALOG };
	CWMPPlayer4	m_wndPlayer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseWMPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseWMPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEWMPDLG_H__E92F18CD_F430_4122_ADDD_14D67E0A15D5__INCLUDED_)
