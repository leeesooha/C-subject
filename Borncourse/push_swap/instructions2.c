/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:39:26 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/08 14:49:21 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **a_stack)
{
	t_list	*last_stack;
	t_list	*before_last_stack;

	if (ft_lstsize(*a_stack) <= 1)
		return (0);
	before_last_stack = *a_stack;
	while ((before_last_stack->next)->next)
		before_last_stack = before_last_stack->next;
	last_stack = ft_lstlast(*a_stack);
	ft_lstadd_front(a_stack, last_stack);
	before_last_stack->next = 0;
	return (0);
}

int	rrb(t_list **b_stack)
{
	t_list	*last_stack;
	t_list	*before_last_stack;

	if (ft_lstsize(*b_stack) <= 1)
		return (0);
	before_last_stack = *b_stack;
	while ((before_last_stack->next)->next)
		before_last_stack = before_last_stack->next;
	last_stack = ft_lstlast(*b_stack);
	ft_lstadd_front(b_stack, last_stack);
	before_last_stack->next = 0;
	return (0);
}

int	rrr(t_list **a_stack, t_list **b_stack)
{
	t_list	*last_stack;
	t_list	*before_last_stack;

	if (ft_lstsize(*a_stack) <= 1 || ft_lstsize(*b_stack) <= 1)
		return (0);
	before_last_stack = *a_stack;
	while ((before_last_stack->next)->next)
		before_last_stack = before_last_stack->next;
	last_stack = ft_lstlast(*a_stack);
	ft_lstadd_front(a_stack, last_stack);
	before_last_stack->next = 0;
	before_last_stack = *b_stack;
	while ((before_last_stack->next)->next)
		before_last_stack = before_last_stack->next;
	last_stack = ft_lstlast(*b_stack);
	ft_lstadd_front(b_stack, last_stack);
	before_last_stack->next = 0;
	return (0);
}

int	ra(t_list **a_stack)
{
	t_list	*first_stack;
	t_list	*second_stack;

	if (ft_lstsize(*a_stack) <= 1)
		return (0);
	first_stack = *a_stack;
	second_stack = (*a_stack)->next;
	ft_lstadd_back(a_stack, first_stack);
	first_stack->next = 0;
	*a_stack = second_stack;
	return (0);
}

int	rb(t_list **b_stack)
{
	t_list	*first_stack;
	t_list	*second_stack;

	if (ft_lstsize(*b_stack) <= 1)
		return (0);
	first_stack = *b_stack;
	second_stack = (*b_stack)->next;
	ft_lstadd_back(b_stack, first_stack);
	first_stack->next = 0;
	*b_stack = second_stack;
	return (0);
}
