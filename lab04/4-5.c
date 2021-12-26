#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Make a directory called linux with a mode of 0755
    // drwxr-xr-x
    if(mkdir("linux", 0755) == -1)
    {
        perror("linux");
        exit(1);
    }

    // Make a directory called programming with a mode of 0644
    // drw-r--r--
    if(mkdir("programming", 0644) == -1)
    {
        perror("programming");
        exit(1);
    }

    return 0;
}