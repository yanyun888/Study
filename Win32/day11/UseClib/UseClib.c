

#include <stdio.h>


//C编译器不要声明

//#pragma comment(lib,"../lib/Clib.lib")
//通知连接器到哪里抓源代码

int main(int argc,char* argv[]){
	
	int sum,sub;
	sum = Clib_add(5,3);
	sub = Clib_sub(5,3);
	printf("sum=%d,sub=%d\n",sum,sub);

	return 0;
}

