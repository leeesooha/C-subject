/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:02:59 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/14 17:44:46 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ma;
	int	i;

	i = 0;
	ma = (int *)malloc(sizeof(int) * (length));
	while (i < length)
	{
		ma[i] = f(tab[i]);
		i++;
	}
	return (ma);
}
