/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:35:12 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/15 10:33:51 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s;

	s = (t_list *)malloc(sizeof(t_list));
	if (s == 0)
		exit (1);
	s->content = content;
	s->next = 0;
	return (s);
}
