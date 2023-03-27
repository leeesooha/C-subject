/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:53:02 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/27 21:15:23 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(t_data *data, int pid)
{
	pid = fork();

	//char *str[3];

	//str[0] = "wc";
	//str[1] = "-l";
	//str[2] = 0;
	if (pid == 0)
	{
		if (data->pipenum == 0)
		{
			infile_to_pipe(data);
			cmd_check(data);
			execve(data->path_cmd, data->sp_cmd, data->envp);
		}
		else if (data->pipenum < data->npipe)
		{
			redirection(data, data->pipenum, data->pipenum + 1);
			cmd_check(data);
			execve(data->path_cmd, data->sp_cmd, data->envp);
		}
		else
		{
			pipe_to_outfile(data);
			cmd_check(data);
			write(2, data->path_cmd, 50);
			write(2, "\n", 1);
			write(2, data->sp_cmd[0], 10);
			write(2, "\n", 1);
			write(2, data->sp_cmd[1], 10);
			write(2, "\n", 1);
//			execve("/bin/cat", str, data->envp);
			execve(data->path_cmd, data->sp_cmd, data->envp);
		}
	}
	return (0);
}

int	pipe_to_outfile(t_data *data)
{
	dup2(data->pipefd[0][0], 0);
	dup2(data->outfilefd, 1);
	close(data->outfilefd);
	close(data->pipefd[0][1]);
	close(data->pipefd[0][0]);
	return (0);
}

int	redirection(t_data *data, int current, int next)
{
	dup2(data->pipefd[current - 1][0], 0);
	dup2(data->pipefd[next - 1][1], 1);
	close_child_pipe(data);
	return (0);
}

int	infile_to_pipe(t_data *data)
{
	dup2(data->infilefd, 0);
	dup2(data->pipefd[0][1], 1);
	close(data->infilefd);
	close(data->pipefd[0][0]);
	close(data->pipefd[0][1]);
	return (0);
}
