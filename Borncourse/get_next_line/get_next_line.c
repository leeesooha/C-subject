/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:48 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/10 21:27:32 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	}
}

t_fileinfo	*ft_find_fd(t_fileinfo **lst, int fd)
{
	t_fileinfo	*files;
	t_fileinfo	*temp;

	temp = *lst;
	while (temp && temp->next)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	files = (t_fileinfo *)malloc(sizeof(t_fileinfo));
	if (!files)
		return (0);		//파일을 만들때실패했다면 겟넷라 종료
	files->fd = fd;
	files->backup = 0;
	files->next = 0;
	if (!temp)
		*lst = files;
	else
		temp->next = files;
	return (files);
}

int	check_backup(char **get_print, t_fileinfo **lst, t_fileinfo *files)
{
	size_t		i;
	t_fileinfo	*lst_temp;

	lst_temp = *lst;
	i = 0;
	while (files->backup[i])
	{
		if (files->backup[i] == '\n')
		{
			*get_print = ft_substr(files->backup, 0, i);
			if (!get_print)
			{
				get_print = free_fd(*lst, files);		//백업삭제 후 fd삭제 후 양옆노드연결
				return (0);
			}
			// 성공시 백업을 개행전까지 삭제;
			return (0);
		}
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_fileinfo	*lst;
	t_fileinfo			*files;
	char				*get_print;

	files = ft_find_fd(&lst, fd);
	if (!files)
		return (0);
	if (!check_backup(&get_print, &lst, files))
		return (get_print);
	
	return (0);
}

//check_backup이 실패시 && 개행찾을시 0 리턴종료 후 get_print반환(실패시 get_print에 널포인터대입) , 개행 못찾으면 복사할 문자가 없으므로 get_print에 아무동작하지 않고 1리턴
