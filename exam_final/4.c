#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pd[2];

    /*  Make a pipe.  */
    pipe(pd);

    if(fork() == 0)
    {
        /*
            In the child process execute 'ls -l' and
            put to the input-side of the pipe.
        */
        dup2(pd[1], 1);
        close(pd[0]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }
    else
    {
        /*
            In the parent get contents from output-side of
            the pipe and execute 'grep c'.
        */
        dup2(pd[0], 0);
        close(pd[1]);
        execlp("grep", "grep", "c", NULL);
        wait(NULL);
    }
    return 0;
}