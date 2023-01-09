/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:48 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/09 21:00:36 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		return (NULL);
	files->fd = fd;
	files->backup = 0;
	files->next = 0;
	if (!temp)
		*lst = files;
	else
		temp->next = files;
	return (files);
}

char	*get_next_line(int fd)
{
	static t_fileinfo	*lst;		//연결리스트로 된 구조체들의 첫번째 주소
	t_fileinfo			*files;		//현재 사용할 구조체주소

	files = ft_find_fd(&lst, fd);	//fd로 구분하여 현재 사용할 파일정보 반환함. 
	if (!files)
		return (0);					//파일정보가담긴구조체생성시 동작할당오류로 실패시 종료
	//연결리스트 연결 완료. 여기까지 특징 : lst는 항상 연결리스트에 가장 첫주소를 가지고 있다. , files은 현재사용할 구조체주소를 가지고 있다.
//  1. 버퍼읽기 전에 backup에 문자가 있는지 확인한다.
//		개행이 "있다면" 개행까지 print_get에 저장, backup엔 개행까지삭제 후 남은 문자열 저장, print_get반환하며 함수 종료
//		개행이 "없다면" 다음 단계 이동
//	2. 개행이 나올때까지 버퍼를 읽는다. 버퍼를 읽은만큼 backup에 이어 붙인다(backup뒤는 null로 처리시도)
//		개행까지만 print_get에 복사, backup에선 개행까진 삭제한다.
//	3. print_get 반환

	return (0);
}