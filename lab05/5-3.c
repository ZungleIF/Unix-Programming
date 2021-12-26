#include <sys/types.h>
#include <time.h>
#include <stdio.h>

int main()
{
    // A format for strftime().
    // ex) 2019. 10. 15. (화) 11:16:05 KST 
    char *fmt = "%G. %m. %d. (%A) %T %Z";
    char buf[256];
    time_t tt;
    struct tm *tm;
    
    time(&tt);             // Get the time from system.
    tm = localtime(&tt);   // Converts the time to localtime.
    strftime(buf, sizeof(buf), fmt, tm);
    printf("%s\n", buf);

    return 0;
}