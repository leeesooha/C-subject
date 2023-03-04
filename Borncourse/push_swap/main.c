/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:00 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/03 13:24:42 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	test_i;
	int	*a_stack;

	parsing(argc, argv, &a_stack);
	test_i = 0;

	while (a_stack[test_i])
	{
		printf("%d\n", a_stack[test_i]);
		test_i++;
	}
//	system ("leaks push_swap");
	free(a_stack);
	return (0);
}
