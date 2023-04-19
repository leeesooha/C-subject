/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:23:26 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/19 23:24:57 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static	int	dfs(int x, int y, t_count cnt, t_map_data *map_db);

int	path_valid_check(t_map_data *map_db)
{
	int	x;
	int	y;
	int	i;

	x = map_db->start_xy[0];
	y = map_db->start_xy[1];
	map_db->cnt.collect = 0;
	map_db->cnt.empty = 0;
	map_db->cnt.out = 0;
	map_db->cnt.start = 0;
	map_db->cnt.wall = 0;
	map_db->validpath = 0;
	map_db->cnt.from = 0;
	i = 0;
	map_db->cnt.count_map = (char **)malloc(sizeof(char *) * map_db->row_len);
	while (i < map_db->row_len)
	{
		map_db->cnt.count_map[i] = (char *)malloc(sizeof(char)
				* map_db->col_len);
		ft_memset(map_db->cnt.count_map[i], '0', map_db->col_len);
		i++;
	}
	if (dfs(x, y, map_db->cnt, map_db))
		return (1);
	return (0);
}

static	int	dfs(int x, int y, t_count cnt, t_map_data *map_db)
{
	if (cnt.count_map[y][x] >= '1' || map_db->map[y][x] == '1')
		return (0);
	if (map_db->map[y][x] == 'E')
		return (1);
	cnt.count_map[y][x]++;
	cnt.from = 1;
	if (cnt.from != 3)
		if (dfs (x - 1, y, cnt, map_db))
			return (1);
	cnt.from = 2;
	if (cnt.from != 4)
		if (dfs (x, y - 1, cnt, map_db))
			return (1);
	cnt.from = 3;
	if (cnt.from != 1)
		if (dfs (x + 1, y, cnt, map_db))
			return (1);
	cnt.from = 4;
	if (cnt.from != 2)
		if (dfs (x, y + 1, cnt, map_db))
			return (1);
	cnt.count_map[y][x]++;
	return (0);
}
