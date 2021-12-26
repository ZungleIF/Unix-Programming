#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    /*  Look for 8s.c for comments.  */
    struct sockaddr_in sin;
    int sd;
    char buf[256];
    int i, offset = 0;

    memset(&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = 9000;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    sd = socket(AF_INET, SOCK_STREAM, 0);
    /*  Connect to the server /w localhost:9000.  */
    connect(sd, (struct sockaddr *) &sin, sizeof(sin));

    /*  
        Concacentrate argv into a single string and
        send it to the server to process.
    */
    for(i = 1; i < argc; i++)
    {
        offset += snprintf(buf + offset, sizeof(buf), "%s ", argv[i]);
    }

    send(sd, buf, strlen(buf) + 1, 0);
    recv(sd, buf, sizeof(buf), 0);

    printf("From Server: %s\n", buf);


    close(sd);

    return 0;
}