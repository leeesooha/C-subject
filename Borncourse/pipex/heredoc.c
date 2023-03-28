/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:22:26 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/28 21:18:54 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	heredoc_chk(t_data *data)
{
	if (ft_strncmp("here_doc", data->argv[1], 9))
	{
		data->heredoc = 0;
		data->hdflag = 0;
		return (0);
	}
	data->heredoc = (char **)ft_calloc(sizeof(char *), 3);
	data->heredoc[0] = ft_strdup("here_doc");
	data->heredoc[1] = ft_strdup(data->argv[2]);
	data->hdflag = 1;
	return (0);
}

int	heredoc(t_data *data)
{
	char	*buff;
	char	herefd;
	char	*endflag;

	herefd = open("here_doc_tmp", O_WRONLY);
	endflag = ft_strjoin(data->argv[2], "\n");
	while (1)
	{
		buff = get_next_line(0);
		if (ft_strncmp(buff, endflag, ft_strlen(endflag)) == 0)
		{
			free(buff);
			free(endflag);
			close(herefd);
			return (0);
		}
		write(herefd, buff, ft_strlen(buff));
		if (buff)
			free(buff);
	}
	return (0);
}
