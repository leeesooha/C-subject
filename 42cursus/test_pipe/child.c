/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:53:02 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/31 00:45:45 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(t_data *data, int pid)
{
	pid = fork();
	if (pid == 0)
	{
		if (data->pipenum == 0)
			infile_to_pipe(data);
		else if (data->pipenum < data->ncmd - 1)
			pipe_to_pipe(data);
		else
			pipe_to_outfile(data);
		cmd_check(data);
		dpch_free(data->envpaths);
		execve(data->path_cmd, data->sp_cmd, data->envp);
		perror("execve fail");
		exit (1);
	}
	return (0);
}

int	infile_to_pipe(t_data *data)
{
	if (data->infilefd == -1)
		all_free(data, 2, 0, 0);
	close(data->pipefd1[0]);
	close(data->outfilefd);
	dup2(data->infilefd, STDIN_FILENO);
	dup2(data->pipefd1[1], STDOUT_FILENO);
	close(data->pipefd1[1]);
	close(data->infilefd);
	return (0);
}

int	pipe_to_pipe(t_data *data)
{
	if (data->pipenum % 2 == 1)
	{
		close(data->pipefd1[1]);
		close(data->infilefd);
		close(data->outfilefd);
		dup2(data->pipefd1[0], STDIN_FILENO);
		dup2(data->pipefd1[1], STDOUT_FILENO);
		close(data->pipefd1[0]);
	}
	else
	{
		close(data->pipefd1[0]);
		close(data->pipefd2[1]);
		close(data->infilefd);
		close(data->outfilefd);
		dup2(data->pipefd2[0], STDIN_FILENO);
		dup2(data->pipefd1[1], STDOUT_FILENO);
		close(data->pipefd2[0]);
		close(data->pipefd1[1]);
	}
	return (0);
}

int	pipe_to_outfile(t_data *data)
{
	if (data->outfilefd < 0)
		all_free(data, 3, 0, 0);
	if (data->pipenum % 2 == 0)
	{
		close(data->pipefd1[0]);
		close(data->pipefd1[1]);
		close(data->pipefd2[1]);
		close(data->infilefd);
		dup2(data->pipefd2[0], STDIN_FILENO);
		dup2(data->outfilefd, STDOUT_FILENO);
		close(data->pipefd2[0]);
		close(data->outfilefd);
	}
	else
	{
		close(data->pipefd2[0]);
		close(data->pipefd2[1]);
		close(data->pipefd1[1]);
		close(data->infilefd);
		dup2(data->pipefd1[0], STDIN_FILENO);
		dup2(data->outfilefd, STDOUT_FILENO);
		close(data->pipefd1[0]);
		close(data->outfilefd);
	}
	return (0);
}
