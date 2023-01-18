/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:48 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/18 11:06:26 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
int		find_file(t_fileinfo **lst, int fd, t_fileinfo **files);
char	*free_fd(t_fileinfo **lst, t_fileinfo **files);
int		get_buff(t_fileinfo **files);
int		get_print(char **res_str, t_fileinfo **file);

char	*get_next_line(int fd)
{
	static t_fileinfo	*lst;
	t_fileinfo			*files;
	char				*res_str;

	if (fd < 0)
		return (0);
	if (!(find_file(&lst, fd, &files)))
		return (0);
	if (!(files->backup))
	{
		free_fd(&lst, &files);
		return (0);
	}
	if (!(get_buff(&files)))
		return (free_fd(&lst, &files));
	if (!(get_print(&res_str, &files)))
		return (free_fd(&lst, &files));
	return (res_str);
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
	if (!*files)
		return (0);
	(*files)->fd = fd;
	(*files)->backup = ft_strdup("");
	(*files)->next = NULL;
	if (!(*lst))
		*lst = *files;
	else
		before_temp->next = *files;
	return (1);
}

char	*free_fd(t_fileinfo **lst, t_fileinfo **files)
{
	t_fileinfo	*cur_node;
	t_fileinfo	*prev_node;

	cur_node = *lst;
	if (cur_node == *files)
		*lst = cur_node->next;
	else
	{
		while (cur_node != *files)
		{
			prev_node = cur_node;
			cur_node = cur_node->next;
		}
		prev_node->next = cur_node->next;
	}
	if (cur_node->backup)
		free(cur_node->backup);
	free(cur_node);
	return (NULL);
}

int	get_buff(t_fileinfo **files)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_len;
	char	*temp;

	while (!(ft_strchr((*files)->backup, '\n')))
	{
		read_len = read((*files)->fd, buff, BUFFER_SIZE);
		if (read_len == -1 || (read_len == 0 && *(*files)->backup == '\0'))
			return (0);
		if (read_len == 0)
			return (1);
		buff[read_len] = '\0';
		temp = (*files)->backup;
		(*files)->backup = ft_strjoin((*files)->backup, buff);
		free(temp);
		if (!((*files)->backup))
			return (0);
	}
	return (1);
}

int	get_print(char **res_str, t_fileinfo **file)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (((*file)->backup)[i] && ((*file)->backup)[i] != '\n')
		i++;
	*res_str = ft_substr((*file)->backup, 0, i + 1);
	if (!(*res_str))
		return (0);
	temp = (*file)->backup;
	(*file)->backup = ft_substr((*file)->backup, i + 1, -1);
	free(temp);
	if (!((*file)->backup))
	{
		free(*res_str);
		return (0);
	}
	return (1);
}
