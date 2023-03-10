/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/10 21:02:51 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

//삭제 후 제출
#include <stdio.h>

//main-
int		parsing(int argc, char **argv, int **num_array, t_list **a_stack);
int		push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd);
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
char	*sa(t_list **a_stack);
char	*sb(t_list **b_stack);
char	*ss(t_list **a_stack, t_list **b_stack);
char	*pa(t_list **a_stack, t_list **b_stack);
char	*pb(t_list **a_stack, t_list **b_stack);
//instructions2
char	*rra(t_list **a_stack);
char	*rrb(t_list **b_stack);
char	*rrr(t_list **a_stack, t_list **b_stack);
char	*ra(t_list **a_stack);
char	*rb(t_list **b_stack);
//instructions3
char	*rr(t_list **a_stack, t_list **b_stack);
//hard_coding
int		hard_coding(t_list **a_stack, t_list **cmd);
int		free_content(void *content);
int		hard_case(t_list **a_stack, int *a, t_list **cmd);

//is_sort
int		is_sort(t_list *stack);

//push_swap
int		allpb_tpvt(t_list **a_stack, t_list **b_stack, t_list **cmd);

#endif
