#include <stdio.h>

int main()
{
    int c;
    FILE *f1 = fopen("3-1.txt", "r");
    FILE *f2 = fopen("3-5.txt", "w");
    if(f1 == NULL || f2 == NULL)
    {
        perror("Open");
    }
    else
    {
        while((c = fgetc(f1)) != EOF)
        {
            fputc(c, f2);
        }
    }

    fclose(f1);
    fclose(f2);

    return 0;
}