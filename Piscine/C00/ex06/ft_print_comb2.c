/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:07:04 by soohlee           #+#    #+#             */
/*   Updated: 2022/08/27 16:55:36 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print(int a, int b)
{
	int	a1;
	int	b1;

	a1 = a % 10;
	b1 = b % 10;
	ft_putchar (a / 10 + '0');
	ft_putchar (a1 + '0');
	ft_putchar (' ');
	ft_putchar (b / 10 + '0');
	ft_putchar (b1 + '0');
}	

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print(a, b);
			if (a < 98)
				write(1, ", ", 2);
			b++;
		}
	a++;
	}
}
