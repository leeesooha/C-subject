/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:13:23 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/06 15:58:07 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long		i;
	unsigned char	c1;

	c1 = (unsigned char)c;
	i = ft_strlen(s);
	while (i)
	{
		if (s[i] == c1)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == c1)
		return ((char *)(s + i));
	return (0);
}
