#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./libft/includes/libft.h"
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
    int *pipefd;
    int *infilefd;
   int   *outfilefd;
   char  *str[2];
   int   pid;

   str[0] = "cat";
   str[1] = 0;
   pipefd = (int *)malloc(4 * 2);
    pipe(pipefd);
   infilefd = (int *)malloc(4 * 2);

   pid = fork();
   if (pid == 0)
   {
   infilefd = open("file1", O_RDONLY);
   outfilefd = open("file3", O_WRONLY);
   dup2(infilefd, 0);
   dup2(pipefd[1]);
   execve("/bin/cat", str, 0);
   }

   pid = fork();
   
   return (0);
}s