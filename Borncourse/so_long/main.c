/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:02:52 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/14 17:54:44 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx_data *mlx_db);

int	main(int argc, char **argv)
{
	t_mlx_data	mlx_db;
	t_map_data	map_db;
	const char	**file = {"./back_ground.xpm", "./wall.xpm",
		"./collect.xpm", "exit.xpm", "./yoda.xpm"};

	if (argc != 2 || !arg_check(argv[1]))
		ft_error(0, 0, 0);
	map_check(argv[1], &(map_db));
	mlx_db.mlx = mlx_init();
	mlx_db.win = mlx_new_window(mlx_db.mlx, map_db.col_len * 64,
			map_db.row_len * 64, "SOOHA WINDOWS");
	map_setting(&map_db, &mlx_db, file);
	mlx_key_hook(mlx_db.win, key_hook, &mlx_db);
	mlx_loop(mlx_db.mlx);
	return (0);
}

int	map_setting(t_map_data *map_db, t_mlx_data *mlx_db, const char **file)
{
	int	x;
	int	y;
	int	weight;
	int	height;

	weight = 64;
	height = 64;
	y = 0;
	while (map_db->map[y])
	{
		x = 0;
		while (map_db->map[y][x] && map_db->map[y][x] != '\n')
		{
//			if (map_db->map[y][x] == '0')
//			{
				mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx, file[map_db->map[y][x] - '0'], &weight, &height);
				mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp), &(mlx_db->line_len), &(mlx_db->endian));
				mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img, x * weight, y * height);
//			}
			//else if (map_db->map[y][x] == '1')
			//{
			//	mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx, "./wall.xpm", &weight, &height);
			//	mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp), &(mlx_db->line_len), &(mlx_db->endian));
			//	mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img, x * weight, y * height);
			//}
			//else if (map_db->map[y][x] == 'C')
			//{
			//	mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx, "./collect.xpm", &weight, &height);
			//	mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp), &(mlx_db->line_len), &(mlx_db->endian));
			//	mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img, x * weight, y * height);
			//}
			//else if (map_db->map[y][x] == 'E')
			//{
			//	mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx, "./exit.xpm", &weight, &height);
			//	mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp), &(mlx_db->line_len), &(mlx_db->endian));
			//	mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img, x * weight, y * height);
			//}
			//else if (map_db->map[y][x] == 'P')
			//{
			//	mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx, "./yoda.xpm", &weight, &height);
			//	mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp), &(mlx_db->line_len), &(mlx_db->endian));
			//	mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img, x * weight, y * height);
			//}
			x++;
		}
		y++;
	}
	return (0);
}

int	key_hook(int keycode, t_mlx_data *mlx_db)
{
	int	weight;
	int	height;

	weight = 64;
	height = 64;
	printf("asdfasdfasdfasdf\n");
	printf("%d\n", keycode);
	if (keycode == 13)
	{
		mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx, "./back_ground.xpm", &weight, &height);
		mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp), &(mlx_db->line_len), &(mlx_db->endian));
		mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img, mlx_db->xy[0], mlx_db->xy[1]);

		printf("before y value: %d\n", mlx_db->xy[1]);
		mlx_db->xy[1] = mlx_db->xy[1] - 64;
		printf("after y value: %d\n", mlx_db->xy[1]);
		mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx, "./yoda.xpm", &weight, &height);
		mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp), &(mlx_db->line_len), &(mlx_db->endian));
		mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img, mlx_db->xy[0], mlx_db->xy[1]);
	}
	return (0);
}
