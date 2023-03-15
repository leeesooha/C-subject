/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_action_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:10:41 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/15 21:34:16 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa_zero(int *best_case, t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	int		ra_cnt;
	int		rb_cnt;
	int		rr_cnt;

	ra_cnt = best_case[7];
	rb_cnt = best_case[8];
	rr_cnt = ra_cnt;
	if (rb_cnt <= ra_cnt)
		rr_cnt = rb_cnt;
	ra_cnt -= rr_cnt;
	rb_cnt -= rr_cnt;
	while (rr_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rr(a_stack, b_stack))));
	while (ra_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(ra(a_stack))));
	while (rb_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rb(b_stack))));
	ft_lstadd_back(cmd, ft_lstnew(ft_strdup(pa(a_stack, b_stack))));
/*
	int *temp;
	t_list *test;
	test = *a_stack;
	printf("a_stack : ");
	while (test)
	{
		temp = (int *)test->content;
		printf("%d ", *temp);
		test = test->next;
	}
*/
	return (0);
}

int	pa_one(int *best_case, t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	int		rra_cnt;
	int		rrb_cnt;
	int		rrr_cnt;

	rra_cnt = best_case[9];
	rrb_cnt = best_case[10];
	rrr_cnt = rra_cnt;
	if (rrb_cnt <= rra_cnt)
		rrr_cnt = rrb_cnt;
	rra_cnt -= rrr_cnt;
	rrb_cnt -= rrr_cnt;
	while (rrr_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rrr(a_stack, b_stack))));
	while (rra_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rra(a_stack))));
	while (rrb_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rrb(b_stack))));
	ft_lstadd_back(cmd, ft_lstnew(ft_strdup(pa(a_stack, b_stack))));
	return (0);
}

int	pa_two(int *best_case, t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	int		ra_cnt;
	int		rrb_cnt;

	ra_cnt = best_case[7];
	rrb_cnt = best_case[10];
	while (rrb_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rrb(b_stack))));
	while (ra_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(ra(a_stack))));
	ft_lstadd_back(cmd, ft_lstnew(ft_strdup(pa(a_stack, b_stack))));
	return (0);
}

int	pa_three(int *best_case, t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	int		rb_cnt;
	int		rra_cnt;

	rb_cnt = best_case[8];
	rra_cnt = best_case[9];
	while (rb_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rb(b_stack))));
	while (rra_cnt--)
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rra(a_stack))));
	ft_lstadd_back(cmd, ft_lstnew(ft_strdup(pa(a_stack, b_stack))));
	return (0);
}
