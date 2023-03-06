/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:04 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/06 16:08:52 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **argv, int **num_array)
{
	char	*str_oneline;

	str_oneline = ft_strdup("");
	if (argc < 2 || !str_oneline)
		exit(1);
	argv_merge(argv, &str_oneline);
	make_stack(ft_split(str_oneline, ' '), num_array);
	free(str_oneline);
	num_array = 0;
	argv = 0;
	return (0);
}

int	argv_merge(char **argv, char **str_oneline)
{
	int		i;
	char	*free_space;

	i = 0;
	while (argv[++i])
	{
		if (i != 1)
		{
			free_space = *str_oneline;
			*str_oneline = ft_strjoin(*str_oneline, " ");
			free(free_space);
			chk_malloc(*str_oneline);
		}
		free_space = *str_oneline;
		*str_oneline = ft_strjoin(*str_oneline, argv[i]);
		free(free_space);
		chk_malloc(*str_oneline);
	}
	return (0);
}

int	make_stack(char **str_double, int **num_array)
{
	size_t	i;
	size_t	j;

	chk_digit(str_double);
	i = 0;
	while (str_double[i])
		i++;
	*num_array = (int *)malloc(sizeof(int) * i + 1);
	chk_malloc(*num_array);
	i = 0;
	while (str_double[i])
	{
		(*num_array)[i] = ft_atoi_no_overflow(str_double[i]);
		j = 0;
		while (j < i)
		{
			if ((*num_array)[i] == (*num_array)[j])
				error_print();
			j++;
		}
		i++;
	}
	free_double_pointer(str_double);
	return (0);
}

void	error_print(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

void	chk_malloc(void *s)
{
	if (s == 0)
		exit (1);
}
