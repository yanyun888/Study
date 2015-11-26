

//#define _BSD_SOURCE || _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
//#define _SVID_SOURCE || _XOPEN_SOURCE
//#include<features.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("PATH=%s\n",getenv("PATH"));
	putenv("MYNAME=zhangfei");
	printf("MYNAME=%s\n",getenv("MYNAME"));
	putenv("MYNAME=zhaoyun");
	printf("MYNAME=%s\n",getenv("MYNAME"));
	setenv("MYHOME", "Zibo", 0);
	printf("MYHOME=%s\n",getenv("MYHOME"));
	setenv("MYHOME", "Yantai", 0);
	printf("MYHOME=%s\n",getenv("MYHOME"));
	setenv ("MYHOME", "Dezhou", 1);
	printf("MYHOME=%s\n",getenv("MYHOME"));
	unsetenv("MYNAME");
	printf("MYNAME=%s\n",getenv("MYNAME"));
	return 0;
}
