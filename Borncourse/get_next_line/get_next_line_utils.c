/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:46 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/12 15:46:50 by soohlee          ###   ########.fr       */
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

size_t	ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;
	char	c1;

	s1 = (char *)s;
	c1 = (char)c;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c1)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
	{
		free(s1);
		return (0);
	}
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
	{
		free(s1);
		return (0);
	}
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		new_str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
