/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:04:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/11 13:34:08 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	if (ft_lstsize(*a_stack) <= 3)
		return (hard_coding(a_stack, cmd));
	allpb_tpvt(a_stack, b_stack, cmd);
	bps(a_stack, b_stack, cmd, (ft_lstsize(*a_stack) + ft_lstsize(*b_stack)));
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
			if (*((int *)((*b_stack)->content)) < pivot_one
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


int	bps(t_list **a_stack, t_list **b_stack, t_list **cmd, int stack_total_len)
{
	int	pivot_one;
	int	pivot_two;

	pivot_one = stack_total_len / 3;
	pivot_two = pivot_one * 2;
	greedy(a_stack, b_stack, cmd, pivot_two);
	greedy(a_stack, b_stack, cmd, pivot_one);
	greedy(a_stack, b_stack, cmd, 0);
	return (0);
}




/*
BPS
{
	while (pivot2끝날때까지)
	그리디(최단경로 원소 pa수행후 cmd스택쌓기)
	while (pivot1< 원소들 >pivot2끝날때까지)
	그리디(최단경로 원소 pa수행후 cmd스택쌓기)
	while (원소빌때까지)
	그리디(최단경로 원소 pa수행후 cmd스택쌓기)
}
*/
// 1 4 0 3 2			a: -	b: 3 4 2 1 0
//						a: 3	b: 4 2 1 0
// 0 1 2 3 4