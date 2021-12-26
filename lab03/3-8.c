#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct m_string
{
    unsigned char str[256];
} m_string;

// A function for skipping the top line.
void skip_line(FILE *fp)
{
    char temp[3][10];
    fscanf(fp, "%s%s%s", temp[0], temp[1], temp[2]);
}

int main()
{
    m_string table[10][4];
    int i = 0, j = 0;
    int last_line;
    int sum;
    double avg;

    FILE *fpi = fopen("3-8.dat", "r");
    FILE *fpo = fopen("3-8.out", "w");

    skip_line(fpi);
    // Reads marks from 3-8.dat and put into a table.
    while(fscanf(fpi, "%s%s%s%s", table[i][0].str, table[i][1].str,
                                  table[i][2].str, table[i][3].str) != EOF)
    {
        ++i;
    }

    last_line = i;

    // Prints sum and average to 3-8.out.
    fprintf(fpo, "\t\tSUM\tAVG\n");
    for(i = 0; i < last_line; i++)
    {
        sum = atoi(table[i][1].str) + atoi(table[i][2].str) + atoi(table[i][3].str);
        avg = (double) sum / 3;
        if(strlen(table[i][0].str) < 4)
        {
            fprintf(fpo, "%s\t\t%i\t%.2f\n", table[i][0].str, sum, avg);
        }
        else
        {
            fprintf(fpo, "%s\t%i\t%.2f\n", table[i][0].str, sum, avg);
        }
    }

    // Prints averages of subjects at the end.
    fprintf(fpo, "Subject AVG\nKO\t\tEN\t\tMA\t\t\n");
    for(int i = 0; i < 3; i++)
    {
        sum = 0;
        for(int j = 0; j < last_line; j++)
        {
            sum += atoi(table[j][i + 1].str);
        }
        fprintf(fpo, "%.2f\t", (double) sum / last_line);
    }

    return 0;
}