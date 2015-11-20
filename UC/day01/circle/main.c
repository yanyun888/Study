

#include"circle.h"


int main(){

	puts("请输入一个半径");
	double r;
	scanf("%lf",&r);
	printf("面积是%lf，周长是%lf\n", area(r),length(r));

	return 0;
}



