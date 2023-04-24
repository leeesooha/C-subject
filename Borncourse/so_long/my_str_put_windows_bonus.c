/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str_put_windows_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:32:23 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 18:39:16 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long_bonus.h"

int	my_str_put_window(t_mlx_data *mlx_db, int width, int height, char img)
{
	char	*num;

	mlx_db->img = mlx_xpm_file_to_image(mlx_db->mlx,
			mlx_db->file[(int) img], &width, &height);
	mlx_db->addr = mlx_get_data_addr(mlx_db->img, &(mlx_db->bpp),
			&(mlx_db->line_len), &(mlx_db->endian));
	mlx_put_image_to_window(mlx_db->mlx, mlx_db->win, mlx_db->img,
		(mlx_db->col_len -1) * width, 0 * height);
	num = ft_itoa(++mlx_db->print_cnt);
	if (!num)
		ft_end(mlx_db, mlx_db->row_len, 7);
	mlx_string_put(mlx_db->mlx, mlx_db->win,
		(((mlx_db->col_len) * width) - width / 2) - 10,
		height / 2, 0xffffff, num);
	free(num);
	return (1);
}
