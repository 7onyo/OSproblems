#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <pthread.h>
#include <semaphore.h>

long finalCount = 0;
pthread_mutex_t digitCount;

void *func(void *arg)
{
    char *s = (char*) arg;
    char *digi = "0123456789";
    long cnt = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(strchr(digi, s[i]))
        {
            cnt++;
        }
    }
    
    pthread_mutex_lock(&digitCount);
    finalCount += cnt;
    pthread_mutex_unlock(&digitCount);
    
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t threads[argc - 1];
    pthread_mutex_init(&digitCount, NULL);
    
    for(int i = 1; i < argc; i++)
    {
        pthread_create(&threads[i], NULL, func, argv[i]);
        /*printf("%s\n", argv[i]);*/
    }
    
    for(int i = 1; i < argc; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    wait(NULL);
    pthread_mutex_destroy(&digitCount);
    printf("%ld", finalCount);
  
    
    
    return 0;
}