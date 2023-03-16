/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:04 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/16 18:18:58 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_merge(char **argv, char **str_oneline)
{
	int		i;
	char	*free_temp;

	i = 0;
	while (argv[++i])
	{
		if (i != 1)
		{
			free_temp = *str_oneline;
			*str_oneline = ft_strjoin(*str_oneline, " ");
			chk_malloc(*str_oneline);
			free(free_temp);
		}
		free_temp = *str_oneline;
		*str_oneline = ft_strjoin(*str_oneline, argv[i]);
		chk_malloc(*str_oneline);
		free(free_temp);
	}
	return (0);
}

long	make_array(char **str_double, int **num_array)
{
	long long	i;
	long long	j;

	if (!str_double)
		exit (1);
	chk_digit(str_double);
	i = 0;
	while (str_double[i])
		i++;
	*num_array = (int *)malloc(sizeof(int) * i + 1);
	chk_malloc(*num_array);
	i = -1;
	while (str_double[++i])
	{
		(*num_array)[i] = ft_atoi_no_overflow(str_double[i]);
		j = 0;
		while (j < i)
		{
			if ((*num_array)[i] == (*num_array)[j])
				error_print();
			j++;
		}
	}
	free_double_pointer(str_double);
	return (i);
}

void	error_print(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	chk_malloc(void *s)
{
	if (s == 0)
		exit (1);
}
