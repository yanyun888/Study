/*
 	观察程序中的内存划分
 
 **/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i1 = 10;
int i2 = 20;
int i3;
const int i4 =40;//只读常量区

void fn(int i5){
	int i6=60;//
	static int i7=70;//全局区
	const int i8=80;
	//p1本身在栈区，p1指向的在堆区
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	//str栈区
	char* str = "hello";
	//strs在栈区，strs指向栈区
	char strs[] = "hello";
	

	printf("只读常量区:&i4=%p\n",&i4);
	printf("只读常量区:str=%p\n",str);
	puts("---------------------");
	printf("全局区:&i1=%p\n",&i1);
	printf("全局区:&i2=%p\n",&i2);
	printf("全局区:&i7=%p\n",&i7);
	puts("---------------------");
	printf("BSS段:&i3=%p\n",&i3);
	puts("---------------------");
	printf("堆区:&p1=%p\n",&p1);
	printf("堆区:&p2=%p\n",&p2);
	puts("---------------------");
	printf("栈区:&i5=%p\n",&i5);
	printf("栈区:&i6=%p\n",&i6);
	printf("栈区:&i8=%p\n",&i8);
	printf("栈区:strs=%p\n",strs);
	puts("---------------------");

	printf("栈区:&i7=%p\n",&i7);

}

int main(){
	
	printf("代码区:fn=%p\n",fn);
	puts("---------------");
	fn(10);
	
	return 0;

}



