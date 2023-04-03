/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:46:28 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/03 18:20:07 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char **s, int flag)
{
	if (flag == 0)
		perror("");
	exit (1);
}

int	free_double(char **s, int idx)
{
	if (s == 0)
		ft_error(0, 0);
	while (1)
	{
		if (idx == -1)
			break ;
		free(s[idx--]);
	}
	free(s);
	ft_error(0, 0);
	return (0);
}
