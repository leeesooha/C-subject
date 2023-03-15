/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:00 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/15 13:27:02 by soohlee          ###   ########.fr       */
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
	printf("\n---------\n");
	print_cmd(&cmd);
	printf("\n---------\n");
	system ("leaks push_swap");
	return (0);
}

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
