#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/*  Define a signal handler for sigaction struct.  */
void handler(int signo)
{
    psignal(signo, "\nReceived Signal");
    sleep(5);
    printf("In Signal Handler, After Sleep.\n");
}

int main()
{
    struct sigaction act;

    /*  Unset every signal.  */
    sigemptyset(&act.sa_mask);
    /*  sa_flags defines how to send signals.  */
    act.sa_flags = 0;
    act.sa_handler = handler;
    /*  Ignores every interrupt signal from now on.  */
    if(sigaction(SIGINT, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(1);
    }

    while(1)
    {
        fprintf(stderr, "Input SIGINT: ");
        pause();
        fprintf(stderr, "After Signal Handler.\n");
    }
    return 0;
}