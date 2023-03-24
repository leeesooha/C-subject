/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:37:36 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/24 21:00:25 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	creat_pipe(t_data *args)
{
	int	i;

	args->pipe_total = args->cmd_total + 1;
	args->pipefd = (int **)ft_calloc(sizeof(int *), (args->pipe_total + 1));
	if (!args->pipefd)
		all_free(args, 2);
	i = 0;
	while (args->pipe_total > i)
	{
		(args->pipefd)[i] = (int *)ft_calloc(sizeof(int), 2);
		if (!(args->pipefd)[i])
			all_free(args, 3);
		if (pipe(args->pipefd[i]) == -1)
			all_free(args, 3);
		i++;
	}
	return (0);
}

int	creat_cmd(t_data *args)
{
	int		i;

	args->cmd_total = args->argc - 3;
	args->cmd = (char **)ft_calloc(sizeof(char *), (args->cmd_total) * 2);
	if (!args->cmd)
		all_free(args, 1);
	i = 0;
	while (args->cmd_total > i)
	{
		args->cmd[i * 2] = ft_strdup(args->argv[i + 2]);
		if (!args->cmd[i * 2])
			all_free(args, 2);
		i++;
	}
	args->full_namecmd = (char **)ft_calloc(sizeof(char *), (args->cmd_total) + 1);
	if (!args->full_namecmd)
		all_free(args, 2);
	return (0);	
}

int	creat_envp(t_data *args, int argc, char **argv, char **envp)
{
	int		i;

	args->argc = argc;
	args->argv = argv;
	args->envp = envp;
	i = 0;
	while (args->envp[i])
	{
		if (ft_strncmp(args->envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	args->envpaths = ft_split(&(args->envp[i][5]), ':');
	if (!args->envpaths)
		all_free(args, 1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	args;
	int		i;

	creat_envp(&args, argc, argv, envp);
	creat_cmd(&args);
	creat_pipe(&args);
	i = 0;
	while (args.pipe_total > i)
	{
		args.pipenum = i;
		child(&args, 0);
		i++;
	}
	waitpid(-1, 0, 0);
	return (0);
}
