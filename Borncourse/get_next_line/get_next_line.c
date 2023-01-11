/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:48 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/11 20:55:07 by soohlee          ###   ########.fr       */
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
	
	// 1. print_get에 backup이어 붙이기
	// 2. 백업에 새 버퍼 읽어오기
	// 3. 새버퍼 print_get에 이어붙이기
	// 4. 개행 찾으면 print_get개행전까지 자르고, 백업은 개행이후부터 저장 후 print_get반환 종료.
//참고 조건
	// while (!(ft_strchr((files->backup), '\n'))),
	// 	{ read반환:0 && backup에 아무것도 없으면 메인 함수 종료 }
	// 	{ read반환:0 && backup에 뭐라도 있으면 있는거 출력변수에 옮기고 백업프리후 종료 }
	return (get_print);
}

// 헷갈린점 : read사용시 buf는 버퍼사이즈로 기반으로 변수를 만들어야 한다. 
// ex) char buf[BUFFER_SIZE]; read(fd, buf, BUFFER_SIZE);

// 궁금중 : 
// 2. 연결리스트 전체는 언제 해제하는것인가?

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
		return (0);		//파일을 만들때실패했다면 겟넷라 종료
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
