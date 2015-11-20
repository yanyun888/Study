// MFCListDlg.h : header file
//

#if !defined(AFX_MFCLISTDLG_H__CFA208CB_6912_4AAB_930E_9C369DE584C6__INCLUDED_)
#define AFX_MFCLISTDLG_H__CFA208CB_6912_4AAB_930E_9C369DE584C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCListDlg dialog

class CMFCListDlg : public CDialog
{
// Construction
public:
	void Show(CString strPath);
	void InitListCtrl();
	CMFCListDlg(CWnd* pParent = NULL);	// standard constructor

	CImageList m_ilNormal;
	CImageList m_ilSmall;
	CStringList m_listPath;
	
	

// Dialog Data
	//{{AFX_DATA(CMFCListDlg)
	enum { IDD = IDD_MFCLIST_DIALOG };
	CComboBox	m_wndStyle;
	CListCtrl	m_wndList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeStyle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCLISTDLG_H__CFA208CB_6912_4AAB_930E_9C369DE584C6__INCLUDED_)
