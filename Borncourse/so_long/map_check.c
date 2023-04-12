/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:38:15 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/12 20:09:22 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *file, char ***map, int *map_weight, int *map_height)
{
	t_config	flag;

	flag.collect = 0;
	flag.empty = 0;
	flag.out = 0;
	flag.start = 0;
	flag.wall = 0;
	read_map(file, &flag, map_weight, map_height);
//	path_check(flag);
	int	i;
	i = 0;
	while (flag.map[i])
	{
		printf("%s", flag.map[i]);
		i++;
	}
	printf("\n");
	*map = flag.map;
	if (map == 0)
		return (0);
	return (0);
}

int	read_map(char *file, t_config *flag, int *map_weight, int *map_height)
{
	int			fd;
	char		*buff;
	int			buff_len;
	int			map_row_len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error (0, 0, 1);
	map_row_len = nl_len(file, &buff_len);
	*map_height = map_row_len;
	flag->map = (char **)malloc(sizeof(char *) * map_row_len + 1);
	if (!flag->map)
		ft_error (0, 0, 1);
	flag->idx = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		flag->map[(flag->idx)++] = buff;
	}
	close(fd);
	flag->map[flag->idx] = 0;
	if (config_check(flag, map_row_len, buff_len) == -1)
		ft_error(flag, flag->idx - 1, 2);
	*map_weight = ft_strlen(flag->map[0]) - 1;
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

int	config_check(t_config *flag, int map_row_len, int buff_len)
{
	int	idx;
	int	jdx;

	idx = -1;
	while (flag->map[++idx])
	{
		if (!(flag->map[idx][0] == '1' && flag->map[idx][buff_len - 2] == '1'))
			return (-1);
		jdx = -1;
		while (flag->map[idx][++jdx] && flag->map[idx][jdx] != '\n')
		{
			if (!(flag->map[0][jdx] == '1'
				&& flag->map[map_row_len - 1][jdx] == '1'))
				return (-1);
			if (flagging(flag->map[idx][jdx], flag, idx, jdx) == -1)
				return (-1);
		}
		if (buff_len - 1 != jdx)
			return (-1);
	}
	if (map_row_len != idx || flag->start != 1
		|| flag->out != 1 || flag->collect < 1)
		return (-1);
	return (0);
}

int	flagging(char c, t_config *flag, int idx, int jdx)
{
	if (c == '0')
		(flag->empty)++;
	else if (c == '1')
		(flag->wall)++;
	else if (c == 'C')
		(flag->collect)++;
	else if (c == 'E')
		(flag->out)++;
	else if (c == 'P')
	{
		flag->start_xy[0] = jdx;
		flag->start_xy[1] = idx;
		(flag->start)++;
	}
	else
		return (-1);
	return (0);
}
