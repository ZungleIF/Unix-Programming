#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "include.h"


/*  
    Executes a shell command and store its output.
    If there's no output, returns -1, otherwise 0.
*/
int execute_cmd(const char *cmd, char *output)
{
    int pd[2];
    int nread;
    char buf[BUFFER_SIZE];

    pipe(pd);
    /*  Set O_NONBLOCK in case of an empty pipe.  */
    fcntl(pd[0], F_SETFL, O_NONBLOCK);  

    if(fork() == 0)
    {
        close(pd[READ_END]);
        dup2(pd[WRITE_END], FD_STDOUT);
        system(cmd);
        exit(EXIT_SUCCESS);
    }
    else
    {
        wait(NULL);
        close(pd[WRITE_END]);
        nread = read(pd[READ_END], output, sizeof(buf));
        if(nread < 0)
        {
            /*  Pipe is empty.  */
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    /*  Declare variables for a socket to work.  */
    struct sockaddr_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);
    char data_out[BUFFER_SIZE], data_in[BUFFER_SIZE];

    /*  Initialize sin with portnum 9000 and localhost.  */
    memset(&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = 9000;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

    sd = socket(AF_INET, SOCK_STREAM, 0);               /*  Make a socket.  */
    bind(sd, (struct sockaddr *) &sin, sizeof(sin));    /*  Bind it with sin.  */
    /*  Now the socket listens for incoming transmissions.  */
    listen(sd, 10);                                      

    while(1)
    {
        ns = accept(sd, (struct sockaddr *) &cli, &clientlen);
        recv(ns, data_in, sizeof(data_in), 0);
        execute_cmd(data_in, data_out);
        send(ns, data_out, strlen(data_out) + 1, 0);
        close(ns);
        /*  Clear data_out in data_in.  */
        memset(data_out, '\0', sizeof(data_out));
        memset(data_in, '\0', sizeof(data_in));
    }
    close(sd);
    return 0;
}