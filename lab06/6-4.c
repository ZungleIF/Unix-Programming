#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int i, status;

    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid > 0)
    {
        printf("Parent %d waits child %d\n", getpid(), pid);
        /* 
            Wait for the child process to finish.
            Child's exit state is stored in status.
        */
        wait(&status);
        printf("Child's exit status = %x\n", status);
        /*  Needs to shift 8 bits to the right.  */
        printf("Child's exit status = %d\n", status >> 8);
    }
    else{
        for(i = 0; i < 5; i++)
        {
            printf("Child %d executes.\n", getpid());
            sleep(1);
        }
        exit(3);
    }

    return 0;
}