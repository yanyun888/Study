// Win32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	//
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof(wce);
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = hInstance;
	wce.lpfnWndProc = DefWindowProc;
	wce.lpszClassName = "Main";
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW;
	ATOM nAtom = RegisterClassEx(&wce);
	if(!nAtom)
	{
		MessageBox(NULL,"×¢²áÊ§°Ü","Infor",MB_OK);
		return 0;
	}
	HWND hWnd = CreateWindow("Main","window",WS_OVERLAPPEDWINDOW,100,100,500,500,NULL,NULL,hInstance,NULL);

	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);
	MSG nMsg = {0};
	while(GetMessage(&nMsg,NULL,0,0)){
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
	return 0;
}



