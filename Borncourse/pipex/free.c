/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:14:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/29 13:07:52 by soohlee          ###   ########.fr       */
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
	free(pipe);
	return (0);
}

int	dpch_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

int	all_free(t_data *data, int flag)
{
	if (flag == 1)
		dpch_free(data->envpaths);
	else if (flag == 2)
	{
		dpch_free(data->envpaths);
		dpch_free(data->cmd);
	}
	else if (flag == 3)
	{
		dpch_free(data->envpaths);
		dpch_free(data->cmd);
	//	pipe_free(data->pipefd);
	}
	perror("");
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