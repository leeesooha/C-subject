/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:37:14 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/09 15:01:34 by soohlee          ###   ########.fr       */
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

void	indexing(int **num_array, long long len)
{
	long long	i;
	long long	j;
	int			hash[100000];
	int			*temp_arr;

	temp_arr = (int *)malloc(sizeof(int) * len);
	chk_malloc(temp_arr);
	i = -1;
	while (++i < len)
		temp_arr[i] = num_array[0][i];
	ft_sort_int_tab(temp_arr, len);
	i = -1;
	while (++i < len)
		hash[i] = temp_arr[i];
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (hash[j] == num_array[0][i])
				num_array[0][i] = j;
		}
	}
	free(temp_arr);
}
