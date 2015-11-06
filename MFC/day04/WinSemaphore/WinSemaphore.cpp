// WinSemaphore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

HANDLE g_hSema = 0;  //½ÓÊÜÐÅºÅ¾ä±ú


DWORD CALLBACK TestProc(LPVOID pParam){
	while(1){
		WaitForSingleObject(g_hSema,INFINITE);
		printf("**************\n");
	}

}

int main(int argc, char* argv[])
{
	g_hSema = CreateSemaphore(NULL,3,10,NULL);

	DWORD nID = 0;
	HANDLE hThread = CreateThread(NULL,0,TestProc,
		NULL, 0, &nID);
	getchar();
	ReleaseSemaphore(g_hSema,11,NULL);
	
	WaitForSingleObject(hThread,INFINITE);
	CloseHandle (hThread);
	CloseHandle(g_hSema);
	return 0;
}
