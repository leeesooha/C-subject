/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:43:53 by soohlee           #+#    #+#             */
/*   Updated: 2022/08/27 16:53:14 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k <= 7)
	{	
		j = k + 1;
		while (j <= 8)
		{	
			i = j + 1;
			while (i <= 9)
			{	
				ft_putchar(k + '0');
				ft_putchar(j + '0');
				ft_putchar(i + '0');
				if (k < 7)
					write(1, ", ", 2);
				i++;
			}
			j++;
		}
		k++;
	}
}
