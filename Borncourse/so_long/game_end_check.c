/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:17:44 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 20:14:46 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	game_end_check(t_mlx_data *mlx_db)
{
	if ((mlx_db->eat_count == mlx_db->collect)
		&& mlx_db->map[mlx_db->xy[1]][mlx_db->xy[0]] == 'e')
		ft_end(mlx_db, mlx_db->row_len, SUCCESS);
	return (0);
}
