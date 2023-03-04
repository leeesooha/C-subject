/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/04 18:15:41 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

typedef struct s_stack
{
	char	*stack;
	int		integer_stack[];
}			t_stack;

int		push_swap(int i);

int		parsing(int argc, char **argv, int **a_stack);
int		argv_merge(char **argv, char **str_stack_oneline);
int		make_stack(char **str_stack, int **a_stack);
void	error_print(void);
void	chk_malloc(void *s);

//parsing_until
int		chk_digit(char **argv);
int		free_double_pointer(char **s);

#endif