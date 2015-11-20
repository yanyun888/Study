#include <stdio.h>
#define VER 7
#if VER < 3
#error "版本太低"
#elif VER > 6
#warning "版本太高"
#else
int main()
{
	printf("正常运行");
	return 0;

}
#endif
