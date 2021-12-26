#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    // fork() three times.
    for(i = 0; i < 3; i++)
    {
        if(fork() == 0)
        {
            printf("My pid is %d and ppid is %d\n", getpid(), getppid());
            break;
        }
    }
    
    // Wait for child processes to finish.
    for(i = 0; i < 3; i++)
    {
        wait(NULL);
    }

    return 0;
}