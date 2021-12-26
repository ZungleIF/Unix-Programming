#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    DIR *dp;                // Points a directory returned by opendir()
    struct dirent *dent;    // Points a file returned by readdir()

    // Open current working directory
    if((dp = opendir(".")) == NULL)
    {
        perror("opendir: .");
        exit(1);
    }

    // Read files in the directory sequentially
    while(dent = readdir(dp))
    {
        printf("Name: %s  ", dent->d_name);
        printf("Inode: %d\n", (int)dent->d_ino);
    }

    closedir(dp);

    return 0;
}