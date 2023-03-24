/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:55:13 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/24 18:54:31 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int cmd_check(t_data *args, char *cmd)
{
    int     i;
    char    *temp;
    char    *full_namecmd;

    cmd = ft_substr(cmd, 0, space_idx(cmd));
    if (!cmd)
        all_free(args, 4);
    i = 0;
    while (args->envpaths[i])
    {
        full_namecmd = ft_strjoin("/", cmd);
        if (!full_namecmd)
           all_free(args, 4);
        temp = full_namecmd;
        full_namecmd = ft_strjoin(args->envpaths[i], full_namecmd);
        free(temp);
        if (access(full_namecmd, X_OK) == 0)
        {
            args->full_namecmd[args->pipenum] = full_namecmd;
            return (0);
        }
        free(full_namecmd);
        i++;
    }
    all_free(args, 4);
    return (-1);
}

int space_idx(char *cmd)
{
    int i;

    i = 0;
    while(cmd[i] && cmd[i] != ' ')
        i++;
    return (i);
}