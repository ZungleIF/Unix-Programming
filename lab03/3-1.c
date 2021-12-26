// Header files needed for open().
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// A header file needed for close().
#include <unistd.h>
// A header file needed for perror() and printf().
#include <stdio.h>

int main()
{
    // Declare an integer for a file descriptor.
    int fd; 
    /* 
        Open 3-1.txt and returns fd. If the file does not exist,
        create one with mode of 0644. (-rw-r--r--)
    */
    fd = open("3-1.txt", O_CREAT, 0644);

    if(fd == -1)
    {
        perror("Open");
    }

    printf("fd is %d\n", fd);   // Print the file descriptor.
    close(fd);                  // Close a file with fd.
    return 0;
}