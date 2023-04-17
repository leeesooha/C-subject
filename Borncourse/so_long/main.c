/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:02:52 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/18 00:13:46 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

//void	end_check(void)
//{
//	system("leaks so_long > res; cat res; rm res");
//}
int	main(int argc, char **argv)
{
	t_mlx_data	mlx_db;
	t_map_data	map_db;

	arg_check(argc, argv[1]);
	map_init(argv[1], &(map_db), &(mlx_db));
	map_print(&map_db, &mlx_db);
	mlx_key_hook(mlx_db.win, key_hook, &mlx_db);
	mlx_loop(mlx_db.mlx);
	return (0);
}
