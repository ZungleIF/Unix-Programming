#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("Argument Max:   %ld\n", sysconf(_SC_ARG_MAX ));     // MAx length of arg in bytes.
    printf("Child Max:      %ld\n", sysconf(_SC_CHILD_MAX ));   // Max number of processes a child can have.
    printf("Clock Tick:     %ld\n", sysconf(_SC_CLK_TCK ));     // Tick rate.
    printf("Open File Max:  %ld\n", sysconf(_SC_OPEN_MAX));     // Max number of files opened per process.
    printf("POSIX Version:  %ld\n", sysconf(_SC_VERSION ));     // POSIX.1 Version.

    return 0;
}