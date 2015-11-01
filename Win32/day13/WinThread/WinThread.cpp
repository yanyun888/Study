// WinThread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"

DWORD CALLBACK TestProc1(LPVOID pParam){
	char *pszText = (char*)pParam;
	while(1){
		printf("%s",pszText);
		Sleep(1000);
	}
}
DWORD CALLBACK TestProc2(LPVOID pParam){
	char *pszText = (char*)pParam;
	while(1){
		printf("%s",pszText);
		Sleep(1000);
	}
}



int main(int argc, char* argv[])
{
	char * pszText1 = "********************************************************************\n";
	DWORD nID = 0;
	HANDLE hThread1 = CreateThread(NULL,0,TestProc1,pszText1 , 0 , &nID);
	char * pszText2 = "--------------------------------------------------------------------\n";
	HANDLE hThread2 = CreateThread(NULL,0,TestProc2,pszText2 , CREATE_SUSPENDED , &nID);
	getchar();
	SuspendThread(hThread1);
	ResumeThread(hThread2);
	getchar();
	return 0;
}
