// WinCreate.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;

void OnTimer(HWND hWnd,WPARAM wParam){
	char szText[256] = {0};
	sprintf(szText,"Timer Message detected!:%d\n",wParam);
	WriteConsole(g_hOutput,szText,strlen(szText),NULL,NULL);
}

//��ʱ��������(�Զ��庯����������Ϣ)
void CALLBACK TimerProc(HWND hWnd,UINT msgID,UINT timerID,DWORD dwTime){
	char szText[256] = {0};
	sprintf(szText,"timer process function  %d\n",timerID);
	WriteConsole(g_hOutput,szText,strlen(szText),NULL,NULL);



}

//���ڴ�����(�Զ��庯����������Ϣ)
LRESULT CALLBACK WndProc(HWND hWnd,
						 UINT msgID,
						 WPARAM wParam,
						 LPARAM lParam
						 ){
	switch(msgID)
	{
	case WM_TIMER:
		OnTimer(hWnd,wParam);
		break;
	case WM_CREATE:
		SetTimer(hWnd,1,1000,NULL);
		SetTimer(hWnd,2,2000,TimerProc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd,msgID,wParam,lParam);

}
void Regsiter (LPSTR lpClassName, WNDPROC wndproc) {
	WNDCLASSEX wce = {0};
	wce.cbSize = sizeof(wce);
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = WndProc;
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx(&wce);
}

HWND CreateMain (LPSTR lpClassName,LPSTR lpWndName){
	HWND hWnd = CreateWindowEx(0,lpClassName,lpWndName,WS_OVERLAPPEDWINDOW,
		200,200,700,500,NULL,NULL,g_hInstance,NULL);
	return hWnd;
}

void Display(HWND hWnd){
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);
}

void Message(){
	MSG nMsg = {0};
	while(GetMessage(&nMsg,NULL,0,0)){
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	AllocConsole();
	g_hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 	g_hInstance = hInstance; //���浱ǰ����ʵ�����
	Regsiter("Main",WndProc);
	HWND hWnd = CreateMain("Main","Window");
	Display(hWnd);
	Message();
	return 0;
}



