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
	else
	{
		if(!(data->pipenum == 0))
			close (data->tmp_fd);
		close(data->pipefd1[1]);
		data->tmp_fd = data->pipefd1[0];
		if (!(data->pipenum == data->ncmd - 1))
			pipe(data->pipefd1);
	}
	return (0);
}

int	infile_to_pipe(t_data *data)
{
	if (data->infilefd == -1)
		all_free(data, 2, 0, 0);
	close(data->pipefd1[0]);
	dup2(data->infilefd, STDIN_FILENO);
	dup2(data->pipefd1[1], STDOUT_FILENO);
	close(data->pipefd1[1]);
	close(data->infilefd);
	return (0);
}

int	pipe_to_pipe(t_data *data)
{
	close(data->pipefd1[0]);
	dup2(data->tmp_fd, STDIN_FILENO);
	dup2(data->pipefd1[1], STDOUT_FILENO);
	close(data->tmp_fd);
	close(data->pipefd1[1]);
	return (0);
}

int	pipe_to_outfile(t_data *data)
{
	if (data->outfilefd < 0)
		all_free(data, 3, 0, 0);
	dup2(data->tmp_fd, STDIN_FILENO);
	dup2(data->outfilefd, STDOUT_FILENO);
	close(data->tmp_fd);
	close(data->outfilefd);
	return (0);
}
