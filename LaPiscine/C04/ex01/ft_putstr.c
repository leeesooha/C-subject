/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:40:14 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/05 18:33:36 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar01(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int				i;
	unsigned char	*str2;

	str2 = (unsigned char *) str;
	i = 0;
	while (str2[i])
	{
		ft_putchar01(str2[i]);
		i++;
	}
}
