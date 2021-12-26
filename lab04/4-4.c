#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    struct stat buf;

    stat("password.txt", &buf);
    printf("Link Count before link() = %d\n", (unsigned int)buf.st_nlink);

    // Create a hard link of password.txt
    // Hard link has the same inode as the original file.
    // Therefore, it increases the link count.
    link("password.txt", "password.ln");

    stat("password.txt", &buf);
    printf("Link Count after link() = %d\n", (unsigned int)buf.st_nlink);

    stat("password.ln", &buf);
    printf("Link Count of password.ln = %d\n", (unsigned int)buf.st_nlink);

    // Create a symbolic link of password.txt
    // Symbolic link has a different inode
    // stat() accesses the original file, lstat() accesses link itself
    symlink("password.txt", "password.sln");

    stat("password.txt", &buf);
    printf("Link Count of password.ln = %d\n", (unsigned int)buf.st_nlink);

    stat("password.sln", &buf);
    printf("Link Count of password.ln = %d\n", (unsigned int)buf.st_nlink);

    lstat("password.sln", &buf);
    printf("Link Count of password.sln itself = %d\n", (unsigned int)buf.st_nlink);

    return 0;
}