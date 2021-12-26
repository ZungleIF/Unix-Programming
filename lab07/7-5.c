#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pd1[2], pd2[2];
    char buf[256];

    pipe(pd1);
    pipe(pd2);
    
    if(fork() == 0)
    {
        close(pd1[1]);
        close(pd2[0]);
        write(pd2[1], "from child", 16);
        read(pd1[0], buf, sizeof(buf));
        printf("Child: %s\n", buf);
        close(pd1[0]);
        close(pd2[1]);
    }
    else
    {
        close(pd1[0]);
        close(pd2[1]);
        write(pd1[1], "from parent", 16);
        read(pd2[0], buf, sizeof(buf));
        printf("Parent: %s\n", buf);
        wait(NULL);
        close(pd1[1]);
        close(pd2[0]);
    }
}