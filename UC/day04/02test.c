//02test.c

#include<stdio.h>

int main(){
  
  int * pi = (int*)0xbf804abc;
  printf("*pi = %d\n",*pi);

  return 0;
}