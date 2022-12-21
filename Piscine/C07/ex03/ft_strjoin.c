/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 08:45:47 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/11 13:45:25 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	length(char **strs, int size, char *sep)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
		}
		res += j;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	res = res + (i * (size - 1)) + 1;
	return (res);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*cpy(char *mystr, int size, char **strs, char *sep)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < size - 1)
	{
		mystr = ft_strcat(mystr, strs[i]);
		mystr = ft_strcat(mystr, sep);
		i++;
	}
	mystr = ft_strcat(mystr, strs[i]);
	return (mystr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*mystr;
	int		strsleng;

	if (size <= 0)
	{
		mystr = (char *)malloc(sizeof(char));
		*mystr = 0;
		return (mystr);
	}
	strsleng = length(strs, size, sep);
	mystr = (char *)malloc(sizeof(char) * (strsleng));
	*mystr = 0;
	if (mystr == 0)
		return (0);
	mystr = cpy(mystr, size, strs, sep);
	return (mystr);
}
