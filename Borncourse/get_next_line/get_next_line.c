/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:48 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/11 15:59:40 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_file(t_fileinfo **lst, int fd, t_fileinfo **files)
{
	t_fileinfo	*temp;

	temp = *lst;
	while (temp && temp->next)
	{
		if (temp->fd == fd)
		{
			*files = temp;
			return (1);
		}
		temp = temp->next;
	}
	*files = (t_fileinfo *)malloc(sizeof(t_fileinfo));
	if (!*files)
		return (0);		//파일을 만들때실패했다면 겟넷라 종료
	(*files)->fd = fd;
	(*files)->backup = 0;
	(*files)->next = 0;
	if (!temp)
		*lst = *files;
	else
		temp->next = *files;
	return (1);
}

// 백업삭제 후 fd삭제 후 양옆노드연결, 성공시 백업을 개행전까지 삭제;
int	check_backup_newline(char **get_print, t_fileinfo **lst, t_fileinfo *files)
{
	size_t		i;
	t_fileinfo	*lst_temp;
	char		*temp;

	lst_temp = *lst;
	i = 0;
	while (files->backup[i])
	{
		if (files->backup[i] == '\n')
		{
			*get_print = ft_substr(files->backup, 0, i);
			if (!*get_print)
				return (free_fd(*lst, files));
			temp = ft_substr(files->backup, i + 1, ft_strlen(files->backup));
			if (!temp)
				return (free_fd(*lst, files));
			free(files->backup);
			files->backup = temp;
			return (0);
		}
		i++;
	}
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
	free(lst_temp->backup);
	free(lst_temp);
	return (0);
}

int	free_lst(t_fileinfo **lst)
{
	t_fileinfo	*next_temp;
	t_fileinfo	*lst_temp;

	lst_temp = *lst;
	while (lst_temp)
	{
		next_temp = lst_temp->next;
		free(lst_temp->backup);
		free(lst_temp);
		lst_temp = next_temp;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fileinfo	*lst;
	t_fileinfo			*files;
	char				*get_print;

	if (!(find_file(&lst, fd, &files)))
		return (0);
	if (!check_backup_newline(&get_print, &lst, files))
		return (get_print);
	
	return (0);
}


