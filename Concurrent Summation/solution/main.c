#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    
    if(argc < 2)
    {
        printf("Error: no argument found");
        exit(0);
    }
    
    int results[argc];
    int childrenPids[argc];
    
    for(int i = 1; i < argc; i++)
    {
        int id = fork();
        if(id > 0)
        {
            wait(NULL);
        }
        if(id == 0)
        {
            int number = atoi(argv[i]);
            int result = 0;
            while(number != 0)
            {
                result = result + (number % 10);
                number = number / 10;
            }
            results[i] = result;
            childrenPids[i] = getpid();
            
            printf("%d ", results[i]);
            
            exit(0);
            
            
        }
    }
    

    return 0;
}