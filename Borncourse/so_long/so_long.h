/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:05:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/05 17:47:43 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"

# include <stdio.h>

typedef enum e_errstr
{
	NO_FREE = 0,
	FREE	= 1
}	t_errstr;

typedef struct s_config
{
	char	**map;
	int		empty;
	int		wall;
	int		collect;
	int		out;
	int		start;
	int		start_xy[2];
}	t_config;

/*
so_long
*/
int	main(int argc, char **argv);

/*
map_check
*/
int	map_check(char *file, char ***map);
int	read_map(char *file, t_config *flag);
int	nl_len(char *file, int *buff_len);
int	config_check(t_config *flag, int map_row_len, int buff_len);
int	flagging(char c, t_config *flag, int idc, int jdx);

/*
error & free
*/
int	ft_error(t_config *flag, int idx, int err_flag);
int	free_double(char **s, int idx);

#endif