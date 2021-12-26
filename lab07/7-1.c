#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *addr;
    struct stat st;

    fd = open(argv[1], O_RDONLY);
    stat(argv[1], &st);
    addr = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    printf("%s", addr);
    return 0;
}