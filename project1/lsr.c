#include <sys/types.h>
#include <sys/queue.h>
#include <dirent.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* A data type for describing a directory. */
typedef struct z_dir
{
    struct dirent   **namelist;     // An array of file info.
    struct z_dir    *next;          // For z_list.
    char            dir_name[256];  // Absolute path to the directory.
    size_t          size;           // The number of files.
} z_dir;

/* A simple list just for lsr(). Contains z_dir data type. */
typedef struct 
{
    z_dir  *first;
    z_dir  *last;
    size_t  size;
} z_list;

/* Initialize a z_list. */
void z_list_init(z_list *__lst)
{
    __lst->first = malloc(sizeof(z_dir));
    __lst->first->next = NULL;
    __lst->last = __lst->first;
    __lst->size = 1;
}

/* Add a element at the end of a list. */
void z_list_add(z_list *__lst)
{
    z_dir *temp = malloc(sizeof(z_dir));
    __lst->last->next = temp;
    __lst->last = temp;
    __lst->size++;
}

int z_printdir_first = 1;

/*  
    Recursively scans a directory __dir, and stores them into __lst.
    With ascending order (a, b, c, ...).
*/
void z_scandir(const char *__dir, z_list *__lst)
{
    // Current working directory for this function.
    z_dir *cur;

    int n, i, j;
    char buffer[256];

    char name[256];
    unsigned char type;

    if(z_printdir_first)
    {
        z_list_init(__lst);
        z_printdir_first = 0;
    }
    else
    {
        z_list_add(__lst);
    }

    cur = __lst->last;
    strcpy(cur->dir_name, __dir);
    cur->size = scandir(__dir, &cur->namelist, NULL, alphasort);

    for(i = 2; i < cur->size; i++)
    {
        strcpy(name, cur->namelist[i]->d_name);
        type = cur->namelist[i]->d_type;

        // if the name of a file starts with '.', then it's a hidden file, so do not scan it.
        if(name[0] != '.' && type == DT_DIR)
        {
            // Concacenate strings to make an absolute path.
            snprintf(buffer, sizeof(buffer), "%s/%s", __dir, name) < 0 ? abort() : (void) 0;
            // If its data type is directory, scan it, too.
            z_scandir(buffer, __lst);
        }
    }
}

/*
    Iterate __lst to print directories
*/
void z_printdir(z_list *__lst)
{
    z_dir *cur;
    char name[256];
    unsigned char type;
    int i, j;

    for(i = 0, cur = __lst->first; i < __lst->size; i++, cur = cur->next)
    {
        printf("%s:\n", cur->dir_name);
        for(j = 2; j < cur->size; j++)
        {
            strcpy(name, cur->namelist[j]->d_name);
            type = cur->namelist[j]->d_type;

            if(name[0] != '.')
            {
                printf("%s\t", name);
            }

            free(cur->namelist[j]);
        }
        printf("\n\n");
        free(cur->namelist);
    }
}

void lsr(int __argc, char **__argv)
{
    z_list lst;
    int i;

    z_list_init(&lst);
    z_list_add(&lst);

    if(__argc == 1)
    {
        z_scandir(".", &lst);
    }
    else
    {
        for(i = 1; i < __argc; i++)
        {
            z_scandir(__argv[i], &lst);
        }
    }

    z_printdir(&lst);
}

int main(int argc, char **argv)
{
    lsr(argc, argv);

    return 0;
}