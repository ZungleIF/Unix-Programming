#include <pwd.h>    // A header for password files or files with those formats.
#include <stdio.h>

int main()
{
    // A struct pointer for storing values returned by getpwnam().
    struct passwd *pw;

    // Reads password.txt by name.
    pw = getpwnam("zungle");

    printf("UID:            %d\n", (int)pw->pw_uid  );
    printf("Name:           %s\n",      pw->pw_name );
    printf("Home Directory: %s\n",      pw->pw_dir  );
    printf("Shell:          %s\n",      pw->pw_shell);

    return 0;
}