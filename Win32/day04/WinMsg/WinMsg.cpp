// WinCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"


HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;
HWND g_hEdit = 0;


#define WM_MYMESSAGE WM_USER+1001

void OnCreate(HWND hWnd,LPARAM lParam){

	PostMessage(hWnd,WM_MYMESSAGE,100,200);
	
	CREATESTRUCT* pcs = (CREATESTRUCT*)lParam;
	char* pszText =
		(char*)pcs->lpCreateParams;
	MessageBox(hWnd,pszText,"Info",MB_OK);
	g_hEdit = CreateWindowEx(0,"EDIT","hello",WS_CHILD|WS_VISIBLE|WS_BORDER,
		0,0,200,200,hWnd,NULL,g_hInstance,NULL);
}

void OnSize(HWND hWnd,LPARAM lParam){
	
	int nWidth = LOWORD(lParam);
	int nHight = HIWORD(lParam);
	char szText[256];
	
	sprintf(szText,"WM_SIZE:宽=%d,高=%d\n",nWidth,nHight);
	WriteConsole(g_hOutput,szText,strlen(szText),NULL,NULL);
	MoveWindow(g_hEdit,0,0,nWidth,nHight,true);

}
void OnMyMessage(HWND hWnd,WPARAM wParam,LPARAM lParam){
	char szText[256];
	sprintf(szText,"自定义消息处理:wParam%d,lParam=%d\n",wParam,lParam);
	MessageBox(hWnd,szText,"Info",MB_OK);

}

//窗口处理函数(自定义函数，处理消息)
LRESULT CALLBACK WndProc(HWND hWnd,
						 UINT msgID,
						 WPARAM wParam,
						 LPARAM lParam
						 ){
	switch(msgID)
	{
	case WM_MYMESSAGE:
		OnMyMessage(hWnd,wParam,lParam);
	case WM_SIZE:
		OnSize(hWnd,lParam);
		break;
	case WM_CREATE:
		OnCreate(hWnd,lParam);
		break;
		
	case WM_SYSCOMMAND:
	//	MessageBox(hWnd,"WM_SYSCOMMAND","Info",MB_OK);
	//	return 0;
		if(wParam == SC_CLOSE){
			int nRet = MessageBox( hWnd,"是否退出?","Info",MB_YESNO );
			if(nRet == IDYES){
				//return 0;
			}
			else{
				return 0;
			}
		}
		break;
	case WM_DESTROY:
		//PostQuitMessage(0);
		PostMessage(hWnd,WM_QUIT,NULL,NULL);
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
		100,100,700,500,NULL,NULL,g_hInstance,"Hello");
	return hWnd;
}
void Display(HWND hWnd){
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);
}
void Message(){
	MSG nMsg = {0};
	while(1){
		if(PeekMessage(&nMsg,NULL,0,0,PM_NOREMOVE)){
			if(GetMessage(&nMsg,NULL,0,0)){
				TranslateMessage(&nMsg);
				DispatchMessage(&nMsg);
			}
			else{
				break;
			}
		}
		else{
		//	WriteConsole(g_hOutput,"OnIdle\n",7,NULL,NULL);
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
	HWND hWnd = CreateMain("Main","Window");
	Display(hWnd);
	Message();
	return 0;
}



