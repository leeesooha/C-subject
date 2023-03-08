/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:37:14 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/08 21:30:29 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_digit(char **str_stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str_stack[i])
	{
		j = 0;
		while (str_stack[i][j])
		{
			if (!ft_isdigit(str_stack[i][j]) && (str_stack[i][j] != ' ')
				&& (str_stack[i][0] != '-' && str_stack[i][0] != '+'))
				error_print();
			j++;
		}
		if (!ft_strncmp(str_stack[i], "-", 2)
			|| !ft_strncmp(str_stack[i], "+", 2))
			error_print();
		i++;
	}
	return (0);
}

int	free_double_pointer(char **s)
{
	char	**temp_space;

	temp_space = s;
	while (*s)
		free(*s++);
	free (temp_space);
	return (0);
}
/*
int	indexing(int **num_array, long long len)
{
	int	i;
	int	j;
	int	hash[100000];

	i = -1;
	while (++i < len)
		hash[i] = num_array[0][i];
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (hash[)
				num_array[0][i] = 
		}
	}
	return (0);
}
*/