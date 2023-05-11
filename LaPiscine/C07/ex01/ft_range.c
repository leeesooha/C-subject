/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:51:28 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/11 11:20:29 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*ary;
	long long	size;
	int			i;

	if (min >= max)
		return (ary = 0);
	size = (long long)max - min;
	ary = (int *)malloc(sizeof(int) * (int)size);
	if (ary == 0)
		return (0);
	i = 0;
	while (i < (int)size)
	{
		ary[i] = min + i;
		i++;
	}
	return (ary);
}
