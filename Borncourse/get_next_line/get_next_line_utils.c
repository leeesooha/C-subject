/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:46 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/11 15:59:42 by soohlee          ###   ########.fr       */
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*m_s;
	size_t	i;

	if (start > len)
		return (ft_strdup(""));
	if (start)
	{
		len = len - start + 1;
		s = s + start;
	}
	i = 0;
	m_s = (char *)malloc(sizeof(char) * len + 1);
	if (m_s == 0)
		return (0);
	while (i < len)
	{
		m_s[i] = s[i];
		i++;
	}
	m_s[i] = 0;
	return (m_s);
}
