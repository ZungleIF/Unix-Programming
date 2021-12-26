#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *fname;
    char fntmp[BUFSIZ];
    char template[32];

    // tmpnam() generates an (seemingly) unique temporary filename
    // and returns it as a pointer to a string. If the argument is not NULL,
    // the name is copied to cstring.
    fname = tmpnam(NULL);
    printf("1. TMP File Name(tmpnam) : %s\n", fname);
    
    tmpnam(fntmp);
    printf("2. TMP File Name(tmpnam) : %s\n", fntmp);

    // tempnam() generates an unique temporary filename according to 
    // the arguments (a directory and a prefix).
    fname = tempnam("/tmp", "coredump");
    printf("3. TMP File Name(tempnam) : %s\n", fname);

    // mktemp() also does the same thing but has an argument with
    // directory and prefix combined.
    strcpy(template, "/tmp/coredumpXXXXXX");
    fname = mktemp(template);
    printf("4. TMP File Name(mktemp) : %s\n", fname);
    
    return 0;
}