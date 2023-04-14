/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:05:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/14 17:54:43 by soohlee          ###   ########.fr       */
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

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			xy[2];
}	t_mlx_data;

typedef struct s_map_data
{
	char	**map;
	int		empty;
	int		wall;
	int		collect;
	int		out;
	int		start;
	int		start_xy[2];
	int		idx;
	int		row_len;
	int		col_len;
}	t_map_data;

/*
so_long
*/
int	main(int argc, char **argv);

/*
map_check
*/
int	map_check(char *file, t_map_data *map_db);
int	read_map(char *file, t_map_data *map_db);
int	nl_len(char *file, int *buff_len);
int	config_check(t_map_data *map_db, int buff_len);
int	flagging(char c, t_map_data *map_db, int idx, int jdx);

/*
error & free
*/
int	ft_error(t_map_data *map_db, int idx, int err_flag);
int	free_double(char **s, int idx);

/*
arg_check
*/
int	arg_check(char *argv);

/*
map_setting
*/
int	map_setting(t_map_data *map_db, t_mlx_data *mlx_db, const char **file);

#endif