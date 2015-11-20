// WinInterLock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"

long g_nValue = 0;

const int time = 20000000;

DWORD CALLBACK TestProc1(LPVOID pParam){
	for(int i=0;i<time;++i){
		InterlockedIncrement(&g_nValue);
		//++g_nValue;
	}
	return 0;
}
DWORD CALLBACK TestProc2(LPVOID pParam){
	for(int i=0;i<time;++i){
		InterlockedIncrement(&g_nValue);
		//++g_nValue;
		//g_nValue++;
	}
	return 0;
}


int main(int argc, char* argv[])
{
	DWORD nID = 0;
	HANDLE hThread[2] = {0};
	hThread[0] = CreateThread(NULL,0,TestProc1,NULL,0,&nID);
	hThread[1] = CreateThread(NULL,0,TestProc2,NULL,0,&nID);
	
	WaitForMultipleObjects(2,hThread,true,INFINITE);

	printf("wait over\n");
	
	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);

	printf("%u\n",g_nValue);
	printf("%u\n",2*time);

	return 0;
}
