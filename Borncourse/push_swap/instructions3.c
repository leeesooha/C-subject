/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:51:31 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/14 12:48:47 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rr(t_list **a_stack, t_list **b_stack)
{
	t_list	*first_stack;
	t_list	*second_stack;

	if (ft_lstsize(*a_stack) <= 1 || ft_lstsize(*b_stack) <= 1)
		return (0);
	first_stack = *a_stack;
	second_stack = (*a_stack)->next;
	ft_lstadd_back(a_stack, first_stack);
	first_stack->next = 0;
	*a_stack = second_stack;
	first_stack = *b_stack;
	second_stack = (*b_stack)->next;
	ft_lstadd_back(b_stack, first_stack);
	first_stack->next = 0;
	*b_stack = second_stack;
	return ("rr");
}
