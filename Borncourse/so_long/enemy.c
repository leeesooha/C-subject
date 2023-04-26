/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:38:43 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/26 17:55:21 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	enemy_print(t_mlx_data *mlx_db, int x, int y, int xdir)
{
	mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx,
			mlx_db->file[(int) '0'], &mlx_db->width, &mlx_db->height);
	mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp),
			&(mlx_db->line_len), &(mlx_db->endian));
	mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img,
		x * mlx_db->width, y * mlx_db->height);
	mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx,
			mlx_db->file[(int) 'D'], &mlx_db->width, &mlx_db->height);
	mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp),
			&(mlx_db->line_len), &(mlx_db->endian));
	mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img,
		(x + xdir) * mlx_db->width, y * mlx_db->height);
	return (0);
}

static void	modify_enemy(t_mlx_data *mlx_db, int xy[2], int cur_enemy, int xdir)
{
	if (mlx_db->map[xy[1]][xy[0] + 1] == '1'
		&& mlx_db->map[xy[1]][xy[0] - 1] == '1')
		return ;
	mlx_db->map[xy[1]][xy[0]] = '0';
	mlx_db->map[xy[1]][xy[0] + xdir] = 'D';
	if (xdir == -1 && mlx_db->map[xy[1]][xy[0] + xdir - 1] == '1')
		mlx_db->enemy_direction[cur_enemy] = 1;
	else if (xdir == 1 && mlx_db->map[xy[1]][xy[0] + xdir + 1] == '1')
		mlx_db->enemy_direction[cur_enemy] = -1;
	else
		mlx_db->enemy_direction[cur_enemy] = xdir;
	if (mlx_db->map[mlx_db->xy[1]][mlx_db->xy[0]] == 'D')
	{
		if (xdir == 1 && !(mlx_db->keycode == 13 || mlx_db->keycode == 1
				|| mlx_db->keycode == 2))
			ft_end(mlx_db, mlx_db->row_len, FAIL);
		if (xdir == -1 && !(mlx_db->keycode == 13 || mlx_db->keycode == 1
				|| mlx_db->keycode == 0))
			ft_end(mlx_db, mlx_db->row_len, FAIL);
	}
	enemy_print(mlx_db, xy[0], xy[1], xdir);
}

int	modify_enemy_map(t_mlx_data *mlx_db, int xy[2])
{
	int	cur_enemy;

	cur_enemy = mlx_db->enemy_num - 1;
	xy[1] = -1;
	while (mlx_db->map[++xy[1]])
	{
		xy[0] = -1;
		while (mlx_db->map[xy[1]][++xy[0]])
		{
			if (mlx_db->map[xy[1]][xy[0]] == 'D')
			{
				if (((mlx_db->enemy_direction[cur_enemy] == 1)
						&& mlx_db->map[xy[1]][xy[0] + 1] == '0') ||
					((mlx_db->enemy_direction[cur_enemy] == -1)
					&& (mlx_db->map[xy[1]][xy[0] - 1] == '1'
					|| mlx_db->map[xy[1]][xy[0] - 1] == 'e')))
					modify_enemy(mlx_db, xy, cur_enemy, 1);
				else
					modify_enemy(mlx_db, xy, cur_enemy, -1);
				cur_enemy--;
				break ;
			}
		}
	}
	return (0);
}

static int	modify_map(t_mlx_data *mlx_db, int enemy_num, int x, int y)
{
	int	three_space_x;

	three_space_x = 0;
	while (mlx_db->map[++y] && enemy_num)
	{
		x = -1;
		while (mlx_db->map[y][++x])
		{
			if (mlx_db->map[y][x] == '0')
				three_space_x++;
			else
				three_space_x = 0;
			if ((((mlx_db->map[y][x] == '0' && y % 5 == 0)
					|| (y == 1 && mlx_db->map[y][x] == '0'))
				&& (mlx_db->map[y][x] != 'e')) && three_space_x >= 2
				&& !space_check(mlx_db, x, y))
			{
				mlx_db->map[y][x] = 'D';
				enemy_num--;
				break ;
			}
		}
	}
	return (0);
}

int	add_enemy(t_mlx_data *mlx_db)
{
	int	i;
	int	enemy_num;

	enemy_num = 0;
	i = -1;
	while (mlx_db->map[++i])
		if (ft_strchr(mlx_db->map[i], '0'))
			enemy_num++;
	if (enemy_num < 5)
		enemy_num = 1;
	else
		enemy_num /= 5;
	mlx_db->enemy_num = enemy_num;
	modify_map(mlx_db, enemy_num, -1, -1);
	i = -1;
	while (++i < enemy_num)
		mlx_db->enemy_direction[i] = 1;
	return (0);
}
