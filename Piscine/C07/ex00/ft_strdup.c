/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 07:24:27 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/08 22:20:25 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*src2;

	i = 0;
	while (src[i])
		i++;
	src2 = (char *)malloc(sizeof(char) * i + 1);
	if (src2 == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = 0;
	return (src2);
}
