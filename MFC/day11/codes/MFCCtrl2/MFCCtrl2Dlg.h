// MFCCtrl2Dlg.h : header file
//

#if !defined(AFX_MFCCTRL2DLG_H__9705C9BD_F863_435D_81B9_B4108059821D__INCLUDED_)
#define AFX_MFCCTRL2DLG_H__9705C9BD_F863_435D_81B9_B4108059821D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCCtrl2Dlg dialog

class CMFCCtrl2Dlg : public CDialog
{
// Construction
public:
	CMFCCtrl2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCCtrl2Dlg)
	enum { IDD = IDD_MFCCTRL2_DIALOG };
	CSliderCtrl	m_wndSlider;
	CProgressCtrl	m_wndProgress;
	CSpinButtonCtrl	m_wndSpin;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCCtrl2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCCtrl2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCTRL2DLG_H__9705C9BD_F863_435D_81B9_B4108059821D__INCLUDED_)
