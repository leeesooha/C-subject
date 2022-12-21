/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:32:32 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/01 15:27:48 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar12(char c)
{
	write (1, &c, 1);
}

void	baseprint1(unsigned long long base1, int k)
{
	const char	*hexa;

	hexa = "0123456789abcdef";
	if (k > 0)
		baseprint1(base1 / 16, k - 1);
	ft_putchar12 (hexa[base1 % 16]);
	if (k == 16)
		write (1, ":", 1);
}

void	baseprint2(char *str)
{
	int			i;
	const char	*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		ft_putchar12(hexa[(unsigned char)str[i] / 16]);
		ft_putchar12(hexa[(unsigned char)str[i] % 16]);
		i++;
		if (str[i - 1] == 0)
			break ;
	}
	if (i != 16)
	{
		while (i < 16)
		{
			if (i % 2 == 0)
				write (1, " ", 1);
			write(1, "  ", 2);
			i++;
		}
	}
}

void	ft_putstr12(char *str)
{
	int	i;

	i = 0;
	write(1, " ", 1);
	while (i < 16)
	{
		if (str[i] >= 32 && str[i] < 127)
			ft_putchar12 (str[i]);
		else
		{
			write(1, ".", 1);
			if (str[i] == 0)
			{
				write(1, "\n", 1);
				return ;
			}
		}
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int			i;
	char					*str;
	unsigned long long int	base1;

	str = (char *)addr;
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			base1 = (unsigned long long)str + i;
			baseprint1 (base1, 16);
			baseprint2 (str + i);
			ft_putstr12 (str + i);
		}
		i++;
	}
	return (addr);
}
