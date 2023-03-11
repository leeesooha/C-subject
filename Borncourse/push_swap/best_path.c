/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:42:21 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/11 16:57:47 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	one_path_cnt(t_list **a_stack, t_list **b_stack, int num)
{
	t_list	*temtack;
	int		rbrrb_cnt;
	int		rarra_cnt;
	int		npostion;

	npostion = 0;
	temtack = (*b_stack);
	while (*(int *)temtack->content != num)
	{
		temtack = temtack->next;
		npostion++;
	}
	rbrrb_cnt = npostion;
	if (ft_lstsize(*b_stack) / 2 < npostion)
		rbrrb_cnt = (ft_lstsize(*b_stack) - npostion) * -1;
	ft_rarra_cnt(a_stack, num, &rarra_cnt);
	return (rbrrb_cnt + rarra_cnt);
}

int	ft_rarra_cnt(t_list **a_stack, int num, int *rarra_cnt)
{
	t_list	*temtack;
	int		npostion;

	npostion = 0;
	temtack = (*a_stack);
	if (!(is_sort(temtack)))
	{
		if (num < *(int *)temtack->content)	//pa할 값이 최상단인 케이스
			return (0);
		else
		{
			sort_case();	//정렬된 케이스
		}	
	}
	else //min과 max가 중간에 붙어 있는경우 (정렬은 순환구조로 되어있는상태)
		//
}

//--------할일------------
//세가지 케이스 제작해야함.

//다하면 최선원소 받은걸로 정렬.






/*	
	while (!(*(int *)temtack->content < num
			&& num < *((int *)(temtack->next)->content)))
	{
		temtack = temtack->next;
		npostion++;
	}
	rarra_cnt = npostion + 1;
	if (ft_lstsize(*a_stack) / 2 < npostion)
		rbrrb_cnt = (ft_lstsize(*a_stack) - npostion) * -1;
	return (0);
*/
}
