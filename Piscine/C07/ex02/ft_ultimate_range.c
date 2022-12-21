/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:51:49 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/11 14:15:40 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	int			i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = (long long)max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		*((*range) + i) = min + i;
		i++;
	}
	return (max - min);
}
