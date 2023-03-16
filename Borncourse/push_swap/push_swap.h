/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:25:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/16 18:40:50 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

//main-
int		parsing(int argc, char **argv, int **num_array, t_list **a_stack);
int		push_swap(t_list **a_stack, t_list **b_stack, t_list **cmd);
int		print_cmd(t_list **cmd);

//-------------parsing-----------
//parsing_utils1
int		argv_merge(char **argv, char **str_oneline);
long	make_array(char **str_double, int **num_array);
void	error_print(void);
void	chk_malloc(void *s);
//parsing_utils2
int		chk_digit(char **str_stack);
int		free_double_pointer(char **s);
void	indexing(int **num_array, long long len);
int		*is_sort(t_list **stack);

//-------------push_swap-----------
//push_swap_utils
int		hard_coding(t_list **a_stack, t_list **cmd);
int		allpb(t_list **a_stack, t_list **b_stack, t_list **cmd);
int		allpa(t_list **a_stack, t_list **b_stack, t_list **cmd, int total_len);
int		greedy(t_list **a_stack, t_list **b_stack, t_list **cmd);
//hard_coding_utiles
int		hard_case(t_list **a_stack, int *a, t_list **cmd);
//greedy_utils
int		select_b(t_list **a_stack, t_list **b_stack, int *best_case, int *hash);
int		move_pa(int *bst_cse, t_list **a_stack, t_list **b_stack, t_list **cmd);
int		zero_to_top(t_list **a_stack, t_list **cmd, int len);
//select_b_utils
int		path_cnt(t_list **a_stack, t_list **b_stack, int num, int *best_case);
int		rarra_cnt(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt);
int		bpath(int *ra_cnt, int *rra_cnt, int *rb_cnt, int *rrb_cnt);
int		case_choice(int *ra_cnt, int *rra_cnt, int *rb_cnt, int *rrb_cnt);
t_list	*find_pivot(t_list **b_stack);
//move_pa_utils
int		pa_zero(int *bst_cse, t_list **a_stack, t_list **b_stack, t_list **cmd);
int		pa_one(int *bst_cse, t_list **a_stack, t_list **b_stack, t_list **cmd);
int		pa_two(int *bst_cse, t_list **a_stack, t_list **b_stack, t_list **cmd);
int		pa_thre(int *bst_cse, t_list **a_stack, t_list **b_stack, t_list **cmd);
//rarra_cnt_utils
int		sort_case(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt);
int		circule_sort_case(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt);
int		circule_ra_find(t_list **a_stack, int num, int *ra_cnt, int *rra_cnt);
int		find_min(t_list **a_stack);

//-------------print_cmd-----------
//print_cmd_utils
int		free_content(void *content);

//----------------instruction----------------
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

#endif
