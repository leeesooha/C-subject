/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:03:49 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/29 12:42:05 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_check(t_data *data)
{
	int		i;
	char	*temp;
	char	*path_cmd;
	char	**sp_cmd;


	sp_cmd = cmd_split(data);
	i = 0;
	while (data->envpaths[i])
	{
		temp = ft_strjoin(data->envpaths[i], "/");
		path_cmd = ft_strjoin(temp, sp_cmd[0]);
		free(temp);
		if (access(path_cmd, X_OK) == 0)
		{
			data->path_cmd = path_cmd;
			data->sp_cmd = sp_cmd;
			return (0);
		}
		else
			free(path_cmd);
		i++;
	}
	free(sp_cmd);
	all_free(data, 2);
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
		i = 0;
		while (sp_cmd[i])
		{
			temp = sp_cmd[i];
			sp_cmd[i] = ft_strtrim(sp_cmd[i], " ");
			free(temp);
			i++;
		}
		return (sp_cmd);
	}
	else
	{
		sp_cmd = ft_split(data->cmd[data->pipenum], ' ');
		return (sp_cmd);
	}
	return (0);
}