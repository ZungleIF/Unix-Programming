#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>
#include <stdio.h>

#include "include.h"

/*  A function to help remove any unused buffer in stdin.  */
void flush_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    struct sockaddr_in sin;
    int sd;
    char data[BUFFER_SIZE];
    int i;
    int connect_status;

    memset(&sin, '\0', sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_port = 9000;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");


    while(1)
    {
        sd = socket(AF_INET, SOCK_STREAM, 0);
        /*  Connect to the server /w localhost:9000.  */
        connect(sd, (struct sockaddr *) &sin, sizeof(sin));
        printf("Shell Command (Type 'exit' to quit): ");
        scanf("%[^\n]s", data);
        flush_stdin();
        if(strcmp("exit", data) == 0)
        {
            break;
        }
        send(sd, data, strlen(data) + 1, 0);
        recv(sd, data, sizeof(data), 0);
        close(sd);
        printf("%s\n", data);
        /*  Clear data.  */
        memset(data, '\0', sizeof(data));
    }
    return 0;
}