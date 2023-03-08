/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:00 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/08 13:29:55 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			*num_array;
	t_list		*a_stack;
	t_list		*b_stack;

	b_stack = 0;
	parsing(argc, argv, &num_array, &a_stack);
	push_swap(&a_stack, &b_stack);
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
	free(num_array);
	system ("leaks push_swap");
└-----------------스택 생성 테스트 코드---------------┘
*/