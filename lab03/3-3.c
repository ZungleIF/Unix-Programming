#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd_1, fd_2;
    int n;
    char buf[10];

    fd_1 = open("3-1.txt", O_RDONLY);
    fd_2 = open("3-3.txt", O_CREAT | O_WRONLY, 0644);

    if(fd_1 == -1 || fd_2 == -1)
    {
        perror("Open");
        exit(1);
    }

    /*
        Read from 3-1.txt about the size of buf, and write to 3-3.txt.
        Should terminate while-loop if there's nothing remains to read.
    */
    while(n = read(fd_1, buf, sizeof(buf)))
    {
        write(fd_2, buf, n);
    }

    close(fd_1);
    close(fd_2);
    
    return 0;
}