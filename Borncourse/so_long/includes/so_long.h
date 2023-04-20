/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:05:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/21 00:56:01 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "../minilibx_mms_20210621/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

# include <stdio.h>

typedef enum e_errstr
{
	NO_FREE = 0,
	FREE	= 1
}	t_errstr;

typedef struct s_count
{
	int		empty;
	int		wall;
	int		collect;
	int		out;
	int		start;
	int		from;
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
	int			path_cnt;
	int			row_len;
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
	int		validpath;
	struct s_count	cnt;
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
int	map_print(t_map_data *map_db, t_mlx_data *mlx_db);
int	new_mlx(t_map_data *map_db, t_mlx_data *mlx_db);

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

#endif