#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

off_t skip_line(int fd)
{
    char buf[1];
    int n;
    while(n = read(fd, buf, sizeof(buf)))
    {
        if(buf[0] == '\n')
        break;
    }
    return lseek(fd, 0, SEEK_CUR);
}

void split(int fd, char **arr)
{
    int b_remain = FALSE;
    char buf[1], temp[10];
    int n, r = 0, c = 0, i = 0;
    while(n = read(fd, buf, sizeof(buf)))
    {
        switch(buf[0])
        {
            case ' ':
                if(b_remain)
                {
                    arr[r][c++] = temp; 
                    b_remain = FALSE;
                    i = 0;
                }
                break;
            case '\n':
                if(b_remain)
                {
                    arr[r++][c] = temp; 
                    b_remain = FALSE;
                    c = 0;
                    i = 0;
                }
                break;
            default:
                b_remain = TRUE;
                temp[i] = buf[0];
                ++i;
                break;
        }
    }

}

int main()
{
    int fdi, fdo;
    int n;
    char *table[5];
    char delims[2][1] = {' ', '\n'};
    char buf[20];

    fdi = open("3-8.dat", O_RDONLY);
    fdo = open("3-8.out", O_CREAT | O_WRONLY);
    skip_line(fdi);
    return 0;
}