/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:42:21 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/14 11:31:54 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	one_path_cnt(t_list **a_stack, t_list **b_stack, int num, int *best_case)
{
	t_list	*temtack;
	int		rb_cnt;
	int		ra_cnt;
	int		rrb_cnt;
	int		rra_cnt;

	rb_cnt = 0;
	temtack = (*b_stack);
	while (*(int *)temtack->content != num)
	{
		temtack = temtack->next;
		rb_cnt++;
	}
	rrb_cnt = (ft_lstsize(*b_stack) - rb_cnt);
	ft_rarra_cnt(a_stack, num, &ra_cnt, &rra_cnt);
	printf("\n안영\n");
	best_case[2] = ra_cnt;
	best_case[3] = rb_cnt;
	best_case[4] = rra_cnt;
	best_case[5] = rrb_cnt;
	best_case[1] = case_choice(&ra_cnt, &rra_cnt, &rb_cnt, &rrb_cnt);
	return (bpath(&ra_cnt, &rra_cnt, &rb_cnt, &rrb_cnt));
}

int	ft_rarra_cnt(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt)
{
	t_list	*temtack;

	*ra_cnt = 0;
	*rra_cnt = 0;
	temtack = (*a_stack);
	if (!(is_sort(temtack)))
	{
		if (num > *(int *)temtack->content)	//pa할 값이 최상단인 케이스
			return (0);
		else
		{
			return (sort_case(a_stack, num, ra_cnt, rra_cnt));	//정렬된 케이스
		}
	}
	else
	{
		printf("\n호호호\n");
		return (circule_sort_case(a_stack, num, ra_cnt, rra_cnt));		//순환구조정렬상태
	}
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

//--------할일------------
//세가지 케이스 제작해야함.

//다하면 최선원소 받은걸로 정렬.
/*
	if (rbrrb_cnt > 0 && rarra_cnt > 0 && rbrrb_cnt >= rarra_cnt)
		best_path = rbrrb_cnt;
	else if (rbrrb_cnt > 0 && rarra_cnt > 0 && rbrrb_cnt < rarra_cnt)
		best_path = rarra_cnt;
	else if (rbrrb_cnt < 0 && rarra_cnt < 0 && rbrrb_cnt <= rarra_cnt)
		return (rbrrb_cnt * 1);
	else if (rbrrb_cnt < 0 && rarra_cnt < 0 && rbrrb_cnt > rarra_cnt)
		return (rarra_cnt * 1);
	if (rbrrb_cnt < 0)
		return ((rbrrb_cnt * 1) + rarra_cnt);
	return ((rarra_cnt * 1) + rbrrb_cnt);
*/