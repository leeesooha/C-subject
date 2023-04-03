/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:38:15 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/03 19:41:26 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *file, char **map)
{
	t_config	flag;

	flag.collect = 0;
	flag.empty = 0;
	flag.out = 0;
	flag.start = 0;
	flag.wall = 0;
	read_map(file, &flag);
	return (0);
}

int	read_map(char *file, t_config *flag)
{
	int			fd;
	char		*buff;
	long long	idx;
	int			buff_len;
	int			map_row_len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(0, 0);
	map_row_len = nl_len(file, flag->map, &buff_len);
	flag->map = (char **)malloc(sizeof(char *) * map_row_len + 1);
	if (!flag->map)
		print_error(0);
	idx = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (buff_check(buff, buff_len, flag, map_row_len) == -1)
			free_double(flag->map, idx - 1);
		flag->map[idx++] = buff;
	}
	config_check(flag, map_row_len, buff_len);
	return (0);
}

int	nl_len(char *file, char **map, int *buff_len)
{
	int		fd;
	char	*buff;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error(0);
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
	close(file);
	return (len);
}

int	buff_check(char *buff, int buff_len, t_config *flag, int map_row_len)
{
	int	len;

	if (buff_len != ft_strlen(buff) || buff_len <= 3)
		return (-1);
	if (!(buff[0] == 1 && buff[buff_len - 2] == 1))
		return (-1);
	if (!ft_strchr(buff, '0'))
		(flag->empty)++;
	if (!ft_strchr(buff, '1'))
		(flag->wall)++;
	if (!ft_strchr(buff, 'C'))
		(flag->collect)++;
	if (!ft_strchr(buff, 'E'))
		(flag->out)++;
	if (!ft_strchr(buff, 'P'))
		(flag->start)++;
	return (0);
}

int	config_check(t_config *flag, int map_row_len, int buff_len)
{
	int	idx;

	idx = 0;
	if (!flag->collect || !flag->start || !flag->out)
		free_double(flag->map, map_row_len);
	while (buff_len--)
	{
		if (flag->map[0][idx] != 1)
			free_double(flag->map, map_row_len);
		idx++;
	}
	retrun (0);
}
