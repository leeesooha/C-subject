/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:59:56 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/15 16:42:47 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(long res)
{
	if (res < 0)
	{
		res = -res;
		write(1, "-", 1);
	}
	if (res >= 10)
		print(res / 10);
	write (1, &"0123456789"[res % 10], 1);
}

void	midcal(int a, int b, char *str)
{
	int	res;

	if (*str == '+')
		res = a + b;
	else if (*str == '-')
		res = a - b;
	else if (*str == '*')
		res = a * b;
	else if (*str == '/')
		res = a / b;
	else
		res = a % b;
	print((long)res);
}
