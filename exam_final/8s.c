#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>
#include <string.h>

int main()
{
    /*  Declare variables for a socket to work.  */
    struct sockaddr_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);
    char buf[256];
    int i;

    /*  Initialize sin with portnum 9000 and localhost.  */
    memset(&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = 9000;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    sd = socket(AF_INET, SOCK_STREAM, 0);               /*  Make a socket.  */
    bind(sd, (struct sockaddr *) &sin, sizeof(sin));    /*  Bind it with sin.  */
    /*  Now the socket listens for incoming transmissions.  */
    listen(sd, 4);                                      

    while(1)
    {
        ns = accept(sd, (struct sockaddr *) &cli, &clientlen);
        recv(ns, buf, sizeof(buf), 0);
        /*  Conver upper-case to lower-case & vice versa.  */
        for(i = 0; i < 256; i++)
        {
            if(buf[i] >= 'A' && buf[i] <= 'Z')
            {
                buf[i] += 32;
            }
            else if(buf[i] >= 'a' && buf[i] <= 'z')
            {
                buf[i] -= 32;
            }
        }
        send(ns, buf, strlen(buf) + 1, 0);
        close(ns);
    }

    close(sd);
    return 0;
}