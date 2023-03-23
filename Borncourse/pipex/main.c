/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:37:36 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/23 18:45:52 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	creat_pipe(t_data *args, int argc)
{
	int	i;

	args->argc = argc;
	args->pipecnt = args->argc - 2;
	i = 0;
	args->pipe = (int **)ft_calloc(sizeof(int *), (args->pipecnt + 1));
	if (!args->pipe)
		exit (1);
	while (args->argc - 2 > i)
	{
		(args->pipe)[i] = ft_calloc(sizeof(int), 2);
		if (!(args->pipe)[i])
			all_free(args, 1);
		if (pipe(args->pipe[i]) == -1)
			all_free(args, 1);
		i++;
	}
	return (0);
}

int	creat_cmd(t_data *args, char **argv)
{
	int		i;
	char	*temp;

	args->argv = argv;
	i = 0;
	args->cmd = ft_split(args->argv[2], "|");
	if (!args->cmd)
		all_free(args, 2);
	while (args->cmd[i])
	{
		temp = args->cmd[i];
		args->cmd[i] = ft_strtrim(args->cmd[i], " ");
		if (!args->cmd[i])
			all_free(args, 2);
		free(temp);
		i++;
	}
	return (0);
}

int	creat_envp(t_data *args, char **envp)
{
	int		i;
	char	*temp;

	args->envp = envp;
	i = 0;
	while (args->envp[i])
	{
		if (ft_strncmp(args->envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (args->envp[i] == 0)
		all_free(args, 2);
	args->envppath = ft_split(args->envp[i] + 5, ":");
	if (!args->envppath)
		all_free(args, 2);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	args;
	int		i;

	i = 0;
	creat_pipe(&args, argc);
	creat_cmd(&args, argv);
	creat_envp(&args, envp);
	while (args.pipecnt > i)
	{
		args.pipenum = i;
		child(&args);
		i++;
	}
	return (0);
}

/*
#include "pipex.h"

int	main(int argc, char **argv)
{
	ft_printf("%s", argv[1]);
	if (argc < 3)
	{
		ft_printf("one");
		return (0);
	}
	else
		ft_printf("over_one");
	if (argv)
		return (0);
	return (0);
}
*/