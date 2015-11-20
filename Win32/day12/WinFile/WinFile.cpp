// WinFile.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "windows.h"
#include "stdio.h"

void Create(){
	HANDLE hFile = CreateFile("C:/file.txt",GENERIC_WRITE,FILE_SHARE_READ,NULL,
				CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
	CloseHandle(hFile);		
}
void Write(){
	HANDLE hFile = CreateFile("C:/file.txt",GENERIC_WRITE,FILE_SHARE_READ,NULL,
		OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	char szText[] = "hello.txt";
	DWORD nLen = 0;
	WriteFile(hFile,szText,strlen(szText),&nLen,NULL);
	printf("准备:%d,实际：%d\n",strlen(szText),nLen);
	CloseHandle(hFile);
}

void Read(){
	HANDLE hFile = CreateFile("C:/file.txt",GENERIC_READ,FILE_SHARE_READ,NULL,
		OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	DWORD nLenFileHi = 0;
	DWORD nLenFileLo = GetFileSize(hFile,&nLenFileHi);
	printf("%d,%d\n",nLenFileHi,nLenFileLo);

	char szText[256] = {0};
	DWORD nLen = 0;
	ReadFile(hFile,szText,nLenFileLo,&nLen,NULL);
	printf("准备:%d,实际：%d\n",nLenFileLo,nLen);
	printf("%s\n",szText);
	CloseHandle(hFile);
}
void UseFile(){
	//CopyFile("C:/file.txt","C:/123/nofile.txt",true);
	//DeleteFile("C:/file.txt");
	MoveFile("C:/123/nofile.txt","C://file.txt");
}


void Find(char* path){
	WIN32_FIND_DATA wfd = {0};
	//char* path = "c:/*.*";
	HANDLE hFind = FindFirstFile(path,&wfd);
	BOOL goFind = true;
	while(goFind){
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
			printf("[%s]\n",wfd.cFileName);
		}
		else{
			printf("%s\n",wfd.cFileName);
		}
		goFind = FindNextFile(hFind,&wfd);
	}
	FindClose(hFind);
}

int main(int argc, char* argv[])
{
//	Create();
//	Write();
//	Read();
//	UseFile();
	Find("c:*.*");
	return 0;
}
