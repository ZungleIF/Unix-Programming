#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b_out = 0;      // A var for getting out of the loop.
    char input[256];    // A var for user input.
    // This is equivalent to "select foo in bar ..."
    while(!b_out)
    {
        printf("1) pwd\n2) date\n3) quit\n#? ");    // Prints menu.
        fgets(input, sizeof(input), stdin);         // Gets user input.
        switch(atoi(input))
        {
            // Use system() library function for shell commands.
            case 1:
                system("pwd");
                break;
            case 2:
                system("date");
                break;
            case 3:
                b_out = 1;
                break;
            default:
                printf("Invalid selection\n");
        }
    }
    return 0;
}