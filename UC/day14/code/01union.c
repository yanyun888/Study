//大端系统和小端系统的概念
#include <stdio.h>

int main(void)
{
	typedef union
	{
		int i;
		char buf[4];
	}Un;

	Un un;
	un.i = 0x12345678;

	int i = 0;
	for(i = 0; i < 4; i++)
	{
		printf("%#x[%p] ",un.buf[i],&un.buf[i]);
	}
	printf("\n");
	return 0;
}


