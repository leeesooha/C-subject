/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:48 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/12 15:46:45 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_fileinfo	*lst;
	t_fileinfo			*files;
	char				*get_print;

	if (!(find_file(&lst, fd, &files)))
		return (0);
	if (!(files->backup))
	{
		free_fd(&lst, &files);
		return (0);
	}
	if (!(get_buff(&lst, &files)))
		return (free_fd(&lst, &files));
	return (get_print);
}

int	get_buff(t_fileinfo **lst, t_fileinfo **files)
{
	char	buff[BUFFER_SIZE];
	int		read_len;
	char	*temp;

	while (!(ft_strchr((*files)->backup, '\n')))
	{
		read_len = read((*files)->fd, buff, BUFFER_SIZE);
		if (read_len == -1 || )
			return (0);
		if (read_len == 0 && )
		buff[BUFFER_SIZE] = '\0';
		temp = (*files)->backup;
		(*files)->backup = ft_strjoin((*files)->backup, buff);
		if (!((*files)->backup))
		{
			free(temp);
			free_fd(&lst, &files);
			return (0);
		}
		free(temp);
		
	}
}

int	find_file(t_fileinfo **lst, int fd, t_fileinfo **files)
{
	t_fileinfo	*lst_temp;
	t_fileinfo	*before_temp;

	lst_temp = *lst;
	while (lst_temp)
	{
		if (lst_temp->fd == fd)
		{
			*files = lst_temp;
			return (1);
		}
		before_temp = lst_temp;
		lst_temp = lst_temp->next;
	}
	*files = (t_fileinfo *)malloc(sizeof(t_fileinfo));
	if (!*files || fd < 0)
		return (0);
	(*files)->fd = fd;
	(*files)->backup = ft_strdup("");
	(*files)->next = 0;
	if (!lst_temp)
		*lst = *files;
	else
		before_temp->next = *files;
	return (1);
}

int	free_fd(t_fileinfo **lst, t_fileinfo *files)
{
	t_fileinfo	*lst_temp;
	t_fileinfo	*next_temp;

	lst_temp = *lst;
	if (lst_temp->fd == files->fd)
	{
		next_temp = lst_temp->next;
		if (lst_temp->backup)
			free(lst_temp->backup);
		free(lst_temp);
		lst_temp = next_temp;
		*lst = lst_temp;
		return (0);
	}
	while (lst_temp->fd != files->fd)
	{
		next_temp = lst_temp;
		lst_temp = lst_temp->next;
	}
	next_temp->next = lst_temp->next;
	if (lst_temp->backup)
		free(lst_temp->backup);
	free(lst_temp);
	return (0);
}
