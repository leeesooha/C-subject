/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:57:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 20:23:02 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long_bonus.h"

int	key_hook(int keycode, t_mlx_data *mlx_db)
{
	int	xy[2];

	modify_enemy_map(mlx_db, xy);
	if (!move_able_check(keycode, mlx_db))
		return (0);
	move_character(keycode, mlx_db, mlx_db->width, mlx_db->height);
	game_end_check(mlx_db);
	return (0);
}

int	move_able_check(int keycode, t_mlx_data *mlx_db)
{
	int	x;
	int	y;

	x = mlx_db->xy[0];
	y = mlx_db->xy[1];
	if (keycode == ESC)
		ft_end(mlx_db, mlx_db->row_len, ESC);
	else if ((mlx_db->map[y][x] == 'D' && (keycode != 13 && keycode != 1))
			|| (keycode == 13 && mlx_db->map[y - 1][x] == 'D'))
		ft_end(mlx_db, mlx_db->row_len, FAIL);
	else if (keycode == 1 && mlx_db->map[y + 1][x] == 'D')
		ft_end(mlx_db, mlx_db->row_len, FAIL);
	else if (keycode == 0 && mlx_db->map[y][x - 1] == 'D')
		ft_end(mlx_db, mlx_db->row_len, FAIL);
	else if (keycode == 2 && mlx_db->map[y][x + 1] == 'D')
		ft_end(mlx_db, mlx_db->row_len, FAIL);
	else if (keycode == 13 && ft_strncmp(&mlx_db->map[y - 1][x], "1", 1))
		return (1);
	else if (keycode == 1 && ft_strncmp(&mlx_db->map[y + 1][x], "1", 1))
		return (1);
	else if (keycode == 0 && ft_strncmp(&mlx_db->map[y][x - 1], "1", 1))
		return (1);
	else if (keycode == 2 && ft_strncmp(&mlx_db->map[y][x + 1], "1", 1))
		return (1);
	return (0);
}

int	move_character(int keycode, t_mlx_data *mlx_db, int width, int height)
{
	int	sprite;

	sprite = 0;
	if (mlx_db->print_cnt % 2 == 1)
		sprite = 1;
	if (mlx_db->map[mlx_db->xy[1]][mlx_db->xy[0]] == 'D')
		my_put_window(mlx_db, width, height, 'D');
	else if (mlx_db->map[mlx_db->xy[1]][mlx_db->xy[0]] == 'e')
		my_put_window(mlx_db, width, height, 'e');
	else
		my_put_window(mlx_db, width, height, '0');
	direction(mlx_db, keycode, &mlx_db->xy[0], &mlx_db->xy[1]);
	my_put_window(mlx_db, width, height, 'P' - sprite);
	my_str_put_window(mlx_db, width, height, '1');
	return (0);
}

int	my_put_window(t_mlx_data *mlx_db, int width, int height, char img)
{
	mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx,
			mlx_db->file[(int) img], &width, &height);
	mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp),
			&(mlx_db->line_len), &(mlx_db->endian));
	mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img,
		mlx_db->xy[0] * width, mlx_db->xy[1] * height);
	return (1);
}

int	direction(t_mlx_data *mlx_db, int keycode, int *x, int *y)
{
	if (keycode == 13)
		*y -= 1;
	else if (keycode == 1)
		*y += 1;
	else if (keycode == 0)
		*x -= 1;
	else if (keycode == 2)
		*x += 1;
	if (mlx_db->map[mlx_db->xy[1]][mlx_db->xy[0]] == 'c')
	{
		mlx_db->eat_count++;
		mlx_db->map[mlx_db->xy[1]][mlx_db->xy[0]] = '0';
	}
	return (0);
}
