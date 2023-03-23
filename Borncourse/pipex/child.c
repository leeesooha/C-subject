/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:53:02 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/23 18:50:55 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(t_data *args)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (args->pipenum == 0)
		{
			get_infile((args->argv)[1], &args);
			cmd_excute(&args);
		}
	}
//	else
	return (0);
}

int	cmd_excute(t_data *args)
{
	int	i;

	i = 0;
	while (args->envppath[i])
	{
		ft_strjoin(args->envppath[i], args->cmd);
		i++;
	}
	return (0);
}

int	get_infile(char *filename, t_data *args)
{
	char	*buff;
	int		unusedfd;

	if (access(filename, R_OK) == -1)
		all_free(args, 3);
	args->infilefd = open(filename, O_RDONLY);
	if (!args->infilefd)
		all_free(args, 3);
	unusedfd = dup2((args->pipe)[0][1], 1);
	if (unusedfd == -1)
		all_free(args, 3);
	unusedfd = dup2(args->pipe[0][0], 0);
	if (unusedfd == -1)
		all_free(args, 3);
	while (buff)
	{
		buff = get_next_line(args->infilefd);
		ft_putstr_fd(buff, 1);
	}
	close(args->pipe[0][0]);
	close(args->pipe[0][1]);
	return (0);
}
