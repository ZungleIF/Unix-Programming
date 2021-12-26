#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pd[2];
    char *str = "Pipe test";
    char buf[BUFSIZ];
    int len, status;

    pipe(pd);

    write(pd[1], str, strlen(str));
    printf("%d writes %s to the pipe.\n", getpid(), str);
    len = read(pd[0], buf, BUFSIZ);
    printf("%d reads %s from the pipe.\n", getpid(), buf);

    close(pd[0]);
    close(pd[1]);
    
    return 0;
}