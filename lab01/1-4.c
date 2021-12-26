#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	if(access("linux.txt", F_OK) == -1)
	{
		/*
			if the program cannot access linux.txt, print error message
			according to the error number.
		*/
		perror("linux.txt");
        exit(1);
	}
	return 0;
}