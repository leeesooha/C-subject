/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:03:49 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/29 20:19:44 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_check(t_data *data)
{
	int		i;
	char	*temp;
	char	*path_cmd;

	data->sp_cmd = cmd_split(data);
	i = 0;
	while (data->envpaths[i])
	{
		temp = ft_strjoin(data->envpaths[i], "/");
		if (!temp)
			all_free(data, 4, 0, 1);
		path_cmd = ft_strjoin(temp, data->sp_cmd[0]);
		if (!path_cmd)
			all_free(data, 4, temp, 1);
		free(temp);
		if (access(path_cmd, X_OK) == 0)
		{
			data->path_cmd = path_cmd;
			return (0);
		}
		else
			free(path_cmd);
		i++;
	}
	all_free(data, 4, 0, 3);
	return (0);
}

char	**cmd_split(t_data *data)
{
	char	*temp;
	char	**sp_cmd;
	int		i;

	if (ft_strncmp(data->cmd[data->pipenum], "awk ", 4) == 0)
	{
		sp_cmd = ft_split(data->cmd[data->pipenum], '\'');
		if (!sp_cmd)
			all_free(data, 3, 0, 1);
		i = 0;
		while (sp_cmd[i])
		{
			temp = sp_cmd[i];
			sp_cmd[i] = ft_strtrim(sp_cmd[i], " ");
			free(temp);
			if (!sp_cmd[i])
				all_free(data, 4, 0, 1);
			i++;
		}
	}
	else
		sp_cmd = ft_split(data->cmd[data->pipenum], ' ');
	if (!sp_cmd)
		all_free(data, 3, 0, 1);
	return (sp_cmd);
}