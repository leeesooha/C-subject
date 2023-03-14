/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:46:10 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/14 18:08:50 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *stack)
{
	int		*previous_num;

	if (ft_lstsize(stack) == 0 || ft_lstsize(stack) == 1)
		return (0);
	else
	{
		previous_num = (stack)->content;
		stack = stack->next;
		while ((stack))
		{
			if (*previous_num > *((int *)(stack->content)))
				return (1);
			previous_num = stack->content;
			stack = stack->next;
		}
	}
	return (0);
}
