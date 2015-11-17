// WinProc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"

void Env(){
	char * pszText = GetEnvironmentStrings();
	char * pszEnv = pszText;
	while(pszEnv[0]){
		printf("%s\n",pszEnv);
		pszEnv = pszEnv + strlen(pszEnv) + 1;
	}
	FreeEnvironmentStrings(pszText);

}

void Variable(){
	
	SetEnvironmentVariable("zjw","good");
	char szVar[256] = {0};
	
	GetEnvironmentVariable("zjw",szVar,256);
	printf("%s\n",szVar);
	
}

void ProcInfo(){
	DWORD nID = GetCurrentProcessID();
	HANDLE hProc = GetCurrentProcess();
	printf("进程ID=%d,进程句柄=%d\n",nID,hProc);
}

void Proc(){
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};
	CreateProcess("c:/windows/system32/calc.exe","",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);	
	printf("进程句柄:%d，进程ID:%d"，pi.hProcess,pi.dwProcessID);
	
	WaitForSingleObject(pi.hProcess,INFINTE);
	printf("wait over\n");
}

void Kill(){
	OpenProcess(PROCESS_ALL_ACCESS,FALSE,3716/*写自己计算机上面的ID*/);
	TerminateProcess(hProc,123); // 123是退出码
}


int main(int argc, char* argv[])
{
	Proc();
	return 0;
}
