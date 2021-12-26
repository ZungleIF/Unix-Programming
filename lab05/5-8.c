#include <sys/times.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

int main()
{
    struct tms tms;
    clock_t t1, t2;
    int i;

    t1 = times(&tms);

    for(i = 0; i <= 1000000; i++)
    {
        printf("%d\n", i);
    }
    
    t2 = times(&tms);

    // printf("Real time:   %.3f sec\n", (double)(t2 - t1)     / sysconf(_SC_CLK_TCK));
    // printf("User time:   %.3f sec\n", (double)tms.tms_utime / sysconf(_SC_CLK_TCK));
    // printf("System time: %.3f sec\n", (double)tms.tms_stime / sysconf(_SC_CLK_TCK));
    printf("Real time:   %.3f sec\n", (double)(t2 - t1)     / CLOCKS_PER_SEC);
    printf("User time:   %.3f sec\n", (double)tms.tms_utime / CLOCKS_PER_SEC);
    printf("System time: %.3f sec\n", (double)tms.tms_stime / CLOCKS_PER_SEC);
    printf("%ld\n", sysconf(_SC_CLK_TCK));
    printf("%ld\n", CLOCKS_PER_SEC);
    printf("%ld\n", tms.tms_utime);
    printf("%ld\n", tms.tms_utime);
    printf("%ld\n", clock());
    return 0;
}