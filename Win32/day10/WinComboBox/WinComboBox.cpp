// WinCreate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"
#include "resource.h"

HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;

void OnCreate(HWND hWnd){
	CreateWindowEx(0,"COMBOBOX","simple",WS_CHILD|WS_VISIBLE|CBS_SIMPLE|WS_VSCROLL,
		50,50,200,200,hWnd,(HMENU)1001,g_hInstance,NULL);
	CreateWindowEx(0,"COMBOBOX","simple",WS_CHILD|WS_VISIBLE|CBS_DROPDOWN|WS_VSCROLL,
		260,50,200,200,hWnd,(HMENU)1002,g_hInstance,NULL);
	CreateWindowEx(0,"COMBOBOX","simple",WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|WS_VSCROLL,
		470,50,200,200,hWnd,(HMENU)1003,g_hInstance,NULL);
}

void OnAdd(HWND hWnd){
	HWND hSimple = GetDlgItem(hWnd,1001);
	HWND hDropDown = GetDlgItem(hWnd,1002);
	HWND hDropList = GetDlgItem(hWnd,1003);

	char szText[256] = {0};
	for(int i = 0 ; i< 100 ;++i){
		sprintf(szText,"ItemID%d",i);
		SendMessage(hSimple,CB_ADDSTRING,0,(LPARAM)szText);
		SendMessage(hDropDown,CB_ADDSTRING,0,(LPARAM)szText);
		SendMessage(hDropList,CB_ADDSTRING,0,(LPARAM)szText);
		memset(szText,0,256);
		SendMessage(hSimple,CB_SETITEMDATA,i,1000+i);
	}
	SendMessage(hSimple,CB_SETCURSEL,0,0);
	SendMessage(hDropDown,CB_SETCURSEL,0,0);
	SendMessage(hDropList,CB_SETCURSEL,0,0);
}

void OnClean(HWND hWnd){
	HWND hSimple = GetDlgItem(hWnd,1001);
	HWND hDropDown = GetDlgItem(hWnd,1002);
	HWND hDropList = GetDlgItem(hWnd,1003);
	SendMessage(hSimple,CB_RESETCONTENT,0,0);
	SendMessage(hDropDown,CB_RESETCONTENT,0,0);
	SendMessage(hDropList,CB_RESETCONTENT,0,0);
}

void OnDelete(HWND hWnd){
	HWND hSimple = GetDlgItem(hWnd,1001);
	HWND hDropDown = GetDlgItem(hWnd,1002);
	HWND hDropList = GetDlgItem(hWnd,1003);
	//获得所选的的索引号码
	//发送消息删除索引号码
	LRESULT nRet = SendMessage(hSimple,CB_GETCURSEL,0,0);
	if(nRet != CB_ERR)
	SendMessage(hSimple,CB_DELETESTRING,nRet,0);

	nRet = SendMessage(hDropDown,CB_GETCURSEL,0,0);
	if(nRet != CB_ERR)
		SendMessage(hDropDown,CB_DELETESTRING,nRet,0);

	nRet = SendMessage(hDropList,CB_GETCURSEL,0,0);
	if(nRet != CB_ERR)
		SendMessage(hDropList,CB_DELETESTRING,nRet,0);
}
void OnFind(HWND hWnd){
	HWND hSimple = GetDlgItem(hWnd,1001);
	char szText[] = "ItemID10";
	LRESULT nRet = SendMessage(hSimple,CB_SELECTSTRING,-1,(LPARAM)szText);
	if(nRet != CB_ERR){
		char szFind[256] = {0};
		sprintf(szFind,"found %d",nRet);
	//	MessageBox(hWnd,szFind,"Info",MB_OK);
	}
	else{
		MessageBox(hWnd,"not found","Info",MB_OK);
	}
}
void OnText(HWND hWnd){
	HWND hSimple = GetDlgItem(hWnd,1001);
	LRESULT nRet = SendMessage(hSimple,CB_GETCURSEL,0,0);
	if(nRet != CB_ERR){
		char szText[256] = {0};
		SendMessage(hSimple,CB_GETLBTEXT,nRet,(LPARAM)szText);
		MessageBox(hWnd,szText,"Info",MB_OK);
	}
	else{
		MessageBox(hWnd,"No Selection","Info",MB_OK);
	}
	char szText1[256] = {0};
	//SendMessage(hSimple,WM_GETTEXT,256,(LPARAM)szText1);
	SendMessage(hSimple,WM_GETTEXT,256, reinterpret_cast<LPARAM>(szText1));
	MessageBox(hWnd,szText1,"Info",MB_OK);
}

void OnDir(HWND hWnd){
	HWND hSimple = GetDlgItem(hWnd,1001);
	char szText[256] = "C:/*.*";
	SendMessage(hSimple,CB_DIR,DDL_ARCHIVE|DDL_DIRECTORY,(LPARAM)szText);
}

void OnData(HWND hWnd){
	HWND hSimple = GetDlgItem(hWnd,1001);
	LRESULT nRet = SendMessage(hSimple,CB_GETCURSEL,0,0);
	if(nRet != CB_ERR){
		LRESULT nData = SendMessage(hSimple,CB_GETITEMDATA,nRet,0);
		char szData[256] = {0};
		sprintf(szData,"Item data = %d",nData);
		MessageBox(hWnd,szData,"Info",MB_OK);
	}
}


void OnCommand(HWND hWnd,WPARAM wParam){
	switch(LOWORD(wParam)){
	case 1001:
		if(HIWORD(wParam) == CBN_SELCHANGE){
			HWND hSimple = GetDlgItem(hWnd,1001);
			HWND hDropDown = GetDlgItem(hWnd,1002);
			HWND hDropList = GetDlgItem(hWnd,1003);
			LRESULT nRet = SendMessage(hSimple,CB_GETCURSEL,0,0);
			SendMessage(hDropDown,CB_SETCURSEL,nRet,0);
			SendMessage(hDropList,CB_SETCURSEL,nRet,0);
		}
		else if(HIWORD(wParam) == CBN_EDITCHANGE ){
			MessageBox(hWnd,"Keyboard Input changes","Info",MB_OK);
		}
		break;
	case ID_DATA:
		OnData(hWnd);
		break;
	case ID_DIR:
		OnDir(hWnd);
		break;
	case ID_TEXT:
		OnText(hWnd);
		break;
	case ID_FIND:
		OnFind(hWnd);
		break;
	case ID_ADD:
		OnAdd(hWnd);
		break;
	case ID_CLEAN:
		OnClean(hWnd);
		break;
	case ID_DELETE:
		OnDelete(hWnd);
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
		OnCreate(hWnd);
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
 	g_hInstance = hInstance; //保存当前程序实例句柄
	Regsiter("Main",WndProc);
	HWND hWnd = CreateMain("Main","Window");
	Display(hWnd);
	Message();
	return 0;
}



