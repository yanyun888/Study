// ODBCDlg.h : header file
//

#if !defined(AFX_ODBCDLG_H__74075C9D_4FC2_4271_B5AD_C2455DC7F828__INCLUDED_)
#define AFX_ODBCDLG_H__74075C9D_4FC2_4271_B5AD_C2455DC7F828__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CODBCDlg dialog

class CODBCDlg : public CDialog
{
// Construction
public:
	CODBCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CODBCDlg)
	enum { IDD = IDD_ODBC_DIALOG };
	CListCtrl	m_wndList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CODBCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDLG_H__74075C9D_4FC2_4271_B5AD_C2455DC7F828__INCLUDED_)
