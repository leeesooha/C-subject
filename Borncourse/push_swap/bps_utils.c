/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bps_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:56:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/14 18:08:46 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greedy(t_list **a_stack, t_list **b_stack, t_list **cmd, int pivot)
{
	int	best_case[6];
	while (ft_lstsize(*b_stack) && *((int *)(*b_stack)->content) >= pivot)
	{
		best_case[0] = best_pa(a_stack, b_stack, pivot, best_case);	//pa할 최선의 원소 반환
		pa_action(best_case, a_stack, b_stack, cmd);
	//	원소찾아서 동작 수행. 0번 최적원소, 1번 케이스
	}
	return (0);
}

int	best_pa(t_list **a_stack, t_list **b_stack, int pivot, int *best_case)
{
	int		hash[100000];
	int		best_num;
	int		cur_num;
	t_list	*temtack;

	temtack = (*b_stack);
	best_num = *((int *)temtack->content);
	hash[best_num] = one_path_cnt(a_stack, b_stack, best_num, best_case);
	while (*b_stack && (temtack) && *((int *)temtack->content) >= pivot)			//모든원소를 돌면서 최선 원소 찾음
	{
		cur_num = *((int *)temtack->content);
		hash[cur_num] = one_path_cnt(a_stack, b_stack, cur_num, best_case);	//one_path경로개수 반환
		if (hash[best_num] == hash[cur_num] && best_num != cur_num)
		{
			if (best_num < cur_num)
				best_num = cur_num;
		}
		else if (hash[best_num] > hash[cur_num] && best_num != cur_num)
			best_num = cur_num;
		temtack = temtack->next;
	}
	return (best_num);
}

int	pa_action(int *best_case, t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	if (best_case[1] == 0)
		return (pa_zero(best_case, a_stack, b_stack, cmd));
	else if (best_case[1] == 1)
		return (pa_one(best_case, a_stack, b_stack, cmd));
	else if (best_case[1] == 2)
		return (pa_two(best_case, a_stack, b_stack, cmd));
	else if (best_case[1] == 3)
		return (pa_three(best_case, a_stack, b_stack, cmd));
	return (0);
}

int	final_ro_a(t_list **a_stack, t_list **cmd, int len)
{
	t_list	*temtack;
	int		zero_index;

	zero_index = 0;
	temtack = *a_stack;
	while (*((int *)temtack->content) != 0)
	{
		zero_index++;
		temtack = temtack->next;
	}
	if (zero_index > len / 2)
	{
		while (*((int *)((*a_stack)->content)) != 0)
			ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rra(a_stack))));
	}
	else
	{
		while (*((int *)((*a_stack)->content)) != 0)
			ft_lstadd_back(cmd, ft_lstnew(ft_strdup(ra(a_stack))));
	}
	return (0);
}
//plan
/*
최적값  (hash[값] : 명령어 수), preint에 key 저장
{
	현재int = 현재값 구하기(명령어수 해쉬에 대입, hash[값] : 명령어 수)
	최적 >=< 현재 비교 후 최적값선정 (ex hash[preint] > hash[현재int])
}
*/