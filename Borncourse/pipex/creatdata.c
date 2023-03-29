/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:41:35 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/29 21:10:47 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	creat_envp(t_data *data, int argc, char **argv, char **envp)
{
	int		i;

	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	heredoc_chk(data);
	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	data->envpaths = ft_split(&(data->envp[i][5]), ':');
	if (!data->envpaths)
		all_free(data, 0, 0, 1);
	return (0);
}

int	creat_cmd(t_data *data)
{
	int		i;

	data->ncmd = data->argc - 3 - data->hdflag;
	data->cmd = (char **)malloc(sizeof(char *) * (data->ncmd + 1));
	if (!data->cmd)
		all_free(data, 1, 0, 1);
	i = 0;
	while (i < data->ncmd)
	{
		data->cmd[i] = ft_strdup(data->argv[i + 2 + data->hdflag]);
		if (!data->cmd[i])
			all_free(data, 2, 0, 1);
		i++;
	}
	data->cmd[i] = 0;
	return (0);
}

int	creat_pipe(t_data *data)
{
	int	i;

	data->npipe = data->ncmd - 1;
	data->pipefd = (int **)malloc(sizeof(int *) * (data->npipe + 1));
	if (!data->pipefd)
		all_free(data, 2, 0, 1);
	i = 0;
	while (i < data->npipe)
	{
		(data->pipefd)[i] = (int *)malloc(sizeof(int) * 2);
		if (!(data->pipefd)[i])
			all_free(data, 3, 0, 1);
		if (pipe(data->pipefd[i]) == -1)
			all_free(data, 3, 0, 1);
		i++;
	}
	data->pipefd[i] = 0;
	return (0);
}

int	file_check(t_data *data)
{
	if (data->hdflag == 0)
	{
		data->infilefd = open(data->argv[1], O_RDONLY);
		if (data->infilefd == -1)
			perror(data->argv[1]);
		data->outfilefd = open(data->argv[data->argc - 1],
				O_CREAT | O_RDWR | O_TRUNC, 0000644);
		if (data->outfilefd < 0)
			all_free(data, 3, 0, 2);
	}
	else
	{
		heredoc(data);
		data->infilefd = open("here_doc_tmp", O_RDONLY);
		if (data->infilefd == -1)
			perror("");
		data->outfilefd = open(data->argv[data->argc - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0666);
		if (data->outfilefd == -1)
			all_free(data, 3, 0, 2);
	}
	return (0);
}
