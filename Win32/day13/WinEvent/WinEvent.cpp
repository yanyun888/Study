
// WinCritial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"


HANDLE g_hEvent = 0; // 用于接收事件句柄

DWORD CALLBACK TestProc1(LPVOID pParam){
//负责输出
	while(1){
		WaitForSingleObject(g_hEvent,INFINITE);
	//	ResetEvent(g_hEvent);
		printf("****************\n");
		
	}
	return 0;
}

DWORD CALLBACK TestProc2(LPVOID pParam){
//负责控制输出
	while(1){
		Sleep(1000);
		SetEvent(g_hEvent);
	}

	return 0;
}


int main(int argc, char* argv[])
{
	g_hEvent = CreateEvent(NULL,false,false,NULL);
	DWORD nID = 0;
	HANDLE hThread[2] = {0};

	hThread[0] = CreateThread(NULL,0,TestProc1,NULL,0,&nID);
	hThread[1] = CreateThread(NULL,0,TestProc2,NULL,0,&nID);

	WaitForMultipleObjects(2,hThread,true,INFINITE);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(g_hEvent);

	return 0;
}

