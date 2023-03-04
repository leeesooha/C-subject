/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/03 12:21:39 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

typedef struct s_stack
{
    char    *stack;
    int     integer_stack[];
}           t_stack;

int 	push_swap(int i);

int 	parsing(int argc, char **argv, int **a_stack);
int 	argv_merge(char **argv, char **str_stack_oneline);
int	    make_stack(char **str_stack, int **a_stack);
void	error_print(void);
void    chk_malloc(void *s);

int	    chk_digit(char **argv);

#endif