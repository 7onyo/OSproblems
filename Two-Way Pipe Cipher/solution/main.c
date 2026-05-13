#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

char *func1(int argc, char **argv)
{
    char *result = malloc(256);
    strcpy(result, "");
    
    for(int i = 1; i < argc; i++)
    {
        strcat(result, argv[i]);
        if(i != (argc - 1))
            strcat(result, " ");
    }
    
    for(int i = 0; i < strlen(result); i++)
    {
        if(result[i] > 'A' && result[i] <= 'Z')
            result[i] -= 1;
        else
            if(result[i] == 'A')
                result[i] = 'Z';
            else
                if(result[i] >= 'a' && result[i] < 'z')
                    result[i] += 1;
                else    
                    if(result[i] == 'z')
                        result[i] = 'a';
    }
    
    return result;
}

void *func2(char *result)
{
    for(int i = 0; i < strlen(result); i++)
    {
        if(result[i] >= 'A' && result[i] < 'Z')
            result[i] += 1;
        else
            if(result[i] == 'Z')
                result[i] = 'A';
            else
                if(result[i] > 'a' && result[i] <= 'z')
                    result[i] -= 1;
                else
                    if(result[i] == 'a')
                        result[i] = 'z';
    }
}


int main(int argc, char **argv)
{
    
    int pp12[2];
    int pp21[2];
    
    pipe(pp12);
    pipe(pp21);
    
    if(argc < 2)
    {
        printf("%s", "Error: no argument found");
        exit(0);
    }
    
    
    int id1 = fork();
    if(id1 == 0)
    {
        close(pp12[0]);
        close(pp21[1]);
        
        char *original = malloc(256);
        strcpy(original, "");
        
        for(int i = 1; i < argc; i++)
        {
            strcat(original, argv[i]);
            if(i != (argc - 1))
                strcat(original, " ");
        }
        
        
        char *result = func1(argc, argv);
        char *comm = malloc(256);
        write(pp12[1], result, strlen(result) + 1);
    
    
        
        int len = read(pp21[0], comm, 200);
        if(strcmp(original, comm) == 0)
            printf("Communication successful");
        else
            printf("Communication failed");
        
    
        
        close(pp12[1]);  
        close(pp21[0]);
        exit(1);
    }
    else
        if(id1 < 0)
            exit(1);
    
    
    int id2 = fork();
    if(id2 == 0)
    {
        close(pp12[1]);
        close(pp21[0]);
        
        char *result = malloc(256);
        
        int len = read(pp12[0], result, 200);
        result[len] = '\0';
        
        printf("%s\n", result);
        func2(result);
        
        
        write(pp21[1], result, strlen(result) + 1);
        
        close(pp12[0]);
        close(pp21[1]);
        exit(1);
        
    }
    else
        if(id2 < 0)
            exit(1);
    
    wait(NULL);
    
    close(pp12[0]);
    close(pp12[1]);
    close(pp21[0]);
    close(pp21[1]);
    
    return 0;
}