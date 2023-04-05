/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:46:28 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/05 12:53:24 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(t_config *flag, int idx, int err_flag)
{
	if (flag != 0)
		free_double(flag->map, idx);
	if (err_flag == 0)
		perror("");
	else if (err_flag == 1)
	{
		write(2, "Error\n", 6);
		write(2, "Invalid map\n", 12);
	}
	exit (1);
}

int	free_double(char **s, int idx)
{
	while (1)
	{
		if (idx == -1)
			break ;
		free(s[idx--]);
	}
	free(s);
	return (0);
}
