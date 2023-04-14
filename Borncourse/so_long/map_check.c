/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:38:15 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/14 16:22:33 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *file, t_map_data *map_db)
{
	map_db->collect = 0;
	map_db->empty = 0;
	map_db->out = 0;
	map_db->start = 0;
	map_db->wall = 0;
	read_map(file, map_db);
//	path_check(flag);
	int	i;
	i = 0;
	while (map_db->map[i])
	{
		printf("%s", map_db->map[i]);
		i++;
	}
	printf("\n");
	if (map_db->map == 0)
		return (0);
	return (0);
}

int	read_map(char *file, t_map_data *map_db)
{
	int			fd;
	char		*buff;
	int			buff_len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error (0, 0, 1);
	map_db->row_len = nl_len(file, &buff_len);
	map_db->map = (char **)malloc(sizeof(char *) * map_db->row_len + 1);
	if (!map_db->map)
		ft_error (0, 0, 1);
	map_db->idx = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		map_db->map[(map_db->idx)++] = buff;
	}
	close(fd);
	map_db->map[map_db->idx] = 0;
	if (config_check(map_db, buff_len) == -1)
		ft_error(map_db, map_db->idx - 1, 2);
	map_db->col_len = ft_strlen(map_db->map[0]) - 1;
	return (0);
}

int	nl_len(char *file, int *buff_len)
{
	int		fd;
	char	*buff;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error (0, 0, 1);
	len = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		len++;
		*buff_len = ft_strlen(buff);
		free(buff);
	}
	(*buff_len)++;
	close(fd);
	return (len);
}

int	config_check(t_map_data *map_db, int buff_len)
{
	int	idx;
	int	jdx;

	idx = -1;
	while (map_db->map[++idx])
	{
		if (!(map_db->map[idx][0] == '1'
			&& map_db->map[idx][buff_len - 2] == '1'))
			return (-1);
		jdx = -1;
		while (map_db->map[idx][++jdx] && map_db->map[idx][jdx] != '\n')
		{
			if (!(map_db->map[0][jdx] == '1'
				&& map_db->map[map_db->row_len - 1][jdx] == '1'))
				return (-1);
			if (flagging(map_db->map[idx][jdx], map_db, idx, jdx) == -1)
				return (-1);
		}
		if (buff_len - 1 != jdx)
			return (-1);
	}
	if (map_db->row_len != idx || map_db->start != 1
		|| map_db->out != 1 || map_db->collect < 1)
		return (-1);
	return (0);
}

int	flagging(char c, t_map_data *map_db, int idx, int jdx)
{
	if (c == '0')
		(map_db->empty)++;
	else if (c == '1')
		(map_db->wall)++;
	else if (c == 'C')
		(map_db->collect)++;
	else if (c == 'E')
		(map_db->out)++;
	else if (c == 'P')
	{
		map_db->start_xy[0] = jdx;
		map_db->start_xy[1] = idx;
		(map_db->start)++;
	}
	else
		return (-1);
	return (0);
}
