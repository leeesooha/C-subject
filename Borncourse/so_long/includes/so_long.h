/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:05:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/25 21:44:26 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <stdio.h>

# define ARGS_ERROR 			0
# define FD_MOLLOC_ERROR 		1
# define MAP_CONTENTS_ERROR		2
# define ESC 					53
# define SUCCESS				4
# define NOT_ROUTE				5
# define FAIL					6
# define STRPUT_MALLOC_ERROR	7
# define X_BUTTEN				17

typedef struct s_count
{
	int		empty;
	int		wall;
	int		collect;
	int		out;
	int		start;
	char	**count_map;
}	t_count;

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
	char		**file;
	char		**map;
	int			eat_count;
	int			collect;
	int			width;
	int			height;
	int			print_cnt;
	int			row_len;
	int			col_len;
	int			enemy_num;
	int			enemy_direction[500];
}	t_mlx_data;

typedef struct s_map_data
{
	char	**map;
	char	**file;
	int		empty;
	int		wall;
	int		collect;
	int		out;
	int		start;
	int		start_xy[2];
	int		idx;
	int		row_len;
	int		col_len;
	t_count	cnt;
}	t_map_data;

/*
so_long
*/
int	main(int argc, char **argv);

/*
map_check
*/
int	map_init(char *mapfile, t_map_data *map_db, t_mlx_data *mlx_db);
int	new_map(char *mapfile, t_map_data *map_db, t_mlx_data *mlx_db);
int	map_size(t_map_data *map_db, char *mapfile);
int	map_check(t_map_data *map_db, t_mlx_data *mlx_db);
int	flagging(t_mlx_data *mlx_db, t_map_data *map_db, int idx, int jdx);

/*
error & free
*/
int	ft_end(t_mlx_data *mlx_db, int idx, int err_flag);
int	two_ptr_free(char **s, int idx);
int	err_print(int err_flag);
int	free_filehash(t_mlx_data *mlx_db);

/*
arg_check
*/
int	arg_check(int argc, char *argv);

/*
creat_filehash
*/
int	creat_filehash(t_mlx_data *mlx_db);
int	filehash_check(t_mlx_data *mlx_db);

/*
map_setting
*/
int	mlxwin_init(t_map_data *map_db, t_mlx_data *mlx_db);
int	new_mlx(t_map_data *map_db, t_mlx_data *mlx_db);
int	map_print(t_mlx_data *mlx_db);
int	add_enemy(t_mlx_data *mlx_db);

/*
path_check
*/
int	valid_path_search(t_map_data *map_db, t_mlx_data *mlx_db);

/*
game_end_check
*/
int	game_end_check(t_mlx_data *mlx_db);

/*
keyhook
*/
int	key_hook(int keycode, t_mlx_data *mlx_db);
int	move_able_check(int keycode, t_mlx_data *mlx_db);
int	move_character(int keycode, t_mlx_data *mlx_db, int width, int height);
int	direction(t_mlx_data *mlx_db, int keycode, int *x, int *y);
int	my_put_window(t_mlx_data *mlx_db, int width, int height, char img);

/*
keyhook_bonus
*/
int	my_str_put_window(t_mlx_data *mlx_db, int width, int height, char img);
int	modify_enemy_map(t_mlx_data *mlx_db, int xy[2]);
int	enemy_print(t_mlx_data *mlx_db, int x, int y, int xdir);

#endif