/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:47:16 by soohlee           #+#    #+#             */
/*   Updated: 2022/12/21 09:17:25 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	ssize_t			bytelength;
	char			*resbuffer;

	resbuffer = find_newline(fd, buffer, &bytelength);
	if (bytelength == -1)
		return (0);
	return (resbuffer);
}

char	*find_newline(int fd, char *buffer, ssize_t *bytelength)
{
	char	*resbuffer;

	resbuffer = ft_strdup(buffer);
	while (!ft_strchr(buffer, '\n') && !ft_strchr(buffer, '\0'))
	{
		*bytelength = read(fd, buffer, BUFFER_SIZE);
		if (*bytelength == -1)
			return (0);
		printf("%s\n",resbuffer);
		resbuffer = ft_strjoin(resbuffer, buffer);
	}
	return (del_newline(resbuffer));
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(i + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*del_newline(char *resbuffer)
{
	size_t	i;

	i = 0;
	while (resbuffer[i] != '\n' && resbuffer[i])
		i++;
	return (ft_substr(resbuffer, 0, i));
}
