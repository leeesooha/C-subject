/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:11:24 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/24 20:14:31 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parent(t_data *args)
{
    int i;

    i = 0;
    if (args->pipenum == args->pipe_total - 1)
    {
        while (args->pipe_total > i)
        {
            close(args->pipefd[i][0]);
            close(args->pipefd[i][1]);
            i++;
        }
    }
    return (0);
}