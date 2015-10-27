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

	enum COLOR color;//C语言不能省略枚举关键字
	color = 100;//C语言可以

	printf("%d\n",color);


	return 0;
}
