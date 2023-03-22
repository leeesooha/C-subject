/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:37:36 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/22 22:44:18 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int	infile;
	
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		ft_printf("%s", argv[1]);
		ft_printf("zsh: %s ", strerror(errno));
	}
	if (access(argv[1], X_OK) == -1)
	{
		ft_printf("%s", strerror(errno));
		ft_printf("%s", argv[1]);
	}
	if (argc && envp)
		return (0);
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