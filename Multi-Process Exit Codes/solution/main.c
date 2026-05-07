#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int childrenPids[20];

    for(int i = 1; i <= 19; i++)
    {
        int id = fork();

        if(id == 0)
        {
            exit(i); 
        }
        else if(id > 0)
        {
            childrenPids[i] = id;
        }
        else
        {
            printf("fork failed");
            exit(1);
        }
    

    }
    
    for(int i = 1; i <= 19; i++)
    {
        int status;
        int finished = waitpid(childrenPids[i], &status, 0);
        printf("CHILD%d having PID: %d ended with exit code: %d\n", i, finished, WEXITSTATUS(status));
    }
    wait(NULL);
    printf("PARENT -- PID: %d -- PPID: %d\n", getpid(), getppid());

    return 0;
}
