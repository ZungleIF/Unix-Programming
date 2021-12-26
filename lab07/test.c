#include <string.h>
#include <stdio.h>

int main()
{
    char *buf;
    strcpy(buf, "hi\0");
    printf("%s\n", buf);
    return 0;
}