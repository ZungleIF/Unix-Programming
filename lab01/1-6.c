#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Declares a string.
    char *str;

    // Allocates 20 bytes of memory on str.
    str = malloc(sizeof(char) * 20);

    // Copies a string "Hello" into str, and prints it.
    strcpy(str, "Hello");
    printf("%s\n", str);
    
    // Copies a string "Good morning" into str, and prints it.
    strcpy(str, "Good morning");
    printf("%s\n", str);

    // Deallocates formally allocated memory.
    free(str);
    return 0;
}