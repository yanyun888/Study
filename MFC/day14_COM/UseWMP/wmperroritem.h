#if !defined(AFX_WMPERRORITEM_H__B9D3CFED_B7BA_4556_A090_0C578938A133__INCLUDED_)
#define AFX_WMPERRORITEM_H__B9D3CFED_B7BA_4556_A090_0C578938A133__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CWMPErrorItem wrapper class

class CWMPErrorItem : public COleDispatchDriver
{
public:
	CWMPErrorItem() {}		// Calls COleDispatchDriver default constructor
	CWMPErrorItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPErrorItem(const CWMPErrorItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetErrorCode();
	CString GetErrorDescription();
	VARIANT GetErrorContext();
	long GetRemedy();
	CString GetCustomUrl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPERRORITEM_H__B9D3CFED_B7BA_4556_A090_0C578938A133__INCLUDED_)
