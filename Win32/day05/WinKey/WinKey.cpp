// WinCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"

HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;
int g_POSx = 100;
int g_POSy = 100;

void OnPaint(HWND hWnd){

	char szText[] = "WM_PAINT\n";
	WriteConsole(g_hOutput,szText,strlen(szText),NULL,NULL);
	PAINTSTRUCT ps = {0};
	HDC hdc = BeginPaint(hWnd,&ps);
	TextOut (hdc,g_POSx,g_POSy,"hello",5);
//	TextOut (hdc,100,120,"world",5);
	EndPaint(hWnd,&ps);
	//以上绘图的代码，必须放在绘图消息(WM_PAINT)处理中调用

}
void OnKeyDown(HWND hWnd, WPARAM wParam){
	char szText[256] = {0};
	sprintf(szText,"WM_KEYDOWN:%#08x\n",wParam);
	WriteConsole(g_hOutput,szText,strlen(szText),NULL,NULL);
	switch(wParam){
		case VK_UP:
			--g_POSy;
			break;
		case VK_LEFT:
			--g_POSx;
			break;
		case VK_RIGHT:
			++g_POSx;
			break;
		case VK_DOWN:
			++g_POSy;
			break;
	}
	sprintf(szText,"POSx=%d,POSy=%d\n",g_POSx,g_POSy);
	WriteConsole(g_hOutput,szText,strlen(szText),NULL,NULL);
	InvalidateRect(hWnd,NULL,true);
	//OnPaint(hWnd);

}
void OnKeyUp(HWND hWnd, WPARAM wParam){
	char szText[256] = {0};
	sprintf(szText,"WM_KEYUP  :%#08x\n",wParam);
	WriteConsole(g_hOutput,szText,strlen(szText),NULL,NULL);
}
void OnChar(HWND hWnd,WPARAM wParam){
	char szText[256] = {0};
	sprintf(szText,"WM_CHAR:%#08x\n",wParam);
	WriteConsole(g_hOutput,szText,strlen(szText),NULL,NULL);
}


//窗口处理函数(自定义函数，处理消息)
LRESULT CALLBACK WndProc(HWND hWnd,
						 UINT msgID,
						 WPARAM wParam,
						 LPARAM lParam
						 ){
	switch(msgID)
	{
	case WM_CHAR:
		OnChar(hWnd,wParam);
		break;
	case WM_PAINT:
		OnPaint(hWnd);
		break;
	case WM_KEYDOWN:
		OnKeyDown(hWnd,wParam);
		break;
	case WM_KEYUP:
		OnKeyUp(hWnd,wParam);
		break;
	case WM_LBUTTONUP:
		InvalidateRect(hWnd,NULL,true);
		OnPaint(hWnd);
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



