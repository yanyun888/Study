// WinWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


//�Զ��庯��(���ڴ�������������Ϣ)
LRESULT CALLBACK WindowProc(HWND hWnd,
							UINT msgID,
							WPARAM wParam,
							LPARAM lParam)
{
	switch(msgID){
		case WM_DESTROY:
			PostQuitMessage(0); //�ܹ�ʹGetMessage����0
			break;	
	}
	return DefWindowProc(hWnd,msgID,wParam,lParam);
	//��������Ϣ��Ĭ�ϴ���
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	//ע�ᴰ����
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.hCursor = NULL;  // ����ϵͳָ����Ĭ�Ϲ��
	wc.hIcon = NULL;  // ����ϵͳѡ��һ��Ĭ��ͼ��
	wc.hInstance = hInstance;
	wc.lpfnWndProc = (WNDPROC) WindowProc;
	wc.lpszClassName = "Main";
	wc.lpszMenuName = NULL; // ���ﶨΪ�վ���û�в˵�
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);  //���������и�ֵȫ��д�����ϵͳ
	
	//��������
	HWND hWnd = CreateWindow("Main","window demo",WS_OVERLAPPEDWINDOW,100,100,500,500,NULL,NULL,hInstance,NULL);

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





