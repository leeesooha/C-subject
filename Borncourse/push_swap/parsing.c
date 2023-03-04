/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:04 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/04 18:15:42 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **argv, int **a_stack)
{
	char	*str_stack_oneline;

	str_stack_oneline = ft_strdup("");
	if (argc < 2 || !str_stack_oneline)
		exit(1);
	argv_merge(argv, &str_stack_oneline);
	make_stack(ft_split(str_stack_oneline, ' '), a_stack);
	free(str_stack_oneline);
	a_stack = 0;
	argv = 0;
	return (0);
}

int	argv_merge(char **argv, char **str_stack_oneline)
{
	int		i;
	char	*free_space;

	i = 0;
	while (argv[++i])
	{
		if (i != 1)
		{
			free_space = *str_stack_oneline;
			*str_stack_oneline = ft_strjoin(*str_stack_oneline, " ");
			free(free_space);
			chk_malloc(*str_stack_oneline);
		}
		free_space = *str_stack_oneline;
		*str_stack_oneline = ft_strjoin(*str_stack_oneline, argv[i]);
		free(free_space);
		chk_malloc(*str_stack_oneline);
	}
	return (0);
}

int	make_stack(char **str_stack, int **a_stack)
{
	size_t	i;
	size_t	j;

	chk_digit(str_stack);
	i = 0;
	while (str_stack[i])
		i++;
	*a_stack = (int *)malloc(sizeof(int) * i + 1);
	chk_malloc(*a_stack);
	i = 0;
	while (str_stack[i])
	{
		(*a_stack)[i] = ft_atoi_no_overflow(str_stack[i]);
		j = 0;
		while (j < i)
		{
			if ((*a_stack)[i] == (*a_stack)[j])
				error_print();
			j++;
		}
		i++;
	}
	free_double_pointer(str_stack);
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
