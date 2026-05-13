#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    for(int i = 2; i < argc; i++)
    {
        int fd = open(argv[i], O_RDONLY);
        char buf[512];
        int n = read(fd, buf, 500);
        buf[n] = '\0';
        
        char *p = strtok(buf, "\n");
        int cnt = 0;
        while(p != NULL)
        {
            
            if(strstr(p, argv[1]))
            {
                cnt++;
            }
            p = strtok(NULL, "\n");
        }
        printf("%d\n", cnt);
    }
 
    return 0;
}