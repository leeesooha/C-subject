/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:04:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/08 21:31:51 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd, int **arr)
{
	b_stack = 0;
	if (ft_lstsize(*a_stack) <= 3)
		return (hard_coding(a_stack, cmd, arr));
	return (0);
}
