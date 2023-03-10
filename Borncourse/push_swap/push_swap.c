/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:04:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/10 16:25:31 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd, int **arr)
{
	b_stack = 0;
	if (ft_lstsize(*a_stack) <= 3)
		return (hard_coding(a_stack, cmd, arr));
	allpb_tpvt(a_stack, b_stack, cmd);
//	greedy(a_stack, b_stack, cmd, arr);		//3분할로 stack_b에 다 넘긴 후 그리디
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
	while (a_stack_size)
	{
		printf("\n%d\n", *((int *)((*a_stack)->content)));
		if (*((int *)((*a_stack)->content)) < pivot_two)
		{	
			ft_lstadd_back(cmd, ft_lstnew(pb(a_stack, b_stack)));
			if (*((int *)((*b_stack)->content)) <= pivot_one)
			{
				printf("\nOK\n");
				ft_lstadd_back(cmd, ft_lstnew(rb(b_stack)));
				
			}
		}
		else
		{
			printf("\nOK\n");
			ft_lstadd_back(cmd, ft_lstnew(ra(a_stack)));
		}
		a_stack_size--;
	}
	while (*a_stack)
		ft_lstadd_back(cmd, ft_lstnew(pb(a_stack, b_stack)));
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