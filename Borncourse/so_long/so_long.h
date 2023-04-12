/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:05:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/12 19:59:34 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"

# include <stdio.h>

typedef enum e_errstr
{
	NO_FREE = 0,
	FREE	= 1
}	t_errstr;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx_data;

typedef struct s_config
{
	char	**map;
	int		empty;
	int		wall;
	int		collect;
	int		out;
	int		start;
	int		start_xy[2];
	int		idx;
}	t_config;

/*
so_long
*/
int	main(int argc, char **argv);

/*
map_check
*/
int	map_check(char *file, char ***map, int *map_weight, int *map_height);
int	read_map(char *file, t_config *flag, int *map_weight, int *map_height);
int	nl_len(char *file, int *buff_len);
int	config_check(t_config *flag, int map_row_len, int buff_len);
int	flagging(char c, t_config *flag, int idc, int jdx);

/*
error & free
*/
int	ft_error(t_config *flag, int idx, int err_flag);
int	free_double(char **s, int idx);

/*
arg_check
*/
int	arg_check(char *argv);

/*
map_setting
*/
int	map_setting(char **map, t_mlx_data *img, t_vars *vars);

#endif