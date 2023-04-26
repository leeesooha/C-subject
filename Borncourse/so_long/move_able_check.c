/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_able_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:28:29 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/26 17:56:40 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long_bonus.h"

static int	fail_check(int keycode, t_mlx_data *mlx_db, int x, int y);

int	move_able_check(int keycode, t_mlx_data *mlx_db)
{
	int	x;
	int	y;

	x = mlx_db->xy[0];
	y = mlx_db->xy[1];
	fail_check(keycode, mlx_db, x, y);
	if ((keycode == 13 && ft_strncmp(&mlx_db->map[y - 1][x], "1", 1))
		|| (keycode == 1 && ft_strncmp(&mlx_db->map[y + 1][x], "1", 1))
		|| (keycode == 0 && ft_strncmp(&mlx_db->map[y][x - 1], "1", 1))
		|| (keycode == 2 && ft_strncmp(&mlx_db->map[y][x + 1], "1", 1)))
		return (1);
	return (0);
}

static int	fail_check(int keycode, t_mlx_data *mlx_db, int x, int y)
{
	if (keycode == ESC)
		ft_end(mlx_db, mlx_db->row_len, ESC);
	if (keycode == 13 && mlx_db->map[y - 1][x] == 'D')
		ft_end(mlx_db, mlx_db->row_len, FAIL);
	else if (keycode == 1 && mlx_db->map[y + 1][x] == 'D')
		ft_end(mlx_db, mlx_db->row_len, FAIL);
	else if (keycode == 0 && mlx_db->map[y][x - 1] == 'D')
		ft_end(mlx_db, mlx_db->row_len, FAIL);
	else if (keycode == 2 && mlx_db->map[y][x + 1] == 'D')
		ft_end(mlx_db, mlx_db->row_len, FAIL);
	return (0);
}
