
#include <cstdio>
#include "../ClassDll/ClassDll.h"

#pragma comment(lib,"../lib/ClassDll.lib")

int main(){

	CMath math;
	int sum = math.Add(5,3);
	int sub = math.Sub(5,3);

	printf("sum=%d,sub=%d\n",sum,sub);
	getchar();
	return 0;
}