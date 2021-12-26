#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int shm;
    char *addr1, *addr2;
    char temp1[32] = "Message from ", temp2[32];
    /*  Initialize an IPC object, shared memory.  */
    shm = shmget(IPC_PRIVATE, 128, IPC_CREAT | 0666);

    if(fork() == 0)
    {
        printf("=Child begins\n");
        addr1 = shmat(shm, NULL, 0);    /*  Connect shm.  */
        sprintf(temp2, "%d", getpid());
        strcat(temp1, temp2);           /*  "Message from: getpid()"  */
        strcpy(addr1, temp1);
        shmdt(addr1);                   /*  Disconnect shm.  */
        printf("=Child ends\n");
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("=Parent begins\n");
        addr2 = shmat(shm, NULL, 0);
        printf("%s\n", addr2);
        shmdt(addr2);
        shmctl(shm, IPC_RMID, NULL);    /*  Destroy the object.  */
        printf("=Parent ends\n");
    }

    return 0;
}