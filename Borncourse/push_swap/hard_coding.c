/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:39:34 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/10 16:08:55 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if ((a[0] == 0 && a[1] == 2 && a[2] == 1)
		|| (a[0] == 2 && a[1] == 1 && a[2] == 0))
		two_case(a_stack, a, cmd);
	else
		one_case(a_stack, a, cmd);
	return (0);
}

int	two_case(t_list **a_stack, int *a, t_list **cmd)
{
	if (a[0] == 0 && a[1] == 2 && a[2] == 1)
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup("rra")));
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup("sa")));
		rra(a_stack);
		sa(a_stack);
	}
	else
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup("sa")));
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup("rra")));
		sa(a_stack);
		rra(a_stack);
	}
	return (0);
}

int	one_case(t_list **a_stack, int *a, t_list **cmd)
{
	if (a[0] == 1 && a[1] == 0 && a[2] == 2)
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup("sa")));
		sa(a_stack);
	}
	else if (a[0] == 1 && a[1] == 2 && a[2] == 0)
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup("rra")));
		rra(a_stack);
	}
	else if (a[0] == 2 && a[1] == 0 && a[2] == 1)
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup("ra")));
		ra(a_stack);
	}
	return (0);
}
/*
0 1 2

0 2 1	//rra,sa

1 0 2	//sa

1 2 0	//rra

2 0 1	//ra

2 1 0	//sa,rra
*/