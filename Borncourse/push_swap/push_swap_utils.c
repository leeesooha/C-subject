/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:04:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/16 11:14:58 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hard_coding(t_list **a_stack, t_list **cmd)
{
	int		a[3];
	t_list	*temp_stack;
	int		i;

	if (!is_sort(a_stack))
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

int	allpb(t_list **a_stack, t_list **b_stack, t_list **cmd)
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

int	allpa(t_list **a_stack, t_list **b_stack, t_list **cmd, int total_len)
{
	greedy(a_stack, b_stack, cmd);
	zero_to_top(a_stack, cmd, total_len);
	return (0);
}

int	greedy(t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	int	best_case[11];

	while (ft_lstsize(*b_stack))
	{
		best_case[0] = select_b(a_stack, b_stack, best_case);
		move_pa(best_case, a_stack, b_stack, cmd);
	}
	return (0);
}