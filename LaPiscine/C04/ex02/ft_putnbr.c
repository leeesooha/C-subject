/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:44:07 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/04 11:51:43 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar02(char c)
{
	c += '0';
	write (1, &c, 1);
}

void	printnbr(long long bnb)
{
	if (bnb >= 10)
		printnbr (bnb / 10);
	ft_putchar02 (bnb % 10);
}

void	ft_putnbr(int nb)
{
	long long	bnb;

	bnb = nb;
	if (bnb >= 0)
	{
		printnbr(bnb);
	}
	else if (bnb < 0)
	{
		write (1, "-", 1);
		printnbr (-bnb);
	}
}
