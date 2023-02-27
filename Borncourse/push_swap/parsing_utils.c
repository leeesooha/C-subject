/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:37:14 by soohlee           #+#    #+#             */
/*   Updated: 2023/02/27 20:56:20 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_digit(char **argv, int i, int j)
{
	if (!ft_isdigit(argv[i][j]) && (argv[i][j] != ' ')
			&& (argv[i][0] != '-' && argv[i][0] != '+'))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (0);
}

int	split_stack_add(char *argv, int **a_stack)
{
	char	**str_nums;
	int		i;

	str_nums = ft_split(argv, ' ');
	i = 0;
	while (str_nums[i])
	{
		
		i++;
	}
	return (0);
}
