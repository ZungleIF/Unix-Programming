#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pd[2];
    char *str = "Pipe Test";
    char buf[BUFSIZ];
    int len, status;

    if(pipe(pd) == -1)
    {
        perror("pipe");
    }


    switch(fork())
    {
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:
            close(pd[1]);   // Close write-end.
            len = read(pd[0], buf, BUFSIZ);
            printf("%d reads %s from the pipe.\n", getpid(), buf);
            close(pd[0]);   // Close read-end.
            break;
        default:
            close(pd[0]);
            write(pd[1], str, strlen(str));
            printf("%d writes %s to the pipe.\n", getpid(), str);
            close(pd[1]);
            wait(NULL);
            break;
    }
    
    return 0;
}