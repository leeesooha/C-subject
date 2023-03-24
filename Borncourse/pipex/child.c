/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:53:02 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/24 21:33:11 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(t_data *args, int pid)
{
	pid = fork();

	if (pid == 0)
	{
		if (args->pipenum == 0)
		{
			infile_to_pipe(args, args->argv[1]);
			cmd_check(args, args->cmd[args->pipenum]);
			execve(args->full_namecmd[args->pipenum], &(args->cmd[args->pipenum * 2]), args->envp);
		}
		else if (args->pipenum < args->pipe_total - 1)
		{
			redirection(args, args->pipenum, args->pipenum + 1);
			cmd_check(args, args->cmd[args->pipenum]);
			execve(args->full_namecmd[args->pipenum], &(args->cmd[args->pipenum * 2]), args->envp);
		}
		else 
		{
			pipe_to_outfile(args, (args->argv)[args->argc - 1]);
			cmd_check(args, args->cmd[args->pipenum]);
			execve(args->full_namecmd[args->pipenum], &(args->cmd[args->pipenum * 2]), args->envp);
		}
	}
	return (0);
}

int	pipe_to_outfile(t_data *args, char *filename)
{
	if (access(filename, W_OK) == -1)
		all_free(args, 4);
	args->outfilefd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (args->outfilefd < 0)
		all_free(args, 4);
	dup2(args->outfilefd, 1);
	dup2(args->pipefd[args->pipenum][0], 0);
	close_child_pipe(args);
	return (0);
}

int	redirection(t_data *args, int current, int next)
{
	dup2(args->pipefd[current - 1][0], 0);
	dup2(args->pipefd[next - 1][1], 1);
//	close_child_pipe(args);
	return (0);
}

int	infile_to_pipe(t_data *args, char *filename)
{
	int		unusedfd;

	if (access(filename, R_OK) == -1)
		all_free(args, 4);
	args->infilefd = open(filename, O_RDONLY);
	if (args->infilefd < 0)
		all_free(args, 4);
	unusedfd = dup2(args->infilefd, 0);
	if (unusedfd == -1)
		all_free(args, 4);
	unusedfd = dup2(args->pipefd[0][1], 1);
	if (unusedfd == -1)
		all_free(args, 4);
//	close_child_pipe(args);
	close(args->pipefd[0][1]);
	return (0);
}
