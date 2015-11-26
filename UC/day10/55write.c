/*File Name: 55write.c
 **Author: 
 **Version: 
 **Created Time: 15/08/11-21:25  */


#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int main()
{

	int fd = open ("data.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
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
		"赵云", 25, 8000};
	char buf[1024] = {
	};
	sprintf(buf, "%s %d %0.2f\n", emp.name, emp.age, emp.salary);
	if (write (fd, buf, strlen(buf) * sizeof (buf[0])) == -1)
	{

		perror ("write");
		exit (EXIT_FAILURE);
	}
	write (fd, buf, strlen(buf) * sizeof (buf[0]));
	write (fd, buf, strlen(buf) * sizeof (buf[0]));


	if (close (fd) == -1)
	{

		perror ("close");
		exit (EXIT_FAILURE);
	}
	return 0;
}

