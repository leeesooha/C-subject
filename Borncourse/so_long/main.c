/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:02:52 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/12 20:12:05 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars);

int	main(int argc, char **argv)
{
	char		**map;
	t_mlx_data	img;
	t_vars		vars;
	int			map_weight;
	int			map_height;

	if (argc != 2 || !arg_check(argv[1]))
		ft_error(0, 0, 0);
	map_check(argv[1], &map, &map_weight, &map_height);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map_weight * 64, map_height * 64, "SOOHA WINDOWS");
	map_setting(map, &img, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	map_setting(char **map, t_mlx_data *img, t_vars *vars)
{
	int	x;
	int	y;
	int	tmpx;
	int	tmpy;
	int	weight;
	int	height;

	weight = 64;
	height = 64;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '\n')
			{
				x++;
				continue ;
			}
			tmpx = x * 64;
			tmpy = y * 64;
			img->img = mlx_xpm_file_to_image(vars->mlx, "./back_ground.xpm", &weight, &height);
			img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, tmpx, tmpy);
			if (map[y][x] == '1')
			{
				img->img = mlx_xpm_file_to_image(vars->mlx, "./wall.xpm", &weight, &height);
				img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, tmpx, tmpy);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	if (vars && keycode)
		return (0);
	return (0);
}
