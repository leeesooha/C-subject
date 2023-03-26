#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./libft/includes/libft.h"
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
    int     pid;
    int     pid2;
    char    *str;
    int     idx;
    int     waitstatus;

    str = (char *)malloc(sizeof(char) * 11);
    idx = 0;
    while (idx < 10)
    {
        str[idx] = idx + 'A';
        idx++;
    }
    str[idx] = 0;
    pid = fork();
    waitpid(-1, 0, 0);
    if (pid)
    {
        printf("parent : %p\n", str);
        printf("parent : %s\n", str);
    }
    if (pid == 0)
    {
        str[0] = 'Z';
        printf("child : %p\n", str);
        printf("child : %s\n", str);
    }
    pid2 = fork();
    if (pid2 == 0)
    {
        str[0] = '&';
        printf("child2 : %p\n", str);
        printf("child2 : %s\n", str);
    }
    return (0);
}