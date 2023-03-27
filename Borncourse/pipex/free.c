/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:14:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/27 17:30:54 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_free(int **pipe)
{
	printf("pipe\n");
	while (*pipe)
	{
		free(*pipe);
		(*pipe)++;
	}
	free(pipe);
	return (0);
}

int	dpch_free(char **s)
{
	printf("s\n");
	while (*s)
	{
		free(*s);
		*s = *s + 1;
	}
	free(s);
	return (0);
}

int	all_free(t_data *data, int flag)
{
	write(2, "\n\nfree\n\n", 8);
	return (0);
	if (flag == 1)
		dpch_free(data->envpaths);
	else if (flag == 2)
	{
		dpch_free(data->envpaths);
		dpch_free(data->cmd);
	}
	else if (flag == 3)
	{
		printf("%s\n", data->envpaths[0]);
		dpch_free(data->envpaths);
		printf("1\n");
		dpch_free(data->cmd);
		printf("2\n");
		pipe_free(data->pipefd);
		printf("3\n");
	}
	perror("");
	return (0);
}

int	close_child_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->npipe)
	{
		close(data->pipefd[i][0]);
		close(data->pipefd[i][1]);
		i++;
	}
	return (0);
}