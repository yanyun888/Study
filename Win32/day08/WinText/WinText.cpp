#include "stdafx.h"
#include "stdio.h"

HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;

void OnPaint(HWND hWnd,WPARAM wParam){
	PAINTSTRUCT ps = {0};
	HDC hdc = BeginPaint(hWnd,&ps);
	
	SetBkColor(hdc,RGB(255,0,0));
	SetBkMode(hdc,TRANSPARENT);
	
	char szText[] = "Hello &txt";


	TextOut(hdc,100,100,szText,strlen(szText));

	RECT rc = {0};
	rc.left = 100;
	rc.right = 200;
	rc.top = 150;
	rc.bottom = 200;
	Rectangle(hdc,100,150,200,200);
	DrawText(hdc,szText,strlen(szText),&rc,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOCLIP|DT_NOPREFIX);


	char szExtText[] = "hello";
	int nDis[]={10,10,10,10};
	ExtTextOut(hdc,100,300,0,NULL,szExtText,strlen(szExtText),nDis);

	EndPaint(hWnd,&ps);
}


//窗口处理函数(自定义函数，处理消息)
LRESULT CALLBACK WndProc(HWND hWnd,
						 UINT msgID,
						 WPARAM wParam,
						 LPARAM lParam
						 ){
	switch(msgID)
	{
	case WM_PAINT:
		OnPaint(hWnd,wParam);
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







