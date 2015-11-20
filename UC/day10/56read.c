/*File Name: 56read.c
 **Author: 
 **Version: 
 **Created Time: 15/08/11-21:27  */


#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{

	int fd = open ("data.txt", O_RDONLY, 0444);
	if (fd == -1)
	{

		perror ("open");
		exit (EXIT_FAILURE);
	}
	typedef struct Employee
	{

		char name[256];
		int age;
		float salary;
	} EMP;
	EMP emp = {
	};
	char buf[1024] = {
	};
	if (read (fd, buf,25 ) == -1)
	{

		perror ("read");
		exit (EXIT_FAILURE);
	}
	sscanf(buf, "%s%d%f", emp.name, &emp.age, &emp.salary);
	printf("%s,%d,%f\n", emp.name, emp.age, emp.salary);
	printf("%s\n",buf);
	/*
	if (read (fd, buf, 1024) == -1)
	{

		perror ("read");
		exit (EXIT_FAILURE);
	}
	sscanf(buf, "%s%d%f", emp.name, &emp.age, &emp.salary);
	printf("%s,%d,%f\n", emp.name, emp.age, emp.salary);

	if (close (fd) == -1)
	{

		perror ("close");
		exit (EXIT_FAILURE);
	}
	*/
	return 0;
}

