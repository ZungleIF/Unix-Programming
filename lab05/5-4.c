#include <unistd.h>
#include <stdio.h>

int main()
{
    sleep(1);   // Sleep 1 sec for checking process list.

    printf("\nPID: %d\n" , (int)getpid  ());    // PID of the process.
    printf("PPID: %d\n"  , (int)getppid ());    // PID of the parent process.

    return 0;
}