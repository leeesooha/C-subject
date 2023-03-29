/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:14:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/29 21:25:25 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_free(int **pipe)
{
	int	i;

	i = 0;
	while (pipe[i])
	{
		free(pipe[i]);
		i++;
	}
	free(pipe[i]);
	free(pipe);
	return (0);
}

int	dpch_free(char **s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s[i]);
	free(s);
	return (0);
}

int	all_free(t_data *data, int flag, char *s, int errorflag)
{
	if (data->pipenum <= data->npipe)
		error_print(data, errorflag);
	if (s)
		free(s);
	if (flag >= 1)
		dpch_free(data->envpaths);
	if (flag >= 2)
		dpch_free(data->cmd);
	if (flag >= 3)
		pipe_free(data->pipefd);
	if (flag >= 4)
		dpch_free(data->sp_cmd);
	if (errorflag != 10)
		exit (1);
	return (0);
}

int	close_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->npipe)
	{
		close(data->pipefd[i][0]);
		close(data->pipefd[i][1]);
		i++;
	}
	close(data->infilefd);
	close(data->outfilefd);
	return (0);
}

void	error_print(t_data *data, int errorflag)
{
	char	*print;

	if (errorflag == 1)
		perror("");
	else if (errorflag == 2)
	{
		perror(data->argv[1]);
	}
	else if (errorflag == 3)
	{
		print = ft_strjoin(data->sp_cmd[0], ": command not found\n");
		if (print)
			write(2, print, ft_strlen(print));
	}
}