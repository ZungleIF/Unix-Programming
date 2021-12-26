#include <unistd.h>
#include <stdio.h>
#include <errno.h>

/* 
	An external varible defined in error.h, stores an error number
*/
extern int errno;

int main()
{
	
	if(access("unix.txt", F_OK) == -1)
	{
		// if program cannot access unix.txt, print the according error number
		printf("errno=%d\n", errno);
	}
	return 0;
}