/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:39:34 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/13 21:07:09 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hard_coding(t_list **a_stack, t_list **cmd)
{
	int		a[3];
	t_list	*temp_stack;
	int		i;

	if (!is_sort(*a_stack))
		return (0);
	else if (ft_lstsize(*a_stack) == 2)
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(sa(a_stack))));
		return (0);
	}
	else if (ft_lstsize(*a_stack) == 3)
	{
		temp_stack = *a_stack;
		i = 0;
		while (temp_stack)
		{
			a[i++] = *((int *)temp_stack->content);
			temp_stack = temp_stack->next;
		}
		hard_case(a_stack, a, cmd);
	}
	return (0);
}

int	hard_case(t_list **a_stack, int *a, t_list **cmd)
{
	if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rra(a_stack))));
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(sa(a_stack))));
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(sa(a_stack))));
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rra(a_stack))));
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(ra(a_stack))));
	else if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
	{
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(sa(a_stack))));
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rra(a_stack))));
	}
	return (0);
}

/*
0 1 2

0 < 2 > 1	< //rra,sa

1 > 0 < 2	< //sa

1 < 2 > 0	> //rra

2 > 0 < 1	> //ra

2 > 1 > 0	> //sa,rra
*/