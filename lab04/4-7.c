#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Remove programming directory
    if(rmdir("programming") == -1)
    {
        perror("rmdir() failed.");
        exit(1);
    }

    return 0;
}