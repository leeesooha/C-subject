/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/07 20:51:52 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

//main
int			parsing(int argc, char **argv, int **num_array, t_list **a_stack);
int			push_swap(int *num_array);

//parsing
int			argv_merge(char **argv, char **str_stack_oneline);
long long	make_num_array(char **str_stack, int **a_stack);
void		error_print(void);
void		chk_malloc(void *s);
//parsing_until
int			chk_digit(char **argv);
int			free_double_pointer(char **s);

//instructions1
int			sa(t_list **a_stack);

#endif
