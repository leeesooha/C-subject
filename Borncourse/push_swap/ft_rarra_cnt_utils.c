/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rarra_cnt_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:44:39 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/15 13:26:52 by soohlee          ###   ########.fr       */
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
	if (find_min(a_stack) > num)
	{
		while (temtack)
		{
			if (*((int *)temtack->content) == find_min(a_stack))
			{
				*rra_cnt = ft_lstsize(*a_stack) - *ra_cnt;
				return (0);
			}
			temtack = temtack->next;
			*ra_cnt++;
		}
	}
	circule_ra_find(a_stack, num, *ra_cnt, *rra_cnt);
	return (0);
}

int	circule_ra_find(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt)
{
	t_list	*temtack;
	int		index;
	int		max;

	index = 0;
	temtack = *a_stack;
	max = find_min(a_stack);
	while (temtack)
	{
		if (*((int *)temtack->content) > max
			&& *((int*)temtack->content) < num)
			max = *((int *)temtack->content);
		temtack = temtack->next;
		index++;
	}
	temtack = *a_stack;
	index = 0;
	while (temtack && *((int *)temtack->content) == max)
	{
		index++;
		temtack = temtack->next;
	}
	*ra_cnt = index + 1;
	*rra_cnt = ft_lstsize(*a_stack) - *ra_cnt;
	return (0);
}

int	find_min(t_list **a_stack)
{
	t_list	*temtack;
	int		index;
	int		min;

	min = 0;
	index = 0;
	temtack = *a_stack;
	min = *((int *)temtack->content);
	while (temtack)
	{
		if (*((int *)temtack->content) < min && index != 0)
			min = *((int *)temtack->content);
		temtack->next;
		index++;
	}
	return (min);
}
