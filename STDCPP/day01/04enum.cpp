/* File Name: emun.c
** Author: 
** Version: 
** Created Time: 15/09/02-14:31  */
 
 
#include <stdio.h>
#include <stdlib.h>


int main(){
	
	enum COLOR{
		RED,
		GREEN,
		BLUE=100,
		YELLOW
	};
	COLOR color;//C++可以省略枚举关键字
	color = BLUE;//C++必须使用枚举类型中的关键字

	printf("%d\n",color);

	return 0;
}
