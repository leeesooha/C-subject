/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:14:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/23 18:24:28 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_free(int **pipe)
{
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
	while (*s)
	{
		free(*s);
		(*s)++;
	}
	free(s);
	return (0);
}

int	all_free(t_data *args, int flag)
{
	if (flag == 1)
	{
		pipe_free(args->pipe);
		perror("");
		exit(1);
	}
	else if (flag == 2)
	{
		pipe_free(args->pipe);
		dpch_free(args->cmd);
		perror("");
		exit(1);
	}
	else if (flag == 3)
	{
		pipe_free(args->pipe);
		dpch_free(args->cmd);
		dpch_free(args->envp);
		perror("");
		exit(1);
	}
	return (0);
}
