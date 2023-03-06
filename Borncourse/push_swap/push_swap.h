/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/06 16:42:38 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

typedef struct s_stack
{
	struct s_stack	*previous;
	struct s_stack	*next;
	int				num;
}					t_stack;

//main
int		parsing(int argc, char **argv, int **a_stack);
int		push_swap(int *num_array);

//parsing
int		argv_merge(char **argv, char **str_stack_oneline);
int		make_num_array(char **str_stack, int **a_stack);
void	error_print(void);
void	chk_malloc(void *s);

//parsing_until
int		chk_digit(char **argv);
int		free_double_pointer(char **s);

//push_swap

#endif
