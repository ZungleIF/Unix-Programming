#include <stdio.h>
#include <unistd.h>

int main()
{
    int i;
    /* Sleep 1 second 10 times. */
    for(i = 0; i < 10; i++)
    {
        printf("Sleep 1 second...\n");
        sleep(1);
    }
    return 0;
}