/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:37:36 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/21 14:39:31 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
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