#include <stdio.h>
#include <stdlib.h>

/*
    argc represents the number of argument.
    argv stores an array of strings input as arguments.
*/
int main(int argc, char **argv) 
{
    int i, sum = 0;

    /*
        Converts every string argument into integer type
        and add to sum in a for loop.
    */
    for(i = 1; i < argc; i ++)
        sum += atoi(argv[i]);
    
    printf("%d\n", sum);
    return 0;
}