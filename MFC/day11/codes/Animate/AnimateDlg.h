// AnimateDlg.h : header file
//

#if !defined(AFX_ANIMATEDLG_H__CB431CB1_5613_430A_AD69_4BA6504A0F75__INCLUDED_)
#define AFX_ANIMATEDLG_H__CB431CB1_5613_430A_AD69_4BA6504A0F75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAnimateDlg dialog

class CAnimateDlg : public CDialog
{
// Construction
public:
	CAnimateDlg(CWnd* pParent = NULL);	// standard constructor
    void Play(); 
// Dialog Data
	//{{AFX_DATA(CAnimateDlg)
	enum { IDD = IDD_ANIMATE_DIALOG };
	CComboBox	m_wndPlayCount;
	CButton	m_wndReplay;
	CAnimateCtrl	m_wndAnimate;
	CListBox	m_wndFileList;
	CString	m_strFilePath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAnimateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenFile();
	afx_msg void OnDblclkFileList();
	afx_msg void OnClose( ); 
    afx_msg void OnRePlay();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATEDLG_H__CB431CB1_5613_430A_AD69_4BA6504A0F75__INCLUDED_)
