/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:23:26 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 20:14:15 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int			valid_path_search(t_map_data *map_db, t_mlx_data *mlx_db);
static int	zero_map_init(t_map_data *map_db, t_mlx_data *mlx_db);
static int	dfs(int x, int y, t_count cnt, t_map_data *map_db);
static int	compare(int x, int y, t_count *cnt, t_map_data *map_db);

int	valid_path_search(t_map_data *map_db, t_mlx_data *mlx_db)
{
	int	x;
	int	y;

	x = map_db->start_xy[0];
	y = map_db->start_xy[1];
	zero_map_init(map_db, mlx_db);
	if (dfs(x, y, map_db->cnt, map_db))
		return (two_ptr_free(map_db->cnt.count_map, map_db->row_len));
	two_ptr_free(map_db->cnt.count_map, map_db->row_len);
	ft_end(mlx_db, map_db->row_len, NOT_ROUTE);
	return (0);
}

static int	zero_map_init(t_map_data *map_db, t_mlx_data *mlx_db)
{
	int	i;

	map_db->cnt.collect = 0;
	map_db->cnt.empty = 0;
	map_db->cnt.out = 0;
	map_db->cnt.start = 0;
	map_db->cnt.wall = 0;
	i = -1;
	map_db->cnt.count_map = (char **)malloc(sizeof(char *)
			* map_db->row_len + 1);
	if (!map_db->cnt.count_map)
		ft_end(mlx_db, map_db->row_len, FD_MOLLOC_ERROR);
	while (++i < map_db->row_len)
	{
		map_db->cnt.count_map[i] = (char *)malloc(sizeof(char)
				* map_db->col_len);
		if (!(map_db->cnt.count_map + i))
		{
			two_ptr_free(map_db->cnt.count_map, i - 1);
			ft_end(mlx_db, map_db->row_len, FD_MOLLOC_ERROR);
		}
		ft_memset(map_db->cnt.count_map[i], '0', map_db->col_len);
	}
	map_db->cnt.count_map[i] = 0;
	return (0);
}

static int	dfs(int x, int y, t_count cnt, t_map_data *map_db)
{
	if (!compare(x, y, &cnt, map_db))
		return (0);
	cnt.count_map[y][x]++;
	if (map_db->cnt.out == 1 && map_db->cnt.collect == map_db->collect)
		return (1);
	if (dfs (x - 1, y, cnt, map_db))
		return (1);
	if (dfs (x, y - 1, cnt, map_db))
		return (1);
	if (dfs (x + 1, y, cnt, map_db))
		return (1);
	if (dfs (x, y + 1, cnt, map_db))
		return (1);
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
