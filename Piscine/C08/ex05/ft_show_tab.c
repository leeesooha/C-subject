/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:13:37 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/13 00:08:49 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	printnbr(long long bnb)
{
	if (bnb >= 10)
		printnbr (bnb / 10);
	write (1, &"0123456789"[bnb % 10], 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		print(par[i].str);
		write (1, "\n", 1);
		printnbr((long long)(par[i].size));
		write (1, "\n", 1);
		print(par[i].copy);
		write (1, "\n", 1);
		i++;
	}
}
