/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:04 by soohlee           #+#    #+#             */
/*   Updated: 2023/02/27 19:01:05 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **argv, int **a_stack)
{
	if (argc < 2)
		exit(1);
	str_parsing(argc, argv, a_stack);
	a_stack = 0;
	argv = 0;
	return (0);
}

int	str_parsing(int argc, char **argv, int **a_stack)
{
	int				i;
	int				j;

	argc = 0;
	a_stack = 0;
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			chk_digit(argv, i, j);
		if (ft_strchr(argv[i], ' '))
			split_stack_add(argv[i], a_stack);
		else
			stack_add(argv[i], a_stack);
	}
	return (0);
}
