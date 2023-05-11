/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:18:16 by soohlee           #+#    #+#             */
/*   Updated: 2023/02/08 21:50:20 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;

	s1s2 = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1s2)
		return (0);
	ft_strlcat(s1s2, s1, ft_strlen(s1s2) + ft_strlen(s1) + 1);
	ft_strlcat(s1s2, s2, ft_strlen(s1s2) + ft_strlen(s2) + 1);
	return (s1s2);
}
