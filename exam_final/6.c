#include <glib.h>
#include <stdio.h>

/*  
    Using glib to utilize various data types and functions.
    Install glib using 'sudo apt install libglib2.0-dev'.
    Compile /w 'gcc 6.c -o 6 $(pkg-config glib-2.0 --cflags --libs)'.
*/
/*  This is a function for sorting  */
gint compare(gconstpointer lhs, gconstpointer rhs)
{
    return strcmp(*(const char**) lhs, *(const char**) rhs);
}

int main(int argc, char **argv)
{
    int i;
    GPtrArray *arr = g_ptr_array_new(); /*  Initialize an array  */

    for(i = 1; i < argc; i++)
    {
        g_ptr_array_add(arr, argv[i]);
    }

    /*  
        Queue: FIFO, Stack: LIFO  
        Simply print array contents in succession and in reverse.
    */
    printf("Queue Order\n");
    for(i = 0; i < argc - 1; i++)
    {
        printf("%s\t", (char*) arr->pdata[i]);
    }
    printf("\n");

    printf("Stack Order\n");
    for(i = argc - 2; i >= 0; i--)
    {
        printf("%s\t", (char*) arr->pdata[i]);
    }
    printf("\n");

    /*  Sort the array in ascending order.  */
    g_ptr_array_sort(arr, compare);
    printf("Alphabetical Order\n");
    for(i = 0; i < argc - 1; i++)
    {
        printf("%s\t", (char*) arr->pdata[i]);
    }
    printf("\n");

    printf("Reverse Alphabetical Order\n");
    for(i = argc - 2; i >= 0; i--)
    {
        printf("%s\t", (char*) arr->pdata[i]);
    }
    printf("\n");

    return 0;
}