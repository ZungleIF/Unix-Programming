#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // A header file needed for write() and close().

#include <stdio.h>
#include <string.h> // A header file needed for strlen().
#include <stdlib.h>

int main()
{
    int fd;
    int n;

    char str[] = "UNIX SYSTEM PROGRAMMING";

    // O_WRONLY: Write only
    fd = open("3-1.txt", O_WRONLY);
    if(fd == -1)
    {
        perror("Open");
        exit(1);
    }
    /*
        Write str to fd with length of str.
        write() returns the number of bytes written.
        strlen() excludes '\0' in caculation.
    */
    n = write(fd, str, strlen(str));
    /*
        If there's a disacordance between the number of bytes written
        and the length of str, print an error message.
    */
    if(n != strlen(str))
    {
        perror("Write");
        exit(2);
    }

    close(fd);
    return 0;
}