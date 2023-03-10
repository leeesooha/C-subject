/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:04:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/10 21:44:52 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	if (ft_lstsize(*a_stack) <= 3)
		return (hard_coding(a_stack, cmd));
	allpb_tpvt(a_stack, b_stack, cmd);
//a스택에 가장큰그룹원소3개 남기고 b스택에 3분할해서 다 넘겼음.
//	greedy(a_stack, b_stack, cmd, arr);
	return (0);
}

int	allpb_tpvt(t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	int	pivot_one;
	int	pivot_two;
	int	a_stack_size;

	a_stack_size = ft_lstsize(*a_stack);
	pivot_one = a_stack_size / 3;
	pivot_two = pivot_one * 2;
	while (a_stack_size && ft_lstsize(*a_stack) > 3)
	{
		if (*((int *)((*a_stack)->content)) < pivot_two)
		{	
			ft_lstadd_back(cmd, ft_lstnew(ft_strdup(pb(a_stack, b_stack))));
			if (*((int *)((*b_stack)->content)) <= pivot_one
				&& (*b_stack)->next)
				ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rb(b_stack))));
		}
		else
			ft_lstadd_back(cmd, ft_lstnew(ft_strdup(ra(a_stack))));
		a_stack_size--;
	}
	while (*a_stack && ft_lstsize(*a_stack) > 3)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(pb(a_stack, b_stack))));
	hard_coding(a_stack, cmd);
	return (0);
}

/*
int	greedy(t_list **a_stack, t_list **b_stack, t_list **cmd, int **arr)
{
	return (0);
}
*/
// 1 4 0 3 2			a: -	b: 3 4 2 1 0
//						a: 3	b: 4 2 1 0
// 0 1 2 3 4