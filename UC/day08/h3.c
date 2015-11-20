/*File Name:h3.c
**Author: 
**Version: 
**Created Time: 15/08/07-19:57  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){

	int res = link("i.txt","i2.txt");
	if(-1 == res){
		perror("link");
	}
	return 0;
}
