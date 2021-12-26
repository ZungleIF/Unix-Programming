#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    struct stat buf;

    stat("password.txt", &buf);

    // Prints access mode of password.txt
    printf("Mode = %o (HEX: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    if(S_ISFIFO(buf.st_mode)) printf("password.txt: FIFO\n"        ); // If it is a FIFO file,
    if(S_ISDIR (buf.st_mode)) printf("password.txt: Directory\n"   ); // If it is a Directory,
    if(S_ISREG (buf.st_mode)) printf("password.txt: Regular File\n"); // If it is a Regular file,

    return 0;
}