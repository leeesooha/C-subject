/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rarra_cnt_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:44:39 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/14 11:23:21 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_case(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt)
{
	t_list	*temtack;

	temtack = *a_stack;
	(*(ra_cnt))++;
	while (temtack->next && !(*((int *)temtack->content) < num
			&& num < *((int *)(temtack->next)->content)))
	{
		(*(ra_cnt))++;
		temtack = temtack->next;
	}
	*rra_cnt = (ft_lstsize(*a_stack) - *ra_cnt);
	return (0);
}

int	circule_sort_case(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt)
{
	t_list	*temtack;

	temtack = *a_stack;
	(*(ra_cnt))++;
	while (temtack->next || !(*((int *)temtack->content) > num
			&& num < *((int *)(temtack->next)->content)))
	{
		(*(ra_cnt))++;
		temtack = temtack->next;
	}
	*rra_cnt = (ft_lstsize(*a_stack) - *ra_cnt);
	return (0);
}