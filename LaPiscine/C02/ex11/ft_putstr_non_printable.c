/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:25:57 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/01 12:31:16 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	check(char *str, int i)
{
	int				j;
	char			base[16];
	unsigned char	tab;

	j = 0;
	while (j < 10)
	{
		base[j] = j + '0';
		j++;
	}
	while (j < 16)
	{
		base[j] = j - 10 + 'a';
		j++;
	}
	tab = (unsigned char)str[i];
	ft_putchar(base[tab / 16]);
	ft_putchar(base[tab % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			check(str, i);
		}
		else
			ft_putchar (str[i]);
		i++;
	}
}
