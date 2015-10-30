// WinWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


//自定义函数(窗口处理函数，处理消息)
LRESULT CALLBACK WindowProc(HWND hWnd,
							UINT msgID,
							WPARAM wParam,
							LPARAM lParam)
{
	switch(msgID){
		case WM_DESTROY:
			PostQuitMessage(0); //能够使GetMessage返回0
			break;	
	}
	return DefWindowProc(hWnd,msgID,wParam,lParam);
	//给各种消息做默认处理
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	//注册窗口类
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.hCursor = NULL;  // 操作系统指定的默认光标
	wc.hIcon = NULL;  // 操作系统选择一个默认图标
	wc.hInstance = hInstance;
	wc.lpfnWndProc = (WNDPROC) WindowProc;
	wc.lpszClassName = "Main";
	wc.lpszMenuName = NULL; // 这里定为空就是没有菜单
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);  //将以上所有赋值全部写入操作系统
	
	//创建窗口
	HWND hWnd = CreateWindow("Main","window demo",WS_OVERLAPPEDWINDOW,100,100,500,500,NULL,NULL,hInstance,NULL);

	//显示窗口
	ShowWindow(hWnd,SW_SHOW);
	//UpdateWindow();
	//消息循环
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg,NULL,0,0) ){
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );  
		//将消息交给自定义的窗口处理函数	
	}
	return 0;
}





