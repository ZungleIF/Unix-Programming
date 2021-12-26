#include <unistd.h>
#include <fcntl.h>

#define SIZE 4096

int main()
{
    int fdin, fdout;    // Vars for file descriptor.
    char buf[SIZE];     // A buffer for read() and write().
    int n = 0;          // To get actual read bytes by read().

    // Open dummy with Read-Only mode
    fdin  = open("dummy" , O_RDONLY                 );
    // Open copy with Write-Only mode. If it does not exist, create one.
    fdout = open("copy"  , O_CREAT  | O_WRONLY, 0644);

    // Read dummy into buf.
    while(n = read(fdin, buf, SIZE))  
    {
        // Write buf into copy.
        write(fdout, buf, n);
    }

    // Close both dummy and copy.
    close(fdin);
    close(fdout);

    return 0;
}