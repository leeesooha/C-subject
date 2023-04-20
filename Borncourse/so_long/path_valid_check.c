/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:23:26 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/20 16:39:20 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static int	exit_check(int x, int y, t_count cnt, t_map_data *map_db);
static int	mapsetzero(t_map_data *map_db, t_mlx_data *mlx_db);
static int	compare(int x, int y, t_count *cnt, t_map_data *map_db);

int	path_valid_check(t_map_data *map_db, t_mlx_data *mlx_db)
{
	int	x;
	int	y;

	x = map_db->start_xy[0];
	y = map_db->start_xy[1];
	mapsetzero(map_db, mlx_db);
	if (exit_check(x, y, map_db->cnt, map_db))
	{
		two_dimen_free(map_db->cnt.count_map, map_db->row_len);
		return (1);
	}
	two_dimen_free(map_db->cnt.count_map, map_db->row_len);
	ft_end(mlx_db, map_db->row_len, 5);
	return (0);
}

static int	mapsetzero(t_map_data *map_db, t_mlx_data *mlx_db)
{
	int	i;

	map_db->cnt.collect = 0;
	map_db->cnt.empty = 0;
	map_db->cnt.out = 0;
	map_db->cnt.start = 0;
	map_db->cnt.wall = 0;
	map_db->validpath = 0;
	map_db->cnt.from = 0;
	i = 0;
	map_db->cnt.count_map = (char **)malloc(sizeof(char *) * map_db->row_len + 1);
	if (!map_db->cnt.count_map)
		ft_end(mlx_db, map_db->row_len, 1);
	while (i < map_db->row_len)
	{
		map_db->cnt.count_map[i] = (char *)malloc(sizeof(char)
			* map_db->col_len);
		if (!(map_db->cnt.count_map + i))
		{
			two_dimen_free(map_db->cnt.count_map, i - 1);
			ft_end(mlx_db, map_db->row_len, 1);
		}
		ft_memset(map_db->cnt.count_map[i], '0', map_db->col_len);
		i++;
	}
	map_db->cnt.count_map[i] = 0;
	return (0);
}

static int	exit_check(int x, int y, t_count cnt, t_map_data *map_db)
{
	if (!compare(x, y, &cnt, map_db))
		return (0);
	if (map_db->cnt.out == 1 && map_db->cnt.collect == map_db->collect)
		return (1);
	cnt.count_map[y][x]++;
	cnt.from = 1;
	if (cnt.from != 3)
		if (exit_check (x - 1, y, cnt, map_db))
			return (1);
	cnt.from = 2;
	if (cnt.from != 4)
		if (exit_check (x, y - 1, cnt, map_db))
			return (1);
	cnt.from = 3;
	if (cnt.from != 1)
		if (exit_check (x + 1, y, cnt, map_db))
			return (1);
	cnt.from = 4;
	if (cnt.from != 2)
		if (exit_check (x, y + 1, cnt, map_db))
			return (1);
	cnt.count_map[y][x]++;
	return (0);
}

static int	compare(int x, int y, t_count *cnt, t_map_data *map_db)
{
	if (cnt->count_map[y][x] >= '1' || map_db->map[y][x] == '1')
		return (0);
	if (map_db->map[y][x] == 'E')
	{
		map_db->cnt.out++;
		map_db->map[y][x] = 'e';
	}
	if (map_db->map[y][x] == 'C')
	{
		map_db->cnt.collect++;
		map_db->map[y][x] = 'c';
	}
	return (2);
}