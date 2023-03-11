/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bps_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:56:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/11 15:59:50 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greedy(t_list **a_stack, t_list **b_stack, t_list **cmd, int pivot)
{
	while ((*b_stack) && *((int *)(*b_stack)->content) >= pivot)
	{
		best_pa(a_stack, b_stack, cmd, pivot);	//pa할 최선의 원소 반환
	//	원소찾아서 동작 수행.
	}
	return (0);
}

int	best_pa(t_list **a_stack, t_list **b_stack, t_list **cmd, int pivot)
{
	int		hash[100000];
	int		best_num;
	int		cur_num;
	t_list	*temtack;

	temtack = (*b_stack);
	best_num = *((int *)temtack->content);
	hash[best_num] = one_path(a_stack, b_stack, best_num);
	while (*b_stack && *((int *)temtack->content) >= pivot)			//모든원소를 돌면서 최선 원소 찾음
	{
		cur_num = *((int *)temtack->content);
		hash[cur_num] = one_path_cnt(a_stack, b_stack, cur_num);	//one_path경로개수 반환
		if (hash[best_num] == hash[cur_num] && best_num != cur_num)
			if (best_num < cur_num)
				best_num = cur_num;
		else if (hash[best_num] > hash[cur_num] && best_num != cur_num)
			best_num = cur_num;
		temtack = temtack->next;
	}
	return (best_num);
}




//plan
/*
최적값  (hash[값] : 명령어 수), preint에 key 저장
{
	현재int = 현재값 구하기(명령어수 해쉬에 대입, hash[값] : 명령어 수)
	최적 >=< 현재 비교 후 최적값선정 (ex hash[preint] > hash[현재int])
}
*/