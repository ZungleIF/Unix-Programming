#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Rename linux to LINUX
    if(rename("linux", "LINUX") == -1)
    {
        perror("Rename failed.");
        exit(1);
    }

    return 0;
}