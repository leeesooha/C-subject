/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:39:34 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/08 21:32:16 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	hard_coding(t_list **a_stack, t_list **cmd, int **arr)
{
	int	*a;

	a = *arr;
	if (!is_sort(*a_stack))
		return (0);
	else if (ft_lstsize(*a_stack) == 2)
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup("sa")));
		return (0);
	}
	else
	{
		if (a[0])
			return (0);
	}
	return (0);
}
/*
1 2 3

1 3 2

2 1 3

2 3 1

3 1 2

3 2 1
*/