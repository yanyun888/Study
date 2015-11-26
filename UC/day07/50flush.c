/**********************************************************
> File Name: 50flush.c
> Author:
> Mail:
> Created Time: 2015年08月06日 星期四 21时21分58秒
 *********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    for(int i=1;i<=20;i++){
        printf("*");
        fflush(stdout);
        sleep(1);
    }

    return 0;
}
