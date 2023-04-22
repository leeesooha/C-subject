/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:02:52 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/22 23:53:57 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

//static int	test_print(char **map);
void	end_check(void)
{
	printf("\n====================================================================================||\n\n");
	system("leaks so_long > res; cat res; rm res");
	printf("====================================================================================||\n\n");
}

int	close_mlx(t_mlx_data *mlx_db)
{
	ft_end(mlx_db, mlx_db->row_len, 3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlx_db;
	t_map_data	map_db;
	int			x_event;

	x_event = 0;
	atexit(end_check);
	arg_check(argc, argv[1]);
	map_init(argv[1], &map_db, &mlx_db);
	mlxwin_init(&map_db, &mlx_db);
	mlx_key_hook(mlx_db.win, key_hook, &mlx_db);
//	mlx_loop_hook(mlx_db.win, map_print, &mlx_db);
	mlx_hook(mlx_db.win, 17, 0, close_mlx, &mlx_db);
	mlx_loop(mlx_db.mlx);
	return (0);
}

//static int	test_print(char **map)
//{
//	int	i;
//	int	j;

//	i = 0;
//	while (map[i])
//	{
//		j = 0;
//		while (map[i][j])
//		{
//			if (map[i][j] == '0')
//				printf("%c", ' ');
//			else
//				printf("%c", map[i][j]);
//			j++;
//		}
//		i++;
//	}
//	printf("\n");
//	return (0);
//}

