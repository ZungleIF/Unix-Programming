#include <stdio.h>
#include <signal.h>

/*  Handler for sigaction()  */
void handler(int signo)
{
    psignal(signo, "\nReceived Signal");
}

int main()
{
    short i = 0;
    struct sigaction act;
    
    /*  Initialize sigaction struct  */
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler = handler;
    /*  Ignore interrupt(ctrl-C) from user.  */
    sigaction(SIGINT, &act, NULL);

    while(1)
    {
        if(i < 0)
        {
            i = 0;
        }
        printf("%d\r", i++);
    }

    return 0;
}