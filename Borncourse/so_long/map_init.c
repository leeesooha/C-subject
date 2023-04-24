/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:38:15 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 20:14:36 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	map_init(char *mapfile, t_map_data *map_db, t_mlx_data *mlx_db)
{
	map_db->collect = 0;
	map_db->empty = 0;
	map_db->out = 0;
	map_db->start = 0;
	map_db->wall = 0;
	new_map(mapfile, map_db, mlx_db);
	map_db->map = mlx_db->map;
	valid_path_search(map_db, mlx_db);
	return (1);
}

int	new_map(char *mapfile, t_map_data *map_db, t_mlx_data *mlx_db)
{
	int			fd;
	char		*buff;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		ft_end (0, 0, FD_MOLLOC_ERROR);
	map_size(map_db, mapfile);
	mlx_db->col_len = map_db->col_len;
	mlx_db->row_len = map_db->row_len;
	mlx_db->map = (char **)malloc(sizeof(char *) * map_db->row_len + 1);
	if (!mlx_db->map)
		ft_end (0, 0, FD_MOLLOC_ERROR);
	map_db->idx = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		mlx_db->map[(map_db->idx)++] = buff;
	}
	close(fd);
	mlx_db->map[map_db->idx] = 0;
	map_check(map_db, mlx_db);
	return (1);
}

int	map_size(t_map_data *map_db, char *mapfile)
{
	int		fd;
	char	*buff;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		ft_end (0, 0, FD_MOLLOC_ERROR);
	map_db->row_len = 0;
	map_db->col_len = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		map_db->row_len++;
		map_db->col_len = ft_strlen(buff);
		free(buff);
	}
	close(fd);
	return (1);
}

int	map_check(t_map_data *map_db, t_mlx_data *mlx_db)
{
	int	y;
	int	x;

	if (map_db->idx != map_db->row_len)
		ft_end(mlx_db, map_db->idx + 1, FD_MOLLOC_ERROR);
	y = -1;
	while (mlx_db->map[++y])
	{
		if (!(mlx_db->map[y][0] == '1'
			&& mlx_db->map[y][map_db->col_len - 1] == '1'))
			ft_end(mlx_db, map_db->row_len, MAP_CONTENTS_ERROR);
		x = -1;
		while (mlx_db->map[y][++x] && mlx_db->map[y][x] != '\n')
		{
			if (!flagging(mlx_db, map_db, y, x))
				ft_end(mlx_db, map_db->row_len, MAP_CONTENTS_ERROR);
		}
		if (map_db->col_len != x)
			ft_end(mlx_db, map_db->row_len, MAP_CONTENTS_ERROR);
	}
	if (map_db->row_len != y || map_db->col_len != x
		|| (map_db->start != 1 || map_db->out != 1 || map_db->collect < 1))
		ft_end(mlx_db, map_db->row_len, MAP_CONTENTS_ERROR);
	return (1);
}

int	flagging(t_mlx_data *mlx_db, t_map_data *map_db, int y, int x)
{
	if (!(mlx_db->map[0][x] == '1'
		&& mlx_db->map[map_db->row_len - 1][x] == '1'))
		return (0);
	if (mlx_db->map[y][x] == '0')
		map_db->empty++;
	else if (mlx_db->map[y][x] == '1')
		map_db->wall++;
	else if (mlx_db->map[y][x] == 'C')
		map_db->collect++;
	else if (mlx_db->map[y][x] == 'E')
		map_db->out++;
	else if (mlx_db->map[y][x] == 'P')
	{
		map_db->start_xy[0] = x;
		map_db->start_xy[1] = y;
		(map_db->start)++;
	}
	else
		return (0);
	mlx_db->collect = map_db->collect;
	return (1);
}
