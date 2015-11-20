#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int demo1(){
	srand(time(NULL));
	int tmp = rand()%10+1;
	return tmp==5?-1:tmp;
}
int demo2(int a,int b, int* res){
	if(a==b){
		*res=a;
		return -1;
	}
	*res=a>b?a:b;
	return 0;
}
char* demo3(char* str){
	return strcmp(str,"error")?"ok":NULL;
}
void demo4(char* str){
	printf("print:%s\n",str);
}

int main(){
	int res = 0;
	printf("demo1:%d\n",demo1());
	printf("demo2:%d\n",demo2(20,30,&res));
	printf("demo2:%d\n",res);
	printf("demo3:%s\n",demo3("error"));
	printf("demo3:%s\n",demo3("noerror"));
	demo4("test");
//	printf("demo4:\n",demo4("test"));

	return 0;
}
