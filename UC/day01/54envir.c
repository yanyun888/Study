#include <stdio.h>



int main (int argc, char* argv[], char* envp[])
{
	extern char** environ;
	printf ("%p, %p\n", environ, envp);
	char** pp;
	for (pp = envp; pp && *pp; ++pp)
		printf ("%s\n", *pp);
	return 0;
}
