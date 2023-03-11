/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:42:21 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/11 18:04:15 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	one_path_cnt(t_list **a_stack, t_list **b_stack, int num)
{
	t_list	*temtack;
	int		rbrrb_cnt;
	int		rarra_cnt;

	rbrrb_cnt = 0;
	temtack = (*b_stack);
	while (*(int *)temtack->content != num)
	{
		temtack = temtack->next;
		rbrrb_cnt++;
	}
	if (ft_lstsize(*b_stack) / 2 < rbrrb_cnt)
		rbrrb_cnt = (ft_lstsize(*b_stack) - rbrrb_cnt) * -1;
	ft_rarra_cnt(a_stack, num, &rarra_cnt);
	if (rbrrb_cnt > 0 && rarra_cnt > 0 && rbrrb_cnt >= rarra_cnt)
		return (rbrrb_cnt);
	else if (rbrrb_cnt > 0 && rarra_cnt > 0 && rbrrb_cnt < rarra_cnt)
		return (rarra_cnt);
	else if (rbrrb_cnt < 0 && rarra_cnt < 0 && rbrrb_cnt <= rarra_cnt)
		return (rbrrb_cnt * 1);
	else if (rbrrb_cnt < 0 && rarra_cnt < 0 && rbrrb_cnt > rarra_cnt)
		return (rarra_cnt * 1);
	if (rbrrb_cnt < 0)
		return ((rbrrb_cnt * 1) + rarra_cnt);
	return ((rarra_cnt * 1) + rbrrb_cnt);
}

int	ft_rarra_cnt(t_list **a_stack, int num, int *rarra_cnt)
{
	t_list	*temtack;

	*rarra_cnt = 0;
	temtack = (*a_stack);
	if (!(is_sort(temtack)))
	{
		if (num < *(int *)temtack->content)	//pa할 값이 최상단인 케이스
			return (0);
		else
		{
			sort_case(a_stack, num, rarra_cnt);	//정렬된 케이스
		}	
	}
//	else min과 max가 중간에 붙어 있는경우 (정렬은 순환구조로 되어있는상태)
}

int	sort_case(t_list **a_stack, int num, int *rarra_cnt)
{
	
	return (0);
}

//--------할일------------
//세가지 케이스 제작해야함.

//다하면 최선원소 받은걸로 정렬.
