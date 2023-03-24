/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:14:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/24 20:45:35 by soohlee          ###   ########.fr       */
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

int	all_free(t_data *args, int flag)
{
	exit (1);
	return (0);
	if (flag == 1)
		dpch_free(args->envpaths);
	else if (flag == 2)
	{
		dpch_free(args->envpaths);
		dpch_free(args->cmd);
	}
	else if (flag == 3)
	{
		printf("%s\n", args->envpaths[0]);
		dpch_free(args->envpaths);
		printf("1\n");
		dpch_free(args->cmd);
		printf("2\n");
		pipe_free(args->pipefd);
		printf("3\n");
	}
	else if (flag == 4)
	{
		dpch_free(args->envpaths);
		dpch_free(args->cmd);
		pipe_free(args->pipefd);
		dpch_free(args->full_namecmd);	
	}
	perror("");
	exit (1);
	return (0);
}

int	close_child_pipe(t_data *args)
{
	int	i;

	i = 0;
	while (i < args->pipe_total)
	{
		close(args->pipefd[i][0]);
		close(args->pipefd[i][1]);
		i++;
	}
	return (0);
}