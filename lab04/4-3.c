#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    struct stat buf;

    stat("password.txt", &buf);
    printf("mode before change = %o\n", (unsigned int)buf.st_mode);

    // Add write access for group (OR)
    buf.st_mode |= S_IWGRP;
    // Drop read access for others (NAND)
    buf.st_mode &= ~(S_IROTH);
    chmod("password.txt", buf.st_mode);
    stat("password.txt", &buf);

    printf("mode after change = %o\n", (unsigned int)buf.st_mode);
    
    return 0;
}