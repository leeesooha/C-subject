/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:19:27 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/26 17:59:24 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long_bonus.h"

int	space_check(t_mlx_data *mlx_db, int x, int y)
{
	char	**map;

	map = mlx_db->map;
	if ((map[y - 1][x - 1] == '0' && map[y - 1][x] == '0'
		&& map[y - 1][x + 1] == '0')
		&& (map[y + 1][x - 1] == '0' && map[y + 1][x] == '0'
		&& map[y + 1][x + 1] == '0')
		&& map[y][x + 1] == '0')
		return (0);
	return (1);
}
