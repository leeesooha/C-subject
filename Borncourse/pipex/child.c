/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:53:02 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/28 21:19:41 by soohlee          ###   ########.fr       */
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
		else if (data->pipenum < data->npipe)
			pipe_to_pipe(data, data->pipenum, data->pipenum + 1);
		else
			pipe_to_outfile(data);
		cmd_check(data);
		execve(data->path_cmd, data->sp_cmd, data->envp);
	}
	return (0);
}

int	infile_to_pipe(t_data *data)
{
	dup2(data->infilefd, 0);
	dup2(data->pipefd[0][1], 1);
	close_pipe(data);
	return (0);
	return (0);
}

int	pipe_to_pipe(t_data *data, int current, int next)
{
	dup2(data->pipefd[current - 1][0], 0);
	dup2(data->pipefd[next - 1][1], 1);
	close_pipe(data);
	return (0);
}

int	pipe_to_outfile(t_data *data)
{
	dup2(data->pipefd[data->pipenum - 1][0], 0);
	dup2(data->outfilefd, 1);
	close_pipe(data);
	return (0);
}
