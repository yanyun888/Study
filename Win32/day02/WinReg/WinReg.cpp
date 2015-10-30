// WinReg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	//基于系统窗口类创建窗口，不需要注册
	//创建窗口
	HWND hWnd = CreateWindow("BUTTON","window",WS_OVERLAPPEDWINDOW,100,100,500,500,NULL,NULL,hInstance,NULL);

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



