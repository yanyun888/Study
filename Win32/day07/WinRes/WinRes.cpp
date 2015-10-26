// WinCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"
#include "resource.h"

HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;
HCURSOR g_hCur1 = 0;
HCURSOR g_hCur2 = 0;


void OnCommand(HWND hWnd,WPARAM wParam){

	switch (LOWORD(wParam)){
	case ID_NEW:
		if(HIWORD(wParam))
			MessageBox(hWnd,"加速键-新建被点击","Info",MB_OK);
		else if(HIWORD(wParam) == 1)
			MessageBox(hWnd,"菜单-新建被点击","Info",MB_OK);
		break;
	case ID_SET:
		MessageBox(hWnd,"Ctrl+P 被点击","Info",MB_OK);
		break;
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
		g_hCur1 = LoadCursorFromFile("c:/windows/cursors/aero_working_xl.ani");
		g_hCur2 = LoadCursorFromFile("c:/windows/cursors/aero_busy_xl.ani");
		break;
	case WM_SETCURSOR:
		//SetCursor消息仅仅会
		if(LOWORD(lParam) == HTCLIENT)
		{
		//	HCURSOR hBall = LoadCursor(g_hInstance,MAKEINTRESOURCE(IDC_CURSOR2));
		//	HCURSOR hCur = LoadCursor(g_hInstance,MAKEINTRESOURCE(IDC_CURSOR1));

			POINT point = {0};
			GetCursorPos(&point);
			ScreenToClient(hWnd,&point);
			RECT rc = {0};
			GetClientRect(hWnd,&rc);
			if(point.x <= (rc.right)>>1)
				SetCursor(g_hCur1);
			else
				SetCursor(g_hCur2);

//			SetCursor(hBall);
			return 0;
		}
		else{
			
		}
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
	wce.hCursor = LoadCursor(g_hInstance,MAKEINTRESOURCE(IDC_CURSOR1));
	wce.hIcon = LoadIcon(g_hInstance,MAKEINTRESOURCE(IDI_ICON1));
	wce.hIconSm = LoadIcon(g_hInstance,MAKEINTRESOURCE(IDI_ICON2));
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
	HACCEL hAccel = LoadAccelerators(g_hInstance,MAKEINTRESOURCE(IDR_ACCELERATOR1));
	MSG nMsg = {0};
	while(GetMessage(&nMsg,NULL,0,0)){

		if(!TranslateAccelerator(nMsg.hwnd,hAccel,&nMsg)){
			TranslateMessage(&nMsg);
			DispatchMessage(&nMsg);
		}
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
	char szTitle[256] = {0};
	LoadString(hInstance,IDS_WND,szTitle,256);
	HWND hWnd = CreateMain("Main",szTitle);
	Display(hWnd);
	Message();
	return 0;
}



