/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:04:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/09 19:54:35 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd, int **arr)
{
	b_stack = 0;
	if (ft_lstsize(*a_stack) <= 3)
		return (hard_coding(a_stack, cmd, arr));
	partition_pb(a_stack, b_stack, cmd, arr);	//3분할로 stack_b에 다 넘겨야함.
	greedy(a_stack, b_stack, cmd, arr);		//3분할로 stack_b에 다 넘긴 후 그리디
	return (0);
}

int	greedy(t_list **a_stack, t_list **b_stack, t_list **cmd, int **arr)
{
	return (0);
}

// 1 4 0 3 2			a: -	b: 3 4 2 1 0
//						a: 3	b: 4 2 1 0
// 0 1 2 3 4