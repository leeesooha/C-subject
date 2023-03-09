/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/09 15:28:21 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

//main
int		parsing(int argc, char **argv, int **num_array, t_list **a_stack);
int		push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd, int **arr);
int		print_cmd(t_list **cmd);
//parsing
int		argv_merge(char **argv, char **str_stack_oneline);
long	make_num_array(char **str_stack, int **a_stack);
void	error_print(void);
void	chk_malloc(void *s);
//parsing_utils
int		chk_digit(char **argv);
int		free_double_pointer(char **s);
void	indexing(int **num_array, long long len);

//instructions1
int		sa(t_list **a_stack);
int		sb(t_list **b_stack);
int		ss(t_list **a_stack, t_list **b_stack);
int		pa(t_list **a_stack, t_list **b_stack);
int		pb(t_list **a_stack, t_list **b_stack);
//instructions2
int		rra(t_list **a_stack);
int		rrb(t_list **b_stack);
int		rrr(t_list **a_stack, t_list **b_stack);
int		ra(t_list **a_stack);
int		rb(t_list **b_stack);
//instructions3
int		rr(t_list **a_stack, t_list **b_stack);

//hard_coding
int		hard_coding(t_list **a_stack, t_list **cmd, int **arr);
int		free_content(void *content);
int		two_case(t_list **a_stack, int *a, t_list **cmd);
int		one_case(t_list **a_stack, int *a, t_list **cmd);

//is_sort
int		is_sort(t_list *stack);

#endif
