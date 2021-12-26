#include <sys/types.h>
#include <sys/queue.h>
#include <dirent.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct z_dir
{
    struct dirent **namelist;
    char dir_name[256];
} z_dir;

z_dir dirs[]
int z_printdir(const char *__dir, z_queue *__q)
{
    struct dirent **namelist;
    int n, i;

    n = scandir(".", &namelist, NULL, alphasort);

    for(i = 0;z_list i++)
    {
        printf("%s ", namelist[i]->d_name);
        free(namelist[i]);
    }
    free(namelist);
    printf("\n");
}
z_list
int main(int argc, char **argv)
{
    DIR *dp;
    struct dirent *dent;
    z_queue q;

    z_q_init(&q);
    z_q_add(&q);z_list

    dp = opendir(".");
    z_printdir(NULL);
    return 0;
}z_list