#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd, n;
    off_t start, cur;
    char buf[256];

    // Open 3-1.txt with Read only access.
    fd = open("3-1.txt", O_RDONLY); 
    if(fd == -1)
    {
        perror("Open unix.txt");
        exit(1);
    }

    // lseek() returns the current data offset pointed
    // by file descriptor, which is start of the file.
    start = lseek(fd, 0, SEEK_CUR);
    // Reads 255 bytes if exists, also moves the offset by n.
    n = read(fd, buf, 255);
    buf[n] = '\0';
    printf("Offset start=%d, Read str=%s, n=%d\n", (int)start, buf, n);
    cur = lseek(fd, 0, SEEK_CUR);
    printf("Offset cur=%d\n", (int)cur);

    // Moves the offset by 7 from current position.
    start = lseek(fd, 7, SEEK_CUR);
    n = read(fd, buf, 255);
    buf[n] = '\0';
    printf("Offset start=%d, Read str=%s\n", (int)start, buf);

    close(fd);

    return 0;
}