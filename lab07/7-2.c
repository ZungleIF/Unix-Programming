#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *addr;
    struct stat st;

    fd = open(argv[1], O_RDONLY);
    stat(argv[1], &st);
    addr = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);

    if(fork() == 0)
    {
        /*  Child Process  */
        printf("%s", addr);
        
    }
    else
    {
        /*  Parent Process  */
        wait(NULL);
        munmap(addr, st.st_size);
    }
    return 0;
}