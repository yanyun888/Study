// WinCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"
#include "resource.h"

HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;

int CALLBACK DlgProc(HWND hWndlg,UINT msgID,WPARAM wParam,LPARAM lParam){
	switch(msgID)
	{
	case WM_INITDIALOG:
		MessageBox(hWndlg,"WN_INITDIALOG","Info",MB_OK);
		break;
	case WM_CREATE:
		MessageBox(hWndlg,"WM_CREATE","Info",MB_OK);
		break;
	case WM_SYSCOMMAND:
		if(wParam == SC_CLOSE){
			//����ģʽ�Ի���
			EndDialog(hWndlg,1001);
//			DestroyWindow(hWndlg);	ֻ�����ٶԻ����ܽ������
		}
		break;
	
	
	}
	return false;
	//����Ϣ���������ĶԻ��򴰿ڴ��������������봦����
}


void OnModel(HWND hWnd){
	int nRet = DialogBox(g_hInstance,MAKEINTRESOURCE(IDD_DIALOG1),hWnd,DlgProc);
	if(nRet = 1001)
		MessageBox(hWnd,"Successful","Info",MB_OK);

}

void OnCommand(HWND hWnd,WPARAM wParam){
	
	switch(LOWORD(wParam)){
		case ID_MODEL:
			//����ģʽ�Ի���
			OnModel(hWnd);
			break;
	
	}


}


//���ڴ�������(�Զ��庯����������Ϣ)
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
 	g_hInstance = hInstance; //���浱ǰ����ʵ�����
	Regsiter("Main",WndProc);
	HWND hWnd = CreateMain("Main","Window");
	Display(hWnd);
	Message();
	return 0;
}


