
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define FILEDIR_BUFFER_SIZE 70

int isdigit(char *c)
{
    return (*c >= '0' && *c <= '9');
}
int is_valid_on_off(char *str)
{
    return !(strcmp(str, "on") == 0 || strcmp(str, "off") == 0);
}

int main(int argc, char *argv[])
{

    char filedir[FILEDIR_BUFFER_SIZE];
    if (argc < 2)
    {
        printf("Error: The first argument is required.\n");
        return 1;
    }
    if (strcmp(argv[1], "-h") == 0)
    {

        /// No time to implement it—maybe next time. :) you can do it
        printf("I can't help you. Try again and i ensure it runs correctly on your end.");
        return 0;
    }
    int isDFlag = 0;
    char *fristArg = argv[1];
    char *secondArg = NULL;
    char *thirdArg = NULL;

    if (argc >= 3 && strcmp(argv[2], "-d") == 0)
    {
        isDFlag = 1;
        if (argc < 4)
        {
            printf("Error: Argument 3 is required when '-d' is specified.\n");
            exit(1);
        }
        secondArg = argv[2];
        thirdArg = argv[3];
    }

    if (!isdigit(argv[1]) && !isDFlag)
    {
        printf("Error: The first argument must be a valid number.\n");
        return 1;
    }
    char *on_off = argv[isDFlag ? 3 : 2];

    if (is_valid_on_off(on_off))
    {
        printf("Error: The third argument must be 'on' or 'off'.\n");
        return 1;
    }

    if (isDFlag)
        snprintf(filedir, FILEDIR_BUFFER_SIZE, "%s", fristArg);
    else
        snprintf(filedir, FILEDIR_BUFFER_SIZE, "/sys/class/leds/input%s::capslock/brightness", fristArg);

    int fileID = open(filedir, O_RDWR);

    if (strcmp(on_off, "on") == 0)
    {
        dprintf(fileID, "1\n");
    }
    else if (strcmp(on_off, "off") == 0)
    {
        dprintf(fileID, "0\n");
    }
    return 0;
}
