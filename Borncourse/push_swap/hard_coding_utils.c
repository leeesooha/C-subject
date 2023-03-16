/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:39:34 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/16 10:50:03 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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