// MFCDynamic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCDynamic.h"

/*
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
*/

class CAnimal:public CObject{
DECLARE_DYNAMIC(CAnimal)
};
IMPLEMENT_DYNAMIC(CAnimal,CObject)

class CDog:public CAnimal{
//DECLARE_DYNAMIC(CDog)
public:
	static const AFX_DATA CRuntimeClass classCDog; 
	virtual CRuntimeClass* GetRuntimeClass() const; 

};

//IMPLEMENT_DYNAMIC(CDog,CAnimal)
//IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL)
AFX_COMDAT const AFX_DATADEF CRuntimeClass CDog::classCDog = {
		"CDog", 
		sizeof(class CDog), 
		0xFFFF,
		NULL, 
		//RUNTIME_CLASS(CAnimal), 
		(CRuntimeClass*)(&CAnimal::classCAnimal),
		NULL }; 
CRuntimeClass* CDog::GetRuntimeClass() const {
	return RUNTIME_CLASS(CDog); 
} 


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	CDog yellowdog;
	if( yellowdog.IsKindOf(RUNTIME_CLASS(CObject)) )
		printf("yellowdog is CObject\n");
	else
		printf("yellowdog is not CObject\n");

	/*
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
	}

	return nRetCode;
	*/
}


