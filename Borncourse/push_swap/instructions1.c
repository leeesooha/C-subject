/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:37:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/07 20:58:39 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **a_stack)
{
	int		*temp_num;
	t_list	*next_stack;

	next_stack = (*a_stack)->next;
	temp_num = next_stack->content;
	next_stack->content = (*a_stack)->content;
	(*a_stack)->content = temp_num;
	return (0);
}
