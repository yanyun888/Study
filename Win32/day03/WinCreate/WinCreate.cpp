// WinCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"

HINSTANCE g_hInstance = 0;
HWND g_hWnd = 0;
//窗口处理函数(自定义函数，处理消息)
LRESULT CALLBACK WndProc(HWND hWnd,
						 UINT msgID,
						 WPARAM wParam,
						 LPARAM lParam
						 ){
	if(hWnd == g_hWnd){
		switch(msgID)
			{
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			}
		}
	return DefWindowProc(hWnd,msgID,wParam,lParam);

}
void Regsiter (LPSTR lpClassName, WNDPROC wndproc) {
	WNDCLASSEX wce = {0};
	wce.cbSize = sizeof(wce);
	wce.cbClsExtra = 200;
	wce.cbWndExtra = 200;
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
		100,100,700,500,NULL,NULL,g_hInstance,NULL);
	return hWnd;
}

HWND CreateChild (LPSTR lpClassName,LPSTR lpWndName, HWND hParent){
	return 
		CreateWindowEx(0,lpClassName,lpWndName,
		WS_CHILD|WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		100,100,200,200,hParent,NULL,g_hInstance,NULL);
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
void SetExtra (HWND hWnd){
	SetClassLong(hWnd,0,100);
	SetWindowLong(hWnd,0,100);
}

void GetExtra(HWND hWnd){
	LONG nClass = GetClassLong(hWnd,0);
	LONG nWnd = GetWindowLong(hWnd,0);
	char szText[256] = {0};
	sprintf(szText,"窗口类:%d,窗口:%s",nClass,nWnd);
	MessageBox(hWnd,szText,"Infor",MB_OK);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	g_hInstance = hInstance; //保存当前程序实例句柄
	Regsiter("Main",WndProc);
	g_hWnd = CreateMain("Main","Window");
	HWND hChild1 = CreateChild("Main","Child1",g_hWnd);
	HWND hChild2 = CreateChild("Main","Child2",g_hWnd);
	Display(g_hWnd);

	MoveWindow(hChild1,100,100,200,100,true);
	MoveWindow(hChild2,100,200,200,100,false);
	SetExtra(hChild1);
	GetExtra(hChild2);

	//Display(hWndChild);

	Message();

	return 0;
}



