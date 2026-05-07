#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int id = fork();

    if(id > 0)
    {
        wait(NULL);
        printf("PARENT -- PID: %d; PPID: %d;\n", getpid(), getppid());
    }  
    else 
        if(id == 0)
        {
            printf(" CHILD -- PID: %d; PPID: %d;\n", getpid(), getppid());
        }
        else
        {
            printf("Error");
            exit(1);
        }
    return 0;
}