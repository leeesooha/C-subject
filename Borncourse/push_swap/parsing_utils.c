/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:37:14 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/03 12:47:03 by soohlee          ###   ########.fr       */
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
		if (!ft_strncmp(str_stack[i], "-", 2) || !ft_strncmp(str_stack[i], "+", 2))
			error_print();
		i++;
	}
	return (0);
}
