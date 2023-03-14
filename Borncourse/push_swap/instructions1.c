/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:37:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/14 18:08:48 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_list **a_stack)
{
	int		*temp_num;
	t_list	*next_stack;

	if (ft_lstsize(*a_stack) <= 1)
		return (0);
	next_stack = (*a_stack)->next;
	temp_num = next_stack->content;
	next_stack->content = (*a_stack)->content;
	(*a_stack)->content = temp_num;
	return ("sa");
}

char	*sb(t_list **b_stack)
{
	int		*temp_num;
	t_list	*next_stack;

	if (ft_lstsize(*b_stack) <= 1)
		return (0);
	next_stack = (*b_stack)->next;
	temp_num = next_stack->content;
	next_stack->content = (*b_stack)->content;
	(*b_stack)->content = temp_num;
	return ("sb");
}

char	*ss(t_list **a_stack, t_list **b_stack)
{
	int		*temp_num;
	t_list	*next_stack;

	if (ft_lstsize(*a_stack) <= 1 || ft_lstsize(*b_stack) <= 1)
		return (0);
	next_stack = (*a_stack)->next;
	temp_num = next_stack->content;
	next_stack->content = (*a_stack)->content;
	(*a_stack)->content = temp_num;
	next_stack = (*b_stack)->next;
	temp_num = next_stack->content;
	next_stack->content = (*b_stack)->content;
	(*b_stack)->content = temp_num;
	return ("ss");
}

char	*pa(t_list **a_stack, t_list **b_stack)
{
	t_list	*second_b_stack;

	if (ft_lstsize(*b_stack) == 0)
		return (0);
	second_b_stack = (*b_stack)->next;
	ft_lstadd_front(a_stack, *b_stack);
	*b_stack = second_b_stack;
	return ("pa");
}

char	*pb(t_list **a_stack, t_list **b_stack)
{
	t_list	*second_a_stack;

	if (ft_lstsize(*a_stack) == 0)
		return (0);
	second_a_stack = (*a_stack)->next;
	ft_lstadd_front(b_stack, *a_stack);
	*a_stack = second_a_stack;
	return ("pb");
}
