#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Before fork ...\n");

    // Generate a child process that has the same code.
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid > 0)
    {
        /* if this is a parent process. */
        sleep(2);
        printf("Parent process has pid = %d ppid = %d\n", getpid(), getppid());
    }
    else
    {
        /* If this is a child process. */
        printf("Child process has pid = %d ppid = %d\n", getpid(), getppid());
    }

    printf("End of fork ...\n");

    return 0;
}