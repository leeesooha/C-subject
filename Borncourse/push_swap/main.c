/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:00 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/16 11:15:05 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*arr;
	t_list		*a_stack;
	t_list		*b_stack;
	t_list		*cmd;

	b_stack = 0;
	a_stack = 0;
	parsing(argc, argv, &arr, &a_stack);
	push_swap(&a_stack, &b_stack, &cmd);
	print_cmd(&cmd);
	return (0);
}

int	parsing(int argc, char **argv, int **num_array, t_list **a_stack)
{
	char		*str_oneline;
	long long	stack_len;
	long long	i;

	str_oneline = ft_strdup("");
	if (argc < 2 || !str_oneline)
		exit(1);
	argv_merge(argv, &str_oneline);
	stack_len = make_array(ft_split(str_oneline, ' '), num_array);
	free(str_oneline);
	indexing(num_array, stack_len);
	i = 0;
	while (i < stack_len)
		ft_lstadd_back(a_stack, ft_lstnew((*num_array + i++)));
	free(*num_array);
	return (0);
}

int	push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	if (ft_lstsize(*a_stack) <= 3)
		return (hard_coding(a_stack, cmd));
	allpb(a_stack, b_stack, cmd);
	allpa(a_stack, b_stack, cmd,
		(ft_lstsize(*a_stack) + ft_lstsize(*b_stack)));
	return (0);
}

int	print_cmd(t_list **cmd)
{
	t_list	*temp_cmd;
	char	*temp_str;

	temp_cmd = *cmd;
	while (temp_cmd)
	{
		temp_str = (char *)temp_cmd->content;
		write(1, temp_str, ft_strlen(temp_str));
		write(1, "\n", 1);
		temp_cmd = temp_cmd->next;
	}
	ft_lstclear(cmd, (void *)free_content);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int			*arr;
	t_list		*a_stack;
	t_list		*b_stack;
	t_list		*cmd;

	b_stack = 0;
	a_stack = 0;
	parsing(argc, argv, &arr, &a_stack);
	push_swap(&a_stack, &b_stack, &cmd);
//	int			*temp;
	t_list		*free_temp;

	printf("a_stack : ");
	while (a_stack)
	{
		free_temp = a_stack;
		temp = (int *)a_stack->content;
		printf("%d ", *temp);
		a_stack = a_stack->next;
		free(free_temp);
	}
	printf("\nb_stack : ");
	while (b_stack)
	{
		free_temp = b_stack;
		temp = (int *)b_stack->content;
		printf("%d ", *temp);
		b_stack = b_stack->next;
		free(free_temp);
	}
//
	free(arr);
//	printf("\n------------------------------\n");
	print_cmd(&cmd);
//	printf("--------------------------------\n");
//	system ("leaks push_swap");
//	return (0);
//}
*/

/*
┌----------------스택 생성 테스트 코드----------------┐
	int			*temp;
	t_list		*free_temp;

	printf("a_stack : ");
	while (a_stack)
	{
		free_temp = a_stack;
		temp = (int *)a_stack->content;
		printf("%d ", *temp);
		a_stack = a_stack->next;
		free(free_temp);
	}
	printf("\nb_stack : ");
	while (b_stack)
	{
		free_temp = b_stack;
		temp = (int *)b_stack->content;
		printf("%d ", *temp);
		b_stack = b_stack->next;
		free(free_temp);
	}
	printf("\n");
	free(arr);
	system ("leaks push_swap");
└-----------------스택 생성 테스트 코드---------------┘
*/

//----조건----
//3개	2 or 3개
//5개	12개
//100개 700개		700 900 1100 1300 1500
//500개 5500개		5500 7000 8500 10000 11500
