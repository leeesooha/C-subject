/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:02:52 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 19:47:52 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long_bonus.h"

int	close_mlx(t_mlx_data *mlx_db)
{
	ft_end(mlx_db, mlx_db->row_len, X_BUTTEN);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlx_db;
	t_map_data	map_db;

	arg_check(argc, argv[1]);
	map_init(argv[1], &map_db, &mlx_db);
	mlxwin_init(&map_db, &mlx_db);
	mlx_key_hook(mlx_db.win, key_hook, &mlx_db);
	mlx_hook(mlx_db.win, X_BUTTEN, 0, close_mlx, &mlx_db);
	mlx_loop(mlx_db.mlx);
	return (0);
}
