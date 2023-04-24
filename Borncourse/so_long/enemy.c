/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:38:43 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 17:51:59 by soohlee          ###   ########.fr       */
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

static int	modify_map(t_mlx_data *mlx_db, int enemy_num)
{
	int	i;
	int	j;

	i = -1;
	while (mlx_db->map[++i] && enemy_num)
	{
		j = -1;
		while (mlx_db->map[i][++j])
		{
			if (((mlx_db->map[i][j] == '0' && i % 5 == 0)
				|| (i == 1 && mlx_db->map[i][j] == '0'))
				&& (mlx_db->map[i][j] != 'e'))
			{
				mlx_db->map[i][j] = 'D';
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
	modify_map(mlx_db, enemy_num);
	i = -1;
	while (++i < enemy_num)
		mlx_db->enemy_direction[i] = 1;
	return (0);
}
