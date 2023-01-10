/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:46 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/10 16:43:59 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*m1;
	size_t	i;
	size_t	after_len;

	i = 0;
	if ((ft_strlen((s)) < start) || s == 0)
		return (ft_strdup(""));
	after_len = ft_strlen(s + start);
	if (after_len < len)
		len = after_len;
	s = s + start;
	m1 = (char *)malloc(sizeof(char) * len + 1);
	if (m1 == 0)
		return (0);
	while (i < len && i < after_len)
	{
		m1[i] = s[i];
		i++;
	}
	m1[i] = 0;
	return (m1);
}
