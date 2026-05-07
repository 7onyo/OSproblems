#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s filename content...\n", argv[0]);
        exit(1);
    }

    int fdWrite = open(argv[1], O_TRUNC | O_CREAT | O_WRONLY, 0777);
    int fdRead  = open(argv[1], O_RDONLY);

    if(fdWrite < 0 || fdRead < 0)
    {
        perror("Error opening file");
        exit(1);
    }

    char buf[256];
    int id = fork();

    if(id == 0)
    {
        close(fdRead);

        for(int i = 2; i < argc; i++)
        {
            write(fdWrite, argv[i], strlen(argv[i]));
        }

        close(fdWrite);
        exit(0);
    }
    else if(id > 0)
    {
        close(fdWrite);

        int status;
        waitpid(id, &status, 0);

        if(!WIFEXITED(status) || WEXITSTATUS(status) != 0)
        {
            fprintf(stderr, "Child process error\n");
            exit(1);
        }

        int n;
        while((n = read(fdRead, buf, sizeof(buf)-1)) > 0)
        {
            buf[n] = '\0';
            printf("%s", buf);
        }

        close(fdRead);
    }
    else
    {
        perror("fork");
        exit(1);
    }

    return 0;
}
