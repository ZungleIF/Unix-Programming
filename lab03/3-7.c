#include <stdio.h>
#include <stdlib.h>

int main()
{
    char template[32] = "tempXXXXXX";
    mkstemp(template);
    return 0;
}