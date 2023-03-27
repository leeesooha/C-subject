#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./libft/includes/libft.h"
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
	int infd;
	int pipefd[2];
	int pid;
	char    *cmd[] = {"/bin/cat", NULL};
	char    *fcmd[] = {"/bin/cat", NULL};
	int     status;
	int outfd;

	pipe(pipefd);
	outfd = open (argv[4], O_WRONLY| O_TRUNC);
	infd = open(argv[1], O_RDONLY);
	pid = fork();
	if (pid == 0)
	{
		dup2(infd,0);
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(fcmd[0], fcmd, envp);
	}

 //  waitpid(-1, 0,0);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[0], 0);
		dup2(outfd, 1);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(cmd[0], cmd, envp);
	}
 //   wait(&status);
 //   close(pipefd[1]);
 //   close(outfd);
  //  close(pipefd[0]);
	return (0);
}