#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main()
{
    char *str;
	if(access("linux.txt", F_OK) == -1)
	{
        /*
            Strerror is defined in string.h.
            Returns an error message according to an error number.
            Similar to perror but does not print itself.
        */
        str = strerror(errno);
        printf("linux.txt: %s\n", str);
        exit(1);
	}
	return 0;
}