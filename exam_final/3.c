#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 100000000

unsigned int s = 0;
pthread_mutex_t mutex;

void *c(void *d)
{
    int i;
    for(i = 0; i < N; i++)
    {
        /*  
            Entering a critical section.
            Locks and unlocks a mutex before and after entering it.
        */
        pthread_mutex_lock(&mutex);
        s++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t t[2];
    int r;

    /*  Initialize a mutex.  */
    pthread_mutex_init(&mutex, NULL);

    /*  Create 2 threads, both working on function c . */
    r = pthread_create(&t[0], NULL, c, NULL);
    if(r)
    {
        perror("Thread create");
        exit(1);
    }
    r = pthread_create(&t[1], NULL, c, NULL);
    if(r)
    {
        perror("Thread create");
        exit(1);
    }
    /*  Wait for both threads to finish.  */
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    printf("%u\n", s);

    pthread_mutex_destroy(&mutex);

    return 0;
}