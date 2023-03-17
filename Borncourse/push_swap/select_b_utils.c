/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_b_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:42:21 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/17 11:18:59 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	path_cnt(t_list **a_stack, t_list **b_stack, int num, int *best_case)
{
	t_list	*temtack;
	int		rb_cnt;
	int		ra_cnt;
	int		rrb_cnt;
	int		rra_cnt;

	rb_cnt = 0;
	rrb_cnt = 0;
	temtack = (*b_stack);
	while (*(int *)temtack->content != num)
	{
		temtack = temtack->next;
		rb_cnt++;
	}
	rrb_cnt = (ft_lstsize(*b_stack) - rb_cnt);
	if (ft_lstsize(*b_stack) == 1)
		rrb_cnt = 0;
	rarra_cnt(a_stack, num, &ra_cnt, &rra_cnt);
	best_case[2] = ra_cnt;
	best_case[3] = rb_cnt;
	best_case[4] = rra_cnt;
	best_case[5] = rrb_cnt;
	best_case[1] = case_choice(&ra_cnt, &rra_cnt, &rb_cnt, &rrb_cnt);
	return (bpath(&ra_cnt, &rra_cnt, &rb_cnt, &rrb_cnt));
}

int	rarra_cnt(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt)
{
	t_list	*temtack;

	*ra_cnt = 0;
	*rra_cnt = 0;
	temtack = (*a_stack);
	if (!(is_sort(a_stack)))
	{
		if (num < *(int *)temtack->content
			&& num > *(int *)(ft_lstlast(temtack)->content))
		{
			*rra_cnt = ft_lstsize(temtack);
			return (0);
		}
		else
			return (sort_case(a_stack, num, ra_cnt, rra_cnt));
	}
	else
		return (circule_sort_case(a_stack, num, ra_cnt, rra_cnt));
	return (0);
}

int	bpath(int *ra_cnt, int *rra_cnt, int *rb_cnt, int *rrb_cnt)
{
	int	best_min;
	int	i;
	int	cnt_case[4];

	if (*ra_cnt >= *rb_cnt)
		cnt_case[0] = *ra_cnt;
	else if (*ra_cnt < *rb_cnt)
		cnt_case[0] = *rb_cnt;
	if (*rra_cnt >= *rrb_cnt)
		cnt_case[1] = *rra_cnt;
	else if (*rra_cnt < *rrb_cnt)
		cnt_case[1] = *rrb_cnt;
	cnt_case[2] = *ra_cnt + *rrb_cnt;
	cnt_case[3] = *rb_cnt + *rra_cnt;
	best_min = cnt_case[0];
	i = 4;
	while (i--)
	{
		if (best_min >= cnt_case[i])
			best_min = cnt_case[i];
	}
	return (best_min);
}

int	case_choice(int *ra_cnt, int *rra_cnt, int *rb_cnt, int *rrb_cnt)
{
	int	best_min[2];
	int	i;
	int	cnt_case[4];

	if (*ra_cnt >= *rb_cnt)
		cnt_case[0] = *ra_cnt;
	else if (*ra_cnt < *rb_cnt)
		cnt_case[0] = *rb_cnt;
	if (*rra_cnt >= *rrb_cnt)
		cnt_case[1] = *rra_cnt;
	else if (*rra_cnt < *rrb_cnt)
		cnt_case[1] = *rrb_cnt;
	cnt_case[2] = *ra_cnt + *rrb_cnt;
	cnt_case[3] = *rb_cnt + *rra_cnt;
	best_min[0] = cnt_case[0];
	i = 4;
	while (i--)
	{
		if (best_min[0] >= cnt_case[i])
		{
			best_min[0] = cnt_case[i];
			best_min[1] = i;
		}
	}
	return (best_min[1]);
}

t_list	*find_pivot(t_list **b_stack)
{
	t_list	*temtack;

	temtack = *b_stack;
	while (temtack)
	{
		if (*((int *)temtack->content))
			return (temtack->content);
		temtack = temtack->next;
	}
	return (0);
}
