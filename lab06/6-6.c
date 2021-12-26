#include <unistd.h>
#include <signal.h>

#include <stdio.h>
int main()
{
    int i;
    /* Ignores interrupt cause by pressing ctrl + C */
    sigignore(SIGINT);
    for(i = 0; i < 10; i++)
    {
        printf("Sleep 1 second...\n");
        sleep(1);
    }
    return 0;
}