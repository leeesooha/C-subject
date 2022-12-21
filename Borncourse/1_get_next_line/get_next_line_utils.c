/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:52:27 by soohlee           #+#    #+#             */
/*   Updated: 2022/12/21 00:52:44 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c1)
			return ((char *)s1 + i);
		i++;
	}
	if (c1 == 0)
		return ((char *)s1 + i);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	start;
	size_t	end;
	char	*ms1;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	ms1 = ft_substr(s1, start, end - start);
	return (ms1);
}

char	*ft_substr(char *s, int start, size_t len)
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
