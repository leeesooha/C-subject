/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_filehash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:52:32 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/25 21:41:47 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static int	file_free(t_mlx_data *mlx_db);

int	creat_filehash(t_mlx_data *mlx_db)
{
	mlx_db->file = (char **)ft_calloc(sizeof(char *), 257);
	if (!mlx_db->file)
		ft_end (mlx_db, mlx_db->row_len, FD_MOLLOC_ERROR);
	(mlx_db->file)['0'] = ft_strdup("./imgfile/back_ground.xpm");
	(mlx_db->file)['1'] = ft_strdup("./imgfile/wall.xpm");
	(mlx_db->file)['c'] = ft_strdup("./imgfile/collect.xpm");
	(mlx_db->file)['e'] = ft_strdup("./imgfile/exit.xpm");
	(mlx_db->file)['P'] = ft_strdup("./imgfile/yoda1.xpm");
	(mlx_db->file)['O'] = ft_strdup("./imgfile/yoda2.xpm");
	(mlx_db->file)['S'] = ft_strdup("./imgfile/start.xpm");
	(mlx_db->file)['D'] = ft_strdup("./imgfile/enemy.xpm");
	(mlx_db->file)['N'] = ft_strdup("./imgfile/loopyexit.xpm");
	return (filehash_check(mlx_db));
}

int	filehash_check(t_mlx_data *mlx_db)
{
	if (!(mlx_db->file)['0'] || !(mlx_db->file)['1'] || !(mlx_db->file)['c']
		|| !(mlx_db->file)['e'] || !(mlx_db->file)['P'] || !(mlx_db->file)['S']
		|| !(mlx_db->file)['O'] || !(mlx_db->file)['D'] || !(mlx_db->file)['N'])
	{
		file_free(mlx_db);
		free(mlx_db->file);
		ft_end(mlx_db, mlx_db->row_len, FD_MOLLOC_ERROR);
	}
	return (1);
}

static int	file_free(t_mlx_data *mlx_db)
{
	if ((mlx_db->file)['0'])
		free ((mlx_db->file)['0']);
	if ((mlx_db->file)['1'])
		free ((mlx_db->file)['1']);
	if ((mlx_db->file)['c'])
		free ((mlx_db->file)['c']);
	if ((mlx_db->file)['e'])
		free ((mlx_db->file)['e']);
	if ((mlx_db->file)['P'])
		free ((mlx_db->file)['P']);
	if ((mlx_db->file)['S'])
		free ((mlx_db->file)['S']);
	if ((mlx_db->file)['O'])
		free ((mlx_db->file)['O']);
	if ((mlx_db->file)['D'])
		free ((mlx_db->file)['D']);
	if ((mlx_db->file)['N'])
		free ((mlx_db->file)['N']);
	return (0);
}
