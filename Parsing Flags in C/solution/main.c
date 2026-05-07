#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *xvalue = NULL;
    int yflag = 0;
    int zflag = 0;

    int option;

    while((option = getopt(argc, argv, "x:yz")) != -1)
    {
        switch (option)
        {
            case 'x':
                xvalue = optarg;
                break;

            case 'y':
                yflag = 1;
                break;

            case 'z':
                zflag = 1;
                break;

            default:
                break;
        }
    }

    printf("xvalue = %s; yflag = %d; zlag = %d\n", xvalue, yflag, zflag);
    return 0;
}