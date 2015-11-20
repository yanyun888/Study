// MFCFile1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCFile1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;



void MFCFileFind(CString strPath){

	CFileFind find;
	BOOL bRet = find.FindFile(strPath+"/*.*");
	//FindFile只能获取到是否有该文件
	while(bRet){
		//得到当前文件信息，并返回下一个文件是否存在
		bRet = find.FindNextFile();
		CString strName=find.GetFileName();
		if(find.IsDirectory()){
			printf("目录:%s\n",strName);
			//CString 直接可以在%s中打印		
#if 1
			if(!find.IsDots()){
				MFCFileFind(strPath+"/"+strName);
				//也可以使用GetFilePath
			}
#endif		
		}
		else{
			printf("文件:%s\n",strName);
		}	
	}
	find.Close();

}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
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
		MFCFileFind("F:/web");
	}


	return nRetCode;
}


