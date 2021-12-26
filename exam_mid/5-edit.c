#include <sys/times.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

void dummy_copy(int fdin, int fdout, int size)
{
    int n = 0;
    char *buf = (char *)malloc(size);
    lseek(fdin, 0, SEEK_SET);
    lseek(fdout, 0, SEEK_SET);
    while(n = read(fdin, buf, size))  
    {
        write(fdout, buf, n);
    }
    free(buf);
}

int main()
{
    const int FILESIZE = 1000 * 1024 * 1024;
    int fdin, fdout;
    struct tms tms;
    clock_t t1, t2;
    int size;

    fdin  = open("dummy" , O_RDONLY                 );
    fdout = open("copy"  , O_CREAT  | O_WRONLY, 0644);
    
    for(size = 128; size <= FILESIZE; size *= 2)
    {   
        t1 = times(&tms);
        dummy_copy(fdin, fdout, size);
        t2 = times(&tms);
        printf("Buffer size: %d\t", size);
        printf("Real time: %.2f sec\n", (double)(t2 - t1) / sysconf(_SC_CLK_TCK));
    }
    
}