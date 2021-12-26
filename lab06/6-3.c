#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *a[3];

    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid > 0)
    {
        printf("Parent %d executes.\n", getpid());
    }
    else
    {
        printf("Child %d executes\n", getpid());
        a[0] = "ls";
        a[1] = "-a";
        a[2] = NULL;
        /* Executes terminal command "ls -a" in the child process. */
        if(execv("/bin/ls", a) == -1)
        {
            perror("exec");
            exit(2);
        }
    }
    return 0;
}