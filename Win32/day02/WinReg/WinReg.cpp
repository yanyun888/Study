// WinReg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	//����ϵͳ�����ഴ�����ڣ�����Ҫע��
	//��������
	HWND hWnd = CreateWindow("BUTTON","window",WS_OVERLAPPEDWINDOW,100,100,500,500,NULL,NULL,hInstance,NULL);

	//��ʾ����
	ShowWindow(hWnd,SW_SHOW);
	//UpdateWindow();
	//��Ϣѭ��
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg,NULL,0,0) ){
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );  
		//����Ϣ�����Զ���Ĵ��ڴ�����	
	}
	return 0;
}



