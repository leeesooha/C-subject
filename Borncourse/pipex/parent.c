/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:11:24 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/28 20:24:25 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parent(t_data *data)
{
	int	i;

	i = 0;
//	if (data->pipenum == data->npipe - 1)
//	{
		while (data->npipe > i)
		{
			close(data->pipefd[i][0]);
			close(data->pipefd[i][1]);
			i++;
		}
//	}
	return (0);
}