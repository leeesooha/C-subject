/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:46:10 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/15 18:52:15 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*is_sort(t_list **stack)
{
	int		*previous_num;
	t_list	*temtack;

	temtack = *stack;
	if (ft_lstsize(temtack) == 0 || ft_lstsize(temtack) == 1)
		return (0);
	else
	{
		previous_num = (temtack)->content;
		temtack = temtack->next;
		while ((temtack))
		{
			if (*previous_num > *((int *)(temtack->content)))
				return ((int *)(temtack->content));
			previous_num = temtack->content;
			temtack = temtack->next;
		}
	}
	return (0);
}
