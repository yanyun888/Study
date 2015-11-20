/*File Name: 01stat.c
>*Author: 
> Mail: 
> Created Time: 15/08/07 - 09:33*/
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
int main(){
    struct stat st = {};
	int arr[];
	printf
    int res = stat("a.txt",&st);
    if(-1 == res){
        perror("stat");
    }
//    maketm();
    printf("st.st_mode = %o,st.st_size = %ld,st.st_mtime = %ld\n",
           st.st_mode,st.st_size,st.st_mtime);
    printf("文件的权限是%o\n",st.st_mode&0777);
    if( S_ISREG(st.st_mode)){
        puts("reg file");
    }
    if( S_ISDIR(st.st_mode)){
        puts("dir file");
    }
	puts("hello");
	
    printf("文件的类型是%o\n",st.st_mode>>9);
    char* tm = ctime(&st.st_mtime);
    printf("%s\n",tm);
	printf("sys.h\n")
	return 0;
}
