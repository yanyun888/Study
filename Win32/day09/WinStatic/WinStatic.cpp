// WinCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"
#include "resource.h"

//#define MAKECHAR(n) #('#'##n)
//思考一下如何将101使用宏完成转换#101

HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;

void OnCreate(HWND hWnd){
	CreateWindowEx(0,"STATIC","Hello text",WS_CHILD|WS_VISIBLE|SS_NOTIFY,
		100,100,200,30,hWnd,(HMENU)1001,g_hInstance,NULL);
	CreateWindowEx(0,"STATIC","#101" ,WS_CHILD|WS_VISIBLE|SS_ICON|SS_NOTIFY,
		400,100,200,100,hWnd,(HMENU)1002,g_hInstance,NULL);
}


void OnCommand(HWND hWnd, WPARAM wParam){
	switch(LOWORD(wParam)){
	case 1001:
		if(HIWORD(wParam) == STN_CLICKED)
			MessageBox(hWnd,"hit you once","Info",MB_OK);
		break;
	case 1002:
		if(HIWORD(wParam) == STN_DBLCLK)
			MessageBox(hWnd,"hit you twice","Info",MB_OK);
		break;
	case ID_ICON1:
		{
		HICON hIcon1 = LoadIcon(g_hInstance,MAKEINTRESOURCE(IDI_ICON1));
		HWND hStatic1 = GetDlgItem(hWnd,1002);
		SendMessage(hStatic1,STM_SETICON,(WPARAM)hIcon1,0);
		break;
		}
	case ID_ICON2:
		{
		HICON hIcon2 = LoadIcon(g_hInstance,MAKEINTRESOURCE(IDI_ICON2));
		HWND hStatic2 = GetDlgItem(hWnd,1002);
		SendMessage(hStatic2,STM_SETICON,(WPARAM)hIcon2,0);
		break;
		}
	}
}

//窗口处理函数(自定义函数，处理消息)
LRESULT CALLBACK WndProc(HWND hWnd,
						 UINT msgID,
						 WPARAM wParam,
						 LPARAM lParam
						 ){
	switch(msgID)
	{
	case WM_COMMAND:
		OnCommand(hWnd,wParam);
		
		break;
	case WM_CREATE:
		OnCreate(hWnd);
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
	wce.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wce.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx(&wce);
}

HWND CreateMain (LPSTR lpClassName,LPSTR lpWndName){
	HWND hWnd = CreateWindowEx(0,lpClassName,lpWndName,WS_OVERLAPPEDWINDOW,
		100,100,700,500,NULL,NULL,g_hInstance,NULL);
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
 	g_hInstance = hInstance; //保存当前程序实例句柄
	Regsiter("Main",WndProc);
	HWND hWnd = CreateMain("Main","Window");
	Display(hWnd);
	Message();
	return 0;
}

