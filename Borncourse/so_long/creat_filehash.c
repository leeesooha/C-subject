/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_filehash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:52:32 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/17 23:33:33 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	creat_filehash(t_mlx_data *mlx_db)
{
	mlx_db->file = (char **)ft_calloc(sizeof(char *), 257);
	if (!mlx_db->file)
		ft_end (mlx_db, mlx_db->row_len, 1);
	(mlx_db->file)['0'] = ft_strdup("./imgfile/back_ground.xpm");
	(mlx_db->file)['1'] = ft_strdup("./imgfile/wall.xpm");
	(mlx_db->file)['C'] = ft_strdup("./imgfile/collect.xpm");
	(mlx_db->file)['E'] = ft_strdup("./imgfile/exit.xpm");
	(mlx_db->file)['P'] = ft_strdup("./imgfile/yoda.xpm");
	(mlx_db->file)['S'] = ft_strdup("./imgfile/start.xpm");
	return (filehash_check(mlx_db));
}

int	filehash_check(t_mlx_data *mlx_db)
{
	if (!(mlx_db->file)['0'] || !(mlx_db->file)['1'] || !(mlx_db->file)['C']
		|| !(mlx_db->file)['E'] || !(mlx_db->file)['P'] || !(mlx_db->file)['S'])
	{
		if ((mlx_db->file)['0'])
			free ((mlx_db->file)['0']);
		if ((mlx_db->file)['1'])
			free ((mlx_db->file)['1']);
		if ((mlx_db->file)['C'])
			free ((mlx_db->file)['C']);
		if ((mlx_db->file)['E'])
			free ((mlx_db->file)['E']);
		if ((mlx_db->file)['P'])
			free ((mlx_db->file)['P']);
		if ((mlx_db->file)['S'])
			free ((mlx_db->file)['S']);
		free(mlx_db->file);
		ft_end(mlx_db, mlx_db->row_len, 1);
	}
	return (1);
}
