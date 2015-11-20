/*File Name: 08pipe.c
**Author: 
**Version: 
**Created Time: 15/08/12-17:05  */
 
 
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


int main(){

//使用pipe创建无名管道
	int pipefd[2] = {};
	int res = pipe(pipefd);
	if(-1 == res){
		perror("pipe");
		exit(-1);
	}
	pid_t pid;
	switch(pid = fork()){
		case -1:perror("fork");
				exit(-1);
		case 0:close(pipefd[1]);
			   int x;
			   do{
				   res = read(pipefd[0],&x,sizeof(int));
				   printf("%d (res = %d)\n",x,res);
	//			   fflush(stdout);
			   }while(res);

			   printf("child ends\n");
			   close(pipefd[0]);
			   exit(-1);
	}

	close(pipefd[0]);
	int i = 0;
	for(i=0;i<50;i++){
		write(pipefd[1],&i,sizeof(int));
	}
//	sleep(5);
	close(pipefd[1]);

	return 0;
}
